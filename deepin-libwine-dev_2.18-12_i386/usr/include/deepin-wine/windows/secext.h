/*
 * Copyright (C) 2004 Mike McCormack
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

#ifndef __SECEXT_H__
#define __SECEXT_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    NameUnknown = 0,
    NameFullyQualifiedDN = 1,
    NameSamCompatible = 2,
    NameDisplay = 3,
    NameUniqueId = 6,
    NameCanonical = 7,
    NameUserPrincipal = 8,
    NameCanonicalEx = 9,
    NameServicePrincipal = 10,
    NameDnsDomain = 12,
    NameGivenName = 13,
    NameSurname = 14,
} EXTENDED_NAME_FORMAT, *PEXTENDED_NAME_FORMAT;

BOOLEAN WINAPI GetComputerObjectNameA( EXTENDED_NAME_FORMAT, LPSTR, PULONG );
BOOLEAN WINAPI GetComputerObjectNameW( EXTENDED_NAME_FORMAT, LPWSTR, PULONG );
#define        GetComputerObjectName WINELIB_NAME_AW(GetComputerObjectName)

BOOLEAN WINAPI GetUserNameExA( EXTENDED_NAME_FORMAT, LPSTR, PULONG );
BOOLEAN WINAPI GetUserNameExW( EXTENDED_NAME_FORMAT, LPWSTR, PULONG );
#define        GetUserNameEx WINELIB_NAME_AW(GetUserNameEx)

BOOLEAN WINAPI TranslateNameA( LPCSTR, EXTENDED_NAME_FORMAT, EXTENDED_NAME_FORMAT, LPSTR, PULONG);
BOOLEAN WINAPI TranslateNameW( LPCWSTR, EXTENDED_NAME_FORMAT, EXTENDED_NAME_FORMAT, LPWSTR, PULONG);
#define        TranslateName WINELIB_NAME_AW(TranslateName)

#ifdef __cplusplus
}
#endif

#endif /* __SECEXT_H__ */
