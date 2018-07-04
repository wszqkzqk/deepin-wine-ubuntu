/*
 * Copyright (c) 2016 Austin English
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

#ifndef __NCRYPT_H__
#define __NCRYPT_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WINAPI
#define WINAPI __stdcall
#endif

#ifndef __SECSTATUS_DEFINED__
typedef LONG SECURITY_STATUS;
#define __SECSTATUS_DEFINED__
#endif

typedef ULONG_PTR NCRYPT_HANDLE;
typedef ULONG_PTR NCRYPT_PROV_HANDLE;
typedef ULONG_PTR NCRYPT_KEY_HANDLE;
typedef ULONG_PTR NCRYPT_HASH_HANDLE;
typedef ULONG_PTR NCRYPT_SECRET_HANDLE;

SECURITY_STATUS WINAPI NCryptCreatePersistedKey(NCRYPT_PROV_HANDLE, NCRYPT_KEY_HANDLE *, const WCHAR *, const WCHAR *, DWORD, DWORD);
SECURITY_STATUS WINAPI NCryptDecrypt(NCRYPT_KEY_HANDLE, BYTE *, DWORD, void *, BYTE *, DWORD, DWORD *, DWORD);
SECURITY_STATUS WINAPI NCryptEncrypt(NCRYPT_KEY_HANDLE, BYTE *, DWORD, void *, BYTE *, DWORD, DWORD *, DWORD);
SECURITY_STATUS WINAPI NCryptFinalizeKey(NCRYPT_KEY_HANDLE, DWORD);
SECURITY_STATUS WINAPI NCryptFreeObject(NCRYPT_HANDLE);
SECURITY_STATUS WINAPI NCryptOpenKey(NCRYPT_PROV_HANDLE, NCRYPT_KEY_HANDLE *, const WCHAR *, DWORD, DWORD);
SECURITY_STATUS WINAPI NCryptOpenStorageProvider(NCRYPT_PROV_HANDLE *, const WCHAR *, DWORD);

#ifdef __cplusplus
}
#endif

#endif /* __NCRYPT_H__ */
