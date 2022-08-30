//---------------------------------------------------------------------------

#ifndef UNewSeriesH
#define UNewSeriesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "RzButton.hpp"
//---------------------------------------------------------------------------
class TNewSeries : public TForm
{
__published:	// IDE-managed Components
        TEdit *EditName;
        TLabel *LNameSeries;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TEdit *Edit5;
        TEdit *Edit6;
        TEdit *Edit7;
        TLabel *Label5;
        TEdit *Edit8;
        TLabel *Label6;
        TLabel *Label7;
        TButton *Button2;
        TEdit *Edit9;
	TRzBitBtn *RzBitBtn1;
        void __fastcall EditEnter(TObject *Sender);
        void __fastcall EditExit(TObject *Sender);
        void __fastcall Edit9Exit(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormHide(TObject *Sender);
private:	// User declarations
        AnsiString OldText,NewText;
        int Tu,To,Ts,Tf,Np,Gen,GenMul;
public:		// User declarations
        __fastcall TNewSeries(TComponent* Owner);
        double dt;
};
//---------------------------------------------------------------------------
extern PACKAGE TNewSeries *NewSeries;
//---------------------------------------------------------------------------
#endif
