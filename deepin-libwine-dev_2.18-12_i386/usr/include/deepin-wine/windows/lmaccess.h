/*
 * Copyright 2002 Andriy Palamarchuk
 *
 * User information Net API.
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

#ifndef __WINE_LMACCESS_H
#define __WINE_LMACCESS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <lmcons.h>

#define ACCESS_NONE     0x0000
#define ACCESS_READ     0x0001
#define ACCESS_WRITE    0x0002
#define ACCESS_CREATE   0x0004
#define ACCESS_EXEC     0x0008
#define ACCESS_DELETE   0x0010
#define ACCESS_ATRIB    0x0020
#define ACCESS_PERM     0x0040
#define ACCESS_GROUP    0x8000
#define ACCESS_ALL      (ACCESS_READ|ACCESS_WRITE|ACCESS_CREATE|ACCESS_EXEC|ACCESS_DELETE|ACCESS_ATRIB|ACCESS_PERM)

#define UF_SCRIPT                               0x000001
#define UF_ACCOUNTDISABLE                       0x000002
#define UF_HOMEDIR_REQUIRED                     0x000008
#define UF_LOCKOUT                              0x000010
#define UF_PASSWD_NOTREQD                       0x000020
#define UF_PASSWD_CANT_CHANGE                   0x000040
#define UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED      0x000080
#define UF_TEMP_DUPLICATE_ACCOUNT               0x000100
#define UF_NORMAL_ACCOUNT                       0x000200
#define UF_INTERDOMAIN_TRUST_ACCOUNT            0x000800
#define UF_WORKSTATION_TRUST_ACCOUNT            0x001000
#define UF_SERVER_TRUST_ACCOUNT                 0x002000
#define UF_DONT_EXPIRE_PASSWD                   0x010000
#define UF_MNS_LOGON_ACCOUNT                    0x020000
#define UF_SMARTCARD_REQUIRED                   0x040000
#define UF_TRUSTED_FOR_DELEGATION               0x080000
#define UF_NOT_DELEGATED                        0x100000
#define UF_USE_DES_KEY_ONLY                     0x200000
#define UF_DONT_REQUIRE_PREAUTH                 0x400000
#define UF_PASSWORD_EXPIRED                     0x800000


#define UF_MACHINE_ACCOUNT_MASK ( \
    UF_INTERDOMAIN_TRUST_ACCOUNT | \
    UF_WORKSTATION_TRUST_ACCOUNT | \
    UF_SERVER_TRUST_ACCOUNT)

#define UF_ACCOUNT_TYPE_MASK ( \
    UF_TEMP_DUPLICATE_ACCOUNT | \
    UF_NORMAL_ACCOUNT | \
    UF_INTERDOMAIN_TRUST_ACCOUNT | \
    UF_WORKSTATION_TRUST_ACCOUNT | \
    UF_SERVER_TRUST_ACCOUNT)

#define UF_SETTABLE_BITS ( \
    UF_SCRIPT | \
    UF_ACCOUNTDISABLE | \
    UF_LOCKOUT | \
    UF_HOMEDIR_REQUIRED  | \
    UF_PASSWD_NOTREQD | \
    UF_PASSWD_CANT_CHANGE | \
    UF_ACCOUNT_TYPE_MASK | \
    UF_DONT_EXPIRE_PASSWD | \
    UF_MNS_LOGON_ACCOUNT |\
    UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED |\
    UF_SMARTCARD_REQUIRED | \
    UF_TRUSTED_FOR_DELEGATION | \
    UF_NOT_DELEGATED | \
    UF_USE_DES_KEY_ONLY  | \
    UF_DONT_REQUIRE_PREAUTH |\
    UF_PASSWORD_EXPIRED)

#if defined(__GNUC__)
# define GROUP_SPECIALGRP_USERS (const WCHAR []){ 'U','S','E','R','S',0 }
#elif defined(_MSC_VER)
# define GROUP_SPECIALGRP_USERS         L"USERS"
#else
static const WCHAR GROUP_SPECIALGRP_USERS[] = { 'U','S','E','R','S',0 };
#endif

#if defined(__GNUC__)
# define GROUP_SPECIALGRP_ADMINS (const WCHAR []){ 'A','D','M','I','N','S',0 }
#elif defined(_MSC_VER)
# define GROUP_SPECIALGRP_ADMINS        L"ADMINS"
#else
static const WCHAR GROUP_SPECIALGRP_ADMINS[] = { 'A','D','M','I','N','S',0 };
#endif

#if defined(__GNUC__)
# define GROUP_SPECIALGRP_GUESTS  (const WCHAR []){ 'G','U','E','S','T','S',0 }
#elif defined(_MSC_VER)
# define GROUP_SPECIALGRP_GUESTS        L"GUESTS"
#else
static const WCHAR GROUP_SPECIALGRP_GUESTS[] = { 'G','U','E','S','T','S',0 };
#endif

#if defined(__GNUC__)
# define GROUP_SPECIALGRP_LOCAL (const WCHAR []){ 'L','O','C','A','L',0 }
#elif defined(_MSC_VER)
# define GROUP_SPECIALGRP_LOCAL         L"LOCAL"
#else
static const WCHAR GROUP_SPECIALGRP_LOCAL[] = { 'L','O','C','A','L',0 };
#endif

#ifndef WINE_NTSTATUS_DECLARED
#define WINE_NTSTATUS_DECLARED
typedef LONG NTSTATUS;
#endif
#ifndef WINE_PNTSTATUS_DECLARED
#define WINE_PNTSTATUS_DECLARED
typedef NTSTATUS *PNTSTATUS;
#endif

/* NetGetUserInfo structures */
typedef struct _USER_INFO_0 {
    LPWSTR usri0_name;
} USER_INFO_0, *PUSER_INFO_0, *LPUSER_INFO_0;

