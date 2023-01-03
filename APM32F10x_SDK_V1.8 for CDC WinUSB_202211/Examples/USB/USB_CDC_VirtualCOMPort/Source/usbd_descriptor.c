/*!
 * @file        usbd_descriptor.c
 *
 * @brief       CDC descriptor
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

/* Includes */
#include "usbd_descriptor.h"
#include "usbd_core.h"

/** @addtogroup Examples
  @{
*/

/** @addtogroup USB_CDC_VirtualCOMPort
  @{
*/

/** @defgroup USB_CDC_VirtualCOMPort_Variables Variables
  @{
*/

extern const uint8_t g_usbDeviceDescriptor[USB_DEVICE_DESCRIPTOR_SIZE];
extern const uint8_t g_usbConfigDescriptor[USB_CONFIG_DESCRIPTOR_SIZE];
extern const uint8_t g_usbLandIDString[USB_LANGID_STRING_SIZE];
extern const uint8_t g_usbVendorString[USB_VENDOR_STRING_SIZE];
extern const uint8_t g_usbProductString[USB_PRODUCT_STRING_SIZE];
extern uint8_t g_usbSerialString[USB_SERIAL_STRING_SIZE];
extern const uint8_t g_usbWinUsbOsString[USB_WINUSB_OS_FEATURE_DESC_SIZE];

#if USB_SUP_WINSUB
const uint8_t g_usbWinUsbOsFeatureDesc[USB_WINUSB_OS_FEATURE_DESC_SIZE];
const uint8_t g_usbWinUsbOsPropertyDesc[USB_WINUSB_OS_PROPERTY_DESC_SIZE];
#endif

/* Device descriptor */
USBD_Descriptor_T g_deviceDescriptor = {g_usbDeviceDescriptor, USB_DEVICE_DESCRIPTOR_SIZE};
/* Config descriptor */
USBD_Descriptor_T g_configDescriptor = {g_usbConfigDescriptor, USB_CONFIG_DESCRIPTOR_SIZE};
/* String descriptor */
USBD_Descriptor_T g_stringDescriptor[SRTING_DESC_NUM] =
{
    {g_usbLandIDString, USB_LANGID_STRING_SIZE},
    {g_usbVendorString, USB_VENDOR_STRING_SIZE},
    {g_usbProductString, USB_PRODUCT_STRING_SIZE},
    {g_usbSerialString, USB_SERIAL_STRING_SIZE},
#if USB_SUP_WINSUB
    /* winusb */
    {g_usbWinUsbOsString, USB_WINUSB_OS_STRING_SIZE}
#endif
};

#if USB_SUP_WINSUB
USBD_Descriptor_T g_winusbOsFeatureDescriptor = {g_usbWinUsbOsFeatureDesc, USB_WINUSB_OS_FEATURE_DESC_SIZE};
USBD_Descriptor_T g_winusbOsPropertyDescriptor = {g_usbWinUsbOsPropertyDesc, USB_WINUSB_OS_PROPERTY_DESC_SIZE};

/**
 * @brief   WinUSB OS descriptor
 */
const uint8_t g_usbWinUsbOsString[USB_WINUSB_OS_FEATURE_DESC_SIZE] =
{
    /* bLength */
    0x12,
    /* bDescriptorType */
    USBD_DESC_STRING,
    'M', 0x00,
    'S', 0x00,
    'F', 0x00,
    'T', 0x00,
    '1', 0x00,
    '0', 0x00,
    '0', 0x00,
    USB_REQ_MS_VENDOR_CODE, 
    0x00,
};

/**
 * @brief   WinUSB OS feature descriptor
 */
const uint8_t g_usbWinUsbOsFeatureDesc[USB_WINUSB_OS_FEATURE_DESC_SIZE] =
{
    0x28, 0, 0, 0, // length
    0, 1,          // bcd version 1.0
    4, 0,          // windex: extended compat ID descritor
    1,             // no of function
    0, 0, 0, 0, 0, 0, 0, // reserve 7 bytes
    0,             // interface no
    0,             // reserved
    'W', 'I', 'N', 'U', 'S', 'B', 0, 0, //  first ID
    0,   0,   0,   0,   0,   0, 0, 0,  // second ID
    0,   0,   0,   0,   0,   0 // reserved 6 bytes
};

