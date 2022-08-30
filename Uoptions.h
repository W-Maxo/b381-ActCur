//---------------------------------------------------------------------------

#ifndef UOptionsH
#define UOptionsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>

//#include "b181.h"
//---------------------------------------------------------------------------
class TFOptions : public TForm
{
__published:	// IDE-managed Components
        TButton *ButtonOK;
        TButton *ButtonCancel;
        TGroupBox *GroupBoxCADC;
        TGroupBox *GroupBoxCDAC;
        TEdit *EditCoef1;
        TEdit *EditCoef2;
        TEdit *EditCoeffDAC1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label5;
        TEdit *Edit1Max;
        TEdit *Edit2Max;
        TEdit *Edit1Min;
        TEdit *Edit2Min;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label6;
        void __fastcall FormHide(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
//        void __fastcall Edit67Exit(TObject *Sender);
        void __fastcall EditEnter(TObject *Sender);
//        void __fastcall Edit2Exit(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall EditCoefADCExit(TObject *Sender);
        void __fastcall EditCoeffDACExit(TObject *Sender);
        void __fastcall EditMaxMinExit(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFOptions(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFOptions *FOptions;

/*extern ADCConfigStruct  ADCConfig;  //     Конфигурация АЦП
/*extern ReadADCStruct    ReadADC;    //     Чтение данных АЦП

/*extern DACConfigStruct  DACConfig;  //     Конфигурация ЦАП
/*extern WriteDACCStruct  WriteDAC;   //     Запись данных в ЦАП

/*extern CmnConfigStruct  CmnConfig;  //     Конфигурация всей системы
/*extern CmnControlStruct CmnControl; //     Управление всей системой
/*extern CmnStatusStruct  CmnStatus;  //     Статусный регистр
        */
//---------------------------------------------------------------------------
#endif
