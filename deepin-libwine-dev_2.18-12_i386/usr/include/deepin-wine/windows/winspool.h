/* Definitions for printing
 *
 * Copyright 1998 Huw Davies, Andreas Mohr
 *
 * Portions Copyright (c) 1999 Corel Corporation
 *                             (Paul Quinn, Albert Den Haan)
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
#ifndef __WINE_WINSPOOL_H
#define __WINE_WINSPOOL_H

#ifdef __cplusplus
extern "C" {
#endif

/* DEFINES */

#define PRINTER_ATTRIBUTE_QUEUED            0x00000001
#define PRINTER_ATTRIBUTE_DIRECT            0x00000002
#define PRINTER_ATTRIBUTE_DEFAULT           0x00000004
#define PRINTER_ATTRIBUTE_SHARED            0x00000008
#define PRINTER_ATTRIBUTE_NETWORK           0x00000010
#define PRINTER_ATTRIBUTE_HIDDEN            0x00000020
#define PRINTER_ATTRIBUTE_LOCAL             0x00000040
#define PRINTER_ATTRIBUTE_ENABLE_DEVQ       0x00000080
#define PRINTER_ATTRIBUTE_KEEPPRINTEDJOBS   0x00000100
#define PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST 0x00000200
#define PRINTER_ATTRIBUTE_WORK_OFFLINE      0x00000400
#define PRINTER_ATTRIBUTE_ENABLE_BIDI       0x00000800
#define PRINTER_ATTRIBUTE_RAW_ONLY          0x00001000
#define PRINTER_ATTRIBUTE_PUBLISHED         0x00002000

#define PRINTER_CONTROL_PAUSE      1
#define PRINTER_CONTROL_RESUME     2
#define PRINTER_CONTROL_PURGE      3
#define PRINTER_CONTROL_SET_STATUS 4

#define PRINTER_ENUM_DEFAULT     0x00000001
#define PRINTER_ENUM_LOCAL       0x00000002
#define PRINTER_ENUM_CONNECTIONS 0x00000004
#define PRINTER_ENUM_FAVORITE    0x00000004
#define PRINTER_ENUM_NAME        0x00000008
#define PRINTER_ENUM_REMOTE      0x00000010
#define PRINTER_ENUM_SHARED      0x00000020
#define PRINTER_ENUM_NETWORK     0x00000040

#define PRINTER_ENUM_EXPAND      0x00004000
#define PRINTER_ENUM_CONTAINER   0x00008000

#define PRINTER_ENUM_ICONMASK    0x00ff0000
#define PRINTER_ENUM_ICON1       0x00010000
#define PRINTER_ENUM_ICON2       0x00020000
#define PRINTER_ENUM_ICON3       0x00040000
#define PRINTER_ENUM_ICON4       0x00080000
#define PRINTER_ENUM_ICON5       0x00100000
#define PRINTER_ENUM_ICON6       0x00200000
#define PRINTER_ENUM_ICON7       0x00400000
#define PRINTER_ENUM_ICON8       0x00800000
#define PRINTER_ENUM_HIDE        0x01000000


/* various printer statuses */
#define PRINTER_STATUS_PAUSED            0x00000001
#define PRINTER_STATUS_ERROR             0x00000002
#define PRINTER_STATUS_PENDING_DELETION  0x00000004
#define PRINTER_STATUS_PAPER_JAM         0x00000008
#define PRINTER_STATUS_PAPER_OUT         0x00000010
#define PRINTER_STATUS_MANUAL_FEED       0x00000020
#define PRINTER_STATUS_PAPER_PROBLEM     0x00000040
#define PRINTER_STATUS_OFFLINE           0x00000080
#define PRINTER_STATUS_IO_ACTIVE         0x00000100
#define PRINTER_STATUS_BUSY              0x00000200
#define PRINTER_STATUS_PRINTING          0x00000400
#define PRINTER_STATUS_OUTPUT_BIN_FULL   0x00000800
#define PRINTER_STATUS_NOT_AVAILABLE     0x00001000
#define PRINTER_STATUS_WAITING           0x00002000
#define PRINTER_STATUS_PROCESSING        0x00004000
#define PRINTER_STATUS_INITIALIZING      0x00008000
#define PRINTER_STATUS_WARMING_UP        0x00010000
#define PRINTER_STATUS_TONER_LOW         0x00020000
#define PRINTER_STATUS_NO_TONER          0x00040000
#define PRINTER_STATUS_PAGE_PUNT         0x00080000
#define PRINTER_STATUS_USER_INTERVENTION 0x00100000
#define PRINTER_STATUS_OUT_OF_MEMORY     0x00200000
#define PRINTER_STATUS_DOOR_OPEN         0x00400000
#define PRINTER_STATUS_SERVER_UNKNOWN    0x00800000
#define PRINTER_STATUS_POWER_SAVE        0x01000000
#define PRINTER_STATUS_SERVER_OFFLINE    0x02000000
#define PRINTER_STATUS_DRIVER_UPDATE_NEEDED 0x04000000

#define NO_PRIORITY  0
#define MAX_PRIORITY 99
#define MIN_PRIORITY 1
#define DEF_PRIORITY 1

#define JOB_CONTROL_PAUSE             1
#define JOB_CONTROL_RESUME            2
#define JOB_CONTROL_CANCEL            3
#define JOB_CONTROL_RESTART           4
#define JOB_CONTROL_DELETE            5
#define JOB_CONTROL_SENT_TO_PRINTER   6
#define JOB_CONTROL_LAST_PAGE_EJECTED 7

#define JOB_STATUS_PAUSED       0x0001
#define JOB_STATUS_ERROR        0x0002
#define JOB_STATUS_DELETING     0x0004
#define JOB_STATUS_SPOOLING     0x0008
#define JOB_STATUS_PRINTING     0x0010
#define JOB_STATUS_OFFLINE      0x0020
#define JOB_STATUS_PAPEROUT     0x0040
#define JOB_STATUS_PRINTED      0x0080
#define JOB_STATUS_DELETED      0x0100
#define JOB_STATUS_BLOCKED_DEVQ 0x0200
#define JOB_STATUS_USER_INTERVENTION 0x0400

#define JOB_POSITION_UNSPECIFIED 1

#define DI_CHANNEL 1
#define DI_READ_SPOOL_JOB 3

#define FORM_USER    0
#define FORM_BUILTIN 1
#define FORM_PRINTER 2

#define PORT_TYPE_WRITE        1
#define PORT_TYPE_READ         2
#define PORT_TYPE_REDIRECTED   4
#define PORT_TYPE_NET_ATTACHED 8

#define PORT_STATUS_TYPE_ERROR   1
#define PORT_STATUS_TYPE_WARNING 2
#define PORT_STATUS_TYPE_INFO    3

#define PORT_STATUS_OFFLINE           1
#define PORT_STATUS_PAPER_JAM         2
#define PORT_STATUS_PAPER_OUT         3
#define PORT_STATUS_OUTPUT_BIN_FULL   4
#define PORT_STATUS_PAPER_PROBLEM     5
#define PORT_STATUS_NO_TONER          6
#define PORT_STATUS_DOOR_OPEN         7
#define PORT_STATUS_USER_INTERVENTION 8
#define PORT_STATUS_OUT_OF_MEMORY     9
#define PORT_STATUS_TONER_LOW         10
#define PORT_STATUS_WARMING_UP        11
#define PORT_STATUS_POWER_SAVE        12

#define PRINTER_NOTIFY_TYPE 0
#define JOB_NOTIFY_TYPE     1

#define PRINTER_NOTIFY_FIELD_SERVER_NAME     0x00
#define PRINTER_NOTIFY_FIELD_PRINTER_NAME    0x01
#define PRINTER_NOTIFY_FIELD_SHARE_NAME      0x02
#define PRINTER_NOTIFY_FIELD_PORT_NAME       0x03
#define PRINTER_NOTIFY_FIELD_DRIVER_NAME     0x04
#define PRINTER_NOTIFY_FIELD_COMMENT         0x05
#define PRINTER_NOTIFY_FIELD_LOCATION        0x06
#define PRINTER_NOTIFY_FIELD_DEVMODE         0x07
#define PRINTER_NOTIFY_FIELD_SEPFILE         0x08
#define PRINTER_NOTIFY_FIELD_PRINT_PROCESSOR 0x09
#define PRINTER_NOTIFY_FIELD_PARAMETERS      0x0a
#define PRINTER_NOTIFY_FIELD_DATATYPE        0x0b
#define PRINTER_NOTIFY_FIELD_SECURITY_DESCRIPTOR 0x0c
#define PRINTER_NOTIFY_FIELD_ATTRIBUTES      0x0d
#define PRINTER_NOTIFY_FIELD_PRIORITY        0x0e
#define PRINTER_NOTIFY_FIELD_DEFAULT_PRIORITY 0x0f
#define PRINTER_NOTIFY_FIELD_START_TIME      0x10
#define PRINTER_NOTIFY_FIELD_UNTIL_TIME      0x11
#define PRINTER_NOTIFY_FIELD_STATUS          0x12
#define PRINTER_NOTIFY_FIELD_STATUS_STRING   0x13
#define PRINTER_NOTIFY_FIELD_CJOBS           0x14
#define PRINTER_NOTIFY_FIELD_AVERAGE_PPM     0x15
#define PRINTER_NOTIFY_FIELD_TOTAL_PAGES     0x16
#define PRINTER_NOTIFY_FIELD_PAGES_PRINTED   0x17
#define PRINTER_NOTIFY_FIELD_TOTAL_BYTES     0x18
#define PRINTER_NOTIFY_FIELD_BYTES_PRINTED   0x19

#define JOB_NOTIFY_FIELD_PRINTER_NAME    0x00
#define JOB_NOTIFY_FIELD_MACHINE_NAME    0x01
#define JOB_NOTIFY_FIELD_PORT_NAME       0x02
#define JOB_NOTIFY_FIELD_USER_NAME       0x03
#define JOB_NOTIFY_FIELD_NOTIFY_NAME     0x04
#define JOB_NOTIFY_FIELD_DATATYPE        0x05
#define JOB_NOTIFY_FIELD_PRINT_PROCESSOR 0x06
#define JOB_NOTIFY_FIELD_PARAMETERS      0x07
#define JOB_NOTIFY_FIELD_DRIVER_NAME     0x08
#define JOB_NOTIFY_FIELD_DEVMODE         0x09
#define JOB_NOTIFY_FIELD_STATUS          0x0a
#define JOB_NOTIFY_FIELD_STATUS_STRING   0x0b
#define JOB_NOTIFY_FIELD_SECURITY_DESCRIPTOR 0x0c
#define JOB_NOTIFY_FIELD_DOCUMENT        0x0d
#define JOB_NOTIFY_FIELD_PRIORITY        0x0e
#define JOB_NOTIFY_FIELD_POSITION        0x0f
#define JOB_NOTIFY_FIELD_SUBMITTED       0x10
#define JOB_NOTIFY_FIELD_START_TIME      0x11
#define JOB_NOTIFY_FIELD_UNTIL_TIME      0x12
#define JOB_NOTIFY_FIELD_TIME            0x13
#define JOB_NOTIFY_FIELD_TOTAL_PAGES     0x14
#define JOB_NOTIFY_FIELD_PAGES_PRINTED   0x15
#define JOB_NOTIFY_FIELD_TOTAL_BYTES     0x16
#define JOB_NOTIFY_FIELD_BYTES_PRINTED   0x17

#define PRINTER_NOTIFY_OPTIONS_REFRESH   1
#define PRINTER_NOTIFY_INFO_DISCARDED    1

#define PRINTER_CHANGE_ADD_PRINTER               0x00000001
#define PRINTER_CHANGE_SET_PRINTER               0x00000002
#define PRINTER_CHANGE_DELETE_PRINTER            0x00000004
#define PRINTER_CHANGE_FAILED_CONNECTION_PRINTER 0x00000008
#define PRINTER_CHANGE_PRINTER                   0x000000ff
#define PRINTER_CHANGE_ADD_JOB                   0x00000100
#define PRINTER_CHANGE_SET_JOB                   0x00000200
#define PRINTER_CHANGE_DELETE_JOB                0x00000400
#define PRINTER_CHANGE_WRITE_JOB                 0x00000800
#define PRINTER_CHANGE_JOB                       0x0000ff00
#define PRINTER_CHANGE_ADD_FORM                  0x00010000
#define PRINTER_CHANGE_SET_FORM                  0x00020000
#define PRINTER_CHANGE_DELETE_FORM               0x00040000
#define PRINTER_CHANGE_FORM                      0x00070000
#define PRINTER_CHANGE_ADD_PORT                  0x00100000
#define PRINTER_CHANGE_CONFIGURE_PORT            0x00200000
#define PRINTER_CHANGE_DELETE_PORT               0x00400000
#define PRINTER_CHANGE_PORT                      0x00700000
#define PRINTER_CHANGE_ADD_PRINT_PROCESSOR       0x01000000
#define PRINTER_CHANGE_DELETE_PRINTER_PROCESSOR  0x04000000
#define PRINTER_CHANGE_PRINT_PROCESSOR           0x07000000
#define PRINTER_CHANGE_ADD_PRINTER_DRIVER        0x10000000
#define PRINTER_CHANGE_SET_PRINTER_DRIVER        0x20000000
#define PRINTER_CHANGE_DELETE_PRINTER_DRIVER     0x40000000
#define PRINTER_CHANGE_PRINTER_DRIVER            0x70000000
#define PRINTER_CHANGE_TIMEOUT                   0x80000000
#define PRINTER_CHANGE_ALL                       0x7777ffff

