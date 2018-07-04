/*
 * Copyright 2010 Thomas Mullaly
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
#ifndef __WINE_STRSAFE_H
#define __WINE_STRSAFE_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/* Windows version includes this header. */
/* #include <specstring.h> */

#define STRSAFE_E_INSUFFICIENT_BUFFER   ((HRESULT)0x8007007A)
#define STRSAFE_E_INVALID_PARAM         ((HRESULT)0x80070075)
#define STRSAFE_E_END_OF_FILE           ((HRESULT)0x80070026)

#endif
