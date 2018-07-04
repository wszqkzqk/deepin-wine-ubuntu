/*
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

#ifndef __WINE_SHELLAPI_H
#define __WINE_SHELLAPI_H

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

#ifndef _WIN64
#include <pshpack1.h>
#endif

DECLARE_HANDLE(HDROP);

/******************************************
 * DragObject
 */

typedef struct _DRAGINFOA
{	UINT uSize;
	POINT pt;
	BOOL fNC;
	LPSTR   lpFileList;
	DWORD grfKeyState;
} DRAGINFOA, *LPDRAGINFOA;

typedef struct _DRAGINFOW
{	UINT uSize;
	POINT pt;
	BOOL fNC;
	LPWSTR  lpFileList;
	DWORD grfKeyState;
} DRAGINFOW, *LPDRAGINFOW;

DECL_WINELIB_TYPE_AW(DRAGINFO)
DECL_WINELIB_TYPE_AW(LPDRAGINFO)

void	WINAPI DragAcceptFiles(HWND hWnd, BOOL b);
UINT	WINAPI DragQueryFileA(HDROP hDrop, UINT lFile, LPSTR lpszFile, UINT lLength);
UINT	WINAPI DragQueryFileW(HDROP hDrop, UINT lFile, LPWSTR lpszFile, UINT lLength);
#define        DragQueryFile WINELIB_NAME_AW(DragQueryFile)
void	WINAPI DragFinish(HDROP h);
BOOL	WINAPI DragQueryPoint(HDROP hDrop, POINT *p);



/******************************************
 * Application Bar
 */
#define ABM_NEW			0x00000000
#define ABM_REMOVE		0x00000001
#define ABM_QUERYPOS		0x00000002
#define ABM_SETPOS		0x00000003
#define ABM_GETSTATE		0x00000004
#define ABM_GETTASKBARPOS	0x00000005
#define ABM_ACTIVATE		0x00000006
#define ABM_GETAUTOHIDEBAR	0x00000007
#define ABM_SETAUTOHIDEBAR	0x00000008
#define ABM_WINDOWPOSCHANGED	0x00000009

#define ABN_STATECHANGE		0x00000000
#define ABN_POSCHANGED		0x00000001
#define ABN_FULLSCREENAPP	0x00000002
#define ABN_WINDOWARRANGE	0x00000003

#define ABS_AUTOHIDE		0x00000001
#define ABS_ALWAYSONTOP		0x00000002

#define ABE_LEFT		0
#define ABE_TOP			1
#define ABE_RIGHT		2
#define ABE_BOTTOM		3

typedef struct _AppBarData
{	DWORD	cbSize;
	HWND	hWnd;
	UINT	uCallbackMessage;
	UINT	uEdge;
	RECT	rc;
	LPARAM	lParam;
} APPBARDATA, *PAPPBARDATA;

UINT_PTR WINAPI SHAppBarMessage(DWORD,PAPPBARDATA);

/******************************************
 * SHGetFileInfo
 */

#define SHGFI_LARGEICON         0x000000000     /* get large icon */
#define SHGFI_SMALLICON         0x000000001     /* get small icon */
#define SHGFI_OPENICON          0x000000002     /* get open icon */
#define SHGFI_SHELLICONSIZE     0x000000004     /* get shell size icon */
#define SHGFI_PIDL              0x000000008     /* pszPath is a pidl */
#define SHGFI_USEFILEATTRIBUTES 0x000000010     /* use passed dwFileAttribute */
#define SHGFI_ADDOVERLAYS       0x000000020
#define SHGFI_OVERLAYINDEX      0x000000040
#define SHGFI_ICON              0x000000100     /* get icon */
#define SHGFI_DISPLAYNAME       0x000000200     /* get display name */
#define SHGFI_TYPENAME          0x000000400     /* get type name */
#define SHGFI_ATTRIBUTES        0x000000800     /* get attributes */
#define SHGFI_ICONLOCATION      0x000001000     /* get icon location */
#define SHGFI_EXETYPE           0x000002000     /* return exe type */
#define SHGFI_SYSICONINDEX      0x000004000     /* get system icon index */
#define SHGFI_LINKOVERLAY       0x000008000     /* put a link overlay on icon */
#define SHGFI_SELECTED          0x000010000     /* show icon in selected state */
#define SHGFI_ATTR_SPECIFIED    0x000020000     /* get only specified attributes */

