/*
 * MMSYSTEM - Multimedia Wine Extension ... :-)
 *
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

#ifndef __WINE_MMSYSTEM_H
#define __WINE_MMSYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

typedef LPSTR		HPSTR;          /* a huge version of LPSTR */
typedef LPCSTR		HPCSTR;         /* a huge version of LPCSTR */
typedef UINT*           LPUINT;

DECLARE_HANDLE(HDRVR);
DECLARE_HANDLE(HWAVE);
DECLARE_HANDLE(HWAVEIN);
DECLARE_HANDLE(HWAVEOUT);
DECLARE_HANDLE(HMIDI);
DECLARE_HANDLE(HMIDIIN);
DECLARE_HANDLE(HMIDIOUT);
DECLARE_HANDLE(HMIDISTRM);
DECLARE_HANDLE(HMIXER);
DECLARE_HANDLE(HMIXEROBJ);
DECLARE_HANDLE(HMMIO);

typedef HMIDI *LPHMIDI;
typedef HMIDIIN *LPHMIDIIN;
typedef HMIDIOUT *LPHMIDIOUT;
typedef HMIDISTRM *LPHMIDISTRM;
typedef HMIXER *LPHMIXER;
typedef HMIXEROBJ *LPHMIXEROBJ;
typedef HWAVEIN *LPHWAVEIN;
typedef HWAVEOUT *LPHWAVEOUT;

#include <pshpack1.h>

typedef LRESULT (CALLBACK *DRIVERPROC)(DWORD_PTR,HDRVR,UINT,LPARAM,LPARAM);

#define MAXWAVEDRIVERS	10
#define MAXMIDIDRIVERS	10
#define MAXAUXDRIVERS	10
#define MAXMCIDRIVERS	32
#define MAXMIXERDRIVERS	10

#define MAXPNAMELEN      32     /* max product name length (including NULL) */
#define MAXERRORLENGTH   256    /* max error text length (including NULL) */
#define MAX_JOYSTICKOEMVXDNAME	260

#ifndef _MCIERROR_
#define _MCIERROR_
typedef DWORD   MCIERROR;
#endif
typedef UINT	MMVERSION;
#ifndef _MCIDEVICEID_
#define _MCIDEVICEID_
typedef UINT	MCIDEVICEID;
#endif
typedef	UINT	MMRESULT;

typedef struct mmtime_tag {
    UINT    wType;
    union {
	DWORD ms;
	DWORD sample;
	DWORD cb;
        DWORD ticks;
	struct {
	    BYTE hour;
	    BYTE min;
	    BYTE sec;
	    BYTE frame;
	    BYTE fps;
	    BYTE dummy;
	    BYTE pad[2];
	} smpte;
	struct {
	    DWORD songptrpos;
	} midi;
    } u;
} MMTIME, *PMMTIME, *LPMMTIME;

#define TIME_MS         0x0001  /* time in milliseconds */
#define TIME_SAMPLES    0x0002  /* number of wave samples */
#define TIME_BYTES      0x0004  /* current byte offset */
#define TIME_SMPTE      0x0008  /* SMPTE time */
#define TIME_MIDI       0x0010  /* MIDI time */
#define TIME_TICKS	0x0020  /* MIDI ticks */

#define MM_JOY1MOVE         0x3A0           /* joystick */
#define MM_JOY2MOVE         0x3A1
#define MM_JOY1ZMOVE        0x3A2
#define MM_JOY2ZMOVE        0x3A3
#define MM_JOY1BUTTONDOWN   0x3B5
#define MM_JOY2BUTTONDOWN   0x3B6
#define MM_JOY1BUTTONUP     0x3B7
#define MM_JOY2BUTTONUP     0x3B8

#define MM_MCINOTIFY        0x3B9           /* MCI */

#define MM_WOM_OPEN         0x3BB           /* waveform output */
#define MM_WOM_CLOSE        0x3BC
#define MM_WOM_DONE         0x3BD

#define MM_WIM_OPEN         0x3BE           /* waveform input */
#define MM_WIM_CLOSE        0x3BF
#define MM_WIM_DATA         0x3C0

#define MM_MIM_OPEN         0x3C1           /* MIDI input */
#define MM_MIM_CLOSE        0x3C2
#define MM_MIM_DATA         0x3C3
#define MM_MIM_LONGDATA     0x3C4
#define MM_MIM_ERROR        0x3C5
#define MM_MIM_LONGERROR    0x3C6

#define MM_MOM_OPEN         0x3C7           /* MIDI output */
#define MM_MOM_CLOSE        0x3C8
#define MM_MOM_DONE         0x3C9
#define MM_MOM_POSITIONCB   0x3CA

#define MM_MIM_MOREDATA     0x3CC

#define MM_MIXM_LINE_CHANGE 0x3D0
#define MM_MIXM_CONTROL_CHANGE 0x3D1

#define MMSYSERR_BASE          0
#define WAVERR_BASE            32
#define MIDIERR_BASE           64
#define TIMERR_BASE            96
#define JOYERR_BASE            160
#define MCIERR_BASE            256

#define MCI_STRING_OFFSET      512
#define MCI_VD_OFFSET          1024
#define MCI_CD_OFFSET          1088
#define MCI_WAVE_OFFSET        1152
#define MCI_SEQ_OFFSET         1216

#define MMSYSERR_NOERROR      0
#define MMSYSERR_ERROR        (MMSYSERR_BASE + 1)
#define MMSYSERR_BADDEVICEID  (MMSYSERR_BASE + 2)
#define MMSYSERR_NOTENABLED   (MMSYSERR_BASE + 3)
#define MMSYSERR_ALLOCATED    (MMSYSERR_BASE + 4)
#define MMSYSERR_INVALHANDLE  (MMSYSERR_BASE + 5)
#define MMSYSERR_NODRIVER     (MMSYSERR_BASE + 6)
#define MMSYSERR_NOMEM        (MMSYSERR_BASE + 7)
#define MMSYSERR_NOTSUPPORTED (MMSYSERR_BASE + 8)
#define MMSYSERR_BADERRNUM    (MMSYSERR_BASE + 9)
#define MMSYSERR_INVALFLAG    (MMSYSERR_BASE + 10)
#define MMSYSERR_INVALPARAM   (MMSYSERR_BASE + 11)
#define MMSYSERR_HANDLEBUSY   (MMSYSERR_BASE + 12)
#define MMSYSERR_INVALIDALIAS (MMSYSERR_BASE + 13)
#define MMSYSERR_BADDB        (MMSYSERR_BASE + 14)
#define MMSYSERR_KEYNOTFOUND  (MMSYSERR_BASE + 15)
#define MMSYSERR_READERROR    (MMSYSERR_BASE + 16)
#define MMSYSERR_WRITEERROR   (MMSYSERR_BASE + 17)
#define MMSYSERR_DELETEERROR  (MMSYSERR_BASE + 18)
#define MMSYSERR_VALNOTFOUND  (MMSYSERR_BASE + 19)
#define MMSYSERR_NODRIVERCB   (MMSYSERR_BASE + 20)
#define MMSYSERR_MOREDATA     (MMSYSERR_BASE + 21)
#define MMSYSERR_LASTERROR    (MMSYSERR_BASE + 21)

#define CALLBACK_TYPEMASK       __MSABI_LONG(0x00070000)      /* callback type mask */
#define CALLBACK_NULL           __MSABI_LONG(0x00000000)      /* no callback */
#define CALLBACK_WINDOW         __MSABI_LONG(0x00010000)      /* dwCallback is a HWND */
#define CALLBACK_TASK           __MSABI_LONG(0x00020000)      /* dwCallback is a HTASK */
#define CALLBACK_THREAD		(CALLBACK_TASK)	/* dwCallback is a thread ID */
#define CALLBACK_FUNCTION       __MSABI_LONG(0x00030000)      /* dwCallback is a FARPROC */
#define CALLBACK_EVENT          __MSABI_LONG(0x00050000)      /* dwCallback is an EVENT Handler */

#define DRV_LOAD                0x0001
#define DRV_ENABLE              0x0002
#define DRV_OPEN                0x0003
#define DRV_CLOSE               0x0004
#define DRV_DISABLE             0x0005
#define DRV_FREE                0x0006
#define DRV_CONFIGURE           0x0007
#define DRV_QUERYCONFIGURE      0x0008
#define DRV_INSTALL             0x0009
#define DRV_REMOVE              0x000A
#define DRV_EXITSESSION         0x000B
#define DRV_EXITAPPLICATION     0x000C
#define DRV_POWER               0x000F

#define DRV_RESERVED            0x0800
#define DRV_MCI_FIRST           DRV_RESERVED
#define DRV_MCI_LAST            (0xFFF + DRV_MCI_FIRST)
#define DRV_USER                0x4000

#define DRVCNF_CANCEL           0x0000
#define DRVCNF_OK               0x0001
#define DRVCNF_RESTART 		0x0002

#define DRVEA_NORMALEXIT  	0x0001
#define DRVEA_ABNORMALEXIT 	0x0002

#define DRV_SUCCESS		0x0001
#define DRV_FAILURE		0x0000

#define GND_FIRSTINSTANCEONLY 	0x00000001

#define GND_FORWARD  		0x00000000
#define GND_REVERSE    		0x00000002

typedef struct tagDRVCONFIGINFO {
    DWORD   			dwDCISize;
    LPCWSTR  			lpszDCISectionName;
    LPCWSTR  			lpszDCIAliasName;
} DRVCONFIGINFO, *LPDRVCONFIGINFO;


LRESULT WINAPI DefDriverProc(DWORD_PTR,HDRVR,UINT,LPARAM,LPARAM);
/* this sounds odd, but it's the way it is. OpenDriverA even disappeared
 * from latest SDK
 */
HDRVR 	WINAPI OpenDriverA(LPCSTR szDriverName, LPCSTR szSectionName,
			   LPARAM lParam2);
HDRVR 	WINAPI OpenDriver(LPCWSTR szDriverName, LPCWSTR szSectionName,
                          LPARAM lParam2);
LRESULT WINAPI CloseDriver(HDRVR hDriver, LPARAM lParam1, LPARAM lParam2);
LRESULT WINAPI SendDriverMessage(HDRVR hDriver, UINT message,
				 LPARAM lParam1, LPARAM lParam2);
HMODULE WINAPI GetDriverModuleHandle(HDRVR hDriver);

DWORD	WINAPI GetDriverFlags(HDRVR hDriver);

typedef void (CALLBACK *LPDRVCALLBACK)(HDRVR,UINT,DWORD_PTR,DWORD_PTR,DWORD_PTR);

#ifndef MM_MICROSOFT
#define MM_MICROSOFT            1       /* Microsoft Corp. */
#endif

#define MM_MIDI_MAPPER          1       /* MIDI Mapper */
#define MM_WAVE_MAPPER          2       /* Wave Mapper */

#define MM_SNDBLST_MIDIOUT      3       /* Sound Blaster MIDI output port */
#define MM_SNDBLST_MIDIIN       4       /* Sound Blaster MIDI input port  */
#define MM_SNDBLST_SYNTH        5       /* Sound Blaster internal synthesizer */
#define MM_SNDBLST_WAVEOUT      6       /* Sound Blaster waveform output */
#define MM_SNDBLST_WAVEIN       7       /* Sound Blaster waveform input */

#define MM_ADLIB                9       /* Ad Lib-compatible synthesizer */

#define MM_MPU401_MIDIOUT       10      /* MPU401-compatible MIDI output port */
#define MM_MPU401_MIDIIN        11      /* MPU401-compatible MIDI input port */

#define MM_PC_JOYSTICK          12      /* Joystick adapter */

#define MM_CREATIVE_SBP16_WAVEOUT   104 

UINT 		WINAPI 	mmsystemGetVersion(void);
BOOL 		WINAPI	sndPlaySoundA(LPCSTR lpszSound, UINT fuSound);
BOOL 		WINAPI	sndPlaySoundW(LPCWSTR lpszSound, UINT fuSound);
#define 		sndPlaySound WINELIB_NAME_AW(sndPlaySound)
BOOL 		WINAPI 	PlaySoundA(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);
BOOL 		WINAPI 	PlaySoundW(LPCWSTR pszSound, HMODULE hmod, DWORD fdwSound);
#define 		PlaySound WINELIB_NAME_AW(PlaySound)

#define SND_SYNC            	0x0000  /* play synchronously (default) */
#define SND_ASYNC           	0x0001  /* play asynchronously */
#define SND_NODEFAULT       	0x0002  /* don't use default sound */
#define SND_MEMORY          	0x0004  /* lpszSoundName points to a memory file */
#define SND_LOOP            	0x0008  /* loop the sound until next sndPlaySound */
#define SND_NOSTOP          	0x0010  /* don't stop any currently playing sound */

#define SND_NOWAIT              __MSABI_LONG(0x00002000) /* don't wait if the driver is busy */
#define SND_ALIAS               __MSABI_LONG(0x00010000) /* name is a registry alias */
#define SND_ALIAS_ID            __MSABI_LONG(0x00110000) /* alias is a predefined ID */
#define SND_FILENAME            __MSABI_LONG(0x00020000) /* name is file name */
#define SND_RESOURCE            __MSABI_LONG(0x00040004) /* name is resource name or atom */
#define SND_PURGE               __MSABI_LONG(0x00000040) /* purge all sounds */
#define SND_APPLICATION         __MSABI_LONG(0x00000080) /* look for application specific association */

#define SND_ALIAS_START         0

#define sndAlias(ch0, ch1)              (SND_ALIAS_START + ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8)))

#define SND_ALIAS_SYSTEMASTERISK        sndAlias('S', '*')
#define SND_ALIAS_SYSTEMQUESTION        sndAlias('S', '?')
#define SND_ALIAS_SYSTEMHAND            sndAlias('S', 'H')
#define SND_ALIAS_SYSTEMEXIT            sndAlias('S', 'E')
#define SND_ALIAS_SYSTEMSTART           sndAlias('S', 'S')
#define SND_ALIAS_SYSTEMWELCOME         sndAlias('S', 'W')
#define SND_ALIAS_SYSTEMEXCLAMATION     sndAlias('S', '!')
#define SND_ALIAS_SYSTEMDEFAULT         sndAlias('S', 'D')

/* waveform audio error return values */
#define WAVERR_BADFORMAT      (WAVERR_BASE + 0)    /* unsupported wave format */
#define WAVERR_STILLPLAYING   (WAVERR_BASE + 1)    /* still something playing */
#define WAVERR_UNPREPARED     (WAVERR_BASE + 2)    /* header not prepared */
#define WAVERR_SYNC           (WAVERR_BASE + 3)    /* device is synchronous */
#define WAVERR_LASTERROR      (WAVERR_BASE + 3)    /* last error in range */

typedef LPDRVCALLBACK LPWAVECALLBACK;

#define WOM_OPEN        MM_WOM_OPEN
#define WOM_CLOSE       MM_WOM_CLOSE
#define WOM_DONE        MM_WOM_DONE
#define WIM_OPEN        MM_WIM_OPEN
#define WIM_CLOSE       MM_WIM_CLOSE
#define WIM_DATA        MM_WIM_DATA

#define WAVE_MAPPER     (-1)

#define  WAVE_FORMAT_QUERY     		0x0001
#define  WAVE_ALLOWSYNC        		0x0002
#define  WAVE_MAPPED               	0x0004
#define  WAVE_FORMAT_DIRECT        	0x0008
#define  WAVE_FORMAT_DIRECT_QUERY  	(WAVE_FORMAT_QUERY | WAVE_FORMAT_DIRECT)

typedef struct wavehdr_tag {
    LPSTR       lpData;
    DWORD       dwBufferLength;
    DWORD       dwBytesRecorded;
    DWORD_PTR   dwUser;
    DWORD       dwFlags;
    DWORD       dwLoops;
    struct wavehdr_tag *lpNext;
    DWORD_PTR   reserved;
} WAVEHDR, *PWAVEHDR, *NPWAVEHDR, *LPWAVEHDR;

#define WHDR_DONE       0x00000001
#define WHDR_PREPARED   0x00000002
#define WHDR_BEGINLOOP  0x00000004
#define WHDR_ENDLOOP    0x00000008
#define WHDR_INQUEUE    0x00000010

typedef struct tagWAVEOUTCAPSA {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    CHAR	szPname[MAXPNAMELEN];
    DWORD	dwFormats;
    WORD	wChannels;
    WORD	wReserved1;
    DWORD	dwSupport;
} WAVEOUTCAPSA, *LPWAVEOUTCAPSA;

typedef struct tagWAVEOUTCAPSW {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    WCHAR	szPname[MAXPNAMELEN];
    DWORD	dwFormats;
    WORD	wChannels;
    WORD	wReserved1;
    DWORD	dwSupport;
} WAVEOUTCAPSW, *LPWAVEOUTCAPSW;
DECL_WINELIB_TYPE_AW(WAVEOUTCAPS)
DECL_WINELIB_TYPE_AW(LPWAVEOUTCAPS)

