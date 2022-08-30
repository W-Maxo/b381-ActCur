//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Recorder.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

CRecData::CRecData() {
  k1=0.05;
  k2=600;
  k3=1;
  Head=NULL;
  Tail=NULL;
  P=NULL;
  LHead=NULL;
  LTail=NULL;
  LP=NULL;
  N=0;
  Nl=0;
  NlStck=0;
  Loaded=false;
  Stopped=true;
  kStack=1024;
  RName="recorder.bn";
}

CRecData::~CRecData() {
  while(Head) {
    P=Head;
    delete[] P->ID;
    delete[] P->VD;
    delete[] P->TD;
    Head=P->Next;
    delete P;
  };

  while(LHead) {
    LP=LHead;
    LHead=LP->Next;
    delete LP;
  };

}

void __fastcall CRecData::Init(TChart* ChI, TChart* ChV,TFastLineSeries* srI,
   TFastLineSeries* srV, TScrollBar* SB, TScrollBar* SBI, TScrollBar* SBU, TPanel* Pnl,TSplitter* Spl) {
  ChartI=ChI;
  ChartV=ChV;
  SrI=srI;
  SrV=srV;
  Scroll=SB;
  ScrollI=SBI;
  ScrollU=SBU;
  Scroll->Visible=false;
  Panel=Pnl;
  Panel->Visible=false;
  Splitter=Spl;
  Splitter->Visible=false;
};

void __fastcall CRecData::AddPoint(float I,float V,double t) {
//  static float k1=0.05;
//  static float k2=300;
//  static float k3=1;

  if (Loaded || Stopped) return;
  //Создание нового элемента стека
  if (Nl==NlStck) {

    P=new RStack;
    P->ID=new float[kStack];
    P->VD=new float[kStack];
    P->TD=new float[kStack];
    P->Next=NULL;

    if (Tail) Tail->Next=P;
    else Head=P;
    Tail=P;

    Nl=0;
    NlStck=kStack;
  }


  if (N==0) {
    T0=t;
    MaxI=MinI=I;
    MaxV=MinV=V;
    ChartI->BottomAxis->Minimum=0;
    ChartI->BottomAxis->Maximum=k2;
    ChartV->BottomAxis->Minimum=0;
    ChartV->BottomAxis->Maximum=k2;

    if (I<ChartI->LeftAxis->Maximum) {
      ChartI->LeftAxis->Minimum=I;
      ChartI->LeftAxis->Maximum=I;
    }
    else {
      ChartI->LeftAxis->Maximum=I;
      ChartI->LeftAxis->Minimum=I;
    };
    if (V<ChartV->LeftAxis->Maximum) {
      ChartV->LeftAxis->Minimum=V;
      ChartV->LeftAxis->Maximum=V;
    }
    else {
      ChartV->LeftAxis->Maximum=V;
      ChartV->LeftAxis->Minimum=V;
    };
  }

  if (I>MaxI) {
    MaxI=I;
    ChartI->LeftAxis->Maximum=MaxI+(MaxI-MinI)*k1;
    ChartI->LeftAxis->Minimum=MinI-(MaxI-MinI)*k1;
    ksI=(MaxI-MinI)/ScrollI->Max;
    ScrollI->Position=0;
    ScrollI->PageSize=ScrollI->Max;
  } else if (I<MinI) {
    MinI=I;
    ChartI->LeftAxis->Maximum=MaxI+(MaxI-MinI)*k1;
    ChartI->LeftAxis->Minimum=MinI-(MaxI-MinI)*k1;
    ksI=(MaxI-MinI)/ScrollI->Max;
    ScrollI->Position=0;
    ScrollI->PageSize=ScrollI->Max;
  };

  if (V>MaxV) {
    MaxV=V;
    ChartV->LeftAxis->Maximum=MaxV+(MaxV-MinV)*k1;
    ChartV->LeftAxis->Minimum=MinV-(MaxV-MinV)*k1;
    ksU=(MaxV-MinV)/ScrollU->Max;
    ScrollU->Position=0;
    ScrollU->PageSize=ScrollU->Max;
  } else if (V<MinV) {
    MinV=V;
    ChartV->LeftAxis->Maximum=MaxV+(MaxV-MinV)*k1;
    ChartV->LeftAxis->Minimum=MinV-(MaxV-MinV)*k1;
    ksU=(MaxV-MinV)/ScrollU->Max;
    ScrollU->Position=0;
    ScrollU->PageSize=ScrollU->Max;
  };

  t=(t-T0)*24*60*60;

  if (t>(k2-k3)) {
    ChartI->BottomAxis->Maximum=t+k3;
    ChartI->BottomAxis->Minimum=t+k3-k2;
    ChartV->BottomAxis->Maximum=t+k3;
    ChartV->BottomAxis->Minimum=t+k3-k2;
  }

  Tail->ID[Nl]=I;
  Tail->VD[Nl]=V;
  Tail->TD[Nl]=t;

  SrI->AddXY(t,I,"",SrI->SeriesColor);
  SrV->AddXY(t,V,"",SrV->SeriesColor);
  Nl++;
  N++;
};




