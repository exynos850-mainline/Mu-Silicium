#include <Library/DebugLib.h>
#include <Library/MemoryAllocationHelperLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/IoLib.h>

#include <Protocol/EFIAcpm.h>

#include "Acpm.h"
#include <Library/PcdLib.h>

STATIC UINTN mAcpmMailbox = 0;
STATIC UINTN mAcpmMessage = 0;

STATIC
EFI_STATUS
AcpmSendDataAsync (
  IN UINT32 IpcChannel,
  IN UINT32 Cmd0,
  IN UINT32 Cmd1
  )
{
  UINT32 AcpmIpc;

  if (mAcpmMailbox == 0 || mAcpmMessage == 0) {
    return EFI_NOT_READY;
  }

  if (IpcChannel >= 16) {
    return EFI_INVALID_PARAMETER;
  }

  AcpmIpc = (1U << IpcChannel) << INTR_FLAG_OFFSET;

  MmioWrite32 (mAcpmMessage + ACPM_SR0, Cmd0);
  MmioWrite32 (mAcpmMessage + ACPM_SR1, Cmd1);

  __asm__ __volatile__ ("dsb sy" ::: "memory");

  MmioWrite32 (mAcpmMailbox + INTGR0, AcpmIpc);

  return EFI_SUCCESS;
}

STATIC
EFI_STATUS
AcpmSendDataWait (
  IN  UINT32  IpcChannel,
  OUT UINT32  *Cmd0,
  OUT UINT32  *Cmd1
  )
{
  UINT32 Timeout;
  UINT32 Reg;

  if (mAcpmMailbox == 0 || mAcpmMessage == 0) {
    return EFI_NOT_READY;
  }

  if (Cmd0 == NULL || Cmd1 == NULL || IpcChannel >= 16) {
    return EFI_INVALID_PARAMETER;
  }

  for (Timeout = ACPM_IPC_TIMEOUT_US; Timeout > 0; Timeout--) {
    Reg = MmioRead32 (mAcpmMailbox + INTSR1) & (1U << IpcChannel);

    if (Reg != 0) {
      MmioWrite32 (mAcpmMailbox + INTCR1, 1U << IpcChannel);

      *Cmd0 = MmioRead32 (mAcpmMessage + ACPM_SR2);
      *Cmd1 = MmioRead32 (mAcpmMessage + ACPM_SR3);

      return EFI_SUCCESS;
    }

    gBS->Stall (1);
  }

  return EFI_TIMEOUT;
}

EFI_STATUS
EFIAPI
I3cRead (
  IN  UINT8  Channel,
  IN  UINT8  Type,
  IN  UINT8  Reg,
  OUT UINT8  *Dest
  )
{
  EFI_STATUS Status;
  UINT32 Command[4] = { 0, 0, 0, 0 };
  UINT32 IpcChannel = IPC_AP_I3C;
  UINT32 Response;

  if (Dest == NULL) {
    return EFI_INVALID_PARAMETER;
  }

  if (Channel > MASK_CHANNEL || Type > MASK_TYPE) {
    return EFI_INVALID_PARAMETER;
  }

  Command[0] =
    SET_PROTOCOL (Type, TYPE) |
    SET_PROTOCOL (Reg, REG) |
    SET_PROTOCOL (Channel, CHANNEL);

  Command[1] = SET_PROTOCOL (FUNC_READ, FUNC);

  Status = AcpmSendDataAsync (
             IpcChannel,
             Command[0],
             Command[1]
             );
  if (EFI_ERROR (Status)) {
    return Status;
  }

  Status = AcpmSendDataWait (
             IpcChannel,
             &Command[2],
             &Command[3]
             );
  if (EFI_ERROR (Status)) {
    return Status;
  }

  Response = Command[3];

  if (READ_PROTOCOL (Response, RETURN) != 0) {
    return EFI_DEVICE_ERROR;
  }

  *Dest = (UINT8)READ_PROTOCOL (Response, DEST);

  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
I3cWrite (
  IN UINT8  Channel,
  IN UINT8  Type,
  IN UINT8  Reg,
  IN UINT8  Value
  )
{
  EFI_STATUS Status;
  UINT32 Command[4] = { 0, 0, 0, 0 };
  UINT32 IpcChannel = IPC_AP_I3C;

  if (Channel > MASK_CHANNEL || Type > MASK_TYPE) {
    return EFI_INVALID_PARAMETER;
  }

  Command[0] =
    SET_PROTOCOL (Type, TYPE) |
    SET_PROTOCOL (Reg, REG) |
    SET_PROTOCOL (Channel, CHANNEL);

  Command[1] =
    SET_PROTOCOL (FUNC_WRITE, FUNC) |
    SET_PROTOCOL (Value, WRITE_VAL);

  Status = AcpmSendDataAsync (
             IpcChannel,
             Command[0],
             Command[1]
             );
  if (EFI_ERROR (Status)) {
    return Status;
  }

  Status = AcpmSendDataWait (
             IpcChannel,
             &Command[2],
             &Command[3]
             );
  if (EFI_ERROR (Status)) {
    return Status;
  }

  if (READ_PROTOCOL (Command[3], RETURN) != 0) {
    return EFI_DEVICE_ERROR;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
InitAcpm (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS Status;
  CONST UINT32 *AcpmAddress;

  AcpmAddress = (CONST UINT32 *)FixedPcdGetPtr (PcdAcpmBusAddr);

  if (AcpmAddress[0] == MAX_UINT32 ||
      AcpmAddress[1] == MAX_UINT32) {
    return EFI_UNSUPPORTED;
  }

  Status = MapMemoryRegion (
             AcpmAddress[0],
             ACPM_MAILBOX_LENGTH,
             EfiMemoryMappedIO
             );
  if (EFI_ERROR (Status)) {
    return Status;
  }

  Status = MapMemoryRegion (
             AcpmAddress[1],
             ACPM_MESSAGE_LENGTH,
             EfiMemoryMappedIO
             );
  if (EFI_ERROR (Status)) {
    return Status;
  }

  mAcpmMailbox = (UINTN)AcpmAddress[0];
  mAcpmMessage = (UINTN)AcpmAddress[1];

  return EFI_SUCCESS;
}
