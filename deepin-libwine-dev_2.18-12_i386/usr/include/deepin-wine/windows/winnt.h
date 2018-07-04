/*
 * Win32 definitions for Windows NT
 *
 * Copyright 1996 Alexandre Julliard
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

#ifndef _WINNT_
#define _WINNT_

#include <basetsd.h>
#include <guiddef.h>

#ifndef RC_INVOKED
#include <ctype.h>
#include <stddef.h>
#include <string.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif

#ifdef _NTSYSTEM_
#define NTSYSAPI
#else
#define NTSYSAPI DECLSPEC_IMPORT
#endif

#define NTAPI __stdcall

#ifndef MIDL_PASS
# if defined(_MSC_VER)
#  define DECLSPEC_IMPORT __declspec(dllimport)
# elif defined(__MINGW32__) || defined(__CYGWIN__)
#  define DECLSPEC_IMPORT __attribute__((dllimport))
# else
#  define DECLSPEC_IMPORT DECLSPEC_HIDDEN
# endif
#else
# define DECLSPEC_IMPORT
#endif

#ifndef DECLSPEC_NORETURN
# if defined(_MSC_VER) && (_MSC_VER >= 1200) && !defined(MIDL_PASS)
#  define DECLSPEC_NORETURN __declspec(noreturn)
# elif defined(__GNUC__)
#  define DECLSPEC_NORETURN __attribute__((noreturn))
# else
#  define DECLSPEC_NORETURN
# endif
#endif

#ifndef DECLSPEC_ALIGN
# if defined(_MSC_VER) && (_MSC_VER >= 1300) && !defined(MIDL_PASS)
#  define DECLSPEC_ALIGN(x) __declspec(align(x))
# elif defined(__GNUC__)
#  define DECLSPEC_ALIGN(x) __attribute__((aligned(x)))
# else
#  define DECLSPEC_ALIGN(x)
# endif
#endif

#ifndef DECLSPEC_CACHEALIGN
# define DECLSPEC_CACHEALIGN DECLSPEC_ALIGN(128)
#endif

#ifndef DECLSPEC_UUID
# if defined(_MSC_VER) && (_MSC_VER >= 1100) && defined (__cplusplus)
#  define DECLSPEC_UUID(x) __declspec(uuid(x))
# else
#  define DECLSPEC_UUID(x)
# endif
#endif

#ifndef DECLSPEC_NOVTABLE
# if defined(_MSC_VER) && (_MSC_VER >= 1100) && defined(__cplusplus)
#  define DECLSPEC_NOVTABLE __declspec(novtable)
# else
#  define DECLSPEC_NOVTABLE
# endif
#endif

#ifndef DECLSPEC_SELECTANY
#if defined(_MSC_VER) && (_MSC_VER >= 1100)
#define DECLSPEC_SELECTANY __declspec(selectany)
#else
#define DECLSPEC_SELECTANY
#endif
#endif

#ifndef NOP_FUNCTION
# if defined(_MSC_VER) && (_MSC_VER >= 1210)
#  define NOP_FUNCTION __noop
# else
#  define NOP_FUNCTION (void)0
# endif
#endif

#ifndef DECLSPEC_ADDRSAFE
# if defined(_MSC_VER) && (_MSC_VER >= 1200) && (defined(_M_ALPHA) || defined(_M_AXP64))
#  define DECLSPEC_ADDRSAFE __declspec(address_safe)
# else
#  define DECLSPEC_ADDRSAFE
# endif
#endif

#ifndef FORCEINLINE
# if defined(_MSC_VER) && (_MSC_VER >= 1200)
#  define FORCEINLINE __forceinline
# elif defined(__GNUC__) && ((__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 2)))
#  define FORCEINLINE inline __attribute__((always_inline))
# else
#  define FORCEINLINE inline
# endif
#endif

#ifndef DECLSPEC_DEPRECATED
# if defined(_MSC_VER) && (_MSC_VER >= 1300) && !defined(MIDL_PASS)
#  define DECLSPEC_DEPRECATED __declspec(deprecated)
#  define DEPRECATE_SUPPORTED
# elif defined(__GNUC__) && ((__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 2)))
#  define DECLSPEC_DEPRECATED __attribute__((deprecated))
#  define DEPRECATE_SUPPORTED
# else
#  define DECLSPEC_DEPRECATED
#  undef  DEPRECATE_SUPPORTED
# endif
#endif

/* a couple of useful Wine extensions */

#ifdef _MSC_VER
# define DECLSPEC_EXPORT __declspec(dllexport)
#elif defined(__MINGW32__)
# define DECLSPEC_EXPORT __attribute__((dllexport))
#elif defined(__GNUC__) && ((__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 3))) && !defined(__sun)
# define DECLSPEC_EXPORT __attribute__((visibility ("default")))
#else
# define DECLSPEC_EXPORT
#endif

#if defined(_MSC_VER) || defined(__MINGW32__) || defined(__CYGWIN__) || defined(__sun)
# define DECLSPEC_HIDDEN
#elif defined(__GNUC__) && ((__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 3)))
# define DECLSPEC_HIDDEN __attribute__((visibility ("hidden")))
#else
# define DECLSPEC_HIDDEN
#endif

#if defined(__GNUC__) && ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 3)))
#define __WINE_ALLOC_SIZE(x) __attribute__((__alloc_size__(x)))
#else
#define __WINE_ALLOC_SIZE(x)
#endif

/* Anonymous union/struct handling */

#ifndef NONAMELESSSTRUCT
# ifdef __GNUC__
   /* Anonymous struct support starts with gcc 2.96 or gcc/g++ 3.x */
#  if (__GNUC__ < 2) || ((__GNUC__ == 2) && (defined(__cplusplus) || (__GNUC_MINOR__ < 96)))
#   define NONAMELESSSTRUCT
#  endif
# elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#  define NONAMELESSSTRUCT
# endif
#endif  /* NONAMELESSSTRUCT */

#ifndef NONAMELESSUNION
# ifdef __GNUC__
   /* Anonymous unions support starts with gcc 2.96/g++ 2.95 */
#  if (__GNUC__ < 2) || ((__GNUC__ == 2) && ((__GNUC_MINOR__ < 95) || ((__GNUC_MINOR__ == 95) && !defined(__cplusplus))))
#   define NONAMELESSUNION
#  endif
# elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#  define NONAMELESSUNION
# endif
#endif  /* NONAMELESSUNION */

#undef DUMMYSTRUCTNAME
#undef DUMMYSTRUCTNAME1
#undef DUMMYSTRUCTNAME2
#undef DUMMYSTRUCTNAME3
#undef DUMMYSTRUCTNAME4
#undef DUMMYSTRUCTNAME5
#ifndef NONAMELESSSTRUCT
#define DUMMYSTRUCTNAME
#define DUMMYSTRUCTNAME1
#define DUMMYSTRUCTNAME2
#define DUMMYSTRUCTNAME3
#define DUMMYSTRUCTNAME4
#define DUMMYSTRUCTNAME5
#else /* !defined(NONAMELESSSTRUCT) */
#define DUMMYSTRUCTNAME   s
#define DUMMYSTRUCTNAME1  s1
#define DUMMYSTRUCTNAME2  s2
#define DUMMYSTRUCTNAME3  s3
#define DUMMYSTRUCTNAME4  s4
#define DUMMYSTRUCTNAME5  s5
#endif /* !defined(NONAMELESSSTRUCT) */

#undef DUMMYUNIONNAME
#undef DUMMYUNIONNAME1
#undef DUMMYUNIONNAME2
#undef DUMMYUNIONNAME3
#undef DUMMYUNIONNAME4
#undef DUMMYUNIONNAME5
#undef DUMMYUNIONNAME6
#undef DUMMYUNIONNAME7
#undef DUMMYUNIONNAME8
#ifndef NONAMELESSUNION
#define DUMMYUNIONNAME
#define DUMMYUNIONNAME1
#define DUMMYUNIONNAME2
#define DUMMYUNIONNAME3
#define DUMMYUNIONNAME4
#define DUMMYUNIONNAME5
#define DUMMYUNIONNAME6
#define DUMMYUNIONNAME7
#define DUMMYUNIONNAME8
#else /* !defined(NONAMELESSUNION) */
#define DUMMYUNIONNAME   u
#define DUMMYUNIONNAME1  u1
#define DUMMYUNIONNAME2  u2
#define DUMMYUNIONNAME3  u3
#define DUMMYUNIONNAME4  u4
#define DUMMYUNIONNAME5  u5
#define DUMMYUNIONNAME6  u6
#define DUMMYUNIONNAME7  u7
#define DUMMYUNIONNAME8  u8
#endif /* !defined(NONAMELESSUNION) */

#undef __C89_NAMELESS
#undef __C89_NAMELESSSTRUCTNAME
#undef __C89_NAMELESSSTRUCTNAME1
#undef __C89_NAMELESSSTRUCTNAME2
#undef __C89_NAMELESSSTRUCTNAME3
#undef __C89_NAMELESSSTRUCTNAME4
#undef __C89_NAMELESSSTRUCTNAME5
#undef __C89_NAMELESSUNIONNAME
#undef __C89_NAMELESSUNIONNAME1
#undef __C89_NAMELESSUNIONNAME2
#undef __C89_NAMELESSUNIONNAME3
#undef __C89_NAMELESSUNIONNAME4
#undef __C89_NAMELESSUNIONNAME5
#undef __C89_NAMELESSUNIONNAME6
#undef __C89_NAMELESSUNIONNAME7
#undef __C89_NAMELESSUNIONNAME8

#if !defined(__WINESRC__) && !defined(WINE_NO_NAMELESS_EXTENSION)
# ifdef __GNUC__
   /* Anonymous structs support starts with gcc 2.96/g++ 2.95 */
#  if (__GNUC__ > 2) || ((__GNUC__ == 2) && ((__GNUC_MINOR__ > 95) || ((__GNUC_MINOR__ == 95) && defined(__cplusplus))))
#   define __C89_NAMELESS __extension__
#  endif
# elif defined(_MSC_VER)
#  define __C89_NAMELESS
# endif
#endif

#ifdef __C89_NAMELESS
#  define __C89_NAMELESSSTRUCTNAME
#  define __C89_NAMELESSSTRUCTNAME1
#  define __C89_NAMELESSSTRUCTNAME2
#  define __C89_NAMELESSSTRUCTNAME3
#  define __C89_NAMELESSSTRUCTNAME4
#  define __C89_NAMELESSSTRUCTNAME5
#  define __C89_NAMELESSUNIONNAME
#  define __C89_NAMELESSUNIONNAME1
#  define __C89_NAMELESSUNIONNAME2
#  define __C89_NAMELESSUNIONNAME3
#  define __C89_NAMELESSUNIONNAME4
#  define __C89_NAMELESSUNIONNAME5
#  define __C89_NAMELESSUNIONNAME6
#  define __C89_NAMELESSUNIONNAME7
#  define __C89_NAMELESSUNIONNAME8
#else
#  define __C89_NAMELESS
#  define __C89_NAMELESSSTRUCTNAME DUMMYSTRUCTNAME
#  define __C89_NAMELESSSTRUCTNAME1 DUMMYSTRUCTNAME1
#  define __C89_NAMELESSSTRUCTNAME2 DUMMYSTRUCTNAME2
#  define __C89_NAMELESSSTRUCTNAME3 DUMMYSTRUCTNAME3
#  define __C89_NAMELESSSTRUCTNAME4 DUMMYSTRUCTNAME4
#  define __C89_NAMELESSSTRUCTNAME5 DUMMYSTRUCTNAME5
#  define __C89_NAMELESSUNIONNAME DUMMYUNIONNAME
#  define __C89_NAMELESSUNIONNAME1 DUMMYUNIONNAME1
#  define __C89_NAMELESSUNIONNAME2 DUMMYUNIONNAME2
#  define __C89_NAMELESSUNIONNAME3 DUMMYUNIONNAME3
#  define __C89_NAMELESSUNIONNAME4 DUMMYUNIONNAME4
#  define __C89_NAMELESSUNIONNAME5 DUMMYUNIONNAME5
#  define __C89_NAMELESSUNIONNAME6 DUMMYUNIONNAME6
#  define __C89_NAMELESSUNIONNAME7 DUMMYUNIONNAME7
#  define __C89_NAMELESSUNIONNAME8 DUMMYUNIONNAME8
#endif

/* C99 restrict support */

#if defined(ENABLE_RESTRICTED) && !defined(MIDL_PASS) && !defined(RC_INVOKED)
# if defined(_MSC_VER) && defined(_M_MRX000)
#  define RESTRICTED_POINTER __restrict
# elif defined(__GNUC__) && ((__GNUC__ > 2) || ((__GNUC__ == 2) && (__GNUC_MINOR__ >= 95)))
#  define RESTRICTED_POINTER __restrict
# else
#  define RESTRICTED_POINTER
# endif
#else
# define RESTRICTED_POINTER
#endif

/* C99 unaligned support */

#ifndef UNALIGNED
#if defined(_MSC_VER) && (defined(_M_MRX000) || defined(_M_ALPHA) || defined(_M_PPC) || defined(_M_IA64) || defined(_M_AMD64))
# define UNALIGNED __unaligned
# ifdef _WIN64
#  define UNALIGNED64 __unaligned
# else
#  define UNALIGNED64
# endif
#else
# define UNALIGNED
# define UNALIGNED64
#endif
#endif

/* Alignment macros */

#if defined(_WIN64) || (defined(_MSC_VER) && defined(_M_ALPHA)) || defined(__alpha__)
#define MAX_NATURAL_ALIGNMENT sizeof(ULONGLONG)
#define MEMORY_ALLOCATION_ALIGNMENT 16
#else
#define MAX_NATURAL_ALIGNMENT sizeof(DWORD)
#define MEMORY_ALLOCATION_ALIGNMENT 8
#endif

#if defined(_MSC_VER) && (_MSC_VER >= 1300) && defined(__cplusplus)
# define TYPE_ALIGNMENT(t) __alignof(t)
#elif defined(__GNUC__)
# define TYPE_ALIGNMENT(t) __alignof__(t)
#else
# define TYPE_ALIGNMENT(t) FIELD_OFFSET(struct { char x; t test; }, test)
#endif

#ifdef _WIN64
# define PROBE_ALIGNMENT(_s) \
    (TYPE_ALIGNMENT(_s) > TYPE_ALIGNMENT(DWORD) ? \
    TYPE_ALIGNMENT(_s) : TYPE_ALIGNMENT(DWORD))
# define PROBE_ALIGNMENT32(_s) TYPE_ALIGNMENT(DWORD)
#else
# define PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#endif

/* Compile time assertion */

#if defined(_MSC_VER)
# define C_ASSERT(e) typedef char __C_ASSERT__[(e)?1:-1]
#else
# define C_ASSERT(e) extern void __C_ASSERT__(int [(e)?1:-1])
#endif

/* Eliminate Microsoft C/C++ compiler warning 4715 */
#if defined(_MSC_VER) && (_MSC_VER > 1200)
# define DEFAULT_UNREACHABLE default: __assume(0)
#elif defined(__clang__) || (defined(__GNUC__) && ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 5))))
# define DEFAULT_UNREACHABLE default: __builtin_unreachable()
#else
# define DEFAULT_UNREACHABLE default:
#endif

/* Error Masks */
#define APPLICATION_ERROR_MASK       0x20000000
#define ERROR_SEVERITY_SUCCESS       0x00000000
#define ERROR_SEVERITY_INFORMATIONAL 0x40000000
#define ERROR_SEVERITY_WARNING       0x80000000
#define ERROR_SEVERITY_ERROR         0xC0000000

#ifdef __cplusplus
#define DEFINE_ENUM_FLAG_OPERATORS(ENUMTYPE) \
extern "C++" { \
    inline ENUMTYPE operator | (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE(((int)a)|((int)b)); } \
    inline ENUMTYPE operator |= (ENUMTYPE &a, ENUMTYPE b) { return (ENUMTYPE &)(((int &)a) |= ((int)b)); } \
    inline ENUMTYPE operator & (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE(((int)a)&((int)b)); } \
    inline ENUMTYPE operator &= (ENUMTYPE &a, ENUMTYPE b) { return (ENUMTYPE &)(((int &)a) &= ((int)b)); } \
    inline ENUMTYPE operator ~ (ENUMTYPE a) { return (ENUMTYPE)(~((int)a)); } \
    inline ENUMTYPE operator ^ (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE(((int)a)^((int)b)); } \
    inline ENUMTYPE operator ^= (ENUMTYPE &a, ENUMTYPE b) { return (ENUMTYPE &)(((int &)a) ^= ((int)b)); } \
}
#else
#define DEFINE_ENUM_FLAG_OPERATORS(ENUMTYPE) /* */
#endif

/* Microsoft's macros for declaring functions */

#ifdef __cplusplus
# define EXTERN_C    extern "C"
#else
# define EXTERN_C    extern
#endif

#define STDMETHODCALLTYPE       __stdcall
#define STDMETHODVCALLTYPE      __cdecl
#define STDAPICALLTYPE          __stdcall
#define STDAPIVCALLTYPE         __cdecl

#define STDAPI                  EXTERN_C HRESULT STDAPICALLTYPE
#define STDAPI_(type)           EXTERN_C type STDAPICALLTYPE
#define STDMETHODIMP            HRESULT STDMETHODCALLTYPE
#define STDMETHODIMP_(type)     type STDMETHODCALLTYPE
#define STDAPIV                 EXTERN_C HRESULT STDAPIVCALLTYPE
#define STDAPIV_(type)          EXTERN_C type STDAPIVCALLTYPE
#define STDMETHODIMPV           HRESULT STDMETHODVCALLTYPE
#define STDMETHODIMPV_(type)    type STDMETHODVCALLTYPE

/* Define the basic types */
#ifndef VOID
#define VOID void
#endif
typedef VOID           *PVOID;
typedef VOID           *PVOID64;
typedef BYTE            BOOLEAN,    *PBOOLEAN;
typedef char            CHAR,       *PCHAR;
typedef short           SHORT,      *PSHORT;
#ifdef _MSC_VER
typedef long            LONG,       *PLONG;
#else
typedef int             LONG,       *PLONG;
#endif

/* Some systems might have wchar_t, but we really need 16 bit characters */
#ifdef WINE_UNICODE_NATIVE
typedef wchar_t         WCHAR,      *PWCHAR;
#else
typedef unsigned short  WCHAR,      *PWCHAR;
#endif

typedef ULONG           UCSCHAR;
#define MIN_UCSCHAR                 (0)
#define MAX_UCSCHAR                 (0x0010ffff)
#define UCSCHAR_INVALID_CHARACTER   (0xffffffff)

/* 'Extended/Wide' numerical types */
#ifndef _ULONGLONG_
# define _ULONGLONG_
# ifdef _MSC_VER
typedef signed __int64   LONGLONG,  *PLONGLONG;
typedef unsigned __int64 ULONGLONG, *PULONGLONG;
# else
typedef signed __int64   DECLSPEC_ALIGN(8) LONGLONG,   *PLONGLONG;
typedef unsigned __int64 DECLSPEC_ALIGN(8) ULONGLONG,  *PULONGLONG;
# endif
#endif

#ifndef _DWORDLONG_
# define _DWORDLONG_
# ifdef _MSC_VER
typedef ULONGLONG DWORDLONG, *PDWORDLONG;
# else
typedef ULONGLONG   DECLSPEC_ALIGN(8) DWORDLONG,   *PDWORDLONG;
# endif
#endif

/* ANSI string types */
typedef CHAR           *PCH,        *LPCH,      *PNZCH;
typedef const CHAR     *PCCH,       *LPCCH,     *PCNZCH;
typedef CHAR           *PSTR,       *LPSTR,     *NPSTR;
typedef const CHAR     *PCSTR,      *LPCSTR;
typedef CHAR           *PZZSTR;
typedef const CHAR     *PCZZSTR;

/* Unicode string types */
typedef const WCHAR    *PCWCHAR,    *LPCUWCHAR, *PCUWCHAR;
typedef WCHAR          *PWCH,       *LPWCH;
typedef const WCHAR    *PCWCH,      *LPCWCH;
typedef WCHAR          *PNZWCH,     *PUNZWCH;
typedef const WCHAR    *PCNZWCH,    *PCUNZWCH;
typedef WCHAR          *PWSTR,      *LPWSTR,    *NWPSTR;
typedef const WCHAR    *PCWSTR,     *LPCWSTR;
typedef WCHAR          *PZZWSTR,    *PUZZWSTR;
typedef const WCHAR    *PCZZWSTR,   *PCUZZWSTR;
typedef PWSTR          *PZPWSTR;
typedef PCWSTR         *PZPCWSTR;

/* Neutral character and string types */
/* These are only defined for Winelib, i.e. _not_ defined for
 * the emulator. The reason is they depend on the UNICODE
 * macro which only exists in the user's code.
 */
#ifndef WINE_NO_UNICODE_MACROS
# ifdef UNICODE
# ifndef _TCHAR_DEFINED
typedef WCHAR           TCHAR,      *PTCHAR;
# define _TCHAR_DEFINED
#endif
typedef LPWCH           PTCH,        LPTCH;
typedef LPCWCH          PCTCH,       LPCTCH;
typedef LPWSTR          PTSTR,       LPTSTR;
typedef LPCWSTR         PCTSTR,      LPCTSTR;
typedef LPWSTR          PUTSTR,      LPUTSTR;
typedef LPCWSTR         PCUTSTR,     LPCUTSTR;
typedef PNZWCH          PNZTCH;
typedef PUNZWCH         PUNZTCH;
typedef PCNZWCH         PCNZTCH;
typedef PCUNZWCH        PCUNZTCH;
typedef PZZWSTR         PZZTSTR;
typedef PCZZWSTR        PCZZTSTR;
typedef PUZZWSTR        PUZZTSTR;
typedef PCUZZWSTR       PCUZZTSTR;
# else  /* UNICODE */
# ifndef _TCHAR_DEFINED
typedef CHAR            TCHAR,      *PTCHAR;
# define _TCHAR_DEFINED
# endif
typedef LPCH            PTCH,        LPTCH;
typedef LPCCH           PCTCH,       LPCTCH;
typedef LPSTR           PTSTR,       LPTSTR;
typedef LPCSTR          PCTSTR,      LPCTSTR;
typedef PNZCH           PNZTCH,      PUNZTCH;
typedef PCNZCH          PCNZTCH,     PCUNZTCH;
typedef PZZSTR          PZZTSTR,     PUZZTSTR;
typedef PCZZSTR         PCZZTSTR,    PCUZZTSTR;
# endif /* UNICODE */
#endif   /* WINE_NO_UNICODE_MACROS */

/* UCS string types */
typedef UCSCHAR         *PUCSCHAR,  *PUUCSCHAR;
typedef const UCSCHAR   *PCUCSCHAR, *PCUUCSCHAR;
typedef UCSCHAR         *PUCSSTR,   *PUUCSSTR;
typedef const UCSCHAR   *PCUCSSTR,  *PCUUCSSTR;

/* Misc common WIN32 types */
typedef char            CCHAR;
typedef DWORD           LCID,       *PLCID;
typedef WORD            LANGID;
typedef DWORD		EXECUTION_STATE;
#ifndef _HRESULT_DEFINED
#define _HRESULT_DEFINED
typedef LONG            HRESULT;
#endif

/* Handle type */

typedef void *HANDLE;
typedef HANDLE *PHANDLE, *LPHANDLE;

#ifdef STRICT
#define DECLARE_HANDLE(a) typedef struct a##__ { int unused; } *a
#else /*STRICT*/
#define DECLARE_HANDLE(a) typedef HANDLE a
#endif /*STRICT*/

typedef BYTE  FCHAR;
typedef WORD  FSHORT;
typedef DWORD FLONG;

/* Macro to deal with LP64 <=> LLP64 differences in numeric constants with 'l' modifier */
#ifndef __MSABI_LONG
# if defined(_MSC_VER) || defined(__MINGW32__) || defined(__CYGWIN__)
#  define __MSABI_LONG(x)         x ## l
# else
#  define __MSABI_LONG(x)         x
# endif
#endif

/* Defines */

#ifndef WIN32_NO_STATUS

#define STATUS_WAIT_0                    ((DWORD) 0x00000000)
#define STATUS_ABANDONED_WAIT_0          ((DWORD) 0x00000080)
#define STATUS_USER_APC                  ((DWORD) 0x000000C0)
#define STATUS_TIMEOUT                   ((DWORD) 0x00000102)
#define STATUS_PENDING                   ((DWORD) 0x00000103)
#define STATUS_SEGMENT_NOTIFICATION      ((DWORD) 0x40000005)
#define STATUS_GUARD_PAGE_VIOLATION      ((DWORD) 0x80000001)
#define STATUS_DATATYPE_MISALIGNMENT     ((DWORD) 0x80000002)
#define STATUS_BREAKPOINT                ((DWORD) 0x80000003)
#define STATUS_SINGLE_STEP               ((DWORD) 0x80000004)
#define STATUS_ACCESS_VIOLATION          ((DWORD) 0xC0000005)
#define STATUS_IN_PAGE_ERROR             ((DWORD) 0xC0000006)
#define STATUS_INVALID_HANDLE            ((DWORD) 0xC0000008)
#define STATUS_NO_MEMORY                 ((DWORD) 0xC0000017)
#define STATUS_ILLEGAL_INSTRUCTION       ((DWORD) 0xC000001D)
#define STATUS_NONCONTINUABLE_EXCEPTION  ((DWORD) 0xC0000025)
#define STATUS_INVALID_DISPOSITION       ((DWORD) 0xC0000026)
#define STATUS_ARRAY_BOUNDS_EXCEEDED     ((DWORD) 0xC000008C)
#define STATUS_FLOAT_DENORMAL_OPERAND    ((DWORD) 0xC000008D)
#define STATUS_FLOAT_DIVIDE_BY_ZERO      ((DWORD) 0xC000008E)
#define STATUS_FLOAT_INEXACT_RESULT      ((DWORD) 0xC000008F)
#define STATUS_FLOAT_INVALID_OPERATION   ((DWORD) 0xC0000090)
#define STATUS_FLOAT_OVERFLOW            ((DWORD) 0xC0000091)
#define STATUS_FLOAT_STACK_CHECK         ((DWORD) 0xC0000092)
#define STATUS_FLOAT_UNDERFLOW           ((DWORD) 0xC0000093)
#define STATUS_INTEGER_DIVIDE_BY_ZERO    ((DWORD) 0xC0000094)
#define STATUS_INTEGER_OVERFLOW          ((DWORD) 0xC0000095)
#define STATUS_PRIVILEGED_INSTRUCTION    ((DWORD) 0xC0000096)
#define STATUS_STACK_OVERFLOW            ((DWORD) 0xC00000FD)
#define STATUS_CONTROL_C_EXIT            ((DWORD) 0xC000013A)
#define STATUS_FLOAT_MULTIPLE_FAULTS     ((DWORD) 0xC00002B4)
#define STATUS_FLOAT_MULTIPLE_TRAPS      ((DWORD) 0xC00002B5)
#define STATUS_REG_NAT_CONSUMPTION       ((DWORD) 0xC00002C9)
#define STATUS_SXS_EARLY_DEACTIVATION    ((DWORD) 0xC015000F)
#define STATUS_SXS_INVALID_DEACTIVATION  ((DWORD) 0xC0150010)

/* status values for ContinueDebugEvent */
#define DBG_EXCEPTION_HANDLED       ((DWORD) 0x00010001)
#define DBG_CONTINUE                ((DWORD) 0x00010002)
#define DBG_TERMINATE_THREAD        ((DWORD) 0x40010003)
#define DBG_TERMINATE_PROCESS       ((DWORD) 0x40010004)
#define DBG_CONTROL_C               ((DWORD) 0x40010005)
#define DBG_PRINTEXCEPTION_C        ((DWORD) 0x40010006)
#define DBG_RIPEXCEPTION            ((DWORD) 0x40010007)
#define DBG_CONTROL_BREAK           ((DWORD) 0x40010008)
#define DBG_COMMAND_EXCEPTION       ((DWORD) 0x40010009)
#define DBG_EXCEPTION_NOT_HANDLED   ((DWORD) 0x80010001)

#endif /* WIN32_NO_STATUS */

/* Argument 1 passed to the DllEntryProc. */
#define	DLL_PROCESS_DETACH	0	/* detach process (unload library) */
#define	DLL_PROCESS_ATTACH	1	/* attach process (load library) */
#define	DLL_THREAD_ATTACH	2	/* attach new thread */
#define	DLL_THREAD_DETACH	3	/* detach thread */
#ifdef __WINESRC__
#define DLL_WINE_PREATTACH      8       /* called before process attach for Wine builtins */
#endif

/* u.x.wProcessorArchitecture (NT) */
#define PROCESSOR_ARCHITECTURE_INTEL	0
#define PROCESSOR_ARCHITECTURE_MIPS	1
#define PROCESSOR_ARCHITECTURE_ALPHA	2
#define PROCESSOR_ARCHITECTURE_PPC	3
#define PROCESSOR_ARCHITECTURE_SHX	4
#define PROCESSOR_ARCHITECTURE_ARM	5
#define PROCESSOR_ARCHITECTURE_IA64     6
#define PROCESSOR_ARCHITECTURE_ALPHA64  7
#define PROCESSOR_ARCHITECTURE_MSIL     8
#define PROCESSOR_ARCHITECTURE_AMD64    9
#define PROCESSOR_ARCHITECTURE_IA32_ON_WIN64    10
#define PROCESSOR_ARCHITECTURE_NEUTRAL          11
#define PROCESSOR_ARCHITECTURE_ARM64            12
#define PROCESSOR_ARCHITECTURE_UNKNOWN	0xFFFF

/* dwProcessorType */
#define PROCESSOR_INTEL_386      386
#define PROCESSOR_INTEL_486      486
#define PROCESSOR_INTEL_PENTIUM  586
#define PROCESSOR_INTEL_860      860
#define PROCESSOR_INTEL_IA64     2200
#define PROCESSOR_AMD_X8664      8664
#define PROCESSOR_MIPS_R2000     2000
#define PROCESSOR_MIPS_R3000     3000
#define PROCESSOR_MIPS_R4000     4000
#define PROCESSOR_ALPHA_21064    21064
#define PROCESSOR_PPC_601        601
#define PROCESSOR_PPC_603        603
#define PROCESSOR_PPC_604        604
#define PROCESSOR_PPC_620        620
#define PROCESSOR_HITACHI_SH3    10003
#define PROCESSOR_HITACHI_SH3E   10004
#define PROCESSOR_HITACHI_SH4    10005
#define PROCESSOR_MOTOROLA_821   821
#define PROCESSOR_SHx_SH3        103
#define PROCESSOR_SHx_SH4        104
#define PROCESSOR_STRONGARM      2577
#define PROCESSOR_ARM720         1824    /* 0x720 */
#define PROCESSOR_ARM820         2080    /* 0x820 */
#define PROCESSOR_ARM920         2336    /* 0x920 */
#define PROCESSOR_ARM_7TDMI      70001
#define PROCESSOR_OPTIL          18767

#ifdef _WIN64
#define MAXIMUM_PROCESSORS       64
#else
#define MAXIMUM_PROCESSORS       32
#endif

typedef struct _MEMORY_BASIC_INFORMATION
{
    LPVOID   BaseAddress;
    LPVOID   AllocationBase;
    DWORD    AllocationProtect;
    SIZE_T   RegionSize;
    DWORD    State;
    DWORD    Protect;
    DWORD    Type;
} MEMORY_BASIC_INFORMATION, *PMEMORY_BASIC_INFORMATION;

#define	PAGE_NOACCESS		0x01
#define	PAGE_READONLY		0x02
#define	PAGE_READWRITE		0x04
#define	PAGE_WRITECOPY		0x08
#define	PAGE_EXECUTE		0x10
#define	PAGE_EXECUTE_READ	0x20
#define	PAGE_EXECUTE_READWRITE	0x40
#define	PAGE_EXECUTE_WRITECOPY	0x80
#define	PAGE_GUARD		0x100
#define	PAGE_NOCACHE		0x200
#define	PAGE_WRITECOMBINE	0x400

#define MEM_COMMIT              0x00001000
#define MEM_RESERVE             0x00002000
#define MEM_DECOMMIT            0x00004000
#define MEM_RELEASE             0x00008000
#define MEM_FREE                0x00010000
#define MEM_PRIVATE             0x00020000
#define MEM_MAPPED              0x00040000
#define MEM_RESET               0x00080000
#define MEM_TOP_DOWN            0x00100000
#define MEM_WRITE_WATCH         0x00200000
#define MEM_PHYSICAL            0x00400000
#define MEM_LARGE_PAGES         0x20000000
#define MEM_4MB_PAGES           0x80000000

#define SEC_FILE                0x00800000
#define SEC_IMAGE               0x01000000
#define SEC_PROTECTED_IMAGE     0x02000000
#define SEC_RESERVE             0x04000000
#define SEC_COMMIT              0x08000000
#define SEC_NOCACHE             0x10000000
#define SEC_WRITECOMBINE        0x40000000
#define SEC_LARGE_PAGES         0x80000000
#define SEC_IMAGE_NO_EXECUTE    (SEC_IMAGE | SEC_NOCACHE)
#define MEM_IMAGE               SEC_IMAGE

#define WRITE_WATCH_FLAG_RESET  0x00000001

#define AT_ROUND_TO_PAGE        0x40000000

#define MINCHAR       0x80
#define MAXCHAR       0x7f
#define MINSHORT      0x8000
#define MAXSHORT      0x7fff
#define MINLONG       0x80000000
#define MAXLONG       0x7fffffff
#define MAXBYTE       0xff
#define MAXWORD       0xffff
#define MAXDWORD      0xffffffff
#define MAXLONGLONG   (((LONGLONG)0x7fffffff << 32) | 0xffffffff)

#define UNICODE_STRING_MAX_CHARS 32767

#define FIELD_OFFSET(type, field) ((LONG)offsetof(type, field))

#define CONTAINING_RECORD(address, type, field) \
  ((type *)((PCHAR)(address) - offsetof(type, field)))

/* Types */

typedef struct _LIST_ENTRY {
  struct _LIST_ENTRY *Flink;
  struct _LIST_ENTRY *Blink;
} LIST_ENTRY, *PLIST_ENTRY, * RESTRICTED_POINTER PRLIST_ENTRY;

typedef struct _SINGLE_LIST_ENTRY {
  struct _SINGLE_LIST_ENTRY *Next;
} SINGLE_LIST_ENTRY, *PSINGLE_LIST_ENTRY;

#ifdef _WIN64

typedef struct DECLSPEC_ALIGN(16) _SLIST_ENTRY *PSLIST_ENTRY;
typedef struct DECLSPEC_ALIGN(16) _SLIST_ENTRY {
    PSLIST_ENTRY Next;
} SLIST_ENTRY;

typedef union DECLSPEC_ALIGN(16) _SLIST_HEADER {
    struct {
        ULONGLONG Alignment;
        ULONGLONG Region;
    } DUMMYSTRUCTNAME;
    struct {
        ULONGLONG Depth:16;
        ULONGLONG Sequence:9;
        ULONGLONG NextEntry:39;
        ULONGLONG HeaderType:1;
        ULONGLONG Init:1;
        ULONGLONG Reserved:59;
        ULONGLONG Region:3;
    } Header8;
    struct {
        ULONGLONG Depth:16;
        ULONGLONG Sequence:48;
        ULONGLONG HeaderType:1;
        ULONGLONG Init:1;
        ULONGLONG Reserved:2;
        ULONGLONG NextEntry:60;
    } Header16;
} SLIST_HEADER, *PSLIST_HEADER;

