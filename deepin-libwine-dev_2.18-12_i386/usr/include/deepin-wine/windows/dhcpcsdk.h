/*
 * Copyright (C) 2017 Alistair Leslie-Hughes
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
#ifndef _DHCPCSDK_
#define _DHCPCSDK_

typedef struct _DHCPAPI_PARAMS
{
    ULONG  Flags;
    ULONG  OptionId;
    BOOL   IsVendor;
    BYTE   *Data;
    DWORD  nBytesData;
} DHCPAPI_PARAMS, *PDHCPAPI_PARAMS, *LPDHCPAPI_PARAMS;

typedef struct _DHCPAPI_PARAMS DHCPCAPI_PARAMS, *PDHCPCAPI_PARAMS, *LPDHCPCAPI_PARAMS;

typedef struct _DHCPCAPI_PARAMS_ARARAY
{
    ULONG             nParams;
    LPDHCPCAPI_PARAMS Params;
} DHCPCAPI_PARAMS_ARRAY, *PDHCPCAPI_PARAMS_ARRAY, *LPDHCPCAPI_PARAMS_ARRAY;

typedef struct _DHCPCAPI_CLASSID
{
    ULONG  Flags;
    BYTE   *Data;
    ULONG  nBytesData;
} DHCPCAPI_CLASSID, *PDHCPCAPI_CLASSID, *LPDHCPCAPI_CLASSID;


DWORD WINAPI DhcpRequestParams( DWORD flags, void *reserved, WCHAR *adaptername, DHCPCAPI_CLASSID *classid,
                                DHCPCAPI_PARAMS_ARRAY sendparams, DHCPCAPI_PARAMS_ARRAY recdparams,
                                BYTE *buffer, DWORD *size, WCHAR *requestidstr );

#endif