#define PRINTER_ERROR_INFORMATION   0x80000000
#define PRINTER_ERROR_WARNING       0x40000000
#define PRINTER_ERROR_SEVERE        0x20000000

#define PRINTER_ERROR_OUTODPAPER    0x00000001
#define PRINTER_ERROR_JAM           0x00000002
#define PRINTER_ERROR_OUTOFTONER    0x00000004

/* Access Rights for Printserver, Printers and Printjobs */
#define SERVER_ACCESS_ADMINISTER    0x00000001
#define SERVER_ACCESS_ENUMERATE     0x00000002
#define SERVER_READ        (STANDARD_RIGHTS_READ | SERVER_ACCESS_ENUMERATE)
#define SERVER_WRITE       (STANDARD_RIGHTS_WRITE | \
                            SERVER_ACCESS_ADMINISTER | SERVER_ACCESS_ENUMERATE)
#define SERVER_EXECUTE     (STANDARD_RIGHTS_EXECUTE |  SERVER_ACCESS_ENUMERATE)
#define SERVER_ALL_ACCESS  (STANDARD_RIGHTS_REQUIRED | \
                            SERVER_ACCESS_ADMINISTER | SERVER_ACCESS_ENUMERATE)

#define PRINTER_ACCESS_ADMINISTER   0x00000004
#define PRINTER_ACCESS_USE          0x00000008
#define PRINTER_READ        (STANDARD_RIGHTS_READ | PRINTER_ACCESS_USE)
#define PRINTER_WRITE       (STANDARD_RIGHTS_WRITE | PRINTER_ACCESS_USE)
#define PRINTER_EXECUTE     (STANDARD_RIGHTS_EXECUTE | PRINTER_ACCESS_USE)
#define PRINTER_ALL_ACCESS  (STANDARD_RIGHTS_REQUIRED | \
                             PRINTER_ACCESS_ADMINISTER | PRINTER_ACCESS_USE)

#define JOB_ACCESS_ADMINISTER       0x00000010
#define JOB_READ            (STANDARD_RIGHTS_READ | JOB_ACCESS_ADMINISTER)
#define JOB_WRITE           (STANDARD_RIGHTS_WRITE | JOB_ACCESS_ADMINISTER)
#define JOB_EXECUTE         (STANDARD_RIGHTS_EXECUTE | JOB_ACCESS_ADMINISTER)
#define JOB_ALL_ACCESS      (STANDARD_RIGHTS_REQUIRED | JOB_ACCESS_ADMINISTER)


/* Flags for printer drivers */
#define DRIVER_KERNELMODE       0x00000001
#define DRIVER_USERMODE         0x00000002

#define APD_STRICT_UPGRADE      0x00000001
#define APD_STRICT_DOWNGRADE    0x00000002
#define APD_COPY_ALL_FILES      0x00000004
#define APD_COPY_NEW_FILES      0x00000008
#define APD_COPY_FROM_DIRECTORY 0x00000010

#define DPD_DELETE_UNUSED_FILES     0x00000001
#define DPD_DELETE_SPECIFIC_VERSION 0x00000002
#define DPD_DELETE_ALL_FILES        0x00000004

/* dwAction for PRINTER_INFO_7 */
#define DSPRINT_PUBLISH     0x00000001
#define DSPRINT_UPDATE      0x00000002
#define DSPRINT_UNPUBLISH   0x00000004
#define DSPRINT_REPUBLISH   0x00000008
#define DSPRINT_PENDING     0x80000000

#define UPDP_SILENT_UPLOAD      0x00000001
#define UPDP_UPLOAD_ALWAYS      0x00000002
#define UPDP_CHECK_DRIVERSTORE  0x00000004

/* ##################################### */

/* TYPES */
typedef struct _PRINTER_DEFAULTSA {
  LPSTR        pDatatype;
  LPDEVMODEA pDevMode;
  ACCESS_MASK  DesiredAccess;
} PRINTER_DEFAULTSA, *LPPRINTER_DEFAULTSA;

typedef struct _PRINTER_DEFAULTSW {
  LPWSTR       pDatatype;
  LPDEVMODEW pDevMode;
  ACCESS_MASK  DesiredAccess;
} PRINTER_DEFAULTSW, *LPPRINTER_DEFAULTSW;

DECL_WINELIB_TYPE_AW(PRINTER_DEFAULTS)
DECL_WINELIB_TYPE_AW(LPPRINTER_DEFAULTS)

typedef struct _DRIVER_INFO_1A {
  LPSTR     pName;
} DRIVER_INFO_1A, *PDRIVER_INFO_1A, *LPDRIVER_INFO_1A;

typedef struct _DRIVER_INFO_1W {
  LPWSTR    pName;
} DRIVER_INFO_1W, *PDRIVER_INFO_1W, *LPDRIVER_INFO_1W;

DECL_WINELIB_TYPE_AW(DRIVER_INFO_1)
DECL_WINELIB_TYPE_AW(PDRIVER_INFO_1)
DECL_WINELIB_TYPE_AW(LPDRIVER_INFO_1)

typedef struct _DRIVER_INFO_2A {
  DWORD     cVersion;
  LPSTR     pName;
  LPSTR     pEnvironment;
  LPSTR     pDriverPath;
  LPSTR     pDataFile;
  LPSTR     pConfigFile;
} DRIVER_INFO_2A, *PDRIVER_INFO_2A, *LPDRIVER_INFO_2A;

typedef struct _DRIVER_INFO_2W {
  DWORD     cVersion;
  LPWSTR    pName;
  LPWSTR    pEnvironment;
  LPWSTR    pDriverPath;
  LPWSTR    pDataFile;
  LPWSTR    pConfigFile;
} DRIVER_INFO_2W, *PDRIVER_INFO_2W, *LPDRIVER_INFO_2W;

DECL_WINELIB_TYPE_AW(DRIVER_INFO_2)
DECL_WINELIB_TYPE_AW(PDRIVER_INFO_2)
DECL_WINELIB_TYPE_AW(LPDRIVER_INFO_2)

typedef struct _DRIVER_INFO_3A {
  DWORD cVersion;
  LPSTR pName;
  LPSTR pEnvironment;
  LPSTR pDriverPath;
  LPSTR pDataFile;
  LPSTR pConfigFile;
  LPSTR pHelpFile;
  LPSTR pDependentFiles;
  LPSTR pMonitorName;
  LPSTR pDefaultDataType;
} DRIVER_INFO_3A, *PDRIVER_INFO_3A, *LPDRIVER_INFO_3A;

typedef struct _DRIVER_INFO_3W {
  DWORD cVersion;
  LPWSTR pName;
  LPWSTR pEnvironment;
  LPWSTR pDriverPath;
  LPWSTR pDataFile;
  LPWSTR pConfigFile;
  LPWSTR pHelpFile;
  LPWSTR pDependentFiles;
  LPWSTR pMonitorName;
  LPWSTR pDefaultDataType;
} DRIVER_INFO_3W, *PDRIVER_INFO_3W, *LPDRIVER_INFO_3W;

DECL_WINELIB_TYPE_AW(DRIVER_INFO_3)
DECL_WINELIB_TYPE_AW(PDRIVER_INFO_3)
DECL_WINELIB_TYPE_AW(LPDRIVER_INFO_3)

typedef struct _DRIVER_INFO_4A {
  DWORD cVersion;
  LPSTR pName;
  LPSTR pEnvironment;
  LPSTR pDriverPath;
  LPSTR pDataFile;
  LPSTR pConfigFile;
  LPSTR pHelpFile;
  LPSTR pDependentFiles;
  LPSTR pMonitorName;
  LPSTR pDefaultDataType;
  LPSTR pszzPreviousNames;
} DRIVER_INFO_4A, *PDRIVER_INFO_4A, *LPDRIVER_INFO_4A;

typedef struct _DRIVER_INFO_4W {
  DWORD cVersion;
  LPWSTR pName;
  LPWSTR pEnvironment;
  LPWSTR pDriverPath;
  LPWSTR pDataFile;
  LPWSTR pConfigFile;
  LPWSTR pHelpFile;
  LPWSTR pDependentFiles;
  LPWSTR pMonitorName;
  LPWSTR pDefaultDataType;
  LPWSTR pszzPreviousNames;
} DRIVER_INFO_4W, *PDRIVER_INFO_4W, *LPDRIVER_INFO_4W;

DECL_WINELIB_TYPE_AW(DRIVER_INFO_4)
DECL_WINELIB_TYPE_AW(PDRIVER_INFO_4)
DECL_WINELIB_TYPE_AW(LPDRIVER_INFO_4)


typedef struct _DRIVER_INFO_5A {
  DWORD cVersion;
  LPSTR pName;
  LPSTR pEnvironment;
  LPSTR pDriverPath;
  LPSTR pDataFile;
  LPSTR pConfigFile;
  DWORD dwDriverAttributes;
  DWORD dwConfigVersion;
  DWORD dwDriverVersion;
} DRIVER_INFO_5A, *PDRIVER_INFO_5A, *LPDRIVER_INFO_5A;

typedef struct _DRIVER_INFO_5W {
  DWORD  cVersion;
  LPWSTR pName;
  LPWSTR pEnvironment;
  LPWSTR pDriverPath;
  LPWSTR pDataFile;
  LPWSTR pConfigFile;
  DWORD  dwDriverAttributes;
  DWORD  dwConfigVersion;
  DWORD  dwDriverVersion;
} DRIVER_INFO_5W, *PDRIVER_INFO_5W, *LPDRIVER_INFO_5W;

DECL_WINELIB_TYPE_AW(DRIVER_INFO_5)
DECL_WINELIB_TYPE_AW(PDRIVER_INFO_5)
DECL_WINELIB_TYPE_AW(LPDRIVER_INFO_5)

typedef struct _DRIVER_INFO_6A {
  DWORD     cVersion;
  LPSTR     pName;
  LPSTR     pEnvironment;
  LPSTR     pDriverPath;
  LPSTR     pDataFile;
  LPSTR     pConfigFile;
  LPSTR     pHelpFile;
  LPSTR     pDependentFiles;
  LPSTR     pMonitorName;
  LPSTR     pDefaultDataType;
  LPSTR     pszzPreviousNames;
  FILETIME  ftDriverDate;
  DWORDLONG dwlDriverVersion;
  LPSTR     pszMfgName;
  LPSTR     pszOEMUrl;
  LPSTR     pszHardwareID;
  LPSTR     pszProvider;
} DRIVER_INFO_6A, *PDRIVER_INFO_6A, *LPDRIVER_INFO_6A;

typedef struct _DRIVER_INFO_6W {
  DWORD     cVersion;
  LPWSTR    pName;
  LPWSTR    pEnvironment;
  LPWSTR    pDriverPath;
  LPWSTR    pDataFile;
  LPWSTR    pConfigFile;
  LPWSTR    pHelpFile;
  LPWSTR    pDependentFiles;
  LPWSTR    pMonitorName;
  LPWSTR    pDefaultDataType;
  LPWSTR    pszzPreviousNames;
  FILETIME  ftDriverDate;
  DWORDLONG dwlDriverVersion;
  LPWSTR    pszMfgName;
  LPWSTR    pszOEMUrl;
  LPWSTR    pszHardwareID;
  LPWSTR    pszProvider;
} DRIVER_INFO_6W, *PDRIVER_INFO_6W, *LPDRIVER_INFO_6W;

DECL_WINELIB_TYPE_AW(DRIVER_INFO_6)
DECL_WINELIB_TYPE_AW(PDRIVER_INFO_6)
DECL_WINELIB_TYPE_AW(LPDRIVER_INFO_6)

/* DRIVER_INFO_7 is not defined in native winspool.h and not found in the www */

