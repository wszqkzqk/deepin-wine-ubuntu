/*
 * Copyright (C) 2003 Juan Lang
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
#ifndef __WINE_NLDEF_H
#define __WINE_NLDEF_H

typedef enum
{
    IpPrefixOriginOther = 0,
    IpPrefixOriginManual,
    IpPrefixOriginWellKnown,
    IpPrefixOriginDhcp,
    IpPrefixOriginRouterAdvertisement,
    IpPrefixOriginUnchanged = 16,
} NL_PREFIX_ORIGIN;

typedef enum
{
    IpSuffixOriginOther = 0,
    IpSuffixOriginManual,
    IpSuffixOriginWellKnown,
    IpSuffixOriginDhcp,
    IpSuffixOriginLinkLayerAddress,
    IpSuffixOriginRandom,
    IpSuffixOriginUnchanged = 16,
} NL_SUFFIX_ORIGIN;

typedef enum
{
    IpDadStateInvalid = 0,
    IpDadStateTentative,
    IpDadStateDuplicate,
    IpDadStateDeprecated,
    IpDadStatePreferred,
} NL_DAD_STATE;

typedef enum _NL_LINK_LOCAL_ADDRESS_BEHAVIOR
{
    LinkLocalAlwaysOff = 0,
    LinkLocalDelayed,
    LinkLocalAlwaysOn,
    LinkLocalUnchanged = -1,
} NL_LINK_LOCAL_ADDRESS_BEHAVIOR;

typedef enum _NL_ROUTER_DISCOVERY_BEHAVIOR
{
    RouterDiscoveryDisabled = 0,
    RouterDiscoveryEnabled,
    RouterDiscoveryDhcp,
    RouterDiscoveryUnchanged = -1,
} NL_ROUTER_DISCOVERY_BEHAVIOR;

typedef enum
{
#define MAKE_ROUTE_PROTOCOL(name, value) \
    MIB_IPPROTO_ ## name = value, \
    PROTO_IP_ ## name = value

    MAKE_ROUTE_PROTOCOL(OTHER,   1),
    MAKE_ROUTE_PROTOCOL(LOCAL,   2),
    MAKE_ROUTE_PROTOCOL(NETMGMT, 3),
    MAKE_ROUTE_PROTOCOL(ICMP,    4),
    MAKE_ROUTE_PROTOCOL(EGP,     5),
    MAKE_ROUTE_PROTOCOL(GGP,     6),
    MAKE_ROUTE_PROTOCOL(HELLO,   7),
    MAKE_ROUTE_PROTOCOL(RIP,     8),
    MAKE_ROUTE_PROTOCOL(IS_IS,   9),
    MAKE_ROUTE_PROTOCOL(ES_IS,   10),
    MAKE_ROUTE_PROTOCOL(CISCO,   11),
    MAKE_ROUTE_PROTOCOL(BBN,     12),
    MAKE_ROUTE_PROTOCOL(OSPF,    13),
    MAKE_ROUTE_PROTOCOL(BGP,     14),

    MAKE_ROUTE_PROTOCOL(NT_AUTOSTATIC,     10002),
    MAKE_ROUTE_PROTOCOL(NT_STATIC,         10006),
    MAKE_ROUTE_PROTOCOL(NT_STATIC_NON_DOD, 10007),
} NL_ROUTE_PROTOCOL, *PNL_ROUTE_PROTOCOL;

typedef struct _NL_INTERFACE_OFFLOAD_ROD
{
    BOOLEAN NlChecksumSupported : 1;
    BOOLEAN NlOptionsSupported : 1;
    BOOLEAN TlDatagramChecksumSupported : 1;
    BOOLEAN TlStreamChecksumSupported : 1;
    BOOLEAN TlStreamOptionsSupported : 1;
    BOOLEAN FastPathCompatible : 1;
    BOOLEAN TlLargeSendOffloadSupported : 1;
    BOOLEAN TlGiantSendOffloadSupported : 1;
} NL_INTERFACE_OFFLOAD_ROD, *PNL_INTERFACE_OFFLOAD_ROD;

#endif /* __WINE_NLDEF_H */
