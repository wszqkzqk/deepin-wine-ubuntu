/*
 * Copyright (C) 2016 Alistair Leslie-Hughes
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

#ifndef __AUTHZ_H__
#define __AUTHZ_H__

#ifdef __cplusplus
extern "C" {
#endif

DECLARE_HANDLE(AUTHZ_ACCESS_CHECK_RESULTS_HANDLE);
DECLARE_HANDLE(AUTHZ_CLIENT_CONTEXT_HANDLE);
DECLARE_HANDLE(AUTHZ_RESOURCE_MANAGER_HANDLE);
DECLARE_HANDLE(AUTHZ_AUDIT_EVENT_HANDLE);

typedef AUTHZ_ACCESS_CHECK_RESULTS_HANDLE *PAUTHZ_ACCESS_CHECK_RESULTS_HANDLE;
typedef AUTHZ_CLIENT_CONTEXT_HANDLE *PAUTHZ_CLIENT_CONTEXT_HANDLE;

typedef BOOL (CALLBACK *PFN_AUTHZ_COMPUTE_DYNAMIC_GROUPS) (
        AUTHZ_CLIENT_CONTEXT_HANDLE handle, void *args,
        PSID_AND_ATTRIBUTES *sid_attr_array, DWORD *sid_cnt,
        PSID_AND_ATTRIBUTES *restricted_sid_attr_array,
        DWORD *restricted_sid_cnt);

typedef BOOL (CALLBACK *PFN_AUTHZ_DYNAMIC_ACCESS_CHECK) (
        AUTHZ_CLIENT_CONTEXT_HANDLE handle, PACE_HEADER ace,
        void *args, BOOL *ace_applicable);

typedef VOID (CALLBACK *PFN_AUTHZ_FREE_DYNAMIC_GROUPS) (
        PSID_AND_ATTRIBUTES sid_attr_array);

typedef struct _AUTHZ_REGISTRATION_OBJECT_TYPE_NAME_OFFSET
{
    WCHAR *szObjectTypeName;
    DWORD dwOffset;
} AUTHZ_REGISTRATION_OBJECT_TYPE_NAME_OFFSET, *PAUTHZ_REGISTRATION_OBJECT_TYPE_NAME_OFFSET;

typedef struct _AUTHZ_ACCESS_REQUEST
{
    ACCESS_MASK       DesiredAccess;
    PSID              PrincipalSelfSid;
    POBJECT_TYPE_LIST ObjectTypeList;
    DWORD             ObjectTypeListLength;
    void              *OptionalArguments;
} AUTHZ_ACCESS_REQUEST, *PAUTHZ_ACCESS_REQUEST;


#define AUTHZ_GENERATE_SUCCESS_AUDIT 0x1
#define AUTHZ_GENERATE_FAILURE_AUDIT 0x2

typedef struct _AUTHZ_ACCESS_REPLY
{
    DWORD       ResultListLength;
    ACCESS_MASK *GrantedAccessMask;
    DWORD       *SaclEvaluationResults;
    DWORD       *Error;
} AUTHZ_ACCESS_REPLY, *PAUTHZ_ACCESS_REPLY;

typedef struct _AUTHZ_SOURCE_SCHEMA_REGISTRATION
{
    DWORD dwFlags;
    WCHAR *szEventSourceName;
    WCHAR *szEventMessageFile;
    WCHAR *szEventSourceXmlSchemaFile;
    WCHAR *szEventAccessStringsFile;
    WCHAR *szExecutableImagePath;

    union
    {
        void *pReserved;
        GUID *pProviderGuid;
    } DUMMYUNIONNAME;

    DWORD dwObjectTypeNameCount;
    AUTHZ_REGISTRATION_OBJECT_TYPE_NAME_OFFSET ObjectTypeNames[ANYSIZE_ARRAY];
} AUTHZ_SOURCE_SCHEMA_REGISTRATION, *PAUTHZ_SOURCE_SCHEMA_REGISTRATION;

BOOL WINAPI AuthzInitializeResourceManager(DWORD flags, PFN_AUTHZ_DYNAMIC_ACCESS_CHECK access_checker,
        PFN_AUTHZ_COMPUTE_DYNAMIC_GROUPS compute_dyn_groups, PFN_AUTHZ_FREE_DYNAMIC_GROUPS free_dyn_groups,
        const WCHAR *managername, AUTHZ_RESOURCE_MANAGER_HANDLE *handle );

BOOL WINAPI AuthzInstallSecurityEventSource(DWORD flags, AUTHZ_SOURCE_SCHEMA_REGISTRATION *registration);

BOOL WINAPI AuthzAccessCheck(DWORD flags, AUTHZ_CLIENT_CONTEXT_HANDLE client_context,
        AUTHZ_ACCESS_REQUEST *request, AUTHZ_AUDIT_EVENT_HANDLE audit_event,
        PSECURITY_DESCRIPTOR security, PSECURITY_DESCRIPTOR *optional_security,
        DWORD optional_security_count, AUTHZ_ACCESS_REPLY *reply,
        AUTHZ_ACCESS_CHECK_RESULTS_HANDLE *access_check_result);

BOOL WINAPI AuthzFreeContext(AUTHZ_CLIENT_CONTEXT_HANDLE client_context);

BOOL WINAPI AuthzInitializeContextFromSid(DWORD flags, PSID sid,
        AUTHZ_RESOURCE_MANAGER_HANDLE resource_manager, LARGE_INTEGER *expire_time,
        LUID id, void *dynamic_group, AUTHZ_CLIENT_CONTEXT_HANDLE *client_context);

BOOL WINAPI AuthzInitializeContextFromToken(DWORD flags, HANDLE token_handle,
        AUTHZ_RESOURCE_MANAGER_HANDLE resource_manager, LARGE_INTEGER *expire_time,
        LUID id, void *dynamic_group, AUTHZ_CLIENT_CONTEXT_HANDLE *client_context);

#ifdef __cplusplus
}
#endif

#endif