typedef struct _DRIVER_INFO_8A {
  DWORD     cVersion;
  LPSTR     pName;
  LPSTR     pEnvironment;
  LPSTR     pDriverPath;
  LPSTR     pDataFile;
  LPSTR     pConfigFile;
  LPSTR     pHelpFile;
  LPSTR     pDependentFiles;
  LPSTR     pMonitorName;
  LPSTR     pDefaultDataType;
  LPSTR     pszzPreviousNames;
  FILETIME  ftDriverDate;
  DWORDLONG dwlDriverVersion;
  LPSTR     pszMfgName;
  LPSTR     pszOEMUrl;
  LPSTR     pszHardwareID;
  LPSTR     pszProvider;
  LPSTR     pszPrintProcessor;
  LPSTR     pszVendorSetup;
  LPSTR     pszzColorProfiles;
  LPSTR     pszInfPath;
  DWORD     dwPrinterDriverAttributes;
  LPSTR     pszzCoreDriverDependencies;
  FILETIME  ftMinInboxDriverVerDate;
  DWORDLONG dwlMinInboxDriverVerVersion;
} DRIVER_INFO_8A, *PDRIVER_INFO_8A, *LPDRIVER_INFO_8A;

typedef struct _DRIVER_INFO_8W {
  DWORD     cVersion;
  LPWSTR    pName;
  LPWSTR    pEnvironment;
  LPWSTR    pDriverPath;
  LPWSTR    pDataFile;
  LPWSTR    pConfigFile;
  LPWSTR    pHelpFile;
  LPWSTR    pDependentFiles;
  LPWSTR    pMonitorName;
  LPWSTR    pDefaultDataType;
  LPWSTR    pszzPreviousNames;
  FILETIME  ftDriverDate;
  DWORDLONG dwlDriverVersion;
  LPWSTR    pszMfgName;
  LPWSTR    pszOEMUrl;
  LPWSTR    pszHardwareID;
  LPWSTR    pszProvider;
  LPWSTR    pszPrintProcessor;
  LPWSTR    pszVendorSetup;
  LPWSTR    pszzColorProfiles;
  LPWSTR    pszInfPath;
  DWORD     dwPrinterDriverAttributes;
  LPWSTR    pszzCoreDriverDependencies;
  FILETIME  ftMinInboxDriverVerDate;
  DWORDLONG dwlMinInboxDriverVerVersion;
} DRIVER_INFO_8W, *PDRIVER_INFO_8W, *LPDRIVER_INFO_8W;

DECL_WINELIB_TYPE_AW(DRIVER_INFO_8)
DECL_WINELIB_TYPE_AW(PDRIVER_INFO_8)
DECL_WINELIB_TYPE_AW(LPDRIVER_INFO_8)


typedef struct _PRINTER_INFO_1A {
  DWORD   Flags;
  LPSTR   pDescription;
  LPSTR   pName;
  LPSTR   pComment;
} PRINTER_INFO_1A, *PPRINTER_INFO_1A, *LPPRINTER_INFO_1A;

typedef struct _PRINTER_INFO_1W {
  DWORD   Flags;
  LPWSTR  pDescription;
  LPWSTR  pName;
  LPWSTR  pComment;
} PRINTER_INFO_1W, *PPRINTER_INFO_1W, *LPPRINTER_INFO_1W;

DECL_WINELIB_TYPE_AW(PRINTER_INFO_1)
DECL_WINELIB_TYPE_AW(PPRINTER_INFO_1)
DECL_WINELIB_TYPE_AW(LPPRINTER_INFO_1)

/* FIXME: winspool.h declares some structure members with the name Status.
 * unfortunately <X11/ICE/ICElib.h> #defines Status to the type 'int'
 * therefore the following hack */
#ifndef Status

typedef struct _PRINTER_INFO_2A {
  LPSTR     pServerName;
  LPSTR     pPrinterName;
  LPSTR     pShareName;
  LPSTR     pPortName;
  LPSTR     pDriverName;
  LPSTR     pComment;
  LPSTR     pLocation;
  LPDEVMODEA pDevMode;
  LPSTR     pSepFile;
  LPSTR     pPrintProcessor;
  LPSTR     pDatatype;
  LPSTR     pParameters;
  PSECURITY_DESCRIPTOR pSecurityDescriptor;
  DWORD   Attributes;
  DWORD   Priority;
  DWORD   DefaultPriority;
  DWORD   StartTime;
  DWORD   UntilTime;
  DWORD   Status;
  DWORD   cJobs;
  DWORD   AveragePPM;
} PRINTER_INFO_2A, *PPRINTER_INFO_2A, *LPPRINTER_INFO_2A;

typedef struct _PRINTER_INFO_2W {
  LPWSTR    pServerName;
  LPWSTR    pPrinterName;
  LPWSTR    pShareName;
  LPWSTR    pPortName;
  LPWSTR    pDriverName;
  LPWSTR    pComment;
  LPWSTR    pLocation;
  LPDEVMODEW pDevMode;
  LPWSTR    pSepFile;
  LPWSTR    pPrintProcessor;
  LPWSTR    pDatatype;
  LPWSTR    pParameters;
  PSECURITY_DESCRIPTOR pSecurityDescriptor;
  DWORD   Attributes;
  DWORD   Priority;
  DWORD   DefaultPriority;
  DWORD   StartTime;
  DWORD   UntilTime;
  DWORD   Status;
  DWORD   cJobs;
  DWORD   AveragePPM;
} PRINTER_INFO_2W, *PPRINTER_INFO_2W, *LPPRINTER_INFO_2W;

DECL_WINELIB_TYPE_AW(PRINTER_INFO_2)
DECL_WINELIB_TYPE_AW(PPRINTER_INFO_2)
DECL_WINELIB_TYPE_AW(LPPRINTER_INFO_2)

typedef struct _PRINTER_INFO_3 {
  PSECURITY_DESCRIPTOR pSecurityDescriptor;
} PRINTER_INFO_3, *PPRINTER_INFO_3, *LPPRINTER_INFO_3;

typedef struct _PRINTER_INFO_4A {
  LPSTR     pPrinterName;
  LPSTR     pServerName;
  DWORD     Attributes;
} PRINTER_INFO_4A, *PPRINTER_INFO_4A, *LPPRINTER_INFO_4A;

typedef struct _PRINTER_INFO_4W {
  LPWSTR     pPrinterName;
  LPWSTR     pServerName;
  DWORD     Attributes;
} PRINTER_INFO_4W, *PPRINTER_INFO_4W, *LPPRINTER_INFO_4W;

DECL_WINELIB_TYPE_AW(PRINTER_INFO_4)
DECL_WINELIB_TYPE_AW(PPRINTER_INFO_4)
DECL_WINELIB_TYPE_AW(LPPRINTER_INFO_4)

typedef struct _PRINTER_INFO_5A {
  LPSTR     pPrinterName;
  LPSTR     pPortName;
  DWORD     Attributes;
  DWORD     DeviceNotSelectedTimeout;
  DWORD     TransmissionRetryTimeout;
} PRINTER_INFO_5A, *PPRINTER_INFO_5A, *LPPRINTER_INFO_5A;

typedef struct _PRINTER_INFO_5W {
  LPWSTR    pPrinterName;
  LPWSTR    pPortName;
  DWORD     Attributes;
  DWORD     DeviceNotSelectedTimeout;
  DWORD     TransmissionRetryTimeout;
} PRINTER_INFO_5W, *PPRINTER_INFO_5W, *LPPRINTER_INFO_5W;

DECL_WINELIB_TYPE_AW(PRINTER_INFO_5)
DECL_WINELIB_TYPE_AW(PPRINTER_INFO_5)
DECL_WINELIB_TYPE_AW(LPPRINTER_INFO_5)

typedef struct _PRINTER_INFO_6 {
  DWORD dwStatus;
} PRINTER_INFO_6, *PPRINTER_INFO_6, *LPPRINTER_INFO_6;

typedef struct _PRINTER_INFO_7A {
  LPSTR     pszObjectGUID;
  DWORD     dwAction;
} PRINTER_INFO_7A, *PPRINTER_INFO_7A, *LPPRINTER_INFO_7A;

typedef struct _PRINTER_INFO_7W {
  LPWSTR    pszObjectGUID;
  DWORD     dwAction;
} PRINTER_INFO_7W, *PPRINTER_INFO_7W, *LPPRINTER_INFO_7W;

DECL_WINELIB_TYPE_AW(PRINTER_INFO_7)
DECL_WINELIB_TYPE_AW(PPRINTER_INFO_7)
DECL_WINELIB_TYPE_AW(LPPRINTER_INFO_7)

typedef struct _PRINTER_INFO_8A {
  LPDEVMODEA pDevMode;
} PRINTER_INFO_8A, *PPRINTER_INFO_8A, *LPPRINTER_INFO_8A;

typedef struct _PRINTER_INFO_8W {
  LPDEVMODEW pDevMode;
} PRINTER_INFO_8W, *PPRINTER_INFO_8W, *LPPRINTER_INFO_8W;

DECL_WINELIB_TYPE_AW(PRINTER_INFO_8)
DECL_WINELIB_TYPE_AW(PPRINTER_INFO_8)
DECL_WINELIB_TYPE_AW(LPPRINTER_INFO_8)

typedef struct _PRINTER_INFO_9A {
  LPDEVMODEA pDevMode;
} PRINTER_INFO_9A, *PPRINTER_INFO_9A, *LPPRINTER_INFO_9A;

typedef struct _PRINTER_INFO_9W {
  LPDEVMODEW pDevMode;
} PRINTER_INFO_9W, *PPRINTER_INFO_9W, *LPPRINTER_INFO_9W;

DECL_WINELIB_TYPE_AW(PRINTER_INFO_9)
DECL_WINELIB_TYPE_AW(PPRINTER_INFO_9)
DECL_WINELIB_TYPE_AW(LPPRINTER_INFO_9)


typedef struct _JOB_INFO_1A {
  DWORD JobId;
  LPSTR pPrinterName;
  LPSTR pMachineName;
  LPSTR pUserName;
  LPSTR pDocument;
  LPSTR pDatatype;
  LPSTR pStatus;
  DWORD Status;
  DWORD Priority;
  DWORD Position;
  DWORD TotalPages;
  DWORD PagesPrinted;
  SYSTEMTIME Submitted;
} JOB_INFO_1A, *PJOB_INFO_1A, *LPJOB_INFO_1A;

typedef struct _JOB_INFO_1W {
  DWORD JobId;
  LPWSTR pPrinterName;
  LPWSTR pMachineName;
  LPWSTR pUserName;
  LPWSTR pDocument;
  LPWSTR pDatatype;
  LPWSTR pStatus;
  DWORD Status;
  DWORD Priority;
  DWORD Position;
  DWORD TotalPages;
  DWORD PagesPrinted;
  SYSTEMTIME Submitted;
} JOB_INFO_1W, *PJOB_INFO_1W, *LPJOB_INFO_1W;

DECL_WINELIB_TYPE_AW(JOB_INFO_1)
DECL_WINELIB_TYPE_AW(PJOB_INFO_1)
DECL_WINELIB_TYPE_AW(LPJOB_INFO_1)

typedef struct _JOB_INFO_2A {
  DWORD JobId;
  LPSTR pPrinterName;
  LPSTR pMachineName;
  LPSTR pUserName;
  LPSTR pDocument;
  LPSTR pNotifyName;
  LPSTR pDatatype;
  LPSTR pPrintProcessor;
  LPSTR pParameters;
  LPSTR pDriverName;
  LPDEVMODEA pDevMode;
  LPSTR pStatus;
  PSECURITY_DESCRIPTOR pSecurityDescriptor;
  DWORD Status;
  DWORD Priority;
  DWORD Position;
  DWORD StartTime;
  DWORD UntilTime;
  DWORD TotalPages;
  DWORD Size;
  SYSTEMTIME Submitted;
  DWORD Time;
  DWORD PagesPrinted;
} JOB_INFO_2A, *PJOB_INFO_2A, *LPJOB_INFO_2A;

typedef struct _JOB_INFO_2W {
  DWORD JobId;
  LPWSTR pPrinterName;
  LPWSTR pMachineName;
  LPWSTR pUserName;
  LPWSTR pDocument;
  LPWSTR pNotifyName;
  LPWSTR pDatatype;
  LPWSTR pPrintProcessor;
  LPWSTR pParameters;
  LPWSTR pDriverName;
  LPDEVMODEW pDevMode;
  LPWSTR pStatus;
  PSECURITY_DESCRIPTOR pSecurityDescriptor;
  DWORD Status;
  DWORD Priority;
  DWORD Position;
  DWORD StartTime;
  DWORD UntilTime;
  DWORD TotalPages;
  DWORD Size;
  SYSTEMTIME Submitted;
  DWORD Time;
  DWORD PagesPrinted;
} JOB_INFO_2W, *PJOB_INFO_2W, *LPJOB_INFO_2W;

DECL_WINELIB_TYPE_AW(JOB_INFO_2)
DECL_WINELIB_TYPE_AW(PJOB_INFO_2)
DECL_WINELIB_TYPE_AW(LPJOB_INFO_2)

typedef struct _JOB_INFO_3 {
  DWORD JobId;
  DWORD NextJobId;
  DWORD Reserved;
} JOB_INFO_3, *PJOB_INFO_3, *LPJOB_INFO_3;

