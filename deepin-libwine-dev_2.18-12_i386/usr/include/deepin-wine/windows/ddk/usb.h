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

#ifndef __DDK_USB_H__
#define __DDK_USB_H__

#include <ddk/usb200.h>

#define URB_FUNCTION_SELECT_CONFIGURATION            0x0000
#define URB_FUNCTION_SELECT_INTERFACE                0x0001
#define URB_FUNCTION_ABORT_PIPE                      0x0002
#define URB_FUNCTION_TAKE_FRAME_LENGTH_CONTROL       0x0003
#define URB_FUNCTION_RELEASE_FRAME_LENGTH_CONTROL    0x0004
#define URB_FUNCTION_GET_FRAME_LENGTH                0x0005
#define URB_FUNCTION_SET_FRAME_LENGTH                0x0006
#define URB_FUNCTION_GET_CURRENT_FRAME_NUMBER        0x0007
#define URB_FUNCTION_CONTROL_TRANSFER                0x0008
#define URB_FUNCTION_BULK_OR_INTERRUPT_TRANSFER      0x0009
#define URB_FUNCTION_ISOCH_TRANSFER                  0x000A
#define URB_FUNCTION_GET_DESCRIPTOR_FROM_DEVICE      0x000B
#define URB_FUNCTION_SET_DESCRIPTOR_TO_DEVICE        0x000C
#define URB_FUNCTION_SET_FEATURE_TO_DEVICE           0x000D
#define URB_FUNCTION_SET_FEATURE_TO_INTERFACE        0x000E
#define URB_FUNCTION_SET_FEATURE_TO_ENDPOINT         0x000F
#define URB_FUNCTION_CLEAR_FEATURE_TO_DEVICE         0x0010
#define URB_FUNCTION_CLEAR_FEATURE_TO_INTERFACE      0x0011
#define URB_FUNCTION_CLEAR_FEATURE_TO_ENDPOINT       0x0012
#define URB_FUNCTION_GET_STATUS_FROM_DEVICE          0x0013
#define URB_FUNCTION_GET_STATUS_FROM_INTERFACE       0x0014
#define URB_FUNCTION_GET_STATUS_FROM_ENDPOINT        0x0015
#define URB_FUNCTION_RESERVED_0X0016                 0x0016
#define URB_FUNCTION_VENDOR_DEVICE                   0x0017
#define URB_FUNCTION_VENDOR_INTERFACE                0x0018
#define URB_FUNCTION_VENDOR_ENDPOINT                 0x0019
#define URB_FUNCTION_CLASS_DEVICE                    0x001A
#define URB_FUNCTION_CLASS_INTERFACE                 0x001B
#define URB_FUNCTION_CLASS_ENDPOINT                  0x001C
#define URB_FUNCTION_RESERVE_0X001D                  0x001D
#define URB_FUNCTION_SYNC_RESET_PIPE_AND_CLEAR_STALL 0x001E
#define URB_FUNCTION_CLASS_OTHER                     0x001F
#define URB_FUNCTION_VENDOR_OTHER                    0x0020
#define URB_FUNCTION_GET_STATUS_FROM_OTHER           0x0021
#define URB_FUNCTION_CLEAR_FEATURE_TO_OTHER          0x0022
#define URB_FUNCTION_SET_FEATURE_TO_OTHER            0x0023
#define URB_FUNCTION_GET_DESCRIPTOR_FROM_ENDPOINT    0x0024
#define URB_FUNCTION_SET_DESCRIPTOR_TO_ENDPOINT      0x0025
#define URB_FUNCTION_GET_CONFIGURATION               0x0026
#define URB_FUNCTION_GET_INTERFACE                   0x0027
#define URB_FUNCTION_GET_DESCRIPTOR_FROM_INTERFACE   0x0028
#define URB_FUNCTION_SET_DESCRIPTOR_TO_INTERFACE     0x0029
#define URB_FUNCTION_GET_MS_FEATURE_DESCRIPTOR       0x002A
#define URB_FUNCTION_RESERVE_0X002B                  0x002B
#define URB_FUNCTION_RESERVE_0X002C                  0x002C
#define URB_FUNCTION_RESERVE_0X002D                  0x002D
#define URB_FUNCTION_RESERVE_0X002E                  0x002E
#define URB_FUNCTION_RESERVE_0X002F                  0x002F
#define URB_FUNCTION_SYNC_RESET_PIPE                 0x0030
#define URB_FUNCTION_SYNC_CLEAR_STALL                0x0031

