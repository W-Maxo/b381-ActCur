object NewSeries: TNewSeries
  Left = 244
  Top = 154
  BorderStyle = bsDialog
  Caption = #1053#1086#1074#1072#1103'  '#1089#1077#1088#1080#1103
  ClientHeight = 108
  ClientWidth = 374
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object LNameSeries: TLabel
    Left = 18
    Top = 30
    Width = 73
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1048#1084#1103' '#1089#1077#1088#1080#1080
  end
  object Label1: TLabel
    Left = 39
    Top = 89
    Width = 169
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1044#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100' '#1080#1084#1087#1091#1083#1100#1089#1072
    Visible = False
  end
  object Label2: TLabel
    Left = 39
    Top = 118
    Width = 205
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1048#1085#1090#1077#1088#1074#1072#1083' '#1084#1077#1078#1076#1091' '#1080#1084#1087#1091#1083#1100#1089#1072#1084#1080
    Visible = False
  end
  object Label3: TLabel
    Left = 39
    Top = 148
    Width = 123
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1077#1088#1077#1076' '#1080#1084#1087#1091#1083#1100#1089#1086#1084
    Visible = False
  end
  object Label4: TLabel
    Left = 39
    Top = 177
    Width = 110
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1055#1086#1089#1083#1077' '#1080#1084#1087#1091#1083#1100#1089#1072
    Visible = False
  end
  object Label5: TLabel
    Left = 246
    Top = 59
    Width = 47
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1042#1088#1077#1084#1103':'
    Visible = False
  end
  object Label6: TLabel
    Left = 374
    Top = 59
    Width = 88
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1063#1080#1089#1083#1086' '#1090#1086#1095#1077#1082':'
    Visible = False
  end
  object Label7: TLabel
    Left = 39
    Top = 226
    Width = 138
    Height = 16
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1063#1080#1089#1083#1086' '#1090#1086#1095#1077#1082' '#1085#1072' '#1086#1082#1085#1086
    Visible = False
  end
  object EditName: TEdit
    Left = 94
    Top = 26
    Width = 273
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 246
    Top = 79
    Width = 120
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 1
    Visible = False
    OnEnter = EditEnter
    OnExit = EditExit
  end
  object Edit2: TEdit
    Left = 246
    Top = 108
    Width = 120
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 2
    Visible = False
    OnEnter = EditEnter
    OnExit = EditExit
  end
  object Edit3: TEdit
    Left = 246
    Top = 138
    Width = 120
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 3
    Visible = False
    OnEnter = EditEnter
    OnExit = EditExit
  end
  object Edit4: TEdit
    Left = 246
    Top = 167
    Width = 120
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 4
    Visible = False
    OnEnter = EditEnter
    OnExit = EditExit
  end
  object Edit5: TEdit
    Left = 374
    Top = 79
    Width = 89
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Enabled = False
    TabOrder = 7
    Visible = False
  end
  object Edit6: TEdit
    Left = 374
    Top = 108
    Width = 89
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Enabled = False
    TabOrder = 8
    Visible = False
  end
  object Edit7: TEdit
    Left = 374
    Top = 138
    Width = 89
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Enabled = False
    TabOrder = 9
    Visible = False
  end
  object Edit8: TEdit
    Left = 374
    Top = 167
    Width = 89
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Enabled = False
    TabOrder = 10
    Visible = False
  end
  object Button2: TButton
    Left = 257
    Top = 70
    Width = 93
    Height = 31
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    Caption = #1054#1090#1084#1077#1085#1072
    ModalResult = 2
    TabOrder = 6
  end
  object Edit9: TEdit
    Left = 246
    Top = 217
    Width = 120
    Height = 24
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    TabOrder = 5
    Visible = False
    OnEnter = EditEnter
    OnExit = Edit9Exit
  end
  object RzBitBtn1: TRzBitBtn
    Left = 157
    Top = 70
    Width = 93
    Height = 31
    ModalResult = 1
    Caption = 'OK'
    TabOrder = 11
    ImageIndex = 30
    Images = Form1.ToolBarImageList
  end
end
