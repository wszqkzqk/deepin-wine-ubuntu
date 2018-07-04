/*
 * Copyright 2002 Andriy Palamarchuk
 *
 * General lm header which includes other lm headers.
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

#ifndef __WINE_LM_H
#define __WINE_LM_H

#include <lmcons.h>
#include <lmerr.h>
#include <lmshare.h>
#include <lmaccess.h>
#include <lmserver.h>
#include <lmwksta.h>
#include <lmapibuf.h>
#include <lmstats.h>
#include <lmjoin.h>
#include <lmmsg.h>
#include <lmuse.h>
/* FIXME: #include <lmalert.h> */
/* FIXME: #include <lmremutl.h> */
/* FIXME: #include <lmrepl.h> */
/* FIXME: #include <lmsvc.h> */
/* FIXME: #include <lmerrlog.h> */
/* FIXME: #include <lmconfig.h> */
/* FIXME: #include <lmaudit.h> */

/* The following are obsolete headers */
#include <lmbrowsr.h>

#endif
