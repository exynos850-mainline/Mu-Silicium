#include <Library/PmicLib.h>

STATIC
EFI_PMIC_DATA
gPmicData = {
  {
  {
    {
      .Id        = ID_S2MPB03,
      .BusNumber = 5,
      .Slave     = 0x56
    }
  }
};

EFI_PMIC_DATA*
GetPmicData ()
{
  return &gPmicData;
}
