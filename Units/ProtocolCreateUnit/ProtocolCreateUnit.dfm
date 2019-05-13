object ProtocolCreateForm: TProtocolCreateForm
  Left = 440
  Top = 200
  BorderStyle = bsDialog
  Caption = #1057#1086#1079#1076#1072#1090#1100' '#1087#1088#1086#1090#1086#1082#1086#1083
  ClientHeight = 159
  ClientWidth = 409
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 19
  object TypeLabel: TLabel
    Left = 8
    Top = 16
    Width = 51
    Height = 19
    Caption = #1058#1080#1087' '#1057#1048':'
  end
  object SerialNumberLabel: TLabel
    Left = 8
    Top = 56
    Width = 124
    Height = 19
    Caption = #1057#1077#1088#1080#1081#1085#1099#1081' '#1085#1086#1084#1077#1088':'
  end
  object OwnerLabel: TLabel
    Left = 8
    Top = 96
    Width = 71
    Height = 19
    Caption = #1042#1083#1072#1076#1077#1083#1077#1094':'
  end
  object TypeEdit: TEdit
    Left = 152
    Top = 8
    Width = 249
    Height = 27
    TabOrder = 0
  end
  object SerNumberEdit: TEdit
    Left = 152
    Top = 48
    Width = 249
    Height = 27
    TabOrder = 1
  end
  object OwnerEdit: TEdit
    Left = 152
    Top = 88
    Width = 249
    Height = 27
    TabOrder = 2
  end
  object CreateProtocolButton: TButton
    Left = 8
    Top = 128
    Width = 393
    Height = 25
    Caption = #1057#1086#1079#1076#1072#1090#1100' '#1087#1088#1086#1090#1086#1082#1086#1083
    TabOrder = 3
    OnClick = CreateProtocolButtonClick
  end
end
