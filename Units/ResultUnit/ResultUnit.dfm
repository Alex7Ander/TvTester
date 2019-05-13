object ResultForm: TResultForm
  Left = 368
  Top = 227
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = #1055#1086#1082#1072#1079#1072#1085#1080#1103
  ClientHeight = 134
  ClientWidth = 531
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 19
  object ResultGroupBox: TGroupBox
    Left = 0
    Top = 0
    Width = 529
    Height = 121
    TabOrder = 0
    object InfoLabel4: TLabel
      Left = 8
      Top = 24
      Width = 305
      Height = 19
      Caption = #1055#1086#1082#1072#1079#1072#1085#1080#1103' '#1087#1086#1074#1077#1088#1103#1077#1084#1086#1075#1086' '#1087#1088#1080#1073#1086#1088#1072' '#1085#1072' '#1095#1072#1089#1090#1086#1090#1077
    end
    object FreqLabel: TLabel
      Left = 320
      Top = 24
      Width = 24
      Height = 19
      Caption = '___'
    end
    object InfoLabel5: TLabel
      Left = 8
      Top = 56
      Width = 86
      Height = 19
      Caption = #1089#1086#1089#1090#1072#1074#1083#1103#1102#1090': '
    end
    object ResultEdit: TEdit
      Left = 96
      Top = 48
      Width = 425
      Height = 27
      TabOrder = 0
    end
    object ContinueButton: TButton
      Left = 8
      Top = 88
      Width = 513
      Height = 25
      Caption = #1055#1088#1086#1076#1086#1083#1078#1080#1090#1100
      TabOrder = 1
      OnClick = ContinueButtonClick
    end
  end
end