typedef struct _ADDJOB_INFO_1A {
  LPSTR Path;
  DWORD JobId;
} ADDJOB_INFO_1A, *PADDJOB_INFO_1A, *LPADDJOB_INFO_1A;

typedef struct _ADDJOB_INFO_1W {
  LPWSTR Path;
  DWORD  JobId;
} ADDJOB_INFO_1W, *PADDJOB_INFO_1W, *LPADDJOB_INFO_1W;

DECL_WINELIB_TYPE_AW(ADDJOB_INFO_1)
DECL_WINELIB_TYPE_AW(PADDJOB_INFO_1)
DECL_WINELIB_TYPE_AW(LPADDJOB_INFO_1)

typedef struct _DOC_INFO_1A {
  LPSTR pDocName;
  LPSTR pOutputFile;
  LPSTR pDatatype;
} DOC_INFO_1A, *PDOC_INFO_1A, *LPDOC_INFO_1A;

typedef struct _DOC_INFO_1W {
  LPWSTR pDocName;
  LPWSTR pOutputFile;
  LPWSTR pDatatype;
} DOC_INFO_1W, *PDOC_INFO_1W, *LPDOC_INFO_1W;

DECL_WINELIB_TYPE_AW(DOC_INFO_1)
DECL_WINELIB_TYPE_AW(PDOC_INFO_1)
DECL_WINELIB_TYPE_AW(LPDOC_INFO_1)

typedef struct _DOC_INFO_2A {
  LPSTR pDocName;
  LPSTR pOutputFile;
  LPSTR pDatatype;
  DWORD dwMode;
  DWORD JobId;
} DOC_INFO_2A, *PDOC_INFO_2A, *LPDOC_INFO_2A;

typedef struct _DOC_INFO_2W {
  LPWSTR pDocName;
  LPWSTR pOutputFile;
  LPWSTR pDatatype;
  DWORD dwMode;
  DWORD JobId;
} DOC_INFO_2W, *PDOC_INFO_2W, *LPDOC_INFO_2W;

DECL_WINELIB_TYPE_AW(DOC_INFO_2)
DECL_WINELIB_TYPE_AW(PDOC_INFO_2)
DECL_WINELIB_TYPE_AW(LPDOC_INFO_2)

typedef struct _FORM_INFO_1A {
  DWORD Flags;
  LPSTR pName;
  SIZEL Size;
  RECTL ImageableArea;
} FORM_INFO_1A, *PFORM_INFO_1A, *LPFORM_INFO_1A;

typedef struct _FORM_INFO_1W {
  DWORD Flags;
  LPWSTR pName;
  SIZEL Size;
  RECTL ImageableArea;
} FORM_INFO_1W, *PFORM_INFO_1W, *LPFORM_INFO_1W;

DECL_WINELIB_TYPE_AW(FORM_INFO_1)
DECL_WINELIB_TYPE_AW(PFORM_INFO_1)
DECL_WINELIB_TYPE_AW(LPFORM_INFO_1)

typedef struct _FORM_INFO_2A {
  DWORD  Flags;
  LPSTR  pName;
  SIZEL  Size;
  RECTL  ImageableArea;
  LPCSTR pKeyword;
  DWORD  StringType;
  LPSTR  pMuiDll;
  DWORD  dwResourceId;
  LPSTR  pDisplayName;
  LANGID wLangId;
} FORM_INFO_2A, *PFORM_INFO_2A, *LPFORM_INFO_2A;

typedef struct _FORM_INFO_2W {
  DWORD  Flags;
  LPWSTR pName;
  SIZEL  Size;
  RECTL  ImageableArea;
  LPCSTR pKeyword;
  DWORD  StringType;
  LPWSTR pMuiDll;
  DWORD  dwResourceId;
  LPWSTR pDisplayName;
  LANGID wLangId;
} FORM_INFO_2W, *PFORM_INFO_2W, *LPFORM_INFO_2W;

DECL_WINELIB_TYPE_AW(FORM_INFO_2)
DECL_WINELIB_TYPE_AW(PFORM_INFO_2)
DECL_WINELIB_TYPE_AW(LPFORM_INFO_2)

typedef struct _PRINTPROCESSOR_INFO_1A {
  LPSTR pName;
} PRINTPROCESSOR_INFO_1A, *PPRINTPROCESSOR_INFO_1A,
  *LPPRINTPROCESSOR_INFO_1A;

typedef struct _PRINTPROCESSOR_INFO_1W {
  LPWSTR pName;
} PRINTPROCESSOR_INFO_1W, *PPRINTPROCESSOR_INFO_1W,
  *LPPRINTPROCESSOR_INFO_1W;

DECL_WINELIB_TYPE_AW(PRINTPROCESSOR_INFO_1)
DECL_WINELIB_TYPE_AW(PPRINTPROCESSOR_INFO_1)
DECL_WINELIB_TYPE_AW(LPPRINTPROCESSOR_INFO_1)

typedef struct _PORT_INFO_1A {
  LPSTR pName;
} PORT_INFO_1A, *PPORT_INFO_1A, *LPPORT_INFO_1A;

typedef struct _PORT_INFO_1W {
  LPWSTR pName;
} PORT_INFO_1W, *PPORT_INFO_1W, *LPPORT_INFO_1W;

DECL_WINELIB_TYPE_AW(PORT_INFO_1)
DECL_WINELIB_TYPE_AW(PPORT_INFO_1)
DECL_WINELIB_TYPE_AW(LPPORT_INFO_1)

typedef struct _PORT_INFO_2A {
  LPSTR pPortName;
  LPSTR pMonitorName;
  LPSTR pDescription;
  DWORD fPortType;
  DWORD Reserved;
} PORT_INFO_2A, *PPORT_INFO_2A, *LPPORT_INFO_2A;

typedef struct _PORT_INFO_2W {
  LPWSTR pPortName;
  LPWSTR pMonitorName;
  LPWSTR pDescription;
  DWORD  fPortType;
  DWORD  Reserved;
} PORT_INFO_2W, *PPORT_INFO_2W, *LPPORT_INFO_2W;

DECL_WINELIB_TYPE_AW(PORT_INFO_2)
DECL_WINELIB_TYPE_AW(PPORT_INFO_2)
DECL_WINELIB_TYPE_AW(LPPORT_INFO_2)

typedef struct _PORT_INFO_3A {
  DWORD dwStatus;
  LPSTR pszStatus;
  DWORD dwSeverity;
} PORT_INFO_3A, *PPORT_INFO_3A, *LPPORT_INFO_3A;

typedef struct _PORT_INFO_3W {
  DWORD  dwStatus;
  LPWSTR pszStatus;
  DWORD  dwSeverity;
} PORT_INFO_3W, *PPORT_INFO_3W, *LPPORT_INFO_3W;

DECL_WINELIB_TYPE_AW(PORT_INFO_3)
DECL_WINELIB_TYPE_AW(PPORT_INFO_3)
DECL_WINELIB_TYPE_AW(LPPORT_INFO_3)

typedef struct _MONITOR_INFO_1A {
  LPSTR pName;
} MONITOR_INFO_1A, *PMONITOR_INFO_1A, *LPMONITOR_INFO_1A;

typedef struct _MONITOR_INFO_1W {
  LPWSTR pName;
} MONITOR_INFO_1W, *PMONITOR_INFO_1W, *LPMONITOR_INFO_1W;

DECL_WINELIB_TYPE_AW(MONITOR_INFO_1)
DECL_WINELIB_TYPE_AW(PMONITOR_INFO_1)
DECL_WINELIB_TYPE_AW(LPMONITOR_INFO_1)

#endif /* Status */


typedef struct _MONITOR_INFO_2A {
  LPSTR pName;
  LPSTR pEnvironment;
  LPSTR pDLLName;
} MONITOR_INFO_2A, *PMONITOR_INFO_2A, *LPMONITOR_INFO_2A;

typedef struct _MONITOR_INFO_2W {
  LPWSTR pName;
  LPWSTR pEnvironment;
  LPWSTR pDLLName;
} MONITOR_INFO_2W, *PMONITOR_INFO_2W, *LPMONITOR_INFO_2W;

DECL_WINELIB_TYPE_AW(MONITOR_INFO_2)
DECL_WINELIB_TYPE_AW(PMONITOR_INFO_2)
DECL_WINELIB_TYPE_AW(LPMONITOR_INFO_2)

typedef struct _DATATYPES_INFO_1A {
  LPSTR pName;
} DATATYPES_INFO_1A, *PDATATYPES_INFO_1A, *LPDATATYPES_INFO_1A;

typedef struct _DATATYPES_INFO_1W {
  LPWSTR pName;
} DATATYPES_INFO_1W, *PDATATYPES_INFO_1W, *LPDATATYPES_INFO_1W;

DECL_WINELIB_TYPE_AW(DATATYPES_INFO_1)
DECL_WINELIB_TYPE_AW(PDATATYPES_INFO_1)
DECL_WINELIB_TYPE_AW(LPDATATYPES_INFO_1)

typedef struct _PRINTER_NOTIFY_OPTIONS_TYPE {
  WORD  Type;
  WORD  Reserved0;
  DWORD Reserved1;
  DWORD Reserved2;
  DWORD Count;
  PWORD pFields;
} PRINTER_NOTIFY_OPTIONS_TYPE, *PPRINTER_NOTIFY_OPTIONS_TYPE,
*LPPRINTER_NOTIFY_OPTIONS_TYPE;

typedef struct _PRINTER_NOTIFY_OPTIONS {
  DWORD Version;
  DWORD Flags;
  DWORD Count;
  PPRINTER_NOTIFY_OPTIONS_TYPE pTypes;
} PRINTER_NOTIFY_OPTIONS, *PPRINTER_NOTIFY_OPTIONS, *LPPRINTER_NOTIFY_OPTIONS;

typedef struct _PRINTER_NOTIFY_INFO_DATA {
  WORD Type;
  WORD Field;
  DWORD Reserved;
  DWORD Id;
  union {
    DWORD adwData[2];
    struct {
      DWORD cbBuf;
      LPVOID pBuf;
    } Data;
  } NotifyData;
} PRINTER_NOTIFY_INFO_DATA, *PPRINTER_NOTIFY_INFO_DATA,
*LPPRINTER_NOTIFY_INFO_DATA;

typedef struct _PRINTER_NOTIFY_INFO {
  DWORD Version;
  DWORD Flags;
  DWORD Count;
  PRINTER_NOTIFY_INFO_DATA aData[1];
} PRINTER_NOTIFY_INFO, *PPRINTER_NOTIFY_INFO, *LPPRINTER_NOTIFY_INFO;

typedef struct _PROVIDOR_INFO_1A {
  LPSTR pName;
  LPSTR pEnvironment;
  LPSTR pDLLName;
} PROVIDOR_INFO_1A, *PPROVIDOR_INFO_1A, *LPPROVIDOR_INFO_1A;

typedef struct _PROVIDOR_INFO_1W {
  LPWSTR pName;
  LPWSTR pEnvironment;
  LPWSTR pDLLName;
} PROVIDOR_INFO_1W, *PPROVIDOR_INFO_1W, *LPPROVIDOR_INFO_1W;

DECL_WINELIB_TYPE_AW(PROVIDOR_INFO_1)
DECL_WINELIB_TYPE_AW(PPROVIDOR_INFO_1)
DECL_WINELIB_TYPE_AW(LPPROVIDOR_INFO_1)

typedef struct _PRINTER_ENUM_VALUESA {
  LPSTR	 pValueName;
  DWORD  cbValueName;
  DWORD  dwType;
  LPBYTE pData;
  DWORD  cbData;
} PRINTER_ENUM_VALUESA, *PPRINTER_ENUM_VALUESA;

typedef struct _PRINTER_ENUM_VALUESW {
  LPWSTR pValueName;
  DWORD  cbValueName;
  DWORD  dwType;
  LPBYTE pData;
  DWORD  cbData;
} PRINTER_ENUM_VALUESW, *PPRINTER_ENUM_VALUESW;

DECL_WINELIB_TYPE_AW(PRINTER_ENUM_VALUES)
DECL_WINELIB_TYPE_AW(PPRINTER_ENUM_VALUES)

typedef enum {
 BIDI_NULL = 0,
 BIDI_INT,
 BIDI_FLOAT,
 BIDI_BOOL,
 BIDI_STRING,
 BIDI_TEXT,
 BIDI_ENUM,
 BIDI_BLOB
} BIDI_TYPE;

typedef struct _BINARY_CONTAINER {
 DWORD  cbBuf;
 LPBYTE pData;
} BINARY_CONTAINER, *PBINARY_CONTAINER;

typedef struct _BIDI_DATA {
 DWORD  dwBidiType;
 union
 {
   BOOL             bData;
   INT              iData;
   LPWSTR           sData;
   FLOAT            fData;
   BINARY_CONTAINER biData;
 } u;
} BIDI_DATA, *LPBIDI_DATA, *PBIDI_DATA;

