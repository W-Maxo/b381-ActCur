//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Dialogs.hpp>
#include <ImgList.hpp>

//#include "b181.h"
#include <CheckLst.hpp>
#include <Buttons.hpp>
#include <TeeProcs.hpp>
#include <Chart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include "TeeEdit.hpp"
#include <XPMan.hpp>
#include "JvBaseDlg.hpp"
#include "JvSelectDirectory.hpp"
#include "FolderDialog.hpp"
#include "RzShellDialogs.hpp"
#include "TeeTools.hpp"
#include "RzButton.hpp"
#include "RzPanel.hpp"
#include "RzSpnEdt.hpp"
#include "RzStatus.hpp"
#include "TeeScroB.hpp"
#include "IdBaseComponent.hpp"
#include "IdThreadComponent.hpp"
#include "RzEdit.hpp"
#include <Mask.hpp>
#include "RzLabel.hpp"
#include "RzCommon.hpp"
#include "RzForms.hpp"
#include "JvComponentBase.hpp"
#include "JvTrayIcon.hpp"
#include "RzCmboBx.hpp"
#include "RzLine.hpp"
#include "JvThread.hpp"
#include "mswheel.hpp"
//---------------------------------------------------------------------------

class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Menu_File;
        TMenuItem *Menu_Edit;
        TMenuItem *Menu_Options;
        TMenuItem *Menu__1;
        TMenuItem *Menu_Exit;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TMenuItem *Menu_Delete;
        TMenuItem *Menu_Print;
        TMenuItem *Menu_Separator1;
        TMenuItem *Menu_Comment;
        TMenuItem *N1;
        TMenuItem *MenuReset;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *N9;
        TMenuItem *N10;
        TMenuItem *fft1;
	TTimer *Timer1;
        TMenuItem *N11;
        TPanel *PanelT;
        TSplitter *Splitter0;
        TPanel *PanelB;
        TPanel *Panel2;
        TSplitter *Splitter1;
        TPanel *Panel3;
        TChart *ChartI;
	TFastLineSeries *SeriesI;
        TChart *ChartU;
	TFastLineSeries *SeriesU;
        TPanel *Panel1;
        TChart *Chart;
        TSplitter *Splitter2;
        TChart *Chart1;
        TScrollBar *ScrollBarY1;
        TScrollBar *ScrollBarY2;
        TUpDown *UpDownY1;
        TUpDown *UpDownY2;
        TUpDown *UpDownX;
        TScrollBar *ScrollBarX;
        TCheckListBox *CheckListBox1;
        TMenuItem *N12;
        TScrollBar *ScrollBarI;
        TScrollBar *ScrollBarU;
        TUpDown *UpDownU;
        TImageList *ImageList1;
        TMenuItem *N13;
	TChartEditor *ChartEditor1;
	TXPManifest *XPManifest1;
	TRzSelectFolderDialog *FolderDialog1;
	TColorLineTool *ChartTool1;
	TCursorTool *ChartTool2;
	TRzToolbar *RzToolbar1;
	TRzToolButton *RzToolButton1;
	TRzToolButton *RzToolButton2;
	TRzToolButton *RzToolButton3;
	TImageList *ToolBarImageList;
	TRzToolButton *RzToolButton4;
	TRzSpacer *RzSpacer1;
	TRzSpacer *RzSpacer2;
	TRzToolButton *RzToolButton5;
	TEdit *Edit4;
	TRzSpacer *RzSpacer3;
	TRzSpacer *RzSpacer4;
	TRzToolButton *RzToolButton6;
	TRzSpacer *RzSpacer5;
	TRzToolButton *RzToolButton7;
	TRzToolButton *BtnExit;
	TRzSpacer *RzSpacer6;
	TRzToolButton *BtnClear;
	TMenuItem *N14;
	TMenuItem *N15;
	TRzVersionInfo *RzVersionInfo1;
	TPointSeries *PointsI;
	TPointSeries *PointsU;
	TChartScrollBar *ChartScrollBar1;
	TAnnotationTool *ChartTool3;
	TAnnotationTool *ChartTool4;
	TUpDown *UpDown1;
	TUpDown *UpDown2;
	TPopupMenu *PopupMenu1;
	TMenuItem *N16;
	TMenuItem *N17;
	TMenuItem *N18;
	TUpDown *UpDown3;
	TUpDown *UpDownI;
	TCursorTool *LineTool;
	TRzToolButton *RzToolButton8;
	TRzPanel *RzPanel1;
	TRzNumericEdit *RzNumericEdit3;
	TRzNumericEdit *RzNumericEdit2;
	TRzNumericEdit *RzNumericEdit1;
	TRzLabel *RzLabel1;
	TRzLabel *RzLabel2;
	TRzLabel *RzLabel3;
	TRzLabel *RzLabel4;
	TRzLabel *RzLabel5;
	TRzLabel *RzLabel6;
	TRzRegIniFile *RzRegIniFile1;
	TRzStatusBar *RzStatusBar1;
	TRzFormState *RzFormState1;
	TRzComboBox *RzComboBox1;
	TRzToolButton *BtnNextRecord;
	TRzSpacer *RzSpacer7;
	TRzLabel *RzLabel7;
	TRzNumericEdit *RzNumericEdit4;
	TRzLabel *RzLabel8;
	TRzSpinEdit *RzSpinEdit1;
	TRzLabel *RzLabel9;
	TCheckBox *CheckBox1;
	TRzGlyphStatus *RzGlyphStatus1;
	TRzLine *RzLine1;
	TRzLabel *RzLabel10;
	TRzNumericEdit *RzNumericEdit5;
	TRzLabel *RzLabel11;
	TRzStatusPane *RzStatusPane1;
	TJvThread *xJvThread1;
	TAnnotationTool *ChartTool5;
	TRzPropertyStore *RzPropertyStore1;
	TMSWheel *MSWheel1;
	TRzLine *RzLine2;
	TCheckBox *CheckBox2;
	TRzSpacer *RzSpacer8;
	TCheckBox *CheckBox3;
	TChartEditor *ChartEditor2;
        void __fastcall Menu_OpenClick(TObject *Sender);
        void __fastcall Menu_Save_AsClick(TObject *Sender);
