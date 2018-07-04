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

#ifndef __WSDXMLDOM_H__
#define __WSDXMLDOM_H__

typedef struct _WSDXML_TYPE WSDXML_TYPE;
typedef struct _WSDXML_NAMESPACE WSDXML_NAMESPACE;
typedef struct _WSDXML_NAME WSDXML_NAME;
typedef struct _WSDXML_PREFIX_MAPPING WSDXML_PREFIX_MAPPING;
typedef struct _WSDXML_ATTRIBUTE WSDXML_ATTRIBUTE;
typedef struct _WSDXML_NODE WSDXML_NODE;
typedef struct _WSDXML_ELEMENT WSDXML_ELEMENT;
typedef struct _WSDXML_TEXT WSDXML_TEXT;

typedef const WSDXML_NAMESPACE *PCWSDXML_NAMESPACE;
typedef const WSDXML_TYPE *PCWSDXML_TYPE;

struct _WSDXML_TYPE
{
    const WCHAR *Uri;
    const BYTE *Table;
};

struct _WSDXML_NAMESPACE
{
    const WCHAR *Uri;
    const WCHAR *PreferredPrefix;
    WSDXML_NAME *Names;
    WORD NamesCount;
    WORD Encoding;
};

struct _WSDXML_NAME
{
    WSDXML_NAMESPACE *Space;
    WCHAR *LocalName;
};

struct _WSDXML_PREFIX_MAPPING
{
    DWORD Refs;
    WSDXML_PREFIX_MAPPING *Next;
    WSDXML_NAMESPACE *Space;
    WCHAR *Prefix;
};

struct _WSDXML_ATTRIBUTE
{
    WSDXML_ELEMENT *Element;
    WSDXML_ATTRIBUTE *Next;
    WSDXML_NAME *Name;
    WCHAR *Value;
};

struct _WSDXML_NODE
{
    enum
    {
        ElementType,
        TextType
    } Type;
    WSDXML_ELEMENT *Parent;
    WSDXML_NODE *Next;
};

struct _WSDXML_ELEMENT
{
    WSDXML_NODE Node;
    WSDXML_NAME *Name;
    WSDXML_ATTRIBUTE *FirstAttribute;
    WSDXML_NODE *FirstChild;
    WSDXML_PREFIX_MAPPING *PrefixMappings;
};

struct _WSDXML_TEXT
{
    WSDXML_NODE Node;
    WCHAR *Text;
};

#endif /* __WSDXMLDOM_H__ */
