/* WINSOCK.H--definitions to be used with the WINSOCK.DLL
 *
 * This header file corresponds to version 1.1 of the Windows Sockets
 * specification.
 *
 * Copyright (C) the Wine project
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

#ifdef __WINESRC__
# ifndef __WINE_WINSOCK2__
#  error Please use Winsock2 in Wine
# endif
#endif

#ifndef __WINE_WINSOCKAPI_STDLIB_H
#define __WINE_WINSOCKAPI_STDLIB_H

/*
 * This section defines the items that conflict with the Unix headers.
 */
#ifndef USE_WS_PREFIX
/* We are not using the WS_ prefix we risk getting conflicts for
 * everything related to select.
 */
# ifdef FD_CLR
/* Too late, the Unix version of stdlib.h was included before winsock.h.
 * This means select and all the related stuff is already defined and we
 * cannot override types and function prototypes.
 * All we can do is disable all these symbols so that they are not used
 * inadvertently.
 */
#  include <sys/types.h>
#  undef FD_SETSIZE
#  undef FD_CLR
#  undef FD_SET
#  undef FD_ZERO
#  undef FD_ISSET

#  define FD_SETSIZE Include_winsock_h_before_stdlib_h_or_use_the_MSVCRT_library
#  define FD_CLR     Include_winsock_h_before_stdlib_h_or_use_the_MSVCRT_library
#  define FD_SET     Include_winsock_h_before_stdlib_h_or_use_the_MSVCRT_library
#  define FD_ZERO    Include_winsock_h_before_stdlib_h_or_use_the_MSVCRT_library
#  define FD_ISSET   Include_winsock_h_before_stdlib_h_or_use_the_MSVCRT_library
#  define fd_set     Include_winsock_h_before_stdlib_h_or_use_the_MSVCRT_library
#  define select     Include_winsock_h_before_stdlib_h_or_use_the_MSVCRT_library
# elif defined(RLIM_INFINITY)
/* On Darwin stdlib.h includes sys/resource.h which defines timeval but not the fd_set macros */
#  define fd_set unix_fd_set
#  include <sys/types.h>
#  include <time.h>
#  include <stdlib.h>
#  undef fd_set
#  undef FD_SETSIZE
#  undef FD_CLR
#  undef FD_SET
#  undef FD_ZERO
#  undef FD_ISSET
#  define select     Include_winsock_h_before_sys_types_h_or_use_the_MSVCRT_library
#  define timeval    Include_winsock_h_before_sys_types_h_or_use_the_MSVCRT_library
# else  /* FD_CLR */
/* stdlib.h has not been included yet so it's not too late. Include it now
 * making sure that none of the select symbols is affected. Then we can
 * define them with our own values.
 */
#  define fd_set unix_fd_set
#  define timeval unix_timeval
#  define select unix_select
#  define socklen_t unix_socklen_t
#  define u_long unix_u_long
#  include <sys/types.h>
#  include <time.h>
#  include <stdlib.h>
#  undef fd_set
#  undef timeval
#  undef select
#  undef socklen_t
#  undef u_long
#  undef FD_SETSIZE
#  undef FD_CLR
#  undef FD_SET
#  undef FD_ZERO
#  undef FD_ISSET
#  undef _TIMEVAL_DEFINED

#  define WS_DEFINE_SELECT
# endif /* FD_CLR */

#else
# define WS_DEFINE_SELECT
# include <sys/types.h>
# include <stdlib.h>
#endif /* !USE_WS_PREFIX */

#endif /* __WINE_WINSOCKAPI_STDLIB_H */

#include <windows.h>

#ifndef _WINSOCKAPI_
#define _WINSOCKAPI_

#include <inaddr.h>

#ifdef USE_WS_PREFIX
typedef unsigned char  WS_u_char;
typedef unsigned short WS_u_short;
typedef unsigned int   WS_u_int;
typedef ULONG          WS_u_long;
#elif (defined(_MSC_VER) || defined(__MINGW32__) || defined(__WATCOMC__)) && !defined(_BSDTYPES_DEFINED)
/* MinGW doesn't define the u_xxx types */
typedef unsigned char  u_char;
typedef unsigned short u_short;
typedef unsigned int   u_int;
typedef ULONG          u_long;
#define _BSDTYPES_DEFINED
#else
#define u_long ULONG  /* make sure we don't use the system u_long */
#endif

#ifdef USE_WS_PREFIX
# define WS(x)    WS_##x
#else
# define WS(x)    x
#endif

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

/*
 * Address families
 */
