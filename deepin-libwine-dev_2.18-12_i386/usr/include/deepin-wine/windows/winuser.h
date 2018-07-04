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

#ifndef _WINUSER_
#define _WINUSER_

#if !defined(_USER32_)
#define WINUSERAPI DECLSPEC_IMPORT
#else
#define WINUSERAPI
#endif

#ifndef RC_INVOKED
#include <stdarg.h>
#endif
#include <winuser.rh>


#ifdef __cplusplus
extern "C" {
#endif

/* Define a bunch of callback types */

#if defined(STRICT)
typedef INT_PTR (CALLBACK *DLGPROC)(HWND,UINT,WPARAM,LPARAM);
typedef BOOL    (CALLBACK *DRAWSTATEPROC)(HDC,LPARAM,WPARAM,int,int);
typedef INT     (CALLBACK *EDITWORDBREAKPROCA)(LPSTR,INT,INT,INT);
typedef INT     (CALLBACK *EDITWORDBREAKPROCW)(LPWSTR,INT,INT,INT);
typedef BOOL    (CALLBACK *GRAYSTRINGPROC)(HDC,LPARAM,INT);
typedef LRESULT (CALLBACK *HOOKPROC)(INT,WPARAM,LPARAM);
typedef BOOL    (CALLBACK *NAMEENUMPROCA)(LPSTR,LPARAM);
typedef BOOL    (CALLBACK *NAMEENUMPROCW)(LPWSTR,LPARAM);
typedef BOOL    (CALLBACK *PROPENUMPROCA)(HWND,LPCSTR,HANDLE);
typedef BOOL    (CALLBACK *PROPENUMPROCW)(HWND,LPCWSTR,HANDLE);
typedef BOOL    (CALLBACK *PROPENUMPROCEXA)(HWND,LPSTR,HANDLE,ULONG_PTR);
typedef BOOL    (CALLBACK *PROPENUMPROCEXW)(HWND,LPWSTR,HANDLE,ULONG_PTR);
typedef VOID    (CALLBACK *SENDASYNCPROC)(HWND,UINT,ULONG_PTR,LRESULT);
typedef VOID    (CALLBACK *TIMERPROC)(HWND,UINT,UINT_PTR,DWORD);
typedef VOID    (CALLBACK *WINEVENTPROC)(HWINEVENTHOOK,DWORD,HWND,LONG,LONG,
                                         DWORD,DWORD);
typedef BOOL    (CALLBACK *WNDENUMPROC)(HWND,LPARAM);

#else
typedef FARPROC DLGPROC;
typedef FARPROC DRAWSTATEPROC;
typedef FARPROC EDITWORDBREAKPROCA;
typedef FARPROC EDITWORDBREAKPROCW;
typedef FARPROC GRAYSTRINGPROC;
typedef FARPROC HOOKPROC;
typedef FARPROC NAMEENUMPROCA;
typedef FARPROC NAMEENUMPROCW;
typedef FARPROC PROPENUMPROCA;
typedef FARPROC PROPENUMPROCW;
typedef FARPROC PROPENUMPROCEXA;
typedef FARPROC PROPENUMPROCEXW;
typedef FARPROC SENDASYNCPROC;
typedef FARPROC TIMERPROC;
typedef FARPROC WINEVENTPROC;
typedef FARPROC WNDENUMPROC;
#endif /* STRICT */

typedef NAMEENUMPROCA WINSTAENUMPROCA;
typedef NAMEENUMPROCA DESKTOPENUMPROCA;
typedef NAMEENUMPROCW WINSTAENUMPROCW;
typedef NAMEENUMPROCW DESKTOPENUMPROCW;

typedef LRESULT (CALLBACK *WNDPROC)(HWND,UINT,WPARAM,LPARAM);

DECL_WINELIB_TYPE_AW(DESKTOPENUMPROC)
DECL_WINELIB_TYPE_AW(EDITWORDBREAKPROC)
DECL_WINELIB_TYPE_AW(NAMEENUMPROC)
DECL_WINELIB_TYPE_AW(PROPENUMPROC)
DECL_WINELIB_TYPE_AW(PROPENUMPROCEX)
DECL_WINELIB_TYPE_AW(WINSTAENUMPROC)


typedef HANDLE HDWP;
typedef void* HPOWERNOTIFY;

#define UOI_FLAGS       1
#define UOI_NAME        2
#define UOI_TYPE        3
#define UOI_USER_SID    4

#define WSF_VISIBLE     1
#define DF_ALLOWOTHERACCOUNTHOOK  1

typedef struct tagUSEROBJECTFLAGS {
    BOOL fInherit;
    BOOL fReserved;
    DWORD dwFlags;
} USEROBJECTFLAGS, *PUSEROBJECTFLAGS;

typedef struct tagBSMINFO {
    UINT  cbSize;
    HDESK hdesk;
    HWND  hwnd;
    LUID  luid;
} BSMINFO, *PBSMINFO;

/* Window stations */
#define WINSTA_ENUMDESKTOPS         0x0001
#define WINSTA_READATTRIBUTES       0x0002
#define WINSTA_ACCESSCLIPBOARD      0x0004
#define WINSTA_CREATEDESKTOP        0x0008
#define WINSTA_WRITEATTRIBUTES      0x0010
#define WINSTA_ACCESSGLOBALATOMS    0x0020
#define WINSTA_EXITWINDOWS          0x0040
#define WINSTA_ENUMERATE            0x0100
#define WINSTA_READSCREEN           0x0200
#define WINSTA_ALL_ACCESS           0x037f

/* Desktops */
#define DESKTOP_READOBJECTS         0x0001
#define DESKTOP_CREATEWINDOW        0x0002
#define DESKTOP_CREATEMENU          0x0004
#define DESKTOP_HOOKCONTROL         0x0008
#define DESKTOP_JOURNALRECORD       0x0010
#define DESKTOP_JOURNALPLAYBACK     0x0020
#define DESKTOP_ENUMERATE           0x0040
#define DESKTOP_WRITEOBJECTS        0x0080
#define DESKTOP_SWITCHDESKTOP       0x0100


/* flags for FILTERKEYS dwFlags field */
#define FKF_AVAILABLE       0x00000002
#define FKF_CLICKON         0x00000040
#define FKF_FILTERKEYSON    0x00000001
#define FKF_HOTKEYACTIVE    0x00000004
#define FKF_HOTKEYSOUND     0x00000010
#define FKF_CONFIRMHOTKEY   0x00000008
#define FKF_INDICATOR       0x00000020

typedef struct tagFILTERKEYS
{
    UINT   cbSize;
    DWORD  dwFlags;
    DWORD  iWaitMSec;
    DWORD  iDelayMSec;
    DWORD  iRepeatMSec;
    DWORD  iBounceMSec;
} FILTERKEYS, *LPFILTERKEYS;

/* flags for TOGGLEKEYS dwFlags field */
#define TKF_AVAILABLE       0x00000002
#define TKF_CONFIRMHOTKEY   0x00000008
#define TKF_HOTKEYACTIVE    0x00000004
#define TKF_HOTKEYSOUND     0x00000010
#define TKF_TOGGLEKEYSON    0x00000001

typedef struct tagTOGGLEKEYS
{
    DWORD   cbSize;
    DWORD   dwFlags;
} TOGGLEKEYS, *LPTOGGLEKEYS;

/* flags for MOUSEKEYS dwFlags field */
#define MKF_AVAILABLE       0x00000002
#define MKF_CONFIRMHOTKEY   0x00000008
#define MKF_HOTKEYACTIVE    0x00000004
#define MKF_HOTKEYSOUND     0x00000010
#define MKF_INDICATOR       0x00000020
#define MKF_MOUSEKEYSON     0x00000001
#define MKF_MODIFIERS       0x00000040
#define MKF_REPLACENUMBERS  0x00000080

typedef struct tagMOUSEKEYS
{
    UINT    cbSize;
    DWORD   dwFlags;
    DWORD   iMaxSpeed;
    DWORD   iTimeToMaxSpeed;
    DWORD   iCtrlSpeed;
    DWORD   dwReserved1;
    DWORD   dwReserved2;
} MOUSEKEYS, *LPMOUSEKEYS;

/* struct and defines for GetMouseMovePointsEx */
#define GMMP_USE_DISPLAY_POINTS 1
#define GMMP_USE_HIGH_RESOLUTION_POINTS 2

typedef struct tagMOUSEMOVEPOINT {
    int x;
    int y;
    DWORD time;
    ULONG_PTR dwExtraInfo;
} MOUSEMOVEPOINT,*PMOUSEMOVEPOINT,*LPMOUSEMOVEPOINT;

/* flags for STICKYKEYS dwFlags field */
#define SKF_AUDIBLEFEEDBACK 0x00000040
#define SKF_AVAILABLE       0x00000002
#define SKF_CONFIRMHOTKEY   0x00000008
#define SKF_HOTKEYACTIVE    0x00000004
#define SKF_HOTKEYSOUND     0x00000010
#define SKF_INDICATOR       0x00000020
#define SKF_STICKYKEYSON    0x00000001
#define SKF_TRISTATE        0x00000080
#define SKF_TWOKEYSOFF      0x00000100

typedef struct tagSTICKYKEYS
{
    DWORD   cbSize;
    DWORD   dwFlags;
} STICKYKEYS, *LPSTICKYKEYS;

/* flags for ACCESSTIMEOUT dwFlags field */
#define ATF_ONOFFFEEDBACK   0x00000002
#define ATF_AVAILABLE       0x00000004
#define ATF_TIMEOUTON       0x00000001

typedef struct tagACCESSTIMEOUT
{
    UINT    cbSize;
    DWORD   dwFlags;
    DWORD   iTimeOutMSec;
} ACCESSTIMEOUT, *LPACCESSTIMEOUT;

/* flags for SERIALKEYS dwFlags field */
#define SERKF_ACTIVE        0x00000008
#define SERKF_AVAILABLE     0x00000002
#define SERKF_INDICATOR     0x00000004
#define SERKF_SERIALKEYSON  0x00000001

typedef struct tagSERIALKEYSA
{
    UINT  cbSize;
    DWORD  dwFlags;
    LPSTR  lpszActivePort;
    LPSTR  lpszPort;
    UINT  iBaudRate;
    UINT  iPortState;
    UINT  iActive;
} SERIALKEYSA, *LPSERIALKEYSA;

typedef struct tagSERIALKEYSW {
    UINT  cbSize;
    DWORD   dwFlags;
    LPWSTR  lpszActivePort;
    LPWSTR  lpszPort;
    UINT   iBaudRate;
    UINT   iPortState;
    UINT   iActive;
} SERIALKEYSW,*LPSERIALKEYSW;

DECL_WINELIB_TYPE_AW(SERIALKEYS)
DECL_WINELIB_TYPE_AW(LPSERIALKEYS)

/* flags for SOUNDSENTRY dwFlags field */
#define SSF_AVAILABLE       0x00000002
#define SSF_SOUNDSENTRYON   0x00000001

#define SSTF_BORDER         0x00000002
#define SSTF_CHARS          0x00000001
#define SSTF_DISPLAY        0x00000003
#define SSTF_NONE           0x00000000

#define SSGF_DISPLAY        0x00000003
#define SSGF_NONE           0x00000000

#define SSWF_DISPLAY        0x00000003
#define SSWF_NONE           0x00000000
#define SSWF_TITLE          0x00000001
#define SSWF_WINDOW         0x00000002

typedef struct tagSOUNDSENTRYA
{
    UINT  cbSize;
    DWORD  dwFlags;
    DWORD  iFSTextEffect;
    DWORD  iFSTextEffectMSec;
    DWORD  iFSTextEffectColorBits;
    DWORD  iFSGrafEffect;
    DWORD  iFSGrafEffectMSec;
    DWORD  iFSGrafEffectColor;
    DWORD  iWindowsEffect;
    DWORD  iWindowsEffectMSec;
    LPSTR  lpszWindowsEffectDLL;
    DWORD  iWindowsEffectOrdinal;
} SOUNDSENTRYA, *LPSOUNDSENTRYA;

typedef struct tagSOUNDSENTRYW
{
    UINT  cbSize;
    DWORD  dwFlags;
    DWORD  iFSTextEffect;
    DWORD  iFSTextEffectMSec;
    DWORD  iFSTextEffectColorBits;
    DWORD  iFSGrafEffect;
    DWORD  iFSGrafEffectMSec;
    DWORD  iFSGrafEffectColor;
    DWORD  iWindowsEffect;
    DWORD  iWindowsEffectMSec;
    LPWSTR  lpszWindowsEffectDLL;
    DWORD  iWindowsEffectOrdinal;
} SOUNDSENTRYW, *LPSOUNDSENTRYW;

DECL_WINELIB_TYPE_AW(SOUNDSENTRY)
DECL_WINELIB_TYPE_AW(LPSOUNDSENTRY)

/* flags for HIGHCONTRAST dwFlags field */
#define HCF_HIGHCONTRASTON  0x00000001
#define HCF_AVAILABLE       0x00000002
#define HCF_HOTKEYACTIVE    0x00000004
#define HCF_CONFIRMHOTKEY   0x00000008
#define HCF_HOTKEYSOUND     0x00000010
#define HCF_INDICATOR       0x00000020
#define HCF_HOTKEYAVAILABLE 0x00000040

typedef struct tagHIGHCONTRASTA
{
    UINT  cbSize;
    DWORD   dwFlags;
    LPSTR   lpszDefaultScheme;
} HIGHCONTRASTA, *LPHIGHCONTRASTA;

typedef struct tagHIGHCONTRASTW
{
    UINT  cbSize;
    DWORD   dwFlags;
    LPWSTR  lpszDefaultScheme;
} HIGHCONTRASTW, *LPHIGHCONTRASTW;

DECL_WINELIB_TYPE_AW(HIGHCONTRAST)
DECL_WINELIB_TYPE_AW(LPHIGHCONTRAST)

typedef struct tagEVENTMSG
{
    UINT  message;
    UINT  paramL;
    UINT  paramH;
    DWORD   time;
    HWND  hwnd;
} EVENTMSG, *PEVENTMSG, *LPEVENTMSG;

/* WH_KEYBOARD_LL structure */
typedef struct tagKBDLLHOOKSTRUCT
{
    DWORD   vkCode;
    DWORD   scanCode;
    DWORD   flags;
    DWORD   time;
    ULONG_PTR dwExtraInfo;
} KBDLLHOOKSTRUCT, *LPKBDLLHOOKSTRUCT, *PKBDLLHOOKSTRUCT;

#define LLKHF_EXTENDED   (KF_EXTENDED >> 8)
#define LLKHF_INJECTED   0x00000010
#define LLKHF_ALTDOWN    (KF_ALTDOWN >> 8)
#define LLKHF_UP         (KF_UP >> 8)

/* WH_MOUSE_LL structure */
typedef struct tagMSLLHOOKSTRUCT
{
    POINT   pt;
    DWORD   mouseData;
    DWORD   flags;
    DWORD   time;
    ULONG_PTR dwExtraInfo;
} MSLLHOOKSTRUCT, *LPMSLLHOOKSTRUCT, *PMSLLHOOKSTRUCT;

#define LLMHF_INJECTED  0x00000001

    /* Mouse hook structure */

typedef struct
{
    POINT pt;
    HWND  hwnd;
    UINT  wHitTestCode;
    ULONG_PTR dwExtraInfo;
} MOUSEHOOKSTRUCT, *PMOUSEHOOKSTRUCT, *LPMOUSEHOOKSTRUCT;

typedef struct
{
    struct { /* MOUSEHOOKSTRUCT */
        POINT pt;
        HWND  hwnd;
        UINT  wHitTestCode;
        ULONG_PTR dwExtraInfo;
    } DUMMYSTRUCTNAME;
    DWORD mouseData;
} MOUSEHOOKSTRUCTEX, *PMOUSEHOOKSTRUCTEX, *LPMOUSEHOOKSTRUCTEX;


    /* Hardware hook structure */

typedef struct
{
    HWND    hwnd;
    UINT    message;
    WPARAM  wParam;
    LPARAM  lParam;
} HARDWAREHOOKSTRUCT, *PHARDWAREHOOKSTRUCT, *LPHARDWAREHOOKSTRUCT;


  /* Debug hook structure */

typedef struct tagDEBUGHOOKINFO
{
    DWORD       idThread;
    DWORD       idThreadInstaller;
    LPARAM      lParam;
    WPARAM    wParam;
    INT       code;
} DEBUGHOOKINFO, *PDEBUGHOOKINFO, *LPDEBUGHOOKINFO;

#define HKL_PREV   0
#define HKL_NEXT   1

#define KLF_ACTIVATE       0x00000001
#define KLF_SUBSTITUTE_OK  0x00000002
#define KLF_UNLOADPREVIOUS 0x00000004
#define KLF_REORDER        0x00000008
#define KLF_REPLACELANG    0x00000010
#define KLF_NOTELLSHELL    0x00000080
#define KLF_SETFORPROCESS  0x00000100
#define KLF_SHIFTLOCK      0x00010000
#define KLF_RESET          0x40000000

#define KL_NAMELENGTH      9

typedef struct tagMOUSEINPUT
{
    LONG    dx;
    LONG    dy;
    DWORD   mouseData;
    DWORD   dwFlags;
    DWORD   time;
    ULONG_PTR dwExtraInfo;
} MOUSEINPUT, *PMOUSEINPUT, *LPMOUSEINPUT;

typedef struct tagKEYBDINPUT
{
    WORD    wVk;
    WORD    wScan;
    DWORD   dwFlags;
    DWORD   time;
    ULONG_PTR dwExtraInfo;
} KEYBDINPUT, *PKEYBDINPUT, *LPKEYBDINPUT;

typedef struct tagHARDWAREINPUT
{
    DWORD   uMsg;
    WORD    wParamL;
    WORD    wParamH;
} HARDWAREINPUT, *PHARDWAREINPUT, *LPHARDWAREINPUT;

#define INPUT_MOUSE     0
#define INPUT_KEYBOARD  1
#define INPUT_HARDWARE  2

typedef struct tagINPUT
{
    DWORD type;
    union
    {
        MOUSEINPUT      mi;
        KEYBDINPUT      ki;
        HARDWAREINPUT   hi;
    } DUMMYUNIONNAME;
} INPUT, *PINPUT, *LPINPUT;

DECLARE_HANDLE(HRAWINPUT);

typedef struct tagRAWINPUTDEVICELIST
{
    HANDLE hDevice;
    DWORD dwType;
} RAWINPUTDEVICELIST, *PRAWINPUTDEVICELIST;

typedef struct tagRAWHID {
    DWORD dwSizeHid;
    DWORD dwCount;
    BYTE bRawData;
} RAWHID, *LPRAWHID;

typedef struct tagRAWKEYBOARD {
    USHORT MakeCode;
    USHORT Flags;
    USHORT Reserved;
    USHORT VKey;
    UINT Message;
    ULONG ExtraInformation;
} RAWKEYBOARD, *PRAWKEYBOARD, *LPRAWKEYBOARD;

typedef struct tagRAWMOUSE {
    USHORT usFlags;
    union {
        ULONG ulButtons;
        struct {
            USHORT usButtonFlags;
            USHORT usButtonData;
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;
    ULONG ulRawButtons;
    LONG  lLastX;
    LONG  lLastY;
    ULONG ulExtraInformation;
} RAWMOUSE, *PRAWMOUSE, *LPRAWMOUSE;

typedef struct tagRAWINPUTHEADER {
    DWORD dwType;
    DWORD dwSize;
    HANDLE hDevice;
    WPARAM wParam;
} RAWINPUTHEADER, *PRAWINPUTHEADER;

typedef struct tagRAWINPUT {
    RAWINPUTHEADER header;
    union {
        RAWMOUSE    mouse;
        RAWKEYBOARD keyboard;
        RAWHID      hid;
    } data;
} RAWINPUT, *PRAWINPUT, *LPRAWINPUT;

typedef struct tagRAWINPUTDEVICE {
    USHORT usUsagePage;
    USHORT usUsage;
    DWORD dwFlags;
    HWND hwndTarget;
} RAWINPUTDEVICE, *PRAWINPUTDEVICE, *LPRAWINPUTDEVICE;

typedef struct tagRID_DEVICE_INFO_MOUSE {
    DWORD dwId;
    DWORD dwNumberOfButtons;
    DWORD dwSampleRate;
    BOOL fHasHorizontalWheel;
} RID_DEVICE_INFO_MOUSE, *PRID_DEVICE_INFO_MOUSE;

typedef struct tagRID_DEVICE_INFO_KEYBOARD {
    DWORD dwType;
    DWORD dwSubType;
    DWORD dwKeyboardMode;
    DWORD dwNumberOfFunctionKeys;
    DWORD dwNumberOfIndicators;
    DWORD dwNumberOfKeysTotal;
} RID_DEVICE_INFO_KEYBOARD, *PRID_DEVICE_INFO_KEYBOARD;

typedef struct tagRID_DEVICE_INFO_HID {
    DWORD dwVendorId;
    DWORD dwProductId;
    DWORD dwVersionNumber;
    USHORT usUsagePage;
    USHORT usUsage;
} RID_DEVICE_INFO_HID, *PRID_DEVICE_INFO_HID;

typedef struct tagRID_DEVICE_INFO {
    DWORD    cbSize;
    DWORD    dwType;
    union {
        RID_DEVICE_INFO_MOUSE     mouse;
        RID_DEVICE_INFO_KEYBOARD  keyboard;
        RID_DEVICE_INFO_HID       hid;
    } DUMMYUNIONNAME;
} RID_DEVICE_INFO, *PRID_DEVICE_INFO, *LPRID_DEVICE_INFO;

#define GET_RAWINPUT_CODE_WPARAM(wParam) ((wParam) & 0xff)

#define RIM_INPUT     0
#define RIM_INPUTSINK 1

#define RIM_TYPEMOUSE    0
#define RIM_TYPEKEYBOARD 1
#define RIM_TYPEHID      2

#define RI_MOUSE_LEFT_BUTTON_DOWN   0x0001
#define RI_MOUSE_LEFT_BUTTON_UP     0x0002
#define RI_MOUSE_RIGHT_BUTTON_DOWN  0x0004
#define RI_MOUSE_RIGHT_BUTTON_UP    0x0008
#define RI_MOUSE_MIDDLE_BUTTON_DOWN 0x0010
#define RI_MOUSE_MIDDLE_BUTTON_UP   0x0020

#define RI_MOUSE_BUTTON_1_DOWN RI_MOUSE_LEFT_BUTTON_DOWN
#define RI_MOUSE_BUTTON_1_UP   RI_MOUSE_LEFT_BUTTON_UP
#define RI_MOUSE_BUTTON_2_DOWN RI_MOUSE_RIGHT_BUTTON_DOWN
#define RI_MOUSE_BUTTON_2_UP   RI_MOUSE_RIGHT_BUTTON_UP
#define RI_MOUSE_BUTTON_3_DOWN RI_MOUSE_MIDDLE_BUTTON_DOWN
#define RI_MOUSE_BUTTON_3_UP   RI_MOUSE_MIDDLE_BUTTON_UP

#define RI_MOUSE_BUTTON_4_DOWN    0x0040
#define RI_MOUSE_BUTTON_4_UP      0x0080
#define RI_MOUSE_BUTTON_5_DOWN    0x0100
#define RI_MOUSE_BUTTON_5_UP      0x0200
#define RI_MOUSE_WHEEL            0x0400
#define RI_MOUSE_HORIZONTAL_WHEEL 0x0800

#define MOUSE_MOVE_RELATIVE      0x00
#define MOUSE_MOVE_ABSOLUTE      0x01
#define MOUSE_VIRTUAL_DESKTOP    0x02
#define MOUSE_ATTRIBUTES_CHANGED 0x04
#define MOUSE_MOVE_NOCOALESCE    0x08

#define KEYBOARD_OVERRUN_MAKE_CODE 0xFF

#define RI_KEY_MAKE            0x00
#define RI_KEY_BREAK           0x01
#define RI_KEY_E0              0x02
#define RI_KEY_E1              0x04
#define RI_KEY_TERMSRV_SET_LED 0x08
#define RI_KEY_TERMSRV_SHADOW  0x10

#define RAWINPUT_ALIGN(x) (((x) + sizeof(DWORD_PTR) - 1) & ~(sizeof(DWORD_PTR) - 1))
#define NEXTRAWINPUTBLOCK(ptr) ((PRAWINPUT)RAWINPUT_ALIGN((ULONG_PTR)((PBYTE)(ptr) + (ptr)->header.dwSize)))

#define RID_INPUT  0x10000003
#define RID_HEADER 0x10000005

#define RIDI_PREPARSEDDATA 0x20000005
#define RIDI_DEVICENAME    0x20000007
#define RIDI_DEVICEINFO    0x2000000b

#define RIDEV_REMOVE       0x00000001
#define RIDEV_EXCLUDE      0x00000010
#define RIDEV_PAGEONLY     0x00000020
#define RIDEV_NOLEGACY     0x00000030
#define RIDEV_INPUTSINK    0x00000100
#define RIDEV_CAPTUREMOUSE 0x00000200
#define RIDEV_NOHOTKEYS    0x00000200
#define RIDEV_APPKEYS      0x00000400
#define RIDEV_EXINPUTSINK  0x00001000
#define RIDEV_DEVNOTIFY    0x00002000
#define RIDEV_EXMODEMASK   0x000000F0

#define RIDEV_EXMODE(mode) ((mode) & RIDEV_EXMODEMASK)

typedef struct tagGESTURECONFIG {
    DWORD dwID;
    DWORD dwWant;
    DWORD dwBlock;
} GESTURECONFIG, *PGESTURECONFIG;

#define GIDC_ARRIVAL 1
#define GIDC_REMOVAL 2

#if (_WIN32_WINNT >= 0x0601)
#define GET_DEVICE_CHANGE_WPARAM(wParam) (LOWORD(wParam))
#elif (_WIN32_WINNT >= 0x0501)
#define GET_DEVICE_CHANGE_LPARAM(lParam) (LOWORD(lParam))
#endif

typedef struct tagGUITHREADINFO
{
    DWORD   cbSize;
    DWORD   flags;
    HWND    hwndActive;
    HWND    hwndFocus;
    HWND    hwndCapture;
    HWND    hwndMenuOwner;
    HWND    hwndMoveSize;
    HWND    hwndCaret;
    RECT    rcCaret;
} GUITHREADINFO, *PGUITHREADINFO, *LPGUITHREADINFO;

#define GUI_CARETBLINKING   0x00000001
#define GUI_INMOVESIZE      0x00000002
#define GUI_INMENUMODE      0x00000004
#define GUI_SYSTEMMENUMODE  0x00000008
#define GUI_POPUPMENUMODE   0x00000010
#define GUI_16BITTASK       0x00000020


/***** Dialogs *****/

/* Gcc on Solaris has a version of this that we don't care about */
#undef FSHIFT

#define	FVIRTKEY	TRUE          /* Assumed to be == TRUE */
#define	FNOINVERT	0x02
#define	FSHIFT		0x04
#define	FCONTROL	0x08
#define	FALT		0x10


typedef struct tagANIMATIONINFO
{
       UINT          cbSize;
       INT           iMinAnimate;
} ANIMATIONINFO, *LPANIMATIONINFO;

typedef struct tagNMHDR
{
    HWND  hwndFrom;
    UINT_PTR idFrom;
    UINT  code;
} NMHDR, *LPNMHDR;

typedef struct tagDRAWTEXTPARAMS
{
	UINT	cbSize;
	INT	iTabLength;
	INT	iLeftMargin;
	INT	iRightMargin;
	UINT	uiLengthDrawn;
} DRAWTEXTPARAMS,*LPDRAWTEXTPARAMS;

typedef struct
{
  LPARAM        lParam;
  WPARAM      wParam;
  UINT        message;
  HWND        hwnd;
} CWPSTRUCT, *PCWPSTRUCT, *LPCWPSTRUCT;

typedef struct
{
  LRESULT       lResult;
  LPARAM        lParam;
  WPARAM      wParam;
  DWORD         message;
  HWND        hwnd;
} CWPRETSTRUCT, *PCWPRETSTRUCT, *LPCWPRETSTRUCT;

typedef struct tagWINDOWPLACEMENT
{
    UINT   length;
    UINT   flags;
    UINT   showCmd;
    POINT  ptMinPosition;
    POINT  ptMaxPosition;
    RECT   rcNormalPosition;
} WINDOWPLACEMENT, *PWINDOWPLACEMENT, *LPWINDOWPLACEMENT;


  /* WINDOWPLACEMENT flags */
#define WPF_SETMINPOSITION      0x0001
#define WPF_RESTORETOMAXIMIZED  0x0002

/***** Dialogs *****/

#define IS_INTRESOURCE(x)   (((ULONG_PTR)(x) >> 16) == 0)
#define MAKEINTRESOURCEA(i) (LPSTR)((ULONG_PTR)((WORD)(i)))
#define MAKEINTRESOURCEW(i) (LPWSTR)((ULONG_PTR)((WORD)(i)))

#ifndef RC_INVOKED
# ifdef WINE_NO_UNICODE_MACROS /* force using a cast */
#  define MAKEINTRESOURCE(i) ((ULONG_PTR)((WORD)(i)))
# else
#  define MAKEINTRESOURCE WINELIB_NAME_AW(MAKEINTRESOURCE)
# endif
#endif

/* Predefined resource types */
#define RT_CURSOR         MAKEINTRESOURCE(1)
#define RT_BITMAP         MAKEINTRESOURCE(2)
#define RT_ICON           MAKEINTRESOURCE(3)
#define RT_MENU           MAKEINTRESOURCE(4)
#define RT_DIALOG         MAKEINTRESOURCE(5)
#define RT_STRING         MAKEINTRESOURCE(6)
#define RT_FONTDIR        MAKEINTRESOURCE(7)
#define RT_FONT           MAKEINTRESOURCE(8)
#define RT_ACCELERATOR    MAKEINTRESOURCE(9)
#define RT_RCDATA         MAKEINTRESOURCE(10)
#define RT_MESSAGETABLE   MAKEINTRESOURCE(11)
#define RT_GROUP_CURSOR   MAKEINTRESOURCE(12)
#define RT_GROUP_ICON     MAKEINTRESOURCE(14)
#define RT_VERSION        MAKEINTRESOURCE(16)
#define RT_DLGINCLUDE     MAKEINTRESOURCE(17)
#define RT_PLUGPLAY       MAKEINTRESOURCE(19)
#define RT_VXD            MAKEINTRESOURCE(20)
#define RT_ANICURSOR      MAKEINTRESOURCE(21)
#define RT_ANIICON        MAKEINTRESOURCE(22)
#define RT_HTML           MAKEINTRESOURCE(23)

#ifdef RC_INVOKED
#define RT_MANIFEST                                        24
#define CREATEPROCESS_MANIFEST_RESOURCE_ID                 1
#define ISOLATIONAWARE_MANIFEST_RESOURCE_ID                2
#define ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID 3
#define MINIMUM_RESERVED_MANIFEST_RESOURCE_ID              1
#define MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID              16
#else
#define RT_MANIFEST                                        MAKEINTRESOURCE(24)
#define CREATEPROCESS_MANIFEST_RESOURCE_ID                 MAKEINTRESOURCE(1)
#define ISOLATIONAWARE_MANIFEST_RESOURCE_ID                MAKEINTRESOURCE(2)
#define ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(3)
#define MINIMUM_RESERVED_MANIFEST_RESOURCE_ID              MAKEINTRESOURCE(1)
#define MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID              MAKEINTRESOURCE(16)
#endif

  /* cbWndExtra bytes for dialog class */
#define DLGWINDOWEXTRA      30


  /* Dialog messages */
#define DM_GETDEFID         (WM_USER+0)
#define DM_SETDEFID         (WM_USER+1)
#define DM_REPOSITION       (WM_USER+2)

#define DC_HASDEFID         0x534b

/* Bit flags for DRAWITEMSTRUCT.CtlType */
#define ODT_MENU        1
#define ODT_LISTBOX     2
#define ODT_COMBOBOX    3
#define ODT_BUTTON      4
#define ODT_STATIC      5

/* Bit flags for DRAWITEMSTRUCT.itemAction */
#define ODA_DRAWENTIRE 0x1
#define ODA_SELECT     0x2
#define ODA_FOCUS      0x4

/* Bit flags for DRAWITEMSTRUCT.itemState */
#define ODS_SELECTED     0x0001 /* Selected */
#define ODS_GRAYED       0x0002 /* Grayed (Menus only) */
#define ODS_DISABLED     0x0004 /* Disabled */
#define ODS_CHECKED      0x0008 /* Checked (Menus only) */
#define ODS_FOCUS        0x0010 /* Has focus */
#define ODS_DEFAULT      0x0020 /* Default */
#define ODS_HOTLIGHT     0x0040 /* Highlighted when under mouse */
#define ODS_INACTIVE     0x0080 /* Inactive */
#define ODS_NOACCEL      0x0100 /* No keyboard accelerator */
#define ODS_NOFOCUSRECT  0x0200 /* No focus rectangle */
#define ODS_COMBOBOXEDIT 0x1000 /* Edit of a combo box */

#ifndef NOCOLOR

#define COLOR_SCROLLBAR		    0
#define COLOR_BACKGROUND	    1
#define COLOR_ACTIVECAPTION	    2
#define COLOR_INACTIVECAPTION	    3
#define COLOR_MENU		    4
#define COLOR_WINDOW		    5
#define COLOR_WINDOWFRAME	    6
#define COLOR_MENUTEXT		    7
#define COLOR_WINDOWTEXT	    8
#define COLOR_CAPTIONTEXT  	    9
#define COLOR_ACTIVEBORDER	   10
#define COLOR_INACTIVEBORDER	   11
#define COLOR_APPWORKSPACE	   12
#define COLOR_HIGHLIGHT		   13
#define COLOR_HIGHLIGHTTEXT	   14
#define COLOR_BTNFACE              15
#define COLOR_BTNSHADOW            16
#define COLOR_GRAYTEXT             17
#define COLOR_BTNTEXT		   18
#define COLOR_INACTIVECAPTIONTEXT  19
#define COLOR_BTNHIGHLIGHT         20
/* win95 colors */
#define COLOR_3DDKSHADOW           21
#define COLOR_3DLIGHT              22
#define COLOR_INFOTEXT             23
#define COLOR_INFOBK               24
#define COLOR_DESKTOP              COLOR_BACKGROUND
#define COLOR_3DFACE               COLOR_BTNFACE
#define COLOR_3DSHADOW             COLOR_BTNSHADOW
#define COLOR_3DHIGHLIGHT          COLOR_BTNHIGHLIGHT
#define COLOR_3DHILIGHT            COLOR_BTNHIGHLIGHT
#define COLOR_BTNHILIGHT           COLOR_BTNHIGHLIGHT
/* win98 colors */
#define COLOR_ALTERNATEBTNFACE         25  /* undocumented, constant name unknown */
#define COLOR_HOTLIGHT                 26
#define COLOR_GRADIENTACTIVECAPTION    27
#define COLOR_GRADIENTINACTIVECAPTION  28
/* win2k/xp colors */
#define COLOR_MENUHILIGHT              29
#define COLOR_MENUBAR                  30

  /* WM_CTLCOLOR values */
#define CTLCOLOR_MSGBOX             0
#define CTLCOLOR_EDIT               1
#define CTLCOLOR_LISTBOX            2
#define CTLCOLOR_BTN                3
#define CTLCOLOR_DLG                4
#define CTLCOLOR_SCROLLBAR          5
#define CTLCOLOR_STATIC             6

WINUSERAPI COLORREF WINAPI GetSysColor(INT);
WINUSERAPI BOOL     WINAPI SetSysColors(INT,const INT*,const COLORREF*);

#endif /* NOCOLOR */

/* IMESTATUS type */
#define EMSIS_COMPOSITIONSTRING 1

/* IMESTATUS type specific data */
#define EIMES_GETCOMPSTRATONCE         0x0001
#define EIMES_CANCELCOMPSTRINFOCUS     0x0002
#define EIMES_COMPLETECOMPSTRKILLFOCUS 0x0004

/* EDITWORDBREAKPROC code values */
#define WB_LEFT         0
#define WB_RIGHT        1
#define WB_ISDELIMITER  2

/* Edit control notification codes */
#define EN_SETFOCUS     0x0100
#define EN_KILLFOCUS    0x0200
#define EN_CHANGE       0x0300
#define EN_UPDATE       0x0400
#define EN_ERRSPACE     0x0500
#define EN_MAXTEXT      0x0501
#define EN_HSCROLL      0x0601
#define EN_VSCROLL      0x0602

/* New since win95 : EM_SETMARGIN parameters */
#define EC_LEFTMARGIN	0x0001
#define EC_RIGHTMARGIN	0x0002
#define EC_USEFONTINFO	0xffff


  /* GetSystemMetrics() codes */
#define SM_CXSCREEN	       0
#define SM_CYSCREEN            1
#define SM_CXVSCROLL           2
#define SM_CYHSCROLL	       3
#define SM_CYCAPTION	       4
#define SM_CXBORDER	       5
#define SM_CYBORDER	       6
#define SM_CXDLGFRAME	       7
#define SM_CYDLGFRAME	       8
#define SM_CYVTHUMB	       9
#define SM_CXHTHUMB	      10
#define SM_CXICON	      11
#define SM_CYICON	      12
#define SM_CXCURSOR	      13
#define SM_CYCURSOR	      14
#define SM_CYMENU	      15
#define SM_CXFULLSCREEN       16
#define SM_CYFULLSCREEN       17
#define SM_CYKANJIWINDOW      18
#define SM_MOUSEPRESENT       19
#define SM_CYVSCROLL	      20
#define SM_CXHSCROLL	      21
#define SM_DEBUG	      22
#define SM_SWAPBUTTON	      23
#define SM_RESERVED1	      24
#define SM_RESERVED2	      25
#define SM_RESERVED3	      26
#define SM_RESERVED4	      27
#define SM_CXMIN	      28
#define SM_CYMIN	      29
#define SM_CXSIZE	      30
#define SM_CYSIZE	      31
#define SM_CXFRAME	      32
#define SM_CYFRAME	      33
#define SM_CXMINTRACK	      34
#define SM_CYMINTRACK	      35
#define SM_CXDOUBLECLK        36
#define SM_CYDOUBLECLK        37
#define SM_CXICONSPACING      38
#define SM_CYICONSPACING      39
#define SM_MENUDROPALIGNMENT  40
#define SM_PENWINDOWS         41
#define SM_DBCSENABLED        42
#define SM_CMOUSEBUTTONS      43
#define SM_CXFIXEDFRAME	      SM_CXDLGFRAME
#define SM_CYFIXEDFRAME	      SM_CYDLGFRAME
#define SM_CXSIZEFRAME	      SM_CXFRAME
#define SM_CYSIZEFRAME	      SM_CYFRAME
#define SM_SECURE	      44
#define SM_CXEDGE	      45
#define SM_CYEDGE	      46
#define SM_CXMINSPACING	      47
#define SM_CYMINSPACING	      48
#define SM_CXSMICON	      49
#define SM_CYSMICON	      50
#define SM_CYSMCAPTION	      51
#define SM_CXSMSIZE	      52
#define SM_CYSMSIZE	      53
#define SM_CXMENUSIZE	      54
#define SM_CYMENUSIZE	      55
#define SM_ARRANGE	      56
#define SM_CXMINIMIZED	      57
#define SM_CYMINIMIZED	      58
#define SM_CXMAXTRACK	      59
#define SM_CYMAXTRACK	      60
#define SM_CXMAXIMIZED	      61
#define SM_CYMAXIMIZED	      62
#define SM_NETWORK	      63
#define SM_CLEANBOOT	      67
#define SM_CXDRAG	      68
#define SM_CYDRAG	      69
#define SM_SHOWSOUNDS	      70
#define SM_CXMENUCHECK	      71
#define SM_CYMENUCHECK	      72
#define SM_SLOWMACHINE	      73
#define SM_MIDEASTENABLED     74
#define SM_MOUSEWHEELPRESENT  75
#define SM_XVIRTUALSCREEN     76
#define SM_YVIRTUALSCREEN     77
#define SM_CXVIRTUALSCREEN    78
#define SM_CYVIRTUALSCREEN    79
#define SM_CMONITORS          80
#define SM_SAMEDISPLAYFORMAT  81
#define SM_IMMENABLED         82
#define SM_CXFOCUSBORDER      83
#define SM_CYFOCUSBORDER      84
#define SM_TABLETPC           86
#define SM_MEDIACENTER        87
#define SM_STARTER            88
#define SM_SERVERR2           89
#define SM_CMETRICS           90
#define SM_MOUSEHORIZONTALWHEELPRESENT 91
#define SM_CXPADDEDBORDER     92

#define SM_REMOTESESSION        0x1000
#define SM_SHUTTINGDOWN         0x2000
#define SM_REMOTECONTROL        0x2001
#define SM_CARETBLINKINGENABLED 0x2002

#define PMB_ACTIVE      0x00000001


/* wParam for WM_POWERBROADCAST */
#define PBT_APMQUERYSUSPEND       0x0000
#define PBT_APMQUERYSTANDBY       0x0001
#define PBT_APMQUERYSUSPENDFAILED 0x0002
#define PBT_APMQUERYSTANDBYFAILED 0x0003
#define PBT_APMSUSPEND            0x0004
#define PBT_APMSTANDBY            0x0005
#define PBT_APMRESUMECRITICAL     0x0006
#define PBT_APMRESUMESUSPEND      0x0007
#define PBT_APMRESUMESTANDBY      0x0008
#define PBT_APMBATTERYLOW         0x0009
#define PBT_APMPOWERSTATUSCHANGE  0x000A
#define PBT_APMOEMEVENT           0x000B
#define PBT_APMRESUMEAUTOMATIC    0x0012

#define PBTF_APMRESUMEFROMFAILURE       0x00000001


/* MsgWaitForMultipleObjectsEx flags */
#define MWMO_WAITALL         0x0001
#define MWMO_ALERTABLE       0x0002
#define MWMO_INPUTAVAILABLE  0x0004

/* WM_GETDLGCODE values */
#define DLGC_WANTARROWS      0x0001
#define DLGC_WANTTAB         0x0002
#define DLGC_WANTALLKEYS     0x0004
#define DLGC_WANTMESSAGE     0x0004
#define DLGC_HASSETSEL       0x0008
#define DLGC_DEFPUSHBUTTON   0x0010
#define DLGC_UNDEFPUSHBUTTON 0x0020
#define DLGC_RADIOBUTTON     0x0040
#define DLGC_WANTCHARS       0x0080
#define DLGC_STATIC          0x0100
#define DLGC_BUTTON          0x2000

/* Used for EnumDisplaySettingsEx */
#define ENUM_CURRENT_SETTINGS  ((DWORD) -1)
#define ENUM_REGISTRY_SETTINGS ((DWORD) -2)

#define EDS_RAWMODE       0x00000002
#define EDS_ROTATEDMODE   0x00000004

/* Used for PrintWindow */
#define PW_CLIENTONLY   0x00000001

/****** Window classes ******/

typedef struct tagCREATESTRUCTA
{
    LPVOID      lpCreateParams;
    HINSTANCE hInstance;
    HMENU     hMenu;
    HWND      hwndParent;
    INT       cy;
    INT       cx;
    INT       y;
    INT       x;
    LONG        style;
    LPCSTR      lpszName;
    LPCSTR      lpszClass;
    DWORD       dwExStyle;
} CREATESTRUCTA, *LPCREATESTRUCTA;

typedef struct tagCREATESTRUCTW
{
    LPVOID      lpCreateParams;
    HINSTANCE hInstance;
    HMENU     hMenu;
    HWND      hwndParent;
    INT       cy;
    INT       cx;
    INT       y;
    INT       x;
    LONG        style;
    LPCWSTR     lpszName;
    LPCWSTR     lpszClass;
    DWORD       dwExStyle;
} CREATESTRUCTW, *LPCREATESTRUCTW;

DECL_WINELIB_TYPE_AW(CREATESTRUCT)
DECL_WINELIB_TYPE_AW(LPCREATESTRUCT)

typedef struct tagPAINTSTRUCT
{
    HDC   hdc;
    BOOL  fErase;
    RECT  rcPaint;
    BOOL  fRestore;
    BOOL  fIncUpdate;
    BYTE  rgbReserved[32];
} PAINTSTRUCT, *PPAINTSTRUCT, *LPPAINTSTRUCT;

typedef struct tagCLIENTCREATESTRUCT
{
    HMENU   hWindowMenu;
    UINT    idFirstChild;
} CLIENTCREATESTRUCT, *LPCLIENTCREATESTRUCT;


typedef struct tagMDICREATESTRUCTA
{
    LPCSTR       szClass;
    LPCSTR       szTitle;
    HINSTANCE  hOwner;
    INT        x;
    INT        y;
    INT        cx;
    INT        cy;
    DWORD        style;
    LPARAM       lParam;
} MDICREATESTRUCTA, *LPMDICREATESTRUCTA;

typedef struct tagMDICREATESTRUCTW
{
    LPCWSTR      szClass;
    LPCWSTR      szTitle;
    HINSTANCE  hOwner;
    INT        x;
    INT        y;
    INT        cx;
    INT        cy;
    DWORD        style;
    LPARAM       lParam;
} MDICREATESTRUCTW, *LPMDICREATESTRUCTW;

DECL_WINELIB_TYPE_AW(MDICREATESTRUCT)
DECL_WINELIB_TYPE_AW(LPMDICREATESTRUCT)

#define MDITILE_VERTICAL     0x0000
#define MDITILE_HORIZONTAL   0x0001
#define MDITILE_SKIPDISABLED 0x0002
#define MDITILE_ZORDER       0x0004

#define MDIS_ALLCHILDSTYLES  0x0001

typedef struct tagSTYLESTRUCT {
    DWORD   styleOld;
    DWORD   styleNew;
} STYLESTRUCT, *LPSTYLESTRUCT;

#define WC_DIALOG  MAKEINTATOM(0x8002)

  /* Offsets for GetWindowLong() and GetWindowWord() */
#define GWL_EXSTYLE         (-20)
#define GWL_STYLE           (-16)
#if !defined _WIN64 && !defined __WINESRC__
# define GWL_USERDATA        (-21)
# define GWL_ID              (-12)
# define GWL_HWNDPARENT      (-8)
# define GWL_HINSTANCE       (-6)
# define GWL_WNDPROC         (-4)
# define DWL_MSGRESULT       0
# define DWL_DLGPROC         4
# define DWL_USER            8
#endif /* _WIN64 && __WINESRC__ */

  /* Offsets for GetWindowLongPtr() and SetWindowLongPtr() */
#define GWLP_USERDATA        (-21)
#define GWLP_ID              (-12)
#define GWLP_HWNDPARENT      (-8)
#define GWLP_HINSTANCE       (-6)
#define GWLP_WNDPROC         (-4)
#define DWLP_MSGRESULT       0
#define DWLP_DLGPROC         DWLP_MSGRESULT + sizeof(LRESULT)
#define DWLP_USER            DWLP_DLGPROC + sizeof(DLGPROC)

  /* GetWindow() constants */
#define GW_HWNDFIRST	0
#define GW_HWNDLAST	1
#define GW_HWNDNEXT	2
#define GW_HWNDPREV	3
#define GW_OWNER	4
#define GW_CHILD	5

/* GetAncestor() constants */
#define GA_PARENT       1
#define GA_ROOT         2
#define GA_ROOTOWNER    3

  /* WM_GETMINMAXINFO struct */
typedef struct tagMINMAXINFO
{
    POINT   ptReserved;
    POINT   ptMaxSize;
    POINT   ptMaxPosition;
    POINT   ptMinTrackSize;
    POINT   ptMaxTrackSize;
} MINMAXINFO, *PMINMAXINFO, *LPMINMAXINFO;


  /* RedrawWindow() flags */
#define RDW_INVALIDATE       0x0001
#define RDW_INTERNALPAINT    0x0002
#define RDW_ERASE            0x0004
#define RDW_VALIDATE         0x0008
#define RDW_NOINTERNALPAINT  0x0010
#define RDW_NOERASE          0x0020
#define RDW_NOCHILDREN       0x0040
#define RDW_ALLCHILDREN      0x0080
#define RDW_UPDATENOW        0x0100
#define RDW_ERASENOW         0x0200
#define RDW_FRAME            0x0400
#define RDW_NOFRAME          0x0800

/* debug flags */
#define DBGFILL_ALLOC  0xfd
#define DBGFILL_FREE   0xfb
#define DBGFILL_BUFFER 0xf9
#define DBGFILL_STACK  0xf7

  /* WM_WINDOWPOSCHANGING/CHANGED struct */
typedef struct tagWINDOWPOS
{
    HWND  hwnd;
    HWND  hwndInsertAfter;
    INT   x;
    INT   y;
    INT   cx;
    INT   cy;
    UINT  flags;
} WINDOWPOS, *PWINDOWPOS, *LPWINDOWPOS;


  /* WM_NCCALCSIZE parameter structure */
typedef struct
{
    RECT       rgrc[3];
    WINDOWPOS *lppos;
} NCCALCSIZE_PARAMS, *LPNCCALCSIZE_PARAMS;


#define PRF_CHECKVISIBLE    __MSABI_LONG(0x00000001)
#define PRF_NONCLIENT       __MSABI_LONG(0x00000002)
#define PRF_CLIENT          __MSABI_LONG(0x00000004)
#define PRF_ERASEBKGND      __MSABI_LONG(0x00000008)
#define PRF_CHILDREN        __MSABI_LONG(0x00000010)
#define PRF_OWNED           __MSABI_LONG(0x00000020)

  /* Offsets for GetClassLong() and GetClassWord() */
#if !defined _WIN64 && !defined __WINESRC__
# define GCL_MENUNAME       (-8)
# define GCL_HBRBACKGROUND  (-10)
# define GCL_HCURSOR        (-12)
# define GCL_HICON          (-14)
# define GCL_HMODULE        (-16)
# define GCL_WNDPROC        (-24)
# define GCL_HICONSM        (-34)
#endif /* _WIN64 && __WINESRC__ */

#define GCL_CBWNDEXTRA      (-18)
#define GCL_CBCLSEXTRA      (-20)
#define GCL_STYLE           (-26)
#define GCW_ATOM            (-32)

#define GCLP_MENUNAME       (-8)
#define GCLP_HBRBACKGROUND  (-10)
#define GCLP_HCURSOR        (-12)
#define GCLP_HICON          (-14)
#define GCLP_HMODULE        (-16)
#define GCLP_WNDPROC        (-24)
#define GCLP_HICONSM        (-34)

/* BroadcastSystemMessage flags */
#define BSM_ALLCOMPONENTS        0x00000000
#define BSM_VXDS                 0x00000001
#define BSM_NETDRIVER            0x00000002
#define BSM_INSTALLABLEDRIVERS   0x00000004
#define BSM_APPLICATIONS         0x00000008
#define BSM_ALLDESKTOPS          0x00000010

#define BSF_QUERY                0x00000001
#define BSF_IGNORECURRENTTASK    0x00000002
#define BSF_FLUSHDISK            0x00000004
#define BSF_NOHANG               0x00000008
#define BSF_POSTMESSAGE          0x00000010
#define BSF_FORCEIFHUNG          0x00000020
#define BSF_NOTIMEOUTIFNOTHUNG   0x00000040
#define BSF_ALLOWSFW             0x00000080
#define BSF_SENDNOTIFYMESSAGE    0x00000100
#define BSF_RETURNHDESK          0x00000200
#define BSF_LUID                 0x00000400

#define BROADCAST_QUERY_DENY     0x424D5144

/***** Window hooks *****/

  /* Hook values */
#define WH_MIN		    (-1)
#define WH_MSGFILTER	    (-1)
#define WH_JOURNALRECORD    0
#define WH_JOURNALPLAYBACK  1
#define WH_KEYBOARD	    2
#define WH_GETMESSAGE	    3
#define WH_CALLWNDPROC	    4
#define WH_CBT		    5
#define WH_SYSMSGFILTER	    6
#define WH_MOUSE	    7
#define WH_HARDWARE	    8
#define WH_DEBUG	    9
#define WH_SHELL            10
#define WH_FOREGROUNDIDLE   11
#define WH_CALLWNDPROCRET   12
#define WH_KEYBOARD_LL      13
#define WH_MOUSE_LL         14
#define WH_MAX              14

#define WH_MINHOOK          WH_MIN
#define WH_MAXHOOK          WH_MAX

  /* Hook action codes */
#define HC_ACTION           0
#define HC_GETNEXT          1
#define HC_SKIP             2
#define HC_NOREMOVE         3
#define HC_NOREM            HC_NOREMOVE
#define HC_SYSMODALON       4
#define HC_SYSMODALOFF      5

  /* CallMsgFilter() values */
#define MSGF_DIALOGBOX      0
#define MSGF_MESSAGEBOX     1
#define MSGF_MENU           2
#define MSGF_MOVE           3
#define MSGF_SIZE           4
#define MSGF_SCROLLBAR      5
#define MSGF_NEXTWINDOW     6
#define MSGF_MAX            8
#define MSGF_USER           0x1000
#define MSGF_DDEMGR         0x8001

typedef struct tagWNDCLASSA
{
    UINT      style;
    WNDPROC   lpfnWndProc;
    INT       cbClsExtra;
    INT       cbWndExtra;
    HINSTANCE hInstance;
    HICON     hIcon;
    HCURSOR   hCursor;
    HBRUSH    hbrBackground;
    LPCSTR      lpszMenuName;
    LPCSTR      lpszClassName;
} WNDCLASSA, *PWNDCLASSA, *LPWNDCLASSA;

typedef struct tagWNDCLASSW
{
    UINT      style;
    WNDPROC   lpfnWndProc;
    INT       cbClsExtra;
    INT       cbWndExtra;
    HINSTANCE hInstance;
    HICON     hIcon;
    HCURSOR   hCursor;
    HBRUSH    hbrBackground;
    LPCWSTR     lpszMenuName;
    LPCWSTR     lpszClassName;
} WNDCLASSW, *PWNDCLASSW, *LPWNDCLASSW;

DECL_WINELIB_TYPE_AW(WNDCLASS)
DECL_WINELIB_TYPE_AW(PWNDCLASS)
DECL_WINELIB_TYPE_AW(LPWNDCLASS)

typedef struct tagCOPYDATASTRUCT {
    ULONG_PTR dwData;
    DWORD cbData;
    PVOID lpData;
} COPYDATASTRUCT, *PCOPYDATASTRUCT;

typedef struct tagMDINEXTMENU {
    HMENU hmenuIn;
    HMENU hmenuNext;
    HWND  hwndNext;
} MDINEXTMENU, *PMDINEXTMENU, *LPMDINEXTMENU;

typedef struct tagMULTIKEYHELPA
{
    DWORD   mkSize;
    CHAR    mkKeylist;
    CHAR    szKeyphrase[1];
} MULTIKEYHELPA, *PMULTIKEYHELPA, *LPMULTIKEYHELPA;

typedef struct tagMULTIKEYHELPW
{
    DWORD   mkSize;
    WCHAR   mkKeylist;
    WCHAR   szKeyphrase[1];
} MULTIKEYHELPW, *PMULTIKEYHELPW, *LPMULTIKEYHELPW;

DECL_WINELIB_TYPE_AW(MULTIKEYHELP)
DECL_WINELIB_TYPE_AW(PMULTIKEYHELP)
DECL_WINELIB_TYPE_AW(LPMULTIKEYHELP)

typedef struct tagHELPWININFOA {
	int wStructSize;
	int x;
	int y;
	int dx;
	int dy;
	int wMax;
	CHAR rgchMember[2];
} HELPWININFOA, *PHELPWININFOA, *LPHELPWININFOA;

typedef struct tagHELPWININFOW {
	int wStructSize;
	int x;
	int y;
	int dx;
	int dy;
	int wMax;
	WCHAR rgchMember[2];
} HELPWININFOW, *PHELPWININFOW, *LPHELPWININFOW;

DECL_WINELIB_TYPE_AW(HELPWININFO)
DECL_WINELIB_TYPE_AW(PHELPWININFO)
DECL_WINELIB_TYPE_AW(LPHELPWININFO)


     /* ChangeDisplaySettings return codes */

#define DISP_CHANGE_SUCCESSFUL 0
#define DISP_CHANGE_RESTART    1
#define DISP_CHANGE_FAILED     (-1)
#define DISP_CHANGE_BADMODE    (-2)
#define DISP_CHANGE_NOTUPDATED (-3)
#define DISP_CHANGE_BADFLAGS   (-4)
#define DISP_CHANGE_BADPARAM   (-5)
#define DISP_CHANGE_BADDUALVIEW (-6)

/* ChangeDisplaySettings.dwFlags */
#define	CDS_UPDATEREGISTRY	0x00000001
#define	CDS_TEST		0x00000002
#define	CDS_FULLSCREEN		0x00000004
#define	CDS_GLOBAL		0x00000008
#define	CDS_SET_PRIMARY		0x00000010
#define	CDS_VIDEOPARAMETERS	0x00000020
#define	CDS_NORESET		0x10000000
#define	CDS_SETRECT		0x20000000
#define	CDS_RESET		0x40000000

typedef struct tagWNDCLASSEXA
{
    UINT      cbSize;
    UINT      style;
    WNDPROC   lpfnWndProc;
    INT       cbClsExtra;
    INT       cbWndExtra;
    HINSTANCE hInstance;
    HICON     hIcon;
    HCURSOR   hCursor;
    HBRUSH    hbrBackground;
    LPCSTR      lpszMenuName;
    LPCSTR      lpszClassName;
    HICON     hIconSm;
} WNDCLASSEXA, *PWNDCLASSEXA, *LPWNDCLASSEXA;

typedef struct tagWNDCLASSEXW
{
    UINT      cbSize;
    UINT      style;
    WNDPROC   lpfnWndProc;
    INT       cbClsExtra;
    INT       cbWndExtra;
    HINSTANCE hInstance;
    HICON     hIcon;
    HCURSOR   hCursor;
    HBRUSH    hbrBackground;
    LPCWSTR     lpszMenuName;
    LPCWSTR     lpszClassName;
    HICON     hIconSm;
} WNDCLASSEXW, *PWNDCLASSEXW, *LPWNDCLASSEXW;

DECL_WINELIB_TYPE_AW(WNDCLASSEX)
DECL_WINELIB_TYPE_AW(PWNDCLASSEX)
DECL_WINELIB_TYPE_AW(LPWNDCLASSEX)

typedef struct tagMSG
{
    HWND    hwnd;
    UINT    message;
    WPARAM  wParam;
    LPARAM    lParam;
    DWORD     time;
    POINT   pt;
} MSG, *PMSG, *LPMSG;

#define POINTSTOPOINT(pt, pts) { (pt).x = (pts).x; (pt).y = (pts).y; }
#define POINTTOPOINTS(pt)      (MAKELONG((short)((pt).x), (short)((pt).y)))

#define MAKELPARAM(low,high)   ((LPARAM)(DWORD)MAKELONG(low,high))
#define MAKEWPARAM(low,high)   ((WPARAM)(DWORD)MAKELONG(low,high))
#define MAKELRESULT(low,high)  ((LRESULT)(DWORD)MAKELONG(low,high))

/* Cursors / Icons */

typedef struct _ICONINFO {
	BOOL		fIcon;
	DWORD		xHotspot;
	DWORD		yHotspot;
	HBITMAP	hbmMask;
	HBITMAP	hbmColor;
} ICONINFO, *PICONINFO;

typedef struct _ICONINFOEXA
{
    DWORD     cbSize;
    BOOL      fIcon;
    DWORD     xHotspot;
    DWORD     yHotspot;
    HBITMAP   hbmMask;
    HBITMAP   hbmColor;
    WORD      wResID;
    CHAR      szModName[MAX_PATH];
    CHAR      szResName[MAX_PATH];
} ICONINFOEXA, *PICONINFOEXA;

typedef struct _ICONINFOEXW
{
    DWORD     cbSize;
    BOOL      fIcon;
    DWORD     xHotspot;
    DWORD     yHotspot;
    HBITMAP   hbmMask;
    HBITMAP   hbmColor;
    WORD      wResID;
    WCHAR     szModName[MAX_PATH];
    WCHAR     szResName[MAX_PATH];
} ICONINFOEXW, *PICONINFOEXW;

DECL_WINELIB_TYPE_AW(ICONINFOEX)
DECL_WINELIB_TYPE_AW(PICONINFOEX)

typedef struct tagCURSORINFO
{
    DWORD cbSize;
    DWORD flags;
    HCURSOR hCursor;
    POINT ptScreenPos;
} CURSORINFO, *PCURSORINFO, *LPCURSORINFO;

#define CURSOR_SHOWING 0x00000001
#define CURSOR_SUPPRESSED 0x00000002

/* this is the 6 byte accel struct used in Win32 when presented to the user */
typedef struct tagACCEL
{
#ifdef WORDS_BIGENDIAN
    WORD   fVirt;
    WORD   key;
    DWORD  cmd;
#else
    BYTE   fVirt;
    WORD   key;
    WORD   cmd;
#endif
} ACCEL, *LPACCEL;


/* Flags for TrackPopupMenu */
#define TPM_LEFTBUTTON    0x0000
#define TPM_RECURSE       0x0001
#define TPM_RIGHTBUTTON   0x0002
#define TPM_LEFTALIGN     0x0000
#define TPM_CENTERALIGN   0x0004
#define TPM_RIGHTALIGN    0x0008
#define TPM_TOPALIGN      0x0000
#define TPM_VCENTERALIGN  0x0010
#define TPM_BOTTOMALIGN   0x0020
#define TPM_HORIZONTAL    0x0000
#define TPM_VERTICAL      0x0040
#define TPM_NONOTIFY      0x0080
#define TPM_RETURNCMD     0x0100
#define TPM_HORPOSANIMATION 0x0400
#define TPM_HORNEGANIMATION 0x0800
#define TPM_VERPOSANIMATION 0x1000
#define TPM_VERNEGANIMATION 0x2000
#define TPM_NOANIMATION     0x4000
#define TPM_LAYOUTRTL       0x8000

typedef struct tagTPMPARAMS
{
    UINT   cbSize;
    RECT   rcExclude;
} TPMPARAMS, *LPTPMPARAMS;


/*
 * Combobox information
 */
typedef struct tagCOMBOBOXINFO
{
    DWORD cbSize;
    RECT  rcItem;
    RECT  rcButton;
    DWORD stateButton;
    HWND  hwndCombo;
    HWND  hwndItem;
    HWND  hwndList;
} COMBOBOXINFO, *PCOMBOBOXINFO, *LPCOMBOBOXINFO;

typedef struct tagMENUITEMINFOA {
  UINT    cbSize;
  UINT    fMask;
  UINT    fType;
  UINT    fState;
  UINT    wID;
  HMENU   hSubMenu;
  HBITMAP hbmpChecked;
  HBITMAP hbmpUnchecked;
  ULONG_PTR dwItemData;
  LPSTR   dwTypeData;
  UINT    cch;
  HBITMAP hbmpItem;
} MENUITEMINFOA, *LPMENUITEMINFOA;

typedef struct tagMENUITEMINFOW {
  UINT    cbSize;
  UINT    fMask;
  UINT    fType;
  UINT    fState;
  UINT    wID;
  HMENU   hSubMenu;
  HBITMAP hbmpChecked;
  HBITMAP hbmpUnchecked;
  ULONG_PTR dwItemData;
  LPWSTR  dwTypeData;
  UINT    cch;
  HBITMAP hbmpItem;
} MENUITEMINFOW, *LPMENUITEMINFOW;

DECL_WINELIB_TYPE_AW(MENUITEMINFO)
DECL_WINELIB_TYPE_AW(LPMENUITEMINFO)
typedef const MENUITEMINFOA *LPCMENUITEMINFOA;
typedef const MENUITEMINFOW *LPCMENUITEMINFOW;
DECL_WINELIB_TYPE_AW(LPCMENUITEMINFO)

typedef struct tagMENUBARINFO {
  DWORD cbSize;
  RECT  rcBar;
  HMENU hMenu;
  HWND  hwndMenu;
  BOOL  fBarFocused:1;
  BOOL  fFocused:1;
} MENUBARINFO, *PMENUBARINFO, *LPMENUBARINFO;

typedef struct tagMENUINFO {
  DWORD   cbSize;
  DWORD   fMask;
  DWORD   dwStyle;
  UINT    cyMax;
  HBRUSH  hbrBack;
  DWORD   dwContextHelpID;
  ULONG_PTR dwMenuData;
} MENUINFO, *LPMENUINFO;

typedef const MENUINFO *LPCMENUINFO;

#define MIM_MAXHEIGHT		0x00000001
#define MIM_BACKGROUND		0x00000002
#define MIM_HELPID		0x00000004
#define MIM_MENUDATA		0x00000008
#define MIM_STYLE		0x00000010
#define MIM_APPLYTOSUBMENUS	0x80000000

#define MNS_NOCHECK             0x80000000
#define MNS_MODELESS            0x40000000
#define MNS_DRAGDROP            0x20000000
#define MNS_AUTODISMISS         0x10000000
#define MNS_NOTIFYBYPOS         0x08000000
#define MNS_CHECKORBMP          0x04000000

typedef struct {
  WORD versionNumber;
  WORD offset;
} MENUITEMTEMPLATEHEADER, *PMENUITEMTEMPLATEHEADER;


typedef struct {
  WORD mtOption;
  WORD mtID;
  WCHAR mtString[1];
} MENUITEMTEMPLATE, *PMENUITEMTEMPLATE;


typedef VOID   MENUTEMPLATE;
typedef PVOID *LPMENUTEMPLATE;

/* Field specifiers for MENUITEMINFO[AW] type.  */
#define MIIM_STATE       0x00000001
#define MIIM_ID          0x00000002
#define MIIM_SUBMENU     0x00000004
#define MIIM_CHECKMARKS  0x00000008
#define MIIM_TYPE        0x00000010
#define MIIM_DATA        0x00000020
#define MIIM_STRING      0x00000040
#define MIIM_BITMAP      0x00000080
#define MIIM_FTYPE       0x00000100

#define HBMMENU_CALLBACK	((HBITMAP) -1)
#define HBMMENU_SYSTEM		((HBITMAP)  1)
#define HBMMENU_MBAR_RESTORE	((HBITMAP)  2)
#define HBMMENU_MBAR_MINIMIZE	((HBITMAP)  3)
#define HBMMENU_MBAR_CLOSE	((HBITMAP)  5)
#define HBMMENU_MBAR_CLOSE_D	((HBITMAP)  6)
#define HBMMENU_MBAR_MINIMIZE_D	((HBITMAP)  7)
#define HBMMENU_POPUP_CLOSE	((HBITMAP)  8)
#define HBMMENU_POPUP_RESTORE	((HBITMAP)  9)
#define HBMMENU_POPUP_MAXIMIZE	((HBITMAP) 10)
#define HBMMENU_POPUP_MINIMIZE	((HBITMAP) 11)

/* WM_H/VSCROLL commands */
#define SB_LINEUP           0
#define SB_LINELEFT         0
#define SB_LINEDOWN         1
#define SB_LINERIGHT        1
#define SB_PAGEUP           2
#define SB_PAGELEFT         2
#define SB_PAGEDOWN         3
#define SB_PAGERIGHT        3
#define SB_THUMBPOSITION    4
#define SB_THUMBTRACK       5
#define SB_TOP              6
#define SB_LEFT             6
#define SB_BOTTOM           7
#define SB_RIGHT            7
#define SB_ENDSCROLL        8

/* Scroll bar selection constants */
#define SB_HORZ             0
#define SB_VERT             1
#define SB_CTL              2
#define SB_BOTH             3

/* EnableScrollBar() flags */
#define ESB_ENABLE_BOTH     0x0000
#define ESB_DISABLE_BOTH    0x0003

#define ESB_DISABLE_LEFT    0x0001
#define ESB_DISABLE_RIGHT   0x0002

#define ESB_DISABLE_UP      0x0001
#define ESB_DISABLE_DOWN    0x0002

#define ESB_DISABLE_LTUP    ESB_DISABLE_LEFT
#define ESB_DISABLE_RTDN    ESB_DISABLE_RIGHT

/* Static Control Messages */
#define STM_SETICON       0x0170
#define STM_GETICON       0x0171
#define STM_SETIMAGE        0x0172
#define STM_GETIMAGE        0x0173
#define STM_MSGMAX          0x0174

#define STN_CLICKED         0
#define STN_DBLCLK          1
#define STN_ENABLE          2
#define STN_DISABLE         3

/* Scrollbar messages */
#define SBM_SETPOS             0x00e0
#define SBM_GETPOS             0x00e1
#define SBM_SETRANGE           0x00e2
#define SBM_GETRANGE           0x00e3
#define SBM_ENABLE_ARROWS      0x00e4
#define SBM_SETRANGEREDRAW     0x00e6
#define SBM_SETSCROLLINFO      0x00e9
#define SBM_GETSCROLLINFO      0x00ea
#define SBM_GETSCROLLBARINFO   0x00eb

/* Scrollbar info */
typedef struct tagSCROLLINFO
{
    UINT    cbSize;
    UINT    fMask;
    INT     nMin;
    INT     nMax;
    UINT    nPage;
    INT     nPos;
    INT     nTrackPos;
} SCROLLINFO, *LPSCROLLINFO;

typedef const SCROLLINFO *LPCSCROLLINFO;

#define CCHILDREN_SCROLLBAR 5

typedef struct tagSCROLLBARINFO
{
    DWORD   cbSize;             /* Size of SCROLLBARINFO struct */
    RECT    rcScrollBar;        /* Coordinates of the scroll bar */
    INT     dxyLineButton;      /* Height or width */
    INT     xyThumbTop;         /* Position of the top or the left */
    INT     xyThumbBottom;      /* Position of the bottom or the right */
    INT     reserved;
    DWORD   rgstate[CCHILDREN_SCROLLBAR+1];
} SCROLLBARINFO, *PSCROLLBARINFO, *LPSCROLLBARINFO;

/* GetScrollInfo() flags */
#define SIF_RANGE           0x0001
#define SIF_PAGE            0x0002
#define SIF_POS             0x0004
#define SIF_DISABLENOSCROLL 0x0008
#define SIF_TRACKPOS        0x0010
#define SIF_ALL             (SIF_RANGE | SIF_PAGE | SIF_POS | SIF_TRACKPOS)

/* Listbox messages */
#define LB_ADDSTRING           0x0180
#define LB_INSERTSTRING        0x0181
#define LB_DELETESTRING        0x0182
#define LB_SELITEMRANGEEX      0x0183
#define LB_RESETCONTENT        0x0184
#define LB_SETSEL              0x0185
#define LB_SETCURSEL           0x0186
#define LB_GETSEL              0x0187
#define LB_GETCURSEL           0x0188
#define LB_GETTEXT             0x0189
#define LB_GETTEXTLEN          0x018a
#define LB_GETCOUNT            0x018b
#define LB_SELECTSTRING        0x018c
#define LB_DIR                 0x018d
#define LB_GETTOPINDEX         0x018e
#define LB_FINDSTRING          0x018f
#define LB_GETSELCOUNT         0x0190
#define LB_GETSELITEMS         0x0191
#define LB_SETTABSTOPS         0x0192
#define LB_GETHORIZONTALEXTENT 0x0193
#define LB_SETHORIZONTALEXTENT 0x0194
#define LB_SETCOLUMNWIDTH      0x0195
#define LB_ADDFILE             0x0196
#define LB_SETTOPINDEX         0x0197
#define LB_GETITEMRECT         0x0198
#define LB_GETITEMDATA         0x0199
#define LB_SETITEMDATA         0x019a
#define LB_SELITEMRANGE        0x019b
#define LB_SETANCHORINDEX      0x019c
#define LB_GETANCHORINDEX      0x019d
#define LB_SETCARETINDEX       0x019e
#define LB_GETCARETINDEX       0x019f
#define LB_SETITEMHEIGHT       0x01a0
#define LB_GETITEMHEIGHT       0x01a1
#define LB_FINDSTRINGEXACT     0x01a2
#define LB_CARETON             0x01a3
#define LB_CARETOFF            0x01a4
#define LB_SETLOCALE           0x01a5
#define LB_GETLOCALE           0x01a6
#define LB_SETCOUNT            0x01a7
#define LB_INITSTORAGE         0x01a8
#define LB_ITEMFROMPOINT       0x01a9
#define LB_GETLISTBOXINFO      0x01b2
#define LB_MSGMAX              0x01b3

/* Listbox notification codes */
#define LBN_ERRSPACE        (-2)
#define LBN_SELCHANGE       1
#define LBN_DBLCLK          2
#define LBN_SELCANCEL       3
#define LBN_SETFOCUS        4
#define LBN_KILLFOCUS       5

/* Listbox message return values */
#define LB_OKAY             0
#define LB_ERR              (-1)
#define LB_ERRSPACE         (-2)

#define LB_CTLCODE          __MSABI_LONG(0)

/* Combo box messages */
#define CB_GETEDITSEL            0x0140
#define CB_LIMITTEXT             0x0141
#define CB_SETEDITSEL            0x0142
#define CB_ADDSTRING             0x0143
#define CB_DELETESTRING          0x0144
#define CB_DIR                   0x0145
#define CB_GETCOUNT              0x0146
#define CB_GETCURSEL             0x0147
#define CB_GETLBTEXT             0x0148
#define CB_GETLBTEXTLEN          0x0149
#define CB_INSERTSTRING          0x014a
#define CB_RESETCONTENT          0x014b
#define CB_FINDSTRING            0x014c
#define CB_SELECTSTRING          0x014d
#define CB_SETCURSEL             0x014e
#define CB_SHOWDROPDOWN          0x014f
#define CB_GETITEMDATA           0x0150
#define CB_SETITEMDATA           0x0151
#define CB_GETDROPPEDCONTROLRECT 0x0152
#define CB_SETITEMHEIGHT         0x0153
#define CB_GETITEMHEIGHT         0x0154
#define CB_SETEXTENDEDUI         0x0155
#define CB_GETEXTENDEDUI         0x0156
#define CB_GETDROPPEDSTATE       0x0157
#define CB_FINDSTRINGEXACT       0x0158
#define CB_SETLOCALE             0x0159
#define CB_GETLOCALE             0x015a
#define CB_GETTOPINDEX           0x015b
#define CB_SETTOPINDEX           0x015c
#define CB_GETHORIZONTALEXTENT   0x015d
#define CB_SETHORIZONTALEXTENT   0x015e
#define CB_GETDROPPEDWIDTH       0x015f
#define CB_SETDROPPEDWIDTH       0x0160
#define CB_INITSTORAGE           0x0161
#define CB_MULTIPLEADDSTRING     0x0163
#define CB_GETCOMBOBOXINFO       0x0164
#define CB_MSGMAX                0x0165

/* Combo box notification codes */
#define CBN_ERRSPACE        (-1)
#define CBN_SELCHANGE       1
#define CBN_DBLCLK          2
#define CBN_SETFOCUS        3
#define CBN_KILLFOCUS       4
#define CBN_EDITCHANGE      5
#define CBN_EDITUPDATE      6
#define CBN_DROPDOWN        7
#define CBN_CLOSEUP         8
#define CBN_SELENDOK        9
#define CBN_SELENDCANCEL    10

/* Combo box message return values */
#define CB_OKAY             0
#define CB_ERR              (-1)
#define CB_ERRSPACE         (-2)

#define MB_OK			0x00000000
#define MB_OKCANCEL		0x00000001
#define MB_ABORTRETRYIGNORE	0x00000002
#define MB_YESNOCANCEL		0x00000003
#define MB_YESNO		0x00000004
#define MB_RETRYCANCEL		0x00000005
#define MB_CANCELTRYCONTINUE	0x00000006
#define MB_TYPEMASK		0x0000000F

#define MB_ICONHAND		0x00000010
#define MB_ICONQUESTION		0x00000020
#define MB_ICONEXCLAMATION	0x00000030
#define MB_ICONASTERISK		0x00000040
#define	MB_USERICON		0x00000080
#define MB_ICONMASK		0x000000F0

#define MB_ICONINFORMATION	MB_ICONASTERISK
#define MB_ICONSTOP		MB_ICONHAND
#define MB_ICONWARNING		MB_ICONEXCLAMATION
#define MB_ICONERROR		MB_ICONHAND

#define MB_DEFBUTTON1		0x00000000
#define MB_DEFBUTTON2		0x00000100
#define MB_DEFBUTTON3		0x00000200
#define MB_DEFBUTTON4		0x00000300
#define MB_DEFMASK		0x00000F00

#define MB_APPLMODAL		0x00000000
#define MB_SYSTEMMODAL		0x00001000
#define MB_TASKMODAL		0x00002000
#define MB_MODEMASK		0x00003000

#define MB_HELP			0x00004000
#define MB_NOFOCUS		0x00008000
#define MB_MISCMASK		0x0000C000

#define MB_SETFOREGROUND	0x00010000
#define MB_DEFAULT_DESKTOP_ONLY	0x00020000
#define MB_SERVICE_NOTIFICATION	0x00040000
#define MB_TOPMOST		0x00040000
#define MB_RIGHT		0x00080000
#define MB_RTLREADING		0x00100000

#define	HELPINFO_WINDOW		0x0001
#define	HELPINFO_MENUITEM	0x0002

/* Structure pointed to by lParam of WM_HELP */
typedef struct tagHELPINFO
{
    UINT	cbSize;		/* Size in bytes of this struct  */
    INT	iContextType;	/* Either HELPINFO_WINDOW or HELPINFO_MENUITEM */
    INT	iCtrlId;	/* Control Id or a Menu item Id. */
    HANDLE	hItemHandle;	/* hWnd of control or hMenu.     */
    DWORD_PTR	dwContextId;	/* Context Id associated with this item */
    POINT	MousePos;	/* Mouse Position in screen co-ordinates */
}  HELPINFO,*LPHELPINFO;

typedef void (CALLBACK *MSGBOXCALLBACK)(LPHELPINFO lpHelpInfo);

typedef struct tagMSGBOXPARAMSA
{
    UINT	cbSize;
    HWND	hwndOwner;
    HINSTANCE	hInstance;
    LPCSTR	lpszText;
    LPCSTR	lpszCaption;
    DWORD	dwStyle;
    LPCSTR	lpszIcon;
    DWORD_PTR	dwContextHelpId;
    MSGBOXCALLBACK	lpfnMsgBoxCallback;
    DWORD	dwLanguageId;
} MSGBOXPARAMSA, *PMSGBOXPARAMSA, *LPMSGBOXPARAMSA;

typedef struct tagMSGBOXPARAMSW
{
    UINT	cbSize;
    HWND	hwndOwner;
    HINSTANCE	hInstance;
    LPCWSTR	lpszText;
    LPCWSTR	lpszCaption;
    DWORD	dwStyle;
    LPCWSTR	lpszIcon;
    DWORD_PTR	dwContextHelpId;
    MSGBOXCALLBACK	lpfnMsgBoxCallback;
    DWORD	dwLanguageId;
} MSGBOXPARAMSW, *PMSGBOXPARAMSW, *LPMSGBOXPARAMSW;

DECL_WINELIB_TYPE_AW(MSGBOXPARAMS)
DECL_WINELIB_TYPE_AW(PMSGBOXPARAMS)
DECL_WINELIB_TYPE_AW(LPMSGBOXPARAMS)

#define MONITOR_DEFAULTTONULL       0x00000000
#define MONITOR_DEFAULTTOPRIMARY    0x00000001
#define MONITOR_DEFAULTTONEAREST    0x00000002

#define MONITORINFOF_PRIMARY        0x00000001

#ifndef CCHDEVICENAME
#define CCHDEVICENAME 32
#endif

typedef struct tagMONITORINFO
{
    DWORD cbSize;
    RECT  rcMonitor;
    RECT  rcWork;
    DWORD dwFlags;
} MONITORINFO, *LPMONITORINFO;

typedef struct tagMONITORINFOEXA
{   /* the 4 first entries are the same as MONITORINFO */
    DWORD	cbSize;	
    RECT	rcMonitor;
    RECT	rcWork;
    DWORD	dwFlags;
    CHAR        szDevice[CCHDEVICENAME];
} MONITORINFOEXA, *LPMONITORINFOEXA;

typedef struct tagMONITORINFOEXW
{   /* the 4 first entries are the same as MONITORINFO */
    DWORD	cbSize;
    RECT	rcMonitor;
    RECT	rcWork;
    DWORD	dwFlags;
    WCHAR       szDevice[CCHDEVICENAME];
} MONITORINFOEXW, *LPMONITORINFOEXW;

DECL_WINELIB_TYPE_AW(MONITORINFOEX)
DECL_WINELIB_TYPE_AW(LPMONITORINFOEX)

typedef BOOL  (CALLBACK *MONITORENUMPROC)(HMONITOR,HDC,LPRECT,LPARAM);

#include <pshpack2.h>

typedef struct tagDLGTEMPLATE
{
    DWORD style;
    DWORD dwExtendedStyle;
    WORD cdit;
    short x;
    short y;
    short cx;
    short cy;
} DLGTEMPLATE;

typedef DLGTEMPLATE *LPDLGTEMPLATEA;
typedef DLGTEMPLATE *LPDLGTEMPLATEW;
DECL_WINELIB_TYPE_AW(LPDLGTEMPLATE)
typedef const DLGTEMPLATE *LPCDLGTEMPLATEA;
typedef const DLGTEMPLATE *LPCDLGTEMPLATEW;
DECL_WINELIB_TYPE_AW(LPCDLGTEMPLATE)

typedef struct tagDLGITEMTEMPLATE
{
    DWORD style;
    DWORD dwExtendedStyle;
    short x;
    short y;
    short cx;
    short cy;
    WORD id;
} DLGITEMTEMPLATE;

typedef DLGITEMTEMPLATE *PDLGITEMTEMPLATEA;
typedef DLGITEMTEMPLATE *PDLGITEMTEMPLATEW;
DECL_WINELIB_TYPE_AW(PDLGITEMTEMPLATE)
typedef DLGITEMTEMPLATE *LPDLGITEMTEMPLATEA;
typedef DLGITEMTEMPLATE *LPDLGITEMTEMPLATEW;
DECL_WINELIB_TYPE_AW(LPDLGITEMTEMPLATE)

#include <poppack.h>

  /* CBT hook values */
#define HCBT_MOVESIZE	    0
#define HCBT_MINMAX	    1
#define HCBT_QS 	    2
#define HCBT_CREATEWND	    3
#define HCBT_DESTROYWND	    4
#define HCBT_ACTIVATE	    5
#define HCBT_CLICKSKIPPED   6
#define HCBT_KEYSKIPPED     7
#define HCBT_SYSCOMMAND	    8
#define HCBT_SETFOCUS	    9

  /* CBT hook structures */

typedef struct tagCBT_CREATEWNDA
{
    CREATESTRUCTA *lpcs;
    HWND           hwndInsertAfter;
} CBT_CREATEWNDA, *LPCBT_CREATEWNDA;

typedef struct tagCBT_CREATEWNDW
{
    CREATESTRUCTW *lpcs;
    HWND           hwndInsertAfter;
} CBT_CREATEWNDW, *LPCBT_CREATEWNDW;

DECL_WINELIB_TYPE_AW(CBT_CREATEWND)
DECL_WINELIB_TYPE_AW(LPCBT_CREATEWND)

typedef struct tagCBTACTIVATESTRUCT
{
    BOOL    fMouse;
    HWND    hWndActive;
} CBTACTIVATESTRUCT, *LPCBTACTIVATESTRUCT;


/* modifiers for RegisterHotKey */
#define	MOD_ALT		0x0001
#define	MOD_CONTROL	0x0002
#define	MOD_SHIFT	0x0004
#define	MOD_WIN		0x0008

/* ids for RegisterHotKey */
#define	IDHOT_SNAPWINDOW	(-1)    /* SHIFT-PRINTSCRN  */
#define	IDHOT_SNAPDESKTOP	(-2)    /* PRINTSCRN        */

  /* keybd_event flags */
#define KEYEVENTF_EXTENDEDKEY        0x0001
#define KEYEVENTF_KEYUP              0x0002
#define KEYEVENTF_UNICODE            0x0004
#define KEYEVENTF_SCANCODE           0x0008

  /* mouse_event flags */
#define MOUSEEVENTF_MOVE            0x0001
#define MOUSEEVENTF_LEFTDOWN        0x0002
#define MOUSEEVENTF_LEFTUP          0x0004
#define MOUSEEVENTF_RIGHTDOWN       0x0008
#define MOUSEEVENTF_RIGHTUP         0x0010
#define MOUSEEVENTF_MIDDLEDOWN      0x0020
#define MOUSEEVENTF_MIDDLEUP        0x0040
#define MOUSEEVENTF_XDOWN           0x0080
#define MOUSEEVENTF_XUP             0x0100
#define MOUSEEVENTF_WHEEL           0x0800
#define MOUSEEVENTF_HWHEEL          0x1000
#define MOUSEEVENTF_MOVE_NOCOALESCE 0x2000
#define MOUSEEVENTF_VIRTUALDESK     0x4000
#define MOUSEEVENTF_ABSOLUTE        0x8000

/* ExitWindows() flags */
#define EW_RESTARTWINDOWS   0x0042
#define EW_REBOOTSYSTEM     0x0043
#define EW_EXITANDEXECAPP   0x0044

/* ExitWindowsEx() flags */
#define EWX_LOGOFF           0
#define EWX_SHUTDOWN         1
#define EWX_REBOOT           2
#define EWX_FORCE            4
#define EWX_POWEROFF         8
#define EWX_FORCEIFHUNG     16

/* SetLastErrorEx types */
#define	SLE_ERROR	0x00000001
#define	SLE_MINORERROR	0x00000002
#define	SLE_WARNING	0x00000003

/* Predefined resources */
#define IDI_APPLICATION    MAKEINTRESOURCE(32512)
#define IDI_HAND           MAKEINTRESOURCE(32513)
#define IDI_QUESTION       MAKEINTRESOURCE(32514)
#define IDI_EXCLAMATION    MAKEINTRESOURCE(32515)
#define IDI_ASTERISK       MAKEINTRESOURCE(32516)
#define IDI_WINLOGO        MAKEINTRESOURCE(32517)

#define IDI_WARNING        IDI_EXCLAMATION
#define IDI_ERROR          IDI_HAND
#define IDI_INFORMATION    IDI_ASTERISK

#define IDC_ARROW          MAKEINTRESOURCE(32512)
#define IDC_IBEAM          MAKEINTRESOURCE(32513)
#define IDC_WAIT           MAKEINTRESOURCE(32514)
#define IDC_CROSS          MAKEINTRESOURCE(32515)
#define IDC_UPARROW        MAKEINTRESOURCE(32516)
#define IDC_PEN            MAKEINTRESOURCE(32631)
#define IDC_SIZE           MAKEINTRESOURCE(32640)
#define IDC_ICON           MAKEINTRESOURCE(32641)
#define IDC_SIZENWSE       MAKEINTRESOURCE(32642)
#define IDC_SIZENESW       MAKEINTRESOURCE(32643)
#define IDC_SIZEWE         MAKEINTRESOURCE(32644)
#define IDC_SIZENS         MAKEINTRESOURCE(32645)
#define IDC_SIZEALL        MAKEINTRESOURCE(32646)
#define IDC_NO             MAKEINTRESOURCE(32648)
#define IDC_HAND           MAKEINTRESOURCE(32649)
#define IDC_APPSTARTING    MAKEINTRESOURCE(32650)
#define IDC_HELP           MAKEINTRESOURCE(32651)

#define MNC_IGNORE 0
#define MNC_CLOSE 1
#define MNC_EXECUTE 2
#define MNC_SELECT 3

/* SystemParametersInfo */
#define SPI_GETBEEP               1
#define SPI_SETBEEP               2
#define SPI_GETMOUSE              3
#define SPI_SETMOUSE              4
#define SPI_GETBORDER             5
#define SPI_SETBORDER             6
#define SPI_GETKEYBOARDSPEED      10
#define SPI_SETKEYBOARDSPEED      11
#define SPI_LANGDRIVER            12
#define SPI_ICONHORIZONTALSPACING 13
#define SPI_GETSCREENSAVETIMEOUT  14
#define SPI_SETSCREENSAVETIMEOUT  15
#define SPI_GETSCREENSAVEACTIVE   16
#define SPI_SETSCREENSAVEACTIVE   17
#define SPI_GETGRIDGRANULARITY    18
#define SPI_SETGRIDGRANULARITY    19
#define SPI_SETDESKWALLPAPER      20
#define SPI_SETDESKPATTERN        21
#define SPI_GETKEYBOARDDELAY      22
#define SPI_SETKEYBOARDDELAY      23
#define SPI_ICONVERTICALSPACING   24
#define SPI_GETICONTITLEWRAP      25
#define SPI_SETICONTITLEWRAP      26
#define SPI_GETMENUDROPALIGNMENT  27
#define SPI_SETMENUDROPALIGNMENT  28
#define SPI_SETDOUBLECLKWIDTH     29
#define SPI_SETDOUBLECLKHEIGHT    30
#define SPI_GETICONTITLELOGFONT   31
#define SPI_SETDOUBLECLICKTIME    32
#define SPI_SETMOUSEBUTTONSWAP    33
#define SPI_SETICONTITLELOGFONT   34
#define SPI_GETFASTTASKSWITCH     35
#define SPI_SETFASTTASKSWITCH     36
#define SPI_SETDRAGFULLWINDOWS    37
#define SPI_GETDRAGFULLWINDOWS    38
#define SPI_GETNONCLIENTMETRICS   41
#define SPI_SETNONCLIENTMETRICS   42
#define SPI_GETMINIMIZEDMETRICS   43
#define SPI_SETMINIMIZEDMETRICS   44
#define SPI_GETICONMETRICS        45
#define SPI_SETICONMETRICS        46
#define SPI_SETWORKAREA           47
#define SPI_GETWORKAREA           48
#define SPI_SETPENWINDOWS         49
#define SPI_GETFILTERKEYS         50
#define SPI_SETFILTERKEYS         51
#define SPI_GETTOGGLEKEYS         52
#define SPI_SETTOGGLEKEYS         53
#define SPI_GETMOUSEKEYS          54
#define SPI_SETMOUSEKEYS          55
#define SPI_GETSHOWSOUNDS         56
#define SPI_SETSHOWSOUNDS         57
#define SPI_GETSTICKYKEYS         58
#define SPI_SETSTICKYKEYS         59
#define SPI_GETACCESSTIMEOUT      60
#define SPI_SETACCESSTIMEOUT      61
#define SPI_GETSERIALKEYS         62
#define SPI_SETSERIALKEYS         63
#define SPI_GETSOUNDSENTRY        64
#define SPI_SETSOUNDSENTRY        65
#define SPI_GETHIGHCONTRAST       66
#define SPI_SETHIGHCONTRAST       67
#define SPI_GETKEYBOARDPREF       68
#define SPI_SETKEYBOARDPREF       69
#define SPI_GETSCREENREADER       70
#define SPI_SETSCREENREADER       71
#define SPI_GETANIMATION          72
#define SPI_SETANIMATION          73
#define SPI_GETFONTSMOOTHING      74
#define SPI_SETFONTSMOOTHING      75
#define SPI_SETDRAGWIDTH          76
#define SPI_SETDRAGHEIGHT         77
#define SPI_SETHANDHELD           78
#define SPI_GETLOWPOWERTIMEOUT    79
#define SPI_GETPOWEROFFTIMEOUT    80
#define SPI_SETLOWPOWERTIMEOUT    81
#define SPI_SETPOWEROFFTIMEOUT    82
#define SPI_GETLOWPOWERACTIVE     83
#define SPI_GETPOWEROFFACTIVE     84
#define SPI_SETLOWPOWERACTIVE     85
#define SPI_SETPOWEROFFACTIVE     86
#define SPI_SETCURSORS            87
#define SPI_SETICONS              88
#define SPI_GETDEFAULTINPUTLANG   89
#define SPI_SETDEFAULTINPUTLANG   90
#define SPI_SETLANGTOGGLE         91
#define SPI_GETWINDOWSEXTENSION   92
#define SPI_SETMOUSETRAILS        93
#define SPI_GETMOUSETRAILS        94
#define SPI_GETSNAPTODEFBUTTON    95
#define SPI_SETSNAPTODEFBUTTON    96
#define SPI_SETSCREENSAVERRUNNING 97
#define SPI_SCREENSAVERRUNNING    SPI_SETSCREENSAVERRUNNING
#define SPI_GETMOUSEHOVERWIDTH    98
#define SPI_SETMOUSEHOVERWIDTH    99
#define SPI_GETMOUSEHOVERHEIGHT   100
#define SPI_SETMOUSEHOVERHEIGHT   101
#define SPI_GETMOUSEHOVERTIME     102
#define SPI_SETMOUSEHOVERTIME     103
#define SPI_GETWHEELSCROLLLINES   104
#define SPI_SETWHEELSCROLLLINES   105
#define SPI_GETMENUSHOWDELAY      106
#define SPI_SETMENUSHOWDELAY      107
#define SPI_GETWHEELSCROLLCHARS   108
#define SPI_SETWHEELSCROLLCHARS   109
#define SPI_GETSHOWIMEUI          110
#define SPI_SETSHOWIMEUI          111
#define SPI_GETMOUSESPEED         112
#define SPI_SETMOUSESPEED         113
#define SPI_GETSCREENSAVERRUNNING 114
#define SPI_GETDESKWALLPAPER      115

#define SPI_GETACTIVEWINDOWTRACKING    0x1000
#define SPI_SETACTIVEWINDOWTRACKING    0x1001
#define SPI_GETMENUANIMATION           0x1002
#define SPI_SETMENUANIMATION           0x1003
#define SPI_GETCOMBOBOXANIMATION       0x1004
#define SPI_SETCOMBOBOXANIMATION       0x1005
#define SPI_GETLISTBOXSMOOTHSCROLLING  0x1006
#define SPI_SETLISTBOXSMOOTHSCROLLING  0x1007
#define SPI_GETGRADIENTCAPTIONS        0x1008
#define SPI_SETGRADIENTCAPTIONS        0x1009
#define SPI_GETKEYBOARDCUES            0x100A
#define SPI_SETKEYBOARDCUES            0x100B
#define SPI_GETMENUUNDERLINES          SPI_GETKEYBOARDCUES
#define SPI_SETMENUUNDERLINES          SPI_SETKEYBOARDCUES
#define SPI_GETACTIVEWNDTRKZORDER      0x100C
#define SPI_SETACTIVEWNDTRKZORDER      0x100D
#define SPI_GETHOTTRACKING             0x100E
#define SPI_SETHOTTRACKING             0x100F
#define SPI_GETMENUFADE                0x1012
#define SPI_SETMENUFADE                0x1013
#define SPI_GETSELECTIONFADE           0x1014
#define SPI_SETSELECTIONFADE           0x1015
#define SPI_GETTOOLTIPANIMATION        0x1016
#define SPI_SETTOOLTIPANIMATION        0x1017
#define SPI_GETTOOLTIPFADE             0x1018
#define SPI_SETTOOLTIPFADE             0x1019
#define SPI_GETCURSORSHADOW            0x101A
#define SPI_SETCURSORSHADOW            0x101B
#define SPI_GETMOUSESONAR              0x101C
#define SPI_SETMOUSESONAR              0x101D
#define SPI_GETMOUSECLICKLOCK          0x101E
#define SPI_SETMOUSECLICKLOCK          0x101F
#define SPI_GETMOUSEVANISH             0x1020
#define SPI_SETMOUSEVANISH             0x1021
#define SPI_GETFLATMENU                0x1022
#define SPI_SETFLATMENU                0x1023
#define SPI_GETDROPSHADOW              0x1024
#define SPI_SETDROPSHADOW              0x1025
#define SPI_GETBLOCKSENDINPUTRESETS    0x1026
#define SPI_SETBLOCKSENDINPUTRESETS    0x1027
#define SPI_GETUIEFFECTS               0x103E
#define SPI_SETUIEFFECTS               0x103F
#define SPI_GETDISABLEOVERLAPPEDCONTENT 0x1040
#define SPI_SETDISABLEOVERLAPPEDCONTENT 0x1041
#define SPI_GETCLIENTAREAANIMATION     0x1042
#define SPI_SETCLIENTAREAANIMATION     0x1043
#define SPI_GETCLEARTYPE               0x1048
#define SPI_SETCLEARTYPE               0x1049
#define SPI_GETSPEECHRECOGNITION       0x104A
#define SPI_SETSPEECHRECOGNITION       0x104B
#define SPI_GETFOREGROUNDLOCKTIMEOUT   0x2000
#define SPI_SETFOREGROUNDLOCKTIMEOUT   0x2001
#define SPI_GETACTIVEWNDTRKTIMEOUT     0x2002
#define SPI_SETACTIVEWNDTRKTIMEOUT     0x2003
#define SPI_GETFOREGROUNDFLASHCOUNT    0x2004
#define SPI_SETFOREGROUNDFLASHCOUNT    0x2005
#define SPI_GETCARETWIDTH              0x2006
#define SPI_SETCARETWIDTH              0x2007
#define SPI_GETMOUSECLICKLOCKTIME      0x2008
#define SPI_SETMOUSECLICKLOCKTIME      0x2009
#define SPI_GETFONTSMOOTHINGTYPE       0x200A
#define SPI_SETFONTSMOOTHINGTYPE       0x200B
#define SPI_GETFONTSMOOTHINGCONTRAST   0x200C
#define SPI_SETFONTSMOOTHINGCONTRAST   0x200D
#define SPI_GETFOCUSBORDERWIDTH        0x200E
#define SPI_SETFOCUSBORDERWIDTH        0x200F
#define SPI_GETFOCUSBORDERHEIGHT       0x2010
#define SPI_SETFOCUSBORDERHEIGHT       0x2011
#define SPI_GETFONTSMOOTHINGORIENTATION 0x2012
#define SPI_SETFONTSMOOTHINGORIENTATION 0x2013

#define FE_FONTSMOOTHINGSTANDARD       0x0001
#define FE_FONTSMOOTHINGCLEARTYPE      0x0002
#define FE_FONTSMOOTHINGDOCKING        0x8000

#define FE_FONTSMOOTHINGORIENTATIONBGR 0x0000
#define FE_FONTSMOOTHINGORIENTATIONRGB 0x0001

#define SETWALLPAPER_DEFAULT           ((LPWSTR)-1)

/* SystemParametersInfo flags */

#define SPIF_UPDATEINIFILE              1
#define SPIF_SENDWININICHANGE           2
#define SPIF_SENDCHANGE                 SPIF_SENDWININICHANGE

#if defined(_WINGDI_) && !defined(NOGDI)
typedef struct tagNONCLIENTMETRICSA {
	UINT		cbSize;
	INT		iBorderWidth;
	INT		iScrollWidth;
	INT		iScrollHeight;
	INT		iCaptionWidth;
	INT		iCaptionHeight;
	LOGFONTA	lfCaptionFont;
	INT		iSmCaptionWidth;
	INT		iSmCaptionHeight;
	LOGFONTA	lfSmCaptionFont;
	INT		iMenuWidth;
	INT		iMenuHeight;
	LOGFONTA	lfMenuFont;
	LOGFONTA	lfStatusFont;
	LOGFONTA	lfMessageFont;
	INT		iPaddedBorderWidth;
} NONCLIENTMETRICSA, *PNONCLIENTMETRICSA, *LPNONCLIENTMETRICSA;

typedef struct tagNONCLIENTMETRICSW {
	UINT		cbSize;
	INT		iBorderWidth;
	INT		iScrollWidth;
	INT		iScrollHeight;
	INT		iCaptionWidth;
	INT		iCaptionHeight;
	LOGFONTW	lfCaptionFont;
	INT		iSmCaptionWidth;
	INT		iSmCaptionHeight;
	LOGFONTW	lfSmCaptionFont;
	INT		iMenuWidth;
	INT		iMenuHeight;
	LOGFONTW	lfMenuFont;
	LOGFONTW	lfStatusFont;
	LOGFONTW	lfMessageFont;
	INT		iPaddedBorderWidth;
} NONCLIENTMETRICSW, *PNONCLIENTMETRICSW, *LPNONCLIENTMETRICSW;

DECL_WINELIB_TYPE_AW(NONCLIENTMETRICS)
DECL_WINELIB_TYPE_AW(PNONCLIENTMETRICS)
DECL_WINELIB_TYPE_AW(LPNONCLIENTMETRICS)

typedef struct tagICONMETRICSA {
    UINT cbSize;
    int iHorzSpacing;
    int iVertSpacing;
    int iTitleWrap;
    LOGFONTA lfFont;
} ICONMETRICSA, *PICONMETRICSA, *LPICONMETRICSA;

typedef struct tagICONMETRICSW {
    UINT cbSize;
    int iHorzSpacing;
    int iVertSpacing;
    int iTitleWrap;
    LOGFONTW lfFont;
} ICONMETRICSW, *PICONMETRICSW, *LPICONMETRICSW;

DECL_WINELIB_TYPE_AW(ICONMETRICS)
DECL_WINELIB_TYPE_AW(PICONMETRICS)
DECL_WINELIB_TYPE_AW(LPICONMETRICS)

typedef struct tagUPDATELAYEREDWINDOWINFO
{
    DWORD                cbSize;
    HDC                  hdcDst;
    POINT const*         pptDst;
    SIZE const*          psize;
    HDC                  hdcSrc;
    POINT const*         pptSrc;
    COLORREF             crKey;
    BLENDFUNCTION const* pblend;
    DWORD                dwFlags;
    RECT const*          prcDirty;
} UPDATELAYEREDWINDOWINFO, *PUPDATELAYEREDWINDOWINFO;

#endif /* defined(_WINGDI_) && !defined(NOGDI) */

#define ARW_BOTTOMLEFT              __MSABI_LONG(0x0000)
#define ARW_BOTTOMRIGHT             __MSABI_LONG(0x0001)
#define ARW_TOPLEFT                 __MSABI_LONG(0x0002)
#define ARW_TOPRIGHT                __MSABI_LONG(0x0003)
#define ARW_STARTMASK               __MSABI_LONG(0x0003)
#define ARW_STARTRIGHT              __MSABI_LONG(0x0001)
#define ARW_STARTTOP                __MSABI_LONG(0x0002)

#define ARW_LEFT                    __MSABI_LONG(0x0000)
#define ARW_RIGHT                   __MSABI_LONG(0x0000)
#define ARW_UP                      __MSABI_LONG(0x0004)
#define ARW_DOWN                    __MSABI_LONG(0x0004)
#define ARW_HIDE                    __MSABI_LONG(0x0008)

typedef struct tagMINIMIZEDMETRICS {
    UINT cbSize;
    int iWidth;
    int iHorzGap;
    int iVertGap;
    int iArrange;
} MINIMIZEDMETRICS, *PMINIMIZEDMETRICS, *LPMINIMIZEDMETRICS;


/* Window scrolling */
#define SW_SCROLLCHILDREN      0x0001
#define SW_INVALIDATE          0x0002
#define SW_ERASE               0x0004

/* CreateWindow() coordinates */
#define CW_USEDEFAULT ((INT)0x80000000)

/* ChildWindowFromPointEx Flags */
#define CWP_ALL                0x0000
#define CWP_SKIPINVISIBLE      0x0001
#define CWP_SKIPDISABLED       0x0002
#define CWP_SKIPTRANSPARENT    0x0004

  /* PeekMessage() options */
#define PM_NOREMOVE       0x0000
#define PM_REMOVE         0x0001
#define PM_NOYIELD        0x0002
#define PM_QS_INPUT       (QS_INPUT << 16)
#define PM_QS_POSTMESSAGE ((QS_POSTMESSAGE | QS_HOTKEY | QS_TIMER) << 16)
#define PM_QS_PAINT       (QS_PAINT << 16)
#define PM_QS_SENDMESSAGE (QS_SENDMESSAGE << 16)

/* SetTimer() limits */
#define USER_TIMER_MINIMUM 0x0000000A
#define USER_TIMER_MAXIMUM 0x7FFFFFFF

/* SetCoalescableTimer() tolerances */
#define TIMERV_DEFAULT_COALESCING   0
#define TIMERV_NO_COALESCING        0xFFFFFFFF
#define TIMERV_COALESCING_MIN       1
#define TIMERV_COALESCING_MAX       0x7FFFFFF5

/* AnimateWindow() flags */
#define AW_SLIDE        0x00040000
#define AW_ACTIVATE     0x00020000
#define AW_BLEND        0x00080000
#define AW_HIDE         0x00010000
#define AW_CENTER       0x00000010
#define AW_HOR_POSITIVE 0x00000001
#define AW_HOR_NEGATIVE 0x00000002
#define AW_VER_POSITIVE 0x00000004
#define AW_VER_NEGATIVE 0x00000008

/* FlashWindowEx() flags */
#define FLASHW_STOP      0x00000000
#define FLASHW_CAPTION   0x00000001
#define FLASHW_TRAY      0x00000002
#define FLASHW_ALL       (FLASHW_CAPTION|FLASHW_TRAY)
#define FLASHW_TIMER     0x00000004
#define FLASHW_TIMERNOFG 0x0000000C

typedef struct {
    UINT cbSize;
    HWND hwnd;
    DWORD dwFlags;
    UINT uCount;
    DWORD dwTimeout;
} FLASHWINFO, *PFLASHWINFO;

/* SetLayeredWindowAttributes() flags */
#define LWA_COLORKEY        0x00000001
#define LWA_ALPHA           0x00000002

/* UpdateLayeredWindow() flags */
#define ULW_COLORKEY        0x00000001
#define ULW_ALPHA           0x00000002
#define ULW_OPAQUE          0x00000004
#define ULW_EX_NORESIZE     0x00000008

/* SetWindowPos() and WINDOWPOS flags */
#define SWP_NOSIZE          0x0001
#define SWP_NOMOVE          0x0002
#define SWP_NOZORDER        0x0004
#define SWP_NOREDRAW        0x0008
#define SWP_NOACTIVATE      0x0010
#define SWP_FRAMECHANGED    0x0020  /* The frame changed: send WM_NCCALCSIZE */
#define SWP_SHOWWINDOW      0x0040
#define SWP_HIDEWINDOW      0x0080
#define SWP_NOCOPYBITS      0x0100
#define SWP_NOOWNERZORDER   0x0200  /* Don't do owner Z ordering */

#define SWP_DRAWFRAME       SWP_FRAMECHANGED
#define SWP_NOREPOSITION    SWP_NOOWNERZORDER

#define SWP_NOSENDCHANGING  0x0400
#define SWP_DEFERERASE      0x2000
#define SWP_ASYNCWINDOWPOS  0x4000

/* undocumented SWP flags - from SDK 3.1 */
#define SWP_NOCLIENTSIZE    0x0800
#define SWP_NOCLIENTMOVE    0x1000
#define SWP_STATECHANGED    0x8000

#define HWND_DESKTOP        ((HWND)0)
#define HWND_BROADCAST      ((HWND)0xffff)

/* SetWindowPos() hwndInsertAfter field values */
#define HWND_TOP            ((HWND)0)
#define HWND_BOTTOM         ((HWND)1)
#define HWND_TOPMOST        ((HWND)-1)
#define HWND_NOTOPMOST      ((HWND)-2)
#define HWND_MESSAGE        ((HWND)-3)

/* GetDCEx flags */
#define DCX_WINDOW           0x00000001
#define DCX_CACHE            0x00000002
#define DCX_NORESETATTRS     0x00000004
#define DCX_CLIPCHILDREN     0x00000008
#define DCX_CLIPSIBLINGS     0x00000010
#define DCX_PARENTCLIP       0x00000020
#define DCX_EXCLUDERGN       0x00000040
#define DCX_INTERSECTRGN     0x00000080
#define DCX_EXCLUDEUPDATE    0x00000100
#define DCX_INTERSECTUPDATE  0x00000200
#define DCX_LOCKWINDOWUPDATE 0x00000400
#define DCX_USESTYLE         0x00010000
#define DCX_NORECOMPUTE      0x00100000
#define DCX_VALIDATE         0x00200000



/* for GetMenuDefaultItem */
#define GMDI_USEDISABLED    __MSABI_LONG(0x0001)
#define GMDI_GOINTOPOPUPS   __MSABI_LONG(0x0002)

/* DrawText() flags */
#define DT_TOP                  0x00000000
#define DT_LEFT                 0x00000000
#define DT_CENTER               0x00000001
#define DT_RIGHT                0x00000002
#define DT_VCENTER              0x00000004
#define DT_BOTTOM               0x00000008
#define DT_WORDBREAK            0x00000010
#define DT_SINGLELINE           0x00000020
#define DT_EXPANDTABS           0x00000040
#define DT_TABSTOP              0x00000080
#define DT_NOCLIP               0x00000100
#define DT_EXTERNALLEADING      0x00000200
#define DT_CALCRECT             0x00000400
#define DT_NOPREFIX             0x00000800
#define DT_INTERNAL             0x00001000
#define DT_EDITCONTROL          0x00002000
#define DT_PATH_ELLIPSIS        0x00004000
#define DT_END_ELLIPSIS         0x00008000
#define DT_MODIFYSTRING         0x00010000
#define DT_RTLREADING           0x00020000
#define DT_WORD_ELLIPSIS        0x00040000
#define DT_NOFULLWIDTHCHARBREAK 0x00080000
#define DT_HIDEPREFIX           0x00100000
#define DT_PREFIXONLY           0x00200000

/* DrawCaption()/DrawCaptionTemp() flags */
#define DC_ACTIVE		0x0001
#define DC_SMALLCAP		0x0002
#define DC_ICON			0x0004
#define DC_TEXT			0x0008
#define DC_INBUTTON		0x0010
#define DC_GRADIENT             0x0020
#define DC_BUTTONS              0x1000

/* DrawEdge() flags */
#define BDR_RAISEDOUTER    0x0001
#define BDR_SUNKENOUTER    0x0002
#define BDR_RAISEDINNER    0x0004
#define BDR_SUNKENINNER    0x0008

#define BDR_OUTER          0x0003
#define BDR_INNER          0x000c
#define BDR_RAISED         0x0005
#define BDR_SUNKEN         0x000a

#define EDGE_RAISED        (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#define EDGE_SUNKEN        (BDR_SUNKENOUTER | BDR_SUNKENINNER)
#define EDGE_ETCHED        (BDR_SUNKENOUTER | BDR_RAISEDINNER)
#define EDGE_BUMP          (BDR_RAISEDOUTER | BDR_SUNKENINNER)

/* border flags */
#define BF_LEFT            0x0001
#define BF_TOP             0x0002
#define BF_RIGHT           0x0004
#define BF_BOTTOM          0x0008
#define BF_DIAGONAL        0x0010
#define BF_MIDDLE          0x0800  /* Fill in the middle */
#define BF_SOFT            0x1000  /* For softer buttons */
#define BF_ADJUST          0x2000  /* Calculate the space left over */
#define BF_FLAT            0x4000  /* For flat rather than 3D borders */
#define BF_MONO            0x8000  /* For monochrome borders */
#define BF_TOPLEFT         (BF_TOP | BF_LEFT)
#define BF_TOPRIGHT        (BF_TOP | BF_RIGHT)
#define BF_BOTTOMLEFT      (BF_BOTTOM | BF_LEFT)
#define BF_BOTTOMRIGHT     (BF_BOTTOM | BF_RIGHT)
#define BF_RECT            (BF_LEFT | BF_TOP | BF_RIGHT | BF_BOTTOM)
#define BF_DIAGONAL_ENDTOPRIGHT     (BF_DIAGONAL | BF_TOP | BF_RIGHT)
#define BF_DIAGONAL_ENDTOPLEFT      (BF_DIAGONAL | BF_TOP | BF_LEFT)
#define BF_DIAGONAL_ENDBOTTOMLEFT   (BF_DIAGONAL | BF_BOTTOM | BF_LEFT)
#define BF_DIAGONAL_ENDBOTTOMRIGHT  (BF_DIAGONAL | BF_BOTTOM | BF_RIGHT)

/* DrawFrameControl() uType's */

#define DFC_CAPTION             1
#define DFC_MENU                2
#define DFC_SCROLL              3
#define DFC_BUTTON              4
#define DFC_POPUPMENU           5

/* uState's */

#define DFCS_CAPTIONCLOSE       0x0000
#define DFCS_CAPTIONMIN         0x0001
#define DFCS_CAPTIONMAX         0x0002
#define DFCS_CAPTIONRESTORE     0x0003
#define DFCS_CAPTIONHELP        0x0004		/* Windows 95 only */

#define DFCS_MENUARROW          0x0000
#define DFCS_MENUCHECK          0x0001
#define DFCS_MENUBULLET         0x0002
#define DFCS_MENUARROWRIGHT     0x0004

#define DFCS_SCROLLUP            0x0000
#define DFCS_SCROLLDOWN          0x0001
#define DFCS_SCROLLLEFT          0x0002
#define DFCS_SCROLLRIGHT         0x0003
#define DFCS_SCROLLCOMBOBOX      0x0005
#define DFCS_SCROLLSIZEGRIP      0x0008
#define DFCS_SCROLLSIZEGRIPRIGHT 0x0010

#define DFCS_BUTTONCHECK        0x0000
#define DFCS_BUTTONRADIOIMAGE   0x0001
#define DFCS_BUTTONRADIOMASK    0x0002		/* to draw nonsquare button */
#define DFCS_BUTTONRADIO        0x0004
#define DFCS_BUTTON3STATE       0x0008
#define DFCS_BUTTONPUSH         0x0010

/* additional state of the control */

#define DFCS_INACTIVE           0x0100
#define DFCS_PUSHED             0x0200
#define DFCS_CHECKED            0x0400
#define DFCS_TRANSPARENT        0x0800
#define DFCS_HOT                0x1000
#define DFCS_ADJUSTRECT         0x2000		/* exclude surrounding edge */
#define DFCS_FLAT               0x4000
#define DFCS_MONO               0x8000


/* Image type */
#define	DST_COMPLEX	0x0000
#define	DST_TEXT	0x0001
#define	DST_PREFIXTEXT	0x0002
#define	DST_ICON	0x0003
#define	DST_BITMAP	0x0004

/* State type */
#define	DSS_NORMAL	0x0000
#define	DSS_UNION	0x0010  /* Gray string appearance */
#define	DSS_DISABLED	0x0020
#define	DSS_DEFAULT	0x0040  /* Make it bold */
#define	DSS_MONO	0x0080
#define	DSS_HIDEPREFIX	0x0200
#define	DSS_PREFIXONLY	0x0400
#define	DSS_RIGHT	0x8000

/* UserObjectInformation classes */
#define UOI_FLAGS 1
#define UOI_NAME 2
#define UOI_TYPE 3
#define UOI_USER_SID 4


/* Sent as the lParam of a WM_DRAWITEM message to instruct how an
 * owner drawn control is to be drawn */
typedef struct tagDRAWITEMSTRUCT
{
    UINT      CtlType;    /* Type of control (ODT_* flags from "winuser.h") */
    UINT      CtlID;      /* Control ID */
    UINT      itemID;     /* Menu item ID */
    UINT      itemAction; /* Action to perform (ODA_* flags from "winuser.h") */
    UINT      itemState;  /* Item state (ODS_* flags from "winuser.h") */
    HWND      hwndItem;   /* Control window */
    HDC       hDC;        /* Device context to draw to */
    RECT      rcItem;     /* Position of the control in hDC */
    ULONG_PTR itemData;   /* Extra data added by the application, if any */
} DRAWITEMSTRUCT, *PDRAWITEMSTRUCT, *LPDRAWITEMSTRUCT;


typedef struct tagMEASUREITEMSTRUCT
{
    UINT      CtlType;
    UINT      CtlID;
    UINT      itemID;
    UINT      itemWidth;
    UINT      itemHeight;
    ULONG_PTR itemData;
} MEASUREITEMSTRUCT, *PMEASUREITEMSTRUCT, *LPMEASUREITEMSTRUCT;


typedef struct tagDELETEITEMSTRUCT
{
    UINT     CtlType;
    UINT     CtlID;
    UINT     itemID;
    HWND     hwndItem;
    ULONG_PTR itemData;
} DELETEITEMSTRUCT, *PDELETEITEMSTRUCT, *LPDELETEITEMSTRUCT;


typedef struct tagCOMPAREITEMSTRUCT
{
    UINT      CtlType;
    UINT      CtlID;
    HWND      hwndItem;
    UINT      itemID1;
    ULONG_PTR itemData1;
    UINT      itemID2;
    ULONG_PTR itemData2;
    DWORD     dwLocaleId;
} COMPAREITEMSTRUCT, *PCOMPAREITEMSTRUCT, *LPCOMPAREITEMSTRUCT;


/* WM_KEYUP/DOWN/CHAR HIWORD(lParam) flags */
#define KF_EXTENDED         0x0100
#define KF_DLGMODE          0x0800
#define KF_MENUMODE         0x1000
#define KF_ALTDOWN          0x2000
#define KF_REPEAT           0x4000
#define KF_UP               0x8000


/* MapVirtualKey translation types */
#define MAPVK_VK_TO_VSC     0
#define MAPVK_VSC_TO_VK     1
#define MAPVK_VK_TO_CHAR    2
#define MAPVK_VSC_TO_VK_EX  3
#define MAPVK_VK_TO_VSC_EX  4



typedef struct tagTRACKMOUSEEVENT {
    DWORD cbSize;
    DWORD dwFlags;
    HWND  hwndTrack;
    DWORD dwHoverTime;
} TRACKMOUSEEVENT, *LPTRACKMOUSEEVENT;

  /* Queue status flags */
#define QS_KEY		0x0001
#define QS_MOUSEMOVE	0x0002
#define QS_MOUSEBUTTON	0x0004
#define QS_MOUSE	(QS_MOUSEMOVE | QS_MOUSEBUTTON)
#define QS_POSTMESSAGE	0x0008
#define QS_TIMER	0x0010
#define QS_PAINT	0x0020
#define QS_SENDMESSAGE	0x0040
#define QS_HOTKEY	0x0080
#define QS_ALLPOSTMESSAGE 0x0100
#define QS_RAWINPUT       0x0400
#define QS_INPUT	(QS_MOUSE | QS_KEY | QS_RAWINPUT)
#define QS_ALLEVENTS	(QS_INPUT | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY)
#define QS_ALLINPUT     (QS_ALLEVENTS | QS_SENDMESSAGE)

/* Extra (undocumented) queue wake bits - see "Undoc. Windows" */
#define QS_SMRESULT      0x8000

/* InSendMessageEx flags */
#define ISMEX_NOSEND      0x00000000
#define ISMEX_SEND        0x00000001
#define ISMEX_NOTIFY      0x00000002
#define ISMEX_CALLBACK    0x00000004
#define ISMEX_REPLIED     0x00000008

#define DDL_READWRITE	0x0000
#define DDL_READONLY	0x0001
#define DDL_HIDDEN	0x0002
#define DDL_SYSTEM	0x0004
#define DDL_DIRECTORY	0x0010
#define DDL_ARCHIVE	0x0020

#define DDL_POSTMSGS	0x2000
#define DDL_DRIVES	0x4000
#define DDL_EXCLUSIVE	0x8000

  /* Shell hook values */
#define HSHELL_WINDOWCREATED       1
#define HSHELL_WINDOWDESTROYED     2
#define HSHELL_ACTIVATESHELLWINDOW 3
#define HSHELL_WINDOWACTIVATED     4
#define HSHELL_GETMINRECT          5
#define HSHELL_REDRAW              6
#define HSHELL_TASKMAN             7
#define HSHELL_LANGUAGE            8
#define HSHELL_SYSMENU             9
#define HSHELL_ENDTASK             10
#define HSHELL_ACCESSIBILITYSTATE  11
#define HSHELL_APPCOMMAND          12
#define HSHELL_WINDOWREPLACED      13
#define HSHELL_WINDOWREPLACING     14

#define HSHELL_HIGHBIT             0x8000
#define HSHELL_FLASH               (HSHELL_REDRAW|HSHELL_HIGHBIT)
#define HSHELL_RUDEAPPACTIVATED    (HSHELL_WINDOWACTIVATED|HSHELL_HIGHBIT)

/* App commands */
#define APPCOMMAND_BROWSER_BACKWARD                  1
#define APPCOMMAND_BROWSER_FORWARD                   2
#define APPCOMMAND_BROWSER_REFRESH                   3
#define APPCOMMAND_BROWSER_STOP                      4
#define APPCOMMAND_BROWSER_SEARCH                    5
#define APPCOMMAND_BROWSER_FAVORITES                 6
#define APPCOMMAND_BROWSER_HOME                      7
#define APPCOMMAND_VOLUME_MUTE                       8
#define APPCOMMAND_VOLUME_DOWN                       9
#define APPCOMMAND_VOLUME_UP                         10
#define APPCOMMAND_MEDIA_NEXTTRACK                   11
#define APPCOMMAND_MEDIA_PREVIOUSTRACK               12
#define APPCOMMAND_MEDIA_STOP                        13
#define APPCOMMAND_MEDIA_PLAY_PAUSE                  14
#define APPCOMMAND_LAUNCH_MAIL                       15
#define APPCOMMAND_LAUNCH_MEDIA_SELECT               16
#define APPCOMMAND_LAUNCH_APP1                       17
#define APPCOMMAND_LAUNCH_APP2                       18
#define APPCOMMAND_BASS_DOWN                         19
#define APPCOMMAND_BASS_BOOST                        20
#define APPCOMMAND_BASS_UP                           21
#define APPCOMMAND_TREBLE_DOWN                       22
#define APPCOMMAND_TREBLE_UP                         23
#define APPCOMMAND_MICROPHONE_VOLUME_MUTE            24
#define APPCOMMAND_MICROPHONE_VOLUME_DOWN            25
#define APPCOMMAND_MICROPHONE_VOLUME_UP              26
#define APPCOMMAND_HELP                              27
#define APPCOMMAND_FIND                              28
#define APPCOMMAND_NEW                               29
#define APPCOMMAND_OPEN                              30
#define APPCOMMAND_CLOSE                             31
#define APPCOMMAND_SAVE                              32
#define APPCOMMAND_PRINT                             33
#define APPCOMMAND_UNDO                              34
#define APPCOMMAND_REDO                              35
#define APPCOMMAND_COPY                              36
#define APPCOMMAND_CUT                               37
#define APPCOMMAND_PASTE                             38
#define APPCOMMAND_REPLY_TO_MAIL                     39
#define APPCOMMAND_FORWARD_MAIL                      40
#define APPCOMMAND_SEND_MAIL                         41
#define APPCOMMAND_SPELL_CHECK                       42
#define APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE 43
#define APPCOMMAND_MIC_ON_OFF_TOGGLE                 44
#define APPCOMMAND_CORRECTION_LIST                   45
#define APPCOMMAND_MEDIA_PLAY                        46
#define APPCOMMAND_MEDIA_PAUSE                       47
#define APPCOMMAND_MEDIA_RECORD                      48
#define APPCOMMAND_MEDIA_FAST_FORWARD                49
#define APPCOMMAND_MEDIA_REWIND                      50
#define APPCOMMAND_MEDIA_CHANNEL_UP                  51
#define APPCOMMAND_MEDIA_CHANNEL_DOWN                52
#define APPCOMMAND_DELETE                            53
#define APPCOMMAND_DWM_FLIP3D                        54

#define FAPPCOMMAND_MOUSE 0x8000
#define FAPPCOMMAND_KEY   0
#define FAPPCOMMAND_OEM   0x1000
#define FAPPCOMMAND_MASK  0xF000

#define GET_APPCOMMAND_LPARAM(lParam) ((short)(HIWORD(lParam) & ~FAPPCOMMAND_MASK))
#define GET_DEVICE_LPARAM(lParam)     ((WORD)(HIWORD(lParam) & FAPPCOMMAND_MASK))
#define GET_MOUSEORKEY_LPARAM         GET_DEVICE_LPARAM
#define GET_FLAGS_LPARAM(lParam)      (LOWORD(lParam))
#define GET_KEYSTATE_LPARAM(lParam)   GET_FLAGS_LPARAM(lParam)


/* types of LoadImage */
#define IMAGE_BITMAP	0
#define IMAGE_ICON	1
#define IMAGE_CURSOR	2
#define IMAGE_ENHMETAFILE	3

/* loadflags to LoadImage */
#define LR_DEFAULTCOLOR		0x0000
#define LR_MONOCHROME		0x0001
#define LR_COLOR		0x0002
#define LR_COPYRETURNORG	0x0004
#define LR_COPYDELETEORG	0x0008
#define LR_LOADFROMFILE		0x0010
#define LR_LOADTRANSPARENT	0x0020
#define LR_DEFAULTSIZE		0x0040
#define LR_VGA_COLOR		0x0080
#define LR_LOADMAP3DCOLORS	0x1000
#define	LR_CREATEDIBSECTION	0x2000
#define LR_COPYFROMRESOURCE	0x4000
#define LR_SHARED		0x8000

/* Flags for DrawIconEx.  */
#define DI_MASK                 0x0001
#define DI_IMAGE                0x0002
#define DI_NORMAL               (DI_MASK | DI_IMAGE)
#define DI_COMPAT               0x0004
#define DI_DEFAULTSIZE          0x0008
#define DI_NOMIRROR             0x0010

/* RegisterDeviceNotification stuff */
typedef  PVOID           HDEVNOTIFY;
typedef  HDEVNOTIFY     *PHDEVNOTIFY;

#define DEVICE_NOTIFY_WINDOW_HANDLE     0x00000000

/* used for GetWindowInfo() */

#define WS_ACTIVECAPTION    0x0001

typedef struct tagWINDOWINFO {
    DWORD cbSize;
    RECT  rcWindow;
    RECT  rcClient;
    DWORD dwStyle;
    DWORD dwExStyle;
    DWORD dwWindowStatus;
    UINT  cxWindowBorders;
    UINT  cyWindowBorders;
    ATOM  atomWindowType;
    WORD  wCreatorVersion;
} WINDOWINFO, *PWINDOWINFO, *LPWINDOWINFO;

/* used for GetTitleBarInfo() */

#define CCHILDREN_TITLEBAR      5

typedef struct tagTITLEBARINFO {
    DWORD cbSize;
    RECT  rcTitleBar;
    DWORD rgstate[CCHILDREN_TITLEBAR+1];
} TITLEBARINFO, *PTITLEBARINFO, *LPTITLEBARINFO;

/* used by GetLastInputInfo */
typedef struct tagLASTINPUTINFO {
    UINT cbSize;
    DWORD dwTime;
} LASTINPUTINFO, *PLASTINPUTINFO;

/* used by GetAltTabInfo */
typedef struct
{
    DWORD cbSize;
    INT cItems;
    INT cColumns;
    INT cRows;
    INT iColFocus;
    INT iRowFocus;
    INT cxItem;
    INT cyItem;
    POINT ptStart;
} ALTTABINFO, *PALTTABINFO, *LPALTTABINFO;

/* SetWinEventHook() flags */
#define WINEVENT_OUTOFCONTEXT   0x0
#define WINEVENT_SKIPOWNTHREAD  0x1
#define WINEVENT_SKIPOWNPROCESS 0x2
#define WINEVENT_INCONTEXT      0x4

#define ENDSESSION_LOGOFF    0x80000000

/* Object Id's */
#define CHILDID_SELF      0
#define INDEXID_OBJECT    0
#define INDEXID_CONTAINER 0

/* System object Id's */
#define OBJID_WINDOW            0
#define OBJID_SYSMENU           -1
#define OBJID_TITLEBAR          -2
#define OBJID_MENU              -3
#define OBJID_CLIENT            -4
#define OBJID_VSCROLL           -5
#define OBJID_HSCROLL           -6
#define OBJID_SIZEGRIP          -7
#define OBJID_CARET             -8
#define OBJID_CURSOR            -9
#define OBJID_ALERT             -10
#define OBJID_SOUND             -11
#define OBJID_QUERYCLASSNAMEIDX -12
#define OBJID_NATIVEOM          -16

/* User event Id limits */
#define EVENT_MIN 0x00000001
#define EVENT_MAX 0x7FFFFFFF

/* System events */
#define EVENT_SYSTEM_SOUND            0x01
#define EVENT_SYSTEM_ALERT            0x02
#define EVENT_SYSTEM_FOREGROUND       0x03
#define EVENT_SYSTEM_MENUSTART        0x04
#define EVENT_SYSTEM_MENUEND          0x05
#define EVENT_SYSTEM_MENUPOPUPSTART   0x06
#define EVENT_SYSTEM_MENUPOPUPEND     0x07
#define EVENT_SYSTEM_CAPTURESTART     0x08
#define EVENT_SYSTEM_CAPTUREEND       0x09
#define EVENT_SYSTEM_MOVESIZESTART    0x0A
#define EVENT_SYSTEM_MOVESIZEEND      0x0B
#define EVENT_SYSTEM_CONTEXTHELPSTART 0x0C
#define EVENT_SYSTEM_CONTEXTHELPEND   0x0D
#define EVENT_SYSTEM_DRAGDROPSTART    0x0E
#define EVENT_SYSTEM_DRAGDROPEND      0x0F
#define EVENT_SYSTEM_DIALOGSTART      0x10
#define EVENT_SYSTEM_DIALOGEND        0x11
#define EVENT_SYSTEM_SCROLLINGSTART   0x12
#define EVENT_SYSTEM_SCROLLINGEND     0x13
#define EVENT_SYSTEM_SWITCHSTART      0x14
#define EVENT_SYSTEM_SWITCHEND        0x15
#define EVENT_SYSTEM_MINIMIZESTART    0x16
#define EVENT_SYSTEM_MINIMIZEEND      0x17

/* Console events */
#define EVENT_CONSOLE_CARET             0x4001
#define EVENT_CONSOLE_UPDATE_REGION     0x4002
#define EVENT_CONSOLE_UPDATE_SIMPLE     0x4003
#define EVENT_CONSOLE_UPDATE_SCROLL     0x4004
#define EVENT_CONSOLE_LAYOUT            0x4005
#define EVENT_CONSOLE_START_APPLICATION 0x4006
#define EVENT_CONSOLE_END_APPLICATION   0x4007

#define CONSOLE_APPLICATION_16BIT 0x1
#define CONSOLE_CARET_SELECTION   0x1
#define CONSOLE_CARET_VISIBLE     0x2

/* Object events */
#define EVENT_OBJECT_CREATE            0x8000
#define EVENT_OBJECT_DESTROY           0x8001
#define EVENT_OBJECT_SHOW              0x8002
#define EVENT_OBJECT_HIDE              0x8003
#define EVENT_OBJECT_REORDER           0x8004
#define EVENT_OBJECT_FOCUS             0x8005
#define EVENT_OBJECT_SELECTION         0x8006
#define EVENT_OBJECT_SELECTIONADD      0x8007
#define EVENT_OBJECT_SELECTIONREMOVE   0x8008
#define EVENT_OBJECT_SELECTIONWITHIN   0x8009
#define EVENT_OBJECT_STATECHANGE       0x800A
#define EVENT_OBJECT_LOCATIONCHANGE    0x800B
#define EVENT_OBJECT_NAMECHANGE        0x800C
#define EVENT_OBJECT_DESCRIPTIONCHANGE 0x800D
#define EVENT_OBJECT_VALUECHANGE       0x800E
#define EVENT_OBJECT_PARENTCHANGE      0x800F
#define EVENT_OBJECT_HELPCHANGE        0x8010
#define EVENT_OBJECT_DEFACTIONCHANGE   0x8011
#define EVENT_OBJECT_ACCELERATORCHANGE 0x8012

/* Sound events */
#define SOUND_SYSTEM_STARTUP      1
#define SOUND_SYSTEM_SHUTDOWN     2
#define SOUND_SYSTEM_BEEP         3
#define SOUND_SYSTEM_ERROR        4
#define SOUND_SYSTEM_QUESTION     5
#define SOUND_SYSTEM_WARNING      6
#define SOUND_SYSTEM_INFORMATION  7
#define SOUND_SYSTEM_MAXIMIZE     8
#define SOUND_SYSTEM_MINIMIZE     9
#define SOUND_SYSTEM_RESTOREUP   10
#define SOUND_SYSTEM_RESTOREDOWN 11
#define SOUND_SYSTEM_APPSTART    12
#define SOUND_SYSTEM_FAULT       13
#define SOUND_SYSTEM_APPEND      14
#define SOUND_SYSTEM_MENUCOMMAND 15
#define SOUND_SYSTEM_MENUPOPUP   16
#define CSOUND_SYSTEM            16

/* Alert events */
#define ALERT_SYSTEM_INFORMATIONAL 1
#define ALERT_SYSTEM_WARNING       2
#define ALERT_SYSTEM_ERROR         3
#define ALERT_SYSTEM_QUERY         4
#define ALERT_SYSTEM_CRITICAL      5
#define CALERT_SYSTEM              6

/* System state flags */
#define STATE_SYSTEM_UNAVAILABLE     0x00000001
#define STATE_SYSTEM_SELECTED        0x00000002
#define STATE_SYSTEM_FOCUSED         0x00000004
#define STATE_SYSTEM_PRESSED         0x00000008
#define STATE_SYSTEM_CHECKED         0x00000010
#define STATE_SYSTEM_MIXED           0x00000020
#define STATE_SYSTEM_INDETERMINATE   STATE_SYSTEM_MIXED
#define STATE_SYSTEM_READONLY        0x00000040
#define STATE_SYSTEM_HOTTRACKED      0x00000080
#define STATE_SYSTEM_DEFAULT         0x00000100
#define STATE_SYSTEM_EXPANDED        0x00000200
#define STATE_SYSTEM_COLLAPSED       0x00000400
#define STATE_SYSTEM_BUSY            0x00000800
#define STATE_SYSTEM_FLOATING        0x00001000
#define STATE_SYSTEM_MARQUEED        0x00002000
#define STATE_SYSTEM_ANIMATED        0x00004000
#define STATE_SYSTEM_INVISIBLE       0x00008000
#define STATE_SYSTEM_OFFSCREEN       0x00010000
#define STATE_SYSTEM_SIZEABLE        0x00020000
#define STATE_SYSTEM_MOVEABLE        0x00040000
#define STATE_SYSTEM_SELFVOICING     0x00080000
#define STATE_SYSTEM_FOCUSABLE       0x00100000
#define STATE_SYSTEM_SELECTABLE      0x00200000
#define STATE_SYSTEM_LINKED          0x00400000
#define STATE_SYSTEM_TRAVERSED       0x00800000
#define STATE_SYSTEM_MULTISELECTABLE 0x01000000
#define STATE_SYSTEM_EXTSELECTABLE   0x02000000
#define STATE_SYSTEM_ALERT_LOW       0x04000000
#define STATE_SYSTEM_ALERT_MEDIUM    0x08000000
#define STATE_SYSTEM_ALERT_HIGH      0x10000000
#define STATE_SYSTEM_PROTECTED       0x20000000
#define STATE_SYSTEM_VALID           0x3FFFFFFF

/* Lock codes for LockSetForegroundWindow */
#define LSFW_LOCK   1
#define LSFW_UNLOCK 2

/* Values for AllowSetForegroundWindow */
#define ASFW_ANY    ((DWORD)-1)

#define     EnumTaskWindows(handle,proc,lparam) \
            EnumThreadWindows(handle,proc,lparam)
#define     OemToAnsiA OemToCharA
#define     OemToAnsiW OemToCharW
#define     OemToAnsi WINELIB_NAME_AW(OemToAnsi)
#define     OemToAnsiBuffA OemToCharBuffA
#define     OemToAnsiBuffW OemToCharBuffW
#define     OemToAnsiBuff WINELIB_NAME_AW(OemToAnsiBuff)
#define     AnsiToOemA CharToOemA
#define     AnsiToOemW CharToOemW
#define     AnsiToOem WINELIB_NAME_AW(AnsiToOem)
#define     AnsiToOemBuffA CharToOemBuffA
#define     AnsiToOemBuffW CharToOemBuffW
#define     AnsiToOemBuff WINELIB_NAME_AW(AnsiToOemBuff)

/* ChangeWindowMessageFilter flags */
#define  MSGFLT_ADD    1
#define  MSGFLT_REMOVE 2

/* ChangeWindowMessageFilterEx defines */
#define  MSGFLTINFO_NONE                     0
#define  MSGFLTINFO_ALREADYALLOWED_FORWND    1
#define  MSGFLTINFO_ALREADYDISALLOWED_FORWND 2
#define  MSGFLTINFO_ALLOWED_HIGHER           3

typedef struct tagCHANGEFILTERSTRUCT
{
    DWORD cbSize;
    DWORD ExtStatus;
} CHANGEFILTERSTRUCT, *PCHANGEFILTERSTRUCT;

/* Actions for ChangeWindowMessageFilterEx */
#define  MSGFLT_RESET    0
#define  MSGFLT_ALLOW    1
#define  MSGFLT_DISALLOW 2

#define USER_DEFAULT_SCREEN_DPI 96

typedef enum tagAR_STATE {
    AR_ENABLED       = 0x0,
    AR_DISABLED      = 0x1,
    AR_SUPPRESSED    = 0x2,
    AR_REMOTESESSION = 0x4,
    AR_MULTIMON      = 0x8,
    AR_NOSENSOR      = 0x10,
    AR_NOT_SUPPORTED = 0x20,
    AR_DOCKED        = 0x40,
    AR_LAPTOP        = 0x80
} AR_STATE, *PAR_STATE;

typedef enum ORIENTATION_PREFERENCE {
    ORIENTATION_PREFERENCE_NONE              = 0x0,
    ORIENTATION_PREFERENCE_LANDSCAPE         = 0x1,
    ORIENTATION_PREFERENCE_PORTRAIT          = 0x2,
    ORIENTATION_PREFERENCE_LANDSCAPE_FLIPPED = 0x4,
    ORIENTATION_PREFERENCE_PORTRAIT_FLIPPED  = 0x8
} ORIENTATION_PREFERENCE;

/* Touch input definitions */
DECLARE_HANDLE(HTOUCHINPUT);

typedef struct tagTOUCHINPUT {
    LONG      x;
    LONG      y;
    HANDLE    hSource;
    DWORD     dwID;
    DWORD     dwFlags;
    DWORD     dwMask;
    DWORD     dwTime;
    ULONG_PTR dwExtraInfo;
    DWORD     cxContact;
    DWORD     cyContact;
} TOUCHINPUT, *PTOUCHINPUT;
typedef TOUCHINPUT const * PCTOUCHINPUT;

/* Gesture definitions */
DECLARE_HANDLE(HGESTUREINFO);

typedef struct tagGESTUREINFO {
    UINT      cbSize;
    DWORD     dwFlags;
    DWORD     dwID;
    HWND      hwndTarget;
    POINTS    ptsLocation;
    DWORD     dwInstanceID;
    DWORD     dwSequenceID;
    ULONGLONG ullArguments;
    UINT      cbExtraArgs;
} GESTUREINFO, *PGESTUREINFO;
typedef GESTUREINFO const * PCGESTUREINFO;

#if defined(_WINGDI_) && !defined(NOGDI)
WINUSERAPI LONG        WINAPI ChangeDisplaySettingsA(LPDEVMODEA,DWORD);
WINUSERAPI LONG        WINAPI ChangeDisplaySettingsW(LPDEVMODEW,DWORD);
#define                       ChangeDisplaySettings WINELIB_NAME_AW(ChangeDisplaySettings)
WINUSERAPI LONG        WINAPI ChangeDisplaySettingsExA(LPCSTR,LPDEVMODEA,HWND,DWORD,LPVOID);
WINUSERAPI LONG        WINAPI ChangeDisplaySettingsExW(LPCWSTR,LPDEVMODEW,HWND,DWORD,LPVOID);
#define                       ChangeDisplaySettingsEx WINELIB_NAME_AW(ChangeDisplaySettingsEx)
WINUSERAPI HDESK       WINAPI CreateDesktopA(LPCSTR,LPCSTR,LPDEVMODEA,DWORD,ACCESS_MASK,LPSECURITY_ATTRIBUTES);
WINUSERAPI HDESK       WINAPI CreateDesktopW(LPCWSTR,LPCWSTR,LPDEVMODEW,DWORD,ACCESS_MASK,LPSECURITY_ATTRIBUTES);
#define                       CreateDesktop WINELIB_NAME_AW(CreateDesktop)
WINUSERAPI LONG        WINAPI DisplayConfigGetDeviceInfo(DISPLAYCONFIG_DEVICE_INFO_HEADER *);
WINUSERAPI BOOL        WINAPI EnumDisplayDevicesA(LPCSTR,DWORD,LPDISPLAY_DEVICEA,DWORD);
WINUSERAPI BOOL        WINAPI EnumDisplayDevicesW(LPCWSTR,DWORD,LPDISPLAY_DEVICEW,DWORD);
#define                       EnumDisplayDevices WINELIB_NAME_AW(EnumDisplayDevices)
WINUSERAPI BOOL        WINAPI EnumDisplaySettingsA(LPCSTR,DWORD,LPDEVMODEA);
WINUSERAPI BOOL        WINAPI EnumDisplaySettingsW(LPCWSTR,DWORD,LPDEVMODEW);
#define                       EnumDisplaySettings WINELIB_NAME_AW(EnumDisplaySettings)
WINUSERAPI BOOL        WINAPI EnumDisplaySettingsExA(LPCSTR,DWORD,LPDEVMODEA,DWORD);
WINUSERAPI BOOL        WINAPI EnumDisplaySettingsExW(LPCWSTR,DWORD,LPDEVMODEW,DWORD);
#define                       EnumDisplaySettingsEx WINELIB_NAME_AW(EnumDisplaySettingsEx)
WINUSERAPI LONG        WINAPI GetDisplayConfigBufferSizes(UINT32,UINT32*,UINT32*);
WINUSERAPI BOOL        WINAPI UpdateLayeredWindow(HWND,HDC,POINT*,SIZE*,HDC,POINT*,COLORREF,BLENDFUNCTION*,DWORD);
WINUSERAPI BOOL        WINAPI UpdateLayeredWindowIndirect(HWND,UPDATELAYEREDWINDOWINFO const*);
#endif /* defined(_WINGDI_) && !defined(NOGDI) */

WINUSERAPI HKL         WINAPI ActivateKeyboardLayout(HKL,UINT);
WINUSERAPI BOOL        WINAPI AddClipboardFormatListener(HWND);
WINUSERAPI BOOL        WINAPI AdjustWindowRect(LPRECT,DWORD,BOOL);
WINUSERAPI BOOL        WINAPI AdjustWindowRectEx(LPRECT,DWORD,BOOL,DWORD);
WINUSERAPI BOOL        WINAPI AllowSetForegroundWindow(DWORD);
WINUSERAPI BOOL        WINAPI AnimateWindow(HWND,DWORD,DWORD);
#define                       AnsiLowerA CharLowerA
#define                       AnsiLowerW CharLowerW
#define                       AnsiLower WINELIB_NAME_AW(AnsiLower)
#define                       AnsiLowerBuffA CharLowerBuffA
#define                       AnsiLowerBuffW CharLowerBuffW
#define                       AnsiLowerBuff WINELIB_NAME_AW(AnsiLowerBuff)
#define                       AnsiNextA CharNextA
#define                       AnsiNextW CharNextW
#define                       AnsiNext WINELIB_NAME_AW(AnsiNext)
#define                       AnsiPrevA CharPrevA
#define                       AnsiPrevW CharPrevW
#define                       AnsiPrev WINELIB_NAME_AW(AnsiPrev)
#define                       AnsiUpperA CharUpperA
#define                       AnsiUpperW CharUpperW
#define                       AnsiUpper WINELIB_NAME_AW(AnsiUpper)
#define                       AnsiUpperBuffA CharUpperBuffA
#define                       AnsiUpperBuffW CharUpperBuffW
#define                       AnsiUpperBuff WINELIB_NAME_AW(AnsiUpperBuff)
WINUSERAPI BOOL        WINAPI AnyPopup(void);
WINUSERAPI BOOL        WINAPI AppendMenuA(HMENU,UINT,UINT_PTR,LPCSTR);
WINUSERAPI BOOL        WINAPI AppendMenuW(HMENU,UINT,UINT_PTR,LPCWSTR);
#define                       AppendMenu WINELIB_NAME_AW(AppendMenu)
WINUSERAPI UINT        WINAPI ArrangeIconicWindows(HWND);
WINUSERAPI BOOL        WINAPI AttachThreadInput(DWORD,DWORD,BOOL);
WINUSERAPI HDWP        WINAPI BeginDeferWindowPos(INT);
WINUSERAPI HDC         WINAPI BeginPaint(HWND,LPPAINTSTRUCT);
WINUSERAPI BOOL        WINAPI BlockInput(BOOL);
WINUSERAPI BOOL        WINAPI BringWindowToTop(HWND);
WINUSERAPI LONG        WINAPI BroadcastSystemMessageA(DWORD,LPDWORD,UINT,WPARAM,LPARAM);
WINUSERAPI LONG        WINAPI BroadcastSystemMessageW(DWORD,LPDWORD,UINT,WPARAM,LPARAM);
#define                       BroadcastSystemMessage WINELIB_NAME_AW(BroadcastSystemMessage)
WINUSERAPI LONG        WINAPI BroadcastSystemMessageExA(DWORD,LPDWORD,UINT,WPARAM,LPARAM,PBSMINFO);
WINUSERAPI LONG        WINAPI BroadcastSystemMessageExW(DWORD,LPDWORD,UINT,WPARAM,LPARAM,PBSMINFO);
#define                       BroadcastSystemMessageEx WINELIB_NAME_AW(BroadcastSystemMessageEx)
WINUSERAPI void        WINAPI CalcChildScroll(HWND, INT);
WINUSERAPI BOOL        WINAPI CallMsgFilterA(LPMSG,INT);
WINUSERAPI BOOL        WINAPI CallMsgFilterW(LPMSG,INT);
#define                       CallMsgFilter WINELIB_NAME_AW(CallMsgFilter)
WINUSERAPI LRESULT     WINAPI CallNextHookEx(HHOOK,INT,WPARAM,LPARAM);
WINUSERAPI LRESULT     WINAPI CallWindowProcA(WNDPROC,HWND,UINT,WPARAM,LPARAM);
WINUSERAPI LRESULT     WINAPI CallWindowProcW(WNDPROC,HWND,UINT,WPARAM,LPARAM);
#define                       CallWindowProc WINELIB_NAME_AW(CallWindowProc)
WINUSERAPI WORD        WINAPI CascadeWindows(HWND, UINT, const RECT *, UINT, const HWND *);
WINUSERAPI BOOL        WINAPI ChangeClipboardChain(HWND,HWND);
WINUSERAPI BOOL        WINAPI ChangeMenuA(HMENU,UINT,LPCSTR,UINT,UINT);
WINUSERAPI BOOL        WINAPI ChangeMenuW(HMENU,UINT,LPCWSTR,UINT,UINT);
#define                       ChangeMenu WINELIB_NAME_AW(ChangeMenu)
WINUSERAPI BOOL        WINAPI ChangeWindowMessageFilter(UINT,DWORD);
WINUSERAPI BOOL        WINAPI ChangeWindowMessageFilterEx(HWND,UINT,DWORD,CHANGEFILTERSTRUCT*);
WINUSERAPI LPSTR       WINAPI CharLowerA(LPSTR);
WINUSERAPI LPWSTR      WINAPI CharLowerW(LPWSTR);
#define                       CharLower WINELIB_NAME_AW(CharLower)
WINUSERAPI DWORD       WINAPI CharLowerBuffA(LPSTR,DWORD);
WINUSERAPI DWORD       WINAPI CharLowerBuffW(LPWSTR,DWORD);
#define                       CharLowerBuff WINELIB_NAME_AW(CharLowerBuff)
WINUSERAPI LPSTR       WINAPI CharNextA(LPCSTR);
WINUSERAPI LPWSTR      WINAPI CharNextW(LPCWSTR);
#define                       CharNext WINELIB_NAME_AW(CharNext)
WINUSERAPI LPSTR       WINAPI CharNextExA(WORD,LPCSTR,DWORD);
/* no CharNextExW (doesn't make sense) */
WINUSERAPI LPSTR       WINAPI CharPrevA(LPCSTR,LPCSTR);
WINUSERAPI LPWSTR      WINAPI CharPrevW(LPCWSTR,LPCWSTR);
#define                       CharPrev WINELIB_NAME_AW(CharPrev)
WINUSERAPI LPSTR       WINAPI CharPrevExA(WORD,LPCSTR,LPCSTR,DWORD);
/* no CharPrevExW (doesn't make sense) */
WINUSERAPI LPSTR       WINAPI CharUpperA(LPSTR);
WINUSERAPI LPWSTR      WINAPI CharUpperW(LPWSTR);
#define                       CharUpper WINELIB_NAME_AW(CharUpper)
WINUSERAPI DWORD       WINAPI CharUpperBuffA(LPSTR,DWORD);
WINUSERAPI DWORD       WINAPI CharUpperBuffW(LPWSTR,DWORD);
#define                       CharUpperBuff WINELIB_NAME_AW(CharUpperBuff)
WINUSERAPI BOOL        WINAPI CharToOemA(LPCSTR,LPSTR);
WINUSERAPI BOOL        WINAPI CharToOemW(LPCWSTR,LPSTR);
#define                       CharToOem WINELIB_NAME_AW(CharToOem)
WINUSERAPI BOOL        WINAPI CharToOemBuffA(LPCSTR,LPSTR,DWORD);
WINUSERAPI BOOL        WINAPI CharToOemBuffW(LPCWSTR,LPSTR,DWORD);
#define                       CharToOemBuff WINELIB_NAME_AW(CharToOemBuff)
WINUSERAPI BOOL        WINAPI CheckDlgButton(HWND,INT,UINT);
WINUSERAPI DWORD       WINAPI CheckMenuItem(HMENU,UINT,UINT);
WINUSERAPI BOOL        WINAPI CheckMenuRadioItem(HMENU,UINT,UINT,UINT,UINT);
WINUSERAPI BOOL        WINAPI CheckRadioButton(HWND,int,int,int);
WINUSERAPI HWND        WINAPI ChildWindowFromPoint(HWND,POINT);
WINUSERAPI HWND        WINAPI ChildWindowFromPointEx(HWND,POINT,UINT);
WINUSERAPI BOOL        WINAPI ClientToScreen(HWND,LPPOINT);
WINUSERAPI BOOL        WINAPI ClipCursor(const RECT*);
WINUSERAPI BOOL        WINAPI CloseClipboard(void);
WINUSERAPI BOOL        WINAPI CloseDesktop(HDESK);
WINUSERAPI BOOL        WINAPI CloseTouchInputHandle(HTOUCHINPUT);
WINUSERAPI BOOL        WINAPI CloseWindow(HWND);
WINUSERAPI BOOL        WINAPI CloseWindowStation(HWINSTA);
WINUSERAPI INT         WINAPI CopyAcceleratorTableA(HACCEL,LPACCEL,INT);
WINUSERAPI INT         WINAPI CopyAcceleratorTableW(HACCEL,LPACCEL,INT);
#define                       CopyAcceleratorTable WINELIB_NAME_AW(CopyAcceleratorTable)
#define                       CopyCursor(cur) ((HCURSOR)CopyIcon((HICON)(cur)))
WINUSERAPI HICON       WINAPI CopyIcon(HICON);
WINUSERAPI HANDLE      WINAPI CopyImage(HANDLE,UINT,INT,INT,UINT);
WINUSERAPI BOOL        WINAPI CopyRect(RECT*,const RECT*);
WINUSERAPI INT         WINAPI CountClipboardFormats(void);
WINUSERAPI HACCEL      WINAPI CreateAcceleratorTableA(LPACCEL,INT);
WINUSERAPI HACCEL      WINAPI CreateAcceleratorTableW(LPACCEL,INT);
#define                       CreateAcceleratorTable WINELIB_NAME_AW(CreateAcceleratorTable)
WINUSERAPI HICON       WINAPI CreateIconIndirect(PICONINFO);
WINUSERAPI BOOL        WINAPI CreateCaret(HWND,HBITMAP,INT,INT);
WINUSERAPI HCURSOR     WINAPI CreateCursor(HINSTANCE,INT,INT,INT,INT,LPCVOID,LPCVOID);
#define                       CreateDialogA(inst,ptr,hwnd,dlg) CreateDialogParamA(inst,ptr,hwnd,dlg,0)
#define                       CreateDialogW(inst,ptr,hwnd,dlg) CreateDialogParamW(inst,ptr,hwnd,dlg,0)
#define                       CreateDialog WINELIB_NAME_AW(CreateDialog)
#define                       CreateDialogIndirectA(inst,ptr,hwnd,dlg) CreateDialogIndirectParamA(inst,ptr,hwnd,dlg,0)
#define                       CreateDialogIndirectW(inst,ptr,hwnd,dlg) CreateDialogIndirectParamW(inst,ptr,hwnd,dlg,0)
#define                       CreateDialogIndirect WINELIB_NAME_AW(CreateDialogIndirect)
WINUSERAPI HWND        WINAPI CreateDialogIndirectParamA(HINSTANCE,LPCDLGTEMPLATEA,HWND,DLGPROC,LPARAM);
WINUSERAPI HWND        WINAPI CreateDialogIndirectParamW(HINSTANCE,LPCDLGTEMPLATEW,HWND,DLGPROC,LPARAM);
#define                       CreateDialogIndirectParam WINELIB_NAME_AW(CreateDialogIndirectParam)
WINUSERAPI HWND        WINAPI CreateDialogParamA(HINSTANCE,LPCSTR,HWND,DLGPROC,LPARAM);
WINUSERAPI HWND        WINAPI CreateDialogParamW(HINSTANCE,LPCWSTR,HWND,DLGPROC,LPARAM);
#define                       CreateDialogParam WINELIB_NAME_AW(CreateDialogParam)
WINUSERAPI HICON       WINAPI CreateIcon(HINSTANCE,INT,INT,BYTE,BYTE,LPCVOID,LPCVOID);
WINUSERAPI HICON       WINAPI CreateIconFromResource(LPBYTE,UINT,BOOL,DWORD);
WINUSERAPI HICON       WINAPI CreateIconFromResourceEx(LPBYTE,UINT,BOOL,DWORD,INT,INT,UINT);
WINUSERAPI HMENU       WINAPI CreateMenu(void);
WINUSERAPI HMENU       WINAPI CreatePopupMenu(void);
#define                       CreateWindowA(className,titleName,style,x,y,width,height,parent,menu,instance,param) CreateWindowExA(0,className,titleName,style,x,y,width,height,parent,menu,instance,param)
#define                       CreateWindowW(className,titleName,style,x,y,width,height,parent,menu,instance,param) CreateWindowExW(0,className,titleName,style,x,y,width,height,parent,menu,instance,param)
#define                       CreateWindow WINELIB_NAME_AW(CreateWindow)
WINUSERAPI HWND        WINAPI CreateWindowExA(DWORD,LPCSTR,LPCSTR,DWORD,INT,INT,INT,INT,HWND,HMENU,HINSTANCE,LPVOID);
WINUSERAPI HWND        WINAPI CreateWindowExW(DWORD,LPCWSTR,LPCWSTR,DWORD,INT,INT,INT,INT,HWND,HMENU,HINSTANCE,LPVOID);
#define                       CreateWindowEx WINELIB_NAME_AW(CreateWindowEx)
WINUSERAPI HWINSTA     WINAPI CreateWindowStationA(LPCSTR,DWORD,ACCESS_MASK,LPSECURITY_ATTRIBUTES);
WINUSERAPI HWINSTA     WINAPI CreateWindowStationW(LPCWSTR,DWORD,ACCESS_MASK,LPSECURITY_ATTRIBUTES);
#define                       CreateWindowStation WINELIB_NAME_AW(CreateWindowStation)
WINUSERAPI HWND        WINAPI CreateMDIWindowA(LPCSTR,LPCSTR,DWORD,INT,INT,INT,INT,HWND,HINSTANCE,LPARAM);
WINUSERAPI HWND        WINAPI CreateMDIWindowW(LPCWSTR,LPCWSTR,DWORD,INT,INT,INT,INT,HWND,HINSTANCE,LPARAM);
#define                       CreateMDIWindow WINELIB_NAME_AW(CreateMDIWindow)
WINUSERAPI LRESULT     WINAPI DefDlgProcA(HWND,UINT,WPARAM,LPARAM);
WINUSERAPI LRESULT     WINAPI DefDlgProcW(HWND,UINT,WPARAM,LPARAM);
#define                       DefDlgProc WINELIB_NAME_AW(DefDlgProc)
WINUSERAPI HDWP        WINAPI DeferWindowPos(HDWP,HWND,HWND,INT,INT,INT,INT,UINT);
WINUSERAPI LRESULT     WINAPI DefFrameProcA(HWND,HWND,UINT,WPARAM,LPARAM);
WINUSERAPI LRESULT     WINAPI DefFrameProcW(HWND,HWND,UINT,WPARAM,LPARAM);
#define                       DefFrameProc WINELIB_NAME_AW(DefFrameProc)
#define                       DefHookProc(code,wparam,lparam,phhook) CallNextHookEx(*(phhook),code,wparam,lparam)
WINUSERAPI LRESULT     WINAPI DefMDIChildProcA(HWND,UINT,WPARAM,LPARAM);
WINUSERAPI LRESULT     WINAPI DefMDIChildProcW(HWND,UINT,WPARAM,LPARAM);
#define                       DefMDIChildProc WINELIB_NAME_AW(DefMDIChildProc)
WINUSERAPI LRESULT     WINAPI DefRawInputProc(PRAWINPUT*,INT,UINT);
WINUSERAPI LRESULT     WINAPI DefWindowProcA(HWND,UINT,WPARAM,LPARAM);
WINUSERAPI LRESULT     WINAPI DefWindowProcW(HWND,UINT,WPARAM,LPARAM);
#define                       DefWindowProc WINELIB_NAME_AW(DefWindowProc)
WINUSERAPI BOOL        WINAPI DeleteMenu(HMENU,UINT,UINT);
WINUSERAPI BOOL        WINAPI DeregisterShellHookWindow(HWND);
WINUSERAPI BOOL        WINAPI DestroyAcceleratorTable(HACCEL);
WINUSERAPI BOOL        WINAPI DestroyCaret(void);
WINUSERAPI BOOL        WINAPI DestroyCursor(HCURSOR);
WINUSERAPI BOOL        WINAPI DestroyIcon(HICON);
WINUSERAPI BOOL        WINAPI DestroyMenu(HMENU);
WINUSERAPI BOOL        WINAPI DestroyWindow(HWND);
#define                       DialogBoxA(inst,template,owner,func) DialogBoxParamA(inst,template,owner,func,0)
#define                       DialogBoxW(inst,template,owner,func) DialogBoxParamW(inst,template,owner,func,0)
#define                       DialogBox WINELIB_NAME_AW(DialogBox)
#define                       DialogBoxIndirectA(inst,template,owner,func) DialogBoxIndirectParamA(inst,template,owner,func,0)
#define                       DialogBoxIndirectW(inst,template,owner,func) DialogBoxIndirectParamW(inst,template,owner,func,0)
#define                       DialogBoxIndirect WINELIB_NAME_AW(DialogBoxIndirect)
WINUSERAPI INT_PTR     WINAPI DialogBoxIndirectParamA(HINSTANCE,LPCDLGTEMPLATEA,HWND,DLGPROC,LPARAM);
WINUSERAPI INT_PTR     WINAPI DialogBoxIndirectParamW(HINSTANCE,LPCDLGTEMPLATEW,HWND,DLGPROC,LPARAM);
#define                       DialogBoxIndirectParam WINELIB_NAME_AW(DialogBoxIndirectParam)
WINUSERAPI INT_PTR     WINAPI DialogBoxParamA(HINSTANCE,LPCSTR,HWND,DLGPROC,LPARAM);
WINUSERAPI INT_PTR     WINAPI DialogBoxParamW(HINSTANCE,LPCWSTR,HWND,DLGPROC,LPARAM);
#define                       DialogBoxParam WINELIB_NAME_AW(DialogBoxParam)
WINUSERAPI VOID        WINAPI DisableProcessWindowsGhosting(VOID);
WINUSERAPI LRESULT     WINAPI DispatchMessageA(const MSG*);
WINUSERAPI LRESULT     WINAPI DispatchMessageW(const MSG*);
#define                       DispatchMessage WINELIB_NAME_AW(DispatchMessage)
WINUSERAPI INT         WINAPI DlgDirListA(HWND,LPSTR,INT,INT,UINT);
WINUSERAPI INT         WINAPI DlgDirListW(HWND,LPWSTR,INT,INT,UINT);
#define                       DlgDirList WINELIB_NAME_AW(DlgDirList)
WINUSERAPI INT         WINAPI DlgDirListComboBoxA(HWND,LPSTR,INT,INT,UINT);
WINUSERAPI INT         WINAPI DlgDirListComboBoxW(HWND,LPWSTR,INT,INT,UINT);
#define                       DlgDirListComboBox WINELIB_NAME_AW(DlgDirListComboBox)
WINUSERAPI BOOL        WINAPI DlgDirSelectComboBoxExA(HWND,LPSTR,INT,INT);
WINUSERAPI BOOL        WINAPI DlgDirSelectComboBoxExW(HWND,LPWSTR,INT,INT);
#define                       DlgDirSelectComboBoxEx WINELIB_NAME_AW(DlgDirSelectComboBoxEx)
WINUSERAPI BOOL        WINAPI DlgDirSelectExA(HWND,LPSTR,INT,INT);
WINUSERAPI BOOL        WINAPI DlgDirSelectExW(HWND,LPWSTR,INT,INT);
#define                       DlgDirSelectEx WINELIB_NAME_AW(DlgDirSelectEx)
WINUSERAPI BOOL        WINAPI DragDetect(HWND,POINT);
WINUSERAPI DWORD       WINAPI DragObject(HWND,HWND,UINT,ULONG_PTR,HCURSOR);
WINUSERAPI BOOL        WINAPI DrawAnimatedRects(HWND,int,const RECT*,const RECT*);
WINUSERAPI BOOL        WINAPI DrawCaption(HWND,HDC,const RECT*,UINT);
WINUSERAPI BOOL        WINAPI DrawCaptionTempA(HWND,HDC,const RECT*,HFONT,HICON,LPCSTR,UINT);
WINUSERAPI BOOL        WINAPI DrawCaptionTempW(HWND,HDC,const RECT*,HFONT,HICON,LPCWSTR,UINT);
#define                       DrawCaptionTemp WINELIB_NAME_AW(DrawCaptionTemp)
WINUSERAPI BOOL        WINAPI DrawEdge(HDC,LPRECT,UINT,UINT);
WINUSERAPI BOOL        WINAPI DrawFocusRect(HDC,const RECT*);
WINUSERAPI BOOL        WINAPI DrawFrameControl(HDC,LPRECT,UINT,UINT);
WINUSERAPI BOOL        WINAPI DrawIcon(HDC,INT,INT,HICON);
WINUSERAPI BOOL        WINAPI DrawIconEx(HDC,INT,INT,HICON,INT,INT,UINT,HBRUSH,UINT);
WINUSERAPI BOOL        WINAPI DrawMenuBar(HWND);
WINUSERAPI BOOL        WINAPI DrawStateA(HDC,HBRUSH,DRAWSTATEPROC,LPARAM,WPARAM,INT,INT,INT,INT,UINT);
WINUSERAPI BOOL        WINAPI DrawStateW(HDC,HBRUSH,DRAWSTATEPROC,LPARAM,WPARAM,INT,INT,INT,INT,UINT);
#define                       DrawState WINELIB_NAME_AW(DrawState)
WINUSERAPI INT         WINAPI DrawTextA(HDC,LPCSTR,INT,LPRECT,UINT);
WINUSERAPI INT         WINAPI DrawTextW(HDC,LPCWSTR,INT,LPRECT,UINT);
#define                       DrawText WINELIB_NAME_AW(DrawText)
WINUSERAPI INT         WINAPI DrawTextExA(HDC,LPSTR,INT,LPRECT,UINT,LPDRAWTEXTPARAMS);
WINUSERAPI INT         WINAPI DrawTextExW(HDC,LPWSTR,INT,LPRECT,UINT,LPDRAWTEXTPARAMS);
#define                       DrawTextEx WINELIB_NAME_AW(DrawTextEx)
WINUSERAPI BOOL        WINAPI EmptyClipboard(void);
WINUSERAPI BOOL        WINAPI EnableMenuItem(HMENU,UINT,UINT);
WINUSERAPI BOOL        WINAPI EnableScrollBar(HWND,UINT,UINT);
WINUSERAPI BOOL        WINAPI EnableWindow(HWND,BOOL);
WINUSERAPI BOOL        WINAPI EndDeferWindowPos(HDWP);
WINUSERAPI BOOL        WINAPI EndDialog(HWND,INT_PTR);
WINUSERAPI BOOL        WINAPI EndMenu(void);
WINUSERAPI BOOL        WINAPI EndPaint(HWND,const PAINTSTRUCT*);
WINUSERAPI BOOL        WINAPI EnumChildWindows(HWND,WNDENUMPROC,LPARAM);
WINUSERAPI UINT        WINAPI EnumClipboardFormats(UINT);
WINUSERAPI BOOL        WINAPI EnumDesktopsA(HWINSTA,DESKTOPENUMPROCA,LPARAM);
WINUSERAPI BOOL        WINAPI EnumDesktopsW(HWINSTA,DESKTOPENUMPROCW,LPARAM);
#define                       EnumDesktops WINELIB_NAME_AW(EnumDesktops)
WINUSERAPI BOOL        WINAPI EnumDesktopWindows(HDESK,WNDENUMPROC,LPARAM);
WINUSERAPI BOOL        WINAPI EnumDisplayMonitors(HDC,LPRECT,MONITORENUMPROC,LPARAM);
WINUSERAPI INT         WINAPI EnumPropsA(HWND,PROPENUMPROCA);
WINUSERAPI INT         WINAPI EnumPropsW(HWND,PROPENUMPROCW);
#define                       EnumProps WINELIB_NAME_AW(EnumProps)
WINUSERAPI INT         WINAPI EnumPropsExA(HWND,PROPENUMPROCEXA,LPARAM);
WINUSERAPI INT         WINAPI EnumPropsExW(HWND,PROPENUMPROCEXW,LPARAM);
#define                       EnumPropsEx WINELIB_NAME_AW(EnumPropsEx)
WINUSERAPI BOOL        WINAPI EnumThreadWindows(DWORD,WNDENUMPROC,LPARAM);
WINUSERAPI BOOL        WINAPI EnumWindows(WNDENUMPROC,LPARAM);
WINUSERAPI BOOL        WINAPI EnumWindowStationsA(WINSTAENUMPROCA,LPARAM);
WINUSERAPI BOOL        WINAPI EnumWindowStationsW(WINSTAENUMPROCW,LPARAM);
#define                       EnumWindowStations WINELIB_NAME_AW(EnumWindowStations)
WINUSERAPI INT         WINAPI ExcludeUpdateRgn(HDC,HWND);
#define                       ExitWindows(a,b) ExitWindowsEx(EWX_LOGOFF,0xffffffff)
WINUSERAPI BOOL        WINAPI ExitWindowsEx(UINT,DWORD);
WINUSERAPI INT         WINAPI FillRect(HDC,const RECT*,HBRUSH);
WINUSERAPI HWND        WINAPI FindWindowA(LPCSTR,LPCSTR);
WINUSERAPI HWND        WINAPI FindWindowW(LPCWSTR,LPCWSTR);
#define                       FindWindow WINELIB_NAME_AW(FindWindow)
WINUSERAPI HWND        WINAPI FindWindowExA(HWND,HWND,LPCSTR,LPCSTR);
WINUSERAPI HWND        WINAPI FindWindowExW(HWND,HWND,LPCWSTR,LPCWSTR);
#define                       FindWindowEx WINELIB_NAME_AW(FindWindowEx)
WINUSERAPI BOOL        WINAPI FlashWindow(HWND,BOOL);
WINUSERAPI BOOL        WINAPI FlashWindowEx(PFLASHWINFO);
WINUSERAPI INT         WINAPI FrameRect(HDC,const RECT*,HBRUSH);
WINUSERAPI HWND        WINAPI GetActiveWindow(void);
WINUSERAPI BOOL        WINAPI GetAltTabInfoA(HWND,INT,PALTTABINFO,LPSTR,UINT);
WINUSERAPI BOOL        WINAPI GetAltTabInfoW(HWND,INT,PALTTABINFO,LPWSTR,UINT);
#define                       GetAltTabInfo WINELIB_NAME_AW(GetAltTabInfo)
WINUSERAPI HWND        WINAPI GetAncestor(HWND,UINT);
WINUSERAPI DWORD       WINAPI GetAppCompatFlags(HTASK);
WINUSERAPI SHORT       WINAPI GetAsyncKeyState(INT);
WINUSERAPI BOOL        WINAPI GetAutoRotationState(AR_STATE*);
WINUSERAPI HWND        WINAPI GetCapture(void);
WINUSERAPI UINT        WINAPI GetCaretBlinkTime(void);
WINUSERAPI BOOL        WINAPI GetCaretPos(LPPOINT);
WINUSERAPI BOOL        WINAPI GetClassInfoA(HINSTANCE,LPCSTR,WNDCLASSA *);
WINUSERAPI BOOL        WINAPI GetClassInfoW(HINSTANCE,LPCWSTR,WNDCLASSW *);
#define                       GetClassInfo WINELIB_NAME_AW(GetClassInfo)
WINUSERAPI BOOL        WINAPI GetClassInfoExA(HINSTANCE,LPCSTR,WNDCLASSEXA *);
WINUSERAPI BOOL        WINAPI GetClassInfoExW(HINSTANCE,LPCWSTR,WNDCLASSEXW *);
#define                       GetClassInfoEx WINELIB_NAME_AW(GetClassInfoEx)
WINUSERAPI DWORD       WINAPI GetClassLongA(HWND,INT);
WINUSERAPI DWORD       WINAPI GetClassLongW(HWND,INT);
#define                       GetClassLong WINELIB_NAME_AW(GetClassLong)
#ifdef _WIN64
WINUSERAPI ULONG_PTR   WINAPI GetClassLongPtrA(HWND,INT);
WINUSERAPI ULONG_PTR   WINAPI GetClassLongPtrW(HWND,INT);
#else
#define                       GetClassLongPtrA GetClassLongA
#define                       GetClassLongPtrW GetClassLongW
#endif
#define                       GetClassLongPtr WINELIB_NAME_AW(GetClassLongPtr)
WINUSERAPI INT         WINAPI GetClassNameA(HWND,LPSTR,INT);
WINUSERAPI INT         WINAPI GetClassNameW(HWND,LPWSTR,INT);
#define                       GetClassName WINELIB_NAME_AW(GetClassName)
WINUSERAPI WORD        WINAPI GetClassWord(HWND,INT);
WINUSERAPI BOOL        WINAPI GetClientRect(HWND,LPRECT);
WINUSERAPI HANDLE      WINAPI GetClipboardData(UINT);
WINUSERAPI INT         WINAPI GetClipboardFormatNameA(UINT,LPSTR,INT);
WINUSERAPI INT         WINAPI GetClipboardFormatNameW(UINT,LPWSTR,INT);
#define                       GetClipboardFormatName WINELIB_NAME_AW(GetClipboardFormatName)
WINUSERAPI HWND        WINAPI GetClipboardOwner(void);
WINUSERAPI DWORD       WINAPI GetClipboardSequenceNumber(VOID);
WINUSERAPI HWND        WINAPI GetClipboardViewer(void);
WINUSERAPI BOOL        WINAPI GetClipCursor(LPRECT);
WINUSERAPI BOOL        WINAPI GetComboBoxInfo(HWND,PCOMBOBOXINFO);
WINUSERAPI HCURSOR     WINAPI GetCursor(void);
WINUSERAPI BOOL        WINAPI GetCursorInfo(PCURSORINFO);
WINUSERAPI HCURSOR     WINAPI GetCursorFrameInfo(HCURSOR,DWORD,DWORD,DWORD*,DWORD*);
WINUSERAPI BOOL        WINAPI GetCursorPos(LPPOINT);
WINUSERAPI HDC         WINAPI GetDC(HWND);
WINUSERAPI HDC         WINAPI GetDCEx(HWND,HRGN,DWORD);
WINUSERAPI HWND        WINAPI GetDesktopWindow(void);
WINUSERAPI DWORD       WINAPI GetDialogBaseUnits(void);
WINUSERAPI BOOL        WINAPI GetDisplayAutoRotationPreferences(ORIENTATION_PREFERENCE*);
WINUSERAPI INT         WINAPI GetDlgCtrlID(HWND);
WINUSERAPI HWND        WINAPI GetDlgItem(HWND,INT);
WINUSERAPI UINT        WINAPI GetDlgItemInt(HWND,INT,BOOL*,BOOL);
WINUSERAPI UINT        WINAPI GetDlgItemTextA(HWND,INT,LPSTR,INT);
WINUSERAPI UINT        WINAPI GetDlgItemTextW(HWND,INT,LPWSTR,INT);
#define                       GetDlgItemText WINELIB_NAME_AW(GetDlgItemText)
WINUSERAPI UINT        WINAPI GetDoubleClickTime(void);
WINUSERAPI HWND        WINAPI GetFocus(void);
WINUSERAPI HWND        WINAPI GetForegroundWindow(void);
WINUSERAPI BOOL        WINAPI GetGestureConfig(HWND,DWORD,DWORD,UINT*,GESTURECONFIG*,UINT);
WINUSERAPI BOOL        WINAPI GetGestureInfo(HGESTUREINFO,PGESTUREINFO);
WINUSERAPI BOOL        WINAPI GetGUIThreadInfo(DWORD,GUITHREADINFO*);
WINUSERAPI DWORD       WINAPI GetGuiResources(HANDLE,DWORD);
WINUSERAPI BOOL        WINAPI GetIconInfo(HICON,PICONINFO);
WINUSERAPI BOOL        WINAPI GetIconInfoExA(HICON,ICONINFOEXA*);
WINUSERAPI BOOL        WINAPI GetIconInfoExW(HICON,ICONINFOEXW*);
#define                       GetIconInfoEx WINELIB_NAME_AW(GetIconInfoEx)
WINUSERAPI BOOL        WINAPI GetInputState(void);
WINUSERAPI UINT        WINAPI GetInternalWindowPos(HWND,LPRECT,LPPOINT);
WINUSERAPI UINT        WINAPI GetKBCodePage(void);
WINUSERAPI HKL         WINAPI GetKeyboardLayout(DWORD);
WINUSERAPI UINT        WINAPI GetKeyboardLayoutList(INT,HKL *);
WINUSERAPI BOOL        WINAPI GetKeyboardState(LPBYTE);
WINUSERAPI INT         WINAPI GetKeyboardType(INT);
WINUSERAPI INT         WINAPI GetKeyNameTextA(LONG,LPSTR,INT);
WINUSERAPI INT         WINAPI GetKeyNameTextW(LONG,LPWSTR,INT);
#define                       GetKeyNameText WINELIB_NAME_AW(GetKeyNameText)
WINUSERAPI BOOL        WINAPI GetKeyboardLayoutNameA(LPSTR);
WINUSERAPI BOOL        WINAPI GetKeyboardLayoutNameW(LPWSTR);
#define                       GetKeyboardLayoutName WINELIB_NAME_AW(GetKeyboardLayoutName)
WINUSERAPI SHORT       WINAPI GetKeyState(INT);
WINUSERAPI HWND        WINAPI GetLastActivePopup(HWND);
WINUSERAPI BOOL        WINAPI GetLastInputInfo(PLASTINPUTINFO);
WINUSERAPI DWORD       WINAPI GetListBoxInfo(HWND);
WINUSERAPI UINT        WINAPI GetRawInputBuffer(PRAWINPUT,PUINT,UINT);
WINUSERAPI UINT        WINAPI GetRawInputData(HRAWINPUT,UINT,LPVOID,PUINT,UINT);
WINUSERAPI UINT        WINAPI GetRawInputDeviceInfoA(HANDLE,UINT,LPVOID,PUINT);
WINUSERAPI UINT        WINAPI GetRawInputDeviceInfoW(HANDLE,UINT,LPVOID,PUINT);
#define                       GetRawInputDeviceInfo WINELIB_NAME_AW(GetRawInputDeviceInfo)
WINUSERAPI UINT        WINAPI GetRawInputDeviceList(PRAWINPUTDEVICELIST,PUINT,UINT);
WINUSERAPI UINT        WINAPI GetRegisteredRawInputDevices(PRAWINPUTDEVICE,PUINT,UINT);
WINUSERAPI BOOL        WINAPI GetLayeredWindowAttributes(HWND,COLORREF*,BYTE*,DWORD*);
WINUSERAPI HMENU       WINAPI GetMenu(HWND);
WINUSERAPI BOOL        WINAPI GetMenuBarInfo(HWND,LONG,LONG,PMENUBARINFO);
WINUSERAPI DWORD       WINAPI GetMenuCheckMarkDimensions(void);
WINUSERAPI DWORD       WINAPI GetMenuContextHelpId(HMENU);
WINUSERAPI UINT        WINAPI GetMenuDefaultItem(HMENU,UINT,UINT);
WINUSERAPI BOOL        WINAPI GetMenuInfo(HMENU,LPMENUINFO);
WINUSERAPI INT         WINAPI GetMenuItemCount(HMENU);
WINUSERAPI UINT        WINAPI GetMenuItemID(HMENU,INT);
WINUSERAPI BOOL        WINAPI GetMenuItemInfoA(HMENU,UINT,BOOL,MENUITEMINFOA*);
WINUSERAPI BOOL        WINAPI GetMenuItemInfoW(HMENU,UINT,BOOL,MENUITEMINFOW*);
#define                       GetMenuItemInfo WINELIB_NAME_AW(GetMenuItemInfo)
WINUSERAPI BOOL        WINAPI GetMenuItemRect(HWND,HMENU,UINT,LPRECT);
WINUSERAPI UINT        WINAPI GetMenuState(HMENU,UINT,UINT);
WINUSERAPI INT         WINAPI GetMenuStringA(HMENU,UINT,LPSTR,INT,UINT);
WINUSERAPI INT         WINAPI GetMenuStringW(HMENU,UINT,LPWSTR,INT,UINT);
#define                       GetMenuString WINELIB_NAME_AW(GetMenuString)
WINUSERAPI BOOL        WINAPI GetMessageA(LPMSG,HWND,UINT,UINT);
WINUSERAPI BOOL        WINAPI GetMessageW(LPMSG,HWND,UINT,UINT);
#define                       GetMessage WINELIB_NAME_AW(GetMessage)
WINUSERAPI LPARAM      WINAPI GetMessageExtraInfo(void);
WINUSERAPI DWORD       WINAPI GetMessagePos(void);
WINUSERAPI LONG        WINAPI GetMessageTime(void);
WINUSERAPI BOOL        WINAPI GetMonitorInfoA(HMONITOR,LPMONITORINFO);
WINUSERAPI BOOL        WINAPI GetMonitorInfoW(HMONITOR,LPMONITORINFO);
#define                       GetMonitorInfo WINELIB_NAME_AW(GetMonitorInfo)
WINUSERAPI HWND        WINAPI GetNextDlgGroupItem(HWND,HWND,BOOL);
WINUSERAPI HWND        WINAPI GetNextDlgTabItem(HWND,HWND,BOOL);
#define                       GetNextWindow GetWindow
WINUSERAPI HWND        WINAPI GetOpenClipboardWindow(void);
WINUSERAPI HWND        WINAPI GetParent(HWND);
WINUSERAPI BOOL        WINAPI GetPhysicalCursorPos(POINT*);
WINUSERAPI INT         WINAPI GetPriorityClipboardFormat(UINT*,INT);
WINUSERAPI BOOL        WINAPI GetProcessDefaultLayout(DWORD*);
WINUSERAPI HANDLE      WINAPI GetPropA(HWND,LPCSTR);
WINUSERAPI HANDLE      WINAPI GetPropW(HWND,LPCWSTR);
#define                       GetProp WINELIB_NAME_AW(GetProp)
WINUSERAPI DWORD       WINAPI GetQueueStatus(UINT);
WINUSERAPI BOOL        WINAPI GetScrollInfo(HWND,INT,LPSCROLLINFO);
WINUSERAPI BOOL        WINAPI GetScrollBarInfo(HWND,LONG,LPSCROLLBARINFO);
WINUSERAPI INT         WINAPI GetScrollPos(HWND,INT);
WINUSERAPI BOOL        WINAPI GetScrollRange(HWND,INT,LPINT,LPINT);
WINUSERAPI HWND        WINAPI GetShellWindow(void);
WINUSERAPI HMENU       WINAPI GetSubMenu(HMENU,INT);
WINUSERAPI HBRUSH      WINAPI GetSysColorBrush(INT);
#define                       GetSysModalWindow() ((HWND)0)
WINUSERAPI HMENU       WINAPI GetSystemMenu(HWND,BOOL);
WINUSERAPI INT         WINAPI GetSystemMetrics(INT);
WINUSERAPI DWORD       WINAPI GetTabbedTextExtentA(HDC,LPCSTR,INT,INT,const INT*);
WINUSERAPI DWORD       WINAPI GetTabbedTextExtentW(HDC,LPCWSTR,INT,INT,const INT*);
#define                       GetTabbedTextExtent WINELIB_NAME_AW(GetTabbedTextExtent)
WINUSERAPI BOOL        WINAPI GetTitleBarInfo(HWND,PTITLEBARINFO);
WINUSERAPI HDESK       WINAPI GetThreadDesktop(DWORD);
WINUSERAPI HWND        WINAPI GetTopWindow(HWND);
WINUSERAPI BOOL        WINAPI GetTouchInputInfo(HTOUCHINPUT,UINT,TOUCHINPUT*,int);
WINUSERAPI BOOL        WINAPI GetUpdateRect(HWND,LPRECT,BOOL);
WINUSERAPI INT         WINAPI GetUpdateRgn(HWND,HRGN,BOOL);
WINUSERAPI BOOL        WINAPI GetUpdatedClipboardFormats(UINT*,UINT,UINT*);
WINUSERAPI BOOL        WINAPI GetUserObjectInformationA(HANDLE,INT,LPVOID,DWORD,LPDWORD);
WINUSERAPI BOOL        WINAPI GetUserObjectInformationW(HANDLE,INT,LPVOID,DWORD,LPDWORD);
#define                       GetUserObjectInformation WINELIB_NAME_AW(GetUserObjectInformation)
WINUSERAPI BOOL        WINAPI GetUserObjectSecurity(HANDLE,PSECURITY_INFORMATION,PSECURITY_DESCRIPTOR,DWORD,LPDWORD);
WINUSERAPI HWND        WINAPI GetWindow(HWND,UINT);
WINUSERAPI DWORD       WINAPI GetWindowContextHelpId(HWND);
WINUSERAPI HDC         WINAPI GetWindowDC(HWND);
WINUSERAPI BOOL        WINAPI GetWindowInfo(HWND, PWINDOWINFO);
WINUSERAPI LONG        WINAPI GetWindowLongA(HWND,INT);
WINUSERAPI LONG        WINAPI GetWindowLongW(HWND,INT);
#define                       GetWindowLong WINELIB_NAME_AW(GetWindowLong)
#ifdef _WIN64
WINUSERAPI LONG_PTR    WINAPI GetWindowLongPtrA(HWND,INT);
WINUSERAPI LONG_PTR    WINAPI GetWindowLongPtrW(HWND,INT);
#else
#define                       GetWindowLongPtrA GetWindowLongA
#define                       GetWindowLongPtrW GetWindowLongW
#endif
#define                       GetWindowLongPtr WINELIB_NAME_AW(GetWindowLongPtr)
WINUSERAPI UINT        WINAPI GetWindowModuleFileNameA(HWND,LPSTR,UINT);
WINUSERAPI UINT        WINAPI GetWindowModuleFileNameW(HWND,LPWSTR,UINT);
#define                       GetWindowModuleFileName WINELIB_NAME_AW(GetWindowModuleFileName)
WINUSERAPI BOOL        WINAPI GetWindowPlacement(HWND,LPWINDOWPLACEMENT);
WINUSERAPI BOOL        WINAPI GetWindowRect(HWND,LPRECT);
WINUSERAPI INT         WINAPI GetWindowRgnBox(HWND,LPRECT);
WINUSERAPI INT         WINAPI GetWindowRgn(HWND,HRGN);
WINUSERAPI HWINSTA     WINAPI GetProcessWindowStation(void);
#define                       GetWindowTask(hwnd) ((HTASK)GetWindowThreadProcessId(hwnd,NULL))
WINUSERAPI INT         WINAPI GetWindowTextA(HWND,LPSTR,INT);
WINUSERAPI INT         WINAPI GetWindowTextW(HWND,LPWSTR,INT);
#define                       GetWindowText WINELIB_NAME_AW(GetWindowText)
WINUSERAPI INT         WINAPI GetWindowTextLengthA(HWND);
WINUSERAPI INT         WINAPI GetWindowTextLengthW(HWND);
#define                       GetWindowTextLength WINELIB_NAME_AW(GetWindowTextLength)
WINUSERAPI DWORD       WINAPI GetWindowThreadProcessId(HWND,LPDWORD);
WINUSERAPI WORD        WINAPI GetWindowWord(HWND,INT);
WINUSERAPI LONG        WINAPI GetXWindowId(HWND);
WINUSERAPI BOOL        WINAPI GrayStringA(HDC,HBRUSH,GRAYSTRINGPROC,LPARAM,INT,INT,INT,INT,INT);
WINUSERAPI BOOL        WINAPI GrayStringW(HDC,HBRUSH,GRAYSTRINGPROC,LPARAM,INT,INT,INT,INT,INT);
#define                       GrayString WINELIB_NAME_AW(GrayString)
WINUSERAPI BOOL        WINAPI HideCaret(HWND);
WINUSERAPI BOOL        WINAPI HiliteMenuItem(HWND,HMENU,UINT,UINT);
WINUSERAPI BOOL        WINAPI InSendMessage(void);
WINUSERAPI DWORD       WINAPI InSendMessageEx(LPVOID);
WINUSERAPI BOOL        WINAPI InsertMenuA(HMENU,UINT,UINT,UINT_PTR,LPCSTR);
WINUSERAPI BOOL        WINAPI InsertMenuW(HMENU,UINT,UINT,UINT_PTR,LPCWSTR);
#define                       InsertMenu WINELIB_NAME_AW(InsertMenu)
WINUSERAPI BOOL        WINAPI InsertMenuItemA(HMENU,UINT,BOOL,const MENUITEMINFOA*);
WINUSERAPI BOOL        WINAPI InsertMenuItemW(HMENU,UINT,BOOL,const MENUITEMINFOW*);
#define                       InsertMenuItem WINELIB_NAME_AW(InsertMenuItem)
WINUSERAPI INT         WINAPI InternalGetWindowText(HWND,LPWSTR,INT);
WINUSERAPI BOOL        WINAPI IntersectRect(LPRECT,const RECT*,const RECT*);
WINUSERAPI BOOL        WINAPI InvalidateRect(HWND,const RECT*,BOOL);
WINUSERAPI BOOL        WINAPI InvalidateRgn(HWND,HRGN,BOOL);
WINUSERAPI BOOL        WINAPI InvertRect(HDC,const RECT*);
WINUSERAPI BOOL        WINAPI IsCharAlphaA(CHAR);
WINUSERAPI BOOL        WINAPI IsCharAlphaW(WCHAR);
#define                       IsCharAlpha WINELIB_NAME_AW(IsCharAlpha)
WINUSERAPI BOOL        WINAPI IsCharAlphaNumericA(CHAR);
WINUSERAPI BOOL        WINAPI IsCharAlphaNumericW(WCHAR);
#define                       IsCharAlphaNumeric WINELIB_NAME_AW(IsCharAlphaNumeric)
WINUSERAPI BOOL        WINAPI IsCharLowerA(CHAR);
WINUSERAPI BOOL        WINAPI IsCharLowerW(WCHAR);
#define                       IsCharLower WINELIB_NAME_AW(IsCharLower)
WINUSERAPI BOOL        WINAPI IsCharUpperA(CHAR);
WINUSERAPI BOOL        WINAPI IsCharUpperW(WCHAR);
#define                       IsCharUpper WINELIB_NAME_AW(IsCharUpper)
WINUSERAPI BOOL        WINAPI IsChild(HWND,HWND);
WINUSERAPI BOOL        WINAPI IsClipboardFormatAvailable(UINT);
WINUSERAPI BOOL        WINAPI IsDialogMessageA(HWND,LPMSG);
WINUSERAPI BOOL        WINAPI IsDialogMessageW(HWND,LPMSG);
#define                       IsDialogMessage WINELIB_NAME_AW(IsDialogMessage)
WINUSERAPI UINT        WINAPI IsDlgButtonChecked(HWND,int);
WINUSERAPI BOOL        WINAPI IsGUIThread(BOOL);
WINUSERAPI BOOL        WINAPI IsHungAppWindow(HWND);
WINUSERAPI BOOL        WINAPI IsIconic(HWND);
WINUSERAPI BOOL        WINAPI IsMenu(HMENU);
WINUSERAPI BOOL        WINAPI IsProcessDPIAware(void);
WINUSERAPI BOOL        WINAPI IsTouchWindow(HWND,PULONG);
WINUSERAPI BOOL        WINAPI IsWinEventHookInstalled(DWORD);
WINUSERAPI BOOL        WINAPI IsWindow(HWND);
WINUSERAPI BOOL        WINAPI IsWindowEnabled(HWND);
WINUSERAPI BOOL        WINAPI IsWindowUnicode(HWND);
WINUSERAPI BOOL        WINAPI IsWindowVisible(HWND);
WINUSERAPI BOOL        WINAPI IsZoomed(HWND);
WINUSERAPI BOOL        WINAPI KillSystemTimer(HWND,UINT_PTR);
WINUSERAPI BOOL        WINAPI KillTimer(HWND,UINT_PTR);
WINUSERAPI HACCEL      WINAPI LoadAcceleratorsA(HINSTANCE,LPCSTR);
WINUSERAPI HACCEL      WINAPI LoadAcceleratorsW(HINSTANCE,LPCWSTR);
#define                       LoadAccelerators WINELIB_NAME_AW(LoadAccelerators)
WINUSERAPI HBITMAP     WINAPI LoadBitmapA(HINSTANCE,LPCSTR);
WINUSERAPI HBITMAP     WINAPI LoadBitmapW(HINSTANCE,LPCWSTR);
#define                       LoadBitmap WINELIB_NAME_AW(LoadBitmap)
WINUSERAPI HCURSOR     WINAPI LoadCursorA(HINSTANCE,LPCSTR);
WINUSERAPI HCURSOR     WINAPI LoadCursorW(HINSTANCE,LPCWSTR);
#define                       LoadCursor WINELIB_NAME_AW(LoadCursor)
WINUSERAPI HCURSOR     WINAPI LoadCursorFromFileA(LPCSTR);
WINUSERAPI HCURSOR     WINAPI LoadCursorFromFileW(LPCWSTR);
#define                       LoadCursorFromFile WINELIB_NAME_AW(LoadCursorFromFile)
WINUSERAPI HICON       WINAPI LoadIconA(HINSTANCE,LPCSTR);
WINUSERAPI HICON       WINAPI LoadIconW(HINSTANCE,LPCWSTR);
#define                       LoadIcon WINELIB_NAME_AW(LoadIcon)
WINUSERAPI HANDLE      WINAPI LoadImageA(HINSTANCE,LPCSTR,UINT,INT,INT,UINT);
WINUSERAPI HANDLE      WINAPI LoadImageW(HINSTANCE,LPCWSTR,UINT,INT,INT,UINT);
#define                       LoadImage WINELIB_NAME_AW(LoadImage)
WINUSERAPI HKL         WINAPI LoadKeyboardLayoutA(LPCSTR,UINT);
WINUSERAPI HKL         WINAPI LoadKeyboardLayoutW(LPCWSTR,UINT);
#define                       LoadKeyboardLayout WINELIB_NAME_AW(LoadKeyboardLayout)
WINUSERAPI HMENU       WINAPI LoadMenuA(HINSTANCE,LPCSTR);
WINUSERAPI HMENU       WINAPI LoadMenuW(HINSTANCE,LPCWSTR);
#define                       LoadMenu WINELIB_NAME_AW(LoadMenu)
WINUSERAPI HMENU       WINAPI LoadMenuIndirectA(LPCVOID);
WINUSERAPI HMENU       WINAPI LoadMenuIndirectW(LPCVOID);
#define                       LoadMenuIndirect WINELIB_NAME_AW(LoadMenuIndirect)
WINUSERAPI INT         WINAPI LoadStringA(HINSTANCE,UINT,LPSTR,INT);
WINUSERAPI INT         WINAPI LoadStringW(HINSTANCE,UINT,LPWSTR,INT);
#define                       LoadString WINELIB_NAME_AW(LoadString)
WINUSERAPI BOOL        WINAPI LogicalToPhysicalPoint(HWND,POINT*);
WINUSERAPI BOOL        WINAPI LockSetForegroundWindow(UINT);
WINUSERAPI BOOL        WINAPI LockWindowUpdate(HWND);
WINUSERAPI BOOL        WINAPI LockWorkStation(void);
WINUSERAPI INT         WINAPI LookupIconIdFromDirectory(LPBYTE,BOOL);
WINUSERAPI INT         WINAPI LookupIconIdFromDirectoryEx(LPBYTE,BOOL,INT,INT,UINT);
WINUSERAPI UINT        WINAPI MapVirtualKeyA(UINT,UINT);
WINUSERAPI UINT        WINAPI MapVirtualKeyW(UINT,UINT);
#define                       MapVirtualKey WINELIB_NAME_AW(MapVirtualKey)
WINUSERAPI UINT        WINAPI MapVirtualKeyExA(UINT,UINT,HKL);
WINUSERAPI UINT        WINAPI MapVirtualKeyExW(UINT,UINT,HKL);
#define                       MapVirtualKeyEx WINELIB_NAME_AW(MapVirtualKeyEx)
WINUSERAPI BOOL        WINAPI MapDialogRect(HWND,LPRECT);
WINUSERAPI INT         WINAPI MapWindowPoints(HWND,HWND,LPPOINT,UINT);
WINUSERAPI INT         WINAPI MenuItemFromPoint(HWND,HMENU,POINT);
WINUSERAPI BOOL        WINAPI MessageBeep(UINT);
WINUSERAPI INT         WINAPI MessageBoxA(HWND,LPCSTR,LPCSTR,UINT);
WINUSERAPI INT         WINAPI MessageBoxW(HWND,LPCWSTR,LPCWSTR,UINT);
#define                       MessageBox WINELIB_NAME_AW(MessageBox)
WINUSERAPI INT         WINAPI MessageBoxExA(HWND,LPCSTR,LPCSTR,UINT,WORD);
WINUSERAPI INT         WINAPI MessageBoxExW(HWND,LPCWSTR,LPCWSTR,UINT,WORD);
#define                       MessageBoxEx WINELIB_NAME_AW(MessageBoxEx)
WINUSERAPI INT         WINAPI MessageBoxIndirectA(LPMSGBOXPARAMSA);
WINUSERAPI INT         WINAPI MessageBoxIndirectW(LPMSGBOXPARAMSW);
#define                       MessageBoxIndirect WINELIB_NAME_AW(MessageBoxIndirect)
WINUSERAPI BOOL        WINAPI ModifyMenuA(HMENU,UINT,UINT,UINT_PTR,LPCSTR);
WINUSERAPI BOOL        WINAPI ModifyMenuW(HMENU,UINT,UINT,UINT_PTR,LPCWSTR);
#define                       ModifyMenu WINELIB_NAME_AW(ModifyMenu)
WINUSERAPI HMONITOR    WINAPI MonitorFromPoint(POINT,DWORD);
WINUSERAPI HMONITOR    WINAPI MonitorFromRect(LPRECT,DWORD);
WINUSERAPI HMONITOR    WINAPI MonitorFromWindow(HWND,DWORD);
WINUSERAPI BOOL        WINAPI MoveWindow(HWND,INT,INT,INT,INT,BOOL);
WINUSERAPI DWORD       WINAPI MsgWaitForMultipleObjects(DWORD,const HANDLE*,BOOL,DWORD,DWORD);
WINUSERAPI DWORD       WINAPI MsgWaitForMultipleObjectsEx(DWORD,const HANDLE*,DWORD,DWORD,DWORD);
WINUSERAPI VOID        WINAPI NotifyWinEvent(DWORD,HWND,LONG,LONG);
WINUSERAPI DWORD       WINAPI OemKeyScan(WORD);
WINUSERAPI BOOL        WINAPI OemToCharA(LPCSTR,LPSTR);
WINUSERAPI BOOL        WINAPI OemToCharW(LPCSTR,LPWSTR);
#define                       OemToChar WINELIB_NAME_AW(OemToChar)
WINUSERAPI BOOL        WINAPI OemToCharBuffA(LPCSTR,LPSTR,DWORD);
WINUSERAPI BOOL        WINAPI OemToCharBuffW(LPCSTR,LPWSTR,DWORD);
#define                       OemToCharBuff WINELIB_NAME_AW(OemToCharBuff)
WINUSERAPI BOOL        WINAPI OpenClipboard(HWND);
WINUSERAPI HDESK       WINAPI OpenDesktopA(LPCSTR,DWORD,BOOL,ACCESS_MASK);
WINUSERAPI HDESK       WINAPI OpenDesktopW(LPCWSTR,DWORD,BOOL,ACCESS_MASK);
#define                       OpenDesktop WINELIB_NAME_AW(OpenDesktop)
WINUSERAPI BOOL        WINAPI OpenIcon(HWND);
WINUSERAPI HDESK       WINAPI OpenInputDesktop(DWORD,BOOL,ACCESS_MASK);
WINUSERAPI HWINSTA     WINAPI OpenWindowStationA(LPCSTR,BOOL,ACCESS_MASK);
WINUSERAPI HWINSTA     WINAPI OpenWindowStationW(LPCWSTR,BOOL,ACCESS_MASK);
#define                       OpenWindowStation WINELIB_NAME_AW(OpenWindowStation)
WINUSERAPI BOOL        WINAPI PaintDesktop(HDC);
WINUSERAPI BOOL        WINAPI PeekMessageA(LPMSG,HWND,UINT,UINT,UINT);
WINUSERAPI BOOL        WINAPI PeekMessageW(LPMSG,HWND,UINT,UINT,UINT);
#define                       PeekMessage WINELIB_NAME_AW(PeekMessage)
WINUSERAPI BOOL        WINAPI PhysicalToLogicalPoint(HWND,POINT*);
#define                       PostAppMessageA(thread,msg,wparam,lparam) PostThreadMessageA((DWORD)(thread),msg,wparam,lparam)
#define                       PostAppMessageW(thread,msg,wparam,lparam) PostThreadMessageW((DWORD)(thread),msg,wparam,lparam)
#define                       PostAppMessage WINELIB_NAME_AW(PostAppMessage)
WINUSERAPI BOOL        WINAPI PostMessageA(HWND,UINT,WPARAM,LPARAM);
WINUSERAPI BOOL        WINAPI PostMessageW(HWND,UINT,WPARAM,LPARAM);
#define                       PostMessage WINELIB_NAME_AW(PostMessage)
WINUSERAPI void        WINAPI PostQuitMessage(INT);
WINUSERAPI BOOL        WINAPI PostThreadMessageA(DWORD,UINT,WPARAM,LPARAM);
WINUSERAPI BOOL        WINAPI PostThreadMessageW(DWORD,UINT,WPARAM,LPARAM);
#define                       PostThreadMessage WINELIB_NAME_AW(PostThreadMessage)
WINUSERAPI BOOL        WINAPI PrintWindow(HWND,HDC,UINT);
WINUSERAPI UINT        WINAPI PrivateExtractIconExA(LPCSTR,int,HICON*,HICON*,UINT);
WINUSERAPI UINT        WINAPI PrivateExtractIconExW(LPCWSTR,int,HICON*,HICON*,UINT);
WINUSERAPI UINT        WINAPI PrivateExtractIconsA(LPCSTR,int,int,int,HICON*,UINT*,UINT,UINT);
WINUSERAPI UINT        WINAPI PrivateExtractIconsW(LPCWSTR,int,int,int,HICON*,UINT*,UINT,UINT);
WINUSERAPI BOOL        WINAPI PtInRect(const RECT*,POINT);
WINUSERAPI HWND        WINAPI RealChildWindowFromPoint(HWND,POINT);
WINUSERAPI UINT        WINAPI RealGetWindowClassA(HWND,LPSTR,UINT);
WINUSERAPI UINT        WINAPI RealGetWindowClassW(HWND,LPWSTR,UINT);
#define                       RealGetWindowClass WINELIB_NAME_AW(RealGetWindowClass)
WINUSERAPI BOOL        WINAPI RedrawWindow(HWND,const RECT*,HRGN,UINT);
WINUSERAPI ATOM        WINAPI RegisterClassA(const WNDCLASSA *);
WINUSERAPI ATOM        WINAPI RegisterClassW(const WNDCLASSW *);
#define                       RegisterClass WINELIB_NAME_AW(RegisterClass)
WINUSERAPI ATOM        WINAPI RegisterClassExA(const WNDCLASSEXA *);
WINUSERAPI ATOM        WINAPI RegisterClassExW(const WNDCLASSEXW *);
#define                       RegisterClassEx WINELIB_NAME_AW(RegisterClassEx)
WINUSERAPI UINT        WINAPI RegisterClipboardFormatA(LPCSTR);
WINUSERAPI UINT        WINAPI RegisterClipboardFormatW(LPCWSTR);
#define                       RegisterClipboardFormat WINELIB_NAME_AW(RegisterClipboardFormat)
WINUSERAPI HDEVNOTIFY  WINAPI RegisterDeviceNotificationA(HANDLE,LPVOID,DWORD);
WINUSERAPI HDEVNOTIFY  WINAPI RegisterDeviceNotificationW(HANDLE,LPVOID,DWORD);
#define                       RegisterDeviceNotification WINELIB_NAME_AW(RegisterDeviceNotification)
WINUSERAPI BOOL        WINAPI RegisterHotKey(HWND,INT,UINT,UINT);
WINUSERAPI HPOWERNOTIFY WINAPI RegisterPowerSettingNotification(HANDLE,LPCGUID,DWORD);
WINUSERAPI BOOL        WINAPI RegisterRawInputDevices(PRAWINPUTDEVICE,UINT,UINT);
WINUSERAPI BOOL        WINAPI RegisterShellHookWindow(HWND);
WINUSERAPI BOOL        WINAPI RegisterTouchWindow(HWND,ULONG);
WINUSERAPI UINT        WINAPI RegisterWindowMessageA(LPCSTR);
WINUSERAPI UINT        WINAPI RegisterWindowMessageW(LPCWSTR);
#define                       RegisterWindowMessage WINELIB_NAME_AW(RegisterWindowMessage)
WINUSERAPI BOOL        WINAPI ReleaseCapture(void);
WINUSERAPI INT         WINAPI ReleaseDC(HWND,HDC);
WINUSERAPI BOOL        WINAPI RemoveClipboardFormatListener(HWND);
WINUSERAPI BOOL        WINAPI RemoveMenu(HMENU,UINT,UINT);
WINUSERAPI HANDLE      WINAPI RemovePropA(HWND,LPCSTR);
WINUSERAPI HANDLE      WINAPI RemovePropW(HWND,LPCWSTR);
#define                       RemoveProp WINELIB_NAME_AW(RemoveProp)
WINUSERAPI BOOL        WINAPI ReplyMessage(LRESULT);
WINUSERAPI BOOL        WINAPI ScreenToClient(HWND,LPPOINT);
WINUSERAPI VOID        WINAPI ScrollChildren(HWND,UINT,WPARAM,LPARAM);
WINUSERAPI BOOL        WINAPI ScrollDC(HDC,INT,INT,const RECT*,const RECT*,HRGN,LPRECT);
WINUSERAPI BOOL        WINAPI ScrollWindow(HWND,INT,INT,const RECT*,const RECT*);
WINUSERAPI INT         WINAPI ScrollWindowEx(HWND,INT,INT,const RECT*,const RECT*,HRGN,LPRECT,UINT);
WINUSERAPI LRESULT     WINAPI SendDlgItemMessageA(HWND,INT,UINT,WPARAM,LPARAM);
WINUSERAPI LRESULT     WINAPI SendDlgItemMessageW(HWND,INT,UINT,WPARAM,LPARAM);
#define                       SendDlgItemMessage WINELIB_NAME_AW(SendDlgItemMessage)
WINUSERAPI UINT        WINAPI SendInput(UINT,LPINPUT,int);
WINUSERAPI LRESULT     WINAPI SendMessageA(HWND,UINT,WPARAM,LPARAM);
WINUSERAPI LRESULT     WINAPI SendMessageW(HWND,UINT,WPARAM,LPARAM);
#define                       SendMessage WINELIB_NAME_AW(SendMessage)
WINUSERAPI BOOL        WINAPI SendMessageCallbackA(HWND,UINT,WPARAM,LPARAM,SENDASYNCPROC,ULONG_PTR);
WINUSERAPI BOOL        WINAPI SendMessageCallbackW(HWND,UINT,WPARAM,LPARAM,SENDASYNCPROC,ULONG_PTR);
#define                       SendMessageCallback WINELIB_NAME_AW(SendMessageCallback)
WINUSERAPI LRESULT     WINAPI SendMessageTimeoutA(HWND,UINT,WPARAM,LPARAM,UINT,UINT,PDWORD_PTR);
WINUSERAPI LRESULT     WINAPI SendMessageTimeoutW(HWND,UINT,WPARAM,LPARAM,UINT,UINT,PDWORD_PTR);
#define                       SendMessageTimeout WINELIB_NAME_AW(SendMessageTimeout)
WINUSERAPI BOOL        WINAPI SendNotifyMessageA(HWND,UINT,WPARAM,LPARAM);
WINUSERAPI BOOL        WINAPI SendNotifyMessageW(HWND,UINT,WPARAM,LPARAM);
#define                       SendNotifyMessage WINELIB_NAME_AW(SendNotifyMessage)
WINUSERAPI HWND        WINAPI SetActiveWindow(HWND);
WINUSERAPI HWND        WINAPI SetCapture(HWND);
WINUSERAPI BOOL        WINAPI SetCaretBlinkTime(UINT);
WINUSERAPI BOOL        WINAPI SetCaretPos(INT,INT);
WINUSERAPI DWORD       WINAPI SetClassLongA(HWND,INT,LONG);
WINUSERAPI DWORD       WINAPI SetClassLongW(HWND,INT,LONG);
#define                       SetClassLong WINELIB_NAME_AW(SetClassLong)
#ifdef _WIN64
WINUSERAPI ULONG_PTR   WINAPI SetClassLongPtrA(HWND,INT,LONG_PTR);
WINUSERAPI ULONG_PTR   WINAPI SetClassLongPtrW(HWND,INT,LONG_PTR);
#else
#define                       SetClassLongPtrA SetClassLongA
#define                       SetClassLongPtrW SetClassLongW
#endif
#define                       SetClassLongPtr WINELIB_NAME_AW(SetClassLongPtr)
WINUSERAPI WORD        WINAPI SetClassWord(HWND,INT,WORD);
WINUSERAPI HANDLE      WINAPI SetClipboardData(UINT,HANDLE);
WINUSERAPI HWND        WINAPI SetClipboardViewer(HWND);
WINUSERAPI UINT_PTR    WINAPI SetCoalescableTimer(HWND,UINT_PTR,UINT,TIMERPROC,ULONG);
WINUSERAPI HCURSOR     WINAPI SetCursor(HCURSOR);
WINUSERAPI BOOL        WINAPI SetCursorPos(INT,INT);
WINUSERAPI VOID        WINAPI SetDebugErrorLevel(DWORD);
WINUSERAPI BOOL        WINAPI SetDeskWallPaper(LPCSTR);
WINUSERAPI BOOL        WINAPI SetDlgItemInt(HWND,INT,UINT,BOOL);
WINUSERAPI BOOL        WINAPI SetDlgItemTextA(HWND,INT,LPCSTR);
WINUSERAPI BOOL        WINAPI SetDlgItemTextW(HWND,INT,LPCWSTR);
#define                       SetDlgItemText WINELIB_NAME_AW(SetDlgItemText)
WINUSERAPI BOOL        WINAPI SetDoubleClickTime(UINT);
WINUSERAPI HWND        WINAPI SetFocus(HWND);
WINUSERAPI BOOL        WINAPI SetForegroundWindow(HWND);
WINUSERAPI BOOL        WINAPI WINE_SetForegroundWindow(HWND);
WINUSERAPI BOOL        WINAPI SetGestureConfig(HWND,DWORD,UINT,PGESTURECONFIG,UINT);
WINUSERAPI void        WINAPI SetInternalWindowPos(HWND,UINT,LPRECT,LPPOINT);
WINUSERAPI BOOL        WINAPI SetKeyboardState(LPBYTE);
WINUSERAPI VOID        WINAPI SetLastErrorEx(DWORD,DWORD);
WINUSERAPI BOOL        WINAPI SetLayeredWindowAttributes(HWND,COLORREF,BYTE,DWORD);
WINUSERAPI BOOL        WINAPI SetMenu(HWND,HMENU);
WINUSERAPI BOOL        WINAPI SetMenuContextHelpId(HMENU,DWORD);
WINUSERAPI BOOL        WINAPI SetMenuDefaultItem(HMENU,UINT,UINT);
WINUSERAPI BOOL        WINAPI SetMenuInfo(HMENU,LPCMENUINFO);
WINUSERAPI BOOL        WINAPI SetMenuItemBitmaps(HMENU,UINT,UINT,HBITMAP,HBITMAP);
WINUSERAPI BOOL        WINAPI SetMenuItemInfoA(HMENU,UINT,BOOL,const MENUITEMINFOA*);
WINUSERAPI BOOL        WINAPI SetMenuItemInfoW(HMENU,UINT,BOOL,const MENUITEMINFOW*);
#define                       SetMenuItemInfo WINELIB_NAME_AW(SetMenuItemInfo)
WINUSERAPI LPARAM      WINAPI SetMessageExtraInfo(LPARAM);
WINUSERAPI BOOL        WINAPI SetMessageQueue(INT);
WINUSERAPI HWND        WINAPI SetParent(HWND,HWND);
WINUSERAPI BOOL        WINAPI SetPhysicalCursorPos(INT,INT);
WINUSERAPI BOOL        WINAPI SetProcessDPIAware(void);
WINUSERAPI BOOL        WINAPI SetProcessDefaultLayout(DWORD);
WINUSERAPI BOOL        WINAPI SetProcessWindowStation(HWINSTA);
WINUSERAPI BOOL        WINAPI SetPropA(HWND,LPCSTR,HANDLE);
WINUSERAPI BOOL        WINAPI SetPropW(HWND,LPCWSTR,HANDLE);
#define                       SetProp WINELIB_NAME_AW(SetProp)
WINUSERAPI INT         WINAPI SetScrollInfo(HWND,INT,const SCROLLINFO*,BOOL);
WINUSERAPI INT         WINAPI SetScrollPos(HWND,INT,INT,BOOL);
WINUSERAPI BOOL        WINAPI SetScrollRange(HWND,INT,INT,INT,BOOL);
#define                       SetSysModalWindow(hwnd) ((HWND)0)
WINUSERAPI BOOL        WINAPI SetSystemCursor(HCURSOR,DWORD);
WINUSERAPI BOOL        WINAPI SetSystemMenu(HWND,HMENU);
WINUSERAPI UINT_PTR    WINAPI SetSystemTimer(HWND,UINT_PTR,UINT,TIMERPROC);
WINUSERAPI BOOL        WINAPI SetThreadDesktop(HDESK);
WINUSERAPI UINT_PTR    WINAPI SetTimer(HWND,UINT_PTR,UINT,TIMERPROC);
WINUSERAPI BOOL        WINAPI SetUserObjectInformationA(HANDLE,INT,LPVOID,DWORD);
WINUSERAPI BOOL        WINAPI SetUserObjectInformationW(HANDLE,INT,LPVOID,DWORD);
#define                       SetUserObjectInformation WINELIB_NAME_AW(SetUserObjectInformation)
WINUSERAPI BOOL        WINAPI SetUserObjectSecurity(HANDLE,PSECURITY_INFORMATION,PSECURITY_DESCRIPTOR);
WINUSERAPI BOOL        WINAPI SetWindowContextHelpId(HWND,DWORD);
WINUSERAPI LONG        WINAPI SetWindowLongA(HWND,INT,LONG);
WINUSERAPI LONG        WINAPI SetWindowLongW(HWND,INT,LONG);
#define                       SetWindowLong WINELIB_NAME_AW(SetWindowLong)
#ifdef _WIN64
WINUSERAPI LONG_PTR    WINAPI SetWindowLongPtrA(HWND,INT,LONG_PTR);
WINUSERAPI LONG_PTR    WINAPI SetWindowLongPtrW(HWND,INT,LONG_PTR);
#else
#define                       SetWindowLongPtrA SetWindowLongA
#define                       SetWindowLongPtrW SetWindowLongW
#endif
#define                       SetWindowLongPtr WINELIB_NAME_AW(SetWindowLongPtr)
WINUSERAPI BOOL        WINAPI SetWindowPlacement(HWND,const WINDOWPLACEMENT*);
WINUSERAPI HHOOK       WINAPI SetWindowsHookA(INT,HOOKPROC);
WINUSERAPI HHOOK       WINAPI SetWindowsHookW(INT,HOOKPROC);
#define                       SetWindowsHook WINELIB_NAME_AW(SetWindowsHook)
WINUSERAPI HHOOK       WINAPI SetWindowsHookExA(INT,HOOKPROC,HINSTANCE,DWORD);
WINUSERAPI HHOOK       WINAPI SetWindowsHookExW(INT,HOOKPROC,HINSTANCE,DWORD);
#define                       SetWindowsHookEx WINELIB_NAME_AW(SetWindowsHookEx)
WINUSERAPI BOOL        WINAPI SetWindowPos(HWND,HWND,INT,INT,INT,INT,UINT);
WINUSERAPI INT         WINAPI SetWindowRgn(HWND,HRGN,BOOL);
WINUSERAPI BOOL        WINAPI SetWindowTextA(HWND,LPCSTR);
WINUSERAPI BOOL        WINAPI SetWindowTextW(HWND,LPCWSTR);
#define                       SetWindowText WINELIB_NAME_AW(SetWindowText)
WINUSERAPI WORD        WINAPI SetWindowWord(HWND,INT,WORD);
WINUSERAPI HWINEVENTHOOK WINAPI SetWinEventHook(DWORD,DWORD,HMODULE,WINEVENTPROC,DWORD,DWORD,DWORD);
WINUSERAPI BOOL        WINAPI ShowCaret(HWND);
WINUSERAPI INT         WINAPI ShowCursor(BOOL);
WINUSERAPI BOOL        WINAPI ShowScrollBar(HWND,INT,BOOL);
WINUSERAPI BOOL        WINAPI ShowOwnedPopups(HWND,BOOL);
WINUSERAPI BOOL        WINAPI ShowWindow(HWND,INT);
WINUSERAPI BOOL        WINAPI ShowWindowAsync(HWND,INT);
WINUSERAPI BOOL        WINAPI ShutdownBlockReasonCreate(HWND,LPCWSTR);
WINUSERAPI BOOL        WINAPI ShutdownBlockReasonDestroy(HWND);
WINUSERAPI BOOL        WINAPI SubtractRect(LPRECT,const RECT*,const RECT*);
WINUSERAPI BOOL        WINAPI SwapMouseButton(BOOL);
WINUSERAPI BOOL        WINAPI SwitchDesktop(HDESK);
WINUSERAPI VOID        WINAPI SwitchToThisWindow(HWND,BOOL);
WINUSERAPI BOOL        WINAPI SystemParametersInfoA(UINT,UINT,LPVOID,UINT);
WINUSERAPI BOOL        WINAPI SystemParametersInfoW(UINT,UINT,LPVOID,UINT);
#define                       SystemParametersInfo WINELIB_NAME_AW(SystemParametersInfo)
WINUSERAPI LONG        WINAPI TabbedTextOutA(HDC,INT,INT,LPCSTR,INT,INT,const INT*,INT);
WINUSERAPI LONG        WINAPI TabbedTextOutW(HDC,INT,INT,LPCWSTR,INT,INT,const INT*,INT);
#define                       TabbedTextOut WINELIB_NAME_AW(TabbedTextOut)
WINUSERAPI WORD        WINAPI TileWindows (HWND,UINT,const RECT *,UINT,const HWND *);
WINUSERAPI INT         WINAPI ToAscii(UINT,UINT,const BYTE *,LPWORD,UINT);
WINUSERAPI INT         WINAPI ToAsciiEx(UINT,UINT,const BYTE *,LPWORD,UINT,HKL);
WINUSERAPI INT         WINAPI ToUnicode(UINT,UINT,const BYTE *,LPWSTR,int,UINT);
WINUSERAPI INT         WINAPI ToUnicodeEx(UINT,UINT,const BYTE *,LPWSTR,int,UINT,HKL);
WINUSERAPI BOOL        WINAPI TrackMouseEvent(LPTRACKMOUSEEVENT);
WINUSERAPI BOOL        WINAPI TrackPopupMenu(HMENU,UINT,INT,INT,INT,HWND,const RECT*);
WINUSERAPI BOOL        WINAPI TrackPopupMenuEx(HMENU,UINT,INT,INT,HWND,LPTPMPARAMS);
WINUSERAPI INT         WINAPI TranslateAcceleratorA(HWND,HACCEL,LPMSG);
WINUSERAPI INT         WINAPI TranslateAcceleratorW(HWND,HACCEL,LPMSG);
#define                       TranslateAccelerator WINELIB_NAME_AW(TranslateAccelerator)
WINUSERAPI BOOL        WINAPI TranslateMDISysAccel(HWND,LPMSG);
WINUSERAPI BOOL        WINAPI TranslateMessage(const MSG*);
WINUSERAPI BOOL        WINAPI UnhookWinEvent(HWINEVENTHOOK);
WINUSERAPI BOOL        WINAPI UnhookWindowsHook(INT,HOOKPROC);
WINUSERAPI BOOL        WINAPI UnhookWindowsHookEx(HHOOK);
WINUSERAPI BOOL        WINAPI UnloadKeyboardLayout(HKL);
WINUSERAPI BOOL        WINAPI UnionRect(LPRECT,const RECT*,const RECT*);
WINUSERAPI BOOL        WINAPI UnregisterClassA(LPCSTR,HINSTANCE);
WINUSERAPI BOOL        WINAPI UnregisterClassW(LPCWSTR,HINSTANCE);
#define                       UnregisterClass WINELIB_NAME_AW(UnregisterClass)
WINUSERAPI BOOL        WINAPI UnregisterDeviceNotification(HDEVNOTIFY);
WINUSERAPI BOOL        WINAPI UnregisterHotKey(HWND,INT);
WINUSERAPI BOOL        WINAPI UnregisterPowerSettingNotification(HPOWERNOTIFY);
WINUSERAPI BOOL        WINAPI UnregisterTouchWindow(HWND);
WINUSERAPI BOOL        WINAPI UpdateWindow(HWND);
WINUSERAPI BOOL        WINAPI UserHandleGrantAccess(HANDLE,HANDLE,BOOL);
WINUSERAPI UINT        WINAPI UserRealizePalette(HDC);
WINUSERAPI BOOL        WINAPI ValidateRect(HWND,const RECT*);
WINUSERAPI BOOL        WINAPI ValidateRgn(HWND,HRGN);
WINUSERAPI SHORT       WINAPI VkKeyScanA(CHAR);
WINUSERAPI SHORT       WINAPI VkKeyScanW(WCHAR);
#define                       VkKeyScan WINELIB_NAME_AW(VkKeyScan)
WINUSERAPI WORD        WINAPI VkKeyScanExA(CHAR, HKL);
WINUSERAPI WORD        WINAPI VkKeyScanExW(WCHAR, HKL);
#define                       VkKeyScanEx WINELIB_NAME_AW(VkKeyScanEx)
WINUSERAPI DWORD       WINAPI WaitForInputIdle(HANDLE,DWORD);
WINUSERAPI BOOL        WINAPI WaitMessage(void);
WINUSERAPI HWND        WINAPI WindowFromDC(HDC);
WINUSERAPI HWND        WINAPI WindowFromPoint(POINT);
WINUSERAPI BOOL        WINAPI WinHelpA(HWND,LPCSTR,UINT,ULONG_PTR);
WINUSERAPI BOOL        WINAPI WinHelpW(HWND,LPCWSTR,UINT,ULONG_PTR);
#define                       WinHelp WINELIB_NAME_AW(WinHelp)
WINUSERAPI VOID        WINAPI keybd_event(BYTE,BYTE,DWORD,ULONG_PTR);
WINUSERAPI VOID        WINAPI mouse_event(DWORD,DWORD,DWORD,DWORD,ULONG_PTR);
WINUSERAPI INT        WINAPIV wsprintfA(LPSTR,LPCSTR,...);
WINUSERAPI INT        WINAPIV wsprintfW(LPWSTR,LPCWSTR,...);
#define                       wsprintf WINELIB_NAME_AW(wsprintf)
WINUSERAPI INT         WINAPI wvsprintfA(LPSTR,LPCSTR,__ms_va_list);
WINUSERAPI INT         WINAPI wvsprintfW(LPWSTR,LPCWSTR,__ms_va_list);
#define                       wvsprintf WINELIB_NAME_AW(wvsprintf)

#if !defined(__WINESRC__) || defined(WINE_NO_INLINE_RECT)

WINUSERAPI BOOL        WINAPI EqualRect(const RECT*,const RECT*);
WINUSERAPI BOOL        WINAPI InflateRect(LPRECT,INT,INT);
WINUSERAPI BOOL        WINAPI IsRectEmpty(const RECT*);
WINUSERAPI BOOL        WINAPI OffsetRect(LPRECT,INT,INT);
WINUSERAPI BOOL        WINAPI SetRect(LPRECT,INT,INT,INT,INT);
WINUSERAPI BOOL        WINAPI SetRectEmpty(LPRECT);

#else

/* Inline versions of common RECT helpers */

static inline BOOL WINAPI EqualRect(const RECT *rect1, const RECT *rect2)
{
    if (!rect1 || !rect2) return FALSE;
    return ((rect1->left == rect2->left) && (rect1->right == rect2->right) &&
            (rect1->top == rect2->top) && (rect1->bottom == rect2->bottom));
}

static inline BOOL WINAPI InflateRect(LPRECT rect, INT x, INT y)
{
    if (!rect) return FALSE;
    rect->left   -= x;
    rect->top    -= y;
    rect->right  += x;
    rect->bottom += y;
    return TRUE;
}

static inline BOOL WINAPI IsRectEmpty(const RECT *rect)
{
    if (!rect) return TRUE;
    return ((rect->left >= rect->right) || (rect->top >= rect->bottom));
}

static inline BOOL WINAPI OffsetRect(LPRECT rect, INT x, INT y)
{
    if (!rect) return FALSE;
    rect->left   += x;
    rect->right  += x;
    rect->top    += y;
    rect->bottom += y;
    return TRUE;
}

static inline BOOL WINAPI SetRect(LPRECT rect, INT left, INT top, INT right, INT bottom)
{
    if (!rect) return FALSE;
    rect->left   = left;
    rect->right  = right;
    rect->top    = top;
    rect->bottom = bottom;
    return TRUE;
}

static inline BOOL WINAPI SetRectEmpty(LPRECT rect)
{
    if (!rect) return FALSE;
    rect->left = rect->right = rect->top = rect->bottom = 0;
    return TRUE;
}

#endif /* !defined(__WINESRC__) || defined(WINE_NO_INLINE_RECT) */

/* Undocumented functions */

/* NOTE: This is SYSTEM.3, not USER.182, which is also named KillSystemTimer */
WORD        WINAPI SYSTEM_KillSystemTimer( WORD );

#ifdef __WINESRC__
WINUSERAPI BOOL CDECL __wine_send_input( HWND hwnd, const INPUT *input );
#endif

#ifdef __cplusplus
}
#endif

#endif /* _WINUSER_ */
