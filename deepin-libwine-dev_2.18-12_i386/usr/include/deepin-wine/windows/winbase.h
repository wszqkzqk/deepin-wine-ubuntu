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

#ifndef __WINE_WINBASE_H
#define __WINE_WINBASE_H

#include <winerror.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _KERNEL32_
#define WINBASEAPI
#else
#define WINBASEAPI DECLSPEC_IMPORT
#endif

#ifdef _ADVAPI32_
#define WINADVAPI
#else
#define WINADVAPI DECLSPEC_IMPORT
#endif

#include <libloaderapi.h>

  /* Windows Exit Procedure flag values */
#define	WEP_FREE_DLL        0
#define	WEP_SYSTEM_EXIT     1

typedef DWORD (CALLBACK *LPTHREAD_START_ROUTINE)(LPVOID);

typedef VOID (WINAPI *PFIBER_START_ROUTINE)( LPVOID lpFiberParameter );
typedef PFIBER_START_ROUTINE LPFIBER_START_ROUTINE;

#define FIBER_FLAG_FLOAT_SWITCH     1

typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;
typedef PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
typedef PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;

typedef RTL_CRITICAL_SECTION_DEBUG CRITICAL_SECTION_DEBUG;
typedef PRTL_CRITICAL_SECTION_DEBUG PCRITICAL_SECTION_DEBUG;
typedef PRTL_CRITICAL_SECTION_DEBUG LPCRITICAL_SECTION_DEBUG;

#define CRITICAL_SECTION_NO_DEBUG_INFO RTL_CRITICAL_SECTION_FLAG_NO_DEBUG_INFO

typedef RTL_SRWLOCK SRWLOCK;
typedef PRTL_SRWLOCK PSRWLOCK;

#define SRWLOCK_INIT RTL_SRWLOCK_INIT

typedef WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK;

#define CONDITION_VARIABLE_INIT RTL_CONDITION_VARIABLE_INIT
#define CONDITION_VARIABLE_LOCKMODE_SHARED RTL_CONDITION_VARIABLE_LOCKMODE_SHARED
typedef RTL_CONDITION_VARIABLE CONDITION_VARIABLE, *PCONDITION_VARIABLE;

#define EXCEPTION_DEBUG_EVENT       1
#define CREATE_THREAD_DEBUG_EVENT   2
#define CREATE_PROCESS_DEBUG_EVENT  3
#define EXIT_THREAD_DEBUG_EVENT     4
#define EXIT_PROCESS_DEBUG_EVENT    5
#define LOAD_DLL_DEBUG_EVENT        6
#define UNLOAD_DLL_DEBUG_EVENT      7
#define OUTPUT_DEBUG_STRING_EVENT   8
#define RIP_EVENT                   9

typedef struct _EXCEPTION_DEBUG_INFO {
    EXCEPTION_RECORD ExceptionRecord;
    DWORD dwFirstChance;
} EXCEPTION_DEBUG_INFO;

typedef struct _CREATE_THREAD_DEBUG_INFO {
    HANDLE hThread;
    LPVOID lpThreadLocalBase;
    LPTHREAD_START_ROUTINE lpStartAddress;
} CREATE_THREAD_DEBUG_INFO;

typedef struct _CREATE_PROCESS_DEBUG_INFO {
    HANDLE hFile;
    HANDLE hProcess;
    HANDLE hThread;
    LPVOID lpBaseOfImage;
    DWORD dwDebugInfoFileOffset;
    DWORD nDebugInfoSize;
    LPVOID lpThreadLocalBase;
    LPTHREAD_START_ROUTINE lpStartAddress;
    LPVOID lpImageName;
    WORD fUnicode;
} CREATE_PROCESS_DEBUG_INFO;

typedef struct _EXIT_THREAD_DEBUG_INFO {
    DWORD dwExitCode;
} EXIT_THREAD_DEBUG_INFO;

typedef struct _EXIT_PROCESS_DEBUG_INFO {
    DWORD dwExitCode;
} EXIT_PROCESS_DEBUG_INFO;

typedef struct _LOAD_DLL_DEBUG_INFO {
    HANDLE hFile;
    LPVOID   lpBaseOfDll;
    DWORD    dwDebugInfoFileOffset;
    DWORD    nDebugInfoSize;
    LPVOID   lpImageName;
    WORD     fUnicode;
} LOAD_DLL_DEBUG_INFO;

typedef struct _UNLOAD_DLL_DEBUG_INFO {
    LPVOID lpBaseOfDll;
} UNLOAD_DLL_DEBUG_INFO;

typedef struct _OUTPUT_DEBUG_STRING_INFO {
    LPSTR lpDebugStringData;
    WORD  fUnicode;
    WORD  nDebugStringLength;
} OUTPUT_DEBUG_STRING_INFO;

typedef struct _RIP_INFO {
    DWORD dwError;
    DWORD dwType;
} RIP_INFO;

typedef struct _DEBUG_EVENT {
    DWORD dwDebugEventCode;
    DWORD dwProcessId;
    DWORD dwThreadId;
    union {
        EXCEPTION_DEBUG_INFO      Exception;
        CREATE_THREAD_DEBUG_INFO  CreateThread;
        CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
        EXIT_THREAD_DEBUG_INFO    ExitThread;
        EXIT_PROCESS_DEBUG_INFO   ExitProcess;
        LOAD_DLL_DEBUG_INFO       LoadDll;
        UNLOAD_DLL_DEBUG_INFO     UnloadDll;
        OUTPUT_DEBUG_STRING_INFO  DebugString;
        RIP_INFO                  RipInfo;
    } u;
} DEBUG_EVENT, *LPDEBUG_EVENT;

typedef PCONTEXT LPCONTEXT;
typedef PEXCEPTION_RECORD LPEXCEPTION_RECORD;
typedef PEXCEPTION_POINTERS LPEXCEPTION_POINTERS;

typedef LONG (CALLBACK *PTOP_LEVEL_EXCEPTION_FILTER)(PEXCEPTION_POINTERS);
typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

#define OFS_MAXPATHNAME 128
typedef struct _OFSTRUCT
{
    BYTE cBytes;
    BYTE fFixedDisk;
    WORD nErrCode;
    WORD Reserved1;
    WORD Reserved2;
    CHAR szPathName[OFS_MAXPATHNAME];
} OFSTRUCT, *POFSTRUCT, *LPOFSTRUCT;

#define OF_READ               0x0000
#define OF_WRITE              0x0001
#define OF_READWRITE          0x0002
#define OF_SHARE_COMPAT       0x0000
#define OF_SHARE_EXCLUSIVE    0x0010
#define OF_SHARE_DENY_WRITE   0x0020
#define OF_SHARE_DENY_READ    0x0030
#define OF_SHARE_DENY_NONE    0x0040
#define OF_PARSE              0x0100
#define OF_DELETE             0x0200
#define OF_VERIFY             0x0400   /* Used with OF_REOPEN */
#define OF_SEARCH             0x0400   /* Used without OF_REOPEN */
#define OF_CANCEL             0x0800
#define OF_CREATE             0x1000
#define OF_PROMPT             0x2000
#define OF_EXIST              0x4000
#define OF_REOPEN             0x8000

/* SetErrorMode values */
#define SEM_FAILCRITICALERRORS      0x0001
#define SEM_NOGPFAULTERRORBOX       0x0002
#define SEM_NOALIGNMENTFAULTEXCEPT  0x0004
#define SEM_NOOPENFILEERRORBOX      0x8000

/* CopyFileEx flags */
#define COPY_FILE_FAIL_IF_EXISTS        0x00000001
#define COPY_FILE_RESTARTABLE           0x00000002
#define COPY_FILE_OPEN_SOURCE_FOR_WRITE 0x00000004
#define COPY_FILE_ALLOW_DECRYPTED_DESTINATION  0x00000008
#define COPY_FILE_COPY_SYMLINK          0x00000800
#define COPY_FILE_NO_BUFFERING          0x00001000

/* return values for CopyProgressRoutine */
#define PROGRESS_CONTINUE   0
#define PROGRESS_CANCEL     1
#define PROGRESS_STOP       2
#define PROGRESS_QUIET      3

/* reason codes for CopyProgressRoutine */
#define CALLBACK_CHUNK_FINISHED 0
#define CALLBACK_STREAM_SWITCH  1

/* GetTempFileName() Flags */
#define TF_FORCEDRIVE	        0x80

#define DRIVE_UNKNOWN              0
#define DRIVE_NO_ROOT_DIR          1
#define DRIVE_REMOVABLE            2
#define DRIVE_FIXED                3
#define DRIVE_REMOTE               4
/* Win32 additions */
#define DRIVE_CDROM                5
#define DRIVE_RAMDISK              6

#define MAX_COMPUTERNAME_LENGTH    15

