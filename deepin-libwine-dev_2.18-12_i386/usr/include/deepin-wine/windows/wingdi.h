/*
 * Copyright (C) the Wine project
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

#ifndef _WINGDI_
#define _WINGDI_
#ifndef NOGDI

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _GDI32_
#define WINGDIAPI
#else
#define WINGDIAPI DECLSPEC_IMPORT
#endif

typedef struct _ABCFLOAT {
    FLOAT   abcfA;
    FLOAT   abcfB;
    FLOAT   abcfC;
} ABCFLOAT, *PABCFLOAT, *LPABCFLOAT;

#define FONTMAPPER_MAX 10

typedef struct
{
    WORD   wFirst;
    WORD   wSecond;
    INT  iKernAmount;
} KERNINGPAIR, *LPKERNINGPAIR;

typedef struct tagPIXELFORMATDESCRIPTOR {
    WORD  nSize;
    WORD  nVersion;
    DWORD dwFlags;
    BYTE  iPixelType;
    BYTE  cColorBits;
    BYTE  cRedBits;
    BYTE  cRedShift;
    BYTE  cGreenBits;
    BYTE  cGreenShift;
    BYTE  cBlueBits;
    BYTE  cBlueShift;
    BYTE  cAlphaBits;
    BYTE  cAlphaShift;
    BYTE  cAccumBits;
    BYTE  cAccumRedBits;
    BYTE  cAccumGreenBits;
    BYTE  cAccumBlueBits;
    BYTE  cAccumAlphaBits;
    BYTE  cDepthBits;
    BYTE  cStencilBits;
    BYTE  cAuxBuffers;
    BYTE  iLayerType;
    BYTE  bReserved;
    DWORD dwLayerMask;
    DWORD dwVisibleMask;
    DWORD dwDamageMask;
} PIXELFORMATDESCRIPTOR, *PPIXELFORMATDESCRIPTOR, *LPPIXELFORMATDESCRIPTOR;

#define PFD_TYPE_RGBA        0
#define PFD_TYPE_COLORINDEX  1

#define PFD_MAIN_PLANE       0
#define PFD_OVERLAY_PLANE    1
#define PFD_UNDERLAY_PLANE   (-1)

#define PFD_DOUBLEBUFFER          0x00000001
#define PFD_STEREO                0x00000002
#define PFD_DRAW_TO_WINDOW        0x00000004
#define PFD_DRAW_TO_BITMAP        0x00000008
#define PFD_SUPPORT_GDI           0x00000010
#define PFD_SUPPORT_OPENGL        0x00000020
#define PFD_GENERIC_FORMAT        0x00000040
#define PFD_NEED_PALETTE          0x00000080
#define PFD_NEED_SYSTEM_PALETTE   0x00000100
#define PFD_SWAP_EXCHANGE         0x00000200
#define PFD_SWAP_COPY             0x00000400
#define PFD_SWAP_LAYER_BUFFERS    0x00000800
#define PFD_GENERIC_ACCELERATED   0x00001000
#define PFD_SUPPORT_COMPOSITION   0x00008000 /* Vista stuff */

#define PFD_DEPTH_DONTCARE        0x20000000
#define PFD_DOUBLEBUFFER_DONTCARE 0x40000000
#define PFD_STEREO_DONTCARE       0x80000000

typedef struct tagCOLORADJUSTMENT
{
	WORD   caSize;
	WORD   caFlags;
	WORD   caIlluminantIndex;
	WORD   caRedGamma;
	WORD   caGreenGamma;
	WORD   caBlueGamma;
	WORD   caReferenceBlack;
	WORD   caReferenceWhite;
	SHORT  caContrast;
	SHORT  caBrightness;
	SHORT  caColorfulness;
	SHORT  caRedGreenTint;
} COLORADJUSTMENT, *PCOLORADJUSTMENT, *LPCOLORADJUSTMENT;

#define CA_NEGATIVE          0x0001
#define CA_LOG_FILTER        0x0002

#define ILLUMINANT_DEVICE_DEFAULT   0
#define ILLUMINANT_A                1
#define ILLUMINANT_B                2
#define ILLUMINANT_C                3
#define ILLUMINANT_D50              4
#define ILLUMINANT_D55              5
#define ILLUMINANT_D65              6
#define ILLUMINANT_D75              7
#define ILLUMINANT_F2               8
#define ILLUMINANT_MAX_INDEX        ILLUMINANT_F2

#define ILLUMINANT_TUNGSTEN         ILLUMINANT_A
#define ILLUMINANT_DAYLIGHT         ILLUMINANT_C
#define ILLUMINANT_FLUORESCENT      ILLUMINANT_F2
#define ILLUMINANT_NTSC             ILLUMINANT_C

#define RGB_GAMMA_MIN               (WORD)02500
#define RGB_GAMMA_MAX               (WORD)65000

#define REFERENCE_WHITE_MIN         (WORD)6000
#define REFERENCE_WHITE_MAX         (WORD)10000
#define REFERENCE_BLACK_MIN         (WORD)0
#define REFERENCE_BLACK_MAX         (WORD)4000

#define COLOR_ADJ_MIN               ((SHORT)-100)
#define COLOR_ADJ_MAX               (SHORT) 100

typedef LONG FXPT16DOT16, *LPFXPT16DOT16;
typedef LONG FXPT2DOT30, *LPFXPT2DOT30;
typedef LONG LCSCSTYPE;
typedef LONG LCSGAMUTMATCH;

#define LCS_sRGB                    0x73524742  /* 'sRGB' */
#define LCS_WINDOWS_COLOR_SPACE     0x57696e20  /* 'Win ' */

#define LCS_CALIBRATED_RGB    __MSABI_LONG(0x00000000)
#define LCS_DEVICE_RGB        __MSABI_LONG(0x00000001)
#define LCS_DEVICE_CMYK       __MSABI_LONG(0x00000002)

#define LCS_GM_BUSINESS       __MSABI_LONG(0x00000001)
#define LCS_GM_GRAPHICS       __MSABI_LONG(0x00000002)
#define LCS_GM_IMAGES         __MSABI_LONG(0x00000004)

#define CM_OUT_OF_GAMUT       255
#define CM_IN_GAMUT           0

typedef struct tagCIEXYZ
{
  FXPT2DOT30 ciexyzX;
  FXPT2DOT30 ciexyzY;
  FXPT2DOT30 ciexyzZ;
} CIEXYZ, *LPCIEXYZ;

typedef struct tagCIEXYZTRIPLE
{
  CIEXYZ ciexyzRed;
  CIEXYZ ciexyzGreen;
  CIEXYZ ciexyzBlue;
} CIEXYZTRIPLE, *LPCIEXYZTRIPLE;

typedef struct tagLOGCOLORSPACEA
{
  DWORD lcsSignature;
  DWORD lcsVersion;
  DWORD lcsSize;
  LCSCSTYPE lcsCSType;
  LCSGAMUTMATCH lcsIntent;
  CIEXYZTRIPLE lcsEndpoints;
  DWORD lcsGammaRed;
  DWORD lcsGammaGreen;
  DWORD lcsGammaBlue;
  CHAR lcsFilename[MAX_PATH];
} LOGCOLORSPACEA, *LPLOGCOLORSPACEA;

typedef struct tagLOGCOLORSPACEW
{
  DWORD lcsSignature;
  DWORD lcsVersion;
  DWORD lcsSize;
  LCSCSTYPE lcsCSType;
  LCSGAMUTMATCH lcsIntent;
  CIEXYZTRIPLE lcsEndpoints;
  DWORD lcsGammaRed;
  DWORD lcsGammaGreen;
  DWORD lcsGammaBlue;
  WCHAR lcsFilename[MAX_PATH];
} LOGCOLORSPACEW, *LPLOGCOLORSPACEW;

DECL_WINELIB_TYPE_AW(LPLOGCOLORSPACE)
DECL_WINELIB_TYPE_AW(LOGCOLORSPACE)

#define DC_FIELDS		1
#define DC_PAPERS		2
#define DC_PAPERSIZE		3
#define DC_MINEXTENT		4
#define DC_MAXEXTENT		5
#define DC_BINS			6
#define DC_DUPLEX		7
#define DC_SIZE			8
#define DC_EXTRA		9
#define DC_VERSION		10
#define DC_DRIVER		11
#define DC_BINNAMES		12
#define DC_ENUMRESOLUTIONS	13
#define DC_FILEDEPENDENCIES	14
#define DC_TRUETYPE		15
#define DC_PAPERNAMES		16
#define DC_ORIENTATION		17
#define DC_COPIES		18
#define DC_BINADJUST            19
#define DC_EMF_COMPLIANT        20
#define DC_DATATYPE_PRODUCED    21
#define DC_COLLATE              22
#define DC_MANUFACTURER         23
#define DC_MODEL                24
#define DC_PERSONALITY          25
#define DC_PRINTRATE            26
#define DC_PRINTRATEUNIT        27
#define DC_PRINTERMEM           28
#define DC_MEDIAREADY           29
#define DC_STAPLE               30
#define DC_PRINTRATEPPM         31
#define DC_COLORDEVICE          32
#define DC_NUP                  33
#define DC_MEDIATYPENAMES       34
#define DC_MEDIATYPES           35

#define DCTT_BITMAP             __MSABI_LONG(0x00000001)
#define DCTT_DOWNLOAD           __MSABI_LONG(0x00000002)
#define DCTT_SUBDEV             __MSABI_LONG(0x00000004)
#define DCTT_DOWNLOAD_OUTLINE   __MSABI_LONG(0x00000008)

#define DCBA_FACEUPNONE         0x0000
#define DCBA_FACEUPCENTER       0x0001
#define DCBA_FACEUPLEFT         0x0002
#define DCBA_FACEUPRIGHT        0x0003
#define DCBA_FACEDOWNNONE       0x0100
#define DCBA_FACEDOWNCENTER     0x0101
#define DCBA_FACEDOWNLEFT       0x0102
#define DCBA_FACEDOWNRIGHT      0x0103

#define PRINTRATEUNIT_PPM       1
#define PRINTRATEUNIT_CPS       2
#define PRINTRATEUNIT_LPM       3
#define PRINTRATEUNIT_IPM       4

/* Flag returned from Escape QUERYDIBSUPPORT */
#define	QDI_SETDIBITS		1
#define	QDI_GETDIBITS		2
#define	QDI_DIBTOSCREEN		4
#define	QDI_STRETCHDIB		8


/* GDI Escape commands */
#define	NEWFRAME		1
#define	ABORTDOC		2
#define	NEXTBAND		3
#define	SETCOLORTABLE		4
#define	GETCOLORTABLE		5
#define	FLUSHOUTPUT		6
#define	DRAFTMODE		7
#define	QUERYESCSUPPORT		8
#define	SETABORTPROC		9
#define	STARTDOC		10
#define	ENDDOC			11
#define	GETPHYSPAGESIZE		12
#define	GETPRINTINGOFFSET	13
#define	GETSCALINGFACTOR	14
#define	MFCOMMENT		15
#define	GETPENWIDTH		16
#define	SETCOPYCOUNT		17
#define	SELECTPAPERSOURCE	18
#define	DEVICEDATA		19
#define	PASSTHROUGH		19
#define	GETTECHNOLGY		20
#define	GETTECHNOLOGY		20 /* yes, both of them */
#define	SETLINECAP		21
#define	SETLINEJOIN		22
#define	SETMITERLIMIT		23
#define	BANDINFO		24
#define	DRAWPATTERNRECT		25
#define	GETVECTORPENSIZE	26
#define	GETVECTORBRUSHSIZE	27
#define	ENABLEDUPLEX		28
#define	GETSETPAPERBINS		29
#define	GETSETPRINTORIENT	30
#define	ENUMPAPERBINS		31
#define	SETDIBSCALING		32
#define	EPSPRINTING		33
#define	ENUMPAPERMETRICS	34
#define	GETSETPAPERMETRICS	35
#define	POSTSCRIPT_DATA		37
#define	POSTSCRIPT_IGNORE	38
#define	MOUSETRAILS		39
#define	GETDEVICEUNITS		42

#define	GETEXTENDEDTEXTMETRICS	256
#define	GETEXTENTTABLE		257
#define	GETPAIRKERNTABLE	258
#define	GETTRACKKERNTABLE	259
#define	EXTTEXTOUT		512
#define	GETFACENAME		513
#define	DOWNLOADFACE		514
#define	ENABLERELATIVEWIDTHS	768
#define	ENABLEPAIRKERNING	769
#define	SETKERNTRACK		770
#define	SETALLJUSTVALUES	771
#define	SETCHARSET		772

#define	STRETCHBLT		2048
#define	GETSETSCREENPARAMS	3072
#define	QUERYDIBSUPPORT		3073
#define	BEGIN_PATH		4096
#define	CLIP_TO_PATH		4097
#define	END_PATH		4098
#define	EXT_DEVICE_CAPS		4099
#define	RESTORE_CTM		4100
#define	SAVE_CTM		4101
#define	SET_ARC_DIRECTION	4102
#define	SET_BACKGROUND_COLOR	4103
#define	SET_POLY_MODE		4104
#define	SET_SCREEN_ANGLE	4105
#define	SET_SPREAD		4106
#define	TRANSFORM_CTM		4107
#define	SET_CLIP_BOX		4108
#define	SET_BOUNDS		4109
#define	SET_MIRROR_MODE		4110
#define	OPENCHANNEL		4110
#define	DOWNLOADHEADER		4111
#define CLOSECHANNEL		4112
#define	POSTSCRIPT_PASSTHROUGH	4115
#define	ENCAPSULATED_POSTSCRIPT	4116
#define	POSTSCRIPT_IDENTIFY	4117
#define	POSTSCRIPT_INJECTION	4118
#define	CHECKJPEGFORMAT		4119
#define	CHECKPNGFORMAT		4120
#define	GET_PS_FEATURESETTING	4121
#define	GDIPLUS_TS_QUERYVER	4122
#define	GDIPLUS_TS_RECORD	4123

/* for POSTSCRIPT_IDENTIFY */
#define PSIDENT_GDICENTRIC	0
#define PSIDENT_PSCENTRIC	1


#define QDI_SETDIBITS           1
#define QDI_GETDIBITS           2
#define QDI_DIBTOSCREEN         4
#define QDI_STRETCHDIB          8

/* Spooler Error Codes */
#define	SP_NOTREPORTED	0x4000
#define	SP_ERROR	(-1)
#define	SP_APPABORT	(-2)
#define	SP_USERABORT	(-3)
#define	SP_OUTOFDISK	(-4)
#define	SP_OUTOFMEMORY	(-5)

#define PR_JOBSTATUS     0

  /* Raster operations */

#define R2_BLACK         1
#define R2_NOTMERGEPEN   2
#define R2_MASKNOTPEN    3
#define R2_NOTCOPYPEN    4
#define R2_MASKPENNOT    5
#define R2_NOT           6
#define R2_XORPEN        7
#define R2_NOTMASKPEN    8
#define R2_MASKPEN       9
#define R2_NOTXORPEN    10
#define R2_NOP          11
#define R2_MERGENOTPEN  12
#define R2_COPYPEN      13
#define R2_MERGEPENNOT  14
#define R2_MERGEPEN     15
#define R2_WHITE        16
#define R2_LAST         16

#define MAKEROP4(fore,back) (DWORD)((((back)<<8)&0xFF000000)|(fore))

#define SRCCOPY         0xcc0020
#define SRCPAINT        0xee0086
#define SRCAND          0x8800c6
#define SRCINVERT       0x660046
#define SRCERASE        0x440328
#define NOTSRCCOPY      0x330008
#define NOTSRCERASE     0x1100a6
#define MERGECOPY       0xc000ca
#define MERGEPAINT      0xbb0226
#define PATCOPY         0xf00021
#define PATPAINT        0xfb0a09
#define PATINVERT       0x5a0049
#define DSTINVERT       0x550009
#define BLACKNESS       0x000042
#define WHITENESS       0xff0062

  /* StretchBlt() modes */
#define BLACKONWHITE         1
#define WHITEONBLACK         2
#define COLORONCOLOR	     3
#define HALFTONE             4
#define MAXSTRETCHBLTMODE    4

#define STRETCH_ANDSCANS     BLACKONWHITE
#define STRETCH_ORSCANS      WHITEONBLACK
#define STRETCH_DELETESCANS  COLORONCOLOR
#define STRETCH_HALFTONE     HALFTONE

  /* Colors */

#define RGB(r,g,b)          ((COLORREF)((BYTE)(r) | ((BYTE)(g) << 8) | ((BYTE)(b) << 16)))
#define PALETTERGB(r,g,b)   (0x02000000 | RGB(r,g,b))
#define PALETTEINDEX(i)     ((COLORREF)(0x01000000 | (WORD)(i)))

#define GetRValue(rgb)      ((BYTE)  (rgb) )
#define GetGValue(rgb)      ((BYTE) ((rgb) >> 8))
#define GetBValue(rgb)      ((BYTE) ((rgb) >> 16))

#define GetKValue(cmyk)     ((BYTE)  (cmyk) )
#define GetYValue(cmyk)     ((BYTE) ((cmyk) >> 8))
#define GetMValue(cmyk)     ((BYTE) ((cmyk) >> 16))
#define GetCValue(cmyk)     ((BYTE) ((cmyk) >> 24))

#define CMYK(c,m,y,k)       ((COLORREF)((((BYTE)(k)|((WORD)((BYTE)(y))<<8))|(((DWORD)(BYTE)(m))<<16))|(((DWORD)(BYTE)(c))<<24)))

/* ICM stuff */
typedef INT (CALLBACK *ICMENUMPROCA)(LPSTR lpszFilename,LPARAM lParam);
typedef INT (CALLBACK *ICMENUMPROCW)(LPWSTR lpszFilename,LPARAM lParam);
DECL_WINELIB_TYPE_AW(ICMENUMPROC)


#define ICM_OFF   1
#define ICM_ON    2
#define ICM_QUERY 3

  /* Bounds Accumulation APIs */
#define DCB_RESET       0x0001
#define DCB_ACCUMULATE  0x0002
#define DCB_DIRTY       DCB_ACCUMULATE
#define DCB_SET         (DCB_RESET | DCB_ACCUMULATE)
#define DCB_ENABLE      0x0004
#define DCB_DISABLE     0x0008

typedef struct
{
    LONG paXCount;
    LONG paYCount;
    LONG paXExt;
    LONG paYExt;
    BYTE paRGBs;
} PELARRAY, *PPELARRAY, *LPPELARRAY;

  /* Bitmaps */

typedef struct
{
    INT  bmType;
    INT  bmWidth;
    INT  bmHeight;
    INT  bmWidthBytes;
    WORD   bmPlanes;
    WORD   bmBitsPixel;
    LPVOID bmBits;
} BITMAP, *PBITMAP, *LPBITMAP;


  /* Brushes */

typedef struct
{
    UINT       lbStyle;
    COLORREF   lbColor;
    ULONG_PTR  lbHatch;
} LOGBRUSH, *PLOGBRUSH, *LPLOGBRUSH;

typedef struct
{
    UINT       lbStyle;
    COLORREF   lbColor;
    ULONG      lbHatch;
} LOGBRUSH32, *PLOGBRUSH32, *LPLOGBRUSH32;

typedef LOGBRUSH PATTERN, *PPATTERN, *LPPATTERN;


  /* Brush styles */
#define BS_SOLID	    0
#define BS_NULL		    1
#define BS_HOLLOW	    1
#define BS_HATCHED	    2
#define BS_PATTERN	    3
#define BS_INDEXED	    4
#define	BS_DIBPATTERN	    5
#define	BS_DIBPATTERNPT	    6
#define BS_PATTERN8X8	    7
#define	BS_DIBPATTERN8X8    8
#define BS_MONOPATTERN      9

  /* Hatch styles */
#define HS_HORIZONTAL       0
#define HS_VERTICAL         1
#define HS_FDIAGONAL        2
#define HS_BDIAGONAL        3
#define HS_CROSS            4
#define HS_DIAGCROSS        5
#define HS_API_MAX          12

  /* Fonts */

#define LF_FACESIZE     32
#define LF_FULLFACESIZE 64

#define RASTER_FONTTYPE     0x0001
#define DEVICE_FONTTYPE     0x0002
#define TRUETYPE_FONTTYPE   0x0004

typedef struct tagLOGFONTA
{
    LONG   lfHeight;
    LONG   lfWidth;
    LONG   lfEscapement;
    LONG   lfOrientation;
    LONG   lfWeight;
    BYTE   lfItalic;
    BYTE   lfUnderline;
    BYTE   lfStrikeOut;
    BYTE   lfCharSet;
    BYTE   lfOutPrecision;
    BYTE   lfClipPrecision;
    BYTE   lfQuality;
    BYTE   lfPitchAndFamily;
    CHAR   lfFaceName[LF_FACESIZE];
} LOGFONTA, *PLOGFONTA, *LPLOGFONTA;

typedef struct tagLOGFONTW
{
    LONG   lfHeight;
    LONG   lfWidth;
    LONG   lfEscapement;
    LONG   lfOrientation;
    LONG   lfWeight;
    BYTE   lfItalic;
    BYTE   lfUnderline;
    BYTE   lfStrikeOut;
    BYTE   lfCharSet;
    BYTE   lfOutPrecision;
    BYTE   lfClipPrecision;
    BYTE   lfQuality;
    BYTE   lfPitchAndFamily;
    WCHAR  lfFaceName[LF_FACESIZE];
} LOGFONTW, *PLOGFONTW, *LPLOGFONTW;

DECL_WINELIB_TYPE_AW(LOGFONT)
DECL_WINELIB_TYPE_AW(PLOGFONT)
DECL_WINELIB_TYPE_AW(LPLOGFONT)

typedef struct
{
  LOGFONTA elfLogFont;
  BYTE       elfFullName[LF_FULLFACESIZE];
  BYTE       elfStyle[LF_FACESIZE];
} ENUMLOGFONTA, *LPENUMLOGFONTA;

typedef struct
{
  LOGFONTW elfLogFont;
  WCHAR      elfFullName[LF_FULLFACESIZE];
  WCHAR      elfStyle[LF_FACESIZE];
} ENUMLOGFONTW, *LPENUMLOGFONTW;

DECL_WINELIB_TYPE_AW(ENUMLOGFONT)
DECL_WINELIB_TYPE_AW(LPENUMLOGFONT)

typedef struct
{
  LOGFONTA elfLogFont;
  BYTE       elfFullName[LF_FULLFACESIZE];
  BYTE       elfStyle[LF_FACESIZE];
  BYTE       elfScript[LF_FACESIZE];
} ENUMLOGFONTEXA,*LPENUMLOGFONTEXA;

