XMOS USB Audio 2.0 Reference Design Readme
..........................................

:Version: 6.1.0rc3
:Vendor: XMOS
:Description: USB Audio Applications


Welcome to version 6 of the XMOS USB Audio software framework.  

The main feature of version 6 of the XMOS USB Audio software framework and associated applications is to add support 
for the latest U series of devices now available from XMOS.  This release supports the previous L devices, however, there is no
need to update to this version unless a specific issues is solved by this release.  Please see CHANGELOG.rst for detailed
change listing.

For full software documentation please see the USB Audio Software Design Guide document available from xmos.com.

This release is built and tested using version 12 of the XMOS toolset.

This repository contains applications (or instances) of the XMOS USB Audio Reference Design framework.  These applications
typically relate to a specific board.  This repository contains the following:

+---------------------+--------------------------+-------------------------------------------------------+
|    App Name         |     Relevant Board(s)    | Description                                           |
+---------------------+--------------------------+-------------------------------------------------------+
|app_usb_aud_l1       | xr-usb-audio-2.0         | XMOS XS1-L8 USB Audio Reference Design                |
|app_usb_aud_skc_su1  | xp-skc-su1 + xa-sk-audio | XMOS XS1-U8 USB Audio Kit                                |
|app_usb_aud_su1      | xr-usb-audio-s1          | XMOS XS1-U8 USB Audio Reference Design (prototype only)  |
+---------------------+--------------------------+-------------------------------------------------------+

Please refer to individual README files in these apps for more detailed information.

Each application contains a "core" folder, this folder contains items that are required to use and run the USB Audio 
application framework.  Mandatory files per application include: 

- An XN file describing the board including required port defines. The XN file is referenced in the application makefile.
- customdefines.h header file containing configuration items such as channel count, strings etc.
- ports.h header file containing declarations of ports that the application uses in addition to the ports in the XN file.

Each application also contains an "extensions" folder which includes board specific extensions such as CODEC 
configuration etc.

Additionally some options are contained in Makefiles for building multiple configurations of an application. For example 
app_usb_aud_l1 builds a MIDI and a S/PDIF configuration.  See the USB Audio Software Design Guide for full details.

Key Framework Features
======================

Key features of the various applications in this repositiry are as follow.  Please refer to the application README for application 
specific feature set.

- USB Audio Class 1.0/2.0 Compliant 

- Fully Asynchronous operation

- Support for the following sample frequencies: 44.1, 48, 88.2, 96, 176.4, 192kHz

- Input/output master/channel volume/mute controls supported

- Field firmware upgrade compliant to the USB Device Firmware Upgrade (DFU) Class Specification

- S/PDIF Output

- S/PDIF Input

- ADAT Input

- MIDI input/output (Compliant to USB Class Specification for MIDI devices)

- Mixer with flexible routing

Note, not all features may be supported at all sample frequencies, chips etc.

Known Issues
============

General known issues are as follows.  For board/application specific known issues please see README in relevant app directory.

-  Windows XP volume control very sensitive.  The Audio 1.0 driver built into Windows XP (usbaudio.sys) does not properly support master volume AND channel volume controls, leading to a very sensitive control.  Descriptors can be easily modified to disable master volume control if required (one byte - bmaControls(0) in Feature Unit descriptors)

-  88.2kHz and 176.4kHz sample frequencies are not exposed in Windows control panels.  This is due to known OS restrictions.

Host System Requirements
========================

- Mac OSX version 10.6 or later

- Windows XP, Vista or 7 with Thesycon Audio Class 2.0 driver for Windows (contact XMOS for details)

In Field Firmware Upgrade
=========================

The firmware provides a DFU interface compliant to the USB DFU Device Class.  An example host application is provided for OSX.  See README in example application for usage.  The Thesycon USB Audio Class 2.0 driver for Windows provides DFU functionality and includes an example application.

Required software (dependencies)
================================

  * sc_ios
  * sc_usb
  * sc_spdif
  * sc_usb_audio
  * xcommon (if using development tools earlier than 11.11.0)
  * sc_xud
  * sc_i2c

Support
=======

  This package is support by XMOS Ltd. Issues can be raised against the software
  at:

      http://www.xmos.com/support

