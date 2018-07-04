/*
 * DISPDIB.dll
 *
 * Copyright 1998 Ove Kaaven
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

#ifndef __WINE_DISPDIB_H
#define __WINE_DISPDIB_H

/* error codes */
#define DISPLAYDIB_NOERROR        0x0000
#define DISPLAYDIB_NOTSUPPORTED   0x0001
#define DISPLAYDIB_INVALIDDIB     0x0002
#define DISPLAYDIB_INVALIDFORMAT  0x0003
#define DISPLAYDIB_INVALIDTASK    0x0004

/* flags */
#define DISPLAYDIB_NOPALETTE      0x0010
#define DISPLAYDIB_NOCENTER       0x0020
#define DISPLAYDIB_NOWAIT         0x0040
#define DISPLAYDIB_BEGIN          0x8000
#define DISPLAYDIB_END            0x4000
#define DISPLAYDIB_MODE           0x000F /* mask */
#define DISPLAYDIB_MODE_DEFAULT   0x0000
#define DISPLAYDIB_MODE_320x200x8 0x0001
#define DISPLAYDIB_MODE_320x240x8 0x0005

WORD WINAPI DisplayDib( LPBITMAPINFO lpbi, LPSTR lpBits, WORD wFlags );

#endif /* __WINE_DISPDIB_H */
