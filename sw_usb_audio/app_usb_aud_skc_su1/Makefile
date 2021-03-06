# The TARGET variable determines what target system the application is 
# compiled for. It either refers to an XN file in the source directories
# or a valid argument for the --target option when compiling.

TARGET = xp_skc_su1.xn
APP_NAME =

# The flags passed to xcc when building the application
BUILD_FLAGS     = -DAUDIO_2 -DFLASH_MAX_UPGRADE_SIZE=64*1024 -fcomment-asm -Xmapper --map -Xmapper MAPFILE -Wall -O3 -report -lflash -fsubword-select -save-temps -g -DUSB_CORE=0 -D TEST_MODE_SUPPORT -DARCH_S -fxscope -DXSCOPE -DSDA_HIGH=2 -DSCL_HIGH=1
#-fschedule


# Test build configs (Note these make use of the defaults in customdefines.h)

# Audio Class 2, Input, Output, No MIDI, SPDIF
XCC_FLAGS_2ioxs = $(BUILD_FLAGS) 
INCLUDE_ONLY_IN_2ioxs = 

# Audio Class 2, No Input, Output, No MIDI, SPDIF
XCC_FLAGS_2xoxs = $(BUILD_FLAGS) -DNUM_USB_CHAN_IN=0 -DI2S_CHANS_ADC=0
INCLUDE_ONLY_IN_2xoxs = 

#Audio Class 2, Input, Output, MIDI, No SPDIF
XCC_FLAGS_2iomx = $(BUILD_FLAGS) -DMIDI=1 -DSPDIF=0
INCLUDE_ONLY_IN_2iomx = 

#Audio Class 2, Input, no Output, no MIDI, No SPDIF
XCC_FLAGS_2ixxx = $(BUILD_FLAGS) -DNUM_USB_CHAN_OUT=0 -DI2S_CHANS_DAC=0 -DSPDIF=0
INCLUDE_ONLY_IN_2ixxx = 

# Audio Class 1, Input, Output, No MIDI, SPDIF, 2in/2out
XCC_FLAGS_1ioxs = $(BUILD_FLAGS) -DNUM_USB_CHAN_IN=2 -DNUM_USB_CHAN_OUT=2 -DAUDIO_CLASS=1
INCLUDE_ONLY_IN_1ioxs = 

# Audio Class 1, No Input, Output, No MIDI, SPDIF, 0in/2out
XCC_FLAGS_1xoxs = $(BUILD_FLAGS) -DNUM_USB_CHAN_IN=0 -DNUM_USB_CHAN_OUT=2 -DAUDIO_CLASS=1
INCLUDE_ONLY_IN_1xoxs = 

# The USED_MODULES variable lists other module used by the application. These
# modules will extend the SOURCE_DIRS, INCLUDE_DIRS and LIB_DIRS variables. 
# Modules are expected to be in the directory above the BASE_DIR directory.
USED_MODULES = module_usb_shared module_xud module_usb_audio module_spdif_tx module_spdif_rx module_usb_midi module_dfu module_i2c_single_port

MODULE_LIBRARIES = xud_s


#=============================================================================
#=============================================================================
# The following part of the Makefile includes the common build infrastructure
# for compiling XMOS applications. You should not need to edit below here.

XMOS_MAKE_PATH ?= ../..
ifneq ($(wildcard $(XMOS_MAKE_PATH)/xcommon/module_xcommon/build/Makefile.common),)
include $(XMOS_MAKE_PATH)/xcommon/module_xcommon/build/Makefile.common
else
include ../module_xcommon/build/Makefile.common
endif


