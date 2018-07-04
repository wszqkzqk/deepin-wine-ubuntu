/* NSPAPI.H -- winsock 1.1
 * not supported on win95
 *
 * Copyright (C) 2001 Stefan Leichter
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

#ifndef _WINE_NSPAPI_
#define _WINE_NSPAPI_

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */
/*
 * constants
 */
#define XP_CONNECTIONLESS		0x00000001
#define XP_GUARANTEED_DELIVERY		0x00000002
#define XP_GUARANTEED_ORDER		0x00000004
#define XP_MESSAGE_ORIENTED		0x00000008
#define XP_PSEUDO_STREAM		0x00000010
#define XP_GRACEFUL_CLOSE		0x00000020
#define XP_EXPEDITED_DATA		0x00000040
#define XP_CONNECT_DATA			0x00000080
#define XP_DISCONNECT_DATA		0x00000100
#define XP_SUPPORTS_BROADCAST		0x00000200
#define XP_SUPPORTS_MULTICAST		0x00000400
#define XP_BANDWIDTH_ALLOCATION		0x00000800
#define XP_FRAGMENTATION		0x00001000
#define XP_ENCRYPTS			0x00002000

/*
 * structures
 */
typedef  struct _PROTOCOL_INFOA
{
         DWORD   dwServiceFlags;
         INT     iAddressFamily;
         INT     iMaxSockAddr;
         INT     iMinSockAddr;
         INT     iSocketType;
         INT     iProtocol;
         DWORD   dwMessageSize;
         LPSTR   lpProtocol;
} PROTOCOL_INFOA, *PPROTOCOL_INFOA, *LPPROTOCOL_INFOA;

typedef  struct _PROTOCOL_INFOW
{
         DWORD   dwServiceFlags;
         INT     iAddressFamily;
         INT     iMaxSockAddr;
         INT     iMinSockAddr;
         INT     iSocketType;
         INT     iProtocol;
         DWORD   dwMessageSize;
         LPWSTR  lpProtocol;
} PROTOCOL_INFOW, *PPROTOCOL_INFOW, *LPPROTOCOL_INFOW;

DECL_WINELIB_TYPE_AW(PROTOCOL_INFO)
DECL_WINELIB_TYPE_AW(PPROTOCOL_INFO)
DECL_WINELIB_TYPE_AW(LPPROTOCOL_INFO)

typedef struct _SERVICE_ADDRESS
{
        DWORD   dwAddressType;
        DWORD   dwAddressFlags;
        DWORD   dwAddressLength;
        DWORD   dwPrincipalLength;
        BYTE*   lpAddress;
        BYTE*   lpPrincipal;
} SERVICE_ADDRESS, *PSERVICE_ADDRESS, *LPSERVICE_ADDRESS;

typedef struct _SERVICE_ADDRESSES
{
        DWORD           dwAddressCount;
        SERVICE_ADDRESS Addresses[1];
} SERVICE_ADDRESSES, *PSERVICE_ADDRESSES, *LPSERVICE_ADDRESSES;

typedef struct _SERVICE_INFOA
{
        LPGUID              lpServiceType;
        LPSTR               lpServiceName;
        LPSTR               lpComment;
        LPSTR               lpLocale;
        DWORD               dwDisplayHint;
        DWORD               dwVersion;
        DWORD               dwTime;
        LPSTR               lpMachineName;
        LPSERVICE_ADDRESSES lpServiceAddress;
        BLOB                ServiceSpecificInfo;
} SERVICE_INFOA, *PSERVICE_INFOA, *LPSERVICE_INFOA;

typedef struct _SERVICE_INFOW
{
        LPGUID              lpServiceType;
        LPWSTR              lpServiceName;
        LPWSTR              lpComment;
        LPWSTR              lpLocale;
        DWORD               dwDisplayHint;
        DWORD               dwVersion;
        DWORD               dwTime;
        LPSTR               lpMachineName;
        LPSERVICE_ADDRESSES lpServiceAddress;
        BLOB                ServiceSpecificInfo; /* May point to SERVICE_TYPE_INFO_ABS */
} SERVICE_INFOW, *PSERVICE_INFOW, *LPSERVICE_INFOW;

DECL_WINELIB_TYPE_AW(SERVICE_INFO)
DECL_WINELIB_TYPE_AW(PSERVICE_INFO)
DECL_WINELIB_TYPE_AW(LPSERVICE_INFO)

typedef struct _SERVICE_TYPE_VALUE_ABSA
{
        DWORD   dwNameSpace; /* Name space or set of name spaces */
        DWORD   dwValueType; /* Type of the value data */
        DWORD   dwValueSize; /* Size of the value data */
        LPSTR   lpValueName; /* Name of the value */
        PVOID   lpValue;     /* Pointer to the value data */
} SERVICE_TYPE_VALUE_ABSA, *PSERVICE_TYPE_VALUE_ABSA, *LPSERVICE_TYPE_VALUE_ABSA;

typedef struct _SERVICE_TYPE_VALUE_ABSW
{
        DWORD   dwNameSpace; /* Name space or set of name spaces */
        DWORD   dwValueType; /* Type of the value data */
        DWORD   dwValueSize; /* Size of the value data */
        LPWSTR  lpValueName; /* Name of the value */
        PVOID   lpValue;     /* Pointer to the value data */
} SERVICE_TYPE_VALUE_ABSW, *PSERVICE_TYPE_VALUE_ABSW, *LPSERVICE_TYPE_VALUE_ABSW;

