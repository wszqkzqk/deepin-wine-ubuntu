/*
 * Copyright (C) 2010 Nikolay Sivov for CodeWeavers
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

#ifndef _RASDLG_H_
#define _RASDLG_H_

#include <ras.h>

typedef struct tagRASENTRYDLGW
{
    DWORD dwSize;
    HWND  hwndOwner;
    DWORD dwFlags;
    LONG  xDlg;
    LONG  yDlg;
    WCHAR szEntry[ RAS_MaxEntryName + 1 ];
    DWORD dwError;
    ULONG_PTR reserved;
    ULONG_PTR reserved2;
} RASENTRYDLGW;

#endif  /* _RASDLG_H_ */
