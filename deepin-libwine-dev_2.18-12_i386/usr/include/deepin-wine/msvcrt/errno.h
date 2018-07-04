/*
 * Copyright 2001 Jon Griffiths
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

#ifndef __WINE_ERRNO_H
#define __WINE_ERRNO_H

#include <crtdefs.h>

#  define EPERM   1
#  define ENOENT  2
#  define ESRCH   3
#  define EINTR   4
#  define EIO     5
#  define ENXIO   6
#  define E2BIG   7
#  define ENOEXEC 8
#  define EBADF   9
#  define ECHILD  10
#  define EAGAIN  11
#  define ENOMEM  12
#  define EACCES  13
#  define EFAULT  14
#  define EBUSY   16
#  define EEXIST  17
#  define EXDEV   18
#  define ENODEV  19
#  define ENOTDIR 20
#  define EISDIR  21
#  define EINVAL  22
#  define ENFILE  23
#  define EMFILE  24
#  define ENOTTY  25
#  define EFBIG   27
#  define ENOSPC  28
#  define ESPIPE  29
#  define EROFS   30
#  define EMLINK  31
#  define EPIPE   32
#  define EDOM    33
#  define ERANGE  34
#  define EDEADLK 36
#  define EDEADLOCK EDEADLK
#  define ENAMETOOLONG 38
#  define ENOLCK  39
#  define ENOSYS  40
#  define ENOTEMPTY 41
#  define EILSEQ    42

#  define STRUNCATE 80

#ifdef __cplusplus
extern "C" {
#endif

extern int* __cdecl _errno(void);

#ifdef __cplusplus
}
#endif

#define errno        (*_errno())

#endif  /* __WINE_ERRNO_H */
