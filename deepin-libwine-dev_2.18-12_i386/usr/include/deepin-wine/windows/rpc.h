/*
 *    RPC interface
 *
 * Copyright (C) the Wine project
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

#ifndef RPC_NO_WINDOWS_H
# include <windows.h>
#endif

#ifndef __WINE_RPC_H
#define __WINE_RPC_H

#if defined(__powerpc__) || defined(_MAC) /* ? */
# define __RPC_MAC__
 /* Also define __RPC_WIN32__ to ensure compatibility */
# define __RPC_WIN32__
#elif defined(_WIN64)
# define __RPC_WIN64__
#else
# define __RPC_WIN32__
#endif

#include <basetsd.h>

#define __RPC_FAR
#define __RPC_API  __stdcall
#define __RPC_USER __stdcall
#define __RPC_STUB __stdcall
#define RPC_ENTRY  __stdcall
#define RPCRTAPI
typedef LONG RPC_STATUS;

typedef void* I_RPC_HANDLE;

#include <rpcdce.h>
/* #include <rpcnsi.h> */
#include <rpcnterr.h>
#include <excpt.h>
#include <winerror.h>
#ifndef RPC_NO_WINDOWS_H
#include <rpcasync.h>
#endif

#ifdef USE_COMPILER_EXCEPTIONS

#define RpcTryExcept __try {
#define RpcExcept(expr) } __except (expr) {
#define RpcEndExcept }
#define RpcTryFinally __try {
#define RpcFinally } __finally {
#define RpcEndFinally }
#define RpcExceptionCode() GetExceptionCode()
#define RpcAbnormalTermination() AbnormalTermination()

#else /* USE_COMPILER_EXCEPTIONS */

/* ignore exception handling for now */
#define RpcTryExcept if (1) {
#define RpcExcept(expr) } else {
#define RpcEndExcept }
#define RpcTryFinally
#define RpcFinally
#define RpcEndFinally
#define RpcExceptionCode() 0
/* #define RpcAbnormalTermination() abort() */

#endif /* USE_COMPILER_EXCEPTIONS */

#endif /*__WINE_RPC_H */
