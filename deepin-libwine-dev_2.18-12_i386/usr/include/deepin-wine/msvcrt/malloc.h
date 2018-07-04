/*
 * Heap definitions
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
#ifndef __WINE_MALLOC_H
#define __WINE_MALLOC_H

#include <crtdefs.h>

/* heap function constants */
#define _HEAPEMPTY    -1
#define _HEAPOK       -2
#define _HEAPBADBEGIN -3
#define _HEAPBADNODE  -4
#define _HEAPEND      -5
#define _HEAPBADPTR   -6

#define _FREEENTRY     0
#define _USEDENTRY     1

#ifndef _HEAPINFO_DEFINED
#define _HEAPINFO_DEFINED
typedef struct _heapinfo
{
  int*           _pentry;
  size_t _size;
  int            _useflag;
} _HEAPINFO;
#endif /* _HEAPINFO_DEFINED */

#ifdef __i386__
extern unsigned int* __cdecl __p__amblksiz(void);
#define _amblksiz (*__p__amblksiz());
#else
extern unsigned int _amblksiz;
#endif

#ifdef __cplusplus
extern "C" {
#endif

void*  __cdecl _expand(void*,size_t);
int    __cdecl _heapadd(void*,size_t);
int    __cdecl _heapchk(void);
int    __cdecl _heapmin(void);
int    __cdecl _heapset(unsigned int);
size_t __cdecl _heapused(size_t*,size_t*);
int    __cdecl _heapwalk(_HEAPINFO*);
size_t __cdecl _msize(void*);

void*  __cdecl calloc(size_t,size_t);
void   __cdecl free(void*);
void*  __cdecl malloc(size_t);
void*  __cdecl realloc(void*,size_t);

void   __cdecl _aligned_free(void*);
void*  __cdecl _aligned_malloc(size_t,size_t);
void*  __cdecl _aligned_offset_malloc(size_t,size_t,size_t);
void*  __cdecl _aligned_realloc(void*,size_t,size_t);
void*  __cdecl _aligned_offset_realloc(void*,size_t,size_t,size_t);

size_t __cdecl _get_sbh_threshold(void);
int    __cdecl _set_sbh_threshold(size_t size);

#ifdef __cplusplus
}
#endif

# ifdef __GNUC__
# define _alloca(x) __builtin_alloca((x))
# define alloca(x) __builtin_alloca((x))
# endif

#endif /* __WINE_MALLOC_H */
