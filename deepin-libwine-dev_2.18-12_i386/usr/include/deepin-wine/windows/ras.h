/*
 * Copyright (C) 1998 Marcus Meissner
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

#ifndef __WINE_RAS_H
#define __WINE_RAS_H

#include <lmcons.h>

#ifdef __cplusplus
extern "C" {
#endif
#include <pshpack4.h>
#include <inaddr.h>
#include <in6addr.h>

#define RAS_MaxCallbackNumber RAS_MaxPhoneNumber
#define RAS_MaxDeviceName     128
#define RAS_MaxDeviceType     16
#define RAS_MaxEntryName      256
#define RAS_MaxPhoneNumber    128
#define RAS_MaxAreaCode       10
#define RAS_MaxPadType        32
#define RAS_MaxX25Address     200
#define RAS_MaxFacilities     200
#define RAS_MaxUserData       200
#define RAS_MaxDnsSuffix      256

/* szDeviceType strings for RASDEVINFO */
#define RASDT_Direct     "direct"
#define RASDT_Modem      "modem"
#define RASDT_Isdn       "isdn"
#define RASDT_X25        "x25"
#define RASDT_Vpn        "vpn"
#define RASDT_Pad        "pad"
#define RASDT_Generic    "GENERIC"
#define RASDT_Serial     "SERIAL"
#define RASDT_FrameRelay "FRAMERELAY"
#define RASDT_Atm        "ATM"
#define RASDT_Sonet      "SONET"
#define RASDT_SW56       "SW56"
#define RASDT_Irda       "IRDA"
#define RASDT_Parallel   "PARALLEL"
#define RASDT_PPPoE      "PPPoE"

typedef struct tagRASDEVINFOA {
    DWORD    dwSize;
    CHAR     szDeviceType[ RAS_MaxDeviceType + 1 ];
    CHAR     szDeviceName[ RAS_MaxDeviceName + 1 ];
} RASDEVINFOA, *LPRASDEVINFOA;

typedef struct tagRASDEVINFOW {
    DWORD    dwSize;
    WCHAR    szDeviceType[ RAS_MaxDeviceType + 1 ];
    WCHAR    szDeviceName[ RAS_MaxDeviceName + 1 ];
} RASDEVINFOW, *LPRASDEVINFOW;

DECL_WINELIB_TYPE_AW(RASDEVINFO)
DECL_WINELIB_TYPE_AW(LPRASDEVINFO)

DECLARE_HANDLE(HRASCONN);
typedef  HRASCONN* LPHRASCONN;

typedef struct tagRASCONNA {
    DWORD    dwSize;
    HRASCONN hRasConn;
    CHAR     szEntryName[ RAS_MaxEntryName + 1 ];
    CHAR     szDeviceType[ RAS_MaxDeviceType + 1 ];
    CHAR     szDeviceName[ RAS_MaxDeviceName + 1 ];
    CHAR     szPhonebook[ MAX_PATH ];
    DWORD    dwSubEntry;
    GUID     guidEntry;
    DWORD    dwFlags;
    LUID     luid;
    GUID     guidCorrelationId;
} RASCONNA,*LPRASCONNA;

typedef struct tagRASCONNW {
    DWORD    dwSize;
    HRASCONN hRasConn;
    WCHAR    szEntryName[ RAS_MaxEntryName + 1 ];
    WCHAR    szDeviceType[ RAS_MaxDeviceType + 1 ];
    WCHAR    szDeviceName[ RAS_MaxDeviceName + 1 ];
    WCHAR    szPhonebook[ MAX_PATH ];
    DWORD    dwSubEntry;
    GUID     guidEntry;
    DWORD    dwFlags;
    LUID     luid;
    GUID     guidCorrelationId;
} RASCONNW,*LPRASCONNW;

DECL_WINELIB_TYPE_AW(RASCONN)
DECL_WINELIB_TYPE_AW(LPRASCONN)