#ifndef USE_WS_PREFIX
#define AF_UNSPEC                  0
#define AF_UNIX                    1
#define AF_INET                    2
#define AF_IMPLINK                 3
#define AF_PUP                     4
#define AF_CHAOS                   5
#define AF_NS                      6
#define AF_IPX                     AF_NS
#define AF_ISO                     7
#define AF_OSI                     AF_ISO
#define AF_ECMA                    8
#define AF_DATAKIT                 9
#define AF_CCITT                   10
#define AF_SNA                     11
#define AF_DECnet                  12
#define AF_DLI                     13
#define AF_LAT                     14
#define AF_HYLINK                  15
#define AF_APPLETALK               16
#define AF_NETBIOS                 17
#define AF_VOICEVIEW               18
#define AF_FIREFOX                 19
#define AF_UNKNOWN1                20
#define AF_BAN                     21
#define AF_ATM                     22
#define AF_INET6                   23
#define AF_CLUSTER                 24
#define AF_12844                   25
#define AF_IRDA                    26
#define AF_MAX                     27
#define PF_UNSPEC                  AF_UNSPEC
#define PF_UNIX                    AF_UNIX
#define PF_INET                    AF_INET
#define PF_IMPLINK                 AF_IMPLINK
#define PF_PUP                     AF_PUP
#define PF_CHAOS                   AF_CHAOS
#define PF_NS                      AF_NS
#define PF_IPX                     AF_IPX
#define PF_ISO                     AF_ISO
#define PF_OSI                     AF_OSI
#define PF_ECMA                    AF_ECMA
#define PF_DATAKIT                 AF_DATAKIT
#define PF_CCITT                   AF_CCITT
#define PF_SNA                     AF_SNA
#define PF_DECnet                  AF_DECnet
#define PF_DLI                     AF_DLI
#define PF_LAT                     AF_LAT
#define PF_HYLINK                  AF_HYLINK
#define PF_APPLETALK               AF_APPLETALK
#define PF_VOICEVIEW               AF_VOICEVIEW
#define PF_FIREFOX                 AF_FIREFOX
#define PF_UNKNOWN1                AF_UNKNOWN1
#define PF_BAN                     AF_BAN
#define PF_MAX                     AF_MAX
#else /* USE_WS_PREFIX */
#define WS_AF_UNSPEC               0
#define WS_AF_UNIX                 1
#define WS_AF_INET                 2
#define WS_AF_IMPLINK              3
#define WS_AF_PUP                  4
#define WS_AF_CHAOS                5
#define WS_AF_NS                   6
#define WS_AF_IPX                  WS_AF_NS
#define WS_AF_ISO                  7
#define WS_AF_OSI                  AF_ISO
#define WS_AF_ECMA                 8
#define WS_AF_DATAKIT              9
#define WS_AF_CCITT                10
#define WS_AF_SNA                  11
#define WS_AF_DECnet               12
#define WS_AF_DLI                  13
#define WS_AF_LAT                  14
#define WS_AF_HYLINK               15
#define WS_AF_APPLETALK            16
#define WS_AF_NETBIOS              17
#define WS_AF_VOICEVIEW            18
#define WS_AF_FIREFOX              19
#define WS_AF_UNKNOWN1             20
#define WS_AF_BAN                  21
#define WS_AF_ATM                  22
#define WS_AF_INET6                23
#define WS_AF_CLUSTER              24
#define WS_AF_12844                25
#define WS_AF_IRDA                 26
#define WS_AF_MAX                  27
#endif /* USE_WS_PREFIX */

/*
 * Types
 */
#ifndef USE_WS_PREFIX
#define SOCK_STREAM                1
#define SOCK_DGRAM                 2
#define SOCK_RAW                   3
#define SOCK_RDM                   4
#define SOCK_SEQPACKET             5
#else /* USE_WS_PREFIX */
#define WS_SOCK_STREAM             1
#define WS_SOCK_DGRAM              2
#define WS_SOCK_RAW                3
#define WS_SOCK_RDM                4
#define WS_SOCK_SEQPACKET          5
#endif /* USE_WS_PREFIX */


/*
 * Protocols
 */
#ifndef USE_WS_PREFIX
#define IPPROTO_IP                 0
#define IPPROTO_ICMP               1
#define IPPROTO_IGMP               2
#define IPPROTO_GGP                3
#define IPPROTO_TCP                6
#define IPPROTO_UDP                17
#define IPPROTO_IDP                22
#define IPPROTO_IPV6               41
#define IPPROTO_ICMPV6             58
#define IPPROTO_ND                 77
#define IPPROTO_RAW                255
#define IPPROTO_MAX                256
#else /* USE_WS_PREFIX */
#define WS_IPPROTO_IP              0
#define WS_IPPROTO_ICMP            1
#define WS_IPPROTO_IGMP            2
#define WS_IPPROTO_GGP             3
#define WS_IPPROTO_TCP             6
#define WS_IPPROTO_UDP             17
#define WS_IPPROTO_IDP             22
#define WS_IPPROTO_IPV6            41
#define WS_IPPROTO_ICMPV6          58
#define WS_IPPROTO_ND              77
#define WS_IPPROTO_RAW             255
#define WS_IPPROTO_MAX             256
#endif /* USE_WS_PREFIX */

typedef struct WS(protoent)
{
    char* p_name;
    char** p_aliases;
    short p_proto;
} PROTOENT, *PPROTOENT, *LPPROTOENT;



/*
 * Networks
 */
struct WS(netent)
{
    char* n_name;                  /* official name of net */
    char** n_aliases;              /* alias list */
    short n_addrtype;              /* net address type */
    ULONG n_net;                   /* network # */
};


/*
 * Services
 */
