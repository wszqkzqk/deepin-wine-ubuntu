/*
 * Copyright (C) 2009 Nikolay Sivov
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

#ifndef __WINE_ACLUI_H
#define __WINE_ACLUI_H

#include <objbase.h>
#include <commctrl.h>
#include <accctrl.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

typedef struct _SI_OBJECT_INFO
{
    DWORD       dwFlags;
    HINSTANCE   hInstance;
    LPWSTR      pszServerName;
    LPWSTR      pszObjectName;
    LPWSTR      pszPageTitle;
    GUID        guidObjectType;
} SI_OBJECT_INFO, *PSI_OBJECT_INFO;

#define SI_EDIT_PERMS                0x00000000
#define SI_EDIT_OWNER                0x00000001
#define SI_EDIT_AUDITS               0x00000002
#define SI_CONTAINER                 0x00000004
#define SI_READONLY                  0x00000008
#define SI_ADVANCED                  0x00000010
#define SI_RESET                     0x00000020
#define SI_OWNER_READONLY            0x00000040
#define SI_EDIT_PROPERTIES           0x00000080
#define SI_OWNER_RECURSE             0x00000100
#define SI_NO_ACL_PROTECT            0x00000200
#define SI_NO_TREE_APPLY             0x00000400
#define SI_PAGE_TITLE                0x00000800
#define SI_SERVER_IS_DC              0x00001000
#define SI_RESET_DACL_TREE           0x00004000
#define SI_RESET_SACL_TREE           0x00008000
#define SI_OBJECT_GUID               0x00010000
#define SI_EDIT_EFFECTIVE            0x00020000
#define SI_RESET_DACL                0x00040000
#define SI_RESET_SACL                0x00080000
#define SI_RESET_OWNER               0x00100000
#define SI_NO_ADDITIONAL_PERMISSION  0x00200000
#define SI_VIEW_ONLY                 0x00400000
#define SI_PERMS_ELEVATION_REQUIRED  0x01000000
#define SI_AUDITS_ELEVATION_REQUIRED 0x02000000
#define SI_OWNER_ELEVATION_REQUIRED  0x04000000
#define SI_MAY_WRITE                 0x10000000

#define SI_EDIT_ALL     (SI_EDIT_PERMS | SI_EDIT_OWNER | SI_EDIT_AUDITS)

typedef struct _SI_ACCESS
{
    const GUID *pguid;
    ACCESS_MASK mask;
    LPCWSTR     pszName;
    DWORD       dwFlags;
} SI_ACCESS, *PSI_ACCESS;

#define SI_ACCESS_SPECIFIC  0x00010000
#define SI_ACCESS_GENERAL   0x00020000
#define SI_ACCESS_CONTAINER 0x00040000
#define SI_ACCESS_PROPERTY  0x00080000

typedef struct _SI_INHERIT_TYPE
{
    const GUID *pguid;
    ULONG       dwFlags;
    LPCWSTR     pszName;
} SI_INHERIT_TYPE, *PSI_INHERIT_TYPE;

typedef enum _SI_PAGE_TYPE
{
    SI_PAGE_PERM,
    SI_PAGE_ADVPERM,
    SI_PAGE_AUDIT,
    SI_PAGE_OWNER,
    SI_PAGE_EFFECTIVE,
    SI_PAGE_TAKEOWNERSHIP
} SI_PAGE_TYPE;

#define PSPCB_SI_INITDIALOG (WM_USER + 1)

#undef INTERFACE
#define INTERFACE ISecurityInformation
DECLARE_INTERFACE_IID_(ISecurityInformation, IUnknown, "965fc360-16ff-11d0-91cb-00aa00bbb723")
{
    /* IUnknown methods */
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID * ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    /* ISecurityInformation methods */
    STDMETHOD(GetObjectInformation) (THIS_ PSI_OBJECT_INFO pObjectInfo ) PURE;
    STDMETHOD(GetSecurity) (THIS_ SECURITY_INFORMATION RequestedInformation,
                            PSECURITY_DESCRIPTOR *ppSecurityDescriptor,
                            BOOL fDefault ) PURE;
    STDMETHOD(SetSecurity) (THIS_ SECURITY_INFORMATION SecurityInformation,
                            PSECURITY_DESCRIPTOR pSecurityDescriptor ) PURE;
    STDMETHOD(GetAccessRights) (THIS_ const GUID* pguidObjectType,
                                DWORD dwFlags,
                                PSI_ACCESS *ppAccess,
                                ULONG *pcAccesses,
                                ULONG *piDefaultAccess ) PURE;
    STDMETHOD(MapGeneric) (THIS_ const GUID *pguidObjectType,
                           UCHAR *pAceFlags,
                           ACCESS_MASK *pMask) PURE;
    STDMETHOD(GetInheritTypes) (THIS_ PSI_INHERIT_TYPE *ppInheritTypes,
                                ULONG *pcInheritTypes ) PURE;
    STDMETHOD(PropertySheetPageCallback)(THIS_ HWND hwnd, UINT uMsg, SI_PAGE_TYPE uPage ) PURE;
};
#undef INTERFACE
typedef ISecurityInformation *LPSECURITYINFO;

