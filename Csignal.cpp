#if !defined CsignalCPP
# define CsignalCPP

#include <fstream.h>
#include <stdio.h>
#include <iomanip.h>
#include "Main.h"

extern int SeriaNumber;


class CSeria {
public:
  AnsiString Name;
  AnsiString FName;
  int Ni;
  int Nt;
  float **Data;
  TFastLineSeries **Series;
  AnsiString **SrNames;
  float t0;
  float dt;
  int tu;
  int to;
  BOOL Modified;

  TChart* Chart;
  TChart* Chart1;
  TFastLineSeries* FastLineSeries;
  TFastLineSeries* FastLineSeries1;
  TCheckListBox* CheckListBox;

  int Counter;
  int Selected;
  TColor SelectedColor;
  TColor ColorI;
  TColor ColorV;

 public:
   CSeria(int Len,float Dt) {
     Name="";
     Ni=0;
     Nt=Len;
     Data=NULL;
     Series=NULL;
     dt=Dt;
     Selected=-1;
     SelectedColor=clFuchsia;
     Modified=false;
   }
  ~CSeria();
   void __fastcall Init(TChart* Ch,TChart* Ch1,TFastLineSeries* FLS,
       TFastLineSeries* FLS1,TCheckListBox* CLB) {
       Chart=Ch;
       Chart1=Ch1;
       FastLineSeries=FLS;
       FastLineSeries1=FLS1;
       CheckListBox=CLB;
       Counter=1;
       ColorI=FLS->SeriesColor;
       ColorV=FLS1->SeriesColor;
   }
   BOOL __fastcall Empty(){if (Ni==0) return true;
                                      return false;};
    int __fastcall Add(int N,float** Sr,AnsiString**);
    int __fastcall Delete(int Index);
   void __fastcall Clear();
//   void __fastcall Close(){};
 float* __fastcall operator [](int I);
    int __fastcall GetLen(){return Nt;}
   void __fastcall SetLen(int L){/*if(!Length)*/ Nt=L;}
   void __fastcall Refresh(int Index);
   void __fastcall RefreshN(int Index);
   void __fastcall Hide(int Index){if (Index<Ni) Series[Index]->Active=false;}
   void __fastcall Show(int Index){if (Index<Ni) Series[Index]->Active=true;}
   void __fastcall SetSelected(int Index) {
     CheckListBox->ItemIndex=Index;
     Index*=2;
     if (Index+1<Ni) {
       if (Selected!=-1) { Series[Selected]->SeriesColor=ColorI;
                           Series[Selected+1]->SeriesColor=ColorV;
                         }
       Selected=Index;
       Series[Selected]->SeriesColor=SelectedColor;
       Series[Selected+1]->SeriesColor=SelectedColor;
     };
   }
 BOOL __fastcall LoadFromBinFile(void);
// BOOL __fastcall LoadFromTxtFile(char *S);
 BOOL __fastcall SaveToBinFile(void);
// BOOL __fastcall SaveToTxtFile(char *S);
};

//------------------------ Деструктор -------------------------------------
 CSeria::~CSeria() {
   if (Ni>0) {
     for (int i=0;i<Ni;i++) {
       delete [] Data[i];
   //    Series[i]->ParentChart=NULL;
   //    delete Series[i];
     }
     for (int i=0;i<Ni/2;i++)
       delete SrNames[i];
     delete [] Data;
     delete [] Series;
     delete [] SrNames;
   }
 };


//--------------------  Добавление новых сигналов --------------------------
 int __fastcall CSeria::Add(int N,float** Sn,AnsiString** Names) {
   float** TmpData;
   TFastLineSeries** TmpSr;
   AnsiString** TmpSrNames;

   Modified=true;

   TmpData=new float* [N+Ni];
   TmpSr=new TFastLineSeries* [N+Ni];
   TmpSrNames=new AnsiString* [(N+Ni)/2];

   for(int i=0;i<Ni;i++) {
     TmpData[i]=Data[i];
     TmpSr[i]=Series[i];
   };
   for(int i=0;i<Ni/2;i++)
     TmpSrNames[i]=SrNames[i];

   for(int i=Ni;i<N+Ni;i++) {
     Counter++;
     TmpData[i]=Sn[i-Ni];
     TmpSr[i]=new TFastLineSeries(FastLineSeries);
     float t=t0;
     for(int j=0;j<Nt;j++) {
       TmpSr[i]->AddXY(t,TmpData[i][j],"",TmpSr[i]->SeriesColor);
       t+=dt;
     }
     if (i%2==0) {
       TmpSr[i]->ParentChart=Chart;
       TmpSr[i]->SeriesColor=ColorI;
     }
     else {
       TmpSr[i]->ParentChart=Chart1;
       TmpSr[i]->SeriesColor=ColorV;
     }

     if (i%2==0)
     {
       TmpSrNames[i/2]=Names[(i-Ni)/2];

       CheckListBox->Items->Add(*TmpSrNames[i/2]);//"Имп. "+IntToStr(V1)+ " "+Val+" : "+IntToStr(Counter/2));
       CheckListBox->Checked[i/2]=true;
      // V1+=dV;
     };
   };
   if (Ni){ delete [] Data;
            delete [] Series;
            delete [] SrNames;
            delete [] Names;}
   Data=TmpData;
   Series=TmpSr;
   SrNames=TmpSrNames;
   Ni+=N;
  return 0;
 };