typedef struct _USER_INFO_1 {
    LPWSTR usri1_name;
    LPWSTR usri1_password;
    DWORD usri1_password_age;
    DWORD usri1_priv;
    LPWSTR usri1_home_dir;
    LPWSTR usri1_comment;
    DWORD usri1_flags;
    LPWSTR usri1_script_path;
} USER_INFO_1, *PUSER_INFO_1, *LPUSER_INFO_1;

typedef struct _USER_INFO_2 {
    LPWSTR usri2_name;
    LPWSTR usri2_password;
    DWORD usri2_password_age;
    DWORD usri2_priv;
    LPWSTR usri2_home_dir;
    LPWSTR usri2_comment;
    DWORD usri2_flags;
    LPWSTR usri2_script_path;
    DWORD usri2_auth_flags;
    LPWSTR usri2_full_name;
    LPWSTR usri2_usr_comment;
    LPWSTR usri2_parms;
    LPWSTR usri2_workstations;
    DWORD usri2_last_logon;
    DWORD usri2_last_logoff;
    DWORD usri2_acct_expires;
    DWORD usri2_max_storage;
    DWORD usri2_units_per_week;
    PBYTE usri2_logon_hours;
    DWORD usri2_bad_pw_count;
    DWORD usri2_num_logons;
    LPWSTR usri2_logon_server;
    DWORD usri2_country_code;
    DWORD usri2_code_page;
} USER_INFO_2, *PUSER_INFO_2, *LPUSER_INFO_2;

typedef struct _USER_INFO_3 {
    LPWSTR usri3_name;
    LPWSTR usri3_password;
    DWORD usri3_password_age;
    DWORD usri3_priv;
    LPWSTR usri3_home_dir;
    LPWSTR usri3_comment;
    DWORD usri3_flags;
    LPWSTR usri3_script_path;
    DWORD usri3_auth_flags;
    LPWSTR usri3_full_name;
    LPWSTR usri3_usr_comment;
    LPWSTR usri3_parms;
    LPWSTR usri3_workstations;
    DWORD usri3_last_logon;
    DWORD usri3_last_logoff;
    DWORD usri3_acct_expires;
    DWORD usri3_max_storage;
    DWORD usri3_units_per_week;
    PBYTE usri3_logon_hours;
    DWORD usri3_bad_pw_count;
    DWORD usri3_num_logons;
    LPWSTR usri3_logon_server;
    DWORD usri3_country_code;
    DWORD usri3_code_page;
    DWORD usri3_user_id;
    DWORD usri3_primary_group_id;
    LPWSTR usri3_profile;
    LPWSTR usri3_home_dir_drive;
    DWORD usri3_password_expired;
} USER_INFO_3, *PUSER_INFO_3, *LPUSER_INFO_3;

