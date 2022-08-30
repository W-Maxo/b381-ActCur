//---------------------------------------------------------------------------

#ifndef RecorderH
#define RecorderH
//---------------------------------------------------------------------------
#include <Chart.hpp>
#include <Series.hpp>
#include <vcl\Clipbrd.hpp>
extern int SeriaNumber;

class CRecData {
 private:
  struct RStack{
    float* ID;
    float* VD;
    float* TD;
    RStack* Next;
  };
  RStack* Head;
  RStack* Tail;
  RStack* P;

  struct RLine{
    float T;
    int SN;
    RLine* Next;
  };
  RLine* LHead;
  RLine* LTail;
  RLine* LP;

  double T0;
  int N;
  int Nl;
  int NlStck;
  TChart* ChartI;
  TChart* ChartV;
  TFastLineSeries* SrI;
  TFastLineSeries* SrV;
  TScrollBar* Scroll;
  TScrollBar* ScrollI;
  TScrollBar* ScrollU;
  TPanel* Panel;
  TSplitter* Splitter;
  bool Loaded;
  bool Stopped;
  float MinI,MaxI;
  float MinV,MaxV;
  int kStack;
  float k1;
  float k2;
  float k3;
  double ksI,ksU;

 public:
  AnsiString RName;
  CRecData();
  ~CRecData();
  void __fastcall Init(TChart* ChI, TChart* ChV, TFastLineSeries* srI,
     TFastLineSeries* srV, TScrollBar* SB, TScrollBar* SBI, TScrollBar* SBU,TPanel* Pnl,TSplitter* Spl);
  void __fastcall AddPoint(float,float,double);
  void __fastcall Clear();
  void __fastcall RLoad();
  void __fastcall RSave();
  void __fastcall Run();
  void __fastcall RScroll();
  void __fastcall RScrollI();
  void __fastcall RScrollU();
  void __fastcall AddLine(double);
  void __fastcall ShowLines(TChart*);
  bool __fastcall SendToClipboard(int,int,int,bool,bool,bool);
  void __fastcall ZoomInI();
  void __fastcall ZoomOutI();
  void __fastcall ZoomInU();
  void __fastcall ZoomOutU();

};

#endif