typedef struct tagRASENTRYNAMEA {
    DWORD dwSize;
    CHAR  szEntryName[ RAS_MaxEntryName + 1 ];
} RASENTRYNAMEA, *LPRASENTRYNAMEA;

typedef struct tagRASENTRYNAMEW {
    DWORD dwSize;
    WCHAR szEntryName[ RAS_MaxEntryName + 1 ];
} RASENTRYNAMEW, *LPRASENTRYNAMEW;

DECL_WINELIB_TYPE_AW(RASENTRYNAME)
DECL_WINELIB_TYPE_AW(LPRASENTRYNAME)

typedef struct tagRASDIALPARAMSA {
    DWORD dwSize;
    CHAR szEntryName[ RAS_MaxEntryName + 1 ];
    CHAR szPhoneNumber[ RAS_MaxPhoneNumber + 1 ];
    CHAR szCallbackNumber[ RAS_MaxCallbackNumber + 1 ];
    CHAR szUserName[ UNLEN + 1 ];
    CHAR szPassword[ PWLEN + 1 ];
    CHAR szDomain[ DNLEN + 1 ];
    DWORD dwSubEntry;
    DWORD dwCallbackId;
} RASDIALPARAMSA, *LPRASDIALPARAMSA;

typedef struct tagRASDIALPARAMSW {
    DWORD dwSize;
    WCHAR szEntryName[ RAS_MaxEntryName + 1 ];
    WCHAR szPhoneNumber[ RAS_MaxPhoneNumber + 1 ];
    WCHAR szCallbackNumber[ RAS_MaxCallbackNumber + 1 ];
    WCHAR szUserName[ UNLEN + 1 ];
    WCHAR szPassword[ PWLEN + 1 ];
    WCHAR szDomain[ DNLEN + 1 ];
    DWORD dwSubEntry;
    DWORD dwCallbackId;
} RASDIALPARAMSW, *LPRASDIALPARAMSW;

DECL_WINELIB_TYPE_AW(RASDIALPARAMS)
DECL_WINELIB_TYPE_AW(LPRASDIALPARAMS)

typedef struct tagRASIPADDR {
	BYTE classA,classB,classC,classD;
} RASIPADDR;