typedef struct _USER_INFO_4 {
    LPWSTR usri4_name;
    LPWSTR usri4_password;
    DWORD usri4_password_age;
    DWORD usri4_priv;
    LPWSTR usri4_home_dir;
    LPWSTR usri4_comment;
    DWORD usri4_flags;
    LPWSTR usri4_script_path;
    DWORD usri4_auth_flags;
    LPWSTR usri4_full_name;
    LPWSTR usri4_usr_comment;
    LPWSTR usri4_parms;
    LPWSTR usri4_workstations;
    DWORD usri4_last_logon;
    DWORD usri4_last_logoff;
    DWORD usri4_acct_expires;
    DWORD usri4_max_storage;
    DWORD usri4_units_per_week;
    PBYTE usri4_logon_hours;
    DWORD usri4_bad_pw_count;
    DWORD usri4_num_logons;
    LPWSTR usri4_logon_server;
    DWORD usri4_country_code;
    DWORD usri4_code_page;
    PSID usri4_user_sid;
    DWORD usri4_primary_group_id;
    LPWSTR usri4_profile;
    LPWSTR usri4_home_dir_drive;
    DWORD usri4_password_expired;
} USER_INFO_4, *PUSER_INFO_4, *LPUSER_INFO_4;

typedef struct _USER_INFO_10 {
    LPWSTR usri10_name;
    LPWSTR usri10_comment;
    LPWSTR usri10_usr_comment;
    LPWSTR usri10_full_name;
} USER_INFO_10, *PUSER_INFO_10, *LPUSER_INFO_10;

typedef struct _USER_INFO_11 {
    LPWSTR usri11_name;
    LPWSTR usri11_comment;
    LPWSTR usri11_usr_comment;
    LPWSTR usri11_full_name;
    DWORD usri11_priv;
    DWORD usri11_auth_flags;
    DWORD usri11_password_age;
    LPWSTR usri11_home_dir;
    LPWSTR usri11_parms;
    DWORD usri11_last_logon;
    DWORD usri11_last_logoff;
    DWORD usri11_bad_pw_count;
    DWORD usri11_num_logons;
    LPWSTR usri11_logon_server;
    DWORD usri11_country_code;
    LPWSTR usri11_workstations;
    DWORD usri11_max_storage;
    DWORD usri11_units_per_week;
    PBYTE usri11_logon_hours;
    DWORD usri11_code_page;
} USER_INFO_11, *PUSER_INFO_11, *LPUSER_INFO_11;

typedef struct _USER_INFO_20 {
    LPWSTR usri20_name;
    LPWSTR usri20_full_name;
    LPWSTR usri20_comment;
    DWORD usri20_flags;
    DWORD usri20_user_id;
} USER_INFO_20, *PUSER_INFO_20, *LPUSER_INFO_20;

typedef struct _USER_INFO_23 {
    LPWSTR usri23_name;
    LPWSTR usri23_full_name;
    LPWSTR usri23_comment;
    DWORD usri23_flags;
    PSID usri23_user_sid;
} USER_INFO_23, *PUSER_INFO_23, *LPUSER_INFO_23;

typedef struct _USER_INFO_1003 {
    LPWSTR  usri1003_password;
} USER_INFO_1003, *PUSER_INFO_1003, *LPUSER_INFO_1003;