typedef struct tagWAVEOUTCAPS2A {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    CHAR	szPname[MAXPNAMELEN];
    DWORD	dwFormats;
    WORD	wChannels;
    WORD	wReserved1;
    DWORD	dwSupport;
    GUID	ManufacturerGuid;
    GUID	ProductGuid;
    GUID	NameGuid;
} WAVEOUTCAPS2A, *LPWAVEOUTCAPS2A;

typedef struct tagWAVEOUTCAPS2W {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    WCHAR	szPname[MAXPNAMELEN];
    DWORD	dwFormats;
    WORD	wChannels;
    WORD	wReserved1;
    DWORD	dwSupport;
    GUID	ManufacturerGuid;
    GUID	ProductGuid;
    GUID	NameGuid;
} WAVEOUTCAPS2W, *LPWAVEOUTCAPS2W;
DECL_WINELIB_TYPE_AW(WAVEOUTCAPS2)
DECL_WINELIB_TYPE_AW(LPWAVEOUTCAPS2)

#define WAVECAPS_PITCH          0x0001   /* supports pitch control */
#define WAVECAPS_PLAYBACKRATE   0x0002   /* supports playback rate control */
#define WAVECAPS_VOLUME         0x0004   /* supports volume control */
#define WAVECAPS_LRVOLUME       0x0008   /* separate left-right volume control */
#define WAVECAPS_SYNC           0x0010	 /* driver is synchronous and playing is blocking */
#define WAVECAPS_SAMPLEACCURATE 0x0020	 /* position is sample accurate */
#define WAVECAPS_DIRECTSOUND	0x0040   /* ? */

typedef struct tagWAVEINCAPSA {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    CHAR	szPname[MAXPNAMELEN];
    DWORD	dwFormats;
    WORD	wChannels;
    WORD	wReserved1;
} WAVEINCAPSA, *LPWAVEINCAPSA;
typedef struct tagWAVEINCAPSW {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    WCHAR	szPname[MAXPNAMELEN];
    DWORD	dwFormats;
    WORD	wChannels;
    WORD	wReserved1;
} WAVEINCAPSW, *LPWAVEINCAPSW;
DECL_WINELIB_TYPE_AW(WAVEINCAPS)
DECL_WINELIB_TYPE_AW(LPWAVEINCAPS)

typedef struct tagWAVEINCAPS2A {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    CHAR	szPname[MAXPNAMELEN];
    DWORD	dwFormats;
    WORD	wChannels;
    WORD	wReserved1;
    GUID	ManufacturerGuid;
    GUID	ProductGuid;
    GUID	NameGuid;
} WAVEINCAPS2A, *LPWAVEINCAPS2A;
typedef struct tagWAVEINCAPS2W {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    WCHAR	szPname[MAXPNAMELEN];
    DWORD	dwFormats;
    WORD	wChannels;
    WORD	wReserved1;
    GUID	ManufacturerGuid;
    GUID	ProductGuid;
    GUID	NameGuid;
} WAVEINCAPS2W, *LPWAVEINCAPS2W;
DECL_WINELIB_TYPE_AW(WAVEINCAPS2)
DECL_WINELIB_TYPE_AW(LPWAVEINCAPS2)

#define WAVE_INVALIDFORMAT     0x00000000    /* invalid format */
#define WAVE_FORMAT_1M08       0x00000001    /* 11.025 kHz, Mono,   8-bit  */
#define WAVE_FORMAT_1S08       0x00000002    /* 11.025 kHz, Stereo, 8-bit  */
#define WAVE_FORMAT_1M16       0x00000004    /* 11.025 kHz, Mono,   16-bit */
#define WAVE_FORMAT_1S16       0x00000008    /* 11.025 kHz, Stereo, 16-bit */
#define WAVE_FORMAT_2M08       0x00000010    /* 22.05  kHz, Mono,   8-bit  */
#define WAVE_FORMAT_2S08       0x00000020    /* 22.05  kHz, Stereo, 8-bit  */
#define WAVE_FORMAT_2M16       0x00000040    /* 22.05  kHz, Mono,   16-bit */
#define WAVE_FORMAT_2S16       0x00000080    /* 22.05  kHz, Stereo, 16-bit */
#define WAVE_FORMAT_4M08       0x00000100    /* 44.1   kHz, Mono,   8-bit  */
#define WAVE_FORMAT_4S08       0x00000200    /* 44.1   kHz, Stereo, 8-bit  */
#define WAVE_FORMAT_4M16       0x00000400    /* 44.1   kHz, Mono,   16-bit */
#define WAVE_FORMAT_4S16       0x00000800    /* 44.1   kHz, Stereo, 16-bit */
#define WAVE_FORMAT_48M08      0x00001000    /* 48     kHz, Mono,   8-bit  */
#define WAVE_FORMAT_48S08      0x00002000    /* 48     kHz, Stereo, 8-bit  */
#define WAVE_FORMAT_48M16      0x00004000    /* 48     kHz, Mono,   16-bit */
#define WAVE_FORMAT_48S16      0x00008000    /* 48     kHz, Stereo, 16-bit */
#define WAVE_FORMAT_96M08      0x00010000    /* 96     kHz, Mono,   8-bit  */
#define WAVE_FORMAT_96S08      0x00020000    /* 96     kHz, Stereo, 8-bit  */
#define WAVE_FORMAT_96M16      0x00040000    /* 96     kHz, Mono,   16-bit */
#define WAVE_FORMAT_96S16      0x00080000    /* 96     kHz, Stereo, 16-bit */

/* General format structure common to all formats, same for Win16 and Win32 */
typedef struct waveformat_tag {
    WORD	wFormatTag;
    WORD	nChannels;
    DWORD	nSamplesPerSec;
    DWORD	nAvgBytesPerSec;
    WORD	nBlockAlign;
} WAVEFORMAT, *LPWAVEFORMAT;

#define WAVE_FORMAT_PCM     1

typedef struct pcmwaveformat_tag {
    WAVEFORMAT	wf;
    WORD	wBitsPerSample;
} PCMWAVEFORMAT, *LPPCMWAVEFORMAT;

#ifndef _WAVEFORMATEX_
#define _WAVEFORMATEX_
/* ditto same for Win16 / Win32 */
typedef struct tWAVEFORMATEX {
    WORD	wFormatTag;
    WORD	nChannels;
    DWORD	nSamplesPerSec;
    DWORD	nAvgBytesPerSec;
    WORD	nBlockAlign;
    WORD	wBitsPerSample;
    WORD	cbSize;
} WAVEFORMATEX, *LPWAVEFORMATEX, *NPWAVEFORMATEX, *PWAVEFORMATEX;
#endif
typedef const WAVEFORMATEX *LPCWAVEFORMATEX;

UINT 		WINAPI 	waveOutGetNumDevs(void);
UINT           WINAPI  waveOutGetDevCapsA(UINT_PTR,LPWAVEOUTCAPSA,UINT);
UINT           WINAPI  waveOutGetDevCapsW(UINT_PTR,LPWAVEOUTCAPSW,UINT);
#define 		waveOutGetDevCaps WINELIB_NAME_AW(waveOutGetDevCaps)
UINT 		WINAPI	waveOutGetVolume(HWAVEOUT,DWORD*);
UINT 		WINAPI 	waveOutSetVolume(HWAVEOUT,DWORD);
UINT 		WINAPI 	waveOutGetErrorTextA(UINT,LPSTR,UINT);
UINT 		WINAPI 	waveOutGetErrorTextW(UINT,LPWSTR,UINT);
#define 	    	waveOutGetErrorText WINELIB_NAME_AW(waveOutGetErrorText)
MMRESULT        WINAPI  waveOutOpen(HWAVEOUT*,UINT,LPCWAVEFORMATEX,DWORD_PTR,DWORD_PTR,DWORD);
UINT 		WINAPI 	waveOutClose(HWAVEOUT);
UINT 		WINAPI 	waveOutPrepareHeader(HWAVEOUT,WAVEHDR*,UINT);
UINT 		WINAPI 	waveOutUnprepareHeader(HWAVEOUT,WAVEHDR*,UINT);
UINT 		WINAPI 	waveOutWrite(HWAVEOUT,WAVEHDR*,UINT);
UINT 		WINAPI 	waveOutPause(HWAVEOUT);
UINT 		WINAPI 	waveOutRestart(HWAVEOUT);
UINT 		WINAPI 	waveOutReset(HWAVEOUT);
UINT 		WINAPI 	waveOutBreakLoop(HWAVEOUT);
UINT 		WINAPI 	waveOutGetPosition(HWAVEOUT,LPMMTIME,UINT);
UINT 		WINAPI 	waveOutGetPitch(HWAVEOUT,DWORD*);
UINT 		WINAPI 	waveOutSetPitch(HWAVEOUT,DWORD);
UINT 		WINAPI 	waveOutGetPlaybackRate(HWAVEOUT,DWORD*);
UINT 		WINAPI 	waveOutSetPlaybackRate(HWAVEOUT,DWORD);
UINT 		WINAPI 	waveOutGetID(HWAVEOUT,UINT*);
UINT           WINAPI  waveOutMessage(HWAVEOUT,UINT,DWORD_PTR,DWORD_PTR);
UINT 		WINAPI 	waveInGetNumDevs(void);
UINT           WINAPI  waveInGetDevCapsA(UINT_PTR,LPWAVEINCAPSA,UINT);
UINT           WINAPI  waveInGetDevCapsW(UINT_PTR,LPWAVEINCAPSW,UINT);
#define 		waveInGetDevCaps WINELIB_NAME_AW(waveInGetDevCaps)
UINT 		WINAPI 	waveInGetErrorTextA(UINT,LPSTR,UINT);
UINT 		WINAPI 	waveInGetErrorTextW(UINT,LPWSTR,UINT);
#define 		waveInGetErrorText WINELIB_NAME_AW(waveInGetErrorText)
MMRESULT        WINAPI  waveInOpen(HWAVEIN*,UINT,LPCWAVEFORMATEX,DWORD_PTR,DWORD_PTR,DWORD);
UINT 		WINAPI  waveInClose(HWAVEIN);
UINT 		WINAPI  waveInPrepareHeader(HWAVEIN,WAVEHDR*,UINT);
UINT 		WINAPI  waveInUnprepareHeader(HWAVEIN,WAVEHDR*,UINT);
UINT 		WINAPI  waveInAddBuffer(HWAVEIN,WAVEHDR*,UINT);
UINT 		WINAPI  waveInStart(HWAVEIN);
UINT 		WINAPI  waveInStop(HWAVEIN);
UINT 		WINAPI  waveInReset(HWAVEIN);
UINT 		WINAPI  waveInGetPosition(HWAVEIN,LPMMTIME,UINT);
UINT 		WINAPI  waveInGetID(HWAVEIN,UINT*);
UINT           WINAPI  waveInMessage(HWAVEIN,UINT,DWORD_PTR,DWORD_PTR);

#define MIDIERR_UNPREPARED    (MIDIERR_BASE + 0)
#define MIDIERR_STILLPLAYING  (MIDIERR_BASE + 1)
#define MIDIERR_NOMAP         (MIDIERR_BASE + 2)
#define MIDIERR_NOTREADY      (MIDIERR_BASE + 3)
#define MIDIERR_NODEVICE      (MIDIERR_BASE + 4)
#define MIDIERR_INVALIDSETUP  (MIDIERR_BASE + 5)
#define MIDIERR_BADOPENMODE   (MIDIERR_BASE + 6)
#define MIDIERR_DONT_CONTINUE (MIDIERR_BASE + 7)
#define MIDIERR_LASTERROR     (MIDIERR_BASE + 7)

typedef LPDRVCALLBACK LPMIDICALLBACK;
#define MIDIPATCHSIZE   128
typedef WORD PATCHARRAY[MIDIPATCHSIZE];
typedef WORD *LPPATCHARRAY;
typedef WORD KEYARRAY[MIDIPATCHSIZE];
typedef WORD *LPKEYARRAY;

#define MIM_OPEN        MM_MIM_OPEN
#define MIM_CLOSE       MM_MIM_CLOSE
#define MIM_DATA        MM_MIM_DATA
#define MIM_LONGDATA    MM_MIM_LONGDATA
#define MIM_ERROR       MM_MIM_ERROR
#define MIM_LONGERROR   MM_MIM_LONGERROR
#define MIM_MOREDATA	MM_MIM_MOREDATA

#define MOM_OPEN        MM_MOM_OPEN
#define MOM_CLOSE       MM_MOM_CLOSE
#define MOM_DONE        MM_MOM_DONE
#define MOM_POSITIONCB	MM_MOM_POSITIONCB

/* device ID for MIDI mapper */

#define MIDIMAPPER     (-1)
#define MIDI_MAPPER    (-1)

/* Only on Win95 and up */
#define MIDI_IO_STATUS __MSABI_LONG(0x00000020)

/* flags for wFlags parm of
	midiOutCachePatches(),
	midiOutCacheDrumPatches() */
#define MIDI_CACHE_ALL      1
#define MIDI_CACHE_BESTFIT  2
#define MIDI_CACHE_QUERY    3
#define MIDI_UNCACHE        4

typedef struct tagMIDIOUTCAPSA {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    CHAR	szPname[MAXPNAMELEN];
    WORD	wTechnology;
    WORD	wVoices;
    WORD	wNotes;
    WORD	wChannelMask;
    DWORD	dwSupport;
} MIDIOUTCAPSA, *LPMIDIOUTCAPSA;

typedef struct tagMIDIOUTCAPSW {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    WCHAR	szPname[MAXPNAMELEN];
    WORD	wTechnology;
    WORD	wVoices;
    WORD	wNotes;
    WORD	wChannelMask;
    DWORD	dwSupport;
} MIDIOUTCAPSW, *LPMIDIOUTCAPSW;

DECL_WINELIB_TYPE_AW(MIDIOUTCAPS)
DECL_WINELIB_TYPE_AW(LPMIDIOUTCAPS)

typedef struct tagMIDIOUTCAPS2A {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    CHAR	szPname[MAXPNAMELEN];
    WORD	wTechnology;
    WORD	wVoices;
    WORD	wNotes;
    WORD	wChannelMask;
    DWORD	dwSupport;
    GUID	ManufacturerGuid;
    GUID	ProductGuid;
    GUID	NameGuid;
} MIDIOUTCAPS2A, *LPMIDIOUTCAPS2A;

typedef struct tagMIDIOUTCAPS2W {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    WCHAR	szPname[MAXPNAMELEN];
    WORD	wTechnology;
    WORD	wVoices;
    WORD	wNotes;
    WORD	wChannelMask;
    DWORD	dwSupport;
    GUID	ManufacturerGuid;
    GUID	ProductGuid;
    GUID	NameGuid;
} MIDIOUTCAPS2W, *LPMIDIOUTCAPS2W;

DECL_WINELIB_TYPE_AW(MIDIOUTCAPS2)
DECL_WINELIB_TYPE_AW(LPMIDIOUTCAPS2)

#define MOD_MIDIPORT    1  /* output port */
#define MOD_SYNTH       2  /* generic internal synth */
#define MOD_SQSYNTH     3  /* square wave internal synth */
#define MOD_FMSYNTH     4  /* FM internal synth */
#define MOD_MAPPER      5  /* MIDI mapper */
#define MOD_WAVETABLE   6  /* hardware wavetable internal synth */
#define MOD_SWSYNTH     7  /* software synth */

#define MIDICAPS_VOLUME		0x0001  /* supports volume control */
#define MIDICAPS_LRVOLUME	0x0002  /* separate left-right volume control */
#define MIDICAPS_CACHE		0x0004
#define MIDICAPS_STREAM		0x0008  /* capable of supporting stream buffer */

typedef struct tagMIDIINCAPSA {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    CHAR	szPname[MAXPNAMELEN];
    DWORD	dwSupport;
} MIDIINCAPSA, *LPMIDIINCAPSA;

typedef struct tagMIDIINCAPSW {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    WCHAR	szPname[MAXPNAMELEN];
    DWORD	dwSupport;
} MIDIINCAPSW, *LPMIDIINCAPSW;

DECL_WINELIB_TYPE_AW(MIDIINCAPS)
DECL_WINELIB_TYPE_AW(LPMIDIINCAPS)

typedef struct tagMIDIINCAPS2A {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    CHAR	szPname[MAXPNAMELEN];
    DWORD	dwSupport;
    GUID	ManufacturerGuid;
    GUID	ProductGuid;
    GUID	NameGuid;
} MIDIINCAPS2A, *LPMIDIINCAPS2A;

typedef struct tagMIDIINCAPS2W {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    WCHAR	szPname[MAXPNAMELEN];
    DWORD	dwSupport;
    GUID	ManufacturerGuid;
    GUID	ProductGuid;
    GUID	NameGuid;
} MIDIINCAPS2W, *LPMIDIINCAPS2W;

DECL_WINELIB_TYPE_AW(MIDIINCAPS2)
DECL_WINELIB_TYPE_AW(LPMIDIINCAPS2)

/* It seems that Win32 has a slightly different structure than Win 16.
 * sigh....
 */
typedef struct midihdr_tag {
    LPSTR	lpData;
    DWORD	dwBufferLength;
    DWORD	dwBytesRecorded;
    DWORD_PTR	dwUser;
    DWORD	dwFlags;
    struct midihdr_tag *lpNext;
    DWORD_PTR	reserved;
    /* Win 32 extended the structure with these 2 fields */
    DWORD	dwOffset;
    DWORD_PTR	dwReserved[8];
} MIDIHDR, *LPMIDIHDR;

