/*
 * Copyright 2015 Hans Leidekker for CodeWeavers
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

#ifndef __WINE_DAVCLNT_H
#define __WINE_DAVCLNT_H

#define OPAQUE_HANDLE DWORD

#define DAV_AUTHN_SCHEME_BASIC     0x00000001
#define DAV_AUTHN_SCHEME_NTLM      0x00000002
#define DAV_AUTHN_SCHEME_PASSPORT  0x00000004
#define DAV_AUTHN_SCHEME_DIGEST    0x00000008
#define DAV_AUTHN_SCHEME_NEGOTIATE 0x00000010
#define DAV_AUTHN_SCHEME_CERT      0x00010000
#define DAV_AUTHN_SCHEME_FBA       0x00100000

typedef enum
{
    DefaultBehavior,
    RetryRequest,
    CancelRequest
} AUTHNEXTSTEP;

typedef struct _DAV_CALLBACK_AUTH_BLOB
{
    PVOID pBuffer;
    ULONG ulSize;
    ULONG ulType;
} DAV_CALLBACK_AUTH_BLOB, *PDAV_CALLBACK_AUTH_BLOB;

typedef struct _DAV_CALLBACK_AUTH_UNP
{
    LPWSTR pszUserName;
    ULONG  ulUserNameLength;
    LPWSTR pszPassword;
    ULONG  ulPasswordLength;
} DAV_CALLBACK_AUTH_UNP, *PDAV_CALLBACK_AUTH_UNP;

typedef struct _DAV_CALLBACK_CRED
{
    DAV_CALLBACK_AUTH_BLOB AuthBlob;
    DAV_CALLBACK_AUTH_UNP  UNPBlob;
    BOOL                   bAuthBlobValid;
    BOOL                   bSave;
} DAV_CALLBACK_CRED, *PDAV_CALLBACK_CRED;

typedef DWORD (*PFNDAVAUTHCALLBACK_FREECRED)
    (PVOID);

typedef DWORD (*PFNDAVAUTHCALLBACK)
    (LPWSTR,LPWSTR,DWORD,DWORD,PDAV_CALLBACK_CRED,AUTHNEXTSTEP*,PFNDAVAUTHCALLBACK_FREECRED*);

DWORD WINAPI DavGetHTTPFromUNCPath(LPCWSTR,LPWSTR,LPDWORD);
DWORD WINAPI DavGetUNCFromHTTPPath(LPCWSTR,LPWSTR,LPDWORD);
OPAQUE_HANDLE WINAPI DavRegisterAuthCallback(PFNDAVAUTHCALLBACK,ULONG);
VOID WINAPI DavUnregisterAuthCallback(OPAQUE_HANDLE);

#endif /* __WINE_DAVCLNT_H */