typedef struct _BIDI_REQUEST_DATA {
 DWORD      dwReqNumber;
 LPWSTR     pSchema;
 BIDI_DATA  data;
} BIDI_REQUEST_DATA, *LPBIDI_REQUEST_DATA, *PBIDI_REQUEST_DATA;

typedef struct _BIDI_REQUEST_CONTAINER {
 DWORD              Version;
 DWORD              Flags;
 DWORD              Count;
 BIDI_REQUEST_DATA  aData[1];
} BIDI_REQUEST_CONTAINER, *LPBIDI_REQUEST_CONTAINER, *PBIDI_REQUEST_CONTAINER;

typedef struct _BIDI_RESPONSE_DATA {
 DWORD      dwResult;
 DWORD      dwReqNumber;
 LPWSTR     pSchema;
 BIDI_DATA  data;
} BIDI_RESPONSE_DATA, *LPBIDI_RESPONSE_DATA, *PBIDI_RESPONSE_DATA;

typedef struct _BIDI_RESPONSE_CONTAINER {
 DWORD              Version;
 DWORD              Flags;
 DWORD              Count;
 BIDI_RESPONSE_DATA aData[1];
} BIDI_RESPONSE_CONTAINER, *LPBIDI_RESPONSE_CONTAINER, *PBIDI_RESPONSE_CONTAINER;

/* string constants */

#define SPLREG_DEFAULT_SPOOL_DIRECTORYA "DefaultSpoolDirectory"
#ifdef _MSC_VER
#define SPLREG_DEFAULT_SPOOL_DIRECTORYW L"DefaultSpoolDirectory"
#elif defined(__GNUC__)
#define SPLREG_DEFAULT_SPOOL_DIRECTORYW (const WCHAR[]){'D','e','f','a','u','l','t','S','p','o','o','l','D','i','r','e','c','t','o','r','y',0}
#else
static const WCHAR SPLREG_DEFAULT_SPOOL_DIRECTORYW[] = {'D','e','f','a','u','l','t','S','p','o','o','l','D','i','r','e','c','t','o','r','y',0};
#endif
#define SPLREG_DEFAULT_SPOOL_DIRECTORY WINELIB_NAME_AW(SPLREG_DEFAULT_SPOOL_DIRECTORY)

#define SPLREG_PORT_THREAD_PRIORITY_DEFAULTA "PortThreadPriorityDefault"
#ifdef _MSC_VER
#define SPLREG_PORT_THREAD_PRIORITY_DEFAULTW L"PortThreadPriorityDefault"
#elif defined(__GNUC__)
#define SPLREG_PORT_THREAD_PRIORITY_DEFAULTW (const WCHAR[]){'P','o','r','t','T','h','r','e','a','d','P','r','i','o','r','i','t','y','D','e','f','a','u','l','t',0}
#else
static const WCHAR SPLREG_PORT_THREAD_PRIORITY_DEFAULTW[] = {'P','o','r','t','T','h','r','e','a','d','P','r','i','o','r','i','t','y','D','e','f','a','u','l','t',0};
#endif
#define SPLREG_PORT_THREAD_PRIORITY_DEFAULT WINELIB_NAME_AW(SPLREG_PORT_THREAD_PRIORITY_DEFAULT)

#define SPLREG_PORT_THREAD_PRIORITYA "PortThreadPriority"
#ifdef _MSC_VER
#define SPLREG_PORT_THREAD_PRIORITYW L"PortThreadPriority"
#elif defined(__GNUC__)
#define SPLREG_PORT_THREAD_PRIORITYW (const WCHAR[]){'P','o','r','t','T','h','r','e','a','d','P','r','i','o','r','i','t','y',0}
#else
static const WCHAR SPLREG_PORT_THREAD_PRIORITYW[] = {'P','o','r','t','T','h','r','e','a','d','P','r','i','o','r','i','t','y',0};
#endif
#define SPLREG_PORT_THREAD_PRIORITY WINELIB_NAME_AW(SPLREG_PORT_THREAD_PRIORITY)

#define SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULTA "SchedulerThreadPriorityDefault"
#ifdef _MSC_VER
#define SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULTW L"SchedulerThreadPriorityDefault"
#elif defined(__GNUC__)
#define SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULTW (const WCHAR[]){'S','c','h','e','d','u','l','e','r','T','h','r','e','a','d','P','r','i','o','r','i','t','y','D','e','f','a','u','l','t',0}
#else
static const WCHAR SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULTW[] = {'S','c','h','e','d','u','l','e','r','T','h','r','e','a','d','P','r','i','o','r','i','t','y','D','e','f','a','u','l','t',0};
#endif
#define SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULT WINELIB_NAME_AW(SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULT)

#define SPLREG_SCHEDULER_THREAD_PRIORITYA "SchedulerThreadPriority"
#ifdef _MSC_VER
#define SPLREG_SCHEDULER_THREAD_PRIORITYW L"SchedulerThreadPriority"
#elif defined(__GNUC__)
#define SPLREG_SCHEDULER_THREAD_PRIORITYW (const WCHAR[]){'S','c','h','e','d','u','l','e','r','T','h','r','e','a','d','P','r','i','o','r','i','t','y',0}
#else
static const WCHAR SPLREG_SCHEDULER_THREAD_PRIORITYW[] = {'S','c','h','e','d','u','l','e','r','T','h','r','e','a','d','P','r','i','o','r','i','t','y',0};
#endif
#define SPLREG_SCHEDULER_THREAD_PRIORITY WINELIB_NAME_AW(SPLREG_SCHEDULER_THREAD_PRIORITY)

#define SPLREG_BEEP_ENABLEDA "BeepEnabled"
#ifdef _MSC_VER
#define SPLREG_BEEP_ENABLEDW L"BeepEnabled"
#elif defined(__GNUC__)
#define SPLREG_BEEP_ENABLEDW (const WCHAR[]){'B','e','e','p','E','n','a','b','l','e','d',0}
#else
static const WCHAR SPLREG_BEEP_ENABLEDW[] = {'B','e','e','p','E','n','a','b','l','e','d',0};
#endif
#define SPLREG_BEEP_ENABLED WINELIB_NAME_AW(SPLREG_BEEP_ENABLED)

#define SPLREG_NET_POPUPA "NetPopup"
#ifdef _MSC_VER
#define SPLREG_NET_POPUPW L"NetPopup"
#elif defined(__GNUC__)
#define SPLREG_NET_POPUPW (const WCHAR[]){'N','e','t','P','o','p','u','p',0}
#else
static const WCHAR SPLREG_NET_POPUPW[] = {'N','e','t','P','o','p','u','p',0};
#endif
#define SPLREG_NET_POPUP WINELIB_NAME_AW(SPLREG_NET_POPUP)

#define SPLREG_RETRY_POPUPA "RetryPopup"
#ifdef _MSC_VER
#define SPLREG_RETRY_POPUPW L"RetryPopup"
#elif defined(__GNUC__)
#define SPLREG_RETRY_POPUPW (const WCHAR[]){'R','e','t','r','y','P','o','p','u','p',0}
#else
static const WCHAR SPLREG_RETRY_POPUPW[] = {'R','e','t','r','y','P','o','p','u','p',0};
#endif
#define SPLREG_RETRY_POPUP WINELIB_NAME_AW(SPLREG_RETRY_POPUP)

#define SPLREG_NET_POPUP_TO_COMPUTERA "NetPopupToComputer"
#ifdef _MSC_VER
#define SPLREG_NET_POPUP_TO_COMPUTERW L"NetPopupToComputer"
#elif defined(__GNUC__)
#define SPLREG_NET_POPUP_TO_COMPUTERW (const WCHAR[]){'N','e','t','P','o','p','u','p','T','o','C','o','m','p','u','t','e','r',0}
#else
static const WCHAR SPLREG_NET_POPUP_TO_COMPUTERW[] = {'N','e','t','P','o','p','u','p','T','o','C','o','m','p','u','t','e','r',0};
#endif
#define SPLREG_NET_POPUP_TO_COMPUTER WINELIB_NAME_AW(SPLREG_NET_POPUP_TO_COMPUTER)

#define SPLREG_EVENT_LOGA "EventLog"
#ifdef _MSC_VER
#define SPLREG_EVENT_LOGW L"EventLog"
#elif defined(__GNUC__)
#define SPLREG_EVENT_LOGW (const WCHAR[]){'E','v','e','n','t','L','o','g',0}
#else
static const WCHAR SPLREG_EVENT_LOGW[] = {'E','v','e','n','t','L','o','g',0};
#endif
#define SPLREG_EVENT_LOG WINELIB_NAME_AW(SPLREG_EVENT_LOG)

#define SPLREG_MAJOR_VERSIONA "MajorVersion"
#ifdef _MSC_VER
#define SPLREG_MAJOR_VERSIONW L"MajorVersion"
#elif defined(__GNUC__)
#define SPLREG_MAJOR_VERSIONW (const WCHAR[]){'M','a','j','o','r','V','e','r','s','i','o','n',0}
#else
static const WCHAR SPLREG_MAJOR_VERSIONW[] = {'M','a','j','o','r','V','e','r','s','i','o','n',0};
#endif
#define SPLREG_MAJOR_VERSION WINELIB_NAME_AW(SPLREG_MAJOR_VERSION)

#define SPLREG_MINOR_VERSIONA "MinorVersion"
#ifdef _MSC_VER
#define SPLREG_MINOR_VERSIONW L"MinorVersion"
#elif defined(__GNUC__)
#define SPLREG_MINOR_VERSIONW (const WCHAR[]){'M','i','n','o','r','V','e','r','s','i','o','n',0}
#else
static const WCHAR SPLREG_MINOR_VERSIONW[] = {'M','i','n','o','r','V','e','r','s','i','o','n',0};
#endif
#define SPLREG_MINOR_VERSION WINELIB_NAME_AW(SPLREG_MINOR_VERSION)

#define SPLREG_ARCHITECTUREA "Architecture"
#ifdef _MSC_VER
#define SPLREG_ARCHITECTUREW L"Architecture"
#elif defined(__GNUC__)
#define SPLREG_ARCHITECTUREW (const WCHAR[]){'A','r','c','h','i','t','e','c','t','u','r','e',0}
#else
static const WCHAR SPLREG_ARCHITECTUREW[] = {'A','r','c','h','i','t','e','c','t','u','r','e',0};
#endif
#define SPLREG_ARCHITECTURE WINELIB_NAME_AW(SPLREG_ARCHITECTURE)

#define SPLREG_OS_VERSIONA "OSVersion"
#ifdef _MSC_VER
#define SPLREG_OS_VERSIONW L"OSVersion"
#elif defined(__GNUC__)
#define SPLREG_OS_VERSIONW (const WCHAR[]){'O','S','V','e','r','s','i','o','n',0}
#else
static const WCHAR SPLREG_OS_VERSIONW[] = {'O','S','V','e','r','s','i','o','n',0};
#endif
#define SPLREG_OS_VERSION WINELIB_NAME_AW(SPLREG_OS_VERSION)

#define SPLREG_OS_VERSIONEXA "OSVersionEx"
#ifdef _MSC_VER
#define SPLREG_OS_VERSIONEXW L"OSVersionEx"
#elif defined(__GNUC__)
#define SPLREG_OS_VERSIONEXW (const WCHAR[]){'O','S','V','e','r','s','i','o','n','E','x',0}
#else
static const WCHAR SPLREG_OS_VERSIONEXW[] = {'O','S','V','e','r','s','i','o','n','E','x',0};
#endif
#define SPLREG_OS_VERSIONEX WINELIB_NAME_AW(SPLREG_OS_VERSIONEX)

#define SPLREG_DS_PRESENTA "DsPresent"
#ifdef _MSC_VER
#define SPLREG_DS_PRESENTW L"DsPresent"
#elif defined(__GNUC__)
#define SPLREG_DS_PRESENTW (const WCHAR[]){'D','s','P','r','e','s','e','n','t',0}
#else
static const WCHAR SPLREG_DS_PRESENTW[] = {'D','s','P','r','e','s','e','n','t',0};
#endif
#define SPLREG_DS_PRESENT WINELIB_NAME_AW(SPLREG_DS_PRESENT)

#define SPLREG_DS_PRESENT_FOR_USERA "DsPresentForUser"
#ifdef _MSC_VER
#define SPLREG_DS_PRESENT_FOR_USERW L"DsPresentForUser"
#elif defined(__GNUC__)
#define SPLREG_DS_PRESENT_FOR_USERW (const WCHAR[]){'D','s','P','r','e','s','e','n','t','F','o','r','U','s','e','r',0}
#else
static const WCHAR SPLREG_DS_PRESENT_FOR_USERW[] = {'D','s','P','r','e','s','e','n','t','F','o','r','U','s','e','r',0};
#endif
#define SPLREG_DS_PRESENT_FOR_USER WINELIB_NAME_AW(SPLREG_DS_PRESENT_FOR_USER)

