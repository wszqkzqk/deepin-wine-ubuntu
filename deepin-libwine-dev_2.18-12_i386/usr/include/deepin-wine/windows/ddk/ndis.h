/*
 * ndis.h
 *
 * Copyright 2015 Austin English
 * Copyright 2016 André Hentschel
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
#ifndef _NDIS_
#define _NDIS_

typedef ULONG NDIS_AF, *PNDIS_AF;
typedef MDL   NDIS_BUFFER, *PNDIS_BUFFER;
typedef void *NDIS_HANDLE, *PNDIS_HANDLE, *PNDIS_PACKET_POOL;
typedef ULONG NDIS_OID, *PNDIS_OID;
typedef int   NDIS_STATUS, *PNDIS_STATUS;
typedef UNICODE_STRING NDIS_STRING, *PNDIS_STRING;

typedef enum _NDIS_REQUEST_TYPE
{
    NdisRequestQueryInformation,
    NdisRequestSetInformation,
    NdisRequestQueryStatistics,
    NdisRequestOpen,
    NdisRequestClose,
    NdisRequestSend,
    NdisRequestTransferData,
    NdisRequestReset,
    NdisRequestGeneric1,
    NdisRequestGeneric2,
    NdisRequestGeneric3,
    NdisRequestGeneric4,
    NdisRequestMethod,
} NDIS_REQUEST_TYPE, *PNDIS_REQUEST_TYPE;

typedef enum _NET_PNP_EVENT_CODE
{
    NetEventSetPower,
    NetEventQueryPower,
    NetEventQueryRemoveDevice,
    NetEventCancelRemoveDevice,
    NetEventReconfigure,
    NetEventBindList,
    NetEventBindsComplete,
    NetEventPnPCapabilities,
    NetEventPause,
    NetEventRestart,
    NetEventPortActivation,
    NetEventPortDeactivation,
    NetEventIMReEnableDevice,
    NetEventMaximum,
} NET_PNP_EVENT_CODE, *PNET_PNP_EVENT_CODE;


typedef struct _NET_PNP_EVENT
{
    NET_PNP_EVENT_CODE NetEvent;
    PVOID Buffer;
    ULONG BufferLength;
    ULONG_PTR NdisReserved[4];
    ULONG_PTR TransportReserved[4];
    ULONG_PTR TdiReserved[4];
    ULONG_PTR TdiClientReserved[4];
} NET_PNP_EVENT, *PNET_PNP_EVENT;

typedef struct _NDIS_PACKET_PRIVATE
{
    UINT PhysicalCount;
    UINT TotalLength;
    PNDIS_BUFFER Head;
    PNDIS_BUFFER Tail;
    PNDIS_PACKET_POOL Pool;
    UINT Count;
    ULONG Flags;
    BOOLEAN ValidCounts;
    UCHAR NdisPacketFlags;
    USHORT NdisPacketOobOffset;
} NDIS_PACKET_PRIVATE, *PNDIS_PACKET_PRIVATE;

typedef struct _NDIS_PACKET
{
    NDIS_PACKET_PRIVATE Private;
    union
    {
        struct
        {
            UCHAR MiniportReserved[2 * sizeof(void*)];
            UCHAR WrapperReserved[2 * sizeof(void*)];
        } DUMMYSTRUCTNAME;
        struct
        {
            UCHAR MiniportReservedEx[3 * sizeof(void*)];
            UCHAR WrapperReservedEx[sizeof(void*)];
        } DUMMYSTRUCTNAME1;
        struct
        {
            UCHAR MacReserved[4 * sizeof(void*)];
        } DUMMYSTRUCTNAME2;
    } DUMMYUNIONNAME;
    ULONG_PTR Reserved[2];
    UCHAR ProtocolReserved[1];
} NDIS_PACKET, *PNDIS_PACKET, **PPNDIS_PACKET;

typedef struct _NDIS_SPIN_LOCK
{
  KSPIN_LOCK SpinLock;
  KIRQL      OldIrql;
} NDIS_SPIN_LOCK, *PNDIS_SPIN_LOCK;


typedef struct _NDIS_REQUEST
{
    UCHAR MacReserved[4 * sizeof(void*)];
    NDIS_REQUEST_TYPE RequestType;
    union _DATA
    {
        struct QUERY_INFORMATION
        {
            NDIS_OID Oid;
            PVOID InformationBuffer;
            UINT InformationBufferLength;
            UINT BytesWritten;
            UINT BytesNeeded;
        } QUERY_INFORMATION;
        struct SET_INFORMATION
        {
            NDIS_OID Oid;
            PVOID InformationBuffer;
            UINT InformationBufferLength;
            UINT BytesRead;
            UINT BytesNeeded;
        } SET_INFORMATION;
    } DATA;
    UCHAR NdisReserved[9 * sizeof(void*)];
    union
    {
        UCHAR CallMgrReserved[2 * sizeof(void*)];
        UCHAR ProtocolReserved[2 * sizeof(void*)];
    } DUMMYUNIONNAME;
    UCHAR MiniportReserved[2 * sizeof(void*)];
} NDIS_REQUEST, *PNDIS_REQUEST;

typedef struct _CO_ADDRESS_FAMILY
{
    NDIS_AF AddressFamily;
    ULONG MajorVersion;
    ULONG MinorVersion;
} CO_ADDRESS_FAMILY, *PCO_ADDRESS_FAMILY;


typedef void (NTAPI *CO_AF_REGISTER_NOTIFY_HANDLER)(NDIS_HANDLE, PCO_ADDRESS_FAMILY);
typedef void (NTAPI *CO_SEND_COMPLETE_HANDLER)(NDIS_STATUS, NDIS_HANDLE, PNDIS_PACKET);
typedef void (NTAPI *CO_STATUS_HANDLER)(NDIS_HANDLE, NDIS_HANDLE, NDIS_STATUS, PVOID, UINT);
typedef UINT (NTAPI *CO_RECEIVE_PACKET_HANDLER)(NDIS_HANDLE, NDIS_HANDLE, PNDIS_PACKET);
typedef void (NTAPI *OPEN_ADAPTER_COMPLETE_HANDLER)(NDIS_HANDLE, NDIS_STATUS, NDIS_STATUS);
typedef void (NTAPI *CLOSE_ADAPTER_COMPLETE_HANDLER)(NDIS_HANDLE, NDIS_STATUS);
typedef void (NTAPI *RESET_COMPLETE_HANDLER)(NDIS_HANDLE, NDIS_STATUS);
typedef void (NTAPI *REQUEST_COMPLETE_HANDLER)(NDIS_HANDLE, PNDIS_REQUEST, NDIS_STATUS);
typedef void (NTAPI *STATUS_HANDLER)(NDIS_HANDLE, NDIS_STATUS, PVOID, UINT);
typedef void (NTAPI *STATUS_COMPLETE_HANDLER)(NDIS_HANDLE);
typedef void (NTAPI *SEND_COMPLETE_HANDLER)(NDIS_HANDLE, PNDIS_PACKET, NDIS_STATUS);
typedef void (NTAPI *TRANSFER_DATA_COMPLETE_HANDLER)(NDIS_HANDLE, PNDIS_PACKET, NDIS_STATUS, UINT);
typedef NDIS_STATUS (NTAPI *RECEIVE_HANDLER)(NDIS_HANDLE, NDIS_HANDLE, PVOID, UINT, PVOID, UINT, UINT);
typedef void (NTAPI *RECEIVE_COMPLETE_HANDLER)(NDIS_HANDLE);
typedef INT  (NTAPI *RECEIVE_PACKET_HANDLER)(NDIS_HANDLE, PNDIS_PACKET);
typedef void (NTAPI *BIND_HANDLER)(PNDIS_STATUS, NDIS_HANDLE, PNDIS_STRING, PVOID, PVOID);
typedef void (NTAPI *UNBIND_HANDLER)(PNDIS_STATUS, NDIS_HANDLE, NDIS_HANDLE);
typedef NDIS_STATUS (NTAPI *PNP_EVENT_HANDLER)(NDIS_HANDLE, PNET_PNP_EVENT);
typedef void (NTAPI *UNLOAD_PROTOCOL_HANDLER)(void);


typedef struct _NDIS_PROTOCOL_CHARACTERISTICS
{
    UCHAR MajorNdisVersion;
    UCHAR MinorNdisVersion;
    USHORT Filler;
    UINT Reserved;
    OPEN_ADAPTER_COMPLETE_HANDLER OpenAdapterCompleteHandler;
    CLOSE_ADAPTER_COMPLETE_HANDLER CloseAdapterCompleteHandler;
    SEND_COMPLETE_HANDLER SendCompleteHandler;
    TRANSFER_DATA_COMPLETE_HANDLER TransferDataCompleteHandler;
    RESET_COMPLETE_HANDLER ResetCompleteHandler;
    REQUEST_COMPLETE_HANDLER RequestCompleteHandler;
    RECEIVE_HANDLER ReceiveHandler;
    RECEIVE_COMPLETE_HANDLER ReceiveCompleteHandler;
    STATUS_HANDLER StatusHandler;
    STATUS_COMPLETE_HANDLER StatusCompleteHandler;
    NDIS_STRING Name;
    RECEIVE_PACKET_HANDLER ReceivePacketHandler;
    BIND_HANDLER BindAdapterHandler;
    UNBIND_HANDLER UnbindAdapterHandler;
    PNP_EVENT_HANDLER PnPEventHandler;
    UNLOAD_PROTOCOL_HANDLER UnloadHandler;
    CO_SEND_COMPLETE_HANDLER CoSendCompleteHandler;
    CO_STATUS_HANDLER CoStatusHandler;
    CO_RECEIVE_PACKET_HANDLER CoReceivePacketHandler;
    CO_AF_REGISTER_NOTIFY_HANDLER CoAfRegisterNotifyHandler;
} NDIS_PROTOCOL_CHARACTERISTICS, *PNDIS_PROTOCOL_CHARACTERISTICS;

#define NDIS_STATUS_FAILURE                                ((NDIS_STATUS) STATUS_UNSUCCESSFUL)

NDIS_STATUS WINAPI NdisAllocateMemoryWithTag(void **, UINT, ULONG);
void WINAPI NdisAllocateSpinLock(NDIS_SPIN_LOCK *);
void WINAPI NdisRegisterProtocol(NDIS_STATUS *, NDIS_HANDLE *, NDIS_PROTOCOL_CHARACTERISTICS *, UINT);
CCHAR WINAPI NdisSystemProcessorCount(void);

#endif /* _NDIS_ */
