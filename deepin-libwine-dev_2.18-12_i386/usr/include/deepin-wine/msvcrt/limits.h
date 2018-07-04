#ifndef __WINE_LIMITS_H
#define __WINE_LIMITS_H

#include <crtdefs.h>

#define CHAR_BIT 8
#define MB_LEN_MAX 5

#define SCHAR_MIN (-0x80)
#define SCHAR_MAX   0x7f
#define UCHAR_MAX   0xff

#ifdef __CHAR_UNSIGNED__
# define CHAR_MIN 0
# define CHAR_MAX UCHAR_MAX
#else
# define CHAR_MIN SCHAR_MIN
# define CHAR_MAX SCHAR_MAX
#endif

#define SHRT_MIN  (-0x8000)
#define SHRT_MAX    0x7fff
#define USHRT_MAX   0xffff

#define INT_MIN   (-0x7fffffff - 1)
#define INT_MAX     0x7fffffff
#define UINT_MAX    0xffffffffU

#define LONG_MIN  (-0x7fffffffL - 1L)
#define LONG_MAX    0x7fffffffL
#define ULONG_MAX   0xffffffffUL

#define LLONG_MAX   (((__int64)0x7fffffff << 32) | 0xffffffff)
#define LLONG_MIN   (-LLONG_MAX-1)
#define ULLONG_MAX  (((unsigned __int64)0xffffffff << 32) | 0xffffffff)

#define _I64_MAX    (((__int64)0x7fffffff << 32) | 0xffffffff)
#define _I64_MIN    (-_I64_MAX-1)
#define _UI64_MAX   (((unsigned __int64)0xffffffff << 32) | 0xffffffff)

#define I64_MIN  _I64_MIN
#define I64_MAX  _I64_MAX
#define UI64_MAX _UI64_MAX

#ifndef SIZE_MAX
# ifdef _WIN64
#  define SIZE_MAX UI64_MAX
# else
#  define SIZE_MAX UINT_MAX
# endif
#endif

#endif /* __WINE_LIMITS_H */
