#ifndef _ACPM_H_
#define _ACPM_H_

#include <Library/PcdLib.h>

#define EXYNOS_MESSAGE_APM          0x203C200U

#define INTGR0                      0x0008
#define INTCR1                      0x0020
#define INTSR1                      0x0028

#define ACPM_SR0                    0x0000
#define ACPM_SR1                    0x0004
#define ACPM_SR2                    0x0008
#define ACPM_SR3                    0x000C

#define IPC_AP_I3C                  10
#define INTR_FLAG_OFFSET            16

#define ACPM_MAILBOX_LENGTH         0x1000
#define ACPM_MESSAGE_LENGTH         0x0010
#define ACPM_IPC_TIMEOUT_US         100000

#define SHIFT_BYTE                  8
#define SHIFT_REG                   0
#define SHIFT_TYPE                  8
#define SHIFT_FUNC                  0
#define SHIFT_DEST                  8
#define SHIFT_CNT                   8
#define SHIFT_WRITE_VAL             8
#define SHIFT_UPDATE_VAL            8
#define SHIFT_UPDATE_MASK           16
#define SHIFT_RETURN                24
#define SHIFT_BULK_VAL               SHIFT_BYTE
#define SHIFT_CHANNEL               12

#define MASK_BYTE                   0xFF
#define MASK_REG                    MASK_BYTE
#define MASK_TYPE                   0xF
#define MASK_FUNC                   MASK_BYTE
#define MASK_DEST                   MASK_BYTE
#define MASK_CNT                    MASK_BYTE
#define MASK_WRITE_VAL              MASK_BYTE
#define MASK_UPDATE_VAL             MASK_BYTE
#define MASK_UPDATE_MASK            MASK_BYTE
#define MASK_RETURN                 MASK_BYTE
#define MASK_BULK_VAL               MASK_BYTE
#define MASK_CHANNEL                0xF

#define SET_PROTOCOL(Data, Protocol) \
  ((((UINT32)(Data)) & MASK_##Protocol) << SHIFT_##Protocol)

#define READ_PROTOCOL(Data, Protocol) \
  ((((UINT32)(Data)) >> SHIFT_##Protocol) & MASK_##Protocol)

#define FUNC_READ                   0
#define FUNC_WRITE                  1
#define FUNC_UPDATE                 2
#define FUNC_BULK_READ              3
#define FUNC_BULK_WRITE             4

EFI_STATUS
EFIAPI
InitAcpm (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

EFI_STATUS
EFIAPI
I3cRead (
  IN  UINT8  Channel,
  IN  UINT8  Type,
  IN  UINT8  Reg,
  OUT UINT8  *Dest
  );

EFI_STATUS
EFIAPI
I3cWrite (
  IN UINT8  Channel,
  IN UINT8  Type,
  IN UINT8  Reg,
  IN UINT8  Value
  );

#endif
