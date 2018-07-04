/*
 * Definitions for the Wine library
 *
 * Copyright 2000 Alexandre Julliard
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

#ifndef __WINE_WINE_LIBRARY_H
#define __WINE_WINE_LIBRARY_H

#include <stdarg.h>
#include <sys/types.h>

#include <windef.h>
#include <winbase.h>

#ifdef __WINE_WINE_TEST_H
#error This file should not be used in Wine tests
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* configuration */

extern const char *wine_get_build_dir(void);
extern const char *wine_get_config_dir(void);
extern const char *wine_get_data_dir(void);
extern const char *wine_get_server_dir(void);
extern const char *wine_get_user_name(void);
extern const char *wine_get_version(void);
extern const char *wine_get_build_id(void);
extern void wine_init_argv0_path( const char *argv0 );
extern void wine_exec_wine_binary( const char *name, char **argv, const char *env_var );

/* dll loading */

typedef void (*load_dll_callback_t)( void *, const char * );

extern void *wine_dlopen( const char *filename, int flag, char *error, size_t errorsize );
extern void *wine_dlsym( void *handle, const char *symbol, char *error, size_t errorsize );
extern int wine_dlclose( void *handle, char *error, size_t errorsize );
extern void wine_dll_set_callback( load_dll_callback_t load );
extern void *wine_dll_load( const char *filename, char *error, int errorsize, int *file_exists );
extern void *wine_dll_load_main_exe( const char *name, char *error, int errorsize,
                                     int test_only, int *file_exists );
extern void wine_dll_unload( void *handle );
extern const char *wine_dll_enum_load_path( unsigned int index );
extern int wine_dll_get_owner( const char *name, char *buffer, int size, int *file_exists );

extern int __wine_main_argc;
extern char **__wine_main_argv;
extern WCHAR **__wine_main_wargv;
extern void __wine_dll_register( const IMAGE_NT_HEADERS *header, const char *filename );
extern void wine_init( int argc, char *argv[], char *error, int error_size );

/* portability */

extern void DECLSPEC_NORETURN wine_switch_to_stack( void (*func)(void *), void *arg, void *stack );
extern int wine_call_on_stack( int (*func)(void *), void *arg, void *stack );

/* memory mappings */

extern void *wine_anon_mmap( void *start, size_t size, int prot, int flags );
extern void wine_mmap_add_reserved_area( void *addr, size_t size );
extern void wine_mmap_remove_reserved_area( void *addr, size_t size, int unmap );
extern int wine_mmap_is_in_reserved_area( void *addr, size_t size );
extern int wine_mmap_enum_reserved_areas( int (*enum_func)(void *base, size_t size, void *arg),
                                          void *arg, int top_down );

#ifdef __i386__

/* LDT management */

extern void wine_ldt_init_locking( void (*lock_func)(void), void (*unlock_func)(void) );
extern void wine_ldt_get_entry( unsigned short sel, LDT_ENTRY *entry );
extern int wine_ldt_set_entry( unsigned short sel, const LDT_ENTRY *entry );
extern int wine_ldt_is_system( unsigned short sel );
extern void *wine_ldt_get_ptr( unsigned short sel, unsigned long offset );
extern unsigned short wine_ldt_alloc_entries( int count );
extern unsigned short wine_ldt_realloc_entries( unsigned short sel, int oldcount, int newcount );
extern void wine_ldt_free_entries( unsigned short sel, int count );
extern unsigned short wine_ldt_alloc_fs(void);
extern void wine_ldt_init_fs( unsigned short sel, const LDT_ENTRY *entry );
extern void wine_ldt_free_fs( unsigned short sel );

/* the local copy of the LDT */
extern struct __wine_ldt_copy
{
    void         *base[8192];  /* base address or 0 if entry is free   */
    unsigned long limit[8192]; /* limit in bytes or 0 if entry is free */
    unsigned char flags[8192]; /* flags (defined below) */
} wine_ldt_copy;

#define WINE_LDT_FLAGS_DATA      0x13  /* Data segment */
#define WINE_LDT_FLAGS_STACK     0x17  /* Stack segment */
#define WINE_LDT_FLAGS_CODE      0x1b  /* Code segment */
#define WINE_LDT_FLAGS_TYPE_MASK 0x1f  /* Mask for segment type */
#define WINE_LDT_FLAGS_32BIT     0x40  /* Segment is 32-bit (code or stack) */
#define WINE_LDT_FLAGS_ALLOCATED 0x80  /* Segment is allocated (no longer free) */

