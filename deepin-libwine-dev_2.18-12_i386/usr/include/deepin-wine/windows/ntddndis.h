/*
 * Copyright 2009 Jacek Caban for CodeWeavers
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

#ifndef _NTDDNDIS_
#define _NTDDNDIS_

#include <ifdef.h>
#include <devpkey.h>
/* #include <pciprop.h> */

#ifndef GUID_DEFINED
# include <guiddef.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define _NDIS_CONTROL_CODE(request, method) \
    CTL_CODE(FILE_DEVICE_PHYSICAL_NETCARD, request, method, FILE_ANY_ACCESS)

#define IOCTL_NDIS_QUERY_GLOBAL_STATS    _NDIS_CONTROL_CODE(0, METHOD_OUT_DIRECT)
#define IOCTL_NDIS_QUERY_ALL_STATS       _NDIS_CONTROL_CODE(1, METHOD_OUT_DIRECT)
#define IOCTL_NDIS_DO_PNP_OPERATION      _NDIS_CONTROL_CODE(2, METHOD_BUFFERED)
#define IOCTL_NDIS_QUERY_SELECTED_STATS  _NDIS_CONTROL_CODE(3, METHOD_OUT_DIRECT)
#define IOCTL_NDIS_ENUMERATE_INTERFACES  _NDIS_CONTROL_CODE(4, METHOD_BUFFERED)
#define IOCTL_NDIS_ADD_TDI_DEVICE        _NDIS_CONTROL_CODE(5, METHOD_BUFFERED)
#define IOCTL_NDIS_GET_LOG_DATA          _NDIS_CONTROL_CODE(7, METHOD_OUT_DIRECT)
#define IOCTL_NDIS_GET_VERSION           _NDIS_CONTROL_CODE(8, METHOD_BUFFERED)

#define IOCTL_NDIS_RESERVED1   _NDIS_CONTROL_CODE(0x09, METHOD_BUFFERED)
#define IOCTL_NDIS_RESERVED2   _NDIS_CONTROL_CODE(0x0a, METHOD_BUFFERED)
#define IOCTL_NDIS_RESERVED3   _NDIS_CONTROL_CODE(0x0b, METHOD_BUFFERED)
#define IOCTL_NDIS_RESERVED4   _NDIS_CONTROL_CODE(0x0c, METHOD_BUFFERED)
#define IOCTL_NDIS_RESERVED5   CTL_CODE(FILE_DEVICE_PHYSICAL_NETCARD, 0x0d, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_NDIS_RESERVED6   CTL_CODE(FILE_DEVICE_PHYSICAL_NETCARD, 0x0e, METHOD_BUFFERED, FILE_WRITE_ACCESS)
#define IOCTL_NDIS_RESERVED7   _NDIS_CONTROL_CODE(0x0f, METHOD_OUT_DIRECT)
#define IOCTL_NDIS_RESERVED8   _NDIS_CONTROL_CODE(0x10, METHOD_BUFFERED)
#define IOCTL_NDIS_RESERVED9   _NDIS_CONTROL_CODE(0x11, METHOD_BUFFERED)
#define IOCTL_NDIS_RESERVED10  _NDIS_CONTROL_CODE(0x12, METHOD_BUFFERED)
#define IOCTL_NDIS_RESERVED11  _NDIS_CONTROL_CODE(0x13, METHOD_BUFFERED)
#define IOCTL_NDIS_RESERVED12  _NDIS_CONTROL_CODE(0x14, METHOD_BUFFERED)
#define IOCTL_NDIS_RESERVED13  _NDIS_CONTROL_CODE(0x15, METHOD_BUFFERED)

