//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UToolWin.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TToolWin *ToolWin;
//---------------------------------------------------------------------------
__fastcall TToolWin::TToolWin(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TToolWin::FormClose(TObject *Sender, TCloseAction &Action)
{
	Form1->PointsI->Clear();
	Form1->PointsU->Clear();
}
//---------------------------------------------------------------------------

