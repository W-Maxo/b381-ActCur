//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "b181.h"
#include "UOptions.h"
#include "CConf.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TComboBox *ComboBox[4];
TFOptions *FOptions;
WORD G0,G1;
WORD N;
double A,dA,T,t;
AnsiString OldText;
extern  CConf* PConf=NULL;
double Coeff[4],DACCoeff[4];
AnsiString Value[4],DACValue[4];
float Min1,Max1,Min2,Max2;

//---------------------------------------------------------------------------
__fastcall TFOptions::TFOptions(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TFOptions::FormHide(TObject *Sender)
{
/*
if(ModalResult==mrOk) {
  N=StrToInt(Edit2->Text);
  PConf->Gen0=G0*50;
  PConf->Gen1=G1*50;
  PConf->dt=0.001;
  if (ComboBox1->ItemIndex==0) {
                                 PConf->ADC_Clock=ClockSrc_IntGen0;
                                 PConf->dt*=G0;
                               }
                         else  {
                                 PConf->ADC_Clock=ClockSrc_IntGen1;
                                 PConf->dt*=G1;
                               }
  if (ComboBox2->ItemIndex==0) PConf->DAC_Clock=ClockSrc_IntGen0;
                         else  PConf->DAC_Clock=ClockSrc_IntGen1;

  PConf->ADCChanel[0]=i0CheckBox->Checked;
  PConf->ADCChanel[1]=i1CheckBox->Checked;
  PConf->ADCChanel[2]=i2CheckBox->Checked;
  PConf->ADCChanel[3]=i3CheckBox->Checked;

  PConf->DACChanel[0]=o0CheckBox->Checked;
  PConf->DACChanel[1]=o1CheckBox->Checked;
  PConf->DACChanel[2]=o2CheckBox->Checked;
  PConf->DACChanel[3]=o3CheckBox->Checked;

  double tmp=T*N*1000;
  if (ComboBox1->ItemIndex==0) tmp/=G0;
                         else  tmp/=G1;
  PConf->ADCLen=tmp;

  tmp=T*N*1000;
  if (ComboBox2->ItemIndex==0) tmp/=G0;
                         else  tmp/=G1;

  PConf->DACLen=tmp;

  switch (ComboBox3->ItemIndex) {
    case 0: PConf->IMemSource0=MemSrc_ADC0; break;
    case 1: PConf->IMemSource1=MemSrc_ADC0; break;
    case 2: PConf->EMemSource0=MemSrc_ADC0; break;
    case 3: PConf->EMemSource1=MemSrc_ADC0; break;
  }

  switch (ComboBox4->ItemIndex) {
    case 0: PConf->IMemSource0=MemSrc_ADC1; break;
    case 1: PConf->IMemSource1=MemSrc_ADC1; break;
    case 2: PConf->EMemSource0=MemSrc_ADC1; break;
    case 3: PConf->EMemSource1=MemSrc_ADC1; break;
  }

  switch (ComboBox5->ItemIndex) {
    case 0: PConf->IMemSource0=MemSrc_DAC0; break;
    case 1: PConf->IMemSource1=MemSrc_DAC0; break;
    case 2: PConf->EMemSource0=MemSrc_DAC0; break;
    case 3: PConf->EMemSource1=MemSrc_DAC0; break;
  }

  switch (ComboBox6->ItemIndex) {
    case 0: PConf->IMemSource0=MemSrc_DAC1; break;
    case 1: PConf->IMemSource1=MemSrc_DAC1; break;
    case 2: PConf->EMemSource0=MemSrc_DAC1; break;
    case 3: PConf->EMemSource1=MemSrc_DAC1; break;
  }

  PConf->NPulse=StrToInt(Edit2->Text);
  PConf->A=A;
  PConf->dA=dA;
  PConf->T=T;
  PConf->t=t;
*/
  for(int i=0;i<4;i++) {
    PConf->ADCCoeff[i]=Coeff[i];
    StrCopy(PConf->ADCValue[i],Value[i].c_str());
    PConf->DACCoeff[i]=DACCoeff[i];
    StrCopy(PConf->DACValue[i],DACValue[i].c_str());
  }

  PConf->ADCMin[0]=Min1;
  PConf->ADCMax[0]=Max1;
  PConf->ADCMin[1]=Min2;
  PConf->ADCMax[1]=Max2;

  /*
  PConf->SaveToFile();

} */
}
//---------------------------------------------------------------------------

void __fastcall TFOptions::FormCreate(TObject *Sender)
{
/* ComboBox[0]=ComboBox3;
 ComboBox[1]=ComboBox4;
 ComboBox[2]=ComboBox5;
 ComboBox[3]=ComboBox6;
*/// ComboBox1->ItemIndex=0;
// ComboBox3->ItemIndex=2;
// ComboBox4->ItemIndex=0;
// ComboBox2->ItemIndex=0;
// ComboBox5->ItemIndex=3;
// ComboBox6->ItemIndex=1;
// ComboBox7->ItemIndex=0;
//
}
//---------------------------------------------------------------------------


;/*
{ int l=-1;
  BOOL k;
  for(int i=0;i<4;i++) {
    k=false;
    for (int j=0;j<4;j++)
      if (ComboBox[j]->ItemIndex==i) {
        k=true;
        break;
      }
    if(k) continue;
    l=i;
    break;
  }
  for(int i=0;i<4;i++)
    if((ComboBox[i]!=Sender)&&(ComboBox[i]->ItemIndex==((TComboBox *)Sender)->ItemIndex))
      ComboBox[i]->ItemIndex=l;
}
//---------------------------------------------------------------------------

void __fastcall TFOptions::Edit67Exit(TObject *Sender)
{
  AnsiString S=((TEdit *)Sender)->Text;
  int c=S.AnsiPos("мкс");
  int LenS=S.Length();
  if(c) S.Delete(c,LenS-c+1);
  do {
    c=S.Pos(" ");
    if(!c) break;
    S.Delete(c,1);
  }while(true);

  ((TEdit *)Sender)->Text=(S+" мкс");

  int Number;
  BOOL k=false;
  try
  {
    Number=StrToInt(S);
  }
  catch(EConvertError&)
  {
    ((TEdit *)Sender)->Text=OldText;
    k=true;
  }
  if (!k) {
    if(Sender==Edit6)G0=Number;
    else G1=Number;
  }
}*/
//---------------------------------------------------------------------------

void __fastcall TFOptions::EditEnter(TObject *Sender)
{
  OldText=((TEdit *)Sender)->Text;
}
//---------------------------------------------------------------------------



/*
  AnsiString S=((TEdit *)Sender)->Text;
  int c=S.AnsiPos("В");
  int LenS=S.Length();
  if(c) S.Delete(c,LenS-c+1);
  do {
    c=S.Pos(" ");
    if(!c) break;
    S.Delete(c,1);
  }while(true);
  c=S.Pos(".");
  if (c) S[c]=',';

  ((TEdit *)Sender)->Text=(S+" В");

  float Number;
  BOOL k=false;
  try
  {
    Number=StrToFloat(S);
  }
  catch(EConvertError&)
  {
    ((TEdit *)Sender)->Text=OldText;
    k=true;
  }
  if (!k) {
    if(Sender==Edit1)A=Number;
    else dA=Number;
  }

}    */
//---------------------------------------------------------------------------

/*
  AnsiString S=((TEdit *)Sender)->Text;
  int c=S.AnsiPos("мс");
  int LenS=S.Length();
  if(c) S.Delete(c,LenS-c+1);
  do {
    c=S.Pos(" ");
    if(!c) break;
    S.Delete(c,1);
  }while(true);

  ((TEdit *)Sender)->Text=(S+" мс");

  int Number;
  BOOL k=false;
  try
  {
    Number=StrToInt(S);
  }
  catch(EConvertError&)
  {
    ((TEdit *)Sender)->Text=OldText;
    k=true;
  }
  if (!k) {
    if(Sender==Edit4)T=Number;
    else t=Number;
  }

}   */
//---------------------------------------------------------------------------

/*
void __fastcall TFOptions::Edit2Exit(TObject *Sender)
{
  AnsiString S=((TEdit *)Sender)->Text;
  int c;
  do {
    c=S.Pos(" ");
    if(!c) break;
    S.Delete(c,1);
  }while(true);

  ((TEdit *)Sender)->Text=S;

  int Number;
  BOOL k=false;
  try
  {
    Number=StrToInt(S);
  }
  catch(EConvertError&)
  {
    k=true;
  }
  if ((!k)&&(Number>0)&&(Number<=100)) {
    UpDown1->Position=Number;
    N=Number;
  }
  else ((TEdit *)Sender)->Text=OldText;
} */
//---------------------------------------------------------------------------


void __fastcall TFOptions::FormShow(TObject *Sender)
{
/*
  G0=PConf->Gen0/50;
  G1=PConf->Gen1/50;

  Edit6->Text=IntToStr(G0)+" мкс";
  Edit7->Text=IntToStr(G1)+" мкс";

  switch (PConf->ADC_Clock) {
    case ClockSrc_IntGen0: ComboBox1->ItemIndex=0; break;
    case ClockSrc_IntGen1: ComboBox1->ItemIndex=1; break;
  }

  switch (PConf->DAC_Clock) {
    case ClockSrc_IntGen0: ComboBox2->ItemIndex=0; break;
    case ClockSrc_IntGen1: ComboBox2->ItemIndex=1; break;
  }

  i0CheckBox->Checked=PConf->ADCChanel[0];
  i1CheckBox->Checked=PConf->ADCChanel[1];
  i2CheckBox->Checked=PConf->ADCChanel[2];
  i3CheckBox->Checked=PConf->ADCChanel[3];
*/
  for(int i=0;i<2;i++) {
    Coeff[i]=PConf->ADCCoeff[i];
    Value[i]=(char *) PConf->ADCValue[i];
  }

  EditCoef1->Text=FloatToStr(PConf->ADCCoeff[0])+" "+PConf->ADCValue[0];
  EditCoef2->Text=FloatToStr(PConf->ADCCoeff[1])+" "+PConf->ADCValue[1];
//  EditCoef3->Text=FloatToStr(PConf->ADCCoeff[2])+" "+PConf->ADCValue[2];
//  EditCoef4->Text=FloatToStr(PConf->ADCCoeff[3])+" "+PConf->ADCValue[3];

  for(int i=0;i<1;i++) {
    DACCoeff[i]=PConf->DACCoeff[i];
    DACValue[i]=(char *) PConf->DACValue[i];
  }

  EditCoeffDAC1->Text=FloatToStr(PConf->DACCoeff[0])+" "+PConf->DACValue[0];

  Min1=PConf->ADCMin[0];
  Max1=PConf->ADCMax[0];
  Min2=PConf->ADCMin[1];
  Max2=PConf->ADCMax[1];

  Edit1Max->Text=Max1;
  Edit1Min->Text=Min1;
  Edit2Max->Text=Max2;
  Edit2Min->Text=Min2;


//  EditCoeffDAC2->Text=FloatToStr(PConf->DACCoeff[1])+" "+PConf->DACValue[1];
//  EditCoeffDAC3->Text=FloatToStr(PConf->DACCoeff[2])+" "+PConf->DACValue[2];
//  EditCoeffDAC4->Text=FloatToStr(PConf->DACCoeff[3])+" "+PConf->DACValue[3];

/*
  o0CheckBox->Checked=PConf->DACChanel[0];
  o1CheckBox->Checked=PConf->DACChanel[1];
  o2CheckBox->Checked=PConf->DACChanel[2];
  o3CheckBox->Checked=PConf->DACChanel[3];

  switch (PConf->EMemSource0) {
    case MemSrc_ADC0: ComboBox3->ItemIndex=2; break;
    case MemSrc_ADC1: ComboBox4->ItemIndex=2; break;
    case MemSrc_DAC0: ComboBox5->ItemIndex=2; break;
    case MemSrc_DAC1: ComboBox6->ItemIndex=2; break;
  }

  switch (PConf->EMemSource1) {
    case MemSrc_ADC0: ComboBox3->ItemIndex=3; break;
    case MemSrc_ADC1: ComboBox4->ItemIndex=3; break;
    case MemSrc_DAC0: ComboBox5->ItemIndex=3; break;
    case MemSrc_DAC1: ComboBox6->ItemIndex=3; break;
  }

  switch (PConf->IMemSource0) {
    case MemSrc_ADC0: ComboBox3->ItemIndex=0; break;
    case MemSrc_ADC1: ComboBox4->ItemIndex=0; break;
    case MemSrc_DAC0: ComboBox5->ItemIndex=0; break;
    case MemSrc_DAC1: ComboBox6->ItemIndex=0; break;
  }

  switch (PConf->IMemSource1) {
    case MemSrc_ADC0: ComboBox3->ItemIndex=1; break;
    case MemSrc_ADC1: ComboBox4->ItemIndex=1; break;
    case MemSrc_DAC0: ComboBox5->ItemIndex=1; break;
    case MemSrc_DAC1: ComboBox6->ItemIndex=1; break;
  }

  ComboBox7->ItemIndex=0;

  N=PConf->NPulse;
  Edit2->Text=IntToStr(N);

  A=PConf->A;
  Edit1->Text=FloatToStr(A)+" В";

  dA=PConf->dA;
  Edit3->Text=FloatToStr(dA)+" В";

  T=PConf->T;
  Edit4->Text=FloatToStr(T)+" мс";

  t=PConf->t;
  Edit5->Text=FloatToStr(t)+" мс";
*/
}
//---------------------------------------------------------------------------

void __fastcall TFOptions::FormDestroy(TObject *Sender)
{
  delete PConf;
}
//---------------------------------------------------------------------------

void __fastcall TFOptions::EditCoefADCExit(TObject *Sender)
{
  AnsiString S=((TEdit *)Sender)->Text;

  int LenS=S.Length();
  AnsiString NumS="";

  int c=S.Pos(".");
  if (c) S[c]=',';

  for(int i=1;(('0'<=S[i])&&(S[i]<='9')||(S[i]==',')||(S[i]=='e')||(S[i]=='E')
    ||(S[i]=='-')||(S[i]=='+'))&&(i<=LenS);i++) NumS+=S[i];

  S.Delete(1,NumS.Length());
  while(S.Pos(" ")) S.Delete(S.Pos(" "),1);


  double Number;
  BOOL k=false;
  try
  {
    Number=StrToFloat(NumS);
  }
  catch(EConvertError&)
  {
    ((TEdit *)Sender)->Text=OldText;
    k=true;
  }
  if (!k) {
    ((TEdit *)Sender)->Text=(FloatToStr(Number)+" "+S);
    if (Sender==EditCoef1) {Coeff[0]=Number; Value[0]=S;}
    else if (Sender==EditCoef2) {Coeff[1]=Number; Value[1]=S;}

/*    else if (Sender==EditCoef3) {Coeff[2]=Number; Value[2]=S;}
    else  {Coeff[3]=Number; Value[3]=S;}*/
  }
}
//---------------------------------------------------------------------------






void __fastcall TFOptions::EditCoeffDACExit(TObject *Sender)
{
  AnsiString S=((TEdit *)Sender)->Text;

  int LenS=S.Length();
  AnsiString NumS="";

  int c=S.Pos(".");
  if (c) S[c]=',';

  for(int i=1;(('0'<=S[i])&&(S[i]<='9')||(S[i]==',')||(S[i]=='e')||(S[i]=='E')
    ||(S[i]=='-')||(S[i]=='+'))&&(i<=LenS);i++) NumS+=S[i];

  S.Delete(1,NumS.Length());
  while(S.Pos(" ")) S.Delete(S.Pos(" "),1);


  double Number;
  BOOL k=false;
  try
  {
    Number=StrToFloat(NumS);
  }
  catch(EConvertError&)
  {
    ((TEdit *)Sender)->Text=OldText;
    k=true;
  }
  if (!k) {
    ((TEdit *)Sender)->Text=(FloatToStr(Number)+" "+S);
    if (Sender==EditCoeffDAC1) {DACCoeff[0]=Number; DACValue[0]=S;}
  }
/*    else if (Sender==EditCoeffDAC2) {DACCoeff[1]=Number; DACValue[1]=S;}
    else if (Sender==EditCoeffDAC3) {DACCoeff[2]=Number; DACValue[2]=S;}
    else  {DACCoeff[3]=Number; DACValue[3]=S;}
  }*/

}
//---------------------------------------------------------------------------



void __fastcall TFOptions::EditMaxMinExit(TObject *Sender)
{
  float Tmp;

  try {
    Tmp=StrToFloat(((TEdit*)Sender)->Text);
  }
  catch (EConvertError&){
    ((TEdit *)Sender)->Text=OldText;
    return;
  };
  if (Sender==Edit1Max) Max1=Tmp; else
  if (Sender==Edit1Min) Min1=Tmp; else
  if (Sender==Edit2Max) Max2=Tmp; else
  if (Sender==Edit2Min) Min2=Tmp;
}
//---------------------------------------------------------------------------