#define USBD_SHORT_TRANSFER_OK                       0x00000002
#define USBD_TRANSFER_DIRECTION_OUT                  0
#define USBD_TRANSFER_DIRECTION_IN                   1

typedef LONG USBD_STATUS;

typedef PVOID USBD_PIPE_HANDLE;
typedef PVOID USBD_CONFIGURATION_HANDLE;
typedef PVOID USBD_INTERFACE_HANDLE;

#define USBD_STATUS_SUCCESS                          ((USBD_STATUS)0x00000000)
#define USBD_STATUS_PENDING                          ((USBD_STATUS)0x40000000)
#define USBD_STATUS_ERROR                            ((USBD_STATUS)0x80000000)
#define USBD_STATUS_HALTED                           ((USBD_STATUS)0xC0000000)

#define USBD_STATUS_CANCELED                         ((USBD_STATUS)0x00010000)
#define USBD_STATUS_CANCELING                        ((USBD_STATUS)0x00020000)
#define USBD_STATUS_CRC                              ((USBD_STATUS)0xC0000001)
#define USBD_STATUS_BTSTUFF                          ((USBD_STATUS)0xC0000002)
#define USBD_STATUS_DATA_TOGGLE_MISMATCH             ((USBD_STATUS)0xC0000003)
#define USBD_STATUS_STALL_PID                        ((USBD_STATUS)0xC0000004)
#define USBD_STATUS_DEV_NOT_RESPONDING               ((USBD_STATUS)0xC0000005)
#define USBD_STATUS_PID_CHECK_FAILURE                ((USBD_STATUS)0xC0000006)
#define USBD_STATUS_UNEXPECTED_PID                   ((USBD_STATUS)0xC0000007)
#define USBD_STATUS_DATA_OVERRUN                     ((USBD_STATUS)0xC0000008)
#define USBD_STATUS_DATA_UNDERRUN                    ((USBD_STATUS)0xC0000009)
#define USBD_STATUS_RESERVED1                        ((USBD_STATUS)0xC000000A)
#define USBD_STATUS_RESERVED2                        ((USBD_STATUS)0xC000000B)
#define USBD_STATUS_BUFFER_OVERRUN                   ((USBD_STATUS)0xC000000C)
#define USBD_STATUS_BUFFER_UNDERRUN                  ((USBD_STATUS)0xC000000D)
#define USBD_STATUS_NOT_ACCESSED                     ((USBD_STATUS)0xC000000F)
#define USBD_STATUS_FIFO                             ((USBD_STATUS)0xC0000010)
#define USBD_STATUS_XACT_ERROR                       ((USBD_STATUS)0xC0000011)
#define USBD_STATUS_BABBLE_DETECTED                  ((USBD_STATUS)0xC0000012)
#define USBD_STATUS_DATA_BUFFER_ERROR                ((USBD_STATUS)0xC0000013)
#define USBD_STATUS_ENDPOINT_HALTED                  ((USBD_STATUS)0xC0000030)
#define USBD_STATUS_NO_MEMORY                        ((USBD_STATUS)0x80000100)
#define USBD_STATUS_INVALID_URB_FUNCTION             ((USBD_STATUS)0x80000200)
#define USBD_STATUS_INVALID_PARAMETER                ((USBD_STATUS)0x80000300)
#define USBD_STATUS_ERROR_BUSY                       ((USBD_STATUS)0x80000400)
#define USBD_STATUS_REQUEST_FAILED                   ((USBD_STATUS)0x80000500)
#define USBD_STATUS_INVALID_PIPE_HANDLE              ((USBD_STATUS)0x80000600)
#define USBD_STATUS_NO_BANDWIDTH                     ((USBD_STATUS)0x80000700)
#define USBD_STATUS_INTERNAL_HC_ERROR                ((USBD_STATUS)0x80000800)
#define USBD_STATUS_ERROR_SHORT_TRANSFER             ((USBD_STATUS)0x80000900)
#define USBD_STATUS_BAD_START_FRAME                  ((USBD_STATUS)0xC0000A00)
#define USBD_STATUS_ISOCH_REQUEST_FAILED             ((USBD_STATUS)0xC0000B00)
#define USBD_STATUS_FRAME_CONTROL_OWNED              ((USBD_STATUS)0xC0000C00)
#define USBD_STATUS_FRAME_CONTROL_NOT_OWNED          ((USBD_STATUS)0xC0000D00)
#define USBD_STATUS_NOT_SUPPORTED                    ((USBD_STATUS)0xC0000E00)
#define USBD_STATUS_INVALID_CONFIGURATION_DESCRIPTOR ((USBD_STATUS)0xC0000F00)
#define USBD_STATUS_INSUFFICIENT_RESOURCES           ((USBD_STATUS)0xC0001000)
#define USBD_STATUS_SET_CONFIG_FAILED                ((USBD_STATUS)0xC0002000)
#define USBD_STATUS_BUFFER_TOO_SMALL                 ((USBD_STATUS)0xC0003000)
#define USBD_STATUS_INTERFACE_NOT_FOUND              ((USBD_STATUS)0xC0004000)
#define USBD_STATUS_INVALID_PIPE_FLAGS               ((USBD_STATUS)0xC0005000)
#define USBD_STATUS_TIMEOUT                          ((USBD_STATUS)0xC0006000)
#define USBD_STATUS_DEVICE_GONE                      ((USBD_STATUS)0xC0007000)
#define USBD_STATUS_STATUS_NOT_MAPPED                ((USBD_STATUS)0xC0008000)
#define USBD_STATUS_ISO_NOT_ACCESSED_BY_HW           ((USBD_STATUS)0xC0020000)
#define USBD_STATUS_ISO_TD_ERROR                     ((USBD_STATUS)0xC0030000)
#define USBD_STATUS_ISO_NA_LATE_USBPORT              ((USBD_STATUS)0xC0040000)
#define USBD_STATUS_ISO_NOT_ACCESSED_LATE            ((USBD_STATUS)0xC0050000)

