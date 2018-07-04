/*
 * Copyright 2017 Owen Rudge for CodeWeavers
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

#ifndef WSDTYPES_H
#define WSDTYPES_H

interface IWSDMessageParameters;

typedef struct _WSD_APP_SEQUENCE WSD_APP_SEQUENCE;
typedef struct _WSD_HEADER_RELATESTO WSD_HEADER_RELATESTO;
typedef struct _WSD_SOAP_HEADER WSD_SOAP_HEADER;
typedef struct _WSD_SOAP_MESSAGE WSD_SOAP_MESSAGE;
typedef struct _WSD_NAME_LIST WSD_NAME_LIST;
typedef struct _WSD_REFERENCE_PARAMETERS WSD_REFERENCE_PARAMETERS;
typedef struct _WSD_REFERENCE_PROPERTIES WSD_REFERENCE_PROPERTIES;
typedef struct _WSD_ENDPOINT_REFERENCE WSD_ENDPOINT_REFERENCE;
typedef struct _WSD_URI_LIST WSD_URI_LIST;

struct _WSD_APP_SEQUENCE
{
  ULONGLONG InstanceId;
  const WCHAR *SequenceId;
  ULONGLONG MessageNumber;
};

struct _WSD_NAME_LIST
{
    WSD_NAME_LIST *Next;
    WSDXML_NAME *Element;
};

struct _WSD_REFERENCE_PARAMETERS
{
    WSDXML_ELEMENT *Any;
};

struct _WSD_REFERENCE_PROPERTIES
{
    WSDXML_ELEMENT *Any;
};

struct _WSD_ENDPOINT_REFERENCE
{
    const WCHAR *Address;
    WSD_REFERENCE_PROPERTIES ReferenceProperties;
    WSD_REFERENCE_PARAMETERS ReferenceParameters;
    WSDXML_NAME *PortType;
    WSDXML_NAME *ServiceName;
    WSDXML_ELEMENT *Any;
};

struct _WSD_URI_LIST
{
    WSD_URI_LIST *Next;
    const WCHAR *Element;
};

struct _WSD_HEADER_RELATESTO
{
    WSDXML_NAME *RelationshipType;
    const WCHAR *MessageID;
};

struct _WSD_SOAP_HEADER
{
    const WCHAR *To;
    const WCHAR *Action;
    const WCHAR *MessageID;
    WSD_HEADER_RELATESTO RelatesTo;
    WSD_ENDPOINT_REFERENCE *ReplyTo;
    WSD_ENDPOINT_REFERENCE *From;
    WSD_ENDPOINT_REFERENCE *FaultTo;
    WSD_APP_SEQUENCE *AppSequence;
    WSDXML_ELEMENT *AnyHeaders;
};

struct _WSD_SOAP_MESSAGE
{
    WSD_SOAP_HEADER Header;
    void *Body;
    WSDXML_TYPE *BodyType;
};

#endif
