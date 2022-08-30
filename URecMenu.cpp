//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "URecMenu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRecDial *RecDial;
//---------------------------------------------------------------------------
__fastcall TRecDial::TRecDial(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TRecDial::Button1Click(TObject *Sender)
{
  Hide();      
}
//---------------------------------------------------------------------------
