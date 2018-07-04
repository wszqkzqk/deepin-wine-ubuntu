/*
 * Declarations for IMAGEHLP
 *
 * Copyright (C) 1998 Patrik Stridvall
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

#ifndef __WINE_IMAGEHLP_H
#define __WINE_IMAGEHLP_H

#include <wintrust.h>

/* A set of documentation macros (see also dbghelp.h) */
#ifndef __deref_out
# define __deref_out
#endif
#ifndef __deref_out_opt
# define __deref_out_opt
#endif
#ifndef __deref_opt_out
# define __deref_opt_out
#endif
#ifndef __in
# define __in
#endif
#ifndef __in_opt
# define __in_opt
#endif
#ifndef __in_bcount
# define __in_bcount(x)
#endif
#ifndef __in_bcount_opt
# define __in_bcount_opt(x)
#endif
#ifndef __in_ecount
# define __in_ecount(x)
#endif
#ifndef __inout
# define __inout
#endif
#ifndef __inout_opt
# define __inout_opt
#endif
#ifndef __inout_bcount
# define __inout_bcount(x)
#endif
#ifndef __inout_ecount
# define __inout_ecount(x)
#endif
#ifndef __out
# define __out
#endif
#ifndef __out_opt
# define __out_opt
#endif
#ifndef __out_bcount
# define __out_bcount(x)
#endif
#ifndef __out_bcount_opt
# define __out_bcount_opt(x)
#endif
#ifndef __out_ecount
# define __out_ecount(x)
#endif
#ifndef __out_ecount_opt
# define __out_ecount_opt(x)
#endif
#ifndef __out_xcount
# define __out_xcount(x)
#endif


#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

#define IMAGEAPI WINAPI
#define DBHLPAPI IMAGEAPI

#define API_VERSION_NUMBER 7 		/* 7 is the default */

/***********************************************************************
 * Types
 */

typedef PVOID DIGEST_HANDLE;

/***********************************************************************
 * Enums/Defines
 */

typedef enum _IMAGEHLP_STATUS_REASON {
  BindOutOfMemory,
  BindRvaToVaFailed,
  BindNoRoomInImage,
  BindImportModuleFailed,
  BindImportProcedureFailed,
  BindImportModule,
  BindImportProcedure,
  BindForwarder,
  BindForwarderNOT,
  BindImageModified,
  BindExpandFileHeaders,
  BindImageComplete,
  BindMismatchedSymbols,
  BindSymbolsNotUpdated
} IMAGEHLP_STATUS_REASON;

#define BIND_NO_BOUND_IMPORTS  0x00000001
#define BIND_NO_UPDATE         0x00000002
#define BIND_ALL_IMAGES        0x00000004
#define BIND_CACHE_IMPORT_DLLS 0x00000008

#define CERT_PE_IMAGE_DIGEST_DEBUG_INFO      0x01
#define CERT_PE_IMAGE_DIGEST_RESOURCES       0x02
#define CERT_PE_IMAGE_DIGEST_ALL_IMPORT_INFO 0x04
#define CERT_PE_IMAGE_DIGEST_NON_PE_INFO     0x08

#define CERT_SECTION_TYPE_ANY 0xFF

#define SPLITSYM_REMOVE_PRIVATE    0x00000001
#define SPLITSYM_EXTRACT_ALL       0x00000002
#define SPLITSYM_SYMBOLPATH_IS_SRC 0x00000004

#define FRAME_FPO    0
#define FRAME_TRAP   1
#define FRAME_TSS    2
#define FRAME_NONFPO 3

#define CHECKSUM_SUCCESS         0
#define CHECKSUM_OPEN_FAILURE    1
#define CHECKSUM_MAP_FAILURE     2
#define CHECKSUM_MAPVIEW_FAILURE 3
#define CHECKSUM_UNICODE_FAILURE 4

typedef enum _ADDRESS_MODE {
  AddrMode1616,
  AddrMode1632,
  AddrModeReal,
  AddrModeFlat
} ADDRESS_MODE;

#define SYMOPT_CASE_INSENSITIVE  0x00000001
#define SYMOPT_UNDNAME           0x00000002
#define SYMOPT_DEFERRED_LOADS    0x00000004
#define SYMOPT_NO_CPP            0x00000008
#define SYMOPT_LOAD_LINES        0x00000010
#define SYMOPT_OMAP_FIND_NEAREST 0x00000020

#define SYMF_OMAP_GENERATED   0x00000001
#define SYMF_OMAP_MODIFIED    0x00000002
/* 0x00000004 has been obsoleted */
#define SYMF_REGISTER         0x00000008
#define SYMF_REGREL           0x00000010
#define SYMF_FRAMEREL         0x00000020
#define SYMF_PARAMETER        0x00000040
#define SYMF_LOCAL            0x00000080
#define SYMF_CONSTANT         0x00000100
#define SYMF_EXPORT           0x00000200
#define SYMF_FORWARDER        0x00000400
#define SYMF_FUNCTION         0x00000800

typedef enum {
  SymNone,
  SymCoff,
  SymCv,
  SymPdb,
  SymExport,
  SymDeferred,
  SymSym,
  SymDia,
  SymVirtual,
  NumSymTypes
} SYM_TYPE;

#define UNDNAME_COMPLETE               0x0000
#define UNDNAME_NO_LEADING_UNDERSCORES 0x0001
#define UNDNAME_NO_MS_KEYWORDS         0x0002
#define UNDNAME_NO_FUNCTION_RETURNS    0x0004
#define UNDNAME_NO_ALLOCATION_MODEL    0x0008
#define UNDNAME_NO_ALLOCATION_LANGUAGE 0x0010
#define UNDNAME_NO_MS_THISTYPE         0x0020
#define UNDNAME_NO_CV_THISTYPE         0x0040
#define UNDNAME_NO_THISTYPE            0x0060
#define UNDNAME_NO_ACCESS_SPECIFIERS   0x0080
#define UNDNAME_NO_THROW_SIGNATURES    0x0100
#define UNDNAME_NO_MEMBER_TYPE         0x0200
#define UNDNAME_NO_RETURN_UDT_MODEL    0x0400
#define UNDNAME_32_BIT_DECODE          0x0800
#define UNDNAME_NAME_ONLY              0x1000
#define UNDNAME_NO_ARGUMENTS           0x2000
#define UNDNAME_NO_SPECIAL_SYMS        0x4000

#define CBA_DEFERRED_SYMBOL_LOAD_START          0x00000001
#define CBA_DEFERRED_SYMBOL_LOAD_COMPLETE       0x00000002
#define CBA_DEFERRED_SYMBOL_LOAD_FAILURE        0x00000003
#define CBA_SYMBOLS_UNLOADED                    0x00000004
#define CBA_DUPLICATE_SYMBOL                    0x00000005

/***********************************************************************
 * Structures
 */

typedef struct _LOADED_IMAGE
{
    PSTR                        ModuleName;
    HANDLE                      hFile;
    PUCHAR                      MappedAddress;
    PIMAGE_NT_HEADERS           FileHeader;
    PIMAGE_SECTION_HEADER       LastRvaSection;
    ULONG                       NumberOfSections;
    PIMAGE_SECTION_HEADER       Sections;
    ULONG                       Characteristics;
    BOOLEAN                     fSystemImage;
    BOOLEAN                     fDOSImage;
    BOOLEAN                     fReadOnly;
    UCHAR                       Version;
    LIST_ENTRY                  Links;
    ULONG                       SizeOfImage;
} LOADED_IMAGE, *PLOADED_IMAGE;

