#if !defined __B381LIB_CPP
#define __B381LIB_CPP
#include "b381lib.h"
//#include <vcl.h>
int __fastcall StrToTm(const AnsiString S) {
  AnsiString St=S,SD;
  int Tm=0,c;
  double D;

  do {
    c=St.Pos(" ");
    if(!c) break;
    St.Delete(c,1);
  }while(true);

  int p0,p=1;
 do {
  p0=p;
  if (p0>St.Length()) break;
  while (p<=St.Length()) {
    if (!(((St[p]>='0')&&(St[p]<='9'))||(St[p]==',')||(St[p]=='e')||(St[p]=='E')||(St[p]=='-')||(St[p]=='+'))) break;
    p++;
  }

  try
  {
    D=StrToFloat(St.SubString(p0,p-p0));
  }
  catch(EConvertError&)
  {
    return 0;
  }

  p0=p;
  if (p0>St.Length()) break;
  while (p<=St.Length()) {
    if (!((St[p]<='ч')||(St[p]=='н')||(St[p]=='и')||(St[p]=='с')||(St[p]=='к')||(St[p]=='м'))) break;
    p++;
  }
  SD=St.SubString(p0,p-p0);
  if (SD=="мкс") Tm+=D/10;
  else if (SD=="мс") Tm+=D*100;
  else if (SD=="с") Tm+=D*1000*100;
  else if (SD=="мин") Tm+=D*60*1000*100;
  else if (SD=="ч") Tm+=D*60*60*1000*100;
  else return 0;

 }
 while (true);


 return Tm;
};

//¬рем€ в виде строки
AnsiString __fastcall TmToStr(const int Tm) {
  AnsiString S="";
  int T=Tm,D;
  if (T<0) {S="-"; T=-T;}

  //часы
  D=T/(60*60*1000*100);
  T%=60*60*1000*100;
  if (D) S+=IntToStr(D)+" ч ";

  //минуты
  D=T/(60*1000*100);
  T%=60*1000*100;
  if (D) S+=IntToStr(D)+" мин ";

  //секунды
  D=T/(1000*100);
  T%=1000*100;
  if (D) S+=IntToStr(D)+" с ";

  //милисекунды
  D=T/100;
  T%=100;
  if (D) S+=IntToStr(D)+" мс ";

  //микросекунды
  D=T*10;
  if (D) S+=IntToStr(D)+" мкс ";

  return S;
};

#endif
