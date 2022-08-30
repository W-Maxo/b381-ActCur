//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Cursor.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
  void __fastcall  Cursors::FillWinLine(){
    double ci=*I0;

    if (!S->Ni) return;

    double T=(P->X-S->t0)/S->dt;
    int k=0;

    if ((T>=0)&&(T<=S->Nt)) k=T;

    P->X=S->t0+k*S->dt;

    ToolWin->Memo1->Lines->Clear();
    ToolWin->Memo1->Lines->Add("\x09t="+FloatToStrF(P->X,ffFixed,6,3)+" мс");
    ToolWin->Memo1->Lines->Add("");

    AnsiString Txt="";

    float **D;
    D=new float*[2];
    for (int i=0;i<2;i++) {
      D[i]=new float[S->Ni/2];
      for (int j=0;j<S->Ni/2;j++) {
        if ((k>=8)&&(k<=S->Nt-8)) {
          D[i][j]=0;
          for (int l=k-8;l<k+8;l++)
            D[i][j]+=S->Data[2*j+i][l];
          D[i][j]/=16;
        }
        else D[i][j]=S->Data[2*j+i][k];
      }
    }

    for(int i=0;i<S->Ni/2;i++) D[0][i]-=ci;

    int MaxI;
    float A;
    for (int i=0;i<S->Ni/2-1;i++) {
      MaxI=i;

      for (int j=i+1;j<S->Ni/2;j++)
        if (D[1][MaxI]<D[1][j]) MaxI=j;

      if (MaxI!=i) {
        A=D[0][i];
        D[0][i]=D[0][MaxI];
        D[0][MaxI]=A;

        A=D[1][i];
        D[1][i]=D[1][MaxI];
        D[1][MaxI]=A;
      }
    }


    for(int i=0;i<S->Ni/2;i++ ) {
      ToolWin->Memo1->Lines->Add(IntToStr(i+1)+": "
        +FloatToStrF(D[1][i],ffFixed,6,1)+PConf->ADCValue[1]+" "
        +FloatToStrF(D[0][i],ffFixed,6,4)+PConf->ADCValue[0]);
      Txt+=FloatToStrF(D[1][i],ffFixed,6,1)+"\x09";
      Txt+=FloatToStrF(D[0][i],ffFixed,6,4);
      if (i!=S->Ni/2-1) Txt+="\n";
    }

    Clipboard()->Clear();
    //Clipboard()->SetTextBuf(Txt.c_str());

    ToolWin->Height=34+(abs(ToolWin->Memo1->Font->Height)+2)*(S->Ni/2+3);

    delete[] D[0];
    delete[] D[1];
    delete[] D;

  };

  void __fastcall  Cursors::FillWinX(){
    AnsiString Txt="";
    int n=0;

    P=Top;
    while (P) {
      P=P->Pred;
      n++;
    };

    float **D;
    D=new float*[n];
    P=Top;
    for(int i=n-1;i>=0;i--) {
      D[i]=new float[3];
      D[i][0]=P->X;
      D[i][1]=P->Y2;
      D[i][2]=P->Y-P->ci0;
      P=P->Pred;
    }

    int MaxI;
    float A;
    for (int i=0;i<n-1;i++) {
      MaxI=i;

      for (int j=i+1;j<n;j++)
        if (D[MaxI][1]>D[j][1]) MaxI=j;

      if (MaxI!=i) {
        A=D[i][0];
        D[i][0]=D[MaxI][0];
        D[MaxI][0]=A;

        A=D[i][1];
        D[i][1]=D[MaxI][1];
        D[MaxI][1]=A;

        A=D[i][2];
        D[i][2]=D[MaxI][2];
        D[MaxI][2]=A;
      }
    }




    ToolWin->Memo1->Lines->Clear();
    for(int i=0;i<n;i++) {
      ToolWin->Memo1->Lines->Add(
        FloatToStrF(D[i][1],ffFixed,6,1)+PConf->ADCValue[1]+"  "
        +FloatToStrF(D[i][2],ffFixed,6,4)+PConf->ADCValue[0]+"  "
        +FloatToStrF(D[i][0],ffFixed,6,0)+"мc ");

      Txt+=FloatToStrF(D[i][1],ffFixed,6,1)+"\x09";
      Txt+=FloatToStrF(D[i][2],ffFixed,6,4)+"\x09";
      Txt+=FloatToStrF(D[i][0],ffFixed,6,0);
      if (i!=n-1) Txt+="\n";
      delete[] D[i];
	}
    delete[] D;

    Clipboard()->Clear();
    //Clipboard()->SetTextBuf(Txt.c_str());

    Txt.c_str();

    ToolWin->Height=34+(abs(ToolWin->Memo1->Font->Height)+2)*(n+1);
  };


//---------------------------------------------------------------------------
   Cursors::~Cursors() {
     Clear();
   }


