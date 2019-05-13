object ConnectionOptionsForm: TConnectionOptionsForm
  Left = 361
  Top = 231
  BorderStyle = bsDialog
  Caption = #1054#1087#1094#1080#1080' '#1087#1086#1076#1082#1083#1102#1095#1077#1085#1080#1103
  ClientHeight = 201
  ClientWidth = 407
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 19
  object Label1: TLabel
    Left = 8
    Top = 16
    Width = 145
    Height = 19
    Caption = 'Ip '#1040#1076#1088#1077#1089#1089' '#1075#1077#1085#1077#1088#1072#1090#1086#1088#1072
  end
  object Label2: TLabel
    Left = 8
    Top = 56
    Width = 113
    Height = 19
    Caption = #1055#1086#1088#1090' '#1075#1077#1085#1077#1088#1072#1090#1086#1088#1072
  end
  object Label3: TLabel
    Left = 8
    Top = 96
    Width = 137
    Height = 19
    Caption = 'Ip '#1040#1076#1088#1077#1089#1089' '#1074#1072#1090#1090#1084#1077#1090#1088#1072
  end
  object Label4: TLabel
    Left = 8
    Top = 136
    Width = 105
    Height = 19
    Caption = #1055#1086#1088#1090' '#1074#1072#1090#1090#1084#1077#1090#1088#1072
  end
  object Label5: TLabel
    Left = 216
    Top = 16
    Width = 4
    Height = 19
    Caption = '.'
  end
  object Label6: TLabel
    Left = 280
    Top = 16
    Width = 4
    Height = 19
    Caption = '.'
  end
  object Label7: TLabel
    Left = 344
    Top = 16
    Width = 4
    Height = 19
    Caption = '.'
  end
  object Label8: TLabel
    Left = 216
    Top = 96
    Width = 4
    Height = 19
    Caption = '.'
  end
  object Label9: TLabel
    Left = 280
    Top = 96
    Width = 4
    Height = 19
    Caption = '.'
  end
  object Label10: TLabel
    Left = 344
    Top = 96
    Width = 4
    Height = 19
    Caption = '.'
  end
  object IpGenEdit1: TEdit
    Left = 160
    Top = 8
    Width = 50
    Height = 27
    TabOrder = 0
  end
  object PortGeneratorEdit: TEdit
    Left = 160
    Top = 48
    Width = 241
    Height = 27
    TabOrder = 1
    Text = '5025'
  end
  object PortPowerrMeterEdit: TEdit
    Left = 160
    Top = 128
    Width = 241
    Height = 27
    TabOrder = 2
    Text = '5025'
  end
  object SaveOptionsButton: TBitBtn
    Left = 248
    Top = 168
    Width = 150
    Height = 25
    Caption = #1059#1089#1090#1072#1085#1086#1074#1080#1090#1100
    TabOrder = 3
    OnClick = SaveOptionsButtonClick
    Kind = bkOK
  end
  object CancelButton: TBitBtn
    Left = 88
    Top = 168
    Width = 150
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 4
    OnClick = CancelButtonClick
    Kind = bkCancel
  end
  object IpGenEdit2: TEdit
    Tag = 1
    Left = 224
    Top = 8
    Width = 50
    Height = 27
    TabOrder = 5
  end
  object IpGenEdit3: TEdit
    Tag = 2
    Left = 288
    Top = 8
    Width = 50
    Height = 27
    TabOrder = 6
  end
  object IpGenEdit4: TEdit
    Tag = 3
    Left = 352
    Top = 8
    Width = 50
    Height = 27
    TabOrder = 7
  end
  object IpPowerMeterEdit1: TEdit
    Tag = 4
    Left = 160
    Top = 88
    Width = 50
    Height = 27
    TabOrder = 8
  end
  object IpPowerMeterEdit2: TEdit
    Tag = 5
    Left = 224
    Top = 88
    Width = 50
    Height = 27
    TabOrder = 9
  end
  object IpPowerMeterEdit3: TEdit
    Tag = 6
    Left = 288
    Top = 88
    Width = 50
    Height = 27
    TabOrder = 10
  end
  object IpPowerMeterEdit4: TEdit
    Tag = 7
    Left = 352
    Top = 88
    Width = 50
    Height = 27
    TabOrder = 11
  end
end