#define RASEO_UseCountryAndAreaCodes	0x0001
#define RASEO_SpecificIpAddr		0x0002
#define RASEO_SpecificNameServers	0x0004
#define RASEO_IpHeaderCompression	0x0008
#define RASEO_RemoteDefaultGateway	0x0010
#define RASEO_DisableLcpExtensions	0x0020
#define RASEO_TerminalBeforeDial	0x0040
#define RASEO_TerminalAfterDial		0x0080
#define RASEO_ModemLights		0x0100
#define RASEO_SwCompression		0x0200
#define RASEO_RequireEncryptedPw	0x0400
#define RASEO_RequireMsEncryptedPw	0x0800
#define RASEO_RequireDataEncryption	0x1000
#define RASEO_NetworkLogon		0x2000
#define RASEO_UseLogonCredentials	0x4000
#define RASEO_PromoteAlternates		0x8000
typedef struct tagRASENTRYA {
    DWORD dwSize;
    DWORD dwfOptions;

    /* Location */

    DWORD dwCountryID;
    DWORD dwCountryCode;
    CHAR szAreaCode[ RAS_MaxAreaCode + 1 ];
    CHAR szLocalPhoneNumber[ RAS_MaxPhoneNumber + 1 ];
    DWORD dwAlternateOffset;

    /* IP related stuff */

    RASIPADDR ipaddr;
    RASIPADDR ipaddrDns;
    RASIPADDR ipaddrDnsAlt;
    RASIPADDR ipaddrWins;
    RASIPADDR ipaddrWinsAlt;

    /* Framing (for ppp/isdn etc...) */

    DWORD dwFrameSize;
    DWORD dwfNetProtocols;
    DWORD dwFramingProtocol;

    CHAR szScript[ MAX_PATH ];

    CHAR szAutodialDll[ MAX_PATH ];
    CHAR szAutodialFunc[ MAX_PATH ];

    CHAR szDeviceType[ RAS_MaxDeviceType + 1 ];
    CHAR szDeviceName[ RAS_MaxDeviceName + 1 ];

    /* x25 only */

    CHAR szX25PadType[ RAS_MaxPadType + 1 ];
    CHAR szX25Address[ RAS_MaxX25Address + 1 ];
    CHAR szX25Facilities[ RAS_MaxFacilities + 1 ];
    CHAR szX25UserData[ RAS_MaxUserData + 1 ];
    DWORD dwChannels;

    DWORD dwReserved1;
    DWORD dwReserved2;

    /* Multilink and BAP */

    DWORD dwSubEntries;
    DWORD dwDialMode;
    DWORD dwDialExtraPercent;
    DWORD dwDialExtraSampleSeconds;
    DWORD dwHangUpExtraPercent;
    DWORD dwHangUpExtraSampleSeconds;

    /* Idle time out */
    DWORD dwIdleDisconnectSeconds;

    DWORD dwType;		/* entry type */
    DWORD dwEncryptionType;	/* type of encryption to use */
    DWORD dwCustomAuthKey;	/* authentication key for EAP */
    GUID guidId;		/* guid that represents the phone-book entry  */
    CHAR szCustomDialDll[MAX_PATH];    /* DLL for custom dialing  */
    DWORD dwVpnStrategy;         /* specifies type of VPN protocol */

    DWORD dwfOptions2;
    DWORD dwfOptions3;
    CHAR szDnsSuffix[RAS_MaxDnsSuffix];
    DWORD dwTcpWindowSize;
    CHAR szPrerequisitePbk[MAX_PATH];
    CHAR szPrerequisiteEntry[RAS_MaxEntryName + 1];
    DWORD dwRedialCount;
    DWORD dwRedialPause;
} RASENTRYA, *LPRASENTRYA;

typedef struct tagRASENTRYW {
    DWORD dwSize;
    DWORD dwfOptions;

    /* Location */

    DWORD dwCountryID;
    DWORD dwCountryCode;
    WCHAR szAreaCode[ RAS_MaxAreaCode + 1 ];
    WCHAR szLocalPhoneNumber[ RAS_MaxPhoneNumber + 1 ];
    DWORD dwAlternateOffset;

    /* IP related stuff */

    RASIPADDR ipaddr;
    RASIPADDR ipaddrDns;
    RASIPADDR ipaddrDnsAlt;
    RASIPADDR ipaddrWins;
    RASIPADDR ipaddrWinsAlt;

    /* Framing (for ppp/isdn etc...) */

    DWORD dwFrameSize;
    DWORD dwfNetProtocols;
    DWORD dwFramingProtocol;

    WCHAR szScript[ MAX_PATH ];

    WCHAR szAutodialDll[ MAX_PATH ];
    WCHAR szAutodialFunc[ MAX_PATH ];

    WCHAR szDeviceType[ RAS_MaxDeviceType + 1 ];
    WCHAR szDeviceName[ RAS_MaxDeviceName + 1 ];

    /* x25 only */

    WCHAR szX25PadType[ RAS_MaxPadType + 1 ];
    WCHAR szX25Address[ RAS_MaxX25Address + 1 ];
    WCHAR szX25Facilities[ RAS_MaxFacilities + 1 ];
    WCHAR szX25UserData[ RAS_MaxUserData + 1 ];
    DWORD dwChannels;

    DWORD dwReserved1;
    DWORD dwReserved2;

    /* Multilink and BAP */

    DWORD dwSubEntries;
    DWORD dwDialMode;
    DWORD dwDialExtraPercent;
    DWORD dwDialExtraSampleSeconds;
    DWORD dwHangUpExtraPercent;
    DWORD dwHangUpExtraSampleSeconds;

    /* Idle time out */
    DWORD dwIdleDisconnectSeconds;

    DWORD dwType;		/* entry type */
    DWORD dwEncryptionType;	/* type of encryption to use */
    DWORD dwCustomAuthKey;	/* authentication key for EAP */
    GUID guidId;		/* guid that represents the phone-book entry  */
    WCHAR szCustomDialDll[MAX_PATH];    /* DLL for custom dialing  */
    DWORD dwVpnStrategy;         /* specifies type of VPN protocol */

    DWORD dwfOptions2;
    DWORD dwfOptions3;
    WCHAR szDnsSuffix[RAS_MaxDnsSuffix];
    DWORD dwTcpWindowSize;
    WCHAR szPrerequisitePbk[MAX_PATH];
    WCHAR szPrerequisiteEntry[RAS_MaxEntryName + 1];
    DWORD dwRedialCount;
    DWORD dwRedialPause;
} RASENTRYW, *LPRASENTRYW;