typedef struct tagSHFILEINFOA
{	HICON	hIcon;			/* icon */
	int	iIcon;			/* icon index */
	DWORD	dwAttributes;		/* SFGAO_ flags */
	CHAR	szDisplayName[MAX_PATH];/* display name (or path) */
	CHAR	szTypeName[80];		/* type name */
} SHFILEINFOA;

typedef struct tagSHFILEINFOW
{	HICON	hIcon;			/* icon */
	int	iIcon;			/* icon index */
	DWORD	dwAttributes;		/* SFGAO_ flags */
	WCHAR	szDisplayName[MAX_PATH];/* display name (or path) */
	WCHAR	szTypeName[80];		/* type name */
} SHFILEINFOW;

DECL_WINELIB_TYPE_AW(SHFILEINFO)

DWORD_PTR	WINAPI SHGetFileInfoA(LPCSTR,DWORD,SHFILEINFOA*,UINT,UINT);
DWORD_PTR	WINAPI SHGetFileInfoW(LPCWSTR,DWORD,SHFILEINFOW*,UINT,UINT);
#define  SHGetFileInfo WINELIB_NAME_AW(SHGetFileInfo)

/******************************************
 * SHGetImageList
 */

HRESULT WINAPI SHGetImageList(INT, REFIID, void **);

#define SHIL_LARGE        0x0
#define SHIL_SMALL        0x1
#define SHIL_EXTRALARGE   0x2
#define SHIL_SYSSMALL     0x3
#define SHIL_JUMBO        0x4
#define SHIL_LAST         SHIL_JUMBO

/******************************************
 * SHSetFileInfo
 */

/******************************************
* SHFileOperation
*/
#define FO_MOVE           0x0001
#define FO_COPY           0x0002
#define FO_DELETE         0x0003
#define FO_RENAME         0x0004

#define FOF_MULTIDESTFILES         0x0001
#define FOF_CONFIRMMOUSE           0x0002
#define FOF_SILENT                 0x0004
#define FOF_RENAMEONCOLLISION      0x0008
#define FOF_NOCONFIRMATION         0x0010
#define FOF_WANTMAPPINGHANDLE      0x0020
#define FOF_ALLOWUNDO              0x0040
#define FOF_FILESONLY              0x0080
#define FOF_SIMPLEPROGRESS         0x0100
#define FOF_NOCONFIRMMKDIR         0x0200
#define FOF_NOERRORUI              0x0400
#define FOF_NOCOPYSECURITYATTRIBS  0x0800
#define FOF_NORECURSION            0x1000  /* don't do recursion into directories */
#define FOF_NO_CONNECTED_ELEMENTS  0x2000  /* don't do connected files */
#define FOF_WANTNUKEWARNING        0x4000  /* during delete operation, warn if delete instead
                                              of recycling (even if FOF_NOCONFIRMATION) */
#define FOF_NORECURSEREPARSE       0x8000  /* don't do recursion into reparse points */
#define FOF_NO_UI                  (FOF_SILENT | FOF_NOCONFIRMATION | FOF_NOERRORUI | FOF_NOCONFIRMMKDIR)

typedef WORD FILEOP_FLAGS;

#define PO_DELETE       0x0013
#define PO_RENAME       0x0014
#define PO_PORTCHANGE   0x0020
#define PO_REN_PORT     (PO_RENAME | PO_PORTCHANGE)

typedef WORD PRINTEROP_FLAGS;

typedef struct _SHFILEOPSTRUCTA
{ HWND          hwnd;
  UINT          wFunc;
  LPCSTR          pFrom;
  LPCSTR          pTo;
  FILEOP_FLAGS    fFlags;
  BOOL          fAnyOperationsAborted;
  LPVOID          hNameMappings;
  LPCSTR          lpszProgressTitle;
} SHFILEOPSTRUCTA, *LPSHFILEOPSTRUCTA;

typedef struct _SHFILEOPSTRUCTW
{ HWND          hwnd;
  UINT          wFunc;
  LPCWSTR         pFrom;
  LPCWSTR         pTo;
  FILEOP_FLAGS    fFlags;
  BOOL          fAnyOperationsAborted;
  LPVOID          hNameMappings;
  LPCWSTR         lpszProgressTitle;
} SHFILEOPSTRUCTW, *LPSHFILEOPSTRUCTW;

