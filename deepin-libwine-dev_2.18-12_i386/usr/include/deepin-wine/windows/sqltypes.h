/*
 * Copyright (C) 1999 Xiang Li
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

#ifndef __SQLTYPES_H
#define __SQLTYPES_H

#ifndef ODBCVER
#define ODBCVER	0x0351
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char   SQLCHAR;
#ifdef WINE_UNICODE_NATIVE
typedef wchar_t         SQLWCHAR;
#else
typedef unsigned short  SQLWCHAR;
#endif
#ifndef UNICODE
typedef SQLCHAR         SQLTCHAR;
#else
typedef SQLWCHAR        SQLTCHAR;
#endif

#if (ODBCVER >= 0x0300)
typedef unsigned char   SQLDATE;
typedef unsigned char   SQLDECIMAL;
typedef double          SQLDOUBLE;
typedef double          SQLFLOAT;
#endif

typedef int             SQLINTEGER;

#if (ODBCVER >= 0x0300)
typedef unsigned char   SQLNUMERIC;
#endif

typedef void *          SQLPOINTER;

#if (ODBCVER >= 0x0300)
typedef float           SQLREAL;
#endif

typedef signed short int   SQLSMALLINT;
typedef unsigned short  SQLUSMALLINT;

#if (ODBCVER >= 0x0300)
typedef unsigned char   SQLTIME;
typedef unsigned char   SQLTIMESTAMP;
typedef unsigned char   SQLVARCHAR;
#endif

typedef SQLSMALLINT     SQLRETURN;

#if (ODBCVER >= 0x0300)
typedef void *SQLHANDLE;
typedef SQLHANDLE               SQLHENV;
typedef SQLHANDLE               SQLHDBC;
typedef SQLHANDLE               SQLHSTMT;
typedef SQLHANDLE               SQLHDESC;
#else
typedef void *SQLHENV;
typedef void *SQLHDBC;
typedef void *SQLHSTMT;
#endif

typedef signed char             SCHAR;
typedef SCHAR                   SQLSCHAR;
typedef int                     SDWORD;
typedef signed short int        SWORD;
typedef unsigned int            UDWORD;
typedef unsigned short int      UWORD;
typedef UDWORD                  SQLUINTEGER;
typedef signed long             SLONG;
typedef signed short            SSHORT;
typedef double                  SDOUBLE;
typedef double            		LDOUBLE;
typedef float                   SFLOAT;
typedef void*              		PTR;
typedef signed short            RETCODE;
typedef void*                   SQLHWND;

#ifdef _WIN64
typedef INT64           SQLLEN;
typedef UINT64          SQLULEN;
typedef UINT64          SQLSETPOSIROW;
#else
#define SQLLEN          SQLINTEGER
#define SQLULEN         SQLUINTEGER
#define SQLSETPOSIROW   SQLUSMALLINT
#endif

typedef SQLHANDLE          		HENV;
typedef SQLHANDLE          		HDBC;
typedef SQLHANDLE          		HSTMT;

#ifndef	__SQLDATE
#define	__SQLDATE
typedef struct tagDATE_STRUCT
{
        SQLSMALLINT    year;
        SQLUSMALLINT   month;
        SQLUSMALLINT   day;
} DATE_STRUCT;

#if (ODBCVER >= 0x0300)
typedef DATE_STRUCT	SQL_DATE_STRUCT;
#endif

typedef struct tagTIME_STRUCT
{
        SQLUSMALLINT   hour;
        SQLUSMALLINT   minute;
        SQLUSMALLINT   second;
} TIME_STRUCT;

#if (ODBCVER >= 0x0300)
typedef TIME_STRUCT	SQL_TIME_STRUCT;
#endif

typedef struct tagTIMESTAMP_STRUCT
{
        SQLSMALLINT    year;
        SQLUSMALLINT   month;
        SQLUSMALLINT   day;
        SQLUSMALLINT   hour;
        SQLUSMALLINT   minute;
        SQLUSMALLINT   second;
        SQLUINTEGER    fraction;
} TIMESTAMP_STRUCT;

#if (ODBCVER >= 0x0300)
typedef TIMESTAMP_STRUCT	SQL_TIMESTAMP_STRUCT;
#endif


#if (ODBCVER >= 0x0300)
typedef enum
{
	SQL_IS_YEAR						= 1,
	SQL_IS_MONTH					= 2,
	SQL_IS_DAY						= 3,
	SQL_IS_HOUR						= 4,
	SQL_IS_MINUTE					= 5,
	SQL_IS_SECOND					= 6,
	SQL_IS_YEAR_TO_MONTH			= 7,
	SQL_IS_DAY_TO_HOUR				= 8,
	SQL_IS_DAY_TO_MINUTE			= 9,
	SQL_IS_DAY_TO_SECOND			= 10,
	SQL_IS_HOUR_TO_MINUTE			= 11,
	SQL_IS_HOUR_TO_SECOND			= 12,
	SQL_IS_MINUTE_TO_SECOND			= 13
} SQLINTERVAL;

#endif

#if (ODBCVER >= 0x0300)
typedef struct tagSQL_YEAR_MONTH
{
		SQLUINTEGER		year;
		SQLUINTEGER		month;
} SQL_YEAR_MONTH_STRUCT;

typedef struct tagSQL_DAY_SECOND
{
		SQLUINTEGER		day;
		SQLUINTEGER		hour;
		SQLUINTEGER		minute;
		SQLUINTEGER		second;
		SQLUINTEGER		fraction;
} SQL_DAY_SECOND_STRUCT;

typedef struct tagSQL_INTERVAL_STRUCT
{
	SQLINTERVAL		interval_type;
	SQLSMALLINT		interval_sign;
	union {
		SQL_YEAR_MONTH_STRUCT		year_month;
		SQL_DAY_SECOND_STRUCT		day_second;
	} intval;

} SQL_INTERVAL_STRUCT;

#endif

#endif

#if (ODBCVER >= 0x0300)
#define ODBCINT64	__int64
#define UODBCINT64	unsigned __int64
#ifdef ODBCINT64
typedef ODBCINT64	SQLBIGINT;
typedef unsigned ODBCINT64	SQLUBIGINT;
#endif
#endif

#if (ODBCVER >= 0x0300)
#define SQL_MAX_NUMERIC_LEN		16
typedef struct tagSQL_NUMERIC_STRUCT
{
	SQLCHAR		precision;
	SQLSCHAR	scale;
	SQLCHAR		sign;	/* 1=pos 0=neg */
	SQLCHAR		val[SQL_MAX_NUMERIC_LEN];
} SQL_NUMERIC_STRUCT;
#endif

#if (ODBCVER >= 0x0350)
#ifdef GUID_DEFINED
typedef GUID	SQLGUID;
#else
typedef struct  tagSQLGUID
{
    DWORD Data1;
    WORD Data2;
    WORD Data3;
    BYTE Data4[ 8 ];
} SQLGUID;
#endif
#endif


typedef SQLULEN BOOKMARK;

#define SQL_WCHAR             (-8)
#define SQL_C_WCHAR            SQL_WCHAR

#ifdef __cplusplus
}
#endif

#endif