//--------------------------------------------------------
void __fastcall CRecData::RSave() {

  if ((!N)||(Loaded)) return;

  int F;
  F=FileCreate(RName);
  FileWrite(F,&N,sizeof(N));

// Запись значений тока
  int TmpN=N;
  P=Head;
  while (TmpN-kStack>0) {
    FileWrite(F,P->ID,kStack*sizeof(float));
    P=P->Next;
    TmpN-=kStack;
  };
  FileWrite(F,Tail->ID,TmpN*sizeof(float));
// Запись значений напряжения
  TmpN=N;
  P=Head;
  while (TmpN-kStack>0) {
    FileWrite(F,P->VD,kStack*sizeof(float));
    P=P->Next;
    TmpN-=kStack;
  };
  FileWrite(F,Tail->VD,TmpN*sizeof(float));
// Запись значений времении
  TmpN=N;
  P=Head;
  while (TmpN-kStack>0) {
    FileWrite(F,P->TD,kStack*sizeof(float));
    P=P->Next;
    TmpN-=kStack;
  };
  FileWrite(F,Tail->TD,TmpN*sizeof(float));

  LP=LHead;
  while (LP) {
    FileWrite(F,&LP->T,sizeof(float));
    FileWrite(F,&LP->SN,sizeof(int));
    LP=LP->Next;
  }

  FileClose(F);

  Loaded=true;
  Stopped=true;
};


void __fastcall CRecData::Clear() {
  while(Head) {
    P=Head;
    delete[] P->ID;
    delete[] P->VD;
    delete[] P->TD;
    Head=P->Next;
    delete P;
  };
  Head=NULL;
  Tail=NULL;
  P=NULL;

  while(LHead) {
    LP=LHead;
    LHead=LP->Next;
    delete LP;
  };
  LHead=NULL;
  LTail=NULL;
  LP=NULL;

  N=0;
  Nl=0;
  NlStck=0;
  Loaded=false;
  Stopped=true;
  kStack=1024;
  SrI->Clear();
  SrV->Clear();
  Scroll->Visible=false;
};



void __fastcall CRecData::RLoad() {
  int F;
  Clear();
  Loaded=true;
  F=FileOpen(RName,fmOpenRead);
  if (F<=0) {
    Panel->Visible=false;
    Splitter->Visible=false;
    return;
  };

  FileRead(F,&N,sizeof(N));
  Nl=N;
  NlStck=N;
  kStack=N;

  Head=new RStack;
  Head->ID=new float[N];
  Head->VD=new float[N];
  Head->TD=new float[N];
  Head->Next=NULL;

  P=Tail=Head;

  FileRead(F,P->ID,N*sizeof(float));
  FileRead(F,P->VD,N*sizeof(float));
  FileRead(F,P->TD,N*sizeof(float));

  float Tm;
  int sn;
  while (FileRead(F,&Tm,sizeof(float))) {
    LP=new RLine;
    LP->T=Tm;
    FileRead(F,&sn,sizeof(int));
    LP->SN=sn;
    LP->Next=NULL;
    if (LTail) {
      LTail->Next=LP;
    }
    else
      LHead=LP;
    LTail=LP;
  };

  FileClose(F);

  MinI=MaxI=P->ID[0];
  MinV=MaxV=P->VD[0];

  for(int i=0;i<N;i++) {
    SrI->AddXY(P->TD[i],P->ID[i],"",SrI->SeriesColor);
    SrV->AddXY(P->TD[i],P->VD[i],"",SrV->SeriesColor);

    if (MinI>P->ID[i]) MinI=P->ID[i];
    else if (MaxI<P->ID[i]) MaxI=P->ID[i];

    if (MinV>P->VD[i]) MinV=P->VD[i];
    else if (MaxV<P->VD[i]) MaxV=P->VD[i];
  }

  ChartI->LeftAxis->Maximum=MaxI+(MaxI-MinI)*k1;
  ChartI->LeftAxis->Minimum=MinI-(MaxI-MinI)*k1;

  ChartV->LeftAxis->Maximum=MaxV+(MaxV-MinV)*k1;
  ChartV->LeftAxis->Minimum=MinV-(MaxV-MinV)*k1;

  ChartI->BottomAxis->Minimum=-1;
  ChartI->BottomAxis->Maximum=k2-1;
  ChartV->BottomAxis->Minimum=-1;
  ChartV->BottomAxis->Maximum=k2-1;

  Panel->Visible=true;
  Splitter->Visible=true;

  if (P->TD[N-1]<=k2) return;
  Scroll->Position=0;
  Scroll->Min=0;
  Scroll->Max=P->TD[N-1]+2;
  Scroll->PageSize=k2;
  Scroll->Visible=true;
}

