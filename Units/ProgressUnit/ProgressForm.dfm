object ProgressShowForm: TProgressShowForm
  Left = 309
  Top = 205
  Width = 644
  Height = 153
  BorderIcons = []
  BorderStyle = bsSizeToolWin
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object MainLabel: TLabel
    Left = 151
    Top = 8
    Width = 326
    Height = 29
    Caption = #1048#1076#1077#1090' '#1092#1086#1088#1084#1080#1088#1086#1074#1072#1085#1080#1077' '#1087#1088#1086#1090#1086#1082#1086#1083#1072
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
  end
  object StatusLabel: TLabel
    Left = 16
    Top = 40
    Width = 32
    Height = 19
    Caption = '____'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
  end
  object ProgressBar1: TProgressBar
    Left = 0
    Top = 72
    Width = 625
    Height = 25
    Min = 0
    Max = 100
    TabOrder = 0
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer1Timer
    Left = 496
    Top = 32
  end
end
