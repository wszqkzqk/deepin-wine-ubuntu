/*
 * Copyright (c) 2015 Andrew Eikum for CodeWeavers
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

#ifndef _X3DAUDIO_H
#define _X3DAUDIO_H

typedef struct X3DAUDIO_VECTOR {
    float x, y, z;
} X3DAUDIO_VECTOR;

typedef struct X3DAUDIO_CONE {
    float InnerAngle;
    float OuterAngle;
    float InnerVolume;
    float OuterVolume;
    float InnerLPF;
    float OuterLPF;
    float InnerReverb;
    float OuterReverb;
} X3DAUDIO_CONE;

typedef struct X3DAUDIO_DISTANCE_CURVE_POINT {
    float Distance;
    float DSPSetting;
} X3DAUDIO_DISTANCE_CURVE_POINT;

typedef struct X3DAUDIO_DISTANCE_CURVE {
    X3DAUDIO_DISTANCE_CURVE_POINT *pPoints;
    UINT32 PointCount;
} X3DAUDIO_DISTANCE_CURVE;

typedef struct X3DAUDIO_LISTENER {
    X3DAUDIO_VECTOR OrientFront;
    X3DAUDIO_VECTOR OrientTop;
    X3DAUDIO_VECTOR Position;
    X3DAUDIO_VECTOR Velocity;
    X3DAUDIO_CONE *pCone;
} X3DAUDIO_LISTENER;

typedef struct X3DAUDIO_EMITTER {
    X3DAUDIO_CONE *pCone;
    X3DAUDIO_VECTOR OrientFront;
    X3DAUDIO_VECTOR OrientTop;
    X3DAUDIO_VECTOR Position;
    X3DAUDIO_VECTOR Velocity;
    float InnerRadius;
    float InnerRadiusAngle;
    UINT32 ChannelCount;
    float ChannelRadius;
    float *pChannelAzimuths;
    X3DAUDIO_DISTANCE_CURVE *pVolumeCurve;
    X3DAUDIO_DISTANCE_CURVE *pLFECurve;
    X3DAUDIO_DISTANCE_CURVE *pLPFDirectCurve;
    X3DAUDIO_DISTANCE_CURVE *pLPFReverbCurve;
    X3DAUDIO_DISTANCE_CURVE *pReverbCurve;
    float CurveDistanceScalar;
    float DopplerScalar;
} X3DAUDIO_EMITTER;

typedef struct X3DAUDIO_DSP_SETTINGS {
    float *pMatrixCoefficients;
    float *pDelayTimes;
    UINT32 SrcChannelCount;
    UINT32 DstChannelCount;
    float LPFDirectCoefficient;
    float LPFReverbCoefficient;
    float ReverbLevel;
    float DopplerFactor;
    float EmitterToListenerAngle;
    float EmitterToListenerDistance;
    float EmitterVelocityComponent;
    float ListenerVelocityComponent;
} X3DAUDIO_DSP_SETTINGS;

#define X3DAUDIO_HANDLE_BYTESIZE 20
typedef BYTE X3DAUDIO_HANDLE[X3DAUDIO_HANDLE_BYTESIZE];

HRESULT CDECL X3DAudioInitialize(UINT32, float, X3DAUDIO_HANDLE);
void CDECL X3DAudioCalculate(const X3DAUDIO_HANDLE, const X3DAUDIO_LISTENER *,
        const X3DAUDIO_EMITTER *, UINT32, X3DAUDIO_DSP_SETTINGS *);

#endif
