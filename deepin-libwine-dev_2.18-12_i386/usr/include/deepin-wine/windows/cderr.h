/*
 * Copyright (C) 1999 Bertho Stultiens
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

#ifndef __WINE_CDERR_H
#define __WINE_CDERR_H

/* General error codes */
#define CDERR_DIALOGFAILURE	0xFFFF
#define CDERR_GENERALCODES	0x0000
#define CDERR_STRUCTSIZE	0x0001
#define CDERR_INITIALIZATION	0x0002
#define CDERR_NOTEMPLATE	0x0003
#define CDERR_NOHINSTANCE	0x0004
#define CDERR_LOADSTRFAILURE	0x0005
#define CDERR_FINDRESFAILURE	0x0006
#define CDERR_LOADRESFAILURE	0x0007
#define CDERR_LOCKRESFAILURE	0x0008
#define CDERR_MEMALLOCFAILURE	0x0009
#define CDERR_MEMLOCKFAILURE	0x000A
#define CDERR_NOHOOK		0x000B
#define CDERR_REGISTERMSGFAIL	0x000C

/* Printer dialog error codes */
#define PDERR_PRINTERCODES	0x1000
#define PDERR_SETUPFAILURE	0x1001
#define PDERR_PARSEFAILURE	0x1002
#define PDERR_RETDEFFAILURE	0x1003
#define PDERR_LOADDRVFAILURE	0x1004
#define PDERR_GETDEVMODEFAIL	0x1005
#define PDERR_INITFAILURE	0x1006
#define PDERR_NODEVICES		0x1007
#define PDERR_NODEFAULTPRN	0x1008
#define PDERR_DNDMMISMATCH	0x1009
#define PDERR_CREATEICFAILURE	0x100A
#define PDERR_PRINTERNOTFOUND	0x100B
#define PDERR_DEFAULTDIFFERENT	0x100C

/* Chose font error codes */
#define CFERR_CHOOSEFONTCODES	0x2000
#define CFERR_NOFONTS		0x2001
#define CFERR_MAXLESSTHANMIN	0x2002

/* File{Open,Save} error codes */
#define FNERR_FILENAMECODES	0x3000
#define FNERR_SUBCLASSFAILURE	0x3001
#define FNERR_INVALIDFILENAME	0x3002
#define FNERR_BUFFERTOOSMALL	0x3003

/* Find/Replace error codes */
#define FRERR_FINDREPLACECODES	0x4000
#define FRERR_BUFFERLENGTHZERO	0x4001

/* Choose color error codes */
#define CCERR_CHOOSECOLORCODES	0x5000

#endif