typedef struct _API_VERSION {
  USHORT  MajorVersion;
  USHORT  MinorVersion;
  USHORT  Revision;
  USHORT  Reserved;
} API_VERSION, *LPAPI_VERSION;

typedef struct _IMAGE_DEBUG_INFORMATION {
  LIST_ENTRY List;
  DWORD        Size;
  PVOID        MappedBase;
  USHORT       Machine;
  USHORT       Characteristics;
  DWORD        CheckSum;
  DWORD        ImageBase;
  DWORD        SizeOfImage;

  DWORD NumberOfSections;
  PIMAGE_SECTION_HEADER Sections;

  DWORD ExportedNamesSize;
  PSTR ExportedNames;

  DWORD NumberOfFunctionTableEntries;
  PIMAGE_FUNCTION_ENTRY FunctionTableEntries;
  DWORD LowestFunctionStartingAddress;
  DWORD HighestFunctionEndingAddress;

  DWORD NumberOfFpoTableEntries;
  PFPO_DATA FpoTableEntries;

  DWORD SizeOfCoffSymbols;
  PIMAGE_COFF_SYMBOLS_HEADER CoffSymbols;

  DWORD SizeOfCodeViewSymbols;
  PVOID CodeViewSymbols;

  PSTR ImageFilePath;
  PSTR ImageFileName;
  PSTR DebugFilePath;

  DWORD TimeDateStamp;

  BOOL RomImage;
  PIMAGE_DEBUG_DIRECTORY DebugDirectory;
  DWORD  NumberOfDebugDirectories;

  DWORD Reserved[3];
} IMAGE_DEBUG_INFORMATION, *PIMAGE_DEBUG_INFORMATION;

typedef struct _ADDRESS {
    DWORD          Offset;
    WORD           Segment;
    ADDRESS_MODE Mode;
} ADDRESS, *LPADDRESS;

typedef struct _ADDRESS64 {
    DWORD64        Offset;
    WORD           Segment;
    ADDRESS_MODE   Mode;
} ADDRESS64, *LPADDRESS64;

typedef struct _KDHELP {
  DWORD Thread;
  DWORD ThCallbackStack;
  DWORD NextCallback;
  DWORD FramePointer;
  DWORD KiCallUserMode;
  DWORD KeUserCallbackDispatcher;
  DWORD SystemRangeStart;
} KDHELP, *PKDHELP;

typedef struct _KDHELP64 {
    DWORD64 Thread;
    DWORD   ThCallbackStack;
    DWORD   ThCallbackBStore;
    DWORD   NextCallback;
    DWORD   FramePointer;
    DWORD64 KiCallUserMode;
    DWORD64 KeUserCallbackDispatcher;
    DWORD64 SystemRangeStart;
    DWORD64 Reserved[8];
} KDHELP64, *PKDHELP64;

typedef struct _STACKFRAME {
  ADDRESS AddrPC;
  ADDRESS AddrReturn;
  ADDRESS AddrFrame;
  ADDRESS AddrStack;
  PVOID     FuncTableEntry;
  DWORD     Params[4];
  BOOL    Far;
  BOOL    Virtual;
  DWORD     Reserved[3];
  KDHELP  KdHelp;
} STACKFRAME, *LPSTACKFRAME;

typedef struct _STACKFRAME64 {
    ADDRESS64 AddrPC;
    ADDRESS64 AddrReturn;
    ADDRESS64 AddrFrame;
    ADDRESS64 AddrStack;
    ADDRESS64 AddrBStore;
    PVOID     FuncTableEntry;
    DWORD64   Params[4];
    BOOL      Far;
    BOOL      Virtual;
    DWORD64   Reserved[3];
    KDHELP64  KdHelp;
} STACKFRAME64, *LPSTACKFRAME64;

typedef struct _SOURCEFILE {
    DWORD64                     ModBase;
    PCHAR                       FileName;
} SOURCEFILE, *PSOURCEFILE;

typedef struct _SOURCEFILEW
{
    DWORD64                     ModBase;
    PWSTR                       FileName;
} SOURCEFILEW, *PSOURCEFILEW;

typedef struct _IMAGEHLP_STACK_FRAME
{
  DWORD InstructionOffset;
  DWORD ReturnOffset;
  DWORD FrameOffset;
  DWORD StackOffset;
  DWORD BackingStoreOffset;
  DWORD FuncTableEntry;
  DWORD Params[4];
  DWORD Reserved[5];
  DWORD Virtual;
  DWORD Reserved2;
} IMAGEHLP_STACK_FRAME, *PIMAGEHLP_STACK_FRAME;

typedef VOID IMAGEHLP_CONTEXT, *PIMAGEHLP_CONTEXT;

typedef struct _IMAGEHLP_SYMBOL {
  DWORD SizeOfStruct;
  DWORD Address;
  DWORD Size;
  DWORD Flags;
  DWORD MaxNameLength;
  CHAR  Name[ANYSIZE_ARRAY];
} IMAGEHLP_SYMBOL, *PIMAGEHLP_SYMBOL;

typedef struct _IMAGEHLP_SYMBOLW {
  DWORD SizeOfStruct;
  DWORD Address;
  DWORD Size;
  DWORD Flags;
  DWORD MaxNameLength;
  WCHAR Name[ANYSIZE_ARRAY];
} IMAGEHLP_SYMBOLW, *PIMAGEHLP_SYMBOLW;

typedef struct _IMAGEHLP_SYMBOL64
{
    DWORD                       SizeOfStruct;
    DWORD64                     Address;
    DWORD                       Size;
    DWORD                       Flags;
    DWORD                       MaxNameLength;
    CHAR                        Name[1];
} IMAGEHLP_SYMBOL64, *PIMAGEHLP_SYMBOL64;

typedef struct _IMAGEHLP_SYMBOLW64
{
    DWORD                       SizeOfStruct;
    DWORD64                     Address;
    DWORD                       Size;
    DWORD                       Flags;
    DWORD                       MaxNameLength;
    WCHAR                       Name[1];
} IMAGEHLP_SYMBOLW64, *PIMAGEHLP_SYMBOLW64;

typedef struct _IMAGEHLP_MODULE {
  DWORD      SizeOfStruct;
  DWORD      BaseOfImage;
  DWORD      ImageSize;
  DWORD      TimeDateStamp;
  DWORD      CheckSum;
  DWORD      NumSyms;
  SYM_TYPE   SymType;
  CHAR       ModuleName[32];
  CHAR       ImageName[256];
  CHAR       LoadedImageName[256];
} IMAGEHLP_MODULE, *PIMAGEHLP_MODULE;

typedef struct _IMAGEHLP_MODULEW {
  DWORD      SizeOfStruct;
  DWORD      BaseOfImage;
  DWORD      ImageSize;
  DWORD      TimeDateStamp;
  DWORD      CheckSum;
  DWORD      NumSyms;
  SYM_TYPE   SymType;
  WCHAR      ModuleName[32];
  WCHAR      ImageName[256];
  WCHAR      LoadedImageName[256];
} IMAGEHLP_MODULEW, *PIMAGEHLP_MODULEW;

