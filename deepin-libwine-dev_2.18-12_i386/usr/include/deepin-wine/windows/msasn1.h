/*
 * Copyright (C) 2015 Austin English
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
#ifndef __MS_ASN1_H__
#define __MS_ASN1_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef char ASN1char_t;
typedef signed char ASN1int8_t;
typedef unsigned char ASN1uint8_t;
typedef unsigned short ASN1uint16_t;
typedef signed short ASN1int16_t;
typedef ULONG ASN1uint32_t;
typedef LONG ASN1int32_t;

typedef ASN1uint16_t ASN1char16_t;
typedef ASN1uint32_t ASN1char32_t;

typedef ASN1char_t *ASN1ztcharstring_t;
typedef ASN1char16_t *ASN1ztchar16string_t;
typedef ASN1char32_t *ASN1ztchar32string_t;
typedef ASN1int32_t ASN1enum_t;
typedef ASN1uint8_t ASN1octet_t;
typedef ASN1uint8_t ASN1bool_t;
typedef ASN1uint16_t ASN1choice_t;
typedef ASN1uint32_t ASN1magic_t;
typedef ASN1ztcharstring_t ASN1objectdescriptor_t;

typedef void (WINAPI *ASN1FreeFun_t)(void *data);
typedef void (WINAPI *ASN1GenericFun_t)(void);

typedef struct ASN1encoding_s *ASN1encoding_t;
typedef struct ASN1decoding_s *ASN1decoding_t;
typedef ASN1int32_t (WINAPI *ASN1PerEncFun_t)(ASN1encoding_t enc,void *data);
typedef ASN1int32_t (WINAPI *ASN1PerDecFun_t)(ASN1decoding_t enc,void *data);

typedef struct tagASN1PerFunArr_t {
  const ASN1PerEncFun_t *apfnEncoder;
  const ASN1PerDecFun_t *apfnDecoder;
} ASN1PerFunArr_t;

typedef ASN1int32_t (WINAPI *ASN1BerEncFun_t)(ASN1encoding_t enc,ASN1uint32_t tag,void *data);
typedef ASN1int32_t (WINAPI *ASN1BerDecFun_t)(ASN1decoding_t enc,ASN1uint32_t tag,void *data);

typedef struct tagASN1BerFunArr_t {
  const ASN1BerEncFun_t *apfnEncoder;
  const ASN1BerDecFun_t *apfnDecoder;
} ASN1BerFunArr_t;

typedef struct tagASN1bitstring_t
{
  ASN1uint32_t length;
  ASN1octet_t *value;
} ASN1bitstring_t;

typedef enum tagASN1blocktype_e
{
  ASN1_DER_SET_OF_BLOCK,
} ASN1blocktype_e;

typedef struct tagASN1charstring_t
{
  ASN1uint32_t length;
  ASN1char_t *value;
} ASN1charstring_t;

typedef struct tagASN1char16string_t
{
  ASN1uint32_t length;
  ASN1char16_t *value;
} ASN1char16string_t;

typedef struct tagASN1char32string_t
{
  ASN1uint32_t length;
  ASN1char32_t *value;
} ASN1char32string_t;

typedef struct tagASN1encodedOID_t
{
  ASN1uint16_t length;
  ASN1octet_t  *value;
} ASN1encodedOID_t;

typedef enum {
  ASN1_PER_RULE_ALIGNED = 0x0001,ASN1_PER_RULE_UNALIGNED = 0x0002,ASN1_PER_RULE = ASN1_PER_RULE_ALIGNED | ASN1_PER_RULE_UNALIGNED,
  ASN1_BER_RULE_BER = 0x0100,ASN1_BER_RULE_CER = 0x0200,ASN1_BER_RULE_DER = 0x0400,
  ASN1_BER_RULE = ASN1_BER_RULE_BER | ASN1_BER_RULE_CER | ASN1_BER_RULE_DER
} ASN1encodingrule_e;

typedef enum tagASN1error_e
{
  ASN1_SUCCESS = 0,
  ASN1_ERR_INTERNAL = -1001,
  ASN1_ERR_EOD = -1002,
  ASN1_ERR_CORRUPT = -1003,
  ASN1_ERR_LARGE = -1004,
  ASN1_ERR_CONSTRAINT = -1005,
  ASN1_ERR_MEMORY = -1006,
  ASN1_ERR_OVERFLOW = -1007,
  ASN1_ERR_BADPDU = -1008,
  ASN1_ERR_BADARGS = -1009,
  ASN1_ERR_BADREAL = -1010,
  ASN1_ERR_BADTAG = -1011,
  ASN1_ERR_CHOICE = -1012,
  ASN1_ERR_RULE = -1013,
  ASN1_ERR_UTF8 = -1014,
  ASN1_ERR_PDU_TYPE = -1051,
  ASN1_ERR_NYI = -1052,
  ASN1_WRN_EXTENDED = 1001,
  ASN1_WRN_NOEOD = 1002,
} ASN1error_e;

typedef struct tagASN1generalizedtime_t
{
  ASN1uint16_t year;
  ASN1uint8_t  month;
  ASN1uint8_t  day;
  ASN1uint8_t  hour;
  ASN1uint8_t  minute;
  ASN1uint8_t  second;
  ASN1uint16_t millisecond;
  ASN1bool_t   universal;
  ASN1int16_t  diff;
} ASN1generalizedtime_t;

typedef struct tagASN1intx_t
{
  ASN1uint32_t length;
  ASN1octet_t *value;
} ASN1intx_t;

typedef struct tagASN1module_t {
  ASN1magic_t nModuleName;
  ASN1encodingrule_e eRule;
  ASN1uint32_t dwFlags;
  ASN1uint32_t cPDUs;
  const ASN1FreeFun_t *apfnFreeMemory;
  const ASN1uint32_t *acbStructSize;
  union {
    ASN1PerFunArr_t PER;
    ASN1BerFunArr_t BER;
  };
} *ASN1module_t;

typedef struct ASN1objectidentifier_s
{
  struct ASN1objectidentifier_s *next;
  ASN1uint32_t value;
} *ASN1objectidentifier_t;

typedef struct tagASN1objectidentifier2_t
{
  ASN1uint16_t count;
  ASN1uint32_t value[16];
} ASN1objectidentifier2_t;

typedef struct tagASN1octetstring_t
{
  ASN1uint32_t length;
  ASN1octet_t *value;
} ASN1octetstring_t;

typedef struct tagASN1open_t
{
  ASN1uint32_t    length;
  union
  {
    void  *encoded;
    void  *value;
  };
} ASN1open_t;

typedef enum tagASN1option_e
{
  ASN1OPT_CHANGE_RULE = 0x101,
  ASN1OPT_GET_RULE = 0x201,
  ASN1OPT_NOT_REUSE_BUFFER = 0x301,
  ASN1OPT_REWIND_BUFFER = 0x302,
  ASN1OPT_SET_DECODED_BUFFER = 0x501,
  ASN1OPT_DEL_DECODED_BUFFER = 0x502,
  ASN1OPT_GET_DECODED_BUFFER_SIZE = 0x601,
} ASN1option_e;

typedef struct tagASN1optionparam_t {
  ASN1option_e eOption;
  union
  {
    ASN1encodingrule_e eRule;
    ASN1uint32_t cbRequiredDecodedBufSize;
    struct
    {
      ASN1octet_t* pbBuf;
      ASN1uint32_t cbBufSize;
    } Buffer;
  };
} ASN1optionparam_t, ASN1optionparam_s;

typedef struct tagASN1utctime_t
{
  ASN1uint8_t year;
  ASN1uint8_t month;
  ASN1uint8_t day;
  ASN1uint8_t hour;
  ASN1uint8_t minute;
  ASN1uint8_t second;
  ASN1bool_t  universal;
  ASN1int16_t diff;
} ASN1utctime_t;

typedef struct tagASN1wstring_t
{
  ASN1uint32_t length;
  WCHAR *value;
} ASN1wstring_t;

void         WINAPI ASN1_CloseDecoder(ASN1decoding_t);
void         WINAPI ASN1_CloseEncoder(ASN1encoding_t);
void         WINAPI ASN1_CloseEncoder2(ASN1encoding_t);
void         WINAPI ASN1_CloseModule(ASN1module_t);
ASN1error_e  WINAPI ASN1_CreateDecoder(ASN1module_t, ASN1decoding_t*,ASN1octet_t*, ASN1uint32_t, ASN1decoding_t);
ASN1error_e  WINAPI ASN1_CreateEncoder(ASN1module_t, ASN1encoding_t*, ASN1octet_t*, ASN1uint32_t, ASN1encoding_t);
ASN1module_t WINAPI ASN1_CreateModule(ASN1uint32_t,ASN1encodingrule_e,ASN1uint32_t,ASN1uint32_t,const ASN1GenericFun_t [],const ASN1GenericFun_t [],const ASN1FreeFun_t [],const ASN1uint32_t [],ASN1magic_t);
ASN1error_e  WINAPI ASN1_Decode(ASN1decoding_t, void** , ASN1uint32_t, ASN1uint32_t, ASN1octet_t*, ASN1uint32_t);
ASN1error_e  WINAPI ASN1_Encode(ASN1encoding_t, void*, ASN1uint32_t, ASN1uint32_t, ASN1octet_t*, ASN1uint32_t);
void         WINAPI ASN1_FreeDecoded(ASN1decoding_t, void*, ASN1uint32_t);
void         WINAPI ASN1_FreeEncoded(ASN1encoding_t, void*);
ASN1error_e  WINAPI ASN1_GetDecoderOption(ASN1decoding_t, ASN1optionparam_t*);
ASN1error_e  WINAPI ASN1_GetEncoderOption(ASN1encoding_t, ASN1optionparam_t*);
ASN1error_e  WINAPI ASN1_SetDecoderOption(ASN1decoding_t, ASN1optionparam_t*);
ASN1error_e  WINAPI ASN1_SetEncoderOption(ASN1encoding_t, ASN1optionparam_t*);
int          WINAPI ASN1bitstring_cmp(ASN1bitstring_t*,ASN1bitstring_t*);
void         WINAPI ASN1bitstring_free(ASN1bitstring_t*);
int          WINAPI ASN1char16string_cmp(ASN1char16string_t*,ASN1char16string_t*);
void         WINAPI ASN1char16string_free(ASN1char16string_t*);
int          WINAPI ASN1char32string_cmp(ASN1char32string_t*,ASN1char32string_t*);
void         WINAPI ASN1char32string_free(ASN1char32string_t*);
int          WINAPI ASN1charstring_cmp(ASN1charstring_t*,ASN1charstring_t*);
void         WINAPI ASN1charstring_free(ASN1charstring_t*);
LPVOID       WINAPI ASN1DecAlloc(ASN1decoding_t,ASN1uint32_t);
LPVOID       WINAPI ASN1DecRealloc(ASN1decoding_t,LPVOID,ASN1uint32_t);
ASN1error_e  WINAPI ASN1DecSetError(ASN1decoding_t,ASN1error_e);
ASN1error_e  WINAPI ASN1EncSetError(ASN1encoding_t,ASN1error_e);
void         WINAPI ASN1Free(LPVOID);
int          WINAPI ASN1generalizedtime_cmp(ASN1generalizedtime_t*,ASN1generalizedtime_t*);
int          WINAPI ASN1intx_cmp(ASN1intx_t*,ASN1intx_t*);
void         WINAPI ASN1intx_free(ASN1intx_t*);
void         WINAPI ASN1intx_setuint32(ASN1intx_t*,ASN1uint32_t);
ASN1uint32_t WINAPI ASN1intx_uoctets(ASN1intx_t*);
ASN1int32_t  WINAPI ASN1intx2int32(ASN1intx_t*);
ASN1uint32_t WINAPI ASN1intx2uint32(ASN1intx_t*);
int          WINAPI ASN1intxisuint32(ASN1intx_t*);
int          WINAPI ASN1objectidentifier_cmp(ASN1objectidentifier_t*,ASN1objectidentifier_t*);
void         WINAPI ASN1objectidentifier_free(ASN1objectidentifier_t*);
int          WINAPI ASN1objectidentifier2_cmp(ASN1objectidentifier2_t*,ASN1objectidentifier2_t*);
int          WINAPI ASN1octetstring_cmp(ASN1octetstring_t*,ASN1octetstring_t*);
void         WINAPI ASN1octetstring_free(ASN1octetstring_t*);
int          WINAPI ASN1open_cmp(ASN1open_t*,ASN1open_t*);
void         WINAPI ASN1open_free(ASN1open_t*);
ASN1uint32_t WINAPI ASN1uint32_uoctets(ASN1uint32_t);
void         WINAPI ASN1utf8string_free(ASN1wstring_t*);
int          WINAPI ASN1utctime_cmp(ASN1utctime_t*,ASN1utctime_t*);
int          WINAPI ASN1ztchar16string_cmp(ASN1ztchar16string_t*,ASN1ztchar16string_t*);
void         WINAPI ASN1ztchar16string_free(ASN1ztchar16string_t*);
void         WINAPI ASN1ztchar32string_free(ASN1ztchar32string_t*);
int          WINAPI ASN1ztcharstring_cmp(ASN1ztcharstring_t*,ASN1ztcharstring_t*);
void         WINAPI ASN1ztcharstring_free(ASN1charstring_t*);

#ifdef __cplusplus
}
#endif

#endif /* __MS_ASN1_H__ */
