/*
 * Copyright (C) 2005 Benjamin Cutler
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

#ifndef __WINE_POWRPROF_H
#define __WINE_POWRPROF_H 1

#define EnableSysTrayBatteryMeter	0x01
#define EnableMultiBatteryDisplay	0x02
#define EnablePasswordLogon		0x04
#define EnableWakeOnRing		0x08
#define EnableVideoDimDisplay		0x10

typedef struct _GLOBAL_MACHINE_POWER_POLICY {
	ULONG Revision;
	SYSTEM_POWER_STATE LidOpenWakeAc;
	SYSTEM_POWER_STATE LidOpenWakeDc;
	ULONG BroadcastCapacityResolution;
} GLOBAL_MACHINE_POWER_POLICY, 
*PGLOBAL_MACHINE_POWER_POLICY;

typedef struct _GLOBAL_USER_POWER_POLICY {
	ULONG Revision;
	POWER_ACTION_POLICY PowerButtonAc;
	POWER_ACTION_POLICY PowerButtonDc;
	POWER_ACTION_POLICY SleepButtonAc;
	POWER_ACTION_POLICY SleepButtonDc;
	POWER_ACTION_POLICY LidCloseAc;
	POWER_ACTION_POLICY LidCloseDc;
	SYSTEM_POWER_LEVEL DischargePolicy[NUM_DISCHARGE_POLICIES];
	ULONG GlobalFlags;
} GLOBAL_USER_POWER_POLICY, 
*PGLOBAL_USER_POWER_POLICY;

typedef struct _GLOBAL_POWER_POLICY {
	GLOBAL_USER_POWER_POLICY user;
	GLOBAL_MACHINE_POWER_POLICY mach;
} GLOBAL_POWER_POLICY, 
*PGLOBAL_POWER_POLICY;

typedef struct _MACHINE_POWER_POLICY {
	ULONG Revision;
	SYSTEM_POWER_STATE MinSleepAc;
	SYSTEM_POWER_STATE MinSleepDc;
	SYSTEM_POWER_STATE ReducedLatencySleepAc;
	SYSTEM_POWER_STATE ReducedLatencySleepDc;
	ULONG DozeTimeoutAc;
	ULONG DozeTimeoutDc;
	ULONG DozeS4TimeoutAc;
	ULONG DozeS4TimeoutDc;
	UCHAR MinThrottleAc;
	UCHAR MinThrottleDc;
	UCHAR pad1[2];
	POWER_ACTION_POLICY OverThrottledAc;
	POWER_ACTION_POLICY OverThrottledDc;
} MACHINE_POWER_POLICY, 
*PMACHINE_POWER_POLICY;

typedef struct _MACHINE_PROCESSOR_POWER_POLICY {
	ULONG Revision;
	PROCESSOR_POWER_POLICY ProcessorPolicyAc;
	PROCESSOR_POWER_POLICY ProcessorPolicyDc;
} MACHINE_PROCESSOR_POWER_POLICY, 
*PMACHINE_PROCESSOR_POWER_POLICY;

typedef struct _USER_POWER_POLICY {
	ULONG Revision;
	POWER_ACTION_POLICY IdleAc;
	POWER_ACTION_POLICY IdleDc;
	ULONG IdleTimeoutAc;
	ULONG IdleTimeoutDc;
	UCHAR IdleSensitivityAc;
	UCHAR IdleSensitivityDc;
	UCHAR ThrottlePolicyAc;
	UCHAR ThrottlePolicyDc;
	SYSTEM_POWER_STATE MaxSleepAc;
	SYSTEM_POWER_STATE MaxSleepDc;
	ULONG Reserved[2];
	ULONG VideoTimeoutAc;
	ULONG VideoTimeoutDc;
	ULONG SpindownTimeoutAc;
	ULONG SpindownTimeoutDc;
	BOOLEAN OptimizeForPowerAc;
	BOOLEAN OptimizeForPowerDc;
	UCHAR FanThrottleToleranceAc;
	UCHAR FanThrottleToleranceDc;
	UCHAR ForcedThrottleAc;
	UCHAR ForcedThrottleDc;
} USER_POWER_POLICY, 
*PUSER_POWER_POLICY;

typedef struct _POWER_POLICY {
	USER_POWER_POLICY user;
	MACHINE_POWER_POLICY mach;
} POWER_POLICY, 
*PPOWER_POLICY;


#ifdef __cplusplus
extern "C" {
#endif

typedef BOOLEAN (CALLBACK* PWRSCHEMESENUMPROC)(UINT, DWORD, LPWSTR, DWORD, LPWSTR, PPOWER_POLICY, LPARAM);

NTSTATUS WINAPI CallNtPowerInformation(POWER_INFORMATION_LEVEL, PVOID, ULONG, PVOID, ULONG);
BOOLEAN WINAPI CanUserWritePwrScheme(VOID);
BOOLEAN WINAPI DeletePwrScheme(UINT);
BOOLEAN WINAPI EnumPwrSchemes(PWRSCHEMESENUMPROC, LPARAM);
BOOLEAN WINAPI GetActivePwrScheme(PUINT);
BOOLEAN WINAPI GetCurrentPowerPolicies(PGLOBAL_POWER_POLICY, PPOWER_POLICY);
BOOLEAN WINAPI GetPwrCapabilities(PSYSTEM_POWER_CAPABILITIES);
BOOLEAN WINAPI GetPwrDiskSpindownRange(PUINT, PUINT);
BOOLEAN WINAPI IsAdminOverrideActive(PADMINISTRATOR_POWER_POLICY);
BOOLEAN WINAPI IsPwrHibernateAllowed(VOID);
BOOLEAN WINAPI IsPwrShutdownAllowed(VOID);
BOOLEAN WINAPI IsPwrSuspendAllowed(VOID);
BOOLEAN WINAPI ReadGlobalPwrPolicy(PGLOBAL_POWER_POLICY);
BOOLEAN WINAPI ReadProcessorPwrScheme(UINT, PMACHINE_PROCESSOR_POWER_POLICY);
BOOLEAN WINAPI ReadPwrScheme(UINT, PPOWER_POLICY);
BOOLEAN WINAPI SetActivePwrScheme(UINT, PGLOBAL_POWER_POLICY, PPOWER_POLICY);
BOOLEAN WINAPI SetSuspendState(BOOLEAN, BOOLEAN, BOOLEAN);
BOOLEAN WINAPI WriteGlobalPwrPolicy(PGLOBAL_POWER_POLICY);
BOOLEAN WINAPI WriteProcessorPwrScheme(UINT, PMACHINE_PROCESSOR_POWER_POLICY);
BOOLEAN WINAPI WritePwrScheme(PUINT, LPWSTR, LPWSTR, PPOWER_POLICY);

/* Power scheme */
POWER_PLATFORM_ROLE WINAPI PowerDeterminePlatformRole(void);

#ifdef __cplusplus
}
#endif

#endif /* _POWRPROF_H */
