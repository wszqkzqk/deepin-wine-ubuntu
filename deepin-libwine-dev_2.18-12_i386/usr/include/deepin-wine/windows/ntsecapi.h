/*
 * Copyright (C) 1999 Juergen Schmied
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

#ifndef __WINE_NTSECAPI_H
#define __WINE_NTSECAPI_H

#ifndef GUID_DEFINED
# include <guiddef.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

/* Policy access rights */
#define POLICY_VIEW_LOCAL_INFORMATION           __MSABI_LONG(0x00000001)
#define POLICY_VIEW_AUDIT_INFORMATION           __MSABI_LONG(0x00000002)
#define POLICY_GET_PRIVATE_INFORMATION          __MSABI_LONG(0x00000004)
#define POLICY_TRUST_ADMIN                      __MSABI_LONG(0x00000008)
#define POLICY_CREATE_ACCOUNT                   __MSABI_LONG(0x00000010)
#define POLICY_CREATE_SECRET                    __MSABI_LONG(0x00000020)
#define POLICY_CREATE_PRIVILEGE                 __MSABI_LONG(0x00000040)
#define POLICY_SET_DEFAULT_QUOTA_LIMITS         __MSABI_LONG(0x00000080)
#define POLICY_SET_AUDIT_REQUIREMENTS           __MSABI_LONG(0x00000100)
#define POLICY_AUDIT_LOG_ADMIN                  __MSABI_LONG(0x00000200)
#define POLICY_SERVER_ADMIN                     __MSABI_LONG(0x00000400)
#define POLICY_LOOKUP_NAMES                     __MSABI_LONG(0x00000800)
#define POLICY_NOTIFICATION                     __MSABI_LONG(0x00001000)

#define POLICY_ALL_ACCESS                       ( \
    STANDARD_RIGHTS_REQUIRED | \
    POLICY_VIEW_LOCAL_INFORMATION | \
    POLICY_VIEW_AUDIT_INFORMATION | \
    POLICY_GET_PRIVATE_INFORMATION | \
    POLICY_TRUST_ADMIN | \
    POLICY_CREATE_ACCOUNT | \
    POLICY_CREATE_SECRET | \
    POLICY_CREATE_PRIVILEGE | \
    POLICY_SET_DEFAULT_QUOTA_LIMITS | \
    POLICY_SET_AUDIT_REQUIREMENTS | \
    POLICY_AUDIT_LOG_ADMIN | \
    POLICY_SERVER_ADMIN | \
    POLICY_LOOKUP_NAMES)


#define POLICY_READ                             ( \
    STANDARD_RIGHTS_READ | \
    POLICY_VIEW_AUDIT_INFORMATION | \
    POLICY_GET_PRIVATE_INFORMATION)

#define POLICY_WRITE                            ( \
   STANDARD_RIGHTS_WRITE | \
   POLICY_TRUST_ADMIN | \
   POLICY_CREATE_ACCOUNT | \
   POLICY_CREATE_SECRET | \
   POLICY_CREATE_PRIVILEGE | \
   POLICY_SET_DEFAULT_QUOTA_LIMITS | \
   POLICY_SET_AUDIT_REQUIREMENTS | \
   POLICY_AUDIT_LOG_ADMIN | \
   POLICY_SERVER_ADMIN)

#define POLICY_EXECUTE                          ( \
   STANDARD_RIGHTS_EXECUTE | \
   POLICY_VIEW_LOCAL_INFORMATION | \
   POLICY_LOOKUP_NAMES)

#define POLICY_AUDIT_EVENT_UNCHANGED __MSABI_LONG(0x00000000)
#define POLICY_AUDIT_EVENT_SUCCESS   __MSABI_LONG(0x00000001)
#define POLICY_AUDIT_EVENT_FAILURE   __MSABI_LONG(0x00000002)
#define POLICY_AUDIT_EVENT_NONE      __MSABI_LONG(0x00000004)

#define POLICY_AUDIT_EVENT_MASK (POLICY_AUDIT_EVENT_SUCCESS | \
                                 POLICY_AUDIT_EVENT_FAILURE | \
                                 POLICY_AUDIT_EVENT_NONE)

/* logon rights names */
#define SE_BATCH_LOGON_NAME \
 TEXT("SeBatchLogonRight")
