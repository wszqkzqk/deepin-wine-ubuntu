/*
 * Copyright 2003 Geoff Thorpe
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

#ifndef __WINE_LMSTATS_H
#define __WINE_LMSTATS_H

#include <lmcons.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _STAT_WORKSTATION_0 {
    LARGE_INTEGER StatisticsStartTime;
    LARGE_INTEGER BytesReceived;
    LARGE_INTEGER SmbsReceived;
    LARGE_INTEGER PagingReadBytesRequested;
    LARGE_INTEGER NonPagingReadBytesRequested;
    LARGE_INTEGER CacheReadBytesRequested;
    LARGE_INTEGER NetworkReadBytesRequested;
    LARGE_INTEGER BytesTransmitted;
    LARGE_INTEGER SmbsTransmitted;
    LARGE_INTEGER PagingWriteBytesRequested;
    LARGE_INTEGER NonPagingWriteBytesRequested;
    LARGE_INTEGER CacheWriteBytesRequested;
    LARGE_INTEGER NetworkWriteBytesRequested;
    DWORD InitiallyFailedOperations;
    DWORD FailedCompletionOperations;
    DWORD ReadOperations;
    DWORD RandomReadOperations;
    DWORD ReadSmbs;
    DWORD LargeReadSmbs;
    DWORD SmallReadSmbs;
    DWORD WriteOperations;
    DWORD RandomWriteOperations;
    DWORD WriteSmbs;
    DWORD LargeWriteSmbs;
    DWORD SmallWriteSmbs;
    DWORD RawReadsDenied;
    DWORD RawWritesDenied;
    DWORD NetworkErrors;
    DWORD Sessions;
    DWORD FailedSessions;
    DWORD Reconnects;
    DWORD CoreConnects;
    DWORD Lanman20Connects;
    DWORD Lanman21Connects;
    DWORD LanmanNtConnects;
    DWORD ServerDisconnects;
    DWORD HungSessions;
    DWORD UseCount;
    DWORD FailedUseCount;
    DWORD CurrentCommands;
} STAT_WORKSTATION_0, *PSTAT_WORKSTATION_0, *LPSTAT_WORKSTATION_0;

typedef struct _STAT_SERVER_0 {
    DWORD sts0_start;
    DWORD sts0_fopens;
    DWORD sts0_devopens;
    DWORD sts0_jobsqueued;
    DWORD sts0_sopens;
    DWORD sts0_stimedout;
    DWORD sts0_serrorout;
    DWORD sts0_pwerrors;
    DWORD sts0_permerrors;
    DWORD sts0_syserrors;
    DWORD sts0_bytessent_low;
    DWORD sts0_bytessent_high;
    DWORD sts0_bytesrcvd_low;
    DWORD sts0_bytesrcvd_high;
    DWORD sts0_avresponse;
    DWORD sts0_reqbufneed;
    DWORD sts0_bigbufneed;
} STAT_SERVER_0, *PSTAT_SERVER_0, *LPSTAT_SERVER_0;

NET_API_STATUS WINAPI NetStatisticsGet(LPWSTR server, LPWSTR service, DWORD level,
                                       DWORD options, LPBYTE *bufptr);

#ifdef __cplusplus
}
#endif

#endif