#define MHDR_DONE       0x00000001       /* done bit */
#define MHDR_PREPARED   0x00000002       /* set if header prepared */
#define MHDR_INQUEUE    0x00000004       /* reserved for driver */
#define MHDR_ISSTRM	0x00000008	 /* data is sent by Stream functions */

typedef struct midiproptempo_tag {
    DWORD		cbStruct;
    DWORD		dwTempo;
} MIDIPROPTEMPO, *LPMIDIPROPTEMPO;

typedef struct midiproptimediv_tag {
    DWORD		cbStruct;
    DWORD		dwTimeDiv;
} MIDIPROPTIMEDIV, *LPMIDIPROPTIMEDIV;

#define MIDIPROP_GET		0x40000000
#define MIDIPROP_SET		0x80000000
#define MIDIPROP_TEMPO		0x00000002
#define MIDIPROP_TIMEDIV	0x00000001

typedef struct midievent_tag {
    DWORD dwDeltaTime;	/* Time, in MIDI ticks, between the previous
			 * event and the current event. */
    DWORD dwStreamID;	/* Reserved; must be zero. */
    DWORD dwEvent;  	/* event => see MEVT_XXX macros */
    DWORD dwParms[1];	/* extra pmts to dwEvent if F_LONG is set */
} MIDIEVENT, *LPMIDIEVENT;

#define MEVT_EVENTTYPE(x) ((BYTE) (((x)>>24)&0xFF))
#define MEVT_EVENTPARM(x) ((DWORD) ((x)&0x00FFFFFF))

#define MEVT_F_CALLBACK __MSABI_LONG(0x40000000)
#define MEVT_F_LONG     __MSABI_LONG(0x80000000)
#define MEVT_F_SHORT    __MSABI_LONG(0x00000000)
#define	MEVT_COMMENT	((BYTE)0x82)
#define	MEVT_LONGMSG	((BYTE)0x80)
#define	MEVT_NOP	((BYTE)0x02)
#define	MEVT_SHORTMSG	((BYTE)0x00)
#define	MEVT_TEMPO	((BYTE)0x01)
#define	MEVT_VERSION	((BYTE)0x84)

UINT		WINAPI	midiOutGetNumDevs(void);
UINT           WINAPI  midiOutGetDevCapsA(UINT_PTR,LPMIDIOUTCAPSA,UINT);
UINT           WINAPI  midiOutGetDevCapsW(UINT_PTR,LPMIDIOUTCAPSW,UINT);
#define 		midiOutGetDevCaps WINELIB_NAME_AW(midiOutGetDevCaps)
UINT		WINAPI	midiOutGetVolume(HMIDIOUT,DWORD*);
UINT		WINAPI	midiOutSetVolume(HMIDIOUT,DWORD);
UINT		WINAPI	midiOutGetErrorTextA(UINT,LPSTR,UINT);
UINT		WINAPI	midiOutGetErrorTextW(UINT,LPWSTR,UINT);
#define 		midiOutGetErrorText WINELIB_NAME_AW(midiOutGetErrorText)
MMRESULT        WINAPI  midiOutOpen(LPHMIDIOUT,UINT,DWORD_PTR,DWORD_PTR,DWORD);
UINT		WINAPI	midiOutClose(HMIDIOUT);
UINT		WINAPI	midiOutPrepareHeader(HMIDIOUT,MIDIHDR*,UINT);
UINT		WINAPI	midiOutUnprepareHeader(HMIDIOUT,MIDIHDR*,UINT);
UINT		WINAPI	midiOutShortMsg(HMIDIOUT,DWORD);
UINT		WINAPI	midiOutLongMsg(HMIDIOUT,MIDIHDR*,UINT);
UINT		WINAPI	midiOutReset(HMIDIOUT);
UINT		WINAPI	midiOutCachePatches(HMIDIOUT,UINT,WORD*,UINT);
UINT		WINAPI	midiOutCacheDrumPatches(HMIDIOUT,UINT,WORD*,UINT);
UINT		WINAPI	midiOutGetID(HMIDIOUT,UINT*);
UINT           WINAPI  midiOutMessage(HMIDIOUT,UINT,DWORD_PTR,DWORD_PTR);

UINT		WINAPI	midiInGetNumDevs(void);
UINT           WINAPI  midiInGetDevCapsA(UINT_PTR,LPMIDIINCAPSA,UINT);
UINT           WINAPI  midiInGetDevCapsW(UINT_PTR,LPMIDIINCAPSW,UINT);
#define 		midiInGetDevCaps WINELIB_NAME_AW(midiInGetDevCaps)
UINT		WINAPI	midiInGetErrorTextA(UINT,LPSTR,UINT);
UINT		WINAPI	midiInGetErrorTextW(UINT,LPWSTR,UINT);
#define 		midiInGetErrorText WINELIB_NAME_AW(midiInGetErrorText)
MMRESULT        WINAPI  midiInOpen(LPHMIDIIN,UINT,DWORD_PTR,DWORD_PTR,DWORD);
UINT		WINAPI	midiInClose(HMIDIIN);
UINT		WINAPI	midiInPrepareHeader(HMIDIIN,MIDIHDR*,UINT);
UINT		WINAPI	midiInUnprepareHeader(HMIDIIN,MIDIHDR*,UINT);
UINT		WINAPI	midiInAddBuffer(HMIDIIN,MIDIHDR*,UINT);
UINT		WINAPI	midiInStart(HMIDIIN);
UINT		WINAPI	midiInStop(HMIDIIN);
UINT		WINAPI	midiInReset(HMIDIIN);
UINT		WINAPI	midiInGetID(HMIDIIN,UINT*);
UINT           WINAPI  midiInMessage(HMIDIIN,UINT,DWORD_PTR,DWORD_PTR);
MMRESULT	WINAPI	midiStreamClose(HMIDISTRM hms);
MMRESULT       WINAPI  midiStreamOpen(LPHMIDISTRM,LPUINT,DWORD,DWORD_PTR,DWORD_PTR,DWORD);
MMRESULT	WINAPI	midiStreamOut(HMIDISTRM hms, LPMIDIHDR lpMidiHdr, UINT cbMidiHdr);
MMRESULT	WINAPI	midiStreamPause(HMIDISTRM hms);
MMRESULT	WINAPI	midiStreamPosition(HMIDISTRM hms, LPMMTIME lpmmt, UINT cbmmt);
MMRESULT	WINAPI	midiStreamProperty(HMIDISTRM hms, LPBYTE lpPropData, DWORD dwProperty);
MMRESULT	WINAPI	midiStreamRestart(HMIDISTRM hms);
MMRESULT	WINAPI	midiStreamStop(HMIDISTRM hms);

#define AUX_MAPPER     (-1)

typedef struct tagAUXCAPSA {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    CHAR	szPname[MAXPNAMELEN];
    WORD	wTechnology;
    WORD	wReserved1;
    DWORD	dwSupport;
} AUXCAPSA, *LPAUXCAPSA;

typedef struct tagAUXCAPSW {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    WCHAR	szPname[MAXPNAMELEN];
    WORD	wTechnology;
    WORD	wReserved1;
    DWORD	dwSupport;
} AUXCAPSW, *LPAUXCAPSW;

DECL_WINELIB_TYPE_AW(AUXCAPS)
DECL_WINELIB_TYPE_AW(LPAUXCAPS)

typedef struct tagAUXCAPS2A {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    CHAR	szPname[MAXPNAMELEN];
    WORD	wTechnology;
    WORD	wReserved1;
    DWORD	dwSupport;
    GUID	ManufacturerGuid;
    GUID	ProductGuid;
    GUID	NameGuid;
} AUXCAPS2A, *LPAUXCAPS2A;

typedef struct tagAUXCAPS2W {
    WORD	wMid;
    WORD	wPid;
    MMVERSION	vDriverVersion;
    WCHAR	szPname[MAXPNAMELEN];
    WORD	wTechnology;
    WORD	wReserved1;
    DWORD	dwSupport;
    GUID	ManufacturerGuid;
    GUID	ProductGuid;
    GUID	NameGuid;
} AUXCAPS2W, *LPAUXCAPS2W;

DECL_WINELIB_TYPE_AW(AUXCAPS2)
DECL_WINELIB_TYPE_AW(LPAUXCAPS2)

#define AUXCAPS_CDAUDIO    1       /* audio from internal CD-ROM drive */
#define AUXCAPS_AUXIN      2       /* audio from auxiliary input jacks */

#define AUXCAPS_VOLUME          0x0001  /* supports volume control */
#define AUXCAPS_LRVOLUME        0x0002  /* separate left-right volume control */

UINT		WINAPI	auxGetNumDevs(void);
UINT           WINAPI  auxGetDevCapsA(UINT_PTR,LPAUXCAPSA,UINT);
UINT           WINAPI  auxGetDevCapsW(UINT_PTR,LPAUXCAPSW,UINT);
#define 		auxGetDevCaps WINELIB_NAME_AW(auxGetDevCaps)
UINT		WINAPI	auxSetVolume(UINT,DWORD);
UINT		WINAPI	auxGetVolume(UINT,LPDWORD);
UINT           WINAPI  auxOutMessage(UINT,UINT,DWORD_PTR,DWORD_PTR);

#define TIMERR_NOERROR        (0)                  /* no error */
#define TIMERR_NOCANDO        (TIMERR_BASE+1)      /* request not completed */
#define TIMERR_STRUCT         (TIMERR_BASE+33)     /* time struct size */

typedef void (CALLBACK *LPTIMECALLBACK)(UINT,UINT,DWORD_PTR,DWORD_PTR,DWORD_PTR);

#define TIME_ONESHOT			0x0000	/* program timer for single event */
#define TIME_PERIODIC			0x0001	/* program for continuous periodic event */
#define TIME_CALLBACK_FUNCTION		0x0000	/* callback is function */
#define TIME_CALLBACK_EVENT_SET		0x0010	/* callback is event - use SetEvent */
#define TIME_CALLBACK_EVENT_PULSE 	0x0020	/* callback is event - use PulseEvent */
#define TIME_KILL_SYNCHRONOUS           0x0100

typedef struct timecaps_tag {
    UINT	wPeriodMin;
    UINT	wPeriodMax;
} TIMECAPS, *LPTIMECAPS;


MMRESULT	WINAPI	timeGetSystemTime(LPMMTIME,UINT);
DWORD		WINAPI	timeGetTime(void);	/* same for win32/win16 */
MMRESULT       WINAPI  timeSetEvent(UINT,UINT,LPTIMECALLBACK,DWORD_PTR,UINT);
MMRESULT	WINAPI	timeKillEvent(UINT);
MMRESULT	WINAPI	timeGetDevCaps(LPTIMECAPS,UINT);
MMRESULT	WINAPI	timeBeginPeriod(UINT);
MMRESULT	WINAPI	timeEndPeriod(UINT);

#define JOYERR_NOERROR        (0)                  /* no error */
#define JOYERR_PARMS          (JOYERR_BASE+5)      /* bad parameters */
#define JOYERR_NOCANDO        (JOYERR_BASE+6)      /* request not completed */
#define JOYERR_UNPLUGGED      (JOYERR_BASE+7)      /* joystick is unplugged */

/* JOYINFO, JOYINFOEX, MM_JOY* */
#define JOY_BUTTON1         	0x0001
#define JOY_BUTTON2         	0x0002
#define JOY_BUTTON3         	0x0004
#define JOY_BUTTON4         	0x0008
#define JOY_BUTTON1CHG      	0x0100
#define JOY_BUTTON2CHG      	0x0200
#define JOY_BUTTON3CHG      	0x0400
#define JOY_BUTTON4CHG      	0x0800

#define JOYSTICKID1         	0
#define JOYSTICKID2         	1

/* JOYCAPS.wCaps */
#define JOYCAPS_HASZ		0x0001
#define JOYCAPS_HASR		0x0002
#define JOYCAPS_HASU		0x0004
#define JOYCAPS_HASV		0x0008
#define JOYCAPS_HASPOV		0x0010
#define JOYCAPS_POV4DIR		0x0020
#define JOYCAPS_POVCTS		0x0040

/* JOYINFOEX stuff */
#define JOY_POVCENTERED		(WORD) -1
#define JOY_POVFORWARD		0
#define JOY_POVRIGHT		9000
#define JOY_POVBACKWARD		18000
#define JOY_POVLEFT		27000

#define JOY_RETURNX		0x00000001
#define JOY_RETURNY		0x00000002
#define JOY_RETURNZ		0x00000004
#define JOY_RETURNR		0x00000008
#define JOY_RETURNU		0x00000010
#define JOY_RETURNV		0x00000020
#define JOY_RETURNPOV		0x00000040
#define JOY_RETURNBUTTONS	0x00000080
#define JOY_RETURNRAWDATA	0x00000100
#define JOY_RETURNPOVCTS	0x00000200
#define JOY_RETURNCENTERED	0x00000400
#define JOY_USEDEADZONE		0x00000800
#define JOY_RETURNALL		(JOY_RETURNX | JOY_RETURNY | JOY_RETURNZ | \
				 JOY_RETURNR | JOY_RETURNU | JOY_RETURNV | \
				 JOY_RETURNPOV | JOY_RETURNBUTTONS)
#define JOY_CAL_READALWAYS	0x00010000
#define JOY_CAL_READXYONLY	0x00020000
#define JOY_CAL_READ3		0x00040000
#define JOY_CAL_READ4		0x00080000
#define JOY_CAL_READXONLY	0x00100000
#define JOY_CAL_READYONLY	0x00200000
#define JOY_CAL_READ5		0x00400000
#define JOY_CAL_READ6		0x00800000
#define JOY_CAL_READZONLY	0x01000000
#define JOY_CAL_READRONLY	0x02000000
#define JOY_CAL_READUONLY	0x04000000
#define JOY_CAL_READVONLY	0x08000000

typedef struct tagJOYCAPSA {
    WORD wMid;
    WORD wPid;
    CHAR szPname[MAXPNAMELEN];
    UINT wXmin;
    UINT wXmax;
    UINT wYmin;
    UINT wYmax;
    UINT wZmin;
    UINT wZmax;
    UINT wNumButtons;
    UINT wPeriodMin;
    UINT wPeriodMax;
    UINT wRmin;
    UINT wRmax;
    UINT wUmin;
    UINT wUmax;
    UINT wVmin;
    UINT wVmax;
    UINT wCaps;
    UINT wMaxAxes;
    UINT wNumAxes;
    UINT wMaxButtons;
    CHAR szRegKey[MAXPNAMELEN];
    CHAR szOEMVxD[MAX_JOYSTICKOEMVXDNAME];
} JOYCAPSA, *LPJOYCAPSA;

typedef struct tagJOYCAPSW {
    WORD wMid;
    WORD wPid;
    WCHAR szPname[MAXPNAMELEN];
    UINT wXmin;
    UINT wXmax;
    UINT wYmin;
    UINT wYmax;
    UINT wZmin;
    UINT wZmax;
    UINT wNumButtons;
    UINT wPeriodMin;
    UINT wPeriodMax;
    UINT wRmin;
    UINT wRmax;
    UINT wUmin;
    UINT wUmax;
    UINT wVmin;
    UINT wVmax;
    UINT wCaps;
    UINT wMaxAxes;
    UINT wNumAxes;
    UINT wMaxButtons;
    WCHAR szRegKey[MAXPNAMELEN];
    WCHAR szOEMVxD[MAX_JOYSTICKOEMVXDNAME];
} JOYCAPSW, *LPJOYCAPSW;
DECL_WINELIB_TYPE_AW(JOYCAPS)
DECL_WINELIB_TYPE_AW(LPJOYCAPS)

typedef struct tagJOYCAPS2A {
    WORD wMid;
    WORD wPid;
    CHAR szPname[MAXPNAMELEN];
    UINT wXmin;
    UINT wXmax;
    UINT wYmin;
    UINT wYmax;
    UINT wZmin;
    UINT wZmax;
    UINT wNumButtons;
    UINT wPeriodMin;
    UINT wPeriodMax;
    UINT wRmin;
    UINT wRmax;
    UINT wUmin;
    UINT wUmax;
    UINT wVmin;
    UINT wVmax;
    UINT wCaps;
    UINT wMaxAxes;
    UINT wNumAxes;
    UINT wMaxButtons;
    CHAR szRegKey[MAXPNAMELEN];
    CHAR szOEMVxD[MAX_JOYSTICKOEMVXDNAME];
    GUID ManufacturerGuid;
    GUID ProductGuid;
    GUID NameGuid;
} JOYCAPS2A, *LPJOYCAPS2A;