#ifndef USE_WS_PREFIX
#define IPPORT_ECHO                7
#define IPPORT_DISCARD             9
#define IPPORT_SYSTAT              11
#define IPPORT_DAYTIME             13
#define IPPORT_NETSTAT             15
#define IPPORT_FTP                 21
#define IPPORT_TELNET              23
#define IPPORT_SMTP                25
#define IPPORT_TIMESERVER          37
#define IPPORT_NAMESERVER          42
#define IPPORT_WHOIS               43
#define IPPORT_MTP                 57
#define IPPORT_TFTP                69
#define IPPORT_RJE                 77
#define IPPORT_FINGER              79
#define IPPORT_TTYLINK             87
#define IPPORT_SUPDUP              95
#define IPPORT_EXECSERVER          512
#define IPPORT_LOGINSERVER         513
#define IPPORT_CMDSERVER           514
#define IPPORT_EFSSERVER           520
#define IPPORT_BIFFUDP             512
#define IPPORT_WHOSERVER           513
#define IPPORT_ROUTESERVER         520
#define IPPORT_RESERVED            1024
#else /* USE_WS_PREFIX */
#define WS_IPPORT_ECHO             7
#define WS_IPPORT_DISCARD          9
#define WS_IPPORT_SYSTAT           11
#define WS_IPPORT_DAYTIME          13
#define WS_IPPORT_NETSTAT          15
#define WS_IPPORT_FTP              21
#define WS_IPPORT_TELNET           23
#define WS_IPPORT_SMTP             25
#define WS_IPPORT_TIMESERVER       37
#define WS_IPPORT_NAMESERVER       42
#define WS_IPPORT_WHOIS            43
#define WS_IPPORT_MTP              57
#define WS_IPPORT_TFTP             69
#define WS_IPPORT_RJE              77
#define WS_IPPORT_FINGER           79
#define WS_IPPORT_TTYLINK          87
#define WS_IPPORT_SUPDUP           95
#define WS_IPPORT_EXECSERVER       512
#define WS_IPPORT_LOGINSERVER      513
#define WS_IPPORT_CMDSERVER        514
#define WS_IPPORT_EFSSERVER        520
#define WS_IPPORT_BIFFUDP          512
#define WS_IPPORT_WHOSERVER        513
#define WS_IPPORT_ROUTESERVER      520
#define WS_IPPORT_RESERVED         1024
#endif /* USE_WS_PREFIX */

typedef struct WS(servent)
{
    char* s_name;                  /* official service name */
    char** s_aliases;              /* alias list */
#ifdef _WIN64
    char* s_proto;                 /* protocol to use */
    short s_port;                  /* port # */
#else
    short s_port;                  /* port # */
    char* s_proto;                 /* protocol to use */
#endif
} SERVENT, *PSERVENT, *LPSERVENT;



/*
 * Hosts
 */

typedef struct WS(hostent)
{
    char* h_name;                  /* official name of host */
    char** h_aliases;              /* alias list */
    short h_addrtype;              /* host address type */
    short h_length;                /* length of address */
    char** h_addr_list;            /* list of addresses from name server */
#define h_addr h_addr_list[0]      /* address, for backward compat */
} HOSTENT, *PHOSTENT, *LPHOSTENT;


/*
 * Sockets
 */

typedef UINT_PTR SOCKET;

/*
 * This is used instead of -1, since the
 * SOCKET type is unsigned.
 */
#define INVALID_SOCKET             (SOCKET)(~0)
#define SOCKET_ERROR               (-1)

typedef struct WS(sockaddr)
{
        WS(u_short) sa_family;
        char        sa_data[14];
} SOCKADDR, *PSOCKADDR, *LPSOCKADDR;

typedef struct WS(linger)
{
    WS(u_short) l_onoff;           /* option on/off */
    WS(u_short) l_linger;          /* linger time */
} LINGER, *PLINGER, *LPLINGER;

/*
 * Select
 */

#ifdef WS_DEFINE_SELECT
/* Define our own version of select and the associated types and macros */

# ifndef USE_WS_PREFIX
#  ifndef FD_SETSIZE
#   define FD_SETSIZE              64
#  endif
# else
#  ifndef WS_FD_SETSIZE
#   define WS_FD_SETSIZE           64
#  endif
# endif

typedef struct WS(fd_set)
{
    WS(u_int) fd_count;            /* how many are SET? */
# ifndef USE_WS_PREFIX
    SOCKET fd_array[FD_SETSIZE];   /* an array of SOCKETs */
# else
    SOCKET fd_array[WS_FD_SETSIZE];/* an array of SOCKETs */
# endif
} WS(fd_set), FD_SET, *PFD_SET, *LPFD_SET;

#ifndef _TIMEVAL_DEFINED
#define _TIMEVAL_DEFINED
typedef struct WS(timeval)
{
    LONG    tv_sec;                /* seconds */
    LONG    tv_usec;               /* and microseconds */
} TIMEVAL, *PTIMEVAL, *LPTIMEVAL;
#endif

#define __WS_FD_CLR(fd, set, cast) do { \
    unsigned int __i; \
    for (__i = 0; __i < ((cast*)(set))->fd_count ; __i++) \
    { \
        if (((cast*)(set))->fd_array[__i] == fd) \
        { \
            while (__i < ((cast*)(set))->fd_count-1) \
            { \
                ((cast*)(set))->fd_array[__i] = \
                    ((cast*)(set))->fd_array[__i+1]; \
                __i++; \
            } \
            ((cast*)(set))->fd_count--; \
            break; \
        } \
    } \
} while(0)
#define __WS_FD_SET1(fd, set, cast) do { \
    if (((cast*)(set))->fd_count < FD_SETSIZE) \
        ((cast*)(set))->fd_array[((cast*)(set))->fd_count++]=(fd); \
} while(0)
/* This version checks if the filedesc is already in the list, and appends it
 * only if it's not the case
 */