/* The security attributes structure */
typedef struct _SECURITY_ATTRIBUTES
{
    DWORD   nLength;
    LPVOID  lpSecurityDescriptor;
    BOOL  bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

#ifndef _FILETIME_
#define _FILETIME_
/* 64 bit number of 100 nanoseconds intervals since January 1, 1601 */
typedef struct _FILETIME
{
#ifdef WORDS_BIGENDIAN
  DWORD  dwHighDateTime;
  DWORD  dwLowDateTime;
#else
  DWORD  dwLowDateTime;
  DWORD  dwHighDateTime;
#endif
} FILETIME, *PFILETIME, *LPFILETIME;
#endif /* _FILETIME_ */

/* Find* structures */
typedef struct _WIN32_FIND_DATAA
{
    DWORD     dwFileAttributes;
    FILETIME  ftCreationTime;
    FILETIME  ftLastAccessTime;
    FILETIME  ftLastWriteTime;
    DWORD     nFileSizeHigh;
    DWORD     nFileSizeLow;
    DWORD     dwReserved0;
    DWORD     dwReserved1;
    CHAR      cFileName[260];
    CHAR      cAlternateFileName[14];
} WIN32_FIND_DATAA, *PWIN32_FIND_DATAA, *LPWIN32_FIND_DATAA;

typedef struct _WIN32_FIND_DATAW
{
    DWORD     dwFileAttributes;
    FILETIME  ftCreationTime;
    FILETIME  ftLastAccessTime;
    FILETIME  ftLastWriteTime;
    DWORD     nFileSizeHigh;
    DWORD     nFileSizeLow;
    DWORD     dwReserved0;
    DWORD     dwReserved1;
    WCHAR     cFileName[260];
    WCHAR     cAlternateFileName[14];
} WIN32_FIND_DATAW, *PWIN32_FIND_DATAW, *LPWIN32_FIND_DATAW;

DECL_WINELIB_TYPE_AW(WIN32_FIND_DATA)
DECL_WINELIB_TYPE_AW(PWIN32_FIND_DATA)
DECL_WINELIB_TYPE_AW(LPWIN32_FIND_DATA)

typedef enum _FINDEX_INFO_LEVELS
{
	FindExInfoStandard,
	FindExInfoBasic,
	FindExInfoMaxInfoLevel
} FINDEX_INFO_LEVELS;

#define FIND_FIRST_EX_CASE_SENSITIVE 1
#define FIND_FIRST_EX_LARGE_FETCH    2

typedef enum _FINDEX_SEARCH_OPS
{
	FindExSearchNameMatch,
	FindExSearchLimitToDirectories,
	FindExSearchLimitToDevices,
	FindExSearchMaxSearchOp
} FINDEX_SEARCH_OPS;

typedef struct _PROCESS_HEAP_ENTRY
{
    LPVOID lpData;
    DWORD cbData;
    BYTE cbOverhead;
    BYTE iRegionIndex;
    WORD wFlags;
    union {
        struct {
            HANDLE hMem;
            DWORD dwReserved[3];
        } Block;
        struct {
            DWORD dwCommittedSize;
            DWORD dwUnCommittedSize;
            LPVOID lpFirstBlock;
            LPVOID lpLastBlock;
        } Region;
    } DUMMYUNIONNAME;
} PROCESS_HEAP_ENTRY, *PPROCESS_HEAP_ENTRY, *LPPROCESS_HEAP_ENTRY;

#define PROCESS_HEAP_REGION                   0x0001
#define PROCESS_HEAP_UNCOMMITTED_RANGE        0x0002
#define PROCESS_HEAP_ENTRY_BUSY               0x0004
#define PROCESS_HEAP_ENTRY_MOVEABLE           0x0010
#define PROCESS_HEAP_ENTRY_DDESHARE           0x0020

#define INVALID_HANDLE_VALUE     ((HANDLE)~(ULONG_PTR)0)
#define INVALID_FILE_SIZE        (~0u)
#define INVALID_SET_FILE_POINTER (~0u)
#define INVALID_FILE_ATTRIBUTES  (~0u)

#define LOCKFILE_FAIL_IMMEDIATELY   1
#define LOCKFILE_EXCLUSIVE_LOCK     2

#define FLS_OUT_OF_INDEXES (~0u)
#define TLS_OUT_OF_INDEXES (~0u)

#define SHUTDOWN_NORETRY 1

/* comm */

#define CBR_110	0xFF10
#define CBR_300	0xFF11
#define CBR_600	0xFF12
#define CBR_1200	0xFF13
#define CBR_2400	0xFF14
#define CBR_4800	0xFF15
#define CBR_9600	0xFF16
#define CBR_14400	0xFF17
#define CBR_19200	0xFF18
#define CBR_38400	0xFF1B
#define CBR_56000	0xFF1F
#define CBR_57600       0xFF20
#define CBR_115200      0xFF21
#define CBR_128000	0xFF23
#define CBR_256000	0xFF27

#define NOPARITY	0
#define ODDPARITY	1
#define EVENPARITY	2
#define MARKPARITY	3
#define SPACEPARITY	4
#define ONESTOPBIT	0
#define ONE5STOPBITS	1
#define TWOSTOPBITS	2

#define IGNORE		0
#define INFINITE      0xFFFFFFFF

#define CE_RXOVER	0x0001
#define CE_OVERRUN	0x0002
#define CE_RXPARITY	0x0004
#define CE_FRAME	0x0008
#define CE_BREAK	0x0010
#define CE_CTSTO	0x0020
#define CE_DSRTO	0x0040
#define CE_RLSDTO	0x0080
#define CE_TXFULL	0x0100
#define CE_PTO		0x0200
#define CE_IOE		0x0400
#define CE_DNS		0x0800
#define CE_OOP		0x1000
#define CE_MODE	0x8000

#define IE_BADID	-1
#define IE_OPEN	-2
#define IE_NOPEN	-3
#define IE_MEMORY	-4
#define IE_DEFAULT	-5
#define IE_HARDWARE	-10
#define IE_BYTESIZE	-11
#define IE_BAUDRATE	-12

#define EV_RXCHAR    0x0001
#define EV_RXFLAG    0x0002
#define EV_TXEMPTY   0x0004
#define EV_CTS       0x0008
#define EV_DSR       0x0010
#define EV_RLSD      0x0020
#define EV_BREAK     0x0040
#define EV_ERR       0x0080
#define EV_RING      0x0100
#define EV_PERR      0x0200
#define EV_RX80FULL  0x0400
#define EV_EVENT1    0x0800
#define EV_EVENT2    0x1000

#define SETXOFF	1
#define SETXON		2
#define SETRTS		3
#define CLRRTS		4
#define SETDTR		5
#define CLRDTR		6
#define RESETDEV	7
#define SETBREAK	8
#define CLRBREAK	9

/* Purge functions for Comm Port */
#define PURGE_TXABORT       0x0001  /* Kill the pending/current writes to the
				       comm port */
#define PURGE_RXABORT       0x0002  /*Kill the pending/current reads to
				     the comm port */
#define PURGE_TXCLEAR       0x0004  /* Kill the transmit queue if there*/
#define PURGE_RXCLEAR       0x0008  /* Kill the typeahead buffer if there*/


/* Modem Status Flags */
#define MS_CTS_ON           ((DWORD)0x0010)
#define MS_DSR_ON           ((DWORD)0x0020)
#define MS_RING_ON          ((DWORD)0x0040)
#define MS_RLSD_ON          ((DWORD)0x0080)

#define	RTS_CONTROL_DISABLE	0
#define	RTS_CONTROL_ENABLE	1
#define	RTS_CONTROL_HANDSHAKE	2
#define	RTS_CONTROL_TOGGLE	3

#define	DTR_CONTROL_DISABLE	0
#define	DTR_CONTROL_ENABLE	1
#define	DTR_CONTROL_HANDSHAKE	2


#define LMEM_FIXED          0
#define LMEM_MOVEABLE       0x0002
#define LMEM_NOCOMPACT      0x0010
#define LMEM_NODISCARD      0x0020
#define LMEM_ZEROINIT       0x0040
#define LMEM_MODIFY         0x0080
#define LMEM_DISCARDABLE    0x0F00
#define LMEM_DISCARDED      0x4000
#define LMEM_INVALID_HANDLE 0x8000
#define LMEM_LOCKCOUNT      0x00FF

#define LPTR (LMEM_FIXED | LMEM_ZEROINIT)
#define LHND (LMEM_MOVEABLE | LMEM_ZEROINIT)

#define NONZEROLHND         (LMEM_MOVEABLE)
#define NONZEROLPTR         (LMEM_FIXED)

#define LocalDiscard(h)     (LocalReAlloc((h),0,LMEM_MOVEABLE))

#define GMEM_FIXED          0x0000
#define GMEM_MOVEABLE       0x0002
#define GMEM_NOCOMPACT      0x0010
#define GMEM_NODISCARD      0x0020
#define GMEM_ZEROINIT       0x0040
#define GMEM_MODIFY         0x0080
#define GMEM_DISCARDABLE    0x0100
#define GMEM_NOT_BANKED     0x1000
#define GMEM_SHARE          0x2000
#define GMEM_DDESHARE       0x2000
#define GMEM_NOTIFY         0x4000
#define GMEM_LOWER          GMEM_NOT_BANKED
#define GMEM_DISCARDED      0x4000
#define GMEM_LOCKCOUNT      0x00ff
#define GMEM_INVALID_HANDLE 0x8000

#define GHND                (GMEM_MOVEABLE | GMEM_ZEROINIT)
#define GPTR                (GMEM_FIXED | GMEM_ZEROINIT)

#define GlobalLRUNewest(h)  ((HANDLE)(h))
#define GlobalLRUOldest(h)  ((HANDLE)(h))
#define GlobalDiscard(h)    (GlobalReAlloc((h),0,GMEM_MOVEABLE))

#define INVALID_ATOM        ((ATOM)0)
#define MAXINTATOM          0xc000
#ifdef WINE_NO_UNICODE_MACROS /* force using a cast */
#define MAKEINTATOM(atom)   ((ULONG_PTR)((WORD)(atom)))
#else
#define MAKEINTATOM(atom)   ((LPTSTR)((ULONG_PTR)((WORD)(atom))))
#endif

typedef struct tagMEMORYSTATUS
{
    DWORD    dwLength;
    DWORD    dwMemoryLoad;
    SIZE_T   dwTotalPhys;
    SIZE_T   dwAvailPhys;
    SIZE_T   dwTotalPageFile;
    SIZE_T   dwAvailPageFile;
    SIZE_T   dwTotalVirtual;
    SIZE_T   dwAvailVirtual;
} MEMORYSTATUS, *LPMEMORYSTATUS;

#include <pshpack8.h>
typedef struct tagMEMORYSTATUSEX {
  DWORD dwLength;
  DWORD dwMemoryLoad;
  DWORDLONG DECLSPEC_ALIGN(8) ullTotalPhys;
  DWORDLONG DECLSPEC_ALIGN(8) ullAvailPhys;
  DWORDLONG DECLSPEC_ALIGN(8) ullTotalPageFile;
  DWORDLONG DECLSPEC_ALIGN(8) ullAvailPageFile;
  DWORDLONG DECLSPEC_ALIGN(8) ullTotalVirtual;
  DWORDLONG DECLSPEC_ALIGN(8) ullAvailVirtual;
  DWORDLONG DECLSPEC_ALIGN(8) ullAvailExtendedVirtual;
} MEMORYSTATUSEX, *LPMEMORYSTATUSEX;
#include <poppack.h>

typedef enum _MEMORY_RESOURCE_NOTIFICATION_TYPE {
    LowMemoryResourceNotification,
    HighMemoryResourceNotification
} MEMORY_RESOURCE_NOTIFICATION_TYPE;

#ifndef _SYSTEMTIME_
#define _SYSTEMTIME_
typedef struct _SYSTEMTIME{
        WORD wYear;
        WORD wMonth;
        WORD wDayOfWeek;
        WORD wDay;
        WORD wHour;
        WORD wMinute;
        WORD wSecond;
        WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;
#endif /* _SYSTEMTIME_ */

/* The 'overlapped' data structure used by async I/O functions.
 */
typedef struct _OVERLAPPED {
#ifdef WORDS_BIGENDIAN
        ULONG_PTR InternalHigh;
        ULONG_PTR Internal;
#else
        ULONG_PTR Internal;
        ULONG_PTR InternalHigh;
#endif
        union {
            struct {
#ifdef WORDS_BIGENDIAN
                DWORD OffsetHigh;
                DWORD Offset;
#else
                DWORD Offset;
                DWORD OffsetHigh;
#endif
            } DUMMYSTRUCTNAME;
            PVOID Pointer;
        } DUMMYUNIONNAME;
        HANDLE hEvent;
} OVERLAPPED, *LPOVERLAPPED;

typedef VOID (CALLBACK *LPOVERLAPPED_COMPLETION_ROUTINE)(DWORD,DWORD,LPOVERLAPPED);

/* Process startup information.
 */

/* STARTUPINFO.dwFlags */
#define	STARTF_USESHOWWINDOW	0x00000001
#define	STARTF_USESIZE		0x00000002
#define	STARTF_USEPOSITION	0x00000004
#define	STARTF_USECOUNTCHARS	0x00000008
#define	STARTF_USEFILLATTRIBUTE	0x00000010
#define	STARTF_RUNFULLSCREEN	0x00000020
#define	STARTF_FORCEONFEEDBACK	0x00000040
#define	STARTF_FORCEOFFFEEDBACK	0x00000080
#define	STARTF_USESTDHANDLES	0x00000100
#define	STARTF_USEHOTKEY	0x00000200

typedef struct _STARTUPINFOA{
        DWORD cb;		/* 00: size of struct */
        LPSTR lpReserved;	/* 04: */
        LPSTR lpDesktop;	/* 08: */
        LPSTR lpTitle;		/* 0c: */
        DWORD dwX;		/* 10: */
        DWORD dwY;		/* 14: */
        DWORD dwXSize;		/* 18: */
        DWORD dwYSize;		/* 1c: */
        DWORD dwXCountChars;	/* 20: */
        DWORD dwYCountChars;	/* 24: */
        DWORD dwFillAttribute;	/* 28: */
        DWORD dwFlags;		/* 2c: */
        WORD wShowWindow;	/* 30: */
        WORD cbReserved2;	/* 32: */
        BYTE *lpReserved2;	/* 34: */
        HANDLE hStdInput;	/* 38: */
        HANDLE hStdOutput;	/* 3c: */
        HANDLE hStdError;	/* 40: */
} STARTUPINFOA, *LPSTARTUPINFOA;

typedef struct _STARTUPINFOW{
        DWORD cb;
        LPWSTR lpReserved;
        LPWSTR lpDesktop;
        LPWSTR lpTitle;
        DWORD dwX;
        DWORD dwY;
        DWORD dwXSize;
        DWORD dwYSize;
        DWORD dwXCountChars;
        DWORD dwYCountChars;
        DWORD dwFillAttribute;
        DWORD dwFlags;
        WORD wShowWindow;
        WORD cbReserved2;
        BYTE *lpReserved2;
        HANDLE hStdInput;
        HANDLE hStdOutput;
        HANDLE hStdError;
} STARTUPINFOW, *LPSTARTUPINFOW;

DECL_WINELIB_TYPE_AW(STARTUPINFO)
DECL_WINELIB_TYPE_AW(LPSTARTUPINFO)

typedef struct _PROCESS_INFORMATION{
	HANDLE	hProcess;
	HANDLE	hThread;
	DWORD		dwProcessId;
	DWORD		dwThreadId;
} PROCESS_INFORMATION, *PPROCESS_INFORMATION, *LPPROCESS_INFORMATION;

typedef struct _TIME_DYNAMIC_ZONE_INFORMATION
{
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
    WCHAR TimeZoneKeyName[128];
    BOOLEAN DynamicDaylightTimeDisabled;
} DYNAMIC_TIME_ZONE_INFORMATION, *PDYNAMIC_TIME_ZONE_INFORMATION;

typedef struct _TIME_ZONE_INFORMATION{
        LONG Bias;
        WCHAR StandardName[32];
        SYSTEMTIME StandardDate;
        LONG StandardBias;
        WCHAR DaylightName[32];
        SYSTEMTIME DaylightDate;
        LONG DaylightBias;
} TIME_ZONE_INFORMATION, *PTIME_ZONE_INFORMATION, *LPTIME_ZONE_INFORMATION;

#define TIME_ZONE_ID_INVALID	((DWORD)0xFFFFFFFF)
#define TIME_ZONE_ID_UNKNOWN    0
#define TIME_ZONE_ID_STANDARD   1
#define TIME_ZONE_ID_DAYLIGHT   2

/* CreateProcess: dwCreationFlag values
 */
#define DEBUG_PROCESS               0x00000001
#define DEBUG_ONLY_THIS_PROCESS     0x00000002
#define CREATE_SUSPENDED            0x00000004
#define DETACHED_PROCESS            0x00000008
#define CREATE_NEW_CONSOLE          0x00000010
#define NORMAL_PRIORITY_CLASS       0x00000020
#define IDLE_PRIORITY_CLASS         0x00000040
#define HIGH_PRIORITY_CLASS         0x00000080
#define REALTIME_PRIORITY_CLASS     0x00000100
#define BELOW_NORMAL_PRIORITY_CLASS 0x00004000
#define ABOVE_NORMAL_PRIORITY_CLASS 0x00008000
#define CREATE_NEW_PROCESS_GROUP    0x00000200
#define CREATE_UNICODE_ENVIRONMENT  0x00000400
#define CREATE_SEPARATE_WOW_VDM     0x00000800
#define CREATE_SHARED_WOW_VDM       0x00001000
#define STACK_SIZE_PARAM_IS_A_RESERVATION 0x00010000
#define CREATE_BREAKAWAY_FROM_JOB   0x01000000
#define CREATE_DEFAULT_ERROR_MODE   0x04000000
#define CREATE_NO_WINDOW            0x08000000
#define PROFILE_USER                0x10000000
#define PROFILE_KERNEL              0x20000000
#define PROFILE_SERVER              0x40000000


/* File object type definitions
 */
#define FILE_TYPE_UNKNOWN       0
#define FILE_TYPE_DISK          1
#define FILE_TYPE_CHAR          2
#define FILE_TYPE_PIPE          3
#define FILE_TYPE_REMOTE        32768

/* File encryption status
 */
#define FILE_ENCRYPTABLE         0
#define FILE_IS_ENCRYPTED        1
#define FILE_SYSTEM_ATTR         2
#define FILE_ROOT_DIR            3
#define FILE_SYSTEM_DIR          4
#define FILE_UNKNOWN             5
#define FILE_SYSTEM_NOT_SUPPORT  6
#define FILE_USER_DISALLOWED     7
#define FILE_READ_ONLY           8
#define FILE_DIR_DISALLOWED      9

typedef DWORD (WINAPI *PFE_EXPORT_FUNC)(PBYTE,PVOID,ULONG);
typedef DWORD (WINAPI *PFE_IMPORT_FUNC)(PBYTE,PVOID,ULONG);

#define CREATE_FOR_IMPORT  (1)
#define CREATE_FOR_DIR     (2)
#define OVERWRITE_HIDDEN   (4)
#define EFSRPC_SECURE_ONLY (8)

/* File creation flags
 */
#define FILE_FLAG_WRITE_THROUGH         0x80000000
#define FILE_FLAG_OVERLAPPED            0x40000000
#define FILE_FLAG_NO_BUFFERING          0x20000000
#define FILE_FLAG_RANDOM_ACCESS         0x10000000
#define FILE_FLAG_SEQUENTIAL_SCAN       0x08000000
#define FILE_FLAG_DELETE_ON_CLOSE       0x04000000
#define FILE_FLAG_BACKUP_SEMANTICS      0x02000000
#define FILE_FLAG_POSIX_SEMANTICS       0x01000000
#define FILE_FLAG_OPEN_REPARSE_POINT    0x00200000
#define FILE_FLAG_OPEN_NO_RECALL        0x00100000
#define FILE_FLAG_FIRST_PIPE_INSTANCE   0x00080000

#define CREATE_NEW              1
#define CREATE_ALWAYS           2
#define OPEN_EXISTING           3
#define OPEN_ALWAYS             4
#define TRUNCATE_EXISTING       5

/* Standard handle identifiers
 */
#define STD_INPUT_HANDLE        ((DWORD) -10)
#define STD_OUTPUT_HANDLE       ((DWORD) -11)
#define STD_ERROR_HANDLE        ((DWORD) -12)

/* Flags for GetFinalPathNameByHandle
 */
#define FILE_NAME_NORMALIZED    0x0
#define FILE_NAME_OPENED        0x8
#define VOLUME_NAME_DOS         0x0
#define VOLUME_NAME_GUID        0x1
#define VOLUME_NAME_NT          0x2
#define VOLUME_NAME_NONE        0x4

typedef struct _BY_HANDLE_FILE_INFORMATION
{
  DWORD dwFileAttributes;
  FILETIME ftCreationTime;
  FILETIME ftLastAccessTime;
  FILETIME ftLastWriteTime;
  DWORD dwVolumeSerialNumber;
  DWORD nFileSizeHigh;
  DWORD nFileSizeLow;
  DWORD nNumberOfLinks;
  DWORD nFileIndexHigh;
  DWORD nFileIndexLow;
} BY_HANDLE_FILE_INFORMATION, *PBY_HANDLE_FILE_INFORMATION, *LPBY_HANDLE_FILE_INFORMATION ;

typedef enum _FILE_ID_TYPE {
    FileIdType,
    ObjectIdType,
    ExtendedFileIdType,
    MaximumFileIdType
} FILE_ID_TYPE, *PFILE_ID_TYPE;

typedef struct _FILE_ID_DESCRIPTOR {
    DWORD        dwSize;
    FILE_ID_TYPE Type;
    union {
        LARGE_INTEGER FileId;
        GUID          ObjectId;
    } DUMMYUNIONNAME;
} FILE_ID_DESCRIPTOR, *LPFILE_ID_DESCRIPTOR;

typedef enum _FILE_INFO_BY_HANDLE_CLASS {
    FileBasicInfo,
    FileStandardInfo,
    FileNameInfo,
    FileRenameInfo,
    FileDispositionInfo,
    FileAllocationInfo,
    FileEndOfFileInfo,
    FileStreamInfo,
    FileCompressionInfo,
    FileAttributeTagInfo,
    FileIdBothDirectoryInfo,
    FileIdBothDirectoryRestartInfo,
    FileIoPriorityHintInfo,
    FileRemoteProtocolInfo,
    FileFullDirectoryInfo,
    FileFullDirectoryRestartInfo,
    FileStorageInfo,
    FileAlignmentInfo,
    FileIdInfo,
    FileIdExtdDirectoryInfo,
    FileIdExtdDirectoryRestartInfo,
    MaximumFileInfoByHandlesClass
} FILE_INFO_BY_HANDLE_CLASS, *PFILE_INFO_BY_HANDLE_CLASS;

typedef struct _FILE_ID_BOTH_DIR_INFO {
    DWORD         NextEntryOffset;
    DWORD         FileIndex;
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER EndOfFile;
    LARGE_INTEGER AllocationSize;
    DWORD         FileAttributes;
    DWORD         FileNameLength;
    DWORD         EaSize;
    CCHAR         ShortNameLength;
    WCHAR         ShortName[12];
    LARGE_INTEGER FileId;
    WCHAR         FileName[1];
} FILE_ID_BOTH_DIR_INFO, *PFILE_ID_BOTH_DIR_INFO;

typedef struct _FILE_BASIC_INFO {
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    DWORD         FileAttributes;
} FILE_BASIC_INFO, *PFILE_BASIC_INFO;

typedef struct _FILE_STANDARD_INFO {
    LARGE_INTEGER AllocationSize;
    LARGE_INTEGER EndOfFile;
    DWORD         NumberOfLinks;
    BOOLEAN       DeletePending;
    BOOLEAN       Directory;
} FILE_STANDARD_INFO, *PFILE_STANDARD_INFO;

typedef struct _FILE_NAME_INFO {
    DWORD         FileNameLength;
    WCHAR         FileName[1];
} FILE_NAME_INFO, *PFILE_NAME_INFO;

typedef enum _PRIORITY_HINT {
    IoPriorityHintVeryLow,
    IoPriorityHintLow,
    IoPriorityHintNormal,
    MaximumIoPriorityHintType
} PRIORITY_HINT;

typedef struct _FILE_IO_PRIORITY_HINT_INFO {
    PRIORITY_HINT PriorityHint;
} FILE_IO_PRIORITY_HINT_INFO;

typedef struct _FILE_ALLOCATION_INFO {
    LARGE_INTEGER AllocationSize;
} FILE_ALLOCATION_INFO, *PFILE_ALLOCATION_INFO;

typedef struct _FILE_DISPOSITION_INFO {
    BOOLEAN DeleteFile;
} FILE_DISPOSITION_INFO, *PFILE_DISPOSITION_INFO;

typedef struct _FILE_END_OF_FILE_INFO {
    LARGE_INTEGER EndOfFile;
} FILE_END_OF_FILE_INFO, *PFILE_END_OF_FILE_INFO;

typedef struct _FILE_RENAME_INFO {
    BOOLEAN ReplaceIfExists;
    HANDLE RootDirectory;
    DWORD FileNameLength;
    WCHAR FileName[1];
} FILE_RENAME_INFO, *PFILE_RENAME_INFO;

typedef struct _FILE_ATTRIBUTE_TAG_INFO {
    DWORD FileAttributes;
    DWORD ReparseTag;
} FILE_ATTRIBUTE_TAG_INFO, *PFILE_ATTRIBUTE_TAG_INFO;

typedef struct _FILE_COMPRESSION_INFO {
    LARGE_INTEGER CompressedFileSize;
    WORD CompressionFormat;
    UCHAR CompressionUnitShift;
    UCHAR ChunkShift;
    UCHAR ClusterShift;
    UCHAR Reserved[3];
} FILE_COMPRESSION_INFO, *PFILE_COMPRESSION_INFO;

typedef struct _FILE_REMOTE_PROTOCOL_INFO {
    USHORT StructureVersion;
    USHORT StructureSize;
    ULONG Protocol;
    USHORT ProtocolMajorVersion;
    USHORT ProtocolMinorVersion;
    USHORT ProtocolRevision;
    USHORT Reserved;
    ULONG Flags;
    struct {
        ULONG Reserved[8];
    } GenericReserved;
    struct {
        ULONG Reserved[16];
    } ProtocolSpecificReserved;
} FILE_REMOTE_PROTOCOL_INFO, *PFILE_REMOTE_PROTOCOL_INFO;

#define PIPE_ACCESS_INBOUND  1
#define PIPE_ACCESS_OUTBOUND 2
#define PIPE_ACCESS_DUPLEX   3

#define PIPE_CLIENT_END       0
#define PIPE_SERVER_END       1
#define PIPE_READMODE_BYTE    0
#define PIPE_READMODE_MESSAGE 2
#define PIPE_TYPE_BYTE        0
#define PIPE_TYPE_MESSAGE     4

#define PIPE_WAIT   0
#define PIPE_NOWAIT 1

#define PIPE_UNLIMITED_INSTANCES 255

#define NMPWAIT_WAIT_FOREVER		0xffffffff
#define NMPWAIT_NOWAIT			0x00000001
#define NMPWAIT_USE_DEFAULT_WAIT	0x00000000

/* Security flags for dwFlagsAndAttributes of CreateFile */
#define SECURITY_ANONYMOUS          (SecurityAnonymous << 16)
#define SECURITY_IDENTIFICATION     (SecurityIdentification << 16)
#define SECURITY_IMPERSONATION      (SecurityImpersonation << 16)
#define SECURITY_DELEGATION         (SecurityDelegation << 16)

#define SECURITY_CONTEXT_TRACKING   0x00040000
#define SECURITY_EFFECTIVE_ONLY     0x00080000

#define SECURITY_SQOS_PRESENT       0x00100000
#define SECURITY_VALID_SQOS_FLAGS   0x001f0000

typedef struct _SYSTEM_POWER_STATUS
{
  BYTE    ACLineStatus;
  BYTE    BatteryFlag;
  BYTE    BatteryLifePercent;
  BYTE    Reserved1;
  DWORD   BatteryLifeTime;
  DWORD   BatteryFullLifeTime;
} SYSTEM_POWER_STATUS, *LPSYSTEM_POWER_STATUS;

typedef enum _POWER_REQUEST_TYPE
{
    PowerRequestDisplayRequired,
    PowerRequestSystemRequired,
    PowerRequestAwayModeRequired
} POWER_REQUEST_TYPE, *PPOWER_REQUEST_TYPE;

typedef struct _SYSTEM_INFO
{
    union {
	DWORD	dwOemId; /* Obsolete field - do not use */
	struct {
		WORD wProcessorArchitecture;
		WORD wReserved;
	} DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;
    DWORD	dwPageSize;
    LPVOID	lpMinimumApplicationAddress;
    LPVOID	lpMaximumApplicationAddress;
    DWORD_PTR	dwActiveProcessorMask;
    DWORD	dwNumberOfProcessors;
    DWORD	dwProcessorType;
    DWORD	dwAllocationGranularity;
    WORD	wProcessorLevel;
    WORD	wProcessorRevision;
} SYSTEM_INFO, *LPSYSTEM_INFO;

typedef BOOL (CALLBACK *ENUMRESTYPEPROCA)(HMODULE,LPSTR,LONG_PTR);
typedef BOOL (CALLBACK *ENUMRESTYPEPROCW)(HMODULE,LPWSTR,LONG_PTR);
typedef BOOL (CALLBACK *ENUMRESNAMEPROCA)(HMODULE,LPCSTR,LPSTR,LONG_PTR);
typedef BOOL (CALLBACK *ENUMRESNAMEPROCW)(HMODULE,LPCWSTR,LPWSTR,LONG_PTR);
typedef BOOL (CALLBACK *ENUMRESLANGPROCA)(HMODULE,LPCSTR,LPCSTR,WORD,LONG_PTR);
typedef BOOL (CALLBACK *ENUMRESLANGPROCW)(HMODULE,LPCWSTR,LPCWSTR,WORD,LONG_PTR);

DECL_WINELIB_TYPE_AW(ENUMRESTYPEPROC)
DECL_WINELIB_TYPE_AW(ENUMRESNAMEPROC)
DECL_WINELIB_TYPE_AW(ENUMRESLANGPROC)

/* flags that can be passed to LoadLibraryEx */
#define DONT_RESOLVE_DLL_REFERENCES         0x00000001
#define LOAD_LIBRARY_AS_DATAFILE            0x00000002
#define LOAD_WITH_ALTERED_SEARCH_PATH       0x00000008
#define LOAD_IGNORE_CODE_AUTHZ_LEVEL        0x00000010
#define LOAD_LIBRARY_AS_IMAGE_RESOURCE      0x00000020
#define LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE  0x00000040
#define LOAD_LIBRARY_REQUIRE_SIGNED_TARGET  0x00000080
#define LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR    0x00000100
#define LOAD_LIBRARY_SEARCH_APPLICATION_DIR 0x00000200
#define LOAD_LIBRARY_SEARCH_USER_DIRS       0x00000400
#define LOAD_LIBRARY_SEARCH_SYSTEM32        0x00000800
#define LOAD_LIBRARY_SEARCH_DEFAULT_DIRS    0x00001000

#define GET_MODULE_HANDLE_EX_FLAG_PIN                 1
#define GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT  2
#define GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS        4

/* flags for SetSearchPathMode */
#define BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE  0x00001
#define BASE_SEARCH_PATH_DISABLE_SAFE_SEARCHMODE 0x10000
#define BASE_SEARCH_PATH_PERMANENT               0x08000
#define BASE_SEARCH_PATH_INVALID_FLAGS         (~0x18001)

typedef PLDT_ENTRY LPLDT_ENTRY;

typedef enum _GET_FILEEX_INFO_LEVELS {
    GetFileExInfoStandard
} GET_FILEEX_INFO_LEVELS;

typedef struct _WIN32_FILE_ATTRIBUTES_DATA {
    DWORD    dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD    nFileSizeHigh;
    DWORD    nFileSizeLow;
} WIN32_FILE_ATTRIBUTE_DATA, *LPWIN32_FILE_ATTRIBUTE_DATA;

/*
 * This one seems to be a Win32 only definition. It also is defined with
 * WINAPI instead of CALLBACK in the windows headers.
 */
typedef DWORD (CALLBACK *LPPROGRESS_ROUTINE)(LARGE_INTEGER, LARGE_INTEGER, LARGE_INTEGER,
                                           LARGE_INTEGER, DWORD, DWORD, HANDLE,
                                           HANDLE, LPVOID);

typedef DWORD (WINAPI *APPLICATION_RECOVERY_CALLBACK)(PVOID);

typedef enum _COPYFILE2_MESSAGE_TYPE
{
    COPYFILE2_CALLBACK_NONE = 0,
    COPYFILE2_CALLBACK_CHUNK_STARTED,
    COPYFILE2_CALLBACK_CHUNK_FINISHED,
    COPYFILE2_CALLBACK_STREAM_STARTED,
    COPYFILE2_CALLBACK_STREAM_FINISHED,
    COPYFILE2_CALLBACK_POLL_CONTINUE,
    COPYFILE2_CALLBACK_ERROR,
    COPYFILE2_CALLBACK_MAX,
} COPYFILE2_MESSAGE_TYPE;

typedef enum _COPYFILE2_MESSAGE_ACTION
{
    COPYFILE2_PROGRESS_CONTINUE = 0,
    COPYFILE2_PROGRESS_CANCEL,
    COPYFILE2_PROGRESS_STOP,
    COPYFILE2_PROGRESS_QUIET,
    COPYFILE2_PROGRESS_PAUSE,
} COPYFILE2_MESSAGE_ACTION;

typedef enum _COPYFILE2_COPY_PHASE
{
    COPYFILE2_PHASE_NONE = 0,
    COPYFILE2_PHASE_PREPARE_SOURCE,
    COPYFILE2_PHASE_PREPARE_DEST,
    COPYFILE2_PHASE_READ_SOURCE,
    COPYFILE2_PHASE_WRITE_DESTINATION,
    COPYFILE2_PHASE_SERVER_COPY,
    COPYFILE2_PHASE_NAMEGRAFT_COPY,
    COPYFILE2_PHASE_MAX,
} COPYFILE2_COPY_PHASE;

typedef struct COPYFILE2_MESSAGE
{
    COPYFILE2_MESSAGE_TYPE Type;
    DWORD                  dwPadding;
    union
    {
        struct
        {
            DWORD          dwStreamNumber;
            DWORD          dwReserved;
            HANDLE         hSourceFile;
            HANDLE         hDestinationFile;
            ULARGE_INTEGER uliChunkNumber;
            ULARGE_INTEGER uliChunkSize;
            ULARGE_INTEGER uliStreamSize;
            ULARGE_INTEGER uliTotalFileSize;
        } ChunkStarted;
        struct
        {
            DWORD          dwStreamNumber;
            DWORD          dwFlags;
            HANDLE         hSourceFile;
            HANDLE         hDestinationFile;
            ULARGE_INTEGER uliChunkNumber;
            ULARGE_INTEGER uliChunkSize;
            ULARGE_INTEGER uliStreamSize;
            ULARGE_INTEGER uliStreamBytesTransferred;
            ULARGE_INTEGER uliTotalFileSize;
            ULARGE_INTEGER uliTotalBytesTransferred;
        } ChunkFinished;
        struct
        {
            DWORD          dwStreamNumber;
            DWORD          dwReserved;
            HANDLE         hSourceFile;
            HANDLE         hDestinationFile;
            ULARGE_INTEGER uliStreamSize;
            ULARGE_INTEGER uliTotalFileSize;
        } StreamStarted;
        struct
        {
            DWORD          dwStreamNumber;
            DWORD          dwReserved;
            HANDLE         hSourceFile;
            HANDLE         hDestinationFile;
            ULARGE_INTEGER uliStreamSize;
            ULARGE_INTEGER uliStreamBytesTransferred;
            ULARGE_INTEGER uliTotalFileSize;
            ULARGE_INTEGER uliTotalBytesTransferred;
        } StreamFinished;
        struct
        {
            DWORD dwReserved;
        } PollContinue;
        struct
        {
            COPYFILE2_COPY_PHASE CopyPhase;
            DWORD                dwStreamNumber;
            HRESULT              hrFailure;
            DWORD                dwReserved;
            ULARGE_INTEGER       uliChunkNumber;
            ULARGE_INTEGER       uliStreamSize;
            ULARGE_INTEGER       uliStreamBytesTransferred;
            ULARGE_INTEGER       uliTotalFileSize;
            ULARGE_INTEGER       uliTotalBytesTransferred;
        } Error;
    } Info;
} COPYFILE2_MESSAGE;

typedef COPYFILE2_MESSAGE_ACTION (CALLBACK *PCOPYFILE2_PROGRESS_ROUTINE)(const COPYFILE2_MESSAGE*,PVOID);

typedef struct COPYFILE2_EXTENDED_PARAMETERS
{
    DWORD                        dwSize;
    DWORD                        dwCopyFlags;
    BOOL                        *pfCancel;
    PCOPYFILE2_PROGRESS_ROUTINE  pProgressRoutine;
    PVOID                        pvCallbackContext;
} COPYFILE2_EXTENDED_PARAMETERS;

#define CREATE_EVENT_MANUAL_RESET 1
#define CREATE_EVENT_INITIAL_SET  2

#define CREATE_MUTEX_INITIAL_OWNER 1

#define CREATE_WAITABLE_TIMER_MANUAL_RESET 1

#define WAIT_FAILED		0xffffffff
#define WAIT_OBJECT_0		0
#define WAIT_ABANDONED		STATUS_ABANDONED_WAIT_0
#define WAIT_ABANDONED_0	STATUS_ABANDONED_WAIT_0
#define WAIT_IO_COMPLETION	STATUS_USER_APC
#define STILL_ACTIVE            STATUS_PENDING

#define FILE_BEGIN              0
#define FILE_CURRENT            1
#define FILE_END                2

#define FILE_MAP_COPY                   0x00000001
#define FILE_MAP_WRITE                  0x00000002
#define FILE_MAP_READ                   0x00000004
#define FILE_MAP_ALL_ACCESS             0x000f001f
#define FILE_MAP_EXECUTE                0x00000020

#define MOVEFILE_REPLACE_EXISTING       0x00000001
#define MOVEFILE_COPY_ALLOWED           0x00000002
#define MOVEFILE_DELAY_UNTIL_REBOOT     0x00000004
#define MOVEFILE_WRITE_THROUGH          0x00000008

#define REPLACEFILE_WRITE_THROUGH       0x00000001
#define REPLACEFILE_IGNORE_MERGE_ERRORS 0x00000002

#define FS_CASE_SENSITIVE               FILE_CASE_SENSITIVE_SEARCH
#define FS_CASE_IS_PRESERVED            FILE_CASE_PRESERVED_NAMES
#define FS_UNICODE_STORED_ON_DISK       FILE_UNICODE_ON_DISK
#define FS_PERSISTENT_ACLS              FILE_PERSISTENT_ACLS
#define FS_VOL_IS_COMPRESSED            FILE_VOLUME_IS_COMPRESSED
#define FS_FILE_COMPRESSION             FILE_FILE_COMPRESSION

#define MUTEX_MODIFY_STATE              MUTANT_QUERY_STATE
#define MUTEX_ALL_ACCESS                MUTANT_ALL_ACCESS

#define EXCEPTION_ACCESS_VIOLATION          STATUS_ACCESS_VIOLATION
#define EXCEPTION_DATATYPE_MISALIGNMENT     STATUS_DATATYPE_MISALIGNMENT
#define EXCEPTION_BREAKPOINT                STATUS_BREAKPOINT
#define EXCEPTION_SINGLE_STEP               STATUS_SINGLE_STEP
#define EXCEPTION_ARRAY_BOUNDS_EXCEEDED     STATUS_ARRAY_BOUNDS_EXCEEDED
#define EXCEPTION_FLT_DENORMAL_OPERAND      STATUS_FLOAT_DENORMAL_OPERAND
#define EXCEPTION_FLT_DIVIDE_BY_ZERO        STATUS_FLOAT_DIVIDE_BY_ZERO
#define EXCEPTION_FLT_INEXACT_RESULT        STATUS_FLOAT_INEXACT_RESULT
#define EXCEPTION_FLT_INVALID_OPERATION     STATUS_FLOAT_INVALID_OPERATION
#define EXCEPTION_FLT_OVERFLOW              STATUS_FLOAT_OVERFLOW
#define EXCEPTION_FLT_STACK_CHECK           STATUS_FLOAT_STACK_CHECK
#define EXCEPTION_FLT_UNDERFLOW             STATUS_FLOAT_UNDERFLOW
#define EXCEPTION_INT_DIVIDE_BY_ZERO        STATUS_INTEGER_DIVIDE_BY_ZERO
#define EXCEPTION_INT_OVERFLOW              STATUS_INTEGER_OVERFLOW
#define EXCEPTION_PRIV_INSTRUCTION          STATUS_PRIVILEGED_INSTRUCTION
#define EXCEPTION_IN_PAGE_ERROR             STATUS_IN_PAGE_ERROR
#define EXCEPTION_ILLEGAL_INSTRUCTION       STATUS_ILLEGAL_INSTRUCTION
#define EXCEPTION_NONCONTINUABLE_EXCEPTION  STATUS_NONCONTINUABLE_EXCEPTION
#define EXCEPTION_STACK_OVERFLOW            STATUS_STACK_OVERFLOW
#define EXCEPTION_INVALID_DISPOSITION       STATUS_INVALID_DISPOSITION
#define EXCEPTION_GUARD_PAGE                STATUS_GUARD_PAGE_VIOLATION
#define EXCEPTION_INVALID_HANDLE            STATUS_INVALID_HANDLE
#define CONTROL_C_EXIT                      STATUS_CONTROL_C_EXIT

#define HANDLE_FLAG_INHERIT             0x00000001
#define HANDLE_FLAG_PROTECT_FROM_CLOSE  0x00000002

#define HINSTANCE_ERROR 32

#define THREAD_PRIORITY_LOWEST          THREAD_BASE_PRIORITY_MIN
#define THREAD_PRIORITY_BELOW_NORMAL    (THREAD_PRIORITY_LOWEST+1)
#define THREAD_PRIORITY_NORMAL          0
#define THREAD_PRIORITY_HIGHEST         THREAD_BASE_PRIORITY_MAX
#define THREAD_PRIORITY_ABOVE_NORMAL    (THREAD_PRIORITY_HIGHEST-1)
#define THREAD_PRIORITY_ERROR_RETURN    (0x7fffffff)
#define THREAD_PRIORITY_TIME_CRITICAL   THREAD_BASE_PRIORITY_LOWRT
#define THREAD_PRIORITY_IDLE            THREAD_BASE_PRIORITY_IDLE

/* flags to FormatMessage */
#define	FORMAT_MESSAGE_ALLOCATE_BUFFER	0x00000100
#define	FORMAT_MESSAGE_IGNORE_INSERTS	0x00000200
#define	FORMAT_MESSAGE_FROM_STRING	0x00000400
#define	FORMAT_MESSAGE_FROM_HMODULE	0x00000800
#define	FORMAT_MESSAGE_FROM_SYSTEM	0x00001000
#define	FORMAT_MESSAGE_ARGUMENT_ARRAY	0x00002000
#define	FORMAT_MESSAGE_MAX_WIDTH_MASK	0x000000FF

/* flags to ACTCTX[AW] */
#define ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID  (0x00000001)
#define ACTCTX_FLAG_LANGID_VALID                  (0x00000002)
#define ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID      (0x00000004)
#define ACTCTX_FLAG_RESOURCE_NAME_VALID           (0x00000008)
#define ACTCTX_FLAG_SET_PROCESS_DEFAULT           (0x00000010)
#define ACTCTX_FLAG_APPLICATION_NAME_VALID        (0x00000020)
#define ACTCTX_FLAG_SOURCE_IS_ASSEMBLYREF         (0x00000040)
#define ACTCTX_FLAG_HMODULE_VALID                 (0x00000080)

/* flags to DeactiveActCtx */
#define DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION  (0x00000001)

/* flags to FindActCtxSection{Guid,String[AW]} */
#define FIND_ACTCTX_SECTION_KEY_RETURN_HACTCTX            (0x00000001)
#define FIND_ACTCTX_SECTION_KEY_RETURN_FLAGS              (0x00000002)
#define FIND_ACTCTX_SECTION_KEY_RETURN_ASSEMBLY_METADATA  (0x00000004)

/* flags to QueryActCtxW */
#define QUERY_ACTCTX_FLAG_USE_ACTIVE_ACTCTX  (0x00000004)
#define QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE  (0x00000008)
#define QUERY_ACTCTX_FLAG_ACTCTX_IS_ADDRESS  (0x00000010)
#define QUERY_ACTCTX_FLAG_NO_ADDREF          (0x80000000)

typedef struct tagACTCTXA {
    ULONG   cbSize;
    DWORD   dwFlags;
    LPCSTR  lpSource;
    USHORT  wProcessorArchitecture;
    LANGID  wLangId;
    LPCSTR  lpAssemblyDirectory;
    LPCSTR  lpResourceName;
    LPCSTR  lpApplicationName;
    HMODULE hModule;
} ACTCTXA, *PACTCTXA;

typedef struct tagACTCTXW {
    ULONG   cbSize;
    DWORD   dwFlags;
    LPCWSTR lpSource;
    USHORT  wProcessorArchitecture;
    LANGID  wLangId;
    LPCWSTR lpAssemblyDirectory;
    LPCWSTR lpResourceName;
    LPCWSTR lpApplicationName;
    HMODULE hModule;
} ACTCTXW, *PACTCTXW;

DECL_WINELIB_TYPE_AW(ACTCTX)
DECL_WINELIB_TYPE_AW(PACTCTX)

typedef const ACTCTXA *PCACTCTXA;
typedef const ACTCTXW *PCACTCTXW;
DECL_WINELIB_TYPE_AW(PCACTCTX)

typedef struct tagACTCTX_SECTION_KEYED_DATA_2600 {
    ULONG  cbSize;
    ULONG  ulDataFormatVersion;
    PVOID  lpData;
    ULONG  ulLength;
    PVOID  lpSectionGlobalData;
    ULONG  ulSectionGlobalDataLength;
    PVOID  lpSectionBase;
    ULONG  ulSectionTotalLength;
    HANDLE hActCtx;
    ULONG  ulAssemblyRosterIndex;
} ACTCTX_SECTION_KEYED_DATA_2600, *PACTCTX_SECTION_KEYED_DATA_2600;
typedef const ACTCTX_SECTION_KEYED_DATA_2600 *PCACTCTX_SECTION_KEYED_DATA_2600;

typedef struct tagACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA {
    PVOID lpInformation;
    PVOID lpSectionBase;
    ULONG ulSectionLength;
    PVOID lpSectionGlobalDataBase;
    ULONG ulSectionGlobalDataLength;
} ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA, *PACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA;
typedef const ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA *PCACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA;

typedef struct tagACTCTX_SECTION_KEYED_DATA {
    ULONG  cbSize;
    ULONG  ulDataFormatVersion;
    PVOID  lpData;
    ULONG  ulLength;
    PVOID  lpSectionGlobalData;
    ULONG  ulSectionGlobalDataLength;
    PVOID  lpSectionBase;
    ULONG  ulSectionTotalLength;
    HANDLE hActCtx;
    ULONG  ulAssemblyRosterIndex;

    /* Non 2600 extra fields */
    ULONG ulFlags;
    ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA AssemblyMetadata;
} ACTCTX_SECTION_KEYED_DATA, *PACTCTX_SECTION_KEYED_DATA;
typedef const ACTCTX_SECTION_KEYED_DATA *PCACTCTX_SECTION_KEYED_DATA;

typedef struct _ACTIVATION_CONTEXT_BASIC_INFORMATION {
    HANDLE hActCtx;
    DWORD  dwFlags;
} ACTIVATION_CONTEXT_BASIC_INFORMATION, *PACTIVATION_CONTEXT_BASIC_INFORMATION;

typedef BOOL (WINAPI *PQUERYACTCTXW_FUNC)(DWORD,HANDLE,PVOID,ULONG,PVOID,SIZE_T,SIZE_T *);

typedef struct tagCOMSTAT
{
    DWORD fCtsHold : 1;
    DWORD fDsrHold : 1;
    DWORD fRlsdHold : 1;
    DWORD fXoffHold : 1;
    DWORD fXoffSent : 1;
    DWORD fEof : 1;
    DWORD fTxim : 1;
    DWORD fReserved : 25;
    DWORD cbInQue;
    DWORD cbOutQue;
} COMSTAT, *LPCOMSTAT;

typedef struct tagDCB
{
    DWORD DCBlength;
    DWORD BaudRate;
    unsigned fBinary               :1;
    unsigned fParity               :1;
    unsigned fOutxCtsFlow          :1;
    unsigned fOutxDsrFlow          :1;
    unsigned fDtrControl           :2;
    unsigned fDsrSensitivity       :1;
    unsigned fTXContinueOnXoff     :1;
    unsigned fOutX                 :1;
    unsigned fInX                  :1;
    unsigned fErrorChar            :1;
    unsigned fNull                 :1;
    unsigned fRtsControl           :2;
    unsigned fAbortOnError         :1;
    unsigned fDummy2               :17;
    WORD wReserved;
    WORD XonLim;
    WORD XoffLim;
    BYTE ByteSize;
    BYTE Parity;
    BYTE StopBits;
    char XonChar;
    char XoffChar;
    char ErrorChar;
    char EofChar;
    char EvtChar;
    WORD wReserved1;
} DCB, *LPDCB;

typedef struct tagCOMMCONFIG {
	DWORD dwSize;
	WORD  wVersion;
	WORD  wReserved;
	DCB   dcb;
	DWORD dwProviderSubType;
	DWORD dwProviderOffset;
	DWORD dwProviderSize;
	DWORD wcProviderData[1];
} COMMCONFIG, *LPCOMMCONFIG;

typedef struct tagCOMMPROP {
	WORD  wPacketLength;
	WORD  wPacketVersion;
	DWORD dwServiceMask;
	DWORD dwReserved1;
	DWORD dwMaxTxQueue;
	DWORD dwMaxRxQueue;
	DWORD dwMaxBaud;
	DWORD dwProvSubType;
	DWORD dwProvCapabilities;
	DWORD dwSettableParams;
	DWORD dwSettableBaud;
	WORD  wSettableData;
	WORD  wSettableStopParity;
	DWORD dwCurrentTxQueue;
	DWORD dwCurrentRxQueue;
	DWORD dwProvSpec1;
	DWORD dwProvSpec2;
	WCHAR wcProvChar[1];
} COMMPROP, *LPCOMMPROP;

#define SP_SERIALCOMM ((DWORD)1)

#define BAUD_075     ((DWORD)0x01)
#define BAUD_110     ((DWORD)0x02)
#define BAUD_134_5   ((DWORD)0x04)
#define BAUD_150     ((DWORD)0x08)
#define BAUD_300     ((DWORD)0x10)
#define BAUD_600     ((DWORD)0x20)
#define BAUD_1200    ((DWORD)0x40)
#define BAUD_1800    ((DWORD)0x80)
#define BAUD_2400    ((DWORD)0x100)
#define BAUD_4800    ((DWORD)0x200)
#define BAUD_7200    ((DWORD)0x400)
#define BAUD_9600    ((DWORD)0x800)
#define BAUD_14400   ((DWORD)0x1000)
#define BAUD_19200   ((DWORD)0x2000)
#define BAUD_38400   ((DWORD)0x4000)
#define BAUD_56K     ((DWORD)0x8000)
#define BAUD_57600   ((DWORD)0x40000)
#define BAUD_115200  ((DWORD)0x20000)
#define BAUD_128K    ((DWORD)0x10000)
#define BAUD_USER    ((DWORD)0x10000000)

#define PST_FAX            ((DWORD)0x21)
#define PST_LAT            ((DWORD)0x101)
#define PST_MODEM          ((DWORD)0x06)
#define PST_NETWORK_BRIDGE ((DWORD)0x100)
#define PST_PARALLELPORT   ((DWORD)0x02)
#define PST_RS232          ((DWORD)0x01)
#define PST_RS442          ((DWORD)0x03)
#define PST_RS423          ((DWORD)0x04)
#define PST_RS449          ((DWORD)0x06)
#define PST_SCANNER        ((DWORD)0x22)
#define PST_TCPIP_TELNET   ((DWORD)0x102)
#define PST_UNSPECIFIED    ((DWORD)0x00)
#define PST_X25            ((DWORD)0x103)

#define PCF_16BITMODE     ((DWORD)0x200)
#define PCF_DTRDSR        ((DWORD)0x01)
#define PCF_INTTIMEOUTS   ((DWORD)0x80)
#define PCF_PARITY_CHECK  ((DWORD)0x08)
#define PCF_RLSD          ((DWORD)0x04)
#define PCF_RTSCTS        ((DWORD)0x02)
#define PCF_SETXCHAR      ((DWORD)0x20)
#define PCF_SPECIALCHARS  ((DWORD)0x100)
#define PCF_TOTALTIMEOUTS ((DWORD)0x40)
#define PCF_XONXOFF       ((DWORD)0x10)

#define SP_BAUD         ((DWORD)0x02)
#define SP_DATABITS     ((DWORD)0x04)
#define SP_HANDSHAKING  ((DWORD)0x10)
#define SP_PARITY       ((DWORD)0x01)
#define SP_PARITY_CHECK ((DWORD)0x20)
#define SP_RLSD         ((DWORD)0x40)
#define SP_STOPBITS     ((DWORD)0x08)

#define DATABITS_5   ((DWORD)0x01)
#define DATABITS_6   ((DWORD)0x02)
#define DATABITS_7   ((DWORD)0x04)
#define DATABITS_8   ((DWORD)0x08)
#define DATABITS_16  ((DWORD)0x10)
#define DATABITS_16X ((DWORD)0x20)

#define STOPBITS_10 ((DWORD)1)
#define STOPBITS_15 ((DWORD)2)
#define STOPBITS_20 ((DWORD)4)

#undef PARITY_NONE  /* defined on Android */
#define PARITY_NONE  ((DWORD)0x100)
#define PARITY_ODD   ((DWORD)0x200)
#define PARITY_EVEN  ((DWORD)0x400)
#define PARITY_MARK  ((DWORD)0x800)
#define PARITY_SPACE ((DWORD)0x1000)

typedef struct tagCOMMTIMEOUTS {
	DWORD	ReadIntervalTimeout;
	DWORD	ReadTotalTimeoutMultiplier;
	DWORD	ReadTotalTimeoutConstant;
	DWORD	WriteTotalTimeoutMultiplier;
	DWORD	WriteTotalTimeoutConstant;
} COMMTIMEOUTS,*LPCOMMTIMEOUTS;

#define GET_TAPE_MEDIA_INFORMATION 0
#define GET_TAPE_DRIVE_INFORMATION 1
#define SET_TAPE_MEDIA_INFORMATION 0
#define SET_TAPE_DRIVE_INFORMATION 1

#define PROCESS_NAME_NATIVE        1

typedef void (CALLBACK *PAPCFUNC)(ULONG_PTR);
typedef void (CALLBACK *PTIMERAPCROUTINE)(LPVOID,DWORD,DWORD);

typedef enum _COMPUTER_NAME_FORMAT
{
	ComputerNameNetBIOS,
	ComputerNameDnsHostname,
	ComputerNameDnsDomain,
	ComputerNameDnsFullyQualified,
	ComputerNamePhysicalNetBIOS,
	ComputerNamePhysicalDnsHostname,
	ComputerNamePhysicalDnsDomain,
	ComputerNamePhysicalDnsFullyQualified,
	ComputerNameMax
} COMPUTER_NAME_FORMAT;

#define HW_PROFILE_GUIDLEN	39
#define MAX_PROFILE_LEN		80

#define DOCKINFO_UNDOCKED	0x1
#define DOCKINFO_DOCKED		0x2
#define DOCKINFO_USER_SUPPLIED	0x4
#define DOCKINFO_USER_UNDOCKED	(DOCKINFO_USER_SUPPLIED | DOCKINFO_UNDOCKED)
#define DOCKINFO_USER_DOCKED	(DOCKINFO_USER_SUPPLIED | DOCKINFO_DOCKED)

typedef struct tagHW_PROFILE_INFOA {
    DWORD dwDockInfo;
    CHAR  szHwProfileGuid[HW_PROFILE_GUIDLEN];
    CHAR  szHwProfileName[MAX_PROFILE_LEN];
} HW_PROFILE_INFOA, *LPHW_PROFILE_INFOA;

typedef struct tagHW_PROFILE_INFOW {
    DWORD dwDockInfo;
    WCHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    WCHAR szHwProfileName[MAX_PROFILE_LEN];
} HW_PROFILE_INFOW, *LPHW_PROFILE_INFOW;

DECL_WINELIB_TYPE_AW(HW_PROFILE_INFO)
DECL_WINELIB_TYPE_AW(LPHW_PROFILE_INFO)

typedef enum _DEP_SYSTEM_POLICY_TYPE {
    AlwaysOff = 0,
    AlwaysOn = 1,
    OptIn = 2,
    OptOut = 3
} DEP_SYSTEM_POLICY_TYPE;

#define PROCESS_DEP_ENABLE 1
#define PROCESS_DEP_DISABLE_ATL_THUNK_EMULATION 2

/* Event Logging */

#define EVENTLOG_FULL_INFO          0

typedef struct _EVENTLOG_FULL_INFORMATION {
    DWORD dwFull;
} EVENTLOG_FULL_INFORMATION, *LPEVENTLOG_FULL_INFORMATION;


/* Stream data structures and defines */
/*the types of backup data -- WIN32_STREAM_ID.dwStreamId below*/
#define BACKUP_INVALID        0
#define BACKUP_DATA           1
#define BACKUP_EA_DATA        2
#define BACKUP_SECURITY_DATA  3
#define BACKUP_ALTERNATE_DATA 4
#define BACKUP_LINK           5
#define BACKUP_PROPERTY_DATA  6
#define BACKUP_OBJECT_ID      7
#define BACKUP_REPARSE_DATA   8
#define BACKUP_SPARSE_BLOCK   9

/*flags for WIN32_STREAM_ID.dwStreamAttributes below*/
#define STREAM_NORMAL_ATTRIBUTE    0
#define STREAM_MODIFIED_WHEN_READ  1
#define STREAM_CONTAINS_SECURITY   2
#define STREAM_CONTAINS_PROPERTIES 4
#define STREAM_SPARSE_ATTRIBUTE    8

#include <pshpack8.h>
typedef struct _WIN32_STREAM_ID {
	DWORD   dwStreamId;
	DWORD   dwStreamAttributes;
	LARGE_INTEGER DECLSPEC_ALIGN(8) Size;
	DWORD   dwStreamNameSize;
	WCHAR   cStreamName[ANYSIZE_ARRAY];
} WIN32_STREAM_ID, *LPWIN32_STREAM_ID;
#include <poppack.h>


/* GetBinaryType return values.
 */

#define SCS_32BIT_BINARY    0
#define SCS_DOS_BINARY      1
#define SCS_WOW_BINARY      2
#define SCS_PIF_BINARY      3
#define SCS_POSIX_BINARY    4
#define SCS_OS216_BINARY    5
#define SCS_64BIT_BINARY    6

/* flags for DefineDosDevice */
#define DDD_RAW_TARGET_PATH         0x00000001
#define DDD_REMOVE_DEFINITION       0x00000002
#define DDD_EXACT_MATCH_ON_REMOVE   0x00000004
#define DDD_NO_BROADCAST_SYSTEM     0x00000008
#define DDD_LUID_BROADCAST_DRIVE    0x00000010

#define LOGON_WITH_PROFILE          0x00000001
#define LOGON_NETCREDENTIALS_ONLY   0x00000002
#define LOGON_ZERO_PASSWORD_BUFFER  0x80000000

/* one-time initialisation API */
typedef RTL_RUN_ONCE  INIT_ONCE;
typedef PRTL_RUN_ONCE PINIT_ONCE;
typedef PRTL_RUN_ONCE LPINIT_ONCE;
#define INIT_ONCE_STATIC_INIT       RTL_RUN_ONCE_INIT
#define INIT_ONCE_CHECK_ONLY        RTL_RUN_ONCE_CHECK_ONLY
#define INIT_ONCE_ASYNC             RTL_RUN_ONCE_ASYNC
#define INIT_ONCE_INIT_FAILED       RTL_RUN_ONCE_INIT_FAILED
/* initialization callback prototype */
typedef BOOL (WINAPI *PINIT_ONCE_FN)(PINIT_ONCE,PVOID,PVOID*);

typedef struct _REASON_CONTEXT
{
    ULONG Version;
    DWORD Flags;
    union
    {
        struct
        {
            HMODULE LocalizedReasonModule;
            ULONG LocalizedReasonId;
            ULONG ReasonStringCount;
            LPWSTR *ReasonStrings;
        } Detailed;
        LPWSTR SimpleReasonString;
    } Reason;
} REASON_CONTEXT, *PREASON_CONTEXT;

#define RESOURCE_ENUM_LN          0x0001
#define RESOURCE_ENUM_MUI         0x0002
#define RESOURCE_ENUM_MUI_SYSTEM  0x0004
#define RESOURCE_ENUM_VALIDATE    0x0008

typedef struct _PROC_THREAD_ATTRIBUTE_LIST
*PPROC_THREAD_ATTRIBUTE_LIST, *LPPROC_THREAD_ATTRIBUTE_LIST;

#define PROC_THREAD_ATTRIBUTE_NUMBER   0x0000ffff
#define PROC_THREAD_ATTRIBUTE_THREAD   0x00010000
#define PROC_THREAD_ATTRIBUTE_INPUT    0x00020000
#define PROC_THREAD_ATTRIBUTE_ADDITIVE 0x00040000

typedef enum _PROC_THREAD_ATTRIBUTE_NUM
{
    ProcThreadAttributeParentProcess = 0,
    ProcThreadAttributeHandleList = 2,
    ProcThreadAttributeGroupAffinity = 3,
    ProcThreadAttributeIdealProcessor = 5,
    ProcThreadAttributeUmsThread = 6,
    ProcThreadAttributeMitigationPolicy = 7,
    ProcThreadAttributeSecurityCapabilities = 9,
    ProcThreadAttributeProtectionLevel = 11,
    ProcThreadAttributeJobList = 13,
    ProcThreadAttributeChildProcessPolicy = 14,
    ProcThreadAttributeAllApplicationPackagesPolicy = 15,
    ProcThreadAttributeWin32kFilter = 16,
    ProcThreadAttributeSafeOpenPromptOriginClaim = 17,
} PROC_THREAD_ATTRIBUTE_NUM;

#define PROC_THREAD_ATTRIBUTE_PARENT_PROCESS (ProcThreadAttributeParentProcess | PROC_THREAD_ATTRIBUTE_INPUT)
#define PROC_THREAD_ATTRIBUTE_HANDLE_LIST (ProcThreadAttributeHandleList | PROC_THREAD_ATTRIBUTE_INPUT)
#define PROC_THREAD_ATTRIBUTE_GROUP_AFFINITY (ProcThreadAttributeGroupAffinity | PROC_THREAD_ATTRIBUTE_THREAD | PROC_THREAD_ATTRIBUTE_INPUT)
#define PROC_THREAD_ATTRIBUTE_IDEAL_PROCESSOR (ProcThreadAttributeIdealProcessor | PROC_THREAD_ATTRIBUTE_THREAD | PROC_THREAD_ATTRIBUTE_INPUT)
#define PROC_THREAD_ATTRIBUTE_UMS_THREAD (ProcThreadAttributeUmsThread | PROC_THREAD_ATTRIBUTE_THREAD | PROC_THREAD_ATTRIBUTE_INPUT)
#define PROC_THREAD_ATTRIBUTE_MIGITATION_POLICY (ProcThreadAttributeMitigationPolicy | PROC_THREAD_ATTRIBUTE_INPUT)
#define PROC_THREAD_ATTRIBUTE_SECURITY_CAPABILITIES (ProcThreadAttributeSecurityCapabilities | PROC_THREAD_ATTRIBUTE_INPUT)
#define PROC_THREAD_ATTRIBUTE_PROTECTION_LEVEL (ProcThreadAttributeProtectionLevel | PROC_THREAD_ATTRIBUTE_INPUT)
#define PROC_THREAD_ATTRIBUTE_JOB_LIST (ProcThreadAttributeJobList | PROC_THREAD_ATTRIBUTE_INPUT)
#define PROC_THREAD_ATTRIBUTE_CHILD_PROCESS_POLICY (ProcThreadAttributeChildProcessPolicy | PROC_THREAD_ATTRIBUTE_INPUT)
#define PROC_THREAD_ATTRIBUTE_ALL_APPLICATION_PACKAGES_POLICY (ProcThreadAttributeAllApplicationPackagesPolicy | PROC_THREAD_ATTRIBUTE_INPUT)
#define PROC_THREAD_ATTRIBUTE_WIN32K_FILTER (ProcThreadAttributeWin32kFilter | PROC_THREAD_ATTRIBUTE_INPUT)

#define SYMBOLIC_LINK_FLAG_DIRECTORY (0x1)
#define VALID_SYMBOLIC_LINK_FLAGS SYMBOLIC_LINK_FLAG_DIRECTORY

WINBASEAPI BOOL        WINAPI ActivateActCtx(HANDLE,ULONG_PTR *);
WINADVAPI  BOOL        WINAPI AddAccessAllowedAce(PACL,DWORD,DWORD,PSID);
WINADVAPI  BOOL        WINAPI AddAccessAllowedAceEx(PACL,DWORD,DWORD,DWORD,PSID);
WINADVAPI  BOOL        WINAPI AddAccessDeniedAce(PACL,DWORD,DWORD,PSID);
WINADVAPI  BOOL        WINAPI AddAccessDeniedAceEx(PACL,DWORD,DWORD,DWORD,PSID);
WINADVAPI  BOOL        WINAPI AddAce(PACL,DWORD,DWORD,LPVOID,DWORD);
WINBASEAPI ATOM        WINAPI AddAtomA(LPCSTR);
WINBASEAPI ATOM        WINAPI AddAtomW(LPCWSTR);
#define                       AddAtom WINELIB_NAME_AW(AddAtom)
WINADVAPI  BOOL        WINAPI AddAuditAccessAce(PACL,DWORD,DWORD,PSID,BOOL,BOOL);
WINADVAPI  BOOL        WINAPI AddAuditAccessAceEx(PACL,DWORD,DWORD,DWORD,PSID,BOOL,BOOL);
WINADVAPI  BOOL        WINAPI AddMandatoryAce(PACL,DWORD,DWORD,DWORD,PSID);
WINBASEAPI VOID        WINAPI AddRefActCtx(HANDLE);
WINBASEAPI PVOID       WINAPI AddVectoredExceptionHandler(ULONG,PVECTORED_EXCEPTION_HANDLER);
WINADVAPI  BOOL        WINAPI AdjustTokenGroups(HANDLE,BOOL,PTOKEN_GROUPS,DWORD,PTOKEN_GROUPS,PDWORD);
WINADVAPI  BOOL        WINAPI AccessCheck(PSECURITY_DESCRIPTOR,HANDLE,DWORD,PGENERIC_MAPPING,PPRIVILEGE_SET,LPDWORD,LPDWORD,LPBOOL);
WINADVAPI  BOOL        WINAPI AccessCheckAndAuditAlarmA(LPCSTR,LPVOID,LPSTR,LPSTR,PSECURITY_DESCRIPTOR,DWORD,PGENERIC_MAPPING,BOOL,LPDWORD,LPBOOL,LPBOOL);
WINADVAPI  BOOL        WINAPI AccessCheckAndAuditAlarmW(LPCWSTR,LPVOID,LPWSTR,LPWSTR,PSECURITY_DESCRIPTOR,DWORD,PGENERIC_MAPPING,BOOL,LPDWORD,LPBOOL,LPBOOL);
#define                       AccessCheckAndAuditAlarm WINELIB_NAME_AW(AccessCheckAndAuditAlarm)
WINADVAPI  BOOL        WINAPI AccessCheckByType(PSECURITY_DESCRIPTOR,PSID,HANDLE,DWORD,POBJECT_TYPE_LIST,DWORD,PGENERIC_MAPPING,PPRIVILEGE_SET,LPDWORD,LPDWORD,LPBOOL);
WINBASEAPI VOID        WINAPI AcquireSRWLockExclusive(PSRWLOCK);
WINBASEAPI VOID        WINAPI AcquireSRWLockShared(PSRWLOCK);
WINADVAPI  BOOL        WINAPI AdjustTokenPrivileges(HANDLE,BOOL,PTOKEN_PRIVILEGES,DWORD,PTOKEN_PRIVILEGES,PDWORD);
WINADVAPI  BOOL        WINAPI AllocateAndInitializeSid(PSID_IDENTIFIER_AUTHORITY,BYTE,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,PSID *);
WINADVAPI  BOOL        WINAPI AllocateLocallyUniqueId(PLUID);
WINADVAPI  BOOL        WINAPI AreAllAccessesGranted(DWORD,DWORD);
WINADVAPI  BOOL        WINAPI AreAnyAccessesGranted(DWORD,DWORD);
WINBASEAPI BOOL        WINAPI AreFileApisANSI(void);
WINBASEAPI BOOL        WINAPI AssignProcessToJobObject(HANDLE,HANDLE);
WINADVAPI  BOOL        WINAPI BackupEventLogA(HANDLE,LPCSTR);
WINADVAPI  BOOL        WINAPI BackupEventLogW(HANDLE,LPCWSTR);
#define                       BackupEventLog WINELIB_NAME_AW(BackupEventLog)
WINBASEAPI BOOL        WINAPI BackupRead(HANDLE,LPBYTE,DWORD,LPDWORD,BOOL,BOOL,LPVOID*);
WINBASEAPI BOOL        WINAPI BackupSeek(HANDLE,DWORD,DWORD,LPDWORD,LPDWORD,LPVOID*);
WINBASEAPI BOOL        WINAPI BackupWrite(HANDLE,LPBYTE,DWORD,LPDWORD,BOOL,BOOL,LPVOID*);
WINBASEAPI BOOL        WINAPI Beep(DWORD,DWORD);
WINBASEAPI HANDLE      WINAPI BeginUpdateResourceA(LPCSTR,BOOL);
WINBASEAPI HANDLE      WINAPI BeginUpdateResourceW(LPCWSTR,BOOL);
#define                       BeginUpdateResource WINELIB_NAME_AW(BeginUpdateResource)
WINBASEAPI BOOL        WINAPI BindIoCompletionCallback(HANDLE,LPOVERLAPPED_COMPLETION_ROUTINE,ULONG);
WINBASEAPI BOOL        WINAPI BuildCommDCBA(LPCSTR,LPDCB);
WINBASEAPI BOOL        WINAPI BuildCommDCBW(LPCWSTR,LPDCB);
#define                       BuildCommDCB WINELIB_NAME_AW(BuildCommDCB)
WINBASEAPI BOOL        WINAPI BuildCommDCBAndTimeoutsA(LPCSTR,LPDCB,LPCOMMTIMEOUTS);
WINBASEAPI BOOL        WINAPI BuildCommDCBAndTimeoutsW(LPCWSTR,LPDCB,LPCOMMTIMEOUTS);
#define                       BuildCommDCBAndTimeouts WINELIB_NAME_AW(BuildCommDCBAndTimeouts)
WINBASEAPI BOOL        WINAPI CallNamedPipeA(LPCSTR,LPVOID,DWORD,LPVOID,DWORD,LPDWORD,DWORD);
WINBASEAPI BOOL        WINAPI CallNamedPipeW(LPCWSTR,LPVOID,DWORD,LPVOID,DWORD,LPDWORD,DWORD);
#define                       CallNamedPipe WINELIB_NAME_AW(CallNamedPipe)
WINBASEAPI BOOL        WINAPI CancelIo(HANDLE);
WINBASEAPI BOOL        WINAPI CancelIoEx(HANDLE,LPOVERLAPPED);
WINBASEAPI BOOL        WINAPI CancelSynchronousIo(HANDLE);
WINBASEAPI BOOL        WINAPI CancelTimerQueueTimer(HANDLE,HANDLE);
WINBASEAPI BOOL        WINAPI CancelWaitableTimer(HANDLE);
WINBASEAPI BOOL        WINAPI CheckNameLegalDOS8Dot3A(const char*,char*,DWORD,BOOL*,BOOL*);
WINBASEAPI BOOL        WINAPI CheckNameLegalDOS8Dot3W(const WCHAR*, char*,DWORD,BOOL*,BOOL*);
WINBASEAPI BOOL        WINAPI CheckRemoteDebuggerPresent(HANDLE,BOOL*);
WINBASEAPI BOOL        WINAPI ChangeTimerQueueTimer(HANDLE,HANDLE,ULONG,ULONG);
WINADVAPI  BOOL        WINAPI CheckTokenMembership(HANDLE,PSID,PBOOL);
WINBASEAPI BOOL        WINAPI ClearCommBreak(HANDLE);
WINBASEAPI BOOL        WINAPI ClearCommError(HANDLE,LPDWORD,LPCOMSTAT);
WINADVAPI  VOID        WINAPI CloseEncryptedFileRaw(PVOID);
WINADVAPI  BOOL        WINAPI ClearEventLogA(HANDLE,LPCSTR);
WINADVAPI  BOOL        WINAPI ClearEventLogW(HANDLE,LPCWSTR);
#define                       ClearEventLog WINELIB_NAME_AW(ClearEventLog)
WINADVAPI  BOOL        WINAPI CloseEventLog(HANDLE);
WINBASEAPI BOOL        WINAPI CloseHandle(HANDLE);
WINBASEAPI VOID        WINAPI CloseThreadpool(PTP_POOL);
WINBASEAPI VOID        WINAPI CloseThreadpoolCleanupGroup(PTP_CLEANUP_GROUP);
WINBASEAPI VOID        WINAPI CloseThreadpoolCleanupGroupMembers(PTP_CLEANUP_GROUP,BOOL,PVOID);
WINBASEAPI VOID        WINAPI CloseThreadpoolTimer(PTP_TIMER);
WINBASEAPI VOID        WINAPI CloseThreadpoolWait(PTP_WAIT);
WINBASEAPI VOID        WINAPI CloseThreadpoolWork(PTP_WORK);
WINBASEAPI BOOL        WINAPI CommConfigDialogA(LPCSTR,HWND,LPCOMMCONFIG);
WINBASEAPI BOOL        WINAPI CommConfigDialogW(LPCWSTR,HWND,LPCOMMCONFIG);
#define                       CommConfigDialog WINELIB_NAME_AW(CommConfigDialog)
WINBASEAPI BOOL        WINAPI ConnectNamedPipe(HANDLE,LPOVERLAPPED);
WINBASEAPI BOOL        WINAPI ContinueDebugEvent(DWORD,DWORD,DWORD);
WINBASEAPI HANDLE      WINAPI ConvertToGlobalHandle(HANDLE hSrc);
WINBASEAPI BOOL        WINAPI CopyFileA(LPCSTR,LPCSTR,BOOL);
WINBASEAPI BOOL        WINAPI CopyFileW(LPCWSTR,LPCWSTR,BOOL);
#define                       CopyFile WINELIB_NAME_AW(CopyFile)
WINBASEAPI HRESULT     WINAPI CopyFile2(PCWSTR,PCWSTR,COPYFILE2_EXTENDED_PARAMETERS*);
WINBASEAPI BOOL        WINAPI CopyFileExA(LPCSTR, LPCSTR, LPPROGRESS_ROUTINE, LPVOID, LPBOOL, DWORD);
WINBASEAPI BOOL        WINAPI CopyFileExW(LPCWSTR, LPCWSTR, LPPROGRESS_ROUTINE, LPVOID, LPBOOL, DWORD);
#define                       CopyFileEx WINELIB_NAME_AW(CopyFileEx)
WINADVAPI  BOOL        WINAPI CopySid(DWORD,PSID,PSID);
WINBASEAPI INT         WINAPI CompareFileTime(const FILETIME*,const FILETIME*);
WINBASEAPI BOOL        WINAPI ConvertFiberToThread(void);
WINBASEAPI LPVOID      WINAPI ConvertThreadToFiber(LPVOID);
WINBASEAPI LPVOID      WINAPI ConvertThreadToFiberEx(LPVOID,DWORD);
WINADVAPI  BOOL        WINAPI ConvertToAutoInheritPrivateObjectSecurity(PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR*,GUID*,BOOL,PGENERIC_MAPPING);
WINBASEAPI HANDLE      WINAPI CreateActCtxA(PCACTCTXA);
WINBASEAPI HANDLE      WINAPI CreateActCtxW(PCACTCTXW);
#define                       CreateActCtx WINELIB_NAME_AW(CreateActCtx)
WINBASEAPI BOOL        WINAPI CreateDirectoryA(LPCSTR,LPSECURITY_ATTRIBUTES);
WINBASEAPI BOOL        WINAPI CreateDirectoryW(LPCWSTR,LPSECURITY_ATTRIBUTES);
#define                       CreateDirectory WINELIB_NAME_AW(CreateDirectory)
WINBASEAPI BOOL        WINAPI CreateDirectoryExA(LPCSTR,LPCSTR,LPSECURITY_ATTRIBUTES);
WINBASEAPI BOOL        WINAPI CreateDirectoryExW(LPCWSTR,LPCWSTR,LPSECURITY_ATTRIBUTES);
#define                       CreateDirectoryEx WINELIB_NAME_AW(CreateDirectoryEx)
WINBASEAPI HANDLE      WINAPI CreateEventA(LPSECURITY_ATTRIBUTES,BOOL,BOOL,LPCSTR);
WINBASEAPI HANDLE      WINAPI CreateEventW(LPSECURITY_ATTRIBUTES,BOOL,BOOL,LPCWSTR);
#define                       CreateEvent WINELIB_NAME_AW(CreateEvent)
WINBASEAPI HANDLE      WINAPI CreateEventExA(SECURITY_ATTRIBUTES*,LPCSTR,DWORD,DWORD);
WINBASEAPI HANDLE      WINAPI CreateEventExW(SECURITY_ATTRIBUTES*,LPCWSTR,DWORD,DWORD);
#define                       CreateEventEx WINELIB_NAME_AW(CreateEventEx)
WINBASEAPI LPVOID      WINAPI CreateFiber(SIZE_T,LPFIBER_START_ROUTINE,LPVOID);
WINBASEAPI LPVOID      WINAPI CreateFiberEx(SIZE_T,SIZE_T,DWORD,LPFIBER_START_ROUTINE,LPVOID);
WINBASEAPI HANDLE      WINAPI CreateFileA(LPCSTR,DWORD,DWORD,LPSECURITY_ATTRIBUTES,DWORD,DWORD,HANDLE);
WINBASEAPI HANDLE      WINAPI CreateFileW(LPCWSTR,DWORD,DWORD,LPSECURITY_ATTRIBUTES,DWORD,DWORD,HANDLE);
#define                       CreateFile WINELIB_NAME_AW(CreateFile)
WINBASEAPI HANDLE      WINAPI CreateFileMappingA(HANDLE,LPSECURITY_ATTRIBUTES,DWORD,DWORD,DWORD,LPCSTR);
WINBASEAPI HANDLE      WINAPI CreateFileMappingW(HANDLE,LPSECURITY_ATTRIBUTES,DWORD,DWORD,DWORD,LPCWSTR);
#define                       CreateFileMapping WINELIB_NAME_AW(CreateFileMapping)
WINBASEAPI HANDLE      WINAPI CreateIoCompletionPort(HANDLE,HANDLE,ULONG_PTR,DWORD);
WINBASEAPI HANDLE      WINAPI CreateJobObjectA(LPSECURITY_ATTRIBUTES,LPCSTR);
WINBASEAPI HANDLE      WINAPI CreateJobObjectW(LPSECURITY_ATTRIBUTES,LPCWSTR);
#define                       CreateJobObject WINELIB_NAME_AW(CreateJobObject)
WINBASEAPI HANDLE      WINAPI CreateMailslotA(LPCSTR,DWORD,DWORD,LPSECURITY_ATTRIBUTES);
WINBASEAPI HANDLE      WINAPI CreateMailslotW(LPCWSTR,DWORD,DWORD,LPSECURITY_ATTRIBUTES);
#define                       CreateMailslot WINELIB_NAME_AW(CreateMailslot)
WINBASEAPI HANDLE      WINAPI CreateMemoryResourceNotification(MEMORY_RESOURCE_NOTIFICATION_TYPE);
WINBASEAPI HANDLE      WINAPI CreateMutexA(LPSECURITY_ATTRIBUTES,BOOL,LPCSTR);
WINBASEAPI HANDLE      WINAPI CreateMutexW(LPSECURITY_ATTRIBUTES,BOOL,LPCWSTR);
#define                       CreateMutex WINELIB_NAME_AW(CreateMutex)
WINBASEAPI HANDLE      WINAPI CreateMutexExA(SECURITY_ATTRIBUTES*,LPCSTR,DWORD,DWORD);
WINBASEAPI HANDLE      WINAPI CreateMutexExW(SECURITY_ATTRIBUTES*,LPCWSTR,DWORD,DWORD);
#define                       CreateMutexEx WINELIB_NAME_AW(CreateMutexEx)
WINBASEAPI HANDLE      WINAPI CreateNamedPipeA(LPCSTR,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,LPSECURITY_ATTRIBUTES);
WINBASEAPI HANDLE      WINAPI CreateNamedPipeW(LPCWSTR,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,LPSECURITY_ATTRIBUTES);
#define                       CreateNamedPipe WINELIB_NAME_AW(CreateNamedPipe)
WINBASEAPI BOOL        WINAPI CreatePipe(PHANDLE,PHANDLE,LPSECURITY_ATTRIBUTES,DWORD);
WINADVAPI  BOOL        WINAPI CreatePrivateObjectSecurity(PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR*,BOOL,HANDLE,PGENERIC_MAPPING);
WINADVAPI  BOOL        WINAPI CreatePrivateObjectSecurityEx(PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR*,GUID*,BOOL,ULONG,HANDLE,PGENERIC_MAPPING);
WINADVAPI  BOOL        WINAPI CreatePrivateObjectSecurityWithMultipleInheritance(PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR*,GUID**,ULONG,BOOL,ULONG,HANDLE,PGENERIC_MAPPING);
WINBASEAPI PTP_POOL    WINAPI CreateThreadpool(PVOID);
WINBASEAPI PTP_CLEANUP_GROUP WINAPI CreateThreadpoolCleanupGroup(void);
WINBASEAPI PTP_TIMER   WINAPI CreateThreadpoolTimer(PTP_TIMER_CALLBACK,PVOID,PTP_CALLBACK_ENVIRON);
WINBASEAPI PTP_WAIT    WINAPI CreateThreadpoolWait(PTP_WAIT_CALLBACK,PVOID,PTP_CALLBACK_ENVIRON);
WINBASEAPI PTP_WORK    WINAPI CreateThreadpoolWork(PTP_WORK_CALLBACK,PVOID,PTP_CALLBACK_ENVIRON);
WINBASEAPI BOOL        WINAPI CreateProcessA(LPCSTR,LPSTR,LPSECURITY_ATTRIBUTES,LPSECURITY_ATTRIBUTES,BOOL,DWORD,LPVOID,LPCSTR,LPSTARTUPINFOA,LPPROCESS_INFORMATION);
WINBASEAPI BOOL        WINAPI CreateProcessW(LPCWSTR,LPWSTR,LPSECURITY_ATTRIBUTES,LPSECURITY_ATTRIBUTES,BOOL,DWORD,LPVOID,LPCWSTR,LPSTARTUPINFOW,LPPROCESS_INFORMATION);
#define                       CreateProcess WINELIB_NAME_AW(CreateProcess)
WINADVAPI  BOOL        WINAPI CreateProcessAsUserA(HANDLE,LPCSTR,LPSTR,LPSECURITY_ATTRIBUTES,LPSECURITY_ATTRIBUTES,BOOL,DWORD,LPVOID,LPCSTR,LPSTARTUPINFOA,LPPROCESS_INFORMATION);
WINADVAPI  BOOL        WINAPI CreateProcessAsUserW(HANDLE,LPCWSTR,LPWSTR,LPSECURITY_ATTRIBUTES,LPSECURITY_ATTRIBUTES,BOOL,DWORD,LPVOID,LPCWSTR,LPSTARTUPINFOW,LPPROCESS_INFORMATION);
#define                       CreateProcessAsUser WINELIB_NAME_AW(CreateProcessAsUser)
WINADVAPI  BOOL        WINAPI CreateProcessWithLogonW(LPCWSTR,LPCWSTR,LPCWSTR,DWORD,LPCWSTR,LPWSTR,DWORD,LPVOID,LPCWSTR,LPSTARTUPINFOW,LPPROCESS_INFORMATION);
WINBASEAPI HANDLE      WINAPI CreateRemoteThread(HANDLE,LPSECURITY_ATTRIBUTES,SIZE_T,LPTHREAD_START_ROUTINE,LPVOID,DWORD,LPDWORD);
WINADVAPI  BOOL        WINAPI CreateRestrictedToken(HANDLE,DWORD,DWORD,PSID_AND_ATTRIBUTES,DWORD,PLUID_AND_ATTRIBUTES,DWORD,PSID_AND_ATTRIBUTES,PHANDLE);
WINBASEAPI HANDLE      WINAPI CreateSemaphoreA(LPSECURITY_ATTRIBUTES,LONG,LONG,LPCSTR);
WINBASEAPI HANDLE      WINAPI CreateSemaphoreW(LPSECURITY_ATTRIBUTES,LONG,LONG,LPCWSTR);
#define                       CreateSemaphore WINELIB_NAME_AW(CreateSemaphore)
WINBASEAPI HANDLE      WINAPI CreateSemaphoreExA(SECURITY_ATTRIBUTES*,LONG,LONG,LPCSTR,DWORD,DWORD);
WINBASEAPI HANDLE      WINAPI CreateSemaphoreExW(SECURITY_ATTRIBUTES*,LONG,LONG,LPCWSTR,DWORD,DWORD);
#define                       CreateSemaphoreEx WINELIB_NAME_AW(CreateSemaphoreEx)
WINBASEAPI BOOLEAN     WINAPI CreateSymbolicLinkA(LPCSTR,LPCSTR,DWORD);
WINBASEAPI BOOLEAN     WINAPI CreateSymbolicLinkW(LPCWSTR,LPCWSTR,DWORD);
#define                       CreateSymbolicLink WINELIB_NAME_AW(CreateSymbolicLink)
WINBASEAPI BOOL        WINAPI CreateHardLinkA(LPCSTR,LPCSTR,LPSECURITY_ATTRIBUTES);
WINBASEAPI BOOL        WINAPI CreateHardLinkW(LPCWSTR,LPCWSTR,LPSECURITY_ATTRIBUTES);
#define                       CreateHardLink WINELIB_NAME_AW(CreateHardLink)
WINBASEAPI DWORD       WINAPI CreateTapePartition(HANDLE,DWORD,DWORD,DWORD);
WINBASEAPI HANDLE      WINAPI CreateThread(LPSECURITY_ATTRIBUTES,SIZE_T,LPTHREAD_START_ROUTINE,LPVOID,DWORD,LPDWORD);
WINBASEAPI HANDLE      WINAPI CreateTimerQueue(void);
WINBASEAPI BOOL        WINAPI CreateTimerQueueTimer(PHANDLE,HANDLE,WAITORTIMERCALLBACK,PVOID,DWORD,DWORD,ULONG);
WINBASEAPI HANDLE      WINAPI CreateWaitableTimerA(LPSECURITY_ATTRIBUTES,BOOL,LPCSTR);
WINBASEAPI HANDLE      WINAPI CreateWaitableTimerW(LPSECURITY_ATTRIBUTES,BOOL,LPCWSTR);
#define                       CreateWaitableTimer WINELIB_NAME_AW(CreateWaitableTimer)
WINBASEAPI HANDLE      WINAPI CreateWaitableTimerExA(SECURITY_ATTRIBUTES*,LPCSTR,DWORD,DWORD);
WINBASEAPI HANDLE      WINAPI CreateWaitableTimerExW(SECURITY_ATTRIBUTES*,LPCWSTR,DWORD,DWORD);
#define                       CreateWaitableTimerEx WINELIB_NAME_AW(CreateWaitableTimerEx)
WINADVAPI  BOOL        WINAPI CreateWellKnownSid(WELL_KNOWN_SID_TYPE,PSID,PSID,DWORD*);
WINBASEAPI BOOL        WINAPI DeactivateActCtx(DWORD,ULONG_PTR);
WINBASEAPI BOOL        WINAPI DebugActiveProcess(DWORD);
WINBASEAPI BOOL        WINAPI DebugActiveProcessStop(DWORD);
WINBASEAPI void        WINAPI DebugBreak(void);
WINBASEAPI BOOL        WINAPI DebugBreakProcess(HANDLE);
WINBASEAPI BOOL        WINAPI DebugSetProcessKillOnExit(BOOL);
WINBASEAPI void *      WINAPI DecodePointer(void *);
WINBASEAPI void *      WINAPI DecodeSystemPointer(void *);
WINADVAPI  BOOL        WINAPI DecryptFileA(LPCSTR,DWORD);
WINADVAPI  BOOL        WINAPI DecryptFileW(LPCWSTR,DWORD);
#define                       DecryptFile WINELIB_NAME_AW(DecryptFile)
WINBASEAPI BOOL        WINAPI DefineDosDeviceA(DWORD,LPCSTR,LPCSTR);
WINBASEAPI BOOL        WINAPI DefineDosDeviceW(DWORD,LPCWSTR,LPCWSTR);
#define                       DefineDosDevice WINELIB_NAME_AW(DefineDosDevice)
#define                       DefineHandleTable(w) ((w),TRUE)
WINADVAPI  BOOL        WINAPI DeleteAce(PACL,DWORD);
WINBASEAPI ATOM        WINAPI DeleteAtom(ATOM);
WINBASEAPI void        WINAPI DeleteCriticalSection(CRITICAL_SECTION *lpCrit);
WINBASEAPI void        WINAPI DeleteFiber(LPVOID);
WINBASEAPI BOOL        WINAPI DeleteFileA(LPCSTR);
WINBASEAPI BOOL        WINAPI DeleteFileW(LPCWSTR);
#define                       DeleteFile WINELIB_NAME_AW(DeleteFile)
WINBASEAPI void        WINAPI DeleteProcThreadAttributeList(struct _PROC_THREAD_ATTRIBUTE_LIST*);
WINBASEAPI BOOL        WINAPI DeleteTimerQueue(HANDLE);
WINBASEAPI BOOL        WINAPI DeleteTimerQueueEx(HANDLE,HANDLE);
WINBASEAPI BOOL        WINAPI DeleteTimerQueueTimer(HANDLE,HANDLE,HANDLE);
WINBASEAPI BOOL        WINAPI DeleteVolumeMountPointA(LPCSTR);
WINBASEAPI BOOL        WINAPI DeleteVolumeMountPointW(LPCWSTR);
#define                       DeleteVolumeMountPoint WINELIB_NAME_AW(DeleteVolumeMountPoint)
WINADVAPI  BOOL        WINAPI DeregisterEventSource(HANDLE);
WINADVAPI  BOOL        WINAPI DestroyPrivateObjectSecurity(PSECURITY_DESCRIPTOR*);
WINBASEAPI BOOL        WINAPI DeviceIoControl(HANDLE,DWORD,LPVOID,DWORD,LPVOID,DWORD,LPDWORD,LPOVERLAPPED);
WINBASEAPI BOOL        WINAPI DisableThreadLibraryCalls(HMODULE);
WINBASEAPI BOOL        WINAPI DisconnectNamedPipe(HANDLE);
WINBASEAPI BOOL        WINAPI DnsHostnameToComputerNameA(LPCSTR,LPSTR,LPDWORD);
WINBASEAPI BOOL        WINAPI DnsHostnameToComputerNameW(LPCWSTR,LPWSTR,LPDWORD);
#define                       DnsHostnameToComputerName WINELIB_NAME_AW(DnsHostnameToComputerName)
WINBASEAPI BOOL        WINAPI DosDateTimeToFileTime(WORD,WORD,LPFILETIME);
WINBASEAPI BOOL        WINAPI DuplicateHandle(HANDLE,HANDLE,HANDLE,HANDLE*,DWORD,BOOL,DWORD);
WINADVAPI  BOOL        WINAPI DuplicateToken(HANDLE,SECURITY_IMPERSONATION_LEVEL,PHANDLE);
WINADVAPI  BOOL        WINAPI DuplicateTokenEx(HANDLE,DWORD,LPSECURITY_ATTRIBUTES,SECURITY_IMPERSONATION_LEVEL,TOKEN_TYPE,PHANDLE);
WINBASEAPI BOOL        WINAPI EscapeCommFunction(HANDLE,DWORD);
WINBASEAPI void *      WINAPI EncodePointer(void *);
WINBASEAPI void *      WINAPI EncodeSystemPointer(void *);
WINADVAPI  BOOL        WINAPI EncryptFileA(LPCSTR);
WINADVAPI  BOOL        WINAPI EncryptFileW(LPCWSTR);
#define                       EncryptFile WINELIB_NAME_AW(EncryptFile)
WINBASEAPI BOOL        WINAPI EndUpdateResourceA(HANDLE,BOOL);
WINBASEAPI BOOL        WINAPI EndUpdateResourceW(HANDLE,BOOL);
#define                       EndUpdateResource WINELIB_NAME_AW(EndUpdateResource)
WINBASEAPI void        WINAPI EnterCriticalSection(CRITICAL_SECTION *lpCrit);
WINBASEAPI BOOL        WINAPI EnumResourceLanguagesA(HMODULE,LPCSTR,LPCSTR,ENUMRESLANGPROCA,LONG_PTR);
WINBASEAPI BOOL        WINAPI EnumResourceLanguagesW(HMODULE,LPCWSTR,LPCWSTR,ENUMRESLANGPROCW,LONG_PTR);
#define                       EnumResourceLanguages WINELIB_NAME_AW(EnumResourceLanguages)
WINBASEAPI BOOL        WINAPI EnumResourceLanguagesExA(HMODULE,LPCSTR,LPCSTR,ENUMRESLANGPROCA,LONG_PTR,DWORD,LANGID);
WINBASEAPI BOOL        WINAPI EnumResourceLanguagesExW(HMODULE,LPCWSTR,LPCWSTR,ENUMRESLANGPROCW,LONG_PTR,DWORD,LANGID);
#define                       EnumResourceLanguagesEx WINELIB_NAME_AW(EnumResourceLanguagesEx)
WINBASEAPI BOOL        WINAPI EnumResourceNamesA(HMODULE,LPCSTR,ENUMRESNAMEPROCA,LONG_PTR);
WINBASEAPI BOOL        WINAPI EnumResourceNamesW(HMODULE,LPCWSTR,ENUMRESNAMEPROCW,LONG_PTR);
#define                       EnumResourceNames WINELIB_NAME_AW(EnumResourceNames)
WINBASEAPI BOOL        WINAPI EnumResourceTypesA(HMODULE,ENUMRESTYPEPROCA,LONG_PTR);
WINBASEAPI BOOL        WINAPI EnumResourceTypesW(HMODULE,ENUMRESTYPEPROCW,LONG_PTR);
#define                       EnumResourceTypes WINELIB_NAME_AW(EnumResourceTypes)
WINADVAPI  BOOL        WINAPI EqualSid(PSID, PSID);
WINADVAPI  BOOL        WINAPI EqualPrefixSid(PSID,PSID);
WINBASEAPI DWORD       WINAPI EraseTape(HANDLE,DWORD,BOOL);
WINBASEAPI VOID DECLSPEC_NORETURN WINAPI ExitProcess(DWORD);
WINBASEAPI VOID DECLSPEC_NORETURN WINAPI ExitThread(DWORD);
WINBASEAPI DWORD       WINAPI ExpandEnvironmentStringsA(LPCSTR,LPSTR,DWORD);
WINBASEAPI DWORD       WINAPI ExpandEnvironmentStringsW(LPCWSTR,LPWSTR,DWORD);
#define                       ExpandEnvironmentStrings WINELIB_NAME_AW(ExpandEnvironmentStrings)
WINBASEAPI void        WINAPI FatalAppExitA(UINT,LPCSTR);
WINBASEAPI void        WINAPI FatalAppExitW(UINT,LPCWSTR);
WINBASEAPI void        WINAPI FatalExit(int);
#define                       FatalAppExit WINELIB_NAME_AW(FatalAppExit)
WINADVAPI  BOOL        WINAPI FileEncryptionStatusA(LPCSTR,LPDWORD);
WINADVAPI  BOOL        WINAPI FileEncryptionStatusW(LPCWSTR,LPDWORD);
#define                       FileEncryptionStatus WINELIB_NAME_AW(FileEncryptionStatus)
WINBASEAPI BOOL        WINAPI FileTimeToDosDateTime(const FILETIME*,LPWORD,LPWORD);
WINBASEAPI BOOL        WINAPI FileTimeToLocalFileTime(const FILETIME*,LPFILETIME);
WINBASEAPI BOOL        WINAPI FileTimeToSystemTime(const FILETIME*,LPSYSTEMTIME);
WINBASEAPI BOOL        WINAPI FindActCtxSectionStringA(DWORD,const GUID *,ULONG,LPCSTR,PACTCTX_SECTION_KEYED_DATA);
WINBASEAPI BOOL        WINAPI FindActCtxSectionStringW(DWORD,const GUID *,ULONG,LPCWSTR,PACTCTX_SECTION_KEYED_DATA);
#define                       FindActCtxSectionString WINELIB_NAME_AW(FindActCtxSectionString)
WINBASEAPI BOOL        WINAPI FindActCtxSectionGuid(DWORD,const GUID *,ULONG,const GUID *,PACTCTX_SECTION_KEYED_DATA);
WINBASEAPI ATOM        WINAPI FindAtomA(LPCSTR);
WINBASEAPI ATOM        WINAPI FindAtomW(LPCWSTR);
#define                       FindAtom WINELIB_NAME_AW(FindAtom)
WINBASEAPI BOOL        WINAPI FindClose(HANDLE);
WINBASEAPI HANDLE      WINAPI FindFirstChangeNotificationA(LPCSTR,BOOL,DWORD);
WINBASEAPI HANDLE      WINAPI FindFirstChangeNotificationW(LPCWSTR,BOOL,DWORD);
#define                       FindFirstChangeNotification WINELIB_NAME_AW(FindFirstChangeNotification)
WINBASEAPI HANDLE      WINAPI FindFirstFileA(LPCSTR,LPWIN32_FIND_DATAA);
WINBASEAPI HANDLE      WINAPI FindFirstFileW(LPCWSTR,LPWIN32_FIND_DATAW);
#define                       FindFirstFile WINELIB_NAME_AW(FindFirstFile)
WINBASEAPI HANDLE      WINAPI FindFirstFileExA(LPCSTR,FINDEX_INFO_LEVELS,LPVOID,FINDEX_SEARCH_OPS,LPVOID,DWORD);
WINBASEAPI HANDLE      WINAPI FindFirstFileExW(LPCWSTR,FINDEX_INFO_LEVELS,LPVOID,FINDEX_SEARCH_OPS,LPVOID,DWORD);
#define                       FindFirstFileEx WINELIB_NAME_AW(FindFirstFileEx)
WINADVAPI  BOOL        WINAPI FindFirstFreeAce(PACL,LPVOID*);
WINBASEAPI BOOL        WINAPI FindNextChangeNotification(HANDLE);
WINBASEAPI BOOL        WINAPI FindNextFileA(HANDLE,LPWIN32_FIND_DATAA);
WINBASEAPI BOOL        WINAPI FindNextFileW(HANDLE,LPWIN32_FIND_DATAW);
#define                       FindNextFile WINELIB_NAME_AW(FindNextFile)
WINBASEAPI BOOL        WINAPI FindCloseChangeNotification(HANDLE);
WINBASEAPI HRSRC       WINAPI FindResourceA(HMODULE,LPCSTR,LPCSTR);
WINBASEAPI HRSRC       WINAPI FindResourceW(HMODULE,LPCWSTR,LPCWSTR);
#define                       FindResource WINELIB_NAME_AW(FindResource)
WINBASEAPI HRSRC       WINAPI FindResourceExA(HMODULE,LPCSTR,LPCSTR,WORD);
WINBASEAPI HRSRC       WINAPI FindResourceExW(HMODULE,LPCWSTR,LPCWSTR,WORD);
#define                       FindResourceEx WINELIB_NAME_AW(FindResourceEx)
WINBASEAPI HANDLE      WINAPI FindFirstVolumeA(LPSTR,DWORD);
WINBASEAPI HANDLE      WINAPI FindFirstVolumeW(LPWSTR,DWORD);
#define                       FindFirstVolume WINELIB_NAME_AW(FindFirstVolume)
WINBASEAPI HANDLE      WINAPI FindFirstVolumeMountPointA(LPCSTR,LPSTR,DWORD);
WINBASEAPI HANDLE      WINAPI FindFirstVolumeMountPointW(LPCWSTR,LPWSTR,DWORD);
#define                       FindFirstVolumeMountPoint WINELIB_NAME_AW(FindFirstVolumeMountPoint)
WINBASEAPI BOOL        WINAPI FindNextVolumeA(HANDLE,LPSTR,DWORD);
WINBASEAPI BOOL        WINAPI FindNextVolumeW(HANDLE,LPWSTR,DWORD);
#define                       FindNextVolume WINELIB_NAME_AW(FindNextVolume)
WINBASEAPI BOOL        WINAPI FindNextVolumeMountPointA(HANDLE,LPSTR,DWORD);
WINBASEAPI BOOL        WINAPI FindNextVolumeMountPointW(HANDLE,LPWSTR,DWORD);
#define                       FindNextVolumeMountPoint WINELIB_NAME_AW(FindNextVolumeMountPoint)
WINBASEAPI BOOL        WINAPI FindVolumeClose(HANDLE);
WINBASEAPI BOOL        WINAPI FindVolumeMountPointClose(HANDLE);
WINBASEAPI DWORD       WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION);
WINBASEAPI BOOL        WINAPI FlsFree(DWORD);
WINBASEAPI PVOID       WINAPI FlsGetValue(DWORD);
WINBASEAPI BOOL        WINAPI FlsSetValue(DWORD,PVOID);
WINBASEAPI BOOL        WINAPI FlushFileBuffers(HANDLE);
WINBASEAPI BOOL        WINAPI FlushInstructionCache(HANDLE,LPCVOID,SIZE_T);
WINBASEAPI VOID        WINAPI FlushProcessWriteBuffers(void);
WINBASEAPI BOOL        WINAPI FlushViewOfFile(LPCVOID,SIZE_T);
WINBASEAPI DWORD       WINAPI FormatMessageA(DWORD,LPCVOID,DWORD,DWORD,LPSTR,DWORD,__ms_va_list*);
WINBASEAPI DWORD       WINAPI FormatMessageW(DWORD,LPCVOID,DWORD,DWORD,LPWSTR,DWORD,__ms_va_list*);
#define                       FormatMessage WINELIB_NAME_AW(FormatMessage)
WINBASEAPI BOOL        WINAPI FreeEnvironmentStringsA(LPSTR);
WINBASEAPI BOOL        WINAPI FreeEnvironmentStringsW(LPWSTR);
#define                       FreeEnvironmentStrings WINELIB_NAME_AW(FreeEnvironmentStrings)
WINBASEAPI BOOL        WINAPI FreeLibrary(HMODULE);
WINBASEAPI VOID DECLSPEC_NORETURN WINAPI FreeLibraryAndExitThread(HINSTANCE,DWORD);
WINBASEAPI VOID        WINAPI FreeLibraryWhenCallbackReturns(PTP_CALLBACK_INSTANCE,HMODULE);
#define                       FreeModule(handle) FreeLibrary(handle)
#define                       FreeProcInstance(proc) /*nothing*/
WINBASEAPI BOOL        WINAPI FreeResource(HGLOBAL);
WINADVAPI  PVOID       WINAPI FreeSid(PSID);
WINADVAPI  BOOL        WINAPI GetAce(PACL,DWORD,LPVOID*);
WINADVAPI  BOOL        WINAPI GetAclInformation(PACL,LPVOID,DWORD,ACL_INFORMATION_CLASS);
WINBASEAPI UINT        WINAPI GetAtomNameA(ATOM,LPSTR,INT);
WINBASEAPI UINT        WINAPI GetAtomNameW(ATOM,LPWSTR,INT);
#define                       GetAtomName WINELIB_NAME_AW(GetAtomName)
WINBASEAPI BOOL        WINAPI GetBinaryTypeA( LPCSTR lpApplicationName, LPDWORD lpBinaryType );
WINBASEAPI BOOL        WINAPI GetBinaryTypeW( LPCWSTR lpApplicationName, LPDWORD lpBinaryType );
#define                       GetBinaryType WINELIB_NAME_AW(GetBinaryType)
WINBASEAPI BOOL        WINAPI GetCurrentActCtx(HANDLE *);
WINBASEAPI BOOL        WINAPI GetCommConfig(HANDLE,LPCOMMCONFIG,LPDWORD);
WINBASEAPI BOOL        WINAPI GetCommMask(HANDLE,LPDWORD);
WINBASEAPI BOOL        WINAPI GetCommModemStatus(HANDLE,LPDWORD);
WINBASEAPI BOOL        WINAPI GetCommProperties(HANDLE,LPCOMMPROP);
WINBASEAPI BOOL        WINAPI GetCommState(HANDLE,LPDCB);
WINBASEAPI BOOL        WINAPI GetCommTimeouts(HANDLE,LPCOMMTIMEOUTS);
WINBASEAPI LPSTR       WINAPI GetCommandLineA(void);
WINBASEAPI LPWSTR      WINAPI GetCommandLineW(void);
#define                       GetCommandLine WINELIB_NAME_AW(GetCommandLine)
WINBASEAPI DWORD       WINAPI GetCompressedFileSizeA(LPCSTR,LPDWORD);
WINBASEAPI DWORD       WINAPI GetCompressedFileSizeW(LPCWSTR,LPDWORD);
#define                       GetCompressedFileSize WINELIB_NAME_AW(GetCompressedFileSize)
WINBASEAPI BOOL        WINAPI GetComputerNameA(LPSTR,LPDWORD);
WINBASEAPI BOOL        WINAPI GetComputerNameW(LPWSTR,LPDWORD);
#define                       GetComputerName WINELIB_NAME_AW(GetComputerName)
WINBASEAPI BOOL        WINAPI GetComputerNameExA(COMPUTER_NAME_FORMAT,LPSTR,LPDWORD);
WINBASEAPI BOOL        WINAPI GetComputerNameExW(COMPUTER_NAME_FORMAT,LPWSTR,LPDWORD);
#define                       GetComputerNameEx WINELIB_NAME_AW(GetComputerNameEx)
WINBASEAPI UINT        WINAPI GetCurrentDirectoryA(UINT,LPSTR);
WINBASEAPI UINT        WINAPI GetCurrentDirectoryW(UINT,LPWSTR);
#define                       GetCurrentDirectory WINELIB_NAME_AW(GetCurrentDirectory)
WINADVAPI  BOOL        WINAPI GetCurrentHwProfileA(LPHW_PROFILE_INFOA);
WINADVAPI  BOOL        WINAPI GetCurrentHwProfileW(LPHW_PROFILE_INFOW);
#define                       GetCurrentHwProfile WINELIB_NAME_AW(GetCurrentHwProfile)
WINBASEAPI HANDLE      WINAPI GetCurrentProcess(void);
WINBASEAPI DWORD       WINAPI GetCurrentProcessorNumber(void);
WINBASEAPI VOID        WINAPI GetCurrentProcessorNumberEx(PPROCESSOR_NUMBER);
WINBASEAPI HANDLE      WINAPI GetCurrentThread(void);
#define                       GetCurrentTime() GetTickCount()
WINBASEAPI BOOL        WINAPI GetDefaultCommConfigA(LPCSTR,LPCOMMCONFIG,LPDWORD);
WINBASEAPI BOOL        WINAPI GetDefaultCommConfigW(LPCWSTR,LPCOMMCONFIG,LPDWORD);
#define                       GetDefaultCommConfig WINELIB_NAME_AW(GetDefaultCommConfig)
WINBASEAPI BOOL        WINAPI GetDevicePowerState(HANDLE,BOOL*);
WINBASEAPI BOOL        WINAPI GetDiskFreeSpaceA(LPCSTR,LPDWORD,LPDWORD,LPDWORD,LPDWORD);
WINBASEAPI BOOL        WINAPI GetDiskFreeSpaceW(LPCWSTR,LPDWORD,LPDWORD,LPDWORD,LPDWORD);
#define                       GetDiskFreeSpace WINELIB_NAME_AW(GetDiskFreeSpace)
WINBASEAPI BOOL        WINAPI GetDiskFreeSpaceExA(LPCSTR,PULARGE_INTEGER,PULARGE_INTEGER,PULARGE_INTEGER);
WINBASEAPI BOOL        WINAPI GetDiskFreeSpaceExW(LPCWSTR,PULARGE_INTEGER,PULARGE_INTEGER,PULARGE_INTEGER);
#define                       GetDiskFreeSpaceEx WINELIB_NAME_AW(GetDiskFreeSpaceEx)
WINBASEAPI DWORD       WINAPI GetDllDirectoryA(DWORD,LPSTR);
WINBASEAPI DWORD       WINAPI GetDllDirectoryW(DWORD,LPWSTR);
#define                       GetDllDirectory WINELIB_NAME_AW(GetDllDirectory)
WINBASEAPI UINT        WINAPI GetDriveTypeA(LPCSTR);
WINBASEAPI UINT        WINAPI GetDriveTypeW(LPCWSTR);
#define                       GetDriveType WINELIB_NAME_AW(GetDriveType)
WINBASEAPI DWORD       WINAPI GetDynamicTimeZoneInformation(PDYNAMIC_TIME_ZONE_INFORMATION);
WINBASEAPI LPSTR       WINAPI GetEnvironmentStringsA(void);
WINBASEAPI LPWSTR      WINAPI GetEnvironmentStringsW(void);
#define                       GetEnvironmentStrings WINELIB_NAME_AW(GetEnvironmentStrings)
WINBASEAPI DWORD       WINAPI GetEnvironmentVariableA(LPCSTR,LPSTR,DWORD);
WINBASEAPI DWORD       WINAPI GetEnvironmentVariableW(LPCWSTR,LPWSTR,DWORD);
#define                       GetEnvironmentVariable WINELIB_NAME_AW(GetEnvironmentVariable)
WINBASEAPI UINT        WINAPI GetErrorMode(void);
WINADVAPI  BOOL        WINAPI GetEventLogInformation(HANDLE,DWORD,LPVOID,DWORD,LPDWORD);
WINBASEAPI BOOL        WINAPI GetExitCodeProcess(HANDLE,LPDWORD);
WINBASEAPI BOOL        WINAPI GetExitCodeThread(HANDLE,LPDWORD);
WINBASEAPI DWORD       WINAPI GetFileAttributesA(LPCSTR);
WINBASEAPI DWORD       WINAPI GetFileAttributesW(LPCWSTR);
#define                       GetFileAttributes WINELIB_NAME_AW(GetFileAttributes)
WINBASEAPI BOOL        WINAPI GetFileAttributesExA(LPCSTR,GET_FILEEX_INFO_LEVELS,LPVOID);
WINBASEAPI BOOL        WINAPI GetFileAttributesExW(LPCWSTR,GET_FILEEX_INFO_LEVELS,LPVOID);
#define                       GetFileAttributesEx WINELIB_NAME_AW(GetFileAttributesEx)
WINBASEAPI BOOL        WINAPI GetFileInformationByHandle(HANDLE,BY_HANDLE_FILE_INFORMATION*);
WINBASEAPI BOOL        WINAPI GetFileInformationByHandleEx(HANDLE,FILE_INFO_BY_HANDLE_CLASS,LPVOID,DWORD);
WINADVAPI  BOOL        WINAPI GetFileSecurityA(LPCSTR,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR,DWORD,LPDWORD);
WINADVAPI  BOOL        WINAPI GetFileSecurityW(LPCWSTR,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR,DWORD,LPDWORD);
#define                       GetFileSecurity WINELIB_NAME_AW(GetFileSecurity)
WINBASEAPI DWORD       WINAPI GetFileSize(HANDLE,LPDWORD);
WINBASEAPI BOOL        WINAPI GetFileSizeEx(HANDLE,PLARGE_INTEGER);
WINBASEAPI BOOL        WINAPI GetFileTime(HANDLE,LPFILETIME,LPFILETIME,LPFILETIME);
WINBASEAPI DWORD       WINAPI GetFileType(HANDLE);
#define                       GetFreeSpace(w) (__MSABI_LONG(0x100000))
WINBASEAPI DWORD       WINAPI GetFullPathNameA(LPCSTR,DWORD,LPSTR,LPSTR*);
WINBASEAPI DWORD       WINAPI GetFullPathNameW(LPCWSTR,DWORD,LPWSTR,LPWSTR*);
#define                       GetFullPathName WINELIB_NAME_AW(GetFullPathName)
WINBASEAPI BOOL        WINAPI GetHandleInformation(HANDLE,LPDWORD);
WINADVAPI  BOOL        WINAPI GetKernelObjectSecurity(HANDLE,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR,DWORD,LPDWORD);
WINADVAPI  DWORD       WINAPI GetLengthSid(PSID);
WINBASEAPI VOID        WINAPI GetLocalTime(LPSYSTEMTIME);
WINBASEAPI DWORD       WINAPI GetLogicalDrives(void);
WINBASEAPI UINT        WINAPI GetLogicalDriveStringsA(UINT,LPSTR);
WINBASEAPI UINT        WINAPI GetLogicalDriveStringsW(UINT,LPWSTR);
#define                       GetLogicalDriveStrings WINELIB_NAME_AW(GetLogicalDriveStrings)
WINBASEAPI DWORD       WINAPI GetLongPathNameA(LPCSTR,LPSTR,DWORD);
WINBASEAPI DWORD       WINAPI GetLongPathNameW(LPCWSTR,LPWSTR,DWORD);
#define                       GetLongPathName WINELIB_NAME_AW(GetLongPathName)
WINBASEAPI BOOL        WINAPI GetMailslotInfo(HANDLE,LPDWORD,LPDWORD,LPDWORD,LPDWORD);
WINBASEAPI DWORD       WINAPI GetModuleFileNameA(HMODULE,LPSTR,DWORD);
WINBASEAPI DWORD       WINAPI GetModuleFileNameW(HMODULE,LPWSTR,DWORD);
#define                       GetModuleFileName WINELIB_NAME_AW(GetModuleFileName)
WINBASEAPI HMODULE     WINAPI GetModuleHandleA(LPCSTR);
WINBASEAPI HMODULE     WINAPI GetModuleHandleW(LPCWSTR);
#define                       GetModuleHandle WINELIB_NAME_AW(GetModuleHandle)
WINBASEAPI BOOL        WINAPI GetModuleHandleExA(DWORD,LPCSTR,HMODULE*);
WINBASEAPI BOOL        WINAPI GetModuleHandleExW(DWORD,LPCWSTR,HMODULE*);
#define                       GetModuleHandleEx WINELIB_NAME_AW(GetModuleHandleEx)
WINBASEAPI BOOL        WINAPI GetNamedPipeHandleStateA(HANDLE,LPDWORD,LPDWORD,LPDWORD,LPDWORD,LPSTR,DWORD);
WINBASEAPI BOOL        WINAPI GetNamedPipeHandleStateW(HANDLE,LPDWORD,LPDWORD,LPDWORD,LPDWORD,LPWSTR,DWORD);
#define                       GetNamedPipeHandleState WINELIB_NAME_AW(GetNamedPipeHandleState)
WINBASEAPI BOOL        WINAPI GetNamedPipeInfo(HANDLE,LPDWORD,LPDWORD,LPDWORD,LPDWORD);
WINBASEAPI BOOL        WINAPI GetNamedPipeClientProcessId(HANDLE,PULONG);
WINBASEAPI VOID        WINAPI GetNativeSystemInfo(LPSYSTEM_INFO);
WINBASEAPI BOOL        WINAPI GetNumaProcessorNode(UCHAR,PUCHAR);
WINADVAPI  BOOL        WINAPI GetNumberOfEventLogRecords(HANDLE,PDWORD);
WINADVAPI  BOOL        WINAPI GetOldestEventLogRecord(HANDLE,PDWORD);
WINBASEAPI BOOL        WINAPI GetOverlappedResult(HANDLE,LPOVERLAPPED,LPDWORD,BOOL);
WINBASEAPI DWORD       WINAPI GetPriorityClass(HANDLE);
WINADVAPI  BOOL        WINAPI GetPrivateObjectSecurity(PSECURITY_DESCRIPTOR,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR,DWORD,PDWORD);
WINBASEAPI UINT        WINAPI GetPrivateProfileIntA(LPCSTR,LPCSTR,INT,LPCSTR);
WINBASEAPI UINT        WINAPI GetPrivateProfileIntW(LPCWSTR,LPCWSTR,INT,LPCWSTR);
#define                       GetPrivateProfileInt WINELIB_NAME_AW(GetPrivateProfileInt)
WINBASEAPI INT         WINAPI GetPrivateProfileSectionA(LPCSTR,LPSTR,DWORD,LPCSTR);
WINBASEAPI INT         WINAPI GetPrivateProfileSectionW(LPCWSTR,LPWSTR,DWORD,LPCWSTR);
#define                       GetPrivateProfileSection WINELIB_NAME_AW(GetPrivateProfileSection)
WINBASEAPI DWORD       WINAPI GetPrivateProfileSectionNamesA(LPSTR,DWORD,LPCSTR);
WINBASEAPI DWORD       WINAPI GetPrivateProfileSectionNamesW(LPWSTR,DWORD,LPCWSTR);
#define                       GetPrivateProfileSectionNames WINELIB_NAME_AW(GetPrivateProfileSectionNames)
WINBASEAPI INT         WINAPI GetPrivateProfileStringA(LPCSTR,LPCSTR,LPCSTR,LPSTR,UINT,LPCSTR);
WINBASEAPI INT         WINAPI GetPrivateProfileStringW(LPCWSTR,LPCWSTR,LPCWSTR,LPWSTR,UINT,LPCWSTR);
#define                       GetPrivateProfileString WINELIB_NAME_AW(GetPrivateProfileString)
WINBASEAPI BOOL        WINAPI GetPrivateProfileStructA(LPCSTR,LPCSTR,LPVOID,UINT,LPCSTR);
WINBASEAPI BOOL        WINAPI GetPrivateProfileStructW(LPCWSTR,LPCWSTR,LPVOID,UINT,LPCWSTR);
#define                       GetPrivateProfileStruct WINELIB_NAME_AW(GetPrivateProfileStruct)
WINBASEAPI BOOL        WINAPI IsInProcess(LPCSTR);
WINBASEAPI FARPROC     WINAPI GetProcAddress(HMODULE,LPCSTR);
WINBASEAPI BOOL        WINAPI GetProcessAffinityMask(HANDLE,PDWORD_PTR,PDWORD_PTR);
WINBASEAPI BOOL        WINAPI GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION,PDWORD);
WINBASEAPI BOOL        WINAPI GetLogicalProcessorInformationEx(LOGICAL_PROCESSOR_RELATIONSHIP,PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX,PDWORD);
WINBASEAPI DWORD       WINAPI GetProcessHeaps(DWORD,PHANDLE);
WINBASEAPI DWORD       WINAPI GetProcessId(HANDLE);
WINBASEAPI DWORD       WINAPI GetProcessIdOfThread(HANDLE);
WINBASEAPI BOOL        WINAPI GetProcessIoCounters(HANDLE,PIO_COUNTERS);
WINBASEAPI BOOL        WINAPI GetProcessPriorityBoost(HANDLE,PBOOL);
WINBASEAPI BOOL        WINAPI GetProcessShutdownParameters(LPDWORD,LPDWORD);
WINBASEAPI BOOL        WINAPI GetProcessTimes(HANDLE,LPFILETIME,LPFILETIME,LPFILETIME,LPFILETIME);
WINBASEAPI DWORD       WINAPI GetProcessVersion(DWORD);
WINBASEAPI BOOL        WINAPI GetProcessWorkingSetSize(HANDLE,PSIZE_T,PSIZE_T);
WINBASEAPI BOOL        WINAPI GetProductInfo(DWORD,DWORD,DWORD,DWORD,PDWORD);
WINBASEAPI UINT        WINAPI GetProfileIntA(LPCSTR,LPCSTR,INT);
WINBASEAPI UINT        WINAPI GetProfileIntW(LPCWSTR,LPCWSTR,INT);
#define                       GetProfileInt WINELIB_NAME_AW(GetProfileInt)
WINBASEAPI INT         WINAPI GetProfileSectionA(LPCSTR,LPSTR,DWORD);
WINBASEAPI INT         WINAPI GetProfileSectionW(LPCWSTR,LPWSTR,DWORD);
#define                       GetProfileSection WINELIB_NAME_AW(GetProfileSection)
WINBASEAPI INT         WINAPI GetProfileStringA(LPCSTR,LPCSTR,LPCSTR,LPSTR,UINT);
WINBASEAPI INT         WINAPI GetProfileStringW(LPCWSTR,LPCWSTR,LPCWSTR,LPWSTR,UINT);
#define                       GetProfileString WINELIB_NAME_AW(GetProfileString)
WINBASEAPI BOOL        WINAPI GetQueuedCompletionStatus(HANDLE,LPDWORD,PULONG_PTR,LPOVERLAPPED*,DWORD);
WINADVAPI  BOOL        WINAPI GetSecurityDescriptorControl(PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR_CONTROL,LPDWORD);
WINADVAPI  BOOL        WINAPI GetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR,LPBOOL,PACL *,LPBOOL);
WINADVAPI  BOOL        WINAPI GetSecurityDescriptorGroup(PSECURITY_DESCRIPTOR,PSID *,LPBOOL);
WINADVAPI  DWORD       WINAPI GetSecurityDescriptorLength(PSECURITY_DESCRIPTOR);
WINADVAPI  BOOL        WINAPI GetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR,PSID *,LPBOOL);
WINADVAPI  BOOL        WINAPI GetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR,LPBOOL,PACL *,LPBOOL);
WINADVAPI  PSID_IDENTIFIER_AUTHORITY WINAPI GetSidIdentifierAuthority(PSID);
WINADVAPI  DWORD       WINAPI GetSidLengthRequired(BYTE);
WINADVAPI  PDWORD      WINAPI GetSidSubAuthority(PSID,DWORD);
WINADVAPI  PUCHAR      WINAPI GetSidSubAuthorityCount(PSID);
WINBASEAPI DWORD       WINAPI GetShortPathNameA(LPCSTR,LPSTR,DWORD);
WINBASEAPI DWORD       WINAPI GetShortPathNameW(LPCWSTR,LPWSTR,DWORD);
#define                       GetShortPathName WINELIB_NAME_AW(GetShortPathName)
WINBASEAPI VOID        WINAPI GetStartupInfoA(LPSTARTUPINFOA);
WINBASEAPI VOID        WINAPI GetStartupInfoW(LPSTARTUPINFOW);
#define                       GetStartupInfo WINELIB_NAME_AW(GetStartupInfo)
WINBASEAPI HANDLE      WINAPI GetStdHandle(DWORD);
WINBASEAPI UINT        WINAPI GetSystemDirectoryA(LPSTR,UINT);
WINBASEAPI UINT        WINAPI GetSystemDirectoryW(LPWSTR,UINT);
#define                       GetSystemDirectory WINELIB_NAME_AW(GetSystemDirectory)
WINBASEAPI UINT        WINAPI GetSystemFirmwareTable(DWORD,DWORD,PVOID,DWORD);
WINBASEAPI VOID        WINAPI GetSystemInfo(LPSYSTEM_INFO);
WINBASEAPI BOOL        WINAPI GetSystemPowerStatus(LPSYSTEM_POWER_STATUS);
WINBASEAPI BOOL        WINAPI GetSystemRegistryQuota(PDWORD,PDWORD);
WINBASEAPI VOID        WINAPI GetSystemTime(LPSYSTEMTIME);
WINBASEAPI BOOL        WINAPI GetSystemTimeAdjustment(PDWORD,PDWORD,PBOOL);
WINBASEAPI VOID        WINAPI GetSystemTimeAsFileTime(LPFILETIME);
WINBASEAPI VOID        WINAPI GetSystemTimePreciseAsFileTime(LPFILETIME);
WINBASEAPI UINT        WINAPI GetSystemWindowsDirectoryA(LPSTR,UINT);
WINBASEAPI UINT        WINAPI GetSystemWindowsDirectoryW(LPWSTR,UINT);
#define                       GetSystemWindowsDirectory WINELIB_NAME_AW(GetSystemWindowsDirectory)
WINBASEAPI UINT        WINAPI GetSystemWow64DirectoryA(LPSTR,UINT);
WINBASEAPI UINT        WINAPI GetSystemWow64DirectoryW(LPWSTR,UINT);
#define                       GetSystemWow64Directory WINELIB_NAME_AW(GetSystemWow64Directory)
WINBASEAPI DWORD       WINAPI GetTapeParameters(HANDLE,DWORD,LPDWORD,LPVOID);
WINBASEAPI DWORD       WINAPI GetTapePosition(HANDLE,DWORD,LPDWORD,LPDWORD,LPDWORD);
WINBASEAPI DWORD       WINAPI GetTapeStatus(HANDLE);
WINBASEAPI UINT        WINAPI GetTempFileNameA(LPCSTR,LPCSTR,UINT,LPSTR);
WINBASEAPI UINT        WINAPI GetTempFileNameW(LPCWSTR,LPCWSTR,UINT,LPWSTR);
#define                       GetTempFileName WINELIB_NAME_AW(GetTempFileName)
WINBASEAPI DWORD       WINAPI GetTempPathA(DWORD,LPSTR);
WINBASEAPI DWORD       WINAPI GetTempPathW(DWORD,LPWSTR);
#define                       GetTempPath WINELIB_NAME_AW(GetTempPath)
WINBASEAPI DWORD       WINAPI GetThreadId(HANDLE);
WINBASEAPI BOOL        WINAPI GetThreadIOPendingFlag(HANDLE,PBOOL);
WINBASEAPI DWORD       WINAPI GetTickCount(void);
WINBASEAPI ULONGLONG   WINAPI GetTickCount64(void);
WINBASEAPI DWORD       WINAPI GetTimeZoneInformation(LPTIME_ZONE_INFORMATION);
WINBASEAPI BOOL        WINAPI GetThreadContext(HANDLE,CONTEXT *);
WINBASEAPI DWORD       WINAPI GetThreadErrorMode(void);
WINBASEAPI INT         WINAPI GetThreadPriority(HANDLE);
WINBASEAPI BOOL        WINAPI GetThreadPriorityBoost(HANDLE,PBOOL);
WINBASEAPI BOOL        WINAPI GetThreadSelectorEntry(HANDLE,DWORD,LPLDT_ENTRY);
WINBASEAPI BOOL        WINAPI GetThreadTimes(HANDLE,LPFILETIME,LPFILETIME,LPFILETIME,LPFILETIME);
WINADVAPI  BOOL        WINAPI GetTokenInformation(HANDLE,TOKEN_INFORMATION_CLASS,LPVOID,DWORD,LPDWORD);
WINADVAPI  BOOL        WINAPI GetUserNameA(LPSTR,LPDWORD);
WINADVAPI  BOOL        WINAPI GetUserNameW(LPWSTR,LPDWORD);
#define                       GetUserName WINELIB_NAME_AW(GetUserName)
WINBASEAPI DWORD       WINAPI GetVersion(void);
WINBASEAPI BOOL        WINAPI GetVersionExA(OSVERSIONINFOA*);
WINBASEAPI BOOL        WINAPI GetVersionExW(OSVERSIONINFOW*);
#define                       GetVersionEx WINELIB_NAME_AW(GetVersionEx)
WINBASEAPI BOOL        WINAPI GetVolumeInformationA(LPCSTR,LPSTR,DWORD,LPDWORD,LPDWORD,LPDWORD,LPSTR,DWORD);
WINBASEAPI BOOL        WINAPI GetVolumeInformationW(LPCWSTR,LPWSTR,DWORD,LPDWORD,LPDWORD,LPDWORD,LPWSTR,DWORD);
#define                       GetVolumeInformation WINELIB_NAME_AW(GetVolumeInformation)
WINBASEAPI BOOL        WINAPI GetVolumeInformationByHandleW(HANDLE,WCHAR *,DWORD,DWORD *,DWORD *,DWORD *,WCHAR *,DWORD);
WINBASEAPI BOOL        WINAPI GetVolumeNameForVolumeMountPointA(LPCSTR,LPSTR,DWORD);
WINBASEAPI BOOL        WINAPI GetVolumeNameForVolumeMountPointW(LPCWSTR,LPWSTR,DWORD);
#define                       GetVolumeNameForVolumeMountPoint WINELIB_NAME_AW(GetVolumeNameForVolumeMountPoint)
WINBASEAPI BOOL        WINAPI GetVolumePathNameA(LPCSTR,LPSTR,DWORD);
WINBASEAPI BOOL        WINAPI GetVolumePathNameW(LPCWSTR,LPWSTR,DWORD);
#define                       GetVolumePathName WINELIB_NAME_AW(GetVolumePathName)
WINBASEAPI BOOL        WINAPI GetVolumePathNamesForVolumeNameA(LPCSTR,LPSTR,DWORD,PDWORD);
WINBASEAPI BOOL        WINAPI GetVolumePathNamesForVolumeNameW(LPCWSTR,LPWSTR,DWORD,PDWORD);
#define                       GetVolumePathNamesForVolumeName WINELIB_NAME_AW(GetVolumePathNamesForVolumeName)
WINBASEAPI UINT        WINAPI GetWindowsDirectoryA(LPSTR,UINT);
WINBASEAPI UINT        WINAPI GetWindowsDirectoryW(LPWSTR,UINT);
#define                       GetWindowsDirectory WINELIB_NAME_AW(GetWindowsDirectory)
WINBASEAPI UINT        WINAPI GetWriteWatch(DWORD,LPVOID,SIZE_T,LPVOID*,ULONG_PTR*,ULONG*);
WINBASEAPI ATOM        WINAPI GlobalAddAtomA(LPCSTR);
WINBASEAPI ATOM        WINAPI GlobalAddAtomW(LPCWSTR);
#define                       GlobalAddAtom WINELIB_NAME_AW(GlobalAddAtom)
WINBASEAPI HGLOBAL     WINAPI GlobalAlloc(UINT,SIZE_T) __WINE_ALLOC_SIZE(2);
WINBASEAPI SIZE_T      WINAPI GlobalCompact(DWORD);
WINBASEAPI ATOM        WINAPI GlobalDeleteAtom(ATOM);
WINBASEAPI ATOM        WINAPI GlobalFindAtomA(LPCSTR);
WINBASEAPI ATOM        WINAPI GlobalFindAtomW(LPCWSTR);
#define                       GlobalFindAtom WINELIB_NAME_AW(GlobalFindAtom)
WINBASEAPI VOID        WINAPI GlobalFix(HGLOBAL);
WINBASEAPI UINT        WINAPI GlobalFlags(HGLOBAL);
WINBASEAPI HGLOBAL     WINAPI GlobalFree(HGLOBAL);
WINBASEAPI UINT        WINAPI GlobalGetAtomNameA(ATOM,LPSTR,INT);
WINBASEAPI UINT        WINAPI GlobalGetAtomNameW(ATOM,LPWSTR,INT);
#define                       GlobalGetAtomName WINELIB_NAME_AW(GlobalGetAtomName)
WINBASEAPI HGLOBAL     WINAPI GlobalHandle(LPCVOID);
WINBASEAPI LPVOID      WINAPI GlobalLock(HGLOBAL);
WINBASEAPI VOID        WINAPI GlobalMemoryStatus(LPMEMORYSTATUS);
WINBASEAPI BOOL        WINAPI GlobalMemoryStatusEx(LPMEMORYSTATUSEX);
WINBASEAPI HGLOBAL     WINAPI GlobalReAlloc(HGLOBAL,SIZE_T,UINT) __WINE_ALLOC_SIZE(2);
WINBASEAPI SIZE_T      WINAPI GlobalSize(HGLOBAL);
WINBASEAPI VOID        WINAPI GlobalUnfix(HGLOBAL);
WINBASEAPI BOOL        WINAPI GlobalUnlock(HGLOBAL);
WINBASEAPI BOOL        WINAPI GlobalUnWire(HGLOBAL);
WINBASEAPI LPVOID      WINAPI GlobalWire(HGLOBAL);
#define                       HasOverlappedIoCompleted(lpOverlapped) ((lpOverlapped)->Internal != STATUS_PENDING)
WINBASEAPI LPVOID      WINAPI HeapAlloc(HANDLE,DWORD,SIZE_T) __WINE_ALLOC_SIZE(3);
WINBASEAPI SIZE_T      WINAPI HeapCompact(HANDLE,DWORD);
WINBASEAPI HANDLE      WINAPI HeapCreate(DWORD,SIZE_T,SIZE_T);
WINBASEAPI BOOL        WINAPI HeapDestroy(HANDLE);
WINBASEAPI BOOL        WINAPI HeapFree(HANDLE,DWORD,LPVOID);
WINBASEAPI BOOL        WINAPI HeapLock(HANDLE);
WINBASEAPI LPVOID      WINAPI HeapReAlloc(HANDLE,DWORD,LPVOID,SIZE_T) __WINE_ALLOC_SIZE(4);
WINBASEAPI BOOL        WINAPI HeapQueryInformation(HANDLE,HEAP_INFORMATION_CLASS,PVOID,SIZE_T,PSIZE_T);
WINBASEAPI BOOL        WINAPI HeapSetInformation(HANDLE,HEAP_INFORMATION_CLASS,PVOID,SIZE_T);
WINBASEAPI SIZE_T      WINAPI HeapSize(HANDLE,DWORD,LPCVOID);
WINBASEAPI BOOL        WINAPI HeapUnlock(HANDLE);
WINBASEAPI BOOL        WINAPI HeapValidate(HANDLE,DWORD,LPCVOID);
WINBASEAPI BOOL        WINAPI HeapWalk(HANDLE,LPPROCESS_HEAP_ENTRY);
WINBASEAPI BOOL        WINAPI InitAtomTable(DWORD);
WINADVAPI  BOOL        WINAPI InitializeAcl(PACL,DWORD,DWORD);
WINBASEAPI VOID        WINAPI InitializeConditionVariable(PCONDITION_VARIABLE);
WINBASEAPI void        WINAPI InitializeCriticalSection(CRITICAL_SECTION *lpCrit);
WINBASEAPI BOOL        WINAPI InitializeCriticalSectionAndSpinCount(CRITICAL_SECTION *,DWORD);
WINBASEAPI BOOL        WINAPI InitializeCriticalSectionEx(CRITICAL_SECTION *,DWORD,DWORD);
WINBASEAPI BOOL        WINAPI InitializeProcThreadAttributeList(struct _PROC_THREAD_ATTRIBUTE_LIST*,DWORD,DWORD,SIZE_T*);
WINADVAPI  BOOL        WINAPI InitializeSecurityDescriptor(PSECURITY_DESCRIPTOR,DWORD);
WINADVAPI  BOOL        WINAPI InitializeSid(PSID,PSID_IDENTIFIER_AUTHORITY,BYTE);
WINBASEAPI VOID        WINAPI InitializeSListHead(PSLIST_HEADER);
WINBASEAPI VOID        WINAPI InitializeSRWLock(PSRWLOCK);
WINBASEAPI BOOL        WINAPI InitOnceBeginInitialize(PINIT_ONCE, DWORD, PBOOL, PVOID*);
WINBASEAPI BOOL        WINAPI InitOnceComplete(PINIT_ONCE, DWORD, PVOID);
WINBASEAPI BOOL        WINAPI InitOnceExecuteOnce(PINIT_ONCE,PINIT_ONCE_FN,PVOID,PVOID*);
WINBASEAPI VOID        WINAPI InitOnceInitialize(PINIT_ONCE);
WINBASEAPI PSLIST_ENTRY WINAPI InterlockedFlushSList(PSLIST_HEADER);
WINBASEAPI PSLIST_ENTRY WINAPI InterlockedPopEntrySList(PSLIST_HEADER);
WINBASEAPI PSLIST_ENTRY WINAPI InterlockedPushEntrySList(PSLIST_HEADER, PSLIST_ENTRY);
WINBASEAPI BOOL        WINAPI IsBadCodePtr(FARPROC);
WINBASEAPI BOOL        WINAPI IsBadHugeReadPtr(LPCVOID,UINT_PTR);
WINBASEAPI BOOL        WINAPI IsBadHugeWritePtr(LPVOID,UINT_PTR);
WINBASEAPI BOOL        WINAPI IsBadReadPtr(LPCVOID,UINT_PTR);
WINBASEAPI BOOL        WINAPI IsBadStringPtrA(LPCSTR,UINT_PTR);
WINBASEAPI BOOL        WINAPI IsBadStringPtrW(LPCWSTR,UINT_PTR);
#define                       IsBadStringPtr WINELIB_NAME_AW(IsBadStringPtr)
WINBASEAPI BOOL        WINAPI IsBadWritePtr(LPVOID,UINT_PTR);
WINBASEAPI BOOL        WINAPI IsDebuggerPresent(void);
WINBASEAPI BOOL        WINAPI IsSystemResumeAutomatic(void);
WINADVAPI  BOOL        WINAPI IsTextUnicode(LPCVOID,INT,LPINT);
WINADVAPI  BOOL        WINAPI IsTokenRestricted(HANDLE);
WINADVAPI  BOOL        WINAPI IsValidAcl(PACL);
WINADVAPI  BOOL        WINAPI IsValidSecurityDescriptor(PSECURITY_DESCRIPTOR);
WINADVAPI  BOOL        WINAPI IsValidSid(PSID);
WINADVAPI  BOOL        WINAPI IsWellKnownSid(PSID,WELL_KNOWN_SID_TYPE);
WINBASEAPI BOOL        WINAPI IsWow64Process(HANDLE,PBOOL);
WINADVAPI  BOOL        WINAPI ImpersonateLoggedOnUser(HANDLE);
WINADVAPI  BOOL        WINAPI ImpersonateNamedPipeClient(HANDLE);
WINADVAPI  BOOL        WINAPI ImpersonateSelf(SECURITY_IMPERSONATION_LEVEL);
WINBASEAPI BOOL        WINAPI IsProcessInJob(HANDLE,HANDLE,PBOOL);
WINBASEAPI BOOL        WINAPI IsProcessorFeaturePresent(DWORD);
WINBASEAPI void        WINAPI LeaveCriticalSection(CRITICAL_SECTION *lpCrit);
WINBASEAPI HMODULE     WINAPI LoadLibraryA(LPCSTR);
WINBASEAPI HMODULE     WINAPI LoadLibraryW(LPCWSTR);
#define                       LoadLibrary WINELIB_NAME_AW(LoadLibrary)
WINBASEAPI HMODULE     WINAPI LoadLibraryExA(LPCSTR,HANDLE,DWORD);
WINBASEAPI HMODULE     WINAPI LoadLibraryExW(LPCWSTR,HANDLE,DWORD);
#define                       LoadLibraryEx WINELIB_NAME_AW(LoadLibraryEx)
WINBASEAPI DWORD       WINAPI LoadModule(LPCSTR,LPVOID);
WINBASEAPI HGLOBAL     WINAPI LoadResource(HMODULE,HRSRC);
WINBASEAPI HLOCAL      WINAPI LocalAlloc(UINT,SIZE_T) __WINE_ALLOC_SIZE(2);
WINBASEAPI SIZE_T      WINAPI LocalCompact(UINT);
WINBASEAPI UINT        WINAPI LocalFlags(HLOCAL);
WINBASEAPI HLOCAL      WINAPI LocalFree(HLOCAL);
WINBASEAPI HLOCAL      WINAPI LocalHandle(LPCVOID);
WINBASEAPI LPVOID      WINAPI LocalLock(HLOCAL);
WINBASEAPI HLOCAL      WINAPI LocalReAlloc(HLOCAL,SIZE_T,UINT) __WINE_ALLOC_SIZE(2);
WINBASEAPI SIZE_T      WINAPI LocalShrink(HGLOBAL,UINT);
WINBASEAPI SIZE_T      WINAPI LocalSize(HLOCAL);
WINBASEAPI BOOL        WINAPI LocalUnlock(HLOCAL);
WINBASEAPI LPVOID      WINAPI LockResource(HGLOBAL);
#define                       LockSegment(handle) GlobalFix((HANDLE)(handle))
WINADVAPI  BOOL        WINAPI LookupAccountNameA(LPCSTR,LPCSTR,PSID,LPDWORD,LPSTR,LPDWORD,PSID_NAME_USE);
WINADVAPI  BOOL        WINAPI LookupAccountNameW(LPCWSTR,LPCWSTR,PSID,LPDWORD,LPWSTR,LPDWORD,PSID_NAME_USE);
#define                       LookupAccountName WINELIB_NAME_AW(LookupAccountName)
WINADVAPI  BOOL        WINAPI LookupAccountSidA(LPCSTR,PSID,LPSTR,LPDWORD,LPSTR,LPDWORD,PSID_NAME_USE);
WINADVAPI  BOOL        WINAPI LookupAccountSidW(LPCWSTR,PSID,LPWSTR,LPDWORD,LPWSTR,LPDWORD,PSID_NAME_USE);
#define                       LookupAccountSid WINELIB_NAME_AW(LookupAccountSid)
WINBASEAPI BOOL        WINAPI LocalFileTimeToFileTime(const FILETIME*,LPFILETIME);
WINBASEAPI BOOL        WINAPI LockFile(HANDLE,DWORD,DWORD,DWORD,DWORD);
WINBASEAPI BOOL        WINAPI LockFileEx(HANDLE, DWORD, DWORD, DWORD, DWORD, LPOVERLAPPED);
WINADVAPI  BOOL        WINAPI LogonUserA(LPCSTR,LPCSTR,LPCSTR,DWORD,DWORD,PHANDLE);
WINADVAPI  BOOL        WINAPI LogonUserW(LPCWSTR,LPCWSTR,LPCWSTR,DWORD,DWORD,PHANDLE);
#define                       LogonUser WINELIB_NAME_AW(LogonUser)
WINADVAPI  BOOL        WINAPI LookupPrivilegeDisplayNameA(LPCSTR,LPCSTR,LPSTR,LPDWORD,LPDWORD);
WINADVAPI  BOOL        WINAPI LookupPrivilegeDisplayNameW(LPCWSTR,LPCWSTR,LPWSTR,LPDWORD,LPDWORD);
#define                       LookupPrivilegeDisplayName WINELIB_NAME_AW(LookupPrivilegeDisplayName)
WINADVAPI  BOOL        WINAPI LookupPrivilegeNameA(LPCSTR,PLUID,LPSTR,LPDWORD);
WINADVAPI  BOOL        WINAPI LookupPrivilegeNameW(LPCWSTR,PLUID,LPWSTR,LPDWORD);
#define                       LookupPrivilegeName WINELIB_NAME_AW(LookupPrivilegeName)
WINADVAPI  BOOL        WINAPI LookupPrivilegeValueA(LPCSTR,LPCSTR,PLUID);
WINADVAPI  BOOL        WINAPI LookupPrivilegeValueW(LPCWSTR,LPCWSTR,PLUID);
#define                       LookupPrivilegeValue WINELIB_NAME_AW(LookupPrivilegeValue)
WINADVAPI  BOOL        WINAPI MakeAbsoluteSD(PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR,LPDWORD,PACL,LPDWORD,PACL,LPDWORD,PSID,LPDWORD,PSID,LPDWORD);
WINBASEAPI void        WINAPI MakeCriticalSectionGlobal(CRITICAL_SECTION *lpCrit);
#define                       MakeProcInstance(proc,inst) (proc)
WINADVAPI  BOOL        WINAPI MakeSelfRelativeSD(PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR,LPDWORD);
WINADVAPI  VOID        WINAPI MapGenericMask(PDWORD,PGENERIC_MAPPING);
WINBASEAPI HMODULE     WINAPI MapHModuleSL(WORD);
WINBASEAPI WORD        WINAPI MapHModuleLS(HMODULE);
WINBASEAPI LPVOID      WINAPI MapViewOfFile(HANDLE,DWORD,DWORD,DWORD,SIZE_T);
WINBASEAPI LPVOID      WINAPI MapViewOfFileEx(HANDLE,DWORD,DWORD,DWORD,SIZE_T,LPVOID);
WINBASEAPI BOOL        WINAPI MoveFileA(LPCSTR,LPCSTR);
WINBASEAPI BOOL        WINAPI MoveFileW(LPCWSTR,LPCWSTR);
#define                       MoveFile WINELIB_NAME_AW(MoveFile)
WINBASEAPI BOOL        WINAPI MoveFileExA(LPCSTR,LPCSTR,DWORD);
WINBASEAPI BOOL        WINAPI MoveFileExW(LPCWSTR,LPCWSTR,DWORD);
#define                       MoveFileEx WINELIB_NAME_AW(MoveFileEx)
WINBASEAPI BOOL        WINAPI MoveFileWithProgressA(LPCSTR,LPCSTR,LPPROGRESS_ROUTINE,LPVOID,DWORD);
WINBASEAPI BOOL        WINAPI MoveFileWithProgressW(LPCWSTR,LPCWSTR,LPPROGRESS_ROUTINE,LPVOID,DWORD);
#define                       MoveFileWithProgress WINELIB_NAME_AW(MoveFileWithProgress)
WINBASEAPI INT         WINAPI MulDiv(INT,INT,INT);
WINBASEAPI BOOL        WINAPI NeedCurrentDirectoryForExePathA(LPCSTR);
WINBASEAPI BOOL        WINAPI NeedCurrentDirectoryForExePathW(LPCWSTR);
#define                       NeedCurrentDirectoryForExePath WINELIB_NAME_AW(NeedCurrentDirectoryForExePath)
WINADVAPI  BOOL        WINAPI NotifyChangeEventLog(HANDLE,HANDLE);
WINADVAPI  BOOL        WINAPI ObjectCloseAuditAlarmA(LPCSTR,LPVOID,BOOL);
WINADVAPI  BOOL        WINAPI ObjectCloseAuditAlarmW(LPCWSTR,LPVOID,BOOL);
#define                       ObjectCloseAuditAlarm WINELIB_NAME_AW(ObjectCloseAuditAlarm)
WINADVAPI  BOOL        WINAPI ObjectDeleteAuditAlarmA(LPCSTR,LPVOID,BOOL);
WINADVAPI  BOOL        WINAPI ObjectDeleteAuditAlarmW(LPCWSTR,LPVOID,BOOL);
#define                       ObjectDeleteAuditAlarm WINELIB_NAME_AW(ObjectDeleteAuditAlarm)
WINADVAPI  BOOL        WINAPI ObjectOpenAuditAlarmA(LPCSTR,LPVOID,LPSTR,LPSTR,PSECURITY_DESCRIPTOR,HANDLE,DWORD,DWORD,PPRIVILEGE_SET,BOOL,BOOL,LPBOOL);
WINADVAPI  BOOL        WINAPI ObjectOpenAuditAlarmW(LPCWSTR,LPVOID,LPWSTR,LPWSTR,PSECURITY_DESCRIPTOR,HANDLE,DWORD,DWORD,PPRIVILEGE_SET,BOOL,BOOL,LPBOOL);
#define                       ObjectOpenAuditAlarm WINELIB_NAME_AW(ObjectOpenAuditAlarm)
WINADVAPI  BOOL        WINAPI ObjectPrivilegeAuditAlarmA(LPCSTR,LPVOID,HANDLE,DWORD,PPRIVILEGE_SET,BOOL);
WINADVAPI  BOOL        WINAPI ObjectPrivilegeAuditAlarmW(LPCWSTR,LPVOID,HANDLE,DWORD,PPRIVILEGE_SET,BOOL);
#define                       ObjectPrivilegeAuditAlarm WINELIB_NAME_AW(ObjectPrivilegeAuditAlarm)
WINADVAPI  HANDLE      WINAPI OpenBackupEventLogA(LPCSTR,LPCSTR);
WINADVAPI  HANDLE      WINAPI OpenBackupEventLogW(LPCWSTR,LPCWSTR);
#define                       OpenBackupEventLog WINELIB_NAME_AW(OpenBackupEventLog)
WINADVAPI  DWORD       WINAPI OpenEncryptedFileRawA(LPCSTR,ULONG,PVOID*);
WINADVAPI  DWORD       WINAPI OpenEncryptedFileRawW(LPCWSTR,ULONG,PVOID*);
#define                       OpenEncryptedFileRaw WINELIB_NAME_AW(OpenEncryptedFileRaw)
WINBASEAPI HANDLE      WINAPI OpenEventA(DWORD,BOOL,LPCSTR);
WINBASEAPI HANDLE      WINAPI OpenEventW(DWORD,BOOL,LPCWSTR);
#define                       OpenEvent WINELIB_NAME_AW(OpenEvent)
WINADVAPI  HANDLE      WINAPI OpenEventLogA(LPCSTR,LPCSTR);
WINADVAPI  HANDLE      WINAPI OpenEventLogW(LPCWSTR,LPCWSTR);
#define                       OpenEventLog WINELIB_NAME_AW(OpenEventLog)
WINBASEAPI HFILE       WINAPI OpenFile(LPCSTR,OFSTRUCT*,UINT);
WINBASEAPI HANDLE      WINAPI OpenFileMappingA(DWORD,BOOL,LPCSTR);
WINBASEAPI HANDLE      WINAPI OpenFileMappingW(DWORD,BOOL,LPCWSTR);
#define                       OpenFileMapping WINELIB_NAME_AW(OpenFileMapping)
WINBASEAPI HANDLE      WINAPI OpenJobObjectA(DWORD,BOOL,LPCSTR);
WINBASEAPI HANDLE      WINAPI OpenJobObjectW(DWORD,BOOL,LPCWSTR);
#define                       OpenJobObject WINELIB_NAME_AW(OpenJobObject)
WINBASEAPI HANDLE      WINAPI OpenMutexA(DWORD,BOOL,LPCSTR);
WINBASEAPI HANDLE      WINAPI OpenMutexW(DWORD,BOOL,LPCWSTR);
#define                       OpenMutex WINELIB_NAME_AW(OpenMutex)
WINBASEAPI HANDLE      WINAPI OpenProcess(DWORD,BOOL,DWORD);
WINADVAPI  BOOL        WINAPI OpenProcessToken(HANDLE,DWORD,PHANDLE);
WINBASEAPI HANDLE      WINAPI OpenSemaphoreA(DWORD,BOOL,LPCSTR);
WINBASEAPI HANDLE      WINAPI OpenSemaphoreW(DWORD,BOOL,LPCWSTR);
#define                       OpenSemaphore WINELIB_NAME_AW(OpenSemaphore)
WINBASEAPI HANDLE      WINAPI OpenThread(DWORD,BOOL,DWORD);
WINADVAPI  BOOL        WINAPI OpenThreadToken(HANDLE,DWORD,BOOL,PHANDLE);
WINBASEAPI HANDLE      WINAPI OpenWaitableTimerA(DWORD,BOOL,LPCSTR);
WINBASEAPI HANDLE      WINAPI OpenWaitableTimerW(DWORD,BOOL,LPCWSTR);
#define                       OpenWaitableTimer WINELIB_NAME_AW(OpenWaitableTimer)
WINBASEAPI VOID        WINAPI OutputDebugStringA(LPCSTR);
WINBASEAPI VOID        WINAPI OutputDebugStringW(LPCWSTR);
#define                       OutputDebugString WINELIB_NAME_AW(OutputDebugString)
WINBASEAPI BOOL        WINAPI PeekNamedPipe(HANDLE,PVOID,DWORD,PDWORD,PDWORD,PDWORD);
WINBASEAPI BOOL        WINAPI PostQueuedCompletionStatus(HANDLE,DWORD,ULONG_PTR,LPOVERLAPPED);
WINBASEAPI DWORD       WINAPI PrepareTape(HANDLE,DWORD,BOOL);
WINBASEAPI BOOL        WINAPI ProcessIdToSessionId(DWORD,DWORD*);
WINADVAPI  BOOL        WINAPI PrivilegeCheck(HANDLE,PPRIVILEGE_SET,LPBOOL);
WINADVAPI  BOOL        WINAPI PrivilegedServiceAuditAlarmA(LPCSTR,LPCSTR,HANDLE,PPRIVILEGE_SET,BOOL);
WINADVAPI  BOOL        WINAPI PrivilegedServiceAuditAlarmW(LPCWSTR,LPCWSTR,HANDLE,PPRIVILEGE_SET,BOOL);
#define                       PrivilegedServiceAuditAlarm WINELIB_NAME_AW(PrivilegedServiceAuditAlarm)
WINBASEAPI BOOL        WINAPI PulseEvent(HANDLE);
WINBASEAPI BOOL        WINAPI PurgeComm(HANDLE,DWORD);
WINBASEAPI BOOL        WINAPI QueryActCtxW(DWORD,HANDLE,PVOID,ULONG,PVOID,SIZE_T,SIZE_T *);
WINBASEAPI USHORT      WINAPI QueryDepthSList(PSLIST_HEADER);
WINBASEAPI DWORD       WINAPI QueryDosDeviceA(LPCSTR,LPSTR,DWORD);
WINBASEAPI DWORD       WINAPI QueryDosDeviceW(LPCWSTR,LPWSTR,DWORD);
#define                       QueryDosDevice WINELIB_NAME_AW(QueryDosDevice)
WINBASEAPI BOOL        WINAPI QueryFullProcessImageNameA(HANDLE,DWORD,LPSTR,PDWORD);
WINBASEAPI BOOL        WINAPI QueryFullProcessImageNameW(HANDLE,DWORD,LPWSTR,PDWORD);
#define                       QueryFullProcessImageName WINELIB_NAME_AW(QueryFullProcessImageName)
WINBASEAPI BOOL        WINAPI QueryInformationJobObject(HANDLE,JOBOBJECTINFOCLASS,LPVOID,DWORD,DWORD*);
WINBASEAPI BOOL        WINAPI QueryMemoryResourceNotification(HANDLE,PBOOL);
WINBASEAPI BOOL        WINAPI QueryPerformanceCounter(LARGE_INTEGER*);
WINBASEAPI BOOL        WINAPI QueryPerformanceFrequency(LARGE_INTEGER*);
WINBASEAPI BOOL        WINAPI QueryThreadCycleTime(HANDLE,PULONG64);
WINBASEAPI DWORD       WINAPI QueueUserAPC(PAPCFUNC,HANDLE,ULONG_PTR);
WINBASEAPI BOOL        WINAPI QueueUserWorkItem(LPTHREAD_START_ROUTINE,PVOID,ULONG);
WINBASEAPI void        WINAPI RaiseException(DWORD,DWORD,DWORD,const ULONG_PTR *);
WINADVAPI  BOOL        WINAPI ReadEventLogA(HANDLE,DWORD,DWORD,LPVOID,DWORD,DWORD *,DWORD *);
WINADVAPI  BOOL        WINAPI ReadEventLogW(HANDLE,DWORD,DWORD,LPVOID,DWORD,DWORD *,DWORD *);
#define                       ReadEventLog WINELIB_NAME_AW(ReadEventLog)
WINBASEAPI BOOL        WINAPI ReadDirectoryChangesW(HANDLE,LPVOID,DWORD,BOOL,DWORD,LPDWORD,LPOVERLAPPED,LPOVERLAPPED_COMPLETION_ROUTINE);
WINADVAPI  DWORD       WINAPI ReadEncryptedFileRaw(PFE_EXPORT_FUNC,PVOID,PVOID);
WINBASEAPI BOOL        WINAPI ReadFile(HANDLE,LPVOID,DWORD,LPDWORD,LPOVERLAPPED);
WINBASEAPI BOOL        WINAPI ReadFileEx(HANDLE,LPVOID,DWORD,LPOVERLAPPED,LPOVERLAPPED_COMPLETION_ROUTINE);
WINBASEAPI BOOL        WINAPI ReadFileScatter(HANDLE,FILE_SEGMENT_ELEMENT*,DWORD,LPDWORD,LPOVERLAPPED);
WINBASEAPI BOOL        WINAPI ReadProcessMemory(HANDLE,LPCVOID,LPVOID,SIZE_T,SIZE_T*);
WINADVAPI  HANDLE      WINAPI RegisterEventSourceA(LPCSTR,LPCSTR);
WINADVAPI  HANDLE      WINAPI RegisterEventSourceW(LPCWSTR,LPCWSTR);
#define                       RegisterEventSource WINELIB_NAME_AW(RegisterEventSource)
WINBASEAPI BOOL        WINAPI RegisterWaitForSingleObject(PHANDLE,HANDLE,WAITORTIMERCALLBACK,PVOID,ULONG,ULONG);
WINBASEAPI HANDLE      WINAPI RegisterWaitForSingleObjectEx(HANDLE,WAITORTIMERCALLBACK,PVOID,ULONG,ULONG);
WINBASEAPI VOID        WINAPI ReleaseActCtx(HANDLE);
WINBASEAPI BOOL        WINAPI ReleaseMutex(HANDLE);
WINBASEAPI BOOL        WINAPI ReleaseSemaphore(HANDLE,LONG,LPLONG);
WINBASEAPI VOID        WINAPI ReleaseSRWLockExclusive(PSRWLOCK);
WINBASEAPI VOID        WINAPI ReleaseSRWLockShared(PSRWLOCK);
WINBASEAPI ULONG       WINAPI RemoveVectoredExceptionHandler(PVOID);
WINBASEAPI BOOL        WINAPI ReplaceFileA(LPCSTR,LPCSTR,LPCSTR,DWORD,LPVOID,LPVOID);
WINBASEAPI BOOL        WINAPI ReplaceFileW(LPCWSTR,LPCWSTR,LPCWSTR,DWORD,LPVOID,LPVOID);
#define                       ReplaceFile WINELIB_NAME_AW(ReplaceFile)
WINBASEAPI BOOL        WINAPI RemoveDirectoryA(LPCSTR);
WINBASEAPI BOOL        WINAPI RemoveDirectoryW(LPCWSTR);
#define                       RemoveDirectory WINELIB_NAME_AW(RemoveDirectory)
WINADVAPI  BOOL        WINAPI ReportEventA(HANDLE,WORD,WORD,DWORD,PSID,WORD,DWORD,LPCSTR *,LPVOID);
WINADVAPI  BOOL        WINAPI ReportEventW(HANDLE,WORD,WORD,DWORD,PSID,WORD,DWORD,LPCWSTR *,LPVOID);
WINBASEAPI BOOL        WINAPI RequestWakeupLatency(LATENCY_TIME latency);
#define                       ReportEvent WINELIB_NAME_AW(ReportEvent)
WINBASEAPI BOOL        WINAPI ResetEvent(HANDLE);
WINBASEAPI UINT        WINAPI ResetWriteWatch(LPVOID,SIZE_T);
WINBASEAPI DWORD       WINAPI ResumeThread(HANDLE);
WINADVAPI  BOOL        WINAPI RevertToSelf(void);
WINBASEAPI DWORD       WINAPI SearchPathA(LPCSTR,LPCSTR,LPCSTR,DWORD,LPSTR,LPSTR*);
WINBASEAPI DWORD       WINAPI SearchPathW(LPCWSTR,LPCWSTR,LPCWSTR,DWORD,LPWSTR,LPWSTR*);
#define                       SearchPath WINELIB_NAME_AW(SearchPath)
WINADVAPI  BOOL        WINAPI SetAclInformation(PACL,LPVOID,DWORD,ACL_INFORMATION_CLASS);
WINBASEAPI BOOL        WINAPI SetCommConfig(HANDLE,LPCOMMCONFIG,DWORD);
WINBASEAPI BOOL        WINAPI SetCommBreak(HANDLE);
WINBASEAPI BOOL        WINAPI SetCommMask(HANDLE,DWORD);
WINBASEAPI BOOL        WINAPI SetCommState(HANDLE,LPDCB);
WINBASEAPI BOOL        WINAPI SetCommTimeouts(HANDLE,LPCOMMTIMEOUTS);
WINBASEAPI BOOL        WINAPI SetComputerNameA(LPCSTR);
WINBASEAPI BOOL        WINAPI SetComputerNameW(LPCWSTR);
#define                       SetComputerName WINELIB_NAME_AW(SetComputerName)
WINBASEAPI BOOL        WINAPI SetComputerNameExA(COMPUTER_NAME_FORMAT,LPCSTR);
WINBASEAPI BOOL        WINAPI SetComputerNameExW(COMPUTER_NAME_FORMAT,LPCWSTR);
#define                       SetComputerNameEx WINELIB_NAME_AW(SetComputerNameEx)
WINBASEAPI DWORD       WINAPI SetCriticalSectionSpinCount(LPCRITICAL_SECTION,DWORD);
WINBASEAPI BOOL        WINAPI SetCurrentDirectoryA(LPCSTR);
WINBASEAPI BOOL        WINAPI SetCurrentDirectoryW(LPCWSTR);
#define                       SetCurrentDirectory WINELIB_NAME_AW(SetCurrentDirectory)
WINBASEAPI BOOL        WINAPI SetDefaultCommConfigA(LPCSTR,LPCOMMCONFIG,DWORD);
WINBASEAPI BOOL        WINAPI SetDefaultCommConfigW(LPCWSTR,LPCOMMCONFIG,DWORD);
#define                       SetDefaultCommConfig WINELIB_NAME_AW(SetDefaultCommConfig)
WINBASEAPI BOOL        WINAPI SetDllDirectoryA(LPCSTR);
WINBASEAPI BOOL        WINAPI SetDllDirectoryW(LPCWSTR);
#define                       SetDllDirectory WINELIB_NAME_AW(SetDllDirectory)
WINBASEAPI BOOL        WINAPI SetDynamicTimeZoneInformation(const DYNAMIC_TIME_ZONE_INFORMATION*);
WINBASEAPI BOOL        WINAPI SetEndOfFile(HANDLE);
WINBASEAPI BOOL        WINAPI SetEnvironmentVariableA(LPCSTR,LPCSTR);
WINBASEAPI BOOL        WINAPI SetEnvironmentVariableW(LPCWSTR,LPCWSTR);
#define                       SetEnvironmentVariable WINELIB_NAME_AW(SetEnvironmentVariable)
WINBASEAPI UINT        WINAPI SetErrorMode(UINT);
WINBASEAPI BOOL        WINAPI SetEvent(HANDLE);
WINBASEAPI VOID        WINAPI SetFileApisToANSI(void);
WINBASEAPI VOID        WINAPI SetFileApisToOEM(void);
WINBASEAPI BOOL        WINAPI SetFileAttributesA(LPCSTR,DWORD);
WINBASEAPI BOOL        WINAPI SetFileAttributesW(LPCWSTR,DWORD);
#define                       SetFileAttributes WINELIB_NAME_AW(SetFileAttributes)
WINBASEAPI BOOL        WINAPI SetFileCompletionNotificationModes(HANDLE,UCHAR);
WINBASEAPI BOOL        WINAPI SetFileInformationByHandle(HANDLE,FILE_INFO_BY_HANDLE_CLASS,LPVOID,DWORD);
WINBASEAPI DWORD       WINAPI SetFilePointer(HANDLE,LONG,LPLONG,DWORD);
WINBASEAPI BOOL        WINAPI SetFilePointerEx(HANDLE,LARGE_INTEGER,LARGE_INTEGER*,DWORD);
WINADVAPI  BOOL        WINAPI SetFileSecurityA(LPCSTR,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR);
WINADVAPI  BOOL        WINAPI SetFileSecurityW(LPCWSTR,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR);
#define                       SetFileSecurity WINELIB_NAME_AW(SetFileSecurity)
WINBASEAPI BOOL        WINAPI SetFileTime(HANDLE,const FILETIME*,const FILETIME*,const FILETIME*);
WINBASEAPI BOOL        WINAPI SetFileValidData(HANDLE,LONGLONG);
WINBASEAPI UINT        WINAPI SetHandleCount(UINT);
WINBASEAPI BOOL        WINAPI SetHandleInformation(HANDLE,DWORD,DWORD);
WINBASEAPI BOOL        WINAPI SetInformationJobObject(HANDLE,JOBOBJECTINFOCLASS,LPVOID,DWORD);
WINADVAPI  BOOL        WINAPI SetKernelObjectSecurity(HANDLE,SECURITY_INFORMATION,PSECURITY_DESCRIPTOR);
WINBASEAPI BOOL        WINAPI SetLocalTime(const SYSTEMTIME*);
WINBASEAPI BOOL        WINAPI SetMailslotInfo(HANDLE,DWORD);
WINBASEAPI BOOL        WINAPI SetNamedPipeHandleState(HANDLE,LPDWORD,LPDWORD,LPDWORD);
WINBASEAPI BOOL        WINAPI SetPriorityClass(HANDLE,DWORD);
WINADVAPI  BOOL        WINAPI SetPrivateObjectSecurity(SECURITY_INFORMATION,PSECURITY_DESCRIPTOR,PSECURITY_DESCRIPTOR*,PGENERIC_MAPPING,HANDLE);
WINBASEAPI BOOL        WINAPI SetProcessAffinityMask(HANDLE,DWORD_PTR);
WINBASEAPI BOOL        WINAPI SetProcessPriorityBoost(HANDLE,BOOL);
WINBASEAPI BOOL        WINAPI SetProcessShutdownParameters(DWORD,DWORD);
WINBASEAPI BOOL        WINAPI SetProcessWorkingSetSize(HANDLE,SIZE_T,SIZE_T);
WINBASEAPI BOOL        WINAPI SetSearchPathMode(DWORD);
WINADVAPI  BOOL        WINAPI SetSecurityDescriptorControl(PSECURITY_DESCRIPTOR,SECURITY_DESCRIPTOR_CONTROL,SECURITY_DESCRIPTOR_CONTROL);
WINADVAPI  BOOL        WINAPI SetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR,BOOL,PACL,BOOL);
WINADVAPI  BOOL        WINAPI SetSecurityDescriptorGroup(PSECURITY_DESCRIPTOR,PSID,BOOL);
WINADVAPI  BOOL        WINAPI SetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR,PSID,BOOL);
WINADVAPI  BOOL        WINAPI SetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR,BOOL,PACL,BOOL);
WINBASEAPI BOOL        WINAPI SetStdHandle(DWORD,HANDLE);
#define                       SetSwapAreaSize(w) (w)
WINBASEAPI BOOL        WINAPI SetSystemPowerState(BOOL,BOOL);
WINBASEAPI BOOL        WINAPI SetSystemTime(const SYSTEMTIME*);
WINBASEAPI BOOL        WINAPI SetSystemTimeAdjustment(DWORD,BOOL);
WINBASEAPI DWORD       WINAPI SetTapeParameters(HANDLE,DWORD,LPVOID);
WINBASEAPI DWORD       WINAPI SetTapePosition(HANDLE,DWORD,DWORD,DWORD,DWORD,BOOL);
WINBASEAPI DWORD_PTR   WINAPI SetThreadAffinityMask(HANDLE,DWORD_PTR);
WINBASEAPI BOOL        WINAPI SetThreadContext(HANDLE,const CONTEXT *);
WINBASEAPI BOOL        WINAPI SetThreadErrorMode(DWORD,LPDWORD);
WINBASEAPI DWORD       WINAPI SetThreadExecutionState(EXECUTION_STATE);
WINBASEAPI DWORD       WINAPI SetThreadIdealProcessor(HANDLE,DWORD);
WINBASEAPI BOOL        WINAPI SetThreadPriority(HANDLE,INT);
WINBASEAPI BOOL        WINAPI SetThreadPriorityBoost(HANDLE,BOOL);
WINADVAPI  BOOL        WINAPI SetThreadToken(PHANDLE,HANDLE);
WINBASEAPI VOID        WINAPI SetThreadpoolTimer(PTP_TIMER,FILETIME*,DWORD,DWORD);
WINBASEAPI VOID        WINAPI SetThreadpoolWait(PTP_WAIT,HANDLE,FILETIME *);
WINBASEAPI HANDLE      WINAPI SetTimerQueueTimer(HANDLE,WAITORTIMERCALLBACK,PVOID,DWORD,DWORD,BOOL);
WINBASEAPI BOOL        WINAPI SetTimeZoneInformation(const TIME_ZONE_INFORMATION *);
WINADVAPI  BOOL        WINAPI SetTokenInformation(HANDLE,TOKEN_INFORMATION_CLASS,LPVOID,DWORD);
WINBASEAPI LPTOP_LEVEL_EXCEPTION_FILTER WINAPI SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER);
WINBASEAPI BOOL        WINAPI SetVolumeLabelA(LPCSTR,LPCSTR);
WINBASEAPI BOOL        WINAPI SetVolumeLabelW(LPCWSTR,LPCWSTR);
#define                       SetVolumeLabel WINELIB_NAME_AW(SetVolumeLabel)
WINBASEAPI BOOL        WINAPI SetVolumeMountPointA(LPCSTR,LPCSTR);
WINBASEAPI BOOL        WINAPI SetVolumeMountPointW(LPCWSTR,LPCWSTR);
#define                       SetVolumeMountPoint WINELIB_NAME_AW(SetVolumeMountPoint)
WINBASEAPI BOOL        WINAPI SetWaitableTimer(HANDLE,const LARGE_INTEGER*,LONG,PTIMERAPCROUTINE,LPVOID,BOOL);
WINBASEAPI BOOL        WINAPI SetWaitableTimerEx(HANDLE,const LARGE_INTEGER*,LONG,PTIMERAPCROUTINE,LPVOID,REASON_CONTEXT*,ULONG);
WINBASEAPI BOOL        WINAPI SetupComm(HANDLE,DWORD,DWORD);
WINBASEAPI DWORD       WINAPI SignalObjectAndWait(HANDLE,HANDLE,DWORD,BOOL);
WINBASEAPI DWORD       WINAPI SizeofResource(HMODULE,HRSRC);
WINBASEAPI VOID        WINAPI Sleep(DWORD);
WINBASEAPI BOOL        WINAPI SleepConditionVariableCS(PCONDITION_VARIABLE,PCRITICAL_SECTION,DWORD);
WINBASEAPI BOOL        WINAPI SleepConditionVariableSRW(PCONDITION_VARIABLE,PSRWLOCK,DWORD,ULONG);
WINBASEAPI DWORD       WINAPI SleepEx(DWORD,BOOL);
WINBASEAPI VOID        WINAPI SubmitThreadpoolWork(PTP_WORK);
WINBASEAPI DWORD       WINAPI SuspendThread(HANDLE);
WINBASEAPI void        WINAPI SwitchToFiber(LPVOID);
WINBASEAPI BOOL        WINAPI SwitchToThread(void);
WINBASEAPI BOOL        WINAPI SystemTimeToFileTime(const SYSTEMTIME*,LPFILETIME);
WINBASEAPI BOOL        WINAPI SystemTimeToTzSpecificLocalTime(const TIME_ZONE_INFORMATION*,const SYSTEMTIME*,LPSYSTEMTIME);
WINBASEAPI BOOL        WINAPI TerminateJobObject(HANDLE,UINT);
WINBASEAPI BOOL        WINAPI TerminateProcess(HANDLE,DWORD);
WINBASEAPI BOOL        WINAPI TerminateThread(HANDLE,DWORD);
WINBASEAPI DWORD       WINAPI TlsAlloc(void);
WINBASEAPI BOOL        WINAPI TlsFree(DWORD);
WINBASEAPI LPVOID      WINAPI TlsGetValue(DWORD);
WINBASEAPI BOOL        WINAPI TlsSetValue(DWORD,LPVOID);
WINBASEAPI BOOL        WINAPI TransactNamedPipe(HANDLE,LPVOID,DWORD,LPVOID,DWORD,LPDWORD,LPOVERLAPPED);
WINBASEAPI BOOL        WINAPI TransmitCommChar(HANDLE,CHAR);
WINBASEAPI BOOLEAN     WINAPI TryAcquireSRWLockExclusive(PSRWLOCK);
WINBASEAPI BOOLEAN     WINAPI TryAcquireSRWLockShared(PSRWLOCK);
WINBASEAPI BOOL        WINAPI TryEnterCriticalSection(CRITICAL_SECTION *lpCrit);
WINBASEAPI BOOL        WINAPI TrySubmitThreadpoolCallback(PTP_SIMPLE_CALLBACK,void*,TP_CALLBACK_ENVIRON*);
WINBASEAPI BOOL        WINAPI TzSpecificLocalTimeToSystemTime(const TIME_ZONE_INFORMATION*,const SYSTEMTIME*,LPSYSTEMTIME);
WINBASEAPI LONG        WINAPI UnhandledExceptionFilter(PEXCEPTION_POINTERS);
WINBASEAPI BOOL        WINAPI UnlockFile(HANDLE,DWORD,DWORD,DWORD,DWORD);
WINBASEAPI BOOL        WINAPI UnlockFileEx(HANDLE,DWORD,DWORD,DWORD,LPOVERLAPPED);
#define                       UnlockResource(handle) ((handle), 0)
#define                       UnlockSegment(handle) GlobalUnfix((HANDLE)(handle))
WINBASEAPI BOOL        WINAPI UnmapViewOfFile(LPCVOID);
WINBASEAPI HRESULT     WINAPI UnregisterApplicationRestart(void);
WINBASEAPI BOOL        WINAPI UnregisterWait(HANDLE);
WINBASEAPI BOOL        WINAPI UnregisterWaitEx(HANDLE,HANDLE);
WINBASEAPI BOOL        WINAPI UpdateProcThreadAttribute(struct _PROC_THREAD_ATTRIBUTE_LIST*,DWORD,DWORD_PTR,void*,SIZE_T,void*,SIZE_T*);
WINBASEAPI BOOL        WINAPI UpdateResourceA(HANDLE,LPCSTR,LPCSTR,WORD,LPVOID,DWORD);
WINBASEAPI BOOL        WINAPI UpdateResourceW(HANDLE,LPCWSTR,LPCWSTR,WORD,LPVOID,DWORD);
#define                       UpdateResource WINELIB_NAME_AW(UpdateResource)
WINBASEAPI BOOL        WINAPI VerifyVersionInfoA(LPOSVERSIONINFOEXA,DWORD,DWORDLONG);
WINBASEAPI BOOL        WINAPI VerifyVersionInfoW(LPOSVERSIONINFOEXW,DWORD,DWORDLONG);
#define                       VerifyVersionInfo WINELIB_NAME_AW(VerifyVersionInfo)
WINBASEAPI LPVOID      WINAPI VirtualAlloc(LPVOID,SIZE_T,DWORD,DWORD);
WINBASEAPI LPVOID      WINAPI VirtualAllocEx(HANDLE,LPVOID,SIZE_T,DWORD,DWORD);
WINBASEAPI BOOL        WINAPI VirtualFree(LPVOID,SIZE_T,DWORD);
WINBASEAPI BOOL        WINAPI VirtualFreeEx(HANDLE,LPVOID,SIZE_T,DWORD);
WINBASEAPI BOOL        WINAPI VirtualLock(LPVOID,SIZE_T);
WINBASEAPI BOOL        WINAPI VirtualProtect(LPVOID,SIZE_T,DWORD,LPDWORD);
WINBASEAPI BOOL        WINAPI VirtualProtectEx(HANDLE,LPVOID,SIZE_T,DWORD,LPDWORD);
WINBASEAPI SIZE_T      WINAPI VirtualQuery(LPCVOID,PMEMORY_BASIC_INFORMATION,SIZE_T);
WINBASEAPI SIZE_T      WINAPI VirtualQueryEx(HANDLE,LPCVOID,PMEMORY_BASIC_INFORMATION,SIZE_T);
WINBASEAPI BOOL        WINAPI VirtualUnlock(LPVOID,SIZE_T);
WINBASEAPI DWORD       WINAPI WTSGetActiveConsoleSessionId(void);
WINBASEAPI BOOL        WINAPI WaitCommEvent(HANDLE,LPDWORD,LPOVERLAPPED);
WINBASEAPI BOOL        WINAPI WaitForDebugEvent(LPDEBUG_EVENT,DWORD);
WINBASEAPI DWORD       WINAPI WaitForMultipleObjects(DWORD,const HANDLE*,BOOL,DWORD);
WINBASEAPI DWORD       WINAPI WaitForMultipleObjectsEx(DWORD,const HANDLE*,BOOL,DWORD,BOOL);
WINBASEAPI DWORD       WINAPI WaitForSingleObject(HANDLE,DWORD);
WINBASEAPI DWORD       WINAPI WaitForSingleObjectEx(HANDLE,DWORD,BOOL);
WINBASEAPI VOID        WINAPI WaitForThreadpoolTimerCallbacks(PTP_TIMER,BOOL);
WINBASEAPI BOOL        WINAPI WaitNamedPipeA(LPCSTR,DWORD);
WINBASEAPI BOOL        WINAPI WaitNamedPipeW(LPCWSTR,DWORD);
#define                       WaitNamedPipe WINELIB_NAME_AW(WaitNamedPipe)
WINBASEAPI VOID        WINAPI WakeAllConditionVariable(PCONDITION_VARIABLE);
WINBASEAPI VOID        WINAPI WakeConditionVariable(PCONDITION_VARIABLE);
WINBASEAPI UINT        WINAPI WinExec(LPCSTR,UINT);
WINBASEAPI BOOL        WINAPI Wow64DisableWow64FsRedirection(PVOID*);
WINBASEAPI BOOLEAN     WINAPI Wow64EnableWow64FsRedirection(BOOLEAN);
WINBASEAPI BOOL        WINAPI Wow64RevertWow64FsRedirection(PVOID);
WINADVAPI  DWORD       WINAPI WriteEncryptedFileRaw(PFE_IMPORT_FUNC,PVOID,PVOID);
WINBASEAPI BOOL        WINAPI WriteFile(HANDLE,LPCVOID,DWORD,LPDWORD,LPOVERLAPPED);
WINBASEAPI BOOL        WINAPI WriteFileEx(HANDLE,LPCVOID,DWORD,LPOVERLAPPED,LPOVERLAPPED_COMPLETION_ROUTINE);
WINBASEAPI BOOL        WINAPI WriteFileGather(HANDLE,FILE_SEGMENT_ELEMENT*,DWORD,LPDWORD,LPOVERLAPPED);
WINBASEAPI BOOL        WINAPI WritePrivateProfileSectionA(LPCSTR,LPCSTR,LPCSTR);
WINBASEAPI BOOL        WINAPI WritePrivateProfileSectionW(LPCWSTR,LPCWSTR,LPCWSTR);
#define                       WritePrivateProfileSection WINELIB_NAME_AW(WritePrivateProfileSection)
WINBASEAPI BOOL        WINAPI WritePrivateProfileStringA(LPCSTR,LPCSTR,LPCSTR,LPCSTR);
WINBASEAPI BOOL        WINAPI WritePrivateProfileStringW(LPCWSTR,LPCWSTR,LPCWSTR,LPCWSTR);
#define                       WritePrivateProfileString WINELIB_NAME_AW(WritePrivateProfileString)
WINBASEAPI BOOL        WINAPI WritePrivateProfileStructA(LPCSTR,LPCSTR,LPVOID,UINT,LPCSTR);
WINBASEAPI BOOL        WINAPI WritePrivateProfileStructW(LPCWSTR,LPCWSTR,LPVOID,UINT,LPCWSTR);
#define                       WritePrivateProfileStruct WINELIB_NAME_AW(WritePrivateProfileStruct)
WINBASEAPI BOOL        WINAPI WriteProcessMemory(HANDLE,LPVOID,LPCVOID,SIZE_T,SIZE_T*);
WINBASEAPI BOOL        WINAPI WriteProfileSectionA(LPCSTR,LPCSTR);
WINBASEAPI BOOL        WINAPI WriteProfileSectionW(LPCWSTR,LPCWSTR);
#define                       WritePrivateProfileSection WINELIB_NAME_AW(WritePrivateProfileSection)
WINBASEAPI BOOL        WINAPI WriteProfileStringA(LPCSTR,LPCSTR,LPCSTR);
WINBASEAPI BOOL        WINAPI WriteProfileStringW(LPCWSTR,LPCWSTR,LPCWSTR);
#define                       WriteProfileString WINELIB_NAME_AW(WriteProfileString)
WINBASEAPI DWORD       WINAPI WriteTapemark(HANDLE,DWORD,DWORD,BOOL);
#define                       Yield()
WINBASEAPI BOOL        WINAPI ZombifyActCtx(HANDLE);

