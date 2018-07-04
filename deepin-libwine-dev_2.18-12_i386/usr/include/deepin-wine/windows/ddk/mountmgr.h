/*
 * Mount point manager definitions
 *
 * Copyright 2007 Alexandre Julliard
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

#ifndef _MOUNTMGR_
#define _MOUNTMGR_

#define MOUNTMGRCONTROLTYPE  ((ULONG)'m')
#define MOUNTDEVCONTROLTYPE  ((ULONG)'M')

#if defined(__GNUC__)
#define MOUNTMGR_DEVICE_NAME (const WCHAR []){'\\','D','e','v','i','c','e','\\','M','o','u','n','t','P','o','i','n','t','M','a','n','a','g','e','r',0}
#define MOUNTMGR_DOS_DEVICE_NAME (const WCHAR []){'\\','\\','.','\\','M','o','u','n','t','P','o','i','n','t','M','a','n','a','g','e','r',0}
#elif defined(_MSC_VER)
#define MOUNTMGR_DEVICE_NAME     L"\\Device\\MountPointManager"
#define MOUNTMGR_DOS_DEVICE_NAME L"\\\\.\\MountPointManager"
#else
static const WCHAR MOUNTMGR_DEVICE_NAME[] = {'\\','D','e','v','i','c','e','\\','M','o','u','n','t','P','o','i','n','t','M','a','n','a','g','e','r',0};
static const WCHAR MOUNTMGR_DOS_DEVICE_NAME[] = {'\\','\\','.','\\','M','o','u','n','t','P','o','i','n','t','M','a','n','a','g','e','r',0};
#endif


#define IOCTL_MOUNTMGR_CREATE_POINT                CTL_CODE(MOUNTMGRCONTROLTYPE, 0, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_DELETE_POINTS               CTL_CODE(MOUNTMGRCONTROLTYPE, 1, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_QUERY_POINTS                CTL_CODE(MOUNTMGRCONTROLTYPE, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_MOUNTMGR_DELETE_POINTS_DBONLY        CTL_CODE(MOUNTMGRCONTROLTYPE, 3, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_NEXT_DRIVE_LETTER           CTL_CODE(MOUNTMGRCONTROLTYPE, 4, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_AUTO_DL_ASSIGNMENTS         CTL_CODE(MOUNTMGRCONTROLTYPE, 5, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_CREATED  CTL_CODE(MOUNTMGRCONTROLTYPE, 6, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_DELETED  CTL_CODE(MOUNTMGRCONTROLTYPE, 7, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_CHANGE_NOTIFY               CTL_CODE(MOUNTMGRCONTROLTYPE, 8, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_MOUNTMGR_KEEP_LINKS_WHEN_OFFLINE     CTL_CODE(MOUNTMGRCONTROLTYPE, 9, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_CHECK_UNPROCESSED_VOLUMES   CTL_CODE(MOUNTMGRCONTROLTYPE, 10, METHOD_BUFFERED, FILE_READ_ACCESS)
#define IOCTL_MOUNTMGR_VOLUME_ARRIVAL_NOTIFICATION CTL_CODE(MOUNTMGRCONTROLTYPE, 11, METHOD_BUFFERED, FILE_READ_ACCESS)

/* Wine extensions */
#ifdef WINE_MOUNTMGR_EXTENSIONS

#define IOCTL_MOUNTMGR_DEFINE_UNIX_DRIVE CTL_CODE(MOUNTMGRCONTROLTYPE, 32, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_MOUNTMGR_QUERY_UNIX_DRIVE  CTL_CODE(MOUNTMGRCONTROLTYPE, 33, METHOD_BUFFERED, FILE_READ_ACCESS)

struct mountmgr_unix_drive
{
    ULONG  size;
    ULONG  type;
    WCHAR  letter;
    USHORT mount_point_offset;
    USHORT device_offset;
};

#endif

typedef struct _MOUNTMGR_CREATE_POINT_INPUT
{
    USHORT SymbolicLinkNameOffset;
    USHORT SymbolicLinkNameLength;
    USHORT DeviceNameOffset;
    USHORT DeviceNameLength;
} MOUNTMGR_CREATE_POINT_INPUT, *PMOUNTMGR_CREATE_POINT_INPUT;