typedef struct _IMAGEHLP_MODULE64
{
    DWORD                       SizeOfStruct;
    DWORD64                     BaseOfImage;
    DWORD                       ImageSize;
    DWORD                       TimeDateStamp;
    DWORD                       CheckSum;
    DWORD                       NumSyms;
    SYM_TYPE                    SymType;
    CHAR                        ModuleName[32];
    CHAR                        ImageName[256];
    CHAR                        LoadedImageName[256];
    CHAR                        LoadedPdbName[256];
    DWORD                       CVSig;
    CHAR                        CVData[MAX_PATH*3];
    DWORD                       PdbSig;
    GUID                        PdbSig70;
    DWORD                       PdbAge;
    BOOL                        PdbUnmatched;
    BOOL                        DbgUnmatched;
    BOOL                        LineNumbers;
    BOOL                        GlobalSymbols;
    BOOL                        TypeInfo;
    BOOL                        SourceIndexed;
    BOOL                        Publics;
} IMAGEHLP_MODULE64, *PIMAGEHLP_MODULE64;

typedef struct _IMAGEHLP_MODULEW64
{
    DWORD                       SizeOfStruct;
    DWORD64                     BaseOfImage;
    DWORD                       ImageSize;
    DWORD                       TimeDateStamp;
    DWORD                       CheckSum;
    DWORD                       NumSyms;
    SYM_TYPE                    SymType;
    WCHAR                       ModuleName[32];
    WCHAR                       ImageName[256];
    WCHAR                       LoadedImageName[256];
    WCHAR                       LoadedPdbName[256];
    DWORD                       CVSig;
    WCHAR                       CVData[MAX_PATH*3];
    DWORD                       PdbSig;
    GUID                        PdbSig70;
    DWORD                       PdbAge;
    BOOL                        PdbUnmatched;
    BOOL                        DbgUnmatched;
    BOOL                        LineNumbers;
    BOOL                        GlobalSymbols;
    BOOL                        TypeInfo;
    BOOL                        SourceIndexed;
    BOOL                        Publics;
} IMAGEHLP_MODULEW64, *PIMAGEHLP_MODULEW64;

typedef struct _IMAGEHLP_LINE {
  DWORD SizeOfStruct;
  PVOID Key;
  DWORD LineNumber;
  PCHAR FileName;
  DWORD Address;
} IMAGEHLP_LINE, *PIMAGEHLP_LINE;

typedef struct _IMAGEHLP_LINEW {
  DWORD SizeOfStruct;
  PVOID Key;
  DWORD LineNumber;
  PWSTR FileName;
  DWORD Address;
} IMAGEHLP_LINEW, *PIMAGEHLP_LINEW;

typedef struct _IMAGEHLP_LINE64 {
  DWORD SizeOfStruct;
  PVOID Key;
  DWORD LineNumber;
  PCHAR FileName;
  DWORD64 Address;
} IMAGEHLP_LINE64, *PIMAGEHLP_LINE64;

typedef struct _IMAGEHLP_LINEW64 {
  DWORD SizeOfStruct;
  PVOID Key;
  DWORD LineNumber;
  PWSTR FileName;
  DWORD64 Address;
} IMAGEHLP_LINEW64, *PIMAGEHLP_LINEW64;

typedef struct _IMAGEHLP_DEFERRED_SYMBOL_LOAD {
  DWORD   SizeOfStruct;
  DWORD   BaseOfImage;
  DWORD   CheckSum;
  DWORD   TimeDateStamp;
  CHAR    FileName[MAX_PATH];
  BOOLEAN Reparse;
} IMAGEHLP_DEFERRED_SYMBOL_LOAD, *PIMAGEHLP_DEFERRED_SYMBOL_LOAD;

typedef struct _IMAGEHLP_DUPLICATE_SYMBOL {
  DWORD              SizeOfStruct;
  DWORD              NumberOfDups;
  PIMAGEHLP_SYMBOL Symbol;
  ULONG              SelectedSymbol;
} IMAGEHLP_DUPLICATE_SYMBOL, *PIMAGEHLP_DUPLICATE_SYMBOL;

typedef enum _IMAGEHLP_SYMBOL_TYPE_INFO
{
    TI_GET_SYMTAG,
    TI_GET_SYMNAME,
    TI_GET_LENGTH,
    TI_GET_TYPE,
    TI_GET_TYPEID,
    TI_GET_BASETYPE,
    TI_GET_ARRAYINDEXTYPEID,
    TI_FINDCHILDREN,
    TI_GET_DATAKIND,
    TI_GET_ADDRESSOFFSET,
    TI_GET_OFFSET,
    TI_GET_VALUE,
    TI_GET_COUNT,
    TI_GET_CHILDRENCOUNT,
    TI_GET_BITPOSITION,
    TI_GET_VIRTUALBASECLASS,
    TI_GET_VIRTUALTABLESHAPEID,
    TI_GET_VIRTUALBASEPOINTEROFFSET,
    TI_GET_CLASSPARENTID,
    TI_GET_NESTED,
    TI_GET_SYMINDEX,
    TI_GET_LEXICALPARENT,
    TI_GET_ADDRESS,
    TI_GET_THISADJUST,
    TI_GET_UDTKIND,
    TI_IS_EQUIV_TO,
    TI_GET_CALLING_CONVENTION,
} IMAGEHLP_SYMBOL_TYPE_INFO;

#define IMAGEHLP_GET_TYPE_INFO_UNCACHED            0x00000001
#define IMAGEHLP_GET_TYPE_INFO_CHILDREN            0x00000002
typedef struct _IMAGEHLP_GET_TYPE_INFO_PARAMS
{
    ULONG       SizeOfStruct;
    ULONG       Flags;
    ULONG       NumIds;
    PULONG      TypeIds;
    ULONG64     TagFilter;
    ULONG       NumReqs;
    IMAGEHLP_SYMBOL_TYPE_INFO* ReqKinds;
    PULONG_PTR  ReqOffsets;
    PULONG      ReqSizes;
    ULONG_PTR   ReqStride;
    ULONG_PTR   BufferSize;
    PVOID       Buffer;
    ULONG       EntriesMatched;
    ULONG       EntriesFilled;
    ULONG64     TagsFound;
    ULONG64     AllReqsValid;
    ULONG       NumReqsValid;
    PULONG64    ReqsValid;
} IMAGEHLP_GET_TYPE_INFO_PARAMS, *PIMAGEHLP_GET_TYPE_INFO_PARAMS;

#define IMAGEHLP_SYMBOL_INFO_VALUEPRESENT          1
#define IMAGEHLP_SYMBOL_INFO_REGISTER              SYMF_REGISTER
#define IMAGEHLP_SYMBOL_INFO_REGRELATIVE           SYMF_REGREL
#define IMAGEHLP_SYMBOL_INFO_FRAMERELATIVE         SYMF_FRAMEREL
#define IMAGEHLP_SYMBOL_INFO_PARAMETER             SYMF_PARAMETER
#define IMAGEHLP_SYMBOL_INFO_LOCAL                 SYMF_LOCAL
#define IMAGEHLP_SYMBOL_INFO_CONSTANT              SYMF_CONSTANT
#define IMAGEHLP_SYMBOL_FUNCTION                   SYMF_FUNCTION

#define MAX_SYM_NAME                               2000