DECL_WINELIB_TYPE_AW(RASENTRY)

#define RASCS_PAUSED 0x1000
#define RASCS_DONE   0x2000
typedef enum tagRASCONNSTATE
{
      RASCS_OpenPort = 0,
      RASCS_PortOpened,
      RASCS_ConnectDevice,
      RASCS_DeviceConnected,
      RASCS_AllDevicesConnected,
      RASCS_Authenticate,
      RASCS_AuthNotify,
      RASCS_AuthRetry,
      RASCS_AuthCallback,
      RASCS_AuthChangePassword,
      RASCS_AuthProject,
      RASCS_AuthLinkSpeed,
      RASCS_AuthAck,
      RASCS_ReAuthenticate,
      RASCS_Authenticated,
      RASCS_PrepareForCallback,
      RASCS_WaitForModemReset,
      RASCS_WaitForCallback,
      RASCS_Projected,
      RASCS_StartAuthentication,
      RASCS_CallbackComplete,
      RASCS_LogonNetwork,
      RASCS_SubEntryConnected,
      RASCS_SubEntryDisconnected,
      RASCS_Interactive = RASCS_PAUSED,
      RASCS_RetryAuthentication,
      RASCS_CallbackSetByCaller,
      RASCS_PasswordExpired,
      RASCS_Connected = RASCS_DONE,
      RASCS_Disconnected
}  RASCONNSTATE, *LPRASCONNSTATE;

typedef struct tagRASCONNSTATUSA
{
    DWORD dwSize;
    RASCONNSTATE rasconnstate;
    DWORD dwError;
    CHAR szDeviceType[RAS_MaxDeviceType + 1];
    CHAR szDeviceName[RAS_MaxDeviceName + 1];
} RASCONNSTATUSA, *LPRASCONNSTATUSA;

typedef struct tagRASCONNSTATUSW
{
    DWORD dwSize;
    RASCONNSTATE rasconnstate;
    DWORD dwError;
    WCHAR szDeviceType[RAS_MaxDeviceType + 1];
    WCHAR szDeviceName[RAS_MaxDeviceName + 1];
} RASCONNSTATUSW, *LPRASCONNSTATUSW;

DECL_WINELIB_TYPE_AW(RASCONNSTATUS)

typedef enum tagRASPROJECTION
{
    RASP_Amb =    0x10000,
    RASP_PppNbf = 0x803F,
    RASP_PppIpx = 0x802B,
    RASP_PppIp =  0x8021,
    RASP_PppLcp = 0xC021,
    RASP_Slip =   0x20000
} RASPROJECTION, *LPRASPROJECTION;

typedef struct tagRASSUBENTRYA
{
    DWORD dwSize;
    DWORD dwfFlags;
    CHAR szDeviceType[RAS_MaxDeviceType + 1];
    CHAR szDeviceName[RAS_MaxDeviceName + 1];
    CHAR szLocalPhoneNumber[RAS_MaxPhoneNumber + 1];
    DWORD dwAlternateOffset;
} RASSUBENTRYA, *LPRASSUBENTRYA;

