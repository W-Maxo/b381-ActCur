#if !defined __B181__H_
#define __B181__H_

#include "UNILPTX.h"
const DWORD	IOCTRL_ADCConfig		= 1;
const DWORD	IOCTRL_ADCReadData		= 2;
const DWORD	IOCTRL_DACConfig		= 3;
const DWORD	IOCTRL_DACWriteData		= 4;
const DWORD	IOCTRL_LAConfig			= 5;
const DWORD	IOCTRL_LAReadData		= 6;
const DWORD	IOCTRL_LGConfig			= 7;
const DWORD	IOCTRL_LGWriteData		= 8;
const DWORD	IOCTRL_CmnConfig		= 9;
const DWORD	IOCTRL_CmnControl		= 10;
const DWORD	IOCTRL_CmnReadStatus	= 11;
const DWORD	IOCTRL_Initialize		= 12;
const DWORD	IOCTRL_Deinitialize		= 13;

const UCHAR DtSrc_DirectChannels	= 0;
const UCHAR DtSrc_Mem0				= 1;
const UCHAR DtSrc_Mem1				= 2;
const UCHAR DtSrc_Trigger			= 3;

const UCHAR RunSrc_SW	= 1;
const UCHAR RunSrc_LD0	= 2; 
const UCHAR RunSrc_LD2	= 4;
const UCHAR RunSrc_LD4	= 8;
const UCHAR RunSrc_LD6	= 16;

const UCHAR ClockSrc_IntGen0	= 1;
const UCHAR ClockSrc_IntGen1	= 2;
const UCHAR ClockSrc_LD1		= 4;	
const UCHAR ClockSrc_LD3		= 8;
const UCHAR ClockSrc_LD5		= 16;
const UCHAR ClockSrc_LD7		= 32;

const UCHAR MemSrc_ADC0	= 1;
const UCHAR MemSrc_ADC1	= 2;
const UCHAR MemSrc_DAC0 = 4;
const UCHAR MemSrc_DAC1 = 8;
const UCHAR MemSrc_LA0	= 16;
const UCHAR MemSrc_LA1	= 32;
const UCHAR MemSrc_LG0	= 64;
const UCHAR MemSrc_LG1	= 128;

const BOOL LDDirection_LG = TRUE;
const BOOL LDDirection_LA = FALSE;

const UCHAR WReg_ADCConfig		= 0;
const UCHAR WReg_DACConfig		= 1;
const UCHAR WReg_DACConfigEx	= 2;
const UCHAR WReg_DACMem0Data	= 3;
const UCHAR WReg_DACMem1Data	= 4;
const UCHAR WReg_DACSingleData	= 5;
const UCHAR WReg_LAConfig		= 6;
const UCHAR WReg_LGConfig		= 7;	
const UCHAR WReg_LGMem0Data		= 8;
const UCHAR WReg_LGMem1Data		= 9;
const UCHAR WReg_LGSingleData	= 10; 
const UCHAR WReg_MemSources		= 11;
const UCHAR WReg_LPortDirection = 12;
const UCHAR WReg_IntScale0		= 13;
const UCHAR WReg_IntScale1		= 14;
const UCHAR WReg_Control		= 15;

const UCHAR RReg_ADCMem0Data	= 0;
const UCHAR RReg_ADCMem1Data	= 1;
const UCHAR RReg_ADCSingleData	= 2;
const UCHAR RReg_LARam0Data		= 3;
const UCHAR RReg_LARam1Data		= 4;
const UCHAR RReg_LATrigger		= 5;
const UCHAR RReg_LAData			= 6;
const UCHAR RReg_Status			= 7;



typedef struct ADCConfigStruct{
				BOOL	m_bRecorder;
				UCHAR	m_cChannels;
				UCHAR	m_cRunSource;
				UCHAR	m_cClockSource;
				WORD	m_wWorkLen;

} CADCConfigStruct;

typedef struct ReadADCStruct{
              USHORT* m_pData;
              UCHAR m_cDataSource;	              
			  WORD  m_wCount;
} CReadADCStruct;

typedef struct DACConfigStruct{
				BOOL	m_bSingleCycle;
				BOOL	m_bEndlessGenerator;
				UCHAR	m_cChannels;
				UCHAR	m_cRunSource;
				UCHAR	m_cClockSource;
				WORD	m_wWorkLen;

} CDACConfigStruct;

typedef struct WriteDACCStruct{
				UCHAR m_cDataDestination;
				ULONG* m_pData;
				WORD   m_wCount;
				UCHAR m_cChannel;
				BOOL  m_bLDAC_;


} CWriteDACStruct;

typedef struct LAConfigStruct{
				BOOL	m_bRecorder;
				UCHAR	m_cRunSource;
				UCHAR	m_cClockSource;
				WORD	m_wWorkLen;

} CLAConfigStruct;


typedef struct ReadLAStruct{
              USHORT* m_pData;
			  WORD m_wCount;
              UCHAR m_cDataSource;	              
} CReadLAStruct;


typedef struct LGConfigStruct{
				BOOL	m_bSingleCycle;
				BOOL	m_bEndlessGenerator;
				UCHAR	m_cRunSource;
				UCHAR	m_cClockSource;
				WORD	m_wWorkLen;
} CLGConfigStruct;

typedef struct WriteLGStruct{
              ULONG* m_pData;
			  WORD m_wCount;
              UCHAR m_cDataDestination;	              
} CWriteLGStruct;


typedef struct CmnConfigStruct{
	UCHAR m_cExtMem0Source;
	UCHAR m_cExtMem1Source;
	UCHAR m_cIntMem0Source;
	UCHAR m_cIntMem1Source;
	BOOL m_bLD3_0Direction;
	BOOL m_bLD7_4Direction;
	BOOL m_bLD11_8Direction;
	BOOL m_bLD15_12Direction;
	WORD m_wInternalScale0;
	WORD m_wInternalScale1;
} CCmnConfigStruct;

typedef struct CmnControlStruct{
	BOOL m_bADC_StartSingleRead;
	BOOL m_bADC_SW_Stop;
	BOOL m_bADC_Run;
	BOOL m_bADC_Reset;
	BOOL m_bDAC_MemCntClear;
	BOOL m_bDAC_SW_Stop;
	BOOL m_bDAC_Run;
	BOOL m_bDAC_Reset;
	BOOL m_bLA_SW_Stop;
	BOOL m_bLA_Run;
	BOOL m_bLA_Reset;
	BOOL m_bLG_MemCntClear;
	BOOL m_bLG_SW_Stop;
	BOOL m_bLG_Run;
	BOOL m_bLG_Reset;
} CCmnControlStruct;

typedef struct CmnStatusStruct{
	BOOL m_bADC_DataReady;
	BOOL m_bADC_Mem1Full;
	BOOL m_bADC_Mem0Full;
	BOOL m_bDAC_Mem1Empty;
	BOOL m_bDAC_Mem0Empty;
	BOOL m_bLA_Mem1Full;
	BOOL m_bLA_Mem0Full;
	BOOL m_bLG_Mem1Empty;
	BOOL m_bLG_Mem0Empty;
}CCmnStatusStruct;

extern WORD m_wOldIntScale0;
extern WORD m_wOldIntScale1;
BOOL __stdcall Init(CDeviceID* pID);
BOOL __stdcall IOControl(DWORD dwIoControlCode, CDeviceID& DeviceID, void* pParameter);

#endif