#else

#undef SLIST_ENTRY /* for Mac OS */
#define SLIST_ENTRY SINGLE_LIST_ENTRY
#define _SLIST_ENTRY _SINGLE_LIST_ENTRY
#define PSLIST_ENTRY PSINGLE_LIST_ENTRY

typedef union _SLIST_HEADER {
    ULONGLONG Alignment;
    struct {
        SLIST_ENTRY Next;
        WORD Depth;
        WORD Sequence;
    } DUMMYSTRUCTNAME;
} SLIST_HEADER, *PSLIST_HEADER;

#endif

NTSYSAPI PSLIST_ENTRY WINAPI RtlFirstEntrySList(const SLIST_HEADER*);
NTSYSAPI VOID         WINAPI RtlInitializeSListHead(PSLIST_HEADER);
NTSYSAPI PSLIST_ENTRY WINAPI RtlInterlockedFlushSList(PSLIST_HEADER);
NTSYSAPI PSLIST_ENTRY WINAPI RtlInterlockedPopEntrySList(PSLIST_HEADER);
NTSYSAPI PSLIST_ENTRY WINAPI RtlInterlockedPushEntrySList(PSLIST_HEADER, PSLIST_ENTRY);
NTSYSAPI WORD         WINAPI RtlQueryDepthSList(PSLIST_HEADER);


/* Heap flags */

#define HEAP_NO_SERIALIZE               0x00000001
#define HEAP_GROWABLE                   0x00000002
#define HEAP_GENERATE_EXCEPTIONS        0x00000004
#define HEAP_ZERO_MEMORY                0x00000008
#define HEAP_REALLOC_IN_PLACE_ONLY      0x00000010
#define HEAP_TAIL_CHECKING_ENABLED      0x00000020
#define HEAP_FREE_CHECKING_ENABLED      0x00000040
#define HEAP_DISABLE_COALESCE_ON_FREE   0x00000080
#define HEAP_CREATE_ALIGN_16            0x00010000
#define HEAP_CREATE_ENABLE_TRACING      0x00020000
#define HEAP_CREATE_ENABLE_EXECUTE      0x00040000

/* This flag allows it to create heaps shared by all processes under win95,
   FIXME: correct name */
#define HEAP_SHARED                     0x04000000

typedef enum _HEAP_INFORMATION_CLASS {
    HeapCompatibilityInformation,
} HEAP_INFORMATION_CLASS;

/* Processor feature flags.  */
#define PF_FLOATING_POINT_PRECISION_ERRATA	0
#define PF_FLOATING_POINT_EMULATED		1
#define PF_COMPARE_EXCHANGE_DOUBLE		2
#define PF_MMX_INSTRUCTIONS_AVAILABLE		3
#define PF_PPC_MOVEMEM_64BIT_OK			4
#define PF_ALPHA_BYTE_INSTRUCTIONS		5
#define PF_XMMI_INSTRUCTIONS_AVAILABLE		6
#define PF_3DNOW_INSTRUCTIONS_AVAILABLE		7
#define PF_RDTSC_INSTRUCTION_AVAILABLE		8
#define PF_PAE_ENABLED				9
#define PF_XMMI64_INSTRUCTIONS_AVAILABLE	10
#define PF_SSE_DAZ_MODE_AVAILABLE		11
#define PF_NX_ENABLED				12
#define PF_SSE3_INSTRUCTIONS_AVAILABLE		13
#define PF_COMPARE_EXCHANGE128			14
#define PF_COMPARE64_EXCHANGE128		15
#define PF_CHANNELS_ENABLED			16
#define PF_XSAVE_ENABLED			17
#define PF_ARM_VFP_32_REGISTERS_AVAILABLE       18
#define PF_ARM_NEON_INSTRUCTIONS_AVAILABLE      19
#define PF_SECOND_LEVEL_ADDRESS_TRANSLATION     20
#define PF_VIRT_FIRMWARE_ENABLED                21
#define PF_RDWRFSGSBASE_AVAILABLE               22
#define PF_FASTFAIL_AVAILABLE                   23
#define PF_ARM_DIVIDE_INSTRUCTION_AVAILABLE     24
#define PF_ARM_64BIT_LOADSTORE_ATOMIC           25
#define PF_ARM_EXTERNAL_CACHE_AVAILABLE         26
#define PF_ARM_FMAC_INSTRUCTIONS_AVAILABLE      27
#define PF_RDRAND_INSTRUCTION_AVAILABLE         28
#define PF_ARM_V8_INSTRUCTIONS_AVAILABLE        29
#define PF_ARM_V8_CRYPTO_INSTRUCTIONS_AVAILABLE 30
#define PF_ARM_V8_CRC32_INSTRUCTIONS_AVAILABLE  31


/* Execution state flags */
#define ES_SYSTEM_REQUIRED    0x00000001
#define ES_DISPLAY_REQUIRED   0x00000002
#define ES_USER_PRESENT       0x00000004
#define ES_CONTINUOUS         0x80000000

/* The Win32 register context */

/* i386 context definitions */
#ifdef __i386__

#define SIZE_OF_80387_REGISTERS      80

typedef struct _FLOATING_SAVE_AREA
{
    DWORD   ControlWord;
    DWORD   StatusWord;
    DWORD   TagWord;
    DWORD   ErrorOffset;
    DWORD   ErrorSelector;
    DWORD   DataOffset;
    DWORD   DataSelector;
    BYTE    RegisterArea[SIZE_OF_80387_REGISTERS];
    DWORD   Cr0NpxState;
} FLOATING_SAVE_AREA, *PFLOATING_SAVE_AREA;

#define MAXIMUM_SUPPORTED_EXTENSION     512

typedef struct _CONTEXT
{
    DWORD   ContextFlags;

    /* These are selected by CONTEXT_DEBUG_REGISTERS */
    DWORD   Dr0;
    DWORD   Dr1;
    DWORD   Dr2;
    DWORD   Dr3;
    DWORD   Dr6;
    DWORD   Dr7;

    /* These are selected by CONTEXT_FLOATING_POINT */
    FLOATING_SAVE_AREA FloatSave;

    /* These are selected by CONTEXT_SEGMENTS */
    DWORD   SegGs;
    DWORD   SegFs;
    DWORD   SegEs;
    DWORD   SegDs;

    /* These are selected by CONTEXT_INTEGER */
    DWORD   Edi;
    DWORD   Esi;
    DWORD   Ebx;
    DWORD   Edx;
    DWORD   Ecx;
    DWORD   Eax;

    /* These are selected by CONTEXT_CONTROL */
    DWORD   Ebp;
    DWORD   Eip;
    DWORD   SegCs;
    DWORD   EFlags;
    DWORD   Esp;
    DWORD   SegSs;

    BYTE    ExtendedRegisters[MAXIMUM_SUPPORTED_EXTENSION];
} CONTEXT;

#define CONTEXT_X86       0x00010000
#define CONTEXT_i386      CONTEXT_X86
#define CONTEXT_i486      CONTEXT_X86

#define CONTEXT_CONTROL   (CONTEXT_i386 | 0x0001) /* SS:SP, CS:IP, FLAGS, BP */
#define CONTEXT_INTEGER   (CONTEXT_i386 | 0x0002) /* AX, BX, CX, DX, SI, DI */
#define CONTEXT_SEGMENTS  (CONTEXT_i386 | 0x0004) /* DS, ES, FS, GS */
#define CONTEXT_FLOATING_POINT  (CONTEXT_i386 | 0x0008) /* 387 state */
#define CONTEXT_DEBUG_REGISTERS (CONTEXT_i386 | 0x0010) /* DB 0-3,6,7 */
#define CONTEXT_EXTENDED_REGISTERS (CONTEXT_i386 | 0x0020)
#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS)
#define CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | \
        CONTEXT_FLOATING_POINT | CONTEXT_DEBUG_REGISTERS | CONTEXT_EXTENDED_REGISTERS)

#define EXCEPTION_READ_FAULT    0
#define EXCEPTION_WRITE_FAULT   1
#define EXCEPTION_EXECUTE_FAULT 8

#endif  /* __i386__ */

typedef struct _LDT_ENTRY {
    WORD	LimitLow;
    WORD	BaseLow;
    union {
        struct {
            BYTE    BaseMid;
            BYTE    Flags1;
            BYTE    Flags2;
            BYTE    BaseHi;
        } Bytes;
        struct {
            unsigned    BaseMid: 8;
            unsigned    Type : 5;
            unsigned    Dpl : 2;
            unsigned    Pres : 1;
            unsigned    LimitHi : 4;
            unsigned    Sys : 1;
            unsigned    Reserved_0 : 1;
            unsigned    Default_Big : 1;
            unsigned    Granularity : 1;
            unsigned    BaseHi : 8;
        } Bits;
    } HighWord;
} LDT_ENTRY, *PLDT_ENTRY;

/* x86-64 context definitions */
#if defined(__x86_64__)

#define CONTEXT_AMD64   0x00100000

#define CONTEXT_CONTROL   (CONTEXT_AMD64 | 0x0001)
#define CONTEXT_INTEGER   (CONTEXT_AMD64 | 0x0002)
#define CONTEXT_SEGMENTS  (CONTEXT_AMD64 | 0x0004)
#define CONTEXT_FLOATING_POINT  (CONTEXT_AMD64 | 0x0008)
#define CONTEXT_DEBUG_REGISTERS (CONTEXT_AMD64 | 0x0010)
#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT)
#define CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_POINT | CONTEXT_DEBUG_REGISTERS)

#define EXCEPTION_READ_FAULT    0
#define EXCEPTION_WRITE_FAULT   1
#define EXCEPTION_EXECUTE_FAULT 8

typedef struct DECLSPEC_ALIGN(16) _M128A {
    ULONGLONG Low;
    LONGLONG High;
} M128A, *PM128A;

typedef struct _XMM_SAVE_AREA32 {
    WORD ControlWord;        /* 000 */
    WORD StatusWord;         /* 002 */
    BYTE TagWord;            /* 004 */
    BYTE Reserved1;          /* 005 */
    WORD ErrorOpcode;        /* 006 */
    DWORD ErrorOffset;       /* 008 */
    WORD ErrorSelector;      /* 00c */
    WORD Reserved2;          /* 00e */
    DWORD DataOffset;        /* 010 */
    WORD DataSelector;       /* 014 */
    WORD Reserved3;          /* 016 */
    DWORD MxCsr;             /* 018 */
    DWORD MxCsr_Mask;        /* 01c */
    M128A FloatRegisters[8]; /* 020 */
    M128A XmmRegisters[16];  /* 0a0 */
    BYTE Reserved4[96];      /* 1a0 */
} XMM_SAVE_AREA32, *PXMM_SAVE_AREA32;

