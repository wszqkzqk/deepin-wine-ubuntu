/*
 * Wine exception handling
 *
 * Copyright (c) 1999 Alexandre Julliard
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

#ifndef __WINE_WINE_EXCEPTION_H
#define __WINE_WINE_EXCEPTION_H

#include <setjmp.h>
#include <windef.h>
#include <excpt.h>

#ifdef __cplusplus
extern "C" {
#endif

/* The following definitions allow using exceptions in Wine and Winelib code
 *
 * They should be used like this:
 *
 * __TRY
 * {
 *     do some stuff that can raise an exception
 * }
 * __EXCEPT(filter_func)
 * {
 *     handle the exception here
 * }
 * __ENDTRY
 *
 * or
 *
 * __TRY
 * {
 *     do some stuff that can raise an exception
 * }
 * __FINALLY(finally_func)
 *
 * The filter_func and finally_func functions must be defined like this:
 *
 * LONG CALLBACK filter_func( PEXCEPTION_POINTERS __eptr ) { ... }
 *
 * void CALLBACK finally_func( BOOL __normal ) { ... }
 *
 * The filter function must return one of the EXCEPTION_* code; it can
 * use GetExceptionInformation() and GetExceptionCode() to retrieve the
 * exception info.
 *
 * Warning: inside a __TRY or __EXCEPT block, 'break' or 'continue' statements
 *          break out of the current block. You cannot use 'return', 'goto'
 *          or 'longjmp' to leave a __TRY block, as this will surely crash.
 *          You can use them to leave a __EXCEPT block though.
 *
 * -- AJ
 */

#ifndef __GNUC__
#define __attribute__(x) /* nothing */
#endif

/* Define this if you want to use your compiler built-in __try/__except support.
 * This is only useful when compiling to a native Windows binary, as the built-in
 * compiler exceptions will most certainly not work under Winelib.
 */
#ifdef USE_COMPILER_EXCEPTIONS

#define __TRY __try
#define __EXCEPT(func) __except((func)(GetExceptionInformation()))
#define __EXCEPT_CTX(func, ctx) __except((func)(GetExceptionInformation(), ctx))
#define __FINALLY(func) __finally { (func)(!AbnormalTermination()); }
#define __FINALLY_CTX(func, ctx) __finally { (func)(!AbnormalTermination(), ctx); }
#define __ENDTRY /*nothing*/
#define __EXCEPT_PAGE_FAULT __except(GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION)
#define __EXCEPT_ALL __except(EXCEPTION_EXECUTE_HANDLER)

#else  /* USE_COMPILER_EXCEPTIONS */

#if defined(__MINGW32__) || defined(__CYGWIN__)
#define sigjmp_buf jmp_buf
#define sigsetjmp(buf,sigs) setjmp(buf)
#define siglongjmp(buf,val) longjmp(buf,val)
#endif

extern void __wine_rtl_unwind( EXCEPTION_REGISTRATION_RECORD* frame, EXCEPTION_RECORD *record,
                               void (*target)(void) ) DECLSPEC_HIDDEN DECLSPEC_NORETURN;
extern DWORD __wine_exception_handler( EXCEPTION_RECORD *record,
                                       EXCEPTION_REGISTRATION_RECORD *frame,
                                       CONTEXT *context,
                                       EXCEPTION_REGISTRATION_RECORD **pdispatcher ) DECLSPEC_HIDDEN;
extern DWORD __wine_exception_ctx_handler( EXCEPTION_RECORD *record,
                                           EXCEPTION_REGISTRATION_RECORD *frame,
                                           CONTEXT *context,
                                           EXCEPTION_REGISTRATION_RECORD **pdispatcher ) DECLSPEC_HIDDEN;
extern DWORD __wine_exception_handler_page_fault( EXCEPTION_RECORD *record,
                                                  EXCEPTION_REGISTRATION_RECORD *frame,
                                                  CONTEXT *context,
                                                  EXCEPTION_REGISTRATION_RECORD **pdispatcher ) DECLSPEC_HIDDEN;
