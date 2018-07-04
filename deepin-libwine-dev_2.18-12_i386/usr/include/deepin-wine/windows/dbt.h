/*
 * Copyright (C) 2004 Ulrich Czekalla
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

#ifndef __WINE_DBT_H
#define __WINE_DBT_H

#ifndef GUID_DEFINED
# include <guiddef.h>
#endif

/* dbt.h doesn't use the normal convention, it adds an underscore before A/W */
#ifdef WINE_NO_UNICODE_MACROS
# define DECL_WINELIB_DBT_TYPE_AW(type)  /* nothing */
#else
# define DECL_WINELIB_DBT_TYPE_AW(type)  typedef WINELIB_NAME_AW(type##_) type;
#endif

#define DBT_DEVNODES_CHANGED            0x0007
#define DBT_QUERYCHANGECONFIG           0x0017
#define DBT_CONFIGCHANGED               0x0018
#define DBT_CONFIGCHANGECANCELED        0x0019
#define DBT_NO_DISK_SPACE               0x0047
#define DBT_LOW_DISK_SPACE              0x0048
#define DBT_CONFIGMGPRIVATE             0x7FFF
#define DBT_DEVICEARRIVAL               0x8000
#define DBT_DEVICEQUERYREMOVE           0x8001
#define DBT_DEVICEQUERYREMOVEFAILED     0x8002
#define DBT_DEVICEREMOVEPENDING         0x8003
#define DBT_DEVICEREMOVECOMPLETE        0x8004
#define DBT_DEVICETYPESPECIFIC          0x8005
#define DBT_CUSTOMEVENT                 0x8006

typedef struct _DEV_BROADCAST_HDR
{
    DWORD dbch_size;
    DWORD dbch_devicetype;
    DWORD dbch_reserved;
} DEV_BROADCAST_HDR, *PDEV_BROADCAST_HDR;

#define DBT_DEVTYP_OEM                  0x00000000
#define DBT_DEVTYP_DEVNODE              0x00000001
#define DBT_DEVTYP_VOLUME               0x00000002
#define DBT_DEVTYP_PORT                 0x00000003
#define DBT_DEVTYP_NET                  0x00000004
#define DBT_DEVTYP_DEVICEINTERFACE      0x00000005
#define DBT_DEVTYP_HANDLE               0x00000006

typedef struct _DEV_BROADCAST_OEM
{
    DWORD       dbco_size;
    DWORD       dbco_devicetype;
    DWORD       dbco_reserved;
    DWORD       dbco_identifier;
    DWORD       dbco_suppfunc;
} DEV_BROADCAST_OEM, *PDEV_BROADCAST_OEM;

typedef struct _DEV_BROADCAST_DEVNODE
{
    DWORD       dbcd_size;
    DWORD       dbcd_devicetype;
    DWORD       dbcd_reserved;
    DWORD       dbcd_devnode;
} DEV_BROADCAST_DEVNODE, *PDEV_BROADCAST_DEVNODE;

typedef struct _DEV_BROADCAST_VOLUME
{
    DWORD       dbcv_size;
    DWORD       dbcv_devicetype;
    DWORD       dbcv_reserved;
    DWORD       dbcv_unitmask;
    WORD        dbcv_flags;
} DEV_BROADCAST_VOLUME, *PDEV_BROADCAST_VOLUME;

#define DBTF_MEDIA 0x0001
#define DBTF_NET   0x0002

typedef struct _DEV_BROADCAST_PORT_A
{
    DWORD       dbcp_size;
    DWORD       dbcp_devicetype;
    DWORD       dbcp_reserved;
    char        dbcp_name[1];
} DEV_BROADCAST_PORT_A, *PDEV_BROADCAST_PORT_A;

typedef struct _DEV_BROADCAST_PORT_W
{
    DWORD       dbcp_size;
    DWORD       dbcp_devicetype;
    DWORD       dbcp_reserved;
    WCHAR       dbcp_name[1];
} DEV_BROADCAST_PORT_W, *PDEV_BROADCAST_PORT_W;

DECL_WINELIB_DBT_TYPE_AW(DEV_BROADCAST_PORT)
DECL_WINELIB_DBT_TYPE_AW(PDEV_BROADCAST_PORT)

typedef struct _DEV_BROADCAST_NET
{
    DWORD       dbcn_size;
    DWORD       dbcn_devicetype;
    DWORD       dbcn_reserved;
    DWORD       dbcn_resource;
    DWORD       dbcn_flags;
} DEV_BROADCAST_NET, *PDEV_BROADCAST_NET;

typedef struct _DEV_BROADCAST_DEVICEINTERFACE_A
{
    DWORD       dbcc_size;
    DWORD       dbcc_devicetype;
    DWORD       dbcc_reserved;
    GUID        dbcc_classguid;
    CHAR        dbcc_name[1];
} DEV_BROADCAST_DEVICEINTERFACE_A, *PDEV_BROADCAST_DEVICEINTERFACE_A;

typedef struct _DEV_BROADCAST_DEVICEINTERFACE_W
{
    DWORD       dbcc_size;
    DWORD       dbcc_devicetype;
    DWORD       dbcc_reserved;
    GUID        dbcc_classguid;
    WCHAR       dbcc_name[1];
} DEV_BROADCAST_DEVICEINTERFACE_W, *PDEV_BROADCAST_DEVICEINTERFACE_W;

DECL_WINELIB_DBT_TYPE_AW(DEV_BROADCAST_DEVICEINTERFACE)
DECL_WINELIB_DBT_TYPE_AW(PDEV_BROADCAST_DEVICEINTERFACE)

typedef struct _DEV_BROADCAST_HANDLE
{
    DWORD       dbch_size;
    DWORD       dbch_devicetype;
    DWORD       dbch_reserved;
    HANDLE      dbch_handle;
    HDEVNOTIFY  dbch_hdevnotify;
    GUID        dbch_eventguid;
    LONG        dbch_nameoffset;
    BYTE        dbch_data[1];
} DEV_BROADCAST_HANDLE, *PDEV_BROADCAST_HANDLE;

#undef DECL_WINELIB_DBT_TYPE_AW

#endif /* __WINE_DBT_H */