#define  SHFILEOPSTRUCT WINELIB_NAME_AW(SHFILEOPSTRUCT)
#define  LPSHFILEOPSTRUCT WINELIB_NAME_AW(LPSHFILEOPSTRUCT)

int	WINAPI SHFileOperationA (LPSHFILEOPSTRUCTA lpFileOp);
int	WINAPI SHFileOperationW (LPSHFILEOPSTRUCTW lpFileOp);
#define  SHFileOperation WINELIB_NAME_AW(SHFileOperation)

typedef struct _SHNAMEMAPPINGA
{
  LPSTR    pszOldPath;
  LPSTR    pszNewPath;
  int      cchOldPath;
  int      cchNewPath;
} SHNAMEMAPPINGA, *LPSHNAMEMAPPINGA;

typedef struct _SHNAMEMAPPINGW
{
  LPWSTR   pszOldPath;
  LPWSTR   pszNewPath;
  int      cchOldPath;
  int      cchNewPath;
} SHNAMEMAPPINGW, *LPSHNAMEMAPPINGW;

DECL_WINELIB_TYPE_AW(SHNAMEMAPPING)
DECL_WINELIB_TYPE_AW(LPSHNAMEMAPPING)

void WINAPI SHFreeNameMappings(HANDLE hNameMappings);

/******************************************
 * ShellExecute
 */

HINSTANCE	WINAPI ShellExecuteA(HWND,LPCSTR,LPCSTR,LPCSTR,LPCSTR,INT);
HINSTANCE	WINAPI ShellExecuteW(HWND,LPCWSTR,LPCWSTR,LPCWSTR,LPCWSTR,INT);
#define     ShellExecute WINELIB_NAME_AW(ShellExecute)

#define SE_ERR_FNF              2       /* file not found */
#define SE_ERR_PNF              3       /* path not found */
#define SE_ERR_ACCESSDENIED     5       /* access denied */
#define SE_ERR_OOM              8       /* out of memory */
#define SE_ERR_DLLNOTFOUND      32
#define SE_ERR_SHARE                    26
#define SE_ERR_ASSOCINCOMPLETE          27
#define SE_ERR_DDETIMEOUT               28
#define SE_ERR_DDEFAIL                  29
#define SE_ERR_DDEBUSY                  30
#define SE_ERR_NOASSOC                  31

#define SEE_MASK_DEFAULT          0x00000000
#define SEE_MASK_CLASSNAME        0x00000001
#define SEE_MASK_CLASSKEY         0x00000003
#define SEE_MASK_IDLIST           0x00000004
#define SEE_MASK_INVOKEIDLIST     0x0000000c
#define SEE_MASK_ICON             0x00000010
#define SEE_MASK_HOTKEY           0x00000020
#define SEE_MASK_NOCLOSEPROCESS   0x00000040
#define SEE_MASK_CONNECTNETDRV    0x00000080
#define SEE_MASK_NOASYNC          0x00000100
#define SEE_MASK_FLAG_DDEWAIT     SEE_MASK_NOASYNC
#define SEE_MASK_DOENVSUBST       0x00000200
#define SEE_MASK_FLAG_NO_UI       0x00000400
#define SEE_MASK_UNICODE          0x00004000
#define SEE_MASK_NO_CONSOLE       0x00008000
#define SEE_MASK_ASYNCOK          0x00100000
#define SEE_MASK_HMONITOR         0x00200000
#define SEE_MASK_NOZONECHECKS     0x00800000
#define SEE_MASK_NOQUERYCLASSSTORE 0x01000000
#define SEE_MASK_WAITFORINPUTIDLE 0x02000000
#define SEE_MASK_FLAG_LOG_USAGE   0x04000000

typedef struct _SHELLEXECUTEINFOA
{       DWORD cbSize;
        ULONG fMask;
        HWND hwnd;
        LPCSTR   lpVerb;
        LPCSTR   lpFile;
        LPCSTR   lpParameters;
        LPCSTR   lpDirectory;
       INT nShow;
        HINSTANCE hInstApp;
        /* Optional fields */
        LPVOID lpIDList;
        LPCSTR   lpClass;
        HKEY hkeyClass;
        DWORD dwHotKey;
        union
        { HANDLE hIcon;
          HANDLE hMonitor;
        } DUMMYUNIONNAME;
        HANDLE hProcess;
} SHELLEXECUTEINFOA, *LPSHELLEXECUTEINFOA;

