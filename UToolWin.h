//---------------------------------------------------------------------------

#ifndef UToolWinH
#define UToolWinH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TToolWin : public TForm
{
__published:	// IDE-managed Components
        TScrollBox *ScrollBox1;
        TMemo *Memo1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TToolWin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TToolWin *ToolWin;
//---------------------------------------------------------------------------
#endif