DECL_WINELIB_TYPE_AW(SERVICE_TYPE_VALUE_ABS)
DECL_WINELIB_TYPE_AW(PSERVICE_TYPE_VALUE_ABS)
DECL_WINELIB_TYPE_AW(LPSERVICE_TYPE_VALUE_ABS)

typedef struct _SERVICE_TYPE_INFO_ABSA
{
        LPSTR                   lpTypeName;     /* Name of the network service type */
        DWORD                   dwValueCount;   /* Number of SERVICE_TYPE_VALUE_ABS structures */
        SERVICE_TYPE_VALUE_ABSA Values[1];      /* Array of SERVICE_TYPE_VALUE_ABS structures */
} SERVICE_TYPE_INFO_ABSA, *PSERVICE_TYPE_INFO_ABSA, *LPSERVICE_TYPE_INFO_ABSA;

typedef struct _SERVICE_TYPE_INFO_ABSW
{
        LPWSTR                  lpTypeName;     /* Name of the network service type */
        DWORD                   dwValueCount;   /* Number of SERVICE_TYPE_VALUE_ABS structures */
        SERVICE_TYPE_VALUE_ABSW Values[1];      /* Array of SERVICE_TYPE_VALUE_ABS structures */
} SERVICE_TYPE_INFO_ABSW, *PSERVICE_TYPE_INFO_ABSW, *LPSERVICE_TYPE_INFO_ABSW;

DECL_WINELIB_TYPE_AW(SERVICE_TYPE_INFO_ABS)
DECL_WINELIB_TYPE_AW(PSERVICE_TYPE_INFO_ABS)
DECL_WINELIB_TYPE_AW(LPSERVICE_TYPE_INFO_ABS)

typedef void (*LPSERVICE_CALLBACK_PROC)(LPARAM lParam, HANDLE hAsyncTaskHandle);

typedef struct _SERVICE_ASYNC_INFO
{
    LPSERVICE_CALLBACK_PROC lpServiceCallbackProc;
    LPARAM                  lParam;
    HANDLE                  hAsyncTaskHandle;
} SERVICE_ASYNC_INFO, *PSERVICE_ASYNC_INFO, *LPSERVICE_ASYNC_INFO;

/*
 * function prototypes
 */
INT WINAPI GetAddressByNameA(DWORD dwNameSpace, LPGUID lpServiceType, LPSTR lpServiceName,
    LPINT lpiProtocols, DWORD dwResolution, LPSERVICE_ASYNC_INFO lpServiceAsyncInfo,
    LPVOID lpCsaddrBuffer, LPDWORD lpdwBufferLength, LPSTR lpAliasBuffer,
    LPDWORD lpdwAliasBufferLength);
INT WINAPI GetAddressByNameW(DWORD dwNameSpace, LPGUID lpServiceType, LPWSTR lpServiceName,
    LPINT lpiProtocols, DWORD dwResolution, LPSERVICE_ASYNC_INFO lpServiceAsyncInfo,
    LPVOID lpCsaddrBuffer, LPDWORD lpdwBufferLength, LPWSTR lpAliasBuffer,
    LPDWORD lpdwAliasBufferLength);
#define GetAddressByName WINELIB_NAME_AW(GetAddressByName)
INT WINAPI GetTypeByNameA(LPSTR lpServiceName, LPGUID lpServiceType);
INT WINAPI GetTypeByNameW(LPWSTR lpServiceName, LPGUID lpServiceType);
#define GetTypeByName WINELIB_NAME_AW(GetTypeByName)
INT WINAPI SetServiceA(DWORD dwNameSpace, DWORD dwOperation, DWORD dwFlags, LPSERVICE_INFOA lpServiceInfo,
                       LPSERVICE_ASYNC_INFO lpServiceAsyncInfo, LPDWORD lpdwStatusFlags);
INT WINAPI SetServiceW(DWORD dwNameSpace, DWORD dwOperation, DWORD dwFlags, LPSERVICE_INFOW lpServiceInfo,
                       LPSERVICE_ASYNC_INFO lpServiceAsyncInfo, LPDWORD lpdwStatusFlags);
#define SetService WINELIB_NAME_AW(SetService)
INT WINAPI GetServiceA(DWORD dwNameSpace, LPGUID lpGuid, LPSTR lpServiceName,
                       DWORD dwProperties, LPVOID lpBuffer, LPDWORD lpdwBufferSize,
                       LPSERVICE_ASYNC_INFO lpServiceAsyncInfo);
INT WINAPI GetServiceW(DWORD dwNameSpace, LPGUID lpGuid, LPSTR lpServiceName,
                       DWORD dwProperties, LPVOID lpBuffer, LPDWORD lpdwBufferSize,
                       LPSERVICE_ASYNC_INFO lpServiceAsyncInfo);
#define GetService WINELIB_NAME_AW(GetService)

#ifdef __cplusplus
}      /* extern "C" */
#endif /* defined(__cplusplus) */

#endif /* _WINE_NSPAPI_ */
