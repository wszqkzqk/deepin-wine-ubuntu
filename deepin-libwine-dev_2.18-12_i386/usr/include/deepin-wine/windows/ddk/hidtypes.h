/*
 * Copyright (C) 2015 Aric Stewart
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
#ifndef __HIDTYPES_H
#define __HIDTYPES_H

typedef enum _HID_STRING_TYPE {
    HID_STRING_INDEXED = 0,
    HID_STRING_ID_IMANUFACTURER,
    HID_STRING_ID_IPRODUCT,
    HID_STRING_ID_ISERIALNUMBER,
    HID_STRING_MAX
} HID_STRING_TYPE;

#endif /* __HIDTYPES_H */
