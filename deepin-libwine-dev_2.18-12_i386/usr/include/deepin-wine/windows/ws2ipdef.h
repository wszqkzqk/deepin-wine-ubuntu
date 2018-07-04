/*
 * Copyright (C) 2009 Robert Shearman
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

#ifndef __WS2IPDEF__
#define __WS2IPDEF__

#include <in6addr.h>

#ifdef USE_WS_PREFIX
#define WS(x)    WS_##x
#else
#define WS(x)    x
#endif

typedef struct WS(sockaddr_in6_old)
{
   SHORT    sin6_family;
   USHORT   sin6_port;
   ULONG    sin6_flowinfo;
   IN6_ADDR sin6_addr;
} SOCKADDR_IN6_OLD,*PSOCKADDR_IN6_OLD, *LPSOCKADDR_IN6_OLD;

typedef union sockaddr_gen
{
   struct WS(sockaddr) Address;
   struct WS(sockaddr_in)  AddressIn;
   struct WS(sockaddr_in6_old) AddressIn6;
} WS(sockaddr_gen);

/* Structure to keep interface specific information */
typedef struct _INTERFACE_INFO
{
    ULONG             iiFlags;             /* Interface flags */
    WS(sockaddr_gen)  iiAddress;           /* Interface address */
    WS(sockaddr_gen)  iiBroadcastAddress;  /* Broadcast address */
    WS(sockaddr_gen)  iiNetmask;           /* Network mask */
} INTERFACE_INFO, * LPINTERFACE_INFO;

/* Possible flags for the  iiFlags - bitmask  */
#ifndef USE_WS_PREFIX
#define IFF_UP                0x00000001 /* Interface is up */
#define IFF_BROADCAST         0x00000002 /* Broadcast is  supported */
#define IFF_LOOPBACK          0x00000004 /* this is loopback interface */
#define IFF_POINTTOPOINT      0x00000008 /* this is point-to-point interface */
#define IFF_MULTICAST         0x00000010 /* multicast is supported */
#else
#define WS_IFF_UP             0x00000001 /* Interface is up */
#define WS_IFF_BROADCAST      0x00000002 /* Broadcast is  supported */
#define WS_IFF_LOOPBACK       0x00000004 /* this is loopback interface */
#define WS_IFF_POINTTOPOINT   0x00000008 /* this is point-to-point interface */
#define WS_IFF_MULTICAST      0x00000010 /* multicast is supported */
#endif /* USE_WS_PREFIX */

#ifndef USE_WS_PREFIX
#define IP_OPTIONS                      1
#define IP_HDRINCL                      2
#define IP_TOS                          3
#define IP_TTL                          4
#define IP_MULTICAST_IF                 9
#define IP_MULTICAST_TTL                10
#define IP_MULTICAST_LOOP               11
#define IP_ADD_MEMBERSHIP               12
#define IP_DROP_MEMBERSHIP              13
#define IP_DONTFRAGMENT                 14
#define IP_ADD_SOURCE_MEMBERSHIP        15
#define IP_DROP_SOURCE_MEMBERSHIP       16
#define IP_BLOCK_SOURCE                 17
#define IP_UNBLOCK_SOURCE               18
#define IP_PKTINFO                      19
#define IP_HOPLIMIT                     21
#define IP_RECEIVE_BROADCAST            22
#define IP_RECVIF                       24
#define IP_RECVDSTADDR                  25
#define IP_IFLIST                       28
#define IP_ADD_IFLIST                   29
#define IP_DEL_IFLIST                   30
#define IP_UNICAST_IF                   31
#define IP_RTHDR                        32
#define IP_RECVRTHDR                    38
#else
#define WS_IP_OPTIONS                   1
#define WS_IP_HDRINCL                   2
#define WS_IP_TOS                       3
#define WS_IP_TTL                       4
#define WS_IP_MULTICAST_IF              9
#define WS_IP_MULTICAST_TTL             10
#define WS_IP_MULTICAST_LOOP            11
#define WS_IP_ADD_MEMBERSHIP            12
#define WS_IP_DROP_MEMBERSHIP           13
#define WS_IP_DONTFRAGMENT              14
#define WS_IP_ADD_SOURCE_MEMBERSHIP     15
#define WS_IP_DROP_SOURCE_MEMBERSHIP    16
#define WS_IP_BLOCK_SOURCE              17
#define WS_IP_UNBLOCK_SOURCE            18
#define WS_IP_PKTINFO                   19
#define WS_IP_HOPLIMIT                  21
#define WS_IP_RECEIVE_BROADCAST         22
#define WS_IP_RECVIF                    24
#define WS_IP_RECVDSTADDR               25
#define WS_IP_IFLIST                    28
#define WS_IP_ADD_IFLIST                29
#define WS_IP_DEL_IFLIST                30
#define WS_IP_UNICAST_IF                31
#define WS_IP_RTHDR                     32
#define WS_IP_RECVRTHDR                 38
#endif /* USE_WS_PREFIX */

