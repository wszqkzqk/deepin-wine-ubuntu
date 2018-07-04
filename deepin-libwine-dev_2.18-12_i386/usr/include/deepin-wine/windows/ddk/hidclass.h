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
#ifndef __HIDCLASS_H
#define __HIDCLASS_H

#ifdef __cplusplus
extern "C" {
#endif

#define HID_REVISION 1

DEFINE_GUID (GUID_DEVINTERFACE_HID, \
  0x4D1E55B2L, 0xF16F, 0x11CF, 0x88, 0xCB, 0x00, 0x11, 0x11, 0x00, 0x00, 0x30);

#define HID_CTL_CODE(id) \
  CTL_CODE (FILE_DEVICE_KEYBOARD, (id), METHOD_NEITHER, FILE_ANY_ACCESS)
#define HID_BUFFER_CTL_CODE(id) \
  CTL_CODE (FILE_DEVICE_KEYBOARD, (id), METHOD_BUFFERED, FILE_ANY_ACCESS)
#define HID_IN_CTL_CODE(id) \
  CTL_CODE (FILE_DEVICE_KEYBOARD, (id), METHOD_IN_DIRECT, FILE_ANY_ACCESS)
#define HID_OUT_CTL_CODE(id) \
  CTL_CODE (FILE_DEVICE_KEYBOARD, (id), METHOD_OUT_DIRECT, FILE_ANY_ACCESS)

#define IOCTL_GET_PHYSICAL_DESCRIPTOR         HID_OUT_CTL_CODE(102)
#define IOCTL_HID_FLUSH_QUEUE                 HID_CTL_CODE(101)
#define IOCTL_HID_GET_COLLECTION_DESCRIPTOR   HID_CTL_CODE(100)
#define IOCTL_HID_GET_COLLECTION_INFORMATION  HID_BUFFER_CTL_CODE(106)
#define IOCTL_HID_GET_FEATURE                 HID_OUT_CTL_CODE(100)
#define IOCTL_HID_GET_HARDWARE_ID             HID_OUT_CTL_CODE(103)
#define IOCTL_HID_GET_INDEXED_STRING          HID_OUT_CTL_CODE(120)
#define IOCTL_HID_GET_INPUT_REPORT            HID_OUT_CTL_CODE(104)
#define IOCTL_HID_GET_MANUFACTURER_STRING     HID_OUT_CTL_CODE(110)
#define IOCTL_GET_NUM_DEVICE_INPUT_BUFFERS    HID_BUFFER_CTL_CODE(104)
#define IOCTL_HID_GET_POLL_FREQUENCY_MSEC     HID_BUFFER_CTL_CODE(102)
#define IOCTL_HID_GET_PRODUCT_STRING          HID_OUT_CTL_CODE(111)
#define IOCTL_HID_GET_SERIALNUMBER_STRING     HID_OUT_CTL_CODE(112)
#define IOCTL_HID_SET_FEATURE                 HID_IN_CTL_CODE(100)
#define IOCTL_SET_NUM_DEVICE_INPUT_BUFFERS    HID_BUFFER_CTL_CODE(105)
#define IOCTL_HID_SET_OUTPUT_REPORT           HID_IN_CTL_CODE(101)
#define IOCTL_HID_SET_POLL_FREQUENCY_MSEC     HID_BUFFER_CTL_CODE(103)

#define IOCTL_HID_GET_DRIVER_CONFIG           HID_BUFFER_CTL_CODE(100)
#define IOCTL_HID_SET_DRIVER_CONFIG           HID_BUFFER_CTL_CODE(101)
#define IOCTL_HID_GET_MS_GENRE_DESCRIPTOR     HID_OUT_CTL_CODE(121)

typedef struct _HID_COLLECTION_INFORMATION {
    ULONG   DescriptorSize;
    BOOLEAN Polled;
    UCHAR   Reserved1[1];
    USHORT  VendorID;
    USHORT  ProductID;
    USHORT  VersionNumber;
} HID_COLLECTION_INFORMATION, *PHID_COLLECTION_INFORMATION;

typedef struct _HID_XFER_PACKET {
  PUCHAR reportBuffer;
  ULONG  reportBufferLen;
  UCHAR  reportId;
} HID_XFER_PACKET, *PHID_XFER_PACKET;

#ifdef __cplusplus
}
#endif

#endif /* __HIDCLASS_H */
