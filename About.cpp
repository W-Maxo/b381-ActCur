//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "About.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RzStatus"
#pragma resource "*.dfm"
#include "Main.h"
TAboutForm *AboutForm;
//---------------------------------------------------------------------------
__fastcall TAboutForm::TAboutForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAboutForm::FormCreate(TObject *Sender)
{
  RzStatusPane1->Caption = "B381 " + Form1->RzVersionInfo1->FileVersion;
}
//---------------------------------------------------------------------------
void __fastcall TAboutForm::BitBtn1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
