/*
 * Copyright (C) 2000 Francois Gouget
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

#ifndef __WINE_MCX_H
#define __WINE_MCX_H

typedef struct tagMODEMDEVCAPS {
       DWORD dwActualSize;
       DWORD dwRequiredSize;
       DWORD dwDevSpecificOffset;
       DWORD dwDevSpecificSize;
       DWORD dwModemProviderVersion;
       DWORD dwModemManufacturerOffset;
       DWORD dwModemManufacturerSize;
       DWORD dwModemModelOffset;
       DWORD dwModemModelSize;
       DWORD dwModemVersionOffset;
       DWORD dwModemVersionSize;
       DWORD dwDialOptions;
       DWORD dwCallSetupFailTimer;
       DWORD dwInactivityTimeout;
       DWORD dwSpeakerVolume;
       DWORD dwSpeakerMode;
       DWORD dwModemoptions;
       DWORD dwMaxDTERate;
       DWORD dwMaxDCERate;
       BYTE  abVariablePortion[1];
} MODEMDEVCAPS, *LPMODEMDEVCAPS;

typedef struct tagMODEMSETTINGS {
       DWORD dwActualSize;
       DWORD dwRequiredSize;
       DWORD dwDevSpecificOffset;
       DWORD dwDevSpecificSize;
       DWORD dwCallSetupFailTimer;
       DWORD dwInactivityTimeout;
       DWORD dwSpeakerVolume;
       DWORD dwSpeakerMode;
       DWORD dwPreferredModemOptions;
       DWORD dwNegotiatedModemOptions;
       DWORD dwNegotiatedDCERate;
       BYTE  abVariablePortion[1];
} MODEMSETTINGS, *LPMODEMSETTINGS;

#endif  /* __WINE_MCX_H */