#define OID_GEN_SUPPORTED_LIST              0x00010101
#define OID_GEN_HARDWARE_STATUS             0x00010102
#define OID_GEN_MEDIA_SUPPORTED             0x00010103
#define OID_GEN_MEDIA_IN_USE                0x00010104
#define OID_GEN_MAXIMUM_LOOKAHEAD           0x00010105
#define OID_GEN_MAXIMUM_FRAME_SIZE          0x00010106
#define OID_GEN_LINK_SPEED                  0x00010107
#define OID_GEN_TRANSMIT_BUFFER_SPACE       0x00010108
#define OID_GEN_RECEIVE_BUFFER_SPACE        0x00010109
#define OID_GEN_TRANSMIT_BLOCK_SIZE         0x0001010a
#define OID_GEN_RECEIVE_BLOCK_SIZE          0x0001010b
#define OID_GEN_VENDOR_ID                   0x0001010c
#define OID_GEN_VENDOR_DESCRIPTION          0x0001010d
#define OID_GEN_CURRENT_PACKET_FILTER       0x0001010e
#define OID_GEN_CURRENT_LOOKAHEAD           0x0001010f
#define OID_GEN_DRIVER_VERSION              0x00010110
#define OID_GEN_MAXIMUM_TOTAL_SIZE          0x00010111
#define OID_GEN_PROTOCOL_OPTIONS            0x00010112
#define OID_GEN_MAC_OPTIONS                 0x00010113
#define OID_GEN_MEDIA_CONNECT_STATUS        0x00010114
#define OID_GEN_MAXIMUM_SEND_PACKETS        0x00010115

#define OID_802_3_PERMANENT_ADDRESS         0x01010101
#define OID_802_3_CURRENT_ADDRESS           0x01010102
#define OID_802_3_MULTICAST_LIST            0x01010103
#define OID_802_3_MAXIMUM_LIST_SIZE         0x01010104
#define OID_802_3_MAC_OPTIONS               0x01010105
#define OID_802_3_RCV_ERROR_ALIGNMENT       0x01020101
#define OID_802_3_XMIT_ONE_COLLISION        0x01020102
#define OID_802_3_XMIT_MORE_COLLISIONS      0x01020103
#define OID_802_3_XMIT_DEFERRED             0x01020201
#define OID_802_3_XMIT_MAX_COLLISIONS       0x01020202
#define OID_802_3_RCV_OVERRUN               0x01020203
#define OID_802_3_XMIT_UNDERRUN             0x01020204
#define OID_802_3_XMIT_HEARTBEAT_FAILURE    0x01020205
#define OID_802_3_XMIT_TIMES_CRS_LOST       0x01020206
#define OID_802_3_XMIT_LATE_COLLISIONS      0x01020207
#define OID_802_3_ADD_MULTICAST_ADDRESS     0x01010208
#define OID_802_3_DELETE_MULTICAST_ADDRESS  0x01010209

#define OID_802_5_PERMANENT_ADDRESS         0x02010101
#define OID_802_5_CURRENT_ADDRESS           0x02010102
#define OID_802_5_CURRENT_FUNCTIONAL        0x02010103
#define OID_802_5_CURRENT_GROUP             0x02010104
#define OID_802_5_LAST_OPEN_STATUS          0x02010105
#define OID_802_5_CURRENT_RING_STATUS       0x02010106
#define OID_802_5_CURRENT_RING_STATE        0x02010107
#define OID_802_5_LINE_ERRORS               0x02020101
#define OID_802_5_LOST_FRAMES               0x02020102
#define OID_802_5_BURST_ERRORS              0x02020201
#define OID_802_5_AC_ERRORS                 0x02020202
#define OID_802_5_ABORT_DELIMETERS          0x02020203
#define OID_802_5_FRAME_COPIED_ERRORS       0x02020204
#define OID_802_5_FREQUENCY_ERRORS          0x02020205
#define OID_802_5_TOKEN_ERRORS              0x02020206
#define OID_802_5_INTERNAL_ERRORS           0x02020207

