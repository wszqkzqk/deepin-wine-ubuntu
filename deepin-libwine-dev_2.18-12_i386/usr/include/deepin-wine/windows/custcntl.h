/*
 * Copyright (C) 2002 Gyorgy 'Nog' Jeney  
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

#ifndef _INC_CUSTCNTL
#define _INC_CUSTCNTL

#ifdef __cplusplus
extern "C" {
#endif

/* Size defs */
#define CCHCCCLASS 32
#define CCHCCDESC 32
#define CCHCCTEXT 256

/* Custom Control Style Structure */
typedef struct tagCCSYLEA {
  DWORD flStyle;
  DWORD flExtStyle;
  char szText[CCHCCTEXT];
  LANGID lgid;
  WORD wReserved1;
} CCSTYLEA, *LPCCSTYLEA;

typedef struct tagCCSYLEW {
  DWORD flStyle;
  DWORD flExtStyle;
  WCHAR szText[CCHCCTEXT];
  LANGID lgid;
  WORD wReserved1;
} CCSTYLEW, *LPCCSTYLEW;

#define CCSTYLE   WINELIB_NAME_AW(CCSTYLE)
#define LPCCSTYLE WINELIB_NAME_AW(LPCCSTYLE)

typedef BOOL (CALLBACK *LPFNCCSTYLEA)(HWND, LPCCSTYLEA);
typedef BOOL (CALLBACK *LPFNCCSTYLEW)(HWND, LPCCSTYLEW);

#define LPFNCCSTYLE WINELIB_NAME_AW(LPFNCCSTYLE)

typedef int (CALLBACK *LPFNCCSIZETOTEXTA)(DWORD, DWORD, HFONT, LPSTR);
typedef int (CALLBACK *LPFNCCSIZETOTEXTW)(DWORD, DWORD, HFONT, LPWSTR);

#define LPFNCCSIZETOTEXT WINELIB_NAME_AW(LPFNCCSIZETOTEXT)

/* Custom Control style flags structure */
typedef struct tagCCSTYLEFLAGA {
  DWORD flStyle;
  DWORD flStyleMask;
  LPSTR pszStyle;
} CCSTYLEFLAGA, *LPCCSTYLEFLAGA;

typedef struct tagCCSTYLEFLAGW {
  DWORD flStyle;
  DWORD flStyleMask;
  LPWSTR pszStyle;
} CCSTYLEFLAGW, *LPCCSTYLEFLAGW;

#define CCSTYLEFLAG WINELIB_NAME_AW(CCSTYLEFLAG)

/* Custom Control Flags */
#define CCF_NOTEXT 0x00000001

/* CustomControl info structure */
typedef struct tagCCINFOA {
  char szClass[CCHCCCLASS];
  DWORD flOptions;
  char szDesc[CCHCCDESC];
  UINT cxDefault;
  UINT cyDefault;
  DWORD flStyleDefault;
  DWORD flExtStyleDefault;
  DWORD flCtrlTypeMask;
  char szTextDefault[CCHCCTEXT];
  int cStyleFlags;
  LPCCSTYLEFLAGA aStyleFlags;
  LPFNCCSTYLEA lpfnStyle;
  LPFNCCSIZETOTEXTA lpfnSizeToText;
  DWORD dwReserved1;
  DWORD dwReserved2;
} CCINFOA, *LPCCINFOA;

typedef struct tagCCINFOW {
  WCHAR szClass[CCHCCCLASS];
  DWORD flOptions;
  WCHAR szDesc[CCHCCDESC];
  UINT cxDefault;
  UINT cyDefault;
  DWORD flStyleDefault;
  DWORD flExtStyleDefault;
  DWORD flCtrlTypeMask;
  int cStyleFlags;
  LPCCSTYLEFLAGW aStyleFlags;
  WCHAR szTextDefault[CCHCCTEXT];
  LPFNCCSTYLEW lpfnStyle;
  LPFNCCSIZETOTEXTW lpfnSizeToText;
  DWORD dwReserved1;
  DWORD dwReserved2;
} CCINFOW, *LPCCINFOW;

DECL_WINELIB_TYPE_AW(CCINFO)
DECL_WINELIB_TYPE_AW(LPCCINFO)

typedef UINT (CALLBACK *LPFNCCINFOA)(LPCCINFOA);
typedef UINT (CALLBACK *LPFNCCINFOW)(LPCCINFOW);

DECL_WINELIB_TYPE_AW(LPFNCCINFO)

#ifdef __cplusplus
}
#endif

#endif /* _INC_CUSTCNTL */
