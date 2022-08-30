//Управление устройством
#include <vcl.h>
//#include "unilptx.h"
#include "b181.h"
#include "CConf.cpp"
extern CConf *PConf;

// Функция из B181.DLL
typedef BOOL (*(__stdcall TIOControl(DWORD,CDeviceID&,void*)));

// Функции из UNILPTX.DLL
// Data access
/*
typedef void  (*(__stdcall TWriteToDevice(const CDeviceID&,char,CRegType,void*,int)));
typedef void* (*(__stdcall TReadFromDevice(const CDeviceID&,char,CRegType,void*,int)));
typedef void  (*(__stdcall TWriteToDeviceEx(const CDeviceID&,UCHAR,CRegType,void*,int)));
typedef void* (*(__stdcall TReadFromDeviceEx(const CDeviceID&,UCHAR,CRegType,void*,int)));

typedef void  (*(__stdcall TWriteToInterface( const CDeviceID&,UCHAR,UCHAR)));
typedef UCHAR (*(__stdcall TReadFromInterface(const CDeviceID&,UCHAR)));
*/
typedef BOOL  (*(__stdcall TReadFromEPROM(const CDeviceID&,int,int,void*)));
/*
typedef BOOL  (*(__stdcall TWriteToEPROM( const CDeviceID&,int,int,void*)));


//Interrupts

typedef void  (*(__stdcall TEnableInt(const CDeviceID&,int,bool))); //***
typedef DWORD (*(__stdcall   TWaitInt(const CDeviceID&,int,DWORD))); //***
typedef void  (*(__stdcall    TSetInt(const CDeviceID&,int,bool))); //***

// Configuring
typedef bool  (*(__stdcall TAlteraPLDProgramming(CDeviceID&,HMODULE,LPCTSTR)));

// Control
typedef CDeviceID* (*(__stdcall TLockDevice(CDeviceType)));
typedef bool       (*(__stdcall TUnLockDevice(CDeviceID&)));

// Debug

typedef bool (*(__stdcall IsLogging()));
typedef void (*(__stdcall StartLog(LPCTSTR)));
typedef void (*(__stdcall EndLog()));
typedef void (*(__stdcall AddToLog(LPCTSTR)));
*/


class CDevice {
            BOOL DevicePresent;
            BOOL DllPresent;
            BOOL DevicePrepared;
       CDeviceID DeviceID;
     TIOControl* IOCONTROL;
 TReadFromEPROM* ReadEPROM;
           ULONG MemExt0[0x10000];
           ULONG MemExt1[0x10000];
           ULONG MemInt0[512];
           ULONG MemInt1[512];
       HINSTANCE B181dll;
       HINSTANCE UNILPTXdll;
          double ADCCoeff[8];
           short DACCoeff[8];

   int LoadFromEPROM();
 public:
  CConf* Config;
  CDevice(){
  DevicePresent=DllPresent=DevicePrepared=false;
  Config=PConf;}
   int PrepareDevice();  //Обнаружение устройства
  void Reset(int k=3);
  void Run(int k=3);
  void Stop(int k=3);
  void ConfigCmn(int c=0);
  void ConfigADC(int c=0);
  void ConfigDAC(int c=0);
  void ReadFromADC(float ** SignalIn,int c=0);
  void WriteToDAC(float * SignalOut,int k=0);
  void WriteToDACDirect(float fValue);
  char ReadStatus();
  void CloseDevice();
};

//-------------  Получение информации из EPROM прибора ---------------------
 int CDevice::LoadFromEPROM() {
   UNILPTXdll=LoadLibrary("unilptx.dll");
   if (UNILPTXdll) {
     ReadEPROM=(TReadFromEPROM *)GetProcAddress(UNILPTXdll,"ReadFromEPROM");
     if (ReadEPROM==NULL) return 2;
     else
       if (ReadEPROM(DeviceID,4,64,ADCCoeff)) DevicePrepared=true;
       else return 1;
   }
   else return 3;
   ReadEPROM(DeviceID,70,16,DACCoeff);
   return 0;

 };

//-------------  Обнаружение устройства  -----------------------------------
 int CDevice::PrepareDevice() {          
   B181dll=LoadLibrary("b181.dll");
   if (B181dll) {
     DllPresent=true;
     IOCONTROL=(TIOControl *)GetProcAddress(B181dll,"IOControl");
     if (IOCONTROL==NULL) return -2;
     else
       if (IOCONTROL(IOCTRL_Initialize,DeviceID,0)) DevicePresent=true;
       else return -1;
   }
   else return -3;


   return LoadFromEPROM();
 };


