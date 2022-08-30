//---------------------------------------------------------------------------

#ifndef ScrollChartH
#define ScrollChartH
//---------------------------------------------------------------------------
#include <Chart.hpp>

class CScrollChart {

  TChart*  Chart1;
  TChart*  Chart2;

  TScrollBar* ScrollX;
  TScrollBar* ScrollY1;
  TScrollBar* ScrollY2;

  double MinX, MaxX, Lx, Kx,
         MinY1,MaxY1,Ly1,Ky1,
         MinY2,MaxY2,Ly2,Ky2;
  double q;

 public:
//  CScrollChart(TChart* Chrt1,TChart* Chrt1,TScrollBar* SBX,TScrollBar* SBY1,TScrollBar* SBY2);
  CScrollChart(TChart*,TChart*,TScrollBar*,TScrollBar*,TScrollBar*);

  void ScrollXChange();
  void ScrollY1Change();
  void ScrollY2Change();

  void ScaleXChange();
  void ScaleY1Change();
  void ScaleY2Change();

  void SetMinMax();
  void ViewAll();
};

#endif
