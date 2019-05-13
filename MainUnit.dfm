object MainForm: TMainForm
  Left = 360
  Top = 126
  BorderStyle = bsDialog
  Caption = 'TvTester'
  ClientHeight = 787
  ClientWidth = 534
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 19
  object ControlGroupBox: TGroupBox
    Left = 0
    Top = 0
    Width = 529
    Height = 161
    Caption = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077' '
    TabOrder = 0
    object InfoLabel1: TLabel
      Left = 8
      Top = 24
      Width = 113
      Height = 19
      Caption = #1063#1072#1089#1090#1086#1090#1085#1072#1103' '#1089#1077#1090#1082#1072':'
    end
    object InfoLabel2: TLabel
      Left = 8
      Top = 128
      Width = 212
      Height = 19
      Caption = #1042#1099#1093#1086#1076#1085#1086#1081' '#1091#1088#1086#1074#1077#1085#1100' '#1084#1086#1097#1085#1086#1089#1090#1080': '
    end
    object InfoLabel3: TLabel
      Left = 480
      Top = 128
      Width = 34
      Height = 19
      Caption = 'dBuV'
    end
    object FreqTableComboBox: TComboBox
      Left = 128
      Top = 16
      Width = 393
      Height = 27
      Style = csDropDownList
      ItemHeight = 19
      TabOrder = 0
      OnChange = FreqTableComboBoxChange
      Items.Strings = (
        '')
    end
    object StartButton: TBitBtn
      Left = 8
      Top = 56
      Width = 90
      Height = 25
      Caption = #1057#1090#1072#1088#1090
      TabOrder = 1
      OnClick = StartButtonClick
      Kind = bkOK
    end
    object CancelButton: TBitBtn
      Left = 112
      Top = 56
      Width = 90
      Height = 25
      Caption = #1057#1073#1088#1086#1089
      TabOrder = 2
      OnClick = CancelButtonClick
      Kind = bkCancel
    end
    object AddFreqTableButton: TBitBtn
      Left = 8
      Top = 88
      Width = 510
      Height = 25
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1095#1072#1089#1090#1086#1090#1085#1091#1102' '#1090#1072#1073#1083#1080#1094#1091
      TabOrder = 3
      OnClick = AddFreqTableButtonClick
    end
    object SaveButton: TBitBtn
      Left = 320
      Top = 56
      Width = 90
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      TabOrder = 4
      OnClick = SaveButtonClick
    end
    object ProtocolButton: TBitBtn
      Left = 424
      Top = 56
      Width = 90
      Height = 25
      Caption = #1055#1088#1086#1090#1086#1082#1086#1083
      TabOrder = 5
      OnClick = ProtocolButtonClick
    end
    object PowerEdit: TEdit
      Left = 224
      Top = 120
      Width = 249
      Height = 27
      TabOrder = 6
      Text = '100'
    end
    object ConnectionOptionsButton: TButton
      Left = 216
      Top = 56
      Width = 90
      Height = 25
      Caption = #1054#1087#1094#1080#1080
      TabOrder = 7
      OnClick = ConnectionOptionsButtonClick
    end
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 168
    Width = 529
    Height = 617
    Caption = 'P'#1077#1079#1091#1083#1100#1090#1072#1090#1099' '#1080#1079#1084#1077#1088#1077#1085#1080#1081' '
    TabOrder = 1
    object ResultsStringGrid: TStringGrid
      Left = 8
      Top = 24
      Width = 513
      Height = 585
      FixedCols = 0
      RowCount = 2
      TabOrder = 0
    end
  end
end
