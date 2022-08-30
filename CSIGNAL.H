#ifndef CSignalH
#define CSignalH
//-------------------------------------------------------------------------------------
#include <vcl.h>

struct CSignal {
     float **Signals;
     UCHAR NS;    // Количество сигналов
     UINT LenS;   // Длина сигналов в отсчетах
     CSignal(){NS=0; LenS=0; Signals=NULL;}
    ~CSignal();
BOOL __fastcall AddSignal();
BOOL __fastcall DeleteSignal(UCHAR c);
void __fastcall ClearAll();
void __fastcall CreateEmpty(UINT N,UINT L);

BOOL __fastcall LoadFromBinFile(char *S);
BOOL __fastcall LoadFromTxtFile(char *S);
BOOL __fastcall SaveToBinFile(char *S);
BOOL __fastcall SaveToTxtFile(char *S);
};

//--------------------------------------------------------------------------------------
#endif