#define SE_INTERACTIVE_LOGON_NAME \
 TEXT("SeInteractiveLogonRight")
#define SE_NETWORK_LOGON_NAME \
 TEXT("SeNetworkLogonRight")
#define SE_REMOTE_INTERACTIVE_LOGON_NAME \
 TEXT("SeRemoteInteractiveLogonRight")
#define SE_SERVICE_LOGON_NAME \
 TEXT("SeServiceLogonRight")
#define SE_DENY_BATCH_LOGON_NAME \
 TEXT("SeDenyBatchLogonRight")
#define SE_DENY_INTERACTIVE_LOGON_NAME \
 TEXT("SeDenyInteractiveLogonRight")
#define SE_DENY_NETWORK_LOGON_NAME \
 TEXT("SeDenyNetworkLogonRight")
#define SE_DENY_REMOTE_INTERACTIVE_LOGON_NAME \
 TEXT("SeDenyRemoteInteractiveLogonRight")
#define SE_DENY_SERVICE_LOGON_NAME \
 TEXT("SeDenyServiceLogonRight")

#ifndef WINE_NTSTATUS_DECLARED
#define WINE_NTSTATUS_DECLARED
typedef LONG NTSTATUS;
#endif
#ifndef WINE_PNTSTATUS_DECLARED
#define WINE_PNTSTATUS_DECLARED
typedef NTSTATUS *PNTSTATUS;
#endif

typedef enum _SECURITY_LOGON_TYPE
{
    Interactive = 2,
    Network,
    Batch,
    Service,
    Proxy
} SECURITY_LOGON_TYPE, *PSECURITY_LOGON_TYPE;

typedef enum _POLICY_AUDIT_EVENT_TYPE
{
    AuditCategorySystem,
    AuditCategoryLogon,
    AuditCategoryObjectAccess,
    AuditCategoryPrivilegeUse,
    AuditCategoryDetailedTracking,
    AuditCategoryPolicyChange,
    AuditCategoryAccountManagement
} POLICY_AUDIT_EVENT_TYPE, *PPOLICY_AUDIT_EVENT_TYPE;

#ifndef __STRING_DEFINED__
#define __STRING_DEFINED__
typedef struct _STRING {
  USHORT Length;
  USHORT MaximumLength;
  PCHAR Buffer;
} STRING, *PSTRING;
#endif

#ifndef __UNICODE_STRING_DEFINED__
#define __UNICODE_STRING_DEFINED__
typedef struct _UNICODE_STRING {
  USHORT Length;        /* bytes */
  USHORT MaximumLength; /* bytes */
  PWSTR  Buffer;
} UNICODE_STRING, *PUNICODE_STRING;
#endif

#ifndef __OBJECT_ATTRIBUTES_DEFINED__
#define __OBJECT_ATTRIBUTES_DEFINED__
typedef struct _OBJECT_ATTRIBUTES {
  ULONG Length;
  HANDLE RootDirectory;
  PUNICODE_STRING ObjectName;
  ULONG Attributes;
  PVOID SecurityDescriptor;       /* type SECURITY_DESCRIPTOR */
  PVOID SecurityQualityOfService; /* type SECURITY_QUALITY_OF_SERVICE */
} OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;
#endif

typedef UNICODE_STRING LSA_UNICODE_STRING, *PLSA_UNICODE_STRING;
typedef STRING LSA_STRING, *PLSA_STRING;
typedef OBJECT_ATTRIBUTES LSA_OBJECT_ATTRIBUTES, *PLSA_OBJECT_ATTRIBUTES;

typedef PVOID LSA_HANDLE, *PLSA_HANDLE;
typedef ULONG LSA_ENUMERATION_HANDLE, *PLSA_ENUMERATION_HANDLE;
typedef ULONG LSA_OPERATIONAL_MODE, *PLSA_OPERATIONAL_MODE;

typedef enum
{
	PolicyAuditLogInformation = 1,
	PolicyAuditEventsInformation,
	PolicyPrimaryDomainInformation,
	PolicyPdAccountInformation,
	PolicyAccountDomainInformation,
	PolicyLsaServerRoleInformation,
	PolicyReplicaSourceInformation,
	PolicyDefaultQuotaInformation,
	PolicyModificationInformation,
	PolicyAuditFullSetInformation,
	PolicyAuditFullQueryInformation,
	PolicyDnsDomainInformation
} POLICY_INFORMATION_CLASS, *PPOLICY_INFORMATION_CLASS;

