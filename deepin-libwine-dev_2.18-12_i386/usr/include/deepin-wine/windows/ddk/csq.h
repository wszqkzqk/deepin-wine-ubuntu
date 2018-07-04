/*
 * Copyright (C) 2014 Austin English
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

#include "ddk/ntddk.h"

#ifndef __WINE_CSQ_H
#define __WINE_CSQ_H

typedef struct _IO_CSQ IO_CSQ, *PIO_CSQ;
typedef VOID (WINAPI *PIO_CSQ_ACQUIRE_LOCK)(PIO_CSQ Csq, PKIRQL Irql);
typedef VOID (WINAPI *PIO_CSQ_COMPLETE_CANCELED_IRP)(PIO_CSQ Csq, PIRP Irp);
typedef VOID (WINAPI *PIO_CSQ_INSERT_IRP)(struct _IO_CSQ *Csq, PIRP Irp);
typedef PIRP (WINAPI *PIO_CSQ_PEEK_NEXT_IRP)(PIO_CSQ Csq, PIRP Irp, PVOID PeekContext);
typedef VOID (WINAPI *PIO_CSQ_RELEASE_LOCK)(PIO_CSQ Csq, KIRQL Irql);
typedef VOID (WINAPI *PIO_CSQ_REMOVE_IRP)(PIO_CSQ Csq, PIRP Irp);

#endif  /* __WINE_CSQ_H */
