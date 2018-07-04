/*
 * Copyright (C) 1999 Rein Klazes
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

#ifndef __WINE_LMCONS_H
#define __WINE_LMCONS_H

/* Types */

#define NET_API_STATUS          DWORD
#define API_RET_TYPE            NET_API_STATUS
#define NET_API_FUNCTION        WINAPI

#define MAX_PREFERRED_LENGTH            ((DWORD) -1)

/* Lan manager API defines */

#define UNLEN       256
#define LM20_UNLEN  20
#define GNLEN       UNLEN
#define LM20_GNLEN  LM20_UNLEN
#define PWLEN       256
#define LM20_PWLEN  14
#define SHPWLEN     8
#define CNLEN       15
#define LM20_CNLEN  CNLEN
#define DNLEN       CNLEN
#define LM20_DNLEN  DNLEN
#define UNCLEN      (CNLEN+2)
#define LM20_UNCLEN (LM20_CNLEN+2)
#define NNLEN       80
#define LM20_NNLEN  12
#define RMLEN       (UNCLEN+1+NNLEN)
#define LM20_RMLEN  (LM20_UNCLEN+1+LM20_NNLEN)
#define SNLEN       80
#define LM20_SNLEN  15
#define STXTLEN     256
#define LM20_STXTLEN 63
#define PATHLEN     256
#define LM20_PATHLEN 256
#define DEVLEN      80
#define LM20_DEVLEN 8
#define EVLEN       16
#define CLTYPE_LEN  12

/* platform IDs */
#define PLATFORM_ID_DOS 300
#define PLATFORM_ID_OS2 400
#define PLATFORM_ID_NT  500
#define PLATFORM_ID_OSF 600
#define PLATFORM_ID_VMS 700

#define LMSTR LPWSTR
#define LMCSTR LPCWSTR

#endif