typedef struct tagRASSUBENTRYW
{
    DWORD dwSize;
    DWORD dwfFlags;
    WCHAR szDeviceType[RAS_MaxDeviceType + 1];
    WCHAR szDeviceName[RAS_MaxDeviceName + 1];
    WCHAR szLocalPhoneNumber[RAS_MaxPhoneNumber + 1];
    DWORD dwAlternateOffset;
} RASSUBENTRYW, *LPRASSUBENTRYW;

typedef struct tagRASDIALEXTENSIONS
{
    DWORD dwSize;
    DWORD dwfOptions;
    HWND hwndParent;
    ULONG_PTR reserved;
} RASDIALEXTENSIONS, *LPRASDIALEXTENSIONS;

typedef struct tagRASAUTODIALENTRYA
{
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwDialingLocation;
    CHAR  szEntry[ RAS_MaxEntryName + 1 ];
} RASAUTODIALENTRYA, *LPRASAUTODIALENTRYA;

typedef struct tagRASAUTODIALENTRYW
{
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwDialingLocation;
    WCHAR szEntry[ RAS_MaxEntryName + 1 ];
} RASAUTODIALENTRYW, *LPRASAUTODIALENTRYW;

typedef struct _RAS_STATS
{
    DWORD dwSize;
    DWORD dwBytesXmited;
    DWORD dwBytesRcved;
    DWORD dwFramesXmited;
    DWORD dwFramesRcved;
    DWORD dwCrcErr;
    DWORD dwTimeoutErr;
    DWORD dwAlignmentErr;
    DWORD dwHardwareOverrunErr;
    DWORD dwFramingErr;
    DWORD dwBufferOverrunErr;
    DWORD dwCompressionRatioIn;
    DWORD dwCompressionRatioOut;
    DWORD dwBps;
    DWORD dwConnectDuration;
} RAS_STATS, *PRAS_STATS;

