/*
 * DDK information for CD ROM
 *
 * Copyright (C) 2002 Eric Pouech
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

#ifndef __NTDDCDRM_H
#define __NTDDCDRM_H

#define IOCTL_CDROM_BASE                FILE_DEVICE_CD_ROM
#define IOCTL_CDROM_UNLOAD_DRIVER       CTL_CODE(IOCTL_CDROM_BASE, 0x0402, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_READ_TOC            CTL_CODE(IOCTL_CDROM_BASE, 0x0000, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_GET_CONTROL         CTL_CODE(IOCTL_CDROM_BASE, 0x000D, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_PLAY_AUDIO_MSF      CTL_CODE(IOCTL_CDROM_BASE, 0x0006, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_SEEK_AUDIO_MSF      CTL_CODE(IOCTL_CDROM_BASE, 0x0001, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_STOP_AUDIO          CTL_CODE(IOCTL_CDROM_BASE, 0x0002, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_PAUSE_AUDIO         CTL_CODE(IOCTL_CDROM_BASE, 0x0003, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_RESUME_AUDIO        CTL_CODE(IOCTL_CDROM_BASE, 0x0004, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_GET_VOLUME          CTL_CODE(IOCTL_CDROM_BASE, 0x0005, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_SET_VOLUME          CTL_CODE(IOCTL_CDROM_BASE, 0x000A, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_READ_Q_CHANNEL      CTL_CODE(IOCTL_CDROM_BASE, 0x000B, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_GET_LAST_SESSION    CTL_CODE(IOCTL_CDROM_BASE, 0x000E, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_RAW_READ            CTL_CODE(IOCTL_CDROM_BASE, 0x000F, METHOD_OUT_DIRECT,  FILE_READ_ACCESS)
#define IOCTL_CDROM_DISK_TYPE           CTL_CODE(IOCTL_CDROM_BASE, 0x0010, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_CDROM_GET_DRIVE_GEOMETRY  CTL_CODE(IOCTL_CDROM_BASE, 0x0013, METHOD_BUFFERED, FILE_READ_ACCESS)

#define IOCTL_CDROM_CHECK_VERIFY        CTL_CODE(IOCTL_CDROM_BASE, 0x0200, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_MEDIA_REMOVAL       CTL_CODE(IOCTL_CDROM_BASE, 0x0201, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_EJECT_MEDIA         CTL_CODE(IOCTL_CDROM_BASE, 0x0202, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_LOAD_MEDIA          CTL_CODE(IOCTL_CDROM_BASE, 0x0203, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_RESERVE             CTL_CODE(IOCTL_CDROM_BASE, 0x0204, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_RELEASE             CTL_CODE(IOCTL_CDROM_BASE, 0x0205, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_CDROM_FIND_NEW_DEVICES    CTL_CODE(IOCTL_CDROM_BASE, 0x0206, METHOD_BUFFERED, FILE_READ_ACCESS)

#include <ntddstor.h>

#define MAXIMUM_NUMBER_TRACKS 100
#define MAXIMUM_CDROM_SIZE 804

typedef struct _TRACK_DATA {
    UCHAR               Reserved;
    UCHAR               Control : 4;
    UCHAR               Adr : 4;
    UCHAR               TrackNumber;
    UCHAR               Reserved1;
    UCHAR               Address[4];
} TRACK_DATA, *PTRACK_DATA;

typedef struct _CDROM_TOC {
    UCHAR               Length[2];
    UCHAR               FirstTrack;
    UCHAR               LastTrack;
    TRACK_DATA TrackData[MAXIMUM_NUMBER_TRACKS];
} CDROM_TOC, *PCDROM_TOC;

#define CDROM_TOC_SIZE sizeof(CDROM_TOC)

typedef struct _CDROM_PLAY_AUDIO_MSF {
    UCHAR               StartingM;
    UCHAR               StartingS;
    UCHAR               StartingF;
    UCHAR               EndingM;
    UCHAR               EndingS;
    UCHAR               EndingF;
} CDROM_PLAY_AUDIO_MSF, *PCDROM_PLAY_AUDIO_MSF;

typedef struct _CDROM_SEEK_AUDIO_MSF {
    UCHAR               M;
    UCHAR               S;
    UCHAR               F;
} CDROM_SEEK_AUDIO_MSF, *PCDROM_SEEK_AUDIO_MSF;

typedef struct _CDROM_DISK_DATA {
    ULONG               DiskData;
} CDROM_DISK_DATA, *PCDROM_DISK_DATA;

#define CDROM_DISK_AUDIO_TRACK      (0x00000001)
#define CDROM_DISK_DATA_TRACK       (0x00000002)

#define IOCTL_CDROM_SUB_Q_CHANNEL    0x00
#define IOCTL_CDROM_CURRENT_POSITION 0x01
#define IOCTL_CDROM_MEDIA_CATALOG    0x02
#define IOCTL_CDROM_TRACK_ISRC       0x03

typedef struct _CDROM_SUB_Q_DATA_FORMAT {
    UCHAR               Format;
    UCHAR               Track;
} CDROM_SUB_Q_DATA_FORMAT, *PCDROM_SUB_Q_DATA_FORMAT;

typedef struct _SUB_Q_HEADER {
    UCHAR               Reserved;
    UCHAR               AudioStatus;
    UCHAR               DataLength[2];
} SUB_Q_HEADER, *PSUB_Q_HEADER;

typedef struct _SUB_Q_CURRENT_POSITION {
    SUB_Q_HEADER        Header;
    UCHAR               FormatCode;
    UCHAR               Control : 4;
    UCHAR               ADR : 4;
    UCHAR               TrackNumber;
    UCHAR               IndexNumber;
    UCHAR               AbsoluteAddress[4];
    UCHAR               TrackRelativeAddress[4];
} SUB_Q_CURRENT_POSITION, *PSUB_Q_CURRENT_POSITION;

typedef struct _SUB_Q_MEDIA_CATALOG_NUMBER {
    SUB_Q_HEADER        Header;
    UCHAR               FormatCode;
    UCHAR               Reserved[3];
    UCHAR               Reserved1 : 7;
    UCHAR               Mcval : 1;
    UCHAR               MediaCatalog[15];
} SUB_Q_MEDIA_CATALOG_NUMBER, *PSUB_Q_MEDIA_CATALOG_NUMBER;

typedef struct _SUB_Q_TRACK_ISRC {
    SUB_Q_HEADER        Header;
    UCHAR               FormatCode;
    UCHAR               Reserved0;
    UCHAR               Track;
    UCHAR               Reserved1;
    UCHAR               Reserved2 : 7;
    UCHAR               Tcval : 1;
    UCHAR               TrackIsrc[15];
} SUB_Q_TRACK_ISRC, *PSUB_Q_TRACK_ISRC;

typedef union _SUB_Q_CHANNEL_DATA {
    SUB_Q_CURRENT_POSITION      CurrentPosition;
    SUB_Q_MEDIA_CATALOG_NUMBER  MediaCatalog;
    SUB_Q_TRACK_ISRC            TrackIsrc;
} SUB_Q_CHANNEL_DATA, *PSUB_Q_CHANNEL_DATA;

#define AUDIO_STATUS_NOT_SUPPORTED      0x00
#define AUDIO_STATUS_IN_PROGRESS        0x11
#define AUDIO_STATUS_PAUSED             0x12
#define AUDIO_STATUS_PLAY_COMPLETE      0x13
#define AUDIO_STATUS_PLAY_ERROR         0x14
#define AUDIO_STATUS_NO_STATUS          0x15

#define ADR_NO_MODE_INFORMATION         0x0
#define ADR_ENCODES_CURRENT_POSITION    0x1
#define ADR_ENCODES_MEDIA_CATALOG       0x2
#define ADR_ENCODES_ISRC                0x3

#define AUDIO_WITH_PREEMPHASIS          0x0
#define DIGITAL_COPY_PERMITTED          0x2
#define AUDIO_DATA_TRACK                0x4
#define TWO_FOUR_CHANNEL_AUDIO          0x8

typedef struct _CDROM_AUDIO_CONTROL {
    UCHAR               LbaFormat;
    USHORT              LogicalBlocksPerSecond;
} CDROM_AUDIO_CONTROL, *PCDROM_AUDIO_CONTROL;

typedef struct _VOLUME_CONTROL {
    UCHAR               PortVolume[4];
} VOLUME_CONTROL, *PVOLUME_CONTROL;

typedef enum _TRACK_MODE_TYPE {
    YellowMode2,
    XAForm2,
    CDDA
} TRACK_MODE_TYPE, *PTRACK_MODE_TYPE;

typedef struct __RAW_READ_INFO {
    LARGE_INTEGER       DiskOffset;
    ULONG               SectorCount;
    TRACK_MODE_TYPE     TrackMode;
} RAW_READ_INFO, *PRAW_READ_INFO;

#endif /* __NTDDCDRM_H */
