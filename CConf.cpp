#if !defined __CCONF_CPP
#define __CCONF_CPP
#include <vcl.h>
#include <math.h>
#include "b181.h"
extern AnsiString WorkDir;

struct CConf {
  WORD Gen0;       // ������� ���������� 0
  WORD Gen1;       // ������� ���������� 1
   int Gen0Mul;       // �������� ������� ���������� 0
  WORD ADC_Clock;  // ��������� ���������� �� ���
  WORD DAC_Clock;  // ��������� ���������� �� ���
  BOOL ADCChanel[4];  // ��������� ������ ���
  double ADCCoeff[4]; // ������������ �������������� ����� �� ���
  char ADCValue[4][10];  // ������������ ������ ��������� ���
  double DACCoeff[4]; // ������������ �������������� ����� �� ���
  char DACValue[4][10];  // ������������ ������ ��������� ���
  BOOL DACChanel[4];  // ��������� ������ ���

  float ADCMin[2];
  float ADCMax[2];

  WORD ADCLen;
  WORD DACLen;

  UCHAR EMemSource0;  //
  UCHAR EMemSource1;  //
  UCHAR IMemSource0;  //
  UCHAR IMemSource1;  //

  int NPulse; // ����� ��������� �� ������
  float A;    // ��������� ������� ��������
  float dA;   // ��������� �������� ��������� ���������

  float dt; //  �������� ������� ����� ����� ���������
  float T;  //  ������ ��������� (to+tu)
  float t;  //  ������������ ��������
  float to; //
  float tu; //
  float tf; //
  float tp; //

  CConf();
  void SaveToFile();
  bool ReadFromFile();
  ~CConf(){
    SaveToFile();
  };

};

 void CConf::SaveToFile() {
   if (FileExists(WorkDir+"\\B381.cgf")) DeleteFile(WorkDir+"\\B381.cfg");
   int F;

   F=FileCreate(WorkDir+"\\B381.cfg");
   FileWrite(F,this,sizeof(CConf));
   FileClose(F);
 };

 bool CConf::ReadFromFile() {
   int F,k;

   F=FileOpen(WorkDir+"\\B381.cfg",fmOpenRead);
   if (F==-1) return false;
   k=FileRead(F,this,sizeof(CConf));
   FileClose(F);
   if (k!=sizeof(CConf)) return false;
   return true;
 };

 CConf::CConf() {
   if (!(FileExists(WorkDir+"\\B381.cfg")&&ReadFromFile())) {
     tp=5;
     tf=5;

     Gen0=500;
     Gen1=500;

     Gen0Mul=1;
     dt=double(Gen0*Gen0Mul)*20e-6;

     NPulse=1;
     T=20+40;
     t=20;
     A=5;
     dA=-0.5;
     dt=0.01;
     tf=5;
     tu=20;
     tp=5;
     to=40;

     ADC_Clock=ClockSrc_IntGen0;
     DAC_Clock=ClockSrc_IntGen0;

     ADCChanel[0]=true;
     ADCChanel[1]=true;
     ADCChanel[2]=false;
     ADCChanel[3]=false;

     DACChanel[0]=true;
     DACChanel[1]=false;
     DACChanel[2]=false;
     DACChanel[3]=false;

     ADCLen=1000;
     DACLen=1000;
     EMemSource0=MemSrc_ADC0;
     EMemSource1=MemSrc_DAC0;
     IMemSource0=MemSrc_ADC1;
     IMemSource1=MemSrc_DAC1;

     for(int i=0;i<4;i++) {
       ADCCoeff[i]=1;
       ADCValue[i][0]='�';
       ADCValue[i][1]=0;

       DACCoeff[i]=1;
       DACValue[i][0]='�';
       DACValue[i][1]=0;
     }
     ADCMax[0]=12*fabs(ADCCoeff[0]);
     ADCMin[0]=-12*fabs(ADCCoeff[0]);
     ADCMax[1]=12*fabs(ADCCoeff[1]);
     ADCMin[1]=-12*fabs(ADCCoeff[1]);
   }
 }
#endif