typedef struct _MOUNTMGR_MOUNT_POINT
{
    ULONG  SymbolicLinkNameOffset;
    USHORT SymbolicLinkNameLength;
    ULONG  UniqueIdOffset;
    USHORT UniqueIdLength;
    ULONG  DeviceNameOffset;
    USHORT DeviceNameLength;
} MOUNTMGR_MOUNT_POINT, *PMOUNTMGR_MOUNT_POINT;

typedef struct _MOUNTMGR_MOUNT_POINTS
{
    ULONG                Size;
    ULONG                NumberOfMountPoints;
    MOUNTMGR_MOUNT_POINT MountPoints[1];
} MOUNTMGR_MOUNT_POINTS, *PMOUNTMGR_MOUNT_POINTS;

typedef struct _MOUNTMGR_DRIVE_LETTER_TARGET
{
    USHORT DeviceNameLength;
    WCHAR  DeviceName[1];
} MOUNTMGR_DRIVE_LETTER_TARGET, *PMOUNTMGR_DRIVE_LETTER_TARGET;

typedef struct _MOUNTMGR_DRIVE_LETTER_INFORMATION
{
    BOOLEAN DriveLetterWasAssigned;
    UCHAR   CurrentDriveLetter;
} MOUNTMGR_DRIVE_LETTER_INFORMATION, *PMOUNTMGR_DRIVE_LETTER_INFORMATION;

typedef struct _MOUNTMGR_VOLUME_MOUNT_POINT
{
    USHORT SourceVolumeNameOffset;
    USHORT SourceVolumeNameLength;
    USHORT TargetVolumeNameOffset;
    USHORT TargetVolumeNameLength;
} MOUNTMGR_VOLUME_MOUNT_POINT, *PMOUNTMGR_VOLUME_MOUNT_POINT;

typedef struct _MOUNTMGR_CHANGE_NOTIFY_INFO
{
    ULONG EpicNumber;
} MOUNTMGR_CHANGE_NOTIFY_INFO, *PMOUNTMGR_CHANGE_NOTIFY_INFO;

typedef struct _MOUNTMGR_TARGET_NAME
{
    USHORT DeviceNameLength;
    WCHAR  DeviceName[1];
} MOUNTMGR_TARGET_NAME, *PMOUNTMGR_TARGET_NAME;

#define MOUNTMGR_IS_DRIVE_LETTER(s) \
    ((s)->Length == 28 && \
     (s)->Buffer[0] == '\\' && (s)->Buffer[1] == 'D'  && (s)->Buffer[2] == 'o'   && \
     (s)->Buffer[3] == 's'  && (s)->Buffer[4] == 'D'  && (s)->Buffer[5] == 'e'   && \
     (s)->Buffer[6] == 'v'  && (s)->Buffer[7] == 'i'  && (s)->Buffer[8] == 'c'   && \
     (s)->Buffer[9] == 'e'  && (s)->Buffer[10] == 's' && (s)->Buffer[11] == '\\' && \
     (s)->Buffer[12] >= 'A' && (s)->Buffer[12] <= 'Z' && (s)->Buffer[13] == ':')

#define MOUNTMGR_IS_VOLUME_NAME(s) \
    (((s)->Length == 96 || ((s)->Length == 98 && (s)->Buffer[48] == '\\')) && \
     (s)->Buffer[0] == '\\' && ((s)->Buffer[1] == '?' || (s)->Buffer[1] == '\\') && \
     (s)->Buffer[2] == '?'  && (s)->Buffer[3] == '\\' && (s)->Buffer[4] == 'V'   && \
     (s)->Buffer[5] == 'o'  && (s)->Buffer[6] == 'l'  && (s)->Buffer[7] == 'u'   && \
     (s)->Buffer[8] == 'm'  && (s)->Buffer[9] == 'e'  && (s)->Buffer[10] == '{'  && \
     (s)->Buffer[19] == '-' && (s)->Buffer[24] == '-' && (s)->Buffer[29] == '-'  && \
     (s)->Buffer[34] == '-' && (s)->Buffer[47] == '}')

#endif /* _MOUNTMGR_ */
