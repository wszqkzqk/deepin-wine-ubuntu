xof 0302txt 0064
// Copyright (C) 2011 Dylan Smith
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA

#pragma xftmpl name D3DRM_XTEMPLATES
#pragma xftmpl size D3DRM_XTEMPLATE_BYTES
#pragma makedep install

template Header
{
    <3D82AB43-62DA-11CF-AB39-0020AF71E433>
    WORD major;
    WORD minor;
    DWORD flags;
}

template Vector
{
    <3D82AB5E-62DA-11CF-AB39-0020AF71E433>
    FLOAT x;
    FLOAT y;
    FLOAT z;
}

template Coords2d
{
    <F6F23F44-7686-11CF-8F52-0040333594A3>
    FLOAT u;
    FLOAT v;
}

template Matrix4x4
{
    <F6F23F45-7686-11CF-8F52-0040333594A3>
    array FLOAT matrix[16];
}

template ColorRGBA
{
    <35FF44E0-6C7C-11CF-8F52-0040333594A3>
    FLOAT red;
    FLOAT green;
    FLOAT blue;
    FLOAT alpha;
}

template ColorRGB
{
    <D3E16E81-7835-11CF-8F52-0040333594A3>
    FLOAT red;
    FLOAT green;
    FLOAT blue;
}

template IndexedColor
{
    <1630B820-7842-11CF-8F52-0040333594A3>
    DWORD index;
    ColorRGBA indexColor;
}

template Boolean
{
    <537DA6A0-CA37-11D0-941C-0080C80CFA7B>
    DWORD truefalse;
}

template Boolean2d
{
    <4885AE63-78E8-11CF-8F52-0040333594A3>
    Boolean u;
    Boolean v;
}

template MaterialWrap
{
    <4885AE60-78E8-11CF-8F52-0040333594A3>
    Boolean u;
    Boolean v;
}

template TextureFilename
{
    <A42790E1-7810-11CF-8F52-0040333594A3>
    STRING filename;
}

template Material
{
    <3D82AB4D-62DA-11CF-AB39-0020AF71E433>
    ColorRGBA faceColor;
    FLOAT power;
    ColorRGB specularColor;
    ColorRGB emissiveColor;
    [ ... ]
}

template MeshFace
{
    <3D82AB5F-62DA-11CF-AB39-0020AF71E433>
    DWORD nFaceVertexIndices;
    array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps
{
    <ED1EC5C0-C0A8-11D0-941C-0080C80CFA7B>
    DWORD nFaceWrapValues;
    array Boolean2d faceWrapValues[nFaceWrapValues];
}

template MeshTextureCoords
{
    <F6F23F40-7686-11CF-8F52-0040333594A3>
    DWORD nTextureCoords;
    array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList
{
    <F6F23F42-7686-11CF-8F52-0040333594A3>
    DWORD nMaterials;
    DWORD nFaceIndexes;
    array DWORD faceIndexes[nFaceIndexes];
    [ Material ]
}

template MeshNormals
{
    <F6F23F43-7686-11CF-8F52-0040333594A3>
    DWORD nNormals;
    array Vector normals[nNormals];
    DWORD nFaceNormals;
    array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors
{
    <1630B821-7842-11CF-8F52-0040333594A3>
    DWORD nVertexColors;
    array IndexedColor vertexColors[nVertexColors];
}

template Mesh
{
    <3D82AB44-62DA-11CF-AB39-0020AF71E433>
    DWORD nVertices;
    array Vector vertices[nVertices];
    DWORD nFaces;
    array MeshFace faces[nFaces];
    [ ... ]
}

template FrameTransformMatrix
{
    <F6F23F41-7686-11CF-8F52-0040333594A3>
    Matrix4x4 frameMatrix;
}

template Frame
{
    <3D82AB46-62DA-11CF-AB39-0020AF71E433>
    [ ... ]
}

template FloatKeys
{
    <10DD46A9-775B-11CF-8F52-0040333594A3>
    DWORD nValues;
    array FLOAT values[nValues];
}

template TimedFloatKeys
{
    <F406B180-7B3B-11CF-8F52-0040333594A3>
    DWORD time;
    FloatKeys tfkeys;
}

template AnimationKey
{
    <10DD46A8-775B-11CF-8F52-0040333594A3>
    DWORD keyType;
    DWORD nKeys;
    array TimedFloatKeys keys[nKeys];
}

template AnimationOptions
{
    <E2BF56C0-840F-11CF-8F52-0040333594A3>
    DWORD openclosed;
    DWORD positionquality;
}

template Animation
{
    <3D82AB4F-62DA-11CF-AB39-0020AF71E433>
    [ ... ]
}

template AnimationSet
{
    <3D82AB50-62DA-11CF-AB39-0020AF71E433>
    [ Animation ]
}

template InlineData
{
    <3A23EEA0-94B1-11D0-AB39-0020AF71E433>
    [ BINARY ]
}

template Url
{
    <3A23EEA1-94B1-11D0-AB39-0020AF71E433>
    DWORD nUrls;
    array STRING urls[nUrls];
}

template ProgressiveMesh
{
    <8A63C360-997D-11D0-941C-0080C80CFA7B>
    [ Url, InlineData ]
}

template Guid
{
    <A42790E0-7810-11CF-8F52-0040333594A3>
    DWORD data1;
    WORD data2;
    WORD data3;
    array UCHAR data4[8];
}

template StringProperty
{
    <7F0F21E0-BFE1-11D1-82C0-00A0C9697271>
    STRING key;
    STRING value;
}

template PropertyBag
{
    <7F0F21E1-BFE1-11D1-82C0-00A0C9697271>
    [ StringProperty ]
}

template ExternalVisual
{
    <98116AA0-BDBA-11D1-82C0-00A0C9697271>
    Guid guidExternalVisual;
    [ ... ]
}

template RightHanded
{
    <7F5D5EA0-D53A-11D1-82C0-00A0C9697271>
    DWORD bRightHanded;
}
