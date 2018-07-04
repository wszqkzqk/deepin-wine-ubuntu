/*
 * DDEML library definitions
 *
 * Copyright 1997 Alexandre Julliard
 * Copyright 1997 Len White
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

#ifndef __WINE_DDEML_H
#define __WINE_DDEML_H

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

#ifdef _USER32_
#define WINUSERAPI
#else
#define WINUSERAPI DECLSPEC_IMPORT
#endif

/* Codepage Constants
 */

#define CP_WINANSI      1004
#define CP_WINUNICODE   1200

/* DDE synchronisation constants
 */

#define MSGF_DDEMGR 0x8001

#define QID_SYNC	0xFFFFFFFF

/*   Type variation for MS  deliberate departures from ANSI standards
 */

#define EXPENTRY CALLBACK

#ifdef UNICODE
#if defined(_MSC_VER)
#define SZDDESYS_TOPIC          L"System"
#define SZDDESYS_ITEM_TOPICS    L"Topics"
#define SZDDESYS_ITEM_SYSITEMS  L"SysItems"
#define SZDDESYS_ITEM_RTNMSG    L"ReturnMessage"
#define SZDDESYS_ITEM_STATUS    L"Status"
#define SZDDESYS_ITEM_FORMATS   L"Formats"
#define SZDDESYS_ITEM_HELP      L"Help"
#define SZDDE_ITEM_ITEMLIST     L"TopicItemList"
#elif defined(__GNUC__)
#define SZDDESYS_TOPIC          (const WCHAR []){'S','y','s','t','e','m',0}
#define SZDDESYS_ITEM_TOPICS    (const WCHAR []){'T','o','p','i','c','s',0}
#define SZDDESYS_ITEM_SYSITEMS  (const WCHAR []){'S','y','s','I','t','e','m','s',0}
#define SZDDESYS_ITEM_RTNMSG    (const WCHAR []){'R','e','t','u','r','n','M','e','s','s','a','g','e',0}
#define SZDDESYS_ITEM_STATUS    (const WCHAR []){'S','t','a','t','u','s',0}
#define SZDDESYS_ITEM_FORMATS   (const WCHAR []){'F','o','r','m','a','t','s',0}
#define SZDDESYS_ITEM_HELP      (const WCHAR []){'H','e','l','p',0}
#define SZDDE_ITEM_ITEMLIST     (const WCHAR []){'T','o','p','i','c','I','t','e','m','L','i','s','t',0}
#else /* _MSC_VER/__GNUC__ */
static const WCHAR SZDDESYS_TOPIC[] = {'S','y','s','t','e','m',0};
static const WCHAR SZDDESYS_ITEM_TOPICS[] = {'T','o','p','i','c','s',0};
static const WCHAR SZDDESYS_ITEM_SYSITEMS[] = {'S','y','s','I','t','e','m','s',0};
static const WCHAR SZDDESYS_ITEM_RTNMSG[] = {'R','e','t','u','r','n','M','e','s','s','a','g','e',0};
static const WCHAR SZDDESYS_ITEM_STATUS[] = {'S','t','a','t','u','s',0};
static const WCHAR SZDDESYS_ITEM_FORMATS[] = {'F','o','r','m','a','t','s',0};
static const WCHAR SZDDESYS_ITEM_HELP[] = {'H','e','l','p',0};
static const WCHAR SZDDE_ITEM_ITEMLIST[] = {'T','o','p','i','c','I','t','e','m','L','i','s','t',0};
#endif
#else /* UNICODE */
#define SZDDESYS_TOPIC          "System"
#define SZDDESYS_ITEM_TOPICS    "Topics"
#define SZDDESYS_ITEM_SYSITEMS  "SysItems"
#define SZDDESYS_ITEM_RTNMSG    "ReturnMessage"
#define SZDDESYS_ITEM_STATUS    "Status"
#define SZDDESYS_ITEM_FORMATS   "Formats"
#define SZDDESYS_ITEM_HELP      "Help"
#define SZDDE_ITEM_ITEMLIST     "TopicItemList"
#endif

/***************************************************

      FLAGS Section - copied from Microsoft SDK as must be standard, probably Copyright Microsoft Corporation

***************************************************/

#define     XST_NULL              0
#define     XST_INCOMPLETE        1
#define     XST_CONNECTED         2
#define     XST_INIT1             3
#define     XST_INIT2             4
#define     XST_REQSENT           5
#define     XST_DATARCVD          6
#define     XST_POKESENT          7
#define     XST_POKEACKRCVD       8
#define     XST_EXECSENT          9
#define     XST_EXECACKRCVD      10
#define     XST_ADVSENT          11
#define     XST_UNADVSENT        12
#define     XST_ADVACKRCVD       13
#define     XST_UNADVACKRCVD     14
#define     XST_ADVDATASENT      15
#define     XST_ADVDATAACKRCVD   16

