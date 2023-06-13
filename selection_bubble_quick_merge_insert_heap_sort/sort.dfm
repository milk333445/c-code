object Form8: TForm8
  Left = 0
  Top = 0
  Caption = 'Form8'
  ClientHeight = 516
  ClientWidth = 918
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
    Width = 241
    Height = 516
    Align = alLeft
    TabOrder = 0
    object Panel2: TPanel
      Left = 8
      Top = 0
      Width = 227
      Height = 137
      TabOrder = 0
      object Label1: TLabel
        Left = 8
        Top = 8
        Width = 29
        Height = 16
        Caption = 'Input'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 8
        Top = 35
        Width = 44
        Height = 16
        Caption = 'Times='
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 8
        Top = 64
        Width = 17
        Height = 16
        Caption = 'N='
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 8
        Top = 88
        Width = 73
        Height = 16
        Caption = 'Range 1~N='
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Edit1: TEdit
        Left = 96
        Top = 34
        Width = 89
        Height = 21
        TabOrder = 0
        Text = '20'
      end
      object Edit2: TEdit
        Left = 96
        Top = 61
        Width = 89
        Height = 21
        TabOrder = 1
        Text = '1000'
      end
      object Edit3: TEdit
        Left = 96
        Top = 88
        Width = 89
        Height = 21
        TabOrder = 2
        Text = '10000'
      end
    end
    object Panel3: TPanel
      Left = 8
      Top = 143
      Width = 227
      Height = 259
      TabOrder = 1
      object Label5: TLabel
        Left = 8
        Top = 8
        Width = 41
        Height = 16
        Caption = 'Sorting'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object CheckBox1: TCheckBox
        Left = 48
        Top = 24
        Width = 97
        Height = 17
        Caption = 'Selection sort'
        TabOrder = 0
      end
      object CheckBox2: TCheckBox
        Left = 48
        Top = 47
        Width = 97
        Height = 17
        Caption = 'Insertion sort'
        TabOrder = 1
      end
      object CheckBox3: TCheckBox
        Left = 48
        Top = 70
        Width = 97
        Height = 17
        Caption = 'Bubble sort'
        TabOrder = 2
      end
      object CheckBox4: TCheckBox
        Left = 48
        Top = 93
        Width = 137
        Height = 17
        Caption = 'Quick sort (recursive)'
        TabOrder = 3
      end
      object CheckBox5: TCheckBox
        Left = 48
        Top = 116
        Width = 147
        Height = 17
        Caption = 'Quick sort (non-recursive)'
        TabOrder = 4
      end
      object CheckBox6: TCheckBox
        Left = 48
        Top = 139
        Width = 147
        Height = 17
        Caption = 'Merge sort (recursive)'
        TabOrder = 5
      end
      object CheckBox7: TCheckBox
        Left = 48
        Top = 162
        Width = 147
        Height = 17
        Caption = 'Merge sort (non-recursive)'
        TabOrder = 6
      end
      object CheckBox8: TCheckBox
        Left = 48
        Top = 185
        Width = 97
        Height = 17
        Caption = 'Heap sort'
        TabOrder = 7
      end
      object Button1: TButton
        Left = 82
        Top = 208
        Width = 137
        Height = 41
        Caption = 'Draw Diagram'
        TabOrder = 8
        OnClick = Button1Click
      end
      object CheckBox9: TCheckBox
        Left = 8
        Top = 224
        Width = 68
        Height = 17
        Caption = 'See Data'
        TabOrder = 9
      end
    end
    object Memo1: TMemo
      Left = 8
      Top = 408
      Width = 227
      Height = 95
      Lines.Strings = (
        'Memo1')
      ScrollBars = ssVertical
      TabOrder = 2
    end
  end
  object PageControl1: TPageControl
    Left = 241
    Top = 0
    Width = 677
    Height = 516
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 1
    ExplicitWidth = 437
    object TabSheet1: TTabSheet
      Caption = 'Data'
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 669
        Height = 488
        Align = alClient
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssVertical
        TabOrder = 0
        ExplicitWidth = 429
      end
    end
  end
end
