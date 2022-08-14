/**
*
*  BTICard Host Linux Driver  Version 2.15.0  (10/28/2020)
*  Copyright (c) 2001-2020
*  Ballard Technology, Inc.
*  www.astronics.com
*  Ballard.Support@astronics.com
*  ALL RIGHTS RESERVED
*
*  NAME:   BTICard.H -- Linux
*                       BTICard Driver Include Header File.
*
**/

/**
*
*  This file defines the procedures provided by the Linux
*  gcc 32-bit Driver Library for Ballard Technology interface.
*  cards.  Applications using the BTICard Driver Library must
*  incorporate this include file using the preprocessor directive
*  #include. If this file is in the current working directory,
*  the form would be:
*
*  #include "BTICard.H"
*
*  Refer to the gcc manual for more information on
*  header files.
*
**/

/**
*
*  Conditional block to prevent multiple defines.
*
**/

#ifndef __BTICard_H
#define __BTICard_H

/**
*
*  Typedefs used by the BTICard Driver.
*
**/

#ifndef BTICardAPI
#define BTICardAPI
#endif

#ifndef FARCODE
#define FARCODE
#endif

#ifndef FARDATA
#define FARDATA
#endif

#ifndef VOID
#define VOID void
#endif

#ifndef LPVOID
#define LPVOID void *
#endif

#ifndef INT
#define INT int
#endif

#ifndef LPINT
#define LPINT int *
#endif

#ifndef BYTE
#define BYTE unsigned char
#endif

#ifndef LPBYTE
#define LPBYTE unsigned char *
#endif

#ifndef CHAR
#define CHAR char
#endif

#ifndef UINT16
#define UINT16 unsigned short
#endif

#ifndef LPUINT16
#define LPUINT16 unsigned short *
#endif

#ifndef UINT32
#define UINT32 unsigned int
#endif

#ifndef LPUINT32
#define LPUINT32 unsigned int *
#endif

#ifndef INT64
#define INT64 long long
#endif

#ifndef LPINT64
#define LPINT64 long long *
#endif

#ifndef UINT64
#define UINT64 unsigned long long
#endif

#ifndef LPUINT64
#define LPUINT64 unsigned long long *
#endif

#ifndef ULONG_PTR
#define ULONG_PTR unsigned long
#endif

#ifndef LPULONG_PTR
#define LPULONG_PTR unsigned long *
#endif

#ifndef MSGADDR
#define MSGADDR unsigned int
#endif

#ifndef BASEADDR
#define BASEADDR unsigned int
#endif

#ifndef LISTADDR
#define LISTADDR unsigned int
#endif

#ifndef LPMSGADDR
#define LPMSGADDR unsigned int *
#endif

#ifndef LPCSTR
#define LPCSTR const char *
#endif

#ifndef LPSTR
#define LPSTR char *
#endif

#ifndef BOOL
#define BOOL int
#endif

#ifndef LPBOOL
#define LPBOOL int *
#endif

#ifndef HCARD
#define HCARD long
#endif

#ifndef LPHCARD
#define LPHCARD long *
#endif

#ifndef HCORE
#define HCORE long
#endif

#ifndef LPHCORE
#define LPHCORE long *
#endif

#ifndef HRPC
#define HRPC void *
#endif

#ifndef LPHRPC
#define LPHRPC void **
#endif

#ifndef ERRVAL
#define ERRVAL int
#endif

#ifndef SCHNDX
#define SCHNDX int
#endif

/**
*
*  Structs used by the BTICard Driver.
*
**/

#ifndef SEQRECORD1553
typedef struct
{
	UINT16  type;               //Valid in all versions
	UINT16  count;              //Valid in all versions
	UINT32   timestamp;          //Valid in all versions
	UINT16  activity;           //Valid in all versions
	UINT16  error;              //Valid in all versions
	UINT16  cwd1;               //Valid in all versions
	UINT16  cwd2;               //Valid in all versions
	UINT16  swd1;               //Valid in all versions
	UINT16  swd2;               //Valid in all versions
	UINT16  datacount;          //Valid in all versions
	UINT16  data[40];           //Variable length (don't exceed data[datacount-1])
} SEQRECORD1553;
#endif

#ifndef LPSEQRECORD1553
typedef SEQRECORD1553 * LPSEQRECORD1553;
#endif

#ifndef SEQRECORDMORE1553
typedef struct
{
	UINT32   timestamph;         //Valid if version of base record (SEQRECORD1553) >= 1
	UINT16  resptime1;          //Valid if version of base record (SEQRECORD1553) >= 1
	UINT16  resptime2;          //Valid if version of base record (SEQRECORD1553) >= 1
} SEQRECORDMORE1553;
#endif

#ifndef LPSEQRECORDMORE1553
typedef SEQRECORDMORE1553 * LPSEQRECORDMORE1553;
#endif

#ifndef SEQRECORD429
typedef struct
{
	UINT16  type;               //Valid in all versions
	UINT16  count;              //Valid in all versions
	UINT32   timestamp;          //Valid in all versions
	UINT16  activity;           //Valid in all versions
	UINT16  decgap;             //Valid if version >= 1
	UINT32   data;               //Valid in all versions
	UINT32   timestamph;         //Valid if version >= 1
} SEQRECORD429;
#endif

#ifndef LPSEQRECORD429
typedef SEQRECORD429 * LPSEQRECORD429;
#endif

#ifndef SEQRECORD717
typedef struct
{
	UINT16  type;               //Valid in all versions
	UINT16  count;              //Valid in all versions
	UINT32   timestamp;          //Valid in all versions
	UINT16  activity;           //Valid in all versions
	UINT16  wordnum;            //Valid in all versions
	UINT16  subframe;           //Valid in all versions
	UINT16  superframe;         //Valid in all versions
	UINT16  data;               //Valid in all versions
	UINT16  rsvd9;              //Valid if version >= 1
	UINT32   timestamph;         //Valid if version >= 1
} SEQRECORD717;
#endif

#ifndef LPSEQRECORD717
typedef SEQRECORD717 * LPSEQRECORD717;
#endif

#ifndef SEQRECORD708
typedef struct
{
	UINT16  type;               //Valid in all versions
	UINT16  count;              //Valid in all versions
	UINT32   timestamp;          //Valid in all versions
	UINT16  activity;           //Valid in all versions
	UINT16  datacount;          //Valid in all versions
	UINT16  data[100];          //Valid in all versions
	UINT16  extra[16];          //Valid if version >= 1
	UINT16  bitcount;           //Valid if version >= 1
	UINT16  rsvd123;            //Valid if version >= 1
	UINT32   timestamph;         //Valid if version >= 1
} SEQRECORD708;
#endif

#ifndef LPSEQRECORD708
typedef SEQRECORD708 * LPSEQRECORD708;
#endif

#ifndef SEQRECORDCSDB
typedef struct
{
	UINT16  type;               //Valid in all versions
	UINT16  count;              //Valid in all versions
	UINT32   timestamp;          //Valid in all versions
	UINT32   timestamph;         //Valid in all versions
	UINT16  activity;           //Valid in all versions
	UINT16  datacount;          //Valid in all versions
	UINT16  data[32];           //Valid in all versions
} SEQRECORDCSDB;
#endif

#ifndef LPSEQRECORDCSDB
typedef SEQRECORDCSDB * LPSEQRECORDCSDB;
#endif

#ifndef SEQRECORDDIO
typedef struct
{
	UINT16  type;               //Valid in all versions
	UINT16  count;              //Valid in all versions
	UINT16  bank;               //Valid in all versions
	UINT16  state;              //Valid in version 0
	UINT32   timestamp;          //Valid in all versions
	UINT32   timestamph;         //Valid in all versions
	UINT16  change;             //Valid in version 1
	UINT16  value;              //Valid in version 1
} SEQRECORDDIO;
#endif

#ifndef LPSEQRECORDDIO
typedef SEQRECORDDIO * LPSEQRECORDDIO;
#endif

#ifndef SEQRECORDEBR
typedef struct
{
	UINT16  type;               //Valid in all versions
	UINT16  count;              //Valid in all versions
	UINT16  activity;           //Valid in all versions
	UINT16  error;              //Valid in all versions
	UINT32   timestamp;          //Valid in all versions
	UINT32   timestamph;         //Valid in all versions
	UINT16  cwd;                //Valid in all versions
	UINT16  cwdinfo;            //Valid in all versions
	UINT16  swd;                //Valid in all versions
	UINT16  swdinfo;            //Valid in all versions
	UINT16  resptime;           //Valid in all versions
	UINT16  datacount;          //Valid in all versions
	UINT16  data[40];           //Variable length (don't exceed data[datacount-1])
} SEQRECORDEBR;
#endif

#ifndef LPSEQRECORDEBR
typedef SEQRECORDEBR * LPSEQRECORDEBR;
#endif

#ifndef SEQFINDINFO
typedef struct
{
	LPUINT16 pRecFirst;
	LPUINT16 pRecNext;
	LPUINT16 pRecLast;
} SEQFINDINFO;
#endif

#ifndef LPSEQFINDINFO
typedef SEQFINDINFO * LPSEQFINDINFO;
#endif

#ifndef BTIIRIGTIME
typedef struct
{
	UINT16  days;
	UINT16  hours;
	UINT16  min;
	UINT16  sec;
	UINT16  msec;
	UINT16  usec;
} BTIIRIGTIME;
#endif

#ifndef LPBTIIRIGTIME
typedef BTIIRIGTIME * LPBTIIRIGTIME;
#endif

#ifndef BTIIDENTIFY
typedef struct
{
	CHAR mac_address[20];
	CHAR serial_number[8];
	CHAR card_string[32];
	CHAR type_string[32];
	CHAR user_string[64];
} BTIIDENTIFY;
#define BTIIDENTIFY BTIIDENTIFY
#endif

#ifndef LPBTIIDENTIFY
typedef BTIIDENTIFY * LPBTIIDENTIFY;
#define LPBTIIDENTIFY LPBTIIDENTIFY
#endif

/**
*
*  "C" block if compiling a C++ file.
*
**/

