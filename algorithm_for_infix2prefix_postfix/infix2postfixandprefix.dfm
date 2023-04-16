object Form6: TForm6
  Left = 0
  Top = 0
  Caption = 'Form6'
  ClientHeight = 505
  ClientWidth = 793
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 793
    Height = 137
    Align = alTop
    TabOrder = 0
    object Label1: TLabel
      Left = 224
      Top = 48
      Width = 20
      Height = 13
      Caption = 'infix'
    end
    object CheckBox1: TCheckBox
      Left = 32
      Top = 88
      Width = 97
      Height = 17
      Caption = 'printstack'
      Checked = True
      State = cbChecked
      TabOrder = 0
    end
    object Edit1: TEdit
      Left = 264
      Top = 45
      Width = 329
      Height = 21
      TabOrder = 1
    end
    object Edit2: TEdit
      Left = 264
      Top = 99
      Width = 329
      Height = 21
      TabOrder = 2
    end
    object Edit3: TEdit
      Left = 264
      Top = 72
      Width = 329
      Height = 21
      TabOrder = 3
    end
    object Button1: TButton
      Left = 183
      Top = 67
      Width = 75
      Height = 25
      Caption = 'infix->prefix'
      TabOrder = 4
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 183
      Top = 98
      Width = 75
      Height = 25
      Caption = 'infix->postfix'
      TabOrder = 5
      OnClick = Button2Click
    end
  end
  object Memo1: TMemo
    Left = 0
    Top = 137
    Width = 793
    Height = 368
    Align = alClient
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
    ExplicitLeft = 376
    ExplicitTop = 312
    ExplicitWidth = 185
    ExplicitHeight = 89
  end
end
