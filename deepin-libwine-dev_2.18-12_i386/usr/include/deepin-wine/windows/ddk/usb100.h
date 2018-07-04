/*
 * Copyright (C) the Wine project
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __DDK_USB100_H__
#define __DDK_USB100_H__

#define USB_DEVICE_DESCRIPTOR_TYPE                0x01
#define USB_CONFIGURATION_DESCRIPTOR_TYPE         0x02
#define USB_STRING_DESCRIPTOR_TYPE                0x03
#define USB_INTERFACE_DESCRIPTOR_TYPE             0x04
#define USB_ENDPOINT_DESCRIPTOR_TYPE              0x05
#define USB_RESERVED_DESCRIPTOR_TYPE              0x06
#define USB_CONFIG_POWER_DESCRIPTOR_TYPE          0x07
#define USB_INTERFACE_POWER_DESCRIPTOR_TYPE       0x08

#include <pshpack1.h>

typedef struct _USB_DEVICE_DESCRIPTOR {
    UCHAR bLength;
    UCHAR bDescriptorType;
    USHORT bcdUSB;
    UCHAR bDeviceClass;
    UCHAR bDeviceSubClass;
    UCHAR bDeviceProtocol;
    UCHAR bMaxPacketSize0;
    USHORT idVendor;
    USHORT idProduct;
    USHORT bcdDevice;
    UCHAR iManufacturer;
    UCHAR iProduct;
    UCHAR iSerialNumber;
    UCHAR bNumConfigurations;
} USB_DEVICE_DESCRIPTOR;
typedef struct _USB_DEVICE_DESCRIPTOR *PUSB_DEVICE_DESCRIPTOR;

#define USB_ENDPOINT_TYPE_MASK            0x03
#define USB_ENDPOINT_TYPE_CONTROL         0x00
#define USB_ENDPOINT_TYPE_ISOCHRONOUS     0x01
#define USB_ENDPOINT_TYPE_BULK            0x02
#define USB_ENDPOINT_TYPE_INTERRUPT       0x03

typedef struct _USB_ENDPOINT_DESCRIPTOR {
    UCHAR bLength;
    UCHAR bDescriptorType;
    UCHAR bEndpointAddress;
    UCHAR bmAttributes;
    USHORT wMaxPacketSize;
    UCHAR bInterval;
} USB_ENDPOINT_DESCRIPTOR;
typedef struct _USB_ENDPOINT_DESCRIPTOR *PUSB_ENDPOINT_DESCRIPTOR;

typedef struct _USB_CONFIGURATION_DESCRIPTOR {
    UCHAR bLength;
    UCHAR bDescriptorType;
    USHORT wTotalLength;
    UCHAR bNumInterfaces;
    UCHAR bConfigurationValue;
    UCHAR iConfiguration;
    UCHAR bmAttributes;
    UCHAR MaxPower;
} USB_CONFIGURATION_DESCRIPTOR;
typedef struct _USB_CONFIGURATION_DESCRIPTOR *PUSB_CONFIGURATION_DESCRIPTOR;

typedef struct _USB_INTERFACE_DESCRIPTOR {
    UCHAR bLength;
    UCHAR bDescriptorType;
    UCHAR bInterfaceNumber;
    UCHAR bAlternateSetting;
    UCHAR bNumEndpoints;
    UCHAR bInterfaceClass;
    UCHAR bInterfaceSubClass;
    UCHAR bInterfaceProtocol;
    UCHAR iInterface;
} USB_INTERFACE_DESCRIPTOR;
typedef struct _USB_INTERFACE_DESCRIPTOR *PUSB_INTERFACE_DESCRIPTOR;

typedef struct _USB_STRING_DESCRIPTOR {
    UCHAR bLength;
    UCHAR bDescriptorType;
    WCHAR bString[1];
} USB_STRING_DESCRIPTOR;
typedef struct _USB_STRING_DESCRIPTOR *PUSB_STRING_DESCRIPTOR;

typedef struct _USB_COMMON_DESCRIPTOR {
    UCHAR bLength;
    UCHAR bDescriptorType;
} USB_COMMON_DESCRIPTOR;
typedef struct _USB_COMMON_DESCRIPTOR *PUSB_COMMON_DESCRIPTOR;

typedef struct _USB_HUB_DESCRIPTOR {
    UCHAR bDescriptorLength;
    UCHAR bDescriptorType;
    UCHAR bNumberOfPorts;
    USHORT wHubCharacteristics;
    UCHAR bPowerOnToPowerGood;
    UCHAR bHubControlCurrent;
    UCHAR bRemoveAndPowerMask[64];
} USB_HUB_DESCRIPTOR;
typedef struct _USB_HUB_DESCRIPTOR *PUSB_HUB_DESCRIPTOR;

#include <poppack.h>

#endif