typedef ULONG POLICY_AUDIT_EVENT_OPTIONS, *PPOLICY_AUDIT_EVENT_OPTIONS;

typedef struct _POLICY_AUDIT_EVENTS_INFO
{
	BOOLEAN AuditingMode;
	PPOLICY_AUDIT_EVENT_OPTIONS EventAuditingOptions;
	ULONG MaximumAuditEventCount;
} POLICY_AUDIT_EVENTS_INFO, *PPOLICY_AUDIT_EVENTS_INFO;

typedef struct _POLICY_PRIMARY_DOMAIN_INFO
{
    LSA_UNICODE_STRING Name;
    PSID Sid;
} POLICY_PRIMARY_DOMAIN_INFO, *PPOLICY_PRIMARY_DOMAIN_INFO;

typedef struct _POLICY_ACCOUNT_DOMAIN_INFO
{
    LSA_UNICODE_STRING DomainName;
    PSID DomainSid;
} POLICY_ACCOUNT_DOMAIN_INFO, *PPOLICY_ACCOUNT_DOMAIN_INFO;

typedef struct _POLICY_DNS_DOMAIN_INFO
{
    LSA_UNICODE_STRING Name;
    LSA_UNICODE_STRING DnsDomainName;
    LSA_UNICODE_STRING DnsForestName;
    GUID DomainGuid;
    PSID Sid;
} POLICY_DNS_DOMAIN_INFO, *PPOLICY_DNS_DOMAIN_INFO;

typedef enum _POLICY_LSA_SERVER_ROLE
{
    PolicyServerRoleBackup = 2,
    PolicyServerRolePrimary
} POLICY_LSA_SERVER_ROLE, *PPOLICY_LSA_SERVER_ROLE;

typedef struct _POLICY_LSA_SERVER_ROLE_INFO
{
    POLICY_LSA_SERVER_ROLE LsaServerRole;
} POLICY_LSA_SERVER_ROLE_INFO, *PPOLICY_LSA_SERVER_ROLE_INFO;

typedef struct _POLICY_MODIFICATION_INFO
{
    LARGE_INTEGER ModifiedId;
    LARGE_INTEGER DatabaseCreationTime;
} POLICY_MODIFICATION_INFO, *PPOLICY_MODIFICATION_INFO;

typedef struct _SECURITY_LOGON_SESSION_DATA {
    ULONG Size;
    LUID LogonId;
    LSA_UNICODE_STRING UserName;
    LSA_UNICODE_STRING LogonDomain;
    LSA_UNICODE_STRING AuthenticationPackage;
    ULONG LogonType;
    ULONG Session;
    PSID Sid;
    LARGE_INTEGER LogonTime;
    LSA_UNICODE_STRING LogonServer;
    LSA_UNICODE_STRING DnsDomainName;
    LSA_UNICODE_STRING Upn;
} SECURITY_LOGON_SESSION_DATA, *PSECURITY_LOGON_SESSION_DATA;

typedef struct
{
    SID_NAME_USE Use;
    LSA_UNICODE_STRING Name;
    LONG DomainIndex;
} LSA_TRANSLATED_NAME, *PLSA_TRANSLATED_NAME;

typedef struct
{
    LSA_UNICODE_STRING Name;
    PSID Sid;
} LSA_TRUST_INFORMATION, *PLSA_TRUST_INFORMATION;

typedef struct
{
    ULONG Entries;
    PLSA_TRUST_INFORMATION Domains;
} LSA_REFERENCED_DOMAIN_LIST, *PLSA_REFERENCED_DOMAIN_LIST;

typedef struct _LSA_TRANSLATED_SID
{
    SID_NAME_USE Use;
    ULONG RelativeId;
    LONG DomainIndex;
} LSA_TRANSLATED_SID, *PLSA_TRANSLATED_SID;

typedef struct _TRUSTED_DOMAIN_INFORMATION_EX
{
    LSA_UNICODE_STRING Name;
    LSA_UNICODE_STRING FlatName;
    PSID Sid;
    ULONG TrustDirection;
    ULONG TrustType;
    ULONG TrustAttributes;
} TRUSTED_DOMAIN_INFORMATION_EX, *PTRUSTED_DOMAIN_INFORMATION_EX;