#define __WS_FD_SET2(fd, set, cast) do { \
    unsigned int __i; \
    for (__i = 0; __i < ((cast*)(set))->fd_count ; __i++) \
    { \
        if (((cast*)(set))->fd_array[__i]==(fd)) \
            break; \
    } \
    if (__i == ((cast*)(set))->fd_count && ((cast*)(set))->fd_count < FD_SETSIZE) \
    { \
        ((cast*)(set))->fd_count++; \
        ((cast*)(set))->fd_array[__i]=(fd);\
    } \
} while(0)

#ifndef __WINE_WINSOCK2__
#define __WS_FD_SET(fd, set, cast) __WS_FD_SET1((fd),(set), cast)
#else
#define __WS_FD_SET(fd, set, cast) __WS_FD_SET2((fd),(set), cast)
#endif

#ifndef USE_WS_PREFIX
#define FD_CLR(fd, set)      __WS_FD_CLR((fd),(set), fd_set)
#define FD_SET(fd, set)      __WS_FD_SET((fd),(set), fd_set)
#define FD_ZERO(set)         (((fd_set*)(set))->fd_count=0)
#define FD_ISSET(fd, set)    __WSAFDIsSet((SOCKET)(fd), (fd_set*)(set))
#else
#define WS_FD_CLR(fd, set)   __WS_FD_CLR((fd),(set), WS_fd_set)
#define WS_FD_SET(fd, set)   __WS_FD_SET((fd),(set), WS_fd_set)
#define WS_FD_ZERO(set)      (((WS_fd_set*)(set))->fd_count=0)
#define WS_FD_ISSET(fd, set) __WSAFDIsSet((SOCKET)(fd), (WS_fd_set*)(set))
#endif

int WINAPI __WSAFDIsSet(SOCKET,WS(fd_set)*);

#endif /* WS_DEFINE_SELECT */

/* we have to define hton/ntoh as macros to avoid conflicts with Unix headers */
#ifndef USE_WS_PREFIX

#undef htonl
#undef htons
#undef ntohl
#undef ntohs

#ifdef WORDS_BIGENDIAN

static inline u_short __wine_ushort_noop(u_short s)
{
    return s;
}
static inline ULONG __wine_ulong_noop(ULONG l)
{
    return l;
}
#define htonl __wine_ulong_noop
#define htons __wine_ushort_noop
#define ntohl __wine_ulong_noop
#define ntohs __wine_ushort_noop

#else  /* WORDS_BIGENDIAN */

static inline u_short __wine_ushort_swap(u_short s)
{
    return (s >> 8) | (s << 8);
}
static inline ULONG __wine_ulong_swap(ULONG l)
{
    return ((ULONG)__wine_ushort_swap((u_short)l) << 16) | __wine_ushort_swap((u_short)(l >> 16));
}
#define htonl __wine_ulong_swap
#define htons __wine_ushort_swap
#define ntohl __wine_ulong_swap
#define ntohs __wine_ushort_swap

#endif  /* WORDS_BIGENDIAN */

#endif  /* USE_WS_PREFIX */

/*
 * Internet address (old style... should be updated)
 */

#ifndef USE_WS_PREFIX
#define IN_CLASSA_NSHIFT           24
#define IN_CLASSA_MAX              128
#define IN_CLASSA_NET              0xff000000
#define IN_CLASSA_HOST             0x00ffffff
#define IN_CLASSA(i)               (((LONG)(i) & 0x80000000) == 0)
#define IN_CLASSB_NSHIFT           16
#define IN_CLASSB_MAX              65536
#define IN_CLASSB_NET              0xffff0000
#define IN_CLASSB_HOST             0x0000ffff
#define IN_CLASSB(i)               (((LONG)(i) & 0xc0000000) == 0x80000000)
#define IN_CLASSC_NSHIFT           8
#define IN_CLASSC_NET              0xffffff00
#define IN_CLASSC_HOST             0x000000ff
#define IN_CLASSC(i)               (((LONG)(i) & 0xe0000000) == 0xc0000000)
#else
#define WS_IN_CLASSA_NSHIFT        24
#define WS_IN_CLASSA_MAX           128
#define WS_IN_CLASSA_NET           0xff000000
#define WS_IN_CLASSA_HOST          0x00ffffff
#define WS_IN_CLASSA(i)            (((LONG)(i) & 0x80000000) == 0)
#define WS_IN_CLASSB_NSHIFT        16
#define WS_IN_CLASSB_MAX           65536
#define WS_IN_CLASSB_NET           0xffff0000
#define WS_IN_CLASSB_HOST          0x0000ffff
#define WS_IN_CLASSB(i)            (((LONG)(i) & 0xc0000000) == 0x80000000)
#define WS_IN_CLASSC_NSHIFT        8
#define WS_IN_CLASSC_NET           0xffffff00
#define WS_IN_CLASSC_HOST          0x000000ff
#define WS_IN_CLASSC(i)            (((LONG)(i) & 0xe0000000) == 0xc0000000)
#endif /* USE_WS_PREFIX */