extern DWORD __wine_exception_handler_all( EXCEPTION_RECORD *record,
                                           EXCEPTION_REGISTRATION_RECORD *frame,
                                           CONTEXT *context,
                                           EXCEPTION_REGISTRATION_RECORD **pdispatcher ) DECLSPEC_HIDDEN;
extern DWORD __wine_finally_handler( EXCEPTION_RECORD *record,
                                     EXCEPTION_REGISTRATION_RECORD *frame,
                                     CONTEXT *context,
                                     EXCEPTION_REGISTRATION_RECORD **pdispatcher ) DECLSPEC_HIDDEN;
extern DWORD __wine_finally_ctx_handler( EXCEPTION_RECORD *record,
                                         EXCEPTION_REGISTRATION_RECORD *frame,
                                         CONTEXT *context,
                                         EXCEPTION_REGISTRATION_RECORD **pdispatcher ) DECLSPEC_HIDDEN;

#define __TRY \
    do { __WINE_FRAME __f; \
         int __first = 1; \
         for (;;) if (!__first) \
         { \
             do {

#define __EXCEPT(func) \
             } while(0); \
             __wine_pop_frame( &__f.frame ); \
             break; \
         } else { \
             __f.frame.Handler = __wine_exception_handler; \
             __f.u.filter = (func); \
             if (sigsetjmp( __f.jmp, 0 )) { \
                 const __WINE_FRAME * const __eptr __attribute__((unused)) = &__f; \
                 do {

#define __EXCEPT_CTX(func, context) \
             } while(0); \
             __wine_pop_frame( &__f.frame ); \
             break; \
         } else { \
             __f.frame.Handler = __wine_exception_ctx_handler; \
             __f.u.filter_ctx = (func); \
             __f.ctx = context; \
             if (sigsetjmp( __f.jmp, 0 )) { \
                 const __WINE_FRAME * const __eptr __attribute__((unused)) = &__f; \
                 do {

/* convenience handler for page fault exceptions */
#define __EXCEPT_PAGE_FAULT \
             } while(0); \
             __wine_pop_frame( &__f.frame ); \
             break; \
         } else { \
             __f.frame.Handler = __wine_exception_handler_page_fault; \
             if (sigsetjmp( __f.jmp, 0 )) { \
                 const __WINE_FRAME * const __eptr __attribute__((unused)) = &__f; \
                 do {

/* convenience handler for all exception */
#define __EXCEPT_ALL \
             } while(0); \
             __wine_pop_frame( &__f.frame ); \
             break; \
         } else { \
             __f.frame.Handler = __wine_exception_handler_all; \
             if (sigsetjmp( __f.jmp, 0 )) { \
                 const __WINE_FRAME * const __eptr __attribute__((unused)) = &__f; \
                 do {

#define __ENDTRY \
                 } while (0); \
                 break; \
             } \
             __wine_push_frame( &__f.frame ); \
             __first = 0; \
         } \
    } while (0);

#define __FINALLY(func) \
             } while(0); \
             __wine_pop_frame( &__f.frame ); \
             (func)(1); \
             break; \
         } else { \
             __f.frame.Handler = __wine_finally_handler; \
             __f.u.finally_func = (func); \
             __wine_push_frame( &__f.frame ); \
             __first = 0; \
         } \
    } while (0);

#define __FINALLY_CTX(func, context) \
             } while(0); \
             __wine_pop_frame( &__f.frame ); \
             (func)(1, context); \
             break; \
         } else { \
             __f.frame.Handler = __wine_finally_ctx_handler; \
             __f.u.finally_func_ctx = (func); \
             __f.ctx = context; \
             __wine_push_frame( &__f.frame ); \
             __first = 0; \
         } \
    } while (0);


typedef LONG (CALLBACK *__WINE_FILTER)(PEXCEPTION_POINTERS);
typedef LONG (CALLBACK *__WINE_FILTER_CTX)(PEXCEPTION_POINTERS, void*);
typedef void (CALLBACK *__WINE_FINALLY)(BOOL);
typedef void (CALLBACK *__WINE_FINALLY_CTX)(BOOL, void*);

