#ifndef _EFI_ACPM_H_
#define _EFI_ACPM_H_

/**
  This Function Reads Data from the Specified I3C Channel.

  @param[in]  Channel  - The I3C Channel.
  @param[in]  Type     - The I3C Device Type.
  @param[in]  Reg      - The Register Address.
  @param[out] Dest     - The Output Data.

  @return EFI_SUCCESS            - Successfully Read Data.
  @return EFI_INVALID_PARAMETER  - A Parameter is Invalid.
  @return EFI_NOT_READY          - The ACPM IPC isn't Initialized.
  @return EFI_TIMEOUT            - The ACPM Command took too Long.
  @return EFI_DEVICE_ERROR       - The ACPM Returned an Error.
**/
typedef
EFI_STATUS
(EFIAPI *EFI_ACPM_I3C_READ) (
  IN  UINT8   Channel,
  IN  UINT8   Type,
  IN  UINT32  Reg,
  OUT UINT32 *Dest
  );

/**
  This Function Writes Data to the Specified I3C Channel.

  @param[in] Channel  - The I3C Channel.
  @param[in] Type     - The I3C Device Type.
  @param[in] Reg      - The Register Address.
  @param[in] Value    - The Data to Write.

  @return EFI_SUCCESS            - Successfully Wrote Data.
  @return EFI_INVALID_PARAMETER  - A Parameter is Invalid.
  @return EFI_NOT_READY          - The ACPM IPC isn't Initialized.
  @return EFI_TIMEOUT            - The ACPM Command took too Long.
  @return EFI_DEVICE_ERROR       - The ACPM Returned an Error.
**/
typedef
EFI_STATUS
(EFIAPI *EFI_ACPM_I3C_WRITE) (
  IN UINT8   Channel,
  IN UINT8   Type,
  IN UINT32  Reg,
  IN UINT32  Value
  );

//
// Define Protocol Functions
//
typedef struct {
  EFI_ACPM_I3C_READ  I3cRead;
  EFI_ACPM_I3C_WRITE I3cWrite;
} EFI_ACPM_PROTOCOL;

#endif /* _EFI_ACPM_H_ */
