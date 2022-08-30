#include <vcl.h>
#pragma hdrstop

#include <Filectrl.hpp>

#include "Main.h"
#include "Ufft.h"
#include "UOptions.h"
#include "UComment.h"
#include "UNewExp.h"
#include "UNewSeries.h"
#include "UToolWin.h"
#include "Recorder.h"
#include "URecMenu.h"
#include "About.h"
#include "TeeThemes.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TeeEdit"
#pragma link "RzShellDialogs"
#pragma link "TeeTools"
#pragma link "RzButton"
#pragma link "RzPanel"
#pragma link "RzSpnEdt"
#pragma link "RzStatus"
#pragma link "TeeScroB"
#pragma link "RzEdit"
#pragma link "RzLabel"
#pragma link "RzCommon"
#pragma link "RzForms"
#pragma link "RzCmboBx"
#pragma link "RzLine"
#pragma link "JvThread"
#pragma link "mswheel"
#pragma resource "*.dfm"
#include <ActnMenus.hpp>
//---------------------------------------------------------------------------
#include "Cursor.h"
#include "CSignal.cpp"
#include "CDevice.cpp"
#include "TeeStore.hpp"
#include "Teeexport.hpp"

 CSeria Sign(0,1);
 Cursors* Crs;
 CRecData Rec;
 double TSr;
 TFastLineSeries *SArrI[1000];
 TFastLineSeries *SArrU[1000];
 String MainDir;
 TStringList* TempFile;
 TStringList* ConfFile;

 TStringList*SnConfFile;
 TStringList*PtConfFile;

 TStringList* RecFile;

 TStringList* SeriesList;

 String xStr;
 bool Record = false;
 bool Chk = false;
 bool DevReady = false;
 bool RecRecorder = false;
 int LineCount=0;
 AnsiString DCText;
 double Last = 100;
 double TCrt = 0;
 double xval;
 double DACValue = 0;
 bool GDACValue = False;
 double OldTime = 0;
 AnsiString NameSrs;
 AnsiString SPath;
 bool Cycle = false;
 int CycleCount = 0;

 int CountSeries=0;

 int SeriaNumber=0;

 double MinX, MaxX, Lx, Kx,
        MinY1,MaxY1,Ly1,Ky1,
        MinY2,MaxY2,Ly2,Ky2,
        q;
 double WCoef;
 BOOL TypeBinO=true;
 BOOL TypeBinS=true;
 AnsiString WorkDir,SeriaName;
 AnsiString MainCap;
 bool MDown=false;
 int ToDAC = 0;
 bool AppTerminate = false;
 int ValData=0;
 double I0=0;
 bool ValI0=true;
 int OutCount = 0;
 bool Wait = false;
 float **tmp;
 int xn = 500;
 int nTimes = 0;

 TSpeedTheme *SpeedThemeI;
 TSpeedTheme *SpeedThemeU;

 void __fastcall FixFName(AnsiString &S) {
  while (S.Pos(":")) S[S.Pos(":")]=';';
  while (S.Pos("|")) S[S.Pos("|")]='!';
  while (S.Pos("/")) S[S.Pos("/")]='(';
  while (S.Pos("\\")) S[S.Pos("\\")]=')';
  while (S.Pos("?")) S[S.Pos("?")]='$';
  while (S.Pos("*")) S[S.Pos("*")]='^';
  while (S.Pos("""")) S[S.Pos("""")]='`';
  while (S.Pos("<")) S[S.Pos("<")]='{';
  while (S.Pos(">")) S[S.Pos(">")]='}';
};

 struct SE{
   AnsiString Name;
   AnsiString Dir;
   AnsiString FName;
   int Ns;
   bool Modified;
        SE(){
          Name="";
          Dir="";
          FName="";
          Ns=0;
          Modified=false;
        };
   BOOL Opened(){if (Name=="") return false;
                               return true;};
   void Open(AnsiString FN){
     int F;
     FName=FN;
     Dir=ExtractFileDir(FN);
     F=FileOpen(FName,fmOpenRead);
     //Form1->CBSeries->Clear();

     int N; char* ch;
     FileRead(F,&N,sizeof(int));
     ch=new char[N+1];
     ch[N]=0;
     FileRead(F,ch,sizeof(char)*N);
     Name=ch;
     delete[] ch;
     FileRead(F,&Ns,sizeof(int));
     for(int i=0;i<Ns;i++){
       FileRead(F,&N,sizeof(int));
       ch=new char[N+1];
       ch[N]=0;
       FileRead(F,ch,sizeof(char)*N);
       //Form1->CBSeries->Items->Add(ch);
       delete[] ch;
     };
     //Form1->CBSeries->ItemIndex=0;
     FileClose(F);
     //AnsiString S=Form1->CBSeries->Items->Strings[0]+".bn";
     //FixFName(S);
     //Sign.FName=Dir+"\\"+S;
	 //Sign.LoadFromBinFile();
	 //Rec.RName=Dir+"\\recorder.bn";
     //Rec.RLoad();
     Form1->Caption=MainCap+" - "+Name;
   };

   void Close(){
     Form1->Caption=MainCap;

     //if (Name=="") return;
	 //if (Sign.Ni==0) Ns--;
	 //if (Ns<=0) return;

     if (!DirectoryExists(Dir)) CreateDir(Dir);
     //Sign.SaveToBinFile();
     Rec.RSave();
     Rec.Clear();
     int F=FileCreate(FName);
     int N;
     char* ch;
     N=Name.Length();
     FileWrite(F,&N,sizeof(N));

     ch=new char[N+1];
     StrCopy(ch,Name.c_str());
     FileWrite(F,ch,sizeof(char)*N);
     delete[] ch;

     FileWrite(F,&Ns,sizeof(Ns));
     for(int i=0;i<Ns;i++) {
       //N=Form1->CBSeries->Items->Strings[i].Length();
       FileWrite(F,&N,sizeof(N));
       ch=new char[N+1];
       //StrCopy(ch,Form1->CBSeries->Items->Strings[i].c_str());
       FileWrite(F,ch,sizeof(char)*N);
       delete[] ch;
     }
     FileClose(F);
   };

   BOOL New(AnsiString NM, AnsiString Dr){
     Close();
     Name=NM;
     Dir=Dr;
     Form1->Caption=MainCap+" - "+Name;
	 //FName=Dir+"\\inf.exp";
	 //Rec.RName=Dir+"\\recorder.bn";
     //Rec.Run();
     Ns=0;
     return true;
   };
 } xExp;

//---------------------------------------------------------------------------
 CDevice B181;
 TForm1 *Form1;

 AnsiString OldTxt;

//---------------------------------------------------------------------------

void __fastcall SetView() {
  q=15;

  Lx=MaxX-MinX;

  if (Form1->ScrollBarX->Max)
    Kx=(MaxX-MinX-Lx)/Form1->ScrollBarX->Max;
  else Kx=0;

  Form1->ScrollBarX->Position=Form1->ScrollBarX->Max/2;

  //Form1->ScrollBarX->SmallChange=(Lx/(MaxX-MinX))*Form1->ScrollBarX->Max/q;
  //Form1->ScrollBarX->LargeChange=(Lx/(MaxX-MinX))*Form1->ScrollBarX->Max/3;

  Ly1=MaxY1-MinY1;
  Ly2=MaxY2-MinY2;


  if (Form1->ScrollBarY1->Max)
    Ky1=(MaxY1-MinY1-Ly1)/Form1->ScrollBarY1->Max;
  else Ky1=0;

  //Form1->ScrollBarY1->Position=Form1->ScrollBarY1->Max/2;
  //Form1->ScrollBarY1->SmallChange=(Ly1/(MaxY1-MinY1))*Form1->ScrollBarY1->Max/q;
  //Form1->ScrollBarY1->LargeChange=(Ly1/(MaxY1-MinY1))*Form1->ScrollBarY1->Max/3;
//  Form1->Chart->Repaint();

  if (Form1->ScrollBarY2->Max)
    Ky2=(MaxY2-MinY2-Ly2)/Form1->ScrollBarY2->Max;
  else Ky2=0;

  //Form1->ScrollBarY2->Position=Form1->ScrollBarY2->Max/2;
  //Form1->ScrollBarY2->SmallChange=(Ly2/(MaxY2-MinY2))*Form1->ScrollBarY2->Max/q;
  //Form1->ScrollBarY2->LargeChange=(Ly2/(MaxY2-MinY2))*Form1->ScrollBarY2->Max/3;
//  Form1->Chart1->Repaint();
};

double InttLineSer(TChartSeries* xSeries, int FirstIndex, int LastIndex, Double XValue)
{
 int Index;
 Double dx,dy;

  for(Index = FirstIndex; Index <= LastIndex; Index++)
	if((xSeries->XValues->Value[Index]) > XValue) break;

  if (Index < 1)
  {
	Index= 1;
  }
  else
  {
	if (xSeries->Count() <= Index)
	{
	  Index = xSeries->Count() - 1;
	}
  }

  dx= xSeries->XValues->Value[Index] - xSeries->XValues->Value[Index-1];
  dy= xSeries->YValues->Value[Index] - xSeries->YValues->Value[Index-1];

  if (dx != 0)
  {
	return dy * (XValue - xSeries->XValues->Value[Index-1]) / dx + xSeries->YValues->Value[Index-1];
  }
    else return 0;
 }

double InterpolateLineSeries(TChartSeries* Series, double XValue)
{
  return InttLineSer(Series, Series->FirstDisplayedIndex(), Series->LastValueIndex, XValue);
};

//---------------------------------------------------------------------------
void __fastcall SetMinMax() {
  //MinX=Sign.t0;
  //MaxX=MinX+Sign.Nt*Sign.dt;
  /*  MaxY=Sign[0][0];
  MinY=Sign[0][0];
  for(int i=0;i<Sign.Number;i++)
    for(int j=0;j<Sign.Length;j++) {
       if(MaxY<Sign[i][j]) MaxY=Sign[i][j];
       if(MinY>Sign[i][j]) MinY=Sign[i][j];
    }*/
  MinY1=PConf->ADCMin[0];
  MaxY1=PConf->ADCMax[0];
  MinY2=PConf->ADCMin[1];
  MaxY2=PConf->ADCMax[1];

  Form1->Chart->BottomAxis->Minimum=MinX;
  Form1->Chart->BottomAxis->Maximum=MaxX;
  Form1->Chart1->BottomAxis->Minimum=MinX;
  Form1->Chart1->BottomAxis->Maximum=MaxX;
  Form1->Chart->LeftAxis->Minimum=MinY1;
  Form1->Chart->LeftAxis->Maximum=MaxY1;
  if (MinY2>Form1->Chart1->LeftAxis->Maximum) {
    Form1->Chart1->LeftAxis->Minimum=MinY2;
    Form1->Chart1->LeftAxis->Maximum=MaxY2;
  }
  else {
    Form1->Chart1->LeftAxis->Maximum=MaxY2;
    Form1->Chart1->LeftAxis->Minimum=MinY2;
  };

};
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OnClose(TWMClose& a)
{
   if (MessageDlg("Вы действительно хотите выйти?",
			   mtConfirmation,
			   TMsgDlgButtons() << mbYes << mbNo,
			   0)==6)
   {
	 Close();
   }

  a.Result=0;
}

//---------------------------------------------------------------------------
//    Открытие файла
//---------------------------------------------------------------------------
void __fastcall TForm1::Menu_OpenClick(TObject *Sender)
{

  if (OpenDialog1->Execute()){

    BOOL k;
    int Tm=Time();

/*    if (TypeBinO)*/ ///k=Sign.LoadFromBinFile(/*OpenDialog1->FileName.c_str() */);
//    else k=Sign.LoadFromTxtFile(OpenDialog1->FileName.c_str() );

    if (k) {
      SetMinMax();
      SetView();
      //CBSeries->Text=ExtractFileName(OpenDialog1->FileName);
    }
    else ShowMessage("Файл не удается прочесть");
    Tm=Time()-Tm;
    ShowMessage("Время чтения из файла "+IntToStr(Tm)+","+IntToStr((int)0));
  }
}

//---------------------------------------------------------------------------
//    Сохранение файла
//---------------------------------------------------------------------------
void __fastcall TForm1::Menu_Save_AsClick(TObject *Sender)
{
	// if (Name=="") return;
	// if ((xExp.Ns<=0)||((xExp.Ns==1)&&(Sign.Ni==0))) return;

	 if (!DirectoryExists(xExp.Dir)) CreateDir(xExp.Dir);
     //if (!Sign.SaveToBinFile()) ShowMessage("Не удалось сохранить файл");


	 int F=FileCreate(xExp.FName);
     int N;
     char* ch;
     N=Name.Length();
     FileWrite(F,&N,sizeof(N));

     ch=new char[N+1];
     //StrCopy(ch,Name.c_str());
     FileWrite(F,ch,sizeof(char)*N);
     delete[] ch;

	 int NS=xExp.Ns;
     //if (Sign.Ni==0) NS--;
     FileWrite(F,&NS,sizeof(NS));
     for(int i=0;i<NS;i++) {
       //N=Form1->CBSeries->Items->Strings[i].Length();
       FileWrite(F,&N,sizeof(N));
       ch=new char[N+1];
       //StrCopy(ch,Form1->CBSeries->Items->Strings[i].c_str());
       FileWrite(F,ch,sizeof(char)*N);
       delete[] ch;
     }
     FileClose(F);
}


//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  WorkDir=GetCurrentDir();

  PConf=new CConf;
  //Sign.Init(Chart,Chart1,Series3,Series4,CheckListBox1);
  //Rec.Init(ChartI,ChartU,Series1,Series2,ScrollBar1,ScrollBarI,ScrollBarU,PanelT,Splitter0);
  B181.Config=PConf;

  MainCap=Form1->Caption;
  xExp.Name="";
  xExp.Dir="";

  MenuResetClick(MenuReset);

  MinX=Chart->BottomAxis->Minimum;//0;//
  MaxX=Chart->BottomAxis->Maximum;//1000;

  //MinY1=Chart->LeftAxis->Minimum;//0;//
  //MaxY1=Chart->LeftAxis->Maximum;//15000;//
  //MinY2=Chart1->LeftAxis->Minimum;//0;//
  //MaxY2=Chart1->LeftAxis->Maximum;//15000;//
  //SetView();
  WCoef=0.5;
  CheckListBox1->Clear();
  Panel2Resize(Panel2);
  OpenDialog1->InitialDir=WorkDir;
  SaveDialog1->InitialDir=WorkDir;


  //UpDown1->Position=PConf->NPulse;
  //Edit1->Text=FloatToStrF(PConf->A,ffFixed,6,1)+" "+PConf->DACValue[0];
  //Edit2->Text=FloatToStrF(PConf->dA,ffFixed,6,1)+" "+PConf->DACValue[0];

  //Crs=new Cursors(Chart,Chart1,&Sign,PConf,&I0/*,Edit4*/);
  //Edit4->Text=FloatToStrF(I0,ffFixed,6,4)+" "+PConf->ADCValue[0];

  TempFile = new TStringList;
  ConfFile = new TStringList;
  RecFile  = new TStringList;

  SnConfFile  = new TStringList;
  PtConfFile  = new TStringList;

  SeriesList  = new TStringList;

  SpeedThemeI = new TSpeedTheme(ChartI);
  SpeedThemeI->Apply();

  SpeedThemeU = new TSpeedTheme(ChartU);
  SpeedThemeU->Apply();

  SeriesI->DrawAllPoints = false;
  SeriesU->DrawAllPoints = false;

  tmp=new float*[2];
  tmp[0]=new float[xn];
  tmp[1]=new float[xn];

  HANDLE ProcessHandle, ThreadHandle;

  DWORD ProcessID = GetCurrentProcessId();
  ProcessHandle = OpenProcess(PROCESS_ALL_ACCESS,false,ProcessID);
  SetPriorityClass(ProcessHandle, HIGH_PRIORITY_CLASS);

  ThreadHandle = GetCurrentThread();
  SetThreadPriority(ThreadHandle, THREAD_PRIORITY_HIGHEST);

  RzPropertyStore1->Load();
}

//---------------------------------------------------------------------------
//  Выгрузка библиотеки при закрытии окна
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{ void * a;
  //AppTerminate = true;

  //while (0) Sleep(10);


  if (Record)
	{
	  ConfFile->Add(xStr + (Char)(9) + "Series" + IntToStr(CountSeries-1) + ".str");

	  TempFile->SaveToFile(MainDir + "\\Series" + IntToStr(CountSeries-1) + ".str");

	  ConfFile->SaveToFile(MainDir + "\\Exp.exd");
	}

	if (RecRecorder)
	{
	  RecFile->SaveToFile(MainDir + "\\Rec.str");
	}

  B181.CloseDevice();

  RzPropertyStore1->Save();

  TempFile   ->Free();
  ConfFile   ->Free();
  RecFile    ->Free();
  PtConfFile ->Free();
  SnConfFile ->Free();
  SeriesList ->Free();

  SpeedThemeI->Free();
  SpeedThemeU->Free();

  delete[] tmp[0];
  delete[] tmp[1];
  delete[] tmp;
}

//---------------------------------------------------------------------------
//  Окно настроек
//---------------------------------------------------------------------------
void __fastcall TForm1::Menu_OptionsClick(TObject *Sender)
{
  FOptions->ShowModal();
}



//---------------------------------------------------------------------------
// Запуск измерений
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonRunClick(TObject *Sender)
{

    if (ValData) {
      AnsiString S="Неправильно введены данные:\n";
      if (ValData&2) S+="Амплитуда\n";
      if (ValData&4) S+="Изменение амплитуды\n";
      if (ValData&1) S+="Количество импульсов\n";
      ShowMessage(S);
      return;
    }

    //PConf->NPulse=StrToInt(Edit3->Text);




    float *tmp_in;
    float **tmp_out;
    float **tmp_data;

    float C;
    BOOL f=false;
	//bool Tmr=Timer1->Enabled;
    //Timer1->Enabled=false;

    //if (Sign.Ni==0) f=true;


    //--------------------------------------------------------

    PConf->ADCLen=256;
    PConf->DACLen=PConf->ADCLen;    //длинна импульса

    tmp_out=new float*[2];
    tmp_out[0]=new float[PConf->ADCLen];
    tmp_out[1]=new float[PConf->ADCLen];

    for(int i=0;i<PConf->DACLen;i++)
      tmp_out[0][i]=0;

    B181.ConfigCmn();
    B181.ConfigADC();
    B181.ConfigDAC();

    B181.WriteToDAC(tmp_out[0]);
    B181.Reset();
    B181.Run();
    while(!(4&B181.ReadStatus()));
    B181.ReadFromADC(tmp_out);

    C=0;
    for(int i =0;i<PConf->ADCLen;i++)
      C+=tmp_out[1][i];
    C/=PConf->ADCLen;

    delete[] tmp_out[1];
    delete[] tmp_out[0];
    delete[] tmp_out;
    //--------------------------------------------------------



    int   N = PConf->NPulse;
    int  G0 = PConf->Gen0;
    int G0M = PConf->Gen0Mul;

    PConf->dt=double(G0)*20e-6*G0M;



    int  Nu = PConf->t/PConf->dt * PConf->Gen0Mul;
    int  No = (PConf->T-PConf->t)/PConf->dt * PConf->Gen0Mul;
    int NtM = (PConf->tp+PConf->tu+PConf->tf)/PConf->dt;
    int NpM = PConf->tp/PConf->dt;

    int N1=65536/(2*(Nu+No));
    if (N1==0) {
      ShowMessage("Слишком длинный сигнал");
      return;
    }

    float A=PConf->A;
    int *b;
    int n=(N1+N-1)/N1;
    b=new int[n];
    for(int i1=0;i1<n-1;i1++)
      b[i1]=N1;
    b[n-1]=N-(n-1)*N1;


//-------------------------------------------------------------------

    tmp_in=new float[b[0]*(Nu+No)];

    tmp_out=new float*[2];

	for(int i=0;i<2;i++)
	  tmp_out[i]=new float[(Nu+No)*b[0]];

    tmp_data=new float*[N*2];
	for(int i=0;i<N*2;i++)
	  tmp_data[i]=new float[NtM];

	for(int i1=0;i1<n;i1++)
	{

	  PConf->DACLen=(Nu+No)*b[i1];
	  PConf->ADCLen=PConf->DACLen;


    int i=0,L=No/2;
    do {
      for(;i<L;i++) tmp_in[i]=0;
      if (L==PConf->DACLen) break;
      L+=Nu;
      for(;i<L;i++) tmp_in[i]=(A-C)/PConf->DACCoeff[0];
      L+=No;
      if (L>PConf->DACLen) L=PConf->DACLen;
      A+=PConf->dA;
    } while (true);

    B181.ConfigCmn();
    B181.ConfigADC();
    B181.ConfigDAC();

    B181.WriteToDAC(tmp_in);

/*--------*/   //Rec.AddLine(double(Time()));

    B181.Reset();
    B181.Run();
    while(!(4&B181.ReadStatus()));

    B181.ReadFromADC(tmp_out);


    int k;
    for(int i=0;i<b[i1]*2;i++) {
      k=(i/2)*(Nu+No)+(No/2-NpM*G0M);
      for(int j=0;j<NtM;j++) {
        tmp_data[i+2*b[0]*i1][j]=tmp_out[i%2][k];
        k+=G0M;
      };
    }
	}


    delete[] tmp_in;
    for(int i=0;i<2;i++) delete[] tmp_out[i];
    delete[] tmp_out;
    delete[] b;
    if (f) {
	  //Sign.SetLen(NtM);
	  //Sign.dt=PConf->dt;
	  //Sign.t0=-PConf->tp;
      SetMinMax();
      SetView();
    }

    AnsiString** Names;
    Names=new AnsiString*[N];

    A=PConf->A;
    for(int i=0;i<N;i++) {
      Names[i]=new AnsiString;
      *Names[i]=FloatToStr(A)+" "+PConf->ADCValue[1];
      A+=PConf->dA;
    }

    //Sign.Add(N*2,tmp_data,Names);

    //Edit1->Text=FloatToStr(PConf->A)+" "+PConf->DACValue[0];

    //Timer1->Enabled=Tmr;
};


//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBarXScroll(TObject *Sender,
      TScrollCode ScrollCode, int &ScrollPos)
{
  if ((Chart->BottomAxis->Maximum)<(MinX+Kx*ScrollPos)) {
    Chart1->BottomAxis->Maximum=MinX+Kx*ScrollPos+Lx;
    Chart1->BottomAxis->Minimum=MinX+Kx*ScrollPos;
    Chart->BottomAxis->Maximum=MinX+Kx*ScrollPos+Lx;
    Chart->BottomAxis->Minimum=MinX+Kx*ScrollPos;
  }
  else {
    Chart->BottomAxis->Minimum=MinX+Kx*ScrollPos;
    Chart->BottomAxis->Maximum=MinX+Kx*ScrollPos+Lx;
    Chart1->BottomAxis->Minimum=MinX+Kx*ScrollPos;
    Chart1->BottomAxis->Maximum=MinX+Kx*ScrollPos+Lx;
  }
}

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBarY1Scroll(TObject *Sender,
      TScrollCode ScrollCode, int &ScrollPos)
{

   int p=ScrollBarY1->Max-ScrollPos;

  if ((Chart->LeftAxis->Maximum)<(MinY1+Ky1*p)) {
    Chart->LeftAxis->Maximum=MinY1+Ky1*p+Ly1;
    Chart->LeftAxis->Minimum=MinY1+Ky1*p;
  }
  else {
    Chart->LeftAxis->Minimum=MinY1+Ky1*p;
    Chart->LeftAxis->Maximum=MinY1+Ky1*p+Ly1;
  }
}

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
void __fastcall TForm1::U(TObject *Sender, TUDBtnType Button)
{
//  btNext refers to the Up or Right arrow, and btPrev refers to the Down or Left
  //if (Button==1) Lx*=1.5;
  //else if (Button==0) Lx/=1.5;

//  if (Lx>MaxX-MinX) Lx=MaxX-MinX;
  //ScrollBarX->SmallChange=(Lx/(MaxX-MinX))*ScrollBarX->Max/q;

  //if (ScrollBarX->Max)
	//Kx=(MaxX-MinX-Lx)/ScrollBarX->Max;
  //else Kx=0;
  //if ((Chart->BottomAxis->Maximum)<(MinX+Kx*ScrollBarX->Position)) {
	//Chart->BottomAxis->Maximum=MinX+Kx*ScrollBarX->Position+Lx;
	//Chart->BottomAxis->Minimum=MinX+Kx*ScrollBarX->Position;
	//Chart1->BottomAxis->Maximum=MinX+Kx*ScrollBarX->Position+Lx;
	//Chart1->BottomAxis->Minimum=MinX+Kx*ScrollBarX->Position;
  //}
  //else {
	//Chart->BottomAxis->Minimum=MinX+Kx*ScrollBarX->Position;
	//Chart->BottomAxis->Maximum=MinX+Kx*ScrollBarX->Position+Lx;
	//Chart1->BottomAxis->Minimum=MinX+Kx*ScrollBarX->Position;
	//Chart1->BottomAxis->Maximum=MinX+Kx*ScrollBarX->Position+Lx;
  //}
  //ScrollBarX->Repaint();
}

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
void __fastcall TForm1::UpDownY1Click(TObject *Sender, TUDBtnType Button)
{
   if (Button==1)
   {
	 Chart->Zoom->Direction=tzdVertical;
	 Chart->ZoomPercent(95);
   }
   else
   {
     Chart->Zoom->Direction=tzdVertical;
	 Chart->ZoomPercent(105);
   }

   Chart->Zoom->Direction=tzdBoth;

  //if (Button==1) Ly1*=1.5;
  //else if (Button==0) Ly1/=1.5;

 // if (Ly>MaxY-MinY) Ly=MaxY-MinY;

  //ScrollBarY1->SmallChange=(Ly1/(MaxY1-MinY1))*ScrollBarY1->Max/q;
  //int p=ScrollBarY1->Max-ScrollBarY1->Position;

  //if (ScrollBarY1->Max)
	//Ky1=(MaxY1-MinY1-Ly1)/ScrollBarY1->Max;
  //else Ky1=0;
  //if ((Chart->LeftAxis->Maximum)<(MinY1+Ky1*p)) {
	//Chart->LeftAxis->Maximum=MinY1+Ky1*p+Ly1;
	//Chart->LeftAxis->Minimum=MinY1+Ky1*p;
  //}
  //else {
	//Chart->LeftAxis->Minimum=MinY1+Ky1*p;
	//Chart->LeftAxis->Maximum=MinY1+Ky1*p+Ly1;
  //}

}