typedef struct
{
  LOGFONTW elfLogFont;
  WCHAR      elfFullName[LF_FULLFACESIZE];
  WCHAR      elfStyle[LF_FACESIZE];
  WCHAR      elfScript[LF_FACESIZE];
} ENUMLOGFONTEXW,*LPENUMLOGFONTEXW;

DECL_WINELIB_TYPE_AW(ENUMLOGFONTEX)
DECL_WINELIB_TYPE_AW(LPENUMLOGFONTEX)

#define MM_MAX_NUMAXES    16

typedef struct
{
  DWORD      dvReserved;
  DWORD      dvNumAxes;
  LONG       dvValues[MM_MAX_NUMAXES];
} DESIGNVECTOR, *PDESIGNVECTOR;

typedef struct
{
  ENUMLOGFONTEXA    elfEnumLogfontEx;
  DESIGNVECTOR      elfDesignVector;
} ENUMLOGFONTEXDVA, *PENUMLOGFONTEXDVA;

typedef struct
{
  ENUMLOGFONTEXW    elfEnumLogfontEx;
  DESIGNVECTOR      elfDesignVector;
} ENUMLOGFONTEXDVW, *PENUMLOGFONTEXDVW;

DECL_WINELIB_TYPE_AW(ENUMLOGFONTEXDV)
DECL_WINELIB_TYPE_AW(PENUMLOGFONTEXDV)

/*
 * The FONTSIGNATURE tells which Unicode ranges and which code pages
 * have glyphs in a font.
 *
 * fsUsb  128-bit bitmap. The most significant bits are 10 (magic number).
 *        The remaining 126 bits map the Unicode ISO 10646 subranges
 *        for which the font provides glyphs.
 *
 * fsCsb  64-bit bitmap. The low 32 bits map the Windows codepages for
 *        which the font provides glyphs. The high 32 bits are for
 *        non Windows codepages.
 */
typedef struct
{
  DWORD fsUsb[4];
  DWORD fsCsb[2];
} FONTSIGNATURE, *PFONTSIGNATURE, *LPFONTSIGNATURE;

typedef struct
{
  UINT	ciCharset; /* character set */
  UINT	ciACP; /* ANSI code page */
  FONTSIGNATURE	fs;
} CHARSETINFO, *PCHARSETINFO, *LPCHARSETINFO;

/* Flags for TranslateCharsetInfo */
#define TCI_SRCCHARSET    1
#define TCI_SRCCODEPAGE   2
#define TCI_SRCFONTSIG    3

typedef struct
{
    DWORD lsUsb[4];
    DWORD lsCsbDefault[2];
    DWORD lsCsbSupported[2];
} LOCALESIGNATURE, *PLOCALESIGNATURE, *LPLOCALESIGNATURE;


/* Flags for ModifyWorldTransform */
#define MWT_IDENTITY      1
#define MWT_LEFTMULTIPLY  2
#define MWT_RIGHTMULTIPLY 3
#define MWT_MIN           MWT_IDENTITY
#define MWT_MAX           MWT_RIGHTMULTIPLY

/* Object Definitions for EnumObjects() */
#define OBJ_PEN             1
#define OBJ_BRUSH           2
#define OBJ_DC              3
#define OBJ_METADC          4
#define OBJ_PAL             5
#define OBJ_FONT            6
#define OBJ_BITMAP          7
#define OBJ_REGION          8
#define OBJ_METAFILE        9
#define OBJ_MEMDC           10
#define OBJ_EXTPEN          11
#define OBJ_ENHMETADC       12
#define OBJ_ENHMETAFILE     13
#define OBJ_COLORSPACE      14

typedef struct tagXFORM
{
    FLOAT  eM11;
    FLOAT  eM12;
    FLOAT  eM21;
    FLOAT  eM22;
    FLOAT  eDx;
    FLOAT  eDy;
} XFORM, *PXFORM, *LPXFORM;

  /* lfWeight values */
#define FW_DONTCARE	    0
#define FW_THIN 	    100
#define FW_EXTRALIGHT	    200
#define FW_ULTRALIGHT	    200
#define FW_LIGHT	    300
#define FW_NORMAL	    400
#define FW_REGULAR	    400
#define FW_MEDIUM	    500
#define FW_SEMIBOLD	    600
#define FW_DEMIBOLD	    600
#define FW_BOLD 	    700
#define FW_EXTRABOLD	    800
#define FW_ULTRABOLD	    800
#define FW_HEAVY	    900
#define FW_BLACK	    900

  /* lfCharSet values */
#define ANSI_CHARSET	      (BYTE)0   /* CP1252, ansi-0, iso8859-{1,15} */
#define DEFAULT_CHARSET       (BYTE)1
#define SYMBOL_CHARSET	      (BYTE)2
#define SHIFTJIS_CHARSET      (BYTE)128 /* CP932 */
#define HANGEUL_CHARSET       (BYTE)129 /* CP949, ksc5601.1987-0 */
#define HANGUL_CHARSET        HANGEUL_CHARSET
#define GB2312_CHARSET        (BYTE)134 /* CP936, gb2312.1980-0 */
#define CHINESEBIG5_CHARSET   (BYTE)136 /* CP950, big5.et-0 */
#define GREEK_CHARSET         (BYTE)161	/* CP1253 */
#define TURKISH_CHARSET       (BYTE)162	/* CP1254, -iso8859-9 */
#define HEBREW_CHARSET        (BYTE)177	/* CP1255, -iso8859-8 */
#define ARABIC_CHARSET        (BYTE)178	/* CP1256, -iso8859-6 */
#define BALTIC_CHARSET        (BYTE)186	/* CP1257, -iso8859-13 */
#define VIETNAMESE_CHARSET    (BYTE)163 /* CP1258 */
#define RUSSIAN_CHARSET       (BYTE)204	/* CP1251, -iso8859-5 */
#define EE_CHARSET	      (BYTE)238	/* CP1250, -iso8859-2 */
#define EASTEUROPE_CHARSET    EE_CHARSET
#define THAI_CHARSET	      (BYTE)222 /* CP874, iso8859-11, tis620 */
#define JOHAB_CHARSET         (BYTE)130 /* korean (johab) CP1361 */
#define MAC_CHARSET           (BYTE)77
#define OEM_CHARSET	      (BYTE)255
/* I don't know if the values of *_CHARSET macros are defined in Windows
 * or if we can choose them as we want. -- srtxg
 */
#define VISCII_CHARSET        (BYTE)240 /* viscii1.1-1 */
#define TCVN_CHARSET          (BYTE)241 /* tcvn-0 */
#define KOI8_CHARSET          (BYTE)242 /* koi8-{r,u,ru} */
#define ISO3_CHARSET          (BYTE)243 /* iso8859-3 */
#define ISO4_CHARSET          (BYTE)244 /* iso8859-4 */
#define ISO10_CHARSET         (BYTE)245 /* iso8859-10 */
#define CELTIC_CHARSET        (BYTE)246 /* iso8859-14 */

#define FS_LATIN1              __MSABI_LONG(0x00000001)
#define FS_LATIN2              __MSABI_LONG(0x00000002)
#define FS_CYRILLIC            __MSABI_LONG(0x00000004)
#define FS_GREEK               __MSABI_LONG(0x00000008)
#define FS_TURKISH             __MSABI_LONG(0x00000010)
#define FS_HEBREW              __MSABI_LONG(0x00000020)
#define FS_ARABIC              __MSABI_LONG(0x00000040)
#define FS_BALTIC              __MSABI_LONG(0x00000080)
#define FS_VIETNAMESE          __MSABI_LONG(0x00000100)
#define FS_THAI                __MSABI_LONG(0x00010000)
#define FS_JISJAPAN            __MSABI_LONG(0x00020000)
#define FS_CHINESESIMP         __MSABI_LONG(0x00040000)
#define FS_WANSUNG             __MSABI_LONG(0x00080000)
#define FS_CHINESETRAD         __MSABI_LONG(0x00100000)
#define FS_JOHAB               __MSABI_LONG(0x00200000)
#define FS_SYMBOL              __MSABI_LONG(0x80000000)

  /* lfOutPrecision values */
#define OUT_DEFAULT_PRECIS           0
#define OUT_STRING_PRECIS            1
#define OUT_CHARACTER_PRECIS         2
#define OUT_STROKE_PRECIS            3
#define OUT_TT_PRECIS                4
#define OUT_DEVICE_PRECIS            5
#define OUT_RASTER_PRECIS            6
#define OUT_TT_ONLY_PRECIS           7
#define OUT_OUTLINE_PRECIS           8
#define OUT_SCREEN_OUTLINE_PRECIS    9
#define OUT_PS_ONLY_PRECIS           10

  /* lfClipPrecision values */
#define CLIP_DEFAULT_PRECIS     0x00
#define CLIP_CHARACTER_PRECIS   0x01
#define CLIP_STROKE_PRECIS      0x02
#define CLIP_MASK               0x0F
#define CLIP_LH_ANGLES          0x10
#define CLIP_TT_ALWAYS          0x20
#define CLIP_DFA_DISABLE        0x40
#define CLIP_EMBEDDED           0x80

  /* lfQuality values */
#define DEFAULT_QUALITY            0
#define DRAFT_QUALITY              1
#define PROOF_QUALITY              2
#define NONANTIALIASED_QUALITY     3
#define ANTIALIASED_QUALITY        4
#define CLEARTYPE_QUALITY          5
#define CLEARTYPE_NATURAL_QUALITY  6

  /* lfPitchAndFamily pitch values */
#define DEFAULT_PITCH       0x00
#define FIXED_PITCH         0x01
#define VARIABLE_PITCH      0x02
#define MONO_FONT           0x08

#define FF_DONTCARE         0x00
#define FF_ROMAN            0x10
#define FF_SWISS            0x20
#define FF_MODERN           0x30
#define FF_SCRIPT           0x40
#define FF_DECORATIVE       0x50

#ifndef _TEXTMETRIC_DEFINED
#define _TEXTMETRIC_DEFINED

typedef struct tagTEXTMETRICA
{
    LONG      tmHeight;
    LONG      tmAscent;
    LONG      tmDescent;
    LONG      tmInternalLeading;
    LONG      tmExternalLeading;
    LONG      tmAveCharWidth;
    LONG      tmMaxCharWidth;
    LONG      tmWeight;
    LONG      tmOverhang;
    LONG      tmDigitizedAspectX;
    LONG      tmDigitizedAspectY;
    BYTE      tmFirstChar;
    BYTE      tmLastChar;
    BYTE      tmDefaultChar;
    BYTE      tmBreakChar;
    BYTE      tmItalic;
    BYTE      tmUnderlined;
    BYTE      tmStruckOut;
    BYTE      tmPitchAndFamily;
    BYTE      tmCharSet;
} TEXTMETRICA, *LPTEXTMETRICA, *PTEXTMETRICA;

typedef struct tagTEXTMETRICW
{
    LONG      tmHeight;
    LONG      tmAscent;
    LONG      tmDescent;
    LONG      tmInternalLeading;
    LONG      tmExternalLeading;
    LONG      tmAveCharWidth;
    LONG      tmMaxCharWidth;
    LONG      tmWeight;
    LONG      tmOverhang;
    LONG      tmDigitizedAspectX;
    LONG      tmDigitizedAspectY;
    WCHAR     tmFirstChar;
    WCHAR     tmLastChar;
    WCHAR     tmDefaultChar;
    WCHAR     tmBreakChar;
    BYTE      tmItalic;
    BYTE      tmUnderlined;
    BYTE      tmStruckOut;
    BYTE      tmPitchAndFamily;
    BYTE      tmCharSet;
} TEXTMETRICW, *LPTEXTMETRICW, *PTEXTMETRICW;

DECL_WINELIB_TYPE_AW(TEXTMETRIC)
DECL_WINELIB_TYPE_AW(PTEXTMETRIC)
DECL_WINELIB_TYPE_AW(LPTEXTMETRIC)
#endif /* _TEXTMETRIC_DEFINED */


typedef struct tagPANOSE
{
    BYTE bFamilyType;
    BYTE bSerifStyle;
    BYTE bWeight;
    BYTE bProportion;
    BYTE bContrast;
    BYTE bStrokeVariation;
    BYTE bArmStyle;
    BYTE bLetterform;
    BYTE bMidline;
    BYTE bXHeight;
} PANOSE, *LPPANOSE;

#define PANOSE_COUNT                   10

#define PAN_FAMILYTYPE_INDEX           0
#define PAN_SERIFSTYLE_INDEX           1
#define PAN_WEIGHT_INDEX               2
#define PAN_PROPORTION_INDEX           3
#define PAN_CONTRAST_INDEX             4
#define PAN_STROKEVARIATION_INDEX      5
#define PAN_ARMSTYLE_INDEX             6
#define PAN_LETTERFORM_INDEX           7
#define PAN_MIDLINE_INDEX              8
#define PAN_XHEIGHT_INDEX              9

#define PAN_CULTURE_LATIN              0

#define PAN_ANY                        0
#define PAN_NO_FIT                     1

#define PAN_FAMILY_TEXT_DISPLAY        2
#define PAN_FAMILY_SCRIPT              3
#define PAN_FAMILY_DECORATIVE          4
#define PAN_FAMILY_PICTORIAL           5

#define PAN_SERIF_COVE                 2
#define PAN_SERIF_OBTUSE_COVE          3
#define PAN_SERIF_SQUARE_COVE          4
#define PAN_SERIF_OBTUSE_SQUARE_COVE   5
#define PAN_SERIF_SQUARE               6
#define PAN_SERIF_THIN                 7
#define PAN_SERIF_BONE                 8
#define PAN_SERIF_EXAGGERATED          9
#define PAN_SERIF_TRIANGLE             10
#define PAN_SERIF_NORMAL_SANS          11
#define PAN_SERIF_OBTUSE_SANS          12
#define PAN_SERIF_PERP_SANS            13
#define PAN_SERIF_FLARED               14
#define PAN_SERIF_ROUNDED              15

#define PAN_WEIGHT_VERY_LIGHT          2
#define PAN_WEIGHT_LIGHT               3
#define PAN_WEIGHT_THIN                4
#define PAN_WEIGHT_BOOK                5
#define PAN_WEIGHT_MEDIUM              6
#define PAN_WEIGHT_DEMI                7
#define PAN_WEIGHT_BOLD                8
#define PAN_WEIGHT_HEAVY               9
#define PAN_WEIGHT_BLACK               10
#define PAN_WEIGHT_NORD                11

#define PAN_PROP_OLD_STYLE             2
#define PAN_PROP_MODERN                3
#define PAN_PROP_EVEN_WIDTH            4
#define PAN_PROP_EXPANDED              5
#define PAN_PROP_CONDENSED             6
#define PAN_PROP_VERY_EXPANDED         7
#define PAN_PROP_VERY_CONDENSED        8
#define PAN_PROP_MONOSPACED            9

#define PAN_CONTRAST_NONE              2
#define PAN_CONTRAST_VERY_LOW          3
#define PAN_CONTRAST_LOW               4
#define PAN_CONTRAST_MEDIUM_LOW        5
#define PAN_CONTRAST_MEDIUM            6
#define PAN_CONTRAST_MEDIUM_HIGH       7
#define PAN_CONTRAST_HIGH              8
#define PAN_CONTRAST_VERY_HIGH         9

#define PAN_STROKE_GRADUAL_DIAG        2
#define PAN_STROKE_GRADUAL_TRAN        3
#define PAN_STROKE_GRADUAL_VERT        4
#define PAN_STROKE_GRADUAL_HORZ        5
#define PAN_STROKE_RAPID_VERT          6
#define PAN_STROKE_RAPID_HORZ          7
#define PAN_STROKE_INSTANT_VERT        8

#define PAN_STRAIGHT_ARMS_HORZ         2
#define PAN_STRAIGHT_ARMS_WEDGE        3
#define PAN_STRAIGHT_ARMS_VERT         4
#define PAN_STRAIGHT_ARMS_SINGLE_SERIF 5
#define PAN_STRAIGHT_ARMS_DOUBLE_SERIF 6
#define PAN_BENT_ARMS_HORZ             7
#define PAN_BENT_ARMS_WEDGE            8
#define PAN_BENT_ARMS_VERT             9
#define PAN_BENT_ARMS_SINGLE_SERIF     10
#define PAN_BENT_ARMS_DOUBLE_SERIF     11

#define PAN_LETT_NORMAL_COMPACT        2
#define PAN_LETT_NORMAL_WEIGHTED       3
#define PAN_LETT_NORMAL_BOXED          4
#define PAN_LETT_NORMAL_FLATTENED      5
#define PAN_LETT_NORMAL_ROUNDED        6
#define PAN_LETT_NORMAL_OFF_CENTER     7
#define PAN_LETT_NORMAL_SQUARE         8
#define PAN_LETT_OBLIQUE_COMPACT       9
#define PAN_LETT_OBLIQUE_WEIGHTED      10
#define PAN_LETT_OBLIQUE_BOXED         11
#define PAN_LETT_OBLIQUE_FLATTENED     12
#define PAN_LETT_OBLIQUE_ROUNDED       13
#define PAN_LETT_OBLIQUE_OFF_CENTER    14
#define PAN_LETT_OBLIQUE_SQUARE        15

#define PAN_MIDLINE_STANDARD_TRIMMED   2
#define PAN_MIDLINE_STANDARD_POINTED   3
#define PAN_MIDLINE_STANDARD_SERIFED   4
#define PAN_MIDLINE_HIGH_TRIMMED       5
#define PAN_MIDLINE_HIGH_POINTED       6
#define PAN_MIDLINE_HIGH_SERIFED       7
#define PAN_MIDLINE_CONSTANT_TRIMMED   8
#define PAN_MIDLINE_CONSTANT_POINTED   9
#define PAN_MIDLINE_CONSTANT_SERIFED   10
#define PAN_MIDLINE_LOW_TRIMMED        11
#define PAN_MIDLINE_LOW_POINTED        12
#define PAN_MIDLINE_LOW_SERIFED        13

#define PAN_XHEIGHT_CONSTANT_SMALL     2
#define PAN_XHEIGHT_CONSTANT_STANDARD  3
#define PAN_XHEIGHT_CONSTANT_LARGE     4
#define PAN_XHEIGHT_DUCKING_SMALL      5
#define PAN_XHEIGHT_DUCKING_STANDARD   6
#define PAN_XHEIGHT_DUCKING_LARGE      7

#define ELF_VENDOR_SIZE 4
typedef struct
{
  LOGFONTA    elfLogFont;
  BYTE        elfFullName[LF_FULLFACESIZE];
  BYTE        elfStyle[LF_FACESIZE];
  DWORD       elfVersion;
  DWORD       elfStyleSize;
  DWORD       elfMatch;
  DWORD       elfReserved;
  BYTE        elfVendorId[ELF_VENDOR_SIZE];
  DWORD       elfCulture;
  PANOSE      elfPanose;
} EXTLOGFONTA, *PEXTLOGFONTA, *LPEXTLOGFONTA;

typedef struct
{
  LOGFONTW    elfLogFont;
  WCHAR       elfFullName[LF_FULLFACESIZE];
  WCHAR       elfStyle[LF_FACESIZE];
  DWORD       elfVersion;
  DWORD       elfStyleSize;
  DWORD       elfMatch;
  DWORD       elfReserved;
  BYTE        elfVendorId[ELF_VENDOR_SIZE];
  DWORD       elfCulture;
  PANOSE      elfPanose;
} EXTLOGFONTW, *PEXTLOGFONTW, *LPEXTLOGFONTW;

DECL_WINELIB_TYPE_AW(EXTLOGFONT)
DECL_WINELIB_TYPE_AW(PEXTLOGFONT)
DECL_WINELIB_TYPE_AW(LPEXTLOGFONT)

#define ELF_VERSION         0
#define ELF_CULTURE_LATIN   0

typedef struct _OUTLINETEXTMETRICA
{
    UINT          otmSize;
    TEXTMETRICA   otmTextMetrics;
    BYTE            otmFiller;
    PANOSE          otmPanoseNumber;
    UINT          otmfsSelection;
    UINT          otmfsType;
    INT           otmsCharSlopeRise;
    INT           otmsCharSlopeRun;
    INT           otmItalicAngle;
    UINT          otmEMSquare;
    INT           otmAscent;
    INT           otmDescent;
    UINT          otmLineGap;
    UINT          otmsCapEmHeight;
    UINT          otmsXHeight;
    RECT          otmrcFontBox;
    INT           otmMacAscent;
    INT           otmMacDescent;
    UINT          otmMacLineGap;
    UINT          otmusMinimumPPEM;
    POINT         otmptSubscriptSize;
    POINT         otmptSubscriptOffset;
    POINT         otmptSuperscriptSize;
    POINT         otmptSuperscriptOffset;
    UINT          otmsStrikeoutSize;
    INT           otmsStrikeoutPosition;
    INT           otmsUnderscoreSize;
    INT           otmsUnderscorePosition;
    LPSTR           otmpFamilyName;
    LPSTR           otmpFaceName;
    LPSTR           otmpStyleName;
    LPSTR           otmpFullName;
} OUTLINETEXTMETRICA, *POUTLINETEXTMETRICA, *LPOUTLINETEXTMETRICA;

typedef struct _OUTLINETEXTMETRICW
{
    UINT          otmSize;
    TEXTMETRICW   otmTextMetrics;
    BYTE            otmFiller;
    PANOSE          otmPanoseNumber;
    UINT          otmfsSelection;
    UINT          otmfsType;
    INT           otmsCharSlopeRise;
    INT           otmsCharSlopeRun;
    INT           otmItalicAngle;
    UINT          otmEMSquare;
    INT           otmAscent;
    INT           otmDescent;
    UINT          otmLineGap;
    UINT          otmsCapEmHeight;
    UINT          otmsXHeight;
    RECT          otmrcFontBox;
    INT           otmMacAscent;
    INT           otmMacDescent;
    UINT          otmMacLineGap;
    UINT          otmusMinimumPPEM;
    POINT         otmptSubscriptSize;
    POINT         otmptSubscriptOffset;
    POINT         otmptSuperscriptSize;
    POINT         otmptSuperscriptOffset;
    UINT          otmsStrikeoutSize;
    INT           otmsStrikeoutPosition;
    INT           otmsUnderscoreSize;
    INT           otmsUnderscorePosition;
    LPSTR           otmpFamilyName;
    LPSTR           otmpFaceName;
    LPSTR           otmpStyleName;
    LPSTR           otmpFullName;
} OUTLINETEXTMETRICW, *POUTLINETEXTMETRICW, *LPOUTLINETEXTMETRICW;

DECL_WINELIB_TYPE_AW(OUTLINETEXTMETRIC)
DECL_WINELIB_TYPE_AW(POUTLINETEXTMETRIC)
DECL_WINELIB_TYPE_AW(LPOUTLINETEXTMETRIC)

