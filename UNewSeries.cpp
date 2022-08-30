//---------------------------------------------------------------------------

#include <vcl.h>
#include "CConf.cpp"
#include "b381lib.h"
#pragma hdrstop

#include "UNewSeries.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RzButton"
#pragma resource "*.dfm"
extern CConf* PConf;
TNewSeries *NewSeries;
//---------------------------------------------------------------------------
__fastcall TNewSeries::TNewSeries(TComponent* Owner)
        : TForm(Owner)
{
}

 AnsiString __fastcall NP(int T) {
   return IntToStr((int)((double)T*10000/NewSeries->dt));
 }


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TNewSeries::EditEnter(TObject *Sender)
{
  OldText=((TEdit *)Sender)->Text;
}

//---------------------------------------------------------------------------
void __fastcall TNewSeries::EditExit(TObject *Sender)
{ int Tm;

  Tm=StrToTm(((TEdit *)Sender)->Text);
  if (Tm==0) {
    ((TEdit *)Sender)->Text=OldText;
    return;
  }
  ((TEdit *)Sender)->Text=TmToStr(Tm);


  if (Edit1==Sender) {Tu=Tm;  Edit5->Text=NP(Tm); }
  else if (Edit2==Sender) {To=Tm;  Edit6->Text=NP(Tm); }
  else if (Edit3==Sender) {Ts=Tm;  Edit7->Text=NP(Tm); }
  else {Tf=Tm;  Edit8->Text=NP(Tm); }

  Edit9->Text=NP(Ts+Tu+Tf);//IntToStr((int)((double)(tp+tu+tf)*10000/dt));

}
//---------------------------------------------------------------------------

void __fastcall TNewSeries::Edit9Exit(TObject *Sender)
{
  try {
    Np=StrToInt(Edit9->Text);
  }
  catch (EConvertError&) {
    Edit9->Text=OldText;
  }
  Np=StrToInt(Edit9->Text);

  dt=(double)(Ts+Tu+Tf)*10000/Np;

  Edit5->Text=NP(Tu);//IntToStr((int)((double)tu*10000/dt));
  Edit6->Text=NP(To);//IntToStr((int)((double)to*10000/dt));
  Edit7->Text=NP(Ts);//IntToStr((int)((double)tp*10000/dt));
  Edit8->Text=NP(Tf);//IntToStr((int)((double)tf*10000/dt));

}
//---------------------------------------------------------------------------

void __fastcall TNewSeries::FormCreate(TObject *Sender)
{

  Tu=(PConf->t*100);
  To=((PConf->T-PConf->t)*100);
  Ts=(PConf->tp*100);
  Tf=(PConf->tf*100);
  dt=PConf->dt*1e6;

  double N=(Ts+Tu+Tf)*10000/dt;
  Np=N;

  Gen=PConf->Gen0;
  GenMul=PConf->Gen0Mul;

}
//---------------------------------------------------------------------------

void __fastcall TNewSeries::FormShow(TObject *Sender)
{
  Edit1->Text=TmToStr(Tu);
  Edit2->Text=TmToStr(To);
  Edit3->Text=TmToStr(Ts);
  Edit4->Text=TmToStr(Tf);

  Edit5->Text=NP(Tu);//IntToStr((int)((double)tu*10000/dt));
  Edit6->Text=NP(To);//IntToStr((int)((double)to*10000/dt));
  Edit7->Text=NP(Ts);//IntToStr((int)((double)tp*10000/dt));
  Edit8->Text=NP(Tf);//IntToStr((int)((double)tf*10000/dt));

  Edit9->Text=IntToStr(Np);
}
//---------------------------------------------------------------------------


void __fastcall TNewSeries::FormHide(TObject *Sender)
{
  PConf->T=((double)(Tu+To))/100;
  PConf->t=((double)Tu)/100;
  PConf->tp=((double)Ts)/100;
  PConf->tu=((double)Tu)/100;
  PConf->tf=((double)Tf)/100;
  PConf->dt=dt/1e6;
  PConf->Gen0=dt/20;
  PConf->Gen1=Gen;//(dt/20);
  PConf->Gen0Mul=1;//(dt/20);

 /**/
}
//---------------------------------------------------------------------------


