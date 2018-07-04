/* Includefile for the decompression library, lzexpand
 *
 * Copyright 1996 Marcus Meissner
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

#ifndef __WINE_LZEXPAND_H
#define __WINE_LZEXPAND_H

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

#define LZERROR_BADINHANDLE	-1	/* -1 */
#define LZERROR_BADOUTHANDLE	-2	/* -2 */
#define LZERROR_READ		-3	/* -3 */
#define LZERROR_WRITE		-4	/* -4 */
#define LZERROR_GLOBALLOC	-5	/* -5 */
#define LZERROR_GLOBLOCK	-6	/* -6 */
#define LZERROR_BADVALUE	-7	/* -7 */
#define LZERROR_UNKNOWNALG	-8	/* -8 */

VOID        WINAPI LZDone(void);
LONG        WINAPI CopyLZFile(HFILE,HFILE);
HFILE       WINAPI LZOpenFileA(LPSTR,LPOFSTRUCT,WORD);
HFILE       WINAPI LZOpenFileW(LPWSTR,LPOFSTRUCT,WORD);
#define     LZOpenFile WINELIB_NAME_AW(LZOpenFile)
INT         WINAPI LZRead(INT,LPSTR,INT);
INT         WINAPI LZStart(void);
void        WINAPI LZClose(HFILE);
LONG        WINAPI LZCopy(HFILE,HFILE);
HFILE       WINAPI LZInit(HFILE);
LONG        WINAPI LZSeek(HFILE,LONG,INT);
INT         WINAPI GetExpandedNameA(LPSTR,LPSTR);
INT         WINAPI GetExpandedNameW(LPWSTR,LPWSTR);
#define     GetExpandedName WINELIB_NAME_AW(GetExpandedName)

#ifdef __cplusplus
} /* extern "C" */
#endif /* defined(__cplusplus) */

#endif  /* __WINE_LZEXPAND_H */