#ifndef USE_WS_PREFIX
#define INADDR_ANY                 ((ULONG)0x00000000)
#define INADDR_LOOPBACK            0x7f000001
#define INADDR_BROADCAST           ((ULONG)0xffffffff)
#define INADDR_NONE                0xffffffff
#else
#define WS_INADDR_ANY              ((ULONG)0x00000000)
#define WS_INADDR_LOOPBACK         0x7f000001
#define WS_INADDR_BROADCAST        ((ULONG)0xffffffff)
#define WS_INADDR_NONE             0xffffffff
#endif /* USE_WS_PREFIX */

typedef struct WS(sockaddr_in)
{
    short              sin_family;
    WS(u_short)        sin_port;
    struct WS(in_addr) sin_addr;
    char               sin_zero[8];
} SOCKADDR_IN, *PSOCKADDR_IN, *LPSOCKADDR_IN;

/*
 * Multicast group information
 */

#if !defined(__WINE_WINSOCK2__)
struct WS(ip_mreq)
{
    struct WS(in_addr) imr_multiaddr;
    struct WS(in_addr) imr_interface;
};
#endif

/*
 * WSAStartup
 */
#define WSADESCRIPTION_LEN      256
#define WSASYS_STATUS_LEN       128

typedef struct WS(WSAData)
{
    WORD                    wVersion;
    WORD                    wHighVersion;
#ifdef _WIN64
    WORD                    iMaxSockets;
    WORD                    iMaxUdpDg;
    char                   *lpVendorInfo;
    char                    szDescription[WSADESCRIPTION_LEN+1];
    char                    szSystemStatus[WSASYS_STATUS_LEN+1];
#else
    char                    szDescription[WSADESCRIPTION_LEN+1];
    char                    szSystemStatus[WSASYS_STATUS_LEN+1];
    WORD                    iMaxSockets;
    WORD                    iMaxUdpDg;
    char                   *lpVendorInfo;
#endif
} WSADATA, *LPWSADATA;



/*
 * {get,set}sockopt
 */
#ifndef USE_WS_PREFIX
#define SOL_SOCKET                 0xffff
#define SO_DEBUG                   0x0001
#define SO_ACCEPTCONN              0x0002
#define SO_REUSEADDR               0x0004
#define SO_EXCLUSIVEADDRUSE        ((u_int)(~SO_REUSEADDR))
#define SO_KEEPALIVE               0x0008
#define SO_DONTROUTE               0x0010
#define SO_BROADCAST               0x0020
#define SO_USELOOPBACK             0x0040
#define SO_LINGER                  0x0080
#define SO_OOBINLINE               0x0100
#define SO_DONTLINGER              ((u_int)(~SO_LINGER))
#define SO_SNDBUF                  0x1001
#define SO_RCVBUF                  0x1002
#define SO_SNDLOWAT                0x1003
#define SO_RCVLOWAT                0x1004
#define SO_SNDTIMEO                0x1005
#define SO_RCVTIMEO                0x1006
#define SO_ERROR                   0x1007
#define SO_TYPE                    0x1008
#define SO_BSP_STATE               0x1009


#define IOCPARM_MASK               0x7f
#define IOC_VOID                   0x20000000
#define IOC_OUT                    0x40000000
#define IOC_IN                     0x80000000
#define IOC_INOUT                  (IOC_IN|IOC_OUT)

#define _IO(x,y)    (IOC_VOID|((x)<<8)|(y))
#define _IOR(x,y,t) (IOC_OUT|(((UINT)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))
#define _IOW(x,y,t) (IOC_IN|(((UINT)sizeof(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))

#else

#define WS_SOL_SOCKET              0xffff
#define WS_SO_DEBUG                0x0001
#define WS_SO_ACCEPTCONN           0x0002
#define WS_SO_REUSEADDR            0x0004
#define WS_SO_EXCLUSIVEADDRUSE     ((WS_u_int)(~WS_SO_REUSEADDR))
#define WS_SO_KEEPALIVE            0x0008
#define WS_SO_DONTROUTE            0x0010
#define WS_SO_BROADCAST            0x0020
#define WS_SO_USELOOPBACK          0x0040
#define WS_SO_LINGER               0x0080
#define WS_SO_OOBINLINE            0x0100
#define WS_SO_DONTLINGER           ((WS_u_int)(~WS_SO_LINGER))
#define WS_SO_SNDBUF               0x1001
#define WS_SO_RCVBUF               0x1002
#define WS_SO_SNDLOWAT             0x1003
#define WS_SO_RCVLOWAT             0x1004
#define WS_SO_SNDTIMEO             0x1005
#define WS_SO_RCVTIMEO             0x1006
#define WS_SO_ERROR                0x1007
#define WS_SO_TYPE                 0x1008
#define WS_SO_BSP_STATE            0x1009

#define WS_IOCPARM_MASK            0x7f
#define WS_IOC_VOID                0x20000000
#define WS_IOC_OUT                 0x40000000
#define WS_IOC_IN                  0x80000000
#define WS_IOC_INOUT               (WS_IOC_IN|WS_IOC_OUT)

#define WS__IO(x,y)    (WS_IOC_VOID|((x)<<8)|(y))
#define WS__IOR(x,y,t) (WS_IOC_OUT|(((LONG)sizeof(t)&WS_IOCPARM_MASK)<<16)|((x)<<8)|(y))
#define WS__IOW(x,y,t) (WS_IOC_IN|(((LONG)sizeof(t)&WS_IOCPARM_MASK)<<16)|((x)<<8)|(y))

#endif

/* IPPROTO_TCP options */
#ifndef USE_WS_PREFIX
#define TCP_NODELAY                1
#else
#define WS_TCP_NODELAY             1
#endif

