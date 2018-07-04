/* Definitions for the Windows Event Log (wevtapi.dll)
 *
 * Copyright 2012 André Hentschel
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

#ifndef __WINE_WINEVT_H
#define __WINE_WINEVT_H

#include <wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

typedef HANDLE EVT_HANDLE, *PEVT_HANDLE;

typedef enum _EVT_CHANNEL_CONFIG_PROPERTY_ID {
    EvtChannelConfigEnabled = 0,
    EvtChannelConfigIsolation,
    EvtChannelConfigType,
    EvtChannelConfigOwningPublisher,
    EvtChannelConfigClassicEventlog,
    EvtChannelConfigAccess,
    EvtChannelLoggingConfigRetention,
    EvtChannelLoggingConfigAutoBackup,
    EvtChannelLoggingConfigMaxSize,
    EvtChannelLoggingConfigLogFilePath,
    EvtChannelPublishingConfigLevel,
    EvtChannelPublishingConfigKeywords,
    EvtChannelPublishingConfigControlGuid,
    EvtChannelPublishingConfigBufferSize,
    EvtChannelPublishingConfigMinBuffers,
    EvtChannelPublishingConfigMaxBuffers,
    EvtChannelPublishingConfigLatency,
    EvtChannelPublishingConfigClockType,
    EvtChannelPublishingConfigSidType,
    EvtChannelPublisherList,
    EvtChannelPublishingConfigFileMax,
    EvtChannelConfigPropertyIdEND
} EVT_CHANNEL_CONFIG_PROPERTY_ID;

typedef enum _EVT_SUBSCRIBE_NOTIFY_ACTION {
    EvtSubscribeActionError = 0,
    EvtSubscribeActionDeliver
} EVT_SUBSCRIBE_NOTIFY_ACTION;

typedef struct _EVT_VARIANT {
    union {
        BOOL        BooleanVal;
        INT8        SByteVal;
        INT16       Int16Val;
        INT32       Int32Val;
        INT64       Int64Val;
        UINT8       ByteVal;
        UINT16      UInt16Val;
        UINT32      UInt32Val;
        UINT64      UInt64Val;
        FLOAT       SingleVal;
        DOUBLE      DoubleVal;
        ULONGLONG   FileTimeVal;
        SYSTEMTIME* SysTimeVal;
        GUID*       GuidVal;
        LPCWSTR     StringVal;
        LPCSTR      AnsiStringVal;
        PBYTE       BinaryVal;
        PSID        SidVal;
        SIZE_T      SizeTVal;

        BOOL*       BooleanArr;
        INT8*       SByteArr;
        INT16*      Int16Arr;
        INT32*      Int32Arr;
        INT64*      Int64Arr;
        UINT8*      ByteArr;
        UINT16*     UInt16Arr;
        UINT32*     UInt32Arr;
        UINT64*     UInt64Arr;
        FLOAT*      SingleArr;
        DOUBLE*     DoubleArr;
        FILETIME*   FileTimeArr;
        SYSTEMTIME* SysTimeArr;
        GUID*       GuidArr;
        LPWSTR*     StringArr;
        LPSTR*      AnsiStringArr;
        PSID*       SidArr;
        SIZE_T*     SizeTArr;

        EVT_HANDLE  EvtHandleVal;
        LPCWSTR     XmlVal;
        LPCWSTR*    XmlValArr;
    } DUMMYUNIONNAME;

    DWORD Count;
    DWORD Type;
} EVT_VARIANT, *PEVT_VARIANT;

typedef DWORD (WINAPI *EVT_SUBSCRIBE_CALLBACK)(EVT_SUBSCRIBE_NOTIFY_ACTION Action,
                                               PVOID UserContext, EVT_HANDLE Event);

BOOL WINAPI EvtGetChannelConfigProperty(EVT_HANDLE ChannelConfig,
                                        EVT_CHANNEL_CONFIG_PROPERTY_ID PropertyId,
                                        DWORD Flags, DWORD PropertyValueBufferSize,
                                        PEVT_VARIANT PropertyValueBuffer,
                                        PDWORD PropertyValueBufferUsed);
BOOL WINAPI EvtSetChannelConfigProperty(EVT_HANDLE ChannelConfig,
                                        EVT_CHANNEL_CONFIG_PROPERTY_ID PropertyId,
                                        DWORD Flags, PEVT_VARIANT PropertyValue);
EVT_HANDLE WINAPI EvtSubscribe(EVT_HANDLE Session, HANDLE SignalEvent, LPCWSTR ChannelPath,
                               LPCWSTR Query, EVT_HANDLE Bookmark, PVOID context,
                               EVT_SUBSCRIBE_CALLBACK Callback, DWORD Flags);
EVT_HANDLE WINAPI EvtOpenChannelConfig(EVT_HANDLE Session, LPCWSTR ChannelPath, DWORD Flags);


#ifdef __cplusplus
} /* extern "C" */
#endif /* defined(__cplusplus) */

#endif /* __WINE_WINEVT_H */