#define     ST_CONNECTED            0x0001
#define     ST_ADVISE               0x0002
#define     ST_ISLOCAL              0x0004
#define     ST_BLOCKED              0x0008
#define     ST_CLIENT               0x0010
#define     ST_TERMINATED           0x0020
#define     ST_INLIST               0x0040
#define     ST_BLOCKNEXT            0x0080
#define     ST_ISSELF               0x0100

/*
 * DdeEnableCallback function codes
 */

#define     EC_ENABLEALL                 0
#define     EC_ENABLEONE                 ST_BLOCKNEXT
#define     EC_DISABLE                   ST_BLOCKED
#define     EC_QUERYWAITING              2

/*
 * Callback filter flags for use with standard apps.
 */

#define     CBF_FAIL_SELFCONNECTIONS     0x00001000
#define     CBF_FAIL_CONNECTIONS         0x00002000
#define     CBF_FAIL_ADVISES             0x00004000
#define     CBF_FAIL_EXECUTES            0x00008000
#define     CBF_FAIL_POKES               0x00010000
#define     CBF_FAIL_REQUESTS            0x00020000
#define     CBF_FAIL_ALLSVRXACTIONS      0x0003f000

#define     CBF_SKIP_CONNECT_CONFIRMS    0x00040000
#define     CBF_SKIP_REGISTRATIONS       0x00080000
#define     CBF_SKIP_UNREGISTRATIONS     0x00100000
#define     CBF_SKIP_DISCONNECTS         0x00200000
#define     CBF_SKIP_ALLNOTIFICATIONS    0x003c0000

#define     CBR_BLOCK                    ((HDDEDATA)-1)

/*
 * Application command flags
 */
#define     APPCMD_CLIENTONLY            __MSABI_LONG(0x00000010)
#define     APPCMD_FILTERINITS           __MSABI_LONG(0x00000020)
#define     APPCMD_MASK                  __MSABI_LONG(0x00000FF0)

/*
 * Application classification flags
 */

#define     APPCLASS_STANDARD            __MSABI_LONG(0x00000000)
#define     APPCLASS_MONITOR             __MSABI_LONG(0x00000001)
#define     APPCLASS_MASK                __MSABI_LONG(0x0000000F)

/*
 * Callback filter flags for use with MONITOR apps - 0 implies no monitor
 * callbacks.
 */
#define     MF_HSZ_INFO                  0x01000000
#define     MF_SENDMSGS                  0x02000000
#define     MF_POSTMSGS                  0x04000000
#define     MF_CALLBACKS                 0x08000000
#define     MF_ERRORS                    0x10000000
#define     MF_LINKS                     0x20000000
#define     MF_CONV                      0x40000000

#define     MF_MASK                      0xFF000000

/*
 *	DdeNameService service name flags
 */

#define     DNS_REGISTER		 0x0001
#define     DNS_UNREGISTER		 0x0002
#define     DNS_FILTERON		 0x0004
#define     DNS_FILTEROFF         	 0x0008


/****************************************************

      End of Flags section

****************************************************/

/****************************************************

	Message Types Section

****************************************************/

#define XTYPF_NOBLOCK		0x0002		/* CBR_NOBLOCK will not work */
#define XTYPF_NODATA		0x0004		/* DDE_FDEFERUPD  */
#define XTYPF_ACKREQ		0x0008		/* DDE_FACKREQ */

#define XCLASS_MASK		0xFC00
#define XCLASS_BOOL		0x1000
#define XCLASS_DATA		0x2000
#define XCLASS_FLAGS		0x4000
#define	XCLASS_NOTIFICATION	0x8000

#define XTYP_ERROR		(0x0000 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define XTYP_ADVDATA		(0x0010 | XCLASS_FLAGS)
#define XTYP_ADVREQ		(0x0020 | XCLASS_DATA | XTYPF_NOBLOCK)
#define XTYP_ADVSTART		(0x0030 | XCLASS_BOOL)
#define XTYP_ADVSTOP		(0x0040 | XCLASS_NOTIFICATION)
#define XTYP_EXECUTE		(0x0050 | XCLASS_FLAGS)
#define XTYP_CONNECT		(0x0060 | XCLASS_BOOL | XTYPF_NOBLOCK)
#define XTYP_CONNECT_CONFIRM	(0x0070 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)
#define XTYP_XACT_COMPLETE	(0x0080 | XCLASS_NOTIFICATION )
#define XTYP_POKE		(0x0090 | XCLASS_FLAGS)
#define XTYP_REGISTER		(0x00A0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK )
#define XTYP_REQUEST		(0x00B0 | XCLASS_DATA )
#define XTYP_DISCONNECT		(0x00C0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK )
#define XTYP_UNREGISTER		(0x00D0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK )
#define XTYP_WILDCONNECT	(0x00E0 | XCLASS_DATA | XTYPF_NOBLOCK)
#define XTYP_MONITOR		(0x00F0 | XCLASS_NOTIFICATION | XTYPF_NOBLOCK)

