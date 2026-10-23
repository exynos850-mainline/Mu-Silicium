#include <Library/GpioBankLib.h>

STATIC
EFI_GPIO_BANK
mGpioBanks[] = {
  //
  // ALIVE
  //
  {
    .CtrlNum = 0,
    .Id      = BANK_ID_A,
    .Number  = 0,
    .Offset  = 0x0
  },
  {
    .CtrlNum = 0,
    .Id      = BANK_ID_A,
    .Number  = 1,
    .Offset  = 0x20
  },
  {
    .CtrlNum = 0,
    .Id      = BANK_ID_A,
    .Number  = 2,
    .Offset  = 0x40
  },
  {
    .CtrlNum = 0,
    .Id      = BANK_ID_A,
    .Number  = 3,
    .Offset  = 0x60
  },
  {
    .CtrlNum = 0,
    .Id      = BANK_ID_A,
    .Number  = 4,
    .Offset  = 0x80
  },
  {
    .CtrlNum = 0,
    .Id      = BANK_ID_Q,
    .Number  = 0,
    .Offset  = 0xA0
  },

  //
  // CMGP
  //
  {
    .CtrlNum = 1,
    .Id      = BANK_ID_M,
    .Number  = 0,
    .Offset  = 0x0
  },
  {
    .CtrlNum = 1,
    .Id      = BANK_ID_M,
    .Number  = 1,
    .Offset  = 0x20
  },
  {
    .CtrlNum = 1,
    .Id      = BANK_ID_M,
    .Number  = 2,
    .Offset  = 0x40
  },
  {
    .CtrlNum = 1,
    .Id      = BANK_ID_M,
    .Number  = 3,
    .Offset  = 0x60
  },
  {
    .CtrlNum = 1,
    .Id      = BANK_ID_M,
    .Number  = 4,
    .Offset  = 0x80
  },
  {
    .CtrlNum = 1,
    .Id      = BANK_ID_M,
    .Number  = 5,
    .Offset  = 0xA0
  },
  {
    .CtrlNum = 1,
    .Id      = BANK_ID_M,
    .Number  = 6,
    .Offset  = 0xC0
  },
  {
    .CtrlNum = 1,
    .Id      = BANK_ID_M,
    .Number  = 7,
    .Offset  = 0xE0
  },

  //
  // HSI1/HSI2
  //
  {
    .CtrlNum = 2,
    .Id      = BANK_ID_F,
    .Number  = 0,
    .Offset  = 0x0
  },
  {
    .CtrlNum = 2,
    .Id      = BANK_ID_F,
    .Number  = 1,
    .Offset  = 0x20
  },

  //
  // HSI3
  //
  {
    .CtrlNum = 3,
    .Id      = BANK_ID_F,
    .Number  = 2,
    .Offset  = 0x0
  },

  //
  // PERIC1
  //
  {
    .CtrlNum = 4,
    .Id      = BANK_ID_C,
    .Number  = 0,
    .Offset  = 0x0
  },
  {
    .CtrlNum = 4,
    .Id      = BANK_ID_C,
    .Number  = 1,
    .Offset  = 0x20
  },
  {
    .CtrlNum = 4,
    .Id      = BANK_ID_G,
    .Number  = 0,
    .Offset  = 0x40
  },
  {
    .CtrlNum = 4,
    .Id      = BANK_ID_G,
    .Number  = 1,
    .Offset  = 0x60
  },
  {
    .CtrlNum = 4,
    .Id      = BANK_ID_G,
    .Number  = 2,
    .Offset  = 0x80
  },
  {
    .CtrlNum = 4,
    .Id      = BANK_ID_G,
    .Number  = 3,
    .Offset  = 0xA0
  },
  {
    .CtrlNum = 4,
    .Id      = BANK_ID_P,
    .Number  = 0,
    .Offset  = 0xC0
  },
  {
    .CtrlNum = 4,
    .Id      = BANK_ID_P,
    .Number  = 1,
    .Offset  = 0xE0
  },
  {
    .CtrlNum = 4,
    .Id      = BANK_ID_P,
    .Number  = 2,
    .Offset  = 0x100
  },

  //
  // PERIC1/PERIC0
  //
  {
    .CtrlNum = 5,
    .Id      = BANK_ID_B,
    .Number  = 0,
    .Offset  = 0x0
  },
  {
    .CtrlNum = 5,
    .Id      = BANK_ID_B,
    .Number  = 1,
    .Offset  = 0x20
  }
};

VOID
GetGpioBanks (
  OUT EFI_GPIO_BANK **Bank,
  OUT UINT8          *Count)
{
  // Pass Data
  *Bank  = mGpioBanks;
  *Count = ARRAY_SIZE (mGpioBanks);
}