typedef struct tagJOYCAPS2W {
    WORD wMid;
    WORD wPid;
    WCHAR szPname[MAXPNAMELEN];
    UINT wXmin;
    UINT wXmax;
    UINT wYmin;
    UINT wYmax;
    UINT wZmin;
    UINT wZmax;
    UINT wNumButtons;
    UINT wPeriodMin;
    UINT wPeriodMax;
    UINT wRmin;
    UINT wRmax;
    UINT wUmin;
    UINT wUmax;
    UINT wVmin;
    UINT wVmax;
    UINT wCaps;
    UINT wMaxAxes;
    UINT wNumAxes;
    UINT wMaxButtons;
    WCHAR szRegKey[MAXPNAMELEN];
    WCHAR szOEMVxD[MAX_JOYSTICKOEMVXDNAME];
    GUID ManufacturerGuid;
    GUID ProductGuid;
    GUID NameGuid;
} JOYCAPS2W, *LPJOYCAPS2W;
DECL_WINELIB_TYPE_AW(JOYCAPS2)
DECL_WINELIB_TYPE_AW(LPJOYCAPS2)

typedef struct joyinfo_tag {
    UINT wXpos;
    UINT wYpos;
    UINT wZpos;
    UINT wButtons;
} JOYINFO, *LPJOYINFO;

typedef struct joyinfoex_tag {
    DWORD	dwSize;
    DWORD	dwFlags;
    DWORD	dwXpos;
    DWORD	dwYpos;
    DWORD	dwZpos;
    DWORD	dwRpos;
    DWORD	dwUpos;
    DWORD	dwVpos;
    DWORD	dwButtons;
    DWORD	dwButtonNumber;
    DWORD	dwPOV;
    DWORD	dwReserved1;
    DWORD	dwReserved2;
} JOYINFOEX,*LPJOYINFOEX;


MMRESULT       WINAPI  joyGetDevCapsA(UINT_PTR,LPJOYCAPSA,UINT);
MMRESULT       WINAPI  joyGetDevCapsW(UINT_PTR,LPJOYCAPSW,UINT);
#define joyGetDevCaps WINELIB_NAME_AW(joyGetDevCaps)
UINT		WINAPI	joyGetNumDevs(void);
MMRESULT	WINAPI	joyGetPos(UINT,LPJOYINFO);
MMRESULT	WINAPI	joyGetPosEx(UINT,LPJOYINFOEX);
MMRESULT	WINAPI	joyGetThreshold(UINT,UINT*);
MMRESULT	WINAPI	joyReleaseCapture(UINT);
MMRESULT	WINAPI	joySetCapture(HWND,UINT,UINT,BOOL);
MMRESULT	WINAPI	joySetThreshold(UINT,UINT);

#define	MIXERR_BASE		1024
#define	MIXERR_INVALLINE	(MIXERR_BASE + 0)
#define MIXERR_INVALCONTROL	(MIXERR_BASE + 1)
#define MIXERR_INVALVALUE	(MIXERR_BASE + 2)
#define MIXERR_LASTERROR	(MIXERR_BASE + 2)

typedef struct tagMIXERCAPSA {
	WORD		wMid;
	WORD		wPid;
	MMVERSION	vDriverVersion;
	CHAR		szPname[MAXPNAMELEN];
	DWORD		fdwSupport;
	DWORD		cDestinations;
} MIXERCAPSA,*LPMIXERCAPSA;

typedef struct tagMIXERCAPSW {
	WORD		wMid;
	WORD		wPid;
	MMVERSION	vDriverVersion;
	WCHAR		szPname[MAXPNAMELEN];
	DWORD		fdwSupport;
	DWORD		cDestinations;
} MIXERCAPSW,*LPMIXERCAPSW;

DECL_WINELIB_TYPE_AW(MIXERCAPS)
DECL_WINELIB_TYPE_AW(LPMIXERCAPS)

typedef struct tagMIXERCAPS2A {
	WORD		wMid;
	WORD		wPid;
	MMVERSION	vDriverVersion;
	CHAR		szPname[MAXPNAMELEN];
	DWORD		fdwSupport;
	DWORD		cDestinations;
	GUID		ManufacturerGuid;
	GUID		ProductGuid;
	GUID		NameGuid;
} MIXERCAPS2A,*LPMIXERCAPS2A;

typedef struct tagMIXERCAPS2W {
	WORD		wMid;
	WORD		wPid;
	MMVERSION	vDriverVersion;
	WCHAR		szPname[MAXPNAMELEN];
	DWORD		fdwSupport;
	DWORD		cDestinations;
	GUID		ManufacturerGuid;
	GUID		ProductGuid;
	GUID		NameGuid;
} MIXERCAPS2W,*LPMIXERCAPS2W;

DECL_WINELIB_TYPE_AW(MIXERCAPS2)
DECL_WINELIB_TYPE_AW(LPMIXERCAPS2)

#define MIXER_SHORT_NAME_CHARS		16
#define MIXER_LONG_NAME_CHARS		64

/*  MIXERLINE.fdwLine */
#define	MIXERLINE_LINEF_ACTIVE		0x00000001
#define	MIXERLINE_LINEF_DISCONNECTED	0x00008000
#define	MIXERLINE_LINEF_SOURCE		0x80000000

/* Mixer flags */
#define MIXER_OBJECTF_HANDLE    __MSABI_LONG(0x80000000)
#define MIXER_OBJECTF_MIXER     __MSABI_LONG(0x00000000)
#define MIXER_OBJECTF_HMIXER	(MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIXER)
#define MIXER_OBJECTF_WAVEOUT   __MSABI_LONG(0x10000000)
#define MIXER_OBJECTF_HWAVEOUT	(MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_WAVEOUT)
#define MIXER_OBJECTF_WAVEIN    __MSABI_LONG(0x20000000)
#define MIXER_OBJECTF_HWAVEIN	(MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_WAVEIN)
#define MIXER_OBJECTF_MIDIOUT   __MSABI_LONG(0x30000000)
#define MIXER_OBJECTF_HMIDIOUT	(MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIDIOUT)
#define MIXER_OBJECTF_MIDIIN    __MSABI_LONG(0x40000000)
#define MIXER_OBJECTF_HMIDIIN	(MIXER_OBJECTF_HANDLE|MIXER_OBJECTF_MIDIIN)
#define MIXER_OBJECTF_AUX       __MSABI_LONG(0x50000000)

/*  MIXERLINE.dwComponentType */
/*  component types for destinations and sources */
#define MIXERLINE_COMPONENTTYPE_DST_FIRST       __MSABI_LONG(0x00000000)
#define	MIXERLINE_COMPONENTTYPE_DST_UNDEFINED	(MIXERLINE_COMPONENTTYPE_DST_FIRST + 0)
#define	MIXERLINE_COMPONENTTYPE_DST_DIGITAL	(MIXERLINE_COMPONENTTYPE_DST_FIRST + 1)
#define	MIXERLINE_COMPONENTTYPE_DST_LINE	(MIXERLINE_COMPONENTTYPE_DST_FIRST + 2)
#define	MIXERLINE_COMPONENTTYPE_DST_MONITOR	(MIXERLINE_COMPONENTTYPE_DST_FIRST + 3)
#define	MIXERLINE_COMPONENTTYPE_DST_SPEAKERS	(MIXERLINE_COMPONENTTYPE_DST_FIRST + 4)
#define	MIXERLINE_COMPONENTTYPE_DST_HEADPHONES	(MIXERLINE_COMPONENTTYPE_DST_FIRST + 5)
#define	MIXERLINE_COMPONENTTYPE_DST_TELEPHONE	(MIXERLINE_COMPONENTTYPE_DST_FIRST + 6)
#define	MIXERLINE_COMPONENTTYPE_DST_WAVEIN	(MIXERLINE_COMPONENTTYPE_DST_FIRST + 7)
#define	MIXERLINE_COMPONENTTYPE_DST_VOICEIN	(MIXERLINE_COMPONENTTYPE_DST_FIRST + 8)
#define	MIXERLINE_COMPONENTTYPE_DST_LAST	(MIXERLINE_COMPONENTTYPE_DST_FIRST + 8)

#define MIXERLINE_COMPONENTTYPE_SRC_FIRST       __MSABI_LONG(0x00001000)
#define	MIXERLINE_COMPONENTTYPE_SRC_UNDEFINED	(MIXERLINE_COMPONENTTYPE_SRC_FIRST + 0)
#define	MIXERLINE_COMPONENTTYPE_SRC_DIGITAL	(MIXERLINE_COMPONENTTYPE_SRC_FIRST + 1)
#define	MIXERLINE_COMPONENTTYPE_SRC_LINE	(MIXERLINE_COMPONENTTYPE_SRC_FIRST + 2)
#define	MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE	(MIXERLINE_COMPONENTTYPE_SRC_FIRST + 3)
#define	MIXERLINE_COMPONENTTYPE_SRC_SYNTHESIZER	(MIXERLINE_COMPONENTTYPE_SRC_FIRST + 4)
#define	MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC	(MIXERLINE_COMPONENTTYPE_SRC_FIRST + 5)
#define	MIXERLINE_COMPONENTTYPE_SRC_TELEPHONE	(MIXERLINE_COMPONENTTYPE_SRC_FIRST + 6)
#define	MIXERLINE_COMPONENTTYPE_SRC_PCSPEAKER	(MIXERLINE_COMPONENTTYPE_SRC_FIRST + 7)
#define	MIXERLINE_COMPONENTTYPE_SRC_WAVEOUT	(MIXERLINE_COMPONENTTYPE_SRC_FIRST + 8)
#define	MIXERLINE_COMPONENTTYPE_SRC_AUXILIARY	(MIXERLINE_COMPONENTTYPE_SRC_FIRST + 9)
#define	MIXERLINE_COMPONENTTYPE_SRC_ANALOG	(MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10)
#define	MIXERLINE_COMPONENTTYPE_SRC_LAST	(MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10)

/*  MIXERLINE.Target.dwType */
#define	MIXERLINE_TARGETTYPE_UNDEFINED	0
#define	MIXERLINE_TARGETTYPE_WAVEOUT	1
#define	MIXERLINE_TARGETTYPE_WAVEIN	2
#define	MIXERLINE_TARGETTYPE_MIDIOUT	3
#define	MIXERLINE_TARGETTYPE_MIDIIN	4
#define MIXERLINE_TARGETTYPE_AUX	5

typedef struct tagMIXERLINEA {
    DWORD	cbStruct;
    DWORD	dwDestination;
    DWORD	dwSource;
    DWORD	dwLineID;
    DWORD	fdwLine;
    DWORD_PTR	dwUser;
    DWORD	dwComponentType;
    DWORD	cChannels;
    DWORD	cConnections;
    DWORD	cControls;
    CHAR	szShortName[MIXER_SHORT_NAME_CHARS];
    CHAR	szName[MIXER_LONG_NAME_CHARS];
    struct {
	DWORD	dwType;
	DWORD	dwDeviceID;
	WORD	wMid;
	WORD	wPid;
	MMVERSION	vDriverVersion;
	CHAR	szPname[MAXPNAMELEN];
    } Target;
} MIXERLINEA, *LPMIXERLINEA;

typedef struct tagMIXERLINEW {
    DWORD	cbStruct;
    DWORD	dwDestination;
    DWORD	dwSource;
    DWORD	dwLineID;
    DWORD	fdwLine;
    DWORD_PTR	dwUser;
    DWORD	dwComponentType;
    DWORD	cChannels;
    DWORD	cConnections;
    DWORD	cControls;
    WCHAR	szShortName[MIXER_SHORT_NAME_CHARS];
    WCHAR	szName[MIXER_LONG_NAME_CHARS];
    struct {
	DWORD	dwType;
	DWORD	dwDeviceID;
	WORD	wMid;
	WORD	wPid;
	MMVERSION	vDriverVersion;
	WCHAR	szPname[MAXPNAMELEN];
    } Target;
} MIXERLINEW, *LPMIXERLINEW;

DECL_WINELIB_TYPE_AW(MIXERLINE)
DECL_WINELIB_TYPE_AW(LPMIXERLINE)

/*  MIXERCONTROL.fdwControl */
#define MIXERCONTROL_CONTROLF_UNIFORM           __MSABI_LONG(0x00000001)
#define MIXERCONTROL_CONTROLF_MULTIPLE          __MSABI_LONG(0x00000002)
#define MIXERCONTROL_CONTROLF_DISABLED          __MSABI_LONG(0x80000000)

/*  MIXERCONTROL_CONTROLTYPE_xxx building block defines */
#define MIXERCONTROL_CT_CLASS_MASK              __MSABI_LONG(0xF0000000)
#define MIXERCONTROL_CT_CLASS_CUSTOM            __MSABI_LONG(0x00000000)
#define MIXERCONTROL_CT_CLASS_METER             __MSABI_LONG(0x10000000)
#define MIXERCONTROL_CT_CLASS_SWITCH            __MSABI_LONG(0x20000000)
#define MIXERCONTROL_CT_CLASS_NUMBER            __MSABI_LONG(0x30000000)
#define MIXERCONTROL_CT_CLASS_SLIDER            __MSABI_LONG(0x40000000)
#define MIXERCONTROL_CT_CLASS_FADER             __MSABI_LONG(0x50000000)
#define MIXERCONTROL_CT_CLASS_TIME              __MSABI_LONG(0x60000000)
#define MIXERCONTROL_CT_CLASS_LIST              __MSABI_LONG(0x70000000)

#define MIXERCONTROL_CT_SUBCLASS_MASK           __MSABI_LONG(0x0F000000)

#define MIXERCONTROL_CT_SC_SWITCH_BOOLEAN       __MSABI_LONG(0x00000000)
#define MIXERCONTROL_CT_SC_SWITCH_BUTTON        __MSABI_LONG(0x01000000)

#define MIXERCONTROL_CT_SC_METER_POLLED         __MSABI_LONG(0x00000000)

#define MIXERCONTROL_CT_SC_TIME_MICROSECS       __MSABI_LONG(0x00000000)
#define MIXERCONTROL_CT_SC_TIME_MILLISECS       __MSABI_LONG(0x01000000)

#define MIXERCONTROL_CT_SC_LIST_SINGLE          __MSABI_LONG(0x00000000)
#define MIXERCONTROL_CT_SC_LIST_MULTIPLE        __MSABI_LONG(0x01000000)

#define MIXERCONTROL_CT_UNITS_MASK              __MSABI_LONG(0x00FF0000)
#define MIXERCONTROL_CT_UNITS_CUSTOM            __MSABI_LONG(0x00000000)
#define MIXERCONTROL_CT_UNITS_BOOLEAN           __MSABI_LONG(0x00010000)
#define MIXERCONTROL_CT_UNITS_SIGNED            __MSABI_LONG(0x00020000)
#define MIXERCONTROL_CT_UNITS_UNSIGNED          __MSABI_LONG(0x00030000)
#define MIXERCONTROL_CT_UNITS_DECIBELS          __MSABI_LONG(0x00040000) /* in 10ths */
#define MIXERCONTROL_CT_UNITS_PERCENT           __MSABI_LONG(0x00050000) /* in 10ths */

/*  Commonly used control types for specifying MIXERCONTROL.dwControlType */
#define MIXERCONTROL_CONTROLTYPE_CUSTOM		(MIXERCONTROL_CT_CLASS_CUSTOM | MIXERCONTROL_CT_UNITS_CUSTOM)
#define MIXERCONTROL_CONTROLTYPE_BOOLEANMETER	(MIXERCONTROL_CT_CLASS_METER | MIXERCONTROL_CT_SC_METER_POLLED | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_SIGNEDMETER	(MIXERCONTROL_CT_CLASS_METER | MIXERCONTROL_CT_SC_METER_POLLED | MIXERCONTROL_CT_UNITS_SIGNED)
#define MIXERCONTROL_CONTROLTYPE_PEAKMETER	(MIXERCONTROL_CONTROLTYPE_SIGNEDMETER + 1)
#define MIXERCONTROL_CONTROLTYPE_UNSIGNEDMETER	(MIXERCONTROL_CT_CLASS_METER | MIXERCONTROL_CT_SC_METER_POLLED | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_BOOLEAN	(MIXERCONTROL_CT_CLASS_SWITCH | MIXERCONTROL_CT_SC_SWITCH_BOOLEAN | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_ONOFF		(MIXERCONTROL_CONTROLTYPE_BOOLEAN + 1)
#define MIXERCONTROL_CONTROLTYPE_MUTE		(MIXERCONTROL_CONTROLTYPE_BOOLEAN + 2)
#define MIXERCONTROL_CONTROLTYPE_MONO		(MIXERCONTROL_CONTROLTYPE_BOOLEAN + 3)
#define MIXERCONTROL_CONTROLTYPE_LOUDNESS	(MIXERCONTROL_CONTROLTYPE_BOOLEAN + 4)
#define MIXERCONTROL_CONTROLTYPE_STEREOENH	(MIXERCONTROL_CONTROLTYPE_BOOLEAN + 5)
#define MIXERCONTROL_CONTROLTYPE_BASS_BOOST     (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 0x00002277)
#define MIXERCONTROL_CONTROLTYPE_BUTTON		(MIXERCONTROL_CT_CLASS_SWITCH | MIXERCONTROL_CT_SC_SWITCH_BUTTON | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_DECIBELS	(MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_DECIBELS)
#define MIXERCONTROL_CONTROLTYPE_SIGNED		(MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_SIGNED)
#define MIXERCONTROL_CONTROLTYPE_UNSIGNED	(MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_PERCENT	(MIXERCONTROL_CT_CLASS_NUMBER | MIXERCONTROL_CT_UNITS_PERCENT)
#define MIXERCONTROL_CONTROLTYPE_SLIDER		(MIXERCONTROL_CT_CLASS_SLIDER | MIXERCONTROL_CT_UNITS_SIGNED)
#define MIXERCONTROL_CONTROLTYPE_PAN		(MIXERCONTROL_CONTROLTYPE_SLIDER + 1)
#define MIXERCONTROL_CONTROLTYPE_QSOUNDPAN	(MIXERCONTROL_CONTROLTYPE_SLIDER + 2)
#define MIXERCONTROL_CONTROLTYPE_FADER		(MIXERCONTROL_CT_CLASS_FADER | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_VOLUME		(MIXERCONTROL_CONTROLTYPE_FADER + 1)
#define MIXERCONTROL_CONTROLTYPE_BASS		(MIXERCONTROL_CONTROLTYPE_FADER + 2)
#define MIXERCONTROL_CONTROLTYPE_TREBLE		(MIXERCONTROL_CONTROLTYPE_FADER + 3)
#define MIXERCONTROL_CONTROLTYPE_EQUALIZER	(MIXERCONTROL_CONTROLTYPE_FADER + 4)
#define MIXERCONTROL_CONTROLTYPE_SINGLESELECT	(MIXERCONTROL_CT_CLASS_LIST | MIXERCONTROL_CT_SC_LIST_SINGLE | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_MUX		(MIXERCONTROL_CONTROLTYPE_SINGLESELECT + 1)
#define MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT	(MIXERCONTROL_CT_CLASS_LIST | MIXERCONTROL_CT_SC_LIST_MULTIPLE | MIXERCONTROL_CT_UNITS_BOOLEAN)
#define MIXERCONTROL_CONTROLTYPE_MIXER		(MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT + 1)
#define MIXERCONTROL_CONTROLTYPE_MICROTIME	(MIXERCONTROL_CT_CLASS_TIME | MIXERCONTROL_CT_SC_TIME_MICROSECS | MIXERCONTROL_CT_UNITS_UNSIGNED)
#define MIXERCONTROL_CONTROLTYPE_MILLITIME	(MIXERCONTROL_CT_CLASS_TIME | MIXERCONTROL_CT_SC_TIME_MILLISECS | MIXERCONTROL_CT_UNITS_UNSIGNED)


