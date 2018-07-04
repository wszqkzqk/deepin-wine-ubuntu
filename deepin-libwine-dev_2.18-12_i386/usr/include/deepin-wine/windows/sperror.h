/*
 * Speech API (SAPI) Errors.
 *
 * Copyright (C) 2017 Huw Davies
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

#ifndef SPError_h
#define SPError_h

#include <winerror.h>

#define SPERR_UNINITIALIZED                0x80045001
#define SPERR_ALREADY_INITIALIZED          0x80045002
#define SPERR_NOT_FOUND                    0x8004503a
#define SPERR_INVALID_REGISTRY_KEY         0x80045040

#endif /* SPError_h */