typedef struct _SHELLEXECUTEINFOW
{       DWORD cbSize;
        ULONG fMask;
        HWND hwnd;
        LPCWSTR  lpVerb;
        LPCWSTR  lpFile;
        LPCWSTR  lpParameters;
        LPCWSTR  lpDirectory;
       INT nShow;
        HINSTANCE hInstApp;
        /* Optional fields*/
        LPVOID lpIDList;
        LPCWSTR  lpClass;
        HKEY hkeyClass;
        DWORD dwHotKey;
        union
        { HANDLE hIcon;
          HANDLE hMonitor;
        } DUMMYUNIONNAME;
        HANDLE hProcess;
} SHELLEXECUTEINFOW, *LPSHELLEXECUTEINFOW;

#define SHELLEXECUTEINFO   WINELIB_NAME_AW(SHELLEXECUTEINFO)
#define LPSHELLEXECUTEINFO WINELIB_NAME_AW(LPSHELLEXECUTEINFO)

BOOL WINAPI ShellExecuteExA(LPSHELLEXECUTEINFOA lpExecInfo);
BOOL WINAPI ShellExecuteExW(LPSHELLEXECUTEINFOW lpExecInfo);
#define ShellExecuteEx  WINELIB_NAME_AW(ShellExecuteEx)

void WINAPI WinExecErrorA(HWND hwnd,INT error, LPCSTR lpstrFileName, LPCSTR lpstrTitle);
void WINAPI WinExecErrorW(HWND hwnd,INT error, LPCWSTR lpstrFileName, LPCWSTR lpstrTitle);
#define WinExecError  WINELIB_NAME_AW(WinExecError)

/******************************************
 * Tray Notification
 */
/* notifyicondata.uFlags values*/
#define NIF_MESSAGE             0x00000001
#define NIF_ICON                0x00000002
#define NIF_TIP                 0x00000004
#define NIF_STATE               0x00000008
#define NIF_INFO                0x00000010
#define NIF_GUID                0x00000020
#define NIF_REALTIME            0x00000040
#define NIF_SHOWTIP             0x00000080

/* notifyicondata.dwState values */
#define NIS_HIDDEN              0x00000001
#define NIS_SHAREDICON          0x00000002

/* notifyicondata.dwInfoFlags values */
#define NIIF_NONE               0x00000000
#define NIIF_INFO               0x00000001
#define NIIF_WARNING            0x00000002
#define NIIF_ERROR              0x00000003
#define NIIF_USER               0x00000004
#define NIIF_ICONMASK           0x0000000f
#define NIIF_NOSOUND            0x00000010
#define NIIF_LARGEICON          0x00000020

/* dwMessage values */
#define NIM_ADD                 0x00000000
#define NIM_MODIFY              0x00000001
#define NIM_DELETE              0x00000002
#define NIM_SETFOCUS            0x00000003
#define NIM_SETVERSION          0x00000004

#define NOTIFY_VERSION   3     /* supported by Windows 2000 and later */
#define NOTIFY_VERSION_4 4     /* supported by Windows Vista */

/* callback message lParam values */
#define NIN_SELECT              (WM_USER+0)
#define NINF_KEY                1
#define NIN_KEYSELECT           (NIN_SELECT|NINF_KEY)  /* WM_USER+1 */
#define NIN_BALOONSHOW          (WM_USER+2)
#define NIN_BALOONHIDE          (WM_USER+3)
#define NIN_BALOONTIMEOUT       (WM_USER+4)
#define NIN_BALOONCLICK         (WM_USER+5)
#define NIN_POPUPOPEN           (WM_USER+6)
#define NIN_POPUPCLOSE          (WM_USER+7)

typedef struct _NOTIFYICONDATAA
{	DWORD cbSize;
	HWND hWnd;
	UINT uID;
	UINT uFlags;
	UINT uCallbackMessage;
	HICON hIcon;
	CHAR szTip[128];
	DWORD dwState;
	DWORD dwStateMask;
	CHAR szInfo[256];
	union {
	    UINT uTimeout;
	    UINT uVersion;
	} DUMMYUNIONNAME;
	CHAR szInfoTitle[64];
	DWORD dwInfoFlags;
	GUID guidItem;
	HICON hBalloonIcon;
} NOTIFYICONDATAA, *PNOTIFYICONDATAA;