typedef struct _SYMBOL_INFO {
    ULONG       SizeOfStruct;
    ULONG       TypeIndex;
    ULONG64     Reserved[2];
    ULONG       info;
    ULONG       Size;
    ULONG64     ModBase;
    ULONG       Flags;
    ULONG64     Value;
    ULONG64     Address;
    ULONG       Register;
    ULONG       Scope;
    ULONG       Tag;
    ULONG       NameLen;
    ULONG       MaxNameLen;
    CHAR        Name[1];
} SYMBOL_INFO, *PSYMBOL_INFO;

typedef struct _SYMBOL_INFOW
{
    ULONG       SizeOfStruct;
    ULONG       TypeIndex;
    ULONG64     Reserved[2];
    ULONG       Index;
    ULONG       Size;
    ULONG64     ModBase;
    ULONG       Flags;
    ULONG64     Value;
    ULONG64     Address;
    ULONG       Register;
    ULONG       Scope;
    ULONG       Tag;
    ULONG       NameLen;
    ULONG       MaxNameLen;
    WCHAR       Name[1];
} SYMBOL_INFOW, *PSYMBOL_INFOW;

typedef struct _SYMBOL_INFO_PACKAGE
{
    SYMBOL_INFO si;
    CHAR        name[MAX_SYM_NAME+1];
} SYMBOL_INFO_PACKAGE, *PSYMBOL_INFO_PACKAGE;

typedef struct _SYMBOL_INFO_PACKAGEW
{
    SYMBOL_INFOW si;
    WCHAR        name[MAX_SYM_NAME+1];
} SYMBOL_INFO_PACKAGEW, *PSYMBOL_INFO_PACKAGEW;

#define DBHHEADER_DEBUGDIRS     0x1
typedef struct _MODLOAD_DATA
{
    DWORD               ssize;
    DWORD               ssig;
    PVOID               data;
    DWORD               size;
    DWORD               flags;
} MODLOAD_DATA, *PMODLOAD_DATA;

typedef struct _SRCCODEINFO
{
    DWORD       SizeOfStruct;
    PVOID       Key;
    DWORD64     ModBase;
    CHAR        Obj[MAX_PATH+1];
    CHAR        FileName[MAX_PATH+1];
    DWORD       LineNumber;
    DWORD64     Address;
} SRCCODEINFO, *PSRCCODEINFO;

typedef struct _SRCCODEINFOW
{
    DWORD       SizeOfStruct;
    PVOID       Key;
    DWORD64     ModBase;
    WCHAR       Obj[MAX_PATH+1];
    WCHAR       FileName[MAX_PATH+1];
    DWORD       LineNumber;
    DWORD64     Address;
} SRCCODEINFOW, *PSRCCODEINFOW;

/***********************************************************************
 * Callbacks
 */

typedef BOOL (CALLBACK *PENUMDIRTREE_CALLBACK)(
  PCSTR, PVOID
);
typedef BOOL (CALLBACK *PENUMDIRTREE_CALLBACKW)(
  PCWSTR, PVOID
);

typedef BOOL (CALLBACK *PENUMLOADED_MODULES_CALLBACK)(
  PCSTR ModuleName, ULONG ModuleBase, ULONG ModuleSize,
  PVOID UserContext
);
typedef BOOL (CALLBACK *PENUMLOADED_MODULES_CALLBACK64)(
  PCSTR, DWORD64, ULONG, PVOID
);
typedef BOOL (CALLBACK *PENUMLOADED_MODULES_CALLBACKW64)(
  PCWSTR, DWORD64, ULONG, PVOID
);

typedef BOOL (CALLBACK *PFIND_DEBUG_FILE_CALLBACK)(
  HANDLE, PCSTR, PVOID
);
typedef BOOL (CALLBACK *PFIND_DEBUG_FILE_CALLBACKW)(
  HANDLE, PCWSTR, PVOID
);

typedef BOOL (CALLBACK *PFIND_EXE_FILE_CALLBACK)(
  HANDLE, PCSTR, PVOID
);
typedef BOOL (CALLBACK *PFIND_EXE_FILE_CALLBACKW)(
  HANDLE, PCWSTR, PVOID
);

typedef BOOL (CALLBACK *PFINDFILEINPATHCALLBACK)(
  PCSTR, PVOID
);
typedef BOOL (CALLBACK *PFINDFILEINPATHCALLBACKW)(
  PCWSTR, PVOID
);

typedef BOOL (CALLBACK *PIMAGEHLP_STATUS_ROUTINE)(
  IMAGEHLP_STATUS_REASON Reason, PCSTR ImageName, PCSTR DllName,
  ULONG_PTR Va, ULONG_PTR Parameter
);
typedef BOOL (CALLBACK *PIMAGEHLP_STATUS_ROUTINE32)(
  IMAGEHLP_STATUS_REASON Reason, PCSTR ImageName, PCSTR DllName,
  ULONG Va, ULONG_PTR Parameter
);
typedef BOOL (CALLBACK *PIMAGEHLP_STATUS_ROUTINE64)(
  IMAGEHLP_STATUS_REASON Reason, PCSTR ImageName, PCSTR DllName,
  ULONG64 Va, ULONG_PTR Parameter
);

typedef BOOL (CALLBACK *PSYM_ENUMERATESYMBOLS_CALLBACK)(
  PSYMBOL_INFO pSymInfo, ULONG SymbolSize, PVOID UserContext
);
typedef BOOL (CALLBACK *PSYM_ENUMERATESYMBOLS_CALLBACKW)(
  PSYMBOL_INFOW pSymInfo, ULONG SymbolSize, PVOID UserContext
);

typedef BOOL (CALLBACK* PSYM_ENUMLINES_CALLBACK)(
  PSRCCODEINFO, PVOID
);
typedef BOOL (CALLBACK* PSYM_ENUMLINES_CALLBACKW)(
  PSRCCODEINFOW, PVOID
);

typedef BOOL (CALLBACK *PSYM_ENUMSOURCEFILES_CALLBACK)(
  PSOURCEFILE pSourceFile, PVOID UserContext
);
typedef BOOL (CALLBACK *PSYM_ENUMSOURCEFILES_CALLBACKW)(
  PSOURCEFILEW pSourceFile, PVOID UserContext
);

typedef BOOL (CALLBACK *PSYM_ENUMMODULES_CALLBACK)(
  PCSTR ModuleName, ULONG BaseOfDll, PVOID UserContext
);
typedef BOOL (CALLBACK *PSYM_ENUMMODULES_CALLBACK64)(
  PCSTR, DWORD64, PVOID
);
typedef BOOL (CALLBACK *PSYM_ENUMMODULES_CALLBACKW64)(
  PCWSTR, DWORD64, PVOID
);

typedef BOOL (CALLBACK *PSYM_ENUMSYMBOLS_CALLBACK)(
  PCSTR, ULONG, ULONG, PVOID
);
typedef BOOL (CALLBACK *PSYM_ENUMSYMBOLS_CALLBACKW)(
  PCWSTR, ULONG, ULONG, PVOID
);
typedef BOOL (CALLBACK *PSYM_ENUMSYMBOLS_CALLBACK64)(
  PCSTR, DWORD64, ULONG, PVOID
);
typedef BOOL (CALLBACK *PSYM_ENUMSYMBOLS_CALLBACK64W)(
  PCWSTR, DWORD64, ULONG, PVOID
);