typedef struct
{
    INT       x;
    INT       y;
    UINT      n;
    LPCSTR    lpstr;
    UINT      uiFlags;
    RECT      rcl;
    INT       *pdx;
} POLYTEXTA, *PPOLYTEXTA, *LPPOLYTEXTA;

typedef struct
{
    INT       x;
    INT       y;
    UINT      n;
    LPCWSTR   lpstr;
    UINT      uiFlags;
    RECT      rcl;
    INT       *pdx;
} POLYTEXTW, *PPOLYTEXTW, *LPPOLYTEXTW;

DECL_WINELIB_TYPE_AW(POLYTEXT)
DECL_WINELIB_TYPE_AW(PPOLYTEXT)
DECL_WINELIB_TYPE_AW(LPPOLYTEXT)


/* ntmFlags field flags */
#define NTM_REGULAR     __MSABI_LONG(0x00000040)
#define NTM_BOLD        __MSABI_LONG(0x00000020)
#define NTM_ITALIC      __MSABI_LONG(0x00000001)

#define NTM_NONNEGATIVE_AC  0x00010000
#define NTM_PS_OPENTYPE     0x00020000
#define NTM_TT_OPENTYPE     0x00040000
#define NTM_MULTIPLEMASTER  0x00080000
#define NTM_TYPE1           0x00100000
#define NTM_DSIG            0x00200000


typedef struct
{
    LONG      tmHeight;
    LONG      tmAscent;
    LONG      tmDescent;
    LONG      tmInternalLeading;
    LONG      tmExternalLeading;
    LONG      tmAveCharWidth;
    LONG      tmMaxCharWidth;
    LONG      tmWeight;
    LONG      tmOverhang;
    LONG      tmDigitizedAspectX;
    LONG      tmDigitizedAspectY;
    BYTE      tmFirstChar;
    BYTE      tmLastChar;
    BYTE      tmDefaultChar;
    BYTE      tmBreakChar;
    BYTE      tmItalic;
    BYTE      tmUnderlined;
    BYTE      tmStruckOut;
    BYTE      tmPitchAndFamily;
    BYTE      tmCharSet;
    DWORD     ntmFlags;
    UINT    ntmSizeEM;
    UINT    ntmCellHeight;
    UINT    ntmAvgWidth;
} NEWTEXTMETRICA, *PNEWTEXTMETRICA, *LPNEWTEXTMETRICA;

typedef struct
{
    LONG      tmHeight;
    LONG      tmAscent;
    LONG      tmDescent;
    LONG      tmInternalLeading;
    LONG      tmExternalLeading;
    LONG      tmAveCharWidth;
    LONG      tmMaxCharWidth;
    LONG      tmWeight;
    LONG      tmOverhang;
    LONG      tmDigitizedAspectX;
    LONG      tmDigitizedAspectY;
    WCHAR     tmFirstChar;
    WCHAR     tmLastChar;
    WCHAR     tmDefaultChar;
    WCHAR     tmBreakChar;
    BYTE      tmItalic;
    BYTE      tmUnderlined;
    BYTE      tmStruckOut;
    BYTE      tmPitchAndFamily;
    BYTE      tmCharSet;
    DWORD     ntmFlags;
    UINT      ntmSizeEM;
    UINT      ntmCellHeight;
    UINT      ntmAvgWidth;
} NEWTEXTMETRICW, *PNEWTEXTMETRICW, *LPNEWTEXTMETRICW;

DECL_WINELIB_TYPE_AW(NEWTEXTMETRIC)
DECL_WINELIB_TYPE_AW(PNEWTEXTMETRIC)
DECL_WINELIB_TYPE_AW(LPNEWTEXTMETRIC)

typedef struct
{
    NEWTEXTMETRICA	ntmTm;
    FONTSIGNATURE       ntmFontSig;
} NEWTEXTMETRICEXA;

typedef struct
{
    NEWTEXTMETRICW	ntmTm;
    FONTSIGNATURE       ntmFontSig;
} NEWTEXTMETRICEXW;

DECL_WINELIB_TYPE_AW(NEWTEXTMETRICEX)

#if defined(STRICT)

#if !defined(NOTEXTMETRIC)
typedef int (CALLBACK *OLDFONTENUMPROCA)(const LOGFONTA *, const TEXTMETRICA *, DWORD, LPARAM);
typedef int (CALLBACK *OLDFONTENUMPROCW)(const LOGFONTW *, const TEXTMETRICW *, DWORD, LPARAM);
#else /* !defined(NOTEXTMETRIC) */
typedef int (CALLBACK *OLDFONTENUMPROCA)(const LOGFONTA *, const VOID *, DWORD, LPARAM);
typedef int (CALLBACK *OLDFONTENUMPROCW)(const LOGFONTW *, const VOID *, DWORD, LPARAM);
#endif /* !defined(NOTEXTMETRIC) */
DECL_WINELIB_TYPE_AW(OLDFONTENUMPROC)

typedef OLDFONTENUMPROCA FONTENUMPROCA;
typedef OLDFONTENUMPROCW FONTENUMPROCW;
DECL_WINELIB_TYPE_AW(FONTENUMPROC)

typedef INT (CALLBACK *GOBJENUMPROC)(LPVOID, LPARAM);
typedef VOID (CALLBACK *LINEDDAPROC)(INT, INT, LPARAM);

#else /* defined(STRICT) */

typedef FARPROC OLDFONTENUMPROC;

typedef FARPROC FONTENUMPROCA;
typedef FARPROC FONTENUMPROCW;
DECL_WINELIB_TYPE_AW(FONTENUMPROC)

typedef FARPROC GOBJENUMPROC;
typedef FARPROC LINEDDAPROC;

#endif /* defined(STRICT) */

  /* tmPitchAndFamily bits */
#define TMPF_FIXED_PITCH    1		/* means variable pitch */
#define TMPF_VECTOR	    2
#define TMPF_TRUETYPE	    4
#define TMPF_DEVICE	    8

  /* Text alignment */
#define TA_NOUPDATECP       0x00
#define TA_UPDATECP         0x01
#define TA_LEFT             0x00
#define TA_RIGHT            0x02
#define TA_CENTER           0x06
#define TA_TOP              0x00
#define TA_BOTTOM           0x08
#define TA_BASELINE         0x18
#define TA_RTLREADING        0x100
#define TA_MASK             TA_BASELINE+TA_CENTER+TA_UPDATECP+TA_RTLREADING

#define VTA_BASELINE        TA_BASELINE
#define VTA_LEFT            TA_BOTTOM
#define VTA_RIGHT           TA_TOP
#define VTA_CENTER          TA_CENTER
#define VTA_BOTTOM          TA_RIGHT
#define VTA_TOP             TA_LEFT


  /* ExtTextOut() parameters */
#define ETO_GRAYED          0x0001
#define ETO_OPAQUE          0x0002
#define ETO_CLIPPED         0x0004
#define ETO_GLYPH_INDEX     0x0010
#define ETO_RTLREADING      0x0080
#define ETO_NUMERICSLOCAL   0x0400
#define ETO_NUMERICSLATIN   0x0800
#define ETO_IGNORELANGUAGE  0x1000
#define ETO_PDY             0x2000

#define ASPECT_FILTERING    0x0001

  /* for GetGlyphIndices() */
#define GGI_MARK_NONEXISTING_GLYPHS  0x0001

typedef struct
{
    UINT	gmBlackBoxX;
    UINT	gmBlackBoxY;
    POINT	gmptGlyphOrigin;
    SHORT	gmCellIncX;
    SHORT	gmCellIncY;
} GLYPHMETRICS, *LPGLYPHMETRICS;


#define GGO_METRICS         0
#define GGO_BITMAP          1
#define GGO_NATIVE          2
#define GGO_BEZIER          3
#define GGO_GRAY2_BITMAP    4
#define GGO_GRAY4_BITMAP    5
#define GGO_GRAY8_BITMAP    6
#define GGO_GLYPH_INDEX     0x80
#define GGO_UNHINTED        0x100

#ifdef __WINESRC__
#define WINE_GGO_GRAY16_BITMAP 0x10
#define WINE_GGO_HRGB_BITMAP   0x11
#define WINE_GGO_HBGR_BITMAP   0x12
#define WINE_GGO_VRGB_BITMAP   0x13
#define WINE_GGO_VBGR_BITMAP   0x14
#define WINE_GGO_NO_SCALE      0x1000
#endif

typedef struct
{
    WORD    fract;
    SHORT   value;
} FIXED;

typedef struct tagPOINTFX
{
	FIXED x;
	FIXED y;
} POINTFX, *LPPOINTFX;

typedef struct tagTTPOLYCURVE
{
	WORD wType;
	WORD cpfx;
	POINTFX apfx[1];
} TTPOLYCURVE, *LPTTPOLYCURVE;

typedef struct tagTTPOLYGONHEADER
{
	DWORD cb;
	DWORD dwType;
	POINTFX pfxStart;
} TTPOLYGONHEADER, *LPTTPOLYGONHEADER;

typedef struct
{
     FIXED  eM11;
     FIXED  eM12;
     FIXED  eM21;
     FIXED  eM22;
} MAT2, *LPMAT2;

  /* for GetCharABCWidths() */
typedef struct
{
    INT   abcA;
    UINT  abcB;
    INT   abcC;
} ABC, *PABC, *LPABC;


  /* for GetCharacterPlacement () */

#define GCP_DBCS          0x0001
#define GCP_REORDER       0x0002
#define GCP_USEKERNING    0x0008
#define GCP_GLYPHSHAPE    0x0010
#define GCP_LIGATE        0x0020
#define GCP_DIACRITIC     0x0100
#define GCP_KASHIDA       0x0200
#define GCP_ERROR         0x8000
#define FLI_MASK          0x103b
#define GCP_JUSTIFY         __MSABI_LONG(0x00010000)
#define FLI_GLYPHS          __MSABI_LONG(0x00040000)
#define GCP_CLASSIN         __MSABI_LONG(0x00080000)
#define GCP_MAXEXTENT       __MSABI_LONG(0x00100000)
#define GCP_JUSTIFYIN       __MSABI_LONG(0x00200000)
#define GCP_DISPLAYZWG      __MSABI_LONG(0x00400000)
#define GCP_SYMSWAPOFF      __MSABI_LONG(0x00800000)
#define GCP_NUMERICOVERRIDE __MSABI_LONG(0x01000000)
#define GCP_NEUTRALOVERRIDE __MSABI_LONG(0x02000000)
#define GCP_NUMERICSLATIN   __MSABI_LONG(0x04000000)
#define GCP_NUMERICSLOCAL   __MSABI_LONG(0x08000000)

#define GCPCLASS_LATIN                     1
#define GCPCLASS_HEBREW                    2
#define GCPCLASS_ARABIC                    3
#define GCPCLASS_NEUTRAL                   4
#define GCPCLASS_LOCALNUMBER               5
#define GCPCLASS_LATINNUMBER               6
#define GCPCLASS_LATINNUMERICTERMINATOR    7
#define GCPCLASS_LATINNUMERICSEPARATOR     8
#define GCPCLASS_NUMERICSEPARATOR          9
#define GCPCLASS_PREBOUNDLTR               0x80
#define GCPCLASS_PREBOUNDRTL               0x40
#define GCPCLASS_POSTBOUNDLTR              0x20
#define GCPCLASS_POSTBOUNDRTL              0x10

#define GCPGLYPH_LINKBEFORE                0x8000
#define GCPGLYPH_LINKAFTER                 0x4000


typedef struct tagGCP_RESULTSA{
    DWORD  lStructSize;
    LPSTR  lpOutString;
    UINT   *lpOrder;
    INT    *lpDx;
    INT    *lpCaretPos;
    LPSTR  lpClass;
    LPWSTR lpGlyphs;
    UINT   nGlyphs;
    UINT   nMaxFit;
} GCP_RESULTSA, *LPGCP_RESULTSA;

typedef struct tagGCP_RESULTSW
{
    DWORD  lStructSize;
    LPWSTR lpOutString;
    UINT   *lpOrder;
    INT    *lpDx;
    INT    *lpCaretPos;
    LPSTR  lpClass;
    LPWSTR lpGlyphs;
    UINT   nGlyphs;
    UINT   nMaxFit;
} GCP_RESULTSW, *LPGCP_RESULTSW;

DECL_WINELIB_TYPE_AW(GCP_RESULTS)
DECL_WINELIB_TYPE_AW(LPGCP_RESULTS)

  /* Rasterizer status */
typedef struct
{
    SHORT nSize;
    SHORT wFlags;
    SHORT nLanguageID;
} RASTERIZER_STATUS, *LPRASTERIZER_STATUS;

#define TT_AVAILABLE        0x0001
#define TT_ENABLED          0x0002

#define TT_PRIM_LINE    1
#define TT_PRIM_QSPLINE 2
#define TT_PRIM_CSPLINE 3
#define TT_POLYGON_TYPE 24

  /* OpenGL defines */
typedef struct {
  FLOAT      x;
  FLOAT      y;
} POINTFLOAT, *PPOINTFLOAT;

typedef struct {
  FLOAT      gmfBlackBoxX;
  FLOAT      gmfBlackBoxY;
  POINTFLOAT gmfptGlyphOrigin;
  FLOAT      gmfCellIncX;
  FLOAT      gmfCellIncY;
} GLYPHMETRICSFLOAT, *PGLYPHMETRICSFLOAT, *LPGLYPHMETRICSFLOAT;

typedef struct {
  WORD  nSize;
  WORD  nVersion;
  DWORD dwFlags;
  BYTE  iPixelType;
  BYTE  cColorBits;
  BYTE  cRedBits;
  BYTE  cRedShift;
  BYTE  cGreenBits;
  BYTE  cGreenShift;
  BYTE  cBlueBits;
  BYTE  cBlueShift;
  BYTE  cAlphaBits;
  BYTE  cAlphaShift;
  BYTE  cAccumBits;
  BYTE  cAccumRedBits;
  BYTE  cAccumGreenBits;
  BYTE  cAccumBlueBits;
  BYTE  cAccumAlphaBits;
  BYTE  cDepthBits;
  BYTE  cStencilBits;
  BYTE  cAuxBuffers;
  BYTE  iLayerPlane;
  BYTE  bReserved;
  COLORREF crTransparent;
} LAYERPLANEDESCRIPTOR, *PLAYERPLANEDESCRIPTOR, *LPLAYERPLANEDESCRIPTOR;

/* Get/SetSystemPaletteUse() values */
#define SYSPAL_ERROR        0
#define SYSPAL_STATIC       1
#define SYSPAL_NOSTATIC     2
#define SYSPAL_NOSTATIC256  3
    
#ifndef _PALETTEENTRY_DEFINED
#define _PALETTEENTRY_DEFINED
typedef struct tagPALETTEENTRY
{
	BYTE peRed, peGreen, peBlue, peFlags;
} PALETTEENTRY, *PPALETTEENTRY, *LPPALETTEENTRY;
#endif

/* Logical palette entry flags */
#define PC_RESERVED     0x01
#define PC_EXPLICIT     0x02
#define PC_NOCOLLAPSE   0x04

#ifndef _LOGPALETTE_DEFINED
#define _LOGPALETTE_DEFINED
typedef struct tagLOGPALETTE
{
    WORD           palVersion;
    WORD           palNumEntries;
    PALETTEENTRY   palPalEntry[1];
} LOGPALETTE, *PLOGPALETTE, *LPLOGPALETTE, *NPLOGPALETTE;
#endif

  /* Pens */

typedef struct
{
    UINT     lopnStyle;
    POINT    lopnWidth;
    COLORREF lopnColor;
} LOGPEN, *LPLOGPEN;


typedef struct tagEXTLOGPEN
{
    DWORD    elpPenStyle;
    DWORD    elpWidth;
    UINT     elpBrushStyle;
    COLORREF elpColor;
    ULONG_PTR elpHatch;
    DWORD elpNumEntries;
    DWORD elpStyleEntry[1];
} EXTLOGPEN, *PEXTLOGPEN, *NPEXTLOGPEN, *LPEXTLOGPEN;

#define PS_SOLID         0x00000000
#define PS_DASH          0x00000001
#define PS_DOT           0x00000002
#define PS_DASHDOT       0x00000003
#define PS_DASHDOTDOT    0x00000004
#define PS_NULL          0x00000005
#define PS_INSIDEFRAME   0x00000006
#define PS_USERSTYLE     0x00000007
#define PS_ALTERNATE     0x00000008
#define PS_STYLE_MASK    0x0000000f

#define PS_ENDCAP_ROUND  0x00000000
#define PS_ENDCAP_SQUARE 0x00000100
#define PS_ENDCAP_FLAT   0x00000200
#define PS_ENDCAP_MASK   0x00000f00

#define PS_JOIN_ROUND    0x00000000
#define PS_JOIN_BEVEL    0x00001000
#define PS_JOIN_MITER    0x00002000
#define PS_JOIN_MASK     0x0000f000

#define PS_COSMETIC      0x00000000
#define PS_GEOMETRIC     0x00010000
#define PS_TYPE_MASK     0x000f0000

  /* Regions */

#define ERROR             0
#define NULLREGION        1
#define SIMPLEREGION      2
#define COMPLEXREGION     3
#define RGN_ERROR         ERROR

#define RGN_AND           1
#define RGN_OR            2
#define RGN_XOR           3
#define RGN_DIFF          4
#define RGN_COPY          5
#define RGN_MIN           RGN_AND
#define RGN_MAX           RGN_COPY

#define SYSRGN            4

  /* Device contexts */

  /* Polygon modes */
#define ALTERNATE         1
#define WINDING           2
#define POLYFILL_LAST     2

/* Background modes */
/* Apparently some broken svr4 includes define TRANSPARENT */
#undef TRANSPARENT
#define TRANSPARENT       1
#define OPAQUE            2
#define BKMODE_LAST       2

  /* Graphics Modes */
#define GM_COMPATIBLE     1
#define GM_ADVANCED       2
#define GM_LAST           2

  /* Arc direction modes */
#define AD_COUNTERCLOCKWISE 1
#define AD_CLOCKWISE        2

  /* Map modes */
#define MM_TEXT		  1
#define MM_LOMETRIC	  2
#define MM_HIMETRIC	  3
#define MM_LOENGLISH	  4
#define MM_HIENGLISH	  5
#define MM_TWIPS	  6
#define MM_ISOTROPIC	  7
#define MM_ANISOTROPIC	  8

#define MM_MIN            MM_TEXT
#define MM_MAX            MM_ANISOTROPIC
#define MM_MAX_FIXEDSCALE MM_TWIPS

  /* Coordinate modes */
#define ABSOLUTE          1
#define RELATIVE          2

  /* Flood fill modes */
#define FLOODFILLBORDER   0
#define FLOODFILLSURFACE  1

  /* Device parameters for GetDeviceCaps() */
#define DRIVERVERSION     0
#define TECHNOLOGY        2
#define HORZSIZE          4
#define VERTSIZE          6
#define HORZRES           8
#define VERTRES           10
#define BITSPIXEL         12
#define PLANES            14
#define NUMBRUSHES        16
#define NUMPENS           18
#define NUMMARKERS        20
#define NUMFONTS          22
#define NUMCOLORS         24
#define PDEVICESIZE       26
#define CURVECAPS         28
#define LINECAPS          30
#define POLYGONALCAPS     32
#define TEXTCAPS          34
#define CLIPCAPS          36
#define RASTERCAPS        38
#define ASPECTX           40
#define ASPECTY           42
#define ASPECTXY          44
#define LOGPIXELSX        88
#define LOGPIXELSY        90
#define CAPS1             94
#define SIZEPALETTE       104
#define NUMRESERVED       106
#define COLORRES          108

#define PHYSICALWIDTH     110
#define PHYSICALHEIGHT    111
#define PHYSICALOFFSETX   112
#define PHYSICALOFFSETY   113
#define SCALINGFACTORX    114
#define SCALINGFACTORY    115
#define VREFRESH          116
#define DESKTOPVERTRES    117
#define DESKTOPHORZRES    118
#define BLTALIGNMENT      119
#define SHADEBLENDCAPS    120
#define COLORMGMTCAPS     121

/* TECHNOLOGY */
#define DT_PLOTTER        0
#define DT_RASDISPLAY     1
#define DT_RASPRINTER     2
#define DT_RASCAMERA      3
#define DT_CHARSTREAM     4
#define DT_METAFILE       5
#define DT_DISPFILE       6

/* CURVECAPS */
#define CC_NONE           0x0000
#define CC_CIRCLES        0x0001
#define CC_PIE            0x0002
#define CC_CHORD          0x0004
#define CC_ELLIPSES       0x0008
#define CC_WIDE           0x0010
#define CC_STYLED         0x0020
#define CC_WIDESTYLED     0x0040
#define CC_INTERIORS      0x0080
#define CC_ROUNDRECT      0x0100

/* LINECAPS */
#define LC_NONE           0x0000
#define LC_POLYLINE       0x0002
#define LC_MARKER         0x0004
#define LC_POLYMARKER     0x0008
#define LC_WIDE           0x0010
#define LC_STYLED         0x0020
#define LC_WIDESTYLED     0x0040
#define LC_INTERIORS      0x0080

/* POLYGONALCAPS */
#define PC_NONE           0x0000
#define PC_POLYGON        0x0001
#define PC_RECTANGLE      0x0002
#define PC_WINDPOLYGON    0x0004
#define PC_TRAPEZOID      0x0004
#define PC_SCANLINE       0x0008
#define PC_WIDE           0x0010
#define PC_STYLED         0x0020
#define PC_WIDESTYLED     0x0040
#define PC_INTERIORS      0x0080
#define PC_POLYPOLYGON    0x0100
#define PC_PATHS          0x0200

/* TEXTCAPS */
#define TC_OP_CHARACTER   0x0001
#define TC_OP_STROKE      0x0002
#define TC_CP_STROKE      0x0004
#define TC_CR_90          0x0008
#define TC_CR_ANY         0x0010
#define TC_SF_X_YINDEP    0x0020
#define TC_SA_DOUBLE      0x0040
#define TC_SA_INTEGER     0x0080
#define TC_SA_CONTIN      0x0100
#define TC_EA_DOUBLE      0x0200
#define TC_IA_ABLE        0x0400
#define TC_UA_ABLE        0x0800
#define TC_SO_ABLE        0x1000
#define TC_RA_ABLE        0x2000
#define TC_VA_ABLE        0x4000
#define TC_RESERVED       0x8000
#define TC_SCROLLBLT      0x00010000

/* CLIPCAPS */
#define CP_NONE           0x0000
#define CP_RECTANGLE      0x0001
#define CP_REGION         0x0002

