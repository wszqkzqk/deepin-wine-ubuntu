/*
 * Copyright (C) 2016 Austin English
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

#ifndef _WMIUM_
#define _WMIUM_

#ifdef _WMI_SOURCE_
#define WMIAPI __stdcall
#else
#define WMIAPI DECLSPEC_IMPORT __stdcall
#endif

#include <guiddef.h>
#include <basetsd.h>
#include <wmistr.h>

typedef PVOID WMIHANDLE, *PWMIHANDLE, MOFHANDLE, *PMOFHANDLE;

#define MOFCI_RESERVED0  0x00000001
#define MOFCI_RESERVED1  0x00000002
#define MOFCI_RESERVED2  0x00000004

typedef struct
{
    char *ImagePath;
    char *ResourceName;
    ULONG ResourceSize;
    UCHAR *ResourceBuffer;
} MOFRESOURCEINFOA, *PMOFRESOURCEINFOA;

typedef struct
{
    WCHAR *ImagePath;
    WCHAR *ResourceName;
    ULONG ResourceSize;
    UCHAR *ResourceBuffer;
} MOFRESOURCEINFOW, *PMOFRESOURCEINFOW;

DECL_WINELIB_TYPE_AW(MOFRESOURCEINFO)
DECL_WINELIB_TYPE_AW(PMOFRESOURCEINFO)

#ifdef __cplusplus
extern "C" {
#endif

#define NOTIFICATION_TRACE_FLAG       0x00010000
#define NOTIFICATION_CALLBACK_DIRECT  0x00000004
#define NOTIFICATION_CHECK_ACCESS     0x00000008

typedef void (WINAPI *NOTIFICATIONCALLBACK)(WNODE_HEADER *, UINT_PTR);

typedef struct _WMIGUIDINFORMATION
{
    ULONG Size;
    BOOLEAN IsExpensive;
    BOOLEAN IsEventOnly;
} WMIGUIDINFORMATION, *PWMIGUIDINFORMATION;

DEFINE_GUID(GUID_REGISTRATION_CHANGE_NOTIFICATION,  0xb48d49a1, 0xe777, 0x11d0, 0xa5, 0xc, 0x0, 0xa0, 0xc9, 0x6, 0x29, 0x10);
DEFINE_GUID(GUID_MOF_RESOURCE_ADDED_NOTIFICATION,   0xb48d49a2, 0xe777, 0x11d0, 0xa5, 0xc, 0x0, 0xa0, 0xc9, 0x6, 0x29, 0x10);
DEFINE_GUID(GUID_MOF_RESOURCE_REMOVED_NOTIFICATION, 0xb48d49a3, 0xe777, 0x11d0, 0xa5, 0xc, 0x0, 0xa0, 0xc9, 0x6, 0x29, 0x10);

ULONG WMIAPI WmiCloseBlock(WMIHANDLE);
ULONG WMIAPI WmiDevInstToInstanceNameA(char *,  ULONG, char *,  ULONG);
ULONG WMIAPI WmiDevInstToInstanceNameW(WCHAR *, ULONG, WCHAR *, ULONG);
#define      WmiDevInstToInstanceName WINELIB_NAME_AW(WmiDevInstToInstanceName)
ULONG WMIAPI WmiEnumerateGuids(GUID *, ULONG *);
ULONG WMIAPI WmiExecuteMethodA(WMIHANDLE, const char *,  ULONG, ULONG, void *, ULONG *, void *);
ULONG WMIAPI WmiExecuteMethodW(WMIHANDLE, const WCHAR *, ULONG, ULONG, void *, ULONG *, void *);
#define      WmiExecuteMethod WINELIB_NAME_AW(WmiExecuteMethod)
ULONG WMIAPI WmiFileHandleToInstanceNameA(WMIHANDLE, HANDLE, ULONG *, char *);
ULONG WMIAPI WmiFileHandleToInstanceNameW(WMIHANDLE, HANDLE, ULONG *, WCHAR *);
#define      WmiFileHandleToInstanceName WINELIB_NAME_AW(WmiFileHandleToInstanceName)
void  WMIAPI WmiFreeBuffer(void *);
#define WmiInsertTimestamp(WnodeHeader) GetSystemTimeAsFileTime((FILETIME *)&((WNODE_HEADER *)WnodeHeader)->TimeStamp)
ULONG WMIAPI WmiMofEnumerateResourcesA(MOFHANDLE, ULONG *, MOFRESOURCEINFOA **);
ULONG WMIAPI WmiMofEnumerateResourcesW(MOFHANDLE, ULONG *, MOFRESOURCEINFOW **);
#define      WmiMofEnumerateResources WINELIB_NAME_AW(WmiMofEnumerateResources)
ULONG WMIAPI WmiNotificationRegistrationA(GUID *, BOOLEAN, void *, ULONG_PTR, ULONG);
ULONG WMIAPI WmiNotificationRegistrationW(GUID *, BOOLEAN, void *, ULONG_PTR, ULONG);
#define      WmiNotificationRegistration WINELIB_NAME_AW(WmiNotificationRegistration)
ULONG WMIAPI WmiOpenBlock(GUID *, ULONG, WMIHANDLE *);
ULONG WMIAPI WmiQueryAllDataA(WMIHANDLE, ULONG *, void *);
ULONG WMIAPI WmiQueryAllDataW(WMIHANDLE, ULONG *, void *);
#define      WmiQueryAllData WINELIB_NAME_AW(WmiQueryAllData)
ULONG WMIAPI WmiQueryGuidInformation(WMIHANDLE, WMIGUIDINFORMATION *);
ULONG WMIAPI WmiQuerySingleInstanceA(WMIHANDLE, const char *, ULONG *, void *);
ULONG WMIAPI WmiQuerySingleInstanceW(WMIHANDLE, const WCHAR *, ULONG *, void *);
#define      WmiQuerySingleInstance WINELIB_NAME_AW(WmiQuerySingleInstance)
ULONG WMIAPI WmiSetSingleInstanceA(WMIHANDLE, const char *,  ULONG, ULONG, void *);
ULONG WMIAPI WmiSetSingleInstanceW(WMIHANDLE, const WCHAR *, ULONG, ULONG, void *);
#define      WmiSetSingleInstance WINELIB_NAME_AW(WmiSetSingleInstance)
ULONG WMIAPI WmiSetSingleItemA(WMIHANDLE, const char *,  ULONG, ULONG, ULONG, void *);
ULONG WMIAPI WmiSetSingleItemW(WMIHANDLE, const WCHAR *, ULONG, ULONG, ULONG, void *);
#define      WmiSetSingleItem WINELIB_NAME_AW(WmiSetSingleItem)

#ifdef __cplusplus
}
#endif

#endif  /* _WMIUM_ */
