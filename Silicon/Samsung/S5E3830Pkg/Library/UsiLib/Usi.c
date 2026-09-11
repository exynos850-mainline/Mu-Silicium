/**
  Copyright (c) 2019 Samsung Electronics Co., Ltd.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License version 2 as
  published by the Free Software Foundation.
**/

#include <Library/UsiLib.h>

STATIC
EFI_USI_DATA
gUsiData[] = {
  [0] = {
    .UsiAddress        = 0x138200C0,
    .ControllerAddress = 0x13820000,
    .I2cBus            = MAX_UINT8,
    .SpiBus            = MAX_UINT8,
    .UartBus           = 0
  },

  [1] = {
    .UsiAddress        = 0x138A00C0,
    .ControllerAddress = 0x138A0000,
    .I2cBus            = 0,
    .SpiBus            = MAX_UINT8,
    .UartBus           = MAX_UINT8
  },

  [2] = {
    .UsiAddress        = 0x138B00C0,
    .ControllerAddress = 0x138B0000,
    .I2cBus            = 1,
    .SpiBus            = MAX_UINT8,
    .UartBus           = MAX_UINT8
  },

  [3] = {
    .UsiAddress        = 0x138C00C0,
    .ControllerAddress = 0x138C0000,
    .I2cBus            = 2,
    .SpiBus            = MAX_UINT8,
    .UartBus           = MAX_UINT8
  },

  [4] = {
    .UsiAddress        = 0x139400C0,
    .ControllerAddress = 0x13940000,
    .I2cBus            = MAX_UINT8,
    .SpiBus            = 0,
    .UartBus           = MAX_UINT8
  },

  [5] = {
    .UsiAddress        = 0x11D000C0,
    .ControllerAddress = 0x11D00000,
    .I2cBus            = 3,
    .SpiBus            = 1,
    .UartBus           = 1
  },

  [6] = {
    .UsiAddress        = 0x11D200C0,
    .ControllerAddress = 0x11D20000,
    .I2cBus            = 4,
    .SpiBus            = 2,
    .UartBus           = 2
  }
};

VOID
GetUsiData (
  OUT EFI_USI_DATA **Data,
  OUT UINT8         *Count)
{
  // Pass Data
  *Data  = gUsiData;
  *Count = ARRAY_SIZE (gUsiData);
}
