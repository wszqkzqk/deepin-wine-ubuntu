/*
 * Copyright 2005 Hans Leidekker
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

#ifndef __WINE_WINLDAP_H
#define __WINE_WINLDAP_H

#include <windef.h>
#include <schnlsp.h>

#ifndef LDAPAPI
#define LDAPAPI __cdecl
#endif


typedef enum {
    LDAP_SUCCESS                    =   0x00,
    LDAP_OPERATIONS_ERROR           =   0x01,
    LDAP_PROTOCOL_ERROR             =   0x02,
    LDAP_TIMELIMIT_EXCEEDED         =   0x03,
    LDAP_SIZELIMIT_EXCEEDED         =   0x04,
    LDAP_COMPARE_FALSE              =   0x05,
    LDAP_COMPARE_TRUE               =   0x06,
    LDAP_AUTH_METHOD_NOT_SUPPORTED  =   0x07,
    LDAP_STRONG_AUTH_REQUIRED       =   0x08,
    LDAP_REFERRAL_V2                =   0x09,
    LDAP_PARTIAL_RESULTS            =   0x09,
    LDAP_REFERRAL                   =   0x0a,
    LDAP_ADMIN_LIMIT_EXCEEDED       =   0x0b,
    LDAP_UNAVAILABLE_CRIT_EXTENSION =   0x0c,
    LDAP_CONFIDENTIALITY_REQUIRED   =   0x0d,
    LDAP_SASL_BIND_IN_PROGRESS      =   0x0e,

    LDAP_NO_SUCH_ATTRIBUTE          =   0x10,
    LDAP_UNDEFINED_TYPE             =   0x11,
    LDAP_INAPPROPRIATE_MATCHING     =   0x12,
    LDAP_CONSTRAINT_VIOLATION       =   0x13,
    LDAP_ATTRIBUTE_OR_VALUE_EXISTS  =   0x14,
    LDAP_INVALID_SYNTAX             =   0x15,

    LDAP_NO_SUCH_OBJECT             =   0x20,
    LDAP_ALIAS_PROBLEM              =   0x21,
    LDAP_INVALID_DN_SYNTAX          =   0x22,
    LDAP_IS_LEAF                    =   0x23,
    LDAP_ALIAS_DEREF_PROBLEM        =   0x24,

    LDAP_INAPPROPRIATE_AUTH         =   0x30,
    LDAP_INVALID_CREDENTIALS        =   0x31,
    LDAP_INSUFFICIENT_RIGHTS        =   0x32,
    LDAP_BUSY                       =   0x33,
    LDAP_UNAVAILABLE                =   0x34,
    LDAP_UNWILLING_TO_PERFORM       =   0x35,
    LDAP_LOOP_DETECT                =   0x36,
    LDAP_SORT_CONTROL_MISSING       =   0x3C,
    LDAP_OFFSET_RANGE_ERROR         =   0x3D,

    LDAP_NAMING_VIOLATION           =   0x40,
    LDAP_OBJECT_CLASS_VIOLATION     =   0x41,
    LDAP_NOT_ALLOWED_ON_NONLEAF     =   0x42,
    LDAP_NOT_ALLOWED_ON_RDN         =   0x43,
    LDAP_ALREADY_EXISTS             =   0x44,
    LDAP_NO_OBJECT_CLASS_MODS       =   0x45,
    LDAP_RESULTS_TOO_LARGE          =   0x46,
    LDAP_AFFECTS_MULTIPLE_DSAS      =   0x47,

    LDAP_VIRTUAL_LIST_VIEW_ERROR    =   0x4c,

    LDAP_OTHER                      =   0x50,
    LDAP_SERVER_DOWN                =   0x51,
    LDAP_LOCAL_ERROR                =   0x52,
    LDAP_ENCODING_ERROR             =   0x53,
    LDAP_DECODING_ERROR             =   0x54,
    LDAP_TIMEOUT                    =   0x55,
    LDAP_AUTH_UNKNOWN               =   0x56,
    LDAP_FILTER_ERROR               =   0x57,
    LDAP_USER_CANCELLED             =   0x58,
    LDAP_PARAM_ERROR                =   0x59,
    LDAP_NO_MEMORY                  =   0x5a,
    LDAP_CONNECT_ERROR              =   0x5b,
    LDAP_NOT_SUPPORTED              =   0x5c,
    LDAP_CONTROL_NOT_FOUND          =   0x5d,
    LDAP_NO_RESULTS_RETURNED        =   0x5e,
    LDAP_MORE_RESULTS_TO_RETURN     =   0x5f,

    LDAP_CLIENT_LOOP                =   0x60,
    LDAP_REFERRAL_LIMIT_EXCEEDED    =   0x61
} LDAP_RETCODE;

#define LDAP_SCOPE_BASE         0x00
#define LDAP_SCOPE_ONELEVEL     0x01
#define LDAP_SCOPE_SUBTREE      0x02

typedef struct berelement
{
    PCHAR opaque;
} BerElement;

#define LDAP_OPT_API_INFO               0x00
#define LDAP_OPT_DESC                   0x01
#define LDAP_OPT_DEREF                  0x02
#define LDAP_OPT_SIZELIMIT              0x03
#define LDAP_OPT_TIMELIMIT              0x04
#define LDAP_OPT_THREAD_FN_PTRS         0x05
#define LDAP_OPT_REBIND_FN              0x06
#define LDAP_OPT_REBIND_ARG             0x07
#define LDAP_OPT_REFERRALS              0x08
#define LDAP_OPT_RESTART                0x09
#define LDAP_OPT_SSL                    0x0a
#define LDAP_OPT_IO_FN_PTRS             0x0b
#define LDAP_OPT_CACHE_FN_PTRS          0x0d
#define LDAP_OPT_CACHE_STRATEGY         0x0e
#define LDAP_OPT_CACHE_ENABLE           0x0f
#define LDAP_OPT_REFERRAL_HOP_LIMIT     0x10
#define LDAP_OPT_PROTOCOL_VERSION       0x11
#define LDAP_OPT_VERSION                0x11
#define LDAP_OPT_API_FEATURE_INFO       0x15
#define LDAP_OPT_HOST_NAME              0x30
#define LDAP_OPT_ERROR_NUMBER           0x31
#define LDAP_OPT_ERROR_STRING           0x32
#define LDAP_OPT_SERVER_ERROR           0x33
#define LDAP_OPT_SERVER_EXT_ERROR       0x34
#define LDAP_OPT_PING_KEEP_ALIVE        0x36
#define LDAP_OPT_PING_WAIT_TIME         0x37
#define LDAP_OPT_PING_LIMIT             0x38
#define LDAP_OPT_DNSDOMAIN_NAME         0x3b
#define LDAP_OPT_GETDSNAME_FLAGS        0x3d
#define LDAP_OPT_HOST_REACHABLE         0x3e
#define LDAP_OPT_PROMPT_CREDENTIALS     0x3f
#define LDAP_OPT_TCP_KEEPALIVE          0x40
#define LDAP_OPT_FAST_CONCURRENT_BIND   0x41
#define LDAP_OPT_SEND_TIMEOUT           0x42
#define LDAP_OPT_REFERRAL_CALLBACK      0x70
#define LDAP_OPT_CLIENT_CERTIFICATE     0x80
#define LDAP_OPT_SERVER_CERTIFICATE     0x81
#define LDAP_OPT_AUTO_RECONNECT         0x91
#define LDAP_OPT_SSPI_FLAGS             0x92
#define LDAP_OPT_SSL_INFO               0x93
#define LDAP_OPT_REF_DEREF_CONN_PER_MSG 0x94
#define LDAP_OPT_TLS                    LDAP_OPT_SSL
#define LDAP_OPT_TLS_INFO               LDAP_OPT_SSL_INFO
#define LDAP_OPT_SIGN                   0x95
#define LDAP_OPT_ENCRYPT                0x96
#define LDAP_OPT_SASL_METHOD            0x97
#define LDAP_OPT_AREC_EXCLUSIVE         0x98
#define LDAP_OPT_SECURITY_CONTEXT       0x99
#define LDAP_OPT_ROOTDSE_CACHE          0x9a

#define LDAP_OPT_ON                     ((void *)1)
#define LDAP_OPT_OFF                    ((void *)0)

#define LDAP_VERSION1   1
#define LDAP_VERSION2   2
#define LDAP_VERSION3   3
#define LDAP_VERSION    LDAP_VERSION2

#define LDAP_MSG_ONE        0
#define LDAP_MSG_ALL        1
#define LDAP_MSG_RECEIVED   2

#define LDAP_RES_BIND           0x61
#define LDAP_RES_SEARCH_ENTRY   0x64
#define LDAP_RES_SEARCH_RESULT  0x65
#define LDAP_RES_MODIFY         0x67
#define LDAP_RES_ADD            0x69
#define LDAP_RES_DELETE         0x6b
#define LDAP_RES_MODRDN         0x6d
#define LDAP_RES_COMPARE        0x6f
#define LDAP_RES_SESSION        0x72
#define LDAP_RES_REFERRAL       0x73
#define LDAP_RES_EXTENDED       0x78
#define LDAP_RES_ANY            (-1)

typedef struct ldap
{
    struct
    {
        UINT_PTR sb_sd;
        UCHAR Reserved1[41];
        ULONG_PTR sb_naddr;
        UCHAR Reserved2[24];
    } ld_sb;

    PCHAR ld_host;
    ULONG ld_version;
    UCHAR ld_lberoptions;
    ULONG ld_deref;
    ULONG ld_timelimit;
    ULONG ld_sizelimit;
    ULONG ld_errno;
    PCHAR ld_matched;
    PCHAR ld_error;
    ULONG ld_msgid;
    UCHAR Reserved3[25];
    ULONG ld_cldaptries;
    ULONG ld_cldaptimeout;
    ULONG ld_refhoplimit;
    ULONG ld_options;
} LDAP, *PLDAP;

#define LDAP_MOD_ADD        0x00
#define LDAP_MOD_DELETE     0x01
#define LDAP_MOD_REPLACE    0x02
#define LDAP_MOD_BVALUES    0x80

typedef struct ldapmodA {
    ULONG mod_op;
    PCHAR mod_type;
    union {
        PCHAR *modv_strvals;
        struct berval **modv_bvals;
    } mod_vals;
} LDAPModA, *PLDAPModA;

typedef struct ldapmodW {
    ULONG mod_op;
    PWCHAR mod_type;
    union {
        PWCHAR *modv_strvals;
        struct berval **modv_bvals;
    } mod_vals;
} LDAPModW, *PLDAPModW;

DECL_WINELIB_TYPE_AW(LDAPMod)
DECL_WINELIB_TYPE_AW(PLDAPMod)

typedef struct l_timeval
{
    LONG tv_sec;
    LONG tv_usec;
} LDAP_TIMEVAL, *PLDAP_TIMEVAL;

typedef struct ldapmsg
{
    ULONG lm_msgid;
    ULONG lm_msgtype;

    PVOID lm_ber;

    struct ldapmsg *lm_chain;
    struct ldapmsg *lm_next;
    ULONG lm_time;

    PLDAP Connection;
    PVOID Request;
    ULONG lm_returncode;
    USHORT lm_referral;
    BOOLEAN lm_chased;
    BOOLEAN lm_eom;
    BOOLEAN ConnectionReferenced;
} LDAPMessage, *PLDAPMessage;

#define LAPI_MAJOR_VER1     1
#define LAPI_MINOR_VER1     1

typedef struct ldap_version_info
{
    ULONG lv_size;
    ULONG lv_major;
    ULONG lv_minor;
} LDAP_VERSION_INFO, *PLDAP_VERSION_INFO;

typedef struct berval
{
    ULONG bv_len;
    PCHAR bv_val;
} LDAP_BERVAL, *PLDAP_BERVAL, BERVAL, *PBERVAL, BerValue;

typedef struct ldapcontrolA
{
    PCHAR ldctl_oid;
    struct berval ldctl_value;
    BOOLEAN ldctl_iscritical;
} LDAPControlA, *PLDAPControlA;

typedef struct ldapcontrolW
{
    PWCHAR ldctl_oid;
    struct berval ldctl_value;
    BOOLEAN ldctl_iscritical;
} LDAPControlW, *PLDAPControlW;

DECL_WINELIB_TYPE_AW(LDAPControl)
DECL_WINELIB_TYPE_AW(PLDAPControl)

typedef struct ldapvlvinfo
{
    int ldvlv_version;
    ULONG ldvlv_before_count;
    ULONG ldvlv_after_count;
    ULONG ldvlv_offset;
    ULONG ldvlv_count;
    PBERVAL ldvlv_attrvalue;
    PBERVAL ldvlv_context;
    VOID *ldvlv_extradata;
} LDAPVLVInfo, *PLDAPVLVInfo;

typedef struct ldapsearch LDAPSearch, *PLDAPSearch;

typedef struct ldapsortkeyA
{
    PCHAR sk_attrtype;
    PCHAR sk_matchruleoid;
    BOOLEAN sk_reverseorder;
} LDAPSortKeyA, *PLDAPSortKeyA;

typedef struct ldapsortkeyW
{
    PWCHAR sk_attrtype;
    PWCHAR sk_matchruleoid;
    BOOLEAN sk_reverseorder;
} LDAPSortKeyW, *PLDAPSortKeyW;

DECL_WINELIB_TYPE_AW(LDAPSortKey)
DECL_WINELIB_TYPE_AW(PLDAPSortKey)

#define LDAP_API_INFO_VERSION     1

typedef struct ldapapiinfoA
{
    int ldapai_info_version;
    int ldapai_api_version;
    int ldapai_protocol_version;
    char **ldapai_extensions;
    char *ldapai_vendor_name;
    int ldapai_vendor_version;
} LDAPAPIInfoA;

typedef struct ldapapiinfoW
{
    int ldapai_info_version;
    int ldapai_api_version;
    int ldapai_protocol_version;
    PWCHAR *ldapai_extensions;
    PWCHAR ldapai_vendor_name;
    int ldapai_vendor_version;
} LDAPAPIInfoW;

DECL_WINELIB_TYPE_AW(LDAPAPIInfo)

#define LDAP_FEATURE_INFO_VERSION    1

typedef struct ldap_apifeature_infoA
{
    int ldapaif_info_version;
    char *ldapaif_name;
    int ldapaif_version;
} LDAPAPIFeatureInfoA;

typedef struct ldap_apifeature_infoW
{
    int ldapaif_info_version;
    PWCHAR ldapaif_name;
    int ldapaif_version;
} LDAPAPIFeatureInfoW;

DECL_WINELIB_TYPE_AW(LDAPAPIFeatureInfo)


#ifdef __cplusplus
extern "C" {
#endif

LDAP * CDECL cldap_openA(PCHAR,ULONG);
LDAP * CDECL cldap_openW(PWCHAR,ULONG);
#define    cldap_open WINELIB_NAME_AW(cldap_open)
ULONG CDECL ldap_abandon(LDAP*,ULONG);
ULONG CDECL ldap_addA(LDAP*,PCHAR,LDAPModA*[]);
ULONG CDECL ldap_addW(LDAP*,PWCHAR,LDAPModW*[]);
#define    ldap_add WINELIB_NAME_AW(ldap_add)
ULONG CDECL ldap_add_extA(LDAP*,PCHAR,LDAPModA*[],PLDAPControlA*,PLDAPControlA*,ULONG*);
ULONG CDECL ldap_add_extW(LDAP*,PWCHAR,LDAPModW*[],PLDAPControlW*,PLDAPControlW*,ULONG*);
#define    ldap_add_ext WINELIB_NAME_AW(ldap_add_ext)
ULONG CDECL ldap_add_ext_sA(LDAP*,PCHAR,LDAPModA*[],PLDAPControlA*,PLDAPControlA*);
ULONG CDECL ldap_add_ext_sW(LDAP*,PWCHAR,LDAPModW*[],PLDAPControlW*,PLDAPControlW*);
#define    ldap_add_ext_s WINELIB_NAME_AW(ldap_add_ext_s)
ULONG CDECL ldap_add_sA(LDAP*,PCHAR,LDAPModA*[]);
ULONG CDECL ldap_add_sW(LDAP*,PWCHAR,LDAPModW*[]);
#define    ldap_add_s WINELIB_NAME_AW(ldap_add_s)
ULONG CDECL ldap_bindA(LDAP*,PCHAR,PCHAR,ULONG);
ULONG CDECL ldap_bindW(LDAP*,PWCHAR,PWCHAR,ULONG);
#define    ldap_bind WINELIB_NAME_AW(ldap_bind)
ULONG CDECL ldap_bind_sA(LDAP*,PCHAR,PCHAR,ULONG);
ULONG CDECL ldap_bind_sW(LDAP*,PWCHAR,PWCHAR,ULONG);
#define    ldap_bind_s WINELIB_NAME_AW(ldap_bind_s)
ULONG CDECL ldap_check_filterA(LDAP*,PCHAR);
ULONG CDECL ldap_check_filterW(LDAP*,PWCHAR);
#define    ldap_check_filter WINELIB_NAME_AW(ldap_check_filter)
ULONG CDECL ldap_cleanup(HANDLE);
ULONG CDECL ldap_close_extended_op(LDAP*,ULONG);
LDAP* CDECL ldap_conn_from_msg(LDAP*,LDAPMessage*);
ULONG CDECL ldap_compareA(LDAP*,PCHAR,PCHAR,PCHAR);
ULONG CDECL ldap_compareW(LDAP*,PWCHAR,PWCHAR,PWCHAR);
#define    ldap_compare WINELIB_NAME_AW(ldap_compare)
ULONG CDECL ldap_compare_extA(LDAP*,PCHAR,PCHAR,PCHAR,struct berval*,PLDAPControlA*,PLDAPControlA*,ULONG*);
ULONG CDECL ldap_compare_extW(LDAP*,PWCHAR,PWCHAR,PWCHAR,struct berval*,PLDAPControlW*,PLDAPControlW*,ULONG*);
#define    ldap_compare_ext WINELIB_NAME_AW(ldap_compare_ext)
ULONG CDECL ldap_compare_ext_sA(LDAP*,PCHAR,PCHAR,PCHAR,struct berval*,PLDAPControlA*,PLDAPControlA*);
ULONG CDECL ldap_compare_ext_sW(LDAP*,PWCHAR,PWCHAR,PWCHAR,struct berval*,PLDAPControlW*,PLDAPControlW*);
#define    ldap_compare_ext_s WINELIB_NAME_AW(ldap_compare_ext_s)
ULONG CDECL ldap_compare_sA(LDAP*,PCHAR,PCHAR,PCHAR);
ULONG CDECL ldap_compare_sW(LDAP*,PWCHAR,PWCHAR,PWCHAR);
#define    ldap_compare_s WINELIB_NAME_AW(ldap_compare_s)
ULONG CDECL ldap_connect(LDAP*,struct l_timeval*);
ULONG CDECL ldap_control_freeA(LDAPControlA*);
ULONG CDECL ldap_control_freeW(LDAPControlW*);
#define    ldap_control_free WINELIB_NAME_AW(ldap_control_free)
ULONG CDECL ldap_controls_freeA(LDAPControlA**);
ULONG CDECL ldap_controls_freeW(LDAPControlW**);
#define    ldap_controls_free WINELIB_NAME_AW(ldap_controls_free)
ULONG CDECL ldap_count_entries(LDAP*,LDAPMessage*);
ULONG CDECL ldap_count_references(LDAP*,LDAPMessage*);
ULONG CDECL ldap_count_values_len(struct berval**);
ULONG CDECL ldap_count_valuesA(PCHAR*);
ULONG CDECL ldap_count_valuesW(PWCHAR*);
#define    ldap_count_values WINELIB_NAME_AW(ldap_count_values)
ULONG CDECL ldap_create_page_controlA(PLDAP,ULONG,struct berval*,UCHAR,PLDAPControlA*);
ULONG CDECL ldap_create_page_controlW(PLDAP,ULONG,struct berval*,UCHAR,PLDAPControlW*);
#define    ldap_create_page_control WINELIB_NAME_AW(ldap_create_page_control)
ULONG CDECL ldap_create_sort_controlA(PLDAP,PLDAPSortKeyA*,UCHAR,PLDAPControlA*);
ULONG CDECL ldap_create_sort_controlW(PLDAP,PLDAPSortKeyW*,UCHAR,PLDAPControlW*);
#define    ldap_create_sort_control WINELIB_NAME_AW(ldap_create_sort_control)
INT CDECL  ldap_create_vlv_controlA(PLDAP,PLDAPVLVInfo,UCHAR,PLDAPControlA*);
INT CDECL  ldap_create_vlv_controlW(PLDAP,PLDAPVLVInfo,UCHAR,PLDAPControlW*);
#define    ldap_create_vlv_control WINELIB_NAME_AW(ldap_create_vlv_control)
ULONG CDECL ldap_deleteA(LDAP*,PCHAR);
ULONG CDECL ldap_deleteW(LDAP*,PWCHAR);
#define    ldap_delete WINELIB_NAME_AW(ldap_delete)
ULONG CDECL ldap_delete_extA(LDAP*,PCHAR,PLDAPControlA*,PLDAPControlA*,ULONG*);
ULONG CDECL ldap_delete_extW(LDAP*,PWCHAR,PLDAPControlW*,PLDAPControlW*,ULONG*);
#define    ldap_delete_ext WINELIB_NAME_AW(ldap_delete_ext)
ULONG CDECL ldap_delete_ext_sA(LDAP*,PCHAR,PLDAPControlA*,PLDAPControlA*);
ULONG CDECL ldap_delete_ext_sW(LDAP*,PWCHAR,PLDAPControlW*,PLDAPControlW*);
#define    ldap_delete_ext_s WINELIB_NAME_AW(ldap_delete_ext_s)
ULONG CDECL ldap_delete_sA(LDAP*,PCHAR);
ULONG CDECL ldap_delete_sW(LDAP*,PWCHAR);
#define    ldap_delete_s WINELIB_NAME_AW(ldap_delete_s)
PCHAR CDECL ldap_dn2ufnA(PCHAR);
PWCHAR CDECL ldap_dn2ufnW(PWCHAR);
#define    ldap_dn2ufn WINELIB_NAME_AW(ldap_dn2ufn)
ULONG CDECL ldap_encode_sort_controlA(PLDAP,PLDAPSortKeyA*,PLDAPControlA,BOOLEAN);
ULONG CDECL ldap_encode_sort_controlW(PLDAP,PLDAPSortKeyW*,PLDAPControlW,BOOLEAN);
#define    ldap_encode_sort_control WINELIB_NAME_AW(ldap_encode_sort_control)
PCHAR CDECL ldap_err2stringA(ULONG);
PWCHAR CDECL ldap_err2stringW(ULONG);
#define    ldap_err2string WINELIB_NAME_AW(ldap_err2string)
ULONG CDECL ldap_escape_filter_elementA(PCHAR,ULONG,PCHAR,ULONG);
ULONG CDECL ldap_escape_filter_elementW(PCHAR,ULONG,PWCHAR,ULONG);
#define    ldap_escape_filter_element WINELIB_NAME_AW(ldap_escape_filter_element)
PCHAR* CDECL ldap_explode_dnA(PCHAR,ULONG);
PWCHAR* CDECL ldap_explode_dnW(PWCHAR,ULONG);
#define    ldap_explode_dn WINELIB_NAME_AW(ldap_explode_dn)
ULONG CDECL ldap_extended_operationA(LDAP*,PCHAR,struct berval*,PLDAPControlA*,PLDAPControlA*,ULONG*);
ULONG CDECL ldap_extended_operationW(LDAP*,PWCHAR,struct berval*,PLDAPControlW*,PLDAPControlW*,ULONG*);
#define    ldap_extended_operation WINELIB_NAME_AW(ldap_extended_operation)
ULONG CDECL ldap_extended_operation_sA(LDAP*,PCHAR,struct berval*,PLDAPControlA*,PLDAPControlA*,PCHAR*,struct berval**);
ULONG CDECL ldap_extended_operation_sW(LDAP*,PWCHAR,struct berval*,PLDAPControlW*,PLDAPControlW*,PWCHAR*,struct berval**);
#define    ldap_extended_operation_s WINELIB_NAME_AW(ldap_extended_operation_s)
PCHAR CDECL ldap_first_attributeA(LDAP*,LDAPMessage*,BerElement**);
PWCHAR CDECL ldap_first_attributeW(LDAP*,LDAPMessage*,BerElement**);
#define    ldap_first_attribute WINELIB_NAME_AW(ldap_first_attribute)
LDAPMessage* CDECL ldap_first_entry(LDAP*,LDAPMessage*);
LDAPMessage* CDECL ldap_first_reference(LDAP*,LDAPMessage*);
ULONG CDECL ldap_free_controlsA(LDAPControlA**);
ULONG CDECL ldap_free_controlsW(LDAPControlW**);
#define    ldap_free_controls WINELIB_NAME_AW(ldap_free_controls)
PCHAR CDECL ldap_get_dnA(LDAP*,LDAPMessage*);
PWCHAR CDECL ldap_get_dnW(LDAP*,LDAPMessage*);
#define    ldap_get_dn WINELIB_NAME_AW(ldap_get_dn)
ULONG CDECL ldap_get_next_page(PLDAP,PLDAPSearch,ULONG,ULONG*);
ULONG CDECL ldap_get_next_page_s(PLDAP,PLDAPSearch,struct l_timeval*,ULONG,ULONG*,LDAPMessage**);
ULONG CDECL ldap_get_optionA(LDAP*,int,void*);
ULONG CDECL ldap_get_optionW(LDAP*,int,void*);
#define    ldap_get_option WINELIB_NAME_AW(ldap_get_option)
ULONG CDECL ldap_get_paged_count(LDAP*,PLDAPSearch,ULONG*,LDAPMessage*);
PCHAR* CDECL ldap_get_valuesA(LDAP*,LDAPMessage*,PCHAR);
PWCHAR* CDECL ldap_get_valuesW(LDAP*,LDAPMessage*,PWCHAR);
#define    ldap_get_values WINELIB_NAME_AW(ldap_get_values)
struct berval ** CDECL ldap_get_values_lenA(LDAP*,LDAPMessage*,PCHAR);
struct berval ** CDECL ldap_get_values_lenW(LDAP*,LDAPMessage*,PWCHAR);
#define    ldap_get_values_len WINELIB_NAME_AW(ldap_get_values_len)
LDAP* CDECL ldap_initA(const PCHAR,ULONG);
LDAP* CDECL ldap_initW(const PWCHAR,ULONG);
#define    ldap_init WINELIB_NAME_AW(ldap_init)
VOID CDECL ldap_memfreeA(PCHAR);
VOID CDECL ldap_memfreeW(PWCHAR);
#define    ldap_memfree WINELIB_NAME_AW(ldap_memfree)
ULONG CDECL ldap_modifyA(LDAP*,PCHAR,LDAPModA*[]);
ULONG CDECL ldap_modifyW(LDAP*,PWCHAR,LDAPModW*[]);
#define    ldap_modify WINELIB_NAME_AW(ldap_modify)
ULONG CDECL ldap_modify_extA(LDAP*,PCHAR,LDAPModA*[],PLDAPControlA*,PLDAPControlA*,ULONG*);
ULONG CDECL ldap_modify_extW(LDAP*,PWCHAR,LDAPModW*[],PLDAPControlW*,PLDAPControlW*,ULONG*);
#define    ldap_modify_ext WINELIB_NAME_AW(ldap_modify_ext)
ULONG CDECL ldap_modify_ext_sA(LDAP*,PCHAR,LDAPModA*[],PLDAPControlA*,PLDAPControlA*);
ULONG CDECL ldap_modify_ext_sW(LDAP*,PWCHAR,LDAPModW*[],PLDAPControlW*,PLDAPControlW*);
#define    ldap_modify_ext_s WINELIB_NAME_AW(ldap_modify_ext_s)
ULONG CDECL ldap_modify_sA(LDAP*,PCHAR,LDAPModA*[]);
ULONG CDECL ldap_modify_sW(LDAP*,PWCHAR,LDAPModW*[]);
#define    ldap_modify_s WINELIB_NAME_AW(ldap_modify_s)
ULONG CDECL ldap_modrdnA(LDAP*,PCHAR,PCHAR);
ULONG CDECL ldap_modrdnW(LDAP*,PWCHAR,PWCHAR);
#define    ldap_modrdn WINELIB_NAME_AW(ldap_modrdn)
ULONG CDECL ldap_modrdn2A(LDAP*,PCHAR,PCHAR,INT);
ULONG CDECL ldap_modrdn2W(LDAP*,PWCHAR,PWCHAR,INT);
#define    ldap_modrdn2 WINELIB_NAME_AW(ldap_modrdn2)
ULONG CDECL ldap_modrdn2_sA(LDAP*,PCHAR,PCHAR,INT);
ULONG CDECL ldap_modrdn2_sW(LDAP*,PWCHAR,PWCHAR,INT);
#define    ldap_modrdn2_s WINELIB_NAME_AW(ldap_modrdn2_s)
ULONG CDECL ldap_modrdn_sA(LDAP*,PCHAR,PCHAR);
ULONG CDECL ldap_modrdn_sW(LDAP*,PWCHAR,PWCHAR);
#define    ldap_modrdn_s WINELIB_NAME_AW(ldap_modrdn_s)
ULONG CDECL ldap_msgfree(LDAPMessage*);
PCHAR CDECL ldap_next_attributeA(LDAP*,LDAPMessage*,BerElement*);
PWCHAR CDECL ldap_next_attributeW(LDAP*,LDAPMessage*,BerElement*);
#define    ldap_next_attribute WINELIB_NAME_AW(ldap_next_attribute)
LDAPMessage * CDECL ldap_next_entry(LDAP*,LDAPMessage*);
LDAP * CDECL ldap_openA(PCHAR,ULONG);
LDAP * CDECL ldap_openW(PWCHAR,ULONG);
#define    ldap_open WINELIB_NAME_AW(ldap_open)
ULONG CDECL ldap_parse_extended_resultA(LDAP*,LDAPMessage*,PCHAR*,struct berval**,BOOLEAN);
ULONG CDECL ldap_parse_extended_resultW(LDAP*,LDAPMessage*,PWCHAR*,struct berval**,BOOLEAN);
#define    ldap_parse_extended_result WINELIB_NAME_AW(ldap_parse_extended_result)
ULONG CDECL ldap_parse_page_controlA(LDAP*,PLDAPControlA*,ULONG*,struct berval**);
ULONG CDECL ldap_parse_page_controlW(LDAP*,PLDAPControlW*,ULONG*,struct berval**);
#define    ldap_parse_page_control WINELIB_NAME_AW(ldap_parse_page_control)
ULONG CDECL ldap_parse_referenceA(LDAP*,LDAPMessage*,PCHAR**);
ULONG CDECL ldap_parse_referenceW(LDAP*,LDAPMessage*,PWCHAR**);
#define    ldap_parse_reference WINELIB_NAME_AW(ldap_parse_reference)
ULONG CDECL ldap_result2error(LDAP*,LDAPMessage*,ULONG);
ULONG CDECL ldap_parse_resultA(LDAP*,LDAPMessage*,ULONG*,PCHAR*,PCHAR*,PCHAR**,PLDAPControlA**,BOOLEAN);
ULONG CDECL ldap_parse_resultW(LDAP*,LDAPMessage*,ULONG*,PWCHAR*,PWCHAR*,PWCHAR**,PLDAPControlW**,BOOLEAN);
#define    ldap_parse_result WINELIB_NAME_AW(ldap_parse_result)
ULONG CDECL ldap_parse_sort_controlA(LDAP*,PLDAPControlA*,ULONG*,PCHAR*);
ULONG CDECL ldap_parse_sort_controlW(LDAP*,PLDAPControlW*,ULONG*,PWCHAR*);
#define    ldap_parse_sort_control WINELIB_NAME_AW(ldap_parse_sort_control)
INT CDECL ldap_parse_vlv_controlA(PLDAP,PLDAPControlA*,PULONG,PULONG,PBERVAL*,PINT);
INT CDECL ldap_parse_vlv_controlW(PLDAP,PLDAPControlW*,PULONG,PULONG,PBERVAL*,PINT);
#define    ldap_parse_vlv_control WINELIB_NAME_AW(ldap_parse_vlv_control)
void CDECL ldap_perror(LDAP*,const PCHAR);
ULONG CDECL ldap_rename_extA(LDAP*,PCHAR,PCHAR,PCHAR,INT,PLDAPControlA*,PLDAPControlA*,ULONG*);
ULONG CDECL ldap_rename_extW(LDAP*,PWCHAR,PWCHAR,PWCHAR,INT,PLDAPControlW*,PLDAPControlW*,ULONG*);
#define    ldap_rename_ext WINELIB_NAME_AW(ldap_rename_ext)
ULONG CDECL ldap_rename_ext_sA(LDAP*,PCHAR,PCHAR,PCHAR,INT,PLDAPControlA*,PLDAPControlA*);
ULONG CDECL ldap_rename_ext_sW(LDAP*,PWCHAR,PWCHAR,PWCHAR,INT,PLDAPControlW*,PLDAPControlW*);
#define    ldap_rename_ext_s WINELIB_NAME_AW(ldap_rename_ext_s)
ULONG CDECL ldap_result(LDAP*,ULONG,ULONG,struct l_timeval*,LDAPMessage**);
ULONG CDECL ldap_result2error(LDAP*,LDAPMessage*,ULONG);
ULONG CDECL ldap_sasl_bindA(LDAP*,const PCHAR,const PCHAR,const BERVAL*,PLDAPControlA*,PLDAPControlA*,int*);
ULONG CDECL ldap_sasl_bindW(LDAP*,const PWCHAR,const PWCHAR,const BERVAL*,PLDAPControlW*,PLDAPControlW*,int*);
#define    ldap_sasl_bind WINELIB_NAME_AW(ldap_sasl_bind)
ULONG CDECL ldap_sasl_bind_sA(LDAP*,const PCHAR,const PCHAR,const BERVAL*,PLDAPControlA*,PLDAPControlA*,PBERVAL*);
ULONG CDECL ldap_sasl_bind_sW(LDAP*,const PWCHAR,const PWCHAR,const BERVAL*,PLDAPControlW*,PLDAPControlW*,PBERVAL*);
#define    ldap_sasl_bind_s WINELIB_NAME_AW(ldap_sasl_bind_s)
ULONG CDECL ldap_simple_bindA(LDAP*,PCHAR,PCHAR);
ULONG CDECL ldap_simple_bindW(LDAP*,PWCHAR,PWCHAR);
#define    ldap_simple_bind WINELIB_NAME_AW(ldap_simple_bind)
ULONG CDECL ldap_simple_bind_sA(LDAP*,PCHAR,PCHAR);
ULONG CDECL ldap_simple_bind_sW(LDAP*,PWCHAR,PWCHAR);
#define    ldap_simple_bind_s WINELIB_NAME_AW(ldap_simple_bind_s)
ULONG CDECL ldap_search_abandon_page(PLDAP,PLDAPSearch);
ULONG CDECL ldap_searchA(LDAP*,PCHAR,ULONG,PCHAR,PCHAR[],ULONG);
ULONG CDECL ldap_searchW(LDAP*,PWCHAR,ULONG,PWCHAR,PCHAR[],ULONG);
#define    ldap_search WINELIB_NAME_AW(ldap_search)
ULONG CDECL ldap_search_extA(LDAP*,PCHAR,ULONG,PCHAR,PCHAR[],ULONG,PLDAPControlA*,
    PLDAPControlA*,ULONG,ULONG,ULONG*);
ULONG CDECL ldap_search_extW(LDAP*,PWCHAR,ULONG,PWCHAR,PWCHAR[],ULONG,PLDAPControlW*,
    PLDAPControlW*,ULONG,ULONG,ULONG*);
#define    ldap_search_ext WINELIB_NAME_AW(ldap_search_ext)
ULONG CDECL ldap_search_ext_sA(LDAP*,PCHAR,ULONG,PCHAR,PCHAR[],ULONG,PLDAPControlA*,
    PLDAPControlA*,struct l_timeval*,ULONG,LDAPMessage**);
ULONG CDECL ldap_search_ext_sW(LDAP*,PWCHAR,ULONG,PWCHAR,PWCHAR[],ULONG,PLDAPControlW*,
    PLDAPControlW*,struct l_timeval*,ULONG,LDAPMessage**);
#define    ldap_search_ext_s WINELIB_NAME_AW(ldap_search_ext_s)
PLDAPSearch CDECL ldap_search_init_pageA(PLDAP,PCHAR,ULONG,PCHAR,PCHAR[],ULONG,PLDAPControlA*,
    PLDAPControlA*,ULONG,ULONG,PLDAPSortKeyA*);
PLDAPSearch CDECL ldap_search_init_pageW(PLDAP,PWCHAR,ULONG,PWCHAR,PWCHAR[],ULONG,PLDAPControlW*,
    PLDAPControlW*,ULONG,ULONG, PLDAPSortKeyW*);
#define    ldap_search_init_page WINELIB_NAME_AW(ldap_search_init_page)
ULONG CDECL ldap_search_sA(LDAP*,PCHAR,ULONG,PCHAR,PCHAR[],ULONG,LDAPMessage**);
ULONG CDECL ldap_search_sW(LDAP*,PWCHAR,ULONG,PWCHAR,PWCHAR[],ULONG,LDAPMessage**);
#define    ldap_search_s WINELIB_NAME_AW(ldap_search_s)
ULONG CDECL ldap_search_stA(LDAP*,const PCHAR,ULONG,const PCHAR,PCHAR[],ULONG,
    struct l_timeval*,LDAPMessage**);
ULONG CDECL ldap_search_stW(LDAP*,const PWCHAR,ULONG,const PWCHAR,PWCHAR[],ULONG,
    struct l_timeval*,LDAPMessage**);
#define    ldap_search_st WINELIB_NAME_AW(ldap_search_st)
ULONG CDECL ldap_set_optionA(LDAP*,int,void*);
ULONG CDECL ldap_set_optionW(LDAP*,int,void*);
#define    ldap_set_option WINELIB_NAME_AW(ldap_set_option)
LDAP * CDECL ldap_sslinitA(PCHAR,ULONG,int);
LDAP * CDECL ldap_sslinitW(PWCHAR,ULONG,int);
#define    ldap_sslinit WINELIB_NAME_AW(ldap_sslinit)
ULONG CDECL ldap_start_tls_sA(LDAP*,PULONG,LDAPMessage**,PLDAPControlA*,PLDAPControlA*);
ULONG CDECL ldap_start_tls_sW(LDAP*,PULONG,LDAPMessage**,PLDAPControlW*,PLDAPControlW*);
#define    ldap_start_tls_s WINELIB_NAME_AW(ldap_start_tls_s)
ULONG CDECL ldap_startup(PLDAP_VERSION_INFO,HANDLE*);
BOOLEAN CDECL ldap_stop_tls_s(LDAP*);
ULONG CDECL ldap_ufn2dnA(PCHAR,PCHAR*);
ULONG CDECL ldap_ufn2dnW(PWCHAR,PWCHAR*);
#define    ldap_ufn2dn WINELIB_NAME_AW(ldap_ufn2dn)
ULONG CDECL ldap_unbind(LDAP*);
ULONG CDECL ldap_unbind_s(LDAP*);
ULONG CDECL ldap_value_freeA(PCHAR*);
ULONG CDECL ldap_value_freeW(PWCHAR*);
#define    ldap_value_free WINELIB_NAME_AW(ldap_value_free)
ULONG CDECL ldap_value_free_len(struct berval**);

BerElement* CDECL ber_alloc_t(INT);
BERVAL* CDECL ber_bvdup(BERVAL*);
void CDECL ber_bvecfree(PBERVAL*);
void CDECL ber_bvfree(BERVAL*);
ULONG CDECL ber_first_element(BerElement*,ULONG*,CHAR**);
INT CDECL ber_flatten(BerElement*,PBERVAL*);
void CDECL ber_free(BerElement*,INT);
BerElement* CDECL ber_init(BERVAL*);
ULONG CDECL ber_next_element(BerElement*,ULONG*,CHAR*);
ULONG CDECL ber_peek_tag(BerElement*,ULONG*);
INT CDECL ber_printf(BerElement*,PCHAR,...);
ULONG CDECL ber_skip_tag(BerElement*,ULONG*);
INT CDECL ber_scanf(BerElement*,PCHAR,...);

ULONG CDECL LdapGetLastError(void);
ULONG CDECL LdapMapErrorToWin32(ULONG);
int CDECL LdapUnicodeToUTF8(LPCWSTR,int,LPSTR,int);
int CDECL LdapUTF8ToUnicode(LPCSTR,int,LPWSTR,int);

#ifdef __cplusplus
}
#endif

#endif  /* __WINE_WINLDAP_H */