#define USBD_SUCCESS(Status) ((USBD_STATUS)(Status) >= 0)
#define USBD_PENDING(Status) ((ULONG)(Status) >> 30 == 1)
#define USBD_ERROR(Status)   ((USBD_STATUS)(Status) < 0)

typedef struct _USBD_VERSION_INFORMATION {
    ULONG  USBDI_Version;
    ULONG  Supported_USB_Version;
} USBD_VERSION_INFORMATION;
typedef struct _USBD_VERSION_INFORMATION *PUSBD_VERSION_INFORMATION;

typedef enum _USBD_PIPE_TYPE {
    UsbdPipeTypeControl,
    UsbdPipeTypeIsochronous,
    UsbdPipeTypeBulk,
    UsbdPipeTypeInterrupt
} USBD_PIPE_TYPE;

typedef struct _USBD_PIPE_INFORMATION {
    USHORT MaximumPacketSize;
    UCHAR EndpointAddress;
    UCHAR Interval;
    USBD_PIPE_TYPE PipeType;
    USBD_PIPE_HANDLE PipeHandle;
    ULONG MaximumTransferSize;
    ULONG PipeFlags;
} USBD_PIPE_INFORMATION;
typedef struct _USBD_PIPE_INFORMATION *PUSBD_PIPE_INFORMATION;

typedef struct _USBD_INTERFACE_INFORMATION {
    USHORT Length;
    UCHAR InterfaceNumber;
    UCHAR AlternateSetting;
    UCHAR Class;
    UCHAR SubClass;
    UCHAR Protocol;
    UCHAR Reserved;
    USBD_INTERFACE_HANDLE InterfaceHandle;
    ULONG NumberOfPipes;
    USBD_PIPE_INFORMATION Pipes[1];
} USBD_INTERFACE_INFORMATION;
typedef struct _USBD_INTERFACE_INFORMATION *PUSBD_INTERFACE_INFORMATION;

typedef struct _USBD_ISO_PACKET_DESCRIPTOR {
    ULONG Offset;
    ULONG Length;
    USBD_STATUS Status;
} USBD_ISO_PACKET_DESCRIPTOR;
typedef struct _USBD_ISO_PACKET_DESCRIPTOR *PUSBD_ISO_PACKET_DESCRIPTOR;