/* RASTERCAPS */
#define RC_NONE           0x0000
#define RC_BITBLT         0x0001
#define RC_BANDING        0x0002
#define RC_SCALING        0x0004
#define RC_BITMAP64       0x0008
#define RC_GDI20_OUTPUT   0x0010
#define RC_GDI20_STATE    0x0020
#define RC_SAVEBITMAP     0x0040
#define RC_DI_BITMAP      0x0080
#define RC_PALETTE        0x0100
#define RC_DIBTODEV       0x0200
#define RC_BIGFONT        0x0400
#define RC_STRETCHBLT     0x0800
#define RC_FLOODFILL      0x1000
#define RC_STRETCHDIB     0x2000
#define RC_OP_DX_OUTPUT   0x4000
#define RC_DEVBITS        0x8000

/* CAPS1 */
#define C1_TRANSPARENT    0x0001
#define TC_TT_ABLE        0x0002
#define C1_TT_CR_ANY      0x0004
#define C1_EMF_COMPLIANT  0x0008
#define C1_DIBENGINE      0x0010
#define C1_GAMMA_RAMP     0x0040
#define C1_REINIT_ABLE    0x0080
#define C1_GLYPH_INDEX    0x0100
#define C1_BIT_PACKED     0x0200
#define C1_BYTE_PACKED    0x0400
#define C1_COLORCURSOR    0x0800
#define C1_CMYK_ABLE      0x1000
#define C1_SLOW_CARD      0x2000

/* SHADEBLENDCAPS */
#define SB_NONE           0x0000
#define SB_CONST_ALPHA    0x0001
#define SB_PIXEL_ALPHA    0x0002
#define SB_PREMULT_ALPHA  0x0004
#define SB_GRAD_RECT      0x0010
#define SB_GRAD_TRI       0x0020

  /* Device-independent bitmaps */

typedef struct tagRGBQUAD {
  BYTE rgbBlue;
  BYTE rgbGreen;
  BYTE rgbRed;
  BYTE rgbReserved;
} RGBQUAD, *LPRGBQUAD;

typedef struct tagRGBTRIPLE {
  BYTE rgbtBlue;
  BYTE rgbtGreen;
  BYTE rgbtRed;
} RGBTRIPLE;