typedef struct tagMIXERCONTROLA {
    DWORD		cbStruct;
    DWORD		dwControlID;
    DWORD		dwControlType;
    DWORD		fdwControl;
    DWORD		cMultipleItems;
    CHAR		szShortName[MIXER_SHORT_NAME_CHARS];
    CHAR		szName[MIXER_LONG_NAME_CHARS];
    union {
	struct {
	    LONG	lMinimum;
	    LONG	lMaximum;
	} DUMMYSTRUCTNAME;
	struct {
	    DWORD	dwMinimum;
	    DWORD	dwMaximum;
	} DUMMYSTRUCTNAME1;
	DWORD       	dwReserved[6];
    } Bounds;
    union {
	DWORD		cSteps;
	DWORD		cbCustomData;
	DWORD		dwReserved[6];
    } Metrics;
} MIXERCONTROLA, *LPMIXERCONTROLA;

typedef struct MIXERCONTROLW {
    DWORD		cbStruct;
    DWORD		dwControlID;
    DWORD		dwControlType;
    DWORD		fdwControl;
    DWORD		cMultipleItems;
    WCHAR		szShortName[MIXER_SHORT_NAME_CHARS];
    WCHAR		szName[MIXER_LONG_NAME_CHARS];
    union {
	struct {
	    LONG	lMinimum;
	    LONG	lMaximum;
	} DUMMYSTRUCTNAME;
	struct {
	    DWORD	dwMinimum;
	    DWORD	dwMaximum;
	} DUMMYSTRUCTNAME1;
	DWORD       	dwReserved[6];
    } Bounds;
    union {
	DWORD		cSteps;
	DWORD		cbCustomData;
	DWORD		dwReserved[6];
    } Metrics;
} MIXERCONTROLW, *LPMIXERCONTROLW;

DECL_WINELIB_TYPE_AW(MIXERCONTROL)
DECL_WINELIB_TYPE_AW(LPMIXERCONTROL)

typedef struct tagMIXERLINECONTROLSA {
    DWORD	cbStruct;
    DWORD	dwLineID;
    union {
	DWORD	dwControlID;
	DWORD	dwControlType;
    } DUMMYUNIONNAME;
    DWORD	cControls;
    DWORD	cbmxctrl;
    LPMIXERCONTROLA	pamxctrl;
} MIXERLINECONTROLSA, *LPMIXERLINECONTROLSA;

typedef struct tagMIXERLINECONTROLSW {
    DWORD	cbStruct;
    DWORD	dwLineID;
    union {
	DWORD	dwControlID;
	DWORD	dwControlType;
    } DUMMYUNIONNAME;
    DWORD	cControls;
    DWORD	cbmxctrl;
    LPMIXERCONTROLW	pamxctrl;
} MIXERLINECONTROLSW, *LPMIXERLINECONTROLSW;

DECL_WINELIB_TYPE_AW(MIXERLINECONTROLS)
DECL_WINELIB_TYPE_AW(LPMIXERLINECONTROLS)

typedef struct tMIXERCONTROLDETAILS {
    DWORD	cbStruct;
    DWORD	dwControlID;
    DWORD	cChannels;
    union {
        HWND	hwndOwner;
        DWORD	cMultipleItems;
    } DUMMYUNIONNAME;
    DWORD	cbDetails;
    LPVOID	paDetails;
} MIXERCONTROLDETAILS,*LPMIXERCONTROLDETAILS;

typedef struct tagMIXERCONTROLDETAILS_LISTTEXTA {
    DWORD	dwParam1;
    DWORD	dwParam2;
    CHAR	szName[MIXER_LONG_NAME_CHARS];
} MIXERCONTROLDETAILS_LISTTEXTA,*LPMIXERCONTROLDETAILS_LISTTEXTA;

typedef struct tagMIXERCONTROLDETAILS_LISTTEXTW {
    DWORD	dwParam1;
    DWORD	dwParam2;
    WCHAR	szName[MIXER_LONG_NAME_CHARS];
} MIXERCONTROLDETAILS_LISTTEXTW,*LPMIXERCONTROLDETAILS_LISTTEXTW;

DECL_WINELIB_TYPE_AW(MIXERCONTROLDETAILS_LISTTEXT)
DECL_WINELIB_TYPE_AW(LPMIXERCONTROLDETAILS_LISTTEXT)

/*  MIXER_GETCONTROLDETAILSF_VALUE */
typedef struct {
	LONG	fValue;
} MIXERCONTROLDETAILS_BOOLEAN,*LPMIXERCONTROLDETAILS_BOOLEAN;

typedef struct {
	LONG	lValue;
} MIXERCONTROLDETAILS_SIGNED,*LPMIXERCONTROLDETAILS_SIGNED;

typedef struct {
	DWORD	dwValue;
} MIXERCONTROLDETAILS_UNSIGNED,*LPMIXERCONTROLDETAILS_UNSIGNED;

/* bits passed to mixerGetLineInfo.fdwInfo */
#define MIXER_GETLINEINFOF_DESTINATION          __MSABI_LONG(0x00000000)
#define MIXER_GETLINEINFOF_SOURCE               __MSABI_LONG(0x00000001)
#define MIXER_GETLINEINFOF_LINEID               __MSABI_LONG(0x00000002)
#define MIXER_GETLINEINFOF_COMPONENTTYPE        __MSABI_LONG(0x00000003)
#define MIXER_GETLINEINFOF_TARGETTYPE           __MSABI_LONG(0x00000004)
#define MIXER_GETLINEINFOF_QUERYMASK            __MSABI_LONG(0x0000000F)

/* bitmask passed to mixerGetLineControl */
#define MIXER_GETLINECONTROLSF_ALL              __MSABI_LONG(0x00000000)
#define MIXER_GETLINECONTROLSF_ONEBYID          __MSABI_LONG(0x00000001)
#define MIXER_GETLINECONTROLSF_ONEBYTYPE        __MSABI_LONG(0x00000002)
#define MIXER_GETLINECONTROLSF_QUERYMASK        __MSABI_LONG(0x0000000F)

/* bitmask passed to mixerGetControlDetails */
#define MIXER_GETCONTROLDETAILSF_VALUE          __MSABI_LONG(0x00000000)
#define MIXER_GETCONTROLDETAILSF_LISTTEXT       __MSABI_LONG(0x00000001)
#define MIXER_GETCONTROLDETAILSF_QUERYMASK      __MSABI_LONG(0x0000000F)

/* bitmask passed to mixerSetControlDetails */
#define MIXER_SETCONTROLDETAILSF_VALUE          __MSABI_LONG(0x00000000)
#define MIXER_SETCONTROLDETAILSF_CUSTOM         __MSABI_LONG(0x00000001)
#define MIXER_SETCONTROLDETAILSF_QUERYMASK      __MSABI_LONG(0x0000000F)

UINT		WINAPI	mixerGetNumDevs(void);
UINT           WINAPI  mixerOpen(LPHMIXER,UINT,DWORD_PTR,DWORD_PTR,DWORD);
UINT		WINAPI	mixerClose(HMIXER);
DWORD           WINAPI  mixerMessage(HMIXER,UINT,DWORD_PTR,DWORD_PTR);
UINT           WINAPI  mixerGetDevCapsA(UINT_PTR,LPMIXERCAPSA,UINT);
UINT           WINAPI  mixerGetDevCapsW(UINT_PTR,LPMIXERCAPSW,UINT);
#define 		mixerGetDevCaps WINELIB_NAME_AW(mixerGetDevCaps)
UINT		WINAPI	mixerGetLineInfoA(HMIXEROBJ,LPMIXERLINEA,DWORD);
UINT		WINAPI	mixerGetLineInfoW(HMIXEROBJ,LPMIXERLINEW,DWORD);
#define 		mixerGetLineInfo WINELIB_NAME_AW(mixerGetLineInfo)
UINT		WINAPI	mixerGetID(HMIXEROBJ,LPUINT,DWORD);
UINT		WINAPI	mixerGetLineControlsA(HMIXEROBJ,LPMIXERLINECONTROLSA,DWORD);
UINT		WINAPI	mixerGetLineControlsW(HMIXEROBJ,LPMIXERLINECONTROLSW,DWORD);
#define 		mixerGetLineControls WINELIB_NAME_AW(mixerGetLineControls)
UINT		WINAPI	mixerGetControlDetailsA(HMIXEROBJ,LPMIXERCONTROLDETAILS,DWORD);
UINT		WINAPI	mixerGetControlDetailsW(HMIXEROBJ,LPMIXERCONTROLDETAILS,DWORD);
#define 		mixerGetControlDetails WINELIB_NAME_AW(mixerGetControlDetails)
UINT		WINAPI	mixerSetControlDetails(HMIXEROBJ,LPMIXERCONTROLDETAILS,DWORD);

#define MMIOERR_BASE            256
#define MMIOERR_FILENOTFOUND    (MMIOERR_BASE + 1)  /* file not found */
#define MMIOERR_OUTOFMEMORY     (MMIOERR_BASE + 2)  /* out of memory */
#define MMIOERR_CANNOTOPEN      (MMIOERR_BASE + 3)  /* cannot open */
#define MMIOERR_CANNOTCLOSE     (MMIOERR_BASE + 4)  /* cannot close */
#define MMIOERR_CANNOTREAD      (MMIOERR_BASE + 5)  /* cannot read */
#define MMIOERR_CANNOTWRITE     (MMIOERR_BASE + 6)  /* cannot write */
#define MMIOERR_CANNOTSEEK      (MMIOERR_BASE + 7)  /* cannot seek */
#define MMIOERR_CANNOTEXPAND    (MMIOERR_BASE + 8)  /* cannot expand file */
#define MMIOERR_CHUNKNOTFOUND   (MMIOERR_BASE + 9)  /* chunk not found */
#define MMIOERR_UNBUFFERED      (MMIOERR_BASE + 10) /* file is unbuffered */
#define MMIOERR_PATHNOTFOUND     (MMIOERR_BASE + 11)
#define MMIOERR_ACCESSDENIED     (MMIOERR_BASE + 12)
#define MMIOERR_SHARINGVIOLATION (MMIOERR_BASE + 13)
#define MMIOERR_NETWORKERROR     (MMIOERR_BASE + 14)
#define MMIOERR_TOOMANYOPENFILES (MMIOERR_BASE + 15)
#define MMIOERR_INVALIDFILE      (MMIOERR_BASE + 16)

#define CFSEPCHAR       '+'             /* compound file name separator char. */

typedef DWORD           FOURCC;         /* a four character code */
typedef LRESULT (CALLBACK *LPMMIOPROC)  (LPSTR lpmmioinfo, UINT uMessage,
					 LPARAM lParam1, LPARAM lParam2);

typedef struct _MMIOINFO {
        DWORD		dwFlags;
        FOURCC		fccIOProc;
        LPMMIOPROC	pIOProc;
        UINT		wErrorRet;
        HTASK		hTask;
        /* fields maintained by MMIO functions during buffered I/O */
        LONG		cchBuffer;
        HPSTR		pchBuffer;
        HPSTR		pchNext;
        HPSTR		pchEndRead;
        HPSTR		pchEndWrite;
        LONG		lBufOffset;
        /* fields maintained by I/O procedure */
        LONG		lDiskOffset;
        DWORD		adwInfo[3];
        /* other fields maintained by MMIO */
        DWORD		dwReserved1;
        DWORD		dwReserved2;
        HMMIO		hmmio;
} MMIOINFO, *PMMIOINFO, *LPMMIOINFO;


typedef struct _MMCKINFO
{
        FOURCC          ckid;           /* chunk ID */
        DWORD           cksize;         /* chunk size */
        FOURCC          fccType;        /* form type or list type */
        DWORD           dwDataOffset;   /* offset of data portion of chunk */
        DWORD           dwFlags;        /* flags used by MMIO functions */
} MMCKINFO, *LPMMCKINFO;

#define MMIO_RWMODE     0x00000003      /* open file for reading/writing/both */
#define MMIO_SHAREMODE  0x00000070      /* file sharing mode number */

#define MMIO_CREATE     0x00001000      /* create new file (or truncate file) */
#define MMIO_PARSE      0x00000100      /* parse new file returning path */
#define MMIO_DELETE     0x00000200      /* create new file (or truncate file) */
#define MMIO_EXIST      0x00004000      /* checks for existence of file */
#define MMIO_ALLOCBUF   0x00010000      /* mmioOpen() should allocate a buffer */
#define MMIO_GETTEMP    0x00020000      /* mmioOpen() should retrieve temp name */

#define MMIO_DIRTY      0x10000000      /* I/O buffer is dirty */

#define MMIO_READ       0x00000000      /* open file for reading only */
#define MMIO_WRITE      0x00000001      /* open file for writing only */
#define MMIO_READWRITE  0x00000002      /* open file for reading and writing */

#define MMIO_COMPAT     0x00000000      /* compatibility mode */
#define MMIO_EXCLUSIVE  0x00000010      /* exclusive-access mode */
#define MMIO_DENYWRITE  0x00000020      /* deny writing to other processes */
#define MMIO_DENYREAD   0x00000030      /* deny reading to other processes */
#define MMIO_DENYNONE   0x00000040      /* deny nothing to other processes */

#define MMIO_FHOPEN             0x0010  /* mmioClose: keep file handle open */
#define MMIO_EMPTYBUF           0x0010  /* mmioFlush: empty the I/O buffer */
#define MMIO_TOUPPER            0x0010  /* mmioStringToFOURCC: to u-case */
#define MMIO_INSTALLPROC    0x00010000  /* mmioInstallIOProc: install MMIOProc */
#define MMIO_GLOBALPROC     0x10000000  /* mmioInstallIOProc: install globally */
#define MMIO_REMOVEPROC     0x00020000  /* mmioInstallIOProc: remove MMIOProc */
#define MMIO_FINDPROC       0x00040000  /* mmioInstallIOProc: find an MMIOProc */
#define MMIO_FINDCHUNK          0x0010  /* mmioDescend: find a chunk by ID */
#define MMIO_FINDRIFF           0x0020  /* mmioDescend: find a LIST chunk */
#define MMIO_FINDLIST           0x0040  /* mmioDescend: find a RIFF chunk */
#define MMIO_CREATERIFF         0x0020  /* mmioCreateChunk: make a LIST chunk */
#define MMIO_CREATELIST         0x0040  /* mmioCreateChunk: make a RIFF chunk */

#ifndef SEEK_SET
#define SEEK_SET   0
#define SEEK_CUR   1
#define SEEK_END   2
#endif  /* SEEK_SET */

#define MMIOM_READ      MMIO_READ       /* read */
#define MMIOM_WRITE    MMIO_WRITE       /* write */
#define MMIOM_SEEK              2       /* seek to a new position in file */
#define MMIOM_OPEN              3       /* open file */
#define MMIOM_CLOSE             4       /* close file */
#define MMIOM_WRITEFLUSH        5       /* write and flush */

#define MMIOM_RENAME            6       /* rename specified file */

