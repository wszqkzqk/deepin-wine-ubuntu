/*
 * Copyright (C) 2003 Ulrich Czekalla for CodeWeavers
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
#ifndef __SDDL_H__
#define __SDDL_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Versioning */
#define SDDL_REVISION_1 1
#define SDDL_REVISION   SDDL_REVISION_1

#ifndef WINE_NO_UNICODE_MACROS
/* Component tags */
#ifndef UNICODE
# define SDDL_OWNER "O"
# define SDDL_GROUP "G"
# define SDDL_DACL  "D"
# define SDDL_SACL  "S"
#else
# if defined(__GNUC__)
#  define SDDL_OWNER (const WCHAR[]){ 'O',0 }
#  define SDDL_GROUP (const WCHAR[]){ 'G',0 }
#  define SDDL_DACL  (const WCHAR[]){ 'D',0 }
#  define SDDL_SACL  (const WCHAR[]){ 'S',0 }
# elif defined(_MSC_VER)
#  define SDDL_OWNER L"O"
#  define SDDL_GROUP L"G"
#  define SDDL_DACL  L"D"
#  define SDDL_SACL  L"S"
# else
   static const WCHAR SDDL_OWNER[] = { 'O',0 };
   static const WCHAR SDDL_GROUP[] = { 'G',0 };
   static const WCHAR SDDL_DACL[]  = { 'D',0 };
   static const WCHAR SDDL_SACL[]  = { 'S',0 };
# endif
#endif /* UNICODE */

/* Separators as characters */
/* SDDL_SEPERATORC is not a typo, as per Microsoft's headers */
#ifndef UNICODE
# define SDDL_SEPERATORC   ';'
# define SDDL_DELIMINATORC ':'
# define SDDL_ACE_BEGINC   '('
# define SDDL_ACE_ENDC     ')'
#else
# define SDDL_SEPERATORC   ((WCHAR)';')
# define SDDL_DELIMINATORC ((WCHAR)':')
# define SDDL_ACE_BEGINC   ((WCHAR)'(')
# define SDDL_ACE_ENDC     ((WCHAR)')')
#endif /* UNICODE */

/* Separators as strings */
/* SDDL_SEPERATOR is not a typo, as per Microsoft's headers */
#ifndef UNICODE
# define SDDL_SEPERATOR   ";"
# define SDDL_DELIMINATOR ":"
# define SDDL_ACE_BEGIN   "("
# define SDDL_ACE_END     ")"
#else
# if defined(__GNUC__)
#  define SDDL_SEPERATOR   (const WCHAR[]){ ';',0 }
#  define SDDL_DELIMINATOR (const WCHAR[]){ ':',0 }
#  define SDDL_ACE_BEGIN   (const WCHAR[]){ '(',0 }
#  define SDDL_ACE_END     (const WCHAR[]){ ')',0 }
# elif defined(_MSC_VER)
#  define SDDL_SEPERATOR   L";"
#  define SDDL_DELIMINATOR L":"
#  define SDDL_ACE_BEGIN   L"("
#  define SDDL_ACE_END     L")"
# else
   static const WCHAR SDDL_SEPERATOR[]   = { ';',0 };
   static const WCHAR SDDL_DELIMINATOR[] = { ':',0 };
   static const WCHAR SDDL_ACE_BEGIN[]   = { '(',0 };
   static const WCHAR SDDL_ACE_END[]     = { ')',0 };
# endif
#endif /* UNICODE */
#endif /* WINE_NO_UNICODE_MACROS */

BOOL WINAPI ConvertSidToStringSidA( PSID, LPSTR* );
BOOL WINAPI ConvertSidToStringSidW( PSID, LPWSTR* );
#define ConvertSidToStringSid WINELIB_NAME_AW(ConvertSidToStringSid)

BOOL WINAPI ConvertStringSidToSidA( LPCSTR, PSID* );
BOOL WINAPI ConvertStringSidToSidW( LPCWSTR, PSID* );
#define ConvertStringSidToSid WINELIB_NAME_AW(ConvertStringSidToSid)

BOOL WINAPI ConvertStringSecurityDescriptorToSecurityDescriptorA(
    LPCSTR, DWORD, PSECURITY_DESCRIPTOR*, PULONG );
BOOL WINAPI ConvertStringSecurityDescriptorToSecurityDescriptorW(
    LPCWSTR, DWORD, PSECURITY_DESCRIPTOR*, PULONG );
#define ConvertStringSecurityDescriptorToSecurityDescriptor WINELIB_NAME_AW(ConvertStringSecurityDescriptorToSecurityDescriptor)

BOOL WINAPI ConvertSecurityDescriptorToStringSecurityDescriptorA(
    PSECURITY_DESCRIPTOR, DWORD, SECURITY_INFORMATION, LPSTR*, PULONG );
BOOL WINAPI ConvertSecurityDescriptorToStringSecurityDescriptorW(
    PSECURITY_DESCRIPTOR, DWORD, SECURITY_INFORMATION, LPWSTR*, PULONG );
#define ConvertSecurityDescriptorToStringSecurityDescriptor WINELIB_NAME_AW(ConvertSecurityDescriptorToStringSecurityDescriptor)

#ifdef __cplusplus
}
#endif

#endif  /* __SDDL_H__ */