//---------------------------------------------------------------------------
   void __fastcall Cursors::Activate(TMouseButton Btn,void* Ch,int x,int y) {

    if (!Active) return;
    switch (Type) {

      case 0:
        return;          // нет курсоров

      case 1: {          // +-образные курсоры
        break;};

      case 2: {          // |-образные курсоры
        if (!Top) {
          Top=new CursorData;
          Top->Pred=NULL;
        };
        P=Top;
        SetChart(Ch);
        SetX(x);
        P->Color=clAqua;
        FillWinLine();
        break;};

      case 3: {          // x-образные курсоры
          switch (Btn) {

            case mbLeft: {
              P=Top;
              Top=new CursorData;
              Top->Pred=P;
              P=Top;
              SetChart(Ch);
              SetX(x);
              SetY(y);
              SetXCoord();
              P->ci0=*I0;
              P->Color=clNavy;
              break;
            };

            case mbRight: {
              if (!Top) break;
              P=Top->Pred;
              delete Top;
              Top=P;
              break;
            };
          }
          FillWinX();
          break;};
/*
      case 4: {        //Уровень
          if (Ch==Chrt[0]) {

          };
          break;}   */
     }

     Visible=true;
     Chrt[0]->Repaint();
     Chrt[1]->Repaint();
     ToolWin->Visible=true;
   };


//---------------------------------------------------------------------------
   void __fastcall Cursors::SetX(int x) {

     int kx=6;
     int Dx=Chrt[P->I]->Width;
     double dx=Dx*Chrt[P->I]->MarginLeft*0.01+Chrt[P->I]->LeftAxis->LabelsSize+kx;

     Dx=Dx*(100.0-Chrt[P->I]->MarginLeft-Chrt[P->I]->MarginRight)*0.01
        -Chrt[P->I]->LeftAxis->LabelsSize-kx;

     double Cx=Chrt[P->I]->BottomAxis->Maximum-Chrt[P->I]->BottomAxis->Minimum;
     int TmpX=x-dx;

     P->X=Chrt[P->I]->BottomAxis->Minimum+(Cx*TmpX)/Dx;
   };



//---------------------------------------------------------------------------
   void __fastcall Cursors::SetY(int y){
     int ky=6;
     double Dy=Chrt[P->I]->Height;
     double dy=Dy*Chrt[P->I]->MarginBottom*0.01+Chrt[P->I]->BottomAxis->LabelsSize+ky;

     Dy=Dy*(100.0-Chrt[P->I]->MarginTop-Chrt[P->I]->MarginBottom)*0.01
        -Chrt[P->I]->BottomAxis->LabelsSize-ky;

     double Cy=Chrt[P->I]->LeftAxis->Maximum-Chrt[P->I]->LeftAxis->Minimum;
     int TmpY=Chrt[P->I]->Height-y-dy;

     P->Y=Chrt[P->I]->LeftAxis->Minimum+(Cy*TmpY)/Dy;
   };


//---------------------------------------------------------------------------
   void __fastcall Cursors::SetXY(int x,int y){
     SetX(x);
     SetY(y);
   };


//---------------------------------------------------------------------------
   void __fastcall Cursors::Set(void* Cht,int x,int y){
     SetChart(Cht);
     SetX(x);
     SetY(y);

/*     Present=true;
     Visible=true;
*/
     ToolWin->Memo1->Lines->Strings[0]=FloatToStrF(P->X,ffFixed,3,3);
     ToolWin->Memo1->Lines->Strings[1]=FloatToStrF(P->Y,ffFixed,3,3);

     Chrt[P->I]->Repaint();
   };


//---------------------------------------------------------------------------
   void __fastcall Cursors::Hide(){
     Visible=false;
     if (Top) {
        Chrt[0]->Repaint();
        Chrt[1]->Repaint();
     };
   };


//---------------------------------------------------------------------------
   void __fastcall Cursors::Show(){
     if (!(Visible&&Top)) return;
     switch (Type) {
       case 1: { DrawCross(); break; }
       case 2: { DrawLine(); break; }
       case 3: { DrawX(); break; }
     }
   };


//---------------------------------------------------------------------------
   void __fastcall Cursors::Clear(){
     ToolWin->Visible=false;
     ToolWin->Memo1->Lines->Clear();
     Hide();
     while (true) {
       P=Top;
       if (!P) break;
       Top=P->Pred;
       delete P;
     }
   };


//---------------------------------------------------------------------------
   void __fastcall Cursors::DrawCross() {
     int x=GetIntX();
     int y=GetIntY();
     Chrt[P->I]->Canvas->Pen->Color=clRed;
     Chrt[P->I]->Canvas->MoveTo(x,0);
     Chrt[P->I]->Canvas->LineTo(x,Chrt[P->I]->Height);
     Chrt[P->I]->Canvas->MoveTo(0,y);
     Chrt[P->I]->Canvas->LineTo(Chrt[P->I]->Width,y);
   };


