/*
 * Copyright (C) 2006 Robert Reif
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
#ifndef _LMMSG_
#define _LMMSG_

#ifdef __cplusplus
extern "C" {
#endif

#define MSGNAME_NOT_FORWARDED   0x00
#define MSGNAME_FORWARDED_TO    0x04
#define MSGNAME_FORWARDED_FROM  0x10

typedef struct _MSG_INFO_0
{
    LPWSTR msgi0_name;
} MSG_INFO_0, *PMSG_INFO_0, *LPMSG_INFO_0;

typedef struct _MSG_INFO_1
{
    LPWSTR msgi1_name;
    DWORD msgi1_forward_flag;
    LPWSTR msgi1_forward;
} MSG_INFO_1, *PMSG_INFO_1, *LPMSG_INFO_1;

NET_API_STATUS NET_API_FUNCTION NetMessageBufferSend(LPCWSTR,LPCWSTR,LPCWSTR,LPBYTE,DWORD);
NET_API_STATUS NET_API_FUNCTION NetMessageNameAdd(LPCWSTR,LPCWSTR);
NET_API_STATUS NET_API_FUNCTION NetMessageNameDel(LPCWSTR,LPCWSTR);
NET_API_STATUS NET_API_FUNCTION NetMessageNameEnum(LPCWSTR,DWORD,LPBYTE*,DWORD,LPDWORD,LPDWORD,LPDWORD);
NET_API_STATUS NET_API_FUNCTION NetMessageNameGetInfo(LPCWSTR,LPCWSTR,DWORD,PBYTE*);

#ifdef __cplusplus
}
#endif

#endif