//---------------- Удаление выбранного сигнала -----------------
 int __fastcall CSeria::Delete(int Index) {

  float** TmpData;
  TFastLineSeries** TmpSr;
  AnsiString** TmpSrNames;

   Index*=2;
   Modified=true;
   if (Selected==Index) Selected=-1;

   Series[Index]->ParentChart=NULL;
   Series[Index+1]->ParentChart=NULL;
   CheckListBox->Items->Delete(Index/2);

   delete Series[Index];
   delete [] Data[Index];
   delete Series[Index+1];
   delete [] Data[Index+1];
   delete SrNames[Index/2];

   TmpData=new float*[Ni-2];
   TmpSr=new TFastLineSeries*[Ni-2];
   TmpSrNames=new AnsiString*[Ni/2-1];
   for(int i=0;i<Index;i++) {
     TmpData[i]=Data[i];
     TmpSr[i]=Series[i];
   };
   for(int i=0;i<Index/2;i++) TmpSrNames[i]=SrNames[i];

   for(int i=Index+2;i<Ni;i++) {
     TmpData[i-2]=Data[i];
     TmpSr[i-2]=Series[i];
   };
   for(int i=Index/2+1;i<Ni/2;i++) TmpSrNames[i-1]=SrNames[i];

   Ni-=2;
   delete [] Data;
   delete [] Series;
   delete [] SrNames;
   Data=TmpData;
   Series=TmpSr;
   SrNames=TmpSrNames;
  return 0;
 };

//---------------------- Очистка данных серии ----------------------
void __fastcall CSeria::Clear() {
   if (Ni>0) {
     CheckListBox->Clear();
     for (int i=0;i<Ni;i++) {
       delete [] Data[i];
       Series[i]->ParentChart=NULL;
       Series[i]->Clear();
       delete Series[i];
     }
     delete [] Data;
     delete [] Series;
   }
   Ni=0;
   Nt=0;
   Counter=0;
   Selected=-1;
 };

 float* __fastcall CSeria::operator[](int I) {
   return Data[I];
 };


//--------------- Чтение из файла -----------------------------
BOOL __fastcall CSeria::LoadFromBinFile(){
  int F,N;
  AnsiString** Names;

  Clear();

  F=FileOpen(FName,fmOpenRead);
  if(F==-1) return false;

  FileRead(F,&N,sizeof(N));
  FileRead(F,&Nt,sizeof(Nt));
  FileRead(F,&t0,sizeof(t0));
  FileRead(F,&dt,sizeof(dt));
  FileRead(F,&tu,sizeof(tu));
  FileRead(F,&to,sizeof(to));
  int N1=N;
  N=abs(N);

  float **Tmp;
  Tmp=new float*[N];
  for(int i=0;i<N;i++) {
    Tmp[i]=new float[Nt];
    FileRead(F,Tmp[i],sizeof(float)*Nt);
  }


  Names=new AnsiString*[N/2];
  if (N1>0) for(int i=0;i<N/2;i++) {
    Names[i]=new AnsiString;
    *Names[i]=IntToStr(i+1);
  }
  else {
    int m;
    char* ch;
    for(int i=0;i<N/2;i++) {
      FileRead(F,&m,sizeof(int));
      ch=new char[m+1];
      ch[m]=0;
      FileRead(F,ch,sizeof(char)*m);
      Names[i]=new AnsiString;
      *Names[i]=ch;
      delete[] ch;
    };
    FileRead(F,&SeriaNumber,sizeof(int));
  };


  FileClose(F);

  Add(N,Tmp,Names);
  Modified=false;
  return true;
};

