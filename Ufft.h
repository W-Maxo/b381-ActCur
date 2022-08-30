//---------------------------------------------------------------------------

#ifndef UfftH
#define UfftH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TChart *Chart1;
        TFastLineSeries *Series1;
        TSplitter *Splitter1;
        TChart *Chart2;
        TFastLineSeries *Series3;
        TFastLineSeries *Series2;
        TFastLineSeries *Series4;
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    float* D;
    int N;
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