#define SPLREG_REMOTE_FAXA "RemoteFax"
#ifdef _MSC_VER
#define SPLREG_REMOTE_FAXW L"RemoteFax"
#elif defined(__GNUC__)
#define SPLREG_REMOTE_FAXW (const WCHAR[]){'R','e','m','o','t','e','F','a','x',0}
#else
static const WCHAR SPLREG_REMOTE_FAXW[] = {'R','e','m','o','t','e','F','a','x',0};
#endif
#define SPLREG_REMOTE_FAX WINELIB_NAME_AW(SPLREG_REMOTE_FAX)

#define SPLREG_RESTART_JOB_ON_POOL_ERRORA "RestartJobOnPoolError"
#ifdef _MSC_VER
#define SPLREG_RESTART_JOB_ON_POOL_ERRORW L"RestartJobOnPoolError"
#elif defined(__GNUC__)
#define SPLREG_RESTART_JOB_ON_POOL_ERRORW (const WCHAR[]){'R','e','s','t','a','r','t','J','o','b','O','n','P','o','o','l','E','r','r','o','r',0}
#else
static const WCHAR SPLREG_RESTART_JOB_ON_POOL_ERRORW[] = {'R','e','s','t','a','r','t','J','o','b','O','n','P','o','o','l','E','r','r','o','r',0};
#endif
#define SPLREG_RESTART_JOB_ON_POOL_ERROR WINELIB_NAME_AW(SPLREG_RESTART_JOB_ON_POOL_ERROR)

#define SPLREG_RESTART_JOB_ON_POOL_ENABLEDA "RestartJobOnPoolEnabled"
#ifdef _MSC_VER
#define SPLREG_RESTART_JOB_ON_POOL_ENABLEDW L"RestartJobOnPoolEnabled"
#elif defined(__GNUC__)
#define SPLREG_RESTART_JOB_ON_POOL_ENABLEDW (const WCHAR[]){'R','e','s','t','a','r','t','J','o','b','O','n','P','o','o','l','E','n','a','b','l','e','d',0}
#else
static const WCHAR SPLREG_RESTART_JOB_ON_POOL_ENABLEDW[] = {'R','e','s','t','a','r','t','J','o','b','O','n','P','o','o','l','E','n','a','b','l','e','d',0};
#endif
#define SPLREG_RESTART_JOB_ON_POOL_ENABLED WINELIB_NAME_AW(SPLREG_RESTART_JOB_ON_POOL_ENABLED)

#define SPLREG_DNS_MACHINE_NAMEA "DNSMachineName"
#ifdef _MSC_VER
#define SPLREG_DNS_MACHINE_NAMEW L"DNSMachineName"
#elif defined(__GNUC__)
#define SPLREG_DNS_MACHINE_NAMEW (const WCHAR[]){'D','N','S','M','a','c','h','i','n','e','N','a','m','e',0}
#else
static const WCHAR SPLREG_DNS_MACHINE_NAMEW[] = {'D','N','S','M','a','c','h','i','n','e','N','a','m','e',0};
#endif
#define SPLREG_DNS_MACHINE_NAME WINELIB_NAME_AW(SPLREG_DNS_MACHINE_NAME)

#define SPLREG_ALLOW_USER_MANAGEFORMSA "AllowUserManageForms"
#ifdef _MSC_VER
#define SPLREG_ALLOW_USER_MANAGEFORMSW L"AllowUserManageForms"
#elif defined(__GNUC__)
#define SPLREG_ALLOW_USER_MANAGEFORMSW (const WCHAR[]){'A','l','l','o','w','U','s','e','r','M','a','n','a','g','e','F','o','r','m','s',0}
#else
static const WCHAR SPLREG_ALLOW_USER_MANAGEFORMSW[] = {'A','l','l','o','w','U','s','e','r','M','a','n','a','g','e','F','o','r','m','s',0};
#endif
#define SPLREG_ALLOW_USER_MANAGEFORMS WINELIB_NAME_AW(SPLREG_ALLOW_USER_MANAGEFORMS)

#define SPLREG_WEBSHAREMGMTA "WebShareMgmt"
#ifdef _MSC_VER
#define SPLREG_WEBSHAREMGMTW L"WebShareMgmt"
#elif defined(__GNUC__)
#define SPLREG_WEBSHAREMGMTW (const WCHAR[]){'W','e','b','S','h','a','r','e','M','g','m','t',0}
#else
static const WCHAR SPLREG_WEBSHAREMGMTW[] = {'W','e','b','S','h','a','r','e','M','g','m','t',0};
#endif
#define SPLREG_WEBSHAREMGMT WINELIB_NAME_AW(SPLREG_WEBSHAREMGMT)

#define SPLREG_PRINT_DRIVER_ISOLATION_GROUPSA "PrintDriverIsolationGroups"
#ifdef _MSC_VER
#define SPLREG_PRINT_DRIVER_ISOLATION_GROUPSW L"PrintDriverIsolationGroups"
#elif defined(__GNUC__)
#define SPLREG_PRINT_DRIVER_ISOLATION_GROUPSW (const WCHAR[]){'P','r','i','n','t','D','r','i','v','e','r','I','s','o','l','a','t','i','o','n','G','r','o','u','p','s',0}
#else
static const WCHAR SPLREG_PRINT_DRIVER_ISOLATION_GROUPSW[] = {'P','r','i','n','t','D','r','i','v','e','r','I','s','o','l','a','t','i','o','n','G','r','o','u','p','s',0};
#endif
#define SPLREG_PRINT_DRIVER_ISOLATION_GROUPS WINELIB_NAME_AW(SPLREG_PRINT_DRIVER_ISOLATION_GROUPS)

#define SPLREG_PRINT_DRIVER_ISOLATION_TIME_BEFORE_RECYCLEA "PrintDriverIsolationTimeBeforeRecycle"
#ifdef _MSC_VER
#define SPLREG_PRINT_DRIVER_ISOLATION_TIME_BEFORE_RECYCLEW L"PrintDriverIsolationTimeBeforeRecycle"
#elif defined(__GNUC__)
#define SPLREG_PRINT_DRIVER_ISOLATION_TIME_BEFORE_RECYCLEW (const WCHAR[]){'P','r','i','n','t','D','r','i','v','e','r','I','s','o','l','a','t','i','o','n','T','i','m','e','B','e','f','o','r','e','R','e','c','y','c','l','e',0}
#else
static const WCHAR SPLREG_PRINT_DRIVER_ISOLATION_TIME_BEFORE_RECYCLEW[] = {'P','r','i','n','t','D','r','i','v','e','r','I','s','o','l','a','t','i','o','n','T','i','m','e','B','e','f','o','r','e','R','e','c','y','c','l','e',0};
#endif
#define SPLREG_PRINT_DRIVER_ISOLATION_TIME_BEFORE_RECYCLE WINELIB_NAME_AW(SPLREG_PRINT_DRIVER_ISOLATION_TIME_BEFORE_RECYCLE)

#define SPLREG_PRINT_DRIVER_ISOLATION_MAX_OBJECTS_BEFORE_RECYCLEA "PrintDriverIsolationMaxobjsBeforeRecycle"
#ifdef _MSC_VER
#define SPLREG_PRINT_DRIVER_ISOLATION_MAX_OBJECTS_BEFORE_RECYCLEW L"PrintDriverIsolationMaxobjsBeforeRecycle"
#elif defined(__GNUC__)
#define SPLREG_PRINT_DRIVER_ISOLATION_MAX_OBJECTS_BEFORE_RECYCLEW (const WCHAR[]){'P','r','i','n','t','D','r','i','v','e','r','I','s','o','l','a','t','i','o','n','M','a','x','o','b','j','s','B','e','f','o','r','e','R','e','c','y','c','l','e',0}
#else
static const WCHAR SPLREG_PRINT_DRIVER_ISOLATION_MAX_OBJECTS_BEFORE_RECYCLEW[] = {'P','r','i','n','t','D','r','i','v','e','r','I','s','o','l','a','t','i','o','n','M','a','x','o','b','j','s','B','e','f','o','r','e','R','e','c','y','c','l','e',0};
#endif
#define SPLREG_PRINT_DRIVER_ISOLATION_MAX_OBJECTS_BEFORE_RECYCLE WINELIB_NAME_AW(SPLREG_PRINT_DRIVER_ISOLATION_MAX_OBJECTS_BEFORE_RECYCLE)

#define SPLREG_PRINT_DRIVER_ISOLATION_IDLE_TIMEOUTA "PrintDriverIsolationIdleTimeout"
#ifdef _MSC_VER
#define SPLREG_PRINT_DRIVER_ISOLATION_IDLE_TIMEOUTW L"PrintDriverIsolationIdleTimeout"
#elif defined(__GNUC__)
#define SPLREG_PRINT_DRIVER_ISOLATION_IDLE_TIMEOUTW (const WCHAR[]){'P','r','i','n','t','D','r','i','v','e','r','I','s','o','l','a','t','i','o','n','I','d','l','e','T','i','m','e','o','u','t',0}
#else
static const WCHAR SPLREG_PRINT_DRIVER_ISOLATION_IDLE_TIMEOUTW[] = {'P','r','i','n','t','D','r','i','v','e','r','I','s','o','l','a','t','i','o','n','I','d','l','e','T','i','m','e','o','u','t',0};
#endif
#define SPLREG_PRINT_DRIVER_ISOLATION_IDLE_TIMEOUT WINELIB_NAME_AW(SPLREG_PRINT_DRIVER_ISOLATION_IDLE_TIMEOUT)

#define SPLREG_PRINT_DRIVER_ISOLATION_EXECUTION_POLICYA "PrintDriverIsolationExecutionPolicy"
#ifdef _MSC_VER
#define SPLREG_PRINT_DRIVER_ISOLATION_EXECUTION_POLICYW L"PrintDriverIsolationExecutionPolicy"
#elif defined(__GNUC__)
#define SPLREG_PRINT_DRIVER_ISOLATION_EXECUTION_POLICYW (const WCHAR[]){'P','r','i','n','t','D','r','i','v','e','r','I','s','o','l','a','t','i','o','n','E','x','e','c','u','t','i','o','n','P','o','l','i','c','y',0}
#else
static const WCHAR SPLREG_PRINT_DRIVER_ISOLATION_EXECUTION_POLICYW[] = {'P','r','i','n','t','D','r','i','v','e','r','I','s','o','l','a','t','i','o','n','E','x','e','c','u','t','i','o','n','P','o','l','i','c','y',0};
#endif
#define SPLREG_PRINT_DRIVER_ISOLATION_EXECUTION_POLICY WINELIB_NAME_AW(SPLREG_PRINT_DRIVER_ISOLATION_EXECUTION_POLICY)

#define SPLREG_PRINT_DRIVER_ISOLATION_OVERRIDE_POLICYA "PrintDriverIsolationOverrideCompat"
#ifdef _MSC_VER
#define SPLREG_PRINT_DRIVER_ISOLATION_OVERRIDE_POLICYW L"PrintDriverIsolationOverrideCompat"
#elif defined(__GNUC__)
#define SPLREG_PRINT_DRIVER_ISOLATION_OVERRIDE_POLICYW (const WCHAR[]){'P','r','i','n','t','D','r','i','v','e','r','I','s','o','l','a','t','i','o','n','O','v','e','r','r','i','d','e','C','o','m','p','a','t',0}
#else
static const WCHAR SPLREG_PRINT_DRIVER_ISOLATION_OVERRIDE_POLICYW[] = {'P','r','i','n','t','D','r','i','v','e','r','I','s','o','l','a','t','i','o','n','O','v','e','r','r','i','d','e','C','o','m','p','a','t',0};
#endif
#define SPLREG_PRINT_DRIVER_ISOLATION_OVERRIDE_POLICY WINELIB_NAME_AW(SPLREG_PRINT_DRIVER_ISOLATION_OVERRIDE_POLICY)

/* DECLARATIONS */
INT WINAPI DeviceCapabilitiesA(LPCSTR pDevice,LPCSTR pPort,WORD fwCapability,
			       LPSTR pOutput, LPDEVMODEA pDevMode);
INT WINAPI DeviceCapabilitiesW(LPCWSTR pDevice, LPCWSTR pPort,
			       WORD fwCapability, LPWSTR pOutput,
			       const DEVMODEW *pDevMode);

#define DeviceCapabilities WINELIB_NAME_AW(DeviceCapabilities)

LONG WINAPI DocumentPropertiesA(HWND hWnd,HANDLE hPrinter,
                                LPSTR pDeviceName, LPDEVMODEA pDevModeOutput,
				LPDEVMODEA pDevModeInput,DWORD fMode );