WINBASEAPI INT         WINAPI lstrcmpA(LPCSTR,LPCSTR);
WINBASEAPI INT         WINAPI lstrcmpW(LPCWSTR,LPCWSTR);
WINBASEAPI INT         WINAPI lstrcmpiA(LPCSTR,LPCSTR);
WINBASEAPI INT         WINAPI lstrcmpiW(LPCWSTR,LPCWSTR);

#if !defined(__WINESRC__) || defined(WINE_NO_INLINE_STRING)

WINBASEAPI LPSTR       WINAPI lstrcatA(LPSTR,LPCSTR);
WINBASEAPI LPWSTR      WINAPI lstrcatW(LPWSTR,LPCWSTR);
WINBASEAPI LPSTR       WINAPI lstrcpyA(LPSTR,LPCSTR);
WINBASEAPI LPWSTR      WINAPI lstrcpyW(LPWSTR,LPCWSTR);
WINBASEAPI LPSTR       WINAPI lstrcpynA(LPSTR,LPCSTR,INT);
WINBASEAPI LPWSTR      WINAPI lstrcpynW(LPWSTR,LPCWSTR,INT);
WINBASEAPI INT         WINAPI lstrlenA(LPCSTR);
WINBASEAPI INT         WINAPI lstrlenW(LPCWSTR);

