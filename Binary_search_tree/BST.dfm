object Form8: TForm8
  Left = 0
  Top = 0
  Caption = 'Form8'
  ClientHeight = 557
  ClientWidth = 764
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
    Width = 764
    Height = 557
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'BSTree'
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 281
        Height = 529
        Align = alLeft
        TabOrder = 0
        object Label1: TLabel
          Left = 36
          Top = 27
          Width = 38
          Height = 13
          Caption = 'element'
        end
        object Label2: TLabel
          Left = 36
          Top = 115
          Width = 38
          Height = 13
          Caption = 'element'
        end
        object Label3: TLabel
          Left = 67
          Top = 200
          Width = 71
          Height = 13
          Caption = '## of integers'
        end
        object Label4: TLabel
          Left = 80
          Top = 258
          Width = 31
          Height = 13
          Caption = 'Range'
        end
        object Label5: TLabel
          Left = 8
          Top = 360
          Width = 66
          Height = 13
          Caption = 'Search target'
        end
        object Label6: TLabel
          Left = 36
          Top = 431
          Width = 138
          Height = 13
          Caption = 'Traverse the BST recursively'
        end
        object Edit1: TEdit
          Left = 80
          Top = 24
          Width = 81
          Height = 21
          TabOrder = 0
        end
        object Button1: TButton
          Left = 40
          Top = 64
          Width = 121
          Height = 33
          Caption = 'insert into BST'
          TabOrder = 1
          OnClick = Button1Click
        end
        object Edit2: TEdit
          Left = 80
          Top = 112
          Width = 81
          Height = 21
          TabOrder = 2
        end
        object Button2: TButton
          Left = 40
          Top = 152
          Width = 121
          Height = 33
          Caption = 'delete from BST'
          TabOrder = 3
          OnClick = Button2Click
        end
        object Edit3: TEdit
          Left = 40
          Top = 219
          Width = 121
          Height = 21
          TabOrder = 4
        end
        object Edit4: TEdit
          Left = 40
          Top = 277
          Width = 121
          Height = 21
          TabOrder = 5
        end
        object Button3: TButton
          Left = 40
          Top = 304
          Width = 121
          Height = 33
          Caption = 'Random integers'
          TabOrder = 6
          OnClick = Button3Click
        end
        object Edit5: TEdit
          Left = 80
          Top = 357
          Width = 81
          Height = 21
          TabOrder = 7
        end
        object Button4: TButton
          Left = 40
          Top = 384
          Width = 121
          Height = 41
          Caption = 'Search target'
          TabOrder = 8
          OnClick = Button4Click
        end
        object Button5: TButton
          Left = 12
          Top = 458
          Width = 49
          Height = 41
          Caption = 'Prefix'
          TabOrder = 9
          OnClick = Button5Click
        end
        object Button6: TButton
          Left = 67
          Top = 459
          Width = 55
          Height = 39
          Caption = 'Infix'
          TabOrder = 10
          OnClick = Button6Click
        end
        object Button7: TButton
          Left = 128
          Top = 459
          Width = 50
          Height = 39
          Caption = 'Postfix'
          TabOrder = 11
          OnClick = Button7Click
        end
        object Button8: TButton
          Left = 184
          Top = 459
          Width = 91
          Height = 39
          Caption = 'LevelOrder'
          TabOrder = 12
          OnClick = Button8Click
        end
      end
      object Memo1: TMemo
        Left = 281
        Top = 0
        Width = 475
        Height = 529
        Align = alClient
        Lines.Strings = (
          'Memo1')
        TabOrder = 1
      end
    end
  end
end