DWORD WINAPI RasConnectionNotificationA(HRASCONN,HANDLE,DWORD);
DWORD WINAPI RasConnectionNotificationW(HRASCONN,HANDLE,DWORD);
#define      RasConnectionNotification WINELIB_NAME_AW(RasConnectionNotification)
DWORD WINAPI RasCreatePhonebookEntryA(HWND,LPCSTR);
DWORD WINAPI RasCreatePhonebookEntryW(HWND,LPCWSTR);
#define      RasCreatePhonebookEntry WINELIB_NAME_AW(RasCreatePhonebookEntry)
DWORD WINAPI RasDeleteEntryA(LPCSTR,LPCSTR);
DWORD WINAPI RasDeleteEntryW(LPCWSTR,LPCWSTR);
#define      RasDeleteEntry WINELIB_NAME_AW(RasDeleteEntry)
DWORD WINAPI RasDeleteSubEntryA(LPCSTR,LPCSTR,DWORD);
DWORD WINAPI RasDeleteSubEntryW(LPCWSTR,LPCWSTR,DWORD);
#define      RasDeleteSubEntry WINELIB_NAME_AW(RasDeleteSubEntry)
DWORD WINAPI RasDialA(LPRASDIALEXTENSIONS,LPCSTR,LPRASDIALPARAMSA,DWORD,LPVOID,LPHRASCONN);
DWORD WINAPI RasDialW(LPRASDIALEXTENSIONS,LPCWSTR,LPRASDIALPARAMSW,DWORD,LPVOID,LPHRASCONN);
#define      RasDial WINELIB_NAME_AW(RasDial)
DWORD WINAPI RasEditPhonebookEntryA(HWND,LPCSTR,LPCSTR);
DWORD WINAPI RasEditPhonebookEntryW(HWND,LPCWSTR,LPCWSTR);
#define      RasEditPhonebookEntry WINELIB_NAME_AW(RasEditPhonebookEntry)
DWORD WINAPI RasEnumAutodialAddressesA(LPSTR*,LPDWORD,LPDWORD);
DWORD WINAPI RasEnumAutodialAddressesW(LPWSTR*,LPDWORD,LPDWORD);
#define      RasEnumAutodialAddresses WINELIB_NAME_AW(RasEnumAutodialAddresses)
DWORD WINAPI RasEnumConnectionsA(LPRASCONNA,LPDWORD,LPDWORD);
DWORD WINAPI RasEnumConnectionsW(LPRASCONNW,LPDWORD,LPDWORD);
#define      RasEnumConnections WINELIB_NAME_AW(RasEnumConnections)
DWORD WINAPI RasEnumDevicesA(LPRASDEVINFOA,LPDWORD,LPDWORD);
DWORD WINAPI RasEnumDevicesW(LPRASDEVINFOW,LPDWORD,LPDWORD);
#define      RasEnumDevices WINELIB_NAME_AW(RasEnumDevices)
DWORD WINAPI RasEnumEntriesA(LPCSTR,LPCSTR,LPRASENTRYNAMEA,LPDWORD,LPDWORD);
DWORD WINAPI RasEnumEntriesW(LPCWSTR,LPCWSTR,LPRASENTRYNAMEW,LPDWORD,LPDWORD);
#define      RasEnumEntries WINELIB_NAME_AW(RasEnumEntries)
DWORD WINAPI RasGetAutodialAddressA(LPCSTR,LPDWORD,LPRASAUTODIALENTRYA,LPDWORD,LPDWORD);
DWORD WINAPI RasGetAutodialAddressW(LPCWSTR,LPDWORD,LPRASAUTODIALENTRYW,LPDWORD,LPDWORD);
#define      RasGetAutodialAddresses WINELIB_NAME_AW(RasGetAutodialAddresses)
DWORD WINAPI RasGetAutodialEnableA(DWORD,LPBOOL);
DWORD WINAPI RasGetAutodialEnableW(DWORD,LPBOOL);
#define      RasGetAutodialEnable WINELIB_NAME_AW(RasGetAutodialEnable)
DWORD WINAPI RasGetAutodialParamA(DWORD dwKey, LPVOID lpvValue, LPDWORD lpdwcbValue);
DWORD WINAPI RasGetAutodialParamW(DWORD dwKey, LPVOID lpvValue, LPDWORD lpdwcbValue);
#define RasGetAutodialParam WINELIB_NAME_AW(RasGetAutodialParam)
DWORD WINAPI RasGetConnectStatusA(HRASCONN,LPRASCONNSTATUSA);
DWORD WINAPI RasGetConnectStatusW(HRASCONN,LPRASCONNSTATUSW);
#define      RasGetConnectStatus WINELIB_NAME_AW(RasGetConnectStatus)
DWORD WINAPI RasGetEntryDialParamsA(LPCSTR,LPRASDIALPARAMSA,LPBOOL);
DWORD WINAPI RasGetEntryDialParamsW(LPCWSTR,LPRASDIALPARAMSW,LPBOOL);
#define      RasGetEntryDialParams WINELIB_NAME_AW(RasGetEntryDialParams)
DWORD WINAPI RasGetEntryPropertiesA(LPCSTR,LPCSTR,LPRASENTRYA,LPDWORD,LPBYTE,LPDWORD);
DWORD WINAPI RasGetEntryPropertiesW(LPCWSTR,LPCWSTR,LPRASENTRYW,LPDWORD,LPBYTE,LPDWORD);
#define      RasGetEntryProperties WINELIB_NAME_AW(RasGetEntryProperties)
DWORD WINAPI RasGetErrorStringA(UINT,LPSTR,DWORD);
DWORD WINAPI RasGetErrorStringW(UINT,LPWSTR,DWORD);
#define      RasGetErrorString WINELIB_NAME_AW(RasGetErrorString)
DWORD WINAPI RasGetProjectionInfoA(HRASCONN,RASPROJECTION,LPVOID,LPDWORD);
DWORD WINAPI RasGetProjectionInfoW(HRASCONN,RASPROJECTION,LPVOID,LPDWORD);
#define      RasGetProjectionInfo WINELIB_NAME_AW(RasGetProjectionInfo)
DWORD WINAPI RasHangUpA(HRASCONN);
DWORD WINAPI RasHangUpW(HRASCONN);
#define      RasHangUp WINELIB_NAME_AW(RasHangUp)
DWORD WINAPI RasRenameEntryA(LPCSTR,LPCSTR,LPCSTR);
DWORD WINAPI RasRenameEntryW(LPCWSTR,LPCWSTR,LPCWSTR);
#define      RasRenameEntry WINELIB_NAME_AW(RasRenameEntry)
DWORD WINAPI RasSetAutodialAddressA(LPCSTR,DWORD,LPRASAUTODIALENTRYA,DWORD,DWORD);
DWORD WINAPI RasSetAutodialAddressW(LPCWSTR,DWORD,LPRASAUTODIALENTRYW,DWORD,DWORD);
#define      RasSetAutodialAddress WINELIB_NAME_AW(RasSetAutodialAddress)
DWORD WINAPI RasSetAutodialParamA(DWORD,LPVOID,DWORD);
DWORD WINAPI RasSetAutodialParamW(DWORD,LPVOID,DWORD);
#define      RasSetAutodialParam WINELIB_NAME_AW(RasSetAutodialParam)
DWORD WINAPI RasSetCustomAuthDataA(const CHAR *,const CHAR *,BYTE *,DWORD);
DWORD WINAPI RasSetCustomAuthDataW(const WCHAR *,const WCHAR *,BYTE *,DWORD);
#define      RasSetCustomAuthData WINELIB_NAME_AW(RasSetCustomAuthData)
DWORD WINAPI RasSetEntryDialParamsA(LPCSTR,LPRASDIALPARAMSA,BOOL);
DWORD WINAPI RasSetEntryDialParamsW(LPCWSTR,LPRASDIALPARAMSW,BOOL);
#define      RasSetEntryDialParams WINELIB_NAME_AW(RasSetEntryDialParams)
DWORD WINAPI RasSetSubEntryPropertiesA(LPCSTR,LPCSTR,DWORD,LPRASSUBENTRYA,DWORD,LPBYTE,DWORD);
DWORD WINAPI RasSetSubEntryPropertiesW(LPCWSTR,LPCWSTR,DWORD,LPRASSUBENTRYW,DWORD,LPBYTE,DWORD);
#define      RasSetSubEntryProperties WINELIB_NAME_AW(RasSetSubEntryProperties)
DWORD WINAPI RasValidateEntryNameA(LPCSTR  lpszPhonebook, LPCSTR  lpszEntry);
DWORD WINAPI RasValidateEntryNameW(LPCWSTR lpszPhonebook, LPCWSTR lpszEntry);
#define RasValidateEntryName WINELIB_NAME_AW(RasValidateEntryName)
DWORD WINAPI RasSetEntryPropertiesA(LPCSTR,LPCSTR,LPRASENTRYA,DWORD,LPBYTE,DWORD);
DWORD WINAPI RasSetEntryPropertiesW(LPCWSTR,LPCWSTR,LPRASENTRYW,DWORD,LPBYTE,DWORD);
#define RasSetEntryProperties WINELIB_NAME_AW(RasSetEntryProperties)
DWORD WINAPI RasSetAutodialEnableA(DWORD dwDialingLocation, BOOL fEnabled);
DWORD WINAPI RasSetAutodialEnableW(DWORD dwDialingLocation, BOOL fEnabled);
#define RasSetAutodialEnable WINELIB_NAME_AW(RasSetAutodialEnable)

#include <poppack.h>
#ifdef __cplusplus
}
#endif

#endif