typedef struct DECLSPEC_ALIGN(16) _CONTEXT {
    DWORD64 P1Home;          /* 000 */
    DWORD64 P2Home;          /* 008 */
    DWORD64 P3Home;          /* 010 */
    DWORD64 P4Home;          /* 018 */
    DWORD64 P5Home;          /* 020 */
    DWORD64 P6Home;          /* 028 */

    /* Control flags */
    DWORD ContextFlags;      /* 030 */
    DWORD MxCsr;             /* 034 */

    /* Segment */
    WORD SegCs;              /* 038 */
    WORD SegDs;              /* 03a */
    WORD SegEs;              /* 03c */
    WORD SegFs;              /* 03e */
    WORD SegGs;              /* 040 */
    WORD SegSs;              /* 042 */
    DWORD EFlags;            /* 044 */

    /* Debug */
    DWORD64 Dr0;             /* 048 */
    DWORD64 Dr1;             /* 050 */
    DWORD64 Dr2;             /* 058 */
    DWORD64 Dr3;             /* 060 */
    DWORD64 Dr6;             /* 068 */
    DWORD64 Dr7;             /* 070 */

    /* Integer */
    DWORD64 Rax;             /* 078 */
    DWORD64 Rcx;             /* 080 */
    DWORD64 Rdx;             /* 088 */
    DWORD64 Rbx;             /* 090 */
    DWORD64 Rsp;             /* 098 */
    DWORD64 Rbp;             /* 0a0 */
    DWORD64 Rsi;             /* 0a8 */
    DWORD64 Rdi;             /* 0b0 */
    DWORD64 R8;              /* 0b8 */
    DWORD64 R9;              /* 0c0 */
    DWORD64 R10;             /* 0c8 */
    DWORD64 R11;             /* 0d0 */
    DWORD64 R12;             /* 0d8 */
    DWORD64 R13;             /* 0e0 */
    DWORD64 R14;             /* 0e8 */
    DWORD64 R15;             /* 0f0 */

    /* Counter */
    DWORD64 Rip;             /* 0f8 */

    /* Floating point */
    union {
        XMM_SAVE_AREA32 FltSave;  /* 100 */
        struct {
            M128A Header[2];      /* 100 */
            M128A Legacy[8];      /* 120 */
            M128A Xmm0;           /* 1a0 */
            M128A Xmm1;           /* 1b0 */
            M128A Xmm2;           /* 1c0 */
            M128A Xmm3;           /* 1d0 */
            M128A Xmm4;           /* 1e0 */
            M128A Xmm5;           /* 1f0 */
            M128A Xmm6;           /* 200 */
            M128A Xmm7;           /* 210 */
            M128A Xmm8;           /* 220 */
            M128A Xmm9;           /* 230 */
            M128A Xmm10;          /* 240 */
            M128A Xmm11;          /* 250 */
            M128A Xmm12;          /* 260 */
            M128A Xmm13;          /* 270 */
            M128A Xmm14;          /* 280 */
            M128A Xmm15;          /* 290 */
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;

    /* Vector */
    M128A VectorRegister[26];     /* 300 */
    DWORD64 VectorControl;        /* 4a0 */

    /* Debug control */
    DWORD64 DebugControl;         /* 4a8 */
    DWORD64 LastBranchToRip;      /* 4b0 */
    DWORD64 LastBranchFromRip;    /* 4b8 */
    DWORD64 LastExceptionToRip;   /* 4c0 */
    DWORD64 LastExceptionFromRip; /* 4c8 */
} CONTEXT;

typedef struct _RUNTIME_FUNCTION
{
    DWORD BeginAddress;
    DWORD EndAddress;
    DWORD UnwindData;
} RUNTIME_FUNCTION, *PRUNTIME_FUNCTION;

#define UNWIND_HISTORY_TABLE_SIZE 12

typedef struct _UNWIND_HISTORY_TABLE_ENTRY
{
    ULONG64 ImageBase;
    PRUNTIME_FUNCTION FunctionEntry;
} UNWIND_HISTORY_TABLE_ENTRY, *PUNWIND_HISTORY_TABLE_ENTRY;

#define UNWIND_HISTORY_TABLE_NONE 0
#define UNWIND_HISTORY_TABLE_GLOBAL 1
#define UNWIND_HISTORY_TABLE_LOCAL 2

typedef struct _UNWIND_HISTORY_TABLE
{
    ULONG Count;
    UCHAR Search;
    ULONG64 LowAddress;
    ULONG64 HighAddress;
    UNWIND_HISTORY_TABLE_ENTRY Entry[UNWIND_HISTORY_TABLE_SIZE];
} UNWIND_HISTORY_TABLE, *PUNWIND_HISTORY_TABLE;

typedef struct _KNONVOLATILE_CONTEXT_POINTERS
{
    union
    {
        PM128A FloatingContext[16];
        struct
        {
            PM128A Xmm0;
            PM128A Xmm1;
            PM128A Xmm2;
            PM128A Xmm3;
            PM128A Xmm4;
            PM128A Xmm5;
            PM128A Xmm6;
            PM128A Xmm7;
            PM128A Xmm8;
            PM128A Xmm9;
            PM128A Xmm10;
            PM128A Xmm11;
            PM128A Xmm12;
            PM128A Xmm13;
            PM128A Xmm14;
            PM128A Xmm15;
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;

    union
    {
        PULONG64 IntegerContext[16];
        struct
        {
            PULONG64 Rax;
            PULONG64 Rcx;
            PULONG64 Rdx;
            PULONG64 Rbx;
            PULONG64 Rsp;
            PULONG64 Rbp;
            PULONG64 Rsi;
            PULONG64 Rdi;
            PULONG64 R8;
            PULONG64 R9;
            PULONG64 R10;
            PULONG64 R11;
            PULONG64 R12;
            PULONG64 R13;
            PULONG64 R14;
            PULONG64 R15;
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME2;
} KNONVOLATILE_CONTEXT_POINTERS, *PKNONVOLATILE_CONTEXT_POINTERS;

typedef PRUNTIME_FUNCTION (CALLBACK *PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64,PVOID);

BOOLEAN CDECL            RtlAddFunctionTable(RUNTIME_FUNCTION*,DWORD,DWORD64);
BOOLEAN CDECL            RtlDeleteFunctionTable(RUNTIME_FUNCTION*);
BOOLEAN CDECL            RtlInstallFunctionTableCallback(DWORD64,DWORD64,DWORD,PGET_RUNTIME_FUNCTION_CALLBACK,PVOID,PCWSTR);
PRUNTIME_FUNCTION WINAPI RtlLookupFunctionEntry(DWORD64,DWORD64*,UNWIND_HISTORY_TABLE*);
PVOID WINAPI             RtlVirtualUnwind(ULONG,ULONG64,ULONG64,RUNTIME_FUNCTION*,CONTEXT*,PVOID*,ULONG64*,KNONVOLATILE_CONTEXT_POINTERS*);

#define UNW_FLAG_NHANDLER  0
#define UNW_FLAG_EHANDLER  1
#define UNW_FLAG_UHANDLER  2
#define UNW_FLAG_CHAININFO 4

#endif /* __x86_64__ */

/* IA64 context definitions */
#ifdef __ia64__

#define CONTEXT_IA64                  0x00080000
#define CONTEXT_CONTROL               (CONTEXT_IA64 | 0x00000001)
#define CONTEXT_LOWER_FLOATING_POINT  (CONTEXT_IA64 | 0x00000002)
#define CONTEXT_HIGHER_FLOATING_POINT (CONTEXT_IA64 | 0x00000004)
#define CONTEXT_INTEGER               (CONTEXT_IA64 | 0x00000008)
#define CONTEXT_DEBUG                 (CONTEXT_IA64 | 0x00000010)
#define CONTEXT_IA32_CONTROL          (CONTEXT_IA64 | 0x00000020)
#define CONTEXT_FLOATING_POINT        (CONTEXT_LOWER_FLOATING_POINT | CONTEXT_HIGHER_FLOATING_POINT)
#define CONTEXT_FULL                  (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER | CONTEXT_IA32_CONTROL)
#define CONTEXT_ALL                   (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER | CONTEXT_DEBUG | CONTEXT_IA32_CONTROL)

#define CONTEXT_EXCEPTION_ACTIVE      0x8000000
#define CONTEXT_SERVICE_ACTIVE        0x10000000
#define CONTEXT_EXCEPTION_REQUEST     0x40000000
#define CONTEXT_EXCEPTION_REPORTING   0x80000000

typedef struct _CONTEXT
{
    DWORD ContextFlags;
    DWORD Fill1[3];
    ULONGLONG DbI0;
    ULONGLONG DbI1;
    ULONGLONG DbI2;
    ULONGLONG DbI3;
    ULONGLONG DbI4;
    ULONGLONG DbI5;
    ULONGLONG DbI6;
    ULONGLONG DbI7;
    ULONGLONG DbD0;
    ULONGLONG DbD1;
    ULONGLONG DbD2;
    ULONGLONG DbD3;
    ULONGLONG DbD4;
    ULONGLONG DbD5;
    ULONGLONG DbD6;
    ULONGLONG DbD7;
    FLOAT128 FltS0;
    FLOAT128 FltS1;
    FLOAT128 FltS2;
    FLOAT128 FltS3;
    FLOAT128 FltT0;
    FLOAT128 FltT1;
    FLOAT128 FltT2;
    FLOAT128 FltT3;
    FLOAT128 FltT4;
    FLOAT128 FltT5;
    FLOAT128 FltT6;
    FLOAT128 FltT7;
    FLOAT128 FltT8;
    FLOAT128 FltT9;
    FLOAT128 FltS4;
    FLOAT128 FltS5;
    FLOAT128 FltS6;
    FLOAT128 FltS7;
    FLOAT128 FltS8;
    FLOAT128 FltS9;
    FLOAT128 FltS10;
    FLOAT128 FltS11;
    FLOAT128 FltS12;
    FLOAT128 FltS13;
    FLOAT128 FltS14;
    FLOAT128 FltS15;
    FLOAT128 FltS16;
    FLOAT128 FltS17;
    FLOAT128 FltS18;
    FLOAT128 FltS19;
    FLOAT128 FltF32;
    FLOAT128 FltF33;
    FLOAT128 FltF34;
    FLOAT128 FltF35;
    FLOAT128 FltF36;
    FLOAT128 FltF37;
    FLOAT128 FltF38;
    FLOAT128 FltF39;
    FLOAT128 FltF40;
    FLOAT128 FltF41;
    FLOAT128 FltF42;
    FLOAT128 FltF43;
    FLOAT128 FltF44;
    FLOAT128 FltF45;
    FLOAT128 FltF46;
    FLOAT128 FltF47;
    FLOAT128 FltF48;
    FLOAT128 FltF49;
    FLOAT128 FltF50;
    FLOAT128 FltF51;
    FLOAT128 FltF52;
    FLOAT128 FltF53;
    FLOAT128 FltF54;
    FLOAT128 FltF55;
    FLOAT128 FltF56;
    FLOAT128 FltF57;
    FLOAT128 FltF58;
    FLOAT128 FltF59;
    FLOAT128 FltF60;
    FLOAT128 FltF61;
    FLOAT128 FltF62;
    FLOAT128 FltF63;
    FLOAT128 FltF64;
    FLOAT128 FltF65;
    FLOAT128 FltF66;
    FLOAT128 FltF67;
    FLOAT128 FltF68;
    FLOAT128 FltF69;
    FLOAT128 FltF70;
    FLOAT128 FltF71;
    FLOAT128 FltF72;
    FLOAT128 FltF73;
    FLOAT128 FltF74;
    FLOAT128 FltF75;
    FLOAT128 FltF76;
    FLOAT128 FltF77;
    FLOAT128 FltF78;
    FLOAT128 FltF79;
    FLOAT128 FltF80;
    FLOAT128 FltF81;
    FLOAT128 FltF82;
    FLOAT128 FltF83;
    FLOAT128 FltF84;
    FLOAT128 FltF85;
    FLOAT128 FltF86;
    FLOAT128 FltF87;
    FLOAT128 FltF88;
    FLOAT128 FltF89;
    FLOAT128 FltF90;
    FLOAT128 FltF91;
    FLOAT128 FltF92;
    FLOAT128 FltF93;
    FLOAT128 FltF94;
    FLOAT128 FltF95;
    FLOAT128 FltF96;
    FLOAT128 FltF97;
    FLOAT128 FltF98;
    FLOAT128 FltF99;
    FLOAT128 FltF100;
    FLOAT128 FltF101;
    FLOAT128 FltF102;
    FLOAT128 FltF103;
    FLOAT128 FltF104;
    FLOAT128 FltF105;
    FLOAT128 FltF106;
    FLOAT128 FltF107;
    FLOAT128 FltF108;
    FLOAT128 FltF109;
    FLOAT128 FltF110;
    FLOAT128 FltF111;
    FLOAT128 FltF112;
    FLOAT128 FltF113;
    FLOAT128 FltF114;
    FLOAT128 FltF115;
    FLOAT128 FltF116;
    FLOAT128 FltF117;
    FLOAT128 FltF118;
    FLOAT128 FltF119;
    FLOAT128 FltF120;
    FLOAT128 FltF121;
    FLOAT128 FltF122;
    FLOAT128 FltF123;
    FLOAT128 FltF124;
    FLOAT128 FltF125;
    FLOAT128 FltF126;
    FLOAT128 FltF127;
    ULONGLONG StFPSR;
    ULONGLONG IntGp;
    ULONGLONG IntT0;
    ULONGLONG IntT1;
    ULONGLONG IntS0;
    ULONGLONG IntS1;
    ULONGLONG IntS2;
    ULONGLONG IntS3;
    ULONGLONG IntV0;
    ULONGLONG IntT2;
    ULONGLONG IntT3;
    ULONGLONG IntT4;
    ULONGLONG IntSp;
    ULONGLONG IntTeb;
    ULONGLONG IntT5;
    ULONGLONG IntT6;
    ULONGLONG IntT7;
    ULONGLONG IntT8;
    ULONGLONG IntT9;
    ULONGLONG IntT10;
    ULONGLONG IntT11;
    ULONGLONG IntT12;
    ULONGLONG IntT13;
    ULONGLONG IntT14;
    ULONGLONG IntT15;
    ULONGLONG IntT16;
    ULONGLONG IntT17;
    ULONGLONG IntT18;
    ULONGLONG IntT19;
    ULONGLONG IntT20;
    ULONGLONG IntT21;
    ULONGLONG IntT22;
    ULONGLONG IntNats;
    ULONGLONG Preds;
    ULONGLONG BrRp;
    ULONGLONG BrS0;
    ULONGLONG BrS1;
    ULONGLONG BrS2;
    ULONGLONG BrS3;
    ULONGLONG BrS4;
    ULONGLONG BrT0;
    ULONGLONG BrT1;
    ULONGLONG ApUNAT;
    ULONGLONG ApLC;
    ULONGLONG ApEC;
    ULONGLONG ApCCV;
    ULONGLONG ApDCR;
    ULONGLONG RsPFS;
    ULONGLONG RsBSP;
    ULONGLONG RsBSPSTORE;
    ULONGLONG RsRSC;
    ULONGLONG RsRNAT;
    ULONGLONG StIPSR;
    ULONGLONG StIIP;
    ULONGLONG StIFS;
    ULONGLONG StFCR;
    ULONGLONG Eflag;
    ULONGLONG SegCSD;
    ULONGLONG SegSSD;
    ULONGLONG Cflag;
    ULONGLONG StFSR;
    ULONGLONG StFIR;
    ULONGLONG StFDR;
    ULONGLONG UNUSEDPACK;
} CONTEXT, *PCONTEXT;

typedef struct _RUNTIME_FUNCTION
{
    ULONG BeginAddress;
    ULONG EndAddress;
    ULONG UnwindInfoAddress;
} RUNTIME_FUNCTION, *PRUNTIME_FUNCTION;

typedef struct _FRAME_POINTERS {
  ULONGLONG MemoryStackFp;
  ULONGLONG BackingStoreFp;
} FRAME_POINTERS, *PFRAME_POINTERS;

#define UNWIND_HISTORY_TABLE_SIZE 12

typedef struct _UNWIND_HISTORY_TABLE_ENTRY {
  ULONG64 ImageBase;
  ULONG64 Gp;
  PRUNTIME_FUNCTION FunctionEntry;
} UNWIND_HISTORY_TABLE_ENTRY, *PUNWIND_HISTORY_TABLE_ENTRY;

typedef struct _UNWIND_HISTORY_TABLE {
  ULONG Count;
  UCHAR Search;
  ULONG64 LowAddress;
  ULONG64 HighAddress;
  UNWIND_HISTORY_TABLE_ENTRY Entry[UNWIND_HISTORY_TABLE_SIZE];
} UNWIND_HISTORY_TABLE, *PUNWIND_HISTORY_TABLE;

typedef struct _KNONVOLATILE_CONTEXT_POINTERS
{
    PFLOAT128  FltS0;
    PFLOAT128  FltS1;
    PFLOAT128  FltS2;
    PFLOAT128  FltS3;
    PFLOAT128  HighFloatingContext[10];
    PFLOAT128  FltS4;
    PFLOAT128  FltS5;
    PFLOAT128  FltS6;
    PFLOAT128  FltS7;
    PFLOAT128  FltS8;
    PFLOAT128  FltS9;
    PFLOAT128  FltS10;
    PFLOAT128  FltS11;
    PFLOAT128  FltS12;
    PFLOAT128  FltS13;
    PFLOAT128  FltS14;
    PFLOAT128  FltS15;
    PFLOAT128  FltS16;
    PFLOAT128  FltS17;
    PFLOAT128  FltS18;
    PFLOAT128  FltS19;
    PULONGLONG IntS0;
    PULONGLONG IntS1;
    PULONGLONG IntS2;
    PULONGLONG IntS3;
    PULONGLONG IntSp;
    PULONGLONG IntS0Nat;
    PULONGLONG IntS1Nat;
    PULONGLONG IntS2Nat;
    PULONGLONG IntS3Nat;
    PULONGLONG IntSpNat;
    PULONGLONG Preds;
    PULONGLONG BrRp;
    PULONGLONG BrS0;
    PULONGLONG BrS1;
    PULONGLONG BrS2;
    PULONGLONG BrS3;
    PULONGLONG BrS4;
    PULONGLONG ApUNAT;
    PULONGLONG ApLC;
    PULONGLONG ApEC;
    PULONGLONG RsPFS;
    PULONGLONG StFSR;
    PULONGLONG StFIR;
    PULONGLONG StFDR;
    PULONGLONG Cflag;
} KNONVOLATILE_CONTEXT_POINTERS, *PKNONVOLATILE_CONTEXT_POINTERS;

ULONGLONG WINAPI RtlVirtualUnwind(ULONGLONG,ULONGLONG,RUNTIME_FUNCTION*,CONTEXT*,BOOLEAN*,FRAME_POINTERS*,KNONVOLATILE_CONTEXT_POINTERS*);

#endif /* __ia64__ */

/* Alpha context definitions */
#if defined(_ALPHA_) || defined(__ALPHA__) || defined(__alpha__)

#define CONTEXT_ALPHA   0x00020000

#define CONTEXT_CONTROL         (CONTEXT_ALPHA | 0x00000001)
#define CONTEXT_FLOATING_POINT  (CONTEXT_ALPHA | 0x00000002)
#define CONTEXT_INTEGER         (CONTEXT_ALPHA | 0x00000004)
#define CONTEXT_FULL  (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER)

#define EXCEPTION_READ_FAULT    0
#define EXCEPTION_WRITE_FAULT   1
#define EXCEPTION_EXECUTE_FAULT 8

typedef struct _CONTEXT
{
    /* selected by CONTEXT_FLOATING_POINT */
    ULONGLONG FltF0;
    ULONGLONG FltF1;
    ULONGLONG FltF2;
    ULONGLONG FltF3;
    ULONGLONG FltF4;
    ULONGLONG FltF5;
    ULONGLONG FltF6;
    ULONGLONG FltF7;
    ULONGLONG FltF8;
    ULONGLONG FltF9;
    ULONGLONG FltF10;
    ULONGLONG FltF11;
    ULONGLONG FltF12;
    ULONGLONG FltF13;
    ULONGLONG FltF14;
    ULONGLONG FltF15;
    ULONGLONG FltF16;
    ULONGLONG FltF17;
    ULONGLONG FltF18;
    ULONGLONG FltF19;
    ULONGLONG FltF20;
    ULONGLONG FltF21;
    ULONGLONG FltF22;
    ULONGLONG FltF23;
    ULONGLONG FltF24;
    ULONGLONG FltF25;
    ULONGLONG FltF26;
    ULONGLONG FltF27;
    ULONGLONG FltF28;
    ULONGLONG FltF29;
    ULONGLONG FltF30;
    ULONGLONG FltF31;

    /* selected by CONTEXT_INTEGER */
    ULONGLONG IntV0;
    ULONGLONG IntT0;
    ULONGLONG IntT1;
    ULONGLONG IntT2;
    ULONGLONG IntT3;
    ULONGLONG IntT4;
    ULONGLONG IntT5;
    ULONGLONG IntT6;
    ULONGLONG IntT7;
    ULONGLONG IntS0;
    ULONGLONG IntS1;
    ULONGLONG IntS2;
    ULONGLONG IntS3;
    ULONGLONG IntS4;
    ULONGLONG IntS5;
    ULONGLONG IntFp;
    ULONGLONG IntA0;
    ULONGLONG IntA1;
    ULONGLONG IntA2;
    ULONGLONG IntA3;
    ULONGLONG IntA4;
    ULONGLONG IntA5;
    ULONGLONG IntT8;
    ULONGLONG IntT9;
    ULONGLONG IntT10;
    ULONGLONG IntT11;
    ULONGLONG IntRa;
    ULONGLONG IntT12;
    ULONGLONG IntAt;
    ULONGLONG IntGp;
    ULONGLONG IntSp;
    ULONGLONG IntZero;

    /* selected by CONTEXT_FLOATING_POINT */
    ULONGLONG Fpcr;
    ULONGLONG SoftFpcr;

    /* selected by CONTEXT_CONTROL */
    ULONGLONG Fir;
    DWORD Psr;
    DWORD ContextFlags;
    DWORD Fill[4];
} CONTEXT;

#define _QUAD_PSR_OFFSET   HighSoftFpcr
#define _QUAD_FLAGS_OFFSET HighFir

#endif  /* _ALPHA_ */

#ifdef __arm__

/* The following flags control the contents of the CONTEXT structure. */

#define CONTEXT_ARM    0x0200000
#define CONTEXT_CONTROL         (CONTEXT_ARM | 0x00000001)
#define CONTEXT_INTEGER         (CONTEXT_ARM | 0x00000002)
#define CONTEXT_FLOATING_POINT  (CONTEXT_ARM | 0x00000004)
#define CONTEXT_DEBUG_REGISTERS (CONTEXT_ARM | 0x00000008)

#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER)

#define EXCEPTION_READ_FAULT    0
#define EXCEPTION_WRITE_FAULT   1
#define EXCEPTION_EXECUTE_FAULT 8

typedef struct _RUNTIME_FUNCTION
{
    DWORD BeginAddress;
    union {
        DWORD UnwindData;
        struct {
            DWORD Flag : 2;
            DWORD FunctionLength : 11;
            DWORD Ret : 2;
            DWORD H : 1;
            DWORD Reg : 3;
            DWORD R : 1;
            DWORD L : 1;
            DWORD C : 1;
            DWORD StackAdjust : 10;
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;
} RUNTIME_FUNCTION, *PRUNTIME_FUNCTION;

#define UNWIND_HISTORY_TABLE_SIZE 12

typedef struct _UNWIND_HISTORY_TABLE_ENTRY
{
    DWORD ImageBase;
    PRUNTIME_FUNCTION FunctionEntry;
} UNWIND_HISTORY_TABLE_ENTRY, *PUNWIND_HISTORY_TABLE_ENTRY;

typedef struct _UNWIND_HISTORY_TABLE
{
    DWORD Count;
    BYTE  LocalHint;
    BYTE  GlobalHint;
    BYTE  Search;
    BYTE  Once;
    DWORD LowAddress;
    DWORD HighAddress;
    UNWIND_HISTORY_TABLE_ENTRY Entry[UNWIND_HISTORY_TABLE_SIZE];
} UNWIND_HISTORY_TABLE, *PUNWIND_HISTORY_TABLE;

typedef struct _CONTEXT {
	/* The flags values within this flag control the contents of
	   a CONTEXT record.

	   If the context record is used as an input parameter, then
	   for each portion of the context record controlled by a flag
	   whose value is set, it is assumed that that portion of the
	   context record contains valid context. If the context record
	   is being used to modify a thread's context, then only that
	   portion of the threads context will be modified.

	   If the context record is used as an IN OUT parameter to capture
	   the context of a thread, then only those portions of the thread's
	   context corresponding to set flags will be returned.

	   The context record is never used as an OUT only parameter. */

	ULONG ContextFlags;

	/* This section is specified/returned if the ContextFlags word contains
	   the flag CONTEXT_INTEGER. */
	ULONG R0;
	ULONG R1;
	ULONG R2;
	ULONG R3;
	ULONG R4;
	ULONG R5;
	ULONG R6;
	ULONG R7;
	ULONG R8;
	ULONG R9;
	ULONG R10;
	ULONG Fp;
	ULONG Ip;

	/* These are selected by CONTEXT_CONTROL */
	ULONG Sp;
	ULONG Lr;
	ULONG Pc;
	ULONG Cpsr;
} CONTEXT;

BOOLEAN CDECL            RtlAddFunctionTable(RUNTIME_FUNCTION*,DWORD,DWORD);
BOOLEAN CDECL            RtlDeleteFunctionTable(RUNTIME_FUNCTION*);
PRUNTIME_FUNCTION WINAPI RtlLookupFunctionEntry(ULONG_PTR,DWORD*,UNWIND_HISTORY_TABLE*);

#endif /* __arm__ */

#ifdef __aarch64__
/*
 * FIXME:
 *
 * There is not yet an official CONTEXT structure defined for the AArch64
 * architecture, so I just made one up.
 *
 */

#define CONTEXT_ARM64           0x400000
#define CONTEXT_CONTROL         (CONTEXT_ARM64 | 0x00000001)
#define CONTEXT_INTEGER         (CONTEXT_ARM64 | 0x00000002)
#define CONTEXT_FLOATING_POINT  (CONTEXT_ARM64 | 0x00000004)
#define CONTEXT_DEBUG_REGISTERS (CONTEXT_ARM64 | 0x00000008)

#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER)

#define EXCEPTION_READ_FAULT    0
#define EXCEPTION_WRITE_FAULT   1
#define EXCEPTION_EXECUTE_FAULT 8

typedef struct _RUNTIME_FUNCTION
{
    DWORD BeginAddress;
    union
    {
        DWORD UnwindData;
        struct
        {
            DWORD Flag : 2;
            DWORD FunctionLength : 11;
            DWORD RegF : 3;
            DWORD RegI : 4;
            DWORD H : 1;
            DWORD CR : 2;
            DWORD FrameSize : 9;
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;
} RUNTIME_FUNCTION, *PRUNTIME_FUNCTION;

#define UNWIND_HISTORY_TABLE_SIZE 12

typedef struct _UNWIND_HISTORY_TABLE_ENTRY
{
    DWORD64 ImageBase;
    PRUNTIME_FUNCTION FunctionEntry;
} UNWIND_HISTORY_TABLE_ENTRY, *PUNWIND_HISTORY_TABLE_ENTRY;

typedef struct _UNWIND_HISTORY_TABLE
{
    DWORD   Count;
    BYTE    LocalHint;
    BYTE    GlobalHint;
    BYTE    Search;
    BYTE    Once;
    DWORD64 LowAddress;
    DWORD64 HighAddress;
    UNWIND_HISTORY_TABLE_ENTRY Entry[UNWIND_HISTORY_TABLE_SIZE];
} UNWIND_HISTORY_TABLE, *PUNWIND_HISTORY_TABLE;

typedef struct _CONTEXT {
    ULONG ContextFlags;
    ULONG Cpsr;

    /* This section is specified/returned if the ContextFlags word contains
       the flag CONTEXT_INTEGER. */
    ULONGLONG X0;
    ULONGLONG X1;
    ULONGLONG X2;
    ULONGLONG X3;
    ULONGLONG X4;
    ULONGLONG X5;
    ULONGLONG X6;
    ULONGLONG X7;
    ULONGLONG X8;
    ULONGLONG X9;
    ULONGLONG X10;
    ULONGLONG X11;
    ULONGLONG X12;
    ULONGLONG X13;
    ULONGLONG X14;
    ULONGLONG X15;
    ULONGLONG X16;
    ULONGLONG X17;
    ULONGLONG X18;
    ULONGLONG X19;
    ULONGLONG X20;
    ULONGLONG X21;
    ULONGLONG X22;
    ULONGLONG X23;
    ULONGLONG X24;
    ULONGLONG X25;
    ULONGLONG X26;
    ULONGLONG X27;
    ULONGLONG X28;

    /* These are selected by CONTEXT_CONTROL */
    ULONGLONG Fp;
    ULONGLONG Lr;
    ULONGLONG Sp;
    ULONGLONG Pc;

    /* These are selected by CONTEXT_FLOATING_POINT */
    /* FIXME */
} CONTEXT;

#endif /* __aarch64__ */


/* Mips context definitions */
#if defined(_MIPS_) || defined(__MIPS__) || defined(__mips__)

#define CONTEXT_R4000   0x00010000

#define CONTEXT_CONTROL         (CONTEXT_R4000 | 0x00000001)
#define CONTEXT_FLOATING_POINT  (CONTEXT_R4000 | 0x00000002)
#define CONTEXT_INTEGER         (CONTEXT_R4000 | 0x00000004)

#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER)

#define EXCEPTION_READ_FAULT    0
#define EXCEPTION_WRITE_FAULT   1
#define EXCEPTION_EXECUTE_FAULT 8

typedef struct _CONTEXT
{
    DWORD Argument[4];
    /* These are selected by CONTEXT_FLOATING_POINT */
    DWORD FltF0;
    DWORD FltF1;
    DWORD FltF2;
    DWORD FltF3;
    DWORD FltF4;
    DWORD FltF5;
    DWORD FltF6;
    DWORD FltF7;
    DWORD FltF8;
    DWORD FltF9;
    DWORD FltF10;
    DWORD FltF11;
    DWORD FltF12;
    DWORD FltF13;
    DWORD FltF14;
    DWORD FltF15;
    DWORD FltF16;
    DWORD FltF17;
    DWORD FltF18;
    DWORD FltF19;
    DWORD FltF20;
    DWORD FltF21;
    DWORD FltF22;
    DWORD FltF23;
    DWORD FltF24;
    DWORD FltF25;
    DWORD FltF26;
    DWORD FltF27;
    DWORD FltF28;
    DWORD FltF29;
    DWORD FltF30;
    DWORD FltF31;

    /* These are selected by CONTEXT_INTEGER */
    DWORD IntZero;
    DWORD IntAt;
    DWORD IntV0;
    DWORD IntV1;
    DWORD IntA0;
    DWORD IntA1;
    DWORD IntA2;
    DWORD IntA3;
    DWORD IntT0;
    DWORD IntT1;
    DWORD IntT2;
    DWORD IntT3;
    DWORD IntT4;
    DWORD IntT5;
    DWORD IntT6;
    DWORD IntT7;
    DWORD IntS0;
    DWORD IntS1;
    DWORD IntS2;
    DWORD IntS3;
    DWORD IntS4;
    DWORD IntS5;
    DWORD IntS6;
    DWORD IntS7;
    DWORD IntT8;
    DWORD IntT9;
    DWORD IntK0;
    DWORD IntK1;
    DWORD IntGp;
    DWORD IntSp;
    DWORD IntS8;
    DWORD IntRa;
    DWORD IntLo;
    DWORD IntHi;

    /* These are selected by CONTEXT_FLOATING_POINT */
    DWORD Fsr;

    /* These are selected by CONTEXT_CONTROL */
    DWORD Fir;
    DWORD Psr;

    DWORD ContextFlags;
    DWORD Fill[2];
} CONTEXT;

#endif  /* _MIPS_ */

/* PowerPC context definitions */
#ifdef __powerpc__

#define CONTEXT_CONTROL         0x0001
#define CONTEXT_FLOATING_POINT  0x0002
#define CONTEXT_INTEGER         0x0004
#define CONTEXT_DEBUG_REGISTERS 0x0008
#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER)

#define EXCEPTION_READ_FAULT    0
#define EXCEPTION_WRITE_FAULT   1
#define EXCEPTION_EXECUTE_FAULT 8

typedef struct
{
    /* These are selected by CONTEXT_FLOATING_POINT */
    double Fpr0;
    double Fpr1;
    double Fpr2;
    double Fpr3;
    double Fpr4;
    double Fpr5;
    double Fpr6;
    double Fpr7;
    double Fpr8;
    double Fpr9;
    double Fpr10;
    double Fpr11;
    double Fpr12;
    double Fpr13;
    double Fpr14;
    double Fpr15;
    double Fpr16;
    double Fpr17;
    double Fpr18;
    double Fpr19;
    double Fpr20;
    double Fpr21;
    double Fpr22;
    double Fpr23;
    double Fpr24;
    double Fpr25;
    double Fpr26;
    double Fpr27;
    double Fpr28;
    double Fpr29;
    double Fpr30;
    double Fpr31;
    double Fpscr;

    /* These are selected by CONTEXT_INTEGER */
    DWORD Gpr0;
    DWORD Gpr1;
    DWORD Gpr2;
    DWORD Gpr3;
    DWORD Gpr4;
    DWORD Gpr5;
    DWORD Gpr6;
    DWORD Gpr7;
    DWORD Gpr8;
    DWORD Gpr9;
    DWORD Gpr10;
    DWORD Gpr11;
    DWORD Gpr12;
    DWORD Gpr13;
    DWORD Gpr14;
    DWORD Gpr15;
    DWORD Gpr16;
    DWORD Gpr17;
    DWORD Gpr18;
    DWORD Gpr19;
    DWORD Gpr20;
    DWORD Gpr21;
    DWORD Gpr22;
    DWORD Gpr23;
    DWORD Gpr24;
    DWORD Gpr25;
    DWORD Gpr26;
    DWORD Gpr27;
    DWORD Gpr28;
    DWORD Gpr29;
    DWORD Gpr30;
    DWORD Gpr31;

    DWORD Cr;
    DWORD Xer;

    /* These are selected by CONTEXT_CONTROL */
    DWORD Msr;
    DWORD Iar; /* Instruction Address Register , aka PC ... */
    DWORD Lr;
    DWORD Ctr;

    DWORD ContextFlags;
    
    DWORD Dar;   /* Fault registers for coredump */
    DWORD Dsisr; 
    DWORD Trap;  /* number of powerpc exception taken */

    /* These are selected by CONTEXT_DEBUG_REGISTERS */
    DWORD Dr0;
    DWORD Dr1;
    DWORD Dr2;
    DWORD Dr3;
    DWORD Dr4;
    DWORD Dr5;
    DWORD Dr6;
    DWORD Dr7;
} CONTEXT;

typedef struct _STACK_FRAME_HEADER
{
    DWORD BackChain;
    DWORD GlueSaved1;
    DWORD GlueSaved2;
    DWORD Reserved1;
    DWORD Spare1;
    DWORD Spare2;

    DWORD Parameter0;
    DWORD Parameter1;
    DWORD Parameter2;
    DWORD Parameter3;
    DWORD Parameter4;
    DWORD Parameter5;
    DWORD Parameter6;
    DWORD Parameter7;
} STACK_FRAME_HEADER,*PSTACK_FRAME_HEADER;

#endif  /* __powerpc__ */

#if !defined(CONTEXT_FULL) && !defined(RC_INVOKED)
#error You need to define a CONTEXT for your CPU
#endif

typedef CONTEXT *PCONTEXT;

NTSYSAPI void WINAPI RtlCaptureContext(CONTEXT*);

/*
 * Product types
 */
#define PRODUCT_UNDEFINED                               0x00000000
#define PRODUCT_ULTIMATE                                0x00000001
#define PRODUCT_HOME_BASIC                              0x00000002
#define PRODUCT_HOME_PREMIUM                            0x00000003
#define PRODUCT_ENTERPRISE                              0x00000004
#define PRODUCT_HOME_BASIC_N                            0x00000005
#define PRODUCT_BUSINESS                                0x00000006
#define PRODUCT_STANDARD_SERVER                         0x00000007
#define PRODUCT_DATACENTER_SERVER                       0x00000008
#define PRODUCT_SMALLBUSINESS_SERVER                    0x00000009
#define PRODUCT_ENTERPRISE_SERVER                       0x0000000A
#define PRODUCT_STARTER                                 0x0000000B
#define PRODUCT_DATACENTER_SERVER_CORE                  0x0000000C
#define PRODUCT_STANDARD_SERVER_CORE                    0x0000000D
#define PRODUCT_ENTERPRISE_SERVER_CORE                  0x0000000E
#define PRODUCT_ENTERPRISE_SERVER_IA64                  0x0000000F
#define PRODUCT_BUSINESS_N                              0x00000010
#define PRODUCT_WEB_SERVER                              0x00000011
#define PRODUCT_CLUSTER_SERVER                          0x00000012
#define PRODUCT_HOME_SERVER                             0x00000013
#define PRODUCT_STORAGE_EXPRESS_SERVER                  0x00000014
#define PRODUCT_STORAGE_STANDARD_SERVER                 0x00000015
#define PRODUCT_STORAGE_WORKGROUP_SERVER                0x00000016
#define PRODUCT_STORAGE_ENTERPRISE_SERVER               0x00000017
#define PRODUCT_SERVER_FOR_SMALLBUSINESS                0x00000018
#define PRODUCT_SMALLBUSINESS_SERVER_PREMIUM            0x00000019
#define PRODUCT_HOME_PREMIUM_N                          0x0000001A
#define PRODUCT_ENTERPRISE_N                            0x0000001B
#define PRODUCT_ULTIMATE_N                              0x0000001C
#define PRODUCT_WEB_SERVER_CORE                         0x0000001D
#define PRODUCT_MEDIUMBUSINESS_SERVER_MANAGEMENT        0x0000001E
#define PRODUCT_MEDIUMBUSINESS_SERVER_SECURITY          0x0000001F
#define PRODUCT_MEDIUMBUSINESS_SERVER_MESSAGING         0x00000020
#define PRODUCT_SERVER_FOUNDATION                       0x00000021
#define PRODUCT_HOME_PREMIUM_SERVER                     0x00000022
#define PRODUCT_SERVER_FOR_SMALLBUSINESS_V              0x00000023
#define PRODUCT_STANDARD_SERVER_V                       0x00000024
#define PRODUCT_DATACENTER_SERVER_V                     0x00000025
#define PRODUCT_SERVER_V                                0x00000025
#define PRODUCT_ENTERPRISE_SERVER_V                     0x00000026
#define PRODUCT_DATACENTER_SERVER_CORE_V                0x00000027
#define PRODUCT_STANDARD_SERVER_CORE_V                  0x00000028
#define PRODUCT_ENTERPRISE_SERVER_CORE_V                0x00000029
#define PRODUCT_HYPERV                                  0x0000002A
#define PRODUCT_STORAGE_EXPRESS_SERVER_CORE             0x0000002B
#define PRODUCT_STORAGE_STANDARD_SERVER_CORE            0x0000002C
#define PRODUCT_STORAGE_WORKGROUP_SERVER_CORE           0x0000002D
#define PRODUCT_STORAGE_ENTERPRISE_SERVER_CORE          0x0000002E
#define PRODUCT_STARTER_N                               0x0000002F
#define PRODUCT_PROFESSIONAL                            0x00000030
#define PRODUCT_PROFESSIONAL_N                          0x00000031
#define PRODUCT_SB_SOLUTION_SERVER                      0x00000032
#define PRODUCT_SERVER_FOR_SB_SOLUTIONS                 0x00000033
#define PRODUCT_STANDARD_SERVER_SOLUTIONS               0x00000034
#define PRODUCT_STANDARD_SERVER_SOLUTIONS_CORE          0x00000035
#define PRODUCT_SB_SOLUTION_SERVER_EM                   0x00000036
#define PRODUCT_SERVER_FOR_SB_SOLUTIONS_EM              0x00000037
#define PRODUCT_SOLUTION_EMBEDDEDSERVER                 0x00000038
#define PRODUCT_SOLUTION_EMBEDDEDSERVER_CORE            0x00000039
#define PRODUCT_PROFESSIONAL_EMBEDDED                   0x0000003A
#define PRODUCT_ESSENTIALBUSINESS_SERVER_MGMT           0x0000003B
#define PRODUCT_ESSENTIALBUSINESS_SERVER_ADDL           0x0000003C
#define PRODUCT_ESSENTIALBUSINESS_SERVER_MGMTSVC        0x0000003D
#define PRODUCT_ESSENTIALBUSINESS_SERVER_ADDLSVC        0x0000003E
#define PRODUCT_SMALLBUSINESS_SERVER_PREMIUM_CORE       0x0000003F
#define PRODUCT_CLUSTER_SERVER_V                        0x00000040
#define PRODUCT_EMBEDDED                                0x00000041
#define PRODUCT_STARTER_E                               0x00000042
#define PRODUCT_HOME_BASIC_E                            0x00000043
#define PRODUCT_HOME_PREMIUM_E                          0x00000044
#define PRODUCT_PROFESSIONAL_E                          0x00000045
#define PRODUCT_ENTERPRISE_E                            0x00000046
#define PRODUCT_ULTIMATE_E                              0x00000047
#define PRODUCT_ENTERPRISE_EVALUATION                   0x00000048
#define PRODUCT_MULTIPOINT_STANDARD_SERVER              0x0000004C
#define PRODUCT_MULTIPOINT_PREMIUM_SERVER               0x0000004D
#define PRODUCT_STANDARD_EVALUATION_SERVER              0x0000004F
#define PRODUCT_DATACENTER_EVALUATION_SERVER            0x00000050
#define PRODUCT_ENTERPRISE_N_EVALUATION                 0x00000054
#define PRODUCT_EMBEDDED_AUTOMOTIVE                     0x00000055
#define PRODUCT_EMBEDDED_INDUSTRY_A                     0x00000056
#define PRODUCT_THINPC                                  0x00000057
#define PRODUCT_EMBEDDED_A                              0x00000058
#define PRODUCT_EMBEDDED_INDUSTRY                       0x00000059
#define PRODUCT_EMBEDDED_E                              0x0000005A
#define PRODUCT_EMBEDDED_INDUSTRY_E                     0x0000005B
#define PRODUCT_EMBEDDED_INDUSTRY_A_E                   0x0000005C
#define PRODUCT_STORAGE_WORKGROUP_EVALUATION_SERVER     0x0000005F
#define PRODUCT_STORAGE_STANDARD_EVALUATION_SERVER      0x00000060
#define PRODUCT_CORE_ARM                                0x00000061
#define PRODUCT_CORE_N                                  0x00000062
#define PRODUCT_CORE_COUNTRYSPECIFIC                    0x00000063
#define PRODUCT_CORE_SINGLELANGUAGE                     0x00000064
#define PRODUCT_CORE_LANGUAGESPECIFIC                   0x00000064
#define PRODUCT_CORE                                    0x00000065
#define PRODUCT_PROFESSIONAL_WMC                        0x00000067
#define PRODUCT_MOBILE_CORE                             0x00000068
#define PRODUCT_EMBEDDED_INDUSTRY_EVAL                  0x00000069
#define PRODUCT_EMBEDDED_INDUSTRY_E_EVAL                0x0000006A
#define PRODUCT_EMBEDDED_EVAL                           0x0000006B
#define PRODUCT_EMBEDDED_E_EVAL                         0x0000006C
#define PRODUCT_NANO_SERVER                             0x0000006D
#define PRODUCT_CLOUD_STORAGE_SERVER                    0x0000006E
#define PRODUCT_CORE_CONNECTED                          0x0000006F
#define PRODUCT_PROFESSIONAL_STUDENT                    0x00000070
#define PRODUCT_CORE_CONNECTED_N                        0x00000071
#define PRODUCT_PROFESSIONAL_STUDENT_N                  0x00000072
#define PRODUCT_CORE_CONNECTED_SINGLELANGUAGE           0x00000073
#define PRODUCT_CORE_CONNECTED_COUNTRYSPECIFIC          0x00000074
#define PRODUCT_CONNECTED_CAR                           0x00000075
#define PRODUCT_INDUSTRY_HANDHELD                       0x00000076
#define PRODUCT_PPI_PRO                                 0x00000077
#define PRODUCT_ARM64_SERVER                            0x00000078
#define PRODUCT_EDUCATION                               0x00000079
#define PRODUCT_EDUCATION_N                             0x0000007A
#define PRODUCT_IOTUAP                                  0x0000007B
#define PRODUCT_CLOUD_HOST_INFRASTRUCTURE_SERVER        0x0000007C
#define PRODUCT_ENTERPRISE_S                            0x0000007D
#define PRODUCT_ENTERPRISE_S_N                          0x0000007E
#define PRODUCT_PROFESSIONAL_S                          0x0000007F
#define PRODUCT_PROFESSIONAL_S_N                        0x00000080
#define PRODUCT_ENTERPRISE_S_EVALUATION                 0x00000081
#define PRODUCT_ENTERPRISE_S_N_EVALUATION               0x00000082
#define PRODUCT_UNLICENSED                              0xABCDABCD


/*
 * Language IDs
 */

#define MAKELCID(l, s)		(MAKELONG(l, s))

#define MAKELANGID(p, s)        ((((WORD)(s))<<10) | (WORD)(p))
#define PRIMARYLANGID(l)        ((WORD)(l) & 0x3ff)
#define SUBLANGID(l)            ((WORD)(l) >> 10)

#define LANGIDFROMLCID(lcid)	((WORD)(lcid))
#define SORTIDFROMLCID(lcid)	((WORD)((((DWORD)(lcid)) >> 16) & 0x0f))

#define LANG_SYSTEM_DEFAULT	(MAKELANGID(LANG_NEUTRAL, SUBLANG_SYS_DEFAULT))
#define LANG_USER_DEFAULT	(MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT))
#define LOCALE_SYSTEM_DEFAULT	(MAKELCID(LANG_SYSTEM_DEFAULT, SORT_DEFAULT))
#define LOCALE_USER_DEFAULT	(MAKELCID(LANG_USER_DEFAULT, SORT_DEFAULT))
#define LOCALE_NEUTRAL		(MAKELCID(MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL),SORT_DEFAULT))
#define LOCALE_INVARIANT	(MAKELCID(MAKELANGID(LANG_INVARIANT,SUBLANG_NEUTRAL),SORT_DEFAULT))
#define LOCALE_CUSTOM_DEFAULT      (MAKELCID(MAKELANGID(LANG_NEUTRAL,SUBLANG_CUSTOM_DEFAULT),SORT_DEFAULT))
#define LOCALE_CUSTOM_UNSPECIFIED  (MAKELCID(MAKELANGID(LANG_NEUTRAL,SUBLANG_CUSTOM_UNSPECIFIED),SORT_DEFAULT))
#define LOCALE_CUSTOM_UI_DEFAULT   (MAKELCID(MAKELANGID(LANG_NEUTRAL,SUBLANG_UI_CUSTOM_DEFAULT),SORT_DEFAULT))
#define LOCALE_NAME_MAX_LENGTH     85


#define UNREFERENCED_PARAMETER(u)	(void)(u)
#define DBG_UNREFERENCED_PARAMETER(u)	(void)(u)
#define DBG_UNREFERENCED_LOCAL_VARIABLE(u) (void)(u)

#include <winnt.rh>


/*
 * Definitions for IsTextUnicode()
 */

#define IS_TEXT_UNICODE_ASCII16		   0x0001
#define IS_TEXT_UNICODE_STATISTICS         0x0002
#define IS_TEXT_UNICODE_CONTROLS           0x0004
#define IS_TEXT_UNICODE_SIGNATURE	   0x0008
#define IS_TEXT_UNICODE_UNICODE_MASK       0x000F
#define IS_TEXT_UNICODE_REVERSE_ASCII16	   0x0010
#define IS_TEXT_UNICODE_REVERSE_STATISTICS 0x0020
#define IS_TEXT_UNICODE_REVERSE_CONTROLS   0x0040
#define IS_TEXT_UNICODE_REVERSE_SIGNATURE  0x0080
#define IS_TEXT_UNICODE_REVERSE_MASK       0x00F0
#define IS_TEXT_UNICODE_ILLEGAL_CHARS	   0x0100
#define IS_TEXT_UNICODE_ODD_LENGTH	   0x0200
#define IS_TEXT_UNICODE_DBCS_LEADBYTE      0x0400
#define IS_TEXT_UNICODE_NOT_UNICODE_MASK   0x0F00
#define IS_TEXT_UNICODE_NULL_BYTES         0x1000
#define IS_TEXT_UNICODE_NOT_ASCII_MASK     0xF000

#define MAXIMUM_WAIT_OBJECTS 64
#define MAXIMUM_SUSPEND_COUNT 127

#define WT_EXECUTEDEFAULT              0x00
#define WT_EXECUTEINIOTHREAD           0x01
#define WT_EXECUTEINUITHREAD           0x02
#define WT_EXECUTEINWAITTHREAD         0x04
#define WT_EXECUTEONLYONCE             0x08
#define WT_EXECUTELONGFUNCTION         0x10
#define WT_EXECUTEINTIMERTHREAD        0x20
#define WT_EXECUTEINPERSISTENTIOTHREAD 0x40
#define WT_EXECUTEINPERSISTENTTHREAD   0x80
#define WT_EXECUTEINLONGTHREAD         0x10
#define WT_EXECUTEDELETEWAIT           0x08
#define WT_TRANSFER_IMPERSONATION      0x0100


#define EXCEPTION_CONTINUABLE        0
#define EXCEPTION_NONCONTINUABLE     0x01

/*
 * The exception record used by Win32 to give additional information
 * about exception to exception handlers.
 */

#define EXCEPTION_MAXIMUM_PARAMETERS 15

typedef struct _EXCEPTION_RECORD
{
    DWORD    ExceptionCode;
    DWORD    ExceptionFlags;
    struct  _EXCEPTION_RECORD *ExceptionRecord;

    PVOID    ExceptionAddress;
    DWORD    NumberParameters;
    ULONG_PTR ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
} EXCEPTION_RECORD, *PEXCEPTION_RECORD;

/*
 * The exception pointers structure passed to exception filters
 * in except() and the UnhandledExceptionFilter().
 */

typedef struct _EXCEPTION_POINTERS
{
  PEXCEPTION_RECORD  ExceptionRecord;
  PCONTEXT           ContextRecord;
} EXCEPTION_POINTERS, *PEXCEPTION_POINTERS;


/*
 * The exception frame, used for registering exception handlers
 * Win32 cares only about this, but compilers generally emit
 * larger exception frames for their own use.
 */

struct _EXCEPTION_REGISTRATION_RECORD;

typedef DWORD (*PEXCEPTION_HANDLER)(PEXCEPTION_RECORD,struct _EXCEPTION_REGISTRATION_RECORD*,
                                    PCONTEXT,struct _EXCEPTION_REGISTRATION_RECORD **);

typedef struct _EXCEPTION_REGISTRATION_RECORD
{
  struct _EXCEPTION_REGISTRATION_RECORD *Prev;
  PEXCEPTION_HANDLER       Handler;
} EXCEPTION_REGISTRATION_RECORD;

/*
 * function pointer to an exception filter
 */

typedef LONG (CALLBACK *PVECTORED_EXCEPTION_HANDLER)(PEXCEPTION_POINTERS ExceptionInfo);

typedef struct _NT_TIB
{
	struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList;
	PVOID StackBase;
	PVOID StackLimit;
	PVOID SubSystemTib;
	union {
          PVOID FiberData;
          DWORD Version;
	} DUMMYUNIONNAME;
	PVOID ArbitraryUserPointer;
	struct _NT_TIB *Self;
} NT_TIB, *PNT_TIB;

struct _TEB;

#if defined(__i386__) && defined(__GNUC__) && ((__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 2)))
static FORCEINLINE struct _TEB * WINAPI NtCurrentTeb(void)
{
    struct _TEB *teb;
    __asm__(".byte 0x64\n\tmovl (0x18),%0" : "=r" (teb));
    return teb;
}
#elif defined(__i386__) && defined(_MSC_VER)
static FORCEINLINE struct _TEB * WINAPI NtCurrentTeb(void)
{
  struct _TEB *teb;
  __asm mov eax, fs:[0x18];
  __asm mov teb, eax;
  return teb;
}
#elif defined(__x86_64__) && defined(__GNUC__)
static FORCEINLINE struct _TEB * WINAPI NtCurrentTeb(void)
{
    struct _TEB *teb;
    __asm__(".byte 0x65\n\tmovq (0x30),%0" : "=r" (teb));
    return teb;
}
#elif defined(__x86_64__) && defined(_MSC_VER)
#pragma intrinsic(__readgsqword)
static FORCEINLINE struct _TEB * WINAPI NtCurrentTeb(void)
{
    return (struct _TEB *)__readgsqword(FIELD_OFFSET(NT_TIB, Self));
}
#else
extern struct _TEB * WINAPI NtCurrentTeb(void);
#endif

#ifdef NONAMELESSUNION
#define GetCurrentFiber()  (((NT_TIB *)NtCurrentTeb())->u.FiberData)
#else
#define GetCurrentFiber()  (((NT_TIB *)NtCurrentTeb())->FiberData)
#endif
#define GetFiberData()     (*(void **)GetCurrentFiber())

#define TLS_MINIMUM_AVAILABLE 64

/*
 * File formats definitions
 */

#include <pshpack2.h>
typedef struct _IMAGE_DOS_HEADER {
    WORD  e_magic;      /* 00: MZ Header signature */
    WORD  e_cblp;       /* 02: Bytes on last page of file */
    WORD  e_cp;         /* 04: Pages in file */
    WORD  e_crlc;       /* 06: Relocations */
    WORD  e_cparhdr;    /* 08: Size of header in paragraphs */
    WORD  e_minalloc;   /* 0a: Minimum extra paragraphs needed */
    WORD  e_maxalloc;   /* 0c: Maximum extra paragraphs needed */
    WORD  e_ss;         /* 0e: Initial (relative) SS value */
    WORD  e_sp;         /* 10: Initial SP value */
    WORD  e_csum;       /* 12: Checksum */
    WORD  e_ip;         /* 14: Initial IP value */
    WORD  e_cs;         /* 16: Initial (relative) CS value */
    WORD  e_lfarlc;     /* 18: File address of relocation table */
    WORD  e_ovno;       /* 1a: Overlay number */
    WORD  e_res[4];     /* 1c: Reserved words */
    WORD  e_oemid;      /* 24: OEM identifier (for e_oeminfo) */
    WORD  e_oeminfo;    /* 26: OEM information; e_oemid specific */
    WORD  e_res2[10];   /* 28: Reserved words */
    DWORD e_lfanew;     /* 3c: Offset to extended header */
} IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;
#include <poppack.h>

#define IMAGE_DOS_SIGNATURE    0x5A4D     /* MZ   */
#define IMAGE_OS2_SIGNATURE    0x454E     /* NE   */
#define IMAGE_OS2_SIGNATURE_LE 0x454C     /* LE   */
#define IMAGE_OS2_SIGNATURE_LX 0x584C     /* LX */
#define IMAGE_VXD_SIGNATURE    0x454C     /* LE   */
#define IMAGE_NT_SIGNATURE     0x00004550 /* PE00 */

/*
 * This is the Windows executable (NE) header.
 * the name IMAGE_OS2_HEADER is misleading, but in the SDK this way.
 */
#include <pshpack2.h>
typedef struct
{
    WORD  ne_magic;             /* 00 NE signature 'NE' */
    BYTE  ne_ver;               /* 02 Linker version number */
    BYTE  ne_rev;               /* 03 Linker revision number */
    WORD  ne_enttab;            /* 04 Offset to entry table relative to NE */
    WORD  ne_cbenttab;          /* 06 Length of entry table in bytes */
    LONG  ne_crc;               /* 08 Checksum */
    WORD  ne_flags;             /* 0c Flags about segments in this file */
    WORD  ne_autodata;          /* 0e Automatic data segment number */
    WORD  ne_heap;              /* 10 Initial size of local heap */
    WORD  ne_stack;             /* 12 Initial size of stack */
    DWORD ne_csip;              /* 14 Initial CS:IP */
    DWORD ne_sssp;              /* 18 Initial SS:SP */
    WORD  ne_cseg;              /* 1c # of entries in segment table */
    WORD  ne_cmod;              /* 1e # of entries in module reference tab. */
    WORD  ne_cbnrestab;         /* 20 Length of nonresident-name table     */
    WORD  ne_segtab;            /* 22 Offset to segment table */
    WORD  ne_rsrctab;           /* 24 Offset to resource table */
    WORD  ne_restab;            /* 26 Offset to resident-name table */
    WORD  ne_modtab;            /* 28 Offset to module reference table */
    WORD  ne_imptab;            /* 2a Offset to imported name table */
    DWORD ne_nrestab;           /* 2c Offset to nonresident-name table */
    WORD  ne_cmovent;           /* 30 # of movable entry points */
    WORD  ne_align;             /* 32 Logical sector alignment shift count */
    WORD  ne_cres;              /* 34 # of resource segments */
    BYTE  ne_exetyp;            /* 36 Flags indicating target OS */
    BYTE  ne_flagsothers;       /* 37 Additional information flags */
    WORD  ne_pretthunks;        /* 38 Offset to return thunks */
    WORD  ne_psegrefbytes;      /* 3a Offset to segment ref. bytes */
    WORD  ne_swaparea;          /* 3c Reserved by Microsoft */
    WORD  ne_expver;            /* 3e Expected Windows version number */
} IMAGE_OS2_HEADER, *PIMAGE_OS2_HEADER;
#include <poppack.h>

#include <pshpack2.h>
typedef struct _IMAGE_VXD_HEADER {
  WORD  e32_magic;
  BYTE  e32_border;
  BYTE  e32_worder;
  DWORD e32_level;
  WORD  e32_cpu;
  WORD  e32_os;
  DWORD e32_ver;
  DWORD e32_mflags;
  DWORD e32_mpages;
  DWORD e32_startobj;
  DWORD e32_eip;
  DWORD e32_stackobj;
  DWORD e32_esp;
  DWORD e32_pagesize;
  DWORD e32_lastpagesize;
  DWORD e32_fixupsize;
  DWORD e32_fixupsum;
  DWORD e32_ldrsize;
  DWORD e32_ldrsum;
  DWORD e32_objtab;
  DWORD e32_objcnt;
  DWORD e32_objmap;
  DWORD e32_itermap;
  DWORD e32_rsrctab;
  DWORD e32_rsrccnt;
  DWORD e32_restab;
  DWORD e32_enttab;
  DWORD e32_dirtab;
  DWORD e32_dircnt;
  DWORD e32_fpagetab;
  DWORD e32_frectab;
  DWORD e32_impmod;
  DWORD e32_impmodcnt;
  DWORD e32_impproc;
  DWORD e32_pagesum;
  DWORD e32_datapage;
  DWORD e32_preload;
  DWORD e32_nrestab;
  DWORD e32_cbnrestab;
  DWORD e32_nressum;
  DWORD e32_autodata;
  DWORD e32_debuginfo;
  DWORD e32_debuglen;
  DWORD e32_instpreload;
  DWORD e32_instdemand;
  DWORD e32_heapsize;
  BYTE  e32_res3[12];
  DWORD e32_winresoff;
  DWORD e32_winreslen;
  WORD  e32_devid;
  WORD  e32_ddkver;
} IMAGE_VXD_HEADER, *PIMAGE_VXD_HEADER;
#include <poppack.h>

/* These defines describe the meanings of the bits in the Characteristics
   field */

#define IMAGE_FILE_RELOCS_STRIPPED	0x0001 /* No relocation info */
#define IMAGE_FILE_EXECUTABLE_IMAGE	0x0002
#define IMAGE_FILE_LINE_NUMS_STRIPPED   0x0004
#define IMAGE_FILE_LOCAL_SYMS_STRIPPED  0x0008
#define IMAGE_FILE_AGGRESIVE_WS_TRIM	0x0010
#define IMAGE_FILE_LARGE_ADDRESS_AWARE	0x0020
#define IMAGE_FILE_16BIT_MACHINE	0x0040
#define IMAGE_FILE_BYTES_REVERSED_LO	0x0080
#define IMAGE_FILE_32BIT_MACHINE	0x0100
#define IMAGE_FILE_DEBUG_STRIPPED	0x0200
#define IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP	0x0400
#define IMAGE_FILE_NET_RUN_FROM_SWAP	0x0800
#define IMAGE_FILE_SYSTEM		0x1000
#define IMAGE_FILE_DLL			0x2000
#define IMAGE_FILE_UP_SYSTEM_ONLY	0x4000
#define IMAGE_FILE_BYTES_REVERSED_HI	0x8000

/* These are the settings of the Machine field. */
#define	IMAGE_FILE_MACHINE_UNKNOWN	0
#define	IMAGE_FILE_MACHINE_I860		0x014d
#define	IMAGE_FILE_MACHINE_I386		0x014c
#define	IMAGE_FILE_MACHINE_R3000	0x0162
#define	IMAGE_FILE_MACHINE_R4000	0x0166
#define	IMAGE_FILE_MACHINE_R10000	0x0168
#define	IMAGE_FILE_MACHINE_WCEMIPSV2	0x0169
#define	IMAGE_FILE_MACHINE_ALPHA	0x0184
#define	IMAGE_FILE_MACHINE_SH3		0x01a2
#define	IMAGE_FILE_MACHINE_SH3DSP	0x01a3
#define	IMAGE_FILE_MACHINE_SH3E		0x01a4
#define	IMAGE_FILE_MACHINE_SH4		0x01a6
#define	IMAGE_FILE_MACHINE_SH5		0x01a8
#define	IMAGE_FILE_MACHINE_ARM		0x01c0
#define	IMAGE_FILE_MACHINE_THUMB	0x01c2
#define	IMAGE_FILE_MACHINE_ARMNT	0x01c4
#define	IMAGE_FILE_MACHINE_ARM64	0xaa64
#define	IMAGE_FILE_MACHINE_AM33		0x01d3
#define	IMAGE_FILE_MACHINE_POWERPC	0x01f0
#define	IMAGE_FILE_MACHINE_POWERPCFP	0x01f1
#define	IMAGE_FILE_MACHINE_IA64		0x0200
#define	IMAGE_FILE_MACHINE_MIPS16	0x0266
#define	IMAGE_FILE_MACHINE_ALPHA64	0x0284
#define	IMAGE_FILE_MACHINE_MIPSFPU	0x0366
#define	IMAGE_FILE_MACHINE_MIPSFPU16	0x0466
#define	IMAGE_FILE_MACHINE_AXP64	IMAGE_FILE_MACHINE_ALPHA64
#define	IMAGE_FILE_MACHINE_TRICORE	0x0520
#define	IMAGE_FILE_MACHINE_CEF		0x0cef
#define	IMAGE_FILE_MACHINE_EBC		0x0ebc
#define	IMAGE_FILE_MACHINE_AMD64	0x8664
#define	IMAGE_FILE_MACHINE_M32R		0x9041
#define	IMAGE_FILE_MACHINE_CEE		0xc0ee

#define	IMAGE_SIZEOF_FILE_HEADER		20
#define IMAGE_SIZEOF_ROM_OPTIONAL_HEADER	56
#define IMAGE_SIZEOF_STD_OPTIONAL_HEADER	28
#define IMAGE_SIZEOF_NT_OPTIONAL32_HEADER 	224
#define IMAGE_SIZEOF_NT_OPTIONAL64_HEADER 	240
#define IMAGE_SIZEOF_SHORT_NAME 		8
#define IMAGE_SIZEOF_SECTION_HEADER 		40
#define IMAGE_SIZEOF_SYMBOL 			18
#define IMAGE_SIZEOF_AUX_SYMBOL 		18
#define IMAGE_SIZEOF_RELOCATION 		10
#define IMAGE_SIZEOF_BASE_RELOCATION 		8
#define IMAGE_SIZEOF_LINENUMBER 		6
#define IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR 	60

/* Possible Magic values */
#define IMAGE_NT_OPTIONAL_HDR32_MAGIC      0x10b
#define IMAGE_NT_OPTIONAL_HDR64_MAGIC      0x20b
#define IMAGE_ROM_OPTIONAL_HDR_MAGIC       0x107

#ifdef _WIN64
#define IMAGE_SIZEOF_NT_OPTIONAL_HEADER IMAGE_SIZEOF_NT_OPTIONAL64_HEADER
#define IMAGE_NT_OPTIONAL_HDR_MAGIC     IMAGE_NT_OPTIONAL_HDR64_MAGIC
#else
#define IMAGE_SIZEOF_NT_OPTIONAL_HEADER IMAGE_SIZEOF_NT_OPTIONAL32_HEADER
#define IMAGE_NT_OPTIONAL_HDR_MAGIC     IMAGE_NT_OPTIONAL_HDR32_MAGIC
#endif

/* These are indexes into the DataDirectory array */
#define IMAGE_FILE_EXPORT_DIRECTORY		0
#define IMAGE_FILE_IMPORT_DIRECTORY		1
#define IMAGE_FILE_RESOURCE_DIRECTORY		2
#define IMAGE_FILE_EXCEPTION_DIRECTORY		3
#define IMAGE_FILE_SECURITY_DIRECTORY		4
#define IMAGE_FILE_BASE_RELOCATION_TABLE	5
#define IMAGE_FILE_DEBUG_DIRECTORY		6
#define IMAGE_FILE_DESCRIPTION_STRING		7
#define IMAGE_FILE_MACHINE_VALUE		8  /* Mips */
#define IMAGE_FILE_THREAD_LOCAL_STORAGE		9
#define IMAGE_FILE_CALLBACK_DIRECTORY		10

/* Directory Entries, indices into the DataDirectory array */

#define	IMAGE_DIRECTORY_ENTRY_EXPORT		0
#define	IMAGE_DIRECTORY_ENTRY_IMPORT		1
#define	IMAGE_DIRECTORY_ENTRY_RESOURCE		2
#define	IMAGE_DIRECTORY_ENTRY_EXCEPTION		3
#define	IMAGE_DIRECTORY_ENTRY_SECURITY		4
#define	IMAGE_DIRECTORY_ENTRY_BASERELOC		5
#define	IMAGE_DIRECTORY_ENTRY_DEBUG		6
#define	IMAGE_DIRECTORY_ENTRY_COPYRIGHT		7
#define	IMAGE_DIRECTORY_ENTRY_GLOBALPTR		8   /* (MIPS GP) */
#define	IMAGE_DIRECTORY_ENTRY_TLS		9
#define	IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG	10
#define	IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT	11
#define	IMAGE_DIRECTORY_ENTRY_IAT		12  /* Import Address Table */
#define	IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT	13
#define	IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR	14

/* Subsystem Values */

#define	IMAGE_SUBSYSTEM_UNKNOWN			0
#define	IMAGE_SUBSYSTEM_NATIVE			1
#define	IMAGE_SUBSYSTEM_WINDOWS_GUI		2	/* Windows GUI subsystem */
#define	IMAGE_SUBSYSTEM_WINDOWS_CUI		3	/* Windows character subsystem */
#define	IMAGE_SUBSYSTEM_OS2_CUI			5
#define	IMAGE_SUBSYSTEM_POSIX_CUI		7
#define	IMAGE_SUBSYSTEM_NATIVE_WINDOWS		8	/* native Win9x driver */
#define	IMAGE_SUBSYSTEM_WINDOWS_CE_GUI		9	/* Windows CE subsystem */
#define	IMAGE_SUBSYSTEM_EFI_APPLICATION		10
#define	IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER	11
#define	IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER	12
#define	IMAGE_SUBSYSTEM_EFI_ROM			13
#define	IMAGE_SUBSYSTEM_XBOX			14
#define	IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION	16

/* DLL Characteristics */
#define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE          0x0040
#define IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY       0x0080
#define IMAGE_DLLCHARACTERISTICS_NX_COMPAT             0x0100
#define IMAGE_DLLCHARACTERISTICS_NO_ISOLATION          0x0200
#define IMAGE_DLLCHARACTERISTICS_NO_SEH                0x0400
#define IMAGE_DLLCHARACTERISTICS_NO_BIND               0x0800
#define IMAGE_DLLCHARACTERISTICS_WDM_DRIVER            0x2000
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

typedef struct _IMAGE_FILE_HEADER {
  WORD  Machine;
  WORD  NumberOfSections;
  DWORD TimeDateStamp;
  DWORD PointerToSymbolTable;
  DWORD NumberOfSymbols;
  WORD  SizeOfOptionalHeader;
  WORD  Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

typedef struct _IMAGE_DATA_DIRECTORY {
  DWORD VirtualAddress;
  DWORD Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

typedef struct _IMAGE_OPTIONAL_HEADER64 {
  WORD  Magic; /* 0x20b */
  BYTE MajorLinkerVersion;
  BYTE MinorLinkerVersion;
  DWORD SizeOfCode;
  DWORD SizeOfInitializedData;
  DWORD SizeOfUninitializedData;
  DWORD AddressOfEntryPoint;
  DWORD BaseOfCode;
  ULONGLONG ImageBase;
  DWORD SectionAlignment;
  DWORD FileAlignment;
  WORD MajorOperatingSystemVersion;
  WORD MinorOperatingSystemVersion;
  WORD MajorImageVersion;
  WORD MinorImageVersion;
  WORD MajorSubsystemVersion;
  WORD MinorSubsystemVersion;
  DWORD Win32VersionValue;
  DWORD SizeOfImage;
  DWORD SizeOfHeaders;
  DWORD CheckSum;
  WORD Subsystem;
  WORD DllCharacteristics;
  ULONGLONG SizeOfStackReserve;
  ULONGLONG SizeOfStackCommit;
  ULONGLONG SizeOfHeapReserve;
  ULONGLONG SizeOfHeapCommit;
  DWORD LoaderFlags;
  DWORD NumberOfRvaAndSizes;
  IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER64, *PIMAGE_OPTIONAL_HEADER64;

typedef struct _IMAGE_NT_HEADERS64 {
  DWORD Signature;
  IMAGE_FILE_HEADER FileHeader;
  IMAGE_OPTIONAL_HEADER64 OptionalHeader;
} IMAGE_NT_HEADERS64, *PIMAGE_NT_HEADERS64;

typedef struct _IMAGE_OPTIONAL_HEADER {

  /* Standard fields */

  WORD  Magic; /* 0x10b or 0x107 */	/* 0x00 */
  BYTE  MajorLinkerVersion;
  BYTE  MinorLinkerVersion;
  DWORD SizeOfCode;
  DWORD SizeOfInitializedData;
  DWORD SizeOfUninitializedData;
  DWORD AddressOfEntryPoint;		/* 0x10 */
  DWORD BaseOfCode;
  DWORD BaseOfData;

  /* NT additional fields */

  DWORD ImageBase;
  DWORD SectionAlignment;		/* 0x20 */
  DWORD FileAlignment;
  WORD  MajorOperatingSystemVersion;
  WORD  MinorOperatingSystemVersion;
  WORD  MajorImageVersion;
  WORD  MinorImageVersion;
  WORD  MajorSubsystemVersion;		/* 0x30 */
  WORD  MinorSubsystemVersion;
  DWORD Win32VersionValue;
  DWORD SizeOfImage;
  DWORD SizeOfHeaders;
  DWORD CheckSum;			/* 0x40 */
  WORD  Subsystem;
  WORD  DllCharacteristics;
  DWORD SizeOfStackReserve;
  DWORD SizeOfStackCommit;
  DWORD SizeOfHeapReserve;		/* 0x50 */
  DWORD SizeOfHeapCommit;
  DWORD LoaderFlags;
  DWORD NumberOfRvaAndSizes;
  IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES]; /* 0x60 */
  /* 0xE0 */
} IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;

typedef struct _IMAGE_NT_HEADERS {
  DWORD Signature; /* "PE"\0\0 */	/* 0x00 */
  IMAGE_FILE_HEADER FileHeader;		/* 0x04 */
  IMAGE_OPTIONAL_HEADER32 OptionalHeader;	/* 0x18 */
} IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;

#ifdef _WIN64
typedef IMAGE_NT_HEADERS64  IMAGE_NT_HEADERS;
typedef PIMAGE_NT_HEADERS64 PIMAGE_NT_HEADERS;
typedef IMAGE_OPTIONAL_HEADER64 IMAGE_OPTIONAL_HEADER;
typedef PIMAGE_OPTIONAL_HEADER64 PIMAGE_OPTIONAL_HEADER;
#else
typedef IMAGE_NT_HEADERS32  IMAGE_NT_HEADERS;
typedef PIMAGE_NT_HEADERS32 PIMAGE_NT_HEADERS;
typedef IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_HEADER;
typedef PIMAGE_OPTIONAL_HEADER32 PIMAGE_OPTIONAL_HEADER;
#endif

#define IMAGE_SIZEOF_SHORT_NAME 8

typedef struct _IMAGE_SECTION_HEADER {
  BYTE  Name[IMAGE_SIZEOF_SHORT_NAME];
  union {
    DWORD PhysicalAddress;
    DWORD VirtualSize;
  } Misc;
  DWORD VirtualAddress;
  DWORD SizeOfRawData;
  DWORD PointerToRawData;
  DWORD PointerToRelocations;
  DWORD PointerToLinenumbers;
  WORD  NumberOfRelocations;
  WORD  NumberOfLinenumbers;
  DWORD Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

#define	IMAGE_SIZEOF_SECTION_HEADER 40

#define IMAGE_FIRST_SECTION(ntheader) \
  ((PIMAGE_SECTION_HEADER)(ULONG_PTR)((const BYTE *)&((const IMAGE_NT_HEADERS *)(ntheader))->OptionalHeader + \
                           ((const IMAGE_NT_HEADERS *)(ntheader))->FileHeader.SizeOfOptionalHeader))

/* These defines are for the Characteristics bitfield. */
/* #define IMAGE_SCN_TYPE_REG			0x00000000 - Reserved */
/* #define IMAGE_SCN_TYPE_DSECT			0x00000001 - Reserved */
/* #define IMAGE_SCN_TYPE_NOLOAD		0x00000002 - Reserved */
/* #define IMAGE_SCN_TYPE_GROUP			0x00000004 - Reserved */
#define IMAGE_SCN_TYPE_NO_PAD			0x00000008 /* Reserved */
/* #define IMAGE_SCN_TYPE_COPY			0x00000010 - Reserved */

#define IMAGE_SCN_CNT_CODE			0x00000020
#define IMAGE_SCN_CNT_INITIALIZED_DATA		0x00000040
#define IMAGE_SCN_CNT_UNINITIALIZED_DATA	0x00000080

#define	IMAGE_SCN_LNK_OTHER			0x00000100
#define	IMAGE_SCN_LNK_INFO			0x00000200
/* #define	IMAGE_SCN_TYPE_OVER		0x00000400 - Reserved */
#define	IMAGE_SCN_LNK_REMOVE			0x00000800
#define	IMAGE_SCN_LNK_COMDAT			0x00001000

/* 						0x00002000 - Reserved */
/* #define IMAGE_SCN_MEM_PROTECTED 		0x00004000 - Obsolete */
#define	IMAGE_SCN_MEM_FARDATA			0x00008000

/* #define IMAGE_SCN_MEM_SYSHEAP		0x00010000 - Obsolete */
#define	IMAGE_SCN_MEM_PURGEABLE			0x00020000
#define	IMAGE_SCN_MEM_16BIT			0x00020000
#define	IMAGE_SCN_MEM_LOCKED			0x00040000
#define	IMAGE_SCN_MEM_PRELOAD			0x00080000

#define	IMAGE_SCN_ALIGN_1BYTES			0x00100000
#define	IMAGE_SCN_ALIGN_2BYTES			0x00200000
#define	IMAGE_SCN_ALIGN_4BYTES			0x00300000
#define	IMAGE_SCN_ALIGN_8BYTES			0x00400000
#define	IMAGE_SCN_ALIGN_16BYTES			0x00500000  /* Default */
#define	IMAGE_SCN_ALIGN_32BYTES			0x00600000
#define	IMAGE_SCN_ALIGN_64BYTES			0x00700000
#define	IMAGE_SCN_ALIGN_128BYTES		0x00800000
#define	IMAGE_SCN_ALIGN_256BYTES		0x00900000
#define	IMAGE_SCN_ALIGN_512BYTES		0x00A00000
#define	IMAGE_SCN_ALIGN_1024BYTES		0x00B00000
#define	IMAGE_SCN_ALIGN_2048BYTES		0x00C00000
#define	IMAGE_SCN_ALIGN_4096BYTES		0x00D00000
#define	IMAGE_SCN_ALIGN_8192BYTES		0x00E00000
/* 						0x00F00000 - Unused */
#define	IMAGE_SCN_ALIGN_MASK			0x00F00000

#define IMAGE_SCN_LNK_NRELOC_OVFL		0x01000000


#define IMAGE_SCN_MEM_DISCARDABLE		0x02000000
#define IMAGE_SCN_MEM_NOT_CACHED		0x04000000
#define IMAGE_SCN_MEM_NOT_PAGED			0x08000000
#define IMAGE_SCN_MEM_SHARED			0x10000000
#define IMAGE_SCN_MEM_EXECUTE			0x20000000
#define IMAGE_SCN_MEM_READ			0x40000000
#define IMAGE_SCN_MEM_WRITE			0x80000000

#include <pshpack2.h>

typedef struct _IMAGE_SYMBOL {
    union {
        BYTE    ShortName[8];
        struct {
            DWORD   Short;
            DWORD   Long;
        } Name;
        DWORD   LongName[2];
    } N;
    DWORD   Value;
    SHORT   SectionNumber;
    WORD    Type;
    BYTE    StorageClass;
    BYTE    NumberOfAuxSymbols;
} IMAGE_SYMBOL;
typedef IMAGE_SYMBOL *PIMAGE_SYMBOL;

#define IMAGE_SIZEOF_SYMBOL 18

typedef struct _IMAGE_LINENUMBER {
    union {
        DWORD   SymbolTableIndex;
        DWORD   VirtualAddress;
    } Type;
    WORD    Linenumber;
} IMAGE_LINENUMBER;
typedef IMAGE_LINENUMBER *PIMAGE_LINENUMBER;

#define IMAGE_SIZEOF_LINENUMBER  6

typedef union _IMAGE_AUX_SYMBOL {
    struct {
        DWORD    TagIndex;
        union {
            struct {
                WORD    Linenumber;
                WORD    Size;
            } LnSz;
           DWORD    TotalSize;
        } Misc;
        union {
            struct {
                DWORD    PointerToLinenumber;
                DWORD    PointerToNextFunction;
            } Function;
            struct {
                WORD     Dimension[4];
            } Array;
        } FcnAry;
        WORD    TvIndex;
    } Sym;
    struct {
        BYTE    Name[IMAGE_SIZEOF_SYMBOL];
    } File;
    struct {
        DWORD   Length;
        WORD    NumberOfRelocations;
        WORD    NumberOfLinenumbers;
        DWORD   CheckSum;
        SHORT   Number;
        BYTE    Selection;
    } Section;
} IMAGE_AUX_SYMBOL;
typedef IMAGE_AUX_SYMBOL *PIMAGE_AUX_SYMBOL;

#define IMAGE_SIZEOF_AUX_SYMBOL 18

#include <poppack.h>

#define IMAGE_SYM_UNDEFINED           (SHORT)0
#define IMAGE_SYM_ABSOLUTE            (SHORT)-1
#define IMAGE_SYM_DEBUG               (SHORT)-2

#define IMAGE_SYM_TYPE_NULL                 0x0000
#define IMAGE_SYM_TYPE_VOID                 0x0001
#define IMAGE_SYM_TYPE_CHAR                 0x0002
#define IMAGE_SYM_TYPE_SHORT                0x0003
#define IMAGE_SYM_TYPE_INT                  0x0004
#define IMAGE_SYM_TYPE_LONG                 0x0005
#define IMAGE_SYM_TYPE_FLOAT                0x0006
#define IMAGE_SYM_TYPE_DOUBLE               0x0007
#define IMAGE_SYM_TYPE_STRUCT               0x0008
#define IMAGE_SYM_TYPE_UNION                0x0009
#define IMAGE_SYM_TYPE_ENUM                 0x000A
#define IMAGE_SYM_TYPE_MOE                  0x000B
#define IMAGE_SYM_TYPE_BYTE                 0x000C
#define IMAGE_SYM_TYPE_WORD                 0x000D
#define IMAGE_SYM_TYPE_UINT                 0x000E
#define IMAGE_SYM_TYPE_DWORD                0x000F
#define IMAGE_SYM_TYPE_PCODE                0x8000

#define IMAGE_SYM_DTYPE_NULL                0
#define IMAGE_SYM_DTYPE_POINTER             1
#define IMAGE_SYM_DTYPE_FUNCTION            2
#define IMAGE_SYM_DTYPE_ARRAY               3

#define IMAGE_SYM_CLASS_END_OF_FUNCTION     (BYTE )-1
#define IMAGE_SYM_CLASS_NULL                0x0000
#define IMAGE_SYM_CLASS_AUTOMATIC           0x0001
#define IMAGE_SYM_CLASS_EXTERNAL            0x0002
#define IMAGE_SYM_CLASS_STATIC              0x0003
#define IMAGE_SYM_CLASS_REGISTER            0x0004
#define IMAGE_SYM_CLASS_EXTERNAL_DEF        0x0005
#define IMAGE_SYM_CLASS_LABEL               0x0006
#define IMAGE_SYM_CLASS_UNDEFINED_LABEL     0x0007
#define IMAGE_SYM_CLASS_MEMBER_OF_STRUCT    0x0008
#define IMAGE_SYM_CLASS_ARGUMENT            0x0009
#define IMAGE_SYM_CLASS_STRUCT_TAG          0x000A
#define IMAGE_SYM_CLASS_MEMBER_OF_UNION     0x000B
#define IMAGE_SYM_CLASS_UNION_TAG           0x000C
#define IMAGE_SYM_CLASS_TYPE_DEFINITION     0x000D
#define IMAGE_SYM_CLASS_UNDEFINED_STATIC    0x000E
#define IMAGE_SYM_CLASS_ENUM_TAG            0x000F
#define IMAGE_SYM_CLASS_MEMBER_OF_ENUM      0x0010
#define IMAGE_SYM_CLASS_REGISTER_PARAM      0x0011
#define IMAGE_SYM_CLASS_BIT_FIELD           0x0012

#define IMAGE_SYM_CLASS_FAR_EXTERNAL        0x0044
#define IMAGE_SYM_CLASS_BLOCK               0x0064
#define IMAGE_SYM_CLASS_FUNCTION            0x0065
#define IMAGE_SYM_CLASS_END_OF_STRUCT       0x0066
#define IMAGE_SYM_CLASS_FILE                0x0067
#define IMAGE_SYM_CLASS_SECTION             0x0068
#define IMAGE_SYM_CLASS_WEAK_EXTERNAL       0x0069

#define N_BTMASK                            0x000F
#define N_TMASK                             0x0030
#define N_TMASK1                            0x00C0
#define N_TMASK2                            0x00F0
#define N_BTSHFT                            4
#define N_TSHIFT                            2

#define BTYPE(x) ((x) & N_BTMASK)

#ifndef ISPTR
#define ISPTR(x) (((x) & N_TMASK) == (IMAGE_SYM_DTYPE_POINTER << N_BTSHFT))
#endif

#ifndef ISFCN
#define ISFCN(x) (((x) & N_TMASK) == (IMAGE_SYM_DTYPE_FUNCTION << N_BTSHFT))
#endif

#ifndef ISARY
#define ISARY(x) (((x) & N_TMASK) == (IMAGE_SYM_DTYPE_ARRAY << N_BTSHFT))
#endif

#ifndef ISTAG
#define ISTAG(x) ((x)==IMAGE_SYM_CLASS_STRUCT_TAG || (x)==IMAGE_SYM_CLASS_UNION_TAG || (x)==IMAGE_SYM_CLASS_ENUM_TAG)
#endif

#ifndef INCREF
#define INCREF(x) ((((x)&~N_BTMASK)<<N_TSHIFT)|(IMAGE_SYM_DTYPE_POINTER<<N_BTSHFT)|((x)&N_BTMASK))
#endif
#ifndef DECREF
#define DECREF(x) ((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
#endif

#define IMAGE_COMDAT_SELECT_NODUPLICATES    1
#define IMAGE_COMDAT_SELECT_ANY             2
#define IMAGE_COMDAT_SELECT_SAME_SIZE       3
#define IMAGE_COMDAT_SELECT_EXACT_MATCH     4
#define IMAGE_COMDAT_SELECT_ASSOCIATIVE     5
#define IMAGE_COMDAT_SELECT_LARGEST         6
#define IMAGE_COMDAT_SELECT_NEWEST          7

#define IMAGE_WEAK_EXTERN_SEARCH_NOLIBRARY  1
#define IMAGE_WEAK_EXTERN_SEARCH_LIBRARY    2
#define IMAGE_WEAK_EXTERN_SEARCH_ALIAS      3

/* Export module directory */

typedef struct _IMAGE_EXPORT_DIRECTORY {
	DWORD	Characteristics;
	DWORD	TimeDateStamp;
	WORD	MajorVersion;
	WORD	MinorVersion;
	DWORD	Name;
	DWORD	Base;
	DWORD	NumberOfFunctions;
	DWORD	NumberOfNames;
	DWORD	AddressOfFunctions;
	DWORD	AddressOfNames;
	DWORD	AddressOfNameOrdinals;
} IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

/* Import name entry */
typedef struct _IMAGE_IMPORT_BY_NAME {
	WORD	Hint;
	BYTE	Name[1];
} IMAGE_IMPORT_BY_NAME,*PIMAGE_IMPORT_BY_NAME;

#include <pshpack8.h>
/* Import thunk */
typedef struct _IMAGE_THUNK_DATA64 {
	union {
		ULONGLONG ForwarderString;
		ULONGLONG Function;
		ULONGLONG Ordinal;
		ULONGLONG AddressOfData;
	} u1;
} IMAGE_THUNK_DATA64,*PIMAGE_THUNK_DATA64;
#include <poppack.h>

typedef struct _IMAGE_THUNK_DATA32 {
	union {
		DWORD ForwarderString;
		DWORD Function;
		DWORD Ordinal;
		DWORD AddressOfData;
	} u1;
} IMAGE_THUNK_DATA32,*PIMAGE_THUNK_DATA32;

/* Import module directory */

typedef struct _IMAGE_IMPORT_DESCRIPTOR {
	union {
		DWORD	Characteristics; /* 0 for terminating null import descriptor  */
		DWORD	OriginalFirstThunk;	/* RVA to original unbound IAT */
	} DUMMYUNIONNAME;
	DWORD	TimeDateStamp;	/* 0 if not bound,
				 * -1 if bound, and real date\time stamp
				 *    in IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT
				 * (new BIND)
				 * otherwise date/time stamp of DLL bound to
				 * (Old BIND)
				 */
	DWORD	ForwarderChain;	/* -1 if no forwarders */
	DWORD	Name;
	/* RVA to IAT (if bound this IAT has actual addresses) */
	DWORD	FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR,*PIMAGE_IMPORT_DESCRIPTOR;

#define IMAGE_ORDINAL_FLAG64             (((ULONGLONG)0x80000000 << 32) | 0x00000000)
#define IMAGE_ORDINAL_FLAG32             0x80000000
#define IMAGE_SNAP_BY_ORDINAL64(ordinal) (((ordinal) & IMAGE_ORDINAL_FLAG64) != 0)
#define IMAGE_SNAP_BY_ORDINAL32(ordinal) (((ordinal) & IMAGE_ORDINAL_FLAG32) != 0)
#define IMAGE_ORDINAL64(ordinal)         ((ordinal) & 0xffff)
#define IMAGE_ORDINAL32(ordinal)         ((ordinal) & 0xffff)

#ifdef _WIN64
#define IMAGE_ORDINAL_FLAG              IMAGE_ORDINAL_FLAG64
#define IMAGE_SNAP_BY_ORDINAL(Ordinal)  IMAGE_SNAP_BY_ORDINAL64(Ordinal)
#define IMAGE_ORDINAL(Ordinal)          IMAGE_ORDINAL64(Ordinal)
typedef IMAGE_THUNK_DATA64              IMAGE_THUNK_DATA;
typedef PIMAGE_THUNK_DATA64             PIMAGE_THUNK_DATA;
#else
#define IMAGE_ORDINAL_FLAG              IMAGE_ORDINAL_FLAG32
#define IMAGE_SNAP_BY_ORDINAL(Ordinal)  IMAGE_SNAP_BY_ORDINAL32(Ordinal)
#define IMAGE_ORDINAL(Ordinal)          IMAGE_ORDINAL32(Ordinal)
typedef IMAGE_THUNK_DATA32              IMAGE_THUNK_DATA;
typedef PIMAGE_THUNK_DATA32             PIMAGE_THUNK_DATA;
#endif

typedef struct _IMAGE_BOUND_IMPORT_DESCRIPTOR
{
    DWORD   TimeDateStamp;
    WORD    OffsetModuleName;
    WORD    NumberOfModuleForwarderRefs;
/* Array of zero or more IMAGE_BOUND_FORWARDER_REF follows */
} IMAGE_BOUND_IMPORT_DESCRIPTOR,  *PIMAGE_BOUND_IMPORT_DESCRIPTOR;

typedef struct _IMAGE_BOUND_FORWARDER_REF
{
    DWORD   TimeDateStamp;
    WORD    OffsetModuleName;
    WORD    Reserved;
} IMAGE_BOUND_FORWARDER_REF, *PIMAGE_BOUND_FORWARDER_REF;

typedef struct _IMAGE_BASE_RELOCATION
{
	DWORD	VirtualAddress;
	DWORD	SizeOfBlock;
	/* WORD	TypeOffset[1]; */
} IMAGE_BASE_RELOCATION,*PIMAGE_BASE_RELOCATION;

#include <pshpack2.h>

typedef struct _IMAGE_RELOCATION
{
    union {
        DWORD   VirtualAddress;
        DWORD   RelocCount;
    } DUMMYUNIONNAME;
    DWORD   SymbolTableIndex;
    WORD    Type;
} IMAGE_RELOCATION, *PIMAGE_RELOCATION;

#include <poppack.h>

#define IMAGE_SIZEOF_RELOCATION 10

typedef struct _IMAGE_DELAYLOAD_DESCRIPTOR
{
    union
    {
        DWORD AllAttributes;
        struct
        {
            DWORD RvaBased:1;
            DWORD ReservedAttributes:31;
        } DUMMYSTRUCTNAME;
    } Attributes;

    DWORD DllNameRVA;
    DWORD ModuleHandleRVA;
    DWORD ImportAddressTableRVA;
    DWORD ImportNameTableRVA;
    DWORD BoundImportAddressTableRVA;
    DWORD UnloadInformationTableRVA;
    DWORD TimeDateStamp;
} IMAGE_DELAYLOAD_DESCRIPTOR, *PIMAGE_DELAYLOAD_DESCRIPTOR;
typedef const IMAGE_DELAYLOAD_DESCRIPTOR *PCIMAGE_DELAYLOAD_DESCRIPTOR;

/* generic relocation types */
#define IMAGE_REL_BASED_ABSOLUTE 		0
#define IMAGE_REL_BASED_HIGH			1
#define IMAGE_REL_BASED_LOW			2
#define IMAGE_REL_BASED_HIGHLOW			3
#define IMAGE_REL_BASED_HIGHADJ			4
#define IMAGE_REL_BASED_MIPS_JMPADDR		5
#define IMAGE_REL_BASED_ARM_MOV32A		5 /* yes, 5 too */
#define IMAGE_REL_BASED_ARM_MOV32		5 /* yes, 5 too */
#define IMAGE_REL_BASED_SECTION			6
#define	IMAGE_REL_BASED_REL			7
#define	IMAGE_REL_BASED_ARM_MOV32T		7 /* yes, 7 too */
#define IMAGE_REL_BASED_THUMB_MOV32		7 /* yes, 7 too */
#define IMAGE_REL_BASED_MIPS_JMPADDR16		9
#define IMAGE_REL_BASED_IA64_IMM64		9 /* yes, 9 too */
#define IMAGE_REL_BASED_DIR64			10
#define IMAGE_REL_BASED_HIGH3ADJ		11

/* I386 relocation types */
#define	IMAGE_REL_I386_ABSOLUTE			0
#define	IMAGE_REL_I386_DIR16			1
#define	IMAGE_REL_I386_REL16			2
#define	IMAGE_REL_I386_DIR32			6
#define	IMAGE_REL_I386_DIR32NB			7
#define	IMAGE_REL_I386_SEG12			9
#define	IMAGE_REL_I386_SECTION			10
#define	IMAGE_REL_I386_SECREL			11
#define	IMAGE_REL_I386_TOKEN			12
#define	IMAGE_REL_I386_SECREL7			13
#define	IMAGE_REL_I386_REL32			20

/* MIPS relocation types */
#define IMAGE_REL_MIPS_ABSOLUTE		0x0000
#define IMAGE_REL_MIPS_REFHALF		0x0001
#define IMAGE_REL_MIPS_REFWORD		0x0002
#define IMAGE_REL_MIPS_JMPADDR		0x0003
#define IMAGE_REL_MIPS_REFHI		0x0004
#define IMAGE_REL_MIPS_REFLO		0x0005
#define IMAGE_REL_MIPS_GPREL		0x0006
#define IMAGE_REL_MIPS_LITERAL		0x0007
#define IMAGE_REL_MIPS_SECTION		0x000A
#define IMAGE_REL_MIPS_SECREL		0x000B
#define IMAGE_REL_MIPS_SECRELLO		0x000C
#define IMAGE_REL_MIPS_SECRELHI		0x000D
#define IMAGE_REL_MIPS_TOKEN		0x000E
#define IMAGE_REL_MIPS_JMPADDR16	0x0010
#define IMAGE_REL_MIPS_REFWORDNB	0x0022
#define IMAGE_REL_MIPS_PAIR		0x0025

/* ALPHA relocation types */
#define IMAGE_REL_ALPHA_ABSOLUTE	0x0000
#define IMAGE_REL_ALPHA_REFLONG		0x0001
#define IMAGE_REL_ALPHA_REFQUAD		0x0002
#define IMAGE_REL_ALPHA_GPREL		0x0003
#define IMAGE_REL_ALPHA_LITERAL		0x0004
#define IMAGE_REL_ALPHA_LITUSE		0x0005
#define IMAGE_REL_ALPHA_GPDISP		0x0006
#define IMAGE_REL_ALPHA_BRADDR		0x0007
#define IMAGE_REL_ALPHA_HINT		0x0008
#define IMAGE_REL_ALPHA_INLINE_REFLONG	0x0009
#define IMAGE_REL_ALPHA_REFHI		0x000A
#define IMAGE_REL_ALPHA_REFLO		0x000B
#define IMAGE_REL_ALPHA_PAIR		0x000C
#define IMAGE_REL_ALPHA_MATCH		0x000D
#define IMAGE_REL_ALPHA_SECTION		0x000E
#define IMAGE_REL_ALPHA_SECREL		0x000F
#define IMAGE_REL_ALPHA_REFLONGNB	0x0010
#define IMAGE_REL_ALPHA_SECRELLO	0x0011
#define IMAGE_REL_ALPHA_SECRELHI	0x0012
#define IMAGE_REL_ALPHA_REFQ3		0x0013
#define IMAGE_REL_ALPHA_REFQ2		0x0014
#define IMAGE_REL_ALPHA_REFQ1		0x0015
#define IMAGE_REL_ALPHA_GPRELLO		0x0016
#define IMAGE_REL_ALPHA_GPRELHI		0x0017

/* PowerPC relocation types */
#define IMAGE_REL_PPC_ABSOLUTE          0x0000
#define IMAGE_REL_PPC_ADDR64            0x0001
#define IMAGE_REL_PPC_ADDR            0x0002
#define IMAGE_REL_PPC_ADDR24            0x0003
#define IMAGE_REL_PPC_ADDR16            0x0004
#define IMAGE_REL_PPC_ADDR14            0x0005
#define IMAGE_REL_PPC_REL24             0x0006
#define IMAGE_REL_PPC_REL14             0x0007
#define IMAGE_REL_PPC_TOCREL16          0x0008
#define IMAGE_REL_PPC_TOCREL14          0x0009
#define IMAGE_REL_PPC_ADDR32NB          0x000A
#define IMAGE_REL_PPC_SECREL            0x000B
#define IMAGE_REL_PPC_SECTION           0x000C
#define IMAGE_REL_PPC_IFGLUE            0x000D
#define IMAGE_REL_PPC_IMGLUE            0x000E
#define IMAGE_REL_PPC_SECREL16          0x000F
#define IMAGE_REL_PPC_REFHI             0x0010
#define IMAGE_REL_PPC_REFLO             0x0011
#define IMAGE_REL_PPC_PAIR              0x0012
#define IMAGE_REL_PPC_SECRELLO          0x0013
#define IMAGE_REL_PPC_SECRELHI          0x0014
#define IMAGE_REL_PPC_GPREL		0x0015
#define IMAGE_REL_PPC_TOKEN             0x0016
#define IMAGE_REL_PPC_TYPEMASK          0x00FF
/* modifier bits */
#define IMAGE_REL_PPC_NEG               0x0100
#define IMAGE_REL_PPC_BRTAKEN           0x0200
#define IMAGE_REL_PPC_BRNTAKEN          0x0400
#define IMAGE_REL_PPC_TOCDEFN           0x0800

/* SH3 relocation types */
#define IMAGE_REL_SH3_ABSOLUTE          0x0000
#define IMAGE_REL_SH3_DIRECT16          0x0001
#define IMAGE_REL_SH3_DIRECT          0x0002
#define IMAGE_REL_SH3_DIRECT8           0x0003
#define IMAGE_REL_SH3_DIRECT8_WORD      0x0004
#define IMAGE_REL_SH3_DIRECT8_LONG      0x0005
#define IMAGE_REL_SH3_DIRECT4           0x0006
#define IMAGE_REL_SH3_DIRECT4_WORD      0x0007
#define IMAGE_REL_SH3_DIRECT4_LONG      0x0008
#define IMAGE_REL_SH3_PCREL8_WORD       0x0009
#define IMAGE_REL_SH3_PCREL8_LONG       0x000A
#define IMAGE_REL_SH3_PCREL12_WORD      0x000B
#define IMAGE_REL_SH3_STARTOF_SECTION   0x000C
#define IMAGE_REL_SH3_SIZEOF_SECTION    0x000D
#define IMAGE_REL_SH3_SECTION           0x000E
#define IMAGE_REL_SH3_SECREL            0x000F
#define IMAGE_REL_SH3_DIRECT32_NB       0x0010
#define IMAGE_REL_SH3_GPREL4_LONG       0x0011
#define IMAGE_REL_SH3_TOKEN             0x0012

/* ARM relocation types */
#define IMAGE_REL_ARM_ABSOLUTE		0x0000
#define IMAGE_REL_ARM_ADDR		0x0001
#define IMAGE_REL_ARM_ADDR32NB		0x0002
#define IMAGE_REL_ARM_BRANCH24		0x0003
#define IMAGE_REL_ARM_BRANCH11		0x0004
#define IMAGE_REL_ARM_TOKEN		0x0005
#define IMAGE_REL_ARM_GPREL12		0x0006
#define IMAGE_REL_ARM_GPREL7		0x0007
#define IMAGE_REL_ARM_BLX24		0x0008
#define IMAGE_REL_ARM_BLX11		0x0009
#define IMAGE_REL_ARM_SECTION		0x000E
#define IMAGE_REL_ARM_SECREL		0x000F
#define IMAGE_REL_ARM_MOV32A		0x0010
#define IMAGE_REL_ARM_MOV32T		0x0011
#define IMAGE_REL_ARM_BRANCH20T	0x0012
#define IMAGE_REL_ARM_BRANCH24T	0x0014
#define IMAGE_REL_ARM_BLX23T		0x0015

/* ARM64 relocation types */
#define IMAGE_REL_ARM64_ABSOLUTE        0x0000
#define IMAGE_REL_ARM64_ADDR32          0x0001
#define IMAGE_REL_ARM64_ADDR32NB        0x0002
#define IMAGE_REL_ARM64_BRANCH26        0x0003
#define IMAGE_REL_ARM64_PAGEBASE_REL21  0x0004
#define IMAGE_REL_ARM64_REL21           0x0005
#define IMAGE_REL_ARM64_PAGEOFFSET_12A  0x0006
#define IMAGE_REL_ARM64_PAGEOFFSET_12L  0x0007
#define IMAGE_REL_ARM64_SECREL          0x0008
#define IMAGE_REL_ARM64_SECREL_LOW12A   0x0009
#define IMAGE_REL_ARM64_SECREL_HIGH12A  0x000A
#define IMAGE_REL_ARM64_SECREL_LOW12L   0x000B
#define IMAGE_REL_ARM64_TOKEN           0x000C
#define IMAGE_REL_ARM64_SECTION         0x000D
#define IMAGE_REL_ARM64_ADDR64          0x000E

/* IA64 relocation types */
#define IMAGE_REL_IA64_ABSOLUTE		0x0000
#define IMAGE_REL_IA64_IMM14		0x0001
#define IMAGE_REL_IA64_IMM22		0x0002
#define IMAGE_REL_IA64_IMM64		0x0003
#define IMAGE_REL_IA64_DIR		0x0004
#define IMAGE_REL_IA64_DIR64		0x0005
#define IMAGE_REL_IA64_PCREL21B		0x0006
#define IMAGE_REL_IA64_PCREL21M		0x0007
#define IMAGE_REL_IA64_PCREL21F		0x0008
#define IMAGE_REL_IA64_GPREL22		0x0009
#define IMAGE_REL_IA64_LTOFF22		0x000A
#define IMAGE_REL_IA64_SECTION		0x000B
#define IMAGE_REL_IA64_SECREL22		0x000C
#define IMAGE_REL_IA64_SECREL64I	0x000D
#define IMAGE_REL_IA64_SECREL		0x000E
#define IMAGE_REL_IA64_LTOFF64		0x000F
#define IMAGE_REL_IA64_DIR32NB		0x0010
#define IMAGE_REL_IA64_SREL14		0x0011
#define IMAGE_REL_IA64_SREL22		0x0012
#define IMAGE_REL_IA64_SREL32		0x0013
#define IMAGE_REL_IA64_UREL32		0x0014
#define IMAGE_REL_IA64_PCREL60X	0x0015
#define IMAGE_REL_IA64_PCREL60B	0x0016
#define IMAGE_REL_IA64_PCREL60F	0x0017
#define IMAGE_REL_IA64_PCREL60I	0x0018
#define IMAGE_REL_IA64_PCREL60M	0x0019
#define IMAGE_REL_IA64_IMMGPREL64	0x001A
#define IMAGE_REL_IA64_TOKEN		0x001B
#define IMAGE_REL_IA64_GPREL32		0x001C
#define IMAGE_REL_IA64_ADDEND		0x001F

/* AMD64 relocation types */
#define IMAGE_REL_AMD64_ABSOLUTE        0x0000
#define IMAGE_REL_AMD64_ADDR64          0x0001
#define IMAGE_REL_AMD64_ADDR32          0x0002
#define IMAGE_REL_AMD64_ADDR32NB        0x0003
#define IMAGE_REL_AMD64_REL32           0x0004
#define IMAGE_REL_AMD64_REL32_1         0x0005
#define IMAGE_REL_AMD64_REL32_2         0x0006
#define IMAGE_REL_AMD64_REL32_3         0x0007
#define IMAGE_REL_AMD64_REL32_4         0x0008
#define IMAGE_REL_AMD64_REL32_5         0x0009
#define IMAGE_REL_AMD64_SECTION         0x000A
#define IMAGE_REL_AMD64_SECREL          0x000B
#define IMAGE_REL_AMD64_SECREL7         0x000C
#define IMAGE_REL_AMD64_TOKEN           0x000D
#define IMAGE_REL_AMD64_SREL32          0x000E
#define IMAGE_REL_AMD64_PAIR            0x000F
#define IMAGE_REL_AMD64_SSPAN32         0x0010

/* archive format */

#define IMAGE_ARCHIVE_START_SIZE             8
#define IMAGE_ARCHIVE_START                  "!<arch>\n"
#define IMAGE_ARCHIVE_END                    "`\n"
#define IMAGE_ARCHIVE_PAD                    "\n"
#define IMAGE_ARCHIVE_LINKER_MEMBER          "/               "
#define IMAGE_ARCHIVE_LONGNAMES_MEMBER       "//              "

typedef struct _IMAGE_ARCHIVE_MEMBER_HEADER
{
    BYTE     Name[16];
    BYTE     Date[12];
    BYTE     UserID[6];
    BYTE     GroupID[6];
    BYTE     Mode[8];
    BYTE     Size[10];
    BYTE     EndHeader[2];
} IMAGE_ARCHIVE_MEMBER_HEADER, *PIMAGE_ARCHIVE_MEMBER_HEADER;

#define IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR 60

typedef struct _IMPORT_OBJECT_HEADER
{
    WORD     Sig1;
    WORD     Sig2;
    WORD     Version;
    WORD     Machine;
    DWORD    TimeDateStamp;
    DWORD    SizeOfData;
    union
    {
        WORD Ordinal;
        WORD Hint;
    } DUMMYUNIONNAME;
    WORD     Type : 2;
    WORD     NameType : 3;
    WORD     Reserved : 11;
} IMPORT_OBJECT_HEADER;

#define IMPORT_OBJECT_HDR_SIG2  0xffff

typedef enum IMPORT_OBJECT_TYPE
{
    IMPORT_OBJECT_CODE = 0,
    IMPORT_OBJECT_DATA = 1,
    IMPORT_OBJECT_CONST = 2
} IMPORT_OBJECT_TYPE;

typedef enum IMPORT_OBJECT_NAME_TYPE
{
    IMPORT_OBJECT_ORDINAL = 0,
    IMPORT_OBJECT_NAME = 1,
    IMPORT_OBJECT_NAME_NO_PREFIX = 2,
    IMPORT_OBJECT_NAME_UNDECORATE = 3
} IMPORT_OBJECT_NAME_TYPE;

typedef struct _ANON_OBJECT_HEADER
{
    WORD     Sig1;
    WORD     Sig2;
    WORD     Version;
    WORD     Machine;
    DWORD    TimeDateStamp;
    CLSID    ClassID;
    DWORD    SizeOfData;
} ANON_OBJECT_HEADER;

/*
 * Resource directory stuff
 */
typedef struct _IMAGE_RESOURCE_DIRECTORY {
	DWORD	Characteristics;
	DWORD	TimeDateStamp;
	WORD	MajorVersion;
	WORD	MinorVersion;
	WORD	NumberOfNamedEntries;
	WORD	NumberOfIdEntries;
	/*  IMAGE_RESOURCE_DIRECTORY_ENTRY DirectoryEntries[]; */
} IMAGE_RESOURCE_DIRECTORY,*PIMAGE_RESOURCE_DIRECTORY;

#define	IMAGE_RESOURCE_NAME_IS_STRING		0x80000000
#define	IMAGE_RESOURCE_DATA_IS_DIRECTORY	0x80000000

typedef struct _IMAGE_RESOURCE_DIRECTORY_ENTRY {
	union {
		struct {
#ifdef BITFIELDS_BIGENDIAN
			unsigned NameIsString:1;
			unsigned NameOffset:31;
#else
			unsigned NameOffset:31;
			unsigned NameIsString:1;
#endif
		} DUMMYSTRUCTNAME;
		DWORD   Name;
#ifdef WORDS_BIGENDIAN
		WORD    __pad;
		WORD    Id;
#else
		WORD    Id;
		WORD    __pad;
#endif
	} DUMMYUNIONNAME;
	union {
		DWORD   OffsetToData;
		struct {
#ifdef BITFIELDS_BIGENDIAN
			unsigned DataIsDirectory:1;
			unsigned OffsetToDirectory:31;
#else
			unsigned OffsetToDirectory:31;
			unsigned DataIsDirectory:1;
#endif
		} DUMMYSTRUCTNAME2;
	} DUMMYUNIONNAME2;
} IMAGE_RESOURCE_DIRECTORY_ENTRY,*PIMAGE_RESOURCE_DIRECTORY_ENTRY;


typedef struct _IMAGE_RESOURCE_DIRECTORY_STRING {
	WORD	Length;
	CHAR	NameString[ 1 ];
} IMAGE_RESOURCE_DIRECTORY_STRING,*PIMAGE_RESOURCE_DIRECTORY_STRING;

typedef struct _IMAGE_RESOURCE_DIR_STRING_U {
	WORD	Length;
	WCHAR	NameString[ 1 ];
} IMAGE_RESOURCE_DIR_STRING_U,*PIMAGE_RESOURCE_DIR_STRING_U;

typedef struct _IMAGE_RESOURCE_DATA_ENTRY {
	DWORD	OffsetToData;
	DWORD	Size;
	DWORD	CodePage;
	DWORD	Reserved;
} IMAGE_RESOURCE_DATA_ENTRY,*PIMAGE_RESOURCE_DATA_ENTRY;


typedef VOID (CALLBACK *PIMAGE_TLS_CALLBACK)(
	LPVOID DllHandle,DWORD Reason,LPVOID Reserved
);

typedef struct _IMAGE_TLS_DIRECTORY64 {
    ULONGLONG   StartAddressOfRawData;
    ULONGLONG   EndAddressOfRawData;
    ULONGLONG   AddressOfIndex;
    ULONGLONG   AddressOfCallBacks;
    DWORD       SizeOfZeroFill;
    DWORD       Characteristics;
} IMAGE_TLS_DIRECTORY64, *PIMAGE_TLS_DIRECTORY64;

typedef struct _IMAGE_TLS_DIRECTORY32 {
    DWORD   StartAddressOfRawData;
    DWORD   EndAddressOfRawData;
    DWORD   AddressOfIndex;
    DWORD   AddressOfCallBacks;
    DWORD   SizeOfZeroFill;
    DWORD   Characteristics;
} IMAGE_TLS_DIRECTORY32, *PIMAGE_TLS_DIRECTORY32;

#ifdef _WIN64
typedef IMAGE_TLS_DIRECTORY64           IMAGE_TLS_DIRECTORY;
typedef PIMAGE_TLS_DIRECTORY64          PIMAGE_TLS_DIRECTORY;
#else
typedef IMAGE_TLS_DIRECTORY32           IMAGE_TLS_DIRECTORY;
typedef PIMAGE_TLS_DIRECTORY32          PIMAGE_TLS_DIRECTORY;
#endif

typedef struct _IMAGE_DEBUG_DIRECTORY {
  DWORD Characteristics;
  DWORD TimeDateStamp;
  WORD  MajorVersion;
  WORD  MinorVersion;
  DWORD Type;
  DWORD SizeOfData;
  DWORD AddressOfRawData;
  DWORD PointerToRawData;
} IMAGE_DEBUG_DIRECTORY, *PIMAGE_DEBUG_DIRECTORY;

#define IMAGE_DEBUG_TYPE_UNKNOWN        0
#define IMAGE_DEBUG_TYPE_COFF           1
#define IMAGE_DEBUG_TYPE_CODEVIEW       2
#define IMAGE_DEBUG_TYPE_FPO            3
#define IMAGE_DEBUG_TYPE_MISC           4
#define IMAGE_DEBUG_TYPE_EXCEPTION      5
#define IMAGE_DEBUG_TYPE_FIXUP          6
#define IMAGE_DEBUG_TYPE_OMAP_TO_SRC    7
#define IMAGE_DEBUG_TYPE_OMAP_FROM_SRC  8
#define IMAGE_DEBUG_TYPE_BORLAND        9
#define IMAGE_DEBUG_TYPE_RESERVED10    10
#define IMAGE_DEBUG_TYPE_CLSID         11
#define IMAGE_DEBUG_TYPE_VC_FEATURE    12
#define IMAGE_DEBUG_TYPE_POGO          13
#define IMAGE_DEBUG_TYPE_ILTCG         14
#define IMAGE_DEBUG_TYPE_MPX           15

typedef enum ReplacesCorHdrNumericDefines
{
    COMIMAGE_FLAGS_ILONLY           = 0x00000001,
    COMIMAGE_FLAGS_32BITREQUIRED    = 0x00000002,
    COMIMAGE_FLAGS_IL_LIBRARY       = 0x00000004,
    COMIMAGE_FLAGS_STRONGNAMESIGNED = 0x00000008,
    COMIMAGE_FLAGS_NATIVE_ENTRYPOINT= 0x00000010,
    COMIMAGE_FLAGS_TRACKDEBUGDATA   = 0x00010000,

    COR_VERSION_MAJOR_V2       = 2,
    COR_VERSION_MAJOR          = COR_VERSION_MAJOR_V2,
    COR_VERSION_MINOR          = 0,
    COR_DELETED_NAME_LENGTH    = 8,
    COR_VTABLEGAP_NAME_LENGTH  = 8,

    NATIVE_TYPE_MAX_CB = 1,
    COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE = 0xff,

    IMAGE_COR_MIH_METHODRVA  = 0x01,
    IMAGE_COR_MIH_EHRVA      = 0x02,
    IMAGE_COR_MIH_BASICBLOCK = 0x08,

    COR_VTABLE_32BIT             = 0x01,
    COR_VTABLE_64BIT             = 0x02,
    COR_VTABLE_FROM_UNMANAGED    = 0x04,
    COR_VTABLE_CALL_MOST_DERIVED = 0x10,

    IMAGE_COR_EATJ_THUNK_SIZE = 32,

    MAX_CLASS_NAME   = 1024,
    MAX_PACKAGE_NAME = 1024,
} ReplacesCorHdrNumericDefines;

typedef struct IMAGE_COR20_HEADER
{
    DWORD cb;
    WORD  MajorRuntimeVersion;
    WORD  MinorRuntimeVersion;

    IMAGE_DATA_DIRECTORY MetaData;
    DWORD Flags;
    union {
        DWORD EntryPointToken;
        DWORD EntryPointRVA;
    } DUMMYUNIONNAME;

    IMAGE_DATA_DIRECTORY Resources;
    IMAGE_DATA_DIRECTORY StrongNameSignature;
    IMAGE_DATA_DIRECTORY CodeManagerTable;
    IMAGE_DATA_DIRECTORY VTableFixups;
    IMAGE_DATA_DIRECTORY ExportAddressTableJumps;
    IMAGE_DATA_DIRECTORY ManagedNativeHeader;

} IMAGE_COR20_HEADER, *PIMAGE_COR20_HEADER;

typedef struct _IMAGE_COFF_SYMBOLS_HEADER {
  DWORD NumberOfSymbols;
  DWORD LvaToFirstSymbol;
  DWORD NumberOfLinenumbers;
  DWORD LvaToFirstLinenumber;
  DWORD RvaToFirstByteOfCode;
  DWORD RvaToLastByteOfCode;
  DWORD RvaToFirstByteOfData;
  DWORD RvaToLastByteOfData;
} IMAGE_COFF_SYMBOLS_HEADER, *PIMAGE_COFF_SYMBOLS_HEADER;

#define FRAME_FPO       0
#define FRAME_TRAP      1
#define FRAME_TSS       2
#define FRAME_NONFPO    3

typedef struct _FPO_DATA {
  DWORD ulOffStart;
  DWORD cbProcSize;
  DWORD cdwLocals;
  WORD  cdwParams;
  WORD  cbProlog : 8;
  WORD  cbRegs   : 3;
  WORD  fHasSEH  : 1;
  WORD  fUseBP   : 1;
  WORD  reserved : 1;
  WORD  cbFrame  : 2;
} FPO_DATA, *PFPO_DATA;

typedef struct _IMAGE_LOAD_CONFIG_DIRECTORY64 {
  DWORD     Size;
  DWORD     TimeDateStamp;
  WORD      MajorVersion;
  WORD      MinorVersion;
  DWORD     GlobalFlagsClear;
  DWORD     GlobalFlagsSet;
  DWORD     CriticalSectionDefaultTimeout;
  ULONGLONG DeCommitFreeBlockThreshold;
  ULONGLONG DeCommitTotalFreeThreshold;
  ULONGLONG LockPrefixTable;
  ULONGLONG MaximumAllocationSize;
  ULONGLONG VirtualMemoryThreshold;
  ULONGLONG ProcessAffinityMask;
  DWORD     ProcessHeapFlags;
  WORD      CSDVersion;
  WORD      Reserved1;
  ULONGLONG EditList;
  ULONGLONG SecurityCookie;
  ULONGLONG SEHandlerTable;
  ULONGLONG SEHandlerCount;
} IMAGE_LOAD_CONFIG_DIRECTORY64, *PIMAGE_LOAD_CONFIG_DIRECTORY64;

typedef struct _IMAGE_LOAD_CONFIG_DIRECTORY32 {
  DWORD Size;
  DWORD TimeDateStamp;
  WORD  MajorVersion;
  WORD  MinorVersion;
  DWORD GlobalFlagsClear;
  DWORD GlobalFlagsSet;
  DWORD CriticalSectionDefaultTimeout;
  DWORD DeCommitFreeBlockThreshold;
  DWORD DeCommitTotalFreeThreshold;
  PVOID LockPrefixTable;
  DWORD MaximumAllocationSize;
  DWORD VirtualMemoryThreshold;
  DWORD ProcessHeapFlags;
  DWORD ProcessAffinityMask;
  WORD  CSDVersion;
  WORD  Reserved1;
  PVOID EditList;
  DWORD SecurityCookie;
  DWORD SEHandlerTable;
  DWORD SEHandlerCount;
} IMAGE_LOAD_CONFIG_DIRECTORY32, *PIMAGE_LOAD_CONFIG_DIRECTORY32;

#ifdef _WIN64
typedef IMAGE_LOAD_CONFIG_DIRECTORY64   IMAGE_LOAD_CONFIG_DIRECTORY;
typedef PIMAGE_LOAD_CONFIG_DIRECTORY64  PIMAGE_LOAD_CONFIG_DIRECTORY;
#else
typedef IMAGE_LOAD_CONFIG_DIRECTORY32   IMAGE_LOAD_CONFIG_DIRECTORY;
typedef PIMAGE_LOAD_CONFIG_DIRECTORY32  PIMAGE_LOAD_CONFIG_DIRECTORY;
#endif

typedef struct _IMAGE_FUNCTION_ENTRY {
  DWORD StartingAddress;
  DWORD EndingAddress;
  DWORD EndOfPrologue;
} IMAGE_FUNCTION_ENTRY, *PIMAGE_FUNCTION_ENTRY;

#define IMAGE_DEBUG_MISC_EXENAME    1

typedef struct _IMAGE_DEBUG_MISC {
    DWORD       DataType;
    DWORD       Length;
    BYTE        Unicode;
    BYTE        Reserved[ 3 ];
    BYTE        Data[ 1 ];
} IMAGE_DEBUG_MISC, *PIMAGE_DEBUG_MISC;

/* This is the structure that appears at the very start of a .DBG file. */

typedef struct _IMAGE_SEPARATE_DEBUG_HEADER {
	WORD	Signature;
	WORD	Flags;
	WORD	Machine;
	WORD	Characteristics;
	DWORD	TimeDateStamp;
	DWORD	CheckSum;
	DWORD	ImageBase;
	DWORD	SizeOfImage;
	DWORD	NumberOfSections;
	DWORD	ExportedNamesSize;
	DWORD	DebugDirectorySize;
	DWORD	SectionAlignment;
	DWORD	Reserved[ 2 ];
} IMAGE_SEPARATE_DEBUG_HEADER,*PIMAGE_SEPARATE_DEBUG_HEADER;

#define IMAGE_SEPARATE_DEBUG_SIGNATURE 0x4944


typedef struct tagMESSAGE_RESOURCE_ENTRY {
	WORD	Length;
	WORD	Flags;
	BYTE	Text[1];
} MESSAGE_RESOURCE_ENTRY,*PMESSAGE_RESOURCE_ENTRY;
#define	MESSAGE_RESOURCE_UNICODE	0x0001

typedef struct tagMESSAGE_RESOURCE_BLOCK {
	DWORD	LowId;
	DWORD	HighId;
	DWORD	OffsetToEntries;
} MESSAGE_RESOURCE_BLOCK,*PMESSAGE_RESOURCE_BLOCK;

typedef struct tagMESSAGE_RESOURCE_DATA {
	DWORD			NumberOfBlocks;
	MESSAGE_RESOURCE_BLOCK	Blocks[ 1 ];
} MESSAGE_RESOURCE_DATA,*PMESSAGE_RESOURCE_DATA;

/*
 * Here follows typedefs for security and tokens.
 */

/*
 * First a constant for the following typedefs.
 */

#define ANYSIZE_ARRAY   1

/* FIXME:  Orphan.  What does it point to? */
typedef PVOID PACCESS_TOKEN;
typedef PVOID PSECURITY_DESCRIPTOR;
typedef PVOID PSID;

typedef enum _TOKEN_ELEVATION_TYPE {
  TokenElevationTypeDefault = 1,
  TokenElevationTypeFull,
  TokenElevationTypeLimited
} TOKEN_ELEVATION_TYPE, *PTOKEN_ELEVATION_TYPE;

/*
 * TOKEN_INFORMATION_CLASS
 */

typedef enum _TOKEN_INFORMATION_CLASS {
  TokenUser = 1,
  TokenGroups,
  TokenPrivileges,
  TokenOwner,
  TokenPrimaryGroup,
  TokenDefaultDacl,
  TokenSource,
  TokenType,
  TokenImpersonationLevel,
  TokenStatistics,
  TokenRestrictedSids,
  TokenSessionId,
  TokenGroupsAndPrivileges,
  TokenSessionReference,
  TokenSandBoxInert,
  TokenAuditPolicy,
  TokenOrigin,
  TokenElevationType,
  TokenLinkedToken,
  TokenElevation,
  TokenHasRestrictions,
  TokenAccessInformation,
  TokenVirtualizationAllowed,
  TokenVirtualizationEnabled,
  TokenIntegrityLevel,
  TokenUIAccess,
  TokenMandatoryPolicy,
  TokenLogonSid,
  TokenIsAppContainer,
  TokenCapabilities,
  TokenAppContainerSid,
  TokenAppContainerNumber,
  TokenUserClaimAttributes,
  TokenDeviceClaimAttributes,
  TokenRestrictedUserClaimAttributes,
  TokenRestrictedDeviceClaimAttributes,
  TokenDeviceGroups,
  TokenRestrictedDeviceGroups,
  TokenSecurityAttributes,
  TokenIsRestricted,
  TokenProcessTrustLevel,
  MaxTokenInfoClass
} TOKEN_INFORMATION_CLASS;

#define TOKEN_TOKEN_ADJUST_DEFAULT   0x0080
#define TOKEN_ADJUST_GROUPS          0x0040
#define TOKEN_ADJUST_PRIVILEGES      0x0020
#define TOKEN_ADJUST_SESSIONID       0x0100
#define TOKEN_ASSIGN_PRIMARY         0x0001
#define TOKEN_DUPLICATE              0x0002
#define TOKEN_EXECUTE                STANDARD_RIGHTS_EXECUTE
#define TOKEN_IMPERSONATE            0x0004
#define TOKEN_QUERY                  0x0008
#define TOKEN_QUERY_SOURCE           0x0010
#define TOKEN_ADJUST_DEFAULT         0x0080
#define TOKEN_READ                   (STANDARD_RIGHTS_READ|TOKEN_QUERY)
#define TOKEN_WRITE                  (STANDARD_RIGHTS_WRITE     | \
					TOKEN_ADJUST_PRIVILEGES | \
					TOKEN_ADJUST_GROUPS | \
					TOKEN_ADJUST_DEFAULT )
#define TOKEN_ALL_ACCESS             (STANDARD_RIGHTS_REQUIRED | \
					TOKEN_ASSIGN_PRIMARY | \
					TOKEN_DUPLICATE | \
					TOKEN_IMPERSONATE | \
					TOKEN_QUERY | \
					TOKEN_QUERY_SOURCE | \
					TOKEN_ADJUST_PRIVILEGES | \
					TOKEN_ADJUST_GROUPS | \
					TOKEN_ADJUST_SESSIONID | \
					TOKEN_ADJUST_DEFAULT )

#ifndef _SECURITY_DEFINED
#define _SECURITY_DEFINED


typedef DWORD ACCESS_MASK, *PACCESS_MASK;

typedef struct _GENERIC_MAPPING {
    ACCESS_MASK GenericRead;
    ACCESS_MASK GenericWrite;
    ACCESS_MASK GenericExecute;
    ACCESS_MASK GenericAll;
} GENERIC_MAPPING, *PGENERIC_MAPPING;

#ifndef SID_IDENTIFIER_AUTHORITY_DEFINED
#define SID_IDENTIFIER_AUTHORITY_DEFINED
typedef struct {
    BYTE Value[6];
} SID_IDENTIFIER_AUTHORITY, *PSID_IDENTIFIER_AUTHORITY;
#endif /* !defined(SID_IDENTIFIER_AUTHORITY_DEFINED) */

#ifndef SID_DEFINED
#define SID_DEFINED
typedef struct _SID {
    BYTE Revision;
    BYTE SubAuthorityCount;
    SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
    DWORD SubAuthority[1];
} SID,*PISID;
#endif /* !defined(SID_DEFINED) */

#define	SID_REVISION			(1)	/* Current revision */
#define	SID_MAX_SUB_AUTHORITIES		(15)	/* current max subauths */
#define	SID_RECOMMENDED_SUB_AUTHORITIES	(1)	/* recommended subauths */

#define SECURITY_MAX_SID_SIZE (sizeof(SID) - sizeof(DWORD) + (SID_MAX_SUB_AUTHORITIES * sizeof(DWORD)))

/*
 * ACL
 */

#define ACL_REVISION1 1
#define ACL_REVISION2 2
#define ACL_REVISION3 3
#define ACL_REVISION4 4

#define MIN_ACL_REVISION ACL_REVISION2
#define MAX_ACL_REVISION ACL_REVISION4

#define ACL_REVISION 2

typedef struct _ACL {
    BYTE AclRevision;
    BYTE Sbz1;
    WORD AclSize;
    WORD AceCount;
    WORD Sbz2;
} ACL, *PACL;

typedef enum _ACL_INFORMATION_CLASS
{
  AclRevisionInformation = 1, 
  AclSizeInformation
} ACL_INFORMATION_CLASS;

typedef struct _ACL_REVISION_INFORMATION
{
    DWORD AclRevision;
} ACL_REVISION_INFORMATION, *PACL_REVISION_INFORMATION;

typedef struct _ACL_SIZE_INFORMATION
{
    DWORD AceCount;
    DWORD AclBytesInUse;
    DWORD AclBytesFree;
} ACL_SIZE_INFORMATION, *PACL_SIZE_INFORMATION;

/* SECURITY_DESCRIPTOR */
#define	SECURITY_DESCRIPTOR_REVISION	1
#define	SECURITY_DESCRIPTOR_REVISION1	1


/*
 * Privilege Names
 */
#ifdef UNICODE
#if defined(_MSC_VER)
#define SE_CREATE_TOKEN_NAME            L"SeCreateTokenPrivilege"
#define SE_ASSIGNPRIMARYTOKEN_NAME      L"SeAssignPrimaryTokenPrivilege"
#define SE_LOCK_MEMORY_NAME             L"SeLockMemoryPrivilege"
#define SE_INCREASE_QUOTA_NAME          L"SeIncreaseQuotaPrivilege"
#define SE_UNSOLICITED_INPUT_NAME       L"SeUnsolicitedInputPrivilege"
#define SE_MACHINE_ACCOUNT_NAME         L"SeMachineAccountPrivilege"
#define SE_TCB_NAME                     L"SeTcbPrivilege"
#define SE_SECURITY_NAME                L"SeSecurityPrivilege"
#define SE_TAKE_OWNERSHIP_NAME          L"SeTakeOwnershipPrivilege"
#define SE_LOAD_DRIVER_NAME             L"SeLoadDriverPrivilege"
#define SE_SYSTEM_PROFILE_NAME          L"SeSystemProfilePrivilege"
#define SE_SYSTEMTIME_NAME              L"SeSystemtimePrivilege"
#define SE_PROF_SINGLE_PROCESS_NAME     L"SeProfileSingleProcessPrivilege"
#define SE_INC_BASE_PRIORITY_NAME       L"SeIncreaseBasePriorityPrivilege"
#define SE_CREATE_PAGEFILE_NAME         L"SeCreatePagefilePrivilege"
#define SE_CREATE_PERMANENT_NAME        L"SeCreatePermanentPrivilege"
#define SE_BACKUP_NAME                  L"SeBackupPrivilege"
#define SE_RESTORE_NAME                 L"SeRestorePrivilege"
#define SE_SHUTDOWN_NAME                L"SeShutdownPrivilege"
#define SE_DEBUG_NAME                   L"SeDebugPrivilege"
#define SE_AUDIT_NAME                   L"SeAuditPrivilege"
#define SE_SYSTEM_ENVIRONMENT_NAME      L"SeSystemEnvironmentPrivilege"
#define SE_CHANGE_NOTIFY_NAME           L"SeChangeNotifyPrivilege"
#define SE_REMOTE_SHUTDOWN_NAME         L"SeRemoteShutdownPrivilege"
#define SE_UNDOCK_NAME                  L"SeUndockPrivilege"
#define SE_ENABLE_DELEGATION_NAME       L"SeEnableDelegationPrivilege"
#define SE_MANAGE_VOLUME_NAME           L"SeManageVolumePrivilege"
#define SE_IMPERSONATE_NAME             L"SeImpersonatePrivilege"
#define SE_CREATE_GLOBAL_NAME           L"SeCreateGlobalPrivilege"
#elif defined(__GNUC__)
#define SE_CREATE_TOKEN_NAME (const WCHAR []){ 'S','e','C','r','e','a','t','e','T','o','k','e','n','P','r','i','v','i','l','e','g','e',0 }
#define SE_ASSIGNPRIMARYTOKEN_NAME (const WCHAR []){ 'S','e','A','s','s','i','g','n','P','r','i','m','a','r','y','T','o','k','e','n','P','r','i','v','i','l','e','g','e',0 }
#define SE_LOCK_MEMORY_NAME (const WCHAR []){ 'S','e','L','o','c','k','M','e','m','o','r','y','P','r','i','v','i','l','e','g','e',0 }
#define SE_INCREASE_QUOTA_NAME (const WCHAR []){ 'S','e','I','n','c','r','e','a','s','e','Q','u','o','t','a','P','r','i','v','i','l','e','g','e',0 }
#define SE_UNSOLICITED_INPUT_NAME (const WCHAR []){ 'S','e','U','n','s','o','l','i','c','i','t','e','d','I','n','p','u','t','P','r','i','v','i','l','e','g','e',0 }
#define SE_MACHINE_ACCOUNT_NAME (const WCHAR []){ 'S','e','M','a','c','h','i','n','e','A','c','c','o','u','n','t','P','r','i','v','i','l','e','g','e',0 }
#define SE_TCB_NAME (const WCHAR []){ 'S','e','T','c','b','P','r','i','v','i','l','e','g','e',0 }
#define SE_SECURITY_NAME (const WCHAR []){ 'S','e','S','e','c','u','r','i','t','y','P','r','i','v','i','l','e','g','e',0 }
#define SE_TAKE_OWNERSHIP_NAME (const WCHAR []){ 'S','e','T','a','k','e','O','w','n','e','r','s','h','i','p','P','r','i','v','i','l','e','g','e',0 }
#define SE_LOAD_DRIVER_NAME (const WCHAR []){ 'S','e','L','o','a','d','D','r','i','v','e','r','P','r','i','v','i','l','e','g','e',0 }
#define SE_SYSTEM_PROFILE_NAME (const WCHAR []){ 'S','e','S','y','s','t','e','m','P','r','o','f','i','l','e','P','r','i','v','i','l','e','g','e',0 }
#define SE_SYSTEMTIME_NAME (const WCHAR []){ 'S','e','S','y','s','t','e','m','t','i','m','e','P','r','i','v','i','l','e','g','e',0 }
#define SE_PROF_SINGLE_PROCESS_NAME (const WCHAR []){ 'S','e','P','r','o','f','i','l','e','S','i','n','g','l','e','P','r','o','c','e','s','s','P','r','i','v','i','l','e','g','e',0 }
#define SE_INC_BASE_PRIORITY_NAME (const WCHAR []){ 'S','e','I','n','c','r','e','a','s','e','B','a','s','e','P','r','i','o','r','i','t','y','P','r','i','v','i','l','e','g','e',0 }
#define SE_CREATE_PAGEFILE_NAME (const WCHAR []){ 'S','e','C','r','e','a','t','e','P','a','g','e','f','i','l','e','P','r','i','v','i','l','e','g','e',0 }
#define SE_CREATE_PERMANENT_NAME (const WCHAR []){ 'S','e','C','r','e','a','t','e','P','e','r','m','a','n','e','n','t','P','r','i','v','i','l','e','g','e',0 }
#define SE_BACKUP_NAME (const WCHAR []){ 'S','e','B','a','c','k','u','p','P','r','i','v','i','l','e','g','e',0 }
#define SE_RESTORE_NAME (const WCHAR []){ 'S','e','R','e','s','t','o','r','e','P','r','i','v','i','l','e','g','e',0 }
#define SE_SHUTDOWN_NAME (const WCHAR []){ 'S','e','S','h','u','t','d','o','w','n','P','r','i','v','i','l','e','g','e',0 }
#define SE_DEBUG_NAME (const WCHAR []){ 'S','e','D','e','b','u','g','P','r','i','v','i','l','e','g','e',0 }
#define SE_AUDIT_NAME (const WCHAR []){ 'S','e','A','u','d','i','t','P','r','i','v','i','l','e','g','e',0 }
#define SE_SYSTEM_ENVIRONMENT_NAME (const WCHAR []){ 'S','e','S','y','s','t','e','m','E','n','v','i','r','o','n','m','e','n','t','P','r','i','v','i','l','e','g','e',0 }
#define SE_CHANGE_NOTIFY_NAME (const WCHAR []){ 'S','e','C','h','a','n','g','e','N','o','t','i','f','y','P','r','i','v','i','l','e','g','e',0 }
#define SE_REMOTE_SHUTDOWN_NAME (const WCHAR []){ 'S','e','R','e','m','o','t','e','S','h','u','t','d','o','w','n','P','r','i','v','i','l','e','g','e',0 }
#define SE_UNDOCK_NAME (const WCHAR []){ 'S','e','U','n','d','o','c','k','P','r','i','v','i','l','e','g','e',0 }
#define SE_ENABLE_DELEGATION_NAME (const WCHAR []){ 'S','e','E','n','a','b','l','e','D','e','l','e','g','a','t','i','o','n','P','r','i','v','i','l','e','g','e',0 }
#define SE_MANAGE_VOLUME_NAME (const WCHAR []){ 'S','e','M','a','n','a','g','e','V','o','l','u','m','e','P','r','i','v','i','l','e','g','e',0 }
#define SE_IMPERSONATE_NAME (const WCHAR []){ 'S','e','I','m','p','e','r','s','o','n','a','t','e','P','r','i','v','i','l','e','g','e',0 }
#define SE_CREATE_GLOBAL_NAME (const WCHAR []){ 'S','e','C','r','e','a','t','e','G','l','o','b','a','l','P','r','i','v','i','l','e','g','e',0 }
#else /* _MSC_VER/__GNUC__ */
static const WCHAR SE_CREATE_TOKEN_NAME[] = { 'S','e','C','r','e','a','t','e','T','o','k','e','n','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_ASSIGNPRIMARYTOKEN_NAME[] = { 'S','e','A','s','s','i','g','n','P','r','i','m','a','r','y','T','o','k','e','n','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_LOCK_MEMORY_NAME[] = { 'S','e','L','o','c','k','M','e','m','o','r','y','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_INCREASE_QUOTA_NAME[] = { 'S','e','I','n','c','r','e','a','s','e','Q','u','o','t','a','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_UNSOLICITED_INPUT_NAME[] = { 'S','e','U','n','s','o','l','i','c','i','t','e','d','I','n','p','u','t','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_MACHINE_ACCOUNT_NAME[] = { 'S','e','M','a','c','h','i','n','e','A','c','c','o','u','n','t','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_TCB_NAME[] = { 'S','e','T','c','b','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_SECURITY_NAME[] = { 'S','e','S','e','c','u','r','i','t','y','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_TAKE_OWNERSHIP_NAME[] = { 'S','e','T','a','k','e','O','w','n','e','r','s','h','i','p','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_LOAD_DRIVER_NAME[] = { 'S','e','L','o','a','d','D','r','i','v','e','r','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_SYSTEM_PROFILE_NAME[] = { 'S','e','S','y','s','t','e','m','P','r','o','f','i','l','e','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_SYSTEMTIME_NAME[] = { 'S','e','S','y','s','t','e','m','t','i','m','e','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_PROF_SINGLE_PROCESS_NAME[] = { 'S','e','P','r','o','f','i','l','e','S','i','n','g','l','e','P','r','o','c','e','s','s','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_INC_BASE_PRIORITY_NAME[] = { 'S','e','I','n','c','r','e','a','s','e','B','a','s','e','P','r','i','o','r','i','t','y','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_CREATE_PAGEFILE_NAME[] = { 'S','e','C','r','e','a','t','e','P','a','g','e','f','i','l','e','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_CREATE_PERMANENT_NAME[] = { 'S','e','C','r','e','a','t','e','P','e','r','m','a','n','e','n','t','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_BACKUP_NAME[] = { 'S','e','B','a','c','k','u','p','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_RESTORE_NAME[] = { 'S','e','R','e','s','t','o','r','e','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_SHUTDOWN_NAME[] = { 'S','e','S','h','u','t','d','o','w','n','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_DEBUG_NAME[] = { 'S','e','D','e','b','u','g','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_AUDIT_NAME[] = { 'S','e','A','u','d','i','t','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_SYSTEM_ENVIRONMENT_NAME[] = { 'S','e','S','y','s','t','e','m','E','n','v','i','r','o','n','m','e','n','t','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_CHANGE_NOTIFY_NAME[] = { 'S','e','C','h','a','n','g','e','N','o','t','i','f','y','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_REMOTE_SHUTDOWN_NAME[] = { 'S','e','R','e','m','o','t','e','S','h','u','t','d','o','w','n','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_UNDOCK_NAME[] = { 'S','e','U','n','d','o','c','k','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_ENABLE_DELEGATION_NAME[] = { 'S','e','E','n','a','b','l','e','D','e','l','e','g','a','t','i','o','n','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_MANAGE_VOLUME_NAME[] = { 'S','e','M','a','n','a','g','e','V','o','l','u','m','e','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_IMPERSONATE_NAME[] = { 'S','e','I','m','p','e','r','s','o','n','a','t','e','P','r','i','v','i','l','e','g','e',0 };
static const WCHAR SE_CREATE_GLOBAL_NAME[] = { 'S','e','C','r','e','a','t','e','G','l','o','b','a','l','P','r','i','v','i','l','e','g','e',0 };
#endif
#else /* UNICODE */
#define SE_CREATE_TOKEN_NAME            "SeCreateTokenPrivilege"
#define SE_ASSIGNPRIMARYTOKEN_NAME      "SeAssignPrimaryTokenPrivilege"
#define SE_LOCK_MEMORY_NAME             "SeLockMemoryPrivilege"
#define SE_INCREASE_QUOTA_NAME          "SeIncreaseQuotaPrivilege"
#define SE_UNSOLICITED_INPUT_NAME       "SeUnsolicitedInputPrivilege"
#define SE_MACHINE_ACCOUNT_NAME         "SeMachineAccountPrivilege"
#define SE_TCB_NAME                     "SeTcbPrivilege"
#define SE_SECURITY_NAME                "SeSecurityPrivilege"
#define SE_TAKE_OWNERSHIP_NAME          "SeTakeOwnershipPrivilege"
#define SE_LOAD_DRIVER_NAME             "SeLoadDriverPrivilege"
#define SE_SYSTEM_PROFILE_NAME          "SeSystemProfilePrivilege"
#define SE_SYSTEMTIME_NAME              "SeSystemtimePrivilege"
#define SE_PROF_SINGLE_PROCESS_NAME     "SeProfileSingleProcessPrivilege"
#define SE_INC_BASE_PRIORITY_NAME       "SeIncreaseBasePriorityPrivilege"
#define SE_CREATE_PAGEFILE_NAME         "SeCreatePagefilePrivilege"
#define SE_CREATE_PERMANENT_NAME        "SeCreatePermanentPrivilege"
#define SE_BACKUP_NAME                  "SeBackupPrivilege"
#define SE_RESTORE_NAME                 "SeRestorePrivilege"
#define SE_SHUTDOWN_NAME                "SeShutdownPrivilege"
#define SE_DEBUG_NAME                   "SeDebugPrivilege"
#define SE_AUDIT_NAME                   "SeAuditPrivilege"
#define SE_SYSTEM_ENVIRONMENT_NAME      "SeSystemEnvironmentPrivilege"
#define SE_CHANGE_NOTIFY_NAME           "SeChangeNotifyPrivilege"
#define SE_REMOTE_SHUTDOWN_NAME         "SeRemoteShutdownPrivilege"
#define SE_UNDOCK_NAME                  "SeUndockPrivilege"
#define SE_ENABLE_DELEGATION_NAME       "SeEnableDelegationPrivilege"
#define SE_MANAGE_VOLUME_NAME           "SeManageVolumePrivilege"
#define SE_IMPERSONATE_NAME             "SeImpersonatePrivilege"
#define SE_CREATE_GLOBAL_NAME           "SeCreateGlobalPrivilege"
#endif

#define SE_GROUP_MANDATORY          0x00000001
#define SE_GROUP_ENABLED_BY_DEFAULT 0x00000002
#define SE_GROUP_ENABLED            0x00000004
#define SE_GROUP_OWNER              0x00000008
#define SE_GROUP_USE_FOR_DENY_ONLY  0x00000010
#define SE_GROUP_INTEGRITY          0x00000020
#define SE_GROUP_INTEGRITY_ENABLED  0x00000040
#define SE_GROUP_LOGON_ID           0xC0000000
#define SE_GROUP_RESOURCE           0x20000000
#define SE_GROUP_VALID_ATTRIBUTES   0xE000007F

#define SE_PRIVILEGE_ENABLED_BY_DEFAULT 0x00000001
#define SE_PRIVILEGE_ENABLED 		0x00000002
#define SE_PRIVILEGE_REMOVED		0x00000004
#define SE_PRIVILEGE_USED_FOR_ACCESS 	0x80000000

#define PRIVILEGE_SET_ALL_NECESSARY     1

#define SE_OWNER_DEFAULTED		0x00000001
#define SE_GROUP_DEFAULTED		0x00000002
#define SE_DACL_PRESENT			0x00000004
#define SE_DACL_DEFAULTED		0x00000008
#define SE_SACL_PRESENT			0x00000010
#define SE_SACL_DEFAULTED		0x00000020
#define SE_DACL_AUTO_INHERIT_REQ	0x00000100
#define SE_SACL_AUTO_INHERIT_REQ	0x00000200
#define SE_DACL_AUTO_INHERITED		0x00000400
#define SE_SACL_AUTO_INHERITED		0x00000800
#define SE_DACL_PROTECTED 		0x00001000
#define SE_SACL_PROTECTED 		0x00002000
#define SE_RM_CONTROL_VALID		0x00004000
#define SE_SELF_RELATIVE		0x00008000

typedef DWORD SECURITY_INFORMATION, *PSECURITY_INFORMATION;
typedef WORD SECURITY_DESCRIPTOR_CONTROL, *PSECURITY_DESCRIPTOR_CONTROL;

/* The security descriptor structure */
typedef struct {
    BYTE Revision;
    BYTE Sbz1;
    SECURITY_DESCRIPTOR_CONTROL Control;
    DWORD Owner;
    DWORD Group;
    DWORD Sacl;
    DWORD Dacl;
} SECURITY_DESCRIPTOR_RELATIVE, *PISECURITY_DESCRIPTOR_RELATIVE;

typedef struct {
    BYTE Revision;
    BYTE Sbz1;
    SECURITY_DESCRIPTOR_CONTROL Control;
    PSID Owner;
    PSID Group;
    PACL Sacl;
    PACL Dacl;
} SECURITY_DESCRIPTOR, *PISECURITY_DESCRIPTOR;

#define SECURITY_DESCRIPTOR_MIN_LENGTH   (sizeof(SECURITY_DESCRIPTOR))

#endif /* _SECURITY_DEFINED */

/*
 * SID_AND_ATTRIBUTES
 */

typedef struct _SID_AND_ATTRIBUTES {
  PSID  Sid;
  DWORD Attributes;
} SID_AND_ATTRIBUTES, *PSID_AND_ATTRIBUTES;

/* security entities */
#define SECURITY_NULL_RID                       __MSABI_LONG(0x00000000)
#define SECURITY_WORLD_RID                      __MSABI_LONG(0x00000000)
#define SECURITY_LOCAL_RID                      __MSABI_LONG(0X00000000)

#define SECURITY_NULL_SID_AUTHORITY		{0,0,0,0,0,0}

/* S-1-1 */
#define SECURITY_WORLD_SID_AUTHORITY		{0,0,0,0,0,1}

/* S-1-2 */
#define SECURITY_LOCAL_SID_AUTHORITY		{0,0,0,0,0,2}

/* S-1-3 */
#define SECURITY_CREATOR_SID_AUTHORITY		{0,0,0,0,0,3}
#define SECURITY_CREATOR_OWNER_RID              __MSABI_LONG(0x00000000)
#define SECURITY_CREATOR_GROUP_RID              __MSABI_LONG(0x00000001)
#define SECURITY_CREATOR_OWNER_SERVER_RID       __MSABI_LONG(0x00000002)
#define SECURITY_CREATOR_GROUP_SERVER_RID       __MSABI_LONG(0x00000003)

/* S-1-4 */
#define SECURITY_NON_UNIQUE_AUTHORITY		{0,0,0,0,0,4}

/* S-1-5 */
#define SECURITY_NT_AUTHORITY			{0,0,0,0,0,5}
#define SECURITY_DIALUP_RID                     __MSABI_LONG(0x00000001)
#define SECURITY_NETWORK_RID                    __MSABI_LONG(0x00000002)
#define SECURITY_BATCH_RID                      __MSABI_LONG(0x00000003)
#define SECURITY_INTERACTIVE_RID                __MSABI_LONG(0x00000004)
#define SECURITY_LOGON_IDS_RID                  __MSABI_LONG(0x00000005)
#define SECURITY_SERVICE_RID                    __MSABI_LONG(0x00000006)
#define SECURITY_ANONYMOUS_LOGON_RID            __MSABI_LONG(0x00000007)
#define SECURITY_PROXY_RID                      __MSABI_LONG(0x00000008)
#define SECURITY_ENTERPRISE_CONTROLLERS_RID     __MSABI_LONG(0x00000009)
#define SECURITY_SERVER_LOGON_RID               SECURITY_ENTERPRISE_CONTROLLERS_RID
#define SECURITY_PRINCIPAL_SELF_RID             __MSABI_LONG(0x0000000A)
#define SECURITY_AUTHENTICATED_USER_RID         __MSABI_LONG(0x0000000B)
#define SECURITY_RESTRICTED_CODE_RID            __MSABI_LONG(0x0000000C)
#define SECURITY_TERMINAL_SERVER_RID            __MSABI_LONG(0x0000000D)
#define SECURITY_REMOTE_LOGON_RID               __MSABI_LONG(0x0000000E)
#define SECURITY_THIS_ORGANIZATION_RID          __MSABI_LONG(0x0000000F)
#define SECURITY_LOCAL_SYSTEM_RID               __MSABI_LONG(0x00000012)
#define SECURITY_LOCAL_SERVICE_RID              __MSABI_LONG(0x00000013)
#define SECURITY_NETWORK_SERVICE_RID            __MSABI_LONG(0x00000014)
#define SECURITY_NT_NON_UNIQUE                  __MSABI_LONG(0x00000015)
#define SECURITY_BUILTIN_DOMAIN_RID             __MSABI_LONG(0x00000020)

#define SECURITY_PACKAGE_BASE_RID               __MSABI_LONG(0x00000040)
#define SECURITY_PACKAGE_NTLM_RID               __MSABI_LONG(0x0000000A)
#define SECURITY_PACKAGE_SCHANNEL_RID           __MSABI_LONG(0x0000000E)
#define SECURITY_PACKAGE_DIGEST_RID             __MSABI_LONG(0x00000015)
#define SECURITY_MAX_ALWAYS_FILTERED            __MSABI_LONG(0x000003E7)
#define SECURITY_MIN_NEVER_FILTERED             __MSABI_LONG(0x000003E8)
#define SECURITY_OTHER_ORGANIZATION_RID         __MSABI_LONG(0x000003E8)

#define FOREST_USER_RID_MAX                     __MSABI_LONG(0x000001F3)
#define DOMAIN_USER_RID_ADMIN                   __MSABI_LONG(0x000001F4)
#define DOMAIN_USER_RID_GUEST                   __MSABI_LONG(0x000001F5)
#define DOMAIN_USER_RID_KRBTGT                  __MSABI_LONG(0x000001F6)
#define DOMAIN_USER_RID_MAX                     __MSABI_LONG(0x000003E7)

#define DOMAIN_GROUP_RID_ADMINS                 __MSABI_LONG(0x00000200)
#define DOMAIN_GROUP_RID_USERS                  __MSABI_LONG(0x00000201)
#define DOMAIN_GROUP_RID_GUESTS                 __MSABI_LONG(0x00000202)
#define DOMAIN_GROUP_RID_COMPUTERS              __MSABI_LONG(0x00000203)
#define DOMAIN_GROUP_RID_CONTROLLERS            __MSABI_LONG(0x00000204)
#define DOMAIN_GROUP_RID_CERT_ADMINS            __MSABI_LONG(0x00000205)
#define DOMAIN_GROUP_RID_SCHEMA_ADMINS          __MSABI_LONG(0x00000206)
#define DOMAIN_GROUP_RID_ENTERPRISE_ADMINS      __MSABI_LONG(0x00000207)
#define DOMAIN_GROUP_RID_POLICY_ADMINS          __MSABI_LONG(0x00000208)

#define SECURITY_APP_PACKAGE_AUTHORITY {0,0,0,0,0,15}
#define SECURITY_APP_PACKAGE_BASE_RID           __MSABI_LONG(0x000000002)
#define SECURITY_BUILTIN_APP_PACKAGE_RID_COUNT  __MSABI_LONG(0x000000002)
#define SECURITY_APP_PACKAGE_RID_COUNT          __MSABI_LONG(0x000000008)
#define SECURITY_CAPABILITY_BASE_RID            __MSABI_LONG(0x000000003)
#define SECURITY_CAPABILITY_APP_RID             __MSABI_LONG(0x000000400)
#define SECURITY_BUILTIN_CAPABILITY_RID_COUNT   __MSABI_LONG(0x000000002)
#define SECURITY_CAPABILITY_RID_COUNT           __MSABI_LONG(0x000000005)
#define SECURITY_PARENT_PACKAGE_RID_COUNT       SECURITY_APP_PACKAGE_RID_COUNT
#define SECURITY_CHILD_PACKAGE_RID_COUNT        __MSABI_LONG(0x00000000c)
#define SECURITY_BUILTIN_PACKAGE_ANY_PACKAGE    __MSABI_LONG(0x000000001)

#define SECURITY_MANDATORY_LABEL_AUTHORITY {0,0,0,0,0,16}
#define SECURITY_MANDATORY_UNTRUSTED_RID        __MSABI_LONG(0x00000000)
#define SECURITY_MANDATORY_LOW_RID              __MSABI_LONG(0x00001000)
#define SECURITY_MANDATORY_MEDIUM_RID           __MSABI_LONG(0x00002000)
#define SECURITY_MANDATORY_HIGH_RID             __MSABI_LONG(0x00003000)
#define SECURITY_MANDATORY_SYSTEM_RID           __MSABI_LONG(0x00004000)
#define SECURITY_MANDATORY_PROTECTED_PROCESS_RID __MSABI_LONG(0x00005000)

#define DOMAIN_ALIAS_RID_ADMINS                 __MSABI_LONG(0x00000220)
#define DOMAIN_ALIAS_RID_USERS                  __MSABI_LONG(0x00000221)
#define DOMAIN_ALIAS_RID_GUESTS                 __MSABI_LONG(0x00000222)
#define DOMAIN_ALIAS_RID_POWER_USERS            __MSABI_LONG(0x00000223)

#define DOMAIN_ALIAS_RID_ACCOUNT_OPS            __MSABI_LONG(0x00000224)
#define DOMAIN_ALIAS_RID_SYSTEM_OPS             __MSABI_LONG(0x00000225)
#define DOMAIN_ALIAS_RID_PRINT_OPS              __MSABI_LONG(0x00000226)
#define DOMAIN_ALIAS_RID_BACKUP_OPS             __MSABI_LONG(0x00000227)

#define DOMAIN_ALIAS_RID_REPLICATOR             __MSABI_LONG(0x00000228)
#define DOMAIN_ALIAS_RID_RAS_SERVERS            __MSABI_LONG(0x00000229)
#define DOMAIN_ALIAS_RID_PREW2KCOMPACCESS       __MSABI_LONG(0x0000022A)
#define DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS   __MSABI_LONG(0x0000022B)
#define DOMAIN_ALIAS_RID_NETWORK_CONFIGURATION_OPS __MSABI_LONG(0x0000022C)
#define DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS __MSABI_LONG(0x0000022D)

#define DOMAIN_ALIAS_RID_MONITORING_USERS       __MSABI_LONG(0x0000022E)
#define DOMAIN_ALIAS_RID_LOGGING_USERS          __MSABI_LONG(0x0000022F)
#define DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS    __MSABI_LONG(0x00000230)
#define DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS     __MSABI_LONG(0x00000231)
#define DOMAIN_ALIAS_RID_DCOM_USERS             __MSABI_LONG(0x00000232)

#define SECURITY_SERVER_LOGON_RID		SECURITY_ENTERPRISE_CONTROLLERS_RID

#define SECURITY_PACKAGE_RID_COUNT              __MSABI_LONG(2)
#define SECURITY_LOGON_IDS_RID_COUNT            __MSABI_LONG(3)

typedef enum {
    WinNullSid                                  = 0,
    WinWorldSid                                 = 1,
    WinLocalSid                                 = 2,
    WinCreatorOwnerSid                          = 3,
    WinCreatorGroupSid                          = 4,
    WinCreatorOwnerServerSid                    = 5,
    WinCreatorGroupServerSid                    = 6,
    WinNtAuthoritySid                           = 7,
    WinDialupSid                                = 8,
    WinNetworkSid                               = 9,
    WinBatchSid                                 = 10,
    WinInteractiveSid                           = 11,
    WinServiceSid                               = 12,
    WinAnonymousSid                             = 13,
    WinProxySid                                 = 14,
    WinEnterpriseControllersSid                 = 15,
    WinSelfSid                                  = 16,
    WinAuthenticatedUserSid                     = 17,
    WinRestrictedCodeSid                        = 18,
    WinTerminalServerSid                        = 19,
    WinRemoteLogonIdSid                         = 20,
    WinLogonIdsSid                              = 21,
    WinLocalSystemSid                           = 22,
    WinLocalServiceSid                          = 23,
    WinNetworkServiceSid                        = 24,
    WinBuiltinDomainSid                         = 25,
    WinBuiltinAdministratorsSid                 = 26,
    WinBuiltinUsersSid                          = 27,
    WinBuiltinGuestsSid                         = 28,
    WinBuiltinPowerUsersSid                     = 29,
    WinBuiltinAccountOperatorsSid               = 30,
    WinBuiltinSystemOperatorsSid                = 31,
    WinBuiltinPrintOperatorsSid                 = 32,
    WinBuiltinBackupOperatorsSid                = 33,
    WinBuiltinReplicatorSid                     = 34,
    WinBuiltinPreWindows2000CompatibleAccessSid = 35,
    WinBuiltinRemoteDesktopUsersSid             = 36,
    WinBuiltinNetworkConfigurationOperatorsSid  = 37,
    WinAccountAdministratorSid                  = 38,
    WinAccountGuestSid                          = 39,
    WinAccountKrbtgtSid                         = 40,
    WinAccountDomainAdminsSid                   = 41,
    WinAccountDomainUsersSid                    = 42,
    WinAccountDomainGuestsSid                   = 43,
    WinAccountComputersSid                      = 44,
    WinAccountControllersSid                    = 45,
    WinAccountCertAdminsSid                     = 46,
    WinAccountSchemaAdminsSid                   = 47,
    WinAccountEnterpriseAdminsSid               = 48,
    WinAccountPolicyAdminsSid                   = 49,
    WinAccountRasAndIasServersSid               = 50,
    WinNTLMAuthenticationSid                    = 51,
    WinDigestAuthenticationSid                  = 52,
    WinSChannelAuthenticationSid                = 53,
    WinThisOrganizationSid                      = 54,
    WinOtherOrganizationSid                     = 55,
    WinBuiltinIncomingForestTrustBuildersSid    = 56,
    WinBuiltinPerfMonitoringUsersSid            = 57,
    WinBuiltinPerfLoggingUsersSid               = 58,
    WinBuiltinAuthorizationAccessSid            = 59,
    WinBuiltinTerminalServerLicenseServersSid   = 60,
    WinBuiltinDCOMUsersSid                      = 61,
    WinBuiltinIUsersSid                         = 62,
    WinIUserSid                                 = 63,
    WinBuiltinCryptoOperatorsSid                = 64,
    WinUntrustedLabelSid                        = 65,
    WinLowLabelSid                              = 66,
    WinMediumLabelSid                           = 67,
    WinHighLabelSid                             = 68,
    WinSystemLabelSid                           = 69,
    WinWriteRestrictedCodeSid                   = 70,
    WinCreatorOwnerRightsSid                    = 71,
    WinCacheablePrincipalsGroupSid              = 72,
    WinNonCacheablePrincipalsGroupSid           = 73,
    WinEnterpriseReadonlyControllersSid         = 74,
    WinAccountReadonlyControllersSid            = 75,
    WinBuiltinEventLogReadersGroup              = 76,
    WinNewEnterpriseReadonlyControllersSid      = 77,
    WinBuiltinCertSvcDComAccessGroup            = 78,
    WinMediumPlusLabelSid                       = 79,
    WinLocalLogonSid                            = 80,
    WinConsoleLogonSid                          = 81,
    WinThisOrganizationCertificateSid           = 82,
    WinApplicationPackageAuthoritySid           = 83,
    WinBuiltinAnyPackageSid                     = 84,
    WinCapabilityInternetClientSid              = 85,
    WinCapabilityInternetClientServerSid        = 86,
    WinCapabilityPrivateNetworkClientServerSid  = 87,
    WinCapabilityPicturesLibrarySid             = 88,
    WinCapabilityVideosLibrarySid               = 89,
    WinCapabilityMusicLibrarySid                = 90,
    WinCapabilityDocumentsLibrarySid            = 91,
    WinCapabilitySharedUserCertificatesSid      = 92,
    WinCapabilityEnterpriseAuthenticationSid    = 93,
    WinCapabilityRemovableStorageSid            = 94,
    WinBuiltinRDSRemoteAccessServersSid         = 95,
    WinBuiltinRDSEndpointServersSid             = 96,
    WinBuiltinRDSManagementServersSid           = 97,
    WinUserModeDriversSid                       = 98,
    WinBuiltinHyperVAdminsSid                   = 99,
    WinAccountCloneableControllersSid           = 100,
    WinBuiltinAccessControlAssistanceOperatorsSid = 101,
    WinBuiltinRemoteManagementUsersSid          = 102,
    WinAuthenticationAuthorityAssertedSid       = 103,
    WinAuthenticationServiceAssertedSid         = 104,
    WinLocalAccountSid                          = 105,
    WinLocalAccountAndAdministratorSid          = 106,
    WinAccountProtectedUsersSid                 = 107,
} WELL_KNOWN_SID_TYPE;

/*
 * TOKEN_USER
 */

typedef struct _TOKEN_USER {
    SID_AND_ATTRIBUTES User;
} TOKEN_USER, *PTOKEN_USER;

/*
 * TOKEN_GROUPS
 */

typedef struct _TOKEN_GROUPS {
    DWORD GroupCount;
    SID_AND_ATTRIBUTES Groups[ANYSIZE_ARRAY];
} TOKEN_GROUPS, *PTOKEN_GROUPS;

/*
 * LUID_AND_ATTRIBUTES
 */

typedef union _LARGE_INTEGER {
    struct {
#ifdef WORDS_BIGENDIAN
        LONG     HighPart;
        DWORD    LowPart;
#else
        DWORD    LowPart;
        LONG     HighPart;
#endif
    } u;
#ifndef NONAMELESSSTRUCT
    struct {
#ifdef WORDS_BIGENDIAN
        LONG     HighPart;
        DWORD    LowPart;
#else
        DWORD    LowPart;
        LONG     HighPart;
#endif
    };
#endif
    LONGLONG QuadPart;
} LARGE_INTEGER, *PLARGE_INTEGER;

typedef union _ULARGE_INTEGER {
    struct {
#ifdef WORDS_BIGENDIAN
        DWORD    HighPart;
        DWORD    LowPart;
#else
        DWORD    LowPart;
        DWORD    HighPart;
#endif
    } u;
#ifndef NONAMELESSSTRUCT
    struct {
#ifdef WORDS_BIGENDIAN
        DWORD    HighPart;
        DWORD    LowPart;
#else
        DWORD    LowPart;
        DWORD    HighPart;
#endif
    };
#endif
    ULONGLONG QuadPart;
} ULARGE_INTEGER, *PULARGE_INTEGER;

/*
 * Locally Unique Identifier
 */

typedef struct _LUID {
    DWORD LowPart;
    LONG HighPart;
} LUID, *PLUID;

#include <pshpack4.h>
typedef struct _LUID_AND_ATTRIBUTES {
  LUID   Luid;
  DWORD  Attributes;
} LUID_AND_ATTRIBUTES, *PLUID_AND_ATTRIBUTES;
#include <poppack.h>

/*
 * PRIVILEGE_SET
 */

typedef struct _PRIVILEGE_SET {
    DWORD PrivilegeCount;
    DWORD Control;
    LUID_AND_ATTRIBUTES Privilege[ANYSIZE_ARRAY];
} PRIVILEGE_SET, *PPRIVILEGE_SET;

/*
 * TOKEN_PRIVILEGES
 */

typedef struct _TOKEN_PRIVILEGES {
  DWORD PrivilegeCount;
  LUID_AND_ATTRIBUTES Privileges[ANYSIZE_ARRAY];
} TOKEN_PRIVILEGES, *PTOKEN_PRIVILEGES;

/*
 * TOKEN_OWNER
 */

typedef struct _TOKEN_OWNER {
  PSID Owner;
} TOKEN_OWNER, *PTOKEN_OWNER;

/*
 * TOKEN_PRIMARY_GROUP
 */

typedef struct _TOKEN_PRIMARY_GROUP {
  PSID PrimaryGroup;
} TOKEN_PRIMARY_GROUP, *PTOKEN_PRIMARY_GROUP;


/*
 * TOKEN_DEFAULT_DACL
 */

typedef struct _TOKEN_DEFAULT_DACL {
  PACL DefaultDacl;
} TOKEN_DEFAULT_DACL, *PTOKEN_DEFAULT_DACL;

/*
 * TOKEN_SOURCE
 */

#define TOKEN_SOURCE_LENGTH 8

typedef struct _TOKEN_SOURCE {
  char SourceName[TOKEN_SOURCE_LENGTH];
  LUID SourceIdentifier;
} TOKEN_SOURCE, *PTOKEN_SOURCE;

/*
 * TOKEN_TYPE
 */

typedef enum tagTOKEN_TYPE {
  TokenPrimary = 1,
  TokenImpersonation
} TOKEN_TYPE;

/*
 * SECURITY_IMPERSONATION_LEVEL
 */

typedef enum _SECURITY_IMPERSONATION_LEVEL {
  SecurityAnonymous,
  SecurityIdentification,
  SecurityImpersonation,
  SecurityDelegation
} SECURITY_IMPERSONATION_LEVEL, *PSECURITY_IMPERSONATION_LEVEL;

#define SECURITY_DYNAMIC_TRACKING   (TRUE)
#define SECURITY_STATIC_TRACKING    (FALSE)

typedef BOOLEAN SECURITY_CONTEXT_TRACKING_MODE,
	* PSECURITY_CONTEXT_TRACKING_MODE;
/*
 *	Quality of Service
 */

typedef struct _SECURITY_QUALITY_OF_SERVICE {
  DWORD				Length;
  SECURITY_IMPERSONATION_LEVEL	ImpersonationLevel;
  SECURITY_CONTEXT_TRACKING_MODE ContextTrackingMode;
  BOOLEAN			EffectiveOnly;
} SECURITY_QUALITY_OF_SERVICE, *PSECURITY_QUALITY_OF_SERVICE;

/*
 * TOKEN_STATISTICS
 */

#include <pshpack4.h>
typedef struct _TOKEN_STATISTICS {
  LUID  TokenId;
  LUID  AuthenticationId;
  LARGE_INTEGER ExpirationTime;
  TOKEN_TYPE    TokenType;
  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
  DWORD DynamicCharged;
  DWORD DynamicAvailable;
  DWORD GroupCount;
  DWORD PrivilegeCount;
  LUID  ModifiedId;
} TOKEN_STATISTICS;
#include <poppack.h>

typedef struct _TOKEN_GROUPS_AND_PRIVILEGES {
  DWORD                 SidCount;
  DWORD                 SidLength;
  PSID_AND_ATTRIBUTES   Sids;
  DWORD                 RestrictedSidCount;
  DWORD                 RestrictedSidLength;
  PSID_AND_ATTRIBUTES   RestrictedSids;
  DWORD                 PrivilegeCount;
  DWORD                 PrivilegeLength;
  PLUID_AND_ATTRIBUTES  Privileges;
  LUID                  AuthenticationId;
} TOKEN_GROUPS_AND_PRIVILEGES, * PTOKEN_GROUPS_AND_PRIVILEGES;

typedef struct _TOKEN_ORIGIN {
  LUID  OriginatingLogonSession;
} TOKEN_ORIGIN, * PTOKEN_ORIGIN;

typedef struct _TOKEN_LINKED_TOKEN {
  HANDLE LinkedToken;
} TOKEN_LINKED_TOKEN, * PTOKEN_LINKED_TOKEN;

typedef struct _TOKEN_ELEVATION {
  DWORD TokenIsElevated;
} TOKEN_ELEVATION, * PTOKEN_ELEVATION;

typedef struct _TOKEN_MANDATORY_LABEL {
  SID_AND_ATTRIBUTES Label;
} TOKEN_MANDATORY_LABEL, * PTOKEN_MANDATORY_LABEL;

typedef struct _TOKEN_APPCONTAINER_INFORMATION {
  PSID TokenAppContainer;
} TOKEN_APPCONTAINER_INFORMATION, * PTOKEN_APPCONTAINER_INFORMATION;

/*
 *	ACLs of NT
 */

/* ACEs, directly starting after an ACL */
typedef struct _ACE_HEADER {
	BYTE	AceType;
	BYTE	AceFlags;
	WORD	AceSize;
} ACE_HEADER,*PACE_HEADER;

/* AceType */
#define	ACCESS_ALLOWED_ACE_TYPE		0
#define	ACCESS_DENIED_ACE_TYPE		1
#define	SYSTEM_AUDIT_ACE_TYPE		2
#define	SYSTEM_ALARM_ACE_TYPE		3
#define SYSTEM_MANDATORY_LABEL_ACE_TYPE 0x11

/* inherit AceFlags */
#define	OBJECT_INHERIT_ACE		0x01
#define	CONTAINER_INHERIT_ACE		0x02
#define	NO_PROPAGATE_INHERIT_ACE	0x04
#define	INHERIT_ONLY_ACE		0x08
#define	INHERITED_ACE		        0x10
#define	VALID_INHERIT_FLAGS		0x1F

/* AceFlags mask for what events we (should) audit */
#define	SUCCESSFUL_ACCESS_ACE_FLAG	0x40
#define	FAILED_ACCESS_ACE_FLAG		0x80

/* different ACEs depending on AceType
 * SidStart marks the begin of a SID
 * so the thing finally looks like this:
 * 0: ACE_HEADER
 * 4: ACCESS_MASK
 * 8... : SID
 */
typedef struct _ACCESS_ALLOWED_ACE {
	ACE_HEADER	Header;
	DWORD		Mask;
	DWORD		SidStart;
} ACCESS_ALLOWED_ACE,*PACCESS_ALLOWED_ACE;

typedef struct _ACCESS_DENIED_ACE {
	ACE_HEADER	Header;
	DWORD		Mask;
	DWORD		SidStart;
} ACCESS_DENIED_ACE,*PACCESS_DENIED_ACE;

typedef struct _SYSTEM_AUDIT_ACE {
	ACE_HEADER	Header;
	DWORD		Mask;
	DWORD		SidStart;
} SYSTEM_AUDIT_ACE,*PSYSTEM_AUDIT_ACE;

typedef struct _SYSTEM_ALARM_ACE {
	ACE_HEADER	Header;
	DWORD		Mask;
	DWORD		SidStart;
} SYSTEM_ALARM_ACE,*PSYSTEM_ALARM_ACE;

typedef struct _SYSTEM_MANDATORY_LABEL_ACE {
    ACE_HEADER  Header;
    ACCESS_MASK Mask;
    DWORD       SidStart;
} SYSTEM_MANDATORY_LABEL_ACE,*PSYSTEM_MANDATORY_LABEL_ACE;

#define SYSTEM_MANDATORY_LABEL_NO_WRITE_UP      0x1
#define SYSTEM_MANDATORY_LABEL_NO_READ_UP       0x2
#define SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP    0x4

typedef enum tagSID_NAME_USE {
	SidTypeUser = 1,
	SidTypeGroup,
	SidTypeDomain,
	SidTypeAlias,
	SidTypeWellKnownGroup,
	SidTypeDeletedAccount,
	SidTypeInvalid,
	SidTypeUnknown
} SID_NAME_USE,*PSID_NAME_USE;

#define ACE_OBJECT_TYPE_PRESENT 0x1
#define ACE_INHERITED_OBJECT_TYPE_PRESENT   0x2

/* Access rights */

/* DELETE may be already defined via /usr/include/arpa/nameser_compat.h */
#undef  DELETE
#define DELETE                     0x00010000
#define READ_CONTROL               0x00020000
#define WRITE_DAC                  0x00040000
#define WRITE_OWNER                0x00080000
#define SYNCHRONIZE                0x00100000
#define STANDARD_RIGHTS_REQUIRED   0x000f0000

#define STANDARD_RIGHTS_READ       READ_CONTROL
#define STANDARD_RIGHTS_WRITE      READ_CONTROL
#define STANDARD_RIGHTS_EXECUTE    READ_CONTROL

#define STANDARD_RIGHTS_ALL        0x001f0000

#define SPECIFIC_RIGHTS_ALL        0x0000ffff

#define GENERIC_READ               0x80000000
#define GENERIC_WRITE              0x40000000
#define GENERIC_EXECUTE            0x20000000
#define GENERIC_ALL                0x10000000

#define MAXIMUM_ALLOWED            0x02000000
#define ACCESS_SYSTEM_SECURITY     0x01000000

#define EVENT_QUERY_STATE          0x0001
#define EVENT_MODIFY_STATE         0x0002
#define EVENT_ALL_ACCESS           (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#define SEMAPHORE_QUERY_STATE      0x0001
#define SEMAPHORE_MODIFY_STATE     0x0002
#define SEMAPHORE_ALL_ACCESS       (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#define MUTANT_QUERY_STATE         0x0001
#define MUTANT_ALL_ACCESS          (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|MUTANT_QUERY_STATE)

#define JOB_OBJECT_ASSIGN_PROCESS           0x0001
#define JOB_OBJECT_SET_ATTRIBUTES           0x0002
#define JOB_OBJECT_QUERY                    0x0004
#define JOB_OBJECT_TERMINATE                0x0008
#define JOB_OBJECT_SET_SECURITY_ATTRIBUTES  0x0010
#define JOB_OBJECT_ALL_ACCESS               (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x1f)

#define TIMER_QUERY_STATE          0x0001
#define TIMER_MODIFY_STATE         0x0002
#define TIMER_ALL_ACCESS           (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#define PROCESS_TERMINATE                 0x0001
#define PROCESS_CREATE_THREAD             0x0002
#define PROCESS_VM_OPERATION              0x0008
#define PROCESS_VM_READ                   0x0010
#define PROCESS_VM_WRITE                  0x0020
#define PROCESS_DUP_HANDLE                0x0040
#define PROCESS_CREATE_PROCESS            0x0080
#define PROCESS_SET_QUOTA                 0x0100
#define PROCESS_SET_INFORMATION           0x0200
#define PROCESS_QUERY_INFORMATION         0x0400
#define PROCESS_SUSPEND_RESUME            0x0800
#define PROCESS_QUERY_LIMITED_INFORMATION 0x1000
#define PROCESS_SET_LIMITED_INFORMATION   0x2000
#define PROCESS_ALL_ACCESS         (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0xffff)

#define THREAD_TERMINATE                  0x0001
#define THREAD_SUSPEND_RESUME             0x0002
#define THREAD_GET_CONTEXT                0x0008
#define THREAD_SET_CONTEXT                0x0010
#define THREAD_SET_INFORMATION            0x0020
#define THREAD_QUERY_INFORMATION          0x0040
#define THREAD_SET_THREAD_TOKEN           0x0080
#define THREAD_IMPERSONATE                0x0100
#define THREAD_DIRECT_IMPERSONATION       0x0200
#define THREAD_SET_LIMITED_INFORMATION    0x0400
#define THREAD_QUERY_LIMITED_INFORMATION  0x0800
#define THREAD_RESUME                     0x1000
#define THREAD_ALL_ACCESS          (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0xffff)

#define THREAD_BASE_PRIORITY_LOWRT  15
#define THREAD_BASE_PRIORITY_MAX    2
#define THREAD_BASE_PRIORITY_MIN   -2
#define THREAD_BASE_PRIORITY_IDLE  -15

typedef struct _QUOTA_LIMITS {
    SIZE_T PagedPoolLimit;
    SIZE_T NonPagedPoolLimit;
    SIZE_T MinimumWorkingSetSize;
    SIZE_T MaximumWorkingSetSize;
    SIZE_T PagefileLimit;
    LARGE_INTEGER TimeLimit;
} QUOTA_LIMITS, *PQUOTA_LIMITS;

#define QUOTA_LIMITS_HARDWS_MIN_ENABLE  0x00000001
#define QUOTA_LIMITS_HARDWS_MIN_DISABLE 0x00000002
#define QUOTA_LIMITS_HARDWS_MAX_ENABLE  0x00000004
#define QUOTA_LIMITS_HARDWS_MAX_DISABLE 0x00000008

typedef struct _QUOTA_LIMITS_EX {
    SIZE_T PagedPoolLimit;
    SIZE_T NonPagedPoolLimit;
    SIZE_T MinimumWorkingSetSize;
    SIZE_T MaximumWorkingSetSize;
    SIZE_T PagefileLimit;
    LARGE_INTEGER TimeLimit;
    SIZE_T Reserved1;
    SIZE_T Reserved2;
    SIZE_T Reserved3;
    SIZE_T Reserved4;
    DWORD Flags;
    DWORD Reserved5;
} QUOTA_LIMITS_EX, *PQUOTA_LIMITS_EX;

#define SECTION_QUERY              0x0001
#define SECTION_MAP_WRITE          0x0002
#define SECTION_MAP_READ           0x0004
#define SECTION_MAP_EXECUTE        0x0008
#define SECTION_EXTEND_SIZE        0x0010
#define SECTION_MAP_EXECUTE_EXPLICIT 0x0020
#define SECTION_ALL_ACCESS         (STANDARD_RIGHTS_REQUIRED|0x01f)

#define FILE_READ_DATA            0x0001    /* file & pipe */
#define FILE_LIST_DIRECTORY       0x0001    /* directory */
#define FILE_WRITE_DATA           0x0002    /* file & pipe */
#define FILE_ADD_FILE             0x0002    /* directory */
#define FILE_APPEND_DATA          0x0004    /* file */
#define FILE_ADD_SUBDIRECTORY     0x0004    /* directory */
#define FILE_CREATE_PIPE_INSTANCE 0x0004    /* named pipe */
#define FILE_READ_EA              0x0008    /* file & directory */
#define FILE_READ_PROPERTIES      FILE_READ_EA
#define FILE_WRITE_EA             0x0010    /* file & directory */
#define FILE_WRITE_PROPERTIES     FILE_WRITE_EA
#define FILE_EXECUTE              0x0020    /* file */
#define FILE_TRAVERSE             0x0020    /* directory */
#define FILE_DELETE_CHILD         0x0040    /* directory */
#define FILE_READ_ATTRIBUTES      0x0080    /* all */
#define FILE_WRITE_ATTRIBUTES     0x0100    /* all */
#define FILE_ALL_ACCESS           (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x1ff)

#define FILE_GENERIC_READ         (STANDARD_RIGHTS_READ | FILE_READ_DATA | \
                                   FILE_READ_ATTRIBUTES | FILE_READ_EA | \
                                   SYNCHRONIZE)
#define FILE_GENERIC_WRITE        (STANDARD_RIGHTS_WRITE | FILE_WRITE_DATA | \
                                   FILE_WRITE_ATTRIBUTES | FILE_WRITE_EA | \
                                   FILE_APPEND_DATA | SYNCHRONIZE)
#define FILE_GENERIC_EXECUTE      (STANDARD_RIGHTS_EXECUTE | FILE_EXECUTE | \
                                   FILE_READ_ATTRIBUTES | SYNCHRONIZE)

#define DUPLICATE_CLOSE_SOURCE     0x00000001
#define DUPLICATE_SAME_ACCESS      0x00000002

/* File attribute flags */
#define FILE_SHARE_READ                    0x00000001
#define FILE_SHARE_WRITE                   0x00000002
#define FILE_SHARE_DELETE                  0x00000004

#define FILE_ATTRIBUTE_READONLY            0x00000001
#define FILE_ATTRIBUTE_HIDDEN              0x00000002
#define FILE_ATTRIBUTE_SYSTEM              0x00000004
#define FILE_ATTRIBUTE_DIRECTORY           0x00000010
#define FILE_ATTRIBUTE_ARCHIVE             0x00000020
#define FILE_ATTRIBUTE_DEVICE              0x00000040
#define FILE_ATTRIBUTE_NORMAL              0x00000080
#define FILE_ATTRIBUTE_TEMPORARY           0x00000100
#define FILE_ATTRIBUTE_SPARSE_FILE         0x00000200
#define FILE_ATTRIBUTE_REPARSE_POINT       0x00000400
#define FILE_ATTRIBUTE_COMPRESSED          0x00000800
#define FILE_ATTRIBUTE_OFFLINE             0x00001000
#define FILE_ATTRIBUTE_NOT_CONTENT_INDEXED 0x00002000
#define FILE_ATTRIBUTE_ENCRYPTED           0x00004000
#define FILE_ATTRIBUTE_INTEGRITY_STREAM    0x00008000
#define FILE_ATTRIBUTE_VIRTUAL             0x00010000
#define FILE_ATTRIBUTE_NO_SCRUB_DATA       0x00020000
#define FILE_ATTRIBUTE_EA                  0x00040000

/* File notification flags */
#define FILE_NOTIFY_CHANGE_FILE_NAME    0x00000001
#define FILE_NOTIFY_CHANGE_DIR_NAME     0x00000002
#define FILE_NOTIFY_CHANGE_NAME         0x00000003
#define FILE_NOTIFY_CHANGE_ATTRIBUTES   0x00000004
#define FILE_NOTIFY_CHANGE_SIZE         0x00000008
#define FILE_NOTIFY_CHANGE_LAST_WRITE   0x00000010
#define FILE_NOTIFY_CHANGE_LAST_ACCESS  0x00000020
#define FILE_NOTIFY_CHANGE_CREATION     0x00000040
#define FILE_NOTIFY_CHANGE_EA           0x00000080
#define FILE_NOTIFY_CHANGE_SECURITY     0x00000100
#define FILE_NOTIFY_CHANGE_STREAM_NAME  0x00000200
#define FILE_NOTIFY_CHANGE_STREAM_SIZE  0x00000400
#define FILE_NOTIFY_CHANGE_STREAM_WRITE 0x00000800

#define FILE_ACTION_ADDED               0x00000001
#define FILE_ACTION_REMOVED             0x00000002
#define FILE_ACTION_MODIFIED            0x00000003
#define FILE_ACTION_RENAMED_OLD_NAME    0x00000004
#define FILE_ACTION_RENAMED_NEW_NAME    0x00000005
#define FILE_ACTION_ADDED_STREAM        0x00000006
#define FILE_ACTION_REMOVED_STREAM      0x00000007
#define FILE_ACTION_MODIFIED_STREAM     0x00000008
#define FILE_ACTION_REMOVED_BY_DELETE   0x00000009
#define FILE_ACTION_ID_NOT_TUNNELLED          0x0000000a
#define FILE_ACTION_TUNNELLED_ID_COLLISION    0x0000000b

#define FILE_CASE_SENSITIVE_SEARCH      0x00000001
#define FILE_CASE_PRESERVED_NAMES       0x00000002
#define FILE_UNICODE_ON_DISK            0x00000004
#define FILE_PERSISTENT_ACLS            0x00000008
#define FILE_FILE_COMPRESSION           0x00000010
#define FILE_VOLUME_QUOTAS              0x00000020
#define FILE_SUPPORTS_SPARSE_FILES      0x00000040
#define FILE_SUPPORTS_REPARSE_POINTS    0x00000080
#define FILE_SUPPORTS_REMOTE_STORAGE    0x00000100
#define FILE_VOLUME_IS_COMPRESSED       0x00008000
#define FILE_SUPPORTS_OBJECT_IDS        0x00010000
#define FILE_SUPPORTS_ENCRYPTION        0x00020000
#define FILE_NAMED_STREAMS              0x00040000
#define FILE_READ_ONLY_VOLUME           0x00080000
#define FILE_SEQUENTIAL_WRITE_ONCE      0x00100000
#define FILE_SUPPORTS_TRANSACTIONS           0x00200000
#define FILE_SUPPORTS_HARD_LINKS             0x00400000
#define FILE_SUPPORTS_EXTENDED_ATTRIBUTES    0x00800000
#define FILE_SUPPORTS_OPEN_BY_FILE_ID        0x01000000
#define FILE_SUPPORTS_USN_JOURNAL            0x02000000
#define FILE_SUPPORTS_INTEGRITY_STREAMS      0x04000000
#define FILE_SUPPORTS_BLOCK_REFCOUNTING      0x08000000
#define FILE_SUPPORTS_SPARSE_VDL             0x10000000

/* File alignments (NT) */
#define	FILE_BYTE_ALIGNMENT		0x00000000
#define	FILE_WORD_ALIGNMENT		0x00000001
#define	FILE_LONG_ALIGNMENT		0x00000003
#define	FILE_QUAD_ALIGNMENT		0x00000007
#define	FILE_OCTA_ALIGNMENT		0x0000000f
#define	FILE_32_BYTE_ALIGNMENT		0x0000001f
#define	FILE_64_BYTE_ALIGNMENT		0x0000003f
#define	FILE_128_BYTE_ALIGNMENT		0x0000007f
#define	FILE_256_BYTE_ALIGNMENT		0x000000ff
#define	FILE_512_BYTE_ALIGNMENT		0x000001ff

#define COMPRESSION_FORMAT_NONE         0
#define COMPRESSION_FORMAT_DEFAULT      1
#define COMPRESSION_FORMAT_LZNT1        2
#define COMPRESSION_ENGINE_STANDARD     0
#define COMPRESSION_ENGINE_MAXIMUM      256

#define MAILSLOT_NO_MESSAGE             ((DWORD)-1)
#define MAILSLOT_WAIT_FOREVER           ((DWORD)-1)

#define REG_NONE		0	/* no type */
#define REG_SZ			1	/* string type (ASCII) */
#define REG_EXPAND_SZ		2	/* string, includes %ENVVAR% (expanded by caller) (ASCII) */
#define REG_BINARY		3	/* binary format, callerspecific */
/* YES, REG_DWORD == REG_DWORD_LITTLE_ENDIAN */
#define REG_DWORD		4	/* DWORD in little endian format */
#define REG_DWORD_LITTLE_ENDIAN	4	/* DWORD in little endian format */
#define REG_DWORD_BIG_ENDIAN	5	/* DWORD in big endian format  */
#define REG_LINK		6	/* symbolic link (UNICODE) */
#define REG_MULTI_SZ		7	/* multiple strings, delimited by \0, terminated by \0\0 (ASCII) */
#define REG_RESOURCE_LIST	8	/* resource list? huh? */
#define REG_FULL_RESOURCE_DESCRIPTOR	9	/* full resource descriptor? huh? */
#define REG_RESOURCE_REQUIREMENTS_LIST	10
#define REG_QWORD		11	/* QWORD in little endian format */
#define REG_QWORD_LITTLE_ENDIAN	11	/* QWORD in little endian format */

/* ----------------------------- begin power management --------------------- */

typedef enum _LATENCY_TIME {
	LT_DONT_CARE,
	LT_LOWEST_LATENCY
} LATENCY_TIME, *PLATENCY_TIME;

#define DISCHARGE_POLICY_CRITICAL 	0
#define DISCHARGE_POLICY_LOW		1
#define NUM_DISCHARGE_POLICIES		4

#define PO_THROTTLE_NONE		0
#define PO_THROTTLE_CONSTANT		1
#define PO_THROTTLE_DEGRADE		2
#define PO_THROTTLE_ADAPTIVE		3

typedef enum _POWER_ACTION {
	PowerActionNone = 0,
	PowerActionReserved,
	PowerActionSleep,
	PowerActionHibernate,
	PowerActionShutdown,
	PowerActionShutdownReset,
	PowerActionShutdownOff,
	PowerActionWarmEject
} POWER_ACTION,
*PPOWER_ACTION;

typedef enum _POWER_PLATFORM_ROLE {
    PlatformRoleUnspecified,
    PlatformRoleDesktop,
    PlatformRoleMobile,
    PlatformRoleWorkstation,
    PlatformRoleEnterpriseServer,
    PlatformRoleSOHOServer,
    PlatformRoleAppliancePC,
    PlatformRolePerformanceServer,
    PlatformRoleSlate,
    PlatformRoleMaximum
} POWER_PLATFORM_ROLE, *PPOWER_PLATFORM_ROLE;

typedef enum _SYSTEM_POWER_STATE {
	PowerSystemUnspecified = 0,
	PowerSystemWorking = 1,
	PowerSystemSleeping1 = 2,
	PowerSystemSleeping2 = 3,
	PowerSystemSleeping3 = 4,
	PowerSystemHibernate = 5,
	PowerSystemShutdown = 6,
	PowerSystemMaximum = 7
} SYSTEM_POWER_STATE,
*PSYSTEM_POWER_STATE;

typedef enum _DEVICE_POWER_STATE {
    PowerDeviceUnspecified,
    PowerDeviceD0,
    PowerDeviceD1,
    PowerDeviceD2,
    PowerDeviceD3,
    PowerDeviceMaximum
} DEVICE_POWER_STATE, *PDEVICE_POWER_STATE;

typedef enum _POWER_INFORMATION_LEVEL {
        SystemPowerPolicyAc,
        SystemPowerPolicyDc,
        VerifySystemPolicyAc,
        VerifySystemPolicyDc,
        SystemPowerCapabilities,
        SystemBatteryState,
        SystemPowerStateHandler,
        ProcessorStateHandler,
        SystemPowerPolicyCurrent,
        AdministratorPowerPolicy,
        SystemReserveHiberFile,
        ProcessorInformation,
        SystemPowerInformation,
        ProcessorStateHandler2,
        LastWakeTime,
        LastSleepTime,
        SystemExecutionState,
        SystemPowerStateNotifyHandler,
        ProcessorPowerPolicyAc,
        ProcessorPowerPolicyDc,
        VerifyProcessorPowerPolicyAc,
        VerifyProcessorPowerPolicyDc,
        ProcessorPowerPolicyCurrent
} POWER_INFORMATION_LEVEL;

typedef struct _ADMINISTRATOR_POWER_POLICY {
	SYSTEM_POWER_STATE MinSleep;
	SYSTEM_POWER_STATE MaxSleep;
	ULONG MinVideoTimeout;
	ULONG MaxVideoTimeout;
	ULONG MinSpindownTimeout;
	ULONG MaxSpindownTimeout;
} ADMINISTRATOR_POWER_POLICY, *PADMINISTRATOR_POWER_POLICY;

typedef struct {
	ULONG Granularity;
	ULONG Capacity;
} BATTERY_REPORTING_SCALE,
*PBATTERY_REPORTING_SCALE;

typedef struct {
	POWER_ACTION Action;
	ULONG Flags;
	ULONG EventCode;
} POWER_ACTION_POLICY,
*PPOWER_ACTION_POLICY;

typedef struct _PROCESSOR_POWER_INFORMATION {
	ULONG Number;
	ULONG MaxMhz;
	ULONG CurrentMhz;
	ULONG MhzLimit;
	ULONG MaxIdleState;
	ULONG CurrentIdleState;
} PROCESSOR_POWER_INFORMATION,
*PPROCESSOR_POWER_INFORMATION;

typedef struct _PROCESSOR_POWER_POLICY_INFO {
	ULONG TimeCheck;
	ULONG DemoteLimit;
	ULONG PromoteLimit;
	UCHAR DemotePercent;
	UCHAR PromotePercent;
	UCHAR Spare[2];
	ULONG AllowDemotion:1;
	ULONG AllowPromotion:1;
	ULONG Reserved:30;
} PROCESSOR_POWER_POLICY_INFO,
*PPROCESSOR_POWER_POLICY_INFO;

typedef struct _PROCESSOR_POWER_POLICY {
	DWORD Revision;
	BYTE DynamicThrottle;
	BYTE Spare[3];
	DWORD DisableCStates:1;
	DWORD Reserved:31;
	DWORD PolicyCount;
	PROCESSOR_POWER_POLICY_INFO Policy[3];
} PROCESSOR_POWER_POLICY,
*PPROCESSOR_POWER_POLICY;

typedef struct {
	BOOLEAN AcOnLine;
	BOOLEAN BatteryPresent;
	BOOLEAN Charging;
	BOOLEAN Discharging;
	BOOLEAN Spare1[4];
	ULONG MaxCapacity;
	ULONG RemainingCapacity;
	ULONG Rate;
	ULONG EstimatedTime;
	ULONG DefaultAlert1;
	ULONG DefaultAlert2;
} SYSTEM_BATTERY_STATE,
*PSYSTEM_BATTERY_STATE;

typedef struct {
	BOOLEAN PowerButtonPresent;
	BOOLEAN SleepButtonPresent;
	BOOLEAN LidPresent;
	BOOLEAN SystemS1;
	BOOLEAN SystemS2;
	BOOLEAN SystemS3;
	BOOLEAN SystemS4;
	BOOLEAN SystemS5;
	BOOLEAN HiberFilePresent;
	BOOLEAN FullWake;
	BOOLEAN VideoDimPresent;
	BOOLEAN ApmPresent;
	BOOLEAN UpsPresent;
	BOOLEAN ThermalControl;
	BOOLEAN ProcessorThrottle;
	UCHAR ProcessorMinThrottle;
	UCHAR ProcessorMaxThrottle;
	UCHAR spare2[4];
	BOOLEAN DiskSpinDown;
	UCHAR spare3[8];
	BOOLEAN SystemBatteriesPresent;
	BOOLEAN BatteriesAreShortTerm;
	BATTERY_REPORTING_SCALE BatteryScale[3];
	SYSTEM_POWER_STATE AcOnLineWake;
	SYSTEM_POWER_STATE SoftLidWake;
	SYSTEM_POWER_STATE RtcWake;
	SYSTEM_POWER_STATE MinDeviceWakeState;
	SYSTEM_POWER_STATE DefaultLowLatencyWake;
} SYSTEM_POWER_CAPABILITIES,
*PSYSTEM_POWER_CAPABILITIES;

typedef struct _SYSTEM_POWER_INFORMATION {
	ULONG MaxIdlenessAllowed;
	ULONG Idleness;
	ULONG TimeRemaining;
	UCHAR CoolingMode;
} SYSTEM_POWER_INFORMATION,
*PSYSTEM_POWER_INFORMATION;

typedef struct _SYSTEM_POWER_LEVEL {
	BOOLEAN Enable;
	UCHAR Spare[3];
	ULONG BatteryLevel;
	POWER_ACTION_POLICY PowerPolicy;
	SYSTEM_POWER_STATE MinSystemState;
} SYSTEM_POWER_LEVEL,
*PSYSTEM_POWER_LEVEL;

typedef struct _SYSTEM_POWER_POLICY {
	ULONG Revision;
	POWER_ACTION_POLICY PowerButton;
	POWER_ACTION_POLICY SleepButton;
	POWER_ACTION_POLICY LidClose;
	SYSTEM_POWER_STATE LidOpenWake;
	ULONG Reserved;
	POWER_ACTION_POLICY Idle;
	ULONG IdleTimeout;
	UCHAR IdleSensitivity;
	UCHAR DynamicThrottle;
	UCHAR Spare2[2];
	SYSTEM_POWER_STATE MinSleep;
	SYSTEM_POWER_STATE MaxSleep;
	SYSTEM_POWER_STATE ReducedLatencySleep;
	ULONG WinLogonFlags;
	ULONG Spare3;
	ULONG DozeS4Timeout;
	ULONG BroadcastCapacityResolution;
	SYSTEM_POWER_LEVEL DischargePolicy[NUM_DISCHARGE_POLICIES];
	ULONG VideoTimeout;
	BOOLEAN VideoDimDisplay;
	ULONG VideoReserved[3];
	ULONG SpindownTimeout;
	BOOLEAN OptimizeForPower;
	UCHAR FanThrottleTolerance;
	UCHAR ForcedThrottle;
	UCHAR MinThrottle;
	POWER_ACTION_POLICY OverThrottled;
} SYSTEM_POWER_POLICY,
*PSYSTEM_POWER_POLICY;

typedef union _FILE_SEGMENT_ELEMENT {
	PVOID64 Buffer;
	ULONGLONG Alignment;
} FILE_SEGMENT_ELEMENT, *PFILE_SEGMENT_ELEMENT;

typedef struct _FILE_NOTIFY_INFORMATION {
	DWORD NextEntryOffset;
	DWORD Action;
	DWORD FileNameLength;
	WCHAR FileName[1];
} FILE_NOTIFY_INFORMATION, *PFILE_NOTIFY_INFORMATION;

/* ----------------------------- begin tape storage --------------------- */

#define TAPE_FIXED_PARTITIONS     0
#define TAPE_SELECT_PARTITIONS    1
#define TAPE_INITIATOR_PARTITIONS 2
#define TAPE_ERASE_SHORT 0
#define TAPE_ERASE_LONG  1
#define TAPE_LOAD    0
#define TAPE_UNLOAD  1
#define TAPE_TENSION 2
#define TAPE_LOCK    3
#define TAPE_UNLOCK  4
#define TAPE_FORMAT  5
#define TAPE_SETMARKS  0
#define TAPE_FILEMARKS 1
#define TAPE_SHORT_FILEMARKS 2
#define TAPE_LONG_FILEMARKS  3
#define TAPE_REWIND                0
#define TAPE_ABSOLUTE_BLOCK        1
#define TAPE_LOGICAL_BLOCK         2
#define TAPE_PSEUDO_LOGICAL_BLOCK  3
#define TAPE_SPACE_END_OF_DATA     4
#define TAPE_SPACE_RELATIVE_BLOCKS 5
#define TAPE_SPACE_FILEMARKS       6
#define TAPE_SPACE_SEQUENTIAL_FMKS 7
#define TAPE_SPACE_SETMARKS        8
#define TAPE_SPACE_SEQUENTIAL_SMKS 9

typedef struct _TAPE_CREATE_PARTITION {
    DWORD Method;
    DWORD Count;
    DWORD Size;
} TAPE_CREATE_PARTITION, *PTAPE_CREATE_PARTITION;

typedef struct _TAPE_ERASE {
    DWORD Type;
    BOOLEAN Immediate;
} TAPE_ERASE, *PTAPE_ERASE;

typedef struct _TAPE_PREPARE {
    DWORD Operation;
    BOOLEAN Immediate;
} TAPE_PREPARE, *PTAPE_PREPARE;

typedef struct _TAPE_SET_DRIVE_PARAMETERS {
    BOOLEAN ECC;
    BOOLEAN Compression;
    BOOLEAN DataPadding;
    BOOLEAN ReportSetmarks;
    ULONG EOTWarningZoneSize;
} TAPE_SET_DRIVE_PARAMETERS, *PTAPE_SET_DRIVE_PARAMETERS;

typedef struct _TAPE_SET_MEDIA_PARAMETERS {
    ULONG BlockSize;
} TAPE_SET_MEDIA_PARAMETERS, *PTAPE_SET_MEDIA_PARAMETERS;

typedef struct _TAPE_WRITE_MARKS {
    DWORD Type;
    DWORD Count;
    BOOLEAN Immediate;
} TAPE_WRITE_MARKS, *PTAPE_WRITE_MARKS;

typedef struct _TAPE_GET_POSITION {
    ULONG Type;
    ULONG Partition;
    ULONG OffsetLow;
    ULONG OffsetHigh;
} TAPE_GET_POSITION, *PTAPE_GET_POSITION;

typedef struct _TAPE_SET_POSITION {
    ULONG Method;
    ULONG Partition;
    LARGE_INTEGER Offset;
    BOOLEAN Immediate;
} TAPE_SET_POSITION, *PTAPE_SET_POSITION;

typedef struct _TAPE_GET_DRIVE_PARAMETERS {
    BOOLEAN ECC;
    BOOLEAN Compression;
    BOOLEAN DataPadding;
    BOOLEAN ReportSetmarks;
    DWORD DefaultBlockSize;
    DWORD MaximumBlockSize;
    DWORD MinimumBlockSize;
    DWORD MaximumPartitionCount;
    DWORD FeaturesLow;
    DWORD FeaturesHigh;
    DWORD EOTWarningZoneSize;
} TAPE_GET_DRIVE_PARAMETERS, *PTAPE_GET_DRIVE_PARAMETERS;

typedef struct _TAPE_GET_MEDIA_PARAMETERS {
    LARGE_INTEGER Capacity;
    LARGE_INTEGER Remaining;
    DWORD BlockSize;
    DWORD PartitionCount;
    BOOLEAN WriteProtected;
} TAPE_GET_MEDIA_PARAMETERS, *PTAPE_GET_MEDIA_PARAMETERS;

/* ----------------------------- begin registry ----------------------------- */

/* Registry security values */
#define OWNER_SECURITY_INFORMATION      0x00000001
#define GROUP_SECURITY_INFORMATION      0x00000002
#define DACL_SECURITY_INFORMATION       0x00000004
#define SACL_SECURITY_INFORMATION       0x00000008
#define LABEL_SECURITY_INFORMATION      0x00000010

#define REG_OPTION_RESERVED             0x00000000
#define REG_OPTION_NON_VOLATILE         0x00000000
#define REG_OPTION_VOLATILE             0x00000001
#define REG_OPTION_CREATE_LINK          0x00000002
#define REG_OPTION_BACKUP_RESTORE       0x00000004 /* FIXME */
#define REG_OPTION_OPEN_LINK            0x00000008
#define REG_LEGAL_OPTION               (REG_OPTION_RESERVED | \
                                        REG_OPTION_NON_VOLATILE | \
                                        REG_OPTION_VOLATILE | \
                                        REG_OPTION_CREATE_LINK | \
                                        REG_OPTION_BACKUP_RESTORE | \
                                        REG_OPTION_OPEN_LINK)


#define REG_CREATED_NEW_KEY	0x00000001
#define REG_OPENED_EXISTING_KEY	0x00000002

/* For RegNotifyChangeKeyValue */
#define REG_NOTIFY_CHANGE_NAME       0x01
#define REG_NOTIFY_CHANGE_ATTRIBUTES 0x02
#define REG_NOTIFY_CHANGE_LAST_SET   0x04
#define REG_NOTIFY_CHANGE_SECURITY   0x08

#define KEY_QUERY_VALUE		0x00000001
#define KEY_SET_VALUE		0x00000002
#define KEY_CREATE_SUB_KEY	0x00000004
#define KEY_ENUMERATE_SUB_KEYS	0x00000008
#define KEY_NOTIFY		0x00000010
#define KEY_CREATE_LINK		0x00000020
#define KEY_WOW64_64KEY         0x00000100
#define KEY_WOW64_32KEY         0x00000200
#define KEY_WOW64_RES           0x00000300

/* for RegKeyRestore flags */
#define REG_WHOLE_HIVE_VOLATILE 0x00000001
#define REG_REFRESH_HIVE        0x00000002
#define REG_NO_LAZY_FLUSH       0x00000004
#define REG_FORCE_RESTORE       0x00000008

#define KEY_READ	      ((STANDARD_RIGHTS_READ|  \
				KEY_QUERY_VALUE|  \
				KEY_ENUMERATE_SUB_KEYS|  \
				KEY_NOTIFY)  \
				& (~SYNCHRONIZE)  \
			      )
#define KEY_WRITE	      ((STANDARD_RIGHTS_WRITE|  \
				KEY_SET_VALUE|  \
				KEY_CREATE_SUB_KEY)  \
				& (~SYNCHRONIZE)  \
			      )
#define KEY_EXECUTE           ((KEY_READ) & (~SYNCHRONIZE))
#define KEY_ALL_ACCESS        ((STANDARD_RIGHTS_ALL|  \
				KEY_QUERY_VALUE|  \
				KEY_SET_VALUE|  \
				KEY_CREATE_SUB_KEY|  \
				KEY_ENUMERATE_SUB_KEYS|  \
				KEY_NOTIFY|  \
				KEY_CREATE_LINK)  \
				& (~SYNCHRONIZE)  \
			      )
/* ------------------------------ end registry ------------------------------ */


#define EVENTLOG_SUCCESS                0x0000
#define EVENTLOG_ERROR_TYPE             0x0001
#define EVENTLOG_WARNING_TYPE           0x0002
#define EVENTLOG_INFORMATION_TYPE       0x0004
#define EVENTLOG_AUDIT_SUCCESS          0x0008
#define EVENTLOG_AUDIT_FAILURE          0x0010

#define EVENTLOG_SEQUENTIAL_READ        0x0001
#define EVENTLOG_SEEK_READ              0x0002
#define EVENTLOG_FORWARDS_READ          0x0004
#define EVENTLOG_BACKWARDS_READ         0x0008

typedef struct _EVENTLOGRECORD {
    DWORD  Length;
    DWORD  Reserved;
    DWORD  RecordNumber;
    DWORD  TimeGenerated;
    DWORD  TimeWritten;
    DWORD  EventID;
    WORD   EventType;
    WORD   NumStrings;
    WORD   EventCategory;
    WORD   ReservedFlags;
    DWORD  ClosingRecordNumber;
    DWORD  StringOffset;
    DWORD  UserSidLength;
    DWORD  UserSidOffset;
    DWORD  DataLength;
    DWORD  DataOffset;
} EVENTLOGRECORD, *PEVENTLOGRECORD;

#define SERVICE_BOOT_START   0x00000000
#define SERVICE_SYSTEM_START 0x00000001
#define SERVICE_AUTO_START   0x00000002
#define SERVICE_DEMAND_START 0x00000003
#define SERVICE_DISABLED     0x00000004

#define SERVICE_ERROR_IGNORE   0x00000000
#define SERVICE_ERROR_NORMAL   0x00000001
#define SERVICE_ERROR_SEVERE   0x00000002
#define SERVICE_ERROR_CRITICAL 0x00000003

/* Service types */
#define SERVICE_KERNEL_DRIVER      0x00000001
#define SERVICE_FILE_SYSTEM_DRIVER 0x00000002
#define SERVICE_ADAPTER            0x00000004
#define SERVICE_RECOGNIZER_DRIVER  0x00000008

#define SERVICE_DRIVER ( SERVICE_KERNEL_DRIVER | SERVICE_FILE_SYSTEM_DRIVER | \
                         SERVICE_RECOGNIZER_DRIVER )

#define SERVICE_WIN32_OWN_PROCESS   0x00000010
#define SERVICE_WIN32_SHARE_PROCESS 0x00000020
#define SERVICE_WIN32  (SERVICE_WIN32_OWN_PROCESS | SERVICE_WIN32_SHARE_PROCESS)

#define SERVICE_INTERACTIVE_PROCESS 0x00000100

#define SERVICE_TYPE_ALL ( SERVICE_WIN32 | SERVICE_ADAPTER | \
                           SERVICE_DRIVER | SERVICE_INTERACTIVE_PROCESS )


typedef enum _CM_SERVICE_NODE_TYPE
{
  DriverType               = SERVICE_KERNEL_DRIVER,
  FileSystemType           = SERVICE_FILE_SYSTEM_DRIVER,
  Win32ServiceOwnProcess   = SERVICE_WIN32_OWN_PROCESS,
  Win32ServiceShareProcess = SERVICE_WIN32_SHARE_PROCESS,
  AdapterType              = SERVICE_ADAPTER,
  RecognizerType           = SERVICE_RECOGNIZER_DRIVER
} SERVICE_NODE_TYPE;

typedef enum _CM_SERVICE_LOAD_TYPE
{
  BootLoad    = SERVICE_BOOT_START,
  SystemLoad  = SERVICE_SYSTEM_START,
  AutoLoad    = SERVICE_AUTO_START,
  DemandLoad  = SERVICE_DEMAND_START,
  DisableLoad = SERVICE_DISABLED
} SERVICE_LOAD_TYPE;

typedef enum _CM_ERROR_CONTROL_TYPE
{
  IgnoreError   = SERVICE_ERROR_IGNORE,
  NormalError   = SERVICE_ERROR_NORMAL,
  SevereError   = SERVICE_ERROR_SEVERE,
  CriticalError = SERVICE_ERROR_CRITICAL
} SERVICE_ERROR_TYPE;



#define RtlEqualMemory(Destination, Source, Length) (!memcmp((Destination),(Source),(Length)))
#define RtlMoveMemory(Destination, Source, Length) memmove((Destination),(Source),(Length))
#define RtlCopyMemory(Destination, Source, Length) memcpy((Destination),(Source),(Length))
#define RtlFillMemory(Destination, Length, Fill) memset((Destination),(Fill),(Length))
#define RtlZeroMemory(Destination, Length) memset((Destination),0,(Length))

static FORCEINLINE void *RtlSecureZeroMemory(void *buffer, SIZE_T length)
{
    volatile char *ptr = (volatile char *)buffer;

    while (length--) *ptr++ = 0;
    return buffer;
}

#include <guiddef.h>

typedef struct _OBJECT_TYPE_LIST {
    WORD   Level;
    WORD   Sbz;
    GUID *ObjectType;
} OBJECT_TYPE_LIST, *POBJECT_TYPE_LIST;

typedef struct _RTL_CRITICAL_SECTION_DEBUG
{
  WORD   Type;
  WORD   CreatorBackTraceIndex;
  struct _RTL_CRITICAL_SECTION *CriticalSection;
  LIST_ENTRY ProcessLocksList;
  DWORD EntryCount;
  DWORD ContentionCount;
#ifdef __WINESRC__  /* in Wine we store the name here */
  DWORD_PTR Spare[8/sizeof(DWORD_PTR)];
#else
  DWORD Spare[ 2 ];
#endif
} RTL_CRITICAL_SECTION_DEBUG, *PRTL_CRITICAL_SECTION_DEBUG, RTL_RESOURCE_DEBUG, *PRTL_RESOURCE_DEBUG;

typedef struct _RTL_CRITICAL_SECTION {
    PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    ULONG_PTR SpinCount;
}  RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION;

#define RTL_CRITICAL_SECTION_FLAG_NO_DEBUG_INFO 0x1000000
#define RTL_CRITICAL_SECTION_FLAG_DYNAMIC_SPIN  0x2000000
#define RTL_CRITICAL_SECTION_FLAG_STATIC_INIT   0x4000000
#define RTL_CRITICAL_SECTION_ALL_FLAG_BITS      0xFF000000
#define RTL_CRITICAL_SECTION_FLAG_RESERVED      (RTL_CRITICAL_SECTION_ALL_FLAG_BITS & ~0x7000000)

typedef struct _RTL_SRWLOCK {
    PVOID Ptr;
} RTL_SRWLOCK, *PRTL_SRWLOCK;

#define RTL_SRWLOCK_INIT {0}

typedef struct _RTL_CONDITION_VARIABLE {
    PVOID Ptr;
} RTL_CONDITION_VARIABLE, *PRTL_CONDITION_VARIABLE;
#define RTL_CONDITION_VARIABLE_INIT {0}
#define RTL_CONDITION_VARIABLE_LOCKMODE_SHARED  0x1

typedef VOID (NTAPI * WAITORTIMERCALLBACKFUNC) (PVOID, BOOLEAN );
typedef VOID (NTAPI * PFLS_CALLBACK_FUNCTION) ( PVOID );

#define RTL_RUN_ONCE_INIT {0}
typedef union _RTL_RUN_ONCE {
    PVOID Ptr;
} RTL_RUN_ONCE, *PRTL_RUN_ONCE;

#define RTL_RUN_ONCE_CHECK_ONLY     0x00000001
#define RTL_RUN_ONCE_ASYNC          0x00000002
#define RTL_RUN_ONCE_INIT_FAILED    0x00000004

typedef DWORD WINAPI RTL_RUN_ONCE_INIT_FN(PRTL_RUN_ONCE, PVOID, PVOID*);
typedef RTL_RUN_ONCE_INIT_FN *PRTL_RUN_ONCE_INIT_FN;
NTSYSAPI VOID WINAPI RtlRunOnceInitialize(PRTL_RUN_ONCE);
NTSYSAPI DWORD WINAPI RtlRunOnceExecuteOnce(PRTL_RUN_ONCE,PRTL_RUN_ONCE_INIT_FN,PVOID,PVOID*);
NTSYSAPI DWORD WINAPI RtlRunOnceBeginInitialize(PRTL_RUN_ONCE, DWORD, PVOID*);
NTSYSAPI DWORD WINAPI RtlRunOnceComplete(PRTL_RUN_ONCE, DWORD, PVOID);

#include <pshpack8.h>
typedef struct _IO_COUNTERS {
    ULONGLONG DECLSPEC_ALIGN(8) ReadOperationCount;
    ULONGLONG DECLSPEC_ALIGN(8) WriteOperationCount;
    ULONGLONG DECLSPEC_ALIGN(8) OtherOperationCount;
    ULONGLONG DECLSPEC_ALIGN(8) ReadTransferCount;
    ULONGLONG DECLSPEC_ALIGN(8) WriteTransferCount;
    ULONGLONG DECLSPEC_ALIGN(8) OtherTransferCount;
} IO_COUNTERS, *PIO_COUNTERS;
#include <poppack.h>

typedef struct {
	DWORD dwOSVersionInfoSize;
	DWORD dwMajorVersion;
	DWORD dwMinorVersion;
	DWORD dwBuildNumber;
	DWORD dwPlatformId;
	CHAR szCSDVersion[128];
} OSVERSIONINFOA, *POSVERSIONINFOA, *LPOSVERSIONINFOA;

typedef struct {
	DWORD dwOSVersionInfoSize;
	DWORD dwMajorVersion;
	DWORD dwMinorVersion;
	DWORD dwBuildNumber;
	DWORD dwPlatformId;
	WCHAR szCSDVersion[128];
} OSVERSIONINFOW, *POSVERSIONINFOW, *LPOSVERSIONINFOW, RTL_OSVERSIONINFOW, *PRTL_OSVERSIONINFOW;

DECL_WINELIB_TYPE_AW(OSVERSIONINFO)
DECL_WINELIB_TYPE_AW(POSVERSIONINFO)
DECL_WINELIB_TYPE_AW(LPOSVERSIONINFO)

typedef struct {
	DWORD dwOSVersionInfoSize;
	DWORD dwMajorVersion;
	DWORD dwMinorVersion;
	DWORD dwBuildNumber;
	DWORD dwPlatformId;
	CHAR szCSDVersion[128];
	WORD wServicePackMajor;
	WORD wServicePackMinor;
	WORD wSuiteMask;
	BYTE wProductType;
	BYTE wReserved;
} OSVERSIONINFOEXA, *POSVERSIONINFOEXA, *LPOSVERSIONINFOEXA;

typedef struct {
	DWORD dwOSVersionInfoSize;
	DWORD dwMajorVersion;
	DWORD dwMinorVersion;
	DWORD dwBuildNumber;
	DWORD dwPlatformId;
	WCHAR szCSDVersion[128];
	WORD wServicePackMajor;
	WORD wServicePackMinor;
	WORD wSuiteMask;
	BYTE wProductType;
	BYTE wReserved;
} OSVERSIONINFOEXW, *POSVERSIONINFOEXW, *LPOSVERSIONINFOEXW, RTL_OSVERSIONINFOEXW, *PRTL_OSVERSIONINFOEXW;

DECL_WINELIB_TYPE_AW(OSVERSIONINFOEX)
DECL_WINELIB_TYPE_AW(POSVERSIONINFOEX)
DECL_WINELIB_TYPE_AW(LPOSVERSIONINFOEX)

NTSYSAPI ULONGLONG WINAPI VerSetConditionMask(ULONGLONG,DWORD,BYTE);

#define VER_SET_CONDITION(_m_,_t_,_c_) ((_m_)=VerSetConditionMask((_m_),(_t_),(_c_)))

#define VER_PLATFORM_WIN32s                     0
#define VER_PLATFORM_WIN32_WINDOWS              1
#define VER_PLATFORM_WIN32_NT                   2

#define	VER_MINORVERSION			0x00000001
#define	VER_MAJORVERSION			0x00000002
#define	VER_BUILDNUMBER				0x00000004
#define	VER_PLATFORMID				0x00000008
#define	VER_SERVICEPACKMINOR			0x00000010
#define	VER_SERVICEPACKMAJOR			0x00000020
#define	VER_SUITENAME				0x00000040
#define	VER_PRODUCT_TYPE			0x00000080

#define	VER_NT_WORKSTATION			1
#define	VER_NT_DOMAIN_CONTROLLER		2
#define	VER_NT_SERVER				3

#define	VER_SUITE_SMALLBUSINESS			0x00000001
#define	VER_SUITE_ENTERPRISE			0x00000002
#define	VER_SUITE_BACKOFFICE			0x00000004
#define	VER_SUITE_COMMUNICATIONS		0x00000008
#define	VER_SUITE_TERMINAL			0x00000010
#define	VER_SUITE_SMALLBUSINESS_RESTRICTED	0x00000020
#define	VER_SUITE_EMBEDDEDNT			0x00000040
#define	VER_SUITE_DATACENTER			0x00000080
#define	VER_SUITE_SINGLEUSERTS			0x00000100
#define	VER_SUITE_PERSONAL			0x00000200
#define	VER_SUITE_BLADE				0x00000400
#define	VER_SUITE_EMBEDDED_RESTRICTED		0x00000800
#define	VER_SUITE_SECURITY_APPLIANCE		0x00001000
#define VER_SUITE_STORAGE_SERVER                0x00002000
#define VER_SUITE_COMPUTE_SERVER                0x00004000
#define VER_SUITE_WH_SERVER                     0x00008000

#define	VER_EQUAL				1
#define	VER_GREATER				2
#define	VER_GREATER_EQUAL			3
#define	VER_LESS				4
#define	VER_LESS_EQUAL				5
#define	VER_AND					6
#define	VER_OR					7

typedef struct _ACTIVATION_CONTEXT_DETAILED_INFORMATION {
    DWORD dwFlags;
    DWORD ulFormatVersion;
    DWORD ulAssemblyCount;
    DWORD ulRootManifestPathType;
    DWORD ulRootManifestPathChars;
    DWORD ulRootConfigurationPathType;
    DWORD ulRootConfigurationPathChars;
    DWORD ulAppDirPathType;
    DWORD ulAppDirPathChars;
    PCWSTR lpRootManifestPath;
    PCWSTR lpRootConfigurationPath;
    PCWSTR lpAppDirPath;
} ACTIVATION_CONTEXT_DETAILED_INFORMATION, *PACTIVATION_CONTEXT_DETAILED_INFORMATION;

typedef struct _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION {
    DWORD ulFlags;
    DWORD ulEncodedAssemblyIdentityLength;
    DWORD ulManifestPathType;
    DWORD ulManifestPathLength;
    LARGE_INTEGER liManifestLastWriteTime;
    DWORD ulPolicyPathType;
    DWORD ulPolicyPathLength;
    LARGE_INTEGER liPolicyLastWriteTime;
    DWORD ulMetadataSatelliteRosterIndex;
    DWORD ulManifestVersionMajor;
    DWORD ulManifestVersionMinor;
    DWORD ulPolicyVersionMajor;
    DWORD ulPolicyVersionMinor;
    DWORD ulAssemblyDirectoryNameLength;
    PCWSTR lpAssemblyEncodedAssemblyIdentity;
    PCWSTR lpAssemblyManifestPath;
    PCWSTR lpAssemblyPolicyPath;
    PCWSTR lpAssemblyDirectoryName;
    DWORD  ulFileCount;
} ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION, *PACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

typedef struct _ACTIVATION_CONTEXT_QUERY_INDEX {
    DWORD ulAssemblyIndex;
    DWORD ulFileIndexInAssembly;
} ACTIVATION_CONTEXT_QUERY_INDEX, *PACTIVATION_CONTEXT_QUERY_INDEX;

typedef const struct _ACTIVATION_CONTEXT_QUERY_INDEX *PCACTIVATION_CONTEXT_QUERY_INDEX;

typedef struct _ASSEMBLY_FILE_DETAILED_INFORMATION {
    DWORD ulFlags;
    DWORD ulFilenameLength;
    DWORD ulPathLength;
    PCWSTR lpFileName;
    PCWSTR lpFilePath;
} ASSEMBLY_FILE_DETAILED_INFORMATION, *PASSEMBLY_FILE_DETAILED_INFORMATION;

typedef const ASSEMBLY_FILE_DETAILED_INFORMATION *PCASSEMBLY_FILE_DETAILED_INFORMATION;

typedef enum _ACTIVATION_CONTEXT_INFO_CLASS {
    ActivationContextBasicInformation                       = 1,
    ActivationContextDetailedInformation                    = 2,
    AssemblyDetailedInformationInActivationContext          = 3,
    FileInformationInAssemblyOfAssemblyInActivationContext  = 4,
    MaxActivationContextInfoClass,

    AssemblyDetailedInformationInActivationContxt          = 3,
    FileInformationInAssemblyOfAssemblyInActivationContxt  = 4
} ACTIVATION_CONTEXT_INFO_CLASS;

#define ACTIVATION_CONTEXT_PATH_TYPE_NONE         1
#define ACTIVATION_CONTEXT_PATH_TYPE_WIN32_FILE   2
#define ACTIVATION_CONTEXT_PATH_TYPE_URL          3
#define ACTIVATION_CONTEXT_PATH_TYPE_ASSEMBLYREF  4

#define ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION          1
#define ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION               2
#define ACTIVATION_CONTEXT_SECTION_WINDOW_CLASS_REDIRECTION      3
#define ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION        4
#define ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION     5
#define ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION  6
#define ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION        7
#define ACTIVATION_CONTEXT_SECTION_GLOBAL_OBJECT_RENAME_TABLE    8
#define ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES                9

typedef enum _JOBOBJECTINFOCLASS
{
    JobObjectBasicAccountingInformation = 1,
    JobObjectBasicLimitInformation,
    JobObjectBasicProcessIdList,
    JobObjectBasicUIRestrictions,
    JobObjectSecurityLimitInformation,
    JobObjectEndOfJobTimeInformation,
    JobObjectAssociateCompletionPortInformation,
    JobObjectBasicAndIoAccountingInformation,
    JobObjectExtendedLimitInformation,
    JobObjectJobSetInformation,
    MaxJobObjectInfoClass
} JOBOBJECTINFOCLASS;

typedef struct _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION {
    LARGE_INTEGER TotalUserTime;
    LARGE_INTEGER TotalKernelTime;
    LARGE_INTEGER ThisPeriodTotalUserTime;
    LARGE_INTEGER ThisPeriodTotalKernelTime;
    DWORD         TotalPageFaultCount;
    DWORD         TotalProcesses;
    DWORD         ActiveProcesses;
    DWORD         TotalTerminatedProcesses;
} JOBOBJECT_BASIC_ACCOUNTING_INFORMATION, *PJOBOBJECT_BASIC_ACCOUNTING_INFORMATION;

typedef struct _JOBOBJECT_BASIC_LIMIT_INFORMATION {
    LARGE_INTEGER PerProcessUserTimeLimit;
    LARGE_INTEGER PerJobUserTimeLimit;
    DWORD         LimitFlags;
    SIZE_T        MinimumWorkingSetSize;
    SIZE_T        MaximumWorkingSetSize;
    DWORD         ActiveProcessLimit;
    ULONG_PTR     Affinity;
    DWORD         PriorityClass;
    DWORD         SchedulingClass;
} JOBOBJECT_BASIC_LIMIT_INFORMATION, *PJOBOBJECT_BASIC_LIMIT_INFORMATION;

typedef struct _JOBOBJECT_BASIC_PROCESS_ID_LIST {
    DWORD     NumberOfAssignedProcesses;
    DWORD     NumberOfProcessIdsInList;
    ULONG_PTR ProcessIdList[1];
} JOBOBJECT_BASIC_PROCESS_ID_LIST, *PJOBOBJECT_BASIC_PROCESS_ID_LIST;

typedef struct _JOBOBJECT_BASIC_UI_RESTRICTIONS {
    DWORD UIRestrictionsClass;
} JOBOBJECT_BASIC_UI_RESTRICTIONS, *PJOBOBJECT_BASIC_UI_RESTRICTIONS;

typedef struct _JOBOBJECT_SECURITY_LIMIT_INFORMATION {
    DWORD             SecurityLimitFlags;
    HANDLE            JobToken;
    PTOKEN_GROUPS     SidsToDisable;
    PTOKEN_PRIVILEGES PrivilegesToDelete;
    PTOKEN_GROUPS     RestrictedSids;
} JOBOBJECT_SECURITY_LIMIT_INFORMATION, *PJOBOBJECT_SECURITY_LIMIT_INFORMATION;

typedef struct _JOBOBJECT_END_OF_JOB_TIME_INFORMATION {
    DWORD EndOfJobTimeAction;
} JOBOBJECT_END_OF_JOB_TIME_INFORMATION, PJOBOBJECT_END_OF_JOB_TIME_INFORMATION;

typedef struct _JOBOBJECT_ASSOCIATE_COMPLETION_PORT {
    PVOID  CompletionKey;
    HANDLE CompletionPort;
} JOBOBJECT_ASSOCIATE_COMPLETION_PORT, *PJOBOBJECT_ASSOCIATE_COMPLETION_PORT;

#define JOB_OBJECT_MSG_END_OF_JOB_TIME              1
#define JOB_OBJECT_MSG_END_OF_PROCESS_TIME          2
#define JOB_OBJECT_MSG_ACTIVE_PROCESS_LIMIT         3
#define JOB_OBJECT_MSG_ACTIVE_PROCESS_ZERO          4
#define JOB_OBJECT_MSG_NEW_PROCESS                  6
#define JOB_OBJECT_MSG_EXIT_PROCESS                 7
#define JOB_OBJECT_MSG_ABNORMAL_EXIT_PROCESS        8
#define JOB_OBJECT_MSG_PROCESS_MEMORY_LIMIT         9
#define JOB_OBJECT_MSG_JOB_MEMORY_LIMIT             10

typedef struct JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION {
    JOBOBJECT_BASIC_ACCOUNTING_INFORMATION BasicInfo;
    IO_COUNTERS                            IoInfo;
} JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION, *PJOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION;

typedef struct _JOBOBJECT_EXTENDED_LIMIT_INFORMATION {
    JOBOBJECT_BASIC_LIMIT_INFORMATION BasicLimitInformation;
    IO_COUNTERS                       IoInfo;
    SIZE_T                            ProcessMemoryLimit;
    SIZE_T                            JobMemoryLimit;
    SIZE_T                            PeakProcessMemoryUsed;
    SIZE_T                            PeakJobMemoryUsed;
} JOBOBJECT_EXTENDED_LIMIT_INFORMATION, *PJOBOBJECT_EXTENDED_LIMIT_INFORMATION;

#define JOB_OBJECT_LIMIT_WORKINGSET                 0x00000001
#define JOB_OBJECT_LIMIT_PROCESS_TIME               0x00000002
#define JOB_OBJECT_LIMIT_JOB_TIME                   0x00000004
#define JOB_OBJECT_LIMIT_ACTIVE_PROCESS             0x00000008
#define JOB_OBJECT_LIMIT_AFFINITY                   0x00000010
#define JOB_OBJECT_LIMIT_PRIORITY_CLASS             0x00000020
#define JOB_OBJECT_LIMIT_PRESERVE_JOB_TIME          0x00000040
#define JOB_OBJECT_LIMIT_SCHEDULING_CLASS           0x00000080
#define JOB_OBJECT_LIMIT_PROCESS_MEMORY             0x00000100
#define JOB_OBJECT_LIMIT_JOB_MEMORY                 0x00000200
#define JOB_OBJECT_LIMIT_DIE_ON_UNHANDLED_EXCEPTION 0x00000400
#define JOB_OBJECT_LIMIT_BREAKAWAY_OK               0x00000800
#define JOB_OBJECT_LIMIT_SILENT_BREAKAWAY_OK        0x00001000
#define JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE          0x00002000
#define JOB_OBJECT_LIMIT_SUBSET_AFFINITY            0x00004000

#define JOB_OBJECT_LIMIT_VALID_FLAGS                0x0007ffff
#define JOB_OBJECT_BASIC_LIMIT_VALID_FLAGS          0x000000ff
#define JOB_OBJECT_EXTENDED_LIMIT_VALID_FLAGS       0x00007fff

typedef enum _LOGICAL_PROCESSOR_RELATIONSHIP
{
    RelationProcessorCore    = 0,
    RelationNumaNode         = 1,
    RelationCache            = 2,
    RelationProcessorPackage = 3,
    RelationGroup            = 4,
    RelationAll              = 0xffff
} LOGICAL_PROCESSOR_RELATIONSHIP;

typedef enum _PROCESSOR_CACHE_TYPE
{
    CacheUnified,
    CacheInstruction,
    CacheData,
    CacheTrace
} PROCESSOR_CACHE_TYPE;

typedef struct _PROCESSOR_GROUP_INFO
{
    BYTE MaximumProcessorCount;
    BYTE ActiveProcessorCount;
    BYTE Reserved[38];
    KAFFINITY ActiveProcessorMask;
} PROCESSOR_GROUP_INFO, *PPROCESSOR_GROUP_INFO;

typedef struct _CACHE_DESCRIPTOR
{
    BYTE Level;
    BYTE Associativity;
    WORD LineSize;
    DWORD Size;
    PROCESSOR_CACHE_TYPE Type;
} CACHE_DESCRIPTOR, *PCACHE_DESCRIPTOR;

typedef struct _GROUP_AFFINITY
{
    KAFFINITY Mask;
    WORD Group;
    WORD Reserved[3];
} GROUP_AFFINITY, *PGROUP_AFFINITY;

typedef struct _PROCESSOR_NUMBER
{
    WORD Group;
    BYTE Number;
    BYTE Reserved;
} PROCESSOR_NUMBER, *PPROCESSOR_NUMBER;

typedef struct _PROCESSOR_RELATIONSHIP
{
    BYTE Flags;
    BYTE EfficiencyClass;
    BYTE Reserved[20];
    WORD GroupCount;
    GROUP_AFFINITY GroupMask[ANYSIZE_ARRAY];
} PROCESSOR_RELATIONSHIP, *PPROCESSOR_RELATIONSHIP;

typedef struct _NUMA_NODE_RELATIONSHIP
{
    DWORD NodeNumber;
    BYTE Reserved[20];
    GROUP_AFFINITY GroupMask;
} NUMA_NODE_RELATIONSHIP, *PNUMA_NODE_RELATIONSHIP;

typedef struct _CACHE_RELATIONSHIP
{
    BYTE Level;
    BYTE Associativity;
    WORD LineSize;
    DWORD CacheSize;
    PROCESSOR_CACHE_TYPE Type;
    BYTE Reserved[20];
    GROUP_AFFINITY GroupMask;
} CACHE_RELATIONSHIP, *PCACHE_RELATIONSHIP;

typedef struct _GROUP_RELATIONSHIP
{
    WORD MaximumGroupCount;
    WORD ActiveGroupCount;
    BYTE Reserved[20];
    PROCESSOR_GROUP_INFO GroupInfo[ANYSIZE_ARRAY];
} GROUP_RELATIONSHIP, *PGROUP_RELATIONSHIP;

typedef struct _SYSTEM_LOGICAL_PROCESSOR_INFORMATION
{
    ULONG_PTR ProcessorMask;
    LOGICAL_PROCESSOR_RELATIONSHIP Relationship;
    union
    {
        struct
        {
            BYTE Flags;
        } ProcessorCore;
        struct
        {
            DWORD NodeNumber;
        } NumaNode;
        CACHE_DESCRIPTOR Cache;
        ULONGLONG Reserved[2];
    } DUMMYUNIONNAME;
} SYSTEM_LOGICAL_PROCESSOR_INFORMATION, *PSYSTEM_LOGICAL_PROCESSOR_INFORMATION;

typedef struct _SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX
{
    LOGICAL_PROCESSOR_RELATIONSHIP Relationship;
    DWORD Size;
    union
    {
        PROCESSOR_RELATIONSHIP Processor;
        NUMA_NODE_RELATIONSHIP NumaNode;
        CACHE_RELATIONSHIP Cache;
        GROUP_RELATIONSHIP Group;
    } DUMMYUNIONNAME;
} SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX, *PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX;

/* Threadpool things */
typedef DWORD TP_VERSION,*PTP_VERSION;

typedef struct _TP_CALLBACK_INSTANCE TP_CALLBACK_INSTANCE,*PTP_CALLBACK_INSTANCE;

typedef VOID (CALLBACK *PTP_SIMPLE_CALLBACK)(PTP_CALLBACK_INSTANCE,PVOID);

typedef struct _TP_POOL TP_POOL,*PTP_POOL;

typedef enum _TP_CALLBACK_PRIORITY
{
	TP_CALLBACK_PRIORITY_HIGH,
	TP_CALLBACK_PRIORITY_NORMAL,
	TP_CALLBACK_PRIORITY_LOW,
	TP_CALLBACK_PRIORITY_INVALID,
	TP_CALLBACK_PRIORITY_COUNT = TP_CALLBACK_PRIORITY_INVALID
} TP_CALLBACK_PRIORITY;

typedef struct _TP_POOL_STACK_INFORMATION
{
	SIZE_T StackReserve;
	SIZE_T StackCommit;
} TP_POOL_STACK_INFORMATION,*PTP_POOL_STACK_INFORMATION;

typedef struct _TP_CLEANUP_GROUP TP_CLEANUP_GROUP,*PTP_CLEANUP_GROUP;

typedef VOID (CALLBACK *PTP_CLEANUP_GROUP_CANCEL_CALLBACK)(PVOID,PVOID);

typedef struct _TP_CALLBACK_ENVIRON_V1
{
	TP_VERSION Version;
	PTP_POOL Pool;
	PTP_CLEANUP_GROUP CleanupGroup;
	PTP_CLEANUP_GROUP_CANCEL_CALLBACK CleanupGroupCancelCallback;
	PVOID RaceDll;
	struct _ACTIVATION_CONTEXT* ActivationContext;
	PTP_SIMPLE_CALLBACK FinalizationCallback;
	union
	{
		DWORD Flags;
		struct
		{
			DWORD LongFunction:1;
			DWORD Persistent:1;
			DWORD Private:30;
		} s;
	} u;
} TP_CALLBACK_ENVIRON_V1;

typedef struct _TP_CALLBACK_ENVIRON_V3
{
    TP_VERSION Version;
    PTP_POOL Pool;
    PTP_CLEANUP_GROUP CleanupGroup;
    PTP_CLEANUP_GROUP_CANCEL_CALLBACK CleanupGroupCancelCallback;
    PVOID RaceDll;
    struct _ACTIVATION_CONTEXT *ActivationContext;
    PTP_SIMPLE_CALLBACK FinalizationCallback;
    union
    {
        DWORD Flags;
        struct
        {
            DWORD LongFunction:1;
            DWORD Persistent:1;
            DWORD Private:30;
        } s;
    } u;
    TP_CALLBACK_PRIORITY CallbackPriority;
    DWORD Size;
} TP_CALLBACK_ENVIRON_V3;

typedef struct _TP_WORK TP_WORK, *PTP_WORK;
typedef struct _TP_TIMER TP_TIMER, *PTP_TIMER;

typedef DWORD TP_WAIT_RESULT;
typedef struct _TP_WAIT TP_WAIT, *PTP_WAIT;

typedef struct _TP_IO TP_IO, *PTP_IO;

typedef TP_CALLBACK_ENVIRON_V1 TP_CALLBACK_ENVIRON, *PTP_CALLBACK_ENVIRON;

typedef VOID (CALLBACK *PTP_WORK_CALLBACK)(PTP_CALLBACK_INSTANCE,PVOID,PTP_WORK);
typedef VOID (CALLBACK *PTP_TIMER_CALLBACK)(PTP_CALLBACK_INSTANCE,PVOID,PTP_TIMER);
typedef VOID (CALLBACK *PTP_WAIT_CALLBACK)(PTP_CALLBACK_INSTANCE,PVOID,PTP_WAIT,TP_WAIT_RESULT);
typedef VOID (CALLBACK *PTP_WIN32_IO_CALLBACK)(PTP_CALLBACK_INSTANCE,PVOID,PVOID,ULONG,ULONG_PTR,PTP_IO);


NTSYSAPI BOOLEAN NTAPI RtlGetProductInfo(DWORD,DWORD,DWORD,DWORD,PDWORD);

#ifdef __cplusplus
}
#endif

#endif  /* _WINNT_ */
