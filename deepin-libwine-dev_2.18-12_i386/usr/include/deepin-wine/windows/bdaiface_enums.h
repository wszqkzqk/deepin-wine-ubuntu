/*
 * Copyright 2013 André Hentschel
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

#ifndef BDAIFACE_ENUMS_H
#define BDAIFACE_ENUMS_H

typedef enum EntitlementType
{
    Entitled,
    NotEntitled,
    TechnicalFailure
} EntitlementType;

typedef enum BDA_DrmPairingError
{
    BDA_DrmPairing_Succeeded,
    BDA_DrmPairing_HardwareFailure,
    BDA_DrmPairing_NeedRevocationData,
    BDA_DrmPairing_NeedIndiv,
    BDA_DrmPairing_Other,
    BDA_DrmPairing_DrmInitFailed,
    BDA_DrmPairing_DrmNotPaired,
    BDA_DrmPairing_DrmRePairSoon,
    BDA_DrmPairing_Aborted,
    BDA_DrmPairing_NeedSDKUpdate
} BDA_DrmPairingError;

typedef enum UICloseReasonType
{
    NotReady,
    UserClosed,
    SystemClosed,
    DeviceClosed,
    ErrorClosed
} UICloseReasonType;

typedef enum LocationCodeSchemeType
{
    SCTE_18
} LocationCodeSchemeType;

typedef struct SmartCardApplication
{
    ApplicationTypeType ApplicationType;
    USHORT ApplicationVersion;
    BSTR pbstrApplicationName;
    BSTR pbstrApplicationURL;
} SmartCardApplication;

typedef struct EALocationCodeType
{
    LocationCodeSchemeType LocationCodeScheme;
    BYTE state_code;
    BYTE county_subdivision;
    WORD county_code;
} EALocationCodeType;

typedef enum SmartCardStatusType
{
    CardInserted,
    CardRemoved,
    CardError,
    CardDataChanged,
    CardFirmwareUpgrade
} SmartCardStatusType;

typedef enum SmartCardAssociationType
{
    NotAssociated,
    Associated,
    AssociationUnknown
} SmartCardAssociationType;

#endif /* BDAIFACE_ENUMS_H */