#define MMIOM_USER         0x8000       /* beginning of user-defined messages */

#define FOURCC_RIFF     mmioFOURCC('R', 'I', 'F', 'F')
#define FOURCC_LIST     mmioFOURCC('L', 'I', 'S', 'T')

#define FOURCC_DOS      mmioFOURCC('D', 'O', 'S', ' ')
#define FOURCC_MEM      mmioFOURCC('M', 'E', 'M', ' ')

#define MMIO_DEFAULTBUFFER      8192    /* default buffer size */

#define mmioFOURCC( ch0, ch1, ch2, ch3 )                                \
                ( (DWORD)(BYTE)(ch0) | ( (DWORD)(BYTE)(ch1) << 8 ) |    \
                ( (DWORD)(BYTE)(ch2) << 16 ) | ( (DWORD)(BYTE)(ch3) << 24 ) )

LPMMIOPROC 	WINAPI 	mmioInstallIOProcA(FOURCC,LPMMIOPROC,DWORD);
LPMMIOPROC 	WINAPI 	mmioInstallIOProcW(FOURCC,LPMMIOPROC,DWORD);
#define      		mmioInstallIOProc WINELIB_NAME_AW(mmioInstallIOProc)

FOURCC 		WINAPI	mmioStringToFOURCCA(LPCSTR,UINT);
FOURCC 		WINAPI	mmioStringToFOURCCW(LPCWSTR,UINT);
#define 		mmioStringToFOURCC WINELIB_NAME_AW(mmioStringToFOURCC)
HMMIO		WINAPI	mmioOpenA(LPSTR,MMIOINFO*,DWORD);
HMMIO		WINAPI	mmioOpenW(LPWSTR,MMIOINFO*,DWORD);
#define			mmioOpen WINELIB_NAME_AW(mmioOpen)

MMRESULT	WINAPI	mmioRenameA(LPCSTR szFileName, LPCSTR szNewFileName,
				    const MMIOINFO * lpmmioinfo, DWORD dwRenameFlags);
MMRESULT	WINAPI	mmioRenameW(LPCWSTR szFileName, LPCWSTR szNewFileName,
				    const MMIOINFO * lpmmioinfo, DWORD dwRenameFlags);
#define 		mmioRename WINELIB_NAME_AW(mmioRename)

MMRESULT 	WINAPI	mmioClose(HMMIO,UINT);
LONG 		WINAPI	mmioRead(HMMIO,HPSTR,LONG);
LONG 		WINAPI	mmioWrite(HMMIO,HPCSTR,LONG);
LONG 		WINAPI	mmioSeek(HMMIO,LONG,INT);
MMRESULT 	WINAPI	mmioGetInfo(HMMIO,MMIOINFO*,UINT);
MMRESULT 	WINAPI	mmioSetInfo(HMMIO,const MMIOINFO*,UINT);
MMRESULT	WINAPI	mmioSetBuffer(HMMIO,LPSTR,LONG,UINT);
MMRESULT	WINAPI	mmioFlush(HMMIO,UINT);
MMRESULT	WINAPI	mmioAdvance(HMMIO,MMIOINFO*,UINT);
LRESULT		WINAPI	mmioSendMessage(HMMIO,UINT,LPARAM,LPARAM);
MMRESULT	WINAPI	mmioDescend(HMMIO,MMCKINFO*,const MMCKINFO*,UINT);
MMRESULT	WINAPI	mmioAscend(HMMIO,MMCKINFO*,UINT);
MMRESULT	WINAPI	mmioCreateChunk(HMMIO,MMCKINFO*,UINT);

typedef UINT (CALLBACK *YIELDPROC)(MCIDEVICEID,DWORD);

BOOL            WINAPI  mciExecute(LPCSTR);
DWORD           WINAPI  mciSendCommandA(MCIDEVICEID,UINT,DWORD_PTR,DWORD_PTR);
DWORD           WINAPI  mciSendCommandW(MCIDEVICEID,UINT,DWORD_PTR,DWORD_PTR);
#define 		mciSendCommand WINELIB_NAME_AW(mciSendCommand)
DWORD		WINAPI	mciSendStringA(LPCSTR,LPSTR,UINT,HWND);
DWORD		WINAPI	mciSendStringW(LPCWSTR,LPWSTR,UINT,HWND);
#define 		mciSendString WINELIB_NAME_AW(mciSendString)
MCIDEVICEID	WINAPI	mciGetDeviceIDA(LPCSTR);
MCIDEVICEID	WINAPI	mciGetDeviceIDW(LPCWSTR);
#define 		mciGetDeviceID WINELIB_NAME_AW(mciGetDeviceID)
MCIDEVICEID     WINAPI  mciGetDeviceIDFromElementIDA(DWORD,LPCSTR);
MCIDEVICEID     WINAPI  mciGetDeviceIDFromElementIDW(DWORD,LPCWSTR);
#define                 mciGetDeviceIDFromElementID WINELIB_NAME_AW(mciGetDeviceIDFromElementID)
BOOL            WINAPI  mciGetErrorStringA(MCIERROR,LPSTR,UINT);
BOOL            WINAPI  mciGetErrorStringW(MCIERROR,LPWSTR,UINT);
#define 		mciGetErrorString WINELIB_NAME_AW(mciGetErrorString)
BOOL            WINAPI  mciSetYieldProc(MCIDEVICEID,YIELDPROC,DWORD);
HTASK           WINAPI  mciGetCreatorTask(MCIDEVICEID);
YIELDPROC       WINAPI  mciGetYieldProc(MCIDEVICEID,DWORD*);

#define MCIERR_INVALID_DEVICE_ID        (MCIERR_BASE + 1)
#define MCIERR_UNRECOGNIZED_KEYWORD     (MCIERR_BASE + 3)
#define MCIERR_UNRECOGNIZED_COMMAND     (MCIERR_BASE + 5)
#define MCIERR_HARDWARE                 (MCIERR_BASE + 6)
#define MCIERR_INVALID_DEVICE_NAME      (MCIERR_BASE + 7)
#define MCIERR_OUT_OF_MEMORY            (MCIERR_BASE + 8)
#define MCIERR_DEVICE_OPEN              (MCIERR_BASE + 9)
#define MCIERR_CANNOT_LOAD_DRIVER       (MCIERR_BASE + 10)
#define MCIERR_MISSING_COMMAND_STRING   (MCIERR_BASE + 11)
#define MCIERR_PARAM_OVERFLOW           (MCIERR_BASE + 12)
#define MCIERR_MISSING_STRING_ARGUMENT  (MCIERR_BASE + 13)
#define MCIERR_BAD_INTEGER              (MCIERR_BASE + 14)
#define MCIERR_PARSER_INTERNAL          (MCIERR_BASE + 15)
#define MCIERR_DRIVER_INTERNAL          (MCIERR_BASE + 16)
#define MCIERR_MISSING_PARAMETER        (MCIERR_BASE + 17)
#define MCIERR_UNSUPPORTED_FUNCTION     (MCIERR_BASE + 18)
#define MCIERR_FILE_NOT_FOUND           (MCIERR_BASE + 19)
#define MCIERR_DEVICE_NOT_READY         (MCIERR_BASE + 20)
#define MCIERR_INTERNAL                 (MCIERR_BASE + 21)
#define MCIERR_DRIVER                   (MCIERR_BASE + 22)
#define MCIERR_CANNOT_USE_ALL           (MCIERR_BASE + 23)
#define MCIERR_MULTIPLE                 (MCIERR_BASE + 24)
#define MCIERR_EXTENSION_NOT_FOUND      (MCIERR_BASE + 25)
#define MCIERR_OUTOFRANGE               (MCIERR_BASE + 26)
#define MCIERR_FLAGS_NOT_COMPATIBLE     (MCIERR_BASE + 28)
#define MCIERR_FILE_NOT_SAVED           (MCIERR_BASE + 30)
#define MCIERR_DEVICE_TYPE_REQUIRED     (MCIERR_BASE + 31)
#define MCIERR_DEVICE_LOCKED            (MCIERR_BASE + 32)
#define MCIERR_DUPLICATE_ALIAS          (MCIERR_BASE + 33)
#define MCIERR_BAD_CONSTANT             (MCIERR_BASE + 34)
#define MCIERR_MUST_USE_SHAREABLE       (MCIERR_BASE + 35)
#define MCIERR_MISSING_DEVICE_NAME      (MCIERR_BASE + 36)
#define MCIERR_BAD_TIME_FORMAT          (MCIERR_BASE + 37)
#define MCIERR_NO_CLOSING_QUOTE         (MCIERR_BASE + 38)
#define MCIERR_DUPLICATE_FLAGS          (MCIERR_BASE + 39)
#define MCIERR_INVALID_FILE             (MCIERR_BASE + 40)
#define MCIERR_NULL_PARAMETER_BLOCK     (MCIERR_BASE + 41)
#define MCIERR_UNNAMED_RESOURCE         (MCIERR_BASE + 42)
#define MCIERR_NEW_REQUIRES_ALIAS       (MCIERR_BASE + 43)
#define MCIERR_NOTIFY_ON_AUTO_OPEN      (MCIERR_BASE + 44)
#define MCIERR_NO_ELEMENT_ALLOWED       (MCIERR_BASE + 45)
#define MCIERR_NONAPPLICABLE_FUNCTION   (MCIERR_BASE + 46)
#define MCIERR_ILLEGAL_FOR_AUTO_OPEN    (MCIERR_BASE + 47)
#define MCIERR_FILENAME_REQUIRED        (MCIERR_BASE + 48)
#define MCIERR_EXTRA_CHARACTERS         (MCIERR_BASE + 49)
#define MCIERR_DEVICE_NOT_INSTALLED     (MCIERR_BASE + 50)
#define MCIERR_GET_CD                   (MCIERR_BASE + 51)
#define MCIERR_SET_CD                   (MCIERR_BASE + 52)
#define MCIERR_SET_DRIVE                (MCIERR_BASE + 53)
#define MCIERR_DEVICE_LENGTH            (MCIERR_BASE + 54)
#define MCIERR_DEVICE_ORD_LENGTH        (MCIERR_BASE + 55)
#define MCIERR_NO_INTEGER               (MCIERR_BASE + 56)

#define MCIERR_WAVE_OUTPUTSINUSE        (MCIERR_BASE + 64)
#define MCIERR_WAVE_SETOUTPUTINUSE      (MCIERR_BASE + 65)
#define MCIERR_WAVE_INPUTSINUSE         (MCIERR_BASE + 66)
#define MCIERR_WAVE_SETINPUTINUSE       (MCIERR_BASE + 67)
#define MCIERR_WAVE_OUTPUTUNSPECIFIED   (MCIERR_BASE + 68)
#define MCIERR_WAVE_INPUTUNSPECIFIED    (MCIERR_BASE + 69)
#define MCIERR_WAVE_OUTPUTSUNSUITABLE   (MCIERR_BASE + 70)
#define MCIERR_WAVE_SETOUTPUTUNSUITABLE (MCIERR_BASE + 71)
#define MCIERR_WAVE_INPUTSUNSUITABLE    (MCIERR_BASE + 72)
#define MCIERR_WAVE_SETINPUTUNSUITABLE  (MCIERR_BASE + 73)

#define MCIERR_SEQ_DIV_INCOMPATIBLE     (MCIERR_BASE + 80)
#define MCIERR_SEQ_PORT_INUSE           (MCIERR_BASE + 81)
#define MCIERR_SEQ_PORT_NONEXISTENT     (MCIERR_BASE + 82)
#define MCIERR_SEQ_PORT_MAPNODEVICE     (MCIERR_BASE + 83)
#define MCIERR_SEQ_PORT_MISCERROR       (MCIERR_BASE + 84)
#define MCIERR_SEQ_TIMER                (MCIERR_BASE + 85)
#define MCIERR_SEQ_PORTUNSPECIFIED      (MCIERR_BASE + 86)
#define MCIERR_SEQ_NOMIDIPRESENT        (MCIERR_BASE + 87)

#define MCIERR_NO_WINDOW                (MCIERR_BASE + 90)
#define MCIERR_CREATEWINDOW             (MCIERR_BASE + 91)
#define MCIERR_FILE_READ                (MCIERR_BASE + 92)
#define MCIERR_FILE_WRITE               (MCIERR_BASE + 93)

#define MCIERR_NO_IDENTITY		(MCIERR_BASE + 94)

#define MCIERR_CUSTOM_DRIVER_BASE       (MCIERR_BASE + 256)

#define MCI_OPEN_DRIVER			0x0801
#define MCI_CLOSE_DRIVER		0x0802
#define MCI_OPEN			0x0803
#define MCI_CLOSE			0x0804
#define MCI_ESCAPE                      0x0805
#define MCI_PLAY                        0x0806
#define MCI_SEEK                        0x0807
#define MCI_STOP                        0x0808
#define MCI_PAUSE                       0x0809
#define MCI_INFO                        0x080A
#define MCI_GETDEVCAPS                  0x080B
#define MCI_SPIN                        0x080C
#define MCI_SET                         0x080D
#define MCI_STEP                        0x080E
#define MCI_RECORD                      0x080F
#define MCI_SYSINFO                     0x0810
#define MCI_BREAK                       0x0811
#define MCI_SOUND                       0x0812
#define MCI_SAVE                        0x0813
#define MCI_STATUS                      0x0814
#define MCI_CUE                         0x0830
#define MCI_REALIZE                     0x0840
#define MCI_WINDOW                      0x0841
#define MCI_PUT                         0x0842
#define MCI_WHERE                       0x0843
#define MCI_FREEZE                      0x0844
#define MCI_UNFREEZE                    0x0845
#define MCI_LOAD                        0x0850
#define MCI_CUT                         0x0851
#define MCI_COPY                        0x0852
#define MCI_PASTE                       0x0853
#define MCI_UPDATE                      0x0854
#define MCI_RESUME                      0x0855
#define MCI_DELETE                      0x0856

#define MCI_USER_MESSAGES               (0x400 + DRV_MCI_FIRST)

#define MCI_ALL_DEVICE_ID               0xFFFFFFFF

#define MCI_DEVTYPE_VCR                 (MCI_STRING_OFFSET + 1)
#define MCI_DEVTYPE_VIDEODISC           (MCI_STRING_OFFSET + 2)
#define MCI_DEVTYPE_OVERLAY             (MCI_STRING_OFFSET + 3)
#define MCI_DEVTYPE_CD_AUDIO            (MCI_STRING_OFFSET + 4)
#define MCI_DEVTYPE_DAT                 (MCI_STRING_OFFSET + 5)
#define MCI_DEVTYPE_SCANNER             (MCI_STRING_OFFSET + 6)
#define MCI_DEVTYPE_ANIMATION           (MCI_STRING_OFFSET + 7)
#define MCI_DEVTYPE_DIGITAL_VIDEO       (MCI_STRING_OFFSET + 8)
#define MCI_DEVTYPE_OTHER               (MCI_STRING_OFFSET + 9)
#define MCI_DEVTYPE_WAVEFORM_AUDIO      (MCI_STRING_OFFSET + 10)
#define MCI_DEVTYPE_SEQUENCER           (MCI_STRING_OFFSET + 11)

#define MCI_DEVTYPE_FIRST               MCI_DEVTYPE_VCR
#define MCI_DEVTYPE_LAST                MCI_DEVTYPE_SEQUENCER

#define MCI_MODE_NOT_READY              (MCI_STRING_OFFSET + 12)
#define MCI_MODE_STOP                   (MCI_STRING_OFFSET + 13)
#define MCI_MODE_PLAY                   (MCI_STRING_OFFSET + 14)
#define MCI_MODE_RECORD                 (MCI_STRING_OFFSET + 15)
#define MCI_MODE_SEEK                   (MCI_STRING_OFFSET + 16)
#define MCI_MODE_PAUSE                  (MCI_STRING_OFFSET + 17)
#define MCI_MODE_OPEN                   (MCI_STRING_OFFSET + 18)

#define MCI_FORMAT_MILLISECONDS         0
#define MCI_FORMAT_HMS                  1
#define MCI_FORMAT_MSF                  2
#define MCI_FORMAT_FRAMES               3
#define MCI_FORMAT_SMPTE_24             4
#define MCI_FORMAT_SMPTE_25             5
#define MCI_FORMAT_SMPTE_30             6
#define MCI_FORMAT_SMPTE_30DROP         7
#define MCI_FORMAT_BYTES                8
#define MCI_FORMAT_SAMPLES              9
#define MCI_FORMAT_TMSF                 10

#define MCI_MSF_MINUTE(msf)             ((BYTE)(msf))
#define MCI_MSF_SECOND(msf)             ((BYTE)(((WORD)(msf)) >> 8))
#define MCI_MSF_FRAME(msf)              ((BYTE)((msf)>>16))

#define MCI_MAKE_MSF(m, s, f)           ((DWORD)(((BYTE)(m) | \
                                                  ((WORD)(s)<<8)) | \
                                                 (((DWORD)(BYTE)(f))<<16)))

