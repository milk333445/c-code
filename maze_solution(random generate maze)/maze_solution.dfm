object Form5: TForm5
  Left = 0
  Top = 0
  Caption = 'Form5'
  ClientHeight = 603
  ClientWidth = 763
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 185
    Top = 0
    Height = 603
    ExplicitLeft = 248
    ExplicitTop = 240
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 185
    Height = 603
    Align = alLeft
    TabOrder = 0
    object Label1: TLabel
      Left = 24
      Top = 70
      Width = 32
      Height = 13
      Caption = 'weight'
    end
    object Label2: TLabel
      Left = 24
      Top = 107
      Width = 30
      Height = 13
      Caption = 'height'
    end
    object Button1: TButton
      Left = 8
      Top = 184
      Width = 171
      Height = 49
      Caption = 'generate random maze'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 8
      Top = 256
      Width = 171
      Height = 49
      Caption = 'find a random maze tour'
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 8
      Top = 328
      Width = 171
      Height = 49
      Caption = 'read file and find tour'
      TabOrder = 2
      OnClick = Button3Click
    end
    object Edit1: TEdit
      Left = 72
      Top = 104
      Width = 107
      Height = 21
      TabOrder = 3
    end
    object Edit2: TEdit
      Left = 72
      Top = 67
      Width = 107
      Height = 21
      TabOrder = 4
    end
  end
  object PageControl1: TPageControl
    Left = 188
    Top = 0
    Width = 575
    Height = 603
    ActivePage = TabSheet4
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'show the ranndom maze'
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 567
        Height = 575
        Align = alClient
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'fine the random maze tour'
      ImageIndex = 1
      object StringGrid2: TStringGrid
        Left = 0
        Top = 0
        Width = 567
        Height = 575
        Align = alClient
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'show the file maze'
      ImageIndex = 2
      object StringGrid3: TStringGrid
        Left = 0
        Top = 0
        Width = 382
        Height = 575
        Align = alClient
        TabOrder = 0
      end
      object Memo1: TMemo
        Left = 382
        Top = 0
        Width = 185
        Height = 575
        Align = alRight
        Lines.Strings = (
          'Memo1')
        TabOrder = 1
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'fine the file maze tour'
      ImageIndex = 3
      object StringGrid4: TStringGrid
        Left = 0
        Top = 0
        Width = 567
        Height = 575
        Align = alClient
        TabOrder = 0
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 8
    Top = 8
  end
end