typedef struct _USER_INFO_1005 {
    DWORD   usri1005_priv;
} USER_INFO_1005, *PUSER_INFO_1005, *LPUSER_INFO_1005;

typedef struct _USER_INFO_1006 {
    LPWSTR  usri1006_home_dir;
} USER_INFO_1006, *PUSER_INFO_1006, *LPUSER_INFO_1006;

typedef struct _USER_INFO_1007 {
    LPWSTR  usri1007_comment;
} USER_INFO_1007, *PUSER_INFO_1007, *LPUSER_INFO_1007;

typedef struct _USER_INFO_1008 {
    DWORD   usri1008_flags;
} USER_INFO_1008, *PUSER_INFO_1008, *LPUSER_INFO_1008;

typedef struct _USER_INFO_1009 {
    LPWSTR  usri1009_script_path;
} USER_INFO_1009, *PUSER_INFO_1009, *LPUSER_INFO_1009;

typedef struct _USER_INFO_1010 {
    DWORD   usri1010_auth_flags;
} USER_INFO_1010, *PUSER_INFO_1010, *LPUSER_INFO_1010;

typedef struct _USER_INFO_1011 {
    LPWSTR  usri1011_full_name;
} USER_INFO_1011, *PUSER_INFO_1011, *LPUSER_INFO_1011;

typedef struct _USER_INFO_1012 {
    LPWSTR  usri1012_usr_comment;
} USER_INFO_1012, *PUSER_INFO_1012, *LPUSER_INFO_1012;

typedef struct _USER_INFO_1013 {
    LPWSTR  usri1013_parms;
} USER_INFO_1013, *PUSER_INFO_1013, *LPUSER_INFO_1013;

typedef struct _USER_INFO_1014 {
    LPWSTR  usri1014_workstations;
} USER_INFO_1014, *PUSER_INFO_1014, *LPUSER_INFO_1014;

typedef struct _USER_INFO_1017 {
    DWORD   usri1017_acct_expires;
} USER_INFO_1017, *PUSER_INFO_1017, *LPUSER_INFO_1017;

typedef struct _USER_INFO_1018 {
    DWORD   usri1018_max_storage;
} USER_INFO_1018, *PUSER_INFO_1018, *LPUSER_INFO_1018;

typedef struct _USER_INFO_1020 {
    DWORD   usri1020_units_per_week;
    LPBYTE  usri1020_logon_hours;
} USER_INFO_1020, *PUSER_INFO_1020, *LPUSER_INFO_1020;

typedef struct _USER_INFO_1023 {
    LPWSTR  usri1023_logon_server;
} USER_INFO_1023, *PUSER_INFO_1023, *LPUSER_INFO_1023;

typedef struct _USER_INFO_1024 {
    DWORD   usri1024_country_code;
} USER_INFO_1024, *PUSER_INFO_1024, *LPUSER_INFO_1024;

typedef struct _USER_INFO_1025 {
    DWORD   usri1025_code_page;
} USER_INFO_1025, *PUSER_INFO_1025, *LPUSER_INFO_1025;

typedef struct _USER_INFO_1051 {
    DWORD   usri1051_primary_group_id;
} USER_INFO_1051, *PUSER_INFO_1051, *LPUSER_INFO_1051;

typedef struct _USER_INFO_1052 {
    LPWSTR  usri1052_profile;
} USER_INFO_1052, *PUSER_INFO_1052, *LPUSER_INFO_1052;

typedef struct _USER_INFO_1053 {
    LPWSTR  usri1053_home_dir_drive;
} USER_INFO_1053, *PUSER_INFO_1053, *LPUSER_INFO_1053;

typedef struct _USER_MODALS_INFO_0 {
    DWORD usrmod0_min_passwd_len;
    DWORD usrmod0_max_passwd_age;
    DWORD usrmod0_min_passwd_age;
    DWORD usrmod0_force_logoff;
    DWORD usrmod0_password_hist_len;
} USER_MODALS_INFO_0, *PUSER_MODALS_INFO_0, *LPUSER_MODALS_INFO_0;

