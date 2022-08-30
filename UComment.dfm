object Comment: TComment
  Left = 194
  Top = 169
  BorderStyle = bsSingle
  Caption = 'Кометтарий'
  ClientHeight = 286
  ClientWidth = 439
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Memo: TMemo
    Left = 0
    Top = 0
    Width = 439
    Height = 233
    Align = alTop
    TabOrder = 0
  end
  object BtnSave: TButton
    Left = 104
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Сохранить'
    ModalResult = 1
    TabOrder = 1
  end
  object BtnCancel: TButton
    Left = 232
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Отмена'
    ModalResult = 2
    TabOrder = 2
  end
end
