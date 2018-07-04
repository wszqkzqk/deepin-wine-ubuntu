/*
 * Math functions.
 *
 * Derived from the mingw header written by Colin Peters.
 * Modified for Wine use by Hans Leidekker.
 * This file is in the public domain.
 */

#ifndef __WINE_MATH_H
#define __WINE_MATH_H

#include <crtdefs.h>

#include <pshpack8.h>

#ifdef __cplusplus
extern "C" {
#endif

#define _DOMAIN         1       /* domain error in argument */
#define _SING           2       /* singularity */
#define _OVERFLOW       3       /* range overflow */
#define _UNDERFLOW      4       /* range underflow */
#define _TLOSS          5       /* total loss of precision */
#define _PLOSS          6       /* partial loss of precision */

#ifndef _EXCEPTION_DEFINED
#define _EXCEPTION_DEFINED
struct _exception
{
  int     type;
  char    *name;
  double  arg1;
  double  arg2;
  double  retval;
};
#endif /* _EXCEPTION_DEFINED */

#ifndef _COMPLEX_DEFINED
#define _COMPLEX_DEFINED
struct _complex
{
  double x;      /* Real part */
  double y;      /* Imaginary part */
};
#endif /* _COMPLEX_DEFINED */

double __cdecl sin(double);
double __cdecl cos(double);
double __cdecl tan(double);
double __cdecl sinh(double);
double __cdecl cosh(double);
double __cdecl tanh(double);
double __cdecl asin(double);
double __cdecl acos(double);
double __cdecl atan(double);
double __cdecl atan2(double, double);
double __cdecl exp(double);
double __cdecl log(double);
double __cdecl log10(double);
double __cdecl pow(double, double);
double __cdecl sqrt(double);
double __cdecl ceil(double);
double __cdecl floor(double);
double __cdecl fabs(double);
double __cdecl ldexp(double, int);
double __cdecl frexp(double, int*);
double __cdecl modf(double, double*);
double __cdecl fmod(double, double);

double __cdecl _hypot(double, double);
double __cdecl _j0(double);
double __cdecl _j1(double);
double __cdecl _jn(int, double);
double __cdecl _y0(double);
double __cdecl _y1(double);
double __cdecl _yn(int, double);

double __cdecl cbrt(double);
double __cdecl exp2(double);
double __cdecl log2(double);
double __cdecl rint(double);
double __cdecl round(double);
double __cdecl trunc(double);

float __cdecl cbrtf(float);
float __cdecl exp2f(float);
float __cdecl log2f(float);
float __cdecl rintf(float);
float __cdecl roundf(float);
float __cdecl truncf(float);

long __cdecl lrint(double);
long __cdecl lrintf(float);
long __cdecl lround(double);
long __cdecl lroundf(float);

#if defined(__x86_64__) || defined(__arm__)

float __cdecl sinf(float);
float __cdecl cosf(float);
float __cdecl tanf(float);
float __cdecl sinhf(float);
float __cdecl coshf(float);
float __cdecl tanhf(float);
float __cdecl asinf(float);
float __cdecl acosf(float);
float __cdecl atanf(float);
float __cdecl atan2f(float, float);
float __cdecl expf(float);
float __cdecl logf(float);
float __cdecl log10f(float);
float __cdecl powf(float, float);
float __cdecl sqrtf(float);
float __cdecl ceilf(float);
float __cdecl floorf(float);
float __cdecl fabsf(float);
float __cdecl ldexpf(float, int);
float __cdecl frexpf(float, int*);
float __cdecl modff(float, float*);
float __cdecl fmodf(float, float);

#else

#define sinf(x) ((float)sin((double)(x)))
#define cosf(x) ((float)cos((double)(x)))
#define tanf(x) ((float)tan((double)(x)))
#define sinhf(x) ((float)sinh((double)(x)))
#define coshf(x) ((float)cosh((double)(x)))
#define tanhf(x) ((float)tanh((double)(x)))
#define asinf(x) ((float)asin((double)(x)))
#define acosf(x) ((float)acos((double)(x)))
#define atanf(x) ((float)atan((double)(x)))
#define atan2f(x,y) ((float)atan2((double)(x), (double)(y)))
#define expf(x) ((float)exp((double)(x)))
#define logf(x) ((float)log((double)(x)))
#define log10f(x) ((float)log10((double)(x)))
#define powf(x,y) ((float)pow((double)(x), (double)(y)))
#define sqrtf(x) ((float)sqrt((double)(x)))
#define ceilf(x) ((float)ceil((double)(x)))
#define floorf(x) ((float)floor((double)(x)))
#define fabsf(x) ((float)fabs((double)(x)))
#define frexpf(x) ((float)frexp((double)(x)))
#define modff(x,y) ((float)modf((double)(x), (double*)(y)))
#define fmodf(x,y) ((float)fmod((double)(x), (double)(y)))

#endif

#define ldexpf(x,y) ((float)ldexp((double)(x),(y)))

double __cdecl nearbyint(double);
float __cdecl nearbyintf(float);

float __cdecl _hypotf(float, float);

int __cdecl _matherr(struct _exception*);
double __cdecl _cabs(struct _complex);

#ifndef HUGE_VAL
#  if defined(__GNUC__) && (__GNUC__ >= 3)
#    define HUGE_VAL    (__extension__ 0x1.0p2047)
#  else
static const union {
    unsigned char __c[8];
    double __d;
} __huge_val = { { 0, 0, 0, 0, 0, 0, 0xf0, 0x7f } };
#    define HUGE_VAL    (__huge_val.__d)
#  endif
#endif

#define FP_INFINITE   1
#define FP_NAN        2
#define FP_NORMAL    -1
#define FP_SUBNORMAL -2
#define FP_ZERO       0

#ifdef __cplusplus
}
#endif

#include <poppack.h>

#ifdef _USE_MATH_DEFINES
#ifndef _MATH_DEFINES_DEFINED
#define _MATH_DEFINES_DEFINED
#define M_E         2.71828182845904523536
#define M_LOG2E     1.44269504088896340736
#define M_LOG10E    0.434294481903251827651
#define M_LN2       0.693147180559945309417
#define M_LN10      2.30258509299404568402
#define M_PI        3.14159265358979323846
#define M_PI_2      1.57079632679489661923
#define M_PI_4      0.785398163397448309616
#define M_1_PI      0.318309886183790671538
#define M_2_PI      0.636619772367581343076
#define M_2_SQRTPI  1.12837916709551257390
#define M_SQRT2     1.41421356237309504880
#define M_SQRT1_2   0.707106781186547524401
#endif /* !_MATH_DEFINES_DEFINED */
#endif /* _USE_MATH_DEFINES */

static inline double hypot( double x, double y ) { return _hypot( x, y ); }
static inline double j0( double x ) { return _j0( x ); }
static inline double j1( double x ) { return _j1( x ); }
static inline double jn( int n, double x ) { return _jn( n, x ); }
static inline double y0( double x ) { return _y0( x ); }
static inline double y1( double x ) { return _y1( x ); }
static inline double yn( int n, double x ) { return _yn( n, x ); }
static inline double cabs(struct _complex z) { return _cabs( z ); }

static inline float hypotf( float x, float y ) { return _hypotf( x, y ); }

#endif /* __WINE_MATH_H */