#else

/* string functions without the exception handler */

static inline LPWSTR WINAPI lstrcpynW( LPWSTR dst, LPCWSTR src, INT n )
{
    LPWSTR d = dst;
    LPCWSTR s = src;
    UINT count = n;

    while ((count > 1) && *s)
    {
        count--;
        *d++ = *s++;
    }
    if (count) *d = 0;
    return dst;
}

static inline LPSTR WINAPI lstrcpynA( LPSTR dst, LPCSTR src, INT n )
{
    LPSTR d = dst;
    LPCSTR s = src;
    UINT count = n;

    while ((count > 1) && *s)
    {
        count--;
        *d++ = *s++;
    }
    if (count) *d = 0;
    return dst;
}

static inline INT WINAPI lstrlenW( LPCWSTR str )
{
    const WCHAR *s = str;
    while (*s) s++;
    return s - str;
}

static inline INT WINAPI lstrlenA( LPCSTR str )
{
    return strlen( str );
}

static inline LPWSTR WINAPI lstrcpyW( LPWSTR dst, LPCWSTR src )
{
    WCHAR *p = dst;
    while ((*p++ = *src++));
    return dst;
}

static inline LPSTR WINAPI lstrcpyA( LPSTR dst, LPCSTR src )
{
    return strcpy( dst, src );
}