/* helper functions to manipulate the LDT_ENTRY structure */
static inline void wine_ldt_set_base( LDT_ENTRY *ent, const void *base )
{
    ent->BaseLow               = (WORD)(ULONG_PTR)base;
    ent->HighWord.Bits.BaseMid = (BYTE)((ULONG_PTR)base >> 16);
    ent->HighWord.Bits.BaseHi  = (BYTE)((ULONG_PTR)base >> 24);
}
static inline void wine_ldt_set_limit( LDT_ENTRY *ent, unsigned int limit )
{
    if ((ent->HighWord.Bits.Granularity = (limit >= 0x100000))) limit >>= 12;
    ent->LimitLow = (WORD)limit;
    ent->HighWord.Bits.LimitHi = (limit >> 16);
}
static inline void *wine_ldt_get_base( const LDT_ENTRY *ent )
{
    return (void *)(ent->BaseLow |
                    (ULONG_PTR)ent->HighWord.Bits.BaseMid << 16 |
                    (ULONG_PTR)ent->HighWord.Bits.BaseHi << 24);
}
static inline unsigned int wine_ldt_get_limit( const LDT_ENTRY *ent )
{
    unsigned int limit = ent->LimitLow | (ent->HighWord.Bits.LimitHi << 16);
    if (ent->HighWord.Bits.Granularity) limit = (limit << 12) | 0xfff;
    return limit;
}
static inline void wine_ldt_set_flags( LDT_ENTRY *ent, unsigned char flags )
{
    ent->HighWord.Bits.Dpl         = 3;
    ent->HighWord.Bits.Pres        = 1;
    ent->HighWord.Bits.Type        = flags;
    ent->HighWord.Bits.Sys         = 0;
    ent->HighWord.Bits.Reserved_0  = 0;
    ent->HighWord.Bits.Default_Big = (flags & WINE_LDT_FLAGS_32BIT) != 0;
}
static inline unsigned char wine_ldt_get_flags( const LDT_ENTRY *ent )
{
    unsigned char ret = ent->HighWord.Bits.Type;
    if (ent->HighWord.Bits.Default_Big) ret |= WINE_LDT_FLAGS_32BIT;
    return ret;
}
static inline int wine_ldt_is_empty( const LDT_ENTRY *ent )
{
    const DWORD *dw = (const DWORD *)ent;
    return (dw[0] | dw[1]) == 0;
}

/* segment register access */

# if defined(__GNUC__) && ((__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 2)))
#  define __DEFINE_GET_SEG(seg) \
    static FORCEINLINE unsigned short wine_get_##seg(void) \
    { unsigned short res; __asm__ __volatile__("movw %%" #seg ",%w0" : "=r"(res)); return res; }
#  define __DEFINE_SET_SEG(seg) \
    static FORCEINLINE void wine_set_##seg(int val) \
    { __asm__("movw %w0,%%" #seg : : "r" (val)); }
# elif defined(_MSC_VER)
#  define __DEFINE_GET_SEG(seg) \
    static inline unsigned short wine_get_##seg(void) \
    { unsigned short res; __asm { mov res, seg } return res; }
#  define __DEFINE_SET_SEG(seg) \
    static inline void wine_set_##seg(unsigned short val) { __asm { mov seg, val } }
# else  /* __GNUC__ || _MSC_VER */
#  define __DEFINE_GET_SEG(seg) extern unsigned short wine_get_##seg(void);
#  define __DEFINE_SET_SEG(seg) extern void wine_set_##seg(unsigned int);
# endif /* __GNUC__ || _MSC_VER */

__DEFINE_GET_SEG(cs)
__DEFINE_GET_SEG(ds)
__DEFINE_GET_SEG(es)
__DEFINE_GET_SEG(fs)
__DEFINE_GET_SEG(gs)
__DEFINE_GET_SEG(ss)
__DEFINE_SET_SEG(fs)
__DEFINE_SET_SEG(gs)
#undef __DEFINE_GET_SEG
#undef __DEFINE_SET_SEG

#endif  /* __i386__ */

#ifdef __cplusplus
}
#endif

#endif  /* __WINE_WINE_LIBRARY_H */
