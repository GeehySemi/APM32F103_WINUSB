/*!
 * @file        usb_config.h
 *
 * @brief       USB configuration file
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
#ifndef __USB_CONFIG_H
#define __USB_CONFIG_H

/** @addtogroup Examples
  @{
*/

/** @addtogroup USB_CDC_VirtualCOMPort
  @{
*/

/** @defgroup USB_CDC_VirtualCOMPort_Macros Macros
  @{
*/

#define USB1                        0
#define USB2                        1

/* Select USB peripheral
*  USB1:  Share FIFO with CAN1
*  USB2:  Private FIFO.Not share whith CAN1
*/
#define USB_SELECT                  USB1

/* Interrupt source */
#define USB_INT_SOURCE          (USBD_INT_RST | USBD_INT_CTR | USBD_INT_SUS | USBD_INT_WKUP)

/* define 0 to disable, 1 to enable */
#define USB_LOW_POWER_SWITCH        0

/* Configuraion number */
#define USB_CONFIGURATION_NUM       1

/* Endpoint number */
#define USB_EP_MAX_NUM              3

/* Endpoint pack size in bytes */
#define USB_EP0_PACKET_SIZE         64

/* Buffer table address */
#define USB_BUFFER_TABLE_ADDR       0

/* EP0 Tx address */
#define USB_EP0_TX_ADDR         (0X18)

/* EP0 Rx address */
#define USB_EP0_RX_ADDR         (0X58)

/* EP1 Tx address */
#define USB_EP1_TX_ADDR         (0X98)

/* EP1 Rx address */
#define USB_EP1_RX_ADDR         (0XB8)

/* EP2 Rx address */
#define USB_EP2_TX_ADDR         (0XD8)

#define USB_SUP_WINSUB              1

/**@} end of group USB_CDC_VirtualCOMPort_Macros */
/**@} end of group USB_CDC_VirtualCOMPort */
/**@} end of group Examples */

#endif /*__USB_CONFIG_H */
