/*
 * Copyright 2013 Hans Leidekker for CodeWeavers.
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

#ifndef __WINE_WINSNMP_H
#define __WINE_WINSNMP_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int          smiINT, *smiLPINT;
typedef smiINT       smiINT32, *smiLPINT32;
typedef unsigned int smiUINT32, *smiLPUINT32;
typedef smiUINT32    SNMPAPI_STATUS;
typedef HANDLE       HSNMP_SESSION;

#define SNMPAPI_NO_SUPPORT  0
#define SNMPAPI_V1_SUPPORT  1
#define SNMPAPI_V2_SUPPORT  2
#define SNMPAPI_M2M_SUPPORT 3

#define SNMPAPI_TRANSLATED      0
#define SNMPAPI_UNTRANSLATED_V1 1
#define SNMPAPI_UNTRANSLATED_V2 2

#define SNMPAPI_OFF 0
#define SNMPAPI_ON  1

#define SNMPAPI_FAILURE 0
#define SNMPAPI_SUCCESS 1

SNMPAPI_STATUS WINAPI SnmpCleanup(void);
HSNMP_SESSION  WINAPI SnmpOpen(HWND,UINT);
SNMPAPI_STATUS WINAPI SnmpSetRetransmitMode(smiUINT32);
SNMPAPI_STATUS WINAPI SnmpSetTranslateMode(smiUINT32);
SNMPAPI_STATUS WINAPI SnmpStartup(smiLPUINT32,smiLPUINT32,smiLPUINT32,smiLPUINT32,smiLPUINT32);

#ifdef __cplusplus
}
#endif

#endif /* __WINE_WINSNMP_H */