struct _URB_HCD_AREA {
    PVOID Reserved8[8];
};

struct _URB_HEADER {
    USHORT Length;
    USHORT Function;
    USBD_STATUS Status;
    PVOID UsbdDeviceHandle;
    ULONG UsbdFlags;
};

struct _URB_SELECT_INTERFACE {
    struct _URB_HEADER Hdr;
    USBD_CONFIGURATION_HANDLE ConfigurationHandle;
    USBD_INTERFACE_INFORMATION Interface;
};

struct _URB_SELECT_CONFIGURATION {
    struct _URB_HEADER Hdr;
    PUSB_CONFIGURATION_DESCRIPTOR ConfigurationDescriptor;
    USBD_CONFIGURATION_HANDLE ConfigurationHandle;
    USBD_INTERFACE_INFORMATION Interface;
};

struct _URB_PIPE_REQUEST {
    struct _URB_HEADER Hdr;
    USBD_PIPE_HANDLE PipeHandle;
    ULONG Reserved;
};

struct _URB_FRAME_LENGTH_CONTROL {
    struct _URB_HEADER Hdr;
};

struct _URB_GET_FRAME_LENGTH {
    struct _URB_HEADER Hdr;
    ULONG FrameLength;
    ULONG FrameNumber;
};

struct _URB_SET_FRAME_LENGTH {
    struct _URB_HEADER Hdr;
    LONG FrameLengthDelta;
};

struct _URB_GET_CURRENT_FRAME_NUMBER {
    struct _URB_HEADER Hdr;
    ULONG FrameNumber;
};

struct _URB_CONTROL_TRANSFER {
    struct _URB_HEADER Hdr;
    USBD_PIPE_HANDLE PipeHandle;
    ULONG TransferFlags;
    ULONG TransferBufferLength;
    PVOID TransferBuffer;
    PMDL TransferBufferMDL;
    struct _URB *UrbLink;
    struct _URB_HCD_AREA hca;
    UCHAR SetupPacket[8];
};

struct _URB_BULK_OR_INTERRUPT_TRANSFER {
    struct _URB_HEADER Hdr;
    USBD_PIPE_HANDLE PipeHandle;
    ULONG TransferFlags;
    ULONG TransferBufferLength;
    PVOID TransferBuffer;
    PMDL TransferBufferMDL;
    struct _URB *UrbLink;
    struct _URB_HCD_AREA hca;
};

struct _URB_ISOCH_TRANSFER {
    struct _URB_HEADER Hdr;
    USBD_PIPE_HANDLE PipeHandle;
    ULONG TransferFlags;
    ULONG TransferBufferLength;
    PVOID TransferBuffer;
    PMDL TransferBufferMDL;
    struct _URB *UrbLink;
    struct _URB_HCD_AREA hca;
    ULONG StartFrame;
    ULONG NumberOfPackets;
    ULONG ErrorCount;
    USBD_ISO_PACKET_DESCRIPTOR IsoPacket[1];
};

struct _URB_CONTROL_DESCRIPTOR_REQUEST {
    struct _URB_HEADER Hdr;
    PVOID Reserved;
    ULONG Reserved0;
    ULONG TransferBufferLength;
    PVOID TransferBuffer;
    PMDL TransferBufferMDL;
    struct _URB *UrbLink;
    struct _URB_HCD_AREA hca;
    USHORT Reserved1;
    UCHAR Index;
    UCHAR DescriptorType;
    USHORT LanguageId;
    USHORT Reserved2;
};

struct _URB_CONTROL_GET_STATUS_REQUEST {
    struct _URB_HEADER Hdr;
    PVOID Reserved;
    ULONG Reserved0;
    ULONG TransferBufferLength;
    PVOID TransferBuffer;
    PMDL TransferBufferMDL;
    struct _URB *UrbLink;
    struct _URB_HCD_AREA hca;
    UCHAR Reserved1[4];
    USHORT Index;
    USHORT Reserved2;
};

