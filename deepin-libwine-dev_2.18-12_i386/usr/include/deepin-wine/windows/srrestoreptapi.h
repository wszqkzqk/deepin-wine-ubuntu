/*
 * System Restore definitions
 *
 * Copyright 2008 Paul Vriens
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

#ifndef __WINE_SRRESTOREPTAPI_H
#define __WINE_SRRESTOREPTAPI_H

/* Event types */
#define BEGIN_NESTED_SYSTEM_CHANGE 102
#define END_NESTED_SYSTEM_CHANGE   103

/* Restore point types */
#define APPLICATION_INSTALL          0

#define MAX_DESC                    64
#define MAX_DESC_W                  256

#pragma pack(1)

typedef struct _RESTOREPTINFOA {
    DWORD dwEventType;
    DWORD dwRestorePtType;
    INT64 llSequenceNumber;
    CHAR  szDescription[MAX_DESC];
} RESTOREPOINTINFOA, *PRESTOREPOINTINFOA;

typedef struct _RESTOREPTINFOW {
    DWORD dwEventType;
    DWORD dwRestorePtType;
    INT64 llSequenceNumber;
    WCHAR szDescription[MAX_DESC_W];
} RESTOREPOINTINFOW, *PRESTOREPOINTINFOW;

typedef struct _RESTOREPTINFOEX {
    FILETIME ftCreation;
    DWORD dwEventType;
    DWORD dwRestorePtType;
    DWORD dwRPNum;
    WCHAR szDescription[MAX_DESC_W];
} RESTOREPOINTINFOEX, *PRESTOREPOINTINFOEX;

typedef struct _SMGRSTATUS {
    DWORD nStatus;
    INT64 llSequenceNumber;
} STATEMGRSTATUS, *PSTATEMGRSTATUS;

#ifdef __cplusplus
extern "C" {
#endif

BOOL WINAPI SRSetRestorePointA(RESTOREPOINTINFOA *, STATEMGRSTATUS *);
BOOL WINAPI SRSetRestorePointW(RESTOREPOINTINFOW *, STATEMGRSTATUS *);
#define     SRSetRestorePoint WINELIB_NAME_AW(SRSetRestorePoint)

DWORD WINAPI SRRemoveRestorePoint(DWORD);

#ifdef __cplusplus
}
#endif

#endif /* !defined(__WINE_SRRESTOREPTAPI_H) */
