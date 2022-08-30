object FOptions: TFOptions
  Left = 295
  Top = 241
  BorderStyle = bsDialog
  Caption = 'Настройки'
  ClientHeight = 185
  ClientWidth = 374
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object ButtonOK: TButton
    Left = 176
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Применить'
    ModalResult = 1
    TabOrder = 0
  end
  object ButtonCancel: TButton
    Left = 280
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Отмена'
    ModalResult = 2
    TabOrder = 1
  end
  object GroupBoxCADC: TGroupBox
    Left = 11
    Top = 16
    Width = 353
    Height = 89
    Caption = 'Каналы АЦП'
    TabOrder = 2
    object Label1: TLabel
      Left = 16
      Top = 37
      Width = 40
      Height = 13
      Caption = 'Канал 1'
    end
    object Label2: TLabel
      Left = 16
      Top = 61
      Width = 40
      Height = 13
      Caption = 'Канал 2'
    end
    object Label3: TLabel
      Left = 76
      Top = 16
      Width = 70
      Height = 13
      Caption = 'Коеффициент'
    end
    object Label4: TLabel
      Left = 168
      Top = 16
      Width = 54
      Height = 13
      Caption = 'Максимум'
    end
    object Label6: TLabel
      Left = 256
      Top = 16
      Width = 48
      Height = 13
      Caption = 'Минимум'
    end
    object EditCoef1: TEdit
      Left = 75
      Top = 32
      Width = 70
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -8
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnEnter = EditEnter
      OnExit = EditCoefADCExit
    end
    object EditCoef2: TEdit
      Left = 75
      Top = 56
      Width = 70
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -8
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnEnter = EditEnter
      OnExit = EditCoefADCExit
    end
    object Edit1Max: TEdit
      Left = 160
      Top = 32
      Width = 70
      Height = 21
      TabOrder = 2
      OnEnter = EditEnter
      OnExit = EditMaxMinExit
    end
    object Edit2Max: TEdit
      Left = 160
      Top = 56
      Width = 70
      Height = 21
      TabOrder = 3
      OnEnter = EditEnter
      OnExit = EditMaxMinExit
    end
    object Edit1Min: TEdit
      Left = 245
      Top = 32
      Width = 70
      Height = 21
      TabOrder = 4
      OnEnter = EditEnter
      OnExit = EditMaxMinExit
    end
    object Edit2Min: TEdit
      Left = 245
      Top = 56
      Width = 70
      Height = 21
      TabOrder = 5
      OnEnter = EditEnter
      OnExit = EditMaxMinExit
    end
  end
  object GroupBoxCDAC: TGroupBox
    Left = 11
    Top = 112
    Width = 153
    Height = 57
    Caption = 'Канал ЦАП'
    TabOrder = 3
    object Label5: TLabel
      Left = 16
      Top = 22
      Width = 40
      Height = 13
      Caption = 'Канал 1'
    end
    object EditCoeffDAC1: TEdit
      Left = 75
      Top = 16
      Width = 70
      Height = 21
      TabOrder = 0
      OnEnter = EditEnter
      OnExit = EditCoeffDACExit
    end
  end
end