typedef struct _NOTIFYICONDATAW
{	DWORD cbSize;
	HWND hWnd;
	UINT uID;
	UINT uFlags;
	UINT uCallbackMessage;
	HICON hIcon;
	WCHAR szTip[128];
	DWORD dwState;
	DWORD dwStateMask;
	WCHAR szInfo[256];
	union {
	    UINT uTimeout;
	    UINT uVersion;
	} DUMMYUNIONNAME;
	WCHAR szInfoTitle[64];
	DWORD dwInfoFlags;
	GUID guidItem;
	HICON hBalloonIcon;
} NOTIFYICONDATAW, *PNOTIFYICONDATAW;

DECL_WINELIB_TYPE_AW(NOTIFYICONDATA)
DECL_WINELIB_TYPE_AW(PNOTIFYICONDATA)

BOOL WINAPI Shell_NotifyIconA(DWORD dwMessage, PNOTIFYICONDATAA lpData);
BOOL WINAPI Shell_NotifyIconW(DWORD dwMessage, PNOTIFYICONDATAW lpData);

#define Shell_NotifyIcon WINELIB_NAME_AW(Shell_NotifyIcon)

/* pre IE 5.0 */
#define NOTIFYICONDATAA_V1_SIZE FIELD_OFFSET(NOTIFYICONDATAA, szTip[64])
#define NOTIFYICONDATAW_V1_SIZE FIELD_OFFSET(NOTIFYICONDATAW, szTip[64])

/* pre Window XP */
#define NOTIFYICONDATAA_V2_SIZE FIELD_OFFSET(NOTIFYICONDATAA, guidItem)
#define NOTIFYICONDATAW_V2_SIZE FIELD_OFFSET(NOTIFYICONDATAW, guidItem)

/* pre Window Vista */
#define NOTIFYICONDATAA_V3_SIZE FIELD_OFFSET(NOTIFYICONDATAA, hBalloonIcon)
#define NOTIFYICONDATAW_V3_SIZE FIELD_OFFSET(NOTIFYICONDATAW, hBalloonIcon)


/******************************************
 * Links
 */

#define SHGNLI_PIDL        0x01
#define SHGNLI_PREFIXNAME  0x02
#define SHGNLI_NOUNIQUE    0x04
#define SHGNLI_NOLNK       0x08

BOOL WINAPI SHGetNewLinkInfoA(LPCSTR,LPCSTR,LPSTR,BOOL*,UINT);
BOOL WINAPI SHGetNewLinkInfoW(LPCWSTR,LPCWSTR,LPWSTR,BOOL*,UINT);
#define     SHGetNewLinkInfo WINELIB_NAME_AW(SHGetNewLinkInfo)

/******************************************
 * Recycle bin
 */

typedef struct _SHQUERYRBINFO
{
    DWORD cbSize;
    DWORDLONG i64Size;
    DWORDLONG i64NumItems;
} SHQUERYRBINFO, *LPSHQUERYRBINFO;

HRESULT     WINAPI SHEmptyRecycleBinA(HWND,LPCSTR,DWORD);
HRESULT     WINAPI SHEmptyRecycleBinW(HWND,LPCWSTR,DWORD);
#define     SHEmptyRecycleBin WINELIB_NAME_AW(SHEmptyRecycleBin)
HRESULT     WINAPI SHQueryRecycleBinA(LPCSTR,LPSHQUERYRBINFO);
HRESULT     WINAPI SHQueryRecycleBinW(LPCWSTR,LPSHQUERYRBINFO);
#define     SHQueryRecycleBin WINELIB_NAME_AW(SHQueryRecycleBin)

/******************************************
 * Misc
 */

typedef enum
{
    QUNS_NOT_PRESENT             = 1,
    QUNS_BUSY                    = 2,
    QUNS_RUNNING_D3D_FULL_SCREEN = 3,
    QUNS_PRESENTATION_MODE       = 4,
    QUNS_ACCEPTS_NOTIFICATIONS   = 5,
    QUNS_QUIET_TIME              = 6,
    QUNS_APP                     = 7
} QUERY_USER_NOTIFICATION_STATE;