/* IPPROTO_IP options */
#ifndef __WINE_WINSOCK2__    /* WinSock2 has different values for the IP_ constants */
# ifndef USE_WS_PREFIX
#  define IP_OPTIONS             1
#  define IP_MULTICAST_IF        2
#  define IP_MULTICAST_TTL       3
#  define IP_MULTICAST_LOOP      4
#  define IP_ADD_MEMBERSHIP      5
#  define IP_DROP_MEMBERSHIP     6
#  define IP_TTL                 7
#  define IP_TOS                 8
#  define IP_DONTFRAGMENT        9
#  define IP_RECEIVE_BROADCAST   22
# else
#  define WS_IP_OPTIONS           1
#  define WS_IP_MULTICAST_IF      2
#  define WS_IP_MULTICAST_TTL     3
#  define WS_IP_MULTICAST_LOOP    4
#  define WS_IP_ADD_MEMBERSHIP    5
#  define WS_IP_DROP_MEMBERSHIP   6
#  define WS_IP_TTL               7
#  define WS_IP_TOS               8
#  define WS_IP_DONTFRAGMENT      9
#  define WS_IP_RECEIVE_BROADCAST 22
# endif
#endif


/*
 * Socket I/O flags (supported by spec 1.1)
 */
#ifndef USE_WS_PREFIX
#define FIONREAD                   _IOR('f', 127, ULONG)
#define FIONBIO                    _IOW('f', 126, ULONG)
#define FIOASYNC                   _IOW('f', 125, ULONG)
#define SIOCSHIWAT                 _IOW('s',  0, ULONG)
#define SIOCGHIWAT                 _IOR('s',  1, ULONG)
#define SIOCSLOWAT                 _IOW('s',  2, ULONG)
#define SIOCGLOWAT                 _IOR('s',  3, ULONG)
#define SIOCATMARK                 _IOR('s',  7, ULONG)
#else
#define WS_FIONREAD                WS__IOR('f', 127, ULONG)
#define WS_FIONBIO                 WS__IOW('f', 126, ULONG)
#define WS_FIOASYNC                WS__IOW('f', 125, ULONG)
#define WS_SIOCSHIWAT              WS__IOW('s',  0, ULONG)
#define WS_SIOCGHIWAT              WS__IOR('s',  1, ULONG)
#define WS_SIOCSLOWAT              WS__IOW('s',  2, ULONG)
#define WS_SIOCGLOWAT              WS__IOR('s',  3, ULONG)
#define WS_SIOCATMARK              WS__IOR('s',  7, ULONG)
#endif

/*
 * Maximum queue length specifiable by listen.
 */
#ifndef USE_WS_PREFIX
#define SOMAXCONN                  5

#define MSG_OOB                    0x0001
#define MSG_PEEK                   0x0002
#define MSG_DONTROUTE              0x0004
#define MSG_WAITALL                0x0008
#define MSG_INTERRUPT              0x0010
#define MSG_PARTIAL                0x8000
#define MSG_MAXIOVLEN              16
#else /* USE_WS_PREFIX */
#define WS_SOMAXCONN               5

#define WS_MSG_OOB                 0x0001
#define WS_MSG_PEEK                0x0002
#define WS_MSG_DONTROUTE           0x0004
#define WS_MSG_WAITALL             0x0008
#define WS_MSG_INTERRUPT           0x0010
#define WS_MSG_PARTIAL             0x8000
#define WS_MSG_MAXIOVLEN           16
#endif /* USE_WS_PREFIX */

/*
 * Define constant based on rfc883, used by gethostbyxxxx() calls.
 */
#ifndef USE_WS_PREFIX
#define MAXGETHOSTSTRUCT           1024
#else
#define MAXGETHOSTSTRUCT           1024
#endif


/*
 * Define flags to be used with the WSAAsyncSelect() call.
 */
#define FD_READ                    0x00000001
#define FD_WRITE                   0x00000002
#define FD_OOB                     0x00000004
#define FD_ACCEPT                  0x00000008
#define FD_CONNECT                 0x00000010
#define FD_CLOSE                   0x00000020

/* internal per-socket flags */
#ifdef __WINESRC__
#define FD_WINE_LISTENING          0x10000000
#define FD_WINE_NONBLOCKING        0x20000000
#define FD_WINE_CONNECTED          0x40000000
#define FD_WINE_RAW                0x80000000
#define FD_WINE_INTERNAL           0xFFFF0000
#endif

/*
 * All Windows Sockets error constants are biased by WSABASEERR from
 * the "normal". They are also defined in winerror.h.
 */
#define WSABASEERR                 10000
/*
 * Windows Sockets definitions of regular Microsoft C error constants
 */
#define WSAEINTR                   (WSABASEERR+4)
#define WSAEBADF                   (WSABASEERR+9)
#define WSAEACCES                  (WSABASEERR+13)
#define WSAEFAULT                  (WSABASEERR+14)
#define WSAEINVAL                  (WSABASEERR+22)
#define WSAEMFILE                  (WSABASEERR+24)

/*
 * Windows Sockets definitions of regular Berkeley error constants
 */
