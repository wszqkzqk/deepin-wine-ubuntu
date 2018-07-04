/*
 * Copyright (C) 2008 Stefan Leichter
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

#ifndef __WINE_RASERROR_H
#define __WINE_RASERROR_H

#define RASBASE                                600
#define ERROR_BUFFER_TOO_SMALL                 (RASBASE+3)
#define ERROR_BUFFER_INVALID                   (RASBASE+10)
#define ERROR_INVALID_SIZE                     (RASBASE+32)
#define ERROR_STATE_MACHINES_NOT_STARTED       (RASBASE+95)
#define ERROR_RASMAN_CANNOT_INITIALIZE         (RASBASE+111)

#endif
