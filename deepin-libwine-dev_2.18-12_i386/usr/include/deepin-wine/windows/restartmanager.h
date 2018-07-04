/*
 * Copyright (C) 2010 Austin English
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

#ifndef RESTARTMANAGER_H
#define RESTARTMANAGER_H

#ifdef __cplusplus
extern "C" {
#endif

#define RM_SESSION_KEY_LEN sizeof(GUID)
#define CCH_RM_SESSION_KEY RM_SESSION_KEY_LEN*2
#define CCH_RM_MAX_APP_NAME 255
#define CH_RM_MAX_SVC_NAME 63
#define RM_INVALID_TS_SESSION -1
#define RM_INVALID_PROCESS -1

typedef enum  {
    RmUnknownApp = 0,
    RmMainWindow = 1,
    RmOtherWindow = 2,
    RmService = 3,
    RmExplorer = 4,
    RmConsole = 5,
    RmCritical = 1000
} RM_APP_TYPE;

typedef enum _RM_REBOOT_REASON {
    RmRebootReasonNone             = 0x0000,
    RmRebootReasonPermissionDenied = 0x0001,
    RmRebootReasonSessionMismatch  = 0x0002,
    RmRebootReasonCriticalProcess  = 0x0004,
    RmRebootReasonCriticalService  = 0x0008,
    RmRebootReasonDetectedSelf     = 0x0010
} RM_REBOOT_REASON;

typedef struct {
    DWORD dwProcessId;
    FILETIME ProcessStartTime;
} RM_UNIQUE_PROCESS, *PRM_UNIQUE_PROCESS;

typedef struct {
    RM_UNIQUE_PROCESS Process;
    WCHAR strAppName[CCH_RM_MAX_APP_NAME+1];
    WCHAR strServiceShortName[CH_RM_MAX_SVC_NAME+1];
    RM_APP_TYPE ApplicationType;
    ULONG AppStatus;
    DWORD TSSessionID;
    BOOL bRestartable;
} RM_PROCESS_INFO, *PRM_PROCESS_INFO;

typedef void (CDECL *RM_WRITE_STATUS_CALLBACK)(UINT);

#ifdef __cplusplus
}
#endif

#endif /* RESTARTMANAGER_H */