#define GetExceptionInformation() (__eptr)
#define GetExceptionCode()        (__eptr->ExceptionRecord->ExceptionCode)
#define AbnormalTermination()     (!__normal)

typedef struct __tagWINE_FRAME
{
    EXCEPTION_REGISTRATION_RECORD frame;
    union
    {
        /* exception data */
        __WINE_FILTER filter;
        __WINE_FILTER_CTX filter_ctx;
        /* finally data */
        __WINE_FINALLY finally_func;
        __WINE_FINALLY_CTX finally_func_ctx;
    } u;
    void *ctx;
    sigjmp_buf jmp;
    /* hack to make GetExceptionCode() work in handler */
    DWORD ExceptionCode;
    const struct __tagWINE_FRAME *ExceptionRecord;
} __WINE_FRAME;

#endif /* USE_COMPILER_EXCEPTIONS */

static inline EXCEPTION_REGISTRATION_RECORD *__wine_push_frame( EXCEPTION_REGISTRATION_RECORD *frame )
{
#if defined(__GNUC__) && defined(__i386__)
    EXCEPTION_REGISTRATION_RECORD *prev;
    __asm__ __volatile__(".byte 0x64\n\tmovl (0),%0"
                         "\n\tmovl %0,(%1)"
                         "\n\t.byte 0x64\n\tmovl %1,(0)"
                         : "=&r" (prev) : "r" (frame) : "memory" );
    return prev;
#else
    NT_TIB *teb = (NT_TIB *)NtCurrentTeb();
    frame->Prev = teb->ExceptionList;
    teb->ExceptionList = frame;
    return frame->Prev;
#endif
}

static inline EXCEPTION_REGISTRATION_RECORD *__wine_pop_frame( EXCEPTION_REGISTRATION_RECORD *frame )
{
#if defined(__GNUC__) && defined(__i386__)
    __asm__ __volatile__(".byte 0x64\n\tmovl %0,(0)"
                         : : "r" (frame->Prev) : "memory" );
    return frame->Prev;

#else
    NT_TIB *teb = (NT_TIB *)NtCurrentTeb();
    teb->ExceptionList = frame->Prev;
    return frame->Prev;
#endif
}

static inline EXCEPTION_REGISTRATION_RECORD *__wine_get_frame(void)
{
#if defined(__GNUC__) && defined(__i386__)
    EXCEPTION_REGISTRATION_RECORD *ret;
    __asm__ __volatile__(".byte 0x64\n\tmovl (0),%0" : "=r" (ret) );
    return ret;
#else
    NT_TIB *teb = (NT_TIB *)NtCurrentTeb();
    return teb->ExceptionList;
#endif
}

/* Exception handling flags - from OS/2 2.0 exception handling */

/* Win32 seems to use the same flags as ExceptionFlags in an EXCEPTION_RECORD */
#define EH_NONCONTINUABLE   0x01
#define EH_UNWINDING        0x02
#define EH_EXIT_UNWIND      0x04
#define EH_STACK_INVALID    0x08
#define EH_NESTED_CALL      0x10
#define EH_TARGET_UNWIND    0x20
#define EH_COLLIDED_UNWIND  0x40

/* Wine-specific exceptions codes */

#define EXCEPTION_WINE_STUB       0x80000100  /* stub entry point called */
#define EXCEPTION_WINE_ASSERTION  0x80000101  /* assertion failed */

/* unhandled return status from vm86 mode */
#define EXCEPTION_VM86_INTx       0x80000110
#define EXCEPTION_VM86_STI        0x80000111
#define EXCEPTION_VM86_PICRETURN  0x80000112

extern void __wine_enter_vm86( CONTEXT *context );

#ifdef __cplusplus
}
#endif

#endif  /* __WINE_WINE_EXCEPTION_H */
