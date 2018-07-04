/*
 * Copyright (C) 2006 Robert Reif
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

#ifndef __WINE_DSGETDC_H
#define __WINE_DSGETDC_H

#ifdef __cplusplus
extern "C" {
#endif

#define DS_FORCE_REDISCOVERY            0x00000001
#define DS_DIRECTORY_SERVICE_REQUIRED   0x00000010
#define DS_DIRECTORY_SERVICE_PREFERRED  0x00000020
#define DS_GC_SERVER_REQUIRED           0x00000040
#define DS_PDC_REQUIRED                 0x00000080
#define DS_BACKGROUND_ONLY              0x00000100
#define DS_IP_REQUIRED                  0x00000200
#define DS_KDC_REQUIRED                 0x00000400
#define DS_TIMESERV_REQUIRED            0x00000800
#define DS_WRITABLE_REQUIRED            0x00001000
#define DS_GOOD_TIMESERV_PREFERRED      0x00002000
#define DS_AVOID_SELF                   0x00004000
#define DS_ONLY_LDAP_NEEDED             0x00008000

#define DS_IS_FLAT_NAME                 0x00010000
#define DS_IS_DNS_NAME                  0x00020000

#define DS_RETURN_DNS_NAME              0x40000000
#define DS_RETURN_FLAT_NAME             0x80000000

#define DSGETDC_VALID_FLAGS ( \
    DS_FORCE_REDISCOVERY | \
    DS_DIRECTORY_SERVICE_REQUIRED | \
    DS_DIRECTORY_SERVICE_PREFERRED | \
    DS_GC_SERVER_REQUIRED | \
    DS_PDC_REQUIRED | \
    DS_BACKGROUND_ONLY | \
    DS_IP_REQUIRED | \
    DS_KDC_REQUIRED | \
    DS_TIMESERV_REQUIRED | \
    DS_WRITABLE_REQUIRED | \
    DS_GOOD_TIMESERV_PREFERRED | \
    DS_AVOID_SELF | \
    DS_ONLY_LDAP_NEEDED | \
    DS_IS_FLAT_NAME | \
    DS_IS_DNS_NAME | \
    DS_RETURN_FLAT_NAME  | \
    DS_RETURN_DNS_NAME )

typedef struct _DOMAIN_CONTROLLER_INFOA {
    LPSTR DomainControllerName;
    LPSTR DomainControllerAddress;
    ULONG DomainControllerAddressType;
    GUID DomainGuid;
    LPSTR DomainName;
    LPSTR DnsForestName;
    ULONG Flags;
    LPSTR DcSiteName;
    LPSTR ClientSiteName;
} DOMAIN_CONTROLLER_INFOA, *PDOMAIN_CONTROLLER_INFOA;

typedef struct _DOMAIN_CONTROLLER_INFOW {
    LPWSTR DomainControllerName;
    LPWSTR DomainControllerAddress;
    ULONG DomainControllerAddressType;
    GUID DomainGuid;
    LPWSTR DomainName;
    LPWSTR DnsForestName;
    ULONG Flags;
    LPWSTR DcSiteName;
    LPWSTR ClientSiteName;
} DOMAIN_CONTROLLER_INFOW, *PDOMAIN_CONTROLLER_INFOW;

DECL_WINELIB_TYPE_AW(DOMAIN_CONTROLLER_INFO)

DWORD WINAPI DsGetDcNameA(LPCSTR,LPCSTR,GUID*,LPCSTR,ULONG,PDOMAIN_CONTROLLER_INFOA*);
DWORD WINAPI DsGetDcNameW(LPCWSTR,LPCWSTR,GUID*,LPCWSTR,ULONG,PDOMAIN_CONTROLLER_INFOW*);
#define     DsGetDcName WINELIB_NAME_AW(DsGetDcName)

DWORD WINAPI DsGetSiteNameA(LPCSTR ComputerName, LPSTR *SiteName);
DWORD WINAPI DsGetSiteNameW(LPCWSTR ComputerName, LPWSTR *SiteName);
#define     DsGetSiteName WINELIB_NAME_AW(DsGetSiteName)

#ifdef __cplusplus
}
#endif

#endif /* __WINE_DSGETDC_H */