typedef struct _USER_MODALS_INFO_1 {
    DWORD usrmod1_role;
    LPWSTR usrmod1_primary;
} USER_MODALS_INFO_1, *PUSER_MODALS_INFO_1, *LPUSER_MODALS_INFO_1;

typedef struct _USER_MODALS_INFO_2 {
    LPWSTR usrmod2_domain_name;
    PSID usrmod2_domain_id;
} USER_MODALS_INFO_2, *PUSER_MODALS_INFO_2, *LPUSER_MODALS_INFO_2;

typedef struct _USER_MODALS_INFO_3 {
    DWORD usrmod3_lockout_duration;
    DWORD usrmod3_lockout_observation_window;
    DWORD usrmod3_lockout_threshold;
} USER_MODALS_INFO_3, *PUSER_MODALS_INFO_3, *LPUSER_MODALS_INFO_3;

typedef struct _NET_DISPLAY_USER {
    LPWSTR usri1_name;
    LPWSTR usri1_comment;
    DWORD usri1_flags;
    LPWSTR usri1_full_name;
    DWORD usri1_user_id;
    DWORD usri1_next_index;
} NET_DISPLAY_USER, *PNET_DISPLAY_USER;

typedef struct _NET_DISPLAY_MACHINE {
    LPWSTR usri2_name;
    LPWSTR usri2_comment;
    DWORD usri2_flags;
    DWORD usri2_user_id;
    DWORD usri2_next_index;
} NET_DISPLAY_MACHINE, *PNET_DISPLAY_MACHINE;

typedef struct _NET_DISPLAY_GROUP {
    LPWSTR grpi3_name;
    LPWSTR grpi3_comment;
    DWORD grpi3_group_id;
    DWORD grpi3_attributes;
    DWORD grpi3_next_index;
} NET_DISPLAY_GROUP, *PNET_DISPLAY_GROUP;

typedef struct _LOCALGROUP_INFO_0 {
    LPWSTR lgrpi0_name;
} LOCALGROUP_INFO_0, *PLOCALGROUP_INFO_0, *LPLOCALGROUP_INFO_0;

typedef struct _LOCALGROUP_INFO_1 {
    LPWSTR lgrpi1_name;
    LPWSTR lgrpi1_comment;
} LOCALGROUP_INFO_1, *PLOCALGROUP_INFO_1, *LPLOCALGROUP_INFO_1;

typedef struct _LOCALGROUP_INFO_1002 {
    LPWSTR lgrpi1002_comment;
} LOCALGROUP_INFO_1002, *PLOCALGROUP_INFO_1002, *LPLOCALGROUP_INFO_1002;

typedef struct _LOCALGROUP_MEMBERS_INFO_0 {
    PSID lgrmi0_sid;
} LOCALGROUP_MEMBERS_INFO_0, *PLOCALGROUP_MEMBERS_INFO_0, *LPLOCALGROUP_MEMBERS_INFO_0;

typedef struct _LOCALGROUP_MEMBERS_INFO_1 {
    PSID lgrmi1_sid;
    SID_NAME_USE lgrmi1_sidusage;
    LPWSTR lgrmi1_name;
} LOCALGROUP_MEMBERS_INFO_1, *PLOCALGROUP_MEMBERS_INFO_1, *LPLOCALGROUP_MEMBERS_INFO_1;

typedef struct _LOCALGROUP_MEMBERS_INFO_2 {
    PSID lgrmi2_sid;
    SID_NAME_USE lgrmi2_sidusage;
    LPWSTR lgrmi2_domainandname;
} LOCALGROUP_MEMBERS_INFO_2, *PLOCALGROUP_MEMBERS_INFO_2, *LPLOCALGROUP_MEMBERS_INFO_2;

typedef struct _LOCALGROUP_MEMBERS_INFO_3 {
    LPWSTR lgrmi3_domainandname;
} LOCALGROUP_MEMBERS_INFO_3, *PLOCALGROUP_MEMBERS_INFO_3, *LPLOCALGROUP_MEMBERS_INFO_3;