static inline LPWSTR WINAPI lstrcatW( LPWSTR dst, LPCWSTR src )
{
    WCHAR *p = dst;
    while (*p) p++;
    while ((*p++ = *src++));
    return dst;
}

static inline LPSTR WINAPI lstrcatA( LPSTR dst, LPCSTR src )
{
    return strcat( dst, src );
}

/* strncpy doesn't do what you think, don't use it */
#undef strncpy
#define strncpy(d,s,n) error do_not_use_strncpy_use_lstrcpynA_or_memcpy_instead

#endif /* !defined(__WINESRC__) || defined(WINE_NO_INLINE_STRING) */

#define     lstrcat WINELIB_NAME_AW(lstrcat)
#define     lstrcmp WINELIB_NAME_AW(lstrcmp)
#define     lstrcmpi WINELIB_NAME_AW(lstrcmpi)
#define     lstrcpy WINELIB_NAME_AW(lstrcpy)
#define     lstrcpyn WINELIB_NAME_AW(lstrcpyn)
#define     lstrlen WINELIB_NAME_AW(lstrlen)

WINBASEAPI LONG        WINAPI _hread(HFILE,LPVOID,LONG);
WINBASEAPI LONG        WINAPI _hwrite(HFILE,LPCSTR,LONG);
WINBASEAPI HFILE       WINAPI _lcreat(LPCSTR,INT);
WINBASEAPI HFILE       WINAPI _lclose(HFILE);
WINBASEAPI LONG        WINAPI _llseek(HFILE,LONG,INT);
WINBASEAPI HFILE       WINAPI _lopen(LPCSTR,INT);
WINBASEAPI UINT        WINAPI _lread(HFILE,LPVOID,UINT);
WINBASEAPI UINT        WINAPI _lwrite(HFILE,LPCSTR,UINT);