#define WSAEWOULDBLOCK             (WSABASEERR+35)
#define WSAEINPROGRESS             (WSABASEERR+36)
#define WSAEALREADY                (WSABASEERR+37)
#define WSAENOTSOCK                (WSABASEERR+38)
#define WSAEDESTADDRREQ            (WSABASEERR+39)
#define WSAEMSGSIZE                (WSABASEERR+40)
#define WSAEPROTOTYPE              (WSABASEERR+41)
#define WSAENOPROTOOPT             (WSABASEERR+42)
#define WSAEPROTONOSUPPORT         (WSABASEERR+43)
#define WSAESOCKTNOSUPPORT         (WSABASEERR+44)
#define WSAEOPNOTSUPP              (WSABASEERR+45)
#define WSAEPFNOSUPPORT            (WSABASEERR+46)
#define WSAEAFNOSUPPORT            (WSABASEERR+47)
#define WSAEADDRINUSE              (WSABASEERR+48)
#define WSAEADDRNOTAVAIL           (WSABASEERR+49)
#define WSAENETDOWN                (WSABASEERR+50)
#define WSAENETUNREACH             (WSABASEERR+51)
#define WSAENETRESET               (WSABASEERR+52)
#define WSAECONNABORTED            (WSABASEERR+53)
#define WSAECONNRESET              (WSABASEERR+54)
#define WSAENOBUFS                 (WSABASEERR+55)
#define WSAEISCONN                 (WSABASEERR+56)
#define WSAENOTCONN                (WSABASEERR+57)
#define WSAESHUTDOWN               (WSABASEERR+58)
#define WSAETOOMANYREFS            (WSABASEERR+59)
#define WSAETIMEDOUT               (WSABASEERR+60)
#define WSAECONNREFUSED            (WSABASEERR+61)
#define WSAELOOP                   (WSABASEERR+62)
#define WSAENAMETOOLONG            (WSABASEERR+63)
#define WSAEHOSTDOWN               (WSABASEERR+64)
#define WSAEHOSTUNREACH            (WSABASEERR+65)
#define WSAENOTEMPTY               (WSABASEERR+66)
#define WSAEPROCLIM                (WSABASEERR+67)
#define WSAEUSERS                  (WSABASEERR+68)
#define WSAEDQUOT                  (WSABASEERR+69)
#define WSAESTALE                  (WSABASEERR+70)
#define WSAEREMOTE                 (WSABASEERR+71)

/*
 * Extended Windows Sockets error constant definitions
 */
#define WSASYSNOTREADY             (WSABASEERR+91)
#define WSAVERNOTSUPPORTED         (WSABASEERR+92)
#define WSANOTINITIALISED          (WSABASEERR+93)
#define WSAEDISCON                 (WSABASEERR+101)
#define WSAENOMORE                 (WSABASEERR+102)
#define WSAECANCELLED              (WSABASEERR+103)
#define WSAEINVALIDPROCTABLE       (WSABASEERR+104)
#define WSAEINVALIDPROVIDER        (WSABASEERR+105)
#define WSAEPROVIDERFAILEDINIT     (WSABASEERR+106)
#define WSASYSCALLFAILURE          (WSABASEERR+107)
#define WSASERVICE_NOT_FOUND       (WSABASEERR+108)
#define WSATYPE_NOT_FOUND          (WSABASEERR+109)
#define WSA_E_NO_MORE              (WSABASEERR+110)
#define WSA_E_CANCELLED            (WSABASEERR+111)
#define WSAEREFUSED                (WSABASEERR+112)

/*
 * Error return codes from gethostbyname() and gethostbyaddr()
 * (when using the resolver). Note that these errors are
 * retrieved via WSAGetLastError() and must therefore follow
 * the rules for avoiding clashes with error numbers from
 * specific implementations or language run-time systems.
 * For this reason the codes are based at WSABASEERR+1001.
 * Note also that [WSA]NO_ADDRESS is defined only for
 * compatibility purposes.
 */

#ifndef USE_WS_PREFIX
#define h_errno                    WSAGetLastError()
#else
#define WS_h_errno                 WSAGetLastError()
#endif

/* Authoritative Answer: Host not found */
#define WSAHOST_NOT_FOUND          (WSABASEERR+1001)

/* Non-Authoritative: Host not found, or SERVERFAIL */
#define WSATRY_AGAIN               (WSABASEERR+1002)

/* Non recoverable errors, FORMERR, REFUSED, NOTIMP */
#define WSANO_RECOVERY             (WSABASEERR+1003)

/* Valid name, no data record of requested type */
#define WSANO_DATA                 (WSABASEERR+1004)

/* no address, look for MX record */
#define WSANO_ADDRESS              WSANO_DATA

#ifndef USE_WS_PREFIX
#define HOST_NOT_FOUND             WSAHOST_NOT_FOUND
#define TRY_AGAIN                  WSATRY_AGAIN
#define NO_RECOVERY                WSANO_RECOVERY
#define NO_DATA                    WSANO_DATA
#define NO_ADDRESS                 WSANO_ADDRESS
#endif /* USE_WS_PREFIX */



/*
 * Windows message parameter composition and decomposition
 * macros.
 */

/*
 * WSAMAKEASYNCREPLY is intended for use by the Windows Sockets implementation
 * when constructing the response to a WSAAsyncGetXByY() routine.
 */
#define WSAMAKEASYNCREPLY(buflen,error)     MAKELONG(buflen,error)
/*
 * WSAMAKESELECTREPLY is intended for use by the Windows Sockets implementation
 * when constructing the response to WSAAsyncSelect().
 */
