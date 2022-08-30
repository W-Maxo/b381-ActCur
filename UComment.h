//---------------------------------------------------------------------------

#ifndef UCommentH
#define UCommentH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TComment : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo;
        TButton *BtnSave;
        TButton *BtnCancel;
private:	// User declarations
public:		// User declarations
        __fastcall TComment(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TComment *Comment;
//---------------------------------------------------------------------------
#endif
