#include <Library/HsI2cLib.h>

STATIC
EFI_HSI2C_BUS_DATA
gHsI2cBusData[] = {
  [0] = {
    {
      .Function   = FUNCTION_2,
      .SclBankId  = BANK_ID_P,
      .SdaBankId  = BANK_ID_P,
      .SclBankNum = 0,
      .SdaBankNum = 0,
      .SclPin     = 0,
      .SdaPin     = 1
    },
    {
      .Freq       = 1000000,
      .SpeedMode  = FAST_PLUS_SPD
    }
  },
  [1] = {
    {
      .Function   = FUNCTION_2,
      .SclBankId  = BANK_ID_P,
      .SdaBankId  = BANK_ID_P,
      .SclBankNum = 1,
      .SdaBankNum = 1,
      .SclPin     = 0,
      .SdaPin     = 1
    },
    {
      .Freq       = 1000000,
      .SpeedMode  = FAST_PLUS_SPD
    }
  },
  [2] = {
    {
      .Function   = FUNCTION_2,
      .SclBankId  = BANK_ID_P,
      .SdaBankId  = BANK_ID_P,
      .SclBankNum = 2,
      .SdaBankNum = 2,
      .SclPin     = 0,
      .SdaPin     = 1
    },
    {
      .Freq       = 1000000,
      .SpeedMode  = FAST_PLUS_SPD
    }
  }
};

VOID
GetHsI2cBusData (
  OUT EFI_HSI2C_BUS_DATA **Data,
  OUT UINT8               *Count)
{
  // Pass Data
  *Data  = gHsI2cBusData;
  *Count = ARRAY_SIZE (gHsI2cBusData);
}