typedef PVOID (CALLBACK *PSYMBOL_FUNCENTRY_CALLBACK)(
  HANDLE, DWORD, PVOID
);
typedef PVOID (CALLBACK *PSYMBOL_FUNCENTRY_CALLBACK64)(
  HANDLE, ULONG64, ULONG64
);

typedef BOOL (CALLBACK *PSYMBOL_REGISTERED_CALLBACK)(
  HANDLE hProcess, ULONG ActionCode, PVOID CallbackData,
  PVOID UserContext
);
typedef BOOL (CALLBACK *PSYMBOL_REGISTERED_CALLBACK64)(
  HANDLE, ULONG, ULONG64, ULONG64
);

typedef BOOL (CALLBACK *DIGEST_FUNCTION)(
  DIGEST_HANDLE refdata, PBYTE pData, DWORD dwLength
);

typedef BOOL (CALLBACK *PREAD_PROCESS_MEMORY_ROUTINE)(
  HANDLE  hProcess, DWORD lpBaseAddress, PVOID lpBuffer,
  DWORD nSize, PDWORD lpNumberOfBytesRead
);

typedef BOOL (CALLBACK *PREAD_PROCESS_MEMORY_ROUTINE64)(
  HANDLE  hProcess, DWORD64 lpBaseAddress, PVOID lpBuffer,
  DWORD nSize, LPDWORD lpNumberOfBytesRead
);

typedef PVOID (CALLBACK *PFUNCTION_TABLE_ACCESS_ROUTINE)(
  HANDLE hProcess, DWORD AddrBase
);

typedef PVOID (CALLBACK *PFUNCTION_TABLE_ACCESS_ROUTINE64)(
  HANDLE hProcess, DWORD64 AddrBase
);

typedef DWORD (CALLBACK *PGET_MODULE_BASE_ROUTINE)(
  HANDLE hProcess, DWORD ReturnAddress);

typedef DWORD (CALLBACK *PGET_MODULE_BASE_ROUTINE64)(
  HANDLE hProcess, DWORD64 ReturnAddress);

typedef DWORD (CALLBACK *PTRANSLATE_ADDRESS_ROUTINE)(
  HANDLE hProcess, HANDLE hThread, LPADDRESS lpaddr
);

typedef DWORD (CALLBACK *PTRANSLATE_ADDRESS_ROUTINE64)(
  HANDLE hProcess, HANDLE hThread, LPADDRESS64 lpaddr
);


/***********************************************************************
 * Functions
 */

