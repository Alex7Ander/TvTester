object NewFreqTableForm: TNewFreqTableForm
  Left = 426
  Top = 190
  BorderStyle = bsDialog
  Caption = #1053#1086#1074#1072#1103' '#1095#1072#1089#1090#1086#1090#1085#1072#1103' '#1090#1072#1073#1083#1080#1094#1072
  ClientHeight = 659
  ClientWidth = 424
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 19
  object FreqCountLabel: TLabel
    Left = 8
    Top = 56
    Width = 134
    Height = 19
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1095#1072#1089#1090#1086#1090': '
  end
  object NameLabel: TLabel
    Left = 8
    Top = 16
    Width = 75
    Height = 19
    Caption = #1053#1072#1079#1074#1072#1085#1080#1077': '
  end
  object FreqCountEdit: TEdit
    Left = 152
    Top = 48
    Width = 265
    Height = 27
    TabOrder = 0
    Text = '4'
    OnKeyDown = FreqCountEditKeyDown
  end
  object FreqTableStringGrid: TStringGrid
    Left = 8
    Top = 88
    Width = 409
    Height = 529
    ColCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 1
  end
  object SaveButton: TButton
    Left = 8
    Top = 624
    Width = 409
    Height = 33
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 2
    OnClick = SaveButtonClick
  end
  object NameEdit: TEdit
    Left = 152
    Top = 8
    Width = 265
    Height = 27
    TabOrder = 3
    Text = #1063#1072#1089#1090#1086#1090#1085#1072#1103' '#1089#1077#1090#1082#1072
  end
end
