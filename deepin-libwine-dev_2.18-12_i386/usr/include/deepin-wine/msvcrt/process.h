/*
 * Process definitions
 *
 * Derived from the mingw header written by Colin Peters.
 * Modified for Wine use by Jon Griffiths and Francois Gouget.
 * This file is in the public domain.
 */
#ifndef __WINE_PROCESS_H
#define __WINE_PROCESS_H

#include <crtdefs.h>

/* Process creation flags */
#define _P_WAIT    0
#define _P_NOWAIT  1
#define _P_OVERLAY 2
#define _P_NOWAITO 3
#define _P_DETACH  4

#define _WAIT_CHILD      0
#define _WAIT_GRANDCHILD 1

#ifdef __cplusplus
extern "C" {
#endif

typedef void (__cdecl *_beginthread_start_routine_t)(void *);
typedef unsigned int (__stdcall *_beginthreadex_start_routine_t)(void *);

uintptr_t __cdecl _beginthread(_beginthread_start_routine_t,unsigned int,void*);
uintptr_t __cdecl _beginthreadex(void*,unsigned int,_beginthreadex_start_routine_t,void*,unsigned int,unsigned int*);
intptr_t  __cdecl _cwait(int*,intptr_t,int);
void      __cdecl _endthread(void);
void      __cdecl _endthreadex(unsigned int);
intptr_t  __cdecl _execl(const char*,const char*,...);
intptr_t  __cdecl _execle(const char*,const char*,...);
intptr_t  __cdecl _execlp(const char*,const char*,...);
intptr_t  __cdecl _execlpe(const char*,const char*,...);
intptr_t  __cdecl _execv(const char*,const char* const *);
intptr_t  __cdecl _execve(const char*,const char* const *,const char* const *);
intptr_t  __cdecl _execvp(const char*,const char* const *);
intptr_t  __cdecl _execvpe(const char*,const char* const *,const char* const *);
int       __cdecl _getpid(void);
intptr_t  __cdecl _spawnl(int,const char*,const char*,...);
intptr_t  __cdecl _spawnle(int,const char*,const char*,...);
intptr_t  __cdecl _spawnlp(int,const char*,const char*,...);
intptr_t  __cdecl _spawnlpe(int,const char*,const char*,...);
intptr_t  __cdecl _spawnv(int,const char*,const char* const *);
intptr_t  __cdecl _spawnve(int,const char*,const char* const *,const char* const *);
intptr_t  __cdecl _spawnvp(int,const char*,const char* const *);
intptr_t  __cdecl _spawnvpe(int,const char*,const char* const *,const char* const *);

void      __cdecl _c_exit(void);
void      __cdecl _cexit(void);
void      __cdecl _exit(int);
void      __cdecl abort(void);
void      __cdecl exit(int);
int       __cdecl system(const char*);

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED
intptr_t __cdecl _wexecl(const wchar_t*,const wchar_t*,...);
intptr_t __cdecl _wexecle(const wchar_t*,const wchar_t*,...);
intptr_t __cdecl _wexeclp(const wchar_t*,const wchar_t*,...);
intptr_t __cdecl _wexeclpe(const wchar_t*,const wchar_t*,...);
intptr_t __cdecl _wexecv(const wchar_t*,const wchar_t* const *);
intptr_t __cdecl _wexecve(const wchar_t*,const wchar_t* const *,const wchar_t* const *);
intptr_t __cdecl _wexecvp(const wchar_t*,const wchar_t* const *);
intptr_t __cdecl _wexecvpe(const wchar_t*,const wchar_t* const *,const wchar_t* const *);
intptr_t __cdecl _wspawnl(int,const wchar_t*,const wchar_t*,...);
intptr_t __cdecl _wspawnle(int,const wchar_t*,const wchar_t*,...);
intptr_t __cdecl _wspawnlp(int,const wchar_t*,const wchar_t*,...);
intptr_t __cdecl _wspawnlpe(int,const wchar_t*,const wchar_t*,...);
intptr_t __cdecl _wspawnv(int,const wchar_t*,const wchar_t* const *);
intptr_t __cdecl _wspawnve(int,const wchar_t*,const wchar_t* const *,const wchar_t* const *);
intptr_t __cdecl _wspawnvp(int,const wchar_t*,const wchar_t* const *);
intptr_t __cdecl _wspawnvpe(int,const wchar_t*,const wchar_t* const *,const wchar_t* const *);
int      __cdecl _wsystem(const wchar_t*);
#endif /* _WPROCESS_DEFINED */

#ifdef __cplusplus
}
#endif


#define P_WAIT          _P_WAIT
#define P_NOWAIT        _P_NOWAIT
#define P_OVERLAY       _P_OVERLAY
#define P_NOWAITO       _P_NOWAITO
#define P_DETACH        _P_DETACH

#define WAIT_CHILD      _WAIT_CHILD
#define WAIT_GRANDCHILD _WAIT_GRANDCHILD

static inline intptr_t cwait(int *status, intptr_t pid, int action) { return _cwait(status, pid, action); }
static inline int getpid(void) { return _getpid(); }
static inline intptr_t execv(const char* name, const char* const* argv) { return _execv(name, argv); }
static inline intptr_t execve(const char* name, const char* const* argv, const char* const* envv) { return _execve(name, argv, envv); }
static inline intptr_t execvp(const char* name, const char* const* argv) { return _execvp(name, argv); }
static inline intptr_t execvpe(const char* name, const char* const* argv, const char* const* envv) { return _execvpe(name, argv, envv); }
static inline intptr_t spawnv(int flags, const char* name, const char* const* argv) { return _spawnv(flags, name, argv); }
static inline intptr_t spawnve(int flags, const char* name, const char* const* argv, const char* const* envv) { return _spawnve(flags, name, argv, envv); }
static inline intptr_t spawnvp(int flags, const char* name, const char* const* argv) { return _spawnvp(flags, name, argv); }
static inline intptr_t spawnvpe(int flags, const char* name, const char* const* argv, const char* const* envv) { return _spawnvpe(flags, name, argv, envv); }

#if defined(__GNUC__) && (__GNUC__ < 4)
extern intptr_t __cdecl execl(const char*,const char*,...) __attribute__((alias("_execl")));
extern intptr_t __cdecl execle(const char*,const char*,...) __attribute__((alias("_execle")));
extern intptr_t __cdecl execlp(const char*,const char*,...) __attribute__((alias("_execlp")));
extern intptr_t __cdecl execlpe(const char*,const char*,...) __attribute__((alias("_execlpe")));
extern intptr_t __cdecl spawnl(int,const char*,const char*,...) __attribute__((alias("_spawnl")));
extern intptr_t __cdecl spawnle(int,const char*,const char*,...) __attribute__((alias("_spawnle")));
extern intptr_t __cdecl spawnlp(int,const char*,const char*,...) __attribute__((alias("_spawnlp")));
extern intptr_t __cdecl spawnlpe(int,const char*,const char*,...) __attribute__((alias("_spawnlpe")));
#else
#define execl    _execl
#define execle   _execle
#define execlp   _execlp
#define execlpe  _execlpe
#define spawnl   _spawnl
#define spawnle  _spawnle
#define spawnlp  _spawnlp
#define spawnlpe _spawnlpe
#endif  /* __GNUC__ */

#endif /* __WINE_PROCESS_H */
