/*
 * Copyright (C) 2009 Jeff Latimer
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

#ifndef __IN6ADDR__
#define __IN6ADDR__

#ifdef USE_WS_PREFIX
#define WS(x)    WS_##x
#else
#define WS(x)    x
#endif

typedef struct WS(in6_addr) {
    union {
        UCHAR  Byte[16];
        USHORT Word[8];
    } u;
} IN6_ADDR, *PIN6_ADDR, *LPIN6_ADDR;

#define in_addr6    WS(in6_addr)

#ifdef USE_WS_PREFIX
#define WS__S6_un   u
#define WS__S6_u8   Byte
#define WS_s6_addr  WS__S6_un.WS__S6_u8
#else
#define _S6_un      u
#define _S6_u8      Byte
#define s6_addr     _S6_un._S6_u8
#endif

#define s6_bytes    u.Byte
#define s6_words    u.Word

#undef WS

#endif /* __IN6ADDR__ */
