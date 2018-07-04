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

#ifndef _WMISTR_
#define _WMISTR_

#define WNODE_FLAG_ALL_DATA              0x00000001
#define WNODE_FLAG_SINGLE_INSTANCE       0x00000002
#define WNODE_FLAG_SINGLE_ITEM           0x00000004
#define WNODE_FLAG_EVENT_ITEM            0x00000008
#define WNODE_FLAG_FIXED_INSTANCE_SIZE   0x00000010
#define WNODE_FLAG_TOO_SMALL             0x00000020
#define WNODE_FLAG_INSTANCES_SAME        0x00000040
#define WNODE_FLAG_STATIC_INSTANCE_NAMES 0x00000080
#define WNODE_FLAG_USE_TIMESTAMP         0x00000200
#define WNODE_FLAG_EVENT_REFERENCE       0x00002000
#define WNODE_FLAG_METHOD_ITEM           0x00008000
#define WNODE_FLAG_PDO_INSTANCE_NAMES    0x00010000
#define WNODE_FLAG_TRACED_GUID           0x00020000
#define WNODE_FLAG_LOG_WNODE             0x00040000
#define WNODE_FLAG_USE_GUID_PTR          0x00080000
#define WNODE_FLAG_USE_MOF_PTR           0x00100000
#define WNODE_FLAG_SEVERITY_MASK         0xFF000000

typedef enum
{
    WMI_GET_ALL_DATA = 0,
    WMI_GET_SINGLE_INSTANCE = 1,
    WMI_SET_SINGLE_INSTANCE = 2,
    WMI_SET_SINGLE_ITEM = 3,
    WMI_ENABLE_EVENTS = 4,
    WMI_DISABLE_EVENTS = 5,
    WMI_ENABLE_CONNECTION = 6,
    WMI_DISABLE_CONNECTION = 7,
    WMI_REGINFO = 8,
    WMI_EXECUTE_METHOD = 9,
} WMIDPREQUESTCODE;

typedef struct _WNODE_HEADER
{
    ULONG BufferSize;
    ULONG ProvicerId;
    union
    {
        ULONG64 HistoricalContext;
        struct
        {
            ULONG Version;
            ULONG Linkage;
        } DUMMYSTRUCTNAME;

    } DUMMYUNIONNAME;
    union
    {
        HANDLE KernelHandle;
        LARGE_INTEGER TimeStamp;
    } DUMMYUNIONNAME2;
    GUID Guid;
    ULONG ClientContext;
    ULONG Flags;
} WNODE_HEADER, *PWNODE_HEADER;

#endif /* _WMISTR_ */