//---------------------------------------------------------------------------
   void __fastcall Cursors::DrawLine() {
     int x=GetIntX();

     for(int i=0;i<2;i++) {
       Chrt[i]->Canvas->Pen->Color=P->Color;
       Chrt[i]->Canvas->MoveTo(x,0);
       Chrt[i]->Canvas->LineTo(x,Chrt[i]->Height);
     }
   };


//---------------------------------------------------------------------------
   void __fastcall Cursors::DrawX() {

    P=Top;
     int y,x;

     while (P) {
       for(int i=0;i<2;i++) {
         x=GetIntX(P->X,Chrt[i]);
         if (i) y=GetIntY(P->Y2,Chrt[1]);
         else y=GetIntY(P->Y,Chrt[0]);

         Chrt[i]->Canvas->Pen->Color=P->Color;

         Chrt[i]->Canvas->MoveTo(x-10,y-10);
         Chrt[i]->Canvas->LineTo(x+10,y+10);
         Chrt[i]->Canvas->MoveTo(x+10,y-10);
         Chrt[i]->Canvas->LineTo(x-10,y+10);
       };
       P=P->Pred;
     };
   };


//---------------------------------------------------------------------------
   int __fastcall  Cursors::GetIntX() {

     int k=6;
     double a1=Chrt[P->I]->Width*Chrt[P->I]->MarginLeft*0.01+Chrt[P->I]->LeftAxis->LabelsSize+k;
     double a2=Chrt[P->I]->Width*Chrt[P->I]->MarginRight*0.01;
     double lx=Chrt[P->I]->Width-a1-a2;

     int x=a1+lx*(P->X-Chrt[P->I]->BottomAxis->Minimum)/
      (Chrt[P->I]->BottomAxis->Maximum-Chrt[P->I]->BottomAxis->Minimum);
     return x;
   };


//---------------------------------------------------------------------------
   int __fastcall  Cursors::GetIntY() {
     int k=6;
     double b1=Chrt[P->I]->Height*Chrt[P->I]->MarginTop*0.01;
     double b2=Chrt[P->I]->Height*Chrt[P->I]->MarginBottom*0.01+Chrt[P->I]->BottomAxis->LabelsSize+k;
     double ly=Chrt[P->I]->Height-b1-b2;

     int y=b1+ly*(Chrt[P->I]->LeftAxis->Maximum-P->Y)/
      (Chrt[P->I]->LeftAxis->Maximum-Chrt[P->I]->LeftAxis->Minimum);
     return y;
   };

//---------------------------------------------------------------------------
   int __fastcall  Cursors::GetIntX(double X,TChart *chrt) {

     int k=6;
     double a1=chrt->Width*chrt->MarginLeft*0.01+chrt->LeftAxis->LabelsSize+k;
     double a2=chrt->Width*chrt->MarginRight*0.01;
     double lx=chrt->Width-a1-a2;

     int x=a1+lx*(X-chrt->BottomAxis->Minimum)/
      (chrt->BottomAxis->Maximum-chrt->BottomAxis->Minimum);
     return x;
   };


//---------------------------------------------------------------------------
   int __fastcall  Cursors::GetIntY(double Y,TChart *chrt) {
     int k=6;
     double b1=chrt->Height*chrt->MarginTop*0.01;
     double b2=chrt->Height*chrt->MarginBottom*0.01+chrt->BottomAxis->LabelsSize+k;
     double ly=chrt->Height-b1-b2;

     int y=b1+ly*(chrt->LeftAxis->Maximum-Y)/
      (chrt->LeftAxis->Maximum-chrt->LeftAxis->Minimum);
     return y;
   };


   void __fastcall Cursors::SetXCoord(){

     if (S->Ni) {
       double T=(P->X-S->t0)/S->dt;
       int k=0;

       if ((T>=0)&&(T<=S->Nt-1)) k=T;
       P->X=S->t0+k*S->dt;

       int MinI=P->I;
       for(int i=P->I;i<S->Ni;i+=2){
         if (fabs(P->Y-S->Data[i][k])<=fabs(P->Y-S->Data[MinI][k])) MinI=i ;
       }

       int i1=k-8; if (i1<0) i1=0;
       int i2=k+8; if (i2>S->Nt) i2=S->Nt;
       float A1=0;
       float A2=0;

       if (P->I)
         for(int i=i1;i<i2;i++) {
           A1+=S->Data[MinI-1][i];
           A2+=S->Data[MinI][i];
         }
       else
         for(int i=i1;i<i2;i++) {
           A1+=S->Data[MinI][i];
           A2+=S->Data[MinI+1][i];
         }
       A1/=(i2-i1);
       A2/=(i2-i1);

       P->Y=A1;
       P->Y2=A2;
     }
   };

