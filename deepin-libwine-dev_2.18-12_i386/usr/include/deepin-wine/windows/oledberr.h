/* OLE DB error codes.
 *
 * Copyright 2009 Huw Davies
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


#ifndef __WINE_OLEDBERR_H
#define __WINE_OLEDBERR_H

#define DB_E_BADBINDINFO                    0x80040e08

#define DB_E_ERRORSINCOMMAND                0x80040e14
#define DB_E_CANTCANCEL                     0x80040e15
#define DB_E_DIALECTNOTSUPPORTED            0x80040e16
#define DB_E_DUPLICATEDATASOURCE            0x80040e17
#define DB_E_CANNOTRESTART                  0x80040e18
#define DB_E_NOTFOUND                       0x80040e19

#define DB_E_UNSUPPORTEDCONVERSION          0x80040e1d

#define DB_E_ERRORSOCCURRED                 0x80040e21

#define DB_E_BADSTORAGEFLAG                 0x80040e26
#define DB_E_BADCOMPAREOP                   0x80040e27
#define DB_E_BADSTATUSVALUE                 0x80040e28
#define DB_E_CANTSCROLLBACKWARDS            0x80040e29
#define DB_E_BADREGIONHANDLE                0x80040e2a
#define DB_E_NONCONTIGUOUSRANGE             0x80040e2b
#define DB_E_INVALIDTRANSITION              0x80040e2c
#define DB_E_NOTASUBREGION                  0x80040e2d
#define DB_E_MULTIPLESTATEMENTS             0x80040e2e
#define DB_E_INTEGRITYVIOLATION             0x80040e2f
#define DB_E_BADTYPENAME                    0x80040e30
#define DB_E_ABORTLIMITREACHED              0x80040e31
#define DB_E_ROWSETINCOMMAND                0x80040e32
#define DB_E_CANTTRANSLATE                  0x80040e33
#define DB_E_DUPLICATEINDEXID               0x80040e34
#define DB_E_NOINDEX                        0x80040e35
#define DB_E_INDEXINUSE                     0x80040e36
#define DB_E_NOTABLE                        0x80040e37
#define DB_E_CONCURRENCYVIOLATION           0x80040e38

#define DB_E_TABLEINUSE                     0x80040e40
#define DB_E_NOLOCALE                       0x80040e41
#define DB_E_BADRECORDNUM                   0x80040e42
#define DB_E_BOOKMARKSKIPPED                0x80040e43
#define DB_E_BADPROPERTYVALUE               0x80040e44
#define DB_E_INVALID                        0x80040e45
#define DB_E_BADACCESSORFLAGS               0x80040e46
#define DB_E_BADSTORAGEFLAGS                0x80040e47
#define DB_E_BYREFACCESSORNOTSUPPORTED      0x80040e48
#define DB_E_NULLACCESSORNOTSUPPORTED       0x80040e49
#define DB_E_NOTPREPARED                    0x80040e4a
#define DB_E_BADACCESSORTYPE                0x80040e4b
#define DB_E_WRITEONLYACCESSOR              0x80040e4c
#define DB_SEC_E_AUTH_FAILED                0x80040e4d
#define DB_E_CANCELED                       0x80040e4e

#define DB_E_ALREADYINITIALIZED             0x80040e52
#define DB_E_DATAOVERFLOW                   0x80040e57

#define DB_E_MISMATCHEDPROVIDER             0x80040e75

#define DB_S_ERRORSOCCURRED                 0x00040eda

#endif /* __WINE_OLEDBERR_H */
