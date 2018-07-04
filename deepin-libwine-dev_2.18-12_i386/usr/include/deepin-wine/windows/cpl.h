/*
 * Control panel definitions
 *
 * Copyright (C) 2001 Eric Pouech
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

#ifndef _INC_CPL
#define _INC_CPL

#include <pshpack1.h>

#ifdef __cplusplus
extern "C" {
#endif

#define WM_CPL_LAUNCH   (WM_USER+1000)
#define WM_CPL_LAUNCHED (WM_USER+1001)

typedef LONG (APIENTRY *APPLET_PROC)(HWND hwndCpl, UINT msg, LPARAM lParam1, LPARAM lParam2);

typedef struct tagCPLINFO {
    int     idIcon;
    int     idName;
    int     idInfo;
    LONG_PTR lData;
} CPLINFO, *LPCPLINFO;

typedef struct tagNEWCPLINFOA
{
    DWORD   dwSize;
    DWORD   dwFlags;
    DWORD   dwHelpContext;
    LONG_PTR lData;
    HICON   hIcon;
    CHAR    szName[32];
    CHAR    szInfo[64];
    CHAR    szHelpFile[128];
} NEWCPLINFOA, *LPNEWCPLINFOA;

typedef struct tagNEWCPLINFOW
{
    DWORD   dwSize;
    DWORD   dwFlags;
    DWORD   dwHelpContext;
    LONG_PTR lData;
    HICON   hIcon;
    WCHAR   szName[32];
    WCHAR   szInfo[64];
    WCHAR   szHelpFile[128];
} NEWCPLINFOW, *LPNEWCPLINFOW;

DECL_WINELIB_TYPE_AW(NEWCPLINFO)
DECL_WINELIB_TYPE_AW(LPNEWCPLINFO)

#define CPL_DYNAMIC_RES 	0
#define CPL_INIT        	1
#define CPL_GETCOUNT    	2
#define CPL_INQUIRE     	3
#define CPL_SELECT      	4
#define CPL_DBLCLK      	5
#define CPL_STOP        	6
#define CPL_EXIT        	7
#define CPL_NEWINQUIRE		8
#define CPL_STARTWPARMSA 	9
#define CPL_STARTWPARMSW 	10
#define CPL_STARTWPARMS WINELIB_NAME_AW(CPL_STARTWPARMS)
#define CPL_SETUP		200

#ifdef __cplusplus
}
#endif

#include <poppack.h>

#endif /* _INC_CPL */