//-------------  Деинициализация устройства  -----------------------------------
 void CDevice::CloseDevice() {
   if (DevicePresent) {
     IOCONTROL(IOCTRL_Deinitialize,DeviceID,0);
     DevicePresent=false;
     IOCONTROL=NULL;
   };
   if (DllPresent) FreeLibrary(B181dll);
   DllPresent=false;
 };



 //--------------------- Общая конфигурация ---------------------------------------
void CDevice::ConfigCmn(int c) {
 CmnConfigStruct cc;
  if (c) {
   cc.m_cExtMem0Source=MemSrc_ADC0;
   cc.m_cExtMem1Source=MemSrc_ADC1;
   cc.m_cIntMem0Source=MemSrc_DAC0;
   cc.m_cIntMem1Source=MemSrc_DAC1;
  }
  else {
   cc.m_cExtMem0Source=MemSrc_ADC0;
   cc.m_cExtMem1Source=MemSrc_DAC0;
   cc.m_cIntMem0Source=MemSrc_ADC1;
   cc.m_cIntMem1Source=MemSrc_DAC1;
  }
/*
  cc.m_bLD3_0Direction=true;
  cc.m_bLD7_4Direction=true;
  cc.m_bLD11_8Direction=true;
  cc.m_bLD15_12Direction=true;
*/
  cc.m_wInternalScale0=Config->Gen0;
  cc.m_wInternalScale1=Config->Gen1;
 IOCONTROL(IOCTRL_CmnConfig,DeviceID,&cc);
};



 //--------------------- Конфигурация АЦП ---------------------------------------
void CDevice::ConfigADC(int k) {
 ADCConfigStruct ca;
  if (k) ca.m_bRecorder=true;
  else   ca.m_bRecorder=false;
  ca.m_cChannels=0;
  unsigned char c=1;
  for(int i=0;i<4;i++) {
    if (Config->ADCChanel[i]) ca.m_cChannels+=c;
    c=c<<1;
  }
  ca.m_cRunSource=RunSrc_SW;
  ca.m_cClockSource=ClockSrc_IntGen0;
  ca.m_wWorkLen=Config->ADCLen;
 IOCONTROL(IOCTRL_ADCConfig,DeviceID,&ca);
};



 //--------------------- Конфигурация ЦАП ---------------------------------------
void CDevice::ConfigDAC(int k)
{
 DACConfigStruct cd;
 cd.m_bEndlessGenerator=false; //true
 if (k) cd.m_bSingleCycle=false;
 else   cd.m_bSingleCycle=true;
  cd.m_cChannels=0;
  unsigned char c=1;
  for(int i=0;i<4;i++) {
    if (Config->DACChanel[i]) cd.m_cChannels+=c;
    c=c<<1;
  }
  cd.m_cRunSource=RunSrc_SW;
  cd.m_cClockSource=ClockSrc_IntGen0;
  cd.m_wWorkLen=Config->DACLen;
 IOCONTROL(IOCTRL_DACConfig,DeviceID,&cd);
};



//--------------------- Состояние устройства ---------------------------------
char CDevice::ReadStatus() {
 CmnStatusStruct cs;

 char c=0;
 IOCONTROL(IOCTRL_CmnReadStatus,DeviceID,&cs);

  if (cs.m_bADC_DataReady) c+=1;
  if (cs.m_bADC_Mem1Full)  c+=2;
  if (cs.m_bADC_Mem0Full)  c+=4;
  if (cs.m_bDAC_Mem1Empty) c+=8;
  if (cs.m_bDAC_Mem0Empty) c+=16;
 return c;
};



//----------------- Чтение из АЦП ----------------------------------------
void CDevice::ReadFromADC(float **SignalIn,int c) {
  int m=0;
  for(int i=0;i<4;i++)
    if(Config->ADCChanel[i]) m++;
 ReadADCStruct ra;
  ra.m_pData=(unsigned short*)MemExt0;
  if (c) ra.m_cDataSource=DtSrc_Mem1;
  else   ra.m_cDataSource=DtSrc_Mem0;
  ra.m_wCount=Config->ADCLen*m;
 IOCONTROL(IOCTRL_ADCReadData,DeviceID,&ra);

  short tmp;

  int j=0;
  for(int i=0;i<PConf->ADCLen;i++)
    for(int k=0;k<m;k++) {
      tmp=((short*)MemExt0)[j];
      if (tmp&0x2000) tmp=tmp|0xC000;
      SignalIn[k][i]=(tmp-ADCCoeff[k*2])*ADCCoeff[k*2+1]*Config->ADCCoeff[k];
      j++;
    }
};



