/*
 * Copyright (C) 2010 Maarten Lankhorst for CodeWeavers
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

#ifndef _DEVPROPDEF_H_
#define _DEVPROPDEF_H_

typedef ULONG DEVPROPTYPE, *PDEVPROPTYPE;

#define DEVPROP_TYPEMOD_ARRAY 0x1000
#define DEVPROP_TYPEMOD_LIST 0x2000
#define MAX_DEVPROP_TYPEMOD DEVPROP_TYPEMOD_LIST

#define DEVPROP_TYPE_EMPTY 0x00
#define DEVPROP_TYPE_NULL 0x01
#define DEVPROP_TYPE_SBYTE 0x02
#define DEVPROP_TYPE_BYTE 0x03
#define DEVPROP_TYPE_INT16 0x04
#define DEVPROP_TYPE_UINT16 0x05
#define DEVPROP_TYPE_INT32 0x06
#define DEVPROP_TYPE_UINT32 0x07
#define DEVPROP_TYPE_INT64 0x08
#define DEVPROP_TYPE_UINT64 0x09
#define DEVPROP_TYPE_FLOAT 0x0a
#define DEVPROP_TYPE_DOUBLE 0x0b
#define DEVPROP_TYPE_DECIMAL 0x0c
#define DEVPROP_TYPE_GUID 0x0d
#define DEVPROP_TYPE_CURRENCY 0x0e
#define DEVPROP_TYPE_DATE 0x0f
#define DEVPROP_TYPE_FILETIME 0x10
#define DEVPROP_TYPE_BOOLEAN 0x11
#define DEVPROP_TYPE_STRING 0x12
#define DEVPROP_TYPE_STRING_LIST (DEVPROP_TYPE_STRING|DEVPROP_TYPEMOD_LIST)
#define DEVPROP_TYPE_SECURITY_DESCRIPTOR 0x13
#define DEVPROP_TYPE_SECURITY_DESCRIPTOR_STRING 0x14
#define DEVPROP_TYPE_DEVPROPKEY 0x15
#define DEVPROP_TYPE_DEVPROPTYPE 0x16
#define DEVPROP_TYPE_BINARY (DEVPROP_TYPE_BYTE|DEVPROP_TYPEMOD_ARRAY)
#define DEVPROP_TYPE_ERROR 0x17
#define DEVPROP_TYPE_NTSTATUS 0x18
#define DEVPROP_TYPE_STRING_INDIRECT 0x19
#define MAX_DEVPROP_TYPE DEVPROP_TYPE_STRING_INDIRECT

#define DEVPROP_MASK_TYPE 0x0fff
#define DEVPROP_MASK_TYPEMOD 0xf000

typedef CHAR DEVPROP_BOOLEAN, *PDEVPROP_BOOLEAN;
#define DEVPROP_TRUE ((DEVPROP_BOOLEAN)-1)
#define DEVPROP_FALSE ((DEVPROP_BOOLEAN)0)

#ifndef DEVPROPKEY_DEFINED
#define DEVPROPKEY_DEFINED
typedef GUID DEVPROPGUID, *PDEVPROPGUID;
typedef ULONG DEVPROPID, *PDEVPROPID;

typedef struct _DEVPROPKEY {
    DEVPROPGUID fmtid;
    DEVPROPID pid;
} DEVPROPKEY, *PDEVPROPKEY;

#define DEVPROPID_FIRST_USABLE 2

#endif /*DEVPROPKEY_DEFINED*/

#endif /*_DEVPROPDEF_H_*/

#undef DEFINE_DEVPROPKEY
#ifdef INITGUID
#ifdef __cplusplus
#define DEFINE_DEVPROPKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) \
        EXTERN_C const DEVPROPKEY name DECLSPEC_HIDDEN DECLSPEC_SELECTANY; \
        EXTERN_C const DEVPROPKEY name = \
        { { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }, pid }
#else
#define DEFINE_DEVPROPKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) \
        const DEVPROPKEY name DECLSPEC_HIDDEN DECLSPEC_SELECTANY; \
        const DEVPROPKEY name = \
        { { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }, pid }
#endif
#else
#define DEFINE_DEVPROPKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) \
    EXTERN_C const DEVPROPKEY name DECLSPEC_HIDDEN DECLSPEC_SELECTANY
#endif

#ifndef IsEqualDevPropKey
#ifdef __cplusplus
#define IsEqualDevPropKey(a,b) (((a).pid == (b).pid) && IsEqualIID((a).fmtid,(b).fmtid))
#else
#define IsEqualDevPropKey(a,b) (((a).pid == (b).pid) && IsEqualIID(&(a).fmtid,&(b).fmtid))
#endif
#endif
