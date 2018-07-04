/*
 * Copyright (C) 2007 Tim Schwartz
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
#ifndef _LMUSE_H
#define _LMUSE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lmcons.h"
#include "lmuseflg.h"


#define USE_LOCAL_PARMNUM          1
#define USE_REMOTE_PARMNUM         2
#define USE_PASSWORD_PARMNUM       3
#define USE_ASGTYPE_PARMNUM        4
#define USE_USERNAME_PARMNUM       5
#define USE_DOMAINNAME_PARMNUM     6

#define USE_OK                     0
#define USE_PAUSED                 1
#define USE_SESSLOST               2
#define USE_DISCONN                USE_SESSLOST
#define USE_NETERR                 3
#define USE_CONN                   4
#define USE_RECONN                 5

#define USE_WILDCARD               ((DWORD)-1)
#define USE_DISKDEV                0
#define USE_SPOOLDEV               1
#define USE_CHARDEV                2
#define USE_IPC                    3

typedef struct _USE_INFO_1
{
    LMSTR ui1_local;
    LMSTR ui1_remote;
    LMSTR ui1_password;
    DWORD ui1_status;
    DWORD ui1_asg_type;
    DWORD ui1_refcount;
    DWORD ui1_usecount;
} USE_INFO_1, *PUSE_INFO_1, *LPUSE_INFO_1;

typedef struct _USE_INFO_2
{
    LMSTR ui2_local;
    LMSTR ui2_remote;
    LMSTR ui2_password;
    DWORD ui2_status;
    DWORD ui2_asg_type;
    DWORD ui2_refcount;
    DWORD ui2_usecount;
    LMSTR ui2_username;
    LMSTR ui2_domainname;
} USE_INFO_2, *PUSE_INFO_2, *LPUSE_INFO_2;

NET_API_STATUS WINAPI NetUseAdd(LMSTR,DWORD,LPBYTE,LPDWORD);
NET_API_STATUS WINAPI NetUseDel(LMSTR,LMSTR,DWORD);
NET_API_STATUS WINAPI NetUseEnum(LMSTR,DWORD,LPBYTE*,DWORD,LPDWORD,LPDWORD,LPDWORD);
NET_API_STATUS WINAPI NetUseGetInfo(LMSTR,LMSTR,DWORD,LPBYTE*);

#ifdef __cplusplus
}
#endif

#endif /* _LMUSE_H */
