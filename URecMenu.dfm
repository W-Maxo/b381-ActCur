object RecDial: TRecDial
  Left = 268
  Top = 126
  BorderStyle = bsDialog
  Caption = 'Выбор данных сомописца'
  ClientHeight = 235
  ClientWidth = 358
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 32
    Width = 210
    Height = 13
    Caption = 'Начальный момент времени (в секундах)'
  end
  object Label2: TLabel
    Left = 24
    Top = 64
    Width = 203
    Height = 13
    Caption = 'Конечный момент времени (в секундах)'
  end
  object Label3: TLabel
    Left = 24
    Top = 96
    Width = 122
    Height = 13
    Caption = 'Число точек (примерно)'
  end
  object Edit1: TEdit
    Left = 240
    Top = 24
    Width = 89
    Height = 21
    TabOrder = 0
    Text = '0'
  end
  object Edit2: TEdit
    Left = 240
    Top = 56
    Width = 89
    Height = 21
    TabOrder = 1
    Text = '100'
  end
  object Edit3: TEdit
    Left = 208
    Top = 88
    Width = 89
    Height = 21
    TabOrder = 2
    Text = '50'
  end
  object Button1: TButton
    Left = 232
    Top = 176
    Width = 75
    Height = 25
    Caption = 'ОК'
    ModalResult = 1
    TabOrder = 3
    OnClick = Button1Click
  end
  object CheckBox1: TCheckBox
    Left = 40
    Top = 144
    Width = 177
    Height = 17
    Caption = 'Отсчет времени от 0 секунд'
    Checked = True
    State = cbChecked
    TabOrder = 4
  end
  object CheckBox2: TCheckBox
    Left = 40
    Top = 184
    Width = 97
    Height = 17
    Caption = 'Ток'
    Checked = True
    State = cbChecked
    TabOrder = 5
  end
  object CheckBox3: TCheckBox
    Left = 40
    Top = 208
    Width = 97
    Height = 17
    Caption = 'Напряжение'
    TabOrder = 6
  end
end
