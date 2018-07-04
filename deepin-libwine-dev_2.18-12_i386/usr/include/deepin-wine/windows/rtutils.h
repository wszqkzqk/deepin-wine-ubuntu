/*
 * Rtutils.h - Routing utilities / RRAS tracing
 *
 * Copyright (C) 2009 Alexander Scott-Johns
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

#ifndef _RTUTILS_H_
#define _RTUTILS_H_

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

DWORD WINAPI TraceRegisterExW(LPCWSTR name, DWORD flags);
DWORD WINAPI TraceRegisterExA(LPCSTR name, DWORD flags);
#define      TraceRegisterEx  WINELIB_NAME_AW(TraceRegisterEx)

#define TraceRegisterW(name) TraceRegisterExW((name), 0)
#define TraceRegisterA(name) TraceRegisterExA((name), 0)
#define TraceRegister  WINELIB_NAME_AW(TraceRegister)

/* Flags for TraceRegisterEx(W|A) */
#define TRACE_USE_FILE     1
#define TRACE_USE_CONSOLE  2

/* Return value of TraceRegisterEx(W|A) */
#define INVALID_TRACEID    0xFFFFFFFF

#ifdef __cplusplus
}
#endif

#endif /* _RTUTILS_H_ */
