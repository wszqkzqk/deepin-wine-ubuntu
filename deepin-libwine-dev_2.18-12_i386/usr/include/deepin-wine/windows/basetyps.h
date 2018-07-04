/*
 * Copyright (C) 1998 Anders Norlander
 * Copyright (C) 2005 Steven Edwards
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

#ifndef _BASETYPS_H_
#define _BASETYPS_H_

#ifdef __cplusplus
# define EXTERN_C extern "C"
#else
# define EXTERN_C extern
#endif

#define STDMETHODCALLTYPE  __stdcall
#define STDMETHODVCALLTYPE __cdecl
#define STDAPICALLTYPE     __stdcall
#define STDAPIVCALLTYPE    __cdecl
#define STDAPI             EXTERN_C HRESULT STDAPICALLTYPE
#define STDAPI_(t)         EXTERN_C t STDAPICALLTYPE
#define STDMETHODIMP       HRESULT STDMETHODCALLTYPE
#define STDMETHODIMP_(t)   t STDMETHODCALLTYPE
#define STDAPIV            EXTERN_C HRESULT STDAPIVCALLTYPE
#define STDAPIV_(t)        EXTERN_C t STDAPIVCALLTYPE
#define STDMETHODIMPV      HRESULT STDMETHODVCALLTYPE
#define STDMETHODIMPV_(t)  t STDMETHODVCALLTYPE

#if defined(__cplusplus) && !defined(CINTERFACE)
# define interface struct
# define STDMETHOD(m) virtual HRESULT STDMETHODCALLTYPE m
# define STDMETHOD_(t,m) virtual t STDMETHODCALLTYPE m
# define PURE =0
# define THIS_
# define THIS void
# define DECLARE_INTERFACE(i)    interface i
# define DECLARE_INTERFACE_(i,b) interface i : public b
#else
# define STDMETHOD(m) HRESULT (STDMETHODCALLTYPE *m)
# define STDMETHOD_(t,m) t (STDMETHODCALLTYPE *m)
# define PURE
# define THIS_ INTERFACE *,
# define THIS INTERFACE *
# ifdef CONST_VTABLE
#  define DECLARE_INTERFACE(i) \
     typedef interface i { const struct i##Vtbl *lpVtbl; } i; \
     typedef struct i##Vtbl i##Vtbl; \
     struct i##Vtbl
# else
#  define DECLARE_INTERFACE(i) \
     typedef interface i { struct i##Vtbl *lpVtbl; } i; \
     typedef struct i##Vtbl i##Vtbl; \
     struct i##Vtbl
# endif
# define DECLARE_INTERFACE_(i,b) DECLARE_INTERFACE(i)
#endif

#include <guiddef.h>

#ifndef _ERROR_STATUS_T_DEFINED
typedef unsigned long error_status_t;
#define _ERROR_STATUS_T_DEFINED
#endif

#ifndef _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#endif /* _BASETYPS_H_ */
