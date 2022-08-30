//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

USEFORM("Main.cpp", Form1);
USEFORM("UOptions.cpp", FOptions);
USEFORM("UComment.cpp", Comment);
USEFORM("UNewExp.cpp", NewExp);
USEFORM("UToolWin.cpp", ToolWin);
USEFORM("UNewSeries.cpp", NewSeries);
USEFORM("Ufft.cpp", Form2);
USEFORM("URecMenu.cpp", RecDial);
USEFORM("About.cpp", AboutForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TFOptions), &FOptions);
		Application->CreateForm(__classid(TComment), &Comment);
		Application->CreateForm(__classid(TNewExp), &NewExp);
		Application->CreateForm(__classid(TToolWin), &ToolWin);
		Application->CreateForm(__classid(TNewSeries), &NewSeries);
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->CreateForm(__classid(TRecDial), &RecDial);
        Application->CreateForm(__classid(TAboutForm), &AboutForm);
		Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