#define OID_802_11_BSSID                    0x0d010101
#define OID_802_11_SSID                     0x0d010102
#define OID_802_11_NETWORK_TYPES_SUPPORTED  0x0d010203
#define OID_802_11_NETWORK_TYPE_IN_USE      0x0d010204
#define OID_802_11_TX_POWER_LEVEL           0x0d010205
#define OID_802_11_RSSI                     0x0d010206
#define OID_802_11_RSSI_TRIGGER             0x0d010207
#define OID_802_11_INFRASTRUCTURE_MODE      0x0d010108
#define OID_802_11_FRAGMENTATION_THRESHOLD  0x0d010209
#define OID_802_11_RTS_THRESHOLD            0x0d01020a
#define OID_802_11_NUMBER_OF_ANTENNAS       0x0d01020b
#define OID_802_11_RX_ANTENNA_SELECTED      0x0d01020c
#define OID_802_11_TX_ANTENNA_SELECTED      0x0d01020d
#define OID_802_11_SUPPORTED_RATES          0x0d01020e
#define OID_802_11_DESIRED_RATES            0x0d010210
#define OID_802_11_CONFIGURATION            0x0d010211
#define OID_802_11_STATISTICS               0x0d020212
#define OID_802_11_ADD_WEP                  0x0d010113
#define OID_802_11_REMOVE_WEP               0x0d010114
#define OID_802_11_DISASSOCIATE             0x0d010115
#define OID_802_11_POWER_MODE               0x0d010216
#define OID_802_11_BSSID_LIST               0x0d010217
#define OID_802_11_AUTHENTICATION_MODE      0x0d010118
#define OID_802_11_PRIVACY_FILTER           0x0d010119
#define OID_802_11_BSSID_LIST_SCAN          0x0d01011a
#define OID_802_11_WEP_STATUS               0x0d01011b
#define OID_802_11_ENCRYPTION_STATUS        OID_802_11_WEP_STATUS
#define OID_802_11_RELOAD_DEFAULTS          0x0d01011c
#define OID_802_11_ADD_KEY                  0x0d01011d
#define OID_802_11_REMOVE_KEY               0x0d01011e
#define OID_802_11_ASSOCIATION_INFORMATION  0x0d01011f
#define OID_802_11_TEST                     0x0d010120
#define OID_802_11_MEDIA_STREAM_MODE        0x0d010121
#define OID_802_11_CAPABILITY               0x0d010122
#define OID_802_11_PMKID                    0x0d010123
#define OID_802_11_NON_BCAST_SSID_LIST      0x0d010124
#define OID_802_11_RADIO_STATUS             0x0d010125

#define NDIS_802_11_LENGTH_SSID      32
#define NDIS_802_11_LENGTH_RATES     8
#define NDIS_802_11_LENGTH_RATES_EX  16

typedef LONG NDIS_802_11_RSSI;

typedef struct _NDIS_802_11_CONFIGURATION_FH {
    ULONG Length;
    ULONG HopPattern;
    ULONG HopSet;
    ULONG DwellTime;
} NDIS_802_11_CONFIGURATION_FH, *PNDIS_802_11_CONFIGURATION_FH;

typedef struct _NDIS_802_11_CONFIGURATION {
    ULONG Length;
    ULONG BeaconPeriod;
    ULONG ATIMWindow;
    ULONG DSConfig;
    NDIS_802_11_CONFIGURATION_FH FHConfig;
} NDIS_802_11_CONFIGURATION, *PNDIS_802_11_CONFIGURATION;

typedef UCHAR NDIS_802_11_MAC_ADDRESS[6];

typedef enum _NDIS_802_11_NETWORK_INFRASTRUCTURE {
    Ndis802_11IBSS,
    Ndis802_11Infrastructure,
    Ndis802_11AutoUnknown,
    Ndis802_11InfrastructureMax
} NDIS_802_11_NETWORK_INFRASTRUCTURE, *PNDIS_802_11_NETWORK_INFRASTRUCTURE;

