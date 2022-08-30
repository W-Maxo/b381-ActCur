
#ifndef __UNILPTX_H__
#define __UNILPTX_H__ 1

// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the UNILPTX_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// UNILPTX_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.

#ifdef UNILPTX_EXPORTS
#define UNILPTX_API __declspec(dllexport)
#else
#define UNILPTX_API __declspec(dllimport)
#endif

#define UNILPTX_CALL __stdcall

// This class is exported from the UniLPTX.dll

#include "DevTypes.h"

namespace UNILPTDrv
{
// Exceptions
        const int ELPTInit = 0xf000;
        const int EResourceFindFailed = 0xf001;
        const int EResourceLoadFailed = 0xf002;
        const int EResourceLockFailed = 0xf003;
        const int EPLDProgError = 0xf004;
//Const
        const int       SlotsCount = 4;
        const int       ConfigReg  = 7; //  XXXX XWWW
        const int       StatusReg  = 7; //  0000 RRRR
        const int       FlagsReg   = 6; // RRRR <RW>
        const int       NConfig = 4;
        const int       DCLK = 2;
        const int       Data0 = 1;

        const LPCTSTR lpAlteraResourceType = "AlteraPLDData";

// Data access
void UNILPTX_CALL WriteToDevice(const CDeviceID& DeviceID, char nInternalAddr, CRegType RegType, void* pData, int nCount);
void* UNILPTX_CALL ReadFromDevice(const CDeviceID& DeviceID, char nInternalAddr, CRegType RegType, void* pData, int nCount);
void UNILPTX_CALL WriteToDeviceEx(const CDeviceID& DeviceID, UCHAR nInternalAddr, CRegType RegType, void* pData, int nCount);
void* UNILPTX_CALL ReadFromDeviceEx(const CDeviceID& DeviceID, UCHAR nInternalAddr, CRegType RegType, void* pData, int nCount);

void UNILPTX_CALL WriteToInterface(const CDeviceID& DeviceID, UCHAR nInterfaceReg, UCHAR nRegData);
UCHAR UNILPTX_CALL ReadFromInterface(const CDeviceID& DeviceID, UCHAR nInterfaceReg);
BOOL UNILPTX_CALL ReadFromEPROM(const CDeviceID& DeviceID, int nStartAddr, int nCount, void* pData);
BOOL UNILPTX_CALL WriteToEPROM(const CDeviceID& DeviceID, int nStartAddr, int nCount, void* pData);

//Interrupts

void UNILPTX_CALL EnableInt(const CDeviceID& DeviceID, int nIntID, bool bEnable); //***
DWORD UNILPTX_CALL WaitInt(const CDeviceID& DeviceID, int nIntID, DWORD nTimeOut); //***
void UNILPTX_CALL SetInt(const CDeviceID& DeviceID, int nIntID, bool bSignaled); //***

// Configuring
bool UNILPTX_CALL AlteraPLDProgramming(CDeviceID& DeviceID,  HMODULE hModule, LPCTSTR lpResName);

// Control
CDeviceID* UNILPTX_CALL LockDevice(CDeviceType DeviceType);
bool UNILPTX_CALL UnLockDevice(CDeviceID& DeviceID);

// Debug

bool UNILPTX_CALL IsLogging();
void UNILPTX_CALL StartLog(LPCTSTR filename);
void UNILPTX_CALL EndLog();
void UNILPTX_CALL AddToLog(LPCTSTR lpStr);

}
#endif