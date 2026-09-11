#include <Library/GpioLib.h>

STATIC
EFI_GPIO_CONTROLLER_DATA
gGpioControllers[] = {
  {
    .Address    = 0x11850000,
    {
      {
        .Id     = BANK_ID_A,
        .Number = 0,
        .Offset = 0x0
      },
      {
        .Id     = BANK_ID_A,
        .Number = 1,
        .Offset = 0x20
      },
      {
        .Id     = BANK_ID_A,
        .Number = 2,
        .Offset = 0x40
      },
      {
        .Id     = BANK_ID_A,
        .Number = 3,
        .Offset = 0x60
      },
      {
        .Id     = BANK_ID_A,
        .Number = 4,
        .Offset = 0x80
      },
      {
        .Id     = BANK_ID_Q,
        .Number = 0,
        .Offset = 0xA0
      }
    }
  },
  {
    .Address    = 0x11c30000,
    {
      {
        .Id     = BANK_ID_M,
        .Number = 0,
        .Offset = 0x0
      },
      {
        .Id     = BANK_ID_M,
        .Number = 1,
        .Offset = 0x20
      },
      {
        .Id     = BANK_ID_M,
        .Number = 2,
        .Offset = 0x40
      },
      {
        .Id     = BANK_ID_M,
        .Number = 3,
        .Offset = 0x60
      },
      {
        .Id     = BANK_ID_M,
        .Number = 4,
        .Offset = 0x80
      },
      {
        .Id     = BANK_ID_M,
        .Number = 5,
        .Offset = 0xA0
      },
      {
        .Id     = BANK_ID_M,
        .Number = 6,
        .Offset = 0xC0
      },
      {
        .Id     = BANK_ID_M,
        .Number = 7,
        .Offset = 0xE0
      }
    }
  },
  {
    .Address    = 0x14a60000,
    {
      {
        .Id     = BANK_ID_B,
        .Number = 0,
        .Offset = 0x0
      },
      {
        .Id     = BANK_ID_B,
        .Number = 1,
        .Offset = 0x20
      }
    }
  },
  {
    .Address    = 0x13430000,
    {
      {
        .Id     = BANK_ID_F,
        .Number = 2,
        .Offset = 0x0
      }
    }
  },
  {
    .Address    = 0x12070000,
    {
      {
        .Id     = BANK_ID_F,
        .Number = 0,
        .Offset = 0x0
      },
      {
        .Id     = BANK_ID_F,
        .Number = 1,
        .Offset = 0x20
      }
    }
  },
  {
    .Address    = 0x139b0000,
    {
      {
        .Id     = BANK_ID_C,
        .Number = 0,
        .Offset = 0x0
      },
      {
        .Id     = BANK_ID_C,
        .Number = 1,
        .Offset = 0x20
      },
      {
        .Id     = BANK_ID_G,
        .Number = 0,
        .Offset = 0x40
      },
      {
        .Id     = BANK_ID_G,
        .Number = 1,
        .Offset = 0x60
      },
      {
        .Id     = BANK_ID_G,
        .Number = 2,
        .Offset = 0x80
      },
      {
        .Id     = BANK_ID_G,
        .Number = 3,
        .Offset = 0xA0
      },
      {
        .Id     = BANK_ID_P,
        .Number = 0,
        .Offset = 0xC0
      },
      {
        .Id     = BANK_ID_P,
        .Number = 1,
        .Offset = 0xE0
      },
      {
        .Id     = BANK_ID_P,
        .Number = 2,
        .Offset = 0x100
      }
    }
  }
};

VOID
GetGpioControllerData (
  OUT EFI_GPIO_CONTROLLER_DATA **Data,
  OUT UINT8                     *Count)
{
  // Pass Data
  *Data  = gGpioControllers;
  *Count = ARRAY_SIZE (gGpioControllers);
}
