object ToolWin: TToolWin
  Left = 360
  Top = 197
  BorderStyle = bsSizeToolWin
  Caption = #1050#1091#1088#1089#1086#1088#1099
  ClientHeight = 42
  ClientWidth = 185
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object ScrollBox1: TScrollBox
    Left = 0
    Top = 0
    Width = 185
    Height = 42
    Align = alClient
    TabOrder = 0
    object Memo1: TMemo
      Left = 0
      Top = 0
      Width = 181
      Height = 38
      Align = alClient
      Lines.Strings = (
        'Memo1'
        '300.000vc 300.000vd 300.000vrF')
      TabOrder = 0
    end
  end
end