#define XTYP_MASK		0x00F0
#define XTYP_SHIFT		4

#define TIMEOUT_ASYNC           0xFFFFFFFF

#define CADV_LATEACK		0xFFFF

/**************************************************

	End of Message Types Section

****************************************************/

/*****************************************************

	DDE Codes for wStatus field

*****************************************************/

#define DDE_FACK		0x8000
#define DDE_FBUSY		0x4000
#define DDE_FDEFERUPD		0x4000
#define DDE_FACKREQ		0x8000
#define DDE_FRELEASE		0x2000
#define DDE_FREQUESTED		0x1000
#define DDE_FAPPSTATUS		0x00FF
#define DDE_FNOTPROCESSED	0x0000

#define DDE_FACKRESERVED        (~(DDE_FACK | DDE_FBUSY | DDE_FAPPSTATUS))
#define DDE_FADVRESERVED        (~(DDE_FACKREQ | DDE_FDEFERUPD))
#define DDE_FDATRESERVED        (~(DDE_FACKREQ | DDE_FRELEASE | DDE_FREQUESTED))
#define DDE_FPOKRESERVED        (~(DDE_FRELEASE))

/*****************************************************

	End of wStatus codes

*****************************************************/

/****************************************************

      Return Codes section again copied from SDK as must be same

*****************************************************/

#define     DMLERR_NO_ERROR                    0       /* must be 0 */

#define     DMLERR_FIRST                       0x4000

#define     DMLERR_ADVACKTIMEOUT               0x4000
#define     DMLERR_BUSY                        0x4001
#define     DMLERR_DATAACKTIMEOUT              0x4002
#define     DMLERR_DLL_NOT_INITIALIZED         0x4003
#define     DMLERR_DLL_USAGE                   0x4004
#define     DMLERR_EXECACKTIMEOUT              0x4005
#define     DMLERR_INVALIDPARAMETER            0x4006
#define     DMLERR_LOW_MEMORY                  0x4007
#define     DMLERR_MEMORY_ERROR                0x4008
#define     DMLERR_NOTPROCESSED                0x4009
#define     DMLERR_NO_CONV_ESTABLISHED         0x400a
#define     DMLERR_POKEACKTIMEOUT              0x400b
#define     DMLERR_POSTMSG_FAILED              0x400c
#define     DMLERR_REENTRANCY                  0x400d
#define     DMLERR_SERVER_DIED                 0x400e
#define     DMLERR_SYS_ERROR                   0x400f
#define     DMLERR_UNADVACKTIMEOUT             0x4010
#define     DMLERR_UNFOUND_QUEUE_ID            0x4011

#define     DMLERR_LAST                        0x4011

#define     HDATA_APPOWNED          	       0x0001

/*****************************************************

      End of Return Codes and Microsoft section

******************************************************/



DECLARE_HANDLE(HCONVLIST);
DECLARE_HANDLE(HCONV);
DECLARE_HANDLE(HSZ);
DECLARE_HANDLE(HDDEDATA);



/*******************************************************

	API Entry Points

*******************************************************/

typedef HDDEDATA (CALLBACK *PFNCALLBACK)(UINT, UINT, HCONV, HSZ, HSZ,
					 HDDEDATA, ULONG_PTR, ULONG_PTR);

/***************************************************

	Externally visible data structures

***************************************************/

typedef struct tagHSZPAIR
{
    HSZ hszSvc;
    HSZ hszTopic;
} HSZPAIR, *PHSZPAIR;

typedef struct tagCONVCONTEXT
{
    UINT  cb;
    UINT  wFlags;
    UINT  wCountryID;
    INT   iCodePage;
    DWORD dwLangID;
    DWORD dwSecurity;
    SECURITY_QUALITY_OF_SERVICE qos;
} CONVCONTEXT, *PCONVCONTEXT;