const uint8_t g_usbWinUsbOsPropertyDesc[USB_WINUSB_OS_PROPERTY_DESC_SIZE] =
{
      0x8E, 0, 0, 0,  // length 246 byte
      0x00, 0x01,   // BCD version 1.0
      0x05, 0x00,   // Extended Property Descriptor Index(5)
      0x01, 0x00,   // number of section (1)
//; property section        
      0x84, 0x00, 0x00, 0x00,   // size of property section
      0x1, 0, 0, 0,   //; property data type (1)
      0x28, 0,        //; property name length (42)
      'D', 0,
      'e', 0,
      'v', 0,
      'i', 0,
      'c', 0,
      'e', 0,
      'I', 0,
      'n', 0,
      't', 0,
      'e', 0,
      'r', 0,
      'f', 0,
      'a', 0,
      'c', 0,
      'e', 0,
      'G', 0,
      'U', 0,
      'I', 0,
      'D', 0,
      0, 0,
      // D6805E56-0447-4049-9848-46D6B2AC5D28
      0x4E, 0, 0, 0,  // ; property data length
      '{', 0,
      '1', 0,
      '3', 0,
      'E', 0,
      'B', 0,
      '3', 0,
      '6', 0,
      '0', 0,
      'B', 0,
      '-', 0,
      'B', 0,
      'C', 0,
      '1', 0,
      'E', 0,
      '-', 0,
      '4', 0,
      '6', 0,
      'C', 0,
      'B', 0,
      '-', 0,
      'A', 0,
      'C', 0,
      '8', 0,
      'B', 0,
      '-', 0,
      'E', 0,
      'F', 0,
      '3', 0,
      'D', 0,
      'A', 0,
      '4', 0,
      '7', 0,
      'B', 0,
      '4', 0,
      '0', 0,
      '6', 0,
      '2', 0,
      '}', 0,
      0, 0,
};

#endif
/**
 * @brief   Device descriptor
 */
const uint8_t g_usbDeviceDescriptor[USB_DEVICE_DESCRIPTOR_SIZE] =
{
    /* bLength */
    0x12,

    /* bDescriptorType */
    USBD_DESC_DEVICE,

    /* bcdUSB */
    0x00, 0x02,

    /* bDeviceClass */
    0x00,
    /* bDeviceSubClass */
    0x00,
    /* bDeviceProtocol */
    0x00,
    /* bMaxPacketSize = 64 */
    USB_EP0_PACKET_SIZE,
    /* idVendor =  314b*/
   // 0x4B, 0x31,
	 2020 & 0xFF, 2020 >> 8,
    /* idProduct = 0215 */
   // 0x15, 0x02,
    2020 & 0xFF, 2020 >> 8,
    /* bcdDevice = 2.00 */
    0x08, 0x01,

    /* Index of string descriptor describing manufacturer */
    1,
    /* Index of string descriptor describing product */
    2,
    /* Index of string descriptor describing the device serial number */
    3,
    /* bNumConfigurations */
    1,
};

#if USB_SUP_WINSUB
/**
 * @brief   Configuration descriptor
 */
const uint8_t g_usbConfigDescriptor[USB_CONFIG_DESCRIPTOR_SIZE] =
{
    /* bLength */
    0x09,
    /* bDescriptorType */
    USBD_DESC_CONFIGURATION,
    /* wTotalLength */
    USB_CONFIG_DESCRIPTOR_SIZE & 0xFF, USB_CONFIG_DESCRIPTOR_SIZE >> 8,

    /* bNumInterfaces: 1 interface for WINUSB */
    0x01,
    /* bConfigurationValue: Configuration value */
    0x01,
    /* iConfiguration: Index of string descriptor describing the configuration */
    USBD_STR_CONFIG_INDEX,
    /* bmAttributes */
    0xC0,
    /* MaxPower */
    0x32,

    /* bLength */
    0x09,
    /* bDescriptorType */
    USBD_DESC_INTERFACE,
    /* bInterfaceNumber */
    0x00,
    /* bAlternateSetting */
    0x00,
    /* bNumEndpoints: Two endpoints used */
    0x02,
    /* bInterfaceClass */
    0xFF,
    /* bInterfaceSubClass */
    0x00,
    /* bInterfaceProtocol */
    0x00,
    /* iInterface */
    0x00,

    /*Endpoint OUT Descriptor*/
    /* bLength: Endpoint Descriptor size */
    0x07,
    /* bDescriptorType: Endpoint */
    USBD_DESC_ENDPOINT,
    /* bEndpointAddress */
    USB_WINUSB_CDC_OUT_EP,
    /* bmAttributes: Bulk */
    0x02,
    /* wMaxPacketSize: */
    USB_WINUSB_CDC_DATA_MAX_PACKET_SIZE & 0xFF,USB_WINUSB_CDC_DATA_MAX_PACKET_SIZE >> 8,
    /* bInterval: ignore for Bulk transfer */
    0x00,
    
    /*Endpoint IN Descriptor*/
    /* bLength: Endpoint Descriptor size */
    0x07,
    /* bDescriptorType: Endpoint */
    USBD_DESC_ENDPOINT,
    /* bEndpointAddress */
    USB_WINUSB_CDC_IN_EP,
    /* bmAttributes: Bulk */
    0x02,
    /* wMaxPacketSize: */
    USB_WINUSB_CDC_DATA_MAX_PACKET_SIZE & 0xFF,USB_WINUSB_CDC_DATA_MAX_PACKET_SIZE >> 8,
    /* bInterval: ignore for Bulk transfer */
    0x00,
};


#else
/**
 * @brief   Configuration descriptor
 */