#define MCI_TMSF_TRACK(tmsf)            ((BYTE)(tmsf))
#define MCI_TMSF_MINUTE(tmsf)           ((BYTE)(((WORD)(tmsf)) >> 8))
#define MCI_TMSF_SECOND(tmsf)           ((BYTE)((tmsf)>>16))
#define MCI_TMSF_FRAME(tmsf)            ((BYTE)((tmsf)>>24))

#define MCI_MAKE_TMSF(t, m, s, f)       ((DWORD)(((BYTE)(t) | \
                                                  ((WORD)(m)<<8)) | \
                                                 (((DWORD)(BYTE)(s) | \
                                                   ((WORD)(f)<<8))<<16)))

#define MCI_HMS_HOUR(hms)               ((BYTE)(hms))
#define MCI_HMS_MINUTE(hms)             ((BYTE)(((WORD)(hms)) >> 8))
#define MCI_HMS_SECOND(hms)             ((BYTE)((hms)>>16))

#define MCI_MAKE_HMS(h, m, s)           ((DWORD)(((BYTE)(h) | \
                                                  ((WORD)(m)<<8)) | \
                                                 (((DWORD)(BYTE)(s))<<16)))

#define MCI_NOTIFY_SUCCESSFUL           0x0001
#define MCI_NOTIFY_SUPERSEDED           0x0002
#define MCI_NOTIFY_ABORTED              0x0004
#define MCI_NOTIFY_FAILURE              0x0008

#define MCI_NOTIFY                      __MSABI_LONG(0x00000001)
#define MCI_WAIT                        __MSABI_LONG(0x00000002)
#define MCI_FROM                        __MSABI_LONG(0x00000004)
#define MCI_TO                          __MSABI_LONG(0x00000008)
#define MCI_TRACK                       __MSABI_LONG(0x00000010)

#define MCI_OPEN_SHAREABLE              __MSABI_LONG(0x00000100)
#define MCI_OPEN_ELEMENT                __MSABI_LONG(0x00000200)
#define MCI_OPEN_ALIAS                  __MSABI_LONG(0x00000400)
#define MCI_OPEN_ELEMENT_ID             __MSABI_LONG(0x00000800)
#define MCI_OPEN_TYPE_ID                __MSABI_LONG(0x00001000)
#define MCI_OPEN_TYPE                   __MSABI_LONG(0x00002000)

#define MCI_SEEK_TO_START               __MSABI_LONG(0x00000100)
#define MCI_SEEK_TO_END                 __MSABI_LONG(0x00000200)

#define MCI_STATUS_ITEM                 __MSABI_LONG(0x00000100)
#define MCI_STATUS_START                __MSABI_LONG(0x00000200)

#define MCI_STATUS_LENGTH               __MSABI_LONG(0x00000001)
#define MCI_STATUS_POSITION             __MSABI_LONG(0x00000002)
#define MCI_STATUS_NUMBER_OF_TRACKS     __MSABI_LONG(0x00000003)
#define MCI_STATUS_MODE                 __MSABI_LONG(0x00000004)
#define MCI_STATUS_MEDIA_PRESENT        __MSABI_LONG(0x00000005)
#define MCI_STATUS_TIME_FORMAT          __MSABI_LONG(0x00000006)
#define MCI_STATUS_READY                __MSABI_LONG(0x00000007)
#define MCI_STATUS_CURRENT_TRACK        __MSABI_LONG(0x00000008)

#define MCI_INFO_PRODUCT                __MSABI_LONG(0x00000100)
#define MCI_INFO_FILE                   __MSABI_LONG(0x00000200)
#define MCI_INFO_MEDIA_UPC              __MSABI_LONG(0x00000400)
#define MCI_INFO_MEDIA_IDENTITY         __MSABI_LONG(0x00000800)
#define MCI_INFO_NAME                   __MSABI_LONG(0x00001000)
#define MCI_INFO_COPYRIGHT              __MSABI_LONG(0x00002000)

#define MCI_GETDEVCAPS_ITEM             __MSABI_LONG(0x00000100)

#define MCI_GETDEVCAPS_CAN_RECORD       __MSABI_LONG(0x00000001)
#define MCI_GETDEVCAPS_HAS_AUDIO        __MSABI_LONG(0x00000002)
#define MCI_GETDEVCAPS_HAS_VIDEO        __MSABI_LONG(0x00000003)
#define MCI_GETDEVCAPS_DEVICE_TYPE      __MSABI_LONG(0x00000004)
#define MCI_GETDEVCAPS_USES_FILES       __MSABI_LONG(0x00000005)
#define MCI_GETDEVCAPS_COMPOUND_DEVICE  __MSABI_LONG(0x00000006)
#define MCI_GETDEVCAPS_CAN_EJECT        __MSABI_LONG(0x00000007)
#define MCI_GETDEVCAPS_CAN_PLAY         __MSABI_LONG(0x00000008)
#define MCI_GETDEVCAPS_CAN_SAVE         __MSABI_LONG(0x00000009)

#define MCI_SYSINFO_QUANTITY            __MSABI_LONG(0x00000100)
#define MCI_SYSINFO_OPEN                __MSABI_LONG(0x00000200)
#define MCI_SYSINFO_NAME                __MSABI_LONG(0x00000400)
#define MCI_SYSINFO_INSTALLNAME         __MSABI_LONG(0x00000800)

#define MCI_SET_DOOR_OPEN               __MSABI_LONG(0x00000100)
#define MCI_SET_DOOR_CLOSED             __MSABI_LONG(0x00000200)
#define MCI_SET_TIME_FORMAT             __MSABI_LONG(0x00000400)
#define MCI_SET_AUDIO                   __MSABI_LONG(0x00000800)
#define MCI_SET_VIDEO                   __MSABI_LONG(0x00001000)
#define MCI_SET_ON                      __MSABI_LONG(0x00002000)
#define MCI_SET_OFF                     __MSABI_LONG(0x00004000)

#define MCI_SET_AUDIO_ALL               __MSABI_LONG(0x00000000)
#define MCI_SET_AUDIO_LEFT              __MSABI_LONG(0x00000001)
#define MCI_SET_AUDIO_RIGHT             __MSABI_LONG(0x00000002)

#define MCI_BREAK_KEY                   __MSABI_LONG(0x00000100)
#define MCI_BREAK_HWND                  __MSABI_LONG(0x00000200)
#define MCI_BREAK_OFF                   __MSABI_LONG(0x00000400)

#define MCI_RECORD_INSERT               __MSABI_LONG(0x00000100)
#define MCI_RECORD_OVERWRITE            __MSABI_LONG(0x00000200)

#define MCI_SOUND_NAME                  __MSABI_LONG(0x00000100)

#define MCI_SAVE_FILE                   __MSABI_LONG(0x00000100)

#define MCI_LOAD_FILE                   __MSABI_LONG(0x00000100)

typedef struct tagMCI_GENERIC_PARMS {
       DWORD_PTR dwCallback;
} MCI_GENERIC_PARMS, *LPMCI_GENERIC_PARMS;

typedef struct tagMCI_OPEN_PARMSA {
       DWORD_PTR       dwCallback;
	MCIDEVICEID	wDeviceID;
	LPCSTR		lpstrDeviceType;
	LPCSTR		lpstrElementName;
	LPCSTR		lpstrAlias;
} MCI_OPEN_PARMSA, *LPMCI_OPEN_PARMSA;

typedef struct tagMCI_OPEN_PARMSW {
       DWORD_PTR       dwCallback;
	MCIDEVICEID	wDeviceID;
	LPCWSTR		lpstrDeviceType;
	LPCWSTR		lpstrElementName;
	LPCWSTR		lpstrAlias;
} MCI_OPEN_PARMSW, *LPMCI_OPEN_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_OPEN_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_OPEN_PARMS)

typedef struct tagMCI_PLAY_PARMS{
       DWORD_PTR dwCallback;
	DWORD   dwFrom;
	DWORD   dwTo;
} MCI_PLAY_PARMS, *LPMCI_PLAY_PARMS;

typedef struct tagMCI_SEEK_PARMS {
       DWORD_PTR dwCallback;
	DWORD   dwTo;
} MCI_SEEK_PARMS, *LPMCI_SEEK_PARMS;

typedef struct tagMCI_STATUS_PARMS {
       DWORD_PTR dwCallback;
       DWORD_PTR dwReturn;
	DWORD   dwItem;
	DWORD   dwTrack;
} MCI_STATUS_PARMS, *LPMCI_STATUS_PARMS;

typedef struct tagMCI_INFO_PARMSA {
    DWORD_PTR   dwCallback;
    LPSTR       lpstrReturn;
    DWORD       dwRetSize;
} MCI_INFO_PARMSA, *LPMCI_INFO_PARMSA;

typedef struct tagMCI_INFO_PARMSW {
    DWORD_PTR   dwCallback;
    LPWSTR      lpstrReturn;
    DWORD       dwRetSize;
} MCI_INFO_PARMSW, *LPMCI_INFO_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_INFO_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_INFO_PARMS)

typedef struct tagMCI_GETDEVCAPS_PARMS {
       DWORD_PTR dwCallback;
	DWORD   dwReturn;
	DWORD   dwItem;
} MCI_GETDEVCAPS_PARMS, *LPMCI_GETDEVCAPS_PARMS;

typedef struct tagMCI_SYSINFO_PARMSA {
    DWORD_PTR   dwCallback;
    LPSTR	lpstrReturn;
    DWORD	dwRetSize;
    DWORD	dwNumber;
    UINT	wDeviceType;
} MCI_SYSINFO_PARMSA, *LPMCI_SYSINFO_PARMSA;

typedef struct tagMCI_SYSINFO_PARMSW {
    DWORD_PTR   dwCallback;
    LPWSTR	lpstrReturn;
    DWORD	dwRetSize;
    DWORD	dwNumber;
    UINT	wDeviceType;
} MCI_SYSINFO_PARMSW, *LPMCI_SYSINFO_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_SYSINFO_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_SYSINFO_PARMS)

typedef struct tagMCI_SET_PARMS {
       DWORD_PTR dwCallback;
	DWORD   dwTimeFormat;
	DWORD   dwAudio;
} MCI_SET_PARMS, *LPMCI_SET_PARMS;

typedef struct tagMCI_BREAK_PARMS {
       DWORD_PTR dwCallback;
	INT	nVirtKey;
	HWND	hwndBreak;
} MCI_BREAK_PARMS, *LPMCI_BREAK_PARMS;


typedef struct tagMCI_SOUND_PARMSA {
    DWORD_PTR   dwCallback;
    LPCSTR      lpstrSoundName;
} MCI_SOUND_PARMSA, *LPMCI_SOUND_PARMSA;

typedef struct tagMCI_SOUND_PARMSW {
    DWORD_PTR   dwCallback;
    LPCWSTR     lpstrSoundName;
} MCI_SOUND_PARMSW, *LPMCI_SOUND_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_SOUND_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_SOUND_PARMS)

typedef struct tagMCI_SAVE_PARMSA {
    DWORD_PTR dwCallback;
    LPCSTR  lpfilename;
} MCI_SAVE_PARMSA, *LPMCI_SAVE_PARMSA;

typedef struct tagMCI_SAVE_PARMSW {
    DWORD_PTR dwCallback;
    LPCWSTR  lpfilename;
} MCI_SAVE_PARMSW, *LPMCI_SAVE_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_SAVE_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_SAVE_PARMS)

typedef struct tagMCI_LOAD_PARMSA {
       DWORD_PTR dwCallback;
	LPCSTR	lpfilename;
} MCI_LOAD_PARMSA, *LPMCI_LOAD_PARMSA;

typedef struct tagMCI_LOAD_PARMSW {
       DWORD_PTR dwCallback;
	LPCWSTR	lpfilename;
} MCI_LOAD_PARMSW, *LPMCI_LOAD_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_LOAD_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_LOAD_PARMS)

typedef struct tagMCI_RECORD_PARMS {
       DWORD_PTR dwCallback;
	DWORD   dwFrom;
	DWORD   dwTo;
} MCI_RECORD_PARMS, *LPMCI_RECORD_PARMS;

#define MCI_CDA_STATUS_TYPE_TRACK 	0x00004001

#define MCI_CDA_TRACK_AUDIO		(MCI_CD_OFFSET + 0)
#define MCI_CDA_TRACK_OTHER		(MCI_CD_OFFSET + 1)

#define MCI_VD_MODE_PARK                (MCI_VD_OFFSET + 1)

#define MCI_VD_MEDIA_CLV                (MCI_VD_OFFSET + 2)
#define MCI_VD_MEDIA_CAV                (MCI_VD_OFFSET + 3)
#define MCI_VD_MEDIA_OTHER              (MCI_VD_OFFSET + 4)

#define MCI_VD_FORMAT_TRACK             0x4001

#define MCI_VD_PLAY_REVERSE             __MSABI_LONG(0x00010000)
#define MCI_VD_PLAY_FAST                __MSABI_LONG(0x00020000)
#define MCI_VD_PLAY_SPEED               __MSABI_LONG(0x00040000)
#define MCI_VD_PLAY_SCAN                __MSABI_LONG(0x00080000)
#define MCI_VD_PLAY_SLOW                __MSABI_LONG(0x00100000)

#define MCI_VD_SEEK_REVERSE             __MSABI_LONG(0x00010000)

#define MCI_VD_STATUS_SPEED             __MSABI_LONG(0x00004002)
#define MCI_VD_STATUS_FORWARD           __MSABI_LONG(0x00004003)
#define MCI_VD_STATUS_MEDIA_TYPE        __MSABI_LONG(0x00004004)
#define MCI_VD_STATUS_SIDE              __MSABI_LONG(0x00004005)
#define MCI_VD_STATUS_DISC_SIZE         __MSABI_LONG(0x00004006)

#define MCI_VD_GETDEVCAPS_CLV           __MSABI_LONG(0x00010000)
#define MCI_VD_GETDEVCAPS_CAV           __MSABI_LONG(0x00020000)

#define MCI_VD_SPIN_UP                  __MSABI_LONG(0x00010000)
#define MCI_VD_SPIN_DOWN                __MSABI_LONG(0x00020000)

#define MCI_VD_GETDEVCAPS_CAN_REVERSE   __MSABI_LONG(0x00004002)
#define MCI_VD_GETDEVCAPS_FAST_RATE     __MSABI_LONG(0x00004003)
#define MCI_VD_GETDEVCAPS_SLOW_RATE     __MSABI_LONG(0x00004004)
#define MCI_VD_GETDEVCAPS_NORMAL_RATE   __MSABI_LONG(0x00004005)

#define MCI_VD_STEP_FRAMES              __MSABI_LONG(0x00010000)
#define MCI_VD_STEP_REVERSE             __MSABI_LONG(0x00020000)

#define MCI_VD_ESCAPE_STRING            __MSABI_LONG(0x00000100)

typedef struct tagMCI_VD_PLAY_PARMS {
       DWORD_PTR dwCallback;
	DWORD   dwFrom;
	DWORD   dwTo;
	DWORD   dwSpeed;
} MCI_VD_PLAY_PARMS, *LPMCI_VD_PLAY_PARMS;

typedef struct tagMCI_VD_STEP_PARMS {
       DWORD_PTR dwCallback;
	DWORD   dwFrames;
} MCI_VD_STEP_PARMS, *LPMCI_VD_STEP_PARMS;

typedef struct tagMCI_VD_ESCAPE_PARMSA {
       DWORD_PTR dwCallback;
	LPCSTR	lpstrCommand;
} MCI_VD_ESCAPE_PARMSA, *LPMCI_VD_ESCAPE_PARMSA;

typedef struct tagMCI_VD_ESCAPE_PARMSW {
       DWORD_PTR dwCallback;
	LPCWSTR	lpstrCommand;
} MCI_VD_ESCAPE_PARMSW, *LPMCI_VD_ESCAPE_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_VD_ESCAPE_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_VD_ESCAPE_PARMS)

#define MCI_WAVE_OPEN_BUFFER            __MSABI_LONG(0x00010000)

#define MCI_WAVE_SET_FORMATTAG          __MSABI_LONG(0x00010000)
#define MCI_WAVE_SET_CHANNELS           __MSABI_LONG(0x00020000)
#define MCI_WAVE_SET_SAMPLESPERSEC      __MSABI_LONG(0x00040000)
#define MCI_WAVE_SET_AVGBYTESPERSEC     __MSABI_LONG(0x00080000)
#define MCI_WAVE_SET_BLOCKALIGN         __MSABI_LONG(0x00100000)
#define MCI_WAVE_SET_BITSPERSAMPLE      __MSABI_LONG(0x00200000)

#define MCI_WAVE_INPUT                  __MSABI_LONG(0x00400000)
#define MCI_WAVE_OUTPUT                 __MSABI_LONG(0x00800000)

#define MCI_WAVE_STATUS_FORMATTAG       __MSABI_LONG(0x00004001)
#define MCI_WAVE_STATUS_CHANNELS        __MSABI_LONG(0x00004002)
#define MCI_WAVE_STATUS_SAMPLESPERSEC   __MSABI_LONG(0x00004003)
#define MCI_WAVE_STATUS_AVGBYTESPERSEC  __MSABI_LONG(0x00004004)
#define MCI_WAVE_STATUS_BLOCKALIGN      __MSABI_LONG(0x00004005)
#define MCI_WAVE_STATUS_BITSPERSAMPLE   __MSABI_LONG(0x00004006)
#define MCI_WAVE_STATUS_LEVEL           __MSABI_LONG(0x00004007)