#define INTERFACE ISecurityInformation2
DECLARE_INTERFACE_IID_(ISecurityInformation2, IUnknown, "c3ccfdb4-6f88-11d2-a3ce-00c04fb1782a")
{
    /* IUnknown methods */
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID * ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    /* ISecurityInformation2 methods */
    STDMETHOD_(BOOL,IsDaclCanonical) (THIS_ PACL pDacl) PURE;
    STDMETHOD(LookupSids) (THIS_ ULONG cSids, PSID *rgpSids, LPDATAOBJECT *ppdo) PURE;
};
#undef INTERFACE
typedef ISecurityInformation2 *LPSECURITYINFO2;

#define CFSTR_ACLUI_SID_INFO_LIST   TEXT("CFSTR_ACLUI_SID_INFO_LIST")

typedef struct _SID_INFO
{
    PSID    pSid;
    PWSTR   pwzCommonName;
    PWSTR   pwzClass;
    PWSTR   pwzUPN;
} SID_INFO, *PSID_INFO;

typedef struct _SID_INFO_LIST
{
    ULONG       cItems;
    SID_INFO    aSidInfo[ANYSIZE_ARRAY];
} SID_INFO_LIST, *PSID_INFO_LIST;


#define INTERFACE IEffectivePermission
DECLARE_INTERFACE_IID_(IEffectivePermission, IUnknown, "3853dc76-9f35-407c-88a1-d19344365fbc")
{
    /* IUnknown methods */
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID * ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    /* ISecurityInformation methods */
    STDMETHOD(GetEffectivePermission) (THIS_
                                       const GUID* pguidObjectType,
                                       PSID pUserSid,
                                       LPCWSTR pszServerName,
                                       PSECURITY_DESCRIPTOR pSD,
                                       POBJECT_TYPE_LIST *ppObjectTypeList,
                                       ULONG *pcObjectTypeListLength,
                                       PACCESS_MASK *ppGrantedAccessList,
                                       ULONG *pcGrantedAccessListLength) PURE;
};
#undef INTERFACE
typedef IEffectivePermission *LPEFFECTIVEPERMISSION;

#define INTERFACE ISecurityObjectTypeInfo
DECLARE_INTERFACE_IID_(ISecurityObjectTypeInfo, IUnknown, "fc3066eb-79ef-444b-9111-d18a75ebf2fa")
{
    /* IUnknown methods */
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID * ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    /* ISecurityInformation methods */
    STDMETHOD(GetInheritSource)(THIS_ SECURITY_INFORMATION si,
                                PACL pACL,
#ifndef WINE_NO_UNICODE_MACROS
                                PINHERITED_FROM *ppInheritArray
#else
                                PINHERITED_FROMW *ppInheritArray
#endif
                                ) PURE;
};
#undef INTERFACE
typedef ISecurityObjectTypeInfo *LPSecurityObjectTypeInfo;


#define INTERFACE ISecurityInformation3
DECLARE_INTERFACE_IID_(ISecurityInformation3, IUnknown, "e2cdc9cc-31bd-4f8f-8c8b-b641af516a1a")
{
    /* IUnknown methods */
    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID * ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;

    /* ISecurityInformation3 methods */
    STDMETHOD(GetFullResourceName) (THIS_ LPWSTR *ppszResourceName) PURE;
    STDMETHOD(OpenElevatedEditor) (THIS_ HWND hWnd, SI_PAGE_TYPE uPage) PURE;
};
#undef INTERFACE
typedef ISecurityInformation3 *LPSECURITYINFO3;

DEFINE_GUID(IID_ISecurityInformation, 0x965fc360, 0x16ff, 0x11d0, 0x91, 0xcb, 0x0, 0xaa, 0x0, 0xbb, 0xb7, 0x23);
DEFINE_GUID(IID_ISecurityInformation2, 0xc3ccfdb4, 0x6f88, 0x11d2, 0xa3, 0xce, 0x0, 0xc0, 0x4f, 0xb1, 0x78, 0x2a);
DEFINE_GUID(IID_IEffectivePermission, 0x3853dc76, 0x9f35, 0x407c, 0x88, 0xa1, 0xd1, 0x93, 0x44, 0x36, 0x5f, 0xbc);
DEFINE_GUID(IID_ISecurityObjectTypeInfo, 0xfc3066eb, 0x79ef, 0x444b, 0x91, 0x11, 0xd1, 0x8a, 0x75, 0xeb, 0xf2, 0xfa);
DEFINE_GUID(IID_ISecurityInformation3, 0xe2cdc9cc, 0x31bd, 0x4f8f, 0x8c, 0x8b, 0xb6, 0x41, 0xaf, 0x51, 0x6a, 0x1a);

HPROPSHEETPAGE WINAPI CreateSecurityPage(LPSECURITYINFO psi);
BOOL WINAPI EditSecurity(HWND owner, LPSECURITYINFO psi);
HRESULT WINAPI EditSecurityAdvanced(HWND owner, LPSECURITYINFO psi, SI_PAGE_TYPE uSIPage);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* __WINE_ACLUI_H */
