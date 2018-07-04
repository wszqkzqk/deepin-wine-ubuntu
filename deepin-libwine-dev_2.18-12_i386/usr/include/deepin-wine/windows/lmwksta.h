/*
 * Copyright 2002 Andriy Palamarchuk
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

#ifndef __WINE_LMWKSTA_H
#define __WINE_LMWKSTA_H

#include <lmcons.h>
#include <lmuseflg.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _WKSTA_TRANSPORT_INFO_0 {
  DWORD wkti0_quality_of_service;
  DWORD wkti0_number_of_vcs;
  LMSTR wkti0_transport_name;
  LMSTR wkti0_transport_address;
  BOOL wkti0_wan_ish;
} WKSTA_TRANSPORT_INFO_0, *PWKSTA_TRANSPORT_INFO_0, *LPWKSTA_TRANSPORT_INFO_0;

typedef struct _WKSTA_USER_INFO_0 {
    LMSTR  wkui0_username;
} WKSTA_USER_INFO_0, *PWKSTA_USER_INFO_0, *LPWKSTA_USER_INFO_0;

typedef struct _WKSTA_USER_INFO_1 {
    LMSTR  wkui1_username;
    LMSTR  wkui1_logon_domain;
    LMSTR  wkui1_oth_domains;
    LMSTR  wkui1_logon_server;
} WKSTA_USER_INFO_1, *PWKSTA_USER_INFO_1, *LPWKSTA_USER_INFO_1;

typedef struct _WKSTA_USER_INFO_1101 {
    LMSTR  wkui1101_oth_domains;
} WKSTA_USER_INFO_1101, *PWKSTA_USER_INFO_1101, *LPWKSTA_USER_INFO_1101;

typedef struct _WKSTA_INFO_100 {
    DWORD   wki100_platform_id;
    LMSTR   wki100_computername;
    LMSTR   wki100_langroup;
    DWORD   wki100_ver_major;
    DWORD   wki100_ver_minor;
} WKSTA_INFO_100, *PWKSTA_INFO_100, *LPWKSTA_INFO_100;

typedef struct _WKSTA_INFO_101 {
    DWORD   wki101_platform_id;
    LMSTR   wki101_computername;
    LMSTR   wki101_langroup;
    DWORD   wki101_ver_major;
    DWORD   wki101_ver_minor;
    LMSTR   wki101_lanroot;
} WKSTA_INFO_101, *PWKSTA_INFO_101, *LPWKSTA_INFO_101;

typedef struct _WKSTA_INFO_102 {
    DWORD   wki102_platform_id;
    LMSTR   wki102_computername;
    LMSTR   wki102_langroup;
    DWORD   wki102_ver_major;
    DWORD   wki102_ver_minor;
    LMSTR   wki102_lanroot;
    DWORD   wki102_logged_on_users;
} WKSTA_INFO_102, *PWKSTA_INFO_102, *LPWKSTA_INFO_102;

/* workstation */
NET_API_STATUS WINAPI NetWkstaGetInfo(LMSTR,DWORD,LPBYTE*);
NET_API_STATUS WINAPI NetWkstaSetInfo(LMSTR,DWORD,LPBYTE,LPDWORD);
NET_API_STATUS WINAPI NetWkstaTransportAdd(LMSTR,DWORD,LPBYTE,LPDWORD);
NET_API_STATUS WINAPI NetWkstaTransportDel(LMSTR,LMSTR,DWORD);
NET_API_STATUS WINAPI NetWkstaTransportEnum(LMSTR,DWORD,LPBYTE*,DWORD,LPDWORD,LPDWORD,LPDWORD);
NET_API_STATUS WINAPI NetWkstaUserGetInfo(LMSTR,DWORD,LPBYTE*);
NET_API_STATUS WINAPI NetWkstaUserSetInfo(LMSTR,DWORD,LPBYTE,LPDWORD);
NET_API_STATUS WINAPI NetWkstaUserEnum(LMSTR,DWORD,LPBYTE*,DWORD,LPDWORD,LPDWORD,LPDWORD);

#ifdef __cplusplus
}
#endif

#endif