typedef enum _NDIS_802_11_NETWORK_TYPE {
    Ndis802_11FH,
    Ndis802_11DS,
    Ndis802_11OFDM5,
    Ndis802_11OFDM24,
    Ndis802_11Automode,
    Ndis802_11NetworkTypeMax
} NDIS_802_11_NETWORK_TYPE, *PNDIS_802_11_NETWORK_TYPE;

typedef UCHAR NDIS_802_11_RATES[NDIS_802_11_LENGTH_RATES];
typedef UCHAR NDIS_802_11_RATES_EX[NDIS_802_11_LENGTH_RATES_EX];

typedef struct _NDIS_802_11_SSID {
    ULONG SsidLength;
    UCHAR Ssid[NDIS_802_11_LENGTH_SSID];
} NDIS_802_11_SSID, *PNDIS_802_11_SSID;

typedef struct _NDIS_WLAN_BSSID {
    ULONG                               Length;
    NDIS_802_11_MAC_ADDRESS             MacAddress;
    UCHAR                               Reserved[2];
    NDIS_802_11_SSID                    Ssid;
    ULONG                               Privacy;
    NDIS_802_11_RSSI                    Rssi;
    NDIS_802_11_NETWORK_TYPE            NetworkTypeInUse;
    NDIS_802_11_CONFIGURATION           Configuration;
    NDIS_802_11_NETWORK_INFRASTRUCTURE  InfrastructureMode;
    NDIS_802_11_RATES                   SupportedRates;
} NDIS_WLAN_BSSID, *PNDIS_WLAN_BSSID;

typedef struct _NDIS_802_11_BSSID_LIST {
    ULONG NumberOfItems;
    NDIS_WLAN_BSSID Bssid[1];
} NDIS_802_11_BSSID_LIST, *PNDIS_802_11_BSSID_LIST;

#ifndef _NDIS_
typedef int NDIS_STATUS, *PNDIS_STATUS;
#endif

typedef enum _NDIS_MEDIUM
{
    NdisMedium802_3,
    NdisMedium802_5,
    NdisMediumFddi,
    NdisMediumWan,
    NdisMediumLocalTalk,
    NdisMediumDix,
    NdisMediumArcnetRaw,
    NdisMediumArcnet878_2,
    NdisMediumAtm,
    NdisMediumWirelessWan,
    NdisMediumIrda,
    NdisMediumBpc,
    NdisMediumCoWan,
    NdisMedium1394,
    NdisMediumInfiniBand,
    NdisMediumTunnel,
    NdisMediumNative802_11,
    NdisMediumLoopback,
    NdisMediumWiMAX,
    NdisMediumIP,
    NdisMediumMax
} NDIS_MEDIUM, *PNDIS_MEDIUM;

typedef enum _NDIS_PHYSICAL_MEDIUM
{
    NdisPhysicalMediumUnspecified,
    NdisPhysicalMediumWirelessLan,
    NdisPhysicalMediumCableModem,
    NdisPhysicalMediumPhoneLine,
    NdisPhysicalMediumPowerLine,
    NdisPhysicalMediumDSL,
    NdisPhysicalMediumFibreChannel,
    NdisPhysicalMedium1394,
    NdisPhysicalMediumWirelessWan,
    NdisPhysicalMediumNative802_11,
    NdisPhysicalMediumBluetooth,
    NdisPhysicalMediumInfiniband,
    NdisPhysicalMediumWiMax,
    NdisPhysicalMediumUWB,
    NdisPhysicalMedium802_3,
    NdisPhysicalMedium802_5,
    NdisPhysicalMediumIrda,
    NdisPhysicalMediumWiredWAN,
    NdisPhysicalMediumWiredCoWan,
    NdisPhysicalMediumOther,
    NdisPhysicalMediumMax
} NDIS_PHYSICAL_MEDIUM, *PNDIS_PHYSICAL_MEDIUM;

#ifdef __cplusplus
}
#endif

#endif /* _NTDDNDIS_ */