//------------------ Запись в ЦАП ------------------------------------------
void CDevice::WriteToDAC(float * SignalOut,int k) {
 WriteDACCStruct wd;
 if (k) wd.m_cDataDestination=DtSrc_Mem1;
 else   wd.m_cDataDestination=DtSrc_Mem0;
  wd.m_pData=MemExt1;
  wd.m_wCount=Config->DACLen;
  wd.m_cChannel=1;
  wd.m_bLDAC_=true;
  for(int i=0;i<Config->DACLen;i++) {
    MemExt1[i]=DACCoeff[1]+(SignalOut[i]+10.0)*(DACCoeff[0]-DACCoeff[1])/20;
  }
 IOCONTROL(IOCTRL_DACWriteData,DeviceID,&wd);
}

void CDevice::WriteToDACDirect(float fValue) {
	ULONG dwCode = DACCoeff[1]+(fValue+10.0)*(DACCoeff[0]-DACCoeff[1])/20;
	WriteDACCStruct wd;
	wd.m_cDataDestination = DtSrc_DirectChannels;
	wd.m_pData = &dwCode;
	wd.m_cChannel = 0; // 0-Ch1, 1-Ch2, 2-Ch3, 3-Ch4
	wd.m_bLDAC_ = FALSE; // FALSE to load
	IOCONTROL(IOCTRL_DACWriteData, DeviceID, &wd);
}

//--------------------- Сброс устройства -----------------------------------
void CDevice::Reset(int k){
 CmnControlStruct cc;
  cc.m_bADC_StartSingleRead=false;
  cc.m_bADC_SW_Stop=false;
  cc.m_bADC_Run=false;
  cc.m_bADC_Reset=false;
  cc.m_bDAC_MemCntClear=false;
  cc.m_bDAC_SW_Stop=false;
  cc.m_bDAC_Run=false;
  cc.m_bDAC_Reset=false;
  cc.m_bLA_SW_Stop=false;
  cc.m_bLA_Run=false;
  cc.m_bLA_Reset=false;
  cc.m_bLG_MemCntClear=false;
  cc.m_bLG_SW_Stop=false;
  cc.m_bLG_Run=false;
  cc.m_bLG_Reset=false;

  if (k&1) cc.m_bADC_Reset=true;
  if (k&2) cc.m_bDAC_Reset=true;
 IOCONTROL(IOCTRL_CmnControl,DeviceID,&cc);
}



//------------------------ Запуск устройства --------------------------------
void CDevice::Run(int k){
 CmnControlStruct cc;
  cc.m_bADC_StartSingleRead=false;
  cc.m_bADC_SW_Stop=false;
  cc.m_bADC_Run=false;
  cc.m_bADC_Reset=false;
  cc.m_bDAC_MemCntClear=false;
  cc.m_bDAC_SW_Stop=false;
  cc.m_bDAC_Run=false;
  cc.m_bDAC_Reset=false;
  cc.m_bLA_SW_Stop=false;
  cc.m_bLA_Run=false;
  cc.m_bLA_Reset=false;
  cc.m_bLG_MemCntClear=false;
  cc.m_bLG_SW_Stop=false;
  cc.m_bLG_Run=false;
  cc.m_bLG_Reset=false;

  if (k&1) cc.m_bADC_Run=true;
  if (k&2) cc.m_bDAC_Run=true;
 IOCONTROL(IOCTRL_CmnControl,DeviceID,&cc);
}



//------------------------ Програмный останов ------------------------------
void CDevice::Stop(int k){
 CmnControlStruct cc;
  cc.m_bADC_StartSingleRead=false;
  cc.m_bADC_SW_Stop=false;
  cc.m_bADC_Run=false;
  cc.m_bADC_Reset=false;
  cc.m_bDAC_MemCntClear=false;
  cc.m_bDAC_SW_Stop=false;
  cc.m_bDAC_Run=false;
  cc.m_bDAC_Reset=false;
  cc.m_bLA_SW_Stop=false;
  cc.m_bLA_Run=false;
  cc.m_bLA_Reset=false;
  cc.m_bLG_MemCntClear=false;
  cc.m_bLG_SW_Stop=false;
  cc.m_bLG_Run=false;
  cc.m_bLG_Reset=false;

  if (k&1) cc.m_bADC_SW_Stop=true;
  if (k&2) cc.m_bDAC_SW_Stop=true;
 IOCONTROL(IOCTRL_CmnControl,DeviceID,&cc);
}