typedef struct WS(sockaddr_in6)
{
   SHORT    sin6_family;
   USHORT   sin6_port;
   ULONG    sin6_flowinfo;
   IN6_ADDR sin6_addr;
   ULONG    sin6_scope_id;
} SOCKADDR_IN6,*PSOCKADDR_IN6, *LPSOCKADDR_IN6;

typedef struct WS(sockaddr_in6_pair)
{
    PSOCKADDR_IN6 SourceAddress;
    PSOCKADDR_IN6 DestinationAddress;
} SOCKADDR_IN6_PAIR, *PSOCKADDR_IN6_PAIR;

typedef union _SOCKADDR_INET
{
    SOCKADDR_IN     Ipv4;
    SOCKADDR_IN6    Ipv6;
    ADDRESS_FAMILY  si_family;
} SOCKADDR_INET, *PSOCKADDR_INET;

/*
 * Multicast group information
 */

typedef struct WS(ip_mreq)
{
    struct WS(in_addr) imr_multiaddr;
    struct WS(in_addr) imr_interface;
} WS(IP_MREQ), *WS(PIP_MREQ);

typedef struct WS(ip_mreq_source) {
    struct WS(in_addr) imr_multiaddr;
    struct WS(in_addr) imr_sourceaddr;
    struct WS(in_addr) imr_interface;
} WS(IP_MREQ_SOURCE), *WS(PIP_MREQ_SOURCE);

typedef struct WS(ip_msfilter) {
    struct WS(in_addr) imsf_multiaddr;
    struct WS(in_addr) imsf_interface;
    ULONG              imsf_fmode;
    ULONG              imsf_numsrc;
    struct WS(in_addr) imsf_slist[1];
} WS(IP_MSFILTER), *WS(PIP_MSFILTER);

typedef struct WS(in_pktinfo) {
    IN_ADDR ipi_addr;
    UINT    ipi_ifindex;
} IN_PKTINFO, *PIN_PKTINFO;

#ifndef USE_WS_PREFIX
#define IPV6_OPTIONS                    1
#define IPV6_HDRINCL                    2
#define IPV6_UNICAST_HOPS               4
#define IPV6_MULTICAST_IF               9
#define IPV6_MULTICAST_HOPS             10
#define IPV6_MULTICAST_LOOP             11
#define IPV6_ADD_MEMBERSHIP             12
#define IPV6_JOIN_GROUP                 IPV6_ADD_MEMBERSHIP
#define IPV6_DROP_MEMBERSHIP            13
#define IPV6_LEAVE_GROUP                IPV6_DROP_MEMBERSHIP
#define IPV6_DONTFRAG                   14
#define IPV6_PKTINFO                    19
#define IPV6_HOPLIMIT                   21
#define IPV6_PROTECTION_LEVEL           23
#define IPV6_RECVIF                     24
#define IPV6_RECVDSTADDR                25
#define IPV6_CHECKSUM                   26
#define IPV6_V6ONLY                     27
#define IPV6_IFLIST                     28
#define IPV6_ADD_IFLIST                 29
#define IPV6_DEL_IFLIST                 30
#define IPV6_UNICAST_IF                 31
#define IPV6_RTHDR                      32
#define IPV6_RECVRTHDR                  38
#else
#define WS_IPV6_OPTIONS                 1
#define WS_IPV6_HDRINCL                 2
#define WS_IPV6_UNICAST_HOPS            4
#define WS_IPV6_MULTICAST_IF            9
#define WS_IPV6_MULTICAST_HOPS          10
#define WS_IPV6_MULTICAST_LOOP          11
#define WS_IPV6_ADD_MEMBERSHIP          12
#define WS_IPV6_DROP_MEMBERSHIP         13
#define WS_IPV6_LEAVE_GROUP             WS_IPV6_DROP_MEMBERSHIP
#define WS_IPV6_DONTFRAG                14
#define WS_IPV6_PKTINFO                 19
#define WS_IPV6_HOPLIMIT                21
#define WS_IPV6_PROTECTION_LEVEL        23
#define WS_IPV6_RECVIF                  24
#define WS_IPV6_RECVDSTADDR             25
#define WS_IPV6_CHECKSUM                26
#define WS_IPV6_V6ONLY                  27
#define WS_IPV6_IFLIST                  28
#define WS_IPV6_ADD_IFLIST              29
#define WS_IPV6_DEL_IFLIST              30
#define WS_IPV6_UNICAST_IF              31
#define WS_IPV6_RTHDR                   32
#define WS_IPV6_RECVRTHDR               38
#endif /* USE_WS_PREFIX */