HRESULT     WINAPI SHQueryUserNotificationState(QUERY_USER_NOTIFICATION_STATE*);

typedef enum SHSTOCKICONID
{
    SIID_INVALID=-1,
    SIID_DOCNOASSOC,
    SIID_DOCASSOC,
    SIID_APPLICATION,
    SIID_FOLDER,
    SIID_FOLDEROPEN,
    SIID_DRIVE525,
    SIID_DRIVE35,
    SIID_DRIVERREMOVE,
    SIID_DRIVERFIXED,
    SIID_DRIVERNET,
    SIID_DRIVERNETDISABLE,
    SIID_DRIVERCD,
    SIID_DRIVERRAM,
    SIID_WORLD,
    /* Missing: 14 */
    SIID_SERVER = 15,
    SIID_PRINTER,
    SIID_MYNETWORK,
    /* Missing: 18 - 21 */
    SIID_FIND = 22,
    SIID_HELP,
    /* Missing: 24 - 27 */
    SIID_SHARE = 28,
    SIID_LINK,
    SIID_SLOWFILE,
    SIID_RECYCLER,
    SIID_RECYCLERFULL,
    /* Missing: 33 - 39 */
    SIID_MEDIACDAUDIO = 40,
    /* Missing: 41 - 46 */
    SIID_LOCK = 47,
    /* Missing: 48 */
    SIID_AUTOLIST = 49,
    SIID_PRINTERNET,
    SIID_SERVERSHARE,
    SIID_PRINTERFAX,
    SIID_PRINTERFAXNET,
    SIID_PRINTERFILE,
    SIID_STACK,
    SIID_MEDIASVCD,
    SIID_STUFFEDFOLDER,
    SIID_DRIVEUNKNOWN,
    SIID_DRIVEDVD,
    SIID_MEDIADVD,
    SIID_MEDIADVDRAM,
    SIID_MEDIADVDRW,
    SIID_MEDIADVDR,
    SIID_MEDIADVDROM,
    SIID_MEDIACDAUDIOPLUS,
    SIID_MEDIACDRW,
    SIID_MEDIACDR,
    SIID_MEDIACDBURN,
    SIID_MEDIABLANKCD,
    SIID_MEDIACDROM,
    SIID_AUDIOFILES,
    SIID_IMAGEFILES,
    SIID_VIDEOFILES,
    SIID_MIXEDFILES,
    SIID_FOLDERBACK,
    SIID_FOLDERFRONT,
    SIID_SHIELD,
    SIID_WARNING,
    SIID_INFO,
    SIID_ERROR,
    SIID_KEY,
    SIID_SOFTWARE,
    SIID_RENAME,
    SIID_DELETE,
    SIID_MEDIAAUDIODVD,
    SIID_MEDIAMOVIEDVD,
    SIID_MEDIAENHANCEDCD,
    SIID_MEDIAENHANCEDDVD,
    SIID_MEDIAHDDVD,
    SIID_MEDIABLUERAY,
    SIID_MEDIAVCD,
    SIID_MEDIADVDPLUSR,
    SIID_MEDIADVDPLUSRW,
    SIID_DESKTOPPC,
    SIID_MOBILEPC,
    SIID_USERS,
    SIID_MEDIASMARTMEDIA,
    SIID_MEDIACOMPACTFLASH,
    SIID_DEVICECELLPHONE,
    SIID_DEVICECAMERA,
    SIID_DEVICEVIDEOCAMERA,
    SIID_DEVICEAUDIOPLAYER,
    SIID_NETWORKCONNECT,
    SIID_INTERNET,
    SIID_ZIPFILE,
    SIID_SETTINGS,
    /* Missing: 107 - 131 */
    SIID_DRIVEHDDVD = 132,
    SIID_DRIVEBD,
    SIID_MEDIAHDDVDROM,
    SIID_MEDIAHDDVDR,
    SIID_MEDIAHDDVDRAM,
    SIID_MEDIABDROM,
    SIID_MEDIABDR,
    SIID_MEDIABDRE,
    SIID_CLUSTEREDDRIVE,
    /* Missing: 141 - 180 */
    SIID_MAX_ICONS = 181
}SHSTOCKICONID;

