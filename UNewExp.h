//---------------------------------------------------------------------------

#ifndef UNewExpH
#define UNewExpH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TNewExp : public TForm
{
__published:	// IDE-managed Components
        TEdit *EditName;
        TButton *Btn_OK;
        TButton *Btn_Cancel;
private:	// User declarations
public:		// User declarations
        __fastcall TNewExp(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNewExp *NewExp;
//---------------------------------------------------------------------------
#endif
