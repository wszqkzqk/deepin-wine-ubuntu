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
#define _KS_

typedef union tagKSIDENTIFIER
{
    struct
    {
        GUID Set;
        ULONG Id;
        ULONG Flags;
    } DUMMYSTRUCTNAME;
    LONGLONG Alignment;
} KSIDENTIFIER;

typedef KSIDENTIFIER KSPROPERTY, *PKSPROPERTY, KSMETHOD, *PKSMETHOD, KSEVENT, *PKSEVENT;

typedef enum
{
    KSPIN_DATAFLOW_IN = 1,
    KSPIN_DATAFLOW_OUT
} KSPIN_DATAFLOW, *PKSPIN_DATAFLOW;

#define KSDATAFORMAT_BIT_TEMPORAL_COMPRESSION 0
#define KSDATAFORMAT_BIT_ATTRIBUTES 1
#define KSDATAFORMAT_TEMPORAL_COMPRESSION (1 << 0)
#define KSDATAFORMAT_ATTRIBUTES 1 (1 << 1)

#define KSDATARANGE_BIT_ATTRIBUTES 1
#define KSDATARANGE_BIT_REQUIRED_ATTRIBUTES 2
#define KSDATARANGE_ATTRIBUTES (1 << 1)
#define KSDATARANGE_REQUIRED_ATTRIBUTES (1 << 2)

typedef union unionKSDATAFORMAT
{
    struct
    {
        ULONG FormatSize;
        ULONG Flags;
        ULONG SampleSize;
        ULONG Reserved;
        GUID MajorFormat;
        GUID SubFormat;
        GUID Specifier;
    } DUMMYSTRUCTNAME;
    LONGLONG Alignment;
} KSDATAFORMAT, *PKSDATAFORMAT, KSDATARANGE, *PKSDATARANGE;

#endif  /* _KS_ */
