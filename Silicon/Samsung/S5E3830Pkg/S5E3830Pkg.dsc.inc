##
#  Copyright (c) 2011 - 2022, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2020, Intel Corporation. All rights reserved.
#  Copyright (c) 2018, Bingxing Wang. All rights reserved.
#  Copyright (c) Microsoft Corporation.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
##

[Defines]
  #
  # Timer
  #
  USE_PHYSICAL_TIMER                         = 0

  #
  # KEP
  #
  HAS_CNTFRQ_EL0_EMPTY_ERRATA                = 1

!include SamsungPkg/SamsungPkg.dsc.inc

[BuildOptions]
  *_*_AARCH64_CC_FLAGS = -march=armv8.2-a+crypto+rcpc

[PcdsFixedAtBuild]
  #
  # ACPI
  #
  gEfiMdeModulePkgTokenSpaceGuid.PcdAcpiDefaultOemTableId|0x2030333839453553
  gEfiMdeModulePkgTokenSpaceGuid.PcdAcpiDefaultOemRevision|0x3830

  #
  # CPU
  #
  gArmPlatformTokenSpaceGuid.PcdCoreCount|8
  gArmPlatformTokenSpaceGuid.PcdClusterCount|2

  #
  # GIC
  #
  gArmTokenSpaceGuid.PcdGicDistributorBase|0x12a00000
  gArmTokenSpaceGuid.PcdGicInterruptInterfaceBase|0x12a01000

  #
  # Timer
  #
  gSiliciumPkgTokenSpaceGuid.PcdTimerFreqOverwrite|26000000

  #
  # GPIO
  # List Contents: 0x11850000, 0x11C30000, 0x12070000, 0x13430000, 0x139B0000, 0x14A60000
  #
  gSamsungPkgTokenSpaceGuid.PcdGpioCtrlAddr|{ 0x00, 0x00, 0x85, 0x11, 0x00, 0x00, 0xC3, 0x11, 0x00, 0x00, 0x07, 0x12, 0x00, 0x00, 0x43, 0x13, 0x00, 0x00, 0x9B, 0x13, 0x00, 0x00, 0xA6, 0x14 }

  #
  # RAM Manager
  #
  gSamsungPkgTokenSpaceGuid.PcdHasSecurePgtbl|TRUE
  gSamsungPkgTokenSpaceGuid.PcdHasHarx|TRUE

  #
  # SMBIOS
  #
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosProcessorModel|"Exynos (TM) 850 @ 2.0 GHz"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosProcessorPartNumber|"S5E3830"

[LibraryClasses]
  #
  # SEC Libraries
  #
  PlatformSecLib|S5E3830Pkg/Library/PlatformSecLib/PlatformSecLib.inf

  #
  # Memory Libraries
  #
  RamManagerLib|SiliciumNullPkg/Library/RamManagerLibNull/RamManagerLibNull.inf

  #
  # UEFI Libraries
  #
  HwResetSystemLib|S5E3830Pkg/Library/ResetSystemLib/ResetSystemLib.inf
  ResetSystemLib|S5E3830Pkg/Library/ResetSystemLib/ResetSystemLib.inf

  #
  # IO Libraries
  #
  GpioLib|S5E3830Pkg/Library/GpioLib/GpioLib.inf
  HsI2cLib|S5E3830Pkg/Library/HsI2cLib/HsI2cLib.inf

  #
  # Power Management Libraries
  #
#  PmicLib|S5E3830Pkg/Library/PmicLib/PmicLib.inf
# TODO: PMIC bringup

  #
  # Storage Libraries
  #
  PlatformMshcLib|S5E3830Pkg/Library/PlatformMshcLib/PlatformMshcLib.inf

  #
  # USB Libraries
  #
  PlatformUsbfnLib|S5E3830Pkg/Library/PlatformUsbfnLib/PlatformUsbfnLib.inf

  #
  # Samsung Libraries
  #
  UsiLib|S5E3830Pkg/Library/UsiLib/UsiLib.inf