LONG WINAPI DocumentPropertiesW(HWND hWnd, HANDLE hPrinter,
				LPWSTR pDeviceName,
				LPDEVMODEW pDevModeOutput,
				LPDEVMODEW pDevModeInput, DWORD fMode);

#define DocumentProperties WINELIB_NAME_AW(DocumentProperties)

BOOL WINAPI OpenPrinterA(LPSTR lpPrinterName,HANDLE *phPrinter,
			     LPPRINTER_DEFAULTSA pDefault);
BOOL WINAPI OpenPrinterW(LPWSTR lpPrinterName,HANDLE *phPrinter,
			     LPPRINTER_DEFAULTSW pDefault);

#define OpenPrinter WINELIB_NAME_AW(OpenPrinter)

BOOL WINAPI ResetPrinterA(HANDLE hPrinter, LPPRINTER_DEFAULTSA pDefault);
BOOL WINAPI ResetPrinterW(HANDLE hPrinter, LPPRINTER_DEFAULTSW pDefault);
#define ResetPrinter WINELIB_NAME_AW(ResetPrinter)

BOOL WINAPI ClosePrinter (HANDLE phPrinter);

BOOL WINAPI EnumJobsA(HANDLE hPrinter, DWORD FirstJob, DWORD NoJobs,
		      DWORD Level, LPBYTE pJob, DWORD cbBuf, LPDWORD pcbNeeded,
		      LPDWORD pcReturned);
BOOL WINAPI EnumJobsW(HANDLE hPrinter, DWORD FirstJob, DWORD NoJobs,
		      DWORD Level, LPBYTE pJob, DWORD cbBuf, LPDWORD pcbNeeded,
		      LPDWORD pcReturned);
#define EnumJobs WINELIB_NAME_AW(EnumJobs)

BOOL  WINAPI EnumPrintersA(DWORD dwType, LPSTR lpszName,
			       DWORD dwLevel, LPBYTE lpbPrinters,
			       DWORD cbBuf, LPDWORD lpdwNeeded,
			       LPDWORD lpdwReturned);
BOOL  WINAPI EnumPrintersW(DWORD dwType, LPWSTR lpszName,
			       DWORD dwLevel, LPBYTE lpbPrinters,
			       DWORD cbBuf, LPDWORD lpdwNeeded,
			       LPDWORD lpdwReturned);
#define EnumPrinters WINELIB_NAME_AW(EnumPrinters)

BOOL WINAPI PrinterProperties(HWND hWnd, HANDLE hPrinter);

BOOL WINAPI GetPrinterDriverDirectoryA(LPSTR,LPSTR,DWORD,LPBYTE,DWORD,LPDWORD);
BOOL WINAPI GetPrinterDriverDirectoryW(LPWSTR,LPWSTR,DWORD,LPBYTE,DWORD,LPDWORD);
#define GetPrinterDriverDirectory WINELIB_NAME_AW(GetPrinterDriverDirectory)

BOOL WINAPI GetPrinterDriverA(HANDLE hPrinter, LPSTR pEnvironment,
			      DWORD Level, LPBYTE pDriverInfo,
			      DWORD cbBuf, LPDWORD pcbNeeded);
BOOL WINAPI GetPrinterDriverW(HANDLE hPrinter, LPWSTR pEnvironment,
			      DWORD Level, LPBYTE pDriverInfo,
			      DWORD cbBuf, LPDWORD pcbNeeded);
#define GetPrinterDriver WINELIB_NAME_AW(GetPrinterDriver)

BOOL WINAPI SetJobA(HANDLE hPrinter, DWORD JobID, DWORD Level, LPBYTE pJob,
		    DWORD Command);
BOOL WINAPI SetJobW(HANDLE hPrinter, DWORD JobID, DWORD Level, LPBYTE pJob,
		    DWORD Command);
#define SetJob WINELIB_NAME_AW(SetJob)

BOOL WINAPI GetJobA(HANDLE hPrinter, DWORD JobID, DWORD Level, LPBYTE pJob,
		    DWORD cbBuf, LPDWORD pcbNeeded);
BOOL WINAPI GetJobW(HANDLE hPrinter, DWORD JobID, DWORD Level, LPBYTE pJob,
		    DWORD cbBuf, LPDWORD pcbNeeded);
#define GetJob WINELIB_NAME_AW(GetJob)

HANDLE WINAPI AddPrinterA(LPSTR pName, DWORD Level, LPBYTE pPrinter);
HANDLE WINAPI AddPrinterW(LPWSTR pName, DWORD Level, LPBYTE pPrinter);
#define AddPrinter WINELIB_NAME_AW(AddPrinter)

BOOL WINAPI DeletePrinter(HANDLE hPrinter);

BOOL WINAPI SetPrinterA(HANDLE hPrinter, DWORD Level, LPBYTE pPrinter,
			DWORD Command);
BOOL WINAPI SetPrinterW(HANDLE hPrinter, DWORD Level, LPBYTE pPrinter,
			DWORD Command);
#define SetPrinter WINELIB_NAME_AW(SetPrinter)

BOOL WINAPI GetPrinterA(HANDLE hPrinter, DWORD Level, LPBYTE pPrinter,
			DWORD cbBuf, LPDWORD pcbNeeded);
BOOL WINAPI GetPrinterW(HANDLE hPrinter, DWORD Level, LPBYTE pPrinter,
			DWORD cbBuf, LPDWORD pcbNeeded);
#define GetPrinter WINELIB_NAME_AW(GetPrinter)

BOOL WINAPI AddPrinterDriverA(LPSTR pName, DWORD Level, LPBYTE pDriverInfo);
BOOL WINAPI AddPrinterDriverW(LPWSTR pName, DWORD Level, LPBYTE pDriverInfo);
#define AddPrinterDriver WINELIB_NAME_AW(AddPrinterDriver)

BOOL WINAPI AddPrinterDriverExA(LPSTR pName, DWORD Level, LPBYTE pDriverInfo,
                                DWORD dwFileCopyFlags);
BOOL WINAPI AddPrinterDriverExW(LPWSTR pName, DWORD Level, LPBYTE pDriverInfo,
                                DWORD dwFileCopyFlags);
#define AddPrinterDriverEx WINELIB_NAME_AW(AddPrinterDriverEx)

BOOL WINAPI EnumPrinterDriversA(LPSTR pName, LPSTR pEnvironment, DWORD Level,
				LPBYTE pDriverInfo, DWORD cbBuf,
				LPDWORD pcbNeeded, LPDWORD pcbReturned);
BOOL WINAPI EnumPrinterDriversW(LPWSTR pName, LPWSTR pEnvironment, DWORD Level,
				LPBYTE pDriverInfo, DWORD cbBuf,
				LPDWORD pcbNeeded, LPDWORD pcbReturned);
#define EnumPrinterDrivers WINELIB_NAME_AW(EnumPrinterDrivers)

BOOL WINAPI GetDefaultPrinterA(LPSTR pName, LPDWORD pcbNameSize);
BOOL WINAPI GetDefaultPrinterW(LPWSTR pName, LPDWORD pcbNameSize);
#define GetDefaultPrinter WINELIB_NAME_AW(GetDefaultPrinter)

BOOL WINAPI SetDefaultPrinterA(LPCSTR);
BOOL WINAPI SetDefaultPrinterW(LPCWSTR);
#define SetDefaultPrinter WINELIB_NAME_AW(SetDefaultPrinter)

BOOL WINAPI DeletePrinterDriverA(LPSTR pName, LPSTR pEnvironment,
				 LPSTR pDriverName);
BOOL WINAPI DeletePrinterDriverW(LPWSTR pName, LPWSTR pEnvironment,
				 LPWSTR pDriverName);
#define DeletePrinterDriver WINELIB_NAME_AW(DeletePrinterDriver)

BOOL WINAPI DeletePrinterDriverExA(LPSTR pName, LPSTR pEnvironment,
                                   LPSTR pDriverName, DWORD dwDeleteFlag, DWORD dwVersionFlag);
BOOL WINAPI DeletePrinterDriverExW(LPWSTR pName, LPWSTR pEnvironment,
                                   LPWSTR pDriverName, DWORD dwDeleteFlag, DWORD dwVersionFlag);
#define DeletePrinterDriverEx WINELIB_NAME_AW(DeletePrinterDriverEx)

BOOL WINAPI AddPrintProcessorA(LPSTR pName, LPSTR pEnvironment,
			       LPSTR pPathName, LPSTR pPrintProcessorName);
BOOL WINAPI AddPrintProcessorW(LPWSTR pName, LPWSTR pEnvironment,
			       LPWSTR pPathName, LPWSTR pPrintProcessorName);
#define AddPrintProcessor WINELIB_NAME_AW(AddPrintProcessor)

BOOL WINAPI EnumPrintProcessorsA(LPSTR pName, LPSTR pEnvironment,
				 DWORD Level, LPBYTE pPrintProcessorInfo,
				 DWORD cbBuf, LPDWORD pcbNeeded,
				 LPDWORD pcbReturned);
BOOL WINAPI EnumPrintProcessorsW(LPWSTR pName, LPWSTR pEnvironment,
				 DWORD Level, LPBYTE pPrintProcessorInfo,
				 DWORD cbBuf, LPDWORD pcbNeeded,
				 LPDWORD pcbReturned);
#define EnumPrintProcessors WINELIB_NAME_AW(EnumPrintProcessors)

BOOL WINAPI GetPrintProcessorDirectoryA(LPSTR pName, LPSTR pEnvironment,
					DWORD Level,
					LPBYTE pPrintProcessorInfo,
					DWORD cbBuf, LPDWORD pcbNeeded);

BOOL WINAPI GetPrintProcessorDirectoryW(LPWSTR pName, LPWSTR pEnvironment,
					DWORD Level,
					LPBYTE pPrintProcessorInfo,
					DWORD cbBuf, LPDWORD pcbNeeded);
#define GetPrintProcessorDirectory WINELIB_NAME_AW(GetPrintProcessorDirectory)

BOOL WINAPI EnumPrintProcessorDatatypesA(LPSTR pName,
					 LPSTR pPrintProcessorName,
					 DWORD Level, LPBYTE pDatatypes,
					 DWORD cbBuf, LPDWORD pcbNeeded,
					 LPDWORD pcbReturned);
BOOL WINAPI EnumPrintProcessorDatatypesW(LPWSTR pName,
					 LPWSTR pPrintProcessorName,
					 DWORD Level, LPBYTE pDatatypes,
					 DWORD cbBuf, LPDWORD pcbNeeded,
					 LPDWORD pcbReturned);
#define EnumPrintProcessorDatatypes WINELIB_NAME_AW(EnumPrintProcessorDatatypes)

BOOL WINAPI DeletePrintProcessorA(LPSTR pName, LPSTR pEnvironment,
				  LPSTR pPrintProcessorName);
BOOL WINAPI DeletePrintProcessorW(LPWSTR pName, LPWSTR pEnvironment,
				  LPWSTR pPrintProcessorName);
#define DeletePrintProcessor WINELIB_NAME_AW(DeletePrintProcessor)

DWORD WINAPI StartDocPrinterA(HANDLE hPrinter, DWORD Level, LPBYTE pDocInfo);
DWORD WINAPI StartDocPrinterW(HANDLE hPrinter, DWORD Level, LPBYTE pDocInfo);
#define StartDocPrinter WINELIB_NAME_AW(StartDocPrinter)

BOOL WINAPI StartPagePrinter(HANDLE hPrinter);
BOOL WINAPI WritePrinter(HANDLE hPrinter, LPVOID pBuf, DWORD cbBuf,
			 LPDWORD pcWritten);
BOOL WINAPI EndPagePrinter(HANDLE hPrinter);
BOOL WINAPI AbortPrinter(HANDLE hPrinter);
BOOL WINAPI ReadPrinter(HANDLE hPrinter, LPVOID pBuf, DWORD cbBuf,
			LPDWORD pNoBytesRead);
BOOL WINAPI EndDocPrinter(HANDLE hPrinter);

BOOL WINAPI AddJobA(HANDLE hPrinter, DWORD Level, LPBYTE pData, DWORD cbBuf,
		    LPDWORD pcbNeeded);
BOOL WINAPI AddJobW(HANDLE hPrinter, DWORD Level, LPBYTE pData, DWORD cbBuf,
		    LPDWORD pcbNeeded);
#define AddJob WINELIB_NAME_AW(AddJob)

BOOL WINAPI ScheduleJob(HANDLE hPrinter, DWORD JobID);

LONG WINAPI AdvancedDocumentPropertiesA(HWND hWnd, HANDLE hPrinter,
					LPSTR pDeviceName,
					PDEVMODEA pDevModeOutput,
					PDEVMODEA pDevModeInput);
LONG WINAPI AdvancedDocumentPropertiesW(HWND hWnd, HANDLE hPrinter,
					LPWSTR pDeviceName,
					PDEVMODEW pDevModeOutput,
					PDEVMODEW pDevModeInput);
