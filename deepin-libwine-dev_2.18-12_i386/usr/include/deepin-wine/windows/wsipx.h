/*
 * Copyright (C) 2001 Stefan Leichter
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

#ifndef _WINE_WSIPX_
#define _WINE_WSIPX_

#ifdef USE_WS_PREFIX
# define WS(x)    WS_##x
#else
# define WS(x)    x
#endif

typedef struct WS_sockaddr_ipx
{
    short sa_family;
    char sa_netnum[4];
    char sa_nodenum[6];
    unsigned short sa_socket;
} SOCKADDR_IPX, *PSOCKADDR_IPX, *LPSOCKADDR_IPX;

/*
 * constants
 */
#ifndef USE_WS_PREFIX
#define NSPROTO_IPX                 1000
#define NSPROTO_SPX                 1256
#define NSPROTO_SPXII               1257
#else
#define WS_NSPROTO_IPX              1000
#define WS_NSPROTO_SPX              1256
#define WS_NSPROTO_SPXII            1257
#endif

#undef WS
#endif /* _WINE_WSIPX_ */
