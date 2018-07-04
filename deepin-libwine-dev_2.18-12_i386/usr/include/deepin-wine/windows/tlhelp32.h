/*
 * Copyright (C) 1998 Patrick Spinler
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

#ifndef __WINE_TLHELP32_H
#define __WINE_TLHELP32_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * CreateToolhelp32Snapshot
 */

#define TH32CS_SNAPHEAPLIST 0x00000001
#define TH32CS_SNAPPROCESS  0x00000002
#define TH32CS_SNAPTHREAD   0x00000004
#define TH32CS_SNAPMODULE   0x00000008
#define TH32CS_SNAPALL     (TH32CS_SNAPHEAPLIST | TH32CS_SNAPPROCESS | TH32CS_SNAPTHREAD | TH32CS_SNAPMODULE)
#define TH32CS_INHERIT     0x80000000

HANDLE WINAPI CreateToolhelp32Snapshot(DWORD,DWORD);

/*
 * thread entry list as created by CreateToolHelp32Snapshot
 */

typedef struct tagTHREADENTRY32
{
    DWORD dwSize;
    DWORD cntUsage;
    DWORD th32ThreadID;
    DWORD th32OwnerProcessID;
    LONG  tpBasePri;
    LONG  tpDeltaPri;
    DWORD dwFlags;
} THREADENTRY32, *PTHREADENTRY32, *LPTHREADENTRY32;

BOOL WINAPI Thread32First(HANDLE,LPTHREADENTRY32);
BOOL WINAPI Thread32Next(HANDLE,LPTHREADENTRY32);

/*
 * Process entry list as created by CreateToolHelp32Snapshot
 */

typedef struct tagPROCESSENTRY32
{
    DWORD     dwSize;
    DWORD     cntUsage;
    DWORD     th32ProcessID;
    ULONG_PTR th32DefaultHeapID;
    DWORD     th32ModuleID;
    DWORD     cntThreads;
    DWORD     th32ParentProcessID;
    LONG      pcPriClassBase;
    DWORD     dwFlags;
    char      szExeFile[MAX_PATH];
} PROCESSENTRY32, *PPROCESSENTRY32, *LPPROCESSENTRY32;

typedef struct tagPROCESSENTRY32W
{
    DWORD     dwSize;
    DWORD     cntUsage;
    DWORD     th32ProcessID;
    ULONG_PTR th32DefaultHeapID;
    DWORD     th32ModuleID;
    DWORD     cntThreads;
    DWORD     th32ParentProcessID;
    LONG      pcPriClassBase;
    DWORD     dwFlags;
    WCHAR     szExeFile[MAX_PATH];
} PROCESSENTRY32W, *PPROCESSENTRY32W, *LPPROCESSENTRY32W;

BOOL WINAPI Process32First(HANDLE,LPPROCESSENTRY32);
BOOL WINAPI Process32FirstW(HANDLE,LPPROCESSENTRY32W);
BOOL WINAPI Process32Next(HANDLE,LPPROCESSENTRY32);
BOOL WINAPI Process32NextW(HANDLE,LPPROCESSENTRY32W);

#ifdef UNICODE
#define Process32First Process32FirstW
#define Process32Next Process32NextW
#define PROCESSENTRY32 PROCESSENTRY32W
#define PPROCESSENTRY32 PPROCESSENTRY32W
#define LPPROCESSENTRY32 LPPROCESSENTRY32W
#endif

/*
 * Module entry list as created by CreateToolHelp32Snapshot
 */

#define MAX_MODULE_NAME32 255

typedef struct tagMODULEENTRY32
{
    DWORD  dwSize;
    DWORD  th32ModuleID;
    DWORD  th32ProcessID;
    DWORD  GlblcntUsage;
    DWORD  ProccntUsage;
    BYTE  *modBaseAddr;
    DWORD  modBaseSize;
    HMODULE hModule;
    char   szModule[MAX_MODULE_NAME32 + 1];
    char   szExePath[MAX_PATH];
} MODULEENTRY32, *PMODULEENTRY32, *LPMODULEENTRY32;

typedef struct tagMODULEENTRY32W
{
    DWORD  dwSize;
    DWORD  th32ModuleID;
    DWORD  th32ProcessID;
    DWORD  GlblcntUsage;
    DWORD  ProccntUsage;
    BYTE  *modBaseAddr;
    DWORD  modBaseSize;
    HMODULE hModule;
    WCHAR  szModule[MAX_MODULE_NAME32 + 1];
    WCHAR  szExePath[MAX_PATH];
} MODULEENTRY32W, *PMODULEENTRY32W, *LPMODULEENTRY32W;

BOOL WINAPI Module32First(HANDLE,LPMODULEENTRY32);
BOOL WINAPI Module32FirstW(HANDLE,LPMODULEENTRY32W);
BOOL WINAPI Module32Next(HANDLE,LPMODULEENTRY32);
BOOL WINAPI Module32NextW(HANDLE,LPMODULEENTRY32W);

#ifdef UNICODE
#define Module32First Module32FirstW
#define Module32Next Module32NextW
#define MODULEENTRY32 MODULEENTRY32W
#define PMODULEENTRY32 PMODULEENTRY32W
#define LPMODULEENTRY32 LPMODULEENTRY32W
#endif

typedef struct tagHEAPLIST32
{
    SIZE_T dwSize;
    DWORD th32ProcessID;
    ULONG_PTR th32HeapID;
    DWORD dwFlags;
} HEAPLIST32, *PHEAPLIST32, *LPHEAPLIST32;

#define HF32_DEFAULT 1
#define HF32_SHARED  2

BOOL WINAPI Heap32ListFirst(HANDLE,LPHEAPLIST32);
BOOL WINAPI Heap32ListNext(HANDLE,LPHEAPLIST32);
BOOL WINAPI Toolhelp32ReadProcessMemory(DWORD,LPCVOID,LPVOID,SIZE_T,SIZE_T*);

typedef struct tagHEAPENTRY32
{
    SIZE_T dwSize;
    HANDLE hHandle;
    ULONG_PTR dwAddress;
    SIZE_T dwBlockSize;
    DWORD dwFlags;
    DWORD dwLockCount;
    DWORD dwResvd;
    DWORD th32ProcessID;
    ULONG_PTR th32HeapID;
} HEAPENTRY32, *PHEAPENTRY32, *LPHEAPENTRY32;

BOOL WINAPI Heap32First(LPHEAPENTRY32,DWORD,ULONG_PTR);
BOOL WINAPI Heap32Next(LPHEAPENTRY32);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __WINE_TLHELP32_H */
