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

#ifndef WSDUTIL_H
#define WSDUTIL_H

void * WINAPI WSDAllocateLinkedMemory(void *pParent, SIZE_T cbSize);
void WINAPI WSDAttachLinkedMemory(void *pParent, void *pChild);
void WINAPI WSDDetachLinkedMemory(void *pVoid);
void WINAPI WSDFreeLinkedMemory(void *pVoid);

HRESULT WINAPI WSDXMLAddChild(WSDXML_ELEMENT *pParent, WSDXML_ELEMENT *pChild);
HRESULT WINAPI WSDXMLAddSibling(WSDXML_ELEMENT *pFirst, WSDXML_ELEMENT *pSecond);
HRESULT WINAPI WSDXMLBuildAnyForSingleElement(WSDXML_NAME *pElementName, LPCWSTR pszText, WSDXML_ELEMENT **ppAny);
HRESULT WINAPI WSDXMLCleanupElement(WSDXML_ELEMENT *pAny);
HRESULT WINAPI WSDXMLGetValueFromAny(const WCHAR *pszNamespace, const WCHAR *pszName, WSDXML_ELEMENT *pAny, LPCWSTR *ppszValue);

#endif
