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

#ifndef _WS2DEF_
#define _WS2DEF_

#include <inaddr.h>

#ifdef USE_WS_PREFIX
#define WS(x)    WS_##x
#else
#define WS(x)    x
#endif

typedef USHORT ADDRESS_FAMILY;

#ifndef __CSADDR_DEFINED__
#define __CSADDR_DEFINED__

typedef struct _SOCKET_ADDRESS {
        LPSOCKADDR      lpSockaddr;
        INT             iSockaddrLength;
} SOCKET_ADDRESS, *PSOCKET_ADDRESS, *LPSOCKET_ADDRESS;

typedef struct _CSADDR_INFO {
        SOCKET_ADDRESS  LocalAddr;
        SOCKET_ADDRESS  RemoteAddr;
        INT             iSocketType;
        INT             iProtocol;
} CSADDR_INFO, *PCSADDR_INFO, *LPCSADDR_INFO;
#endif

#ifdef USE_WS_PREFIX
#define WS__SS_MAXSIZE 128
#define WS__SS_ALIGNSIZE (sizeof(__int64))
#define WS__SS_PAD1SIZE (WS__SS_ALIGNSIZE - sizeof(short))
#define WS__SS_PAD2SIZE (WS__SS_MAXSIZE - 2 * WS__SS_ALIGNSIZE)
#else
#define _SS_MAXSIZE 128
#define _SS_ALIGNSIZE (sizeof(__int64))
#define _SS_PAD1SIZE (_SS_ALIGNSIZE - sizeof(short))
#define _SS_PAD2SIZE (_SS_MAXSIZE - 2 * _SS_ALIGNSIZE)
#endif

typedef struct WS(sockaddr_storage) {
        short ss_family;
        char __ss_pad1[WS(_SS_PAD1SIZE)];
        __int64 DECLSPEC_ALIGN(8) __ss_align;
        char __ss_pad2[WS(_SS_PAD2SIZE)];
} SOCKADDR_STORAGE, *PSOCKADDR_STORAGE, *LPSOCKADDR_STORAGE;

/*socket address list */
typedef struct _SOCKET_ADDRESS_LIST {
        INT             iAddressCount;
        SOCKET_ADDRESS  Address[1];
} SOCKET_ADDRESS_LIST, *LPSOCKET_ADDRESS_LIST;

typedef enum {
    ScopeLevelInterface    = 1,
    ScopeLevelLink         = 2,
    ScopeLevelSubnet       = 3,
    ScopeLevelAdmin        = 4,
    ScopeLevelSite         = 5,
    ScopeLevelOrganization = 8,
    ScopeLevelGlobal       = 14,
    ScopeLevelCount        = 16,
} SCOPE_LEVEL;

typedef struct
{
    union {
        struct {
            ULONG Zone  : 28;
            ULONG Level : 4;
        } DUMMYSTRUCTNAME;
        ULONG Value;
    } DUMMYUNIONNAME;
} SCOPE_ID, *PSCOPE_ID;

typedef struct _WSABUF
{
    ULONG len;
    CHAR* buf;
} WSABUF, *LPWSABUF;

typedef struct _WSAMSG {
    LPSOCKADDR  name;
    INT         namelen;
    LPWSABUF    lpBuffers;
    DWORD       dwBufferCount;
    WSABUF      Control;
    DWORD       dwFlags;
} WSAMSG, *PWSAMSG, *LPWSAMSG;

/*
 * Macros for retrieving control message data returned by WSARecvMsg()
 */
#define WSA_CMSG_DATA(cmsg)     ((UCHAR*)((WSACMSGHDR*)(cmsg)+1))
#define WSA_CMSG_FIRSTHDR(mhdr) ((mhdr)->Control.len >= sizeof(WSACMSGHDR) ? (WSACMSGHDR *) (mhdr)->Control.buf : (WSACMSGHDR *) 0)
#define WSA_CMSG_ALIGN(len)     (((len) + sizeof(SIZE_T) - 1) & ~(sizeof(SIZE_T) - 1))
/*
 * Next Header: If the response is too short (or the next message in the response
 * is too short) then return NULL, otherwise return the next control message.
 */
#define WSA_CMSG_NXTHDR(mhdr,cmsg) \
        (!(cmsg) ? WSA_CMSG_FIRSTHDR(mhdr) : \
         ((mhdr)->Control.len < sizeof(WSACMSGHDR) ? NULL : \
         (((unsigned char*)(((WSACMSGHDR*)((unsigned char*)cmsg + WSA_CMSG_ALIGN(cmsg->cmsg_len)))+1) > ((unsigned char*)(mhdr)->Control.buf + (mhdr)->Control.len)) ? NULL : \
          (((unsigned char*)cmsg + WSA_CMSG_ALIGN(cmsg->cmsg_len)+WSA_CMSG_ALIGN(((WSACMSGHDR*)((unsigned char*)cmsg + WSA_CMSG_ALIGN(cmsg->cmsg_len)))->cmsg_len) > ((unsigned char*)(mhdr)->Control.buf + (mhdr)->Control.len)) ? NULL : \
           (WSACMSGHDR*)((unsigned char*)cmsg + WSA_CMSG_ALIGN(cmsg->cmsg_len))))))

typedef struct addrinfoexA {
    int ai_flags;
    int ai_family;
    int ai_socktype;
    int ai_protocol;
    SIZE_T ai_addrlen;
    char *ai_canonname;
    struct WS(sockaddr) *ai_addr;
    void *ai_blob;
    SIZE_T ai_bloblen;
    GUID *ai_provider;
    struct addrinfoexA *ai_next;
} ADDRINFOEXA, *PADDRINFOEXA, *LPADDRINFOEXA;

typedef struct addrinfoexW {
    int ai_flags;
    int ai_family;
    int ai_socktype;
    int ai_protocol;
    SIZE_T ai_addrlen;
    WCHAR *ai_canonname;
    struct WS(sockaddr) *ai_addr;
    void *ai_blob;
    SIZE_T ai_bloblen;
    GUID *ai_provider;
    struct addrinfoexW *ai_next;
} ADDRINFOEXW, *PADDRINFOEXW, *LPADDRINFOEXW;

#endif /* _WS2DEF_ */
