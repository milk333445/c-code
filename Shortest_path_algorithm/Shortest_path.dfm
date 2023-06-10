object Form8: TForm8
  Left = 0
  Top = 0
  Caption = 'Form8'
  ClientHeight = 548
  ClientWidth = 854
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
    Width = 249
    Height = 548
    Align = alLeft
    TabOrder = 0
    object Label1: TLabel
      Left = 18
      Top = 8
      Width = 58
      Height = 16
      Caption = 'G = (V, E)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Panel2: TPanel
      Left = 8
      Top = 30
      Width = 235
      Height = 275
      TabOrder = 0
      object Label2: TLabel
        Left = 10
        Top = 16
        Width = 100
        Height = 13
        Caption = 'Randomly generated'
      end
      object Label3: TLabel
        Left = 24
        Top = 66
        Width = 16
        Height = 16
        Caption = 'n='
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 24
        Top = 88
        Width = 79
        Height = 16
        Caption = 'range(w(e))='
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label5: TLabel
        Left = 24
        Top = 120
        Width = 51
        Height = 16
        Caption = 'if w(e)> '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label6: TLabel
        Left = 24
        Top = 147
        Width = 36
        Height = 16
        Caption = 'w(e)='
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label7: TLabel
        Left = 24
        Top = 174
        Width = 65
        Height = 16
        Caption = 'source.no='
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Button1: TButton
        Left = 24
        Top = 216
        Width = 169
        Height = 49
        Caption = 'generate G'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = Button1Click
      end
      object Edit1: TEdit
        Left = 152
        Top = 65
        Width = 75
        Height = 21
        TabOrder = 1
        Text = '10'
      end
      object Edit2: TEdit
        Left = 152
        Top = 92
        Width = 75
        Height = 21
        TabOrder = 2
        Text = '1000'
      end
      object Edit3: TEdit
        Left = 152
        Top = 119
        Width = 75
        Height = 21
        TabOrder = 3
        Text = '250'
      end
      object Edit4: TEdit
        Left = 152
        Top = 146
        Width = 75
        Height = 21
        TabOrder = 4
        Text = '9999'
      end
      object Edit5: TEdit
        Left = 152
        Top = 173
        Width = 75
        Height = 21
        TabOrder = 5
        Text = '0'
      end
    end
    object Panel3: TPanel
      Left = 8
      Top = 344
      Width = 235
      Height = 200
      TabOrder = 1
      object Label8: TLabel
        Left = 10
        Top = 8
        Width = 72
        Height = 13
        Caption = 'shortest solver'
      end
      object CheckBox2: TCheckBox
        Left = 10
        Top = 27
        Width = 97
        Height = 17
        Caption = 'print result'
        TabOrder = 0
      end
      object Button2: TButton
        Left = 24
        Top = 50
        Width = 169
        Height = 39
        Caption = 'single sort all destination'
        TabOrder = 1
        OnClick = Button2Click
      end
      object Button3: TButton
        Left = 24
        Top = 95
        Width = 169
        Height = 42
        Caption = 'all pairs'
        TabOrder = 2
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 24
        Top = 143
        Width = 169
        Height = 42
        Caption = 'transitive closure'
        TabOrder = 3
        OnClick = Button4Click
      end
    end
    object CheckBox1: TCheckBox
      Left = 14
      Top = 311
      Width = 97
      Height = 17
      Caption = 'echo print G'
      TabOrder = 2
    end
  end
  object PageControl1: TPageControl
    Left = 249
    Top = 0
    Width = 605
    Height = 548
    ActivePage = TabSheet2
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'G adjacent matrix'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 597
        Height = 520
        Align = alClient
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Graph in adjacent matrix'
      ImageIndex = 1
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 597
        Height = 520
        Align = alClient
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'SSAD table'
      ImageIndex = 2
      object StringGrid2: TStringGrid
        Left = 0
        Top = 0
        Width = 597
        Height = 520
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 457
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'All pairs'
      ImageIndex = 3
      object StringGrid3: TStringGrid
        Left = 0
        Top = 0
        Width = 597
        Height = 520
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 457
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Allpairs table'
      ImageIndex = 4
      object StringGrid4: TStringGrid
        Left = 0
        Top = 0
        Width = 597
        Height = 520
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 457
      end
    end
    object TabSheet6: TTabSheet
      Caption = 'Transitive closure'
      ImageIndex = 5
      object StringGrid5: TStringGrid
        Left = 0
        Top = 0
        Width = 597
        Height = 520
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 457
      end
    end
  end
end