#ifndef USE_WS_PREFIX
#define TCP_OFFLOAD_NO_PREFERENCE       0
#define TCP_OFFLOAD_NOT_PREFERRED       1
#define TCP_OFFLOAD_PREFERRED           2
#else
#define WS_TCP_OFFLOAD_NO_PREFERENCE    0
#define WS_TCP_OFFLOAD_NOT_PREFERRED    1
#define WS_TCP_OFFLOAD_PREFERRED        2
#endif /* USE_WS_PREFIX */

#ifndef USE_WS_PREFIX
/* TCP_NODELAY is defined elsewhere */
#define TCP_EXPEDITED_1122              2
#define TCP_KEEPALIVE                   3
#define TCP_MAXSEG                      4
#define TCP_MAXRT                       5
#define TCP_STDURG                      6
#define TCP_NOURG                       7
#define TCP_ATMARK                      8
#define TCP_NOSYNRETRIES                9
#define TCP_TIMESTAMPS                  10
#define TCP_OFFLOAD_PREFERENCE          11
#define TCP_CONGESTION_ALGORITHM        12
#define TCP_DELAY_FIN_ACK               13
#else
/* WS_TCP_NODELAY is defined elsewhere */
#define WS_TCP_EXPEDITED_1122           2
#define WS_TCP_KEEPALIVE                3
#define WS_TCP_MAXSEG                   4
#define WS_TCP_MAXRT                    5
#define WS_TCP_STDURG                   6
#define WS_TCP_NOURG                    7
#define WS_TCP_ATMARK                   8
#define WS_TCP_NOSYNRETRIES             9
#define WS_TCP_TIMESTAMPS               10
#define WS_TCP_OFFLOAD_PREFERENCE       11
#define WS_TCP_CONGESTION_ALGORITHM     12
#define WS_TCP_DELAY_FIN_ACK            13
#endif /* USE_WS_PREFIX */

#ifndef USE_WS_PREFIX
#define INET_ADDRSTRLEN         22
#define INET6_ADDRSTRLEN        65
#define IN6ADDR_ANY_INIT        { 0 }
#define IN6ADDR_LOOPBACK_INIT   { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }
#else
#define WS_INET_ADDRSTRLEN      22
#define WS_INET6_ADDRSTRLEN     65
#define WS_IN6ADDR_ANY_INIT     { 0 }
#define WS_IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }
#endif /* USE_WS_PREFIX */

#ifdef __cplusplus
extern "C" {
#endif

static inline BOOL WS(IN6_IS_ADDR_LOOPBACK) ( const IN6_ADDR *a )
{
    return (BOOL)((a->s6_words[0] == 0) &&
                  (a->s6_words[1] == 0) &&
                  (a->s6_words[2] == 0) &&
                  (a->s6_words[3] == 0) &&
                  (a->s6_words[4] == 0) &&
                  (a->s6_words[5] == 0) &&
                  (a->s6_words[6] == 0) &&
                  (a->s6_words[7] == 0x0100));
}

#ifdef __cplusplus
}
#endif

#endif /* __WS2IPDEF__ */
