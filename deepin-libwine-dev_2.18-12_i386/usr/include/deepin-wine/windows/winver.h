/* Definitions for the VERsion info library (VER.DLL)
 *
 * Copyright 1996 Marcus Meissner
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

#ifndef __WINE_WINVER_H
#define __WINE_WINVER_H

/* FIXME: #include <specstrings.h> */
#include <verrsrc.h>

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

#ifndef RC_INVOKED

/* function prototypes */

DWORD       WINAPI VerFindFileA(DWORD,LPCSTR,LPCSTR,LPCSTR,LPSTR,PUINT,LPSTR,PUINT);
DWORD       WINAPI VerFindFileW(DWORD,LPCWSTR,LPCWSTR,LPCWSTR,LPWSTR,PUINT,LPWSTR,PUINT);
#define     VerFindFile WINELIB_NAME_AW(VerFindFile)
DWORD       WINAPI VerInstallFileA(DWORD,LPCSTR,LPCSTR,LPCSTR,LPCSTR,LPCSTR,LPSTR,PUINT);
DWORD       WINAPI VerInstallFileW(DWORD,LPCWSTR,LPCWSTR,LPCWSTR,LPCWSTR,LPCWSTR,LPWSTR,PUINT);
#define     VerInstallFile WINELIB_NAME_AW(VerInstallFile)
DWORD       WINAPI VerLanguageNameA(DWORD,LPSTR,DWORD);
DWORD       WINAPI VerLanguageNameW(DWORD,LPWSTR,DWORD);
#define     VerLanguageName WINELIB_NAME_AW(VerLanguageName)
BOOL        WINAPI VerQueryValueA(LPCVOID,LPCSTR,LPVOID*,PUINT);
BOOL        WINAPI VerQueryValueW(LPCVOID,LPCWSTR,LPVOID*,PUINT);
#define     VerQueryValue WINELIB_NAME_AW(VerQueryValue)
DWORD       WINAPI GetFileVersionInfoSizeA(LPCSTR,LPDWORD);
DWORD       WINAPI GetFileVersionInfoSizeW(LPCWSTR,LPDWORD);
#define     GetFileVersionInfoSize WINELIB_NAME_AW(GetFileVersionInfoSize)
BOOL        WINAPI GetFileVersionInfoA(LPCSTR,DWORD,DWORD,LPVOID);
BOOL        WINAPI GetFileVersionInfoW(LPCWSTR,DWORD,DWORD,LPVOID);
#define     GetFileVersionInfo WINELIB_NAME_AW(GetFileVersionInfo)
DWORD       WINAPI GetFileVersionInfoSizeExA(DWORD,LPCSTR,LPDWORD);
DWORD       WINAPI GetFileVersionInfoSizeExW(DWORD,LPCWSTR,LPDWORD);
#define     GetFileVersionInfoSizeEx WINELIB_NAME_AW(GetFileVersionInfoSizeEx)
BOOL        WINAPI GetFileVersionInfoExA(DWORD,LPCSTR,DWORD,DWORD,LPVOID);
BOOL        WINAPI GetFileVersionInfoExW(DWORD,LPCWSTR,DWORD,DWORD,LPVOID);
#define     GetFileVersionInfoEx WINELIB_NAME_AW(GetFileVersionInfoEx)

#endif /* RC_INVOKED */

#ifdef __cplusplus
} /* extern "C" */
#endif /* defined(__cplusplus) */

#endif /* __WINE_WINVER_H */
