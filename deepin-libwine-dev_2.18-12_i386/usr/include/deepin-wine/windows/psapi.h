/*
 * Declarations for PSAPI
 *
 * Copyright (C) 1998 Patrik Stridvall
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

#ifndef __WINE_PSAPI_H
#define __WINE_PSAPI_H

#ifndef PSAPI_VERSION
#define PSAPI_VERSION 2
#endif

typedef struct _MODULEINFO {
  LPVOID lpBaseOfDll;
  DWORD SizeOfImage;
  LPVOID EntryPoint;
} MODULEINFO, *LPMODULEINFO;

typedef struct _PROCESS_MEMORY_COUNTERS {
  DWORD  cb;
  DWORD  PageFaultCount;
  SIZE_T PeakWorkingSetSize;
  SIZE_T WorkingSetSize;
  SIZE_T QuotaPeakPagedPoolUsage;
  SIZE_T QuotaPagedPoolUsage;
  SIZE_T QuotaPeakNonPagedPoolUsage;
  SIZE_T QuotaNonPagedPoolUsage;
  SIZE_T PagefileUsage;
  SIZE_T PeakPagefileUsage;
} PROCESS_MEMORY_COUNTERS;
typedef PROCESS_MEMORY_COUNTERS *PPROCESS_MEMORY_COUNTERS;

typedef struct _PSAPI_WS_WATCH_INFORMATION {
  LPVOID FaultingPc;
  LPVOID FaultingVa;
} PSAPI_WS_WATCH_INFORMATION, *PPSAPI_WS_WATCH_INFORMATION;

typedef struct _PERFORMANCE_INFORMATION {
    DWORD cb;
    SIZE_T CommitTotal;
    SIZE_T CommitLimit;
    SIZE_T CommitPeak;
    SIZE_T PhysicalTotal;
    SIZE_T PhysicalAvailable;
    SIZE_T SystemCache;
    SIZE_T KernelTotal;
    SIZE_T KernelPaged;
    SIZE_T KernelNonpaged;
    SIZE_T PageSize;
    DWORD HandleCount;
    DWORD ProcessCount;
    DWORD ThreadCount;
} PERFORMANCE_INFORMATION, *PPERFORMANCE_INFORMATION;

typedef struct _ENUM_PAGE_FILE_INFORMATION {
    DWORD cb;
    DWORD Reserved;
    SIZE_T TotalSize;
    SIZE_T TotalInUse;
    SIZE_T PeakUsage;
} ENUM_PAGE_FILE_INFORMATION, *PENUM_PAGE_FILE_INFORMATION;

typedef BOOL (*PENUM_PAGE_FILE_CALLBACKA) (LPVOID, PENUM_PAGE_FILE_INFORMATION, LPCSTR);
typedef BOOL (*PENUM_PAGE_FILE_CALLBACKW) (LPVOID, PENUM_PAGE_FILE_INFORMATION, LPCWSTR);
#define PENUM_PAGE_FILE_CALLBACK WINELIB_NAME_AW(PENUM_PAGE_FILE_CALLBACK)

#ifdef __cplusplus
extern "C" {
#endif

#if PSAPI_VERSION > 1
#define EnumProcesses               K32EnumProcesses
#define EnumProcessModules          K32EnumProcessModules
#define EnumProcessModulesEx        K32EnumProcessModulesEx
#define GetModuleBaseNameA          K32GetModuleBaseNameA
#define GetModuleBaseNameW          K32GetModuleBaseNameW
#define GetModuleFileNameExA        K32GetModuleFileNameExA
#define GetModuleFileNameExW        K32GetModuleFileNameExW
#define GetModuleInformation        K32GetModuleInformation
#define EmptyWorkingSet             K32EmptyWorkingSet
#define QueryWorkingSet             K32QueryWorkingSet
#define QueryWorkingSetEx           K32QueryWorkingSetEx
#define InitializeProcessForWsWatch K32InitializeProcessForWsWatch
#define GetWsChanges                K32GetWsChanges
#define GetWsChangesEx              K32GetWsChangesEx
#define GetMappedFileNameW          K32GetMappedFileNameW
#define GetMappedFileNameA          K32GetMappedFileNameA
#define EnumDeviceDrivers           K32EnumDeviceDrivers
#define GetDeviceDriverBaseNameA    K32GetDeviceDriverBaseNameA
#define GetDeviceDriverBaseNameW    K32GetDeviceDriverBaseNameW
#define GetDeviceDriverFileNameA    K32GetDeviceDriverFileNameA
#define GetDeviceDriverFileNameW    K32GetDeviceDriverFileNameW
#define GetProcessMemoryInfo        K32GetProcessMemoryInfo
#define GetPerformanceInfo          K32GetPerformanceInfo
#define EnumPageFilesW              K32EnumPageFilesW
#define EnumPageFilesA              K32EnumPageFilesA
#define GetProcessImageFileNameA    K32GetProcessImageFileNameA
#define GetProcessImageFileNameW    K32GetProcessImageFileNameW
#endif

BOOL  WINAPI EnumProcesses(DWORD*, DWORD, DWORD*);
BOOL  WINAPI EnumProcessModules(HANDLE, HMODULE*, DWORD, LPDWORD);
BOOL  WINAPI EnumProcessModulesEx(HANDLE, HMODULE*, DWORD, LPDWORD, DWORD);
DWORD WINAPI GetModuleBaseNameA(HANDLE, HMODULE, LPSTR, DWORD);
DWORD WINAPI GetModuleBaseNameW(HANDLE, HMODULE, LPWSTR, DWORD);
#define      GetModuleBaseName WINELIB_NAME_AW(GetModuleBaseName)
DWORD WINAPI GetModuleFileNameExA(HANDLE, HMODULE, LPSTR, DWORD);
DWORD WINAPI GetModuleFileNameExW(HANDLE, HMODULE, LPWSTR, DWORD);
#define      GetModuleFileNameEx WINELIB_NAME_AW(GetModuleFileNameEx)
BOOL  WINAPI GetModuleInformation(HANDLE, HMODULE, LPMODULEINFO, DWORD);
BOOL  WINAPI EmptyWorkingSet(HANDLE);
BOOL  WINAPI QueryWorkingSet(HANDLE, PVOID, DWORD);
BOOL  WINAPI QueryWorkingSetEx(HANDLE, PVOID, DWORD);
BOOL  WINAPI InitializeProcessForWsWatch(HANDLE);
BOOL  WINAPI GetWsChanges(HANDLE, PPSAPI_WS_WATCH_INFORMATION, DWORD);
DWORD WINAPI GetMappedFileNameW(HANDLE, LPVOID, LPWSTR, DWORD);
DWORD WINAPI GetMappedFileNameA(HANDLE, LPVOID, LPSTR, DWORD);
#define      GetMappedFileName WINELIB_NAME_AW(GetMappedFileName)
BOOL  WINAPI EnumDeviceDrivers(LPVOID*, DWORD, LPDWORD);
DWORD WINAPI GetDeviceDriverBaseNameA(LPVOID, LPSTR, DWORD);
DWORD WINAPI GetDeviceDriverBaseNameW(LPVOID, LPWSTR, DWORD);
#define      GetDeviceDriverBaseName WINELIB_NAME_AW(GetDeviceDriverBaseName)
DWORD WINAPI GetDeviceDriverFileNameA(LPVOID, LPSTR, DWORD);
DWORD WINAPI GetDeviceDriverFileNameW(LPVOID, LPWSTR, DWORD);
#define      GetDeviceDriverFileName WINELIB_NAME_AW(GetDeviceDriverFileName)
BOOL  WINAPI GetProcessMemoryInfo(HANDLE, PPROCESS_MEMORY_COUNTERS, DWORD);
BOOL  WINAPI GetPerformanceInfo(PPERFORMANCE_INFORMATION, DWORD);
BOOL  WINAPI EnumPageFilesA(PENUM_PAGE_FILE_CALLBACKA, LPVOID);
BOOL  WINAPI EnumPageFilesW(PENUM_PAGE_FILE_CALLBACKW, LPVOID);
#define EnumPageFiles WINELIB_NAME_AW(EnumPageFiles)
DWORD WINAPI GetProcessImageFileNameA(HANDLE, LPSTR, DWORD);
DWORD WINAPI GetProcessImageFileNameW(HANDLE, LPWSTR, DWORD);
#define      GetProcessImageFileName WINELIB_NAME_AW(GetProcessImageFileName)

#ifdef __cplusplus
}
#endif

#endif  /* __WINE_PSAPI_H */
