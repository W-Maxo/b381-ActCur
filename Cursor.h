//---------------------------------------------------------------------------

#ifndef CursorH
#define CursorH
#include <Chart.hpp>
#include <vcl\Clipbrd.hpp>
#include "UToolWin.h"
#include "Csignal.cpp"
#include "CConf.cpp"
//---------------------------------------------------------------------------
 struct CursorData {
   double X,Y,Y2,ci0;
      int I,NS;
   TColor Color;

   CursorData *Pred;
 };


 class Cursors {

  private:
   CursorData *P;
   CursorData *Top;
       double *I0;
//     bool PI0;
//    TEdit *EditI0;
//     bool Present;
      int Type;
     bool Visible;
     bool Active;
   TChart *Chrt[2];
//      int I;
//      int N;
//  Cursors *Pred;
//  Cursors *Next;
   CSeria *S;
   CConf  *PConf;

  public:

   Cursors(TChart* ch1,TChart* ch2,CSeria* Sr,CConf* Cnf,double *i0/*,TEdit* Edt*/){
//       PI0=false;
       Type=0;
       I0=i0;
       P=NULL;
       Top=NULL;
       Visible=false;
       Chrt[0]=ch1;
       Chrt[1]=ch2;
       S=Sr;
       PConf=Cnf;
       Active=true;
//       EditI0=Edt;
//       EditI0->Text=FloatToStrF(I0,ffFixed,5,4)+" "+PConf->ADCValue[0];
   };
   ~Cursors();

   void __fastcall SetChart(void* Chr){
       if (Chrt[0]==(TChart *) Chr)
         P->I=0;
       else if (Chrt[1]==(TChart *) Chr)
         P->I=1;
       else
         P->I=-1;
   };

 private:
   void __fastcall SetX(int x);
   void __fastcall SetY(int y);
   void __fastcall SetXY(int x,int y);
   void __fastcall Set(void* Chrt,int x,int y);

 public:
   void __fastcall Activate(TMouseButton Btn,void* Chrt,int x,int y);
   void __fastcall On(){Active=true;};
   void __fastcall Off(){Active=false;};
   void __fastcall Hide();
   void __fastcall Show();
   void __fastcall Clear();
   void __fastcall SetType(int T){
     if (T!=Type) {
       Clear();
       Type=T;
     };
   };


 private:
   void __fastcall DrawCross();
   void __fastcall DrawLine();
   void __fastcall DrawX();
    int __fastcall GetIntX();
    int __fastcall GetIntY();
    int __fastcall GetIntX(double X,TChart *chrt);
    int __fastcall GetIntY(double Y,TChart *chrt);
   void __fastcall FillWinLine();
   void __fastcall FillWinX();
   void __fastcall SetXCoord();
 };

#endif
