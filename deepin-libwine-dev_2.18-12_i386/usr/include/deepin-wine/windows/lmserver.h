/*
 * Copyright (C) 2003 Juan Lang
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
#ifndef _LMSERVER_
#define _LMSERVER_

#include <winsvc.h>
#include <lmcons.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _SERVER_INFO_100 {
    DWORD sv100_platform_id;
    LMSTR sv100_name;
} SERVER_INFO_100, *PSERVER_INFO_100, *LPSERVER_INFO_100;

typedef struct _SERVER_INFO_101 {
    DWORD sv101_platform_id;
    LMSTR sv101_name;
    DWORD sv101_version_major;
    DWORD sv101_version_minor;
    DWORD sv101_type;
    LMSTR sv101_comment;
} SERVER_INFO_101, *PSERVER_INFO_101, *LPSERVER_INFO_101;

NET_API_STATUS WINAPI NetServerEnum(LMCSTR,DWORD,LPBYTE*,DWORD,LPDWORD,LPDWORD,DWORD,LMCSTR,LPDWORD);
NET_API_STATUS WINAPI NetServerEnumEx(LMCSTR,DWORD,LPBYTE*,DWORD,LPDWORD,LPDWORD,DWORD,LMCSTR,LMCSTR);
NET_API_STATUS WINAPI NetServerGetInfo(LMSTR,DWORD,LPBYTE*);
BOOL WINAPI SetServiceBits(SERVICE_STATUS_HANDLE,DWORD,BOOL,BOOL);

#define SV_TYPE_WORKSTATION       0x00000001
#define SV_TYPE_SERVER            0x00000002
#define SV_TYPE_SQLSERVER         0x00000004
#define SV_TYPE_DOMAIN_CTRL       0x00000008
#define SV_TYPE_DOMAIN_BAKCTRL    0x00000010
#define SV_TYPE_TIME_SOURCE       0x00000020
#define SV_TYPE_AFP               0x00000040
#define SV_TYPE_NOVELL            0x00000080
#define SV_TYPE_DOMAIN_MEMBER     0x00000100
#define SV_TYPE_PRINTQ_SERVER     0x00000200
#define SV_TYPE_DIALIN_SERVER     0x00000400
#define SV_TYPE_XENIX_SERVER      0x00000800
#define SV_TYPE_SERVER_UNIX       SV_TYPE_XENIX_SERVER
#define SV_TYPE_NT                0x00001000
#define SV_TYPE_WFW               0x00002000
#define SV_TYPE_SERVER_MFPN       0x00004000
#define SV_TYPE_SERVER_NT         0x00008000
#define SV_TYPE_POTENTIAL_BROWSER 0x00010000
#define SV_TYPE_BACKUP_BROWSER    0x00020000
#define SV_TYPE_MASTER_BROWSER    0x00040000
#define SV_TYPE_DOMAIN_MASTER     0x00080000
#define SV_TYPE_SERVER_OSF        0x00100000
#define SV_TYPE_SERVER_VMS        0x00200000
#define SV_TYPE_WINDOWS           0x00400000
#define SV_TYPE_DFS               0x00800000
#define SV_TYPE_CLUSTER_NT        0x01000000
#define SV_TYPE_TERMINALSERVER    0x02000000
#define SV_TYPE_CLUSTER_VS_NT     0x04000000
#define SV_TYPE_DCE               0x10000000
#define SV_TYPE_ALTERNATE_XPORT   0x20000000
#define SV_TYPE_LOCAL_LIST_ONLY   0x40000000
#define SV_TYPE_DOMAIN_ENUM       0x80000000
#define SV_TYPE_ALL               0xFFFFFFFF

#ifdef __cplusplus
}
#endif

#endif /* ndef _LMSERVER_ */