const uint8_t g_usbConfigDescriptor[USB_CONFIG_DESCRIPTOR_SIZE] =
{
    /* bLength */
    0x09,
    /* bDescriptorType */
    USBD_DESC_CONFIGURATION,
    /* wTotalLength */
    USB_CONFIG_DESCRIPTOR_SIZE & 0xFF, USB_CONFIG_DESCRIPTOR_SIZE >> 8,

    /* bNumInterfaces */
    0x02,
    /* bConfigurationValue */
    0x01,
    /* iConfiguration */
    0x00,
    /* bmAttributes */
    0xC0,
    /* MaxPower */
    0x32,

    /* bLength */
    0x09,
    /* bDescriptorType */
    USBD_DESC_INTERFACE,
    /* bInterfaceNumber */
    0x00,
    /* bAlternateSetting */
    0x00,
    /* bNumEndpoints */
    0x01,
    /* bInterfaceClass */
    0x02,
    /* bInterfaceSubClass */
    0x02,
    /* bInterfaceProtocol */
    0x01,
    /* iInterface */
    0x00,

    /* bLength: Endpoint Descriptor size */
    0x05,
    /* bDescriptorType: CS_INTERFACE */
    0x24,
    /* bDescriptorSubtype: Header Func Desc */
    0x00,
    /* bcdCDC: spec release number */
    0x00, 0x02,

    /* bFunctionLength */
    0x05,
    /* bDescriptorType: CS_INTERFACE */
    0x24,
    /* bDescriptorSubtype: Call Management Func Desc */
    0x01,
    /* bmCapabilities: D0+D1 */
    0x00,
    /* bDataInterface: 1 */
    0x01,

    /* bFunctionLength */
    0x04,
    /* bDescriptorType: CS_INTERFACE */
    0x24,
    /* bDescriptorSubtype: Abstract Control Management desc */
    0x02,
    /* bmCapabilities */
    0x02,

    /* bFunctionLength */
    0x05,
    /* bDescriptorType: CS_INTERFACE */
    0x24,
    /* bDescriptorSubtype: Union func desc */
    0x06,
    /* bMasterInterface: Communication class interface */
    0x00,
    /* bSlaveInterface0: Data Class Interface */
    0x01,

    /* bLength: Endpoint Descriptor size */
    0x07,
    /* bDescriptorType: Endpoint */
    USBD_DESC_ENDPOINT,
    /* bEndpointAddress */
    0x82,
    /* bmAttributes: Interrupt */
    0x03,
    /* wMaxPacketSize: */
    0x08,0x00,
    /* bInterval: */
    0xFF,


    /* bLength: Endpoint Descriptor size */
    0x09,
    /* bDescriptorType: */
    USBD_DESC_INTERFACE,
    /* bInterfaceNumber: Number of Interface */
    0x01,
    /* bAlternateSetting: Alternate setting */
    0x00,
    /* bNumEndpoints: Two endpoints used */
    0x02,
    /* bInterfaceClass: CDC */
    0x0A,
    /* bInterfaceSubClass: */
    0x00,
    /* bInterfaceProtocol: */
    0x00,
    /* iInterface: */
    0x00,

    /* bLength: Endpoint Descriptor size */
    0x07,
    /* bDescriptorType: Endpoint */
    USBD_DESC_ENDPOINT,
    /* bEndpointAddress */
    0x01,
    /* bmAttributes: Bulk */
    0x02,
    /* wMaxPacketSize: */
    0x40,0x00,
    /* bInterval: ignore for Bulk transfer */
    0x00,

    /* bLength: Endpoint Descriptor size */
    0x07,
    /* bDescriptorType: Endpoint */
    USBD_DESC_ENDPOINT,
    /* bEndpointAddress */
    0x81,
    /* bmAttributes: Bulk */
    0x02,
    /* wMaxPacketSize: */
    0x40,0x00,
    /* bInterval: ignore for Bulk transfer */
    0x00
};
#endif

/**
 * @brief   language ID string
 */
const uint8_t g_usbLandIDString[USB_LANGID_STRING_SIZE] =
{
    /* Size */
    USB_LANGID_STRING_SIZE,
    /* bDescriptorType */
    USBD_DESC_STRING,
    0X09,0X04
};

/**
 * @brief   Vendor string
 */
const uint8_t g_usbVendorString[USB_VENDOR_STRING_SIZE] =
{
    /* Size */
    USB_VENDOR_STRING_SIZE,
    /* bDescriptorType */
    USBD_DESC_STRING,
    'G', 0, 'e', 0, 'e', 0, 'h', 0, 'y', 0
};

/**
 * @brief   Product string
 */
const uint8_t g_usbProductString[USB_PRODUCT_STRING_SIZE] =
{
    USB_PRODUCT_STRING_SIZE,
    USBD_DESC_STRING,
    'A', 0, 'P', 0, 'M', 0, '3', 0, '2', 0,
    ' ', 0, 'W', 0, 'I', 0, 'N', 0, 'U', 0,
    'S', 0, 'B', 0
};

/**
 * @brief   Serial string
 */
uint8_t g_usbSerialString[USB_SERIAL_STRING_SIZE] =
{
    USB_SERIAL_STRING_SIZE,
    USBD_DESC_STRING,

    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0,
    '0', 0
};

/**@} end of group USB_CDC_VirtualCOMPort_Variables */
/**@} end of group USB_CDC_VirtualCOMPort */
/**@} end of group Examples */
