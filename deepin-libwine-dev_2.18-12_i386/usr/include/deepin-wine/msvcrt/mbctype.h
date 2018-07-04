/*
 * Multibyte char definitions
 *
 * Copyright 2001 Francois Gouget.
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
#ifndef __WINE_MBCTYPE_H
#define __WINE_MBCTYPE_H

#include <crtdefs.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __i386__
unsigned char* __cdecl __p__mbctype(void);
#define _mbctype                   (__p__mbctype())
#else
extern unsigned char MSVCRT_mbctype[];
#endif

#define _MS     0x01
#define _MP     0x02
#define _M1     0x04
#define _M2     0x08

#define _SBUP   0x10
#define _SBLOW  0x20

#define _MBC_SINGLE     0
#define _MBC_LEAD       1
#define _MBC_TRAIL      2
#define _MBC_ILLEGAL    -1

#define _KANJI_CP   932

#define _MB_CP_SBCS     0
#define _MB_CP_OEM      -2
#define _MB_CP_ANSI     -3
#define _MB_CP_LOCALE   -4

int __cdecl _getmbcp(void);
int __cdecl _ismbbalnum(unsigned int);
int __cdecl _ismbbalpha(unsigned int);
int __cdecl _ismbbgraph(unsigned int);
int __cdecl _ismbbkalnum(unsigned int);
int __cdecl _ismbbkana(unsigned int);
int __cdecl _ismbbkprint(unsigned int);
int __cdecl _ismbbkpunct(unsigned int);
int __cdecl _ismbbprint(unsigned int);
int __cdecl _ismbbpunct(unsigned int);
int __cdecl _setmbcp(int);

#ifndef _MBLEADTRAIL_DEFINED
#define _MBLEADTRAIL_DEFINED
int __cdecl _ismbblead(unsigned int);
int __cdecl _ismbbtrail(unsigned int);
int __cdecl _ismbslead(const unsigned char*,const unsigned char*);
int __cdecl _ismbstrail(const unsigned char*,const unsigned char*);
#endif /* _MBLEADTRAIL_DEFINED */

#ifdef __cplusplus
}
#endif

#endif /* __WINE_MBCTYPE_H */