typedef struct _SHSTOCKICONINFO
{
    DWORD   cbSize;
    HICON   hIcon;
    INT     iSysImageIndex;
    INT     iIcon;
    WCHAR   szPath[MAX_PATH];
} SHSTOCKICONINFO;

/* flags for SHGetStockIconInfo */
#define SHGSI_ICONLOCATION  0
#define SHGSI_ICON          SHGFI_ICON
#define SHGSI_SYSICONINDEX  SHGFI_SYSICONINDEX
#define SHGSI_LINKOVERLAY   SHGFI_LINKOVERLAY
#define SHGSI_SELECTED      SHGFI_SELECTED
#define SHGSI_LARGEICON     SHGFI_LARGEICON
#define SHGSI_SMALLICON     SHGFI_SMALLICON
#define SHGSI_SHELLICONSIZE SHGFI_SHELLICONSIZE

HRESULT     WINAPI SHGetStockIconInfo(SHSTOCKICONID, UINT, SHSTOCKICONINFO*);
LPWSTR*     WINAPI CommandLineToArgvW(LPCWSTR,int*);
HICON       WINAPI ExtractIconA(HINSTANCE,LPCSTR,UINT);
HICON       WINAPI ExtractIconW(HINSTANCE,LPCWSTR,UINT);
#define     ExtractIcon WINELIB_NAME_AW(ExtractIcon)
HICON       WINAPI ExtractAssociatedIconA(HINSTANCE,LPSTR,LPWORD);
HICON       WINAPI ExtractAssociatedIconW(HINSTANCE,LPWSTR,LPWORD);
#define     ExtractAssociatedIcon WINELIB_NAME_AW(ExtractAssociatedIcon)
HICON       WINAPI ExtractAssociatedIconExA(HINSTANCE,LPSTR,LPWORD,LPWORD);
HICON       WINAPI ExtractAssociatedIconExW(HINSTANCE,LPWSTR,LPWORD,LPWORD);
#define     ExtractAssociatedIconEx WINELIB_NAME_AW(ExtractAssociatedIconEx)
UINT        WINAPI ExtractIconExA(LPCSTR,INT,HICON*,HICON*,UINT);
UINT        WINAPI ExtractIconExW(LPCWSTR,INT,HICON*,HICON*,UINT);
#define     ExtractIconEx WINELIB_NAME_AW(ExtractIconEx)
HINSTANCE   WINAPI FindExecutableA(LPCSTR,LPCSTR,LPSTR);
HINSTANCE   WINAPI FindExecutableW(LPCWSTR,LPCWSTR,LPWSTR);
#define     FindExecutable WINELIB_NAME_AW(FindExecutable)
BOOL        WINAPI ShellAboutA(HWND,LPCSTR,LPCSTR,HICON);
BOOL        WINAPI ShellAboutW(HWND,LPCWSTR,LPCWSTR,HICON);
#define     ShellAbout WINELIB_NAME_AW(ShellAbout)
int         WINAPIV ShellMessageBoxA(HINSTANCE,HWND,LPCSTR,LPCSTR,UINT,...);
int         WINAPIV ShellMessageBoxW(HINSTANCE,HWND,LPCWSTR,LPCWSTR,UINT,...);
#define     ShellMessageBox WINELIB_NAME_AW(ShellMessageBox)
DWORD       WINAPI DoEnvironmentSubstA(LPSTR, UINT);
DWORD       WINAPI DoEnvironmentSubstW(LPWSTR, UINT);
#define     DoEnvironmentSubst WINELIB_NAME_AW(DoEnvironmentSubst)

HRESULT     WINAPI SHEnumerateUnreadMailAccountsA(HKEY,DWORD,LPSTR,INT);
HRESULT     WINAPI SHEnumerateUnreadMailAccountsW(HKEY,DWORD,LPWSTR,INT);
#define     SHEnumerateUnreadMailAccounts WINELIB_NAME_AW(SHEnumerateUnreadMailAccounts)

HRESULT     WINAPI SHGetPropertyStoreForWindow(HWND,REFIID,void **);

#ifdef __cplusplus
} /* extern "C" */
#endif /* defined(__cplusplus) */

#ifndef _WIN64
#include <poppack.h>
#endif

#endif /* __WINE_SHELLAPI_H */
