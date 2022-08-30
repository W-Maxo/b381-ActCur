//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ScrollChart.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)



CScrollChart::CScrollChart(TChart* Chrt1,TChart* Chrt2,TScrollBar* SBX,TScrollBar* SBY1,TScrollBar* SBY2) {
  Chart1=Chrt1;
  Chart2=Chrt2;

  ScrollX=SBX;
  ScrollY1=SBY1;
  ScrollY2=SBY2;
};