typedef struct _LSA_AUTH_INFORMATION
{
    LARGE_INTEGER LastUpdateTime;
    ULONG AuthType;
    ULONG AuthInfoLength;
    PUCHAR AuthInfo;
} LSA_AUTH_INFORMATION, *PLSA_AUTH_INFORMATION;

typedef struct _TRUSTED_DOMAIN_AUTH_INFORMATION
{
    ULONG IncomingAuthInfos;
    PLSA_AUTH_INFORMATION IncomingAuthenticationInformation;
    PLSA_AUTH_INFORMATION IncomingPreviousAuthenticationInformation;
    ULONG OutgoingAuthInfos;
    PLSA_AUTH_INFORMATION OutgoingAuthenticationInformation;
    PLSA_AUTH_INFORMATION OutgoingPreviousAuthenticationInformation;
} TRUSTED_DOMAIN_AUTH_INFORMATION, *PTRUSTED_DOMAIN_AUTH_INFORMATION;

typedef struct _LSA_TRANSLATED_SID2
{
    SID_NAME_USE Use;
    PSID Sid;
    LONG DomainIndex;
    ULONG Flags;
} LSA_TRANSLATED_SID2, *PLSA_TRANSLATED_SID2;

typedef enum _TRUSTED_INFORMATION_CLASS
{
    TrustedDomainNameInformation = 1,
    TrustedControllersInformation,
    TrustedPosixOffsetInformation,
    TrustedPasswordInformation,
    TrustedDomainInformationBasic,
    TrustedDomainInformationEx,
    TrustedDomainAuthInformation,
    TrustedDomainFullInformation
} TRUSTED_INFORMATION_CLASS, *PTRUSTED_INFORMATION_CLASS;

typedef enum _POLICY_NOTIFICATION_INFORMATION_CLASS
{
    PolicyNotifyAuditEventsInformation = 1,
    PolicyNotifyAccountDomainInformation,
    PolicyNotifyServerRoleInformation,
    PolicyNotifyDnsDomainInformation,
    PolicyNotifyDomainEfsInformation,
    PolicyNotifyDomainKerberosTicketInformation,
    PolicyNotifyMachineAccountPasswordInformation
} POLICY_NOTIFICATION_INFORMATION_CLASS, *PPOLICY_NOTIFICATION_INFORMATION_CLASS;

#define RtlGenRandom                    SystemFunction036
#define RtlEncryptMemory                SystemFunction040
#define RtlDecryptMemory                SystemFunction041

BOOLEAN WINAPI RtlGenRandom(PVOID,ULONG);
NTSTATUS WINAPI RtlEncryptMemory(PVOID,ULONG,ULONG);
NTSTATUS WINAPI RtlDecryptMemory(PVOID,ULONG,ULONG);

NTSTATUS WINAPI LsaAddAccountRights(LSA_HANDLE,PSID,PLSA_UNICODE_STRING,ULONG);
NTSTATUS WINAPI LsaCallAuthenticationPackage(HANDLE,ULONG,PVOID,ULONG,PVOID*,PULONG,PNTSTATUS);
NTSTATUS WINAPI LsaClose(LSA_HANDLE);
NTSTATUS WINAPI LsaConnectUntrusted(PHANDLE);
NTSTATUS WINAPI LsaCreateTrustedDomainEx(LSA_HANDLE,PTRUSTED_DOMAIN_INFORMATION_EX,
                                         PTRUSTED_DOMAIN_AUTH_INFORMATION,ACCESS_MASK,PLSA_HANDLE);
