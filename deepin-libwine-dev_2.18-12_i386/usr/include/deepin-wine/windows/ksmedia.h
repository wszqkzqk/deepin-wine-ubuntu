/*
 * Copyright (C) 2004 Robert Reif
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

#ifndef _KS_
#error must include ks.h before ksmedia.h
#endif

#ifndef _KSMEDIA_
#define _KSMEDIA_

DEFINE_GUID(KSDATAFORMAT_TYPE_AUDIO, 0x73647561, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);

DEFINE_GUID(KSDATAFORMAT_SUBTYPE_PCM, 0x00000001, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
DEFINE_GUID(KSDATAFORMAT_SUBTYPE_IEEE_FLOAT, 0x00000003, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
DEFINE_GUID(KSDATAFORMAT_SUBTYPE_MULAW, 0x00000007, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);
DEFINE_GUID(KSDATAFORMAT_SUBTYPE_ALAW, 0x00000006, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71);

#define KSAUDIO_SPEAKER_DIRECTOUT 0
#define KSAUDIO_SPEAKER_MONO SPEAKER_FRONT_CENTER
#define KSAUDIO_SPEAKER_STEREO (SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT)
#define KSAUDIO_SPEAKER_QUAD (SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT | SPEAKER_BACK_LEFT | SPEAKER_BACK_RIGHT)
#define KSAUDIO_SPEAKER_SURROUND (SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT | SPEAKER_FRONT_CENTER | SPEAKER_BACK_CENTER)
#define KSAUDIO_SPEAKER_5POINT1 (SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT | SPEAKER_FRONT_CENTER | SPEAKER_LOW_FREQUENCY | SPEAKER_BACK_LEFT | SPEAKER_BACK_RIGHT)
/* 5:1 SIDE or BACK is not distinguished, only 0x3F shall be used (BACK) */
#define KSAUDIO_SPEAKER_5POINT1_SURROUND (SPEAKER_FRONT_LEFT | SPEAKER_FRONT_RIGHT | SPEAKER_FRONT_CENTER | SPEAKER_LOW_FREQUENCY | SPEAKER_SIDE_LEFT | SPEAKER_SIDE_RIGHT)
#define KSAUDIO_SPEAKER_7POINT1 (KSAUDIO_SPEAKER_5POINT1 | SPEAKER_FRONT_LEFT_OF_CENTER | SPEAKER_FRONT_RIGHT_OF_CENTER)
/* 7:1 home theater 0x63F */
#define KSAUDIO_SPEAKER_7POINT1_SURROUND (KSAUDIO_SPEAKER_5POINT1 | SPEAKER_SIDE_LEFT | SPEAKER_SIDE_RIGHT)

#ifndef REFERENCE_TIME_DEFINED
#define REFERENCE_TIME_DEFINED
typedef LONGLONG REFERENCE_TIME;
#endif

typedef enum
{
    eConnTypeUnknown = 0,
    eConnType3Point5mm,
    eConnTypeQuarter,
    eConnTypeAtapiInternal,
    eConnTypeRCA,
    eConnTypeOptical,
    eConnTypeOtherDigital,
    eConnTypeOtherAnalog,
    eConnTypeMultichannelAnalogDIN,
    eConnTypeXlrProfessional,
    eConnTypeRJ11Modem,
    eConnTypeCombination
} EPcxConnectionType;

typedef enum
{
    eGeoLocRear = 1,
    eGeoLocFront,
    eGeoLocLeft,
    eGeoLocRight,
    eGeoLocTop,
    eGeoLocBottom,
    eGeoLocRearPanel,
    eGeoLocRiser,
    eGeoLocInsideMobileLid,
    eGeoLocDrivebay,
    eGeoLocHDMI,
    eGeoLocOutsideMobileLid,
    eGeoLocATAPI,
    eGeoLocReserved5,
    eGeoLocReserved6
} EPcxGeoLocation;

typedef enum
{
    eGenLocPrimaryBox = 0,
    eGenLocInternal,
    eGenLocSeparate,
    eGenLocOther
} EPcxGenLocation;

typedef enum
{
    ePortConnJack = 0,
    ePortConnIntegratedDevice,
    ePortConnBothIntegratedAndJack,
    ePortConnUnknown
} EPxcPortConnection;

typedef struct
{
    DWORD ChannelMapping;
    COLORREF Color;
    EPcxConnectionType ConnectionType;
    EPcxGeoLocation GeoLocation;
    EPcxGenLocation GenLocation;
    EPxcPortConnection PortConnection;
    BOOL IsConnected;
} KSJACK_DESCRIPTION;

typedef KSJACK_DESCRIPTION *PKSJACK_DESCRIPTION;

typedef enum
{
    KSJACK_SINK_CONNECTIONTYPE_HDMI = 0,
    KSJACK_SINK_CONNECTIONTYPE_DISPLAYPORT
} KSJACK_SINK_CONNECTIONTYPE;

#define MAX_SINK_DESCRIPTION_NAME_LENGTH 32

typedef struct _tagKSJACK_SINK_INFORMATION
{
    KSJACK_SINK_CONNECTIONTYPE ConnType;
    WORD ManufacturerId;
    WORD ProductId;
    WORD AudioLatency;
    BOOL HDCPCapable;
    BOOL AICapable;
    UCHAR SinkDescriptionLength;
    WCHAR SinkDescription[MAX_SINK_DESCRIPTION_NAME_LENGTH];
    LUID PortId;
} KSJACK_SINK_INFORMATION;

#define JACKDESC2_PRESENCE_DETECT_CAPABILITY 0x1
#define JACKDESC2_DYNAMIC_FORMAT_CHANGE_CAPABILITY 0x2

typedef struct _tagKSJACK_DESCRIPTION2
{
    DWORD DeviceStateInfo;
    DWORD JackCapabilities;
} KSJACK_DESCRIPTION2;

typedef struct _tagKSJACK_DESCRIPTION2 *PKSJACK_DESCRIPTION2;

#endif  /* _KSMEDIA_ */
