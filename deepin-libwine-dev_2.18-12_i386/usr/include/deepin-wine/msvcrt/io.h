/*
 * System I/O definitions.
 *
 * Derived from the mingw header written by Colin Peters.
 * Modified for Wine use by Jon Griffiths and Francois Gouget.
 * This file is in the public domain.
 */
#ifndef __WINE_IO_H
#define __WINE_IO_H

#include <crtdefs.h>

#include <pshpack8.h>

/* The following are also defined in dos.h */
#define _A_NORMAL 0x00000000
#define _A_RDONLY 0x00000001
#define _A_HIDDEN 0x00000002
#define _A_SYSTEM 0x00000004
#define _A_VOLID  0x00000008
#define _A_SUBDIR 0x00000010
#define _A_ARCH   0x00000020

#ifndef _FSIZE_T_DEFINED
typedef __msvcrt_ulong _fsize_t;
#define _FSIZE_T_DEFINED
#endif

#ifndef _FINDDATA_T_DEFINED
#define _FINDDATA_T_DEFINED
struct _finddata_t
{
  unsigned attrib;
  time_t   time_create;
  time_t   time_access;
  time_t   time_write;
  _fsize_t size;
  char             name[260];
};

struct _finddatai64_t
{
  unsigned attrib;
  time_t time_create;
  time_t time_access;
  time_t time_write;
  __int64 DECLSPEC_ALIGN(8) size;
  char           name[260];
};

struct _finddata64_t
{
  unsigned attrib;
  __time64_t time_create;
  __time64_t time_access;
  __time64_t time_write;
  __int64 DECLSPEC_ALIGN(8) size;
  char           name[260];
};
#endif /* _FINDDATA_T_DEFINED */

#ifndef _WFINDDATA_T_DEFINED
#define _WFINDDATA_T_DEFINED
struct _wfinddata_t {
  unsigned attrib;
  time_t   time_create;
  time_t   time_access;
  time_t   time_write;
  _fsize_t size;
  wchar_t  name[260];
};

struct _wfinddatai64_t {
  unsigned attrib;
  time_t  time_create;
  time_t  time_access;
  time_t  time_write;
  __int64 DECLSPEC_ALIGN(8) size;
  wchar_t name[260];
};
#endif /* _WFINDDATA_T_DEFINED */

#ifdef __cplusplus
extern "C" {
#endif

int         __cdecl _access(const char*,int);
int         __cdecl _chmod(const char*,int);
int         __cdecl _chsize(int,__msvcrt_ulong);
int         __cdecl _chsize_s(int,__int64);
int         __cdecl _close(int);
int         __cdecl _commit(int);
int         __cdecl _creat(const char*,int);
int         __cdecl _dup(int);
int         __cdecl _dup2(int,int);
int         __cdecl _eof(int);
__int64     __cdecl _filelengthi64(int);
__msvcrt_long __cdecl _filelength(int);
int         __cdecl _findclose(intptr_t);
intptr_t    __cdecl _findfirst(const char*,struct _finddata_t*);
intptr_t    __cdecl _findfirsti64(const char*, struct _finddatai64_t*);
intptr_t    __cdecl _findfirst64(const char*, struct _finddata64_t*);
int         __cdecl _findnext(intptr_t,struct _finddata_t*);
int         __cdecl _findnexti64(intptr_t, struct _finddatai64_t*);
int         __cdecl _findnext64(intptr_t, struct _finddata64_t*);
intptr_t    __cdecl _get_osfhandle(int);
int         __cdecl _isatty(int);
int         __cdecl _locking(int,int,__msvcrt_long);
__msvcrt_long __cdecl _lseek(int,__msvcrt_long,int);
__int64     __cdecl _lseeki64(int,__int64,int);
char*       __cdecl _mktemp(char*);
int         __cdecl _mktemp_s(char*,size_t);
int         __cdecl _open(const char*,int,...);
int         __cdecl _open_osfhandle(intptr_t,int);
int         __cdecl _pipe(int*,unsigned int,int);
int         __cdecl _read(int,void*,unsigned int);
int         __cdecl _setmode(int,int);
int         __cdecl _sopen(const char*,int,int,...);
__msvcrt_long __cdecl _tell(int);
__int64     __cdecl _telli64(int);
int         __cdecl _umask(int);
int         __cdecl _unlink(const char*);
int         __cdecl _write(int,const void*,unsigned int);

int         __cdecl remove(const char*);
int         __cdecl rename(const char*,const char*);

#ifndef _WIO_DEFINED
#define _WIO_DEFINED
int         __cdecl _waccess(const wchar_t*,int);
int         __cdecl _wchmod(const wchar_t*,int);
int         __cdecl _wcreat(const wchar_t*,int);
intptr_t    __cdecl _wfindfirst(const wchar_t*,struct _wfinddata_t*);
intptr_t    __cdecl _wfindfirsti64(const wchar_t*, struct _wfinddatai64_t*);
int         __cdecl _wfindnext(intptr_t,struct _wfinddata_t*);
int         __cdecl _wfindnexti64(intptr_t, struct _wfinddatai64_t*);
wchar_t *   __cdecl _wmktemp(wchar_t*);
int         __cdecl _wopen(const wchar_t*,int,...);
int         __cdecl _wrename(const wchar_t*,const wchar_t*);
int         __cdecl _wsopen(const wchar_t*,int,int,...);
int         __cdecl _wunlink(const wchar_t*);
#endif /* _WIO_DEFINED */

#ifdef __cplusplus
}
#endif


static inline int access(const char* path, int mode) { return _access(path, mode); }
static inline int chmod(const char* path, int mode) { return _chmod(path, mode); }
static inline int chsize(int fd, __msvcrt_long size) { return _chsize(fd, size); }
static inline int close(int fd) { return _close(fd); }
static inline int creat(const char* path, int mode) { return _creat(path, mode); }
static inline int dup(int od) { return _dup(od); }
static inline int dup2(int od, int nd) { return _dup2(od, nd); }
static inline int eof(int fd) { return _eof(fd); }
static inline __msvcrt_long filelength(int fd) { return _filelength(fd); }
static inline int isatty(int fd) { return _isatty(fd); }
static inline int locking(int fd, int mode, __msvcrt_long size) { return _locking(fd, mode, size); }
static inline __msvcrt_long lseek(int fd, __msvcrt_long off, int where) { return _lseek(fd, off, where); }
static inline char* mktemp(char* pat) { return _mktemp(pat); }
static inline int read(int fd, void* buf, unsigned int size) { return _read(fd, buf, size); }
static inline int setmode(int fd, int mode) { return _setmode(fd, mode); }
static inline __msvcrt_long tell(int fd) { return _tell(fd); }
#ifndef _UMASK_DEFINED
static inline int umask(int fd) { return _umask(fd); }
#define _UMASK_DEFINED
#endif
#ifndef _UNLINK_DEFINED
static inline int unlink(const char* path) { return _unlink(path); }
#define _UNLINK_DEFINED
#endif
static inline int write(int fd, const void* buf, unsigned int size) { return _write(fd, buf, size); }

#if defined(__GNUC__) && (__GNUC__ < 4)
extern int __cdecl open(const char*,int,...) __attribute__((alias("_open")));
extern int __cdecl sopen(const char*,int,int,...) __attribute__((alias("_sopen")));
#else
#define open _open
#define sopen _sopen
#endif /* __GNUC__ */

#include <poppack.h>

#endif /* __WINE_IO_H */