BOOL WINAPI BindImage(
  PCSTR ImageName, PCSTR DllPath, PCSTR SymbolPath
);
BOOL WINAPI BindImageEx(
  DWORD Flags, PCSTR ImageName, PCSTR DllPath, PCSTR SymbolPath,
  PIMAGEHLP_STATUS_ROUTINE StatusRoutine
);
PIMAGE_NT_HEADERS WINAPI CheckSumMappedFile(
  LPVOID BaseAddress, DWORD FileLength,
  LPDWORD HeaderSum, LPDWORD CheckSum
);
BOOL WINAPI EnumDirTree(
  HANDLE, PCSTR, PCSTR, PSTR, PENUMDIRTREE_CALLBACK, PVOID
);
BOOL WINAPI EnumDirTreeW(
  HANDLE, PCWSTR, PCWSTR, PWSTR, PENUMDIRTREE_CALLBACKW, PVOID
);
BOOL WINAPI EnumerateLoadedModules(
  HANDLE hProcess,
  PENUMLOADED_MODULES_CALLBACK EnumLoadedModulesCallback,
  PVOID UserContext
);
BOOL WINAPI EnumerateLoadedModules64(
  HANDLE, PENUMLOADED_MODULES_CALLBACK64, PVOID
);
BOOL WINAPI EnumerateLoadedModulesW64(
  HANDLE, PENUMLOADED_MODULES_CALLBACKW64, PVOID
);
HANDLE WINAPI FindDebugInfoFile(
  PCSTR FileName, PCSTR SymbolPath, PSTR DebugFilePath
);
HANDLE WINAPI FindDebugInfoFileEx(
  PCSTR, PCSTR, PSTR, PFIND_DEBUG_FILE_CALLBACK, PVOID
);
HANDLE WINAPI FindDebugInfoFileExW(
  PCWSTR, PCWSTR, PWSTR, PFIND_DEBUG_FILE_CALLBACKW, PVOID
);
HANDLE WINAPI FindExecutableImage(
  PCSTR, PCSTR, PSTR
);
HANDLE WINAPI FindExecutableImageEx(
  PCSTR, PCSTR, PSTR, PFIND_EXE_FILE_CALLBACK, PVOID
);
HANDLE WINAPI FindExecutableImageExW(
  PCWSTR, PCWSTR, PWSTR, PFIND_EXE_FILE_CALLBACKW, PVOID
);
BOOL WINAPI FindFileInPath(
  HANDLE, PCSTR, PCSTR, PVOID, DWORD, DWORD, DWORD,
  PSTR, PFINDFILEINPATHCALLBACK, PVOID
);
BOOL WINAPI GetImageConfigInformation(
  PLOADED_IMAGE LoadedImage,
  PIMAGE_LOAD_CONFIG_DIRECTORY ImageConfigInformation
);
DWORD WINAPI GetImageUnusedHeaderBytes(
  PLOADED_IMAGE LoadedImage,
  LPDWORD SizeUnusedHeaderBytes
);
DWORD WINAPI GetTimestampForLoadedLibrary(
  HMODULE Module
);
BOOL WINAPI ImageAddCertificate(
  HANDLE FileHandle, LPWIN_CERTIFICATE Certificate, PDWORD Index
);
PVOID WINAPI ImageDirectoryEntryToData(
  PVOID Base, BOOLEAN MappedAsImage, USHORT DirectoryEntry, PULONG Size
);
BOOL WINAPI ImageEnumerateCertificates(
  HANDLE FileHandle, WORD TypeFilter, PDWORD CertificateCount,
  PDWORD Indices, DWORD IndexCount
);
BOOL WINAPI ImageGetCertificateData(
  HANDLE FileHandle, DWORD CertificateIndex,
  LPWIN_CERTIFICATE Certificate, PDWORD RequiredLength
);
BOOL WINAPI ImageGetCertificateHeader(
  HANDLE FileHandle, DWORD CertificateIndex,
  LPWIN_CERTIFICATE Certificateheader
);
BOOL WINAPI ImageGetDigestStream(
  HANDLE FileHandle, DWORD DigestLevel,
  DIGEST_FUNCTION DigestFunction, DIGEST_HANDLE DigestHandle
);
PLOADED_IMAGE WINAPI ImageLoad(
  PCSTR DllName, PCSTR DllPath
);
PIMAGE_NT_HEADERS WINAPI ImageNtHeader(
  PVOID Base
);
BOOL WINAPI ImageRemoveCertificate(
  HANDLE FileHandle, DWORD Index
);
PIMAGE_SECTION_HEADER WINAPI ImageRvaToSection(
  PIMAGE_NT_HEADERS NtHeaders, PVOID Base, ULONG Rva
);
PVOID WINAPI ImageRvaToVa(
  PIMAGE_NT_HEADERS NtHeaders, PVOID Base, ULONG Rva,
  PIMAGE_SECTION_HEADER *LastRvaSection
);
BOOL WINAPI ImageUnload(
  PLOADED_IMAGE LoadedImage
);
LPAPI_VERSION WINAPI ImagehlpApiVersion(
  void
);
LPAPI_VERSION WINAPI ImagehlpApiVersionEx(
  LPAPI_VERSION AppVersion
);
BOOL WINAPI MakeSureDirectoryPathExists(
  PCSTR DirPath
);
BOOL WINAPI MapAndLoad(
  PCSTR ImageName, PCSTR DllPath, PLOADED_IMAGE LoadedImage,
  BOOL DotDll, BOOL ReadOnly
);
PIMAGE_DEBUG_INFORMATION WINAPI MapDebugInformation(
  HANDLE FileHandle, PCSTR FileName,
  PCSTR SymbolPath, ULONG ImageBase
);
DWORD WINAPI MapFileAndCheckSumA(
  PCSTR Filename, PDWORD HeaderSum, PDWORD CheckSum
);
DWORD WINAPI MapFileAndCheckSumW(
  PCWSTR Filename, PDWORD HeaderSum, PDWORD CheckSum
);
BOOL WINAPI ReBaseImage(
  PCSTR CurrentImageName, PCSTR SymbolPath, BOOL fReBase,
  BOOL fRebaseSysfileOk, BOOL fGoingDown, ULONG CheckImageSize,
  ULONG *OldImageSize, ULONG_PTR *OldImageBase, ULONG *NewImageSize,
  ULONG_PTR *NewImageBase, ULONG TimeStamp
);
BOOL WINAPI ReBaseImage64(
  PCSTR CurrentImageName, PCSTR SymbolPath, BOOL fReBase,
  BOOL fRebaseSysfileOk, BOOL fGoingDown, ULONG CheckImageSize,
  ULONG *OldImageSize, ULONG64 *OldImageBase, ULONG *NewImageSize,
  ULONG64 *NewImageBase, ULONG TimeStamp
);
BOOL WINAPI RemovePrivateCvSymbolic(
  PCHAR DebugData, PCHAR *NewDebugData, ULONG *NewDebugSize
);
BOOL WINAPI SearchTreeForFile(
  PCSTR RootPath, PCSTR InputPathName, PSTR OutputPathBuffer
);
BOOL WINAPI SearchTreeForFileW(
  PCWSTR RootPath, PCWSTR InputPathName, PWSTR OutputPathBuffer
);
BOOL WINAPI SetImageConfigInformation(
  PLOADED_IMAGE LoadedImage,
  PIMAGE_LOAD_CONFIG_DIRECTORY ImageConfigInformation
);
BOOL WINAPI SplitSymbols(
  PSTR ImageName, PCSTR SymbolsPath,
  PSTR SymbolFilePath, ULONG Flags
);
BOOL WINAPI StackWalk(
  DWORD MachineType, HANDLE hProcess, HANDLE hThread,
  LPSTACKFRAME StackFrame, PVOID ContextRecord,
  PREAD_PROCESS_MEMORY_ROUTINE ReadMemoryRoutine,
  PFUNCTION_TABLE_ACCESS_ROUTINE FunctionTableAccessRoutine,
  PGET_MODULE_BASE_ROUTINE GetModuleBaseRoutine,
  PTRANSLATE_ADDRESS_ROUTINE TranslateAddress
);
BOOL WINAPI StackWalk64(
  DWORD MachineType, HANDLE hProcess, HANDLE hThread,
  LPSTACKFRAME64 StackFrame, PVOID ContextRecord,
  PREAD_PROCESS_MEMORY_ROUTINE64 ReadMemoryRoutine,
  PFUNCTION_TABLE_ACCESS_ROUTINE64 FunctionTableAccessRoutine,
  PGET_MODULE_BASE_ROUTINE64 GetModuleBaseRoutine,
  PTRANSLATE_ADDRESS_ROUTINE64 TranslateAddress
);
BOOL WINAPI SymAddSymbol(
  HANDLE, ULONG64, PCSTR, DWORD64, DWORD, DWORD
);
BOOL WINAPI SymAddSymbolW(
  HANDLE, ULONG64, PCWSTR, DWORD64, DWORD, DWORD
);
BOOL WINAPI SymCleanup(
  HANDLE hProcess
);
BOOL WINAPI SymDeleteSymbol(
  HANDLE, ULONG64, PCSTR, DWORD64, DWORD
);
BOOL WINAPI SymDeleteSymbolW(
  HANDLE, ULONG64, PCWSTR, DWORD64, DWORD
);
BOOL WINAPI SymEnumerateModules(
  HANDLE hProcess, PSYM_ENUMMODULES_CALLBACK EnumModulesCallback,
  PVOID UserContext
);
BOOL WINAPI SymEnumerateModules64(
  HANDLE, PSYM_ENUMMODULES_CALLBACK64, PVOID
);
BOOL WINAPI SymEnumerateModulesW64(
  HANDLE, PSYM_ENUMMODULES_CALLBACKW64, PVOID
);
BOOL WINAPI SymEnumerateSymbols(
  HANDLE hProcess, DWORD BaseOfDll,
  PSYM_ENUMSYMBOLS_CALLBACK EnumSymbolsCallback, PVOID UserContext
);
BOOL WINAPI SymEnumerateSymbolsW(
  HANDLE hProcess, DWORD BaseOfDll,
  PSYM_ENUMSYMBOLS_CALLBACKW EnumSymbolsCallback, PVOID UserContext
);
BOOL WINAPI SymEnumerateSymbols64(
  HANDLE, ULONG64, PSYM_ENUMSYMBOLS_CALLBACK64, PVOID
);
BOOL WINAPI SymEnumerateSymbolsW64(
  HANDLE, ULONG64, PSYM_ENUMSYMBOLS_CALLBACK64W, PVOID
);
BOOL WINAPI SymEnumLines(
  HANDLE, ULONG64, PCSTR, PCSTR, PSYM_ENUMLINES_CALLBACK, PVOID
);
BOOL WINAPI SymEnumLinesW(
  HANDLE, ULONG64, PCWSTR, PCWSTR, PSYM_ENUMLINES_CALLBACKW, PVOID
);
BOOL WINAPI SymEnumSourceFiles(
  HANDLE hProcess, ULONG64 ModBase, PCSTR Mask,
  PSYM_ENUMSOURCEFILES_CALLBACK cbSrcFiles, PVOID UserContext
);
BOOL WINAPI SymEnumSourceFilesW(
  HANDLE hProcess, ULONG64 ModBase, PCWSTR Mask,
  PSYM_ENUMSOURCEFILES_CALLBACKW cbSrcFiles, PVOID UserContext
);
BOOL WINAPI SymEnumSourceLines(
  HANDLE, ULONG64, PCSTR, PCSTR, DWORD, DWORD, PSYM_ENUMLINES_CALLBACK, PVOID
);
BOOL WINAPI SymEnumSourceLinesW(
  HANDLE, ULONG64, PCWSTR, PCWSTR, DWORD, DWORD, PSYM_ENUMLINES_CALLBACKW, PVOID
);
BOOL WINAPI SymEnumSymbols(
  HANDLE hProcess, DWORD BaseOfDll, PCSTR Mask, 
  PSYM_ENUMERATESYMBOLS_CALLBACK EnumSymbolsCallback, PVOID UserContext
);
BOOL WINAPI SymEnumSymbolsW(
  HANDLE hProcess, DWORD BaseOfDll, PCWSTR Mask,
  PSYM_ENUMERATESYMBOLS_CALLBACKW EnumSymbolsCallback, PVOID UserContext
);
BOOL WINAPI SymEnumSymbolsForAddr(
  HANDLE, DWORD64, PSYM_ENUMERATESYMBOLS_CALLBACK, PVOID
);
BOOL WINAPI SymEnumSymbolsForAddrW(
  HANDLE, DWORD64, PSYM_ENUMERATESYMBOLS_CALLBACKW, PVOID
);
BOOL WINAPI SymEnumTypes(
  HANDLE, ULONG64, PSYM_ENUMERATESYMBOLS_CALLBACK, PVOID
);
BOOL WINAPI SymEnumTypesW(
  HANDLE, ULONG64, PSYM_ENUMERATESYMBOLS_CALLBACKW, PVOID
);
HANDLE WINAPI SymFindExecutableImage(
  HANDLE, PCSTR, PSTR, PFIND_EXE_FILE_CALLBACK, PVOID
);
HANDLE WINAPI SymFindExecutableImageW(
  HANDLE, PCWSTR, PWSTR, PFIND_EXE_FILE_CALLBACKW, PVOID
);
BOOL WINAPI SymFindFileInPath(
  HANDLE, PCSTR, PCSTR, PVOID, DWORD, DWORD, DWORD,
  PSTR, PFINDFILEINPATHCALLBACK, PVOID
);
BOOL WINAPI SymFindFileInPathW(
  HANDLE, PCWSTR, PCWSTR, PVOID, DWORD, DWORD, DWORD,
  PWSTR, PFINDFILEINPATHCALLBACKW, PVOID
);
BOOL WINAPI SymFromAddr(
  HANDLE, DWORD64, DWORD64*, SYMBOL_INFO*
);
BOOL WINAPI SymFromAddrW(
  HANDLE, DWORD64, DWORD64*, SYMBOL_INFOW*
);
BOOL WINAPI SymFromIndex(
  HANDLE, ULONG64, DWORD, PSYMBOL_INFO
);
BOOL WINAPI SymFromIndexW(
  HANDLE, ULONG64, DWORD, PSYMBOL_INFOW
);
BOOL WINAPI SymFromName(
  HANDLE, PCSTR, PSYMBOL_INFO
);
BOOL WINAPI SymFromNameW(
  HANDLE, PCWSTR, PSYMBOL_INFOW
);
BOOL WINAPI SymFromToken(
  HANDLE, DWORD64, DWORD, PSYMBOL_INFO
);
BOOL WINAPI SymFromTokenW(
  HANDLE, DWORD64, DWORD, PSYMBOL_INFOW
);
PVOID WINAPI SymFunctionTableAccess(
  HANDLE hProcess, DWORD AddrBase
);
PVOID WINAPI SymFunctionTableAccess64(
  HANDLE hProcess, DWORD64 AddrBase
);
ULONG WINAPI SymGetFileLineOffsets64(
  HANDLE, PCSTR, PCSTR, PDWORD64, ULONG
);
PCHAR WINAPI SymGetHomeDirectory(
  DWORD, PSTR, size_t
);
PWSTR WINAPI SymGetHomeDirectoryW(
  DWORD, PWSTR, size_t
);
BOOL WINAPI SymGetLineFromAddr(
  HANDLE, DWORD, PDWORD, PIMAGEHLP_LINE
);
BOOL WINAPI SymGetLineFromAddrW(
  HANDLE, DWORD, PDWORD, PIMAGEHLP_LINEW
);
BOOL WINAPI SymGetLineFromAddr64(
  HANDLE, DWORD64, PDWORD, PIMAGEHLP_LINE64
);
BOOL WINAPI SymGetLineFromAddrW64(
  HANDLE, DWORD64, PDWORD, PIMAGEHLP_LINEW64
);
BOOL WINAPI SymGetLineFromName(
  HANDLE, PCSTR, PCSTR, DWORD, PLONG, PIMAGEHLP_LINE
);
BOOL WINAPI SymGetLineFromName64(
  HANDLE, PCSTR, PCSTR, DWORD, PLONG, PIMAGEHLP_LINE64
);
BOOL WINAPI SymGetLineFromNameW64(
  HANDLE, PCWSTR, PCWSTR, DWORD, PLONG, PIMAGEHLP_LINEW64
);
BOOL WINAPI SymGetLineNext(
  HANDLE, PIMAGEHLP_LINE
);
BOOL WINAPI SymGetLineNextW(
  HANDLE, PIMAGEHLP_LINEW
);
BOOL WINAPI SymGetLineNext64(
  HANDLE, PIMAGEHLP_LINE64
);
BOOL WINAPI SymGetLineNextW64(
  HANDLE, PIMAGEHLP_LINEW64
);
BOOL WINAPI SymGetLinePrev(
  HANDLE, PIMAGEHLP_LINE
);
BOOL WINAPI SymGetLinePrevW(
  HANDLE, PIMAGEHLP_LINEW
);
BOOL WINAPI SymGetLinePrev64(
  HANDLE, PIMAGEHLP_LINE64
);
BOOL WINAPI SymGetLinePrevW64(
  HANDLE, PIMAGEHLP_LINEW64
);
DWORD WINAPI SymGetModuleBase(
  HANDLE hProcess, DWORD dwAddr
);
BOOL WINAPI SymGetModuleInfo(
  HANDLE hProcess, DWORD dwAddr,
  PIMAGEHLP_MODULE ModuleInfo
);
BOOL WINAPI SymGetModuleInfoW(
  HANDLE, DWORD, PIMAGEHLP_MODULEW
);
BOOL WINAPI SymGetModuleInfo64(
  HANDLE, DWORD64, PIMAGEHLP_MODULE64
);
BOOL WINAPI SymGetModuleInfoW64(
  HANDLE, DWORD64, PIMAGEHLP_MODULEW64
);
DWORD WINAPI SymGetOptions(
  void
);
BOOL WINAPI SymGetScope(
  HANDLE, ULONG64, DWORD, PSYMBOL_INFO
);
BOOL WINAPI SymGetScopeW(
  HANDLE, ULONG64, DWORD, PSYMBOL_INFOW
);
BOOL WINAPI SymGetSearchPath(
  HANDLE hProcess, PSTR szSearchPath, DWORD SearchPathLength
);
BOOL WINAPI SymGetSearchPathW(
  HANDLE hProcess, PWSTR szSearchPath, DWORD SearchPathLength
);
BOOL WINAPI SymGetSourceFile(
  HANDLE, ULONG64, PCSTR, PCSTR, PSTR, DWORD
);
BOOL WINAPI SymGetSourceFileW(
  HANDLE, ULONG64, PCWSTR, PCWSTR, PWSTR, DWORD
);
BOOL WINAPI SymGetSourceFileFromToken(
  HANDLE, PVOID, PCSTR, PSTR, DWORD
);
BOOL WINAPI SymGetSourceFileFromTokenW(
  HANDLE, PVOID, PCWSTR, PWSTR, DWORD
);
BOOL WINAPI SymGetSourceFileToken(
  HANDLE, ULONG64, PCSTR, PVOID*, DWORD*
);
BOOL WINAPI SymGetSourceFileTokenW(
  HANDLE, ULONG64, PCWSTR, PVOID*, DWORD*
);
BOOL WINAPI SymGetSourceVarFromToken(
  HANDLE, PVOID, PCSTR, PCSTR, PSTR, DWORD
);
BOOL WINAPI SymGetSourceVarFromTokenW(
  HANDLE, PVOID, PCWSTR, PCWSTR, PWSTR, DWORD
);
BOOL WINAPI SymGetSymFromAddr(
  HANDLE hProcess, DWORD dwAddr,
  PDWORD pdwDisplacement, PIMAGEHLP_SYMBOL Symbol
);
BOOL WINAPI SymGetSymFromAddr64(
  HANDLE, DWORD64, PDWORD64, PIMAGEHLP_SYMBOL64
);
BOOL WINAPI SymGetSymFromName(
  HANDLE hProcess, PCSTR Name, PIMAGEHLP_SYMBOL Symbol
);
BOOL WINAPI SymGetSymFromName64(
  HANDLE, PCSTR, PIMAGEHLP_SYMBOL64
);
BOOL WINAPI SymGetSymNext(
  HANDLE hProcess, PIMAGEHLP_SYMBOL Symbol
);
BOOL WINAPI SymGetSymNext64(
  HANDLE, PIMAGEHLP_SYMBOL64
);
BOOL WINAPI SymGetSymPrev(
  HANDLE hProcess, PIMAGEHLP_SYMBOL Symbol
);
BOOL WINAPI SymGetSymPrev64(
  HANDLE, PIMAGEHLP_SYMBOL64
);
BOOL WINAPI SymGetTypeFromName(
  HANDLE, ULONG64, PCSTR, PSYMBOL_INFO
);
BOOL WINAPI SymGetTypeFromNameW(
  HANDLE, ULONG64, PCWSTR, PSYMBOL_INFOW
);
BOOL WINAPI SymGetTypeInfo(
  HANDLE, DWORD64, ULONG, IMAGEHLP_SYMBOL_TYPE_INFO, PVOID
);
BOOL WINAPI SymGetTypeInfoEx(
  HANDLE, DWORD64, PIMAGEHLP_GET_TYPE_INFO_PARAMS
);
BOOL WINAPI SymInitialize(
  HANDLE hProcess, PCSTR UserSearchPath, BOOL fInvadeProcess
);
BOOL WINAPI SymInitializeW(
  HANDLE hProcess, PCWSTR UserSearchPath, BOOL fInvadeProcess
);
DWORD WINAPI SymLoadModule(
  HANDLE hProcess, HANDLE hFile, PCSTR ImageName, PCSTR ModuleName,
  DWORD BaseOfDll, DWORD SizeOfDll
);
DWORD64 WINAPI SymLoadModule64(
  HANDLE, HANDLE, PCSTR, PCSTR, DWORD64, DWORD
);
DWORD64 WINAPI SymLoadModuleEx(
  HANDLE, HANDLE, PCSTR, PCSTR, DWORD64, DWORD, PMODLOAD_DATA, DWORD
);
DWORD64 WINAPI SymLoadModuleExW(
  HANDLE, HANDLE, PCWSTR, PCWSTR, DWORD64, DWORD, PMODLOAD_DATA, DWORD
);
BOOL WINAPI SymMatchFileName(
  PCSTR, PCSTR, PSTR*, PSTR*
);
BOOL WINAPI SymMatchFileNameW(
  PCWSTR, PCWSTR, PWSTR*, PWSTR*
);
BOOL WINAPI SymMatchString(
  PCSTR, PCSTR, BOOL
);
BOOL WINAPI SymMatchStringA(
  PCSTR, PCSTR, BOOL
);
BOOL WINAPI SymMatchStringW(
  PCWSTR, PCWSTR, BOOL
);
BOOL WINAPI SymRegisterCallback(
  HANDLE hProcess, PSYMBOL_REGISTERED_CALLBACK CallbackFunction,
  PVOID UserContext
);
BOOL WINAPI SymRegisterCallback64(
  HANDLE, PSYMBOL_REGISTERED_CALLBACK64, ULONG64
);
BOOL WINAPI SymRegisterCallbackW64(
  HANDLE, PSYMBOL_REGISTERED_CALLBACK64, ULONG64
);
BOOL WINAPI SymRegisterFunctionEntryCallback(
  HANDLE, PSYMBOL_FUNCENTRY_CALLBACK, PVOID
);
BOOL WINAPI SymRegisterFunctionEntryCallback64(
  HANDLE, PSYMBOL_FUNCENTRY_CALLBACK64, ULONG64
);
BOOL WINAPI SymSearch(
  HANDLE, ULONG64, DWORD, DWORD, PCSTR, DWORD64,
  PSYM_ENUMERATESYMBOLS_CALLBACK, PVOID, DWORD
);
BOOL WINAPI SymSearchW(
  HANDLE, ULONG64, DWORD, DWORD, PCWSTR, DWORD64,
  PSYM_ENUMERATESYMBOLS_CALLBACKW, PVOID, DWORD
);
DWORD WINAPI SymSetContext(
  HANDLE hProcess, PIMAGEHLP_STACK_FRAME StackFrame, 
  PIMAGEHLP_CONTEXT Context
);
PCHAR WINAPI SymSetHomeDirectory(
  HANDLE, PCSTR
);
PWSTR WINAPI SymSetHomeDirectoryW(
  HANDLE, PCWSTR
);
DWORD WINAPI SymSetOptions(
  DWORD SymOptions
);
BOOL WINAPI SymSetParentWindow(
  HWND
);
BOOL WINAPI SymSetSearchPath(
  HANDLE hProcess, PCSTR szSearchPath
);
BOOL WINAPI SymSetSearchPathW(
  HANDLE hProcess, PCWSTR szSearchPath
);
BOOL WINAPI SymUnDName(
  PIMAGEHLP_SYMBOL sym, PSTR UnDecName, DWORD UnDecNameLength
);
BOOL WINAPI SymUnDName64(
  PIMAGEHLP_SYMBOL64, PSTR, DWORD
);
BOOL WINAPI SymUnloadModule(
  HANDLE hProcess, DWORD BaseOfDll
);
BOOL WINAPI TouchFileTimes(
  HANDLE FileHandle, LPSYSTEMTIME lpSystemTime
);
DWORD WINAPI UnDecorateSymbolName(
  PCSTR DecoratedName, PSTR UnDecoratedName,
  DWORD UndecoratedLength, DWORD Flags
);
DWORD WINAPI UnDecorateSymbolNameW(
  PCWSTR DecoratedName, PWSTR UnDecoratedName,
  DWORD UndecoratedLength, DWORD Flags
);
BOOL WINAPI UnMapAndLoad(
  PLOADED_IMAGE LoadedImage
);
BOOL WINAPI UnmapDebugInformation(
  PIMAGE_DEBUG_INFORMATION DebugInfo
);
BOOL WINAPI UpdateDebugInfoFile(
  PCSTR ImageFileName, PCSTR SymbolPath,
  PSTR DebugFilePath, PIMAGE_NT_HEADERS32 NtHeaders
);
BOOL WINAPI UpdateDebugInfoFileEx(
  PCSTR ImageFileName, PCSTR SymbolPath, PSTR DebugFilePath,
  PIMAGE_NT_HEADERS32 NtHeaders, DWORD OldChecksum
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* defined(__cplusplus) */

#endif  /* __WINE_IMAGEHLP_H */