#define MCI_WAVE_SET_ANYINPUT           __MSABI_LONG(0x04000000)
#define MCI_WAVE_SET_ANYOUTPUT          __MSABI_LONG(0x08000000)

#define MCI_WAVE_GETDEVCAPS_INPUTS      __MSABI_LONG(0x00004001)
#define MCI_WAVE_GETDEVCAPS_OUTPUTS     __MSABI_LONG(0x00004002)

typedef struct tagMCI_WAVE_OPEN_PARMSA {
       DWORD_PTR       dwCallback;
	MCIDEVICEID	wDeviceID;
	LPCSTR		lpstrDeviceType;
	LPCSTR		lpstrElementName;
	LPCSTR		lpstrAlias;
	DWORD   	dwBufferSeconds;
} MCI_WAVE_OPEN_PARMSA, *LPMCI_WAVE_OPEN_PARMSA;

typedef struct tagMCI_WAVE_OPEN_PARMSW {
       DWORD_PTR       dwCallback;
	MCIDEVICEID	wDeviceID;
	LPCWSTR		lpstrDeviceType;
	LPCWSTR		lpstrElementName;
	LPCWSTR		lpstrAlias;
	DWORD   	dwBufferSeconds;
} MCI_WAVE_OPEN_PARMSW, *LPMCI_WAVE_OPEN_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_WAVE_OPEN_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_WAVE_OPEN_PARMS)

typedef struct tagMCI_WAVE_DELETE_PARMS {
       DWORD_PTR dwCallback;
	DWORD   dwFrom;
	DWORD   dwTo;
} MCI_WAVE_DELETE_PARMS, *LPMCI_WAVE_DELETE_PARMS;

typedef struct tagMCI_WAVE_SET_PARMS {
       DWORD_PTR dwCallback;
	DWORD	dwTimeFormat;
	DWORD	dwAudio;
	UINT	wInput;
	UINT	wOutput;
	UINT	wFormatTag;
	UINT	nChannels;
	DWORD	nSamplesPerSec;
	DWORD	nAvgBytesPerSec;
	UINT	nBlockAlign;
	UINT	wBitsPerSample;
} MCI_WAVE_SET_PARMS, * LPMCI_WAVE_SET_PARMS;


#define     MCI_SEQ_DIV_PPQN            (0 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_DIV_SMPTE_24        (1 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_DIV_SMPTE_25        (2 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_DIV_SMPTE_30DROP    (3 + MCI_SEQ_OFFSET)
#define     MCI_SEQ_DIV_SMPTE_30        (4 + MCI_SEQ_OFFSET)

#define     MCI_SEQ_FORMAT_SONGPTR      0x4001
#define     MCI_SEQ_FILE                0x4002
#define     MCI_SEQ_MIDI                0x4003
#define     MCI_SEQ_SMPTE               0x4004
#define     MCI_SEQ_NONE                65533

#define MCI_SEQ_STATUS_TEMPO            __MSABI_LONG(0x00004002)
#define MCI_SEQ_STATUS_PORT             __MSABI_LONG(0x00004003)
#define MCI_SEQ_STATUS_SLAVE            __MSABI_LONG(0x00004007)
#define MCI_SEQ_STATUS_MASTER           __MSABI_LONG(0x00004008)
#define MCI_SEQ_STATUS_OFFSET           __MSABI_LONG(0x00004009)
#define MCI_SEQ_STATUS_DIVTYPE          __MSABI_LONG(0x0000400A)

#define MCI_SEQ_SET_TEMPO               __MSABI_LONG(0x00010000)
#define MCI_SEQ_SET_PORT                __MSABI_LONG(0x00020000)
#define MCI_SEQ_SET_SLAVE               __MSABI_LONG(0x00040000)
#define MCI_SEQ_SET_MASTER              __MSABI_LONG(0x00080000)
#define MCI_SEQ_SET_OFFSET              __MSABI_LONG(0x01000000)

typedef struct tagMCI_SEQ_SET_PARMS {
       DWORD_PTR dwCallback;
	DWORD   dwTimeFormat;
	DWORD   dwAudio;
	DWORD   dwTempo;
	DWORD   dwPort;
	DWORD   dwSlave;
	DWORD   dwMaster;
	DWORD   dwOffset;
} MCI_SEQ_SET_PARMS, *LPMCI_SEQ_SET_PARMS;

#define MCI_ANIM_OPEN_WS                __MSABI_LONG(0x00010000)
#define MCI_ANIM_OPEN_PARENT            __MSABI_LONG(0x00020000)
#define MCI_ANIM_OPEN_NOSTATIC          __MSABI_LONG(0x00040000)

#define MCI_ANIM_PLAY_SPEED             __MSABI_LONG(0x00010000)
#define MCI_ANIM_PLAY_REVERSE           __MSABI_LONG(0x00020000)
#define MCI_ANIM_PLAY_FAST              __MSABI_LONG(0x00040000)
#define MCI_ANIM_PLAY_SLOW              __MSABI_LONG(0x00080000)
#define MCI_ANIM_PLAY_SCAN              __MSABI_LONG(0x00100000)

#define MCI_ANIM_STEP_REVERSE           __MSABI_LONG(0x00010000)
#define MCI_ANIM_STEP_FRAMES            __MSABI_LONG(0x00020000)

#define MCI_ANIM_STATUS_SPEED           __MSABI_LONG(0x00004001)
#define MCI_ANIM_STATUS_FORWARD         __MSABI_LONG(0x00004002)
#define MCI_ANIM_STATUS_HWND            __MSABI_LONG(0x00004003)
#define MCI_ANIM_STATUS_HPAL            __MSABI_LONG(0x00004004)
#define MCI_ANIM_STATUS_STRETCH         __MSABI_LONG(0x00004005)

#define MCI_ANIM_INFO_TEXT              __MSABI_LONG(0x00010000)

#define MCI_ANIM_GETDEVCAPS_CAN_REVERSE __MSABI_LONG(0x00004001)
#define MCI_ANIM_GETDEVCAPS_FAST_RATE   __MSABI_LONG(0x00004002)
#define MCI_ANIM_GETDEVCAPS_SLOW_RATE   __MSABI_LONG(0x00004003)
#define MCI_ANIM_GETDEVCAPS_NORMAL_RATE __MSABI_LONG(0x00004004)
#define MCI_ANIM_GETDEVCAPS_PALETTES    __MSABI_LONG(0x00004006)
#define MCI_ANIM_GETDEVCAPS_CAN_STRETCH __MSABI_LONG(0x00004007)
#define MCI_ANIM_GETDEVCAPS_MAX_WINDOWS __MSABI_LONG(0x00004008)

#define MCI_ANIM_REALIZE_NORM           __MSABI_LONG(0x00010000)
#define MCI_ANIM_REALIZE_BKGD           __MSABI_LONG(0x00020000)

#define MCI_ANIM_WINDOW_HWND            __MSABI_LONG(0x00010000)
#define MCI_ANIM_WINDOW_STATE           __MSABI_LONG(0x00040000)
#define MCI_ANIM_WINDOW_TEXT            __MSABI_LONG(0x00080000)
#define MCI_ANIM_WINDOW_ENABLE_STRETCH  __MSABI_LONG(0x00100000)
#define MCI_ANIM_WINDOW_DISABLE_STRETCH __MSABI_LONG(0x00200000)

#define MCI_ANIM_WINDOW_DEFAULT         __MSABI_LONG(0x00000000)

#define MCI_ANIM_RECT                   __MSABI_LONG(0x00010000)
#define MCI_ANIM_PUT_SOURCE             __MSABI_LONG(0x00020000)
#define MCI_ANIM_PUT_DESTINATION        __MSABI_LONG(0x00040000)

#define MCI_ANIM_WHERE_SOURCE           __MSABI_LONG(0x00020000)
#define MCI_ANIM_WHERE_DESTINATION      __MSABI_LONG(0x00040000)

#define MCI_ANIM_UPDATE_HDC             __MSABI_LONG(0x00020000)

typedef struct tagMCI_ANIM_OPEN_PARMSA {
       DWORD_PTR       dwCallback;
	MCIDEVICEID	wDeviceID;
	LPCSTR		lpstrDeviceType;
	LPCSTR		lpstrElementName;
	LPCSTR		lpstrAlias;
	DWORD		dwStyle;
	HWND		hWndParent;
} MCI_ANIM_OPEN_PARMSA, *LPMCI_ANIM_OPEN_PARMSA;

typedef struct tagMCI_ANIM_OPEN_PARMSW {
       DWORD_PTR       dwCallback;
	MCIDEVICEID	wDeviceID;
	LPCWSTR		lpstrDeviceType;
	LPCWSTR		lpstrElementName;
	LPCWSTR		lpstrAlias;
	DWORD		dwStyle;
	HWND		hWndParent;
} MCI_ANIM_OPEN_PARMSW, *LPMCI_ANIM_OPEN_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_ANIM_OPEN_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_ANIM_OPEN_PARMS)

typedef struct tagMCI_ANIM_PLAY_PARMS {
       DWORD_PTR dwCallback;
	DWORD   dwFrom;
	DWORD   dwTo;
	DWORD   dwSpeed;
} MCI_ANIM_PLAY_PARMS, *LPMCI_ANIM_PLAY_PARMS;

typedef struct tagMCI_ANIM_STEP_PARMS {
       DWORD_PTR dwCallback;
	DWORD   dwFrames;
} MCI_ANIM_STEP_PARMS, *LPMCI_ANIM_STEP_PARMS;

typedef struct tagMCI_ANIM_WINDOW_PARMSA {
       DWORD_PTR dwCallback;
	HWND	hWnd;
	UINT	nCmdShow;
	LPCSTR	lpstrText;
} MCI_ANIM_WINDOW_PARMSA, *LPMCI_ANIM_WINDOW_PARMSA;

typedef struct tagMCI_ANIM_WINDOW_PARMSW {
       DWORD_PTR dwCallback;
	HWND	hWnd;
	UINT	nCmdShow;
	LPCWSTR	lpstrText;
} MCI_ANIM_WINDOW_PARMSW, *LPMCI_ANIM_WINDOW_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_ANIM_WINDOW_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_ANIM_WINDOW_PARMS)

typedef struct tagMCI_ANIM_RECT_PARMS {
       DWORD_PTR dwCallback;
#ifdef MCI_USE_OFFEXT
	POINT	ptOffset;
	POINT	ptExtent;
#else   /* ifdef MCI_USE_OFFEXT */
	RECT	rc;
#endif  /* ifdef MCI_USE_OFFEXT */
} MCI_ANIM_RECT_PARMS, *LPMCI_ANIM_RECT_PARMS;


typedef struct tagMCI_ANIM_UPDATE_PARMS {
       DWORD_PTR dwCallback;
	RECT  rc;
	HDC   hDC;
} MCI_ANIM_UPDATE_PARMS, *LPMCI_ANIM_UPDATE_PARMS;


#define MCI_OVLY_OPEN_WS                __MSABI_LONG(0x00010000)
#define MCI_OVLY_OPEN_PARENT            __MSABI_LONG(0x00020000)

#define MCI_OVLY_STATUS_HWND            __MSABI_LONG(0x00004001)
#define MCI_OVLY_STATUS_STRETCH         __MSABI_LONG(0x00004002)

#define MCI_OVLY_INFO_TEXT              __MSABI_LONG(0x00010000)

#define MCI_OVLY_GETDEVCAPS_CAN_STRETCH __MSABI_LONG(0x00004001)
#define MCI_OVLY_GETDEVCAPS_CAN_FREEZE  __MSABI_LONG(0x00004002)
#define MCI_OVLY_GETDEVCAPS_MAX_WINDOWS __MSABI_LONG(0x00004003)

#define MCI_OVLY_WINDOW_HWND            __MSABI_LONG(0x00010000)
#define MCI_OVLY_WINDOW_STATE           __MSABI_LONG(0x00040000)
#define MCI_OVLY_WINDOW_TEXT            __MSABI_LONG(0x00080000)
#define MCI_OVLY_WINDOW_ENABLE_STRETCH  __MSABI_LONG(0x00100000)
#define MCI_OVLY_WINDOW_DISABLE_STRETCH __MSABI_LONG(0x00200000)

#define MCI_OVLY_WINDOW_DEFAULT         __MSABI_LONG(0x00000000)

#define MCI_OVLY_RECT                   __MSABI_LONG(0x00010000)
#define MCI_OVLY_PUT_SOURCE             __MSABI_LONG(0x00020000)
#define MCI_OVLY_PUT_DESTINATION        __MSABI_LONG(0x00040000)
#define MCI_OVLY_PUT_FRAME              __MSABI_LONG(0x00080000)
#define MCI_OVLY_PUT_VIDEO              __MSABI_LONG(0x00100000)

#define MCI_OVLY_WHERE_SOURCE           __MSABI_LONG(0x00020000)
#define MCI_OVLY_WHERE_DESTINATION      __MSABI_LONG(0x00040000)
#define MCI_OVLY_WHERE_FRAME            __MSABI_LONG(0x00080000)
#define MCI_OVLY_WHERE_VIDEO            __MSABI_LONG(0x00100000)

typedef struct tagMCI_OVLY_OPEN_PARMSA {
       DWORD_PTR       dwCallback;
	MCIDEVICEID	wDeviceID;
	LPCSTR		lpstrDeviceType;
	LPCSTR		lpstrElementName;
	LPCSTR		lpstrAlias;
	DWORD		dwStyle;
	HWND		hWndParent;
} MCI_OVLY_OPEN_PARMSA, *LPMCI_OVLY_OPEN_PARMSA;

typedef struct tagMCI_OVLY_OPEN_PARMSW {
       DWORD_PTR       dwCallback;
	MCIDEVICEID	wDeviceID;
	LPCWSTR		lpstrDeviceType;
	LPCWSTR		lpstrElementName;
	LPCWSTR		lpstrAlias;
	DWORD		dwStyle;
	HWND		hWndParent;
} MCI_OVLY_OPEN_PARMSW, *LPMCI_OVLY_OPEN_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_OVLY_OPEN_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_OVLY_OPEN_PARMS)

typedef struct tagMCI_OVLY_WINDOW_PARMSA {
       DWORD_PTR dwCallback;
	HWND	hWnd;
	UINT	nCmdShow;
	LPCSTR	lpstrText;
} MCI_OVLY_WINDOW_PARMSA, *LPMCI_OVLY_WINDOW_PARMSA;

typedef struct tagMCI_OVLY_WINDOW_PARMSW {
       DWORD_PTR dwCallback;
	HWND	hWnd;
	UINT	nCmdShow;
	LPCWSTR	lpstrText;
} MCI_OVLY_WINDOW_PARMSW, *LPMCI_OVLY_WINDOW_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_OVLY_WINDOW_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_OVLY_WINDOW_PARMS)

typedef struct tagMCI_OVLY_RECT_PARMS {
       DWORD_PTR dwCallback;
#ifdef MCI_USE_OFFEXT
	POINT ptOffset;
	POINT ptExtent;
#else   /* ifdef MCI_USE_OFFEXT */
	RECT  rc;
#endif  /* ifdef MCI_USE_OFFEXT */
} MCI_OVLY_RECT_PARMS, *LPMCI_OVLY_RECT_PARMS;


typedef struct tagMCI_OVLY_SAVE_PARMSA {
       DWORD_PTR dwCallback;
	LPCSTR  lpfilename;
	RECT  rc;
} MCI_OVLY_SAVE_PARMSA, *LPMCI_OVLY_SAVE_PARMSA;

typedef struct tagMCI_OVLY_SAVE_PARMSW {
       DWORD_PTR dwCallback;
	LPCWSTR  lpfilename;
	RECT  rc;
} MCI_OVLY_SAVE_PARMSW, *LPMCI_OVLY_SAVE_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_OVLY_SAVE_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_OVLY_SAVE_PARMS)

typedef struct tagMCI_OVLY_LOAD_PARMSA {
       DWORD_PTR dwCallback;
	LPCSTR	lpfilename;
	RECT	rc;
} MCI_OVLY_LOAD_PARMSA, *LPMCI_OVLY_LOAD_PARMSA;

typedef struct tagMCI_OVLY_LOAD_PARMSW {
       DWORD_PTR dwCallback;
	LPCWSTR	lpfilename;
	RECT	rc;
} MCI_OVLY_LOAD_PARMSW, *LPMCI_OVLY_LOAD_PARMSW;

DECL_WINELIB_TYPE_AW(MCI_OVLY_LOAD_PARMS)
DECL_WINELIB_TYPE_AW(LPMCI_OVLY_LOAD_PARMS)

#ifndef NEWTRANSPARENT
#define NEWTRANSPARENT 3
#define QUERYROPSUPPORT 40
#endif

#define SELECTDIB 41
#define DIBINDEX(n) MAKELONG((n),0x10FF)

#ifndef SC_SCREENSAVE
#define SC_SCREENSAVE 0xf140
#endif

#include <poppack.h>

#ifdef __cplusplus
}
#endif

#endif /* __WINE_MMSYSTEM_H */
