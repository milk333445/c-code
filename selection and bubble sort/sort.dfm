object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 571
  ClientWidth = 759
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 56
    Top = 91
    Width = 14
    Height = 13
    Caption = 'n='
  end
  object Label2: TLabel
    Left = 48
    Top = 136
    Width = 36
    Height = 13
    Caption = 'range='
  end
  object Memo1: TMemo
    Left = 48
    Top = 208
    Width = 177
    Height = 289
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Memo2: TMemo
    Left = 272
    Top = 208
    Width = 177
    Height = 289
    Lines.Strings = (
      'Memo2')
    TabOrder = 1
  end
  object Memo3: TMemo
    Left = 488
    Top = 208
    Width = 177
    Height = 289
    Lines.Strings = (
      'Memo3')
    TabOrder = 2
  end
  object Button1: TButton
    Left = 48
    Top = 160
    Width = 177
    Height = 33
    Caption = 'generate random number'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 272
    Top = 160
    Width = 177
    Height = 33
    Caption = 'selection sort'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 488
    Top = 160
    Width = 177
    Height = 33
    Caption = 'bubble sort'
    TabOrder = 5
    OnClick = Button3Click
  end
  object Edit1: TEdit
    Left = 104
    Top = 88
    Width = 121
    Height = 21
    TabOrder = 6
  end
  object Edit2: TEdit
    Left = 104
    Top = 133
    Width = 121
    Height = 21
    TabOrder = 7
  end
  object CheckBox1: TCheckBox
    Left = 128
    Top = 24
    Width = 97
    Height = 17
    Caption = 'ecoprint'
    Checked = True
    State = cbChecked
    TabOrder = 8
  end
  object CheckBox2: TCheckBox
    Left = 128
    Top = 47
    Width = 97
    Height = 17
    Caption = 'selfcheck'
    Checked = True
    State = cbChecked
    TabOrder = 9
  end
end
