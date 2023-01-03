/*!
 * @file        ubsd_descriptor.h
 *
 * @brief       CDC descriptor head file
 *
 * @version     V1.0.1
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

/* Define to prevent recursive inclusion */
#ifndef __USBD_DESCRIPTOR_H
#define __USBD_DESCRIPTOR_H

/* Includes */
#include "usbd_core.h"

/** @addtogroup Examples
  @{
*/

/** @addtogroup USB_CDC_VirtualCOMPort
  @{
*/

/** @defgroup USB_CDC_VirtualCOMPort_Macros Macros
  @{
*/

#if USB_SUP_WINSUB
#define USB_WINUSB_OS_STRING_SIZE           0x12
#define USB_WINUSB_OS_FEATURE_DESC_SIZE     0x28
#define USB_WINUSB_OS_PROPERTY_DESC_SIZE    0x8E
#define USB_WINUSB_CDC_OUT_EP               0x01
#define USB_WINUSB_CDC_IN_EP                0x81
#define USB_WINUSB_CDC_DATA_MAX_PACKET_SIZE 0x40
#define USBD_STR_CONFIG_INDEX               0x04
#endif

#define USB_DEVICE_DESCRIPTOR_SIZE          (18)

#if USB_SUP_WINSUB
#define USB_CONFIG_DESCRIPTOR_SIZE          0x20
#else
#define USB_CONFIG_DESCRIPTOR_SIZE          (67)
#endif

#define USB_LANGID_STRING_SIZE              (4)
#define USB_VENDOR_STRING_SIZE              (12)
#define USB_PRODUCT_STRING_SIZE             (26)
#define USB_SERIAL_STRING_SIZE              (26)
#define USB_USER_STRING_1_SIZE              (94)
#define USB_USER_STRING_2_SIZE              (72)
#define USB_QUALIFIER_DESCRIPTOR_SIZE       (10)

#if USB_SUP_WINSUB
#define SRTING_DESC_NUM                     (5)
#else
#define SRTING_DESC_NUM                     (4)
#endif

/**@} end of group USB_CDC_VirtualCOMPort_Macros */

/** @defgroup USB_CDC_VirtualCOMPort_Variables Variables
  @{
*/

extern USBD_Descriptor_T g_deviceDescriptor;
extern USBD_Descriptor_T g_configDescriptor;
extern USBD_Descriptor_T g_stringDescriptor[SRTING_DESC_NUM];

#if USB_SUP_WINSUB
extern USBD_Descriptor_T g_winusbOsFeatureDescriptor;
extern USBD_Descriptor_T g_winusbOsPropertyDescriptor;
#endif

/**@} end of group USB_CDC_VirtualCOMPort_Variables */
/**@} end of group USB_CDC_VirtualCOMPort */
/**@} end of group Examples */

#endif /*__USBD_DESCRIPTOR_H */