typedef struct _LOCALGROUP_USERS_INFO_0 {
    LPWSTR lgrui0_name;
} LOCALGROUP_USERS_INFO_0, *PLOCALGROUP_USERS_INFO_0, *LPLOCALGROUP_USERS_INFO_0;

#define USER_PRIV_GUEST   0
#define USER_PRIV_USER    1
#define USER_PRIV_ADMIN   2
#define USER_PRIV_MASK    3

#define LOCALGROUP_NAME_PARMNUM         1
#define LOCALGROUP_COMMENT_PARMNUM      2

NET_API_STATUS WINAPI NetGetDCName(LPCWSTR,LPCWSTR,LPBYTE*);
NET_API_STATUS WINAPI NetGroupEnum(LPCWSTR,DWORD,LPBYTE*,DWORD,LPDWORD,LPDWORD,LPDWORD);
NET_API_STATUS WINAPI NetLocalGroupAdd(LPCWSTR,DWORD,LPBYTE,LPDWORD);
NET_API_STATUS WINAPI NetLocalGroupAddMember(LPCWSTR,LPCWSTR,PSID);
NET_API_STATUS WINAPI NetLocalGroupAddMembers(LPCWSTR,LPCWSTR,DWORD,LPBYTE,DWORD);
NET_API_STATUS WINAPI NetLocalGroupDel(LPCWSTR,LPCWSTR);
NET_API_STATUS WINAPI NetLocalGroupDelMember(LPCWSTR,LPCWSTR,PSID);
NET_API_STATUS WINAPI NetLocalGroupDelMembers(LPCWSTR,LPCWSTR,DWORD,LPBYTE,DWORD);
NET_API_STATUS WINAPI NetLocalGroupEnum(LPCWSTR,DWORD,LPBYTE*,DWORD,LPDWORD,LPDWORD,PDWORD_PTR);
NET_API_STATUS WINAPI NetLocalGroupGetInfo(LPCWSTR,LPCWSTR,DWORD,LPBYTE*);
NET_API_STATUS WINAPI NetLocalGroupGetMembers(LPCWSTR,LPCWSTR,DWORD,LPBYTE*,DWORD,LPDWORD,LPDWORD,PDWORD_PTR);
NET_API_STATUS WINAPI NetLocalGroupSetInfo(LPCWSTR,LPCWSTR,DWORD,LPBYTE,LPDWORD);
NET_API_STATUS WINAPI NetLocalGroupSetMembers(LPCWSTR,LPCWSTR,DWORD,LPBYTE,DWORD);
NET_API_STATUS WINAPI NetQueryDisplayInformation(LPCWSTR,DWORD,DWORD,DWORD,DWORD,LPDWORD,PVOID*);
NET_API_STATUS WINAPI NetUserAdd(LPCWSTR,DWORD,LPBYTE,LPDWORD);
NET_API_STATUS WINAPI NetUserChangePassword(LPCWSTR,LPCWSTR,LPCWSTR,LPCWSTR);
NET_API_STATUS WINAPI NetUserDel(LPCWSTR,LPCWSTR);
NET_API_STATUS WINAPI NetUserEnum(LPCWSTR,DWORD,DWORD,LPBYTE*,DWORD,LPDWORD,LPDWORD,LPDWORD);
NET_API_STATUS WINAPI NetUserGetInfo(LPCWSTR,LPCWSTR,DWORD,LPBYTE*);
NET_API_STATUS WINAPI NetUserGetGroups(LPCWSTR,LPCWSTR,DWORD,LPBYTE*,DWORD,LPDWORD,LPDWORD);
NET_API_STATUS WINAPI NetUserGetLocalGroups(LPCWSTR,LPCWSTR,DWORD,DWORD,LPBYTE*,DWORD,LPDWORD,LPDWORD);
NET_API_STATUS WINAPI NetUserModalsGet(LPCWSTR,DWORD,LPBYTE*);

#ifdef __cplusplus
}
#endif

#endif
