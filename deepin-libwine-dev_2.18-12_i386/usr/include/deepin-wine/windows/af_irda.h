/*
 * Copyright 2009 Juan Lang
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
#ifndef AF_IRDA_H
#define AF_IRDA_H

typedef struct _IRDA_DEVICE_INFO
{
    UCHAR irdaDeviceID[4];
    char  irdaDeviceName[22];
    UCHAR irdaDeviceHints1;
    UCHAR irdaDeviceHints2;
    UCHAR irdaCharSet;
} IRDA_DEVICE_INFO, *PIRDA_DEVICE_INFO;

typedef struct _DEVICELIST
{
    ULONG            numDevice;
    IRDA_DEVICE_INFO Device[1];
} DEVICELIST, *PDEVICELIST;

typedef struct _SOCKADDR_IRDA
{
    USHORT irdaAddressFamily;
    UCHAR  irdaDeviceID[4];
    char   irdaServiceName[25];
} SOCKADDR_IRDA, *PSOCKADDR_IRDA, *LPSOCKADDR_IRDA;

#ifdef USE_WS_PREFIX

/* Socket levels and options */
#define WS_SOL_IRLMP 0xff

#define WS_IRLMP_ENUMDEVICES    ((ULONG)0x10)
#define WS_IRLMP_IAS_SET        ((ULONG)0x11)
#define WS_IRLMP_IAS_QUERY      ((ULONG)0x12)
#define WS_IRLMP_SEND_PDU_LEN   ((ULONG)0x13)
#define WS_IRLMP_EXCLUSIVE_MODE ((ULONG)0x14)
#define WS_IRLMP_IRLPT_MODE     ((ULONG)0x15)
#define WS_IRLMP_9WIRE_MODE     ((ULONG)0x16)
#define WS_IRLMP_TINYTP_MODE    ((ULONG)0x17)
#define WS_IRLMP_PARAMETERS     ((ULONG)0x18)
#define WS_IRLMP_DISCOVER_MODE  ((ULONG)0x19)
#define WS_IRLMP_SHARP_MODE     ((ULONG)0x20)

#define WS_IAS_MAX_CLASSNAME    64
#define WS_IAS_MAX_ATTRIBNAME   256

#else

/* Socket levels and options */
#define SOL_IRLMP 0xff

#define IRLMP_ENUMDEVICES    ((ULONG)0x10)
#define IRLMP_IAS_SET        ((ULONG)0x11)
#define IRLMP_IAS_QUERY      ((ULONG)0x12)
#define IRLMP_SEND_PDU_LEN   ((ULONG)0x13)
#define IRLMP_EXCLUSIVE_MODE ((ULONG)0x14)
#define IRLMP_IRLPT_MODE     ((ULONG)0x15)
#define IRLMP_9WIRE_MODE     ((ULONG)0x16)
#define IRLMP_TINYTP_MODE    ((ULONG)0x17)
#define IRLMP_PARAMETERS     ((ULONG)0x18)
#define IRLMP_DISCOVER_MODE  ((ULONG)0x19)
#define IRLMP_SHARP_MODE     ((ULONG)0x20)

#define IAS_MAX_CLASSNAME    64
#define IAS_MAX_ATTRIBNAME   256

#endif

#define IAS_MAX_OCTET_STRING 1024
#define IAS_MAX_USER_STRING  256

#define LmCharSetASCII      0x00
#define LmCharSetISO_8859_1 0x01
#define LmCharSetISO_8859_2 0x02
#define LmCharSetISO_8859_3 0x03
#define LmCharSetISO_8859_4 0x04
#define LmCharSetISO_8859_5 0x05
#define LmCharSetISO_8859_6 0x06
#define LmCharSetISO_8859_7 0x07
#define LmCharSetISO_8859_8 0x08
#define LmCharSetISO_8859_9 0x09
#define LmCharSetUNICODE    0xff

#endif /* AF_IRDA_H */
