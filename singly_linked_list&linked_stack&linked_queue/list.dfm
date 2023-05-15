object Form8: TForm8
  Left = 0
  Top = 0
  Caption = 'Form8'
  ClientHeight = 480
  ClientWidth = 665
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 665
    Height = 480
    ActivePage = TabSheet3
    Align = alClient
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'singly linked list'
      object Label1: TLabel
        Left = 40
        Top = 40
        Width = 38
        Height = 13
        Caption = 'element'
      end
      object Label2: TLabel
        Left = 48
        Top = 80
        Width = 30
        Height = 13
        Caption = 'target'
      end
      object Label3: TLabel
        Left = 72
        Top = 128
        Width = 6
        Height = 13
        Caption = 'n'
      end
      object Label4: TLabel
        Left = 168
        Top = 128
        Width = 28
        Height = 13
        Caption = 'range'
      end
      object Memo1: TMemo
        Left = 0
        Top = 176
        Width = 657
        Height = 276
        Align = alBottom
        Lines.Strings = (
          'Memo1')
        TabOrder = 0
      end
      object Edit1: TEdit
        Left = 84
        Top = 37
        Width = 69
        Height = 21
        TabOrder = 1
      end
      object Button1: TButton
        Left = 295
        Top = 31
        Width = 121
        Height = 34
        Caption = 'insert front'
        TabOrder = 2
        OnClick = Button1Click
      end
      object Button2: TButton
        Left = 176
        Top = 31
        Width = 113
        Height = 34
        Caption = 'insert last'
        TabOrder = 3
        OnClick = Button2Click
      end
      object Edit2: TEdit
        Left = 84
        Top = 77
        Width = 69
        Height = 21
        TabOrder = 4
      end
      object Button3: TButton
        Left = 168
        Top = 71
        Width = 121
        Height = 34
        Caption = 'search target'
        TabOrder = 5
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 304
        Top = 71
        Width = 113
        Height = 34
        Caption = 'search insert after'
        TabOrder = 6
        OnClick = Button4Click
      end
      object Button5: TButton
        Left = 423
        Top = 71
        Width = 106
        Height = 34
        Caption = 'search insert before'
        TabOrder = 7
        OnClick = Button5Click
      end
      object Button6: TButton
        Left = 544
        Top = 71
        Width = 89
        Height = 34
        Caption = 'search delete'
        TabOrder = 8
        OnClick = Button6Click
      end
      object Edit3: TEdit
        Left = 84
        Top = 125
        Width = 69
        Height = 21
        TabOrder = 9
      end
      object Edit4: TEdit
        Left = 202
        Top = 125
        Width = 87
        Height = 21
        TabOrder = 10
      end
      object Button7: TButton
        Left = 295
        Top = 121
        Width = 129
        Height = 30
        Caption = 'insert n random number'
        TabOrder = 11
        OnClick = Button7Click
      end
      object Button8: TButton
        Left = 430
        Top = 122
        Width = 99
        Height = 28
        Caption = 'clean list'
        TabOrder = 12
        OnClick = Button8Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'linked stack'
      ImageIndex = 1
      object Label5: TLabel
        Left = 48
        Top = 56
        Width = 38
        Height = 13
        Caption = 'element'
      end
      object Memo2: TMemo
        Left = 0
        Top = 192
        Width = 657
        Height = 260
        Align = alBottom
        Lines.Strings = (
          'Memo2')
        TabOrder = 0
      end
      object Edit5: TEdit
        Left = 92
        Top = 53
        Width = 77
        Height = 21
        TabOrder = 1
      end
      object Button9: TButton
        Left = 200
        Top = 39
        Width = 137
        Height = 49
        Caption = 'push'
        TabOrder = 2
        OnClick = Button9Click
      end
      object Button10: TButton
        Left = 200
        Top = 120
        Width = 137
        Height = 49
        Caption = 'pop'
        TabOrder = 3
        OnClick = Button10Click
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'linked queue'
      ImageIndex = 2
      object Label6: TLabel
        Left = 56
        Top = 32
        Width = 38
        Height = 13
        Caption = 'element'
      end
      object Memo3: TMemo
        Left = 0
        Top = 176
        Width = 657
        Height = 276
        Align = alBottom
        Lines.Strings = (
          'Memo3')
        TabOrder = 0
      end
      object Edit6: TEdit
        Left = 120
        Top = 29
        Width = 121
        Height = 21
        TabOrder = 1
      end
      object Button11: TButton
        Left = 280
        Top = 13
        Width = 137
        Height = 53
        Caption = 'insert'
        TabOrder = 2
        OnClick = Button11Click
      end
      object Button12: TButton
        Left = 280
        Top = 96
        Width = 137
        Height = 57
        Caption = 'delete'
        TabOrder = 3
        OnClick = Button12Click
      end
    end
  end
end