NTSTATUS WINAPI LsaDeleteTrustedDomain(LSA_HANDLE,PSID);
NTSTATUS WINAPI LsaDeregisterLogonProcess(HANDLE);
NTSTATUS WINAPI LsaEnumerateAccountRights(LSA_HANDLE,PSID,PLSA_UNICODE_STRING*,PULONG);
NTSTATUS WINAPI LsaEnumerateAccountsWithUserRight(LSA_HANDLE,PLSA_UNICODE_STRING,PVOID*,PULONG);
NTSTATUS WINAPI LsaEnumerateLogonSessions(PULONG,PLUID*);
NTSTATUS WINAPI LsaEnumerateTrustedDomains(LSA_HANDLE,PLSA_ENUMERATION_HANDLE,PVOID*,ULONG,PULONG);
NTSTATUS WINAPI LsaEnumerateTrustedDomainsEx(LSA_HANDLE,PLSA_ENUMERATION_HANDLE,PVOID*,ULONG,PULONG);
NTSTATUS WINAPI LsaFreeMemory(PVOID);
NTSTATUS WINAPI LsaFreeReturnBuffer(PVOID);
NTSTATUS WINAPI LsaGetLogonSessionData(PLUID,PSECURITY_LOGON_SESSION_DATA*);
NTSTATUS WINAPI LsaLogonUser(HANDLE,PLSA_STRING,SECURITY_LOGON_TYPE,ULONG,PVOID,ULONG,PTOKEN_GROUPS,PTOKEN_SOURCE,PVOID*,PULONG,PLUID,PHANDLE,PQUOTA_LIMITS,PNTSTATUS);
NTSTATUS WINAPI LsaLookupAuthenticationPackage(HANDLE,PLSA_STRING,PULONG);
NTSTATUS WINAPI LsaLookupNames(LSA_HANDLE,ULONG,PLSA_UNICODE_STRING,PLSA_REFERENCED_DOMAIN_LIST*,
                               PLSA_TRANSLATED_SID*);
NTSTATUS WINAPI LsaLookupNames2(LSA_HANDLE,ULONG,ULONG,PLSA_UNICODE_STRING,PLSA_REFERENCED_DOMAIN_LIST*,
                                PLSA_TRANSLATED_SID2*);
NTSTATUS WINAPI LsaLookupSids(LSA_HANDLE,ULONG,PSID *,PLSA_REFERENCED_DOMAIN_LIST *,PLSA_TRANSLATED_NAME *);
ULONG WINAPI LsaNtStatusToWinError(NTSTATUS);
NTSTATUS WINAPI LsaOpenPolicy(PLSA_UNICODE_STRING,PLSA_OBJECT_ATTRIBUTES,ACCESS_MASK,PLSA_HANDLE);
NTSTATUS WINAPI LsaOpenTrustedDomainByName(LSA_HANDLE,PLSA_UNICODE_STRING,ACCESS_MASK,PLSA_HANDLE);
NTSTATUS WINAPI LsaQueryInformationPolicy(LSA_HANDLE,POLICY_INFORMATION_CLASS,PVOID*);
NTSTATUS WINAPI LsaQueryTrustedDomainInfo(LSA_HANDLE,PSID,TRUSTED_INFORMATION_CLASS,PVOID*);
NTSTATUS WINAPI LsaQueryTrustedDomainInfoByName(LSA_HANDLE,PLSA_UNICODE_STRING,TRUSTED_INFORMATION_CLASS,PVOID*);
NTSTATUS WINAPI LsaRegisterLogonProcess(PLSA_STRING,PHANDLE,PLSA_OPERATIONAL_MODE);
NTSTATUS WINAPI LsaRegisterPolicyChangeNotification(POLICY_NOTIFICATION_INFORMATION_CLASS,HANDLE);
NTSTATUS WINAPI LsaRemoveAccountRights(LSA_HANDLE,PSID,BOOLEAN,PLSA_UNICODE_STRING,ULONG);
NTSTATUS WINAPI LsaRetrievePrivateData(LSA_HANDLE,PLSA_UNICODE_STRING,PLSA_UNICODE_STRING*);
NTSTATUS WINAPI LsaSetInformationPolicy(LSA_HANDLE,POLICY_INFORMATION_CLASS,PVOID);
NTSTATUS WINAPI LsaSetTrustedDomainInfoByName(LSA_HANDLE,PLSA_UNICODE_STRING,TRUSTED_INFORMATION_CLASS,PVOID);
NTSTATUS WINAPI LsaSetTrustedDomainInformation(LSA_HANDLE,PSID,TRUSTED_INFORMATION_CLASS,PVOID);
NTSTATUS WINAPI LsaStorePrivateData(LSA_HANDLE,PLSA_UNICODE_STRING,PLSA_UNICODE_STRING);
NTSTATUS WINAPI LsaUnregisterPolicyChangeNotification(POLICY_NOTIFICATION_INFORMATION_CLASS,HANDLE);

#ifdef __cplusplus
} /* extern "C" */
#endif /* defined(__cplusplus) */

#endif /* !defined(__WINE_NTSECAPI_H) */