#define AdvancedDocumentProperties WINELIB_NAME_AW(AdvancedDocumentProperties)

DWORD WINAPI GetPrinterDataA(HANDLE hPrinter, LPSTR pValueName, LPDWORD pType,
			     LPBYTE pData, DWORD nSize, LPDWORD pcbNeeded);
DWORD WINAPI GetPrinterDataW(HANDLE hPrinter, LPWSTR pValueName, LPDWORD pType,
			     LPBYTE pData, DWORD nSize, LPDWORD pcbNeeded);
#define GetPrinterData WINELIB_NAME_AW(GetPrinterData)

DWORD WINAPI GetPrinterDataExA(HANDLE hPrinter, LPCSTR pKeyName,
			       LPCSTR pValueName, LPDWORD pType,
			       LPBYTE pData, DWORD nSize, LPDWORD pcbNeeded);
DWORD WINAPI GetPrinterDataExW(HANDLE hPrinter, LPCWSTR pKeyName,
			       LPCWSTR pValueName, LPDWORD pType,
			       LPBYTE pData, DWORD nSize, LPDWORD pcbNeeded);
#define GetPrinterDataEx WINELIB_NAME_AW(GetPrinterDataEx)

DWORD WINAPI DeletePrinterDataExA(HANDLE hPrinter, LPCSTR pKeyName,
                                  LPCSTR pValueName);
DWORD WINAPI DeletePrinterDataExW(HANDLE hPrinter, LPCWSTR pKeyName,
                                  LPCWSTR pValueName);
#define DeletePrinterDataEx WINELIB_NAME_AW(DeletePrinterDataEx)

DWORD WINAPI SetPrinterDataA(HANDLE hPrinter, LPSTR pValueName, DWORD Type,
			     LPBYTE pData, DWORD cbData);
DWORD WINAPI SetPrinterDataW(HANDLE hPrinter, LPWSTR pValueName, DWORD Type,
			     LPBYTE pData, DWORD cbData);
#define SetPrinterData WINELIB_NAME_AW(SetPrinterData)

DWORD WINAPI SetPrinterDataExA(HANDLE hPrinter, LPCSTR pKeyName,
			       LPCSTR pValueName, DWORD Type,
			       LPBYTE pData, DWORD cbData);
DWORD WINAPI SetPrinterDataExW(HANDLE hPrinter, LPCWSTR pKeyName,
			       LPCWSTR pValueName, DWORD Type,
			       LPBYTE pData, DWORD cbData);
#define SetPrinterDataEx WINELIB_NAME_AW(SetPrinterDataEx)

DWORD WINAPI WaitForPrinterChange(HANDLE hPrinter, DWORD Flags);
HANDLE WINAPI FindFirstPrinterChangeNotification(HANDLE hPrinter,
						 DWORD fdwFlags,
						 DWORD fdwOptions,
						 LPVOID pPrinterNotifyOptions);
BOOL WINAPI FindNextPrinterChangeNotification(HANDLE hChange,
					      PDWORD pdwChange,
					      LPVOID pvReserved,
					      LPVOID *ppPrinterNotifyInfo);
BOOL WINAPI FreePrinterNotifyInfo(PPRINTER_NOTIFY_INFO pPrinterNotifyInfo);
BOOL WINAPI FindClosePrinterChangeNotification(HANDLE hChange);

DWORD WINAPI PrinterMessageBoxA(HANDLE hPrinter, DWORD Error, HWND hWnd,
				LPSTR pText, LPSTR pCaption, DWORD dwType);
DWORD WINAPI PrinterMessageBoxW(HANDLE hPrinter, DWORD Error, HWND hWnd,
				LPWSTR pText, LPWSTR pCaption, DWORD dwType);
#define PrinterMessageBox WINELIB_NAME_AW(PrinterMessageBox)

BOOL WINAPI AddFormA(HANDLE hPrinter, DWORD Level, LPBYTE pForm);
BOOL WINAPI AddFormW(HANDLE hPrinter, DWORD Level, LPBYTE pForm);
#define AddForm WINELIB_NAME_AW(AddForm)

BOOL WINAPI DeleteFormA(HANDLE hPrinter, LPSTR pFormName);
BOOL WINAPI DeleteFormW(HANDLE hPrinter, LPWSTR pFormName);
#define DeleteForm WINELIB_NAME_AW(DeleteForm)

BOOL WINAPI GetFormA(HANDLE hPrinter, LPSTR pFormName, DWORD Level,
		     LPBYTE pForm, DWORD cbBuf, LPDWORD pcbNeeded);
BOOL WINAPI GetFormW(HANDLE hPrinter, LPWSTR pFormName, DWORD Level,
		     LPBYTE pForm, DWORD cbBuf, LPDWORD pcbNeeded);
#define GetForm WINELIB_NAME_AW(GetForm)

BOOL WINAPI SetFormA(HANDLE hPrinter, LPSTR pFormName, DWORD Level,
		     LPBYTE pForm);
BOOL WINAPI SetFormW(HANDLE hPrinter, LPWSTR pFormName, DWORD Level,
		     LPBYTE pForm);
#define SetForm WINELIB_NAME_AW(SetForm)

BOOL WINAPI EnumFormsA(HANDLE hPrinter, DWORD Level, LPBYTE pForm, DWORD cbBuf,
		       LPDWORD pcbNeeded, LPDWORD pcReturned);
BOOL WINAPI EnumFormsW(HANDLE hPrinter, DWORD Level, LPBYTE pForm, DWORD cbBuf,
		       LPDWORD pcbNeeded, LPDWORD pcReturned);
#define EnumForms WINELIB_NAME_AW(EnumForms)

BOOL WINAPI EnumMonitorsA(LPSTR pName, DWORD Level, LPBYTE pMonitors,
			  DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
BOOL WINAPI EnumMonitorsW(LPWSTR pName, DWORD Level, LPBYTE pMonitors,
			  DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
#define EnumMonitors WINELIB_NAME_AW(EnumMonitors)

DWORD WINAPI EnumPrinterDataA( HANDLE hPrinter, DWORD dwIndex, LPSTR pValueName,
    DWORD cbValueName, LPDWORD pcbValueName, LPDWORD pType, LPBYTE pData,
    DWORD cbData, LPDWORD pcbData );
DWORD WINAPI EnumPrinterDataW( HANDLE hPrinter, DWORD dwIndex, LPWSTR pValueName,
    DWORD cbValueName, LPDWORD pcbValueName, LPDWORD pType, LPBYTE pData,
    DWORD cbData, LPDWORD pcbData );
#define EnumPrinterData WINELIB_NAME_AW(EnumPrinterData)

BOOL WINAPI AddMonitorA(LPSTR pName, DWORD Level, LPBYTE pMonitors);
BOOL WINAPI AddMonitorW(LPWSTR pName, DWORD Level, LPBYTE pMonitors);
#define AddMonitor WINELIB_NAME_AW(AddMonitor)

BOOL WINAPI DeleteMonitorA(LPSTR pName, LPSTR pEnvironment,
			   LPSTR pMonitorName);
BOOL WINAPI DeleteMonitorW(LPWSTR pName, LPWSTR pEnvironment,
			   LPWSTR pMonitorName);
#define DeleteMonitor WINELIB_NAME_AW(DeleteMonitor)

BOOL WINAPI EnumPortsA(LPSTR pName, DWORD Level, LPBYTE pPorts,
		       DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
BOOL WINAPI EnumPortsW(LPWSTR pName, DWORD Level, LPBYTE pPorts,
		       DWORD cbBuf, LPDWORD pcbNeeded, LPDWORD pcReturned);
#define EnumPorts WINELIB_NAME_AW(EnumPorts)

BOOL WINAPI AddPortA(LPSTR pName, HWND hWnd, LPSTR pMonitorName);
BOOL WINAPI AddPortW(LPWSTR pName, HWND hWnd, LPWSTR pMonitorName);
#define AddPort WINELIB_NAME_AW(AddPort)

BOOL WINAPI AddPortExA(LPSTR, DWORD, LPBYTE, LPSTR);
BOOL WINAPI AddPortExW(LPWSTR, DWORD, LPBYTE, LPWSTR);
#define AddPortEx WINELIB_NAME_AW(AddPortEx)

BOOL WINAPI ConfigurePortA(LPSTR pName, HWND hWnd, LPSTR pPortName);
BOOL WINAPI ConfigurePortW(LPWSTR pName, HWND hWnd, LPWSTR pPortName);
#define ConfigurePort WINELIB_NAME_AW(ConfigurePort)

BOOL WINAPI DeletePortA(LPSTR pName, HWND hWnd, LPSTR pPortName);
BOOL WINAPI DeletePortW(LPWSTR pName, HWND hWnd, LPWSTR pPortName);
#define DeletePort WINELIB_NAME_AW(DeletePort)

BOOL WINAPI SetPortA(LPSTR pName, LPSTR pPortName, DWORD dwLevel,
		     LPBYTE pPortInfo);
BOOL WINAPI SetPortW(LPWSTR pName, LPWSTR pPortName, DWORD dwLevel,
		     LPBYTE pPortInfo);
#define SetPort WINELIB_NAME_AW(SetPort)

BOOL WINAPI AddPrinterConnectionA(LPSTR pName);
BOOL WINAPI AddPrinterConnectionW(LPWSTR pName);
#define AddPrinterConnection WINELIB_NAME_AW(AddPrinterConnection)

BOOL WINAPI DeletePrinterConnectionA(LPSTR pName);
BOOL WINAPI DeletePrinterConnectionW(LPWSTR pName);
#define DeletePrinterConnection WINELIB_NAME_AW(DeletePrinterConnection)

HANDLE WINAPI ConnectToPrinterDlg(HWND hwnd, DWORD Flags);

BOOL WINAPI AddPrintProvidorA(LPSTR pName, DWORD Level, LPBYTE pProvidorInfo);
BOOL WINAPI AddPrintProvidorW(LPWSTR pName, DWORD Level, LPBYTE pProvidorInfo);
#define AddPrintProvidor WINELIB_NAME_AW(AddPrintProvidor)

BOOL WINAPI DeletePrintProvidorA(LPSTR pName, LPSTR pEnvironment,
				 LPSTR pPrintProvidorName);
BOOL WINAPI DeletePrintProvidorW(LPWSTR pName, LPWSTR pEnvironment,
				 LPWSTR pPrintProvidorName);
#define DeletePrintProvidor WINELIB_NAME_AW(DeletePrintProvidor)

DWORD WINAPI EnumPrinterKeyA(HANDLE printer, const CHAR *key,
                             CHAR *subkey, DWORD size, DWORD *needed);
DWORD WINAPI EnumPrinterKeyW(HANDLE printer, const WCHAR *key,
                             WCHAR *subkey, DWORD size, DWORD *needed);
#define EnumPrinterKey WINELIB_NAME_AW(EnumPrinterKey)

DWORD WINAPI EnumPrinterDataExA(HANDLE hPrinter, LPCSTR pKeyName,
				LPBYTE pEnumValues, DWORD cbEnumValues,
				LPDWORD pcbEnumValues, LPDWORD pnEnumValues);
DWORD WINAPI EnumPrinterDataExW(HANDLE hPrinter, LPCWSTR pKeyName,
				LPBYTE pEnumValues, DWORD cbEnumValues,
				LPDWORD pcbEnumValues, LPDWORD pnEnumValues);
#define EnumPrinterDataEx WINELIB_NAME_AW(EnumPrinterDataEx)

LONG WINAPI ExtDeviceMode( HWND hWnd, HANDLE hInst, LPDEVMODEA pDevModeOutput,
    LPSTR pDeviceName, LPSTR pPort, LPDEVMODEA pDevModeInput, LPSTR pProfile,
    DWORD fMode);

LPSTR WINAPI StartDocDlgA(HANDLE hPrinter, DOCINFOA *doc);
LPWSTR WINAPI StartDocDlgW(HANDLE hPrinter, DOCINFOW *doc);
#define StartDocDlg WINELIB_NAME_AW(StartDocDlg)

HRESULT WINAPI UploadPrinterDriverPackageA(LPCSTR,LPCSTR,LPCSTR,DWORD,HWND,LPSTR,PULONG);
HRESULT WINAPI UploadPrinterDriverPackageW(LPCWSTR,LPCWSTR,LPCWSTR,DWORD,HWND,LPWSTR,PULONG);
#define UploadPrinterDriverPackage WINELIB_NAME_AW(UploadPrinterDriverPackage)

BOOL WINAPI XcvDataW(HANDLE hXcv, LPCWSTR pszDataName, PBYTE pInputData,
    DWORD cbInputData, PBYTE pOutputData, DWORD cbOutputData,
    PDWORD pcbOutputNeeded, PDWORD pdwStatus);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  /* __WINE_WINSPOOL_H */
