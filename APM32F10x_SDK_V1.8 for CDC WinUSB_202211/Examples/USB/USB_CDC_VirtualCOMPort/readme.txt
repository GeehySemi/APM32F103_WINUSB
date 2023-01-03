/*!
 * @file        readme.txt
 *
 * @brief       This file is routine instruction
 *
 * @version     V1.0.3
 *
 * @date        2022-12-01
 *
 * @attention
 *
 *  Copyright (C) 2020-2022 Geehy Semiconductor
 *
 *  You may not use this file except in compliance with the
 *  GEEHY COPYRIGHT NOTICE (GEEHY SOFTWARE PACKAGE LICENSE).
 *
 *  The program is only for reference, which is distributed in the hope
 *  that it will be useful and instructional for customers to develop
 *  their software. Unless required by applicable law or agreed to in
 *  writing, the program is distributed on an "AS IS" BASIS, WITHOUT
 *  ANY WARRANTY OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the GEEHY SOFTWARE PACKAGE LICENSE for the governing permissions
 *  and limitations under the License.
 */

&par Example Description

This example describes how to use the USB device module on APM32F103 to
enumerate as a Virtual Com Port. This example use PC as host, you can use
serial assistant to transfer USB data. Once serial assistant send data to
device through the Virtual Com Port that USB enumerated, then device will
send the same data back to PC.

&par Directory contents

  - USB\USB_CDC_VirtualCOMPort\Source\apm32f10x_int.c    Interrupt handlers
  - USB\USB_CDC_VirtualCOMPort\Source\main.c             Main program
  - USB\USB_CDC_VirtualCOMPort\Source\usb_user.c         provides functions for usb user configuration

&par IDE environment

  - MDK-ARM V5.36
  - EWARM V8.50.5.26295

&par Hardware and Software environment

  - This example runs on APM32F103 MINI Devices.