void __fastcall CRecData::Run() {
  Panel->Visible=true;
  Splitter->Visible=true;
  Stopped=false;
}

void __fastcall CRecData::RScroll() {
  if (Scroll->Position-1>=ChartI->BottomAxis->Maximum) {
    ChartI->BottomAxis->Maximum=Scroll->Position+k2;
    ChartI->BottomAxis->Minimum=Scroll->Position-1;
    ChartV->BottomAxis->Maximum=Scroll->Position+k2;
    ChartV->BottomAxis->Minimum=Scroll->Position-1;
  }
  else {
    ChartI->BottomAxis->Minimum=Scroll->Position-1;
    ChartI->BottomAxis->Maximum=Scroll->Position+k2;
    ChartV->BottomAxis->Minimum=Scroll->Position-1;
    ChartV->BottomAxis->Maximum=Scroll->Position+k2;
  }
};

void __fastcall CRecData::AddLine(double t) {
  LP=new RLine;
  LP->T=(t-T0)*24*60*60;
  LP->SN=SeriaNumber;
  LP->Next=NULL;
  if (LTail)
    LTail->Next=LP;
  else
    LHead=LP;
  LTail=LP;
};

void __fastcall CRecData::ShowLines(TChart* Ch) {
  int k=6;
  int x;
  double a1=Ch->Width*Ch->MarginLeft*0.01+Ch->LeftAxis->LabelsSize+k;
  double a2=Ch->Width*Ch->MarginRight*0.01;
  double lx=Ch->Width-a1-a2;

  LP=LHead;
  while (LP) {
    if ((Ch->BottomAxis->Minimum<LP->T)&&(Ch->BottomAxis->Maximum>LP->T)) {
      x=a1+lx*(LP->T-Ch->BottomAxis->Minimum)/(Ch->BottomAxis->Maximum-Ch->BottomAxis->Minimum);
      if (SeriaNumber==LP->SN) Ch->Canvas->Pen->Color=clFuchsia;
      else Ch->Canvas->Pen->Color=clAqua;
      Ch->Canvas->MoveTo(x,0);
      Ch->Canvas->LineTo(x,Ch->Height);
    }
    LP=LP->Next;
  };
};


bool __fastcall CRecData::SendToClipboard(int t1,int t2,int nt,bool f0,bool i,bool v){
  if ((t1==-1)||(t2==-1)||(nt==-1)||(!(i||v))) return false;

    double dt=t2-t1;
    if (dt<0) return false;

    double t;
    t=t1;
    if (nt==0) nt=1;
    dt/=nt;

    double c=0;
    if (f0) c=t;

    AnsiString Txt="T,сек";
    if (i) {
      Txt+="\x09";
      Txt+="I,мкА";
    };
    if (v) {
      Txt+="\x09";
      Txt+="V,мВ";
    };
    Txt+="\n";

    bool key=true;
    P=Head;
    while(P) {
      for(int j=0;j<kStack;j++)
        if (P->TD[j]>=t) {
          key=false;
          Txt+=FloatToStrF(P->TD[j]-c,ffFixed,6,2);
          if (i) Txt+="\x09"+FloatToStrF(P->ID[j],ffFixed,6,4);
          if (v) Txt+="\x09"+FloatToStrF(P->VD[j],ffFixed,6,1);
          Txt+="\n";
          while (t<=P->TD[j])t+=dt;
          if (t>t2) break;
        }
      if (t>t2) break;
      P=P->Next;
    };
    Clipboard()->Clear();
    //if (key) Clipboard()->SetTextBuf("Нет данных из этого диапазона");
    //else Clipboard()->SetTextBuf(Txt.c_str());

  return true;
};


void __fastcall CRecData::RScrollI() {
  double I1,I2;
/*
  I1=MinI+ksI*ScrollI->Position;
  I2=MinI+ksI*(ScrollI->Position+ScrollI->PageSize);

  if (I1>=ChartI->LeftAxis->Maximum) {
    ChartI->LeftAxis->Maximum=I2;
    ChartI->LeftAxis->Minimum=I1;
  }
  else {
    ChartI->LeftAxis->Minimum=I1;
    ChartI->LeftAxis->Maximum=I2;
  }*/
};

void __fastcall CRecData::ZoomInI() {
/* int i=0;
  i=i;
  ScrollI->Position+=ScrollI->PageSize/3;
  ScrollI->PageSize=double(ScrollI->PageSize)/3.0*2.0;
  RScrollI();  */
};

void __fastcall CRecData::ZoomOutI() {
/*  ScrollI->Position+=3.0/4.0*ScrollI->PageSize;
  ScrollI->PageSize*=3.0/2.0;
  RScrollI(); */
};