/* compatibility macros */
#define     FillMemory RtlFillMemory
#define     MoveMemory RtlMoveMemory
#define     ZeroMemory RtlZeroMemory
#define     CopyMemory RtlCopyMemory
#define     SecureZeroMemory RtlSecureZeroMemory

/* Wine internal functions */

extern char * CDECL wine_get_unix_file_name( LPCWSTR dos );
extern WCHAR * CDECL wine_get_dos_file_name( LPCSTR str );


/* Interlocked functions */

#ifdef __i386__
# if defined(__GNUC__) && !defined(_NTSYSTEM_) && ((__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 2)))

static FORCEINLINE LONG WINAPI InterlockedCompareExchange( LONG volatile *dest, LONG xchg, LONG compare )
{
    LONG ret;
    __asm__ __volatile__( "lock; cmpxchgl %2,(%1)"
                          : "=a" (ret) : "r" (dest), "r" (xchg), "0" (compare) : "memory" );
    return ret;
}

static FORCEINLINE LONG WINAPI InterlockedExchange( LONG volatile *dest, LONG val )
{
    LONG ret;
    __asm__ __volatile__( "lock; xchgl %0,(%1)"
                          : "=r" (ret) :"r" (dest), "0" (val) : "memory" );
    return ret;
}

static FORCEINLINE LONG WINAPI InterlockedExchangeAdd( LONG volatile *dest, LONG incr )
{
    LONG ret;
    __asm__ __volatile__( "lock; xaddl %0,(%1)"
                          : "=r" (ret) : "r" (dest), "0" (incr) : "memory" );
    return ret;
}