void __fastcall TForm1::UpDownY2Click(TObject *Sender, TUDBtnType Button)
{
   if (Button==1)
   {
	 Chart1->Zoom->Direction=tzdVertical;
	 Chart1->ZoomPercent(95);
   }
   else
   {
	 Chart1->Zoom->Direction=tzdVertical;
	 Chart1->ZoomPercent(105);
   }

   Chart1->Zoom->Direction=tzdBoth;
  //if (Button==1) Ly2*=1.5;
  //else if (Button==0) Ly2/=1.5;

 // if (Ly>MaxY-MinY) Ly=MaxY-MinY;

  //ScrollBarY2->SmallChange=(Ly2/(MaxY2-MinY2))*ScrollBarY2->Max/q;
  //int p=ScrollBarY2->Max-ScrollBarY2->Position;

  //if (ScrollBarY2->Max)
	//Ky2=(MaxY2-MinY2-Ly2)/ScrollBarY2->Max;
  //else Ky2=0;
  //if ((Chart1->LeftAxis->Maximum)<(MinY2+Ky2*p)) {
	//Chart1->LeftAxis->Maximum=MinY2+Ky2*p+Ly2;
	//Chart1->LeftAxis->Minimum=MinY2+Ky2*p;
  //}
  //else {
	//Chart1->LeftAxis->Minimum=MinY2+Ky2*p;
	//Chart1->LeftAxis->Maximum=MinY2+Ky2*p+Ly2;
  //}

}