typedef struct tagCONVINFO
{
    DWORD		cb;
    DWORD_PTR 		hUser;
    HCONV		hConvPartner;
    HSZ			hszSvcPartner;
    HSZ			hszServiceReq;
    HSZ			hszTopic;
    HSZ			hszItem;
    UINT		wFmt;
    UINT		wType;
    UINT		wStatus;
    UINT		wConvst;
    UINT		wLastError;
    HCONVLIST		hConvList;
    CONVCONTEXT		ConvCtxt;
    HWND		hwnd;
    HWND		hwndPartner;
} CONVINFO, *PCONVINFO;

/*            Interface Definitions		*/

WINUSERAPI BOOL      WINAPI DdeAbandonTransaction(DWORD idInst, HCONV hConv, DWORD idTransaction);
WINUSERAPI LPBYTE    WINAPI DdeAccessData(HDDEDATA,LPDWORD);
WINUSERAPI HDDEDATA  WINAPI DdeAddData(HDDEDATA,LPBYTE,DWORD,DWORD);
WINUSERAPI HDDEDATA  WINAPI DdeClientTransaction(LPBYTE,DWORD,HCONV,HSZ,UINT,UINT,DWORD,LPDWORD);
WINUSERAPI INT       WINAPI DdeCmpStringHandles(HSZ,HSZ);
WINUSERAPI HCONV     WINAPI DdeConnect(DWORD,HSZ,HSZ,PCONVCONTEXT);
WINUSERAPI HCONVLIST WINAPI DdeConnectList(DWORD,HSZ,HSZ,HCONVLIST,PCONVCONTEXT);
WINUSERAPI HDDEDATA  WINAPI DdeCreateDataHandle(DWORD,LPBYTE,DWORD,DWORD,HSZ,UINT,UINT);
WINUSERAPI HSZ       WINAPI DdeCreateStringHandleA(DWORD,LPCSTR,INT);
WINUSERAPI HSZ       WINAPI DdeCreateStringHandleW(DWORD,LPCWSTR,INT);
#define                     DdeCreateStringHandle WINELIB_NAME_AW(DdeCreateStringHandle)
WINUSERAPI BOOL      WINAPI DdeDisconnect(HCONV);
WINUSERAPI BOOL      WINAPI DdeDisconnectList(HCONVLIST);
WINUSERAPI BOOL      WINAPI DdeEnableCallback(DWORD,HCONV,UINT);
WINUSERAPI BOOL      WINAPI DdeFreeDataHandle(HDDEDATA);
WINUSERAPI BOOL      WINAPI DdeFreeStringHandle(DWORD,HSZ);
WINUSERAPI DWORD     WINAPI DdeGetData(HDDEDATA,LPBYTE,DWORD,DWORD);
WINUSERAPI UINT      WINAPI DdeGetLastError(DWORD);
WINUSERAPI BOOL      WINAPI DdeImpersonateClient(HCONV);
WINUSERAPI UINT      WINAPI DdeInitializeA(LPDWORD,PFNCALLBACK,DWORD,DWORD);
WINUSERAPI UINT      WINAPI DdeInitializeW(LPDWORD,PFNCALLBACK,DWORD,DWORD);
#define                     DdeInitialize WINELIB_NAME_AW(DdeInitialize)
WINUSERAPI BOOL      WINAPI DdeKeepStringHandle(DWORD,HSZ);
WINUSERAPI HDDEDATA  WINAPI DdeNameService(DWORD,HSZ,HSZ,UINT);
WINUSERAPI BOOL      WINAPI DdePostAdvise(DWORD,HSZ,HSZ);
WINUSERAPI UINT      WINAPI DdeQueryConvInfo(HCONV,DWORD,PCONVINFO);
WINUSERAPI HCONV     WINAPI DdeQueryNextServer(HCONVLIST, HCONV);
WINUSERAPI DWORD     WINAPI DdeQueryStringA(DWORD, HSZ, LPSTR, DWORD, INT);
WINUSERAPI DWORD     WINAPI DdeQueryStringW(DWORD, HSZ, LPWSTR, DWORD, INT);
#define                     DdeQueryString WINELIB_NAME_AW(DdeQueryString)
WINUSERAPI HCONV     WINAPI DdeReconnect(HCONV);
WINUSERAPI BOOL      WINAPI DdeSetUserHandle(HCONV,DWORD,DWORD);
WINUSERAPI BOOL      WINAPI DdeUnaccessData(HDDEDATA);
WINUSERAPI BOOL      WINAPI DdeUninitialize(DWORD);

#ifdef __cplusplus
} /* extern "C" */
#endif /* defined(__cplusplus) */

#endif  /* __WINE_DDEML_H */