#define WSAMAKESELECTREPLY(event,error)     MAKELONG(event,error)
/*
 * WSAGETASYNCBUFLEN is intended for use by the Windows Sockets application
 * to extract the buffer length from the lParam in the response
 * to a WSAGetXByY().
 */
#define WSAGETASYNCBUFLEN(lParam)           LOWORD(lParam)
/*
 * WSAGETASYNCERROR is intended for use by the Windows Sockets application
 * to extract the error code from the lParam in the response
 * to a WSAGetXByY().
 */
#define WSAGETASYNCERROR(lParam)            HIWORD(lParam)
/*
 * WSAGETSELECTEVENT is intended for use by the Windows Sockets application
 * to extract the event code from the lParam in the response
 * to a WSAAsyncSelect().
 */
#define WSAGETSELECTEVENT(lParam)           LOWORD(lParam)
/*
 * WSAGETSELECTERROR is intended for use by the Windows Sockets application
 * to extract the error code from the lParam in the response
 * to a WSAAsyncSelect().
 */
#define WSAGETSELECTERROR(lParam)           HIWORD(lParam)



/*
 * Prototypes
 *
 * Remember to keep this section in sync with the
 * "Winsock Function Typedefs" section in winsock2.h.
 */
#if !defined(__WINE_WINSOCK2__) || WS_API_PROTOTYPES
HANDLE WINAPI WSAAsyncGetHostByAddr(HWND,WS(u_int),const char*,int,int,char*,int);
HANDLE WINAPI WSAAsyncGetHostByName(HWND,WS(u_int),const char*,char*,int);
HANDLE WINAPI WSAAsyncGetProtoByName(HWND,WS(u_int),const char*,char*,int);
HANDLE WINAPI WSAAsyncGetProtoByNumber(HWND,WS(u_int),int,char*,int);
HANDLE WINAPI WSAAsyncGetServByName(HWND,WS(u_int),const char*,const char*,char*,int);
HANDLE WINAPI WSAAsyncGetServByPort(HWND,WS(u_int),int,const char*,char*,int);
int WINAPI WSAAsyncSelect(SOCKET,HWND,WS(u_int),LONG);
int WINAPI WSACancelAsyncRequest(HANDLE);
int WINAPI WSACancelBlockingCall(void);
int WINAPI WSACleanup(void);
int WINAPI WSAGetLastError(void);
BOOL WINAPI WSAIsBlocking(void);
FARPROC WINAPI WSASetBlockingHook(FARPROC);
void WINAPI WSASetLastError(int);
int WINAPI WSAStartup(WORD,LPWSADATA);
int WINAPI WSAUnhookBlockingHook(void);

SOCKET WINAPI WS(accept)(SOCKET,struct WS(sockaddr)*,int*);
int WINAPI WS(bind)(SOCKET,const struct WS(sockaddr)*,int);
int WINAPI WS(closesocket)(SOCKET);
int WINAPI WS(connect)(SOCKET,const struct WS(sockaddr)*,int);
struct WS(hostent)* WINAPI WS(gethostbyaddr)(const char*,int,int);
struct WS(hostent)* WINAPI WS(gethostbyname)(const char*);
int WINAPI WS(getpeername)(SOCKET,struct WS(sockaddr)*,int*);
struct WS(protoent)* WINAPI WS(getprotobyname)(const char*);
struct WS(protoent)* WINAPI WS(getprotobynumber)(int);
#ifdef WS_DEFINE_SELECT
int WINAPI WS(select)(int,WS(fd_set)*,WS(fd_set)*,WS(fd_set)*,const struct WS(timeval)*);
#endif
struct WS(servent)* WINAPI WS(getservbyname)(const char*,const char*);
struct WS(servent)* WINAPI WS(getservbyport)(int,const char*);
int WINAPI WS(getsockname)(SOCKET,struct WS(sockaddr)*,int*);
int WINAPI WS(getsockopt)(SOCKET,int,int,char*,int*);
ULONG WINAPI WS(inet_addr)(const char*);
char* WINAPI WS(inet_ntoa)(struct WS(in_addr));
int WINAPI WS(ioctlsocket)(SOCKET,LONG,ULONG*);
int WINAPI WS(listen)(SOCKET,int);
int WINAPI WS(recv)(SOCKET,char*,int,int);
int WINAPI WS(recvfrom)(SOCKET,char*,int,int,struct WS(sockaddr)*,int*);
int WINAPI WS(send)(SOCKET,const char*,int,int);
int WINAPI WS(sendto)(SOCKET,const char*,int,int,const struct WS(sockaddr)*,int);
int WINAPI WS(setsockopt)(SOCKET,int,int,const char*,int);
int WINAPI WS(shutdown)(SOCKET,int);
SOCKET WINAPI WS(socket)(int,int,int);

#if defined(__MINGW32__) || defined (_MSC_VER)
/* gethostname is not defined on Unix because of conflicts with unistd.h */
int WINAPI WS(gethostname)(char*,int);
#endif

#endif /* !defined(__WINE_WINSOCK2__) || WS_API_PROTOTYPES */

#ifdef __cplusplus
}
#endif

#ifndef __WINE_WINSOCK2__
#undef WS
#undef WS_API_PROTOTYPES
#undef WS_API_TYPEDEFS
#endif

#endif  /* _WINSOCKAPI_ */
