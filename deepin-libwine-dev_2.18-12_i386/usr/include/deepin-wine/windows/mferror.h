/*
 * Copyright (C) 2014 Sebastian Lackner
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

#ifndef __WINE_MFERROR_H
#define __WINE_MFERROR_H

#define MF_E_PLATFORM_NOT_INITIALIZED       _HRESULT_TYPEDEF_(0xc00d36b0)
#define MF_E_BUFFERTOOSMALL                 _HRESULT_TYPEDEF_(0xc00d36b1)
#define MF_E_INVALIDREQUEST                 _HRESULT_TYPEDEF_(0xc00d36b2)
#define MF_E_INVALIDSTREAMNUMBER            _HRESULT_TYPEDEF_(0xc00d36b3)
#define MF_E_INVALIDMEDIATYPE               _HRESULT_TYPEDEF_(0xc00d36b4)
#define MF_E_NOTACCEPTING                   _HRESULT_TYPEDEF_(0xc00d36b5)
#define MF_E_NOT_INITIALIZED                _HRESULT_TYPEDEF_(0xc00d36b6)
#define MF_E_UNSUPPORTED_REPRESENTATION     _HRESULT_TYPEDEF_(0xc00d36b7)
#define MF_E_NO_MORE_TYPES                  _HRESULT_TYPEDEF_(0xc00d36b9)
#define MF_E_UNSUPPORTED_SERVICE            _HRESULT_TYPEDEF_(0xc00d36ba)
#define MF_E_UNEXPECTED                     _HRESULT_TYPEDEF_(0xc00d36bb)
#define MF_E_INVALIDNAME                    _HRESULT_TYPEDEF_(0xc00d36bc)
#define MF_E_INVALIDTYPE                    _HRESULT_TYPEDEF_(0xc00d36bd)
#define MF_E_INVALID_FILE_FORMAT            _HRESULT_TYPEDEF_(0xc00d36be)
#define MF_E_INVALIDINDEX                   _HRESULT_TYPEDEF_(0xc00d36bf)
#define MF_E_INVALID_TIMESTAMP              _HRESULT_TYPEDEF_(0xc00d36c0)
#define MF_E_UNSUPPORTED_SCHEME             _HRESULT_TYPEDEF_(0xc00d36c3)
#define MF_E_UNSUPPORTED_BYTESTREAM_TYPE    _HRESULT_TYPEDEF_(0xc00d36c4)
#define MF_E_UNSUPPORTED_TIME_FORMAT        _HRESULT_TYPEDEF_(0xc00d36c5)
#define MF_E_NO_SAMPLE_TIMESTAMP            _HRESULT_TYPEDEF_(0xc00d36c8)
#define MF_E_NO_SAMPLE_DURATION             _HRESULT_TYPEDEF_(0xc00d36c9)
#define MF_E_INVALID_STREAM_DATA            _HRESULT_TYPEDEF_(0xc00d36cb)
#define MF_E_RT_UNAVAILABLE                 _HRESULT_TYPEDEF_(0xc00d36cf)
#define MF_E_UNSUPPORTED_RATE               _HRESULT_TYPEDEF_(0xc00d36d0)
#define MF_E_THINNING_UNSUPPORTED           _HRESULT_TYPEDEF_(0xc00d36d1)
#define MF_E_REVERSE_UNSUPPORTED            _HRESULT_TYPEDEF_(0xc00d36d2)
#define MF_E_UNSUPPORTED_RATE_TRANSITION    _HRESULT_TYPEDEF_(0xc00d36d3)
#define MF_E_RATE_CHANGE_PREEMPTED          _HRESULT_TYPEDEF_(0xc00d36d4)
#define MF_E_NOT_FOUND                      _HRESULT_TYPEDEF_(0xc00d36d5)
#define MF_E_NOT_AVAILABLE                  _HRESULT_TYPEDEF_(0xc00d36d6)
#define MF_E_NO_CLOCK                       _HRESULT_TYPEDEF_(0xc00d36d7)
#define MF_S_MULTIPLE_BEGIN                 _HRESULT_TYPEDEF_(0x000d36d8)
#define MF_E_MULTIPLE_BEGIN                 _HRESULT_TYPEDEF_(0xc00d36d9)
#define MF_E_MULTIPLE_SUBSCRIBERS           _HRESULT_TYPEDEF_(0xc00d36da)
#define MF_E_TIMER_ORPHANED                 _HRESULT_TYPEDEF_(0xc00d36db)
#define MF_E_STATE_TRANSITION_PENDING       _HRESULT_TYPEDEF_(0xc00d36dc)
#define MF_E_UNSUPPORTED_STATE_TRANSITION   _HRESULT_TYPEDEF_(0xc00d36dd)
#define MF_E_UNRECOVERABLE_ERROR_OCCURRED   _HRESULT_TYPEDEF_(0xc00d36de)
#define MF_E_SAMPLE_HAS_TOO_MANY_BUFFERS    _HRESULT_TYPEDEF_(0xc00d36df)
#define MF_E_SAMPLE_NOT_WRITABLE            _HRESULT_TYPEDEF_(0xc00d36e0)
#define MF_E_INVALID_KEY                    _HRESULT_TYPEDEF_(0xc00d36e2)
#define MF_E_BAD_STARTUP_VERSION            _HRESULT_TYPEDEF_(0xc00d36e3)
#define MF_E_UNSUPPORTED_CAPTION            _HRESULT_TYPEDEF_(0xc00d36e4)
#define MF_E_INVALID_POSITION               _HRESULT_TYPEDEF_(0xc00d36e5)
#define MF_E_ATTRIBUTENOTFOUND              _HRESULT_TYPEDEF_(0xc00d36e6)
#define MF_E_PROPERTY_TYPE_NOT_ALLOWED      _HRESULT_TYPEDEF_(0xc00d36e7)

#define MF_E_TOPO_INVALID_OPTIONAL_NODE             _HRESULT_TYPEDEF_(0xc00d520e)
#define MF_E_TOPO_CANNOT_FIND_DECRYPTOR             _HRESULT_TYPEDEF_(0xc00d5211)
#define MF_E_TOPO_CODEC_NOT_FOUND                   _HRESULT_TYPEDEF_(0xc00d5212)
#define MF_E_TOPO_CANNOT_CONNECT                    _HRESULT_TYPEDEF_(0xc00d5213)
#define MF_E_TOPO_UNSUPPORTED                       _HRESULT_TYPEDEF_(0xc00d5214)
#define MF_E_TOPO_INVALID_TIME_ATTRIBUTES           _HRESULT_TYPEDEF_(0xc00d5215)
#define MF_E_TOPO_LOOPS_IN_TOPOLOGY                 _HRESULT_TYPEDEF_(0xC00d5216)
#define MF_E_TOPO_MISSING_PRESENTATION_DESCRIPTOR   _HRESULT_TYPEDEF_(0xc00d5217)
#define MF_E_TOPO_MISSING_STREAM_DESCRIPTOR         _HRESULT_TYPEDEF_(0xc00d5218)
#define MF_E_TOPO_STREAM_DESCRIPTOR_NOT_SELECTED    _HRESULT_TYPEDEF_(0xc00d5219)
#define MF_E_TOPO_MISSING_SOURCE                    _HRESULT_TYPEDEF_(0xc00d521a)
#define MF_E_TOPO_SINK_ACTIVATES_UNSUPPORTED        _HRESULT_TYPEDEF_(0xc00d521b)

#endif  /* __WINE_MFERROR_H */
