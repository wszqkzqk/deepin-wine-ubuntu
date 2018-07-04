/*
 * Copyright 2008 Hans Leidekker for CodeWeavers.
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
#ifndef __WINE_MSTCPIP_H
#define __WINE_MSTCPIP_H

#include <nldef.h>

struct tcp_keepalive
{
    ULONG onoff;
    ULONG keepalivetime;
    ULONG keepaliveinterval;
};

#ifndef USE_WS_PREFIX

#define SIO_RCVALL            _WSAIOW(IOC_VENDOR, 1)
#define SIO_RCVALL_MCAST      _WSAIOW(IOC_VENDOR, 2)
#define SIO_RCVALL_IGMPMCAST  _WSAIOW(IOC_VENDOR, 3)
#define SIO_KEEPALIVE_VALS    _WSAIOW(IOC_VENDOR, 4)
#define SIO_ABSORB_RTRALERT   _WSAIOW(IOC_VENDOR, 5)
#define SIO_UCAST_IF          _WSAIOW(IOC_VENDOR, 6)
#define SIO_LIMIT_BROADCASTS  _WSAIOW(IOC_VENDOR, 7)
#define SIO_INDEX_BIND        _WSAIOW(IOC_VENDOR, 8)
#define SIO_INDEX_MCASTIF     _WSAIOW(IOC_VENDOR, 9)
#define SIO_INDEX_ADD_MCAST   _WSAIOW(IOC_VENDOR, 10)
#define SIO_INDEX_DEL_MCAST   _WSAIOW(IOC_VENDOR, 11)

#define RCVALL_OFF             0
#define RCVALL_ON              1
#define RCVALL_SOCKETLEVELONLY 2

#else

#define WS_SIO_RCVALL            _WSAIOW(WS_IOC_VENDOR, 1)
#define WS_SIO_RCVALL_MCAST      _WSAIOW(WS_IOC_VENDOR, 2)
#define WS_SIO_RCVALL_IGMPMCAST  _WSAIOW(WS_IOC_VENDOR, 3)
#define WS_SIO_KEEPALIVE_VALS    _WSAIOW(WS_IOC_VENDOR, 4)
#define WS_SIO_ABSORB_RTRALERT   _WSAIOW(WS_IOC_VENDOR, 5)
#define WS_SIO_UCAST_IF          _WSAIOW(WS_IOC_VENDOR, 6)
#define WS_SIO_LIMIT_BROADCASTS  _WSAIOW(WS_IOC_VENDOR, 7)
#define WS_SIO_INDEX_BIND        _WSAIOW(WS_IOC_VENDOR, 8)
#define WS_SIO_INDEX_MCASTIF     _WSAIOW(WS_IOC_VENDOR, 9)
#define WS_SIO_INDEX_ADD_MCAST   _WSAIOW(WS_IOC_VENDOR, 10)
#define WS_SIO_INDEX_DEL_MCAST   _WSAIOW(WS_IOC_VENDOR, 11)

#define WS_RCVALL_OFF             0
#define WS_RCVALL_ON              1
#define WS_RCVALL_SOCKETLEVELONLY 2

#endif /* USE_WS_PREFIX */

#endif /* __WINE_MSTCPIP_H */