//---------------------------------------------------------------------------
// Настройка системы
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonOptionClick(TObject *Sender)
{
 FOptions->ShowModal();
}


void __fastcall TForm1::OpenDialog1TypeChange(TObject *Sender)
{
  TypeBinO=!TypeBinO;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SaveDialog1TypeChange(TObject *Sender)
{
  TypeBinS=!TypeBinS;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckListBox1ClickCheck(TObject *Sender)
{
  bool Ts = true;

  for(int i=0;i<CheckListBox1->Count;i++)
  {
	//Sign.Series[i*2]->Active=CheckListBox1->Checked[i];
	//Sign.Series[i*2+1]->Active=CheckListBox1->Checked[i];

	SArrI[i]->Active=CheckListBox1->Checked[i];
	SArrU[i]->Active=CheckListBox1->Checked[i];

	if (CheckListBox1->Checked[i] == false)
	{
	  Ts = false;
	}
  }

  if (Ts != CheckBox2->Checked)
  {
    Chk = true;
	CheckBox2->Checked = Ts;
  }

}
//---------------------------------------------------------------------------



/*
void __fastcall TForm1::Menu_ExitClick(TObject *Sender)
{
  int c=CheckListBox1->ItemIndex;
  if (c>=0) Sign.Delete(c);
  else ShowMessage("Выберите сигнал");

} */
//---------------------------------------------------------------------------
void __fastcall TForm1::ClearSeria()
{
  PtConfFile->Clear();
  SnConfFile->Clear();

  ConfFile->Clear();
  TempFile->Clear();

  CheckListBox1->Clear();

  for (int i = 0; i < CountSeries; i++)
  {
    SArrI[i]->ParentChart=NULL;
	SArrU[i]->ParentChart=NULL;

	SArrI[i]->Free();
	SArrU[i]->Free();
  }

  CountSeries=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Menu_NewClick(TObject *Sender)
{
  NewExp->EditName->Text="Эксперимент от "+DateTimeToStr(Now());

  if (NewExp->ShowModal()==mrOk) {

	if (Record)
	{
	  ConfFile->Add(xStr + (Char)(9) + "Series" + IntToStr(CountSeries-1) + ".str");

	  TempFile->SaveToFile(MainDir + "\\Series" + IntToStr(CountSeries-1) + ".str");
	  TempFile->Clear();

	  ConfFile->SaveToFile(MainDir + "\\Exp.exd");
	}

	ClearSeria();
	SeriesList->Clear();

	if (RecRecorder)
	{
	  RecFile->SaveToFile(MainDir + "\\Rec.str");
	  RecFile->Clear();
	}

    SeriesI->Clear();
    SeriesU->Clear();

	ChartI->BottomAxis->SetMinMax(0, 100);
    ChartU->BottomAxis->SetMinMax(0, 100);

	RecRecorder=true;

    AnsiString NM,DR;
    NM=NewExp->EditName->Text;
	DR=NM;
	FixFName(DR);
	DR=WorkDir+"\\"+DR;
	//xExp.New(NM,DR);

	RzToolButton7->Enabled=True;

	MainDir=DR;

	TCrt=double(Time());

	if (!DirectoryExists(MainDir)) CreateDir(MainDir);

	//Sign.Clear();

	//CBSeries->Clear();//Text="Серия "+Time()+" "+FloatToStr(PConf->T)+" мс";

	Menu_NewSeriaClick(NULL);

	//ShowMessage(MainDir);

	if(DevReady)
	{
	  B181.WriteToDACDirect(0);
	}

	BtnNextRecord->Enabled = true;
	N2->Enabled = true;
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CheckListBox1Click(TObject *Sender)
{
  int i;
  int c=CheckListBox1->ItemIndex;

  if (c>=0) //Sign.SetSelected(c);
  {
	for (i = 0; i < CheckListBox1->Count; i++)
	{
	  if (CheckListBox1->Selected[i])
	  {
		SArrI[i]->SeriesColor= (TColor)clFuchsia;
		SArrU[i]->SeriesColor= (TColor)clFuchsia;
	  }
	  else
	  {
		SArrI[i]->SeriesColor= (TColor)clRed;
		SArrU[i]->SeriesColor= (TColor)clBlue;
      }
	}
  }
  //Sign.Refresh(c);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Panel1Resize(TObject *Sender)
{
  Chart->Height=Panel1->Height*WCoef;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Splitter1Moved(TObject *Sender)
{
  double c=Chart->Height;
  WCoef=c/Panel1->Height;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::ChartMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  //if((Sender==Chart)&&(ToolButton9))MDown=true;
  //Crs->Activate(Button,Sender,X,Y);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Panel3Resize(TObject *Sender)
{
  UpDownX->Height=16;
  UpDownX->Width=16;
  UpDownX->Top=Panel3->Height-UpDownX->Height-2;
  UpDownX->Left=2;

  ScrollBarX->Height=16;
  ScrollBarX->Width=Chart->Width;
  ScrollBarX->Top=Panel3->Height-ScrollBarX->Height-2;
  ScrollBarX->Left=UpDownX->Width+4;

  Panel1->Top=1;
  Panel1->Left=20;
  Panel1->Height=Panel3->Height-20;
  Panel1->Width=Panel3->Width-Panel1->Left;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ChartResize(TObject *Sender)
{
  ScrollBarY1->Top=Chart->Top+2;
  ScrollBarY1->Height=Chart->Height-2;

  ScrollBarY2->Top=Chart->Top+Chart->Height+5;
  ScrollBarY2->Height=Chart1->Height-2;

  ScrollBarX->Width=Chart->Width-2;
  ScrollBarX->Left=Panel1->Left+1;

  UpDownY1->Top=Chart->Height/2-11;
  UpDownY1->Left=2;

  UpDownY2->Top=Chart1->Height/2-11;
  UpDownY2->Left=2;

  UpDown2->Top=Chart->Height-20;
  UpDown2->Left=2;

  UpDown1->Top=Chart1->Height-20;
  UpDown1->Left=2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBarY2Scroll(TObject *Sender,
      TScrollCode ScrollCode, int &ScrollPos)
{
   int p=ScrollBarY2->Max-ScrollPos;

  if ((Chart1->LeftAxis->Maximum)<(MinY2+Ky2*p)) {
    Chart1->LeftAxis->Maximum=MinY1+Ky2*p+Ly2;
    Chart1->LeftAxis->Minimum=MinY1+Ky2*p;
  }
  else {
    Chart1->LeftAxis->Minimum=MinY2+Ky2*p;
    Chart1->LeftAxis->Maximum=MinY2+Ky2*p+Ly2;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Menu_PrintClick(TObject *Sender)
{
  Chart->PrintLandscape();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ChartAfterDraw(TObject *Sender)
{
int xs, ys, i;

  if (LineTool->Active)
  {
	xs = Chart->Axes->Bottom->CalcXPosValue(xval);

	if (CheckListBox1->ItemIndex != -1)
	{
	//for (i = 0; i < Chart1.SeriesCount; i++)
	//{
	  ys = SArrI[CheckListBox1->ItemIndex]->GetVertAxis->CalcYPosValue(InterpolateLineSeries(SArrI[CheckListBox1->ItemIndex],xval));
	  Chart->Canvas->Brush->Color = (TColor)clFuchsia;//Chart1[i].Color;
	  Chart->Canvas->Ellipse(xs-4,ys-4,xs+4,ys+4);
	}
	//}
  }
}

//---------------------------------------------------------------------------
//                   Коментарий к эксперементу
//---------------------------------------------------------------------------
void __fastcall TForm1::Menu_CommentClick(TObject *Sender)
{
  AnsiString FComment=xExp.Dir+"\\comment.txt";

  Comment->Memo->Text="";
  if (FileExists(FComment))
    Comment->Memo->Lines->LoadFromFile(FComment);

  if (Comment->ShowModal()==mrOk) {
    if (!DirectoryExists(xExp.Dir)) CreateDir(xExp.Dir);
    Comment->Memo->Lines->SaveToFile(FComment);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel2Resize(TObject *Sender)
{
 int Width=Panel2->Width;
 //CBSeries->Width=Width;
 CheckListBox1->Width=Width;
 CheckListBox1->Top=112;
 CheckListBox1->Height=Panel2->Height-CheckListBox1->Top;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolCursClick(TObject *Sender)
{
  //if (ToolCross->Down||ToolLine->Down||ToolX->Down) {

                         //Chart->AllowPanning=pmNone;
   //                      Chart->AllowZoom=false;
						 //Chart1->AllowPanning=pmNone;
   //                      Chart1->AllowZoom=false;

/*                         ToolButton9->Down=false;
                         ToolButton9->Enabled=false;
						 Edit4->Enabled=false;
*/
  //   if(ToolCross->Down) Crs->SetType(1);
  //   if(ToolLine->Down)  Crs->SetType(2);
  //   if(ToolX->Down)     Crs->SetType(3);

//                         ToolWin->Visible=true;
  //}
  //else {
//                         ToolWin->Visible=false;
  //                       Chart->AllowPanning=pmBoth;
  //                       Chart->AllowZoom=true;
  //                       Chart1->AllowPanning=pmBoth;
  //                       Chart1->AllowZoom=true;

/*                         ToolButton9->Enabled=true;
*/
 //                        Crs->SetType(0);
  //};
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Menu_DeleteClick(TObject *Sender)
{
  int c=CheckListBox1->ItemIndex;
  //if (c>=0) Sign.Delete(c);
  //else ShowMessage("Выберите сигнал");

}

//---------------------------------------------------------------------------


void __fastcall TForm1::MenuResetClick(TObject *Sender)
{

  B181.CloseDevice();
  int c=B181.PrepareDevice();

  Timer1->Enabled=false;
  //AppTerminate=true;

  DevReady=true;

  switch (c) {
    case -1: ShowMessage("Прибор не обнаружен"); break;
    case -2: ShowMessage("Не удалось загрузить функцию"); break;
    case -3: ShowMessage("Не удалось загрузить ""b181.dll"""); break;
    case  1: ShowMessage("Не удается прочитать информацию из прибора"); break;
    case  2: ShowMessage("Не удалось загрузить функцию ""ReadFromEPROM"""); break;
    case  3: ShowMessage("Не удалось загрузить ""unilptx.dll"""); break;
	case  0: {  DevReady=true;
                //MenuReset->Enabled=false;
                //ToolButton6->Visible=false;
				Timer1->Enabled=true;

				//AppTerminate = false;
				//JvThread1->Execute(Application);

				ChartTool3->Active=true;
				ChartTool4->Active=true;
              };
  };
  if (c) {
    B181.CloseDevice();
	ChartTool3->Active=false;
    ChartTool4->Active=false;
    DevReady=false;
	//Timer1->Enabled=false;

	//AppTerminate = true;
  }
  Timer1->Enabled=true;

  //AppTerminate = false;
  //JvThread1->Execute(Application);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Menu_NewSeriaClick(TObject *Sender)
{
  int i=0;//CBSeries->ItemIndex;

  NewSeries->EditName->Text="Серия "+Time();
  if (NewSeries->ShowModal()==mrOk) {
	if (i>=0)
	{
      ClearSeria();

	  NameSrs = NewSeries->EditName->Text;
	  FixFName(NameSrs);

	  SPath = MainDir + "\\" + NameSrs;

	  if (!DirectoryExists(SPath)) CreateDir(SPath);

	  RzComboBox1->Add(NameSrs);
	  SeriesList ->Add(NameSrs);

	  SeriesList ->SaveToFile(MainDir + "\\Series.lst");

	  RzComboBox1->ItemIndex=SeriaNumber;
	  SeriaNumber++;

	  //if (Sign.Ni>0) {
		//if (!DirectoryExists(xExp.Dir)) CreateDir(xExp.Dir);
		//Sign.SaveToBinFile();
		//Sign.Clear();
      //}
	  //else {
        //CBSeries->Items->Delete(i);
		//xExp.Ns-=1;
      //}
	};
	//AnsiString NameSrs=NewSeries->EditName->Text;

	//Sign.Name=NameSrs;
	//FixFName(NameSrs);
    //Sign.FName=xExp.Dir+"\\"+NameSrs+".bn";

	//xExp.Ns+=1;
    //i=CBSeries->Items->Add(NewSeries->EditName->Text);
    //CBSeries->ItemIndex=i;
	//SeriaNumber++;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MenuClearClick(TObject *Sender)
{
  //Sign.Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CBSeriesChange(TObject *Sender)
{
  //Sign.SaveToBinFile();
  //AnsiString S=CBSeries->Text+".bn";
  //FixFName(S);
  //Sign.FName=xExp.Dir+"//"+S;
  //Sign.LoadFromBinFile();

  //SetMinMax();
  //SetView();
  //ChartI->Repaint();
  //ChartU->Repaint();

  //Sr.Name=CBSeries->Text
  //
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LoadSeria(AnsiString SerPath)
{
  String TmpStr;
  int i, k, p;
  double TmpTime;
  String Str;

  SPath = SerPath;

  if (!FileExists(AnsiString(SerPath + "\\Exp.exd"))) return;

  ConfFile->LoadFromFile(AnsiString(SerPath + "\\Exp.exd"));

  for (i = 0; i < ConfFile->Count; i++)
  {
	if (true)
	{
	  TmpStr = ConfFile->Strings[i];

	  Str =TmpStr.SubString(0, TmpStr.Pos((Char)(9)) - 1);
	  CheckListBox1->Items->Add(Str);
	  SnConfFile->Add(Str);
	  CheckListBox1->Checked[CountSeries]=True;

	  SArrI[CountSeries]= new TFastLineSeries(Chart);
	  SArrI[CountSeries]->Clear();
	  SArrI[CountSeries]->Color= (TColor)clRed;
	  SArrI[CountSeries]->ParentChart=Chart;
	  SArrI[CountSeries]->Active=False;

	  SArrU[CountSeries]= new TFastLineSeries(Chart1);
	  SArrU[CountSeries]->Clear();
	  SArrU[CountSeries]->Color= (TColor)clBlue;
	  SArrU[CountSeries]->ParentChart=Chart1;
	  SArrU[CountSeries]->Active=False;

	  TempFile->Clear();

	  Str = TmpStr.SubString(TmpStr.Pos((Char)(9)) + 1, TmpStr.Length());
	  PtConfFile->Add(Str);

	  TempFile->LoadFromFile(SerPath + "\\" + Str);
	  for (k = 0; k < TempFile->Count; k++)
	  {
		TmpStr=TempFile->Strings[k];

		p = TmpStr.Pos((Char)(9));
		TmpTime=StrToFloat(TmpStr.SubString(0, p - 1));

		TmpStr=TmpStr.SubString(p + 1, TmpStr.Length());

		SArrI[CountSeries]->AddXY(TmpTime, StrToFloat(TmpStr.SubString(0, TmpStr.Pos((Char)(9)) - 1)));

		SArrU[CountSeries]->AddXY(TmpTime, StrToFloat(TmpStr.SubString(TmpStr.Pos((Char)(9)) + 1, TmpStr.Length())));
	  }

	  SArrI[CountSeries]->Active=True;
	  SArrU[CountSeries]->Active=True;

	  CountSeries++;
	}
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N9Click(TObject *Sender)
{
  //OpenDialog1->InitialDir=WorkDir;
  //OpenDialog1->Filter="Данные эксперемента|*.exp";
  //if (OpenDialog1->Execute())
   //xExp.Open(OpenDialog1->FileName);
  //if (Sign.Ni) {
	//SetMinMax();
	//SetView();
  //};

  int i, k, p;
  String TmpStr;
  double TmpTime;

  FolderDialog1->SelectedPathName=WorkDir;
  if (FolderDialog1->Execute())
  {
    RecRecorder = false;

	ConfFile->Clear();
	CheckListBox1->Clear();

	for (i = 0; i < CountSeries; i++)
	{
	  SArrI[i]->Free();
	  SArrU[i]->Free();
	}

	CountSeries=0;

	MainDir=FolderDialog1->SelectedPathName;

	SeriesI->Clear();
    SeriesU->Clear();

	RecFile->Clear();

	RecFile->LoadFromFile(FolderDialog1->SelectedPathName + "\\Rec.str");
	for (k = 0; k < RecFile->Count; k++)
	{
	  TmpStr=RecFile->Strings[k];

	  p = TmpStr.Pos((Char)(9));
	  TmpTime=StrToFloat(TmpStr.SubString(0, p - 1));

	  TmpStr=TmpStr.SubString(p + 1, TmpStr.Length());

	  SeriesI->AddXY(TmpTime, StrToFloat(TmpStr.SubString(0, TmpStr.Pos((Char)(9)) - 1)));
	  SeriesU->AddXY(TmpTime, StrToFloat(TmpStr.SubString(TmpStr.Pos((Char)(9)) + 1, TmpStr.Length())));
	}

	RzToolButton7->Enabled = false;

	if (TmpTime > 100)
	{
	  ChartI->BottomAxis->SetMinMax(TmpTime - 100, TmpTime);
	  ChartU->BottomAxis->SetMinMax(TmpTime - 100, TmpTime);
	}

	SeriesList->Clear();
	RzComboBox1->Clear();

	SeriesList->LoadFromFile(FolderDialog1->SelectedPathName + "\\Series.lst");
	RzComboBox1->Items->Assign(SeriesList);

	RzComboBox1->ItemIndex=SeriesList->Count - 1;
	RzComboBox1Change(Sender);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Menu_FileClick(TObject *Sender)
{
  if (xExp.Name=="") {
	//N2->Enabled=false;
    Menu_Comment->Enabled=false;
  } else {
    //N2->Enabled=true;
    Menu_Comment->Enabled=true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ToolButton6Click(TObject *Sender)
{

    Rec.AddLine(double(Time()));

    if (ValData) {
      AnsiString S="Неправильно введены данные:\n";
      if (ValData&2) S+="Амплитуда\n";
      if (ValData&4) S+="Изменение амплитуды\n";
      if (ValData&1) S+="Количество импульсов\n";
      ShowMessage(S);
      return;
    }


    float **tmp;
    int T,t,t1,t2;
    BOOL k=false;

    //if (Sign.Ni==0) k=true;
    B181.Config=PConf;


    T=PConf->T/PConf->dt;
    t=PConf->t/PConf->dt;

    int m=0;
    for(int i=0;i<4;i++)
      if(PConf->ADCChanel[i]) m++;


    float A=PConf->A;

    tmp=new float*[PConf->NPulse*m];
    for(int i=0;i<PConf->NPulse*m;i++) {
      tmp[i]=new float[T];
      int j=0;
      for(;j<(T-t)/2;j++) tmp[i][j]=0;
      for(;j<(T+t)/2;j++) tmp[i][j]=A*(exp(-30*(double)(j-(T-t)/2)/t)+0.3);
      for(;j<T;j++) tmp[i][j]=0;

      if (i%2) A+=PConf->dA;
    }

	//Sign.SetLen(T);
    //Sign.dt=PConf->dt;
//    Sign.t0=-(PConf->T-PConf->t)/2;

    AnsiString** Names;
    Names=new AnsiString*[PConf->NPulse];
    A=PConf->A;
    for(int i=0;i<PConf->NPulse;i++) {
      Names[i]=new AnsiString;
      *Names[i]=FloatToStr(A)+" "+PConf->ADCValue[1];
      A+=PConf->dA;
    }
    //Sign.Add(PConf->NPulse*m,tmp,Names);

    if (k) {
      SetMinMax();
      SetView();
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Exit(TObject *Sender)
{
  //if(!(ValData&2)) Edit1->Text=FloatToStrF(PConf->A,ffFixed,6,1)+" "+PConf->DACValue[0];
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit3Exit(TObject *Sender)
{
  AnsiString S=((TEdit *)Sender)->Text;
  while(S.Pos(" ")) S.Delete(S.Pos(" "),1);
  int Number;
  BOOL k=false;
  try
  {
    Number=StrToInt(S);
  }
  catch(EConvertError&)
  {
    k=true;
  }
  if ((!k)&&(Number>0)&&(Number<=100)) {
    ((TEdit *)Sender)->Text=S;
    //UpDown1->Position=Number;
    PConf->NPulse=Number;
    ValData=true;
    return;
  }
  ValData=false;
  ((TEdit *)Sender)->Text=OldTxt;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N10Click(TObject *Sender)
{
  xExp.Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::fft1Click(TObject *Sender)
{
  int c=CheckListBox1->ItemIndex;
  if (c<0) {
    ShowMessage("Выберите сигнал");
    return;
  }
  //Form2->D=Sign[c*2];
  //Form2->N=Sign.Nt;
  //Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
   //PConf->NPulse=StrToInt(Edit3->Text);
   if (Button==1)
   {
	 Chart1->Zoom->Direction=tzdHorizontal;
	 Chart1->ZoomPercent(95);
   }
   else
   {
	 Chart1->Zoom->Direction=tzdHorizontal;
	 Chart1->ZoomPercent(105);
   }

   Chart1->Zoom->Direction=tzdBoth;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	double xTime;

	if (Wait) return;

	Wait = true;

    int  G0 = PConf->Gen0;
	//int n=500;

	float I=0,U=0;
	int Srt, St;

	Srt=GetTickCount();

	if(DevReady)
	{
	  PConf->Gen0=500;
	  PConf->ADCLen=xn;

	  B181.ConfigCmn();
	  B181.ConfigADC();

	  B181.Reset(1);
	  B181.Run(1);

	  do
	  {
		nTimes++;
		Sleep(1);
	  }
	  while(!(4&B181.ReadStatus()) && (nTimes < 100));

	  Wait = false;

	  if (nTimes < 100)
	  {
		B181.ReadFromADC(tmp);
	  }
	  else
	  {
		nTimes = 0;
		return;
	  }

	  nTimes = 0;
	  St=GetTickCount();
	  RzStatusPane1->Caption=IntToStr(St - Srt);

	  for(int i=0;i<xn;i++) {
	   I+=tmp[0][i];
	   U+=tmp[1][i];
	}
	I/=xn;
    U/=xn;
  }
  else {
    static c=0;
    I=U=c;
    c++;
	c=c%200;

	Wait = false;
  }

	PConf->Gen0=G0;

	ChartTool3->Text="  " + FloatToStrF(I,ffFixed,6,4) + " "+PConf->ADCValue[0];
	ChartTool4->Text="  " + FloatToStrF(U,ffFixed,5,1) + " "+PConf->ADCValue[1];

	SeriesI->Active=True;
	SeriesU->Active=True;

    if (Record)
	{
      xTime =(double(Time())-TSr)*24*60*60;

	  SArrI[CountSeries-1]->AddXY(xTime, I);
	  SArrU[CountSeries-1]->AddXY(xTime, U);

	  TempFile->Add(FloatToStrF(xTime, ffFixed, 6,3) + (Char)(9) +
					FloatToStrF(I, ffFixed, 7,5) + (Char)(9) +
				    FloatToStrF(U, ffFixed, 6,3));

	  if (Cycle)
	  {
		RzToolButton7->Caption="Rec " +
					   FloatToStrF(xTime, ffFixed, 6,1) +
					   " (" +
					   IntToStr(RzSpinEdit1->IntValue - CycleCount) +
					   "/" +
					   IntToStr(RzSpinEdit1->IntValue) +
					   ")";
	  }
	  else
	  {
		RzToolButton7->Caption="Rec " + FloatToStrF(xTime, ffFixed, 6,1);
	  }

	  if (RzNumericEdit1->IntValue > xTime)
	  {
		RzNumericEdit1->Enabled=false;
		if (Cycle) RzNumericEdit4->Enabled=true;
	  }
	  else
	  {
		OldTime = RzNumericEdit1->IntValue;
		RzNumericEdit1->Enabled=true;

		if ((RzNumericEdit2->IntValue + OldTime) > xTime)
		{
		  RzNumericEdit2->Enabled=false;
		  RzNumericEdit3->Enabled=false;

		  if (!GDACValue)
		  {
			DACValue = ToDAC - U;
			GDACValue = true;

			if(DevReady)
			{
			  B181.WriteToDACDirect(DACValue/PConf->DACCoeff[0]);
            }
		  }
		}
		else
		{
		  RzNumericEdit2->Enabled=true;
		  RzNumericEdit3->Enabled=true;
		  RzNumericEdit4->Enabled=false;

		  DACValue = 0;

		  if (GDACValue)
		  {
            if(DevReady)
			{
			  B181.WriteToDACDirect(0);
			}
            GDACValue = false;
		  }

		  if (((RzNumericEdit1->IntValue +
				RzNumericEdit2->IntValue +
				RzNumericEdit4->IntValue) < xTime) && Cycle)
		  {
			if (CycleCount > 0)
			{
              CycleCount--;

			  StopRec();
			  StartRec();
			  //RzToolButton7Click(Sender);
			  //RzToolButton7Click(Sender);

			  ToDAC = ToDAC + RzNumericEdit5->IntValue;
			}
			else
			{
			   RzToolButton7Click(Sender);
			}

		  }
		  else
		  {

		  }
		}
      }
	}

	if (RecRecorder)
	{
      xTime =(double(Time())-TCrt)*24*60*60;

      RecFile->Add(FloatToStrF(xTime, ffFixed, 6,2) + (Char)(9) +
				   FloatToStrF(I, ffFixed, 7,4) + (Char)(9) +
				   FloatToStrF(U, ffFixed, 6,1));

	  SeriesI->AddXY(xTime, I);
	  SeriesU->AddXY(xTime, U);

	  if (xTime > 100)
	  {
		if (1)//OutCount == 10)
		{
          ChartI->BottomAxis->SetMinMax(ChartI->BottomAxis->Minimum + (xTime - Last),
									    ChartI->BottomAxis->Maximum + (xTime - Last));

		  ChartU->BottomAxis->SetMinMax(ChartU->BottomAxis->Minimum + (xTime - Last),
										ChartU->BottomAxis->Maximum + (xTime - Last));

		  Last=xTime;

		  OutCount = 0;
		}
        //OutCount++;
	  }
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
/*  SetMinMax();
  SetView();
*/}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit3Change(TObject *Sender)
{
 int c;
 try {
   //c=StrToInt(Edit3->Text);
 }
 catch(EConvertError&){
   //Edit3->Font->Color=clRed;
   ValData=ValData|1;
   return;
 };
 if ((c<1)||(c>100)) {
   //Edit3->Font->Color=clRed;
   ValData=ValData|1;
 }
 else {
   //Edit3->Font->Color=clWindowText;
   ValData=ValData&(0xFF-1);
   PConf->NPulse=c;
 }
 // ShowMessage("Изменения в окне Edit3:\n"+Edit3->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EditChange(TObject *Sender)
{
  AnsiString S=((TEdit *)Sender)->Text;
  AnsiString Val=PConf->DACValue[0];
  int c=S.AnsiPos(Val);
  if(c) S.Delete(c,Val.Length());
  while(S.Pos(" ")) S.Delete(S.Pos(" "),1);
  c=S.Pos(".");
  if (c) S[c]=DecimalSeparator;
  c=S.Pos(",");
  if (c) S[c]=DecimalSeparator;


  float Number;
  try
  {
    Number=StrToFloat(S);
  }
  catch(EConvertError&)
  {
    ((TEdit *)Sender)->Font->Color=clRed;
	//if(Sender==Edit1) ValData=ValData|2;
	//else ValData=ValData|4;
    return;
  }
  ((TEdit *)Sender)->Font->Color=clWindowText;
  //if(Sender==Edit1) {
	//ValData=ValData&(0xF-2);
	//PConf->A=Number;
  //}
 // else {
	//ValData=ValData&(0xF-4);
	//PConf->dA=Number;
  //}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Exit(TObject *Sender)
{
  //if(!(ValData&4)) Edit2->Text=FloatToStrF(PConf->dA,ffFixed,6,1)+" "+PConf->DACValue[0];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{
  //int c=CheckListBox1->ItemIndex;
  //if (c>=0) {
	//c*=2;
	//float s[16];
	//for(int k=0;k<2;k++) {
	  //for(int i=0;i<16;i++)
		//s[i]=Sign[c+k][i];
	  //for(int i=8;i<Sign.Nt-8;i++){
		//Sign[c+k][i]=0;
		//for(int j=0;j<16;j++)
		  //Sign.Data[c+k][i]+=s[j];
		//Sign[c+k][i]/=16;
	  //s[(i-8)%16]=Sign[c+k][i+8];
	  //};
	//};
	//Sign.RefreshN(c);
  //}   //Sign.Delete(c);
  //else ShowMessage("Выберите сигнал");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::p(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
   //MDown=false;
   //if (ToolButton9->Down) {
	 //int ky=6;
	 //double Dy=Chart->Height;
	 //double dy=Dy*Chart->MarginBottom*0.01+Chart->BottomAxis->LabelsSize+ky;

	 //Dy=Dy*(100.0-Chart->MarginTop-Chart->MarginBottom)*0.01
		//-Chart->BottomAxis->LabelsSize-ky;

	 //double Cy=Chart->LeftAxis->Maximum-Chart->LeftAxis->Minimum;
	 //int TmpY=Chart->Height-Y-dy;

	 //double y=Chart->LeftAxis->Minimum+(Cy*TmpY)/Dy;
     //I0=y;
	 //Edit4->Text=FloatToStrF(y,ffFixed,6,4)+" "+PConf->ADCValue[0];
   //}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ToolButton9Click(TObject *Sender)
{
  //if (ToolButton9->Down) {
                         //Chart->AllowPanning=pmNone;
  //                       Chart->AllowZoom=false;
                         //Chart1->AllowPanning=pmNone;
  //                       Chart1->AllowZoom=false;
  //                       Edit4->Enabled=true;
  //                       Crs->Off();
  //                       return;
  //}

  //Crs->On();
  //Edit4->Enabled=false;

  //if (!(ToolCross->Down||ToolLine->Down||ToolX->Down)){
  //                       Chart->AllowPanning=pmBoth;
  //                       Chart->AllowZoom=true;
  //                       Chart1->AllowPanning=pmBoth;
  //                       Chart1->AllowZoom=true;
  //};

}
//---------------------------------------------------------------------------
void __fastcall TForm1::ChartMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
  //if (!(ToolButton9->Down&&MDown)) return;
	 //int ky=6;
	 //double Dy=Chart->Height;
	 //double dy=Dy*Chart->MarginBottom*0.01+Chart->BottomAxis->LabelsSize+ky;

	 //Dy=Dy*(100.0-Chart->MarginTop-Chart->MarginBottom)*0.01
		//-Chart->BottomAxis->LabelsSize-ky;

	 //double Cy=Chart->LeftAxis->Maximum-Chart->LeftAxis->Minimum;
	 //int TmpY=Chart->Height-Y-dy;

	 //double y=Chart->LeftAxis->Minimum+(Cy*TmpY)/Dy;
     //I0=y;
	 //Edit4->Text=FloatToStrF(I0,ffFixed,6,4)+" "+PConf->ADCValue[0];
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit4Change(TObject *Sender)
{
  ChartTool1->Value=StrToFloat(Edit4->Text);

  //AnsiString S=((TEdit *)Sender)->Text;
  //AnsiString Val=PConf->ADCValue[0];
  //int c=S.AnsiPos(Val);
  //if(c) S.Delete(c,Val.Length());
  //while(S.Pos(" ")) S.Delete(S.Pos(" "),1);
  //c=S.Pos(".");
  //if (c) S[c]=DecimalSeparator;
  //c=S.Pos(",");
  //if (c) S[c]=DecimalSeparator;


  //float Number;
  //try
  //{
	//I0=StrToFloat(S);
  //}
  //catch(EConvertError&)
  //{
	//((TEdit *)Sender)->Font->Color=clRed;
	 //I0=0;
	 //ValI0=false;
	//return;
  //}
  //((TEdit *)Sender)->Font->Color=clWindowText;
  //ValI0=true;

  //Chart->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit4Exit(TObject *Sender)
{
  //Edit4->Text=FloatToStrF(I0,ffFixed,6,4)+" "+PConf->ADCValue[0];
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Splitter0Moved(TObject *Sender)
{
  ChartI->Height=(PanelT->Height-10)/2;
  ChartU->Height=(PanelT->Height-10)/2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBar1Change(TObject *Sender)
{
  //Rec.RScroll();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Splitter0CanResize(TObject *Sender, int &NewSize,
      bool &Accept)
{
  if (NewSize<10) NewSize=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Splitter2CanResize(TObject *Sender, int &NewSize,
      bool &Accept)
{
  if (NewSize<10) NewSize=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ChartIAfterDraw(TObject *Sender)
{
 //Rec.ShowLines((TChart*)Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N12Click(TObject *Sender)
{
   int T1,T2,Nt;
   bool From0,I,V;

 RecDial->ShowModal();

 try {
   T1=StrToInt(RecDial->Edit1->Text);
 }
 catch(EConvertError&){
   RecDial->Edit1->Text="";
   T1=-1;
 };

 try {
   T2=StrToInt(RecDial->Edit2->Text);
 }
 catch(EConvertError&){
   RecDial->Edit2->Text="";
   T2=-1;
 };

 try {
   Nt=StrToInt(RecDial->Edit3->Text);
 }
 catch(EConvertError&){
   RecDial->Edit3->Text="";
   Nt=-1;
 };
 From0=RecDial->CheckBox1->Checked;
 I=RecDial->CheckBox2->Checked;
 V=RecDial->CheckBox3->Checked;
 if(!Rec.SendToClipboard(T1,T2,Nt,From0,I,V)){
   Clipboard()->Clear();
   //Clipboard()->SetTextBuf("Неправильно введены данные");
 };

}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBarIChange(TObject *Sender)
{
  //Rec.RScrollI();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpDownIClick(TObject *Sender, TUDBtnType Button)
{
  if (Button==1)
   {
	 ChartI->Zoom->Direction=tzdVertical;
	 ChartI->ZoomPercent(95);
   }
   else
   {
	 ChartI->Zoom->Direction=tzdVertical;
	 ChartI->ZoomPercent(105);
   }

   ChartI->Zoom->Direction=tzdBoth;

  //if (Button==1) Rec.ZoomInI();
  //else Rec.ZoomOutI();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ChartTool1DragLine(TColorLineTool *Sender)
 {
	Edit4->Text=FloatToStrF(ChartTool1->Value, ffFixed, 7,4);
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::ChartClick(TObject *Sender)
{
  int Fr, Ls;
  double TmpX;
  double ValX, ValY;

  //ValY

  if ((ChartTool2->Active) || (LineTool->Active))
  {
	  Clipboard()->Clear();

	  PointsI->AddXY(ChartTool2->XValue, ChartTool2->YValue);

	  if ((CheckListBox1->ItemIndex == -1) || (CheckListBox1->Count == 0))
	  {
		CheckListBox1->Selected[0]=true;
		CheckListBox1->ItemIndex=0;
		CheckListBox1Click(Sender);
      }

	  Fr=SArrU[CheckListBox1->ItemIndex]->FirstDisplayedIndex();
	  Ls=SArrU[CheckListBox1->ItemIndex]->LastValueIndex;

	  TmpX=InttLineSer(SArrU[CheckListBox1->ItemIndex],
					   Fr,
					   Ls,
					   double(ChartTool2->XValue));

	  PointsU->AddXY(ChartTool2->XValue, TmpX);

	  if (ToolWin->Visible)
	  {
		DCText=DCText + (Char)(13) + (Char)(10) +
			 FloatToStrF(TmpX, ffFixed,6,1) +
						(Char)(9) +
			 FloatToStrF(ChartTool2->YValue - ChartTool1->Value, ffFixed,6,4);
	  }
	  else
	  {
        DCText=FloatToStrF(TmpX, ffFixed,6,1) +
						  (Char)(9) +
			   FloatToStrF(ChartTool2->YValue - ChartTool1->Value, ffFixed,6,4);

        ToolWin->Memo1->Lines->Clear();
		ToolWin->Show();
      }

	  Clipboard()->AsText=DCText.c_str();

	  ToolWin->Memo1->Lines->Add(FloatToStrF(ChartTool2->XValue, ffFixed,6,3) + "сек. " +
								 FloatToStrF(TmpX, ffFixed,6,1) + "мВ. " +
								 FloatToStrF(ChartTool2->YValue - ChartTool1->Value, ffFixed,6,4) + " мкА");

	  ToolWin->Height=34+(abs(ToolWin->Memo1->Font->Height)+2)*(ToolWin->Memo1->Lines->Count +2);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RzToolButton5Click(TObject *Sender)
{
  if (!ChartTool1->Active)
  {
	Edit4->Enabled=true;
	ChartTool1->Active=true;
	return;
  }
  Edit4->Enabled=false;
  ChartTool1->Active=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RzToolButton6Click(TObject *Sender)
{
  if (!ChartTool2->Active)
  {
	//Edit4->Enabled=true;
	ChartTool2->Active=true;
	ChartTool5->Active=true;

	//ToolWin->Visible=True;
	ToolWin->Memo1->Lines->Clear();

	return;
  }
  //Edit4->Enabled=false;
  ChartTool2->Active=false;
  ChartTool5->Active=false;
  //ToolWin->Visible=False;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RzToolButton4Click(TObject *Sender)
{
   ChartTool3->Active=!ChartTool3->Active;
   ChartTool4->Active=!ChartTool4->Active;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnExitClick(TObject *Sender)
{
  PostMessage(Form1->Handle,WM_CLOSE,0,0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StartRec()
{
  RzComboBox1->Enabled = false;

  BtnNextRecord->Enabled = false;
  RzToolButton1->Enabled = false;
  RzToolButton3->Enabled = false;
  N7->Enabled = false;
  N2->Enabled = false;

  TSr=Double(Time());

  if (Cycle)
  {
	xStr=AnsiString(IntToStr(RzNumericEdit3->IntValue +
						   ((RzSpinEdit1->IntValue -
						   CycleCount - 1) *
						   RzNumericEdit5->IntValue)) +
	   "мВ (" +
	   TimeToStr(TSr) +
	   ")");
  }
  else
  {
	xStr=AnsiString(IntToStr(RzNumericEdit3->IntValue) +
	   "мВ (" +
	   TimeToStr(TSr) +
	   ")");
  }

  CheckListBox1->Items->Add(xStr);
  CheckListBox1->Checked[CountSeries]=True;

  SnConfFile->Add(xStr);

  SArrI[CountSeries]= new TFastLineSeries(Chart);
  SArrI[CountSeries]->Clear();
  SArrI[CountSeries]->Color= (TColor)clFuchsia;
  SArrI[CountSeries]->ParentChart=Chart;

  SArrU[CountSeries]= new TFastLineSeries(Chart1);
  SArrU[CountSeries]->Clear();
  SArrU[CountSeries]->Color= (TColor)clFuchsia;
  SArrU[CountSeries]->ParentChart=Chart1;

  RzToolButton7->ImageIndex=14;

  CountSeries++;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StopRec()
{
  SArrI[CountSeries-1]->Color= (TColor)clRed;
  SArrU[CountSeries-1]->Color= (TColor)clBlue;

  RzNumericEdit1->Enabled=true;
  RzNumericEdit2->Enabled=true;
  RzNumericEdit3->Enabled=true;
  GDACValue = false;

  DACValue = 0;

  if(DevReady)
  {
	B181.WriteToDACDirect(0);
  }

  PtConfFile->Add("Series" + IntToStr(CountSeries-1) + ".str");

  ConfFile->Clear();

  for (int i = 0; i < SnConfFile->Count; i++)
   {
	 ConfFile->Add(SnConfFile->Strings[i] + (Char)(9) + PtConfFile->Strings[i]);
   }

   TempFile->SaveToFile(SPath + "\\Series" + IntToStr(CountSeries-1) + ".str");
   TempFile->Clear();

   ConfFile->SaveToFile(SPath + "\\Exp.exd");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RzToolButton7Click(TObject *Sender)
{
  Record=!Record;

  if (Record)
  {
	ToDAC = RzNumericEdit3->IntValue;

	if (!CheckBox1->Checked)
	{
      Cycle = false;
	  CheckBox1->Enabled=false;
	  RzNumericEdit4->Enabled=false;
	  RzSpinEdit1->Enabled=false;
	  RzNumericEdit5->Enabled=false;
	  CycleCount = 0;
	}
	else
	{
	  Cycle = true;
      CheckBox1->Enabled=false;
	  //RzNumericEdit4->Enabled=false;
	  RzSpinEdit1->Enabled=false;
	  RzNumericEdit5->Enabled=false;
	  CycleCount = RzSpinEdit1->IntValue - 1;
    }

	//ShowMessage(IntToStr(CycleCount));

	StartRec();
  }
  else
  {
    StopRec();

	RzToolButton7->ImageIndex=12;
	RzComboBox1->Enabled = true;

	BtnNextRecord->Enabled = true;
	RzToolButton1->Enabled = true;
	RzToolButton3->Enabled = true;
	N7->Enabled = true;
	N2->Enabled = true;

	CheckBox1->Enabled=true;
	RzNumericEdit4->Enabled=true;
	RzSpinEdit1->Enabled=true;
	RzNumericEdit5->Enabled=true;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnClearClick(TObject *Sender)
{
   Rec.Clear();
}

void __fastcall TForm1::ChartIScroll(TObject *Sender)
{
  ChartU->BottomAxis->SetMinMax(ChartI->BottomAxis->Minimum,
                                ChartI->BottomAxis->Maximum);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChartUScroll(TObject *Sender)
{
  ChartI->BottomAxis->SetMinMax(ChartU->BottomAxis->Minimum,
                                ChartU->BottomAxis->Maximum);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::UpDown2Click(TObject *Sender, TUDBtnType Button)
{
   if (Button==1)
   {
	 Chart->Zoom->Direction=tzdHorizontal;
	 Chart->ZoomPercent(95);
   }
   else
   {
	 Chart->Zoom->Direction=tzdHorizontal;
	 Chart->ZoomPercent(105);
   }

   Chart->Zoom->Direction=tzdBoth;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ChartIResize(TObject *Sender)
{
  UpDownI->Top=ChartI->Height/2-11;
  UpDownI->Left=2;

  //UpDown4->Top=ChartI->Height-14;
  //UpDown4->Left=2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChartUResize(TObject *Sender)
{
  UpDownU->Top=ChartU->Height/2-11;
  UpDownU->Left=2;

  UpDown3->Top=ChartU->Height-14;
  UpDown3->Left=2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpDownUClick(TObject *Sender, TUDBtnType Button)
{
  if (Button==1)
   {
	 ChartU->Zoom->Direction=tzdVertical;
	 ChartU->ZoomPercent(95);
   }
   else
   {
	 ChartU->Zoom->Direction=tzdVertical;
	 ChartU->ZoomPercent(105);
   }

   ChartU->Zoom->Direction=tzdBoth;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpDown4Click(TObject *Sender, TUDBtnType Button)
{
  //if (Button==1)
   //{
	 //ChartI->Zoom->Direction=tzdHorizontal;
	 //ChartI->ZoomPercent(95);
   //}
   //else
   //{
	 //ChartI->Zoom->Direction=tzdHorizontal;
	 //ChartI->ZoomPercent(105);
   //}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpDown3Click(TObject *Sender, TUDBtnType Button)
{
  if (Button==1)
   {
	 ChartU->Zoom->Direction=tzdHorizontal;
	 ChartU->ZoomPercent(95);
   }
   else
   {
	 ChartU->Zoom->Direction=tzdHorizontal;
	 ChartU->ZoomPercent(105);
   }

  ChartUScroll(Sender);

  ChartI->Zoom->Direction=tzdBoth;
  ChartU->Zoom->Direction=tzdBoth;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RzToolButton8Click(TObject *Sender)
{
  LineTool->Active = !LineTool->Active;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LineToolChange(TCursorTool *Sender, int x, int y, const double XValue,
          const double YValue, TChartSeries *Series, int ValueIndex)
{
  int i;

  xval = XValue;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N15Click(TObject *Sender)
{
  AboutForm->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RzComboBox1Change(TObject *Sender)
{
  ClearSeria();
  LoadSeria(MainDir + "\\" + SeriesList->Strings[RzComboBox1->ItemIndex]);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::xJvThread1Execute(TObject *Sender, Pointer Params)
{
  double xTime;
  float **tmp;

  int  G0 = PConf->Gen0;
  int n=500;

  float I=0,U=0;
  int Srt, St;

  while (!AppTerminate)
  {
    Srt=GetTickCount();

	if(DevReady)
	{
	  tmp=new float*[2];
	  tmp[0]=new float[n];
	  tmp[1]=new float[n];

	  PConf->Gen0=500;
	  PConf->ADCLen=n;

	  B181.ConfigCmn();
	  B181.ConfigADC();

	  B181.Reset(1);
	  B181.Run(1);
	  while(!(4&B181.ReadStatus()));
	  B181.ReadFromADC(tmp);

	  St=GetTickCount();
	  //RzStatusPane1->Caption=IntToStr(St - Srt);

	  for(int i=0;i<n;i++)
	  {
		I+=tmp[0][i];
		U+=tmp[1][i];
	  }

	  I/=n;
	  U/=n;

	  delete[] tmp[0];
	  delete[] tmp[1];
	  delete[] tmp;

	  if (AppTerminate) goto Term;
	}
	else
	{
	  static c=0;
	  I=U=c;
	  c++;
	  c=c%200;
	}

	  PConf->Gen0=G0;

	  ChartTool3->Text="  "+FloatToStrF(I,ffFixed,6,4)+" "+PConf->ADCValue[0];
	  ChartTool4->Text="  "+FloatToStrF(U,ffFixed,5,1)+" "+PConf->ADCValue[1];

	  SeriesI->Active=True;
	  SeriesU->Active=True;

	  if (Record)
	  {
		xTime =(double(Time())-TSr)*24*60*60;

		SArrI[CountSeries-1]->AddXY(xTime, I);
		SArrU[CountSeries-1]->AddXY(xTime, U);

		TempFile->Add(FloatToStrF(xTime, ffFixed, 6,3) + (Char)(9) +
					FloatToStrF(I, ffFixed, 7,5) + (Char)(9) +
				    FloatToStrF(U, ffFixed, 6,3));

		if (Cycle)
		{
		  RzToolButton7->Caption="Rec " +
						 FloatToStrF(xTime, ffFixed, 6,1) +
						 " (" +
						 IntToStr(RzSpinEdit1->IntValue - CycleCount) +
						 "/" +
						 IntToStr(RzSpinEdit1->IntValue) +
						 ")";
		}
		else
		{
		  RzToolButton7->Caption="Rec " + FloatToStrF(xTime, ffFixed, 6,1);
		}

		if (RzNumericEdit1->IntValue > xTime)
		{
		  RzNumericEdit1->Enabled=false;
		  RzNumericEdit4->Enabled=true;
		}
		else
		{
		  OldTime = RzNumericEdit1->IntValue;
		  RzNumericEdit1->Enabled=true;

		  if ((RzNumericEdit2->IntValue + OldTime) > xTime)
		  {
			RzNumericEdit2->Enabled=false;
			RzNumericEdit3->Enabled=false;

			if (!GDACValue)
			{
			  DACValue = ToDAC - U;
			  GDACValue = true;

			  if(DevReady)
			  {
				B181.WriteToDACDirect(DACValue/PConf->DACCoeff[0]);
			  }
			}
		  }
		  else
		  {
			RzNumericEdit2->Enabled=true;
			RzNumericEdit3->Enabled=true;
			RzNumericEdit4->Enabled=false;

			DACValue = 0;

			if (GDACValue)
			{
			  if(DevReady)
			  {
				B181.WriteToDACDirect(0);
			  }
			  GDACValue = false;
			 }

			if (((RzNumericEdit1->IntValue +
				  RzNumericEdit2->IntValue +
				  RzNumericEdit4->IntValue) < xTime) && Cycle)
			{
			  if (CycleCount > 0)
			  {
				CycleCount--;

				StopRec();
				StartRec();

				ToDAC = ToDAC + RzNumericEdit5->IntValue;
			  }
			  else
			  {
				 RzToolButton7Click(Sender);
			  }
			}
			else
			{

			}
		  }
		}
	  }

	  if (RecRecorder)
	  {
		xTime =(double(Time())-TCrt)*24*60*60;

		RecFile->Add(FloatToStrF(xTime, ffFixed, 6,2) + (Char)(9) +
					 FloatToStrF(I, ffFixed, 7,4) + (Char)(9) +
					 FloatToStrF(U, ffFixed, 6,1));

		SeriesI->AddXY(xTime, I);
		SeriesU->AddXY(xTime, U);

		if (xTime > 100)
		{
		  ChartI->BottomAxis->SetMinMax(ChartI->BottomAxis->Minimum + (xTime - Last),
										ChartI->BottomAxis->Maximum + (xTime - Last));

		  ChartU->BottomAxis->SetMinMax(ChartU->BottomAxis->Minimum + (xTime - Last),
										ChartU->BottomAxis->Maximum + (xTime - Last));

		  Last=xTime;
		}
	  }
	Sleep(50);
	}
  Term:;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ChartTool2Change(TCursorTool *Sender, int x, int y, const double XValue,
          const double YValue, TChartSeries *Series, int ValueIndex)
{
  ChartTool5->Text=FloatToStrF(XValue, ffFixed, 8,3) +
				   " с. " +
				   FloatToStrF(YValue, ffFixed, 8,4) +
				   " мкА";
}
//---------------------------------------------------------------------------



void __fastcall TForm1::MSWheel1WheelEvent(int zdelta, int xpos, int ypos, int ScrollLines)

{
  //ShowMessage(IntToStr(ScrollLines));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChartMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled)
{
	ShowMessage(IntToStr(WheelDelta));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChartMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
 	ShowMessage("qwerty");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
		  bool &Handled)
{
	String CName;

	CName=FindVCLWindow(MousePos)->Name;

	if (CName == "Chart")
	{
      Chart->Zoom->Direction=tzdBoth;
	  Chart->ZoomPercent(102);
	}

	if (CName == "Chart1")
	{
	  Chart1->Zoom->Direction=tzdBoth;
	  Chart1->ZoomPercent(102);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
	String CName;

	CName=FindVCLWindow(MousePos)->Name;

	if (CName == "Chart")
	{
	  Chart->Zoom->Direction=tzdBoth;
	  Chart->ZoomPercent(98);
	}

	if (CName == "Chart1")
	{
	  Chart1->Zoom->Direction=tzdBoth;
	  Chart1->ZoomPercent(98);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChartScroll(TObject *Sender)
{
  Chart1->BottomAxis->SetMinMax(Chart->BottomAxis->Minimum,
								Chart->BottomAxis->Maximum);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart1Scroll(TObject *Sender)
{
  Chart->BottomAxis->SetMinMax(Chart1->BottomAxis->Minimum,
  							   Chart1->BottomAxis->Maximum);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart1Zoom(TObject *Sender)
{
  Chart->BottomAxis->SetMinMax(Chart1->BottomAxis->Minimum,
							   Chart1->BottomAxis->Maximum);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChartZoom(TObject *Sender)
{
  Chart1->BottomAxis->SetMinMax(Chart->BottomAxis->Minimum,
								Chart->BottomAxis->Maximum);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChartUndoZoom(TObject *Sender)
{
  Chart1->BottomAxis->SetMinMax(Chart->BottomAxis->Minimum,
								Chart->BottomAxis->Maximum);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart1UndoZoom(TObject *Sender)
{
  Chart->BottomAxis->SetMinMax(Chart1->BottomAxis->Minimum,
							   Chart1->BottomAxis->Maximum);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
  int i;

  if (Chk == true)
  {
    Chk = false;
	return;
  }

  for (i = 0; i < CheckListBox1->Count; i++)
  {
	CheckListBox1->Checked[i] = CheckBox2->Checked;

	SArrI[i]->Active=CheckListBox1->Checked[i];
	SArrU[i]->Active=CheckListBox1->Checked[i];
  }

  //CheckListBox1ClickCheck(Sender);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox3Click(TObject *Sender)
{
  int i;

  for (i = 0; i < CheckListBox1->Count; i++)
  {
	//SArrI[i]->Smoothed = CheckBox3->Checked;
	//SArrU[i]->Smoothed = CheckBox3->Checked;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ChartDblClick(TObject *Sender)
{
  ChartEditor1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart1DblClick(TObject *Sender)
{
  ChartEditor2->Execute();
}
//---------------------------------------------------------------------------

