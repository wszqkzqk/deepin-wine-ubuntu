/*
 * WOW Generic Thunk API
 *
 * Copyright (C) 1999 Ulrich Weigand
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

#ifndef _WOWNT32_H_
#define _WOWNT32_H_

#ifdef __WINESRC__
/* under Wine use the kernel functions directly so we don't have to import wow32 */
#define WOWCallback16 K32WOWCallback16
#define WOWCallback16Ex K32WOWCallback16Ex
#define WOWDirectedYield16 K32WOWDirectedYield16
#define WOWGetVDMPointer K32WOWGetVDMPointer
#define WOWGetVDMPointerFix K32WOWGetVDMPointerFix
#define WOWGetVDMPointerUnfix K32WOWGetVDMPointerUnfix
#define WOWGlobalAlloc16 K32WOWGlobalAlloc16
#define WOWGlobalAllocLock16 K32WOWGlobalAllocLock16
#define WOWGlobalFree16 K32WOWGlobalFree16
#define WOWGlobalLock16 K32WOWGlobalLock16
#define WOWGlobalLockSize16 K32WOWGlobalLockSize16
#define WOWGlobalUnlock16 K32WOWGlobalUnlock16
#define WOWGlobalUnlockFree16 K32WOWGlobalUnlockFree16
#define WOWHandle16 K32WOWHandle16
#define WOWHandle32 K32WOWHandle32
#define WOWYield16 K32WOWYield16
#endif

LPVOID WINAPI WOWGetVDMPointer(DWORD,DWORD,BOOL);
LPVOID WINAPI WOWGetVDMPointerFix(DWORD,DWORD,BOOL);
VOID   WINAPI WOWGetVDMPointerUnfix(DWORD);

WORD   WINAPI WOWGlobalAlloc16(WORD,DWORD);
WORD   WINAPI WOWGlobalFree16(WORD);
DWORD  WINAPI WOWGlobalLock16(WORD);
BOOL   WINAPI WOWGlobalUnlock16(WORD);
DWORD  WINAPI WOWGlobalAllocLock16(WORD,DWORD,WORD *);
WORD   WINAPI WOWGlobalUnlockFree16(DWORD);
DWORD  WINAPI WOWGlobalLockSize16(WORD,PDWORD);

VOID   WINAPI WOWYield16(VOID);
VOID   WINAPI WOWDirectedYield16(WORD);

typedef enum
{
    WOW_TYPE_HWND,
    WOW_TYPE_HMENU,
    WOW_TYPE_HDWP,
    WOW_TYPE_HDROP,
    WOW_TYPE_HDC,
    WOW_TYPE_HFONT,
    WOW_TYPE_HMETAFILE,
    WOW_TYPE_HRGN,
    WOW_TYPE_HBITMAP,
    WOW_TYPE_HBRUSH,
    WOW_TYPE_HPALETTE,
    WOW_TYPE_HPEN,
    WOW_TYPE_HACCEL,
    WOW_TYPE_HTASK,
    WOW_TYPE_FULLHWND

} WOW_HANDLE_TYPE;

HANDLE WINAPI WOWHandle32(WORD,WOW_HANDLE_TYPE);
WORD   WINAPI WOWHandle16(HANDLE,WOW_HANDLE_TYPE);

#ifdef __WINESRC__
/* under Wine we use optimized versions where we can */
#define HWND_32(h16)      ((HWND)      (ULONG_PTR)(h16))
#define HMENU_32(h16)     ((HMENU)     (ULONG_PTR)(h16))
#define HDWP_32(h16)      ((HDWP)      (ULONG_PTR)(h16))
#define HDROP_32(h16)     ((HDROP)     (ULONG_PTR)(h16))
#define HDC_32(h16)       ((HDC)       (ULONG_PTR)(h16))
#define HFONT_32(h16)     ((HFONT)     (ULONG_PTR)(h16))
#define HRGN_32(h16)      ((HRGN)      (ULONG_PTR)(h16))
#define HBITMAP_32(h16)   ((HBITMAP)   (ULONG_PTR)(h16))
#define HBRUSH_32(h16)    ((HBRUSH)    (ULONG_PTR)(h16))
#define HPALETTE_32(h16)  ((HPALETTE)  (ULONG_PTR)(h16))
#define HPEN_32(h16)      ((HPEN)      (ULONG_PTR)(h16))
#define HACCEL_32(h16)    ((HACCEL)    (ULONG_PTR)(h16))