#include <pshpack2.h>
typedef struct
{
    WORD    bfType;
    DWORD   bfSize;
    WORD    bfReserved1;
    WORD    bfReserved2;
    DWORD   bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER, *LPBITMAPFILEHEADER;
#include <poppack.h>

#define MAKEPOINTS(l)  (*((POINTS *)&(l)))

typedef struct
{
    DWORD 	biSize;
    LONG  	biWidth;
    LONG  	biHeight;
    WORD 	biPlanes;
    WORD 	biBitCount;
    DWORD 	biCompression;
    DWORD 	biSizeImage;
    LONG  	biXPelsPerMeter;
    LONG  	biYPelsPerMeter;
    DWORD 	biClrUsed;
    DWORD 	biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER, *LPBITMAPINFOHEADER;

typedef struct
{
    DWORD        bV4Size;
    LONG         bV4Width;
    LONG         bV4Height;
    WORD         bV4Planes;
    WORD         bV4BitCount;
    DWORD        bV4V4Compression;
    DWORD        bV4SizeImage;
    LONG         bV4XPelsPerMeter;
    LONG         bV4YPelsPerMeter;
    DWORD        bV4ClrUsed;
    DWORD        bV4ClrImportant;
    DWORD        bV4RedMask;
    DWORD        bV4GreenMask;
    DWORD        bV4BlueMask;
    DWORD        bV4AlphaMask;
    DWORD        bV4CSType;
    CIEXYZTRIPLE bV4Endpoints;
    DWORD        bV4GammaRed;
    DWORD        bV4GammaGreen;
    DWORD        bV4GammaBlue;
} BITMAPV4HEADER, *PBITMAPV4HEADER;

typedef struct {
    DWORD        bV5Size;
    LONG         bV5Width;
    LONG         bV5Height;
    WORD         bV5Planes;
    WORD         bV5BitCount;
    DWORD        bV5Compression;
    DWORD        bV5SizeImage;
    LONG         bV5XPelsPerMeter;
    LONG         bV5YPelsPerMeter;
    DWORD        bV5ClrUsed;
    DWORD        bV5ClrImportant;
    DWORD        bV5RedMask;
    DWORD        bV5GreenMask;
    DWORD        bV5BlueMask;
    DWORD        bV5AlphaMask;
    DWORD        bV5CSType;
    CIEXYZTRIPLE bV5Endpoints;
    DWORD        bV5GammaRed;
    DWORD        bV5GammaGreen;
    DWORD        bV5GammaBlue;
    DWORD        bV5Intent;
    DWORD        bV5ProfileData;
    DWORD        bV5ProfileSize;
    DWORD        bV5Reserved;
} BITMAPV5HEADER, *LPBITMAPV5HEADER, *PBITMAPV5HEADER;

#define PROFILE_LINKED   0x4c494e4b     /* 'LINK' */
#define PROFILE_EMBEDDED 0x4d424544     /* 'MBED' */


  /* biCompression */
#define BI_RGB           0
#define BI_RLE8          1
#define BI_RLE4          2
#define BI_BITFIELDS     3
#define BI_JPEG          4
#define BI_PNG           5

typedef struct tagBITMAPINFO
{
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD          bmiColors[1];
} BITMAPINFO, *PBITMAPINFO, *LPBITMAPINFO;

typedef struct
{
    DWORD   bcSize;
    WORD    bcWidth;
    WORD    bcHeight;
    WORD    bcPlanes;
    WORD    bcBitCount;
} BITMAPCOREHEADER, *PBITMAPCOREHEADER, *LPBITMAPCOREHEADER;

typedef struct
{
    BITMAPCOREHEADER bmciHeader;
    RGBTRIPLE        bmciColors[1];
} BITMAPCOREINFO, *PBITMAPCOREINFO, *LPBITMAPCOREINFO;

#define DIB_RGB_COLORS   0
#define DIB_PAL_COLORS   1
#define CBM_INIT         4

typedef struct
{
	BITMAP		dsBm;
	BITMAPINFOHEADER	dsBmih;
	DWORD			dsBitfields[3];
	HANDLE		dshSection;
	DWORD			dsOffset;
} DIBSECTION, *PDIBSECTION, *LPDIBSECTION;

  /* Stock GDI objects for GetStockObject() */

#define WHITE_BRUSH	    0
#define LTGRAY_BRUSH	    1
#define GRAY_BRUSH	    2
#define DKGRAY_BRUSH	    3
#define BLACK_BRUSH	    4
#define NULL_BRUSH	    5
#define HOLLOW_BRUSH	    5
#define WHITE_PEN	    6
#define BLACK_PEN	    7
#define NULL_PEN	    8
#define OEM_FIXED_FONT	    10
#define ANSI_FIXED_FONT     11
#define ANSI_VAR_FONT	    12
#define SYSTEM_FONT	    13
#define DEVICE_DEFAULT_FONT 14
#define DEFAULT_PALETTE     15
#define SYSTEM_FIXED_FONT   16
#define DEFAULT_GUI_FONT    17
#define DC_BRUSH            18
#define DC_PEN              19

#define STOCK_LAST          19

#define CLR_INVALID         0xffffffff

typedef USHORT COLOR16;

typedef struct _TRIVERTEX
{
    LONG    x;
    LONG    y;
    COLOR16 Red;
    COLOR16 Green;
    COLOR16 Blue;
    COLOR16 Alpha;
} TRIVERTEX, *PTRIVERTEX, *LPTRIVERTEX;

typedef struct _GRADIENT_TRIANGLE
{
    ULONG Vertex1;
    ULONG Vertex2;
    ULONG Vertex3;
} GRADIENT_TRIANGLE, *PGRADIENT_TRIANGLE, *LPGRADIENT_TRIANGLE;

typedef struct _GRADIENT_RECT
{
    ULONG UpperLeft;
    ULONG LowerRight;
} GRADIENT_RECT, *PGRADIENT_RECT, *LPGRADIENT_RECT;

#define AC_SRC_OVER  0x00
#define AC_SRC_ALPHA 0x01

typedef struct _BLENDFUNCTION
{
    BYTE BlendOp;
    BYTE BlendFlags;
    BYTE SourceConstantAlpha;
    BYTE AlphaFormat;
} BLENDFUNCTION, *PBLENDFUNCTION;

#define GRADIENT_FILL_RECT_H      0x00000000
#define GRADIENT_FILL_RECT_V      0x00000001
#define GRADIENT_FILL_TRIANGLE    0x00000002
#define GRADIENT_FILL_OP_FLAG     0x000000ff


/* Metafile header structure */
#include <pshpack2.h>
typedef struct
{
    WORD       mtType;
    WORD       mtHeaderSize;
    WORD       mtVersion;
    DWORD      mtSize;
    WORD       mtNoObjects;
    DWORD      mtMaxRecord;
    WORD       mtNoParameters;
} METAHEADER, *PMETAHEADER, *LPMETAHEADER;
#include <poppack.h>

/* Metafile typical record structure */
typedef struct
{
    DWORD      rdSize;
    WORD       rdFunction;
    WORD       rdParm[1];
} METARECORD, *PMETARECORD, *LPMETARECORD;

/* Handle table structure */

typedef struct
{
    HGDIOBJ objectHandle[1];
} HANDLETABLE, *PHANDLETABLE, *LPHANDLETABLE;


/* Clipboard metafile picture structure */
typedef struct
{
    LONG       mm;
    LONG       xExt;
    LONG       yExt;
    HMETAFILE  hMF;
} METAFILEPICT, *LPMETAFILEPICT;


/* Metafile functions */
#define META_SETBKCOLOR              0x0201
#define META_SETBKMODE               0x0102
#define META_SETMAPMODE              0x0103
#define META_SETROP2                 0x0104
#define META_SETRELABS               0x0105
#define META_SETPOLYFILLMODE         0x0106
#define META_SETSTRETCHBLTMODE       0x0107
#define META_SETTEXTCHAREXTRA        0x0108
#define META_SETTEXTCOLOR            0x0209
#define META_SETTEXTJUSTIFICATION    0x020A
#define META_SETWINDOWORG            0x020B
#define META_SETWINDOWEXT            0x020C
#define META_SETVIEWPORTORG          0x020D
#define META_SETVIEWPORTEXT          0x020E
#define META_OFFSETWINDOWORG         0x020F
#define META_SCALEWINDOWEXT          0x0410
#define META_OFFSETVIEWPORTORG       0x0211
#define META_SCALEVIEWPORTEXT        0x0412
#define META_LINETO                  0x0213
#define META_MOVETO                  0x0214
#define META_EXCLUDECLIPRECT         0x0415
#define META_INTERSECTCLIPRECT       0x0416
#define META_ARC                     0x0817
#define META_ELLIPSE                 0x0418
#define META_FLOODFILL               0x0419
#define META_PIE                     0x081A
#define META_RECTANGLE               0x041B
#define META_ROUNDRECT               0x061C
#define META_PATBLT                  0x061D
#define META_SAVEDC                  0x001E
#define META_SETPIXEL                0x041F
#define META_OFFSETCLIPRGN           0x0220
#define META_TEXTOUT                 0x0521
#define META_BITBLT                  0x0922
#define META_STRETCHBLT              0x0B23
#define META_POLYGON                 0x0324
#define META_POLYLINE                0x0325
#define META_ESCAPE                  0x0626
#define META_RESTOREDC               0x0127
#define META_FILLREGION              0x0228
#define META_FRAMEREGION             0x0429
#define META_INVERTREGION            0x012A
#define META_PAINTREGION             0x012B
#define META_SELECTCLIPREGION        0x012C
#define META_SELECTOBJECT            0x012D
#define META_SETTEXTALIGN            0x012E
#define META_DRAWTEXT                0x062F
#define META_CHORD                   0x0830
#define META_SETMAPPERFLAGS          0x0231
#define META_EXTTEXTOUT              0x0A32
#define META_SETDIBTODEV             0x0D33
#define META_SELECTPALETTE           0x0234
#define META_REALIZEPALETTE          0x0035
#define META_ANIMATEPALETTE          0x0436
#define META_SETPALENTRIES           0x0037
#define META_POLYPOLYGON             0x0538
#define META_RESIZEPALETTE           0x0139
#define META_DIBBITBLT               0x0940
#define META_DIBSTRETCHBLT           0x0B41
#define META_DIBCREATEPATTERNBRUSH   0x0142
#define META_STRETCHDIB              0x0F43
#define META_EXTFLOODFILL            0x0548
#define META_RESETDC                 0x014C
#define META_STARTDOC                0x014D
#define META_STARTPAGE               0x004F
#define META_ENDPAGE                 0x0050
#define META_ABORTDOC                0x0052
#define META_ENDDOC                  0x005E
#define META_DELETEOBJECT            0x01F0
#define META_CREATEPALETTE           0x00F7
#define META_CREATEBRUSH             0x00F8
#define META_CREATEPATTERNBRUSH      0x01F9
#define META_CREATEPENINDIRECT       0x02FA
#define META_CREATEFONTINDIRECT      0x02FB
#define META_CREATEBRUSHINDIRECT     0x02FC
#define META_CREATEBITMAPINDIRECT    0x02FD
#define META_CREATEBITMAP            0x06FE
#define META_CREATEREGION            0x06FF
#define META_UNKNOWN                 0x0529  /* FIXME: unknown meta magic */

typedef INT (CALLBACK *MFENUMPROC)(HDC,HANDLETABLE*,METARECORD*,
                                       INT,LPARAM);

/* enhanced metafile structures and functions */

/* note that ENHMETAHEADER is just a particular kind of ENHMETARECORD,
   ie. the header is just the first record in the metafile */
typedef struct {
    DWORD iType;
    DWORD nSize;
    RECTL rclBounds;
    RECTL rclFrame;
    DWORD dSignature;
    DWORD nVersion;
    DWORD nBytes;
    DWORD nRecords;
    WORD  nHandles;
    WORD  sReserved;
    DWORD nDescription;
    DWORD offDescription;
    DWORD nPalEntries;
    SIZEL szlDevice;
    SIZEL szlMillimeters;
    DWORD cbPixelFormat;
    DWORD offPixelFormat;
    DWORD bOpenGL;
    SIZEL szlMicrometers;
} ENHMETAHEADER, *PENHMETAHEADER, *LPENHMETAHEADER;

typedef struct {
    DWORD iType;
    DWORD nSize;
    DWORD dParm[1];
} ENHMETARECORD, *LPENHMETARECORD;

typedef struct {
    DWORD iType;
    DWORD nSize;
} EMR, *PEMR;

typedef struct {
    POINTL ptlReference;
    DWORD  nChars;
    DWORD  offString;
    DWORD  fOptions;
    RECTL  rcl;
    DWORD  offDx;
} EMRTEXT, *PEMRTEXT;

typedef struct {
    EMR emr;
} EMRABORTPATH,      *PEMRABORTPATH,
  EMRBEGINPATH,      *PEMRBEGINPATH,
  EMRENDPATH,        *PEMRENDPATH,
  EMRCLOSEFIGURE,    *PEMRCLOSEFIGURE,
  EMRFLATTENPATH,    *PEMRFLATTENPATH,
  EMRWIDENPATH,      *PEMRWIDENPATH,
  EMRSETMETARGN,     *PEMRSETMETARGN,
  EMRSAVEDC,         *PEMRSAVEDC,
  EMRREALIZEPALETTE, *PEMRREALIZEPALETTE;

typedef struct {
    EMR    emr;
    POINTL ptlCenter;
    DWORD  nRadius;
    FLOAT  eStartAngle;
    FLOAT  eSweepAngle;
} EMRANGLEARC, *PEMRANGLEARC;

typedef struct {
    EMR    emr;
    RECTL  rclBox;
    POINTL ptlStart;
    POINTL ptlEnd;
} EMRARC,   *PEMRARC,
  EMRARCTO, *PEMRARCTO,
  EMRCHORD, *PEMRCHORD,
  EMRPIE,   *PEMRPIE;

typedef struct {
    EMR      emr;
    RECTL    rclBounds;
    LONG     xDest;
    LONG     yDest;
    LONG     cxDest;
    LONG     cyDest;
    DWORD    dwRop;
    LONG     xSrc;
    LONG     ySrc;
    XFORM    xformSrc;
    COLORREF crBkColorSrc;
    DWORD    iUsageSrc;
    DWORD    offBmiSrc;
    DWORD    cbBmiSrc;
    DWORD    offBitsSrc;
    DWORD    cbBitsSrc;
} EMRBITBLT, *PEMRBITBLT;

typedef struct {
    EMR        emr;
    DWORD      ihBrush;
    LOGBRUSH32 lb;
} EMRCREATEBRUSHINDIRECT, *PEMRCREATEBRUSHINDIRECT;

typedef struct {
    EMR            emr;
    DWORD          ihCS;
    LOGCOLORSPACEA lcs;
} EMRCREATECOLORSPACE, *PEMRCREATECOLORSPACE;

typedef struct {
  EMR            emr;
  DWORD          ihCS;
  LOGCOLORSPACEW lcs;
  DWORD          dwFlags;
  DWORD          cbData;
  BYTE           Data[1];
} EMRCREATECOLORSPACEW, *PEMRCREATECOLORSPACEW;

typedef struct {
    EMR   emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD offBits;
    DWORD cbBits;
} EMRCREATEDIBPATTERNBRUSHPT, *PEMRCREATEDIBPATTERNBRUSHPT;

typedef struct {
    EMR   emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD offBits;
    DWORD cbBits;
} EMRCREATEMONOBRUSH, *PEMRCREATEMONOBRUSH;

typedef struct {
    EMR        emr;
    DWORD      ihPal;
    LOGPALETTE lgpl;
} EMRCREATEPALETTE, *PEMRCREATEPALETTE;

typedef struct {
    EMR    emr;
    DWORD  ihPen;
    LOGPEN lopn;
} EMRCREATEPEN, *PEMRCREATEPEN;

typedef struct {
    EMR           emr;
    DWORD         ihCS;
} EMRDELETECOLORSPACE, *PEMRDELETECOLORSPACE,
  EMRSELECTCOLORSPACE, *PEMRSELECTCOLORSPACE,
  EMRSETCOLORSPACE,    *PEMRSETCOLORSPACE;

typedef struct {
    EMR   emr;
    DWORD ihObject;
} EMRDELETEOBJECT, *PEMRDELETEOBJECT,
  EMRSELECTOBJECT, *PEMRSELECTOBJECT;

typedef struct {
    EMR   emr;
    RECTL rclBox;
} EMRELLIPSE,   *PEMRELLIPSE,
  EMRRECTANGLE, *PEMRRECTANGLE;

typedef struct {
    EMR   emr;
    DWORD nPalEntries;
    DWORD offPalEntries;
    DWORD nSizeLast;
} EMREOF, *PEMREOF;

typedef struct {
    EMR   emr;
    RECTL rclClip;
} EMREXCLUDECLIPRECT,   *PEMREXCLUDECLIPRECT,
  EMRINTERSECTCLIPRECT, *PEMRINTERSECTCLIPRECT;

typedef struct {
    EMR         emr;
    DWORD       ihFont;
    EXTLOGFONTW elfw;
} EMREXTCREATEFONTINDIRECTW, *PEMREXTCREATEFONTINDIRECTW;

typedef struct {
    EMR       emr;
    DWORD     ihPen;
    DWORD     offBmi;
    DWORD     cbBmi;
    DWORD     offBits;
    DWORD     cbBits;
    EXTLOGPEN elp;
} EMREXTCREATEPEN, *PEMREXTCREATEPEN;

typedef struct {
    EMR      emr;
    POINTL   ptlStart;
    COLORREF crColor;
    DWORD    iMode;
} EMREXTFLOODFILL, *PEMREXTFLOODFILL;

typedef struct {
    EMR   emr;
    DWORD cbRgnData;
    DWORD iMode;
    BYTE  RgnData[1];
} EMREXTSELECTCLIPRGN, *PEMREXTSELECTCLIPRGN;

typedef struct {
    EMR     emr;
    RECTL   rclBounds;
    DWORD   iGraphicsMode;
    FLOAT   exScale;
    FLOAT   eyScale;
    EMRTEXT emrtext;
} EMREXTTEXTOUTA, *PEMREXTTEXTOUTA,
  EMREXTTEXTOUTW, *PEMREXTTEXTOUTW;

typedef struct {
    EMR emr;
    RECTL rclBounds;
} EMRFILLPATH,          *PEMRFILLPATH,
  EMRSTROKEANDFILLPATH, *PEMRSTROKEANDFILLPATH,
  EMRSTROKEPATH,        *PEMRSTROKEPATH;

typedef struct {
    EMR   emr;
    RECTL rclBounds;
    DWORD cbRgnData;
    DWORD ihBrush;
    BYTE  RgnData[1];
} EMRFILLRGN, *PEMRFILLRGN;

typedef struct {
    DWORD dSignature;
    DWORD nVersion;
    DWORD cbData;
    DWORD offData;
} EMRFORMAT, *PEMRFORMAT;

typedef struct {
    EMR   emr;
    RECTL rclBounds;
    DWORD cbRgnData;
    DWORD ihBrush;
    SIZEL szlStroke;
    BYTE  RgnData[1];
} EMRFRAMERGN, *PEMRFRAMERGN;

typedef struct {
    EMR   emr;
    DWORD cbData;
    BYTE  Data[1];
} EMRGDICOMMENT, *PEMRGDICOMMENT;

typedef struct {
    EMR       emr;
    RECTL     rclBounds;
    DWORD     nVer;
    DWORD     nTri;
    ULONG     ulMode;
    TRIVERTEX Ver[1];
} EMRGRADIENTFILL, *PEMRGRADIENTFILL;

typedef struct {
    EMR   emr;
    RECTL rclBounds;
    DWORD cbRgnData;
    BYTE  RgnData[1];
} EMRINVERTRGN, *PEMRINVERTRGN,
  EMRPAINTRGN,  *PEMRPAINTRGN;

typedef struct {
    EMR    emr;
    POINTL ptl;
} EMRLINETO,   *PEMRLINETO,
  EMRMOVETOEX, *PEMRMOVETOEX;

typedef struct {
    EMR      emr;
    RECTL    rclBounds;
    LONG     xDest;
    LONG     yDest;
    LONG     cxDest;
    LONG     cyDest;
    DWORD    dwRop;
    LONG     xSrc;
    LONG     ySrc;
    XFORM    xformSrc;
    COLORREF crBkColorSrc;
    DWORD    iUsageSrc;
    DWORD    offBmiSrc;
    DWORD    cbBmiSrc;
    DWORD    offBitsSrc;
    DWORD    cbBitsSrc;
    LONG     xMask;
    LONG     yMask;
    DWORD    iUsageMask;
    DWORD    offBmiMask;
    DWORD    cbBmiMask;
    DWORD    offBitsMask;
    DWORD    cbBitsMask;
} EMRMASKBLT, *PEMRMASKBLT;

typedef struct {
    EMR   emr;
    XFORM xform;
    DWORD iMode;
} EMRMODIFYWORLDTRANSFORM, *PEMRMODIFYWORLDTRANSFORM;

typedef struct {
    EMR    emr;
    POINTL ptlOffset;
} EMROFFSETCLIPRGN, *PEMROFFSETCLIPRGN;

typedef struct {
    EMR      emr;
    RECTL    rclBounds;
    POINTL   aptlDest[3];
    LONG     xSrc;
    LONG     ySrc;
    LONG     cxSrc;
    LONG     cySrc;
    XFORM    xformSrc;
    COLORREF crBkColorSrc;
    DWORD    iUsageSrc;
    DWORD    offBmiSrc;
    DWORD    cbBmiSrc;
    DWORD    offBitsSrc;
    DWORD    cbBitsSrc;
    LONG     xMask;
    LONG     yMask;
    DWORD    iUsageMask;
    DWORD    offBmiMask;
    DWORD    cbBmiMask;
    DWORD    offBitsMask;
    DWORD    cbBitsMask;
} EMRPLGBLT, *PEMRPLGBLT;

typedef struct {
    EMR    emr;
    RECTL  rclBounds;
    DWORD  cptl;
    POINTL aptl[1];
} EMRPOLYLINE,     *PEMRPOLYLINE,
  EMRPOLYBEZIER,   *PEMRPOLYBEZIER,
  EMRPOLYGON,      *PEMRPOLYGON,
  EMRPOLYBEZIERTO, *PEMRPOLYBEZIERTO,
  EMRPOLYLINETO,   *PEMRPOLYLINETO;

typedef struct {
    EMR    emr;
    RECTL  rclBounds;
    DWORD  cpts;
    POINTS apts[1];
} EMRPOLYLINE16,     *PEMRPOLYLINE16,
  EMRPOLYBEZIER16,   *PEMRPOLYBEZIER16,
  EMRPOLYGON16,      *PEMRPOLYGON16,
  EMRPOLYBEZIERTO16, *PEMRPOLYBEZIERTO16,
  EMRPOLYLINETO16,   *PEMRPOLYLINETO16;

typedef struct {
    EMR    emr;
    RECTL  rclBounds;
    DWORD  cpts;
    POINTS apts[1];
    BYTE   abTypes[1];
} EMRPOLYDRAW16, *PEMRPOLYDRAW16;

typedef struct {
    EMR     emr;
    RECTL   rclBounds;
    DWORD   nPolys;
    DWORD   cpts;
    DWORD   aPolyCounts[1];
    POINTS  apts[1];
} EMRPOLYPOLYLINE16, *PEMRPOLYPOLYLINE16,
  EMRPOLYPOLYGON16,  *PEMRPOLYPOLYGON16;

typedef struct {
    EMR    emr;
    RECTL  rclBounds;
    DWORD  cptl;
    POINTL aptl[1];
    BYTE   abTypes[1];
} EMRPOLYDRAW, *PEMRPOLYDRAW;

typedef struct {
    EMR     emr;
    RECTL   rclBounds;
    DWORD   nPolys;
    DWORD   cptl;
    DWORD   aPolyCounts[1];
    POINTL  aptl[1];
} EMRPOLYPOLYLINE, *PEMRPOLYPOLYLINE,
  EMRPOLYPOLYGON,  *PEMRPOLYPOLYGON;

typedef struct {
    EMR     emr;
    RECTL   rclBounds;
    DWORD   iGraphicsMode;
    FLOAT   exScale;
    FLOAT   eyScale;
    LONG    cStrings;
    EMRTEXT aemrtext[1];
} EMRPOLYTEXTOUTA, *PEMRPOLYTEXTOUTA,
  EMRPOLYTEXTOUTW, *PEMRPOLYTEXTOUTW;

typedef struct {
    EMR   emr;
    DWORD ihPal;
    DWORD cEntries;
} EMRRESIZEPALETTE, *PEMRRESIZEPALETTE;

typedef struct {
    EMR  emr;
    LONG iRelative;
} EMRRESTOREDC, *PEMRRESTOREDC;

typedef struct {
    EMR   emr;
    RECTL rclBox;
    SIZEL szlCorner;
} EMRROUNDRECT, *PEMRROUNDRECT;

typedef struct {
    EMR  emr;
    LONG xNum;
    LONG xDenom;
    LONG yNum;
    LONG yDenom;
} EMRSCALEVIEWPORTEXTEX, *PEMRSCALEVIEWPORTEXTEX,
  EMRSCALEWINDOWEXTEX,   *PEMRSCALEWINDOWEXTEX;

typedef struct {
    EMR   emr;
    DWORD iMode;
} EMRSELECTCLIPPATH,    *PEMRSELECTCLIPPATH,
  EMRSETBKMODE,         *PEMRSETBKMODE,
  EMRSETMAPMODE,        *PEMRSETMAPMODE,
  EMRSETPOLYFILLMODE,   *PEMRSETPOLYFILLMODE,
  EMRSETROP2,           *PEMRSETROP2,
  EMRSETSTRETCHBLTMODE, *PEMRSETSTRETCHBLTMODE,
  EMRSETTEXTALIGN,      *PEMRSETTEXTALIGN,
  EMRSETICMMODE,        *PEMRSETICMMODE,
  EMRSETLAYOUT,         *PEMRSETLAYOUT;

typedef struct {
    EMR   emr;
    DWORD ihPal;
} EMRSELECTPALETTE, *PEMRSELECTPALETTE;

typedef struct {
    EMR   emr;
    DWORD iArcDirection;
} EMRSETARCDIRECTION, *PEMRSETARCDIRECTION;

typedef struct {
    EMR      emr;
    COLORREF crColor;
} EMRSETBKCOLOR,   *PEMRSETBKCOLOR,
  EMRSETTEXTCOLOR, *PEMRSETTEXTCOLOR;

typedef struct {
    EMR   emr;
    POINTL ptlOrigin;
} EMRSETBRUSHORGEX,    *PEMRSETBRUSHORGEX,
  EMRSETVIEWPORTORGEX, *PEMRSETVIEWPORTORGEX,
  EMRSETWINDOWORGEX,   *PEMRSETWINDOWORGEX;

typedef struct {
    EMR  emr;
    COLORADJUSTMENT ColorAdjustment;
} EMRSETCOLORADJUSTMENT, *PEMRSETCOLORADJUSTMENT;

typedef struct {
    EMR   emr;
    RECTL rclBounds;
    LONG  xDest;
    LONG  yDest;
    LONG  xSrc;
    LONG  ySrc;
    LONG  cxSrc;
    LONG  cySrc;
    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD offBitsSrc;
    DWORD cbBitsSrc;
    DWORD iUsageSrc;
    DWORD iStartScan;
    DWORD cScans;
} EMRSETDIBITSTODEVICE, *PEMRSETDIBITSTODEVICE;

typedef struct {
    EMR   emr;
    DWORD dwFlags;
} EMRSETMAPPERFLAGS, *PEMRSETMAPPERFLAGS;

typedef struct {
    EMR   emr;
    FLOAT eMiterLimit;
} EMRSETMITERLIMIT, *PEMRSETMITERLIMIT;

typedef struct {
    EMR          emr;
    DWORD        ihPal;
    DWORD        iStart;
    DWORD        cEntries;
    PALETTEENTRY aPalEntries[1];
} EMRSETPALETTEENTRIES, *PEMRSETPALETTEENTRIES;

typedef struct {
    EMR     emr;
    POINTL  ptlPixel;
    COLORREF crColor;
} EMRSETPIXELV, *PEMRSETPIXELV;

typedef struct {
    EMR   emr;
    SIZEL szlExtent;
} EMRSETVIEWPORTEXTEX, *PEMRSETVIEWPORTEXTEX,
  EMRSETWINDOWEXTEX,   *PEMRSETWINDOWEXTEX;

typedef struct {
    EMR   emr;
    XFORM xform;
} EMRSETWORLDTRANSFORM, *PEMRSETWORLDTRANSFORM;

typedef struct {
    EMR      emr;
    RECTL    rclBounds;
    LONG     xDest;
    LONG     yDest;
    LONG     cxDest;
    LONG     cyDest;
    DWORD    dwRop;
    LONG     xSrc;
    LONG     ySrc;
    XFORM    xformSrc;
    COLORREF crBkColorSrc;
    DWORD    iUsageSrc;
    DWORD    offBmiSrc;
    DWORD    cbBmiSrc;
    DWORD    offBitsSrc;
    DWORD    cbBitsSrc;
    LONG     cxSrc;
    LONG     cySrc;
} EMRSTRETCHBLT, *PEMRSTRETCHBLT;

typedef struct {
    EMR      emr;
    RECTL    rclBounds;
    LONG     xDest;
    LONG     yDest;
    LONG     cxDest;
    LONG     cyDest;
    DWORD    dwRop;
    LONG     xSrc;
    LONG     ySrc;
    XFORM    xformSrc;
    COLORREF crBkColorSrc;
    DWORD    iUsageSrc;
    DWORD    offBmiSrc;
    DWORD    cbBmiSrc;
    DWORD    offBitsSrc;
    DWORD    cbBitsSrc;
    LONG     cxSrc;
    LONG     cySrc;
} EMRALPHABLEND, *PEMRALPHABLEND;

typedef struct {
    EMR   emr;
    RECTL rclBounds;
    LONG  xDest;
    LONG  yDest;
    LONG  xSrc;
    LONG  ySrc;
    LONG  cxSrc;
    LONG  cySrc;
    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD offBitsSrc;
    DWORD cbBitsSrc;
    DWORD iUsageSrc;
    DWORD dwRop;
    LONG  cxDest;
    LONG  cyDest;
} EMRSTRETCHDIBITS, *PEMRSTRETCHDIBITS;

typedef struct {
    EMR                   emr;
    PIXELFORMATDESCRIPTOR pfd;
} EMRPIXELFORMAT, *PEMRPIXELFORMAT;

typedef struct tagEMRGLSRECORD {
  EMR   emr;
  DWORD cbData;
  BYTE  Data[1];
} EMRGLSRECORD, *PEMRGLSRECORD;

typedef struct {
  EMR   emr;
  RECTL rclBounds;
  DWORD cbData;
  BYTE  Data[1];
} EMRGLSBOUNDEDRECORD, *PEMRGLSBOUNDEDRECORD;

typedef INT (CALLBACK *ENHMFENUMPROC)(HDC, HANDLETABLE *,
                                      const ENHMETARECORD *, INT, LPARAM);

#define EMR_HEADER	1
#define EMR_POLYBEZIER	2
#define EMR_POLYGON	3
#define EMR_POLYLINE	4
#define EMR_POLYBEZIERTO	5
#define EMR_POLYLINETO	6
#define EMR_POLYPOLYLINE	7
#define EMR_POLYPOLYGON	8
#define EMR_SETWINDOWEXTEX	9
#define EMR_SETWINDOWORGEX	10
#define EMR_SETVIEWPORTEXTEX	11
#define EMR_SETVIEWPORTORGEX	12
#define EMR_SETBRUSHORGEX	13
#define EMR_EOF	14
#define EMR_SETPIXELV	15
#define EMR_SETMAPPERFLAGS	16
#define EMR_SETMAPMODE	17
#define EMR_SETBKMODE	18
#define EMR_SETPOLYFILLMODE	19
#define EMR_SETROP2	20
#define EMR_SETSTRETCHBLTMODE	21
#define EMR_SETTEXTALIGN	22
#define EMR_SETCOLORADJUSTMENT	23
#define EMR_SETTEXTCOLOR	24
#define EMR_SETBKCOLOR	25
#define EMR_OFFSETCLIPRGN	26
#define EMR_MOVETOEX	27
#define EMR_SETMETARGN	28
#define EMR_EXCLUDECLIPRECT	29
#define EMR_INTERSECTCLIPRECT	30
#define EMR_SCALEVIEWPORTEXTEX	31
#define EMR_SCALEWINDOWEXTEX	32
#define EMR_SAVEDC	33
#define EMR_RESTOREDC	34
#define EMR_SETWORLDTRANSFORM	35
#define EMR_MODIFYWORLDTRANSFORM	36
#define EMR_SELECTOBJECT	37
#define EMR_CREATEPEN	38
#define EMR_CREATEBRUSHINDIRECT	39
#define EMR_DELETEOBJECT	40
#define EMR_ANGLEARC	41
#define EMR_ELLIPSE	42
#define EMR_RECTANGLE	43
#define EMR_ROUNDRECT	44
#define EMR_ARC	45
#define EMR_CHORD	46
#define EMR_PIE	47
#define EMR_SELECTPALETTE	48
#define EMR_CREATEPALETTE	49
#define EMR_SETPALETTEENTRIES	50
#define EMR_RESIZEPALETTE	51
#define EMR_REALIZEPALETTE	52
#define EMR_EXTFLOODFILL	53
#define EMR_LINETO	54
#define EMR_ARCTO	55
#define EMR_POLYDRAW	56
#define EMR_SETARCDIRECTION	57
#define EMR_SETMITERLIMIT	58
#define EMR_BEGINPATH	59
#define EMR_ENDPATH	60
#define EMR_CLOSEFIGURE	61
#define EMR_FILLPATH	62
#define EMR_STROKEANDFILLPATH	63
#define EMR_STROKEPATH	64
#define EMR_FLATTENPATH	65
#define EMR_WIDENPATH	66
#define EMR_SELECTCLIPPATH	67
#define EMR_ABORTPATH	68
#define EMR_GDICOMMENT	70
#define EMR_FILLRGN	71
#define EMR_FRAMERGN	72
#define EMR_INVERTRGN	73
#define EMR_PAINTRGN	74
#define EMR_EXTSELECTCLIPRGN	75
#define EMR_BITBLT	76
#define EMR_STRETCHBLT	77
#define EMR_MASKBLT	78
#define EMR_PLGBLT	79
#define EMR_SETDIBITSTODEVICE	80
#define EMR_STRETCHDIBITS	81
#define EMR_EXTCREATEFONTINDIRECTW	82
#define EMR_EXTTEXTOUTA	83
#define EMR_EXTTEXTOUTW	84
#define EMR_POLYBEZIER16	85
#define EMR_POLYGON16	86
#define EMR_POLYLINE16	87
#define EMR_POLYBEZIERTO16	88
#define EMR_POLYLINETO16	89
#define EMR_POLYPOLYLINE16	90
#define EMR_POLYPOLYGON16	91
#define EMR_POLYDRAW16	92
#define EMR_CREATEMONOBRUSH	93
#define EMR_CREATEDIBPATTERNBRUSHPT	94
#define EMR_EXTCREATEPEN	95
#define EMR_POLYTEXTOUTA	96
#define EMR_POLYTEXTOUTW	97
#define EMR_SETICMMODE	98
#define EMR_CREATECOLORSPACE	99
#define EMR_SETCOLORSPACE	100
#define EMR_DELETECOLORSPACE	101
#define EMR_GLSRECORD	102
#define EMR_GLSBOUNDEDRECORD	103
#define EMR_PIXELFORMAT 104
#define EMR_DRAWESCAPE 	105
#define EMR_EXTESCAPE	106
#define EMR_STARTDOC	107
#define EMR_SMALLTEXTOUT	108
#define EMR_FORCEUFIMAPPING	109
#define EMR_NAMEDESCAPE	110
#define EMR_COLORCORRECTPALETTE	111
#define EMR_SETICMPROFILEA	112
#define EMR_SETICMPROFILEW	113
#define EMR_ALPHABLEND	114
#define EMR_SETLAYOUT	115
#define EMR_TRANSPARENTBLT	116
#define EMR_RESERVED_117	117
#define EMR_GRADIENTFILL	118
#define EMR_SETLINKEDUFI	119
#define EMR_SETTEXTJUSTIFICATION	120
#define EMR_COLORMATCHTOTARGETW	121
#define EMR_CREATECOLORSPACEW	122

#define EMR_MIN 1
#define EMR_MAX 122

#define ENHMETA_SIGNATURE	1179469088
#define ENHMETA_STOCK_OBJECT	0x80000000

#define GDICOMMENT_IDENTIFIER         0x43494447
#define GDICOMMENT_WINDOWS_METAFILE   0x80000001
#define GDICOMMENT_BEGINGROUP         0x00000002
#define GDICOMMENT_ENDGROUP           0x00000003
#define GDICOMMENT_MULTIFORMATS       0x40000004
#define GDICOMMENT_UNICODE_STRING     0x00000040
#define GDICOMMENT_UNICODE_END        0x00000080
#define EPS_SIGNATURE                 0x46535045

#define CCHDEVICENAME 32
#define CCHFORMNAME   32

typedef struct
{
    BYTE   dmDeviceName[CCHDEVICENAME];
    WORD   dmSpecVersion;
    WORD   dmDriverVersion;
    WORD   dmSize;
    WORD   dmDriverExtra;
    DWORD  dmFields;
    union {
      struct {
	short  dmOrientation;
	short  dmPaperSize;
	short  dmPaperLength;
	short  dmPaperWidth;
        short  dmScale;
        short  dmCopies;
        short  dmDefaultSource;
        short  dmPrintQuality;
      } DUMMYSTRUCTNAME1;
      struct {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      } DUMMYSTRUCTNAME2;
    } DUMMYUNIONNAME1;
    short  dmColor;
    short  dmDuplex;
    short  dmYResolution;
    short  dmTTOption;
    short  dmCollate;
    BYTE   dmFormName[CCHFORMNAME];
    WORD   dmLogPixels;
    DWORD  dmBitsPerPel;
    DWORD  dmPelsWidth;
    DWORD  dmPelsHeight;
    union {
      DWORD dmDisplayFlags;
      DWORD dmNup;
    } DUMMYUNIONNAME2;
    DWORD  dmDisplayFrequency;
    DWORD  dmICMMethod;
    DWORD  dmICMIntent;
    DWORD  dmMediaType;
    DWORD  dmDitherType;
    DWORD  dmReserved1;
    DWORD  dmReserved2;
    DWORD  dmPanningWidth;
    DWORD  dmPanningHeight;
} DEVMODEA, *PDEVMODEA, *LPDEVMODEA;

typedef struct
{
    WCHAR  dmDeviceName[CCHDEVICENAME];
    WORD   dmSpecVersion;
    WORD   dmDriverVersion;
    WORD   dmSize;
    WORD   dmDriverExtra;
    DWORD  dmFields;
    union {
      struct {
	short  dmOrientation;
	short  dmPaperSize;
	short  dmPaperLength;
	short  dmPaperWidth;
        short  dmScale;
        short  dmCopies;
        short  dmDefaultSource;
        short  dmPrintQuality;
      } DUMMYSTRUCTNAME1;
      struct {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      } DUMMYSTRUCTNAME2;
    } DUMMYUNIONNAME1;
    short  dmColor;
    short  dmDuplex;
    short  dmYResolution;
    short  dmTTOption;
    short  dmCollate;
    WCHAR  dmFormName[CCHFORMNAME];
    WORD   dmLogPixels;
    DWORD  dmBitsPerPel;
    DWORD  dmPelsWidth;
    DWORD  dmPelsHeight;
    union {
      DWORD dmDisplayFlags;
      DWORD dmNup;
    } DUMMYUNIONNAME2;
    DWORD  dmDisplayFrequency;
    DWORD  dmICMMethod;
    DWORD  dmICMIntent;
    DWORD  dmMediaType;
    DWORD  dmDitherType;
    DWORD  dmReserved1;
    DWORD  dmReserved2;
    DWORD  dmPanningWidth;
    DWORD  dmPanningHeight;
} DEVMODEW, *PDEVMODEW, *LPDEVMODEW;

DECL_WINELIB_TYPE_AW(DEVMODE)
DECL_WINELIB_TYPE_AW(PDEVMODE)
DECL_WINELIB_TYPE_AW(LPDEVMODE)

#define DM_SPECVERSION  0x401
#define DM_UPDATE	1
#define DM_COPY		2
#define DM_PROMPT	4
#define DM_MODIFY	8

#define DM_IN_BUFFER      DM_MODIFY
#define DM_IN_PROMPT      DM_PROMPT
#define DM_OUT_BUFFER     DM_COPY
#define DM_OUT_DEFAULT    DM_UPDATE

#define DM_ORIENTATION          __MSABI_LONG(0x00000001)
#define DM_PAPERSIZE            __MSABI_LONG(0x00000002)
#define DM_PAPERLENGTH          __MSABI_LONG(0x00000004)
#define DM_PAPERWIDTH           __MSABI_LONG(0x00000008)
#define DM_SCALE                __MSABI_LONG(0x00000010)
#define DM_POSITION             __MSABI_LONG(0x00000020)
#define DM_NUP                  __MSABI_LONG(0x00000040)
#define DM_DISPLAYORIENTATION   __MSABI_LONG(0x00000080)
#define DM_COPIES               __MSABI_LONG(0x00000100)
#define DM_DEFAULTSOURCE        __MSABI_LONG(0x00000200)
#define DM_PRINTQUALITY         __MSABI_LONG(0x00000400)
#define DM_COLOR                __MSABI_LONG(0x00000800)
#define DM_DUPLEX               __MSABI_LONG(0x00001000)
#define DM_YRESOLUTION          __MSABI_LONG(0x00002000)
#define DM_TTOPTION             __MSABI_LONG(0x00004000)
#define DM_COLLATE              __MSABI_LONG(0x00008000)
#define DM_FORMNAME             __MSABI_LONG(0x00010000)
#define DM_LOGPIXELS            __MSABI_LONG(0x00020000)
#define DM_BITSPERPEL           __MSABI_LONG(0x00040000)
#define DM_PELSWIDTH            __MSABI_LONG(0x00080000)
#define DM_PELSHEIGHT           __MSABI_LONG(0x00100000)
#define DM_DISPLAYFLAGS         __MSABI_LONG(0x00200000)
#define DM_DISPLAYFREQUENCY     __MSABI_LONG(0x00400000)
#define DM_ICMMETHOD            __MSABI_LONG(0x00800000)
#define DM_ICMINTENT            __MSABI_LONG(0x01000000)
#define DM_MEDIATYPE            __MSABI_LONG(0x02000000)
#define DM_DITHERTYPE           __MSABI_LONG(0x04000000)
#define DM_PANNINGWIDTH         __MSABI_LONG(0x08000000)
#define DM_PANNINGHEIGHT        __MSABI_LONG(0x10000000)
#define DM_DISPLAYFIXEDOUTPUT   __MSABI_LONG(0x20000000)

#define DM_GRAYSCALE            1
#define DM_INTERLACED           2
#define DMDISPLAYFLAGS_TEXTMODE 4

#define DMORIENT_PORTRAIT	1
#define DMORIENT_LANDSCAPE	2

#define DMPAPER_FIRST              DMPAPER_LETTER
#define DMPAPER_LETTER		   1
#define DMPAPER_LETTERSMALL        2
#define DMPAPER_TABLOID            3
#define DMPAPER_LEDGER             4
#define DMPAPER_LEGAL		   5
#define DMPAPER_STATEMENT          6
#define DMPAPER_EXECUTIVE	   7
#define DMPAPER_A3		   8
#define DMPAPER_A4		   9
#define DMPAPER_A4SMALL            10
#define DMPAPER_A5		   11
#define DMPAPER_B4                 12
#define DMPAPER_B5                 13
#define DMPAPER_FOLIO              14
#define DMPAPER_QUARTO             15
#define DMPAPER_10X14              16
#define DMPAPER_11X17              17
#define DMPAPER_NOTE               18
#define DMPAPER_ENV_9              19
#define DMPAPER_ENV_10		   20
#define DMPAPER_ENV_11             21
#define DMPAPER_ENV_12             22
#define DMPAPER_ENV_14             23
#define DMPAPER_CSHEET             24
#define DMPAPER_DSHEET             25
#define DMPAPER_ESHEET             26
#define DMPAPER_ENV_DL		   27
#define DMPAPER_ENV_C5		   28
#define DMPAPER_ENV_C3             29
#define DMPAPER_ENV_C4             30
#define DMPAPER_ENV_C6             31
#define DMPAPER_ENV_C65            32
#define DMPAPER_ENV_B4             33
#define DMPAPER_ENV_B5		   34
#define DMPAPER_ENV_B6             35
#define DMPAPER_ENV_ITALY          36
#define DMPAPER_ENV_MONARCH	   37
#define DMPAPER_ENV_PERSONAL       38
#define DMPAPER_FANFOLD_US         39
#define DMPAPER_FANFOLD_STD_GERMAN 40
#define DMPAPER_FANFOLD_LGL_GERMAN 41
#define DMPAPER_ISO_B4             42
#define DMPAPER_JAPANESE_POSTCARD  43
#define DMPAPER_9X11               44
#define DMPAPER_10X11              45
#define DMPAPER_15X11              46
#define DMPAPER_ENV_INVITE         47
#define DMPAPER_RESERVED_48        48
#define DMPAPER_RESERVED_49        49
#define DMPAPER_LETTER_EXTRA       50
#define DMPAPER_LEGAL_EXTRA        51
#define DMPAPER_TABLOID_EXTRA      52
#define DMPAPER_A4_EXTRA           53
#define DMPAPER_LETTER_TRANSVERSE  54
#define DMPAPER_A4_TRANSVERSE      55
#define DMPAPER_LETTER_EXTRA_TRANSVERSE 56
#define DMPAPER_A_PLUS             57
#define DMPAPER_B_PLUS             58
#define DMPAPER_LETTER_PLUS        59
#define DMPAPER_A4_PLUS            60
#define DMPAPER_A5_TRANSVERSE      61
#define DMPAPER_B5_TRANSVERSE      62
#define DMPAPER_A3_EXTRA           63
#define DMPAPER_A5_EXTRA           64
#define DMPAPER_B5_EXTRA           65
#define DMPAPER_A2                 66
#define DMPAPER_A3_TRANSVERSE      67
#define DMPAPER_A3_EXTRA_TRANSVERSE           68
#define DMPAPER_DBL_JAPANESE_POSTCARD         69
#define DMPAPER_A6                 70
#define DMPAPER_JENV_KAKU2         71
#define DMPAPER_JENV_KAKU3         72
#define DMPAPER_JENV_CHOU3         73
#define DMPAPER_JENV_CHOU4         74
#define DMPAPER_LETTER_ROTATED     75
#define DMPAPER_A3_ROTATED         76
#define DMPAPER_A4_ROTATED         77
#define DMPAPER_A5_ROTATED         78
#define DMPAPER_B4_JIS_ROTATED     79
#define DMPAPER_B5_JIS_ROTATED     80
#define DMPAPER_JAPANESE_POSTCARD_ROTATED     81
#define DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED 82
#define DMPAPER_A6_ROTATED         83
#define DMPAPER_JENV_KAKU2_ROTATED 84
#define DMPAPER_JENV_KAKU3_ROTATED 85
#define DMPAPER_JENV_CHOU3_ROTATED 86
#define DMPAPER_JENV_CHOU4_ROTATED 87
#define DMPAPER_B6_JIS             88
#define DMPAPER_B6_JIS_ROTATED     89
#define DMPAPER_12X11              90
#define DMPAPER_JENV_YOU4          91
#define DMPAPER_JENV_YOU4_ROTATED  92
#define DMPAPER_P16K               93
#define DMPAPER_P32K               94
#define DMPAPER_P32KBIG            95
#define DMPAPER_PENV_1             96
#define DMPAPER_PENV_2             97
#define DMPAPER_PENV_3             98
#define DMPAPER_PENV_4             99
#define DMPAPER_PENV_5             100
#define DMPAPER_PENV_6             101
#define DMPAPER_PENV_7             102
#define DMPAPER_PENV_8             103
#define DMPAPER_PENV_9             104
#define DMPAPER_PENV_10            105
#define DMPAPER_P16K_ROTATED       106
#define DMPAPER_P32K_ROTATED       107
#define DMPAPER_P32KBIG_ROTATED    108
#define DMPAPER_PENV_1_ROTATED     109
#define DMPAPER_PENV_2_ROTATED     110
#define DMPAPER_PENV_3_ROTATED     111
#define DMPAPER_PENV_4_ROTATED     112
#define DMPAPER_PENV_5_ROTATED     113
#define DMPAPER_PENV_6_ROTATED     114
#define DMPAPER_PENV_7_ROTATED     115
#define DMPAPER_PENV_8_ROTATED     116
#define DMPAPER_PENV_9_ROTATED     117
#define DMPAPER_PENV_10_ROTATED    118

#define DMPAPER_LAST               DMPAPER_PENV_10_ROTATED
#define DMPAPER_USER               256

#define DMBIN_FIRST             DMBIN_UPPER
#define DMBIN_UPPER		1
#define DMBIN_ONLYONE           1
#define DMBIN_LOWER		2
#define DMBIN_MIDDLE		3
#define DMBIN_MANUAL		4
#define DMBIN_ENVELOPE		5
#define DMBIN_ENVMANUAL		6
#define DMBIN_AUTO		7
#define DMBIN_TRACTOR           8
#define DMBIN_SMALLFMT          9
#define DMBIN_LARGEFMT          10
#define DMBIN_LARGECAPACITY	11
#define DMBIN_CASSETTE          14
#define DMBIN_FORMSOURCE        15
#define DMBIN_LAST              DMBIN_FORMSOURCE
#define DMBIN_USER              256

#define DMRES_DRAFT             (-1)
#define DMRES_LOW               (-2)
#define DMRES_MEDIUM            (-3)
#define DMRES_HIGH              (-4)

#define DMCOLOR_MONOCHROME	1
#define DMCOLOR_COLOR		2

#define DMDUP_SIMPLEX           1
#define DMDUP_VERTICAL          2
#define DMDUP_HORIZONTAL        3

#define DMTT_BITMAP		1
#define DMTT_DOWNLOAD		2
#define DMTT_SUBDEV		3
#define DMTT_DOWNLOAD_OUTLINE   4

#define DMCOLLATE_FALSE         0
#define DMCOLLATE_TRUE          1

#define DMICMMETHOD_NONE        1
#define DMICMMETHOD_SYSTEM      2
#define DMICMMETHOD_DRIVER      3
#define DMICMMETHOD_DEVICE      4
#define DMICMMETHOD_USER        256

#define DMICM_SATURATE          1
#define DMICM_CONTRAST          2
#define DMICM_COLORMETRIC       3
#define DMICM_USER              256

#define DMMEDIA_STANDARD        1
#define DMMEDIA_TRANSPARENCY    2
#define DMMEDIA_GLOSSY          3
#define DMMEDIA_USER            256

#define DMDITHER_NONE           1
#define DMDITHER_COARSE         2
#define DMDITHER_FINE           3
#define DMDITHER_LINEART        4
#define DMDITHER_GRAYSCALE      5
#define DMDITHER_USER           256

#define DMDO_DEFAULT            0
#define DMDO_90                 1
#define DMDO_180                2
#define DMDO_270                3

#define DMDFO_DEFAULT           0
#define DMDFO_STRETCH           1
#define DMDFO_CENTER            2

typedef struct
{
    INT    cbSize;
    LPCSTR   lpszDocName;
    LPCSTR   lpszOutput;
    LPCSTR   lpszDatatype;
    DWORD    fwType;
} DOCINFOA, *LPDOCINFOA;

typedef struct
{
    INT    cbSize;
    LPCWSTR  lpszDocName;
    LPCWSTR  lpszOutput;
    LPCWSTR  lpszDatatype;
    DWORD    fwType;
} DOCINFOW, *LPDOCINFOW;

DECL_WINELIB_TYPE_AW(DOCINFO)
DECL_WINELIB_TYPE_AW(LPDOCINFO)

#define DI_APPBANDING     0x0001

/* Flags for PolyDraw and GetPath */
#define PT_CLOSEFIGURE          0x0001
#define PT_LINETO               0x0002
#define PT_BEZIERTO             0x0004
#define PT_MOVETO               0x0006

#define	RDH_RECTANGLES  1

typedef struct _RGNDATAHEADER {
    DWORD	dwSize;
    DWORD	iType;
    DWORD	nCount;
    DWORD	nRgnSize;
    RECT	rcBound;
} RGNDATAHEADER,*PRGNDATAHEADER;

typedef struct _RGNDATA {
    RGNDATAHEADER	rdh;
    char		Buffer[1];
} RGNDATA,*PRGNDATA,*LPRGNDATA;

typedef BOOL (CALLBACK *ABORTPROC)(HDC, INT);

typedef enum {
    DISPLAYCONFIG_DEVICE_INFO_GET_SOURCE_NAME                = 1,
    DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_NAME                = 2,
    DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_PREFERRED_MODE      = 3,
    DISPLAYCONFIG_DEVICE_INFO_GET_ADAPTER_NAME               = 4,
    DISPLAYCONFIG_DEVICE_INFO_SET_TARGET_PERSISTENCE         = 5,
    DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_BASE_TYPE           = 6,
    DISPLAYCONFIG_DEVICE_INFO_GET_SUPPORT_VIRTUAL_RESOLUTION = 7,
    DISPLAYCONFIG_DEVICE_INFO_SET_SUPPORT_VIRTUAL_RESOLUTION = 8,
    DISPLAYCONFIG_DEVICE_INFO_FORCE_UINT32                   = 0xffffffff
} DISPLAYCONFIG_DEVICE_INFO_TYPE;

typedef struct DISPLAYCONFIG_DEVICE_INFO_HEADER {
    DISPLAYCONFIG_DEVICE_INFO_TYPE type;
    UINT32                         size;
    LUID                           adapterId;
    UINT32                         id;
} DISPLAYCONFIG_DEVICE_INFO_HEADER;

typedef struct {
    DWORD	cb;
    CHAR	DeviceName[32];
    CHAR	DeviceString[128];
    DWORD	StateFlags;
    CHAR	DeviceID[128];
    CHAR	DeviceKey[128];
} DISPLAY_DEVICEA,*PDISPLAY_DEVICEA,*LPDISPLAY_DEVICEA;

typedef struct {
    DWORD	cb;
    WCHAR	DeviceName[32];
    WCHAR	DeviceString[128];
    DWORD	StateFlags;
    WCHAR	DeviceID[128];
    WCHAR	DeviceKey[128];
} DISPLAY_DEVICEW,*PDISPLAY_DEVICEW,*LPDISPLAY_DEVICEW;
DECL_WINELIB_TYPE_AW(DISPLAY_DEVICE)
DECL_WINELIB_TYPE_AW(PDISPLAY_DEVICE)
DECL_WINELIB_TYPE_AW(LPDISPLAY_DEVICE)

/* DISPLAY_DEVICE.StateFlags (?)*/
#define	DISPLAY_DEVICE_ATTACHED_TO_DESKTOP	0x00000001
#define	DISPLAY_DEVICE_MULTI_DRIVER		0x00000002
#define	DISPLAY_DEVICE_PRIMARY_DEVICE		0x00000004
#define	DISPLAY_DEVICE_MIRRORING_DRIVER		0x00000008
#define	DISPLAY_DEVICE_VGA_COMPATIBLE		0x00000010

typedef struct DISPLAYCONFIG_DESKTOP_IMAGE_INFO
{
    POINTL PathSourceSize;
    RECTL DesktopImageRegion;
    RECTL DesktopImageClip;
} DISPLAYCONFIG_DESKTOP_IMAGE_INFO;

typedef enum
{
    DISPLAYCONFIG_MODE_INFO_TYPE_SOURCE = 1,
    DISPLAYCONFIG_MODE_INFO_TYPE_TARGET = 2,
    DISPLAYCONFIG_MODE_INFO_TYPE_DESKTOP_IMAGE = 3,
    DISPLAYCONFIG_MODE_INFO_TYPE_FORCE_UINT32 = 0xffffffff
} DISPLAYCONFIG_MODE_INFO_TYPE;

typedef enum
{
    DISPLAYCONFIG_PIXELFORMAT_8BPP = 1,
    DISPLAYCONFIG_PIXELFORMAT_16BPP = 2,
    DISPLAYCONFIG_PIXELFORMAT_24BPP = 3,
    DISPLAYCONFIG_PIXELFORMAT_32BPP = 4,
    DISPLAYCONFIG_PIXELFORMAT_NONGDI = 5,
    DISPLAYCONFIG_PIXELFORMAT_FORCE_UINT32 = 0xffffffff
} DISPLAYCONFIG_PIXELFORMAT;

typedef enum
{
    DISPLAYCONFIG_ROTATION_IDENTITY = 1,
    DISPLAYCONFIG_ROTATION_ROTATE90 = 2,
    DISPLAYCONFIG_ROTATION_ROTATE180 = 3,
    DISPLAYCONFIG_ROTATION_ROTATE270 = 4,
    DISPLAYCONFIG_ROTATION_FORCE_UINT32 = 0xffffffff
} DISPLAYCONFIG_ROTATION;

typedef enum
{
    DISPLAYCONFIG_SCALING_IDENTITY = 1,
    DISPLAYCONFIG_SCALING_CENTERED = 2,
    DISPLAYCONFIG_SCALING_STRETCHED = 3,
    DISPLAYCONFIG_SCALING_ASPECTRATIOCENTEREDMAX = 4,
    DISPLAYCONFIG_SCALING_CUSTOM = 5,
    DISPLAYCONFIG_SCALING_PREFERRED = 128,
    DISPLAYCONFIG_SCALING_FORCE_UINT32 = 0xffffffff
} DISPLAYCONFIG_SCALING;

typedef enum
{
    DISPLAYCONFIG_SCANLINE_ORDERING_UNSPECIFIED = 0,
    DISPLAYCONFIG_SCANLINE_ORDERING_PROGRESSIVE = 1,
    DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED = 2,
    DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_UPPERFIELDFIRST = DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED,
    DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_LOWERFIELDFIRST = 3,
    DISPLAYCONFIG_SCANLINE_ORDERING_FORCE_UINT32 = 0xffffffff
} DISPLAYCONFIG_SCANLINE_ORDERING;

typedef enum
{
    DISPLAYCONFIG_TOPOLOGY_INTERNAL = 0x00000001,
    DISPLAYCONFIG_TOPOLOGY_CLONE = 0x00000002,
    DISPLAYCONFIG_TOPOLOGY_EXTEND = 0x00000004,
    DISPLAYCONFIG_TOPOLOGY_EXTERNAL = 0x00000008,
    DISPLAYCONFIG_TOPOLOGY_FORCE_UINT32 = 0xffffffff
} DISPLAYCONFIG_TOPOLOGY_ID;

typedef enum
{
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_OTHER = -1,
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HD15 = 0,
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SVIDEO = 1,
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPOSITE_VIDEO = 2,
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPONENT_VIDEO = 3,
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DVI = 4,
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HDMI = 5,
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_LVDS = 6,
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_D_JPN = 8,
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDI = 9,
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EXTERNAL = 10,
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EMBEDDED = 11,
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EXTERNAL = 12,
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EMBEDDED = 13,
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDTVDONGLE = 14,
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_MIRACAST = 15,
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INTERNAL = 0x80000000,
    DISPLAYCONFIG_OUTPUT_TECHNOLOGY_FORCE_UINT32 = 0xffffffff
} DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY;

typedef struct DISPLAYCONFIG_2DREGION
{
    UINT32 cx;
    UINT32 cy;
} DISPLAYCONFIG_2DREGION;

typedef struct DISPLAYCONFIG_RATIONAL
{
    UINT32 Numerator;
    UINT32 Denominator;
} DISPLAYCONFIG_RATIONAL;

typedef struct DISPLAYCONFIG_PATH_SOURCE_INFO
{
    LUID adapterId;
    UINT32 id;
    union {
        UINT32 modeInfoIdx;
        struct {
            UINT32 cloneGroupId :16;
            UINT32 sourceModeInfoIdx :16;
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;
    UINT32 statusFlags;
} DISPLAYCONFIG_PATH_SOURCE_INFO;

typedef struct DISPLAYCONFIG_SOURCE_MODE
{
    UINT32 width;
    UINT32 height;
    DISPLAYCONFIG_PIXELFORMAT pixelFormat;
    POINTL position;
} DISPLAYCONFIG_SOURCE_MODE;

typedef struct DISPLAYCONFIG_VIDEO_SIGNAL_INFO
{
  UINT64 pixelRate;
  DISPLAYCONFIG_RATIONAL hSyncFreq;
  DISPLAYCONFIG_RATIONAL vSyncFreq;
  DISPLAYCONFIG_2DREGION activeSize;
  DISPLAYCONFIG_2DREGION totalSize;
  union {
      struct {
          UINT32 videoStandard :16;
          UINT32 vSyncFreqDivider :6;
          UINT32 reserved :10;
      } AdditionalSignalInfo;
      UINT32 videoStandard;
  } DUMMYUNIONNAME;
  DISPLAYCONFIG_SCANLINE_ORDERING scanLineOrdering;
} DISPLAYCONFIG_VIDEO_SIGNAL_INFO;

typedef struct DISPLAYCONFIG_PATH_TARGET_INFO
{
    LUID adapterId;
    UINT32 id;
    union {
        UINT32 modeInfoIdx;
        struct {
            UINT32 desktopModeInfoIdx :16;
            UINT32 targetModeInfoIdx :16;
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;
    DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY outputTechnology;
    DISPLAYCONFIG_ROTATION rotation;
    DISPLAYCONFIG_SCALING scaling;
    DISPLAYCONFIG_RATIONAL refreshRate;
    DISPLAYCONFIG_SCANLINE_ORDERING scanLineOrdering;
    BOOL targetAvailable;
    UINT32 statusFlags;
} DISPLAYCONFIG_PATH_TARGET_INFO;

typedef struct DISPLAYCONFIG_TARGET_MODE
{
    DISPLAYCONFIG_VIDEO_SIGNAL_INFO targetVideoSignalInfo;
} DISPLAYCONFIG_TARGET_MODE;

typedef struct DISPLAYCONFIG_PATH_INFO
{
    DISPLAYCONFIG_PATH_SOURCE_INFO sourceInfo;
    DISPLAYCONFIG_PATH_TARGET_INFO targetInfo;
    UINT32 flags;
} DISPLAYCONFIG_PATH_INFO;

typedef struct DISPLAYCONFIG_MODE_INFO
{
    DISPLAYCONFIG_MODE_INFO_TYPE infoType;
    UINT32 id;
    LUID adapterId;
    union {
        DISPLAYCONFIG_TARGET_MODE targetMode;
        DISPLAYCONFIG_SOURCE_MODE sourceMode;
        DISPLAYCONFIG_DESKTOP_IMAGE_INFO desktopImageInfo;
    } DUMMYUNIONNAME;
} DISPLAYCONFIG_MODE_INFO;

/* For GetDisplayConfigBufferSizes */
#define QDC_ALL_PATHS                           0x00000001
#define QDC_ONLY_ACTIVE_PATHS                   0x00000002
#define QDC_DATABASE_CURRENT                    0x00000004

#define GDI_ERROR                               (~0u)
#define HGDI_ERROR                              ((HANDLE)~(ULONG_PTR)0)

/* AddFontResourceEx flags */
#define FR_PRIVATE  0x10
#define FR_NOT_ENUM 0x20

/* Mirroring flags */
#define LAYOUT_LTR                         0x00000000
#define LAYOUT_RTL                         0x00000001
#define LAYOUT_BITMAPORIENTATIONPRESERVED  0x00000008
#define NOMIRRORBITMAP                     0x80000000

/* For DRAWPATTERNRECT Escape */
typedef struct _DRAWPATRECT
{
    POINT ptPosition;
    POINT ptSize;
    WORD  wStyle;
    WORD  wPattern;
} DRAWPATRECT, *PDRAWPATRECT;

typedef struct tagWCRANGE {
  WCHAR  wcLow;
  USHORT cGlyphs;
} WCRANGE, *PWCRANGE, *LPWCRANGE;

typedef struct tagGLYPHSET {
  DWORD    cbThis;
  DWORD    flAccel;
  DWORD    cGlyphsSupported;
  DWORD    cRanges;
  WCRANGE  ranges[1];
} GLYPHSET, *PGLYPHSET, *LPGLYPHSET;

#define GS_8BIT_INDICES 0x00000001

WINGDIAPI INT         WINAPI AbortDoc(HDC);
WINGDIAPI BOOL        WINAPI AbortPath(HDC);
WINGDIAPI INT         WINAPI AddFontResourceA(LPCSTR);
WINGDIAPI INT         WINAPI AddFontResourceW(LPCWSTR);
#define                      AddFontResource WINELIB_NAME_AW(AddFontResource)
WINGDIAPI INT         WINAPI AddFontResourceExA(LPCSTR, DWORD, PVOID);
WINGDIAPI INT         WINAPI AddFontResourceExW(LPCWSTR, DWORD, PVOID);
#define                      AddFontResourceEx WINELIB_NAME_AW(AddFontResourceEx)
WINGDIAPI HANDLE      WINAPI AddFontMemResourceEx(PVOID, DWORD, PVOID, DWORD *);
WINGDIAPI BOOL        WINAPI AlphaBlend(HDC,int,int,int,int,HDC,int,int,int,int,BLENDFUNCTION);
WINGDIAPI BOOL        WINAPI AngleArc(HDC, INT, INT, DWORD, FLOAT, FLOAT);
WINGDIAPI BOOL        WINAPI AnimatePalette(HPALETTE,UINT,UINT,const PALETTEENTRY*);
WINGDIAPI BOOL        WINAPI Arc(HDC,INT,INT,INT,INT,INT,INT,INT,INT);
WINGDIAPI BOOL        WINAPI ArcTo(HDC, INT, INT, INT, INT, INT, INT, INT, INT);
WINGDIAPI BOOL        WINAPI BeginPath(HDC);
WINGDIAPI BOOL        WINAPI BitBlt(HDC,INT,INT,INT,INT,HDC,INT,INT,DWORD);
WINGDIAPI INT         WINAPI ChoosePixelFormat(HDC,const PIXELFORMATDESCRIPTOR*);
WINGDIAPI BOOL        WINAPI Chord(HDC,INT,INT,INT,INT,INT,INT,INT,INT);
WINGDIAPI HENHMETAFILE WINAPI CloseEnhMetaFile(HDC);
WINGDIAPI BOOL        WINAPI CloseFigure(HDC);
WINGDIAPI HMETAFILE   WINAPI CloseMetaFile(HDC);
WINGDIAPI INT         WINAPI CombineRgn(HRGN,HRGN,HRGN,INT);
WINGDIAPI BOOL        WINAPI CombineTransform(LPXFORM,const XFORM *,const XFORM *);
WINGDIAPI HENHMETAFILE WINAPI CopyEnhMetaFileA(HENHMETAFILE,LPCSTR);
WINGDIAPI HENHMETAFILE WINAPI CopyEnhMetaFileW(HENHMETAFILE,LPCWSTR);
#define                      CopyEnhMetaFile WINELIB_NAME_AW(CopyEnhMetaFile)
WINGDIAPI HMETAFILE   WINAPI CopyMetaFileA(HMETAFILE,LPCSTR);
WINGDIAPI HMETAFILE   WINAPI CopyMetaFileW(HMETAFILE,LPCWSTR);
#define                      CopyMetaFile WINELIB_NAME_AW(CopyMetaFile)
WINGDIAPI HBITMAP     WINAPI CreateBitmap(INT,INT,UINT,UINT,LPCVOID);
WINGDIAPI HBITMAP     WINAPI CreateBitmapIndirect(const BITMAP*);
WINGDIAPI HBRUSH      WINAPI CreateBrushIndirect(const LOGBRUSH*);
WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceA(LPLOGCOLORSPACEA);
WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceW(LPLOGCOLORSPACEW);
#define                      CreateColorSpace WINELIB_NAME_AW(CreateColorSpace)
WINGDIAPI HBITMAP     WINAPI CreateCompatibleBitmap(HDC,INT,INT);
WINGDIAPI HDC         WINAPI CreateCompatibleDC(HDC);
WINGDIAPI HDC         WINAPI CreateDCA(LPCSTR,LPCSTR,LPCSTR,const DEVMODEA*);
WINGDIAPI HDC         WINAPI CreateDCW(LPCWSTR,LPCWSTR,LPCWSTR,const DEVMODEW*);
#define                      CreateDC WINELIB_NAME_AW(CreateDC)
WINGDIAPI HBITMAP     WINAPI CreateDIBitmap(HDC,const BITMAPINFOHEADER*,DWORD,LPCVOID,const BITMAPINFO*,UINT);
WINGDIAPI HBRUSH      WINAPI CreateDIBPatternBrush(HGLOBAL,UINT);
WINGDIAPI HBRUSH      WINAPI CreateDIBPatternBrushPt(const void*,UINT);
WINGDIAPI HBITMAP     WINAPI CreateDIBSection(HDC, const BITMAPINFO *, UINT, void **, HANDLE, DWORD offset);
WINGDIAPI HBITMAP     WINAPI CreateDiscardableBitmap(HDC,INT,INT);
WINGDIAPI HRGN        WINAPI CreateEllipticRgn(INT,INT,INT,INT);
WINGDIAPI HRGN        WINAPI CreateEllipticRgnIndirect(const RECT *);
WINGDIAPI HDC         WINAPI CreateEnhMetaFileA(HDC,LPCSTR,const RECT*,LPCSTR);
WINGDIAPI HDC         WINAPI CreateEnhMetaFileW(HDC,LPCWSTR,const RECT*,LPCWSTR);
#define                      CreateEnhMetaFile WINELIB_NAME_AW(CreateEnhMetaFile)
WINGDIAPI HFONT       WINAPI CreateFontA(INT,INT,INT,INT,INT,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,LPCSTR);
WINGDIAPI HFONT       WINAPI CreateFontW(INT,INT,INT,INT,INT,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,LPCWSTR);
#define                      CreateFont WINELIB_NAME_AW(CreateFont)
WINGDIAPI HFONT       WINAPI CreateFontIndirectA(const LOGFONTA*);
WINGDIAPI HFONT       WINAPI CreateFontIndirectW(const LOGFONTW*);
#define                      CreateFontIndirect WINELIB_NAME_AW(CreateFontIndirect)
WINGDIAPI HFONT       WINAPI CreateFontIndirectExA(const ENUMLOGFONTEXDVA*);
WINGDIAPI HFONT       WINAPI CreateFontIndirectExW(const ENUMLOGFONTEXDVW*);
#define                      CreateFontIndirectEx WINELIB_NAME_AW(CreateFontIndirectEx)
WINGDIAPI HPALETTE    WINAPI CreateHalftonePalette(HDC);
WINGDIAPI HBRUSH      WINAPI CreateHatchBrush(INT,COLORREF);
WINGDIAPI HDC         WINAPI CreateICA(LPCSTR,LPCSTR,LPCSTR,const DEVMODEA*);
WINGDIAPI HDC         WINAPI CreateICW(LPCWSTR,LPCWSTR,LPCWSTR,const DEVMODEW*);
#define                      CreateIC WINELIB_NAME_AW(CreateIC)
WINGDIAPI HDC         WINAPI CreateMetaFileA(LPCSTR);
WINGDIAPI HDC         WINAPI CreateMetaFileW(LPCWSTR);
#define                      CreateMetaFile WINELIB_NAME_AW(CreateMetaFile)
WINGDIAPI HPALETTE    WINAPI CreatePalette(const LOGPALETTE*);
WINGDIAPI HBRUSH      WINAPI CreatePatternBrush(HBITMAP);
WINGDIAPI HPEN        WINAPI CreatePen(INT,INT,COLORREF);
WINGDIAPI HPEN        WINAPI CreatePenIndirect(const LOGPEN*);
WINGDIAPI HRGN        WINAPI CreatePolyPolygonRgn(const POINT*,const INT*,INT,INT);
WINGDIAPI HRGN        WINAPI CreatePolygonRgn(const POINT*,INT,INT);
WINGDIAPI HRGN        WINAPI CreateRectRgn(INT,INT,INT,INT);
WINGDIAPI HRGN        WINAPI CreateRectRgnIndirect(const RECT*);
WINGDIAPI HRGN        WINAPI CreateRoundRectRgn(INT,INT,INT,INT,INT,INT);
WINGDIAPI BOOL        WINAPI CreateScalableFontResourceA(DWORD,LPCSTR,LPCSTR,LPCSTR);
WINGDIAPI BOOL        WINAPI CreateScalableFontResourceW(DWORD,LPCWSTR,LPCWSTR,LPCWSTR);
#define                      CreateScalableFontResource WINELIB_NAME_AW(CreateScalableFontResource)
WINGDIAPI HBRUSH      WINAPI CreateSolidBrush(COLORREF);
WINGDIAPI BOOL        WINAPI DPtoLP(HDC,LPPOINT,INT);
WINGDIAPI BOOL        WINAPI DeleteColorSpace(HCOLORSPACE);
WINGDIAPI BOOL        WINAPI DeleteDC(HDC);
WINGDIAPI BOOL        WINAPI DeleteEnhMetaFile(HENHMETAFILE);
WINGDIAPI BOOL        WINAPI DeleteMetaFile(HMETAFILE);
WINGDIAPI BOOL        WINAPI DeleteObject(HGDIOBJ);
WINGDIAPI INT         WINAPI DescribePixelFormat(HDC,int,UINT,LPPIXELFORMATDESCRIPTOR);
WINGDIAPI INT         WINAPI DrawEscape(HDC,INT,INT,LPCSTR);
WINGDIAPI BOOL        WINAPI Ellipse(HDC,INT,INT,INT,INT);
WINGDIAPI INT         WINAPI EndDoc(HDC);
WINGDIAPI BOOL        WINAPI EndPath(HDC);
WINGDIAPI BOOL        WINAPI EnumEnhMetaFile(HDC,HENHMETAFILE,ENHMFENUMPROC,LPVOID,const RECT*);
WINGDIAPI INT         WINAPI EnumFontFamiliesA(HDC,LPCSTR,FONTENUMPROCA,LPARAM);
WINGDIAPI INT         WINAPI EnumFontFamiliesW(HDC,LPCWSTR,FONTENUMPROCW,LPARAM);
#define                      EnumFontFamilies WINELIB_NAME_AW(EnumFontFamilies)
WINGDIAPI INT         WINAPI EnumFontFamiliesExA(HDC,LPLOGFONTA,FONTENUMPROCA,LPARAM,DWORD);
WINGDIAPI INT         WINAPI EnumFontFamiliesExW(HDC,LPLOGFONTW,FONTENUMPROCW,LPARAM,DWORD);
#define                      EnumFontFamiliesEx WINELIB_NAME_AW(EnumFontFamiliesEx)
WINGDIAPI INT         WINAPI EnumFontsA(HDC,LPCSTR,FONTENUMPROCA,LPARAM);
WINGDIAPI INT         WINAPI EnumFontsW(HDC,LPCWSTR,FONTENUMPROCW,LPARAM);
#define                      EnumFonts WINELIB_NAME_AW(EnumFonts)
WINGDIAPI INT         WINAPI EnumICMProfilesA(HDC,ICMENUMPROCA,LPARAM);
WINGDIAPI INT         WINAPI EnumICMProfilesW(HDC,ICMENUMPROCW,LPARAM);
#define                      EnumICMProfiles WINELIB_NAME_AW(EnumICMProfiles)
WINGDIAPI BOOL        WINAPI EnumMetaFile(HDC,HMETAFILE,MFENUMPROC,LPARAM);
WINGDIAPI INT         WINAPI EnumObjects(HDC,INT,GOBJENUMPROC,LPARAM);
WINGDIAPI BOOL        WINAPI EqualRgn(HRGN,HRGN);
WINGDIAPI INT         WINAPI Escape(HDC,INT,INT,LPCSTR,LPVOID);
WINGDIAPI INT         WINAPI ExcludeClipRect(HDC,INT,INT,INT,INT);
WINGDIAPI HPEN        WINAPI ExtCreatePen(DWORD,DWORD,const LOGBRUSH*,DWORD,const DWORD*);
WINGDIAPI HRGN        WINAPI ExtCreateRegion(const XFORM*,DWORD,const RGNDATA*);
WINGDIAPI INT         WINAPI ExtEscape(HDC,INT,INT,LPCSTR,INT,LPSTR);
WINGDIAPI BOOL        WINAPI ExtFloodFill(HDC,INT,INT,COLORREF,UINT);
WINGDIAPI INT         WINAPI ExtSelectClipRgn(HDC,HRGN,INT);
WINGDIAPI BOOL        WINAPI ExtTextOutA(HDC,INT,INT,UINT,const RECT*,LPCSTR,UINT,const INT*);
WINGDIAPI BOOL        WINAPI ExtTextOutW(HDC,INT,INT,UINT,const RECT*,LPCWSTR,UINT,const INT*);
#define                      ExtTextOut WINELIB_NAME_AW(ExtTextOut)
WINGDIAPI BOOL        WINAPI FillPath(HDC);
WINGDIAPI BOOL        WINAPI FillRgn(HDC,HRGN,HBRUSH);
WINGDIAPI BOOL        WINAPI FixBrushOrgEx(HDC,INT,INT,LPPOINT);
WINGDIAPI BOOL        WINAPI FlattenPath(HDC);
WINGDIAPI BOOL        WINAPI FloodFill(HDC,INT,INT,COLORREF);
WINGDIAPI BOOL        WINAPI FrameRgn(HDC,HRGN,HBRUSH,INT,INT);
WINGDIAPI BOOL        WINAPI GdiAlphaBlend(HDC,int,int,int,int,HDC,int,int,int,int,BLENDFUNCTION);
WINGDIAPI BOOL        WINAPI GdiComment(HDC,UINT,const BYTE *);
WINGDIAPI DEVMODEW *  WINAPI GdiConvertToDevmodeW(const DEVMODEA *);
WINGDIAPI BOOL        WINAPI GdiFlush(void);
WINGDIAPI DWORD       WINAPI GdiGetBatchLimit(void);
WINGDIAPI LONG        WINAPI GdiGetCharDimensions(HDC, LPTEXTMETRICW, LONG *);
WINGDIAPI DWORD       WINAPI GdiGetCodePage(HDC);
WINGDIAPI BOOL        WINAPI GdiGradientFill(HDC,PTRIVERTEX,ULONG,PVOID,ULONG,ULONG);
WINGDIAPI BOOL        WINAPI GdiIsMetaFileDC(HDC);
WINGDIAPI BOOL        WINAPI GdiIsMetaPrintDC(HDC);
WINGDIAPI BOOL        WINAPI GdiIsPlayMetafileDC(HDC);
WINGDIAPI DWORD       WINAPI GdiSetBatchLimit(DWORD);
WINGDIAPI BOOL        WINAPI GdiTransparentBlt(HDC,int,int,int,int,HDC,int,int,int,int,UINT);
WINGDIAPI INT         WINAPI GetArcDirection(HDC);
WINGDIAPI BOOL        WINAPI GetAspectRatioFilterEx(HDC,LPSIZE);
WINGDIAPI LONG        WINAPI GetBitmapBits(HBITMAP,LONG,LPVOID);
WINGDIAPI BOOL        WINAPI GetBitmapDimensionEx(HBITMAP,LPSIZE);
WINGDIAPI BOOL        WINAPI GetBrushOrgEx(HDC,LPPOINT);
WINGDIAPI COLORREF    WINAPI GetBkColor(HDC);
WINGDIAPI INT         WINAPI GetBkMode(HDC);
WINGDIAPI UINT        WINAPI GetBoundsRect(HDC,LPRECT,UINT);
WINGDIAPI BOOL        WINAPI GetCharABCWidthsA(HDC,UINT,UINT,LPABC);
WINGDIAPI BOOL        WINAPI GetCharABCWidthsW(HDC,UINT,UINT,LPABC);
#define                      GetCharABCWidths WINELIB_NAME_AW(GetCharABCWidths)
WINGDIAPI BOOL        WINAPI GetCharABCWidthsFloatA(HDC,UINT,UINT,LPABCFLOAT);
WINGDIAPI BOOL        WINAPI GetCharABCWidthsFloatW(HDC,UINT,UINT,LPABCFLOAT);
#define                      GetCharABCWidthsFloat WINELIB_NAME_AW(GetCharABCWidthsFloat)
WINGDIAPI BOOL        WINAPI GetCharABCWidthsI(HDC,UINT,UINT,LPWORD,LPABC);
WINGDIAPI DWORD       WINAPI GetCharacterPlacementA(HDC,LPCSTR,INT,INT,GCP_RESULTSA*,DWORD);
WINGDIAPI DWORD       WINAPI GetCharacterPlacementW(HDC,LPCWSTR,INT,INT,GCP_RESULTSW*,DWORD);
#define                      GetCharacterPlacement WINELIB_NAME_AW(GetCharacterPlacement)
WINGDIAPI BOOL        WINAPI GetCharWidth32A(HDC,UINT,UINT,LPINT);
WINGDIAPI BOOL        WINAPI GetCharWidth32W(HDC,UINT,UINT,LPINT);
#define                      GetCharWidth32 WINELIB_NAME_AW(GetCharWidth32)
WINGDIAPI BOOL        WINAPI GetCharWidthA(HDC,UINT,UINT,LPINT);
WINGDIAPI BOOL        WINAPI GetCharWidthI(HDC,UINT,UINT,LPWORD,LPINT);
WINGDIAPI BOOL        WINAPI GetCharWidthW(HDC,UINT,UINT,LPINT);
#define                      GetCharWidth WINELIB_NAME_AW(GetCharWidth)
WINGDIAPI BOOL        WINAPI GetCharWidthFloatA(HDC,UINT,UINT,PFLOAT);
WINGDIAPI BOOL        WINAPI GetCharWidthFloatW(HDC,UINT,UINT,PFLOAT);
#define                      GetCharWidthFloat WINELIB_NAME_AW(GetCharWidthFloat)
WINGDIAPI INT         WINAPI GetClipBox(HDC,LPRECT);
WINGDIAPI INT         WINAPI GetClipRgn(HDC,HRGN);
WINGDIAPI BOOL        WINAPI GetColorAdjustment(HDC, LPCOLORADJUSTMENT);
WINGDIAPI HCOLORSPACE WINAPI GetColorSpace(HDC);
WINGDIAPI HGDIOBJ     WINAPI GetCurrentObject(HDC,UINT);
WINGDIAPI BOOL        WINAPI GetCurrentPositionEx(HDC,LPPOINT);
WINGDIAPI INT         WINAPI GetDeviceCaps(HDC,INT);
WINGDIAPI BOOL        WINAPI GetDeviceGammaRamp(HDC,LPVOID);
WINGDIAPI COLORREF    WINAPI GetDCBrushColor(HDC);
WINGDIAPI BOOL        WINAPI GetDCOrgEx(HDC,LPPOINT);
WINGDIAPI COLORREF    WINAPI GetDCPenColor(HDC);
WINGDIAPI UINT        WINAPI GetDIBColorTable(HDC,UINT,UINT,RGBQUAD*);
WINGDIAPI INT         WINAPI GetDIBits(HDC,HBITMAP,UINT,UINT,LPVOID,LPBITMAPINFO,UINT);
WINGDIAPI HENHMETAFILE WINAPI GetEnhMetaFileA(LPCSTR);
WINGDIAPI HENHMETAFILE WINAPI GetEnhMetaFileW(LPCWSTR);
#define                      GetEnhMetaFile WINELIB_NAME_AW(GetEnhMetaFile)
WINGDIAPI UINT        WINAPI GetEnhMetaFileBits(HENHMETAFILE,UINT,LPBYTE);
WINGDIAPI UINT        WINAPI GetEnhMetaFileDescriptionA(HENHMETAFILE,UINT,LPSTR);
WINGDIAPI UINT        WINAPI GetEnhMetaFileDescriptionW(HENHMETAFILE,UINT,LPWSTR);
#define                      GetEnhMetaFileDescription WINELIB_NAME_AW(GetEnhMetaFileDescription)
WINGDIAPI UINT        WINAPI GetEnhMetaFileHeader(HENHMETAFILE,UINT,LPENHMETAHEADER);
WINGDIAPI UINT        WINAPI GetEnhMetaFilePaletteEntries(HENHMETAFILE,UINT,LPPALETTEENTRY);
WINGDIAPI DWORD       WINAPI GetFontData(HDC,DWORD,DWORD,LPVOID,DWORD);
WINGDIAPI DWORD       WINAPI GetFontLanguageInfo(HDC);
WINGDIAPI DWORD       WINAPI GetFontUnicodeRanges(HDC,LPGLYPHSET);
WINGDIAPI DWORD       WINAPI GetGlyphIndicesA(HDC,LPCSTR,INT,LPWORD,DWORD);
WINGDIAPI DWORD       WINAPI GetGlyphIndicesW(HDC,LPCWSTR,INT,LPWORD,DWORD);
#define                    GetGlyphIndices WINELIB_NAME_AW(GetGlyphIndices)
WINGDIAPI DWORD       WINAPI GetGlyphOutlineA(HDC,UINT,UINT,LPGLYPHMETRICS,DWORD,LPVOID,const MAT2*);
WINGDIAPI DWORD       WINAPI GetGlyphOutlineW(HDC,UINT,UINT,LPGLYPHMETRICS,DWORD,LPVOID,const MAT2*);
#define                      GetGlyphOutline WINELIB_NAME_AW(GetGlyphOutline)
WINGDIAPI INT         WINAPI GetGraphicsMode(HDC);
WINGDIAPI BOOL        WINAPI GetICMProfileA(HDC,LPDWORD,LPSTR);
WINGDIAPI BOOL        WINAPI GetICMProfileW(HDC,LPDWORD,LPWSTR);
#define                      GetICMProfile WINELIB_NAME_AW(GetICMProfile)
WINGDIAPI DWORD       WINAPI GetKerningPairsA(HDC,DWORD,LPKERNINGPAIR);
WINGDIAPI DWORD       WINAPI GetKerningPairsW(HDC,DWORD,LPKERNINGPAIR);
#define                      GetKerningPairs WINELIB_NAME_AW(GetKerningPairs)
WINGDIAPI DWORD       WINAPI GetLayout(HDC);
WINGDIAPI BOOL        WINAPI GetLogColorSpaceA(HCOLORSPACE,LPLOGCOLORSPACEA,DWORD);
WINGDIAPI BOOL        WINAPI GetLogColorSpaceW(HCOLORSPACE,LPLOGCOLORSPACEW,DWORD);
#define                      GetLogColorSpace WINELIB_NAME_AW(GetLogColorSpace)
WINGDIAPI INT         WINAPI GetMapMode(HDC);
WINGDIAPI HMETAFILE   WINAPI GetMetaFileA(LPCSTR);
WINGDIAPI HMETAFILE   WINAPI GetMetaFileW(LPCWSTR);
#define                      GetMetaFile WINELIB_NAME_AW(GetMetaFile)
WINGDIAPI UINT        WINAPI GetMetaFileBitsEx(HMETAFILE,UINT,LPVOID);
WINGDIAPI INT         WINAPI GetMetaRgn(HDC,HRGN);
WINGDIAPI BOOL        WINAPI GetMiterLimit(HDC, PFLOAT);
WINGDIAPI DWORD       WINAPI GetNearestColor(HDC,DWORD);
WINGDIAPI UINT        WINAPI GetNearestPaletteIndex(HPALETTE,COLORREF);
WINGDIAPI INT         WINAPI GetObjectA(HGDIOBJ,INT,LPVOID);
WINGDIAPI INT         WINAPI GetObjectW(HGDIOBJ,INT,LPVOID);
#define                      GetObject WINELIB_NAME_AW(GetObject)
WINGDIAPI DWORD       WINAPI GetObjectType(HGDIOBJ);
WINGDIAPI UINT        WINAPI GetOutlineTextMetricsA(HDC,UINT,LPOUTLINETEXTMETRICA);
WINGDIAPI UINT        WINAPI GetOutlineTextMetricsW(HDC,UINT,LPOUTLINETEXTMETRICW);
#define                      GetOutlineTextMetrics WINELIB_NAME_AW(GetOutlineTextMetrics)
WINGDIAPI UINT        WINAPI GetPaletteEntries(HPALETTE,UINT,UINT,LPPALETTEENTRY);
WINGDIAPI INT         WINAPI GetPath(HDC,LPPOINT,LPBYTE,INT);
WINGDIAPI COLORREF    WINAPI GetPixel(HDC,INT,INT);
WINGDIAPI INT         WINAPI GetPixelFormat(HDC);
WINGDIAPI INT         WINAPI GetPolyFillMode(HDC);
WINGDIAPI INT         WINAPI GetRandomRgn(HDC,HRGN,INT);
WINGDIAPI BOOL        WINAPI GetRasterizerCaps(LPRASTERIZER_STATUS,UINT);
WINGDIAPI DWORD       WINAPI GetRegionData(HRGN,DWORD,LPRGNDATA);
WINGDIAPI INT         WINAPI GetRelAbs(HDC,DWORD);
WINGDIAPI INT         WINAPI GetRgnBox(HRGN,LPRECT);
WINGDIAPI INT         WINAPI GetROP2(HDC);
WINGDIAPI HGDIOBJ     WINAPI GetStockObject(INT);
WINGDIAPI INT         WINAPI GetStretchBltMode(HDC);
WINGDIAPI UINT        WINAPI GetSystemPaletteEntries(HDC,UINT,UINT,LPPALETTEENTRY);
WINGDIAPI UINT        WINAPI GetSystemPaletteUse(HDC);
WINGDIAPI UINT        WINAPI GetTextAlign(HDC);
WINGDIAPI INT         WINAPI GetTextCharacterExtra(HDC);
WINGDIAPI UINT        WINAPI GetTextCharset(HDC);
WINGDIAPI UINT        WINAPI GetTextCharsetInfo(HDC,LPFONTSIGNATURE,DWORD);
WINGDIAPI COLORREF    WINAPI GetTextColor(HDC);
WINGDIAPI BOOL        WINAPI GetTextExtentExPointA(HDC,LPCSTR,INT,INT,LPINT,LPINT,LPSIZE);
WINGDIAPI BOOL        WINAPI GetTextExtentExPointW(HDC,LPCWSTR,INT,INT,LPINT,LPINT,LPSIZE);
#define                      GetTextExtentExPoint WINELIB_NAME_AW(GetTextExtentExPoint)
WINGDIAPI BOOL        WINAPI GetTextExtentPointA(HDC,LPCSTR,INT,LPSIZE);
WINGDIAPI BOOL        WINAPI GetTextExtentPointW(HDC,LPCWSTR,INT,LPSIZE);
#define                      GetTextExtentPoint WINELIB_NAME_AW(GetTextExtentPoint)
WINGDIAPI BOOL        WINAPI GetTextExtentPoint32A(HDC,LPCSTR,INT,LPSIZE);
WINGDIAPI BOOL        WINAPI GetTextExtentPoint32W(HDC,LPCWSTR,INT,LPSIZE);
#define                      GetTextExtentPoint32 WINELIB_NAME_AW(GetTextExtentPoint32)
WINGDIAPI BOOL        WINAPI GetTextExtentExPointI(HDC,const WORD*,INT,INT,LPINT,LPINT,LPSIZE);
WINGDIAPI BOOL        WINAPI GetTextExtentPointI(HDC,const WORD*,INT,LPSIZE);
WINGDIAPI INT         WINAPI GetTextFaceA(HDC,INT,LPSTR);
WINGDIAPI INT         WINAPI GetTextFaceW(HDC,INT,LPWSTR);
#define                      GetTextFace WINELIB_NAME_AW(GetTextFace)
WINGDIAPI BOOL        WINAPI GetTextMetricsA(HDC,LPTEXTMETRICA);
WINGDIAPI BOOL        WINAPI GetTextMetricsW(HDC,LPTEXTMETRICW);
#define                      GetTextMetrics WINELIB_NAME_AW(GetTextMetrics)
WINGDIAPI BOOL        WINAPI GetTransform(HDC,DWORD,XFORM*);
WINGDIAPI BOOL        WINAPI GetViewportExtEx(HDC,LPSIZE);
WINGDIAPI BOOL        WINAPI GetViewportOrgEx(HDC,LPPOINT);
WINGDIAPI BOOL        WINAPI GetWindowExtEx(HDC,LPSIZE);
WINGDIAPI BOOL        WINAPI GetWindowOrgEx(HDC,LPPOINT);
WINGDIAPI UINT        WINAPI GetWinMetaFileBits(HENHMETAFILE,UINT,LPBYTE,INT,HDC);
WINGDIAPI BOOL        WINAPI GetWorldTransform(HDC,LPXFORM);
WINGDIAPI BOOL        WINAPI GradientFill(HDC,PTRIVERTEX,ULONG,PVOID,ULONG,ULONG);
WINGDIAPI INT         WINAPI IntersectClipRect(HDC,INT,INT,INT,INT);
WINGDIAPI BOOL        WINAPI InvertRgn(HDC,HRGN);
WINGDIAPI BOOL        WINAPI LineDDA(INT,INT,INT,INT,LINEDDAPROC,LPARAM);
WINGDIAPI BOOL        WINAPI LineTo(HDC,INT,INT);
WINGDIAPI BOOL        WINAPI LPtoDP(HDC,LPPOINT,INT);
WINGDIAPI BOOL        WINAPI MaskBlt(HDC,INT,INT,INT,INT,HDC,INT,INT,HBITMAP,INT,INT,DWORD);
WINGDIAPI BOOL        WINAPI MirrorRgn(HWND,HRGN);
WINGDIAPI BOOL        WINAPI ModifyWorldTransform(HDC,const XFORM *, DWORD);
WINGDIAPI BOOL        WINAPI MoveToEx(HDC,INT,INT,LPPOINT);
WINGDIAPI INT         WINAPI OffsetClipRgn(HDC,INT,INT);
WINGDIAPI INT         WINAPI OffsetRgn(HRGN,INT,INT);
WINGDIAPI BOOL        WINAPI OffsetViewportOrgEx(HDC,INT,INT,LPPOINT);
WINGDIAPI BOOL        WINAPI OffsetWindowOrgEx(HDC,INT,INT,LPPOINT);
WINGDIAPI BOOL        WINAPI PaintRgn(HDC,HRGN);
WINGDIAPI BOOL        WINAPI PatBlt(HDC,INT,INT,INT,INT,DWORD);
WINGDIAPI HRGN        WINAPI PathToRegion(HDC);
WINGDIAPI BOOL        WINAPI Pie(HDC,INT,INT,INT,INT,INT,INT,INT,INT);
WINGDIAPI BOOL        WINAPI PlayEnhMetaFile(HDC,HENHMETAFILE,const RECT*);
WINGDIAPI BOOL        WINAPI PlayEnhMetaFileRecord(HDC,LPHANDLETABLE,const ENHMETARECORD*,UINT);
WINGDIAPI BOOL        WINAPI PlayMetaFile(HDC,HMETAFILE);
WINGDIAPI BOOL        WINAPI PlayMetaFileRecord(HDC,LPHANDLETABLE,LPMETARECORD,UINT);
WINGDIAPI BOOL        WINAPI PlgBlt(HDC,const POINT*,HDC,INT,INT,INT,INT,HBITMAP,INT,INT);
WINGDIAPI BOOL        WINAPI PolyBezier(HDC,const POINT*,DWORD);
WINGDIAPI BOOL        WINAPI PolyBezierTo(HDC,const POINT*,DWORD);
WINGDIAPI BOOL        WINAPI PolyDraw(HDC,const POINT*,const BYTE*,DWORD);
WINGDIAPI BOOL        WINAPI PolyPolygon(HDC,const POINT*,const INT*,UINT);
WINGDIAPI BOOL        WINAPI PolyPolyline(HDC,const POINT*,const DWORD*,DWORD);
WINGDIAPI BOOL        WINAPI Polygon(HDC,const POINT*,INT);
WINGDIAPI BOOL        WINAPI Polyline(HDC,const POINT*,INT);
WINGDIAPI BOOL        WINAPI PolylineTo(HDC,const POINT*,DWORD);
WINGDIAPI BOOL        WINAPI PtInRegion(HRGN,INT,INT);
WINGDIAPI BOOL        WINAPI PtVisible(HDC,INT,INT);
WINGDIAPI UINT        WINAPI RealizePalette(HDC);
WINGDIAPI BOOL        WINAPI Rectangle(HDC,INT,INT,INT,INT);
WINGDIAPI BOOL        WINAPI RectInRegion(HRGN,const RECT *);
WINGDIAPI BOOL        WINAPI RectVisible(HDC,const RECT*);
WINGDIAPI BOOL        WINAPI RemoveFontMemResourceEx(HANDLE);
WINGDIAPI BOOL        WINAPI RemoveFontResourceA(LPCSTR);
WINGDIAPI BOOL        WINAPI RemoveFontResourceW(LPCWSTR);
#define                      RemoveFontResource WINELIB_NAME_AW(RemoveFontResource)
WINGDIAPI BOOL        WINAPI RemoveFontResourceExA(LPCSTR, DWORD, PVOID);
WINGDIAPI BOOL        WINAPI RemoveFontResourceExW(LPCWSTR, DWORD, PVOID);
#define                      RemoveFontResourceEx WINELIB_NAME_AW(RemoveFontResourceEx)
WINGDIAPI HDC         WINAPI ResetDCA(HDC,const DEVMODEA *);
WINGDIAPI HDC         WINAPI ResetDCW(HDC,const DEVMODEW *);
#define                      ResetDC WINELIB_NAME_AW(ResetDC)
WINGDIAPI BOOL        WINAPI ResizePalette(HPALETTE,UINT);
WINGDIAPI BOOL        WINAPI RestoreDC(HDC,INT);
WINGDIAPI BOOL        WINAPI RoundRect(HDC,INT,INT,INT,INT,INT,INT);
WINGDIAPI INT         WINAPI SaveDC(HDC);
WINGDIAPI BOOL        WINAPI ScaleViewportExtEx(HDC,INT,INT,INT,INT,LPSIZE);
WINGDIAPI BOOL        WINAPI ScaleWindowExtEx(HDC,INT,INT,INT,INT,LPSIZE);
WINGDIAPI BOOL        WINAPI SelectClipPath(HDC,INT);
WINGDIAPI INT         WINAPI SelectClipRgn(HDC,HRGN);
WINGDIAPI HGDIOBJ     WINAPI SelectObject(HDC,HGDIOBJ);
WINGDIAPI HPALETTE    WINAPI SelectPalette(HDC,HPALETTE,BOOL);
WINGDIAPI INT         WINAPI SetAbortProc(HDC,ABORTPROC);
WINGDIAPI INT         WINAPI SetArcDirection(HDC,INT);
WINGDIAPI LONG        WINAPI SetBitmapBits(HBITMAP,LONG,LPCVOID);
WINGDIAPI BOOL        WINAPI SetBitmapDimensionEx(HBITMAP,INT,INT,LPSIZE);
WINGDIAPI COLORREF    WINAPI SetBkColor(HDC,COLORREF);
WINGDIAPI INT         WINAPI SetBkMode(HDC,INT);
WINGDIAPI UINT        WINAPI SetBoundsRect(HDC,const RECT*,UINT);
WINGDIAPI BOOL        WINAPI SetBrushOrgEx(HDC,INT,INT,LPPOINT);
WINGDIAPI BOOL        WINAPI SetColorAdjustment(HDC,const COLORADJUSTMENT*);
WINGDIAPI HCOLORSPACE WINAPI SetColorSpace(HDC,HCOLORSPACE);
WINGDIAPI BOOL        WINAPI SetDeviceGammaRamp(HDC,LPVOID);
WINGDIAPI COLORREF    WINAPI SetDCBrushColor(HDC,COLORREF);
WINGDIAPI COLORREF    WINAPI SetDCPenColor(HDC, COLORREF);
WINGDIAPI UINT        WINAPI SetDIBColorTable(HDC,UINT,UINT,const RGBQUAD*);
WINGDIAPI INT         WINAPI SetDIBits(HDC,HBITMAP,UINT,UINT,LPCVOID,const BITMAPINFO*,UINT);
WINGDIAPI INT         WINAPI SetDIBitsToDevice(HDC,INT,INT,DWORD,DWORD,INT,INT,UINT,UINT,LPCVOID,const BITMAPINFO*,UINT);
WINGDIAPI HENHMETAFILE WINAPI SetEnhMetaFileBits(UINT,const BYTE *);
WINGDIAPI INT         WINAPI SetGraphicsMode(HDC,INT);
WINGDIAPI INT         WINAPI SetICMMode(HDC,INT);
WINGDIAPI BOOL        WINAPI SetICMProfileA(HDC,LPSTR);
WINGDIAPI BOOL        WINAPI SetICMProfileW(HDC,LPWSTR);
#define                      SetICMProfile WINELIB_NAME_AW(SetICMProfile)
WINGDIAPI DWORD       WINAPI SetLayout(HDC,DWORD);
WINGDIAPI INT         WINAPI SetMapMode(HDC,INT);
WINGDIAPI DWORD       WINAPI SetMapperFlags(HDC,DWORD);
WINGDIAPI HMETAFILE   WINAPI SetMetaFileBitsEx(UINT,const BYTE*);
WINGDIAPI INT         WINAPI SetMetaRgn(HDC);
WINGDIAPI BOOL        WINAPI SetMiterLimit(HDC, FLOAT, PFLOAT);
WINGDIAPI UINT        WINAPI SetPaletteEntries(HPALETTE,UINT,UINT,const PALETTEENTRY*);
WINGDIAPI COLORREF    WINAPI SetPixel(HDC,INT,INT,COLORREF);
WINGDIAPI BOOL        WINAPI SetPixelV(HDC,INT,INT,COLORREF);
WINGDIAPI BOOL        WINAPI SetPixelFormat(HDC,int,const PIXELFORMATDESCRIPTOR*);
WINGDIAPI INT         WINAPI SetPolyFillMode(HDC,INT);
WINGDIAPI BOOL        WINAPI SetRectRgn(HRGN,INT,INT,INT,INT);
WINGDIAPI INT         WINAPI SetRelAbs(HDC,INT);
WINGDIAPI INT         WINAPI SetROP2(HDC,INT);
WINGDIAPI INT         WINAPI SetStretchBltMode(HDC,INT);
WINGDIAPI UINT        WINAPI SetSystemPaletteUse(HDC,UINT);
WINGDIAPI UINT        WINAPI SetTextAlign(HDC,UINT);
WINGDIAPI INT         WINAPI SetTextCharacterExtra(HDC,INT);
WINGDIAPI COLORREF    WINAPI SetTextColor(HDC,COLORREF);
WINGDIAPI BOOL        WINAPI SetTextJustification(HDC,INT,INT);
WINGDIAPI BOOL        WINAPI SetViewportExtEx(HDC,INT,INT,LPSIZE);
WINGDIAPI BOOL        WINAPI SetViewportOrgEx(HDC,INT,INT,LPPOINT);
WINGDIAPI BOOL        WINAPI SetWindowExtEx(HDC,INT,INT,LPSIZE);
WINGDIAPI BOOL        WINAPI SetWindowOrgEx(HDC,INT,INT,LPPOINT);
WINGDIAPI HENHMETAFILE WINAPI SetWinMetaFileBits(UINT,const BYTE*,HDC,const METAFILEPICT *);
WINGDIAPI BOOL        WINAPI SetWorldTransform(HDC,const XFORM*);
WINGDIAPI INT         WINAPI StartDocA(HDC,const DOCINFOA*);
WINGDIAPI INT         WINAPI StartDocW(HDC,const DOCINFOW*);
#define                      StartDoc WINELIB_NAME_AW(StartDoc)
WINGDIAPI INT         WINAPI StartPage(HDC);
WINGDIAPI INT         WINAPI EndPage(HDC);
WINGDIAPI BOOL        WINAPI StretchBlt(HDC,INT,INT,INT,INT,HDC,INT,INT,INT,INT,DWORD);
WINGDIAPI INT         WINAPI StretchDIBits(HDC,INT,INT,INT,INT,INT,INT,INT,INT,const VOID*,const BITMAPINFO*,UINT,DWORD);
WINGDIAPI BOOL        WINAPI StrokeAndFillPath(HDC);
WINGDIAPI BOOL        WINAPI StrokePath(HDC);
WINGDIAPI BOOL        WINAPI SwapBuffers(HDC);
WINGDIAPI BOOL        WINAPI TextOutA(HDC,INT,INT,LPCSTR,INT);
WINGDIAPI BOOL        WINAPI TextOutW(HDC,INT,INT,LPCWSTR,INT);
#define                      TextOut WINELIB_NAME_AW(TextOut)
WINGDIAPI BOOL        WINAPI TranslateCharsetInfo(LPDWORD,LPCHARSETINFO,DWORD);
WINGDIAPI BOOL        WINAPI TransparentBlt(HDC,int,int,int,int,HDC,int,int,int,int,UINT);
WINGDIAPI BOOL        WINAPI UnrealizeObject(HGDIOBJ);
WINGDIAPI BOOL        WINAPI UpdateColors(HDC);
WINGDIAPI BOOL        WINAPI UpdateICMRegKeyA(DWORD,LPSTR,LPSTR,UINT);
WINGDIAPI BOOL        WINAPI UpdateICMRegKeyW(DWORD,LPWSTR,LPWSTR,UINT);
#define                      UpdateICMRegKey WINELIB_NAME_AW(UpdateICMRegKey)
WINGDIAPI BOOL        WINAPI WidenPath(HDC);
WINGDIAPI BOOL        WINAPI PolyTextOutA(HDC,const POLYTEXTA*,INT);
WINGDIAPI BOOL        WINAPI PolyTextOutW(HDC,const POLYTEXTW*,INT);
#define                      PolyTextOut WINELIB_NAME_AW(PolyTextOut)

/* These defines are used by wglSwapLayerBuffers */
#define WGL_SWAP_MAIN_PLANE (1 <<  0)
#define WGL_SWAP_OVERLAY1   (1 <<  1)
#define WGL_SWAP_OVERLAY2   (1 <<  2)
#define WGL_SWAP_OVERLAY3   (1 <<  3)
#define WGL_SWAP_OVERLAY4   (1 <<  4)
#define WGL_SWAP_OVERLAY5   (1 <<  5)
#define WGL_SWAP_OVERLAY6   (1 <<  6)
#define WGL_SWAP_OVERLAY7   (1 <<  7)
#define WGL_SWAP_OVERLAY8   (1 <<  8)
#define WGL_SWAP_OVERLAY9   (1 <<  9)
#define WGL_SWAP_OVERLAY10  (1 << 10)
#define WGL_SWAP_OVERLAY11  (1 << 11)
#define WGL_SWAP_OVERLAY12  (1 << 12)
#define WGL_SWAP_OVERLAY13  (1 << 13)
#define WGL_SWAP_OVERLAY14  (1 << 14)
#define WGL_SWAP_OVERLAY15  (1 << 15)
#define WGL_SWAP_UNDERLAY1  (1 << 16)
#define WGL_SWAP_UNDERLAY2  (1 << 17)
#define WGL_SWAP_UNDERLAY3  (1 << 18)
#define WGL_SWAP_UNDERLAY4  (1 << 19)
#define WGL_SWAP_UNDERLAY5  (1 << 20)
#define WGL_SWAP_UNDERLAY6  (1 << 21)
#define WGL_SWAP_UNDERLAY7  (1 << 22)
#define WGL_SWAP_UNDERLAY8  (1 << 23)
#define WGL_SWAP_UNDERLAY9  (1 << 24)
#define WGL_SWAP_UNDERLAY10 (1 << 25)
#define WGL_SWAP_UNDERLAY11 (1 << 26)
#define WGL_SWAP_UNDERLAY12 (1 << 27)
#define WGL_SWAP_UNDERLAY13 (1 << 28)
#define WGL_SWAP_UNDERLAY14 (1 << 29)
#define WGL_SWAP_UNDERLAY15 (1 << 30)

#define WGL_FONT_LINES      0
#define WGL_FONT_POLYGONS   1

/* WGL prototypes */
WINGDIAPI HGLRC   WINAPI wglCreateContext(HDC);
WINGDIAPI HGLRC   WINAPI wglCreateLayerContext(HDC,INT);
WINGDIAPI BOOL    WINAPI wglCopyContext(HGLRC,HGLRC,UINT);
WINGDIAPI BOOL    WINAPI wglDeleteContext(HGLRC);
WINGDIAPI BOOL    WINAPI wglDescribeLayerPlane(HDC,INT,INT,UINT,LPLAYERPLANEDESCRIPTOR);
WINGDIAPI HGLRC   WINAPI wglGetCurrentContext(void);
WINGDIAPI HDC     WINAPI wglGetCurrentDC(void);
WINGDIAPI INT     WINAPI wglGetLayerPaletteEntries(HDC,INT,INT,INT,const COLORREF *);
WINGDIAPI PROC    WINAPI wglGetProcAddress(LPCSTR);
WINGDIAPI BOOL    WINAPI wglMakeCurrent(HDC,HGLRC);
WINGDIAPI BOOL    WINAPI wglRealizeLayerPalette(HDC,INT,BOOL);
WINGDIAPI INT     WINAPI wglSetLayerPaletteEntries(HDC,INT,INT,INT,const COLORREF *);
WINGDIAPI BOOL    WINAPI wglShareLists(HGLRC,HGLRC);
WINGDIAPI BOOL    WINAPI wglSwapLayerBuffers(HDC,UINT);
WINGDIAPI BOOL    WINAPI wglUseFontBitmapsA(HDC,DWORD,DWORD,DWORD);
WINGDIAPI BOOL    WINAPI wglUseFontBitmapsW(HDC,DWORD,DWORD,DWORD);
#define                  wglUseFontBitmaps WINELIB_NAME_AW(wglUseFontBitmaps)
WINGDIAPI BOOL    WINAPI wglUseFontOutlinesA(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,INT,LPGLYPHMETRICSFLOAT);
WINGDIAPI BOOL    WINAPI wglUseFontOutlinesW(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,INT,LPGLYPHMETRICSFLOAT);
#define                  wglUseFontOutlines WINELIB_NAME_AW(wglUseFontOutlines)

#ifdef __cplusplus
}
#endif

#endif /* !NOGDI */
#endif /* _WINGDI_ */