//        void __fastcall ButtonClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
//        void __fastcall ButtonInitClick(TObject *Sender);
        void __fastcall Menu_OptionsClick(TObject *Sender);
        void __fastcall ButtonRunClick(TObject *Sender);
        void __fastcall ScrollBarXScroll(TObject *Sender,
          TScrollCode ScrollCode, int &ScrollPos);
        void __fastcall ScrollBarY1Scroll(TObject *Sender,
          TScrollCode ScrollCode, int &ScrollPos);
        void __fastcall U(TObject *Sender, TUDBtnType Button);
        void __fastcall UpDownY1Click(TObject *Sender, TUDBtnType Button);
        void __fastcall ButtonOptionClick(TObject *Sender);
        void __fastcall OpenDialog1TypeChange(TObject *Sender);
        void __fastcall SaveDialog1TypeChange(TObject *Sender);
        void __fastcall CheckListBox1ClickCheck(TObject *Sender);
        void __fastcall Menu_NewClick(TObject *Sender);
        void __fastcall CheckListBox1Click(TObject *Sender);
        void __fastcall Panel1Resize(TObject *Sender);
        void __fastcall Splitter1Moved(TObject *Sender);
        void __fastcall ChartMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Panel3Resize(TObject *Sender);
        void __fastcall ChartResize(TObject *Sender);
        void __fastcall UpDownY2Click(TObject *Sender, TUDBtnType Button);
        void __fastcall ScrollBarY2Scroll(TObject *Sender,
          TScrollCode ScrollCode, int &ScrollPos);
        void __fastcall Menu_PrintClick(TObject *Sender);
        void __fastcall ChartAfterDraw(TObject *Sender);
        void __fastcall Menu_CommentClick(TObject *Sender);
        void __fastcall Panel2Resize(TObject *Sender);
        void __fastcall ToolCursClick(TObject *Sender);
        void __fastcall Menu_DeleteClick(TObject *Sender);
        void __fastcall MenuResetClick(TObject *Sender);
        void __fastcall Menu_NewSeriaClick(TObject *Sender);
        void __fastcall MenuClearClick(TObject *Sender);
        void __fastcall CBSeriesChange(TObject *Sender);
        void __fastcall N9Click(TObject *Sender);
        void __fastcall Menu_FileClick(TObject *Sender);
        void __fastcall ToolButton6Click(TObject *Sender);
        void __fastcall Edit1Exit(TObject *Sender);
        void __fastcall Edit3Exit(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall fft1Click(TObject *Sender);
        void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall Edit3Change(TObject *Sender);
        void __fastcall EditChange(TObject *Sender);
        void __fastcall Edit2Exit(TObject *Sender);
        void __fastcall N11Click(TObject *Sender);
        void __fastcall p(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall ToolButton9Click(TObject *Sender);
        void __fastcall ChartMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Edit4Change(TObject *Sender);
        void __fastcall Edit4Exit(TObject *Sender);
        void __fastcall Splitter0Moved(TObject *Sender);
        void __fastcall ScrollBar1Change(TObject *Sender);
        void __fastcall Splitter0CanResize(TObject *Sender, int &NewSize,
          bool &Accept);
        void __fastcall Splitter2CanResize(TObject *Sender, int &NewSize,
          bool &Accept);
        void __fastcall ChartIAfterDraw(TObject *Sender);
        void __fastcall N12Click(TObject *Sender);
        void __fastcall ScrollBarIChange(TObject *Sender);
        void __fastcall UpDownIClick(TObject *Sender, TUDBtnType Button);
	void __fastcall ChartTool1DragLine(TColorLineTool *Sender);
	void __fastcall ChartClick(TObject *Sender);
	void __fastcall RzToolButton5Click(TObject *Sender);
	void __fastcall RzToolButton6Click(TObject *Sender);
	void __fastcall RzToolButton4Click(TObject *Sender);
	void __fastcall BtnExitClick(TObject *Sender);
	void __fastcall RzToolButton7Click(TObject *Sender);
	void __fastcall BtnClearClick(TObject *Sender);
	void __fastcall ChartIScroll(TObject *Sender);
	void __fastcall ChartUScroll(TObject *Sender);
	void __fastcall UpDown2Click(TObject *Sender, TUDBtnType Button);
	void __fastcall ChartIResize(TObject *Sender);
	void __fastcall ChartUResize(TObject *Sender);
	void __fastcall UpDownUClick(TObject *Sender, TUDBtnType Button);
	void __fastcall UpDown4Click(TObject *Sender, TUDBtnType Button);
	void __fastcall UpDown3Click(TObject *Sender, TUDBtnType Button);
	void __fastcall RzToolButton8Click(TObject *Sender);
	void __fastcall LineToolChange(TCursorTool *Sender, int x, int y, const double XValue,
          const double YValue, TChartSeries *Series, int ValueIndex);
	void __fastcall N15Click(TObject *Sender);
	void __fastcall ClearSeria();
	void __fastcall LoadSeria(AnsiString SerPath);
	void __fastcall RzComboBox1Change(TObject *Sender);
	void __fastcall StartRec();
	void __fastcall StopRec();
	void __fastcall xJvThread1Execute(TObject *Sender, Pointer Params);
	void __fastcall ChartTool2Change(TCursorTool *Sender, int x, int y, const double XValue,
          const double YValue, TChartSeries *Series, int ValueIndex);
	void __fastcall MSWheel1WheelEvent(int zdelta, int xpos, int ypos, int ScrollLines);
	void __fastcall ChartMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled);
	void __fastcall ChartMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
	void __fastcall FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
	void __fastcall FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
	void __fastcall ChartScroll(TObject *Sender);
	void __fastcall Chart1Scroll(TObject *Sender);
	void __fastcall Chart1Zoom(TObject *Sender);
	void __fastcall ChartZoom(TObject *Sender);
	void __fastcall ChartUndoZoom(TObject *Sender);
	void __fastcall Chart1UndoZoom(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall CheckBox3Click(TObject *Sender);
	void __fastcall ChartDblClick(TObject *Sender);
	void __fastcall Chart1DblClick(TObject *Sender);




//        void __fastcall ScrollBar1Change(TObject *Sender);
private:	// User declarations

        void __fastcall OnClose(TWMClose& Message);

public:		// User declarations
		__fastcall TForm1(TComponent* Owner);

        TLineSeries *PSeries[40];
  BEGIN_MESSAGE_MAP
     MESSAGE_HANDLER(WM_CLOSE,TWMClose,OnClose)
  END_MESSAGE_MAP(TComponent)
};


//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
