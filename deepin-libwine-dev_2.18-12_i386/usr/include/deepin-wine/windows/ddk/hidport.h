/*
 * Copyright (C) 2015 Aric Stewart
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

#ifndef __HIDPORT_H__
#define __HIDPORT_H__

#include <ddk/hidclass.h>

typedef struct _HID_MINIDRIVER_REGISTRATION
{
    ULONG           Revision;
    PDRIVER_OBJECT  DriverObject;
    PUNICODE_STRING RegistryPath;
    ULONG           DeviceExtensionSize;
    BOOLEAN         DevicesArePolled;
    UCHAR           Reserved[3];
} HID_MINIDRIVER_REGISTRATION, *PHID_MINIDRIVER_REGISTRATION;

NTSTATUS WINAPI HidRegisterMinidriver(PHID_MINIDRIVER_REGISTRATION MinidriverRegistration);

typedef struct _HID_DEVICE_EXTENSION
{
    PDEVICE_OBJECT PhysicalDeviceObject;
    PDEVICE_OBJECT NextDeviceObject;
    PVOID          MiniDeviceExtension;
} HID_DEVICE_EXTENSION, *PHID_DEVICE_EXTENSION;

typedef struct _HID_DEVICE_ATTRIBUTES
{
    ULONG  Size;
    USHORT VendorID;
    USHORT ProductID;
    USHORT VersionNumber;
    USHORT Reserved[11];
} HID_DEVICE_ATTRIBUTES, *PHID_DEVICE_ATTRIBUTES;

typedef struct _HID_DESCRIPTOR
{
    UCHAR   bLength;
    UCHAR   bDescriptorType;
    USHORT  bcdHID;
    UCHAR   bCountry;
    UCHAR   bNumDescriptors;
    struct _HID_DESCRIPTOR_DESC_LIST
    {
        UCHAR   bReportType;
        USHORT  wReportLength;
    } DescriptorList[1];
} HID_DESCRIPTOR, *PHID_DESCRIPTOR;

#define HID_HID_DESCRIPTOR_TYPE 0x21
#define HID_REPORT_DESCRIPTOR_TYPE 0x22

#define IOCTL_HID_GET_DEVICE_DESCRIPTOR          HID_CTL_CODE(0)
#define IOCTL_HID_GET_REPORT_DESCRIPTOR          HID_CTL_CODE(1)
#define IOCTL_HID_READ_REPORT                    HID_CTL_CODE(2)
#define IOCTL_HID_WRITE_REPORT                   HID_CTL_CODE(3)
#define IOCTL_HID_GET_STRING                     HID_CTL_CODE(4)
#define IOCTL_HID_ACTIVATE_DEVICE                HID_CTL_CODE(7)
#define IOCTL_HID_DEACTIVATE_DEVICE              HID_CTL_CODE(8)
#define IOCTL_HID_GET_DEVICE_ATTRIBUTES          HID_CTL_CODE(9)
#define IOCTL_HID_SEND_IDLE_NOTIFICATION_REQUEST HID_CTL_CODE(10)

#endif /* __HIDPORT_H__ */