static FORCEINLINE LONG WINAPI InterlockedIncrement( LONG volatile *dest )
{
    return InterlockedExchangeAdd( dest, 1 ) + 1;
}

static FORCEINLINE LONG WINAPI InterlockedDecrement( LONG volatile *dest )
{
    return InterlockedExchangeAdd( dest, -1 ) - 1;
}

# else  /* __GNUC__ */

WINBASEAPI LONG WINAPI InterlockedCompareExchange(LONG volatile*,LONG,LONG);
WINBASEAPI LONG WINAPI InterlockedDecrement(LONG volatile*);
WINBASEAPI LONG WINAPI InterlockedExchange(LONG volatile*,LONG);
WINBASEAPI LONG WINAPI InterlockedExchangeAdd(LONG volatile*,LONG);
WINBASEAPI LONG WINAPI InterlockedIncrement(LONG volatile*);

# endif  /* __GNUC__ */

static FORCEINLINE PVOID WINAPI InterlockedCompareExchangePointer( PVOID volatile *dest, PVOID xchg, PVOID compare )
{
    return (PVOID)InterlockedCompareExchange( (LONG volatile*)dest, (LONG)xchg, (LONG)compare );
}

static FORCEINLINE PVOID WINAPI InterlockedExchangePointer( PVOID volatile *dest, PVOID val )
{
    return (PVOID)InterlockedExchange( (LONG volatile*)dest, (LONG)val );
}