struct _URB_CONTROL_FEATURE_REQUEST {
    struct _URB_HEADER Hdr;
    PVOID Reserved;
    ULONG Reserved2;
    ULONG Reserved3;
    PVOID Reserved4;
    PMDL Reserved5;
    struct _URB *UrbLink;
    struct _URB_HCD_AREA hca;
    USHORT Reserved0;
    USHORT FeatureSelector;
    USHORT Index;
    USHORT Reserved1;
};

struct _URB_CONTROL_VENDOR_OR_CLASS_REQUEST {
    struct _URB_HEADER Hdr;
    PVOID Reserved;
    ULONG TransferFlags;
    ULONG TransferBufferLength;
    PVOID TransferBuffer;
    PMDL TransferBufferMDL;
    struct _URB *UrbLink;
    struct _URB_HCD_AREA hca;
    UCHAR RequestTypeReservedBits;
    UCHAR Request;
    USHORT Value;
    USHORT Index;
    USHORT Reserved1;
};

struct _URB_CONTROL_GET_INTERFACE_REQUEST {
    struct _URB_HEADER Hdr;
    PVOID Reserved;
    ULONG Reserved0;
    ULONG TransferBufferLength;
    PVOID TransferBuffer;
    PMDL TransferBufferMDL;
    struct _URB *UrbLink;
    struct _URB_HCD_AREA hca;
    UCHAR Reserved1[4];
    USHORT Interface;
    USHORT Reserved2;
};

struct _URB_CONTROL_GET_CONFIGURATION_REQUEST {
    struct _URB_HEADER Hdr;
    PVOID Reserved;
    ULONG Reserved0;
    ULONG TransferBufferLength;
    PVOID TransferBuffer;
    PMDL TransferBufferMDL;
    struct _URB *UrbLink;
    struct _URB_HCD_AREA hca;
    UCHAR Reserved1[8];
};

struct _URB_OS_FEATURE_DESCRIPTOR_REQUEST {
    struct _URB_HEADER Hdr;
    PVOID Reserved;
    ULONG Reserved0;
    ULONG TransferBufferLength;
    PVOID TransferBuffer;
    PMDL TransferBufferMDL;
    struct _URB *UrbLink;
    struct _URB_HCD_AREA hca;
    UCHAR   Recipient:5;
    UCHAR   Reserved1:3;
    UCHAR   Reserved2;
    UCHAR   InterfaceNumber;
    UCHAR   MS_PageIndex;
    USHORT  MS_FeatureDescriptorIndex;
    USHORT  Reserved3;
};

typedef struct _URB {
    union {
        struct _URB_HEADER UrbHeader;
        struct _URB_SELECT_INTERFACE UrbSelectInterface;
        struct _URB_SELECT_CONFIGURATION UrbSelectConfiguration;
        struct _URB_PIPE_REQUEST UrbPipeRequest;
        struct _URB_FRAME_LENGTH_CONTROL UrbFrameLengthControl;
        struct _URB_GET_FRAME_LENGTH UrbGetFrameLength;
        struct _URB_SET_FRAME_LENGTH UrbSetFrameLength;
        struct _URB_GET_CURRENT_FRAME_NUMBER UrbGetCurrentFrameNumber;
        struct _URB_CONTROL_TRANSFER UrbControlTransfer;
        struct _URB_BULK_OR_INTERRUPT_TRANSFER UrbBulkOrInterruptTransfer;
        struct _URB_ISOCH_TRANSFER UrbIsochronousTransfer;
        struct _URB_CONTROL_DESCRIPTOR_REQUEST UrbControlDescriptorRequest;
        struct _URB_CONTROL_GET_STATUS_REQUEST UrbControlGetStatusRequest;
        struct _URB_CONTROL_FEATURE_REQUEST UrbControlFeatureRequest;
        struct _URB_CONTROL_VENDOR_OR_CLASS_REQUEST UrbControlVendorClassRequest;
        struct _URB_CONTROL_GET_INTERFACE_REQUEST UrbControlGetInterfaceRequest;
        struct _URB_CONTROL_GET_CONFIGURATION_REQUEST UrbControlGetConfigurationRequest;
        struct _URB_OS_FEATURE_DESCRIPTOR_REQUEST UrbOSFeatureDescriptorRequest;
    } DUMMYUNIONNAME;
} URB;
typedef struct _URB *PURB;

#endif
