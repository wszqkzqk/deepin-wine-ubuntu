/*
 * ExitWindowsEx() reason codes
 *
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

#ifndef __WINE_REASON_H
#define __WINE_REASON_H


#define SHTDN_REASON_FLAG_USER_DEFINED            0x40000000
#define SHTDN_REASON_FLAG_PLANNED                 0x80000000

#define SHTDN_REASON_MAJOR_OTHER                  0x00000000
#define SHTDN_REASON_MAJOR_NONE                   0x00000000
#define SHTDN_REASON_MAJOR_HARDWARE               0x00010000
#define SHTDN_REASON_MAJOR_OPERATINGSYSTEM        0x00020000
#define SHTDN_REASON_MAJOR_SOFTWARE               0x00030000
#define SHTDN_REASON_MAJOR_APPLICATION            0x00040000
#define SHTDN_REASON_MAJOR_SYSTEM                 0x00050000
#define SHTDN_REASON_MAJOR_POWER                  0x00060000
#define SHTDN_REASON_MAJOR_LEGACY_API             0x00070000

#define SHTDN_REASON_MINOR_OTHER                  0x00000000
#define SHTDN_REASON_MINOR_MAINTENANCE            0x00000001
#define SHTDN_REASON_MINOR_INSTALLATION           0x00000002
#define SHTDN_REASON_MINOR_UPGRADE                0x00000003
#define SHTDN_REASON_MINOR_RECONFIG               0x00000004
#define SHTDN_REASON_MINOR_HUNG                   0x00000005
#define SHTDN_REASON_MINOR_UNSTABLE               0x00000006
#define SHTDN_REASON_MINOR_DISK                   0x00000007
#define SHTDN_REASON_MINOR_PROCESSOR              0x00000008
#define SHTDN_REASON_MINOR_NETWORKCARD            0x00000009
#define SHTDN_REASON_MINOR_POWER_SUPPLY           0x0000000a
#define SHTDN_REASON_MINOR_CORDUNPLUGGED          0x0000000b
#define SHTDN_REASON_MINOR_ENVIRONMENT            0x0000000c
#define SHTDN_REASON_MINOR_HARDWARE_DRIVER        0x0000000d
#define SHTDN_REASON_MINOR_OTHERDRIVER            0x0000000e
#define SHTDN_REASON_MINOR_BLUESCREEN             0x0000000f
#define SHTDN_REASON_MINOR_SERVICEPACK            0x00000010
#define SHTDN_REASON_MINOR_HOTFIX                 0x00000011
#define SHTDN_REASON_MINOR_SECURITYFIX            0x00000012
#define SHTDN_REASON_MINOR_SECURITY               0x00000013
#define SHTDN_REASON_MINOR_NETWORK_CONNECTIVITY   0x00000014
#define SHTDN_REASON_MINOR_WMI                    0x00000015
#define SHTDN_REASON_MINOR_SERVICEPACK_UNINSTALL  0x00000016
#define SHTDN_REASON_MINOR_HOTFIX_UNINSTALL       0x00000017
#define SHTDN_REASON_MINOR_SECURITYFIX_UNINSTALL  0x00000018
#define SHTDN_REASON_MINOR_MMC                    0x00000019
#define SHTDN_REASON_MINOR_SYSTEMRESTORE          0x0000001a
#define SHTDN_REASON_MINOR_TERMSRV                0x00000020
#define SHTDN_REASON_MINOR_DC_PROMOTION           0x00000021
#define SHTDN_REASON_MINOR_DC_DEMOTION            0x00000022
#define SHTDN_REASON_MINOR_NONE                   0x000000ff

#define SHTDN_REASON_VALID_BIT_MASK               0xc0ffffff

#define SHTDN_REASON_UNKNOWN                      SHTDN_REASON_MINOR_NONE
#define SHTDN_REASON_LEGACY_API                   (SHTDN_REASON_MAJOR_LEGACY_API | SHTDN_REASON_FLAG_PLANNED)

#endif
