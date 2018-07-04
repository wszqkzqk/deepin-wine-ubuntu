/*
 * Definitions for scsi media access
 *
 * Copyright (C) 2002 Laurent Pinchart
 * Copyright 2005 Ivan Leo Puoti
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

#ifndef _NTDDSCSI_H_
#define _NTDDSCSI_H_

#ifdef __cplusplus
extern "C" {
#endif

#define IOCTL_SCSI_BASE FILE_DEVICE_CONTROLLER

#define IOCTL_SCSI_PASS_THROUGH         CTL_CODE(IOCTL_SCSI_BASE, 0x0401, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_SCSI_MINIPORT             CTL_CODE(IOCTL_SCSI_BASE, 0x0402, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_SCSI_GET_INQUIRY_DATA     CTL_CODE(IOCTL_SCSI_BASE, 0x0403, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCSI_GET_CAPABILITIES     CTL_CODE(IOCTL_SCSI_BASE, 0x0404, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCSI_PASS_THROUGH_DIRECT  CTL_CODE(IOCTL_SCSI_BASE, 0x0405, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_SCSI_GET_ADDRESS          CTL_CODE(IOCTL_SCSI_BASE, 0x0406, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCSI_RESCAN_BUS           CTL_CODE(IOCTL_SCSI_BASE, 0x0407, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCSI_GET_DUMP_POINTERS    CTL_CODE(IOCTL_SCSI_BASE, 0x0408, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCSI_FREE_DUMP_POINTERS   CTL_CODE(IOCTL_SCSI_BASE, 0x0409, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_IDE_PASS_THROUGH          CTL_CODE(IOCTL_SCSI_BASE, 0x040a, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_ATA_PASS_THROUGH          CTL_CODE(IOCTL_SCSI_BASE, 0x040b, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_ATA_PASS_THROUGH_DIRECT   CTL_CODE(IOCTL_SCSI_BASE, 0x040c, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define SCSI_IOCTL_DATA_OUT             0
#define SCSI_IOCTL_DATA_IN              1
#define SCSI_IOCTL_DATA_UNSPECIFIED     2

typedef struct _SCSI_PASS_THROUGH {
    USHORT       Length;
    UCHAR        ScsiStatus;
    UCHAR        PathId;
    UCHAR        TargetId;
    UCHAR        Lun;
    UCHAR        CdbLength;
    UCHAR        SenseInfoLength;
    UCHAR        DataIn;
    ULONG        DataTransferLength;
    ULONG        TimeOutValue;
    ULONG_PTR    DataBufferOffset;
    ULONG        SenseInfoOffset;
    UCHAR        Cdb[16];
} SCSI_PASS_THROUGH, *PSCSI_PASS_THROUGH;

typedef struct _SCSI_PASS_THROUGH_DIRECT {
    USHORT       Length;
    UCHAR        ScsiStatus;
    UCHAR        PathId;
    UCHAR        TargetId;
    UCHAR        Lun;
    UCHAR        CdbLength;
    UCHAR        SenseInfoLength;
    UCHAR        DataIn;
    ULONG        DataTransferLength;
    ULONG        TimeOutValue;
    PVOID        DataBuffer;
    ULONG        SenseInfoOffset;
    UCHAR        Cdb[16];
} SCSI_PASS_THROUGH_DIRECT, *PSCSI_PASS_THROUGH_DIRECT;

typedef struct _SCSI_ADDRESS {
    ULONG        Length;
    UCHAR        PortNumber;
    UCHAR        PathId;
    UCHAR        TargetId;
    UCHAR        Lun;
} SCSI_ADDRESS, *PSCSI_ADDRESS;

typedef struct _IO_SCSI_CAPABILITIES {
    ULONG       Length;
    ULONG       MaximumTransferLength;
    ULONG       MaximumPhysicalPages;
    ULONG       SupportedAsynchronousEvents;
    ULONG       AlignmentMask;
    BOOLEAN     TaggedQueuing;
    BOOLEAN     AdapterScansDown;
    BOOLEAN     AdapterUsesPio;
} IO_SCSI_CAPABILITIES, *PIO_SCSI_CAPABILITIES;

typedef struct _SCSI_BUS_DATA {
    UCHAR NumberOfLogicalUnits;
    UCHAR InitiatorBusId;
    ULONG InquiryDataOffset;
} SCSI_BUS_DATA, *PSCSI_BUS_DATA;

typedef struct _SCSI_ADAPTER_BUS_INFO {
    UCHAR NumberOfBuses;
    SCSI_BUS_DATA BusData[1];
} SCSI_ADAPTER_BUS_INFO, *PSCSI_ADAPTER_BUS_INFO;

typedef struct _SCSI_INQUIRY_DATA {
    UCHAR PathId;
    UCHAR TargetId;
    UCHAR Lun;
    BOOLEAN DeviceClaimed;
    ULONG InquiryDataLength;
    ULONG NextInquiryDataOffset;
    UCHAR InquiryData[1];
} SCSI_INQUIRY_DATA, *PSCSI_INQUIRY_DATA;

#ifdef __cplusplus
}
#endif

#endif /* _NTDDSCSI_H_ */
