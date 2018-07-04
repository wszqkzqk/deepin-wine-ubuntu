/*
 * Copyright (c) 2013 André Hentschel
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

#ifndef __WINE_DIFXAPI_H
#define __WINE_DIFXAPI_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _INSTALLERINFO_A
{
    PSTR pApplicationId;
    PSTR pDisplayName;
    PSTR pProductName;
    PSTR pMfgName;
} INSTALLERINFO_A, *PINSTALLERINFO_A;
typedef const PINSTALLERINFO_A PCINSTALLERINFO_A;

typedef struct _INSTALLERINFO_W
{
    PWSTR pApplicationId;
    PWSTR pDisplayName;
    PWSTR pProductName;
    PWSTR pMfgName;
} INSTALLERINFO_W, *PINSTALLERINFO_W;
typedef const PINSTALLERINFO_W PCINSTALLERINFO_W;

typedef enum _DIFXAPI_LOG
{
    DIFXAPI_SUCCESS,
    DIFXAPI_INFO,
    DIFXAPI_WARNING,
    DIFXAPI_ERROR,
} DIFXAPI_LOG;

typedef VOID (CALLBACK *DIFXAPILOGCALLBACK_A)(DIFXAPI_LOG,DWORD,PCSTR,PVOID);
typedef VOID (CALLBACK *DIFXAPILOGCALLBACK_W)(DIFXAPI_LOG,DWORD,PCWSTR,PVOID);
typedef VOID (CALLBACK *DIFXLOGCALLBACK_A)(DIFXAPI_LOG,DWORD,PCSTR,PVOID);
typedef VOID (CALLBACK *DIFXLOGCALLBACK_W)(DIFXAPI_LOG,DWORD,PCWSTR,PVOID);

VOID  WINAPI DIFXAPISetLogCallbackA(DIFXAPILOGCALLBACK_A,VOID*);
VOID  WINAPI DIFXAPISetLogCallbackW(DIFXAPILOGCALLBACK_W,VOID*);
DWORD WINAPI DriverPackageGetPathA(PCSTR,PSTR,DWORD*);
DWORD WINAPI DriverPackageGetPathW(PCWSTR,PWSTR,DWORD*);
DWORD WINAPI DriverPackageInstallA(PCSTR,DWORD,PCINSTALLERINFO_A,BOOL*);
DWORD WINAPI DriverPackageInstallW(PCWSTR,DWORD,PCINSTALLERINFO_W,BOOL*);
DWORD WINAPI DriverPackagePreinstallA(PCSTR,DWORD);
DWORD WINAPI DriverPackagePreinstallW(PCWSTR,DWORD);
DWORD WINAPI DriverPackageUninstallA(PCSTR,DWORD,PCINSTALLERINFO_A,BOOL*);
DWORD WINAPI DriverPackageUninstallW(PCWSTR,DWORD,PCINSTALLERINFO_W,BOOL*);
VOID  WINAPI SetDifxLogCallbackA(DIFXLOGCALLBACK_A,VOID*);
VOID  WINAPI SetDifxLogCallbackW(DIFXLOGCALLBACK_W,VOID*);

#ifdef __cplusplus
}
#endif

#endif  /* __WINE_DIFXAPI_H */