#ifdef __cplusplus
extern "C" {
#endif

/**
*
*  BTICard Driver functions.
*
**/

BTICardAPI VOID BTICard_Add64(LPUINT32 resulth,LPUINT32 resultl,UINT32 valah,UINT32 valal,UINT32 valbh,UINT32 valbl);
BTICardAPI UINT32 BTICard_AddrDSP(UINT32 addr,HCARD handleval);
BTICardAPI UINT32 BTICard_AddrHost(UINT32 addr,HCARD handleval);
BTICardAPI ERRVAL BTICard_AsciiToMant(LPCSTR str,LPUINT32 mant,LPINT exp);
BTICardAPI UINT32 BTICard_BCDToBin(UINT32 bcdval,INT msb,INT lsb);
BTICardAPI UINT32 BTICard_BinToBCD(UINT32 oldbcdval,UINT32 binval,INT msb,INT lsb);
BTICardAPI ERRVAL BTICard_BITConfig(UINT32 configval,HCORE handleval);
BTICardAPI ERRVAL BTICard_BITInitiate(HCORE handleval);
BTICardAPI ERRVAL BTICard_BITStatusClear(UINT32 statval,HCORE handleval);
BTICardAPI UINT32 BTICard_BITStatusRd(HCORE handleval);
BTICardAPI ERRVAL BTICard_BootAdd(LPCSTR filename,LPCSTR name,HCORE handleval);
BTICardAPI ERRVAL BTICard_BootAddr(INT index,LPUINT32 addr,HCORE handleval);
BTICardAPI ERRVAL BTICard_BootAddTiEx(LPCSTR filename,HCORE handleval);
BTICardAPI ERRVAL BTICard_BootCount(LPUINT16 count,HCORE handleval);
BTICardAPI ERRVAL BTICard_BootDelete(UINT16 index,HCORE handleval);
BTICardAPI ERRVAL BTICard_BootGet(UINT16 index,LPCSTR filename,HCORE handleval);
BTICardAPI ERRVAL BTICard_BootInfo(UINT16 index,LPUINT16 base,LPUINT16 length,LPSTR name,UINT16 namelen,LPUINT32 crc,HCORE handleval);
BTICardAPI ERRVAL BTICard_BootPtrGet(LPUINT16 index,HCORE handleval);
BTICardAPI ERRVAL BTICard_BootPtrGetTiEx(LPUINT16 value,HCORE handleval);
BTICardAPI ERRVAL BTICard_BootPtrPut(UINT16 index,HCORE handleval);
BTICardAPI ERRVAL BTICard_BootPtrPutTiEx(UINT16 value,HCORE handleval);
BTICardAPI ERRVAL BTICard_BootRdW(LPUINT16 value,UINT32 addr,HCORE handleval);
BTICardAPI ERRVAL BTICard_BootStr(UINT16 index,LPSTR keystr,LPSTR buf,UINT16 bufcount,HCORE handleval);
BTICardAPI ERRVAL BTICard_BootWipe(HCORE handleval);
BTICardAPI ERRVAL BTICard_BootWipeTiEx(HCORE handleval);
BTICardAPI ERRVAL BTICard_BootWrW(UINT16 value,UINT32 addr,HCORE handleval);
BTICardAPI ERRVAL BTICard_CardClose(HCARD handleval);
BTICardAPI ERRVAL BTICard_CardCloseAll(VOID);
BTICardAPI UINT32 BTICard_CardGetInfo(UINT16 infotype,INT channum,HCORE handleval);
BTICardAPI ERRVAL BTICard_CardGetInfoEx(LPUINT16 bufmodel,UINT16 bufmodelcount,LPUINT16 buffeature,UINT16 buffeaturecount,HCORE handleval);
BTICardAPI BOOL BTICard_CardIsRunning(HCORE handleval);
BTICardAPI ERRVAL BTICard_CardNop(HCARD handleval);
BTICardAPI ERRVAL BTICard_CardOpen(LPHCARD lpHandle,INT cardnum);
BTICardAPI ERRVAL BTICard_CardOpenStr(LPHCARD lpHandle,LPCSTR cardstr);
BTICardAPI LPCSTR BTICard_CardProductStr(HCORE handleval);
BTICardAPI LPCSTR BTICard_CardReserveRd(HCORE handleval);
BTICardAPI ERRVAL BTICard_CardReserveWr(LPCSTR str,HCORE handleval);
BTICardAPI VOID BTICard_CardReset(HCORE handleval);
BTICardAPI VOID BTICard_CardResetEx(HCORE handleval);
BTICardAPI ERRVAL BTICard_CardResume(HCORE handleval);
BTICardAPI ERRVAL BTICard_CardShadow(BOOL shadowval,HCORE handleval);
BTICardAPI ERRVAL BTICard_CardStart(HCORE handleval);
BTICardAPI BOOL BTICard_CardStop(HCORE handleval);
BTICardAPI VOID BTICard_CardSyncEnable(BOOL enableflag,UINT16 syncmask,UINT16 pinpolarity,HCORE handleval);
BTICardAPI UINT16 BTICard_CardSyncValid(HCORE handleval);
BTICardAPI ERRVAL BTICard_CardSyncValidEx(LPUINT16 maskout,UINT16 maskin,HCORE handleval);
BTICardAPI ERRVAL BTICard_CardTest(UINT16 level,HCORE handleval);
BTICardAPI ERRVAL BTICard_CardTest0(HCORE handleval);
BTICardAPI ERRVAL BTICard_CardTest1(HCORE handleval);
BTICardAPI ERRVAL BTICard_CardTest2(HCORE handleval);
BTICardAPI ERRVAL BTICard_CardTest3(HCORE handleval);
BTICardAPI VOID BTICard_CardTrigger(HCORE handleval);
BTICardAPI VOID BTICard_CardTriggerEnable(BOOL enableflag,HCORE handleval);
BTICardAPI VOID BTICard_CardTriggerEnableEx(BOOL enableflag,UINT16 trigmask,UINT16 pinpolarity,HCORE handleval);
BTICardAPI VOID BTICard_CardTriggerEx(UINT16 trigmask,HCORE handleval);
BTICardAPI UINT16 BTICard_CardTriggerValid(HCORE handleval);
BTICardAPI ERRVAL BTICard_CardTriggerValidEx(LPUINT16 maskout,UINT16 maskin,HCORE handleval);
BTICardAPI LPCSTR BTICard_CardTypeStr(HCORE handleval);
BTICardAPI VOID BTICard_ChDARClr(UINT16 maskval,UINT16 addrval,INT channum,HCORE handleval);
BTICardAPI BOOL BTICard_ChDARGet(UINT16 maskval,UINT16 addrval,INT channum,HCORE handleval);
BTICardAPI UINT32 BTICard_ChDARRdL(UINT16 addrval,INT channum,HCORE handleval);
BTICardAPI VOID BTICard_ChDARRdsW(LPUINT16 valueptr,UINT16 addrval,INT countval,INT channum,HCORE handleval);
BTICardAPI UINT16 BTICard_ChDARRdW(UINT16 addrval,INT channum,HCORE handleval);
BTICardAPI VOID BTICard_ChDARSet(UINT16 maskval,UINT16 addrval,INT channum,HCORE handleval);
BTICardAPI VOID BTICard_ChDARWrL(UINT32 value,UINT16 addrval,INT channum,HCORE handleval);
BTICardAPI VOID BTICard_ChDARWrsW(LPUINT16 valueptr,UINT16 addrval,INT countval,INT channum,HCORE handleval);
BTICardAPI VOID BTICard_ChDARWrW(UINT16 value,UINT16 addrval,INT channum,HCORE handleval);
BTICardAPI ERRVAL BTICard_CISRd(LPUINT16 buf,UINT16 bufcount,INT cistype,HCORE handleval);
BTICardAPI ERRVAL BTICard_CISWr(LPUINT16 buf,UINT16 bufcount,INT cistype,HCORE handleval);
BTICardAPI UINT16 BTICard_CommBufRd(UINT16 offset,HCORE handleval);
BTICardAPI VOID BTICard_CommBufWr(UINT16 value,UINT16 offset,HCORE handleval);
BTICardAPI ERRVAL BTICard_CommCall(UINT32 addrval,HCORE handleval);
BTICardAPI ERRVAL BTICard_CommChannelReconfig(UINT32 chmask,HCORE handleval);
BTICardAPI ERRVAL BTICard_CommCheck(HCORE handleval);
BTICardAPI ERRVAL BTICard_CommDisable(UINT16 command,HCORE handleval);
BTICardAPI ERRVAL BTICard_CommDisableEx(UINT16 command,HCORE handleval);
BTICardAPI ERRVAL BTICard_CommEnable(HCORE handleval);
BTICardAPI ERRVAL BTICard_CommExternSRQ(UINT32 chmask,HCORE handleval);
BTICardAPI ERRVAL BTICard_CommFillW(UINT16 value,UINT32 addrval,UINT16 count,HCORE handleval);
BTICardAPI BOOL BTICard_CommProtocolFunc(UINT16 opcode,UINT16 argcount,LPUINT16 argbuf,HCORE handleval);
BTICardAPI UINT32 BTICard_CommRdL(UINT32 addrval,HCORE handleval);
BTICardAPI ERRVAL BTICard_CommRdsW(LPUINT16 valueptr,UINT32 addrval,UINT16 count,HCORE handleval);
BTICardAPI UINT16 BTICard_CommRdW(UINT32 addrval,HCORE handleval);
BTICardAPI ERRVAL BTICard_CommRun(LPUINT16 dataptr,UINT16 datacount,LPUINT16 codeptr,UINT16 codecount,HCORE handleval);
BTICardAPI VOID BTICard_CommWrL(UINT32 value,UINT32 addrval,HCORE handleval);
BTICardAPI ERRVAL BTICard_CommWrsW(LPUINT16 valueptr,UINT32 addrval,UINT16 count,HCORE handleval);
BTICardAPI VOID BTICard_CommWrW(UINT16 value,UINT32 addrval,HCORE handleval);
BTICardAPI ERRVAL BTICard_CoProcCheck(HCARD handleval);
BTICardAPI ERRVAL BTICard_CoProcGetInfo(LPUINT32 valueptr,UINT16 infotype,HCARD handleval);
BTICardAPI ERRVAL BTICard_CoProcMemRdL(LPUINT32 valueptr,UINT32 addrval,HCARD handleval);
BTICardAPI ERRVAL BTICard_CoProcMemRdsL(LPUINT32 valueptr,UINT32 addrval,UINT32 count,HCARD handleval);
BTICardAPI ERRVAL BTICard_CoProcMemRdsW(LPUINT16 valueptr,UINT32 addrval,UINT32 count,HCARD handleval);
BTICardAPI ERRVAL BTICard_CoProcMemRdW(LPUINT16 valueptr,UINT32 addrval,HCARD handleval);
BTICardAPI ERRVAL BTICard_CoProcMemWrL(UINT32 value,UINT32 addrval,HCARD handleval);
BTICardAPI ERRVAL BTICard_CoProcMemWrsL(LPUINT32 valueptr,UINT32 addrval,UINT32 count,HCARD handleval);
BTICardAPI ERRVAL BTICard_CoProcMemWrsW(LPUINT16 valueptr,UINT32 addrval,UINT32 count,HCARD handleval);
BTICardAPI ERRVAL BTICard_CoProcMemWrW(UINT16 value,UINT32 addrval,HCARD handleval);
BTICardAPI ERRVAL BTICard_CoreOpen(LPHCORE lphCore,INT corenum,HCARD hCard);
BTICardAPI VOID BTICard_DARClr(UINT16 maskval,UINT16 addrval,HCORE handleval);
BTICardAPI BOOL BTICard_DARGet(UINT16 maskval,UINT16 addrval,HCORE handleval);
BTICardAPI UINT32 BTICard_DARRdL(UINT16 addrval,HCORE handleval);
BTICardAPI VOID BTICard_DARRdsW(LPUINT16 valueptr,UINT16 addrval,INT countval,HCORE handleval);
BTICardAPI UINT16 BTICard_DARRdW(UINT16 addrval,HCORE handleval);
BTICardAPI VOID BTICard_DARSet(UINT16 maskval,UINT16 addrval,HCORE handleval);
BTICardAPI VOID BTICard_DARWrL(UINT32 value,UINT16 addrval,HCORE handleval);
BTICardAPI VOID BTICard_DARWrsW(LPUINT16 valueptr,UINT16 addrval,INT countval,HCORE handleval);
BTICardAPI VOID BTICard_DARWrW(UINT16 value,UINT16 addrval,HCORE handleval);
BTICardAPI UINT32 BTICard_Div(UINT32 diva,UINT32 divb);
BTICardAPI VOID BTICard_Div64(LPUINT32 resulth,LPUINT32 resultl,UINT32 valah,UINT32 valal,UINT32 valbh,UINT32 valbl);
BTICardAPI ERRVAL BTICard_DspBioClear(HCORE handleval);
BTICardAPI BOOL BTICard_DspBioRd(HCORE handleval);
BTICardAPI ERRVAL BTICard_DspBioSet(HCORE handleval);
BTICardAPI ERRVAL BTICard_DspIntfClear(UINT16 intmask,HCORE handleval);
BTICardAPI BOOL BTICard_DspIntfRd(UINT16 intmask,HCORE handleval);
BTICardAPI ERRVAL BTICard_DspIntmClear(HCORE handleval);
BTICardAPI ERRVAL BTICard_DspIntmSet(HCORE handleval);
BTICardAPI ERRVAL BTICard_DspXfClear(HCORE handleval);
BTICardAPI BOOL BTICard_DspXfRd(HCORE handleval);
BTICardAPI ERRVAL BTICard_DspXfSet(HCORE handleval);
BTICardAPI LPCSTR BTICard_ErrDesc(ERRVAL errval,HCARD handleval);
BTICardAPI LPCSTR BTICard_ErrDescStr(ERRVAL errval,HCORE handleval);
BTICardAPI LPCSTR BTICard_ErrName(ERRVAL errval,HCARD handleval);
BTICardAPI ERRVAL BTICard_EventLogClear(HCORE handleval);
BTICardAPI ERRVAL BTICard_EventLogConfig(UINT16 configval,UINT16 count,HCORE handleval);
BTICardAPI UINT32 BTICard_EventLogRd(LPUINT16 typeval,LPUINT32 infoval,LPINT channel,HCORE handleval);
BTICardAPI INT BTICard_EventLogStatus(HCORE handleval);
BTICardAPI VOID BTICard_ExpandMant(LPUINT32 mant,LPINT exp);
BTICardAPI BOOL BTICard_ExtDinRd(HCORE handleval);
BTICardAPI VOID BTICard_ExtDinWr(BOOL dinval,HCORE handleval);
BTICardAPI VOID BTICard_ExtDIODirSet(INT dionum,BOOL dirval,HCORE handleval);
BTICardAPI VOID BTICard_ExtDIOEnWr(INT dionum,BOOL dioval,BOOL dioen,HCORE handleval);
BTICardAPI ERRVAL BTICard_ExtDIOMonConfig(UINT16 rise_edge,UINT16 fall_edge,INT banknum,HCORE handleval);
BTICardAPI BOOL BTICard_ExtDIORd(INT dionum,HCORE handleval);
BTICardAPI VOID BTICard_ExtDIOWr(INT dionum,BOOL dioval,HCORE handleval);
BTICardAPI ERRVAL BTICard_ExtDIOBankConfig(UINT32 configtype, UINT16 configmask, INT banknum, HCORE handleval);
BTICardAPI INT BTICard_ExtLEDRd(HCORE handleval);
BTICardAPI VOID BTICard_ExtLEDWr(INT ledval,HCORE handleval);
BTICardAPI VOID BTICard_ExtStatusLEDRd(LPINT ledon,LPINT ledcolor,HCORE handleval);
BTICardAPI VOID BTICard_ExtStatusLEDWr(INT ledon,INT ledcolor,HCORE handleval);
BTICardAPI VOID BTICard_FileClose(LPVOID handle);
BTICardAPI BOOL BTICard_FileErr(VOID);
BTICardAPI VOID BTICard_FileErrClr(VOID);
BTICardAPI VOID BTICard_FileErrSet(VOID);
BTICardAPI LPVOID BTICard_FileOpenRead(LPCSTR filename);
BTICardAPI LPVOID BTICard_FileOpenWrite(LPCSTR filename);
BTICardAPI BOOL BTICard_FileRead(LPVOID handle,LPVOID buffer,UINT16 count);
BTICardAPI BOOL BTICard_FileSeek(LPVOID handle,UINT32 offset);
BTICardAPI UINT32 BTICard_FileTell(LPVOID handle);
BTICardAPI BOOL BTICard_FileWrite(LPVOID handle,LPVOID buffer,UINT16 count);
BTICardAPI ERRVAL BTICard_FPGAAdd(LPCSTR filename,HCORE handleval);
BTICardAPI ERRVAL BTICard_FPGAInfoRd(LPUINT16 buf,HCORE handleval);
BTICardAPI ERRVAL BTICard_FPGAWipe(HCORE handleval);
BTICardAPI UINT16 BTICard_GetHigh(UINT32 val);
BTICardAPI UINT32 BTICard_GetHighL(UINT64 val);
BTICardAPI UINT16 BTICard_GetLow(UINT32 val);
BTICardAPI UINT32 BTICard_GetLowL(UINT64 val);
BTICardAPI UINT32 BTICard_GetTickCount();
BTICardAPI UINT16 BTICard_GlobalRdW(UINT16 addrval,HCORE handleval);
BTICardAPI VOID BTICard_GlobalWrW(UINT16 value,UINT16 addrval,HCORE handleval);
BTICardAPI ERRVAL BTICard_HandleDisableSet(BOOL flag,HCARD handleval);
BTICardAPI ERRVAL BTICard_HandleIgnoreSet(BOOL flag,HCARD handleval);
BTICardAPI ERRVAL BTICard_HandleInfo(LPSTR cardstr,LPINT cardnum,LPUINT32 sizval,LPVOID *vxdptr,HCORE handleval);
BTICardAPI ERRVAL BTICard_HandleInfoEx(LPUINT32 valueptr,UINT32 type,HCORE handleval);
BTICardAPI BOOL BTICard_HandleIsCard(HCARD handleval);
BTICardAPI BOOL BTICard_HandleIsCore(HCORE handleval);
BTICardAPI ERRVAL BTICard_HandleMakeCard(LPHCARD lphCard,LPINT lpcorenum,HCORE hCore);
BTICardAPI ERRVAL BTICard_HandleMakeCore(LPHCORE lphCore,INT corenum,HCARD hCard);
BTICardAPI ERRVAL BTICard_HandleMakeRPC(LPHCARD hCard_Remote,LPHRPC lphRPC,HCARD handleval);
BTICardAPI BOOL BTICard_HandleOkay(HCARD handleval);
BTICardAPI UINT32 BTICard_HeapAlloc(INT section,UINT32 wordcount,HCORE handleval);
BTICardAPI UINT32 BTICard_HeapAllocAll(INT section,LPUINT32 wordcount,HCORE handleval);
BTICardAPI UINT32 BTICard_HeapAllocEx(UINT16 configval,INT section,UINT32 wordcount,HCORE handleval);
BTICardAPI UINT32 BTICard_HeapWipe(INT section,HCORE handleval);
BTICardAPI ERRVAL BTICard_HexRd(LPCSTR fname,ERRVAL (*proc)(UINT16 value,UINT16 section,UINT32 addr,LPVOID lpParam),LPVOID lpParam);
BTICardAPI ERRVAL BTICard_HexRun(LPCSTR fname,HCORE handleval);
BTICardAPI ERRVAL BTICard_HexRunIO(LPCSTR fname,HCARD handleval);
BTICardAPI ERRVAL BTICard_HexRunIO16(LPCSTR fname,HCARD handleval);
BTICardAPI ERRVAL BTICard_HexRunSerial(LPCSTR fname,HCARD handleval);
BTICardAPI ERRVAL BTICard_HexStat(LPUINT32 lowaddr,LPUINT32 highaddr,LPUINT32 count,LPCSTR fname);
BTICardAPI ERRVAL BTICard_HexWrAddr(UINT16 addr,HCARD handleval);
BTICardAPI ERRVAL BTICard_HexWrByte(BYTE ch,HCARD handleval);
BTICardAPI ERRVAL BTICard_HexWrClose(HCARD handleval);
BTICardAPI ERRVAL BTICard_HexWrFlush(HCARD handleval);
BTICardAPI ERRVAL BTICard_HexWrFlushByte(UINT16 value,HCARD handleval);
BTICardAPI ERRVAL BTICard_HexWrOpen(LPCSTR fname,HCARD handleval);
BTICardAPI ERRVAL BTICard_HexWrPage(UINT16 pageval,HCARD handleval);
BTICardAPI VOID BTICard_HookProtocolFunc(INT index,ERRVAL (FARCODE * ptr)(INT msgval,LPVOID lpParam,HCARD handleval));
BTICardAPI VOID BTICard_HPIFill(UINT16 value,UINT16 addrval,INT countval,HCORE handleval);
BTICardAPI UINT32 BTICard_HPIRdL(UINT16 addrval,HCORE handleval);
BTICardAPI VOID BTICard_HPIRdsL(LPUINT32 valueptr,UINT16 addrval,INT countval,HCORE handleval);
BTICardAPI VOID BTICard_HPIRdsW(LPUINT16 valueptr,UINT16 addrval,INT countval,HCORE handleval);
BTICardAPI UINT16 BTICard_HPIRdW(UINT16 addrval,HCORE handleval);
BTICardAPI VOID BTICard_HPIWrL(UINT32 value,UINT16 addrval,HCORE handleval);
BTICardAPI VOID BTICard_HPIWrsL(LPUINT32 valueptr,UINT16 addrval,INT countval,HCORE handleval);
BTICardAPI VOID BTICard_HPIWrsW(LPUINT16 valueptr,UINT16 addrval,INT countval,HCORE handleval);
BTICardAPI VOID BTICard_HPIWrW(UINT16 value,UINT16 addrval,HCORE handleval);
BTICardAPI ERRVAL BTICard_Identify(LPBTIIDENTIFY infoptr,HCARD handleval);
BTICardAPI UINT16 BTICard_IDRegRd(INT gate_array_num,HCORE handleval);
BTICardAPI VOID BTICard_IDRegWr(UINT16 value,INT gate_array_num,HCORE handleval);
BTICardAPI VOID BTICard_IntClear(HCORE handleval);
BTICardAPI ERRVAL BTICard_IntDisable(HCORE handleval);
BTICardAPI ERRVAL BTICard_IntEnable(HCORE handleval);
BTICardAPI ERRVAL BTICard_IntEnableCond(HCORE handleval);
BTICardAPI INT BTICard_IntGet(HCORE handleval);
BTICardAPI ERRVAL BTICard_IntInstall(LPVOID hEvent,HCORE handleval);
BTICardAPI VOID BTICard_IntReset(HCORE handleval);
BTICardAPI ERRVAL BTICard_IntUninstall(HCORE handleval);
BTICardAPI ERRVAL BTICard_IntVerify(LPUINT32 valueptr,HCORE handleval);
BTICardAPI UINT32 BTICard_IORdL(INT addrval,HCORE handleval);
BTICardAPI VOID BTICard_IORdsL(LPUINT32 valueptr,UINT32 addrval,INT countval,HCORE handleval);
BTICardAPI VOID BTICard_IORdsW(LPUINT16 valueptr,UINT32 addrval,INT countval,HCORE handleval);
BTICardAPI UINT16 BTICard_IORdW(INT addrval,HCORE handleval);
BTICardAPI UINT16 BTICard_IOWINRdW(INT addrval,HCORE handleval);
BTICardAPI VOID BTICard_IOWINWrW(UINT16 value,INT addrval,HCORE handleval);
BTICardAPI VOID BTICard_IOWrL(UINT32 value,INT addrval,HCORE handleval);
BTICardAPI VOID BTICard_IOWrsL(LPUINT32 valueptr,UINT32 addrval,INT countval,HCORE handleval);
BTICardAPI VOID BTICard_IOWrsW(LPUINT16 valueptr,UINT32 addrval,INT countval,HCORE handleval);
BTICardAPI VOID BTICard_IOWrW(UINT16 value,INT addrval,HCORE handleval);
BTICardAPI ERRVAL BTICard_IRIGConfig(UINT32 configval,HCORE handleval);
BTICardAPI UINT32 BTICard_IRIGFieldGetDays(UINT32 irigvalh,UINT32 irigvall);
BTICardAPI UINT32 BTICard_IRIGFieldGetHours(UINT32 irigvalh,UINT32 irigvall);
BTICardAPI UINT32 BTICard_IRIGFieldGetMicrosec(UINT32 irigvalh,UINT32 irigvall);
BTICardAPI UINT32 BTICard_IRIGFieldGetMillisec(UINT32 irigvalh,UINT32 irigvall);
BTICardAPI UINT32 BTICard_IRIGFieldGetMin(UINT32 irigvalh,UINT32 irigvall);
BTICardAPI UINT32 BTICard_IRIGFieldGetSec(UINT32 irigvalh,UINT32 irigvall);
BTICardAPI VOID BTICard_IRIGFieldPutDays(UINT32 value,LPUINT32 irigvalh,LPUINT32 irigvall);
BTICardAPI VOID BTICard_IRIGFieldPutHours(UINT32 value,LPUINT32 irigvalh,LPUINT32 irigvall);
BTICardAPI VOID BTICard_IRIGFieldPutMicrosec(UINT32 value,LPUINT32 irigvalh,LPUINT32 irigvall);
BTICardAPI VOID BTICard_IRIGFieldPutMillisec(UINT32 value,LPUINT32 irigvalh,LPUINT32 irigvall);
BTICardAPI VOID BTICard_IRIGFieldPutMin(UINT32 value,LPUINT32 irigvalh,LPUINT32 irigvall);
BTICardAPI VOID BTICard_IRIGFieldPutSec(UINT32 value,LPUINT32 irigvalh,LPUINT32 irigvall);
BTICardAPI ERRVAL BTICard_IRIGInputThresholdGet(LPUINT16 dacval,HCORE handleval);
BTICardAPI ERRVAL BTICard_IRIGInputThresholdSet(UINT16 dacval,HCORE handleval);
BTICardAPI ERRVAL BTICard_IRIGRd(LPBTIIRIGTIME irigtime,HCORE handleval);
BTICardAPI ERRVAL BTICard_IRIGRdEx(LPUINT16 timebuf,HCORE handleval);
BTICardAPI BOOL BTICard_IRIGSyncStatus(HCORE handleval);
BTICardAPI VOID BTICard_IRIGTimeBCDToBin(LPUINT32 timevalh,LPUINT32 timevall,UINT32 irigvalh,UINT32 irigvall);
BTICardAPI VOID BTICard_IRIGTimeBCDToNanoBin(LPUINT32 timevalh,LPUINT32 timevall,UINT32 irigvalh,UINT32 irigvall);
BTICardAPI VOID BTICard_IRIGTimeBinToBCD(LPUINT32 irigvalh,LPUINT32 irigvall,UINT32 timevalh,UINT32 timevall);
BTICardAPI VOID BTICard_IRIGTimeNanoBinToBCD(LPUINT32 irigvalh,LPUINT32 irigvall,UINT32 timevalh,UINT32 timevall);
BTICardAPI ERRVAL BTICard_IRIGWr(LPBTIIRIGTIME irigtime,HCORE handleval);
BTICardAPI ERRVAL BTICard_IRIGWrEx(LPUINT16 timebuf,HCORE handleval);
BTICardAPI ERRVAL BTICard_KernIntStatus(LPINT valueptr,HCARD handleval);
BTICardAPI ERRVAL BTICard_KernStatus(LPULONG_PTR valueptr,UINT32 type,HCARD handleval);
BTICardAPI ERRVAL BTICard_KernStatusEx(LPULONG_PTR valueptr,UINT32 type,UINT32 index,HCARD handleval);
BTICardAPI LPVOID BTICard_KernUSBKillWorker(HCARD handleval);
BTICardAPI UINT32 BTICard_MakeLong(UINT16 valh,UINT16 vall);
BTICardAPI UINT64 BTICard_MakeQuad(UINT32 valh,UINT32 vall);
BTICardAPI UINT16 BTICard_MakeWord(BYTE valh,BYTE vall);
BTICardAPI LPSTR BTICard_MantToAscii(LPSTR buf,INT mant,INT exp);
BTICardAPI UINT32 BTICard_Mask(UINT32 dataval,UINT16 cntval);
BTICardAPI VOID BTICard_MaxMant(LPUINT32 mant,LPINT exp);
BTICardAPI UINT32 BTICard_Mod(UINT32 moda,UINT32 modb);
BTICardAPI VOID BTICard_Mod64(LPUINT32 resulth,LPUINT32 resultl,UINT32 valah,UINT32 valal,UINT32 valbh,UINT32 valbl);
BTICardAPI UINT32 BTICard_Mul(UINT32 mula,UINT32 mulb);
BTICardAPI VOID BTICard_Mul64(LPUINT32 resulth,LPUINT32 resultl,UINT32 valah,UINT32 valal,UINT32 valbh,UINT32 valbl);
BTICardAPI VOID BTICard_NormalMant(LPUINT32 mant,LPINT exp);
BTICardAPI UINT16 BTICard_PortRd(INT addrval,HCORE handleval);
BTICardAPI VOID BTICard_PortWr(UINT16 value,INT addrval,HCORE handleval);
BTICardAPI ERRVAL BTICard_ProcCall(UINT32 useraddr,HCORE handleval);
BTICardAPI UINT32 BTICard_ProcLoad(LPUINT16 userbuf,UINT16 count,HCORE handleval);
BTICardAPI VOID BTICard_ProcLoc(LPUINT16 inputcode,LPUINT16 outputcode,UINT16 inputbase,UINT16 outputbase,INT count);
BTICardAPI ERRVAL BTICard_ProcRun(LPUINT16 userbuf,UINT16 count,HCORE handleval);
BTICardAPI ERRVAL BTICard_ProcSetFore(UINT32 useraddr,HCORE handleval);
BTICardAPI ERRVAL BTICard_ProcSetInt(UINT16 useraddr,INT intnum,UINT16 intmask,HCORE handleval);
BTICardAPI ERRVAL BTICard_ProcSetPost(UINT32 useraddr,UINT32 msgaddr,INT channum,HCORE handleval);
BTICardAPI ERRVAL BTICard_ProcSetPre(UINT32 useraddr,UINT32 msgaddr,INT channum,HCORE handleval);
BTICardAPI UINT16 BTICard_ProgRdW(UINT32 addrval,HCORE handleval);
BTICardAPI VOID BTICard_ProgWrW(UINT16 value,UINT32 addrval,HCORE handleval);
BTICardAPI ERRVAL BTICard_PXIStatus(LPUINT32 infoptr,UINT16 infotype,HCORE handleval);
BTICardAPI VOID BTICard_RAMFill(UINT16 value,UINT32 addrval,UINT32 countval,HCORE handleval);
BTICardAPI UINT16 BTICard_RAMRdB(UINT32 addrval,HCORE handleval);
BTICardAPI UINT32 BTICard_RAMRdL(UINT32 addrval,HCORE handleval);
BTICardAPI VOID BTICard_RAMRdmL(LPUINT32 valueptr,LPUINT32 addrptr,INT countval,HCORE handleval);
BTICardAPI VOID BTICard_RAMRdmW(LPUINT16 valueptr,LPUINT32 addrptr,INT countval,HCORE handleval);
BTICardAPI VOID BTICard_RAMRdsL(LPUINT32 valueptr,UINT32 addrval,INT countval,HCORE handleval);
BTICardAPI VOID BTICard_RAMRdsW(LPUINT16 valueptr,UINT32 addrval,INT countval,HCORE handleval);
BTICardAPI UINT16 BTICard_RAMRdW(UINT32 addrval,HCORE handleval);
BTICardAPI VOID BTICard_RAMWipe(HCORE handleval);
BTICardAPI VOID BTICard_RAMWipeEx(UINT16 value,HCORE handleval);
BTICardAPI VOID BTICard_RAMWrB(UINT16 value,UINT32 addrval,HCORE handleval);
BTICardAPI VOID BTICard_RAMWrL(UINT32 value,UINT32 addrval,HCORE handleval);
BTICardAPI VOID BTICard_RAMWrmL(LPUINT32 valueptr,LPUINT32 addrptr,INT countval,HCORE handleval);
BTICardAPI VOID BTICard_RAMWrmW(LPUINT16 valueptr,LPUINT32 addrptr,INT countval,HCORE handleval);
BTICardAPI VOID BTICard_RAMWrsL(LPUINT32 valueptr,UINT32 addrval,INT countval,HCORE handleval);
BTICardAPI VOID BTICard_RAMWrsW(LPUINT16 valueptr,UINT32 addrval,INT countval,HCORE handleval);
BTICardAPI VOID BTICard_RAMWrW(UINT16 value,UINT32 addrval,HCORE handleval);
BTICardAPI UINT32 BTICard_ReverseLong(UINT32 value);
BTICardAPI UINT16 BTICard_ReverseWord(UINT16 value);
BTICardAPI ERRVAL BTICard_ROMClose(HCORE handleval);
BTICardAPI ERRVAL BTICard_ROMFlush(HCORE handleval);
BTICardAPI ERRVAL BTICard_ROMInfoRd(LPBYTE buf,HCORE handleval);
BTICardAPI ERRVAL BTICard_ROMInfoWr(LPBYTE buf,HCORE handleval);
BTICardAPI ERRVAL BTICard_ROMOpen(HCORE handleval);
BTICardAPI ERRVAL BTICard_ROMProg(UINT16 enableflag,LPUINT16 valueptr,UINT16 count,UINT32 addrval,HCORE handleval);
BTICardAPI ERRVAL BTICard_ROMRdsW(LPUINT16 valueptr,UINT32 addrval,UINT16 countval,HCORE handleval);
BTICardAPI ERRVAL BTICard_ROMRdW(LPUINT16 valueptr,UINT32 addrval,HCORE handleval);
BTICardAPI ERRVAL BTICard_ROMSwitchSet(BOOL flag,HCARD handleval);
BTICardAPI ERRVAL BTICard_ROMWrsW(UINT16 enableflag,LPUINT16 valueptr,UINT32 addrval,UINT16 countval,HCORE handleval);
BTICardAPI ERRVAL BTICard_ROMWrW(UINT16 value,UINT32 addrval,HCORE handleval);
BTICardAPI UINT32 BTICard_SeqBlkRd(LPUINT16 buf,UINT32 bufcount,LPUINT32 blkcnt,HCORE handleval);
BTICardAPI UINT32 BTICard_SeqBlkRdEx(LPUINT16 buf,UINT32 bufcount,UINT32 maxblkcnt,LPUINT32 blkcnt,HCORE handleval);
BTICardAPI ERRVAL BTICard_SeqClear(HCORE handleval);
BTICardAPI UINT16 BTICard_SeqCommRd(LPUINT16 buf,UINT16 bufcount,HCORE handleval);
BTICardAPI ERRVAL BTICard_SeqConfig(UINT32 configval,HCORE handleval);
BTICardAPI ERRVAL BTICard_SeqConfigEx(UINT32 configval,UINT32 seqcount,UINT16 cardnum,HCORE handleval);
BTICardAPI ERRVAL BTICard_SeqConfigExx(UINT32 configval,UINT32 seqaddr,UINT32 seqcount,UINT16 cardnum,HCORE handleval);
BTICardAPI UINT32 BTICard_SeqDMARd(LPUINT16 buf,UINT32 bufcount,HCORE handleval);
BTICardAPI BOOL BTICard_SeqFindCheckVersion(LPUINT16 pRecord,UINT16 version);
BTICardAPI ERRVAL BTICard_SeqFindInit(LPUINT16 seqbuf,UINT32 seqbufsize,LPSEQFINDINFO sfinfo);
BTICardAPI ERRVAL BTICard_SeqFindMore1553(LPSEQRECORDMORE1553 *pRecMore,LPSEQRECORD1553 pRecBase);
BTICardAPI ERRVAL BTICard_SeqFindMore1553Ex(LPSEQRECORDMORE1553 pRecMore,UINT16 recordsize,LPSEQRECORD1553 pRecBase);
BTICardAPI ERRVAL BTICard_SeqFindNext(LPUINT16 *pRecord,LPUINT16 seqtype,LPSEQFINDINFO sfinfo);
BTICardAPI ERRVAL BTICard_SeqFindNext1553(LPSEQRECORD1553 *pRecord,LPSEQFINDINFO sfinfo);
BTICardAPI ERRVAL BTICard_SeqFindNext1553Ex(LPSEQRECORD1553 pRecord,UINT16 recordsize,LPSEQFINDINFO sfinfo);
BTICardAPI ERRVAL BTICard_SeqFindNext429(LPSEQRECORD429 *pRecord,LPSEQFINDINFO sfinfo);
BTICardAPI ERRVAL BTICard_SeqFindNext429Ex(LPSEQRECORD429 pRecord,UINT16 recordsize,LPSEQFINDINFO sfinfo);
BTICardAPI ERRVAL BTICard_SeqFindNext708(LPSEQRECORD708 *pRecord,LPSEQFINDINFO sfinfo);
BTICardAPI ERRVAL BTICard_SeqFindNext708Ex(LPSEQRECORD708 pRecord,UINT16 recordsize,LPSEQFINDINFO sfinfo);
BTICardAPI ERRVAL BTICard_SeqFindNext717(LPSEQRECORD717 *pRecord,LPSEQFINDINFO sfinfo);
BTICardAPI ERRVAL BTICard_SeqFindNext717Ex(LPSEQRECORD717 pRecord,UINT16 recordsize,LPSEQFINDINFO sfinfo);
BTICardAPI ERRVAL BTICard_SeqFindNextCSDB(LPSEQRECORDCSDB *pRecord,LPSEQFINDINFO sfinfo);
BTICardAPI ERRVAL BTICard_SeqFindNextCSDBEx(LPSEQRECORDCSDB pRecord,UINT16 recordsize,LPSEQFINDINFO sfinfo);
BTICardAPI ERRVAL BTICard_SeqFindNextDIO(LPSEQRECORDDIO *pRecord,LPSEQFINDINFO sfinfo);
BTICardAPI ERRVAL BTICard_SeqFindNextDIOEx(LPSEQRECORDDIO pRecord,UINT16 recordsize,LPSEQFINDINFO sfinfo);
BTICardAPI ERRVAL BTICard_SeqFindNextEBR(LPSEQRECORDEBR *pRecord,LPSEQFINDINFO sfinfo);
BTICardAPI ERRVAL BTICard_SeqFindNextEBREx(LPSEQRECORDEBR pRecord,UINT16 recordsize,LPSEQFINDINFO sfinfo);
BTICardAPI ERRVAL BTICard_SeqFindNextEx(LPUINT16 pRecord,UINT16 recordcount,LPUINT16 seqtype,LPSEQFINDINFO sfinfo);
BTICardAPI INT BTICard_SeqInterval(INT interval,INT mode,HCORE handleval);
BTICardAPI UINT16 BTICard_SeqIntervalEx(UINT16 shiftval,HCORE handleval);
BTICardAPI BOOL BTICard_SeqIsRunning(HCORE handleval);
BTICardAPI UINT16 BTICard_SeqLogFrequency(UINT16 logfreq,HCORE handleval);
BTICardAPI UINT16 BTICard_SeqRd(LPUINT16 buf,HCORE handleval);
BTICardAPI UINT16 BTICard_SeqRdEx(LPUINT16 buf,UINT16 bufcount,HCORE handleval);
BTICardAPI BOOL BTICard_SeqResume(HCORE handleval);
BTICardAPI BOOL BTICard_SeqStart(HCORE handleval);
BTICardAPI BOOL BTICard_SeqStatus(HCORE handleval);
BTICardAPI BOOL BTICard_SeqStop(HCORE handleval);
BTICardAPI UINT32 BTICard_Shl(UINT32 dataval,UINT16 cntval);
BTICardAPI UINT32 BTICard_Shr(UINT32 dataval,UINT16 cntval);
BTICardAPI UINT16 BTICard_SignMant(LPCSTR str);
BTICardAPI VOID BTICard_Sub64(LPUINT32 resulth,LPUINT32 resultl,UINT32 valah,UINT32 valal,UINT32 valbh,UINT32 valbl);
BTICardAPI VOID BTICard_SwapEndianL(LPUINT32 value);
BTICardAPI VOID BTICard_SwapEndianW(LPUINT16 valuea,LPUINT16 valueb);
BTICardAPI VOID BTICard_SwapIfBigEndianL(LPUINT32 value);
BTICardAPI VOID BTICard_SwapIfBigEndianW(LPUINT16 valuea,LPUINT16 valueb);
BTICardAPI VOID BTICard_SwapIfLittleEndianL(LPUINT32 value);
BTICardAPI VOID BTICard_SwapIfLittleEndianW(LPUINT16 valuea,LPUINT16 valueb);
BTICardAPI ERRVAL BTICard_SysMonClear(HCORE handleval);
BTICardAPI INT BTICard_SysMonDACToVal(UINT16 dacval,INT rangemin,INT rangemax,UINT16 dacval_max,INT scalefactor,HCARD handleval);
BTICardAPI LPCSTR BTICard_SysMonDescGet(INT index,HCORE handleval);
BTICardAPI ERRVAL BTICard_SysMonInit(HCORE handleval);
BTICardAPI INT BTICard_SysMonMaxRd(INT index,HCORE handleval);
BTICardAPI INT BTICard_SysMonMinRd(INT index,HCORE handleval);
BTICardAPI INT BTICard_SysMonNomRd(INT index,HCORE handleval);
BTICardAPI ERRVAL BTICard_SysMonThresholdGet(LPBOOL enable,LPINT min,LPINT max,INT index,HCORE handleval);
BTICardAPI ERRVAL BTICard_SysMonThresholdSet(BOOL enable,INT min,INT max,INT index,HCORE handleval);
BTICardAPI UINT32 BTICard_SysMonTypeGet(INT index,HCORE handleval);
BTICardAPI LPCSTR BTICard_SysMonUserStr(INT value,INT index,HCORE handleval);
BTICardAPI INT BTICard_SysMonValRd(INT index,HCORE handleval);
BTICardAPI LPCSTR BTICard_SysMonValStr(INT index,HCORE handleval);
BTICardAPI UINT16 BTICard_SysMonValToDAC(INT val,INT rangemin,INT rangemax,UINT16 dacval_max,INT scalefactor,HCARD handleval);
BTICardAPI INT BTICard_TickTimerRemaining(INT timer);
BTICardAPI INT BTICard_TickTimerStart(INT milliseconds);
BTICardAPI BOOL BTICard_TickTimerValid(INT timer);
BTICardAPI ERRVAL BTICard_Timer64Rd(LPUINT32 valueh,LPUINT32 valuel,HCORE handleval);
BTICardAPI VOID BTICard_Timer64Wr(UINT32 valueh,UINT32 valuel,HCORE handleval);
BTICardAPI VOID BTICard_TimerClear(HCORE handleval);
BTICardAPI UINT32 BTICard_TimerRd(HCORE handleval);
BTICardAPI INT BTICard_TimerResolution(INT timerresol,HCORE handleval);
BTICardAPI UINT16 BTICard_TimerResolutionEx(UINT16 timershift,HCORE handleval);
BTICardAPI INT BTICard_TimerStatus(HCORE handleval);
BTICardAPI VOID BTICard_TimerWr(UINT32 value,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMDriftMaxGet(LPUINT32 driftptr,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMDriftMaxSet(UINT32 drift,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMDriftRd(LPINT driftptr,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMDriftRelWr(INT drift,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMDriftWr(INT drift,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMInputDelayCompGet(LPINT delayptr,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMInputDelayCompSet(INT delay,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMInputThresholdAuto(INT pinindex,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMInputThresholdGet(LPUINT16 dacval,INT pinindex,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMInputThresholdSet(UINT16 dacval,INT pinindex,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMIntTrigger(LPUINT64 timetagptr,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMIRIGControlRd(LPUINT32 ctrlptr,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMIRIGControlWr(UINT32 ctrlval,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMIRIGYearsRd(LPUINT32 year,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMIRIGYearsWr(UINT32 year,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMJumpThresholdGet(LPUINT32 drift,LPUINT32 offset,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMJumpThresholdSet(UINT32 drift,UINT32 offset,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMOffsetLastRd(LPINT64 offsetptr,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMReset(HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMSourceConfig(UINT32 sourcecfg,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMStatus(LPUINT32 statusptr,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMSyncConfig(UINT32 timeconfig,UINT32 driftconfig,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMTimerRd(LPUINT64 valueptr,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMTimerRelWr(INT64 value,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMTimerRolloverGet(LPUINT64 valueptr,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMTimerRolloverSet(UINT64 value,HCORE handleval);
BTICardAPI ERRVAL BTICard_TSMTimerWr(UINT64 value,HCORE handleval);
BTICardAPI INT BTICard_ValAsciiCmpi(LPSTR str1,LPSTR str2);
BTICardAPI LPSTR BTICard_ValAsciiCpy(LPSTR strdest,LPCSTR strsrc,INT count);
BTICardAPI VOID BTICard_ValAsciiTrimLead(LPSTR buf);
BTICardAPI VOID BTICard_ValAsciiTrimTrail(LPSTR buf);
BTICardAPI UINT32 BTICard_ValFromAscii(LPCSTR asciistr,INT radixval);
BTICardAPI UINT32 BTICard_ValGetBits(UINT32 oldvalue,INT startbit,INT endbit);
BTICardAPI LPSTR BTICard_ValIncAscii(LPSTR asciistr);
BTICardAPI LPSTR BTICard_ValInccAscii(LPSTR asciistr);
BTICardAPI BOOL BTICard_ValIsLower(INT value);
BTICardAPI INT BTICard_ValLenAscii(INT numbits,INT radixval);
BTICardAPI UINT32 BTICard_ValPutBits(UINT32 oldvalue,UINT32 newfld,INT startbit,INT endbit);
BTICardAPI LPSTR BTICard_ValToAscii(UINT32 value,LPSTR asciistr,INT numbits,INT radixval);
BTICardAPI INT BTICard_ValToUpper(INT value);
BTICardAPI UINT32 BTICard_VARRdL(UINT16 addrval,HCORE handleval);
BTICardAPI VOID BTICard_VARRdsW(LPUINT16 valueptr,UINT16 addrval,INT countval,HCORE handleval);
BTICardAPI UINT16 BTICard_VARRdW(UINT16 addrval,HCORE handleval);
BTICardAPI VOID BTICard_VARWrL(UINT32 value,UINT16 addrval,HCORE handleval);
BTICardAPI VOID BTICard_VARWrsW(LPUINT16 valueptr,UINT16 addrval,INT countval,HCORE handleval);
BTICardAPI VOID BTICard_VARWrW(UINT16 value,UINT16 addrval,HCORE handleval);
BTICardAPI ERRVAL BTICard_XBitFileRd(LPCSTR fname,ERRVAL (*proc)(UINT16 value,UINT16 section,UINT32 addr,LPVOID lpParam),LPVOID lpParam);

#ifdef __cplusplus
}
#endif

/**
*
*  External definitions
*
**/

#ifdef __cplusplus

extern "C" BTICardAPI UINT32 FARDATA BTICard_HandleTotalCount;
extern "C" BTICardAPI UINT32 FARDATA BTICard_HandleCardNumbers[64];

#else

extern BTICardAPI UINT32 FARDATA BTICard_HandleTotalCount;
extern BTICardAPI UINT32 FARDATA BTICard_HandleCardNumbers[64];

#endif

/**
*
*  Core number constants
*
**/

enum {	COREA              = 0x0000,               //Selects Core A
		COREB              = 0x0001,               //Selects Core B
		COREC              = 0x0002,               //Selects Core C
		CORED              = 0x0003                //Selects Core D
};

/**
*
*  Sequential Record configuration options
*
**/

enum {	SEQCFG_DEFAULT     = 0x00000000L,          //Select all default settings
		SEQCFG_FILLHALT    = 0x00000000L,          //Enable sequential record in fill and halt mode (default)
		SEQCFG_DISABLE     = 0x00000001L,          //Disable sequential record
		SEQCFG_CONTINUOUS  = 0x00000002L,          //Enable sequential record in continuous mode
		SEQCFG_DMA         = 0x00000004L,          //Enable monitor in DMA mode
		SEQCFG_FREE        = 0x00000008L,          //Enable sequential record in free mode
		SEQCFG_DELTA       = 0x00000010L,          //Enable sequential record in delta mode
		SEQCFG_INTERVAL    = 0x00000020L,          //Enable sequential record in interval mode
		SEQCFG_NOLOGFULL   = 0x00000000L,          //Do not generate event log when sequential record is full (default)
		SEQCFG_LOGFULL     = 0x00001000L,          //Generate event log when sequential record is full
		SEQCFG_NOLOGFREQ   = 0x00000000L,          //Do not generate event logs at a user specified frequency (default)
		SEQCFG_LOGFREQ     = 0x00002000L,          //Generate event logs at user specified frequency
		SEQCFG_TCPNODELAY  = 0x00004000L,          //Disable Nagle's algorithm on sequential DMA for RPC devices
		SEQCFG_16K         = 0x00000000L,          //Allocate a 16K sequential record buffer (default)
		SEQCFG_ALLAVAIL    = 0x01000000L,          //Allocate all available memory to a sequential record buffer
		SEQCFG_32K         = 0x02000000L,          //Allocate a 32K sequential record buffer
		SEQCFG_64K         = 0x04000000L,          //Allocate a 64K sequential record buffer
		SEQCFG_128K        = 0x08000000L           //Allocate a 128K sequential record buffer
};

/**
*
*  Sequential Record type fields
*
**/

enum {	SEQTYPE_MASK       = 0x00FF,               //Sequential record type mask value
		SEQTYPE_429        = 0x0001,               //Sequential record type is ARINC 429
		SEQTYPE_717        = 0x0002,               //Sequential record type is ARINC 717
		SEQTYPE_1553       = 0x0003,               //Sequential record type is MIL-STD-1553
		SEQTYPE_708        = 0x0004,               //Sequential record type is ARINC 708
		SEQTYPE_USER       = 0x0005,               //Sequential record type is User Defined
		SEQTYPE_CSDB       = 0x0006,               //Sequential record type is CSDB
		SEQTYPE_DIO        = 0x0007,               //Sequential record type is DIO
		SEQTYPE_EBR        = 0x0008,               //Sequential record type is EBR-1553
		SEQTYPE_717SF      = 0x0009,               //Sequential record type is ARINC 717 Subframe
		SEQTYPE_PMC10      = 0x000A,               //Sequential record type is PMC10
		SEQTYPE_RESTART    = 0x00FF                //Sequential record type is Restart
};

/**
*
*  Sequential Record version fields
*
**/

enum {	SEQVER_MASK        = 0xFF00,               //Sequential record version mask value
		SEQVER_0           = 0x0000,               //Sequential record version number is 0
		SEQVER_1           = 0x0100                //Sequential record version number is 1
};

/**
*
*  Event log list configuration options
*
**/

enum {	LOGCFG_DEFAULT     = 0x00000000L,          //Select all default settings
		LOGCFG_ENABLE      = 0x00000000L,          //Enable event log list (default)
		LOGCFG_DISABLE     = 0x00000001L           //Disable event log list
};

/**
*
*  IRIG timer configuration options
*
**/

enum {	IRIGCFG_DEFAULT    = 0x00000000L,          //Select all default settings
		IRIGCFG_ENABLE     = 0x00000000L,          //Enable IRIG timer (default)
		IRIGCFG_DISABLE    = 0x00000001L,          //Disable IRIG timer
		IRIGCFG_SPEEDB     = 0x00000000L,          //Bit rate is IRIGB (default)
		IRIGCFG_SPEEDA     = 0x00000002L,          //Bit rate is IRIGA
		IRIGCFG_INTERNAL   = 0x00000000L,          //IRIG timer operates internally (default)
		IRIGCFG_EXTERNAL   = 0x00000004L,          //IRIG timer operates externally
		IRIGCFG_SLAVE      = 0x00000000L,          //IRIG timer is a slave  / receiver (default)
		IRIGCFG_MASTER     = 0x00000008L,          //IRIG timer is a master / transmitter
		IRIGCFG_PPS        = 0x00000010L,          //IRIG timer operates in PPS mode (rcv/xmt)
		IRIGCFG_PWM        = 0x00000000L,          //IRIG timer uses pulse width modulated signaling (rcv/xmt) (default)
		IRIGCFG_AM         = 0x00000020L           //IRIG timer uses amplitude modulated signaling (rcv/xmt, hw dependant)
};

/**
*
*  IRIG timer field definitions
*
**/

enum {	IRIGFIELD_USECLSB  = 0x0000,               //Microseconds LSB in timestamp field
		IRIGFIELD_USECMSB  = 0x000B,               //Microseconds MSB in timestamp field
		IRIGFIELD_MSECLSB  = 0x000C,               //Milliseconds LSB in timestamp field
		IRIGFIELD_MSECMSB  = 0x0017,               //Milliseconds MSB in timestamp field
		IRIGFIELD_SECLSB   = 0x0018,               //Seconds LSB in timestamp field
		IRIGFIELD_SECMSB   = 0x001F,               //Seconds MSB in timestamp field

		IRIGFIELD_MINLSB   = 0x0000,               //Minutes LSB in timestamph field
		IRIGFIELD_MINMSB   = 0x0007,               //Minutes MSB in timestamph field
		IRIGFIELD_HRSLSB   = 0x0008,               //Hours LSB in timestamph field
		IRIGFIELD_HRSMSB   = 0x000F,               //Hours MSB in timestamph field
		IRIGFIELD_DAYLSB   = 0x0010,               //Days LSB in timestamph field
		IRIGFIELD_DAYMSB   = 0x001B                //Days MSB in timestamph field
};

/**
*
*  C54x Global Registers
*
**/

enum {	C54_GREG_IMR       = 0x0000,               //Interrupt mask register
		C54_GREG_IFR       = 0x0001,               //Interrupt flag register
		C54_GREG_ST0       = 0x0006,               //Status register 0
		C54_GREG_ST1       = 0x0007,               //Status register 1
		C54_GREG_AL        = 0x0008,               //Accumulator A low word (bits 15-00)
		C54_GREG_AH        = 0x0009,               //Accumulator A high word (bits 31-16)
		C54_GREG_AG        = 0x000A,               //Accumulator A guars bits (bits 39-32)
		C54_GREG_BL        = 0x000B,               //Accumulator B low word (bits 15-00)
		C54_GREG_BH        = 0x000C,               //Accumulator B high word (bits 31-16)
		C54_GREG_BG        = 0x000D,               //Accumulator B guard bits (bits 39-32
		C54_GREG_T         = 0x000E,               //Temporary register
		C54_GREG_TRN       = 0x000F,               //Transition register
		C54_GREG_AR0       = 0x0010,               //Auxilliary register 0
		C54_GREG_AR1       = 0x0011,               //Auxilliary register 1
		C54_GREG_AR2       = 0x0012,               //Auxilliary register 2
		C54_GREG_AR3       = 0x0013,               //Auxilliary register 3
		C54_GREG_AR4       = 0x0014,               //Auxilliary register 4
		C54_GREG_AR5       = 0x0015,               //Auxilliary register 5
		C54_GREG_AR6       = 0x0016,               //Auxilliary register 6
		C54_GREG_AR7       = 0x0017,               //Auxilliary register 7
		C54_GREG_SP        = 0x0018,               //Stack pointer
		C54_GREG_BK        = 0x0019,               //Circular-buffer size register
		C54_GREG_BRC       = 0x001A,               //Block-repeat counter
		C54_GREG_RSA       = 0x001B,               //Block-repeat start address
		C54_GREG_REA       = 0x001C,               //Block-repeat end address
		C54_GREG_PMST      = 0x001D,               //Processor mode status register
		C54_GREG_XPC       = 0x001E,               //Program counter extension register
		C54_GREG_DRR20     = 0x0020,               //McBSP0 data receive register high
		C54_GREG_DRR10     = 0x0021,               //McBSP0 data receive register low
		C54_GREG_DXR20     = 0x0022,               //McBSP0 data transmit register high
		C54_GREG_DXR10     = 0x0023,               //McBSP0 data transmit register low
		C54_GREG_TIM       = 0x0024,               //Timer count register
		C54_GREG_PRD       = 0x0025,               //Timer period register
		C54_GREG_TCR       = 0x0026,               //Timer control register
		C54_GREG_SWWSR     = 0x0028,               //External interface software wait-state register
		C54_GREG_BSCR      = 0x0029,               //External interface bank-switching control register
		C54_GREG_SWCR      = 0x002B,               //Software wait-state control register
		C54_GREG_HPIC      = 0x002C,               //Host port interface control register
		C54_GREG_DRR22     = 0x0030,               //McBSP2 data receive register high
		C54_GREG_DRR12     = 0x0031,               //McBSP2 data receive register low
		C54_GREG_DXR22     = 0x0032,               //McBSP2 data transmit register high
		C54_GREG_DXR12     = 0x0033,               //McBSP2 data transmit register low
		C54_GREG_SPSA2     = 0x0034,               //McBSP2 sub-address register
		C54_GREG_SPDR2     = 0x0035,               //McBSP2 sub-address data register
		C54_GREG_SPSA0     = 0x0038,               //McBSP0 sub-address register
		C54_GREG_SPDR0     = 0x0039,               //McBSP0 sub-address data register
		C54_GREG_DRR21     = 0x0040,               //McBSP1 data receive register high
		C54_GREG_DRR11     = 0x0041,               //McBSP1 data receive register low
		C54_GREG_DXR21     = 0x0042,               //McBSP1 data transmit register high
		C54_GREG_DXR11     = 0x0043,               //McBSP1 data transmit register low
		C54_GREG_SPSA1     = 0x0048,               //McBSP1 sub-address register
		C54_GREG_SPDR1     = 0x0049,               //McBSP1 sub-address data register
		C54_GREG_DMPREC    = 0x0054,               //DMA channel priority and enable control
		C54_GREG_DMSBAR    = 0x0055,               //DMA channel sub-address register
		C54_GREG_DMADI     = 0x0056,               //DMA channel sub-address data with increment
		C54_GREG_DMADN     = 0x0057,               //DMA channel sub-address data without increment
		C54_GREG_CLKMD     = 0x0058                //Clock-mode register
};

/**
*
*  Event types.
*
**/

enum {	EVENTTYPE_1553MSG    = 0x0001,             //MIL-STD-1553 message
		EVENTTYPE_1553OPCODE = 0x0002,             //MIL-STD-1553 event log opcode
		EVENTTYPE_1553HALT   = 0x0003,             //MIL-STD-1553 schedule halt
		EVENTTYPE_1553PAUSE  = 0x0004,             //MIL-STD-1553 schedule pause
		EVENTTYPE_1553LIST   = 0x0005,             //MIL-STD-1553 list buffer empty/full
		EVENTTYPE_1553SERIAL = 0x0006,             //MIL-STD-1553 serial empty

		EVENTTYPE_429MSG     = 0x0011,             //ARINC 429 message
		EVENTTYPE_429OPCODE  = 0x0012,             //ARINC 429 event log opcode
		EVENTTYPE_429HALT    = 0x0013,             //ARINC 429 schedule halt
		EVENTTYPE_429PAUSE   = 0x0014,             //ARINC 429 schedule pause
		EVENTTYPE_429LIST    = 0x0015,             //ARINC 429 list buffer empty/full
		EVENTTYPE_429ERR     = 0x0016,             //ARINC 429 decoder error detected

		EVENTTYPE_717WORD    = 0x0021,             //ARINC 717 word received
		EVENTTYPE_717SUBFRM  = 0x0022,             //ARINC 717 sub frame completed
		EVENTTYPE_717SYNCERR = 0x0023,             //ARINC 717 receive channel lost synchronization

		EVENTTYPE_708MSG     = 0x0031,             //ARINC 708 message

		EVENTTYPE_SEQFULL    = 0x0041,             //Sequential record full
		EVENTTYPE_SEQFREQ    = 0x0042,             //Sequential record frequency

		EVENTTYPE_422TXTHRESHOLD  = 0x0051,        //RS-422 TX under threshold
		EVENTTYPE_422TXFIFO       = 0x0052,        //RS-422 TX underflow
		EVENTTYPE_422RXTHRESHOLD  = 0x0053,        //RS-422 RX over threshold
		EVENTTYPE_422RXFIFO       = 0x0054,        //RS-422 RX overflow
		EVENTTYPE_422RXERROR      = 0x0055,        //RS-422 RX error

		EVENTTYPE_CSDBMSG     = 0x0058,            //CSDB message
		EVENTTYPE_CSDBOPCODE  = 0x0059,            //CSDB event log opcode
		EVENTTYPE_CSDBHALT    = 0x005A,            //CSDB schedule halt
		EVENTTYPE_CSDBPAUSE   = 0x005B,            //CSDB schedule pause
		EVENTTYPE_CSDBLIST    = 0x005C,            //CSDB list buffer empty/full
		EVENTTYPE_CSDBERR     = 0x005D,            //CSDB decoder error detected
		EVENTTYPE_CSDBSYNCERR = 0x005E,            //CSDB receive channel lost synchronization

		EVENTTYPE_DIOEDGE     = 0x0060,            //DIO edge event
		EVENTTYPE_DIOFAULT    = 0x0061,            //DIO fault event

		EVENTTYPE_BITERROR    = 0x0071,            //Built-in Test error event

		EVENTTYPE_EBRMSG    = 0x0081,              //EBR message
		EVENTTYPE_EBROPCODE = 0x0082,              //EBR event log opcode
		EVENTTYPE_EBRHALT   = 0x0083,              //EBR schedule halt
		EVENTTYPE_EBRPAUSE  = 0x0084,              //EBR schedule pause
		EVENTTYPE_EBRLIST   = 0x0085,              //EBR list buffer empty/full
		EVENTTYPE_EBRRESV   = 0x0086               //EBR Reserved
};

/**
*
*  Card Info types
*
**/

enum {	INFOTYPE_PLAT      = 0x0001,               //Returns the platform type
		INFOTYPE_PROD      = 0x0002,               //Returns the product type
		INFOTYPE_GEN       = 0x0003,               //Returns the generation number
		INFOTYPE_1553COUNT = 0x0004,               //Returns the 1553 channel count
		INFOTYPE_1553SIZE  = 0x0005,               //Returns the 1553 channel size
		INFOTYPE_429COUNT  = 0x0006,               //Returns the 429 channel count
		INFOTYPE_429SIZE   = 0x0007,               //Returns the 429 channel size
		INFOTYPE_717COUNT  = 0x0008,               //Returns the 717 channel count
		INFOTYPE_717SIZE   = 0x0009,               //Returns the 717 channel size
		INFOTYPE_708COUNT  = 0x000A,               //Returns the 708 channel count
		INFOTYPE_708SIZE   = 0x000B,               //Returns the 708 channel size
		INFOTYPE_VERSION   = 0x000C,               //Returns the version number
		INFOTYPE_DATE      = 0x000D,               //Returns the version date
		INFOTYPE_CHINFO    = 0x000E,               //Returns the channel info
		INFOTYPE_422COUNT  = 0x000F,               //Returns the 422 port count
		INFOTYPE_422SIZE   = 0x0010,               //Returns the 422 port size
		INFOTYPE_CSDBCOUNT = 0x0011,               //Returns the CSDB channel count
		INFOTYPE_CSDBSIZE  = 0x0012,               //Returns the CSDB channel size
		INFOTYPE_DIOCOUNT  = 0x0013,               //Returns the DIO bank count
		INFOTYPE_DIOSIZE   = 0x0014,               //Returns the DIO bank size
		INFOTYPE_HWGEN     = 0x0015,               //Returns the Hardware Generation
		INFOTYPE_EBRCOUNT  = 0x0016,               //Returns the EBR channel count
		INFOTYPE_EBRSIZE   = 0x0017,               //Returns the EBR channel size
		INFOTYPE_CARDTYPE  = 0x0018,               //Returns the card type
		INFOTYPE_SERIALNUM = 0x0019,               //Returns the serial number
		INFOTYPE_VERSIONEX = 0x001A                //Returns the version number including minor-minor
};

/**
*
*  Co-Processor Info types
*
**/

enum {	COPROCINFO_PLAT      = 0x0001,              //Returns the platform type
		COPROCINFO_PROD      = 0x0002,              //Returns the product type
		COPROCINFO_GEN       = 0x0003,              //Returns the generation number
		COPROCINFO_VERSION   = 0x0004,              //Returns the version number (major.minor)
		COPROCINFO_DATE      = 0x0005,              //Returns the version date
		COPROCINFO_CISADDR   = 0x0006,              //Returns the CIS address
		COPROCINFO_DMA       = 0x0007,              //Returns whether or not CoProc supports DMA mode
		COPROCINFO_VERSIONEX = 0x0009,              //Returns the version number (major.minor.minorminor)
		COPROCINFO_PN        = 0x000A               //Returns software part number
};

/**
*
*  CIS types
*
**/

enum {	CISTYPE_CARD         = 0x0001,              //Select card CIS
		CISTYPE_IOMODULE     = 0x0002,              //Select I/O module CIS
		CISTYPE_PLX          = 0x0003,              //Select PLX EEPROM
		CISTYPE_INFO         = 0x0004,              //Select Info module CIS
		CISTYPE_ENV          = 0x0005,              //Select environment
		CISTYPE_BIT          = 0x0006               //Select bitfile
};

/**
*
*  Handle Info types
*
**/

enum {	HANDINFO_CORENUM	= 0x0001,               //Returns the Handle Core number
		HANDINFO_RPC		= 0x0002               //Returns the Handle Core number
};

/**
*
*  Trigger flags
*
**/

enum {	TRIGMASK_TRIGA     = 0x0001,               //Selects trigger line A from default DIN
		TRIGMASK_TRIGB     = 0x0002,               //Selects trigger line B from default DIN
		TRIGMASK_TRIGC     = 0x0004,               //Selects trigger line C from default DIN
		TRIGMASK_PXITRIGA  = 0x0010,               //Selects trigger line A from PXI_TRIG[0]
		TRIGMASK_PXITRIGB  = 0x0020,               //Selects trigger line B from PXI_TRIG[1]
		TRIGMASK_PXITRIGC  = 0x0040,               //Selects trigger line C from PXI_TRIG[2]
		TRIGMASK_PXISTARA  = 0x0100,               //Selects trigger line A from PXIe_DSTARA
		TRIGMASK_PXISTARB  = 0x0200,               //Selects trigger line B from PXIe_DSTARB
		TRIGMASK_PXISTARC  = 0x0400,               //Selects trigger line C from PXI_STAR

		TRIGVAL_TRIGAOFF   = 0x0000,               //Tests for trigger line A inactive
		TRIGVAL_TRIGAON    = 0x0001,               //Tests for trigger line A active
		TRIGVAL_TRIGBOFF   = 0x0000,               //Tests for trigger line B inactive
		TRIGVAL_TRIGBON    = 0x0002,               //Tests for trigger line B active
		TRIGVAL_TRIGCOFF   = 0x0000,               //Tests for trigger line C inactive
		TRIGVAL_TRIGCON    = 0x0004,               //Tests for trigger line C active

		TRIGPOL_TRIGAL     = 0x0000,               //Sets active low polarity for trigger line A
		TRIGPOL_TRIGAH     = 0x0001,               //Sets active high polarity for trigger line A
		TRIGPOL_TRIGAF     = 0x0010,               //Sets active on falling edge of trigger line A
		TRIGPOL_TRIGAR     = 0x0011,               //Sets active on rising edge of trigger line A
		TRIGPOL_TRIGAMASK  = 0x0011,               //Mask of all trigger line A options

		TRIGPOL_TRIGBL     = 0x0000,               //Sets active low polarity for trigger line B
		TRIGPOL_TRIGBH     = 0x0002,               //Sets active high polarity for trigger line B
		TRIGPOL_TRIGBF     = 0x0020,               //Sets active on falling edge of trigger line B
		TRIGPOL_TRIGBR     = 0x0022,               //Sets active on rising edge of trigger line B
		TRIGPOL_TRIGBMASK  = 0x0022,               //Mask of all trigger line B options

		TRIGPOL_TRIGCL     = 0x0000,               //Sets active low polarity for trigger line C
		TRIGPOL_TRIGCH     = 0x0004,               //Sets active high polarity for trigger line C
		TRIGPOL_TRIGCF     = 0x0040,               //Sets active on falling edge of trigger line C
		TRIGPOL_TRIGCR     = 0x0044,               //Sets active on rising edge of trigger line C
		TRIGPOL_TRIGCMASK  = 0x0044                //Mask of all trigger line C options
};

/**
*
*  Sync flags
*
**/

enum {	SYNCMASK_SYNCA     = 0x0001,              //Selects sync line A
		SYNCMASK_SYNCB     = 0x0002,              //Selects sync line B
		SYNCMASK_SYNCC     = 0x0004,              //Selects sync line C

		SYNCMASK_PXITRIGA  = 0x0100,              //Selects sync line A to PXI_TRIG 0
		SYNCMASK_PXITRIGB  = 0x0200,              //Selects sync line B to PXI_TRIG 1
		SYNCMASK_PXITRIGC  = 0x0400,              //Selects sync line C	to PXI_TRIG 2
		SYNCMASK_PXISTARC  = 0x4000,              //Selects sync line C	to PXI STAR

		SYNCPOL_SYNCAL     = 0x0000,              //Sets active low polarity for sync line A
		SYNCPOL_SYNCAH     = 0x0001,              //Sets active high polarity for sync line A
		SYNCPOL_SYNCBL     = 0x0000,              //Sets active low polarity for sync line B
		SYNCPOL_SYNCBH     = 0x0002,              //Sets active high polarity for sync line B
		SYNCPOL_SYNCCL     = 0x0000,              //Sets active low polarity for sync line C
		SYNCPOL_SYNCCH     = 0x0004               //Sets active high polarity for sync line C
};

/**
*
*  PXI Status flags
*
**/

enum {	PXITYPE_GEOADDR		= 0x0001,			//Return the Geographical Address
		PXITYPE_CLKSEL		= 0x0002,			//Return the Clock Selection (Local oscillator vs PXIe_CLK100)
		PXITYPE_TRIGVERS	= 0x0003,			//Return the Version of the triggers
		PXITYPE_OUTEN		= 0x0004			//Return the bitmask of output enables for dionums 33 to 48
};

/**
*
*  Heap flags.
*
**/

enum {	HEAPCFG_DEFAULT    = 0x0000,               //Block is allocated within page
		HEAPCFG_TEST       = 0x0001,               //Returns address but doesn't make it permanent
		HEAPCFG_NULL       = 0x0002,               //Returns address but doesn't mark it as in use
		HEAPCFG_SPAN       = 0x0004,               //Block can span pages
		HEAPCFG_QUICK      = 0x0008,               //Does a quick allocation
		HEAPCFG_NOALIGN    = 0x0010,               //Relaxes alignment rules to help fit

		HEAPSECT_SRAM      = 0x0000                //Heap section for primary SRAM
};

/**
*
*  Timer resolutions.
*
**/

enum {
		TIMERRESOL_CURRENT = 0,                    //Keep the current timer resolution
		TIMERRESOL_1US     = 1,                    //1us timer resolution
		TIMERRESOL_16US    = 2,                    //16us timer resolution
		TIMERRESOL_1024US  = 3,                    //1024us timer resolution
		TIMERRESOL_1NS     = 4                     //1ns timer resolution
};

/**
*
*  Timer status.
*
**/

enum {	TIMETAG_FORMAT_BIN = 0,                    //Timetag will be in binary format
		TIMETAG_FORMAT_BCD = 1                     //Timetag will be in BCD format
};

/**
*
*  Interval calculation modes.
*
**/

enum {	INTERVALMODE_CLOSEST  = 1,                 //Finds interval closest to value specified
		INTERVALMODE_LESS     = 2,                 //Finds closest interval less than value specified
		INTERVALMODE_GREATER  = 3                  //Finds closest interval more than value specified
};

/**
*
*  Test flags.
*
**/

enum {	TEST_LEVEL_0       = 0,                    //Test I/O interface
		TEST_LEVEL_1       = 1,                    //Test memory interface
		TEST_LEVEL_2       = 2,                    //Test communication process
		TEST_LEVEL_3       = 3                     //Test bus transceiver
};

/**
*
*  Status flags.
*
**/

enum {	STAT_EMPTY         = 0,                   //Buffer is empty
		STAT_PARTIAL       = 1,                   //Buffer is partially filled
		STAT_FULL          = 2,                   //Buffer is full
		STAT_OFF           = 3                    //Buffer is off
};

/**
*
*  SysMon flags
*
**/

enum {	SYSMONTYPE_NONE		= 0,							//Sensor not present
		SYSMONTYPE_TEMP		= 1,							//Temperature sensor
		SYSMONTYPE_VOLTAGE	= 2,							//Voltage sensor
		SYSMONTYPE_CURRENT	= 3								//Current sensor
};

/**
*
*  SysMon Read Constant
*
**/

enum {	SYSMONRD_NOTVALID				= -1000000	//SysMon value not available
};

/**
*
*  BIT flags
*
**/

enum {	BITCFG_DEFAULT					= 0x00000000L,		//Select all default settings
		BITCFG_MEMECC_ENABLE			= 0x00000000L,		//Enables Stopping card operation on memory ECC failure  ie, uncorrectable error(default)
		BITCFG_MEMECC_DISABLE			= 0x00000001L,		//Disables Stopping card operation on memory ECC failure  ie, uncorrectable error
		BITCFG_FPGA_ENABLE				= 0x00000000L,		//Enables FPGA Single Event Upset (SEU) detection (default)
		BITCFG_FPGA_DISABLE				= 0x00000002L,		//Disables FPGA Single Event Upset (SEU) detection
		BITCFG_PROTOCOL_ENABLE			= 0x00000000L,		//Enables Protocol error reporting (default)
		BITCFG_PROTOCOL_DISABLE			= 0x00000004L,		//Disables Protocol error reporting
		BITCFG_MEMECC_NOLOG				= 0x00000000L,		//Do not generate event logs when ECC event occurs (default)
		BITCFG_MEMECC_LOG				= 0x00000010L,		//Generate event logs when ECC event occurs
		BITCFG_FPGA_NOLOG				= 0x00000000L,		//Do not generate event logs when FPGA Single Event Upset (SEU) event occurs (default)
		BITCFG_FPGA_LOG					= 0x00000020L,		//Generate event logs when FPGA Single Event Upset (SEU) event occurs
		BITCFG_PROTOCOL_NOLOG			= 0x00000000L,		//Do not generate event logs when Protocol error occurs (default)
		BITCFG_PROTOCOL_LOG				= 0x00000040L,		//Generate event logs when Protocol error occurs
		BITCFG_CARD_STOPPED_NOLOG		= 0x00000000L,		//Do not generate event logs when the card is stopped due to CBIT error (default)
		BITCFG_CARD_STOPPED_LOG			= 0x00000080L,		//Generate event logs when the card is stopped due to CBIT error
		BITCFG_SYSMON_NOLOG				= 0x00000000L,		//Do not generate event logs when System Monitor error occurs (default)
		BITCFG_SYSMON_LOG				= 0x00000100L		//Generate event logs when System Monitor error occurs
};

enum {	BITSTAT_NOSTATUS				= 0x00000000L,		//No errors or warnings for BIT
		BITSTAT_CARD_STOPPED			= 0x20000000L,		//Continuous BIT fatal system error, card stopped
		BITSTAT_CBIT_FPGA_ERR			= 0x10000000L,		//Continuous BIT FPGA error (SEU)
		BITSTAT_SINGLE_BIT_ERR			= 0x08000000L,		//Continuous BIT Single Bit Error (Correctable)
		BITSTAT_DOUBLE_BIT_ERR			= 0x04000000L,		//Continuous BIT Double Bit Error
		BITSTAT_SYSMON_ERR				= 0x0000FFFFL,		//Continuous BIT System Monitor error
		BITSTAT_PROTOCOL_ERR			= 0x00FF0000L		//Continuous BIT Protocol Error
};

/**
*
*  Timing Synchronization Manager configuration options
*
**/

enum {	TSMCFG_PPS0			= 0x00000001,				//PPS on DC Pin 0
		TSMCFG_PPS1			= 0x00000002,				//PPS on DC Pin 1
		TSMCFG_PWMIRIG0		= 0x00000004,				//DC IRIG on DC Pin 0
		TSMCFG_PWMIRIG1		= 0x00000008,				//DC IRIG on DC Pin 1
		TSMCFG_AMIRIG		= 0x00000010,				//AM IRIG
		TSMCFG_10MHZ		= 0x00000020,				//10MHz (output and Drift control input only)
		TSMCFG_HOST			= 0x00000040,				//Host (or 1588) control (input-only)
		TSMCFG_PPSMODE		= 0x00000080,				//IRIG is in PPS Mode (input-only)
		TSMCFG_AMDACAUTO	= 0x00000000,				//Enable auto-threshold determination for the IRIG AM high dac
		TSMCFG_AMDACUSER	= 0x00000100,				//User control of threshold for the IRIG AM high dac
		TSMCFG_IRIGDAYS		= 0x00000200,				//Select IRIG days counting from 1-365.  Default is 0-364
		TSMCFG_NONE			= 0x00000000,				//Timer is free-running
		TSMCFG_IRIGA		= 0x00010000,				//Set IRIG Time Code to A
		TSMCFG_IRIGB		= 0x00000000				//Set IRIG Time Code to B (default)
};

/**
*
*  Timing Synchronization Manager status flags
*
**/

enum {
		TSMSTAT_IRIGPRES		= 0x00000001,			//Input IRIG signal is toggling and decodable
		TSMSTAT_IRIGBITSYNC		= 0x00000002,			//Input IRIG signal is toggling
		TSMSTAT_IRIGSYNC		= 0x00000004,			//TSM is locked to IRIG input
		TSMSTAT_10MHZPRES		= 0x00000008,			//Input 10 MHz signal is toggling
		TSMSTAT_10MHZSYNC		= 0x00000010,			//TSM is locked to 10 MHz input
		TSMSTAT_PPSPRES			= 0x00000020,			//Input PPS signal is toggling
		TSMSTAT_PPSSYNC			= 0x00000040,			//TSM is locked to PPS input
		TSMSTAT_OUTOFBOUNDS		= 0x00000080			//Timing source is beyond drift synchronization threshold
};

/**
*
*  Timing Synchronization Manager pin selection values
*
**/

enum {	TSMPIN_PWMIRIG0    = 0x0001,              //Index of PWM IRIG/PPS Pin 0 Threshold
		TSMPIN_PWMIRIG1    = 0x0002,              //Index of PWM IRIG/PPS Pin 1 Threshold
		TSMPIN_AMIRIGH     = 0x0003,              //Index of AM IRIG Pin High Threshold
		TSMPIN_AMIRIGL     = 0x0004,              //Index of AM IRIG Pin Low Threshold
		TSMPIN_10MHZ       = 0x0005               //Index of 10MHz Pin Threshold
};

/**
*
*  DIO Configuration selection values
*
**/

enum {
	EXTDIOBANKCFG_INPUTMODE = 1     //Set input mode to Open/Ground or 28V/Open (0-Open/Gnd, 1=28V/Open)
};

/**
*
*  Other flags.
*
**/

enum {	RCV     = 0,
		XMT     = 1
};

/**
*
*  Error types.
*
**/

enum {	ERR_NONE          =  0,                   //No error
		ERR_UNKNOWN       = -1,                   //An unexpected error occurred
		ERR_BADVER        = -2,                   //A bad version was encountered
		ERR_BADPTR        = -3,                   //A bad pointer was passed
		ERR_NOCORE        = -4,                   //The specified core number doesn't exist
		ERR_BADPARAMS     = -11,                  //Function called with bad parameters
		ERR_NOHANDLES     = -12,                  //CardOpen() already has allocated too many handles
		ERR_NOCARD        = -13,                  //CardOpen() could not find a L43 card at the specified address
		ERR_NOIO          = -14,                  //CardOpen() could not find the I/O ports
		ERR_NOMEM         = -15,                  //CardOpen() could not find the memory
		ERR_BAD16BIT      = -16,                  //Card is conflicting with another 16-bit card
		ERR_WRONGMODEL    = -17,                  //Card does not support this feature
		ERR_NOSEL         = -18,                  //CardOpen() could not allocate a memory selector
		ERR_LOCK          = -19,                  //The communication process is locked up
		ERR_TOOMANY       = -20,                  //Too many channels have been configured
		ERR_BADHANDLE     = -21,                  //A bad handle was specified
		ERR_GOODHANDLE    = -22,                  //The handle is still valid and should not be destroyed
		ERR_NOTCHAN       = -23,                  //Not a valid channel
		ERR_NOTXMT        = -24,                  //The Transmitter has not been configured
		ERR_NOTRCV        = -25,                  //The Receiver has not been configured
		ERR_NOTSEQ        = -26,                  //The Sequential Record has not been configured
		ERR_ALLOC         = -27,                  //There is not enough memory to allocate
		ERR_VXD           = -28,                  //An error occurred in the VXD
		ERR_BADLABEL      = -29,                  //The specified label value is not valid
		ERR_BADSDI        = -30,                  //The specified sdi value is not valid
		ERR_BADMSG        = -31,                  //The specified command block is not a message block
		ERR_BADSCHNDX     = -32,                  //Specified command index is out of range
		ERR_BUFSIZE       = -33,                  //Insufficient space in user buffer
		ERR_NOCONFIG      = -34,                  //The card has not been properly configured
		ERR_CONFLICTS     = -35,                  //Unable to resolve conflicts
		ERR_RANGE         = -36,                  //Schedule is out of range
		ERR_FACTOR        = -37,                  //A bad factor value was specified
		ERR_NOIOBOOT      = -40,                  //Could not talk to IO Boot port of DSP
		ERR_BOOTFULL      = -41,                  //No space to add boot code
		ERR_BOOTNUM       = -42,                  //There is no boot code with the specified number
		ERR_ACCESS        = -43,                  //Unable to write to access register
		ERR_ROMVERIFY     = -44,                  //Unable to verify the value written to the ROM
		ERR_COUNT         = -45,                  //An invalid count was specified
		ERR_CRC           = -46,                  //There was a bad checksum in the HEX file
		ERR_FNAME         = -47,                  //Bad filenames were specified
		ERR_FRDWR         = -48,                  //There was an error reading or writing the HEX file
		ERR_HEX           = -49,                  //There was a bad hex character in the HEX file
		ERR_INDEX         = -51,                  //The command block index was invalid or the schedule is full
		ERR_NOMSGS        = -52,                  //No messages specified
		ERR_TYPE          = -54,                  //There was a bad type value in the HEX file
		ERR_ZEROLEN       = -55,                  //Zero length was specified
		ERR_BADADDRESS    = -56,                  //A bad address was specified
		ERR_MSGNDX        = -57,                  //A bad message index was specified
		ERR_BADTA         = -60,                  //A bad terminal address was specified
		ERR_BADFRAME      = -61,                  //A bad frame time was specified
		ERR_NOTBC         = -62,                  //The BC has not been configured
		ERR_NOTRT         = -63,                  //The RT has not been configured
		ERR_NOTMON        = -64,                  //The monitor has not been configured
		ERR_SELFIOFAIL    = -71,                  //I/O selftest failed
		ERR_SELFMEMFAIL   = -72,                  //Memory selftest failed
		ERR_SELFCOMMFAIL  = -73,                  //Communication selftest failed
		ERR_SELFXMTFAIL   = -74,                  //Transmit selftest failed
		ERR_PLXBUG        = -75,                  //PLX bug is causing problems
		ERR_NOTSUPPORTED  = -76,                  //Base class does not support feature
		ERR_DLL           = -77,                  //A required DLL is missing
		ERR_SEQTYPE       = -80,                  //Invalid sequential record type value
		ERR_SEQNEXT       = -81,                  //Next sequential record does not exist
		ERR_SEQFINDINFO   = -82,                  //The SEQFINDINFO structure is not valid
		ERR_SEQBASEPTR    = -83,                  //The base pointer passed is invalid
		ERR_SEQMORE       = -84,                  //More (extended) record data does not exist
		ERR_TIMEOUT       = -90,                  //Function timed out waiting for data
		ERR_SUBFRMNUM     = -101,                 //Invalid SubFrame number was specified
		ERR_WORDNUM       = -102,                 //Invalid Word number was specified
		ERR_NOTINSYNC     = -103,                 //Not Synchronized to databus
		ERR_SUPERFRM      = -104,                 //SuperFrame not configured
		ERR_SUPERFRMNUM   = -105,                 //Invalid SuperFrame number was specified
		ERR_BADPORT       = -106,                 //A bad port number was specified
		ERR_NOTLHUB       = -107,                 //The Logical Hub has not been configured
		ERR_UNDERFLOW     = -108,                 //The read failed because the buffer is empty
		ERR_OVERFLOW      = -109,                 //The write failed because the buffer is full
		ERR_ENDIAN        = -110,                 //An endianness mismatch was detected
		ERR_NOCLK         = -111                  //Protocol clock source is missing or invalid
};

#endif