WINBASEAPI LONGLONG WINAPI InterlockedCompareExchange64(LONGLONG volatile*,LONGLONG,LONGLONG);

#elif defined(_MSC_VER)

#pragma intrinsic(_InterlockedCompareExchange)
#pragma intrinsic(_InterlockedCompareExchangePointer)
#pragma intrinsic(_InterlockedCompareExchange64)
#pragma intrinsic(_InterlockedExchange)
#pragma intrinsic(_InterlockedExchangePointer)
#pragma intrinsic(_InterlockedExchangeAdd)
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

static FORCEINLINE LONG WINAPI InterlockedCompareExchange( LONG volatile *dest, LONG xchg, LONG compare )
{
    return _InterlockedCompareExchange( dest, xchg, compare );
}

static FORCEINLINE PVOID WINAPI InterlockedCompareExchangePointer( PVOID volatile *dest, PVOID xchg, PVOID compare )
{
    return _InterlockedCompareExchangePointer( dest, xchg, compare );
}

static FORCEINLINE LONGLONG WINAPI InterlockedCompareExchange64( LONGLONG volatile *dest, LONGLONG xchg, LONGLONG compare )
{
    return _InterlockedCompareExchange64( dest, xchg, compare );
}

static FORCEINLINE LONG WINAPI InterlockedExchange( LONG volatile *dest, LONG val )
{
    return _InterlockedExchange( dest, val );
}

static FORCEINLINE PVOID WINAPI InterlockedExchangePointer( PVOID volatile *dest, PVOID val )
{
    return _InterlockedExchangePointer( dest, val );
}

static FORCEINLINE LONG WINAPI InterlockedExchangeAdd( LONG volatile *dest, LONG incr )
{
    return _InterlockedExchangeAdd( dest, incr );
}

static FORCEINLINE LONG WINAPI InterlockedIncrement( LONG volatile *dest )
{
    return _InterlockedIncrement( dest );
}

static FORCEINLINE LONG WINAPI InterlockedDecrement( LONG volatile *dest )
{
    return _InterlockedDecrement( dest );
}

#elif defined(__GNUC__)

static FORCEINLINE LONG WINAPI InterlockedCompareExchange( LONG volatile *dest, LONG xchg, LONG compare )
{
    return __sync_val_compare_and_swap( dest, compare, xchg );
}

static FORCEINLINE PVOID WINAPI InterlockedCompareExchangePointer( PVOID volatile *dest, PVOID xchg, PVOID compare )
{
    return __sync_val_compare_and_swap( dest, compare, xchg );
}

static FORCEINLINE LONGLONG WINAPI InterlockedCompareExchange64( LONGLONG volatile *dest, LONGLONG xchg, LONGLONG compare )
{
    return __sync_val_compare_and_swap( dest, compare, xchg );
}

static FORCEINLINE LONG WINAPI InterlockedExchange( LONG volatile *dest, LONG val )
{
    LONG ret;
#ifdef __x86_64__
    __asm__ __volatile__( "lock; xchgl %0,(%1)" : "=r" (ret) :"r" (dest), "0" (val) : "memory" );
#else
    do ret = *dest; while (!__sync_bool_compare_and_swap( dest, ret, val ));
#endif
    return ret;
}

static FORCEINLINE PVOID WINAPI InterlockedExchangePointer( PVOID volatile *dest, PVOID val )
{
    PVOID ret;
#ifdef __x86_64__
    __asm__ __volatile__( "lock; xchgq %0,(%1)" : "=r" (ret) :"r" (dest), "0" (val) : "memory" );
#else
    do ret = *dest; while (!__sync_bool_compare_and_swap( dest, ret, val ));
#endif
    return ret;
}

static FORCEINLINE LONG WINAPI InterlockedExchangeAdd( LONG volatile *dest, LONG incr )
{
    return __sync_fetch_and_add( dest, incr );
}

static FORCEINLINE LONG WINAPI InterlockedIncrement( LONG volatile *dest )
{
    return __sync_add_and_fetch( dest, 1 );
}

static FORCEINLINE LONG WINAPI InterlockedDecrement( LONG volatile *dest )
{
    return __sync_add_and_fetch( dest, -1 );
}

#endif  /* __i386__ */

/* A few optimizations for gcc */

#if defined(__GNUC__) && !defined(__MINGW32__) && (defined(__i386__) || defined(__x86_64__)) && ((__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 2)))

static FORCEINLINE DWORD WINAPI GetLastError(void)
{
    DWORD ret;
#ifdef __x86_64__
#ifdef __APPLE__
    DWORD* teb;
    __asm__ __volatile__( ".byte 0x65\n\tmovq 0x30,%0" : "=r" (teb) );
    ret = teb[0x68 / sizeof(DWORD)];
#else
    __asm__ __volatile__( ".byte 0x65\n\tmovl 0x68,%0" : "=r" (ret) );
#endif
#else
    __asm__ __volatile__( ".byte 0x64\n\tmovl 0x34,%0" : "=r" (ret) );
#endif
    return ret;
}

static FORCEINLINE DWORD WINAPI GetCurrentProcessId(void)
{
    DWORD ret;
#ifdef __x86_64__
#ifdef __APPLE__
    DWORD* teb;
    __asm__ __volatile__( ".byte 0x65\n\tmovq 0x30,%0" : "=r" (teb) );
    ret = teb[0x40 / sizeof(DWORD)];
#else
    __asm__ __volatile__( ".byte 0x65\n\tmovl 0x40,%0" : "=r" (ret) );
#endif
#else
    __asm__ __volatile__( ".byte 0x64\n\tmovl 0x20,%0" : "=r" (ret) );
#endif
    return ret;
}

static FORCEINLINE DWORD WINAPI GetCurrentThreadId(void)
{
    DWORD ret;
#ifdef __x86_64__
#ifdef __APPLE__
    DWORD* teb;
    __asm__ __volatile__( ".byte 0x65\n\tmovq 0x30,%0" : "=r" (teb) );
    ret = teb[0x48 / sizeof(DWORD)];
#else
    __asm__ __volatile__( ".byte 0x65\n\tmovl 0x48,%0" : "=r" (ret) );
#endif
#else
    __asm__ __volatile__( ".byte 0x64\n\tmovl 0x24,%0" : "=r" (ret) );
#endif
    return ret;
}

static FORCEINLINE void WINAPI SetLastError( DWORD err )
{
#ifdef __x86_64__
#ifdef __APPLE__
    DWORD* teb;
    __asm__ __volatile__( ".byte 0x65\n\tmovq 0x30,%0" : "=r" (teb) );
    teb[0x68 / sizeof(DWORD)] = err;
#else
    __asm__ __volatile__( ".byte 0x65\n\tmovl %0,0x68" : : "r" (err) : "memory" );
#endif
#else
    __asm__ __volatile__( ".byte 0x64\n\tmovl %0,0x34" : : "r" (err) : "memory" );
#endif
}

static FORCEINLINE HANDLE WINAPI GetProcessHeap(void)
{
    HANDLE *pdb;
#ifdef __x86_64__
#ifdef __APPLE__
    HANDLE** teb;
    __asm__ __volatile__( ".byte 0x65\n\tmovq 0x30,%0" : "=r" (teb) );
    pdb = teb[0x60 / sizeof(HANDLE*)];
#else
    __asm__ __volatile__( ".byte 0x65\n\tmovq 0x60,%0" : "=r" (pdb) );
#endif
    return pdb[0x30 / sizeof(HANDLE)];  /* get dword at offset 0x30 in pdb */
#else
    __asm__ __volatile__( ".byte 0x64\n\tmovl 0x30,%0" : "=r" (pdb) );
    return pdb[0x18 / sizeof(HANDLE)];  /* get dword at offset 0x18 in pdb */
#endif
}

#else  /* __GNUC__ */

WINBASEAPI DWORD       WINAPI GetCurrentProcessId(void);
WINBASEAPI DWORD       WINAPI GetCurrentThreadId(void);
WINBASEAPI DWORD       WINAPI GetLastError(void);
WINBASEAPI HANDLE      WINAPI GetProcessHeap(void);
WINBASEAPI VOID        WINAPI SetLastError(DWORD);

#endif  /* __GNUC__ */

#ifdef __WINESRC__
#define GetCurrentProcess() ((HANDLE)~(ULONG_PTR)0)
#define GetCurrentThread()  ((HANDLE)~(ULONG_PTR)1)
#endif

#define GetCurrentProcessToken()            ((HANDLE)~(ULONG_PTR)3)
#define GetCurrentThreadToken()             ((HANDLE)~(ULONG_PTR)4)
#define GetCurrentThreadEffectiveToken()    ((HANDLE)~(ULONG_PTR)5)

/* WinMain(entry point) must be declared in winbase.h. */
/* If this is not declared, we cannot compile many sources written with C++. */
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int);

#ifdef __WINESRC__
/* shouldn't be here, but is nice for type checking */
BOOL WINAPI DllMain( HINSTANCE hinst, DWORD reason, LPVOID reserved ) DECLSPEC_HIDDEN;
#endif

#ifdef __cplusplus
}
#endif

#endif  /* __WINE_WINBASE_H */
