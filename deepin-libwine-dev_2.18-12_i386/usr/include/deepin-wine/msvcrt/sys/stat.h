/*
 * _stat() definitions
 *
 * Derived from the mingw header written by Colin Peters.
 * Modified for Wine use by Jon Griffiths and Francois Gouget.
 * This file is in the public domain.
 */
#ifndef __WINE_SYS_STAT_H
#define __WINE_SYS_STAT_H

#include <crtdefs.h>
#include <sys/types.h>

#include <pshpack8.h>

#ifndef _DEV_T_DEFINED
typedef unsigned int _dev_t;
#define _DEV_T_DEFINED
#endif

#ifndef _INO_T_DEFINED
typedef unsigned short _ino_t;
#define _INO_T_DEFINED
#endif

#ifndef _OFF_T_DEFINED
typedef int _off_t;
#define _OFF_T_DEFINED
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

#define _S_IEXEC  0x0040
#define _S_IWRITE 0x0080
#define _S_IREAD  0x0100
#define _S_IFIFO  0x1000
#define _S_IFCHR  0x2000
#define _S_IFDIR  0x4000
#define _S_IFREG  0x8000
#define _S_IFMT   0xF000

/* for FreeBSD */
#undef st_atime
#undef st_ctime
#undef st_mtime

#ifndef _STAT_DEFINED
#define _STAT_DEFINED

struct _stat {
  _dev_t st_dev;
  _ino_t st_ino;
  unsigned short st_mode;
  short          st_nlink;
  short          st_uid;
  short          st_gid;
  _dev_t st_rdev;
  _off_t st_size;
  time_t st_atime;
  time_t st_mtime;
  time_t st_ctime;
};

struct stat {
  _dev_t st_dev;
  _ino_t st_ino;
  unsigned short st_mode;
  short          st_nlink;
  short          st_uid;
  short          st_gid;
  _dev_t st_rdev;
  _off_t st_size;
  time_t st_atime;
  time_t st_mtime;
  time_t st_ctime;
};

struct _stat32 {
  _dev_t st_dev;
  _ino_t st_ino;
  unsigned short st_mode;
  short st_nlink;
  short st_uid;
  short st_gid;
  _dev_t st_rdev;
  _off_t st_size;
  __time32_t st_atime;
  __time32_t st_mtime;
  __time32_t st_ctime;
};

struct _stat32i64 {
  _dev_t st_dev;
  _ino_t st_ino;
  unsigned short st_mode;
  short st_nlink;
  short st_uid;
  short st_gid;
  _dev_t st_rdev;
  __int64 DECLSPEC_ALIGN(8) st_size;
  time_t st_atime;
  time_t st_mtime;
  time_t st_ctime;
};

struct _stat64i32 {
  _dev_t st_dev;
  _ino_t st_ino;
  unsigned short st_mode;
  short st_nlink;
  short st_uid;
  short st_gid;
  _dev_t st_rdev;
  _off_t st_size;
  __time64_t st_atime;
  __time64_t st_mtime;
  __time64_t st_ctime;
};

struct _stati64 {
  _dev_t st_dev;
  _ino_t st_ino;
  unsigned short st_mode;
  short          st_nlink;
  short          st_uid;
  short          st_gid;
  _dev_t st_rdev;
  __int64 DECLSPEC_ALIGN(8) st_size;
  time_t st_atime;
  time_t st_mtime;
  time_t st_ctime;
};

struct _stat64 {
  _dev_t st_dev;
  _ino_t st_ino;
  unsigned short st_mode;
  short          st_nlink;
  short          st_uid;
  short          st_gid;
  _dev_t st_rdev;
  __int64 DECLSPEC_ALIGN(8) st_size;
  __time64_t     st_atime;
  __time64_t     st_mtime;
  __time64_t     st_ctime;
};
#endif /* _STAT_DEFINED */

#ifdef __cplusplus
extern "C" {
#endif

int __cdecl _fstat(int,struct _stat*);
int __cdecl _stat(const char*,struct _stat*);
int __cdecl _fstat32(int, struct _stat32*);
int __cdecl _stat32(const char*, struct _stat32*);
int __cdecl _fstati64(int,struct _stati64*);
int __cdecl _stati64(const char*,struct _stati64*);
int __cdecl _fstat64(int,struct _stat64*);
int __cdecl _stat64(const char*,struct _stat64*);
int __cdecl _umask(int);

#ifndef _WSTAT_DEFINED
#define _WSTAT_DEFINED
int __cdecl _wstat(const wchar_t*,struct _stat*);
int __cdecl _wstat32(const wchar_t*, struct _stat32*);
int __cdecl _wstati64(const wchar_t*,struct _stati64*);
int __cdecl _wstat64(const wchar_t*,struct _stat64*);
#endif /* _WSTAT_DEFINED */

#ifdef __cplusplus
}
#endif


#define S_IFMT   _S_IFMT
#define S_IFDIR  _S_IFDIR
#define S_IFCHR  _S_IFCHR
#define S_IFREG  _S_IFREG
#define S_IREAD  _S_IREAD
#define S_IWRITE _S_IWRITE
#define S_IEXEC  _S_IEXEC

static inline int fstat(int fd, struct stat* ptr) { return _fstat(fd, (struct _stat*)ptr); }
static inline int stat(const char* path, struct stat* ptr) { return _stat(path, (struct _stat*)ptr); }
#ifndef _UMASK_DEFINED
static inline int umask(int fd) { return _umask(fd); }
#define _UMASK_DEFINED
#endif

#include <poppack.h>

#endif /* __WINE_SYS_STAT_H */