//---------------- запись в файл ------------------------------
BOOL __fastcall CSeria::SaveToBinFile() {
  if (!Modified) return true;

  int F;
  F=FileCreate(FName);
  if (F==-1) return false;

  int N1=-Ni;
  FileWrite(F,&N1,sizeof(N1));
  FileWrite(F,&Nt,sizeof(Nt));
  FileWrite(F,&t0,sizeof(t0));
  FileWrite(F,&dt,sizeof(dt));
  FileWrite(F,&tu,sizeof(tu));
  FileWrite(F,&to,sizeof(to));

  for(int i=0;i<Ni;i++)
    FileWrite(F,Data[i],sizeof(float)*Nt);

  int N;char* ch;
  for(int i=0;i<Ni/2;i++) {
    N=(*SrNames[i]).Length();
    FileWrite(F,&N,sizeof(N));
    ch=new char[N+1];
    StrCopy(ch,(*SrNames[i]).c_str());
    FileWrite(F,ch,sizeof(char)*N);
    delete[] ch;
  }

  FileWrite(F,&SeriaNumber,sizeof(int));

  FileClose(F);
  Modified=false;
  return true;
};
/*
//--------------- Чтение серий из текстового файла -----------------------------
BOOL __fastcall CSeria::LoadFromTxtFile(char *S) {
  int L=1,N=0;
  char ch2,ch1=' ';
  ifstream file(S);
  if (!file) return false;
  do {
    ch2=file.get();
    if( ((ch1==' ')||(ch1==9)) && ((ch2=='-')|| ((ch2>='0')&&(ch2<='9'))  ) ) N++;
    if(ch2==EOF) return false;
    ch1=ch2;
  }
  while (ch2!='\n');
  while (ch1!=EOF) {
    ch1=file.get();
    if (ch1=='\n') L++;
  }
  file.close();

  file.open(S);
  SetLen(L);
  float** tmp;
  float t1,t2=0;
  N--;
  tmp=new float*[N];
  for(int i=0;i<N;i++) tmp[i]=new float[L];

  for(int i=0;i<L;i++) {
      t1=t2;
      file>>t2;
    for(int j=0;j<N;j++)
      file>>tmp[j][i];
  }
  dt=t2-t1;
  Add(N,tmp,1,1,"");
  file.close();
  return true;
};*/

//------------------------- Сохранение в текстовый файл ---------------
/*BOOL __fastcall CSeria::SaveToTxtFile(char *S) {
  if (Data) {
  ofstream file(S);
  if (file) {
    float t=0;
    for(int i=0;i<Nt;i++) {
      file<<setw(10)<<t<<' ';
      t+=dt;
      for(int j=0;j<Ni-1;j++)
        file<<setw(10)<<Data[j][i]<<' ';
      file<<setw(10)<<Data[Ni-1][i]<<endl;
    }
    file.close();
    return true;
  }
  }
  return false;
}; */


//-------------------- Обновление данных серии ----------------------------
 void __fastcall CSeria::Refresh(int Index) {
   Index*=2;
   Series[Index]->ParentChart=NULL;
   Series[Index+1]->ParentChart=NULL;
   Series[Index]->ParentChart=Chart;
   Series[Index+1]->ParentChart=Chart1;

/*
   Series[Index]->Clear();
   Series[Index+1]->Clear();
   delete Series[Index];
   delete Series[Index+1];
   Series[Index]=new TFastLineSeries(FastLineSeries);
   Series[Index+1]=new TFastLineSeries(FastLineSeries);
   float t=0;
   for(int i=0;i<Nt;i++) {
     Series[Index]->AddXY(t,Data[Index][i],"",Series[Index]->SeriesColor);
     Series[Index+1]->AddXY(t,Data[Index+1][i],"",Series[Index+1]->SeriesColor);
     t+=dt;
   };  */
   Series[Index]->ParentChart=Chart;
   Series[Index+1]->ParentChart=Chart1;
 };

 void __fastcall CSeria::RefreshN(int Index) {
   Series[Index]->Clear();
   Series[Index+1]->Clear();
   float t=t0;
   for(int i=0;i<Nt;i++) {
     Series[Index]->AddXY(t,Data[Index][i],"",Series[Index]->SeriesColor);
     Series[Index+1]->AddXY(t,Data[Index+1][i],"",Series[Index+1]->SeriesColor);
     t+=dt;
   };  
 };

#endif
