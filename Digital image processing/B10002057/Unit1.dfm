object Form1: TForm1
  Left = 111
  Top = 94
  Width = 1243
  Height = 631
  Caption = 'Homework'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 120
    Top = 24
    Width = 180
    Height = 29
    Caption = #36984#25799#22294#27284#26684#24335
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = #27161#26999#39636
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 568
    Top = 8
    Width = 143
    Height = 21
    Caption = #39340#36093#20811#30340#31243#24230':'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = #27161#26999#39636
    Font.Style = []
    ParentFont = False
  end
  object Select: TGroupBox
    Left = 328
    Top = 8
    Width = 209
    Height = 65
    Caption = #26684#24335
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #27161#26999#39636
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object BMP: TRadioButton
      Left = 8
      Top = 24
      Width = 113
      Height = 17
      Caption = 'BMP'
      TabOrder = 0
    end
    object JPEG: TRadioButton
      Left = 104
      Top = 24
      Width = 73
      Height = 17
      Caption = 'JPEG'
      TabOrder = 1
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 793
    Width = 1210
    Height = 19
    Panels = <
      item
        Width = 100
      end
      item
        Width = 100
      end
      item
        Width = 250
      end
      item
        Width = 100
      end>
    SimplePanel = False
  end
  object Edit2: TEdit
    Left = 720
    Top = 8
    Width = 50
    Height = 21
    TabOrder = 2
  end
  object Button1: TButton
    Left = 776
    Top = 8
    Width = 70
    Height = 25
    Caption = #30906#23450
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = #27161#26999#39636
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button1Click
  end
  object f: TPageControl
    Left = 16
    Top = 96
    Width = 1105
    Height = 697
    ActivePage = TabSheet14
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #27161#26999#39636
    Font.Style = []
    ParentFont = False
    TabIndex = 14
    TabOrder = 4
    object open_file: TTabSheet
      Caption = #21407#22987#22294
      object ScrollBox1: TScrollBox
        Left = 16
        Top = 6
        Width = 950
        Height = 450
        TabOrder = 0
        object Image1: TImage
          Left = 0
          Top = 0
          Width = 105
          Height = 105
          OnMouseMove = Image1MouseMove
          OnMouseUp = Image1MouseUp
        end
      end
    end
    object TabSheet1: TTabSheet
      Caption = #28784#38542#22294
      ImageIndex = 1
      object ScrollBox2: TScrollBox
        Left = 16
        Top = 6
        Width = 950
        Height = 450
        TabOrder = 0
        object Image2: TImage
          Left = 0
          Top = 0
          Width = 105
          Height = 105
          OnMouseMove = Image1MouseMove
          OnMouseUp = Image1MouseUp
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = #32302#23567#22294
      ImageIndex = 2
      object ScrollBox3: TScrollBox
        Left = 16
        Top = 6
        Width = 950
        Height = 450
        TabOrder = 0
        object Image3: TImage
          Left = 0
          Top = 0
          Width = 105
          Height = 105
          OnMouseMove = Image1MouseMove
          OnMouseUp = Image1MouseUp
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = #39340#36093#20811
      ImageIndex = 3
      object ScrollBox4: TScrollBox
        Left = 16
        Top = 6
        Width = 953
        Height = 450
        TabOrder = 0
        object Image4: TImage
          Left = 0
          Top = 0
          Width = 105
          Height = 105
          OnMouseMove = Image1MouseMove
          OnMouseUp = Image1MouseUp
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = #38477#33394#38542
      ImageIndex = 4
      object ScrollBox5: TScrollBox
        Left = 16
        Top = 6
        Width = 593
        Height = 387
        TabOrder = 0
        object Image5: TImage
          Left = 0
          Top = 0
          Width = 105
          Height = 105
          OnMouseMove = Image1MouseMove
          OnMouseUp = Image1MouseUp
        end
      end
      object Chart1: TChart
        Left = 0
        Top = 400
        Width = 1057
        Height = 273
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        BackWall.Color = clBlack
        BottomWall.Brush.Color = clWhite
        LeftWall.Brush.Color = clWhite
        Title.Text.Strings = (
          'TChart')
        BackColor = clBlack
        TabOrder = 1
        object Series1: TBarSeries
          Marks.ArrowLength = 20
          Marks.Visible = False
          SeriesColor = clRed
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Bar'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
      end
    end
    object TabSheet5: TTabSheet
      Caption = #27169#31946#21270
      ImageIndex = 5
      object Label3: TLabel
        Left = 24
        Top = 480
        Width = 99
        Height = 21
        Caption = 'MASK'#22823#23567':'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = #27161#26999#39636
        Font.Style = []
        ParentFont = False
      end
      object ScrollBox6: TScrollBox
        Left = 16
        Top = 6
        Width = 953
        Height = 450
        TabOrder = 0
        object Image6: TImage
          Left = 0
          Top = 0
          Width = 105
          Height = 105
          OnMouseMove = Image1MouseMove
          OnMouseUp = Image1MouseUp
        end
      end
      object Edit3: TEdit
        Left = 128
        Top = 480
        Width = 65
        Height = 32
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = #27161#26999#39636
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
    end
    object TabSheet6: TTabSheet
      Caption = #37002#32227#20597#28204
      ImageIndex = 6
      object ScrollBox7: TScrollBox
        Left = 16
        Top = 6
        Width = 953
        Height = 450
        TabOrder = 0
        object Image7: TImage
          Left = 0
          Top = 0
          Width = 105
          Height = 105
          OnMouseMove = Image1MouseMove
          OnMouseUp = Image1MouseUp
        end
      end
    end
    object TabSheet7: TTabSheet
      Caption = #37555#21033#21270
      ImageIndex = 7
      object ScrollBox8: TScrollBox
        Left = 16
        Top = 6
        Width = 953
        Height = 450
        TabOrder = 0
        object Image8: TImage
          Left = 0
          Top = 0
          Width = 105
          Height = 105
          OnMouseMove = Image1MouseMove
          OnMouseUp = Image1MouseUp
        end
      end
    end
    object TabSheet8: TTabSheet
      Caption = ' IDFT'
      ImageIndex = 8
      object ScrollBox9: TScrollBox
        Left = 16
        Top = 6
        Width = 953
        Height = 450
        TabOrder = 0
        object Image9: TImage
          Left = 0
          Top = 0
          Width = 105
          Height = 105
          OnMouseMove = Image1MouseMove
          OnMouseUp = Image1MouseUp
        end
      end
    end
    object TabSheet9: TTabSheet
      Caption = 'DFT'
      ImageIndex = 9
      object ScrollBox10: TScrollBox
        Left = 16
        Top = 6
        Width = 953
        Height = 450
        TabOrder = 0
        object Image10: TImage
          Left = 0
          Top = 0
          Width = 105
          Height = 105
          OnMouseMove = Image1MouseMove
          OnMouseUp = Image1MouseUp
        end
      end
    end
    object TabSheet10: TTabSheet
      Caption = 'Lowpass'
      ImageIndex = 10
      object ScrollBox11: TScrollBox
        Left = 16
        Top = 6
        Width = 953
        Height = 450
        TabOrder = 0
        object Image11: TImage
          Left = 0
          Top = 0
          Width = 105
          Height = 105
          OnMouseMove = Image1MouseMove
          OnMouseUp = Image1MouseUp
        end
      end
    end
    object TabSheet11: TTabSheet
      Caption = 'Highpass'
      ImageIndex = 11
      object ScrollBox12: TScrollBox
        Left = 16
        Top = 6
        Width = 953
        Height = 450
        TabOrder = 0
        object Image12: TImage
          Left = 0
          Top = 0
          Width = 105
          Height = 105
          OnMouseMove = Image1MouseMove
          OnMouseUp = Image1MouseUp
        end
      end
    end
    object TabSheet12: TTabSheet
      Caption = 'Highboost'
      ImageIndex = 12
      object ScrollBox13: TScrollBox
        Left = 16
        Top = 6
        Width = 953
        Height = 450
        TabOrder = 0
        object Image13: TImage
          Left = 0
          Top = 0
          Width = 105
          Height = 105
          OnMouseMove = Image1MouseMove
          OnMouseUp = Image1MouseUp
        end
      end
    end
    object TabSheet13: TTabSheet
      Caption = 'Color quantization'
      ImageIndex = 13
      object ScrollBox14: TScrollBox
        Left = 16
        Top = 6
        Width = 953
        Height = 450
        TabOrder = 0
        object Image14: TImage
          Left = 0
          Top = 0
          Width = 105
          Height = 105
          OnMouseMove = Image1MouseMove
          OnMouseUp = Image1MouseUp
        end
      end
    end
    object TabSheet14: TTabSheet
      Caption = 'color'
      ImageIndex = 14
      object ScrollBox15: TScrollBox
        Left = 16
        Top = 6
        Width = 953
        Height = 450
        TabOrder = 0
        object Image15: TImage
          Left = 0
          Top = 0
          Width = 105
          Height = 105
          OnMouseMove = Image1MouseMove
          OnMouseUp = Image1MouseUp
        end
      end
    end
  end
  object Button2: TButton
    Left = 896
    Top = 8
    Width = 75
    Height = 25
    Caption = 'DFT'
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 896
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Lowpass'
    TabOrder = 6
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 1016
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Highpass'
    TabOrder = 7
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 1016
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Highboost'
    TabOrder = 8
    OnClick = Button5Click
  end
  object GroupBox1: TGroupBox
    Left = 584
    Top = 40
    Width = 257
    Height = 49
    TabOrder = 9
    object RadioButton3: TRadioButton
      Left = 8
      Top = 24
      Width = 49
      Height = 17
      Caption = 'Ideal'
      TabOrder = 0
    end
    object RadioButton4: TRadioButton
      Left = 80
      Top = 24
      Width = 81
      Height = 17
      Caption = 'ButterWorth'
      TabOrder = 1
    end
    object RadioButton5: TRadioButton
      Left = 168
      Top = 24
      Width = 73
      Height = 17
      Caption = 'Gaussion'
      TabOrder = 2
    end
  end
  object MainMenu1: TMainMenu
    Top = 3
    object File1: TMenuItem
      Caption = 'File'
      object Open1: TMenuItem
        Caption = 'Open'
        OnClick = Open1Click
      end
      object Save1: TMenuItem
        Caption = 'Save'
        OnClick = Save1Click
      end
      object Close1: TMenuItem
        Caption = 'Close'
        OnClick = Close1Click
      end
    end
    object Edit1: TMenuItem
      Caption = 'Edit'
      object N3: TMenuItem
        Caption = #28784#38542#24433#20687
        OnClick = N3Click
      end
      object N1: TMenuItem
        Caption = #32302#23567#24433#20687
        OnClick = N1Click
        object N4: TMenuItem
          Caption = #24179#22343
          OnClick = N4Click
        end
        object N5: TMenuItem
          Caption = #26368#22823#20540
          OnClick = N5Click
        end
        object N6: TMenuItem
          Caption = #26368#23567#20540
          OnClick = N6Click
        end
      end
      object N2: TMenuItem
        Caption = #38477#33394#38542
        object N2561281: TMenuItem
          Caption = '256->128'
          OnClick = N2561281Click
        end
        object N128641: TMenuItem
          Caption = '128->64'
          OnClick = N128641Click
        end
        object N64321: TMenuItem
          Caption = '64->32'
          OnClick = N64321Click
        end
        object N32161: TMenuItem
          Caption = '32->16'
          OnClick = N32161Click
        end
        object N1681: TMenuItem
          Caption = '16->8'
          OnClick = N1681Click
        end
        object N841: TMenuItem
          Caption = '8->4'
          OnClick = N841Click
        end
        object N421: TMenuItem
          Caption = '4->2'
          OnClick = N421Click
        end
      end
      object N7: TMenuItem
        Caption = #27169#31946#21270
        object N7_1: TMenuItem
          Caption = #24179#22343
          OnClick = N7_1Click
        end
        object N7_2: TMenuItem
          Caption = #20013#20301#25976
          OnClick = N7_2Click
        end
        object N10: TMenuItem
          Caption = #26368#22823
          OnClick = N10Click
        end
        object N11: TMenuItem
          Caption = #26368#23567
          OnClick = N11Click
        end
      end
      object N9: TMenuItem
        Caption = #37002#32227#20597#28204
        object Laplacian1: TMenuItem
          Caption = 'Laplacian'
          OnClick = Laplacian1Click
        end
        object Sobel1: TMenuItem
          Caption = 'Sobel'
          OnClick = Sobel1Click
        end
      end
      object N8: TMenuItem
        Caption = #37555#21033#21270
        object Laplacian2: TMenuItem
          Caption = 'Laplacian'
          OnClick = Laplacian2Click
        end
      end
      object DFT1: TMenuItem
        Caption = 'DFT'
        OnClick = DFT1Click
      end
      object IDFT1: TMenuItem
        Caption = 'IDFT'
        OnClick = IDFT1Click
      end
      object colormodels1: TMenuItem
        Caption = 'color models'
        object RGBYIQ1: TMenuItem
          Caption = 'RGB->YIQ'
          OnClick = RGBYIQ1Click
        end
        object RGBHSI1: TMenuItem
          Caption = 'RGB->HSI'
          OnClick = RGBHSI1Click
        end
        object RGB2: TMenuItem
          Caption = '->RGB'
          OnClick = RGB2Click
        end
      end
      object Colorquantization1: TMenuItem
        Caption = 'Color quantization'
        object RGB1: TMenuItem
          Caption = 'RGB'
          object N2561282: TMenuItem
            Caption = '128'
            OnClick = N2561282Click
          end
          object N126641: TMenuItem
            Caption = '64'
            OnClick = N126641Click
          end
          object N64322: TMenuItem
            Caption = '32'
            OnClick = N64322Click
          end
          object N32162: TMenuItem
            Caption = '16'
            OnClick = N32162Click
          end
          object N1682: TMenuItem
            Caption = '8'
            OnClick = N1682Click
          end
          object N842: TMenuItem
            Caption = '4'
            OnClick = N842Click
          end
          object N422: TMenuItem
            Caption = '2'
            OnClick = N422Click
          end
        end
        object YIQ1: TMenuItem
          Caption = 'YIQ'
          object N1281: TMenuItem
            Caption = '128'
            OnClick = N1281Click
          end
          object N641: TMenuItem
            Caption = '64'
            OnClick = N641Click
          end
          object N321: TMenuItem
            Caption = '32'
            OnClick = N321Click
          end
          object N161: TMenuItem
            Caption = '16'
            OnClick = N161Click
          end
          object N81: TMenuItem
            Caption = '8'
            OnClick = N81Click
          end
          object N41: TMenuItem
            Caption = '4'
            OnClick = N41Click
          end
          object N21: TMenuItem
            Caption = '2'
            OnClick = N21Click
          end
        end
        object HSI1: TMenuItem
          Caption = 'HSI'
        end
      end
    end
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 32
    Top = 3
  end
  object SavePictureDialog1: TSavePictureDialog
    Left = 64
    Top = 3
  end
end