#define HWND_16(h32)      (LOWORD(h32))
#define HMENU_16(h32)     (LOWORD(h32))
#define HDWP_16(h32)      (LOWORD(h32))
#define HDROP_16(h32)     (LOWORD(h32))
#define HDC_16(h32)       (LOWORD(h32))
#define HFONT_16(h32)     (LOWORD(h32))
#define HRGN_16(h32)      (LOWORD(h32))
#define HBITMAP_16(h32)   (LOWORD(h32))
#define HBRUSH_16(h32)    (LOWORD(h32))
#define HPALETTE_16(h32)  (LOWORD(h32))
#define HPEN_16(h32)      (LOWORD(h32))
#define HACCEL_16(h32)    (LOWORD(h32))

#else  /* __WINESRC__ */

#define HWND_32(h16)      ((HWND)      (WOWHandle32(h16, WOW_TYPE_HWND)))
#define HMENU_32(h16)     ((HMENU)     (WOWHandle32(h16, WOW_TYPE_HMENU)))
#define HDWP_32(h16)      ((HDWP)      (WOWHandle32(h16, WOW_TYPE_HDWP)))
#define HDROP_32(h16)     ((HDROP)     (WOWHandle32(h16, WOW_TYPE_HDROP)))
#define HDC_32(h16)       ((HDC)       (WOWHandle32(h16, WOW_TYPE_HDC)))
#define HFONT_32(h16)     ((HFONT)     (WOWHandle32(h16, WOW_TYPE_HFONT)))
#define HRGN_32(h16)      ((HRGN)      (WOWHandle32(h16, WOW_TYPE_HRGN)))
#define HBITMAP_32(h16)   ((HBITMAP)   (WOWHandle32(h16, WOW_TYPE_HBITMAP)))
#define HBRUSH_32(h16)    ((HBRUSH)    (WOWHandle32(h16, WOW_TYPE_HBRUSH)))
#define HPALETTE_32(h16)  ((HPALETTE)  (WOWHandle32(h16, WOW_TYPE_HPALETTE)))
#define HPEN_32(h16)      ((HPEN)      (WOWHandle32(h16, WOW_TYPE_HPEN)))
#define HACCEL_32(h16)    ((HACCEL)    (WOWHandle32(h16, WOW_TYPE_HACCEL)))

#define HWND_16(h32)      (WOWHandle16(h32, WOW_TYPE_HWND))
#define HMENU_16(h32)     (WOWHandle16(h32, WOW_TYPE_HMENU))
#define HDWP_16(h32)      (WOWHandle16(h32, WOW_TYPE_HDWP))
#define HDROP_16(h32)     (WOWHandle16(h32, WOW_TYPE_HDROP))
#define HDC_16(h32)       (WOWHandle16(h32, WOW_TYPE_HDC))
#define HFONT_16(h32)     (WOWHandle16(h32, WOW_TYPE_HFONT))
#define HRGN_16(h32)      (WOWHandle16(h32, WOW_TYPE_HRGN))
#define HBITMAP_16(h32)   (WOWHandle16(h32, WOW_TYPE_HBITMAP))
#define HBRUSH_16(h32)    (WOWHandle16(h32, WOW_TYPE_HBRUSH))
#define HPALETTE_16(h32)  (WOWHandle16(h32, WOW_TYPE_HPALETTE))
#define HPEN_16(h32)      (WOWHandle16(h32, WOW_TYPE_HPEN))
#define HACCEL_16(h32)    (WOWHandle16(h32, WOW_TYPE_HACCEL))

#endif  /* __WINESRC__ */

#define HMETAFILE_32(h16) ((HMETAFILE)(WOWHandle32(h16, WOW_TYPE_HMETAFILE)))
#define HTASK_32(h16)     ((DWORD)(WOWHandle32(h16, WOW_TYPE_HTASK)))
#define FULLHWND_32(h16)  ((HWND)(WOWHandle32(h16, WOW_TYPE_FULLHWND)))

#define HMETAFILE_16(h32) (WOWHandle16(h32, WOW_TYPE_HMETAFILE))
#define HTASK_16(h32)     (WOWHandle16((HANDLE)(h32), WOW_TYPE_HTASK))

#define WCB16_PASCAL     0
#define WCB16_CDECL      1
#define WCB16_MAX_CBARGS 16

/* Wine extensions: call register function, context ptr is passed in the return value LPDWORD */
#define WCB16_REGS       2
#define WCB16_REGS_LONG  4  /* function uses 32-bit lret */

DWORD WINAPI WOWCallback16(DWORD,DWORD);
BOOL  WINAPI WOWCallback16Ex(DWORD,DWORD,DWORD,LPVOID,LPDWORD);

#endif /* _WOWNT32_H_ */
