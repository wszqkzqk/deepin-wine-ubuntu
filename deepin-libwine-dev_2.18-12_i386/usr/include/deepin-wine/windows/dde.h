/*
 * Copyright 1995, Technion, Israel Institute of Technology
 * Electrical Eng, Software Lab.
 * Author:    Michael Veksler.
 * Purpose:   dde declarations
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

#ifndef __WINE_DDE_H
#define __WINE_DDE_H

#include <windef.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _USER32_
#define WINUSERAPI
#else
#define WINUSERAPI DECLSPEC_IMPORT
#endif

#include <dde.rh>

/* DDEACK: wStatus in WM_DDE_ACK message */
typedef struct
{
    unsigned short bAppReturnCode:8, reserved:6, fBusy:1, fAck:1;
} DDEACK;

/* DDEDATA: hData in WM_DDE_DATA message */
typedef struct
{
    unsigned short unused:12, fResponse:1, fRelease:1, reserved:1, fAckReq:1;
    short cfFormat;
    BYTE Value[1];		/* undetermined array */
} DDEDATA;

/* DDEADVISE: hOptions in WM_DDE_ADVISE message */
typedef struct
{
    unsigned short reserved:14, fDeferUpd:1, fAckReq:1;
    short cfFormat;
} DDEADVISE;

/* DDEPOKE: hData in WM_DDE_POKE message. */
typedef struct
{
    unsigned short unused:13, fRelease:1, fReserved:2;
    short cfFormat;
    BYTE Value[1];   	/* undetermined array */
} DDEPOKE;

WINUSERAPI BOOL        WINAPI DdeSetQualityOfService(HWND,const SECURITY_QUALITY_OF_SERVICE *,PSECURITY_QUALITY_OF_SERVICE);
WINUSERAPI BOOL        WINAPI FreeDDElParam(UINT,LPARAM);
WINUSERAPI BOOL        WINAPI ImpersonateDdeClientWindow(HWND,HWND);
WINUSERAPI LPARAM      WINAPI PackDDElParam(UINT,UINT_PTR,UINT_PTR);
WINUSERAPI LPARAM      WINAPI ReuseDDElParam(LPARAM,UINT,UINT,UINT_PTR,UINT_PTR);
WINUSERAPI BOOL        WINAPI UnpackDDElParam(UINT,LPARAM,PUINT_PTR,PUINT_PTR);

#ifdef __cplusplus
}
#endif

#endif /* __WINE_DDE_H */
