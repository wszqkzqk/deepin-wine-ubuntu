/*
 * Character type definitions
 *
 * Derived from the mingw header written by Colin Peters.
 * Modified for Wine use by Jon Griffiths and Francois Gouget.
 * This file is in the public domain.
 */
#ifndef __WINE_CTYPE_H
#define __WINE_CTYPE_H

#include <crtdefs.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WEOF
#define WEOF        (wint_t)(0xFFFF)
#endif

/* ASCII char classification table - binary compatible */
#define _UPPER        0x0001  /* C1_UPPER */
#define _LOWER        0x0002  /* C1_LOWER */
#define _DIGIT        0x0004  /* C1_DIGIT */
#define _SPACE        0x0008  /* C1_SPACE */
#define _PUNCT        0x0010  /* C1_PUNCT */
#define _CONTROL      0x0020  /* C1_CNTRL */
#define _BLANK        0x0040  /* C1_BLANK */
#define _HEX          0x0080  /* C1_XDIGIT */
#define _LEADBYTE     0x8000
#define _ALPHA       (0x0100|_UPPER|_LOWER)  /* (C1_ALPHA|_UPPER|_LOWER) */

int __cdecl __isascii(int);
int __cdecl __iscsym(int);
int __cdecl __iscsymf(int);
int __cdecl __toascii(int);
int __cdecl _isctype(int,int);
int __cdecl _tolower(int);
int __cdecl _toupper(int);
int __cdecl isalnum(int);
int __cdecl isalpha(int);
int __cdecl iscntrl(int);
int __cdecl isdigit(int);
int __cdecl isgraph(int);
int __cdecl islower(int);
int __cdecl isprint(int);
int __cdecl ispunct(int);
int __cdecl isspace(int);
int __cdecl isupper(int);
int __cdecl isxdigit(int);
int __cdecl tolower(int);
int __cdecl toupper(int);

#ifndef _WCTYPE_DEFINED
#define _WCTYPE_DEFINED
int __cdecl is_wctype(wint_t,wctype_t);
int __cdecl isleadbyte(int);
int __cdecl iswalnum(wint_t);
int __cdecl iswalpha(wint_t);
int __cdecl iswascii(wint_t);
int __cdecl iswcntrl(wint_t);
int __cdecl iswctype(wint_t,wctype_t);
int __cdecl iswdigit(wint_t);
int __cdecl iswgraph(wint_t);
int __cdecl iswlower(wint_t);
int __cdecl iswprint(wint_t);
int __cdecl iswpunct(wint_t);
int __cdecl iswspace(wint_t);
int __cdecl iswupper(wint_t);
int __cdecl iswxdigit(wint_t);
wchar_t __cdecl towlower(wchar_t);
wchar_t __cdecl towupper(wchar_t);
#endif /* _WCTYPE_DEFINED */

#ifdef __cplusplus
}
#endif


static inline int isascii(int c) { return __isascii(c); }
static inline int iscsym(int c) { return __iscsym(c); }
static inline int iscsymf(int c) { return __iscsymf(c); }
static inline int toascii(int c) { return __toascii(c); }

#endif /* __WINE_CTYPE_H */
