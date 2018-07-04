/*
 * VDMDBG definitions
 *
 * Copyright (C) 2007 James Hawkins
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

#ifndef __WINE_VDMDBG_H
#define __WINE_VDMDBG_H

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

typedef BOOL (WINAPI *PROCESSENUMPROC)(DWORD, DWORD, LPARAM);
typedef BOOL (WINAPI *TASKENUMPROC)(DWORD, WORD, WORD, LPARAM);
typedef BOOL (WINAPI *TASKENUMPROCEX)(DWORD, WORD, WORD, PSZ, PSZ, LPARAM);

INT WINAPI VDMEnumProcessWOW(PROCESSENUMPROC, LPARAM);
INT WINAPI VDMEnumTaskWOW(DWORD, TASKENUMPROC, LPARAM);
INT WINAPI VDMEnumTaskWOWEx(DWORD, TASKENUMPROCEX, LPARAM);

#ifdef __cplusplus
} /* extern "C" */
#endif /* defined(__cplusplus) */

#endif /* __WINE_VDMDBG_H */
