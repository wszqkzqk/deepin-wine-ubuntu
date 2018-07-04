/*
 * Copyright (C) 2005 Mike McCormack
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

#ifndef _EVNTRACE_
#define _EVNTRACE_

#include <guiddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define EVENT_TRACE_CONTROL_QUERY     0
#define EVENT_TRACE_CONTROL_STOP      1
#define EVENT_TRACE_CONTROL_UPDATE    2
#define EVENT_TRACE_CONTROL_FLUSH     3

#define TRACE_LEVEL_NONE              0
#define TRACE_LEVEL_CRITICAL          1
#define TRACE_LEVEL_FATAL             1
#define TRACE_LEVEL_ERROR             2
#define TRACE_LEVEL_WARNING           3
#define TRACE_LEVEL_INFORMATION       4
#define TRACE_LEVEL_VERBOSE           5

#define EVENT_TRACE_FILE_MODE_NONE             0x00000000
#define EVENT_TRACE_FILE_MODE_SEQUENTIAL       0x00000001
#define EVENT_TRACE_FILE_MODE_CIRCULAR         0x00000002
#define EVENT_TRACE_FILE_MODE_APPEND           0x00000004
#define EVENT_TRACE_FILE_MODE_NEWFILE          0x00000008
#define EVENT_TRACE_FILE_MODE_PREALLOCATE      0x00000020
#define EVENT_TRACE_NONSTOPPABLE_MODE          0x00000040
#define EVENT_TRACE_SECURE_MODE                0x00000080
#define EVENT_TRACE_REAL_TIME_MODE             0x00000100
#define EVENT_TRACE_DELAY_OPEN_FILE_MODE       0x00000200
#define EVENT_TRACE_BUFFERING_MODE             0x00000400
#define EVENT_TRACE_PRIVATE_LOGGER_MODE        0x00000800
#define EVENT_TRACE_ADD_HEADER_MODE            0x00001000
#define EVENT_TRACE_USE_KBYTES_FOR_SIZE        0x00002000
#define EVENT_TRACE_USE_GLOBAL_SEQUENCE        0x00004000
#define EVENT_TRACE_USE_LOCAL_SEQUENCE         0x00008000
#define EVENT_TRACE_RELOG_MODE                 0x00010000
#define EVENT_TRACE_PRIVATE_IN_PROC            0x00020000
#define EVENT_TRACE_MODE_RESERVED              0x00100000
#define EVENT_TRACE_STOP_ON_HYBRID_SHUTDOWN    0x00400000
#define EVENT_TRACE_PERSIST_ON_HYBRID_SHUTDOWN 0x00800000
#define EVENT_TRACE_USE_PAGED_MEMORY           0x01000000
#define EVENT_TRACE_SYSTEM_LOGGER_MODE         0x02000000
#define EVENT_TRACE_INDEPENDENT_SESSION_MODE   0x08000000
#define EVENT_TRACE_NO_PER_PROCESSOR_BUFFERING 0x10000000
#define EVENT_TRACE_ADDTO_TRIAGE_DUMP          0x80000000

DEFINE_GUID (SystemTraceControlGuid, 0x9e814aad, 0x3204, 0x11d2, 0x9a, 0x82, 0x00, 0x60, 0x08, 0xa8, 0x69, 0x39);

typedef ULONG64 TRACEHANDLE, *PTRACEHANDLE;

struct _EVENT_TRACE_LOGFILEA;
struct _EVENT_TRACE_LOGFILEW;

typedef struct _EVENT_TRACE_LOGFILEA EVENT_TRACE_LOGFILEA, *PEVENT_TRACE_LOGFILEA;
typedef struct _EVENT_TRACE_LOGFILEW EVENT_TRACE_LOGFILEW, *PEVENT_TRACE_LOGFILEW;

typedef ULONG (WINAPI * PEVENT_TRACE_BUFFER_CALLBACKA)( PEVENT_TRACE_LOGFILEA );
typedef ULONG (WINAPI * PEVENT_TRACE_BUFFER_CALLBACKW)( PEVENT_TRACE_LOGFILEW );

typedef ULONG (WINAPI * WMIDPREQUEST)( WMIDPREQUESTCODE, PVOID, ULONG*, PVOID );

typedef struct _TRACE_GUID_REGISTRATION
{
    LPCGUID Guid;
    HANDLE RegHandle;
} TRACE_GUID_REGISTRATION, *PTRACE_GUID_REGISTRATION;

typedef struct _TRACE_GUID_PROPERTIES {
    GUID    Guid;
    ULONG   GuidType;
    ULONG   LoggerId;
    ULONG   EnableLevel;
    ULONG   EnableFlags;
    BOOLEAN IsEnable;
} TRACE_GUID_PROPERTIES, *PTRACE_GUID_PROPERTIES;

typedef struct _EVENT_TRACE_HEADER
{
    USHORT Size;
    union
    {
        USHORT FieldTypeFlags;
        struct
        {
            UCHAR HeaderType;
            UCHAR MarkerFlags;
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;
    union
    {
        ULONG Version;
        struct
        {
            UCHAR Type;
            UCHAR Level;
            USHORT Version;
        } Class;
    } DUMMYUNIONNAME1;
    ULONG ThreadId;
    ULONG ProcessId;
    LARGE_INTEGER TimeStamp;
    union
    {
        GUID Guid;
        ULONGLONG GuidPtr;
    } DUMMYUNIONNAME2;
    union
    {
        struct
        {
            ULONG ClientContext;
            ULONG Flags;
        } DUMMYSTRUCTNAME1;
        struct
        {
            ULONG KernelTime;
            ULONG UserTime;
        } DUMMYSTRUCTNAME2;
    } DUMMYUNIONNAME3;
} EVENT_TRACE_HEADER, *PEVENT_TRACE_HEADER;

typedef struct _EVENT_TRACE
{
    EVENT_TRACE_HEADER Header;
    ULONG InstanceId;
    ULONG ParentInstanceId;
    GUID ParentGuid;
    PVOID MofData;
    ULONG MofLength;
    ULONG ClientContext;
} EVENT_TRACE, *PEVENT_TRACE;

typedef VOID (WINAPI * PEVENT_CALLBACK)( PEVENT_TRACE );

typedef struct _TRACE_LOGFILE_HEADER
{
    ULONG BufferSize;
    union
    {
        ULONG Version;
        struct 
        {
            UCHAR MajorVersion;
            UCHAR MinorVersion;
            UCHAR SubVersion;
            UCHAR SubMinorVersion;
        } VersionDetail;
    } DUMMYUNIONNAME;
    ULONG ProviderVersion;
    ULONG NumberOfProcessors;
    LARGE_INTEGER EndTime;
    ULONG TimerResolution;
    ULONG MaximumFileSize;
    ULONG LogFileMode;
    ULONG BuffersWritten;
    union
    {
        GUID LogInstanceGuid;
        struct
        {
            ULONG StartBuffers;
            ULONG PointerSize;
            ULONG EventsLost;
            ULONG CpuSpeedInMHZ;
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME1;
    LPWSTR LoggerName;
    LPWSTR LogFileName;
    TIME_ZONE_INFORMATION TimeZone;
    LARGE_INTEGER BootTime;
    LARGE_INTEGER PerfFreq;
    LARGE_INTEGER StartTime;
    ULONG ReservedTime;
    ULONG BuffersLost;
} TRACE_LOGFILE_HEADER, *PTRACE_LOGFILE_HEADER;

struct _EVENT_TRACE_LOGFILEW
{
    LPWSTR LogFileName;
    LPWSTR LoggerName;
    LONGLONG CurrentTime;
    ULONG LogFileMode;
    EVENT_TRACE CurrentEvent;
    TRACE_LOGFILE_HEADER LogfileHeader;
    PEVENT_TRACE_BUFFER_CALLBACKW BufferCallback;
    ULONG BufferSize;
    ULONG Filled;
    ULONG EventsLost;
    PEVENT_CALLBACK EventCallback;
    PVOID Context;
};

struct _EVENT_TRACE_LOGFILEA
{
    LPSTR LogFileName;
    LPSTR LoggerName;
    LONGLONG CurrentTime;
    ULONG LogFileMode;
    EVENT_TRACE CurrentEvent;
    TRACE_LOGFILE_HEADER LogfileHeader;
    PEVENT_TRACE_BUFFER_CALLBACKA BufferCallback;
    ULONG BufferSize;
    ULONG Filled;
    ULONG EventsLost;
    PEVENT_CALLBACK EventCallback;
    PVOID Context;
};

typedef struct _EVENT_TRACE_PROPERTIES
{
    WNODE_HEADER Wnode;
    ULONG BufferSize;
    ULONG MinimumBuffers;
    ULONG MaximumBuffers;
    ULONG MaximumFileSize;
    ULONG LogFileMode;
    ULONG FlushTimer;
    ULONG EnableFlags;
    LONG AgeLimit;
    ULONG NumberOfBuffers;
    ULONG FreeBuffers;
    ULONG EventsLost;
    ULONG BuffersWritten;
    ULONG LogBuffersLost;
    ULONG RealTimeBuffersLost;
    HANDLE LoggerThreadId;
    ULONG LogFileNameOffset;
    ULONG LoggerNameOffset;
} EVENT_TRACE_PROPERTIES, *PEVENT_TRACE_PROPERTIES;

typedef struct _ENABLE_TRACE_PARAMETERS
{
    ULONG                            Version;
    ULONG                            EnableProperty;
    ULONG                            ControlFlags;
    GUID                             SourceId;
    struct _EVENT_FILTER_DESCRIPTOR *EnableFilterDesc;
    ULONG                            FilterDescCount;
} ENABLE_TRACE_PARAMETERS, *PENABLE_TRACE_PARAMETERS;

#define INVALID_PROCESSTRACE_HANDLE ((TRACEHANDLE)~(ULONG_PTR)0)

ULONG WINAPI CloseTrace(TRACEHANDLE);
ULONG WINAPI ControlTraceA(TRACEHANDLE,LPCSTR,PEVENT_TRACE_PROPERTIES,ULONG);
ULONG WINAPI ControlTraceW(TRACEHANDLE,LPCWSTR,PEVENT_TRACE_PROPERTIES,ULONG);
#define      ControlTrace WINELIB_NAME_AW(ControlTrace)
ULONG WINAPI EnableTrace(ULONG,ULONG,ULONG,LPCGUID,TRACEHANDLE);
ULONG WINAPI EnableTraceEx2(TRACEHANDLE,LPCGUID,ULONG,UCHAR,ULONGLONG,ULONGLONG,ULONG,PENABLE_TRACE_PARAMETERS);
ULONG WINAPI FlushTraceA(TRACEHANDLE,LPCSTR,PEVENT_TRACE_PROPERTIES);
ULONG WINAPI FlushTraceW(TRACEHANDLE,LPCWSTR,PEVENT_TRACE_PROPERTIES);
#define      FlushTrace WINELIB_NAME_AW(FlushTrace)
ULONG WINAPI GetTraceEnableFlags(TRACEHANDLE);
UCHAR WINAPI GetTraceEnableLevel(TRACEHANDLE);
TRACEHANDLE WINAPI GetTraceLoggerHandle(PVOID);
ULONG WINAPI QueryAllTracesA(PEVENT_TRACE_PROPERTIES*,ULONG,PULONG);
ULONG WINAPI QueryAllTracesW(PEVENT_TRACE_PROPERTIES*,ULONG,PULONG);
#define      QueryAllTraces WINELIB_NAME_AW(QueryAllTraces)
ULONG WINAPI RegisterTraceGuidsA(WMIDPREQUEST,PVOID,LPCGUID,ULONG,PTRACE_GUID_REGISTRATION,LPCSTR,LPCSTR,PTRACEHANDLE);
ULONG WINAPI RegisterTraceGuidsW(WMIDPREQUEST,PVOID,LPCGUID,ULONG,PTRACE_GUID_REGISTRATION,LPCWSTR,LPCWSTR,PTRACEHANDLE);
#define      RegisterTraceGuids WINELIB_NAME_AW(RegisterTraceGuids)
ULONG WINAPI StartTraceA(PTRACEHANDLE,LPCSTR,PEVENT_TRACE_PROPERTIES);
ULONG WINAPI StartTraceW(PTRACEHANDLE,LPCWSTR,PEVENT_TRACE_PROPERTIES);
#define      StartTrace WINELIB_NAME_AW(StartTrace)
ULONG WINAPI TraceEvent(TRACEHANDLE,PEVENT_TRACE_HEADER);
ULONG WINAPIV TraceMessage(TRACEHANDLE,ULONG,LPGUID,USHORT,...);
ULONG WINAPI TraceMessageVa(TRACEHANDLE,ULONG,LPGUID,USHORT,__ms_va_list);
ULONG WINAPI UnregisterTraceGuids(TRACEHANDLE);

#ifdef __cplusplus
}
#endif

#endif /* _EVNTRACE_ */
