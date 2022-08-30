object Form1: TForm1
  Left = 201
  Top = 129
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  Caption = 'B381'
  ClientHeight = 475
  ClientWidth = 782
  Color = clBtnFace
  Constraints.MinHeight = 375
  Constraints.MinWidth = 554
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDefault
  Scaled = False
  ShowHint = True
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter0: TSplitter
    Left = 0
    Top = 139
    Width = 782
    Height = 3
    Cursor = crVSplit
    Align = alTop
    MinSize = 9
    OnCanResize = Splitter0CanResize
    OnMoved = Splitter0Moved
    ExplicitTop = 136
  end
  object PanelT: TPanel
    Left = 0
    Top = 29
    Width = 782
    Height = 110
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object ChartI: TChart
      Left = 0
      Top = 0
      Width = 782
      Height = 50
      BackWall.Brush.Color = clWhite
      BackWall.Brush.Style = bsClear
      Legend.MaxNumRows = 0
      Legend.Visible = False
      MarginRight = 1
      Title.Text.Strings = (
        'TChart')
      Title.Visible = False
      OnScroll = ChartIScroll
      BottomAxis.Automatic = False
      BottomAxis.AutomaticMaximum = False
      BottomAxis.AutomaticMinimum = False
      BottomAxis.Labels = False
      BottomAxis.LabelStyle = talValue
      BottomAxis.Maximum = 100.000000000000000000
      BottomAxis.TickOnLabelsOnly = False
      LeftAxis.LabelsMultiLine = True
      LeftAxis.LabelsSize = 15
      LeftAxis.MaximumOffset = 1
      LeftAxis.MinimumOffset = 1
      RightAxis.Visible = False
      TopAxis.Visible = False
      View3D = False
      View3DWalls = False
      OnAfterDraw = ChartIAfterDraw
      Align = alTop
      BevelInner = bvRaised
      BevelOuter = bvLowered
      TabOrder = 0
      OnResize = ChartIResize
      object ScrollBarI: TScrollBar
        Left = 2
        Top = 2
        Width = 16
        Height = 46
        Align = alLeft
        Enabled = False
        Kind = sbVertical
        Max = 2000000000
        PageSize = 100
        TabOrder = 0
        Visible = False
        OnChange = ScrollBarIChange
      end
      object UpDownI: TUpDown
        Left = 13
        Top = 13
        Width = 10
        Height = 21
        Min = -32000
        Max = 32000
        TabOrder = 1
        OnClick = UpDownIClick
      end
      object SeriesI: TFastLineSeries
        Marks.Arrow.Visible = True
        Marks.Callout.Brush.Color = clBlack
        Marks.Callout.Arrow.Visible = True
        Marks.Visible = False
        Title = 'SeriesI'
        LinePen.Color = clRed
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
    end
    object ChartU: TChart
      Left = 0
      Top = 50
      Width = 782
      Height = 43
      BackWall.Brush.Color = clWhite
      BackWall.Brush.Style = bsClear
      Legend.MaxNumRows = 0
      Legend.Visible = False
      MarginRight = 1
      Title.Text.Strings = (
        'TChart')
      Title.Visible = False
      OnScroll = ChartUScroll
      BottomAxis.Automatic = False
      BottomAxis.AutomaticMaximum = False
      BottomAxis.AutomaticMinimum = False
      BottomAxis.AxisValuesFormat = '#,##0.#'
      BottomAxis.LabelsSize = 12
      BottomAxis.Maximum = 100.000000000000000000
      LeftAxis.LabelsSize = 15
      LeftAxis.MaximumOffset = 1
      LeftAxis.MinimumOffset = 1
      RightAxis.Visible = False
      TopAxis.Visible = False
      View3D = False
      View3DWalls = False
      OnAfterDraw = ChartIAfterDraw
      Align = alClient
      BevelInner = bvRaised
      BevelOuter = bvLowered
      TabOrder = 1
      OnResize = ChartUResize
      object ScrollBarU: TScrollBar
        Left = 2
        Top = 2
        Width = 16
        Height = 39
        Align = alLeft
        Enabled = False
        Kind = sbVertical
        Max = 2000000000
        PageSize = 100
        TabOrder = 0
        Visible = False
      end
      object UpDownU: TUpDown
        Left = 13
        Top = 13
        Width = 10
        Height = 21
        Min = -32000
        Max = 32000
        TabOrder = 1
        OnClick = UpDownUClick
      end
      object UpDown3: TUpDown
        Left = 24
        Top = 35
        Width = 17
        Height = 11
        Min = -32000
        Max = 32000
        Orientation = udHorizontal
        TabOrder = 2
        OnClick = UpDown3Click
      end
      object SeriesU: TFastLineSeries
        Marks.Arrow.Visible = True
        Marks.Callout.Brush.Color = clBlack
        Marks.Callout.Arrow.Visible = True
        Marks.Visible = False
        SeriesColor = clBlue
        Title = 'SeriesU'
        LinePen.Color = clBlue
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
    end
    object ChartScrollBar1: TChartScrollBar
      Left = 0
      Top = 93
      Width = 782
      Height = 17
      Align = alBottom
      LargeChange = 3000
      PageSize = 125000
      SmallChange = 300
      TabOrder = 2
      Visible = False
    end
  end
  object PanelB: TPanel
    Left = 0
    Top = 142
    Width = 782
    Height = 314
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object Splitter1: TSplitter
      Left = 112
      Top = 0
      Height = 314
      ExplicitLeft = 108
      ExplicitHeight = 434
    end
    object Panel2: TPanel
      Left = 0
      Top = 0
      Width = 112
      Height = 314
      Align = alLeft
      BevelOuter = bvSpace
      TabOrder = 0
      OnResize = Panel2Resize
      object CheckListBox1: TCheckListBox
        Left = 1
        Top = 217
        Width = 110
        Height = 96
        OnClickCheck = CheckListBox1ClickCheck
        Align = alClient
        ItemHeight = 13
        TabOrder = 0
        OnClick = CheckListBox1Click
      end
      object RzPanel1: TRzPanel
        Left = 1
        Top = 1
        Width = 110
        Height = 216
        Align = alTop
        BorderOuter = fsNone
        TabOrder = 1
        object RzLabel1: TRzLabel
          Left = 5
          Top = 39
          Width = 12
          Height = 13
          Caption = 'T1'
        end
        object RzLabel2: TRzLabel
          Left = 5
          Top = 64
          Width = 12
          Height = 13
          Caption = 'T2'
        end
        object RzLabel3: TRzLabel
          Left = 7
          Top = 83
          Width = 12
          Height = 13
          Caption = 'Ea'
        end
        object RzLabel4: TRzLabel
          Left = 79
          Top = 39
          Width = 21
          Height = 13
          Caption = #1089#1077#1082'.'
        end
        object RzLabel5: TRzLabel
          Left = 79
          Top = 64
          Width = 21
          Height = 13
          Caption = #1089#1077#1082'.'
        end
        object RzLabel6: TRzLabel
          Left = 79
          Top = 83
          Width = 12
          Height = 13
          Caption = #1084#1042
        end
        object RzLabel7: TRzLabel
          Left = 82
          Top = 128
          Width = 21
          Height = 13
          Caption = #1089#1077#1082'.'
        end
        object RzLabel8: TRzLabel
          Left = 4
          Top = 128
          Width = 18
          Height = 13
          Caption = 'T3*'
        end
        object RzLabel9: TRzLabel
          Left = 7
          Top = 149
          Width = 7
          Height = 13
          Caption = 'N'
        end
        object RzGlyphStatus1: TRzGlyphStatus
          Left = 20
          Top = 100
          Width = 24
          FrameStyle = fsNone
          ImageIndex = 26
          Images = ToolBarImageList
        end
        object RzLine1: TRzLine
          Left = 33
          Top = 100
          Width = 82
          Height = 20
        end
        object RzLabel10: TRzLabel
          Left = 7
          Top = 173
          Width = 12
          Height = 13
          Caption = 'En'
        end
        object RzLabel11: TRzLabel
          Left = 82
          Top = 173
          Width = 12
          Height = 13
          Caption = #1084#1042
        end
        object RzLine2: TRzLine
          Left = 0
          Top = 182
          Width = 110
          Height = 20
        end
        object RzNumericEdit3: TRzNumericEdit
          Left = 25
          Top = 77
          Width = 48
          Height = 21
          TabOrder = 0
          Value = -120.000000000000000000
          DisplayFormat = ',0;-,0'
        end
        object RzNumericEdit2: TRzNumericEdit
          Left = 25
          Top = 54
          Width = 48
          Height = 21
          TabOrder = 1
          Value = 180.000000000000000000
          DisplayFormat = ',0;(,0)'
        end
        object RzNumericEdit1: TRzNumericEdit
          Left = 25
          Top = 31
          Width = 48
          Height = 21
          TabOrder = 2
          Value = 60.000000000000000000
          DisplayFormat = ',0;(,0)'
        end
        object RzComboBox1: TRzComboBox
          Left = 3
          Top = 5
          Width = 104
          Height = 21
          TabOrder = 3
          OnChange = RzComboBox1Change
        end
        object RzNumericEdit4: TRzNumericEdit
          Left = 28
          Top = 121
          Width = 48
          Height = 21
          TabOrder = 4
          Value = 60.000000000000000000
          DisplayFormat = ',0;(,0)'
        end
        object RzSpinEdit1: TRzSpinEdit
          Left = 28
          Top = 144
          Width = 47
          Height = 21
          Max = 100.000000000000000000
          Value = 5.000000000000000000
          TabOrder = 5
        end
        object CheckBox1: TCheckBox
          Left = 5
          Top = 101
          Width = 17
          Height = 17
          TabOrder = 6
        end
        object RzNumericEdit5: TRzNumericEdit
          Left = 28
          Top = 167
          Width = 48
          Height = 21
          TabOrder = 7
          Value = 40.000000000000000000
          DisplayFormat = ',0;-,0'
        end
        object CheckBox2: TCheckBox
          Left = 8
          Top = 196
          Width = 20
          Height = 17
          Checked = True
          State = cbChecked
          TabOrder = 8
          OnClick = CheckBox2Click
        end
        object CheckBox3: TCheckBox
          Left = 34
          Top = 196
          Width = 71
          Height = 17
          Caption = 'Smoothed'
          TabOrder = 9
          Visible = False
          OnClick = CheckBox3Click
        end
      end
    end
    object Panel3: TPanel
      Left = 115
      Top = 0
      Width = 667
      Height = 314
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      OnResize = Panel3Resize
      object Panel1: TPanel
        Left = 6
        Top = 0
        Width = 667
        Height = 290
        BevelOuter = bvNone
        TabOrder = 0
        OnResize = Panel1Resize
        object Splitter2: TSplitter
          Left = 0
          Top = 157
          Width = 667
          Height = 3
          Cursor = crVSplit
          Align = alTop
          MinSize = 9
          OnCanResize = Splitter2CanResize
          OnMoved = Splitter1Moved
          ExplicitTop = 144
          ExplicitWidth = 653
        end
        object Chart: TChart
          Left = 0
          Top = 0
          Width = 667
          Height = 157
          BackWall.Brush.Color = clWhite
          BackWall.Brush.Style = bsClear
          Legend.MaxNumRows = 0
          Legend.Visible = False
          MarginBottom = 0
          MarginTop = 3
          Title.Text.Strings = (
            'TChart')
          Title.Visible = False
          OnScroll = ChartScroll
          OnUndoZoom = ChartUndoZoom
          OnZoom = ChartZoom
          BottomAxis.Axis.Width = 1
          BottomAxis.AxisValuesFormat = '##0.###'
          BottomAxis.LabelsSize = 15
          BottomAxis.LabelStyle = talValue
          BottomAxis.MaximumOffset = 1
          BottomAxis.MinimumOffset = 1
          BottomAxis.TickOnLabelsOnly = False
          DepthAxis.Axis.Width = 1
          DepthTopAxis.Axis.Width = 1
          LeftAxis.Axis.Width = 1
          LeftAxis.AxisValuesFormat = '##0.###'
          LeftAxis.LabelsSize = 20
          LeftAxis.LabelStyle = talValue
          LeftAxis.MaximumOffset = 1
          LeftAxis.MinimumOffset = 1
          LeftAxis.TickOnLabelsOnly = False
          RightAxis.Axis.Width = 1
          RightAxis.Visible = False
          TopAxis.Axis.Width = 1
          TopAxis.Visible = False
          View3D = False
          View3DWalls = False
          OnAfterDraw = ChartAfterDraw
          Align = alTop
          BevelInner = bvRaised
          BevelOuter = bvLowered
          TabOrder = 0
          OnClick = ChartClick
          OnResize = ChartResize
          OnMouseWheel = ChartMouseWheel
          OnMouseWheelDown = ChartMouseWheelDown
          PrintMargins = (
            15
            38
            15
            38)
          object UpDownY1: TUpDown
            Left = 1
            Top = 64
            Width = 12
            Height = 21
            Min = -32000
            Max = 32000
            TabOrder = 0
            Wrap = True
            OnClick = UpDownY1Click
          end
          object UpDown2: TUpDown
            Left = 1
            Top = 141
            Width = 18
            Height = 16
            Min = -32000
            Max = 32000
            Orientation = udHorizontal
            TabOrder = 1
            Wrap = True
            OnClick = UpDown2Click
          end
          object PointsI: TPointSeries
            Marks.Arrow.Visible = True
            Marks.Callout.Brush.Color = clBlack
            Marks.Callout.Arrow.Visible = True
            Marks.Visible = False
            Title = 'PointsI'
            ClickableLine = False
            Pointer.Brush.Gradient.EndColor = clRed
            Pointer.Gradient.EndColor = clRed
            Pointer.HorizSize = 5
            Pointer.InflateMargins = True
            Pointer.Style = psCross
            Pointer.VertSize = 5
            Pointer.Visible = True
            XValues.Name = 'X'
            XValues.Order = loAscending
            YValues.Name = 'Y'
            YValues.Order = loNone
          end
          object ChartTool1: TColorLineTool
            Active = False
            DragRepaint = True
            Draw3D = False
            OnBeginDragLine = ChartTool1DragLine
            OnDragLine = ChartTool1DragLine
            OnEndDragLine = ChartTool1DragLine
            AxisID = 2
          end
          object ChartTool2: TCursorTool
            Active = False
            FollowMouse = True
            OnChange = ChartTool2Change
          end
          object ChartTool3: TAnnotationTool
            AutoSize = False
            Callout.Brush.Color = clBlack
            Callout.Arrow.Visible = False
            Position = ppRightTop
            PositionUnits = muPercent
            Shape.Brush.Gradient.SubGradient.Transparency = 44
            Shape.Emboss.Color = clWhite
            Shape.Emboss.Transparency = 7
            Shape.Font.Height = -17
            Shape.Font.Name = 'Tahoma'
            Shape.Gradient.SubGradient.Transparency = 44
            Shape.Shadow.Visible = False
            Shape.Transparency = 35
            Shape.AutoSize = False
            Shape.Margins.Right = 18
            Shape.Text = '00.0000 '#1084#1082#1040
            Shape.TextAlignment = taCenter
            Text = '00.0000 '#1084#1082#1040
            TextAlignment = taCenter
            Height = 25
            Width = 116
          end
          object LineTool: TCursorTool
            Active = False
            FollowMouse = True
            Pen.Style = psDot
            Style = cssVertical
            OnChange = LineToolChange
          end
          object ChartTool5: TAnnotationTool
            Active = False
            Callout.Brush.Color = clBlack
            Callout.Arrow.Visible = False
            Shape.Font.Height = -17
            Shape.Font.Name = 'Tahoma'
            Shape.Shadow.Visible = False
            Shape.Transparency = 35
            Shape.Text = '00.000 '#1089'. 00.000 '#1084#1082#1040
            Shape.TextAlignment = taCenter
            Text = '00.000 '#1089'. 00.000 '#1084#1082#1040
            TextAlignment = taCenter
          end
        end
        object Chart1: TChart
          Left = 0
          Top = 160
          Width = 667
          Height = 130
          BackWall.Brush.Color = clWhite
          BackWall.Brush.Style = bsClear
          Legend.MaxNumRows = 0
          Legend.Visible = False
          MarginBottom = 0
          MarginTop = 3
          Title.Text.Strings = (
            'TChart')
          Title.Visible = False
          OnScroll = Chart1Scroll
          OnUndoZoom = Chart1UndoZoom
          OnZoom = Chart1Zoom
          BottomAxis.Axis.Width = 1
          BottomAxis.LabelsSize = 15
          BottomAxis.MaximumOffset = 1
          BottomAxis.MinimumOffset = 1
          DepthAxis.Axis.Width = 1
          DepthTopAxis.Axis.Width = 1
          LeftAxis.Axis.Width = 1
          LeftAxis.LabelsSize = 20
          LeftAxis.MaximumOffset = 1
          LeftAxis.MinimumOffset = 1
          RightAxis.Axis.Width = 1
          RightAxis.Visible = False
          TopAxis.Axis.Width = 1
          TopAxis.Visible = False
          View3D = False
          View3DWalls = False
          Align = alClient
          BevelInner = bvRaised
          BevelOuter = bvLowered
          TabOrder = 1
          OnResize = ChartResize
          object UpDownY2: TUpDown
            Left = 4
            Top = 64
            Width = 12
            Height = 21
            Min = -32000
            Max = 32000
            TabOrder = 0
            Wrap = True
            OnClick = UpDownY2Click
          end
          object UpDown1: TUpDown
            Left = 1
            Top = 114
            Width = 18
            Height = 16
            Min = -32000
            Max = 32000
            Orientation = udHorizontal
            TabOrder = 1
            Wrap = True
            OnClick = UpDown1Click
          end
          object PointsU: TPointSeries
            Marks.Arrow.Visible = True
            Marks.Callout.Brush.Color = clBlack
            Marks.Callout.Arrow.Visible = True
            Marks.Visible = False
            Title = 'PointsU'
            ClickableLine = False
            Pointer.Brush.Gradient.EndColor = clRed
            Pointer.Gradient.EndColor = clRed
            Pointer.HorizSize = 5
            Pointer.InflateMargins = True
            Pointer.Style = psCross
            Pointer.VertSize = 5
            Pointer.Visible = True
            XValues.Name = 'X'
            XValues.Order = loAscending
            YValues.Name = 'Y'
            YValues.Order = loNone
          end
          object ChartTool4: TAnnotationTool
            AutoSize = False
            Callout.Brush.Color = clBlack
            Callout.Arrow.Visible = False
            Position = ppRightTop
            PositionUnits = muPercent
            Shape.Brush.Gradient.SubGradient.Transparency = 44
            Shape.Emboss.Color = clWhite
            Shape.Emboss.Transparency = 7
            Shape.Font.Height = -17
            Shape.Font.Name = 'Tahoma'
            Shape.Gradient.SubGradient.Transparency = 44
            Shape.Shadow.Visible = False
            Shape.Transparency = 35
            Shape.AutoSize = False
            Shape.Margins.Right = 18
            Shape.Text = '00.0000 '#1084#1042
            Shape.TextAlignment = taCenter
            Text = '00.0000 '#1084#1042
            TextAlignment = taCenter
            Height = 25
            Width = 116
          end
        end
      end
      object ScrollBarY1: TScrollBar
        Left = 2
        Top = 2
        Width = 8
        Height = 149
        Kind = sbVertical
        Max = 1000000
        PageSize = 0
        TabOrder = 1
        Visible = False
        OnScroll = ScrollBarY1Scroll
      end
      object ScrollBarY2: TScrollBar
        Left = 2
        Top = 163
        Width = 8
        Height = 126
        Kind = sbVertical
        Max = 1000000
        PageSize = 0
        TabOrder = 2
        Visible = False
        OnScroll = ScrollBarY2Scroll
      end
      object UpDownX: TUpDown
        Left = 2
        Top = 296
        Width = 16
        Height = 16
        Min = -32000
        Max = 32000
        Orientation = udHorizontal
        TabOrder = 3
        Visible = False
        Wrap = True
        OnClick = U
      end
      object ScrollBarX: TScrollBar
        Left = 15
        Top = 296
        Width = 659
        Height = 16
        Max = 1000000
        PageSize = 0
        TabOrder = 4
        Visible = False
        OnScroll = ScrollBarXScroll
      end
    end
  end
  object RzToolbar1: TRzToolbar
    Left = 0
    Top = 0
    Width = 782
    Height = 29
    Images = ToolBarImageList
    BorderInner = fsNone
    BorderOuter = fsGroove
    BorderSides = [sdTop]
    BorderWidth = 0
    TabOrder = 2
    VisualStyle = vsGradient
    ToolbarControls = (
      BtnNextRecord
      RzSpacer7
      RzToolButton1
      RzToolButton2
      RzToolButton3
      RzSpacer1
      BtnExit
      RzSpacer6
      RzToolButton4
      BtnClear
      RzSpacer2
      RzToolButton5
      RzSpacer3
      Edit4
      RzSpacer4
      RzToolButton6
      RzToolButton8
      RzSpacer5
      RzToolButton7
      RzSpacer8)
    object RzToolButton1: TRzToolButton
      Left = 37
      Top = 2
      Hint = #1053#1086#1074#1099#1081' '#1101#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090
      ImageIndex = 4
      OnClick = Menu_NewClick
    end
    object RzToolButton2: TRzToolButton
      Left = 62
      Top = 2
      ImageIndex = 2
      Visible = False
    end
    object RzToolButton3: TRzToolButton
      Left = 87
      Top = 2
      Hint = #1054#1090#1082#1088#1099#1090#1100
      ImageIndex = 0
      OnClick = N9Click
    end
    object RzToolButton4: TRzToolButton
      Left = 159
      Top = 2
      Hint = #1057#1082#1088#1099#1090#1100'\'#1087#1086#1082#1072#1079#1072#1090#1100' '#1080#1085#1076#1080#1082#1072#1090#1086#1088#1099
      ImageIndex = 6
      OnClick = RzToolButton4Click
    end
    object RzSpacer1: TRzSpacer
      AlignWithMargins = True
      Left = 115
      Top = 2
      Grooved = True
    end
    object RzSpacer2: TRzSpacer
      AlignWithMargins = True
      Left = 212
      Top = 2
      Grooved = True
    end
    object RzToolButton5: TRzToolButton
      Left = 223
      Top = 2
      AllowAllUp = True
      ImageIndex = 8
      OnClick = RzToolButton5Click
    end
    object RzSpacer3: TRzSpacer
      Left = 248
      Top = 2
    end
    object RzSpacer4: TRzSpacer
      Left = 327
      Top = 2
    end
    object RzToolButton6: TRzToolButton
      Left = 335
      Top = 2
      AllowAllUp = True
      DownIndex = 11
      ImageIndex = 10
      OnClick = RzToolButton6Click
    end
    object RzSpacer5: TRzSpacer
      AlignWithMargins = True
      Left = 388
      Top = 2
      Grooved = True
    end
    object RzToolButton7: TRzToolButton
      Left = 399
      Top = 2
      Width = 28
      DropDownMenu = PopupMenu1
      ImageIndex = 12
      ShowCaption = True
      UseToolbarShowCaption = False
      Enabled = False
      OnClick = RzToolButton7Click
    end
    object BtnExit: TRzToolButton
      Left = 126
      Top = 2
      Hint = #1042#1099#1081#1090#1080' '#1080#1079' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
      DisabledIndex = 17
      ImageIndex = 16
      Caption = 'Exit'
      OnClick = BtnExitClick
    end
    object RzSpacer6: TRzSpacer
      Left = 151
      Top = 2
      Grooved = True
    end
    object BtnClear: TRzToolButton
      Left = 184
      Top = 2
      Hint = 'Clear'
      DisabledIndex = 19
      ImageIndex = 18
      Caption = 'Clear'
      Visible = False
      OnClick = BtnClearClick
    end
    object RzToolButton8: TRzToolButton
      Left = 360
      Top = 2
      ImageIndex = 20
      OnClick = RzToolButton8Click
    end
    object BtnNextRecord: TRzToolButton
      Left = 4
      Top = 2
      Hint = 'Next Record'
      DisabledIndex = 25
      ImageIndex = 24
      Caption = 'Next Record'
      Enabled = False
      OnClick = Menu_NewSeriaClick
    end
    object RzSpacer7: TRzSpacer
      Left = 29
      Top = 2
      Grooved = True
    end
    object RzSpacer8: TRzSpacer
      Left = 427
      Top = 2
    end
    object Edit4: TEdit
      Left = 256
      Top = 4
      Width = 71
      Height = 21
      Enabled = False
      TabOrder = 0
      Text = '0,0000'
      OnChange = Edit4Change
      OnExit = Edit4Exit
    end
  end
  object RzStatusBar1: TRzStatusBar
    Left = 0
    Top = 456
    Width = 782
    Height = 19
    BorderInner = fsNone
    BorderOuter = fsNone
    BorderSides = [sdLeft, sdTop, sdRight, sdBottom]
    BorderWidth = 0
    TabOrder = 3
    object RzStatusPane1: TRzStatusPane
      Left = 0
      Top = 0
      Height = 19
      Align = alLeft
      ExplicitLeft = 782
      ExplicitHeight = 20
    end
  end
  object MainMenu1: TMainMenu
    Images = ImageList1
    Left = 464
    Top = 368
    object Menu_File: TMenuItem
      Caption = #1060#1072#1081#1083
      OnClick = Menu_FileClick
      object N7: TMenuItem
        Caption = #1069#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090
        ImageIndex = 20
        object N8: TMenuItem
          Caption = #1053#1086#1074#1099#1081
          ImageIndex = 12
          OnClick = Menu_NewClick
        end
        object N9: TMenuItem
          Caption = #1054#1090#1082#1088#1099#1090#1100'...'
          ImageIndex = 5
          OnClick = N9Click
        end
        object N10: TMenuItem
          Caption = #1047#1072#1082#1088#1099#1090#1100
          Visible = False
          OnClick = N10Click
        end
      end
      object N2: TMenuItem
        Caption = #1057#1077#1088#1080#1103
        Enabled = False
        object N3: TMenuItem
          Caption = #1053#1086#1074#1072#1103
          ImageIndex = 16
          OnClick = Menu_NewSeriaClick
        end
        object N13: TMenuItem
          Caption = '-'
          Visible = False
        end
        object N4: TMenuItem
          Caption = #1048#1079#1084#1077#1085#1080#1090#1100
          Enabled = False
          Visible = False
        end
        object N5: TMenuItem
          Caption = #1054#1095#1080#1089#1090#1080#1090#1100
          ImageIndex = 14
          Visible = False
          OnClick = MenuClearClick
        end
        object N6: TMenuItem
          Caption = #1059#1076#1072#1083#1080#1090#1100
          Enabled = False
          Visible = False
        end
      end
      object Menu_Comment: TMenuItem
        Caption = #1050#1086#1084#1077#1085#1090#1072#1088#1080#1081
        ImageIndex = 18
        Visible = False
        OnClick = Menu_CommentClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object MenuReset: TMenuItem
        Caption = #1056#1077#1089#1090#1072#1088#1090' '#1087#1088#1080#1073#1086#1088#1072
        ImageIndex = 24
        OnClick = MenuResetClick
      end
      object Menu__1: TMenuItem
        Caption = '-'
      end
      object Menu_Print: TMenuItem
        Caption = #1055#1077#1095#1072#1090#1100
        Enabled = False
        Visible = False
        OnClick = Menu_PrintClick
      end
      object Menu_Separator1: TMenuItem
        Caption = '-'
        Visible = False
      end
      object Menu_Exit: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        ImageIndex = 0
        OnClick = BtnExitClick
      end
    end
    object N12: TMenuItem
      Caption = #1057#1072#1084#1086#1087#1080#1089#1077#1094
      Visible = False
      OnClick = N12Click
    end
    object Menu_Edit: TMenuItem
      Caption = '&'#1055#1088#1072#1074#1082#1072
      Visible = False
      object fft1: TMenuItem
        Caption = 'fft'
        Visible = False
        OnClick = fft1Click
      end
      object N11: TMenuItem
        Caption = #1057#1075#1083#1072#1078#1080#1074#1072#1085#1080#1077
        Visible = False
        OnClick = N11Click
      end
      object Menu_Delete: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100
        OnClick = Menu_DeleteClick
      end
    end
    object Menu_Options: TMenuItem
      Caption = '&'#1053#1072#1089#1090#1088#1086#1081#1082#1080
      OnClick = Menu_OptionsClick
    end
    object N14: TMenuItem
      Caption = '?'
      object N15: TMenuItem
        Caption = #1054' '#1055#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = N15Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = #1060#1072#1081#1083#1099' '#1087#1088#1086#1075#1088#1072#1084#1084#1099'|*.bn|'#1058#1077#1082#1089#1090#1086#1074#1099#1077' '#1092#1072#1081#1083#1099'|*.txt'
    OnTypeChange = OpenDialog1TypeChange
    Left = 528
    Top = 368
  end
  object SaveDialog1: TSaveDialog
    Filter = #1060#1072#1081#1083#1099' '#1087#1088#1086#1075#1088#1072#1084#1084#1099'|*.bn|'#1058#1077#1082#1089#1090#1086#1074#1099#1077' '#1092#1072#1081#1083#1099'|*.txt'
    OnTypeChange = SaveDialog1TypeChange
    Left = 464
    Top = 328
  end
  object Timer1: TTimer
    Interval = 100
    OnTimer = Timer1Timer
    Left = 465
    Top = 238
  end
  object ImageList1: TImageList
    Left = 464
    Top = 288
    Bitmap = {
      494C010120008000A40010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000009000000001002000000000000090
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000E2EF
      F100E5E5E500E5E5E500E5E5E500E5E5E500E5E5E50000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E5E5E500C0C0
      C0009999990080808000808080009999990099A8AC00C0C0C000CCCCCC00E2EF
      F10000000000000000000000000000000000000000000000000000000000C0C0
      C00099999900999999008080800099999900CCCCCC00C0C0C000CCCCCC000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000CCCCCC00CCCC
      CC00CCCC9900CCCC9900CCCC990099999900808080006666660080808000B2B2
      B200E5E5E5000000000000000000000000000000000000000000CCCCCC00CCCC
      CC00C0C0C000C0C0C000C0C0C00099999900808080009999990080808000B2B2
      B200000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000E5E5E500FFFFCC00F2EA
      BF00F2EABF00CCCC9900ECC6D900FFCC9900F2EABF00F2EABF00808080006666
      660099999900E5E5E50000000000000000000000000000000000000000000000
      000000000000C0C0C000CCCCCC00C0C0C0000000000000000000808080009999
      990099999900000000000000000000000000000000000000FF00000099000000
      99000000990000000000000000000000000000000000000000000000FF000000
      99000000990000009900000000000000000000000000B2B2B200808080008080
      8000808080000000000000000000000000000000000000000000B2B2B2008080
      80008080800080808000000000000000000000000000FFCC9900F2EABF00F2EA
      BF00CCCCCC00ECC6D90000990000CCCCCC00CCCCCC00CCCCCC00FFFFCC00B2B2
      B200646F7100CCCCCC00000000000000000000000000C0C0C000000000000000
      0000CCCCCC00CCCCCC0099999900CCCCCC00CCCCCC00CCCCCC0000000000B2B2
      B20099999900CCCCCC000000000000000000000000000000FF000000CC000000
      CC000000CC00000099000000000000000000000000000000FF000000CC000000
      CC000000CC0000009900000000000000000000000000B2B2B200999999009999
      99009999990080808000000000000000000000000000B2B2B200999999009999
      99009999990080808000000000000000000000000000FFCC9900FFCC9900E5E5
      E500ECC6D900ECC6D9000099000000990000009900000099000099CC9900F2EA
      BF0080808000B2B2B200E2EFF1000000000000000000C0C0C000C0C0C0000000
      0000CCCCCC00CCCCCC0099999900999999009999990099999900B2B2B2000000
      000080808000B2B2B200000000000000000000000000000000000000FF000000
      CC000000CC000000CC0000009900000000000000FF000000CC000000CC000000
      CC00000099000000000000000000000000000000000000000000B2B2B2009999
      990099999900999999008080800000000000B2B2B20099999900999999009999
      990080808000000000000000000000000000E5E5E500FFCC9900E5E5E500E5E5
      E500ECC6D900C0C0C000009900000099000066CC6600CCFFCC0033CC3300FFCC
      990080808000B2B2B200E2EFF1000000000000000000C0C0C000000000000000
      0000CCCCCC00C0C0C0009999990099999900CCCCCC000000000099999900C0C0
      C00080808000B2B2B20000000000000000000000000000000000000000000000
      FF000000CC000000CC000000CC00000099000000CC000000CC000000CC000000
      990000000000000000000000000000000000000000000000000000000000B2B2
      B200999999009999990099999900808080009999990099999900999999008080
      800000000000000000000000000000000000F2EABF00F2EABF00FFFFFF00FFFF
      FF00CC999900ECC6D90099CC9900CCCC990033CC330099CC990099CC9900CCCC
      99009999990099999900E5E5E50000000000CCCCCC0000000000000000000000
      000099999900CCCCCC00B2B2B200C0C0C00099999900B2B2B200B2B2B200C0C0
      C000999999009999990000000000000000000000000000000000000000000000
      00000000FF000000CC000000CC000000CC000000CC000000CC00000099000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000B2B2B2009999990099999900999999009999990099999900808080000000
      000000000000000000000000000000000000F2EABF00FFFFCC00FFFFFF00ECC6
      D900CC999900ECC6D90066993300FFFFFF0066CC66000099000000990000F2EA
      BF009999990099999900E5E5E50000000000CCCCCC000000000000000000CCCC
      CC0099999900CCCCCC009999990000000000CCCCCC0099999900999999000000
      0000999999009999990000000000000000000000000000000000000000000000
      0000000000000000FF000000CC000000CC000000CC0000009900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000B2B2B20099999900999999009999990080808000000000000000
      000000000000000000000000000000000000F2EABF00FFFFFF00FFFFFF00ECC6
      D900ECC6D900ECC6D90099CC990000990000339933000099000000990000F2EA
      BF00CCCC990080808000E5E5E50000000000CCCCCC000000000000000000CCCC
      CC00CCCCCC00CCCCCC00B2B2B200999999009999990099999900999999000000
      0000C0C0C0008080800000000000000000000000000000000000000000000000
      00000000FF000000CC000000CC000000CC000000CC000000CC00000099000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000B2B2B2009999990099999900999999009999990099999900808080000000
      000000000000000000000000000000000000FFFFCC00FFFFCC00FFFFCC00FFFF
      FF00FFFFFF00E2EFF100E5E5E50099CC990099CC990066CC660000990000FFFF
      CC00C0C0C00080808000CCCCCC0000000000CCCCCC0000000000000000000000
      0000000000000000000000000000B2B2B200B2B2B200CCCCCC00999999000000
      0000C0C0C00080808000CCCCCC00000000000000000000000000000000000000
      FF000000CC000000CC000000CC00000099000000CC000000CC000000CC000000
      990000000000000000000000000000000000000000000000000000000000B2B2
      B200999999009999990099999900808080009999990099999900999999008080
      800000000000000000000000000000000000FFFFCC00FFFFCC00FFFFCC00FFFF
      CC00E2EFF100E2EFF100E2EFF100FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFCC00646F7100CCCCCC0000000000CCCCCC0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099999900CCCCCC000000000000000000000000000000FF000000
      CC000000CC000000CC0000009900000000000000FF000000CC000000CC000000
      CC00000099000000000000000000000000000000000000000000B2B2B2009999
      990099999900999999008080800000000000B2B2B20099999900999999009999
      990080808000000000000000000000000000F2EABF00F2EABF00F2EABF00E5E5
      E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E2EFF100F2EABF00FFFF
      CC00FFFFCC00646F7100CCCCCC000000000000000000CCCCCC00CCCCCC000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099999900CCCCCC0000000000000000000000FF000000CC000000
      CC000000CC00000099000000000000000000000000000000FF000000CC000000
      CC000000CC0000009900000000000000000000000000B2B2B200999999009999
      99009999990080808000000000000000000000000000B2B2B200999999009999
      99009999990080808000000000000000000000000000E5E5E500E5E5E50099CC
      FF00CCFFFF00CCFFFF00CCFFFF00CCFFFF00E2EFF10099CCFF00FFCC9900FFCC
      9900FFFFCC0080808000E5E5E50000000000000000000000000000000000CCCC
      CC000000000000000000000000000000000000000000CCCCCC00C0C0C000C0C0
      C00000000000808080000000000000000000000000000000FF000000FF000000
      FF000000FF0000000000000000000000000000000000000000000000FF000000
      FF000000FF000000FF00000000000000000000000000B2B2B200B2B2B200B2B2
      B200B2B2B2000000000000000000000000000000000000000000B2B2B200B2B2
      B200B2B2B200B2B2B2000000000000000000000000000000000000000000E2EF
      F10099CCFF0099CCFF0099CCFF00CCFFFF00CCFFFF0099CCFF00FFCC9900FFCC
      9900FFCC9900C0C0C000E2EFF100000000000000000000000000000000000000
      0000CCCCCC00CCCCCC00CCCCCC000000000000000000CCCCCC00C0C0C000C0C0
      C000C0C0C000C0C0C00000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000099CCFF0099CCFF0099CCFF00F2EABF00F2EA
      BF00E5E5E500E2EFF10000000000000000000000000000000000000000000000
      0000000000000000000000000000CCCCCC00CCCCCC00CCCCCC00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000003333330033333300999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000006666660066666600999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000CCCCCC0066666600333333003333
      3300000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000009999990080808000666666006666
      6600000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000066666600666666006666
      6600333333009999990000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000808080008080
      8000666666009999990000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      9900000099000000990000009900000099000000990000009900000099000000
      9900000099000000000000000000000000000000000000000000000000009999
      9900999999009999990099999900999999009999990099999900999999009999
      99009999990000000000000000000000000000000000CCCCCC00666666006666
      6600666666003333330000999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000099999900808080008080
      8000808080006666660099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000099000000
      CC000000CC000000CC000000CC000000CC00000099000000CC00000099000000
      990000009900000099000000000000000000000000000000000099999900B2B2
      B200B2B2B200B2B2B200B2B2B200B2B2B20099999900B2B2B200999999009999
      9900999999009999990000000000000000000000000000000000666666006666
      660099FFFF0099CCCC0099CCCC00009999000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080008080
      8000E5E5E500CCCCCC00CCCCCC00999999000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000099000000
      FF000000CC000000CC000000CC000000CC000000CC00000099000000CC000000
      990000009900000099000000000000000000000000000000000099999900CCCC
      CC00B2B2B200B2B2B200B2B2B200B2B2B200B2B2B20099999900B2B2B2009999
      9900999999009999990000000000000000000000000000000000CCCCCC008080
      8000CCFFFF0099FFFF0099CCCC0099CCCC000099990099CCCC00000000000000
      0000000000000000000000000000000000000000000000000000999999008080
      8000E5E5E500E5E5E500CCCCCC00CCCCCC0099999900CCCCCC00000000000000
      0000000000000000000000000000000000000000000000000000000099000000
      CC000000FF000000CC000000CC000000CC000000CC000000CC00000099000000
      CC0000009900000099000000000000000000000000000000000099999900B2B2
      B200CCCCCC00B2B2B200B2B2B200B2B2B200B2B2B200B2B2B20099999900B2B2
      B2009999990099999900000000000000000000000000000000000000000066CC
      CC00FFFFFF00CCFFFF0099FFFF0099FFFF0099CCCC0066CCCC00009999000000
      000000000000000000000000000000000000000000000000000000000000CCCC
      CC00FFFFFF00E5E5E500E5E5E500E5E5E500CCCCCC00CCCCCC00999999000000
      0000000000000000000000000000000000000000000000000000000099000000
      FF000000CC000000FF000000CC000000CC000000CC000000CC000000CC000000
      99000000CC00000099000000000000000000000000000000000099999900CCCC
      CC00B2B2B200CCCCCC00B2B2B200B2B2B200B2B2B200B2B2B200B2B2B2009999
      9900B2B2B20099999900000000000000000000000000000000000000000066CC
      CC00FFFFFF00CCFFFF00CCFFFF0099FFFF0099FFFF0099CCCC0099CCCC000099
      990066CCCC00000000000000000000000000000000000000000000000000CCCC
      CC00FFFFFF00E5E5E500E5E5E500E5E5E500E5E5E500CCCCCC00CCCCCC009999
      9900CCCCCC000000000000000000000000000000000000000000000099000000
      FF000000FF000000CC000000FF000000CC000000CC000000CC000000CC000000
      CC0000009900000099000000000000000000000000000000000099999900CCCC
      CC00CCCCCC00B2B2B200CCCCCC00B2B2B200B2B2B200B2B2B200B2B2B200B2B2
      B200999999009999990000000000000000000000000000000000000000000000
      000099CCCC00FFFFFF00CCFFFF00CCFFFF0099FFFF0099FFFF0099CCCC00FFCC
      CC00993300009933000000000000000000000000000000000000000000000000
      0000CCCCCC00FFFFFF00E5E5E500E5E5E500E5E5E500E5E5E500CCCCCC00CCCC
      CC00666666006666660000000000000000000000000000000000000099009999
      FF000000FF000000FF000000CC000000FF000000CC000000CC000000CC000000
      CC000000CC00000099000000000000000000000000000000000099999900E5E5
      E500CCCCCC00CCCCCC00B2B2B200CCCCCC00B2B2B200B2B2B200B2B2B200B2B2
      B200B2B2B2009999990000000000000000000000000000000000000000000000
      000066CCCC00FFFFFF00CCFFFF00CCFFFF00FFCCCC00CC660000CC6600009933
      0000993300009933000099330000000000000000000000000000000000000000
      0000CCCCCC00FFFFFF00E5E5E500E5E5E500CCCCCC0080808000808080006666
      6600666666006666660066666600000000000000000000000000000099009999
      FF009999FF000000FF000000FF000000CC000000FF000000CC000000CC000000
      CC000000CC00000099000000000000000000000000000000000099999900E5E5
      E500E5E5E500CCCCCC00CCCCCC00B2B2B200CCCCCC00B2B2B200B2B2B200B2B2
      B200B2B2B2009999990000000000000000000000000000000000000000000000
      00000000000099CCCC00FFFFFF00CCFFFF00CC660000CC660000CC660000CC66
      0000993300009933000099330000993300000000000000000000000000000000
      000000000000CCCCCC00FFFFFF00E5E5E5008080800080808000808080008080
      8000666666006666660066666600666666000000000000000000000000000000
      9900000099000000990000009900000099000000990000009900000099000000
      9900000099000000000000000000000000000000000000000000000000009999
      9900999999009999990099999900999999009999990099999900999999009999
      9900999999000000000000000000000000000000000000000000000000000000
      00000000000066CCCC00FFFFFF00FFCCCC00CC660000CC660000CC660000CC66
      0000CC6600009933000099330000993300000000000000000000000000000000
      000000000000CCCCCC00FFFFFF00CCCCCC008080800080808000808080008080
      8000808080006666660066666600666666000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FF990000FF990000CC660000CC660000CC660000CC66
      0000CC660000CC66000099330000993300000000000000000000000000000000
      0000000000000000000099999900999999008080800080808000808080008080
      8000808080008080800066666600666666000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000CC660000FF990000FF990000CC660000CC660000CC66
      0000CC660000CC660000CC660000993300000000000000000000000000000000
      0000000000000000000066666600999999009999990080808000808080008080
      8000808080008080800080808000666666000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000CC660000FF990000FF990000CC660000CC66
      0000CC660000CC660000CC660000CC6600000000000000000000000000000000
      0000000000000000000000000000666666009999990099999900808080008080
      8000808080008080800080808000808080000000000000000000000000000000
      00000000000066CCCC0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000066CCCC000099CC00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000066CCCC000099CC000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099999900999999000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099330000993300009933000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099999900999999009999990099999900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000066CCCC0099FFFF000099CC0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099999900E5E5E5009999990000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099330000CC660000CC66000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099999900CCCCCC00CCCCCC0099999900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000066CCCC000099CC000099CC000099CC0066FFFF000099CC00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000099999900999999009999990099999900CCCCCC0099999900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099330000CC660000CC66000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099999900CCCCCC00CCCCCC0099999900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000066CCCC0099FFFF0066FFFF0066FFFF0066FFFF0066FFFF000099CC000000
      0000000000000000000000000000000000000000000000000000000000000000
      000099999900E5E5E500CCCCCC00CCCCCC00CCCCCC00CCCCCC00999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099330000CC660000CC66000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099999900CCCCCC00CCCCCC0099999900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000066CCCC0099FFFF0066FFFF000099CC0066CCCC0066CCCC0066CC
      CC00000000000000000000000000000000000000000000000000000000000000
      00000000000099999900E5E5E500CCCCCC009999990099999900999999009999
      9900000000000000000000000000000000000000000000000000993300009933
      0000993300009933000099330000CC660000CC66000099330000993300009933
      0000993300009933000000000000000000000000000000000000999999009999
      9900999999009999990099999900CCCCCC00CCCCCC0099999900999999009999
      9900999999009999990000000000000000000000000000000000000000000000
      00000000000066CCCC0099FFFF0066FFFF0066FFFF000099CC00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099999900E5E5E500CCCCCC00CCCCCC0099999900000000000000
      000000000000000000000000000000000000000000000000000099330000CC66
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000CC660000993300000000000000000000000000000000000099999900CCCC
      CC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00CCCCCC00999999000000000000000000000000000000000066CCCC000099
      CC000099CC000099CC000099CC0099FFFF0066FFFF0066FFFF000099CC000000
      0000000000000000000000000000000000000000000000000000999999009999
      9900999999009999990099999900E5E5E500CCCCCC00CCCCCC00999999000000
      000000000000000000000000000000000000000000000000000099330000CC66
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000CC660000993300000000000000000000000000000000000099999900CCCC
      CC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00CCCCCC00999999000000000000000000000000000000000066CCCC0099FF
      FF0099FFFF0066FFFF0066FFFF0066FFFF0066FFFF0066FFFF0066FFFF000099
      CC0000000000000000000000000000000000000000000000000099999900E5E5
      E500E5E5E500CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC009999
      9900000000000000000000000000000000000000000000000000993300009933
      0000993300009933000099330000CC660000CC66000099330000993300009933
      0000993300009933000000000000000000000000000000000000999999009999
      9900999999009999990099999900CCCCCC00CCCCCC0099999900999999009999
      99009999990099999900000000000000000000000000000000000000000066CC
      CC0099FFFF0099FFFF0066FFFF0066FFFF000099CC0066CCCC0066CCCC0066CC
      CC00000000000000000000000000000000000000000000000000000000009999
      9900E5E5E500E5E5E500CCCCCC00CCCCCC009999990099999900999999009999
      9900000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099330000CC660000CC66000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099999900CCCCCC00CCCCCC0099999900000000000000
      00000000000000000000000000000000000000000000000000000000000066CC
      CC0099FFFF0099FFFF0099FFFF0066FFFF0066FFFF000099CC00000000000000
      0000000000000000000000000000000000000000000000000000000000009999
      9900E5E5E500E5E5E500E5E5E500CCCCCC00CCCCCC0099999900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099330000CC660000CC66000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099999900CCCCCC00CCCCCC0099999900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000066CCCC0099FFFF0099FFFF0099FFFF0066FFFF0066FFFF000099CC000000
      0000000000000000000000000000000000000000000000000000000000000000
      000099999900E5E5E500E5E5E500E5E5E500CCCCCC00CCCCCC00999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099330000CC660000CC66000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099999900CCCCCC00CCCCCC0099999900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000066CCCC0099FFFF0099FFFF0099FFFF0066FFFF0066FFFF0066FFFF000099
      CC00000000000000000000000000000000000000000000000000000000000000
      000099999900E5E5E500E5E5E500E5E5E500CCCCCC00CCCCCC00CCCCCC009999
      9900000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099330000993300009933000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099999900999999009999990099999900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000066CCCC0099FFFF0099FFFF0099FFFF0066FFFF0066FFFF0066FF
      FF000099CC000000000000000000000000000000000000000000000000000000
      00000000000099999900E5E5E500E5E5E500E5E5E500CCCCCC00CCCCCC00CCCC
      CC00999999000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000066CCCC0066CCCC0066CCCC0066CCCC0066CCCC0066CCCC0066CC
      CC0066CCCC0066CCCC0000000000000000000000000000000000000000000000
      0000000000009999990099999900999999009999990099999900999999009999
      9900999999009999990000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF990000CC660000CC66
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC6600000000
      00000000000000000000000000000000000000000000CCCCCC00999999009999
      9900999999009999990099999900999999009999990099999900999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF990000CC660000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC66
      000000000000000000000000000000000000CCCCCC0099999900FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF009999
      9900000000000000000000000000000000000000000000000000000000000000
      0000000000009933000099330000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990099999900000000000000000000000000000000000000
      000000000000000000000000000000000000FF990000CC660000E5E5E500E5E5
      E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500CC66
      000000000000000000000000000000000000CCCCCC0099999900E5E5E500E5E5
      E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E5009999
      9900000000000000000000000000000000000000000000000000000000000000
      00000000000099330000CC660000993300000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099999900CCCCCC00999999000000000000000000000000000000
      000000000000000000000000000000000000FF990000CC660000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC66
      000000000000000000000000000000000000CCCCCC0099999900FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF009999
      9900000000000000000000000000000000000000000000000000000000000000
      00000000000099330000CC660000CC6600009933000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099999900CCCCCC00CCCCCC009999990000000000000000000000
      000000000000000000000000000000000000FF990000CC660000E5E5E500E5E5
      E500E5E5E500E5E5E500CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CC66
      000000000000000000000000000000000000CCCCCC0099999900E5E5E500E5E5
      E500E5E5E500E5E5E500CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC009999
      9900000000000000000000000000000000000000000000000000000000009933
      00009933000099330000CC660000CC660000CC66000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000009999
      99009999990099999900CCCCCC00CCCCCC00CCCCCC0099999900000000000000
      000000000000000000000000000000000000FF990000CC660000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500CC66
      000000000000000000000000000000000000CCCCCC0099999900FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E5009999
      9900000000000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000993300000000
      0000000000000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00999999000000
      000000000000000000000000000000000000FF990000CC660000E5E5E500E5E5
      E500E5E5E500CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CC66
      000000000000000000000000000000000000CCCCCC0099999900E5E5E500E5E5
      E500E5E5E500CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC009999
      9900000000000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC6600009933
      0000000000000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC009999
      990000000000000000000000000000000000FF990000CC660000FFFFFF00FFFF
      FF00FFFFFF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500CC66
      000000000000000000000000000000000000CCCCCC0099999900FFFFFF00FFFF
      FF00FFFFFF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E5009999
      9900000000000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC0099999900000000000000000000000000FF990000CC660000E5E5E500E5E5
      E500CCCCCC00CCCCCC00CC660000CC660000CC660000CC660000CC660000CC66
      0000CC660000CC660000CC660000CC660000CCCCCC0099999900E5E5E500E5E5
      E500CCCCCC00CCCCCC0099999900999999009999990099999900999999009999
      9900999999009999990099999900999999000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC6600009933
      0000000000000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC009999
      990000000000000000000000000000000000FF990000CC660000FFFFFF00FFFF
      FF00E5E5E500CC660000FF990000CC660000CC660000CC660000CC660000CC66
      0000CC660000CC660000CC660000CC660000CCCCCC0099999900FFFFFF00FFFF
      FF00E5E5E50099999900CCCCCC00999999009999990099999900999999009999
      9900999999009999990099999900999999000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000993300000000
      0000000000000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00999999000000
      000000000000000000000000000000000000FF990000CC660000E5E5E500CCCC
      CC00FF990000FF990000FF990000FF990000FF990000CC660000CC660000CC66
      0000CC660000CC660000CC66000000000000CCCCCC0099999900E5E5E500CCCC
      CC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC0099999900999999009999
      9900999999009999990099999900000000000000000000000000000000009933
      00009933000099330000CC660000CC660000CC66000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000009999
      99009999990099999900CCCCCC00CCCCCC00CCCCCC0099999900000000000000
      000000000000000000000000000000000000FF990000CC660000FFFFFF00FF99
      0000FF996600FF996600FF990000FF990000FF990000FF990000FF990000CC66
      0000CC660000CC6600000000000000000000CCCCCC0099999900FFFFFF00CCCC
      CC00E5E5E500E5E5E500CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC009999
      9900999999009999990000000000000000000000000000000000000000000000
      00000000000099330000CC660000CC6600009933000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099999900CCCCCC00CCCCCC009999990000000000000000000000
      000000000000000000000000000000000000FF990000CC660000FF990000FF99
      6600FF996600FF996600FF996600FF996600FF990000FF990000FF990000FF99
      0000CC660000000000000000000000000000CCCCCC0099999900CCCCCC00E5E5
      E500E5E5E500E5E5E500E5E5E500E5E5E500CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00999999000000000000000000000000000000000000000000000000000000
      00000000000099330000CC660000993300000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099999900CCCCCC00999999000000000000000000000000000000
      000000000000000000000000000000000000FF990000FF990000FF996600FF99
      6600FF996600FF996600FF996600FF996600FF996600FF996600FF990000CC66
      000000000000000000000000000000000000CCCCCC00CCCCCC00E5E5E500E5E5
      E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500CCCCCC009999
      9900000000000000000000000000000000000000000000000000000000000000
      0000000000009933000099330000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990099999900000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF99000099999900FFFF
      FF0099999900FFFFFF0099999900FFFFFF0099999900FFFFFF0099999900FFFF
      FF000000000000000000000000000000000000000000CCCCCC0099999900FFFF
      FF0099999900FFFFFF0099999900FFFFFF0099999900FFFFFF0099999900FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000099999900CCCC
      CC0099999900CCCCCC0099999900CCCCCC0099999900CCCCCC00999999000000
      000000000000000000000000000000000000000000000000000099999900CCCC
      CC0099999900CCCCCC0099999900CCCCCC0099999900CCCCCC00999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF0000000000FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF0000000000FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC996600CC99
      6600CC996600CC99660000000000000000000000000000000000999999009999
      9900999999009999990099999900999999009999990099999900999999009999
      990099999900999999000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000999999000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008080800000009900000099000000990000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008080800066666600666666006666660000000000000000000000
      0000000000000000000000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC0000000000999999000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00808080000000CC0000009900000099000000990000009900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00808080009999990066666600666666006666660066666600000000000000
      0000000000000000000000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000999999000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000CC000000CC000000CC00000099000000990000009900000099000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00999999009999990099999900666666006666660066666600666666000000
      0000000000000000000000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC0000000000999999000000000000000000FFFFFF0000000000FFFFFF000000
      00000000FF000000CC000000CC000000CC000000990000009900000099000099
      990000000000000000000000000000000000FFFFFF0000000000FFFFFF000000
      0000CCCCCC009999990099999900999999006666660066666600666666006666
      6600000000000000000000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000000000000000
      00000000FF000000FF000000CC000000CC000000CC00000099000099990000CC
      CC00009999000000000000000000000000000000000000000000000000000000
      0000CCCCCC00CCCCCC0099999900999999009999990066666600666666009999
      9900666666000000000000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000000000000000
      0000000000000000FF000000FF000000CC000000CC000099990000CCCC0000CC
      CC0000CCCC000099990000000000000000000000000000000000000000000000
      000000000000CCCCCC00CCCCCC00999999009999990066666600999999009999
      9900999999006666660000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000000000000000
      000000000000000000000000FF000000800000CCCC0000FFFF0000FFFF0000CC
      CC0000CCCC0000CCCC0000999900000000000000000000000000000000000000
      00000000000000000000CCCCCC006666660099999900CCCCCC00CCCCCC009999
      9900999999009999990066666600000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000000000000000
      000000000000000000000000000000CCCC0000FFFF00FFFFFF00C0C0C00000FF
      FF0000CCCC0000CCCC0000CCCC00009999000000000000000000000000000000
      000000000000000000000000000099999900CCCCCC00FFFFFF00C0C0C000CCCC
      CC00999999009999990099999900666666000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000CCCC0000FFFF00FFFFFF00C0C0
      C00000FFFF0000CCCC0000999900993300000000000000000000000000000000
      00000000000000000000000000000000000099999900CCCCCC00FFFFFF00C0C0
      C000CCCCCC009999990066666600666666000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500FFFFFF00CC996600CC99
      6600CC996600CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC0000000000999999009999
      9900999999009999990000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000CCCC0000FFFF00FFFF
      FF0000FFFF0000999900CC660000993300000000000000000000000000000000
      0000000000000000000000000000000000000000000099999900CCCCCC00FFFF
      FF00CCCCCC006666660099999900666666000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC996600E5E5
      E500CC9966000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000999999000000
      0000999999000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000CCCC0000FF
      FF0000CCCC00CC660000CC660000CC6600000000000000000000000000000000
      000000000000000000000000000000000000000000000000000099999900CCCC
      CC00999999009999990099999900999999000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC996600CC99
      6600000000000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000999999009999
      9900000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000000CC
      CC00FF990000FF990000CC660000CC6600000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC0099999900999999000000000000000000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC9966000000
      0000000000000000000000000000000000000000000000000000999999009999
      9900999999009999990099999900999999009999990099999900999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000099330000FF990000FF990000CC6600000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000066666600CCCCCC00CCCCCC00999999000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099330000FF990000FF9900000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000066666600CCCCCC00CCCCCC000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000007B000000000000000000000000000000000000000000
      000000000000000000007B000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000007B0000000000000000000000000000000000
      0000000000007B00000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B00000000000000000000000000
      00007B0000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F70000000000BDE7F700000000000000000000000000000000000000
      0000000000009933000099330000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000007B000000000000007B00
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F70000000000BDE7F70000000000000000000000000000000000000000000000
      00000000000099330000CC660000993300000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007B0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F70000000000BDE7F70000000000000000000000000000000000000000000000
      00000000000099330000CC660000CC6600009933000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000007B000000000000007B00
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F70000000000BDE7F70000000000000000000000000000000000000000000000
      00000000000099330000CC660000CC660000CC66000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B00000000000000000000000000
      00007B0000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099330000CC660000CC660000CC660000CC660000993300000000
      000000000000000000000000000000000000000000007B000000000000000000
      00000000000000000000000000007B000000000000007B000000000000000000
      0000000000007B0000000000000000000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F7000000000000000000000000000000
      00000000000099330000CC660000CC660000CC660000CC660000CC6600009933
      00000000000000000000000000000000000000000000000000007B0000000000
      000000000000000000007B000000000000007B00000000000000000000000000
      000000000000000000007B000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F7000000000000000000000000000000
      00000000000099330000CC660000CC660000CC660000CC660000993300000000
      0000000000000000000000000000000000000000000000000000000000007B00
      00000000000000000000000000007B0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099330000CC660000CC660000CC66000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00007B000000000000007B000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700000000000000000000000000000000000000
      00000000000099330000CC660000CC6600009933000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000007B00000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700000000000000000000000000000000000000000000000000000000000000
      00000000000099330000CC660000993300000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00007B000000000000007B000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F70000000000BDE7F700000000000000000000000000000000000000
      0000000000009933000099330000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000007B00
      00000000000000000000000000007B0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F70000000000BDE7F700000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007B0000000000
      0000000000000000000000000000000000007B00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000007B000000000000000000
      000000000000000000000000000000000000000000007B000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000003399CC00006699000066
      9900006699000066990000669900006699000066990000669900006699000066
      990066CCCC000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009933
      0000993300009933000099330000000000000000000099330000993300009933
      0000993300000000000000000000000000003399CC003399CC0099FFFF0066CC
      FF0066CCFF0066CCFF0066CCFF0066CCFF0066CCFF0066CCFF0066CCFF003399
      CC00006699000000000000000000000000000000000000000000000000000000
      0000000000009933000099330000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009933
      0000993300009933000099330000993300009933000099330000993300009933
      0000993300000000000000000000000000000000000000000000000000009933
      0000CC660000CC66000099330000000000000000000099330000CC660000CC66
      0000993300000000000000000000000000003399CC003399CC0066CCFF0099FF
      FF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0066CC
      FF00006699003399CC0000000000000000000000000000000000000000000000
      00000000000099330000CC660000993300000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009933
      0000CC660000CC66000099330000000000000000000099330000CC660000CC66
      0000993300000000000000000000000000003399CC003399CC0066CCFF0099FF
      FF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0066CC
      FF0066CCCC000066990000000000000000000000000000000000000000000000
      00000000000099330000CC660000CC6600009933000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009933
      0000CC660000CC66000099330000000000000000000099330000CC660000CC66
      0000993300000000000000000000000000003399CC0066CCFF003399CC0099FF
      FF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0066CC
      FF0099FFFF00006699003399CC00000000000000000000000000000000000000
      00000000000099330000CC660000CC660000CC66000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009933
      0000CC660000CC66000099330000000000000000000099330000CC660000CC66
      0000993300000000000000000000000000003399CC0066CCFF0066CCCC0066CC
      CC0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0066CC
      FF0099FFFF0066CCCC0000669900000000000000000000000000000000000000
      00000000000099330000CC660000CC660000CC660000CC660000993300000000
      0000000000000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009933
      0000CC660000CC66000099330000000000000000000099330000CC660000CC66
      0000993300000000000000000000000000003399CC0099FFFF0066CCFF003399
      CC00CCFFFF00CCFFFF00CCFFFF00CCFFFF00CCFFFF00CCFFFF00CCFFFF0099FF
      FF00CCFFFF00CCFFFF0000669900000000000000000000000000000000000000
      00000000000099330000CC660000CC660000CC660000CC660000CC6600009933
      0000000000000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009933
      0000CC660000CC66000099330000000000000000000099330000CC660000CC66
      0000993300000000000000000000000000003399CC0099FFFF0099FFFF0066CC
      FF003399CC003399CC003399CC003399CC003399CC003399CC003399CC003399
      CC003399CC003399CC0066CCFF00000000000000000000000000000000000000
      00000000000099330000CC660000CC660000CC660000CC660000993300000000
      0000000000000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009933
      0000CC660000CC66000099330000000000000000000099330000CC660000CC66
      0000993300000000000000000000000000003399CC00CCFFFF0099FFFF0099FF
      FF0099FFFF0099FFFF00CCFFFF00CCFFFF00CCFFFF00CCFFFF00CCFFFF000066
      9900000000000000000000000000000000000000000000000000000000000000
      00000000000099330000CC660000CC660000CC66000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009933
      0000CC660000CC66000099330000000000000000000099330000CC660000CC66
      000099330000000000000000000000000000000000003399CC00CCFFFF00CCFF
      FF00CCFFFF00CCFFFF003399CC003399CC003399CC003399CC003399CC000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099330000CC660000CC6600009933000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009933
      0000993300009933000099330000000000000000000099330000993300009933
      00009933000000000000000000000000000000000000000000003399CC003399
      CC003399CC003399CC0000000000000000000000000000000000000000000000
      0000000000009933000099330000993300000000000000000000000000000000
      00000000000099330000CC660000993300000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009933
      0000993300009933000099330000993300009933000099330000993300009933
      0000993300000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099330000993300000000000000000000000000000000
      0000000000009933000099330000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000099330000000000000000
      0000000000009933000000000000993300000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000993300009933
      0000993300000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000E2EFF100000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFE718000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000E7000000000000000000000000000000000000000000000000000000
      000000E71800000000000000000000000000000000000000000000000000E2EF
      F100E5E5E500CCCCCC00E5E5E500E2EFF1000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000993300009933
      0000993300009933000099330000993300009933000099330000993300009933
      0000993300009933000099330000000000000000000000000000000000000000
      0000000000000000000000000000FFE718000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000E7000000000000000000000000000000000000000000000000000000
      000000E7180000000000000000000000000000000000E2EFF100E5E5E500B2B2
      B200CC9999009966660099666600B2B2B200CCCCCC00E5E5E500E2EFF1000000
      0000000000000000000000000000000000000000000099330000CC660000CC66
      000099330000E5E5E500CC66000099330000E5E5E500E5E5E500E5E5E5009933
      0000CC660000CC66000099330000000000000000000000000000000000000000
      0000000000000000000000000000FFE718000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000E7000000000000000000000000000000000000000000000000000000
      000000E71800000000000000000000000000E5E5E500CC99990099666600CC99
      9900CC999900FFFFFF00996666009999990099999900B2B2B200E5E5E5000000
      0000000000000000000000000000000000000000000099330000CC660000CC66
      000099330000E5E5E500CC66000099330000E5E5E500E5E5E500E5E5E5009933
      0000CC660000CC66000099330000000000000000000000000000000000000000
      0000000000000000000000000000FFE718000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000E7000000000000000000000000000000000000000000000000000000
      000000E7180000000000000000000000000099666600CC999900FFCC9900FFCC
      9900FFCCCC00FFFFFF0099666600336699003366990033669900E2EFF1000000
      0000000000000000000000000000000000000000000099330000CC660000CC66
      000099330000E5E5E500CC66000099330000E5E5E500E5E5E500E5E5E5009933
      0000CC660000CC66000099330000000000000000000000000000000000000000
      0000000000000000000000000000FFE718000000000000000000000000000000
      00000000000000000000000000000000000000E7180000E7180000E7180000E7
      180000E7180000E7180000E7180000E7180000E7180000E7180000E7180000E7
      180000E7180000E7180000E7180000E7180099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF009966660066CCCC0066CCCC000099CC00FFFFFF00FFCC
      CC00000000000000000000000000000000000000000099330000CC660000CC66
      000099330000E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E5009933
      0000CC660000CC66000099330000000000000000000000000000000000000000
      0000000000000000000000000000FFE718000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000E7000000000000000000000000000000000000000000000000000000
      000000E7180000000000000000000000000099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF009966660066CCCC0066CCFF003399CC00FFCCCC00CC66
      0000000000000000000000000000000000000000000099330000CC660000CC66
      0000CC660000993300009933000099330000993300009933000099330000CC66
      0000CC660000CC66000099330000000000000000000000000000000000000000
      0000000000000000000000000000FFE718000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000E7000000000000000000000000000000000000000000000000000000
      000000E7180000000000000000000000000099666600FFCC9900CC999900CC99
      6600FFCCCC00FFFFFF009966660099CCCC0099CCFF00B2B2B200FF660000CC66
      0000000000000000000000000000000000000000000099330000CC660000CC66
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000CC660000CC66000099330000000000000000000000000000000000000000
      0000000000000000000000000000FFE718000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000E7000000000000000000000000000000000000000000000000000000
      000000E7180000000000000000000000000099666600FFCC990099666600FFFF
      FF00FFCCCC00FFFFFF009966660099CCCC00C0C0C000CC660000CC660000CC66
      0000CC660000CC660000CC660000000000000000000099330000CC660000CC66
      0000993300009933000099330000993300009933000099330000993300009933
      0000CC660000CC66000099330000000000000000000000000000000000000000
      0000000000000000000000000000FFE718000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000E7000000000000000000000000000000000000000000000000000000
      000000E7180000000000000000000000000099666600FFCC9900CC9999009966
      6600FFCCCC00FFFFFF009966660000000000CC660000CC660000CC660000CC66
      0000CC660000CC660000CC660000000000000000000099330000CC6600009933
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0099330000CC66000099330000000000000000000000000000000000000000
      0000000000000000000000000000FFE718000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000E7000000000000000000000000000000000000000000000000000000
      000000E7180000000000000000000000000099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF009966660000000000CC999900CC660000CC660000CC66
      0000CC660000CC660000CC660000000000000000000099330000CC6600009933
      0000FFFFFF00993300009933000099330000993300009933000099330000FFFF
      FF0099330000CC66000099330000000000000000000000000000000000000000
      0000000000000000000000000000FFE718000000000000000000000000000000
      0000000000000000000000000000000000000000E7000000E7000000E7000000
      E7000000E7000000E7000000E7000000E7000000E7000000E7000000E7000000
      E70000E718000000E7000000E7000000E70099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF0099666600CCCCCC00E2EFF100CC999900FF660000CC66
      0000000000000000000000000000000000000000000099330000CC6600009933
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0099330000CC66000099330000000000000000000000000000000000000000
      0000000000000000000000000000FFE718000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000E7000000000000000000000000000000000000000000000000000000
      000000E7180000000000000000000000000099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF009966660099CCCC000000000099CCCC00FFCC9900CC66
      0000000000000000000000000000000000000000000099330000E5E5E5009933
      0000FFFFFF00993300009933000099330000993300009933000099330000FFFF
      FF00993300009933000099330000000000000000000000000000000000000000
      0000000000000000000000000000FFE718000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000E7000000000000000000000000000000000000000000000000000000
      000000E7180000000000000000000000000099666600CC999900FFCC9900FFCC
      9900FFCCCC00FFFFFF0099666600CCCCCC00000000003399CC0000000000FFCC
      9900000000000000000000000000000000000000000099330000CC6600009933
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0099330000CC66000099330000000000000000000000000000000000000000
      0000000000000000000000000000FFE718000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000E7000000000000000000000000000000000000000000000000000000
      000000E7180000000000000000000000000000000000C0C0C000CC996600CC99
      9900CCCC9900FFFFFF00996666000099CC000099CC000099CC00000000000000
      0000000000000000000000000000000000000000000099330000993300009933
      0000993300009933000099330000993300009933000099330000993300009933
      0000993300009933000099330000000000000000000000000000000000000000
      0000000000000000000000000000FFE718000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000E7000000000000000000000000000000000000000000000000000000
      000000E71800000000000000000000000000000000000000000000000000CCCC
      CC00CC9999009966660099666600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFE718000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000E7000000000000000000000000000000000000000000000000000000
      000000E71800000000000000000000000000424D3E000000000000003E000000
      2800000040000000900000000100010000000000800400000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000E07FFFFFFFFFFFFFC00FE01FFFFFFFFF
      C007C00FFFFFFFFF8003F8C787C387C38003B0238383838380019013C107C107
      0001B043E00FE00F00017003F01FF01F00016113F83FF83F00016013F01FF01F
      00017E11E00FE00F00017FF9C107C10700019FF9838383838001EF8B87C387C3
      E001F183FFFFFFFFFE03FE3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1FFF1FFF
      FFFFFFFF0FFF0FFFFFFFFFFF83FF83FFE007E00781FF81FFC003C003C0FFC0FF
      C003C003C03FC03FC003C003E01FE01FC003C003E007E007C003C003F003F003
      C003C003F001F001C003C003F800F800E007E007F800F800FFFFFFFFFC00FC00
      FFFFFFFFFC00FC00FFFFFFFFFE00FE00FBFFFBFFFFFFFFFFF9FFF9FFFFFFFFFF
      FCFFFCFFFC3FFC3FFC7FFC7FFC3FFC3FF03FF03FFC3FFC3FF01FF01FFC3FFC3F
      F80FF80FC003C003F83FF83FC003C003C01FC01FC003C003C00FC00FC003C003
      E00FE00FFC3FFC3FE03FE03FFC3FFC3FF01FF01FFC3FFC3FF00FF00FFC3FFC3F
      F807F807FFFFFFFFF803F803FFFFFFFFFFFFFFFF801F801FFFFFFFFF000F000F
      F9FFF9FF000F000FF8FFF8FF000F000FF87FF87F000F000FE03FE03F000F000F
      E01FE01F000F000FE00FE00F000F000FE007E00700000000E00FE00F00000000
      E01FE01F00010001E03FE03F00030003F87FF87F00070007F8FFF8FF000F000F
      F9FFF9FF800F800FFFFFFFFFC01FC01FFFFFFFFFA7FFA7FFC003C00301FF01FF
      C003DFFB007F007FC003D00B003F003FC003DFFB001F001FC003D00B500F500F
      C003DFFBF007F007C003D00BF803F803C003DFFBFC01FC01C003D00BFE00FE00
      C003DFFBFF00FF00C003D043FF80FF80C007DFD7FFC0FFC0C00FDFCFFFE0FFE0
      C01FC01FFFF0FFF0FFFFFFFFFFF8FFF8FFFFFDFDFFFFFFFFFFFFFEFBFFFF8001
      FFFFFF77FFFF8001F9FFFFAFFFFF8001F8FFFFDFFFFF8001F87FFFAFFFFF8001
      F83FFF77FFFFFFFFF81FBEBB00000000F80FDD7DFFFF0000F81FEEFFFFFFFFFF
      F83FF5FFFFFF8001F87FFBFFFFFF8001F8FFF5FFFFFF8001F9FFEEFFFFFF8001
      FFFFDF7FFFFF8001FFFFBFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF8007FFFFFFFFE1870007F9FFE007E1870003F8FFE007E1870003F87FE007
      E1870001F83FE007E1870001F81FE007E1870001F80FE007E1870001F81FE007
      E187000FF83FE007E187801FF87FE007E187C3F8F8FFE007FFFFFFFCF9FFFFFF
      FFFFFFBAFFFFFFFFFFFFFFC7FFFFFFFFFDFFFFFFFEFFF7F7E0FFC001FEFFF7F7
      801F8001FEFFF7F7001F8001FEFFF7F7001F8001FEFF0000000F8001FEFFF7F7
      000F8001FEFFF7F7000F8001FEFFF7F700018001FEFFF7F701018001FEFFF7F7
      01018001FEFF0000000F8001FEFFF7F7008F8001FEFFF7F700AF8001FEFFF7F7
      803F8001FEFFF7F7E1FFFFFFFEFFF7F700000000000000000000000000000000
      000000000000}
  end
  object ChartEditor1: TChartEditor
    Chart = Chart
    GalleryHeight = 0
    GalleryWidth = 0
    Height = 0
    Width = 0
    Left = 520
    Top = 288
  end
  object XPManifest1: TXPManifest
    Left = 520
    Top = 192
  end
  object FolderDialog1: TRzSelectFolderDialog
    Left = 520
    Top = 240
  end
  object ToolBarImageList: TImageList
    Left = 576
    Top = 232
    Bitmap = {
      494C010120009000280110001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000009000000001002000000000000090
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000FF0000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000FF0000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000FF000000FF0000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000FF000000FF0000
      0000000000000000000000000000000000000000000000000000000000000000
      000000CC00000066000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000B2B2B2008080800000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C6C6C6395A5A5AA50000
      00FF000000FF000000FF0000000000000000000000FF000000FF000000FF0000
      00FF000000FF5A5A5AA5C6C6C6390000000000000000C6C6C6395A5A5AA50000
      00FF000000FF000000FF0000000000000000000000FF000000FF000000FF0000
      00FF000000FF5A5A5AA5C6C6C6390000000000000000000000000000000000CC
      0000009900000099000000660000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000B2B2
      B200999999009999990080808000000000000000000000000000000000000000
      000000000000000000000000000000000000C6C6C6395C5C5CA3E4E4E41BFDFD
      FD020000000000000000000000000000000000000000000000FF000000FF0000
      0000FDFDFD02E4E4E41B5C5C5CA3C6C6C639C6C6C6395C5C5CA3E4E4E41BFDFD
      FD020000000000000000000000000000000000000000000000FF000000FF0000
      0000FDFDFD02E4E4E41B5C5C5CA3C6C6C639000000000000000000CC00000099
      0000009900000099000000990000006600000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000B2B2B2009999
      9900999999009999990099999900808080000000000000000000000000000000
      0000000000000000000000000000000000005A5A5AA5E4E4E41B000000000000
      0000000000000000000000000000000000000000000000000000000000FF0000
      00000000000000000000E4E4E41B5A5A5AA55A5A5AA5E4E4E41B000000000000
      0000000000000000000000000000000000000000000000000000000000FF0000
      00000000000000000000E4E4E41B5A5A5AA50000000000CC0000009900000099
      0000009900000099000000990000009900000066000000000000000000000000
      00000000000000000000000000000000000000000000B2B2B200999999009999
      9900999999009999990099999900999999008080800000000000000000000000
      000000000000000000000000000000000000000000FFFDFDFD02000000000000
      000000000000000000008080FF7FD8D8FF2700000000D8D8FF278080FF7F0000
      00000000000000000000FDFDFD02000000FF000000FFFDFDFD02000000000000
      000000000000000000008080FF7FD8D8FF2700000000D8D8FF278080FF7F0000
      00000000000000000000FDFDFD02000000FF0000000000CC0000009900000099
      00000066000000CC000000990000009900000099000000660000000000000000
      00000000000000000000000000000000000000000000B2B2B200999999009999
      990080808000B2B2B20099999900999999009999990080808000000000000000
      000000000000000000000000000000000000000000FF00000000000000000000
      00000000000000000000D8D8FF270000FFFFB6B6FF490000FFFFD8D8FF270000
      0000000000000000000000000000000000FF000000FF00000000000000000000
      00000000000000000000D8D8FF270000FFFFB6B6FF490000FFFFD8D8FF270000
      0000000000000000000000000000000000FF0000000000CC0000009900000066
      0000000000000000000000CC0000009900000099000000990000006600000000
      00000000000000000000000000000000000000000000B2B2B200999999008080
      80000000000000000000B2B2B200999999009999990099999900808080000000
      000000000000000000000000000000000000000000FF00000000000000000000
      0000000000000000000000000000B6B6FF490000FFFFB6B6FF49000000000000
      0000000000000000000000000000000000FF000000FF00000000000000000000
      0000000000000000000000000000B6B6FF490000FFFFB6B6FF49000000000000
      0000000000000000000000000000000000FF0000000000CC0000006600000000
      000000000000000000000000000000CC00000099000000990000009900000066
      00000000000000000000000000000000000000000000B2B2B200808080000000
      0000000000000000000000000000B2B2B2009999990099999900999999008080
      800000000000000000000000000000000000000000FFFDFDFD02000000000000
      00000000000000000000D8D8FF270000FFFFB6B6FF490000FFFFD8D8FF270000
      00000000000000000000FDFDFD02000000FF000000FFFDFDFD02000000000000
      00000000000000000000D8D8FF270000FFFFB6B6FF490000FFFFD8D8FF270000
      00000000000000000000FDFDFD02000000FF0000000000000000000000000000
      00000000000000000000000000000000000000CC000000990000009900000099
      0000006600000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000B2B2B20099999900999999009999
      9900808080000000000000000000000000005A5A5AA5E4E4E41B000000000000
      000000000000000000008080FF7FD8D8FF2700000000D8D8FF278080FF7F0000
      00000000000000000000E4E4E41B5A5A5AA55A5A5AA5E4E4E41B000000000000
      000000000000000000008080FF7FD8D8FF2700000000D8D8FF278080FF7F0000
      00000000000000000000E4E4E41B5A5A5AA50000000000000000000000000000
      0000000000000000000000000000000000000000000000CC0000009900000099
      0000009900000066000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000B2B2B200999999009999
      990099999900808080000000000000000000C6C6C6395C5C5CA3E4E4E41BFDFD
      FD0200000000FFFFFF0000000000000000000000000000000000000000000000
      0000FDFDFD02E4E4E41B5C5C5CA3C6C6C639C6C6C6395C5C5CA3E4E4E41BFDFD
      FD0200000000FFFFFF0000000000000000000000000000000000000000000000
      0000FDFDFD02E4E4E41B5C5C5CA3C6C6C6390000000000000000000000000000
      000000000000000000000000000000000000000000000000000000CC00000099
      0000009900000066000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000B2B2B2009999
      99009999990080808000000000000000000000000000C6C6C6395A5A5AA50000
      00FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF0000
      00FF000000FF5A5A5AA5C6C6C6390000000000000000C6C6C6395A5A5AA50000
      00FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF0000
      00FF000000FF5A5A5AA5C6C6C639000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000000CC
      0000009900000066000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000B2B2
      B200999999008080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000CC00000066000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000B2B2B2008080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000FF0000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000FF0000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009933000099330000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000FF000000FF0000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000FF000000FF0000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099330000CC660000993300000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099999900CCCCCC00999999000000000000000000000000000000
      00000000000000000000000000000000000000000000C6C6C6395A5A5AA50000
      00FF000000FF000000FF0000000000000000000000FF000000FF000000FF0000
      00FF000000FF5A5A5AA5C6C6C6390000000000000000C6C6C6395A5A5AA50000
      00FF000000FF000000FF0000000000000000000000FF000000FF000000FF0000
      00FF000000FF5A5A5AA5C6C6C639000000000000000000000000000000000000
      00000000000099330000CC660000CC6600009933000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099999900CCCCCC00CCCCCC009999990000000000000000000000
      000000000000000000000000000000000000C6C6C6395C5C5CA3E4E4E41BFDFD
      FD020000000000000000000000000000000000000000000000FF000000FF0000
      0000FDFDFD02E4E4E41B5C5C5CA3C6C6C639C6C6C6395C5C5CA3E4E4E41BFDFD
      FD020000000000000000000000000000000000000000000000FF000000FF0000
      0000FDFDFD02E4E4E41B5C5C5CA3C6C6C6390000000000000000000000009933
      00009933000099330000CC660000CC660000CC66000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000009999
      99009999990099999900CCCCCC00CCCCCC00CCCCCC0099999900000000000000
      0000000000000000000000000000000000005A5A5AA5E4E4E41B000000000000
      0000000000000000000000000000000000000000000000000000000000FF0000
      00000000000000000000E4E4E41B5A5A5AA55A5A5AA5E4E4E41B000000000000
      0000000000000000000000000000000000000000000000000000000000FF0000
      00000000000000000000E4E4E41B5A5A5AA50000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000993300000000
      0000000000000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00999999000000
      000000000000000000000000000000000000000000FFFDFDFD02000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FDFDFD02000000FF000000FFFDFDFD02000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FDFDFD02000000FF0000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC6600009933
      0000000000000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC009999
      990000000000000000000000000000000000000000FF00000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000FF000000FF00000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000FF0000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC0099999900000000000000000000000000000000FF00000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000FF000000FF00000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000FF0000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC6600009933
      0000000000000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC009999
      990000000000000000000000000000000000000000FFFDFDFD02000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FDFDFD02000000FF000000FFFDFDFD02000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FDFDFD02000000FF0000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000993300000000
      0000000000000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00999999000000
      0000000000000000000000000000000000005A5A5AA5E4E4E41B000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000E4E4E41B5A5A5AA55A5A5AA5E4E4E41B000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000E4E4E41B5A5A5AA50000000000000000000000009933
      00009933000099330000CC660000CC660000CC66000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000009999
      99009999990099999900CCCCCC00CCCCCC00CCCCCC0099999900000000000000
      000000000000000000000000000000000000C6C6C6395C5C5CA3E4E4E41BFDFD
      FD02000000000000000000000000000000000000000000000000000000000000
      0000FDFDFD02E4E4E41B5C5C5CA3C6C6C639C6C6C6395C5C5CA3E4E4E41BFDFD
      FD02000000000000000000000000000000000000000000000000000000000000
      0000FDFDFD02E4E4E41B5C5C5CA3C6C6C6390000000000000000000000000000
      00000000000099330000CC660000CC6600009933000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099999900CCCCCC00CCCCCC009999990000000000000000000000
      00000000000000000000000000000000000000000000C6C6C6395A5A5AA50000
      00FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF0000
      00FF000000FF5A5A5AA5C6C6C6390000000000000000C6C6C6395A5A5AA50000
      00FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF0000
      00FF000000FF5A5A5AA5C6C6C639000000000000000000000000000000000000
      00000000000099330000CC660000993300000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099999900CCCCCC00999999000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009933000099330000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009933
      0000993300000000000000000000993300009933000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009999
      9900999999000000000000000000999999009999990000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009933
      0000CC660000993300000000000099330000CC66000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000009999
      9900CCCCCC00999999000000000099999900CCCCCC0099999900000000000000
      0000000000000000000000000000000000000000000000000000000000000099
      0000009900000099000000990000009900000099000000990000009900000099
      0000009900000000000000000000000000000000000000000000000000009999
      9900999999009999990099999900999999009999990099999900999999009999
      9900999999000000000000000000000000000000000000000000000000009933
      0000CC660000CC6600009933000099330000CC660000CC660000993300000000
      0000000000000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC009999990099999900CCCCCC00CCCCCC00999999000000
      00000000000000000000000000000000000000000000000000000099000000CC
      000000CC000000CC000000CC000000CC00000099000000CC0000009900000099
      000000990000009900000000000000000000000000000000000099999900B2B2
      B200B2B2B200B2B2B200B2B2B200B2B2B20099999900B2B2B200999999009999
      9900999999009999990000000000000000000000000099330000993300009933
      0000CC660000CC660000CC66000099330000CC660000CC660000CC6600009933
      0000000000000000000000000000000000000000000099999900999999009999
      9900CCCCCC00CCCCCC00CCCCCC0099999900CCCCCC00CCCCCC00CCCCCC009999
      99000000000000000000000000000000000000000000000000000099000000FF
      000000CC000000CC000000CC000000CC000000CC00000099000000CC00000099
      000000990000009900000000000000000000000000000000000099999900CCCC
      CC00B2B2B200B2B2B200B2B2B200B2B2B200B2B2B20099999900B2B2B2009999
      9900999999009999990000000000000000000000000099330000CC660000CC66
      0000CC660000CC660000CC660000CC66000099330000CC660000CC660000CC66
      0000993300000000000000000000000000000000000099999900CCCCCC00CCCC
      CC00CCCCCC00CCCCCC00CCCCCC00CCCCCC0099999900CCCCCC00CCCCCC00CCCC
      CC009999990000000000000000000000000000000000000000000099000000CC
      000000FF000000CC000000CC000000CC000000CC000000CC00000099000000CC
      000000990000009900000000000000000000000000000000000099999900B2B2
      B200CCCCCC00B2B2B200B2B2B200B2B2B200B2B2B200B2B2B20099999900B2B2
      B200999999009999990000000000000000000000000099330000CC660000CC66
      0000CC660000CC660000CC660000CC660000CC66000099330000CC660000CC66
      0000CC6600009933000000000000000000000000000099999900CCCCCC00CCCC
      CC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC0099999900CCCCCC00CCCC
      CC00CCCCCC0099999900000000000000000000000000000000000099000000FF
      000000CC000000FF000000CC000000CC000000CC000000CC000000CC00000099
      000000CC0000009900000000000000000000000000000000000099999900CCCC
      CC00B2B2B200CCCCCC00B2B2B200B2B2B200B2B2B200B2B2B200B2B2B2009999
      9900B2B2B2009999990000000000000000000000000099330000CC660000CC66
      0000CC660000CC660000CC660000CC660000CC660000CC66000099330000CC66
      0000CC660000CC66000099330000000000000000000099999900CCCCCC00CCCC
      CC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC0099999900CCCC
      CC00CCCCCC00CCCCCC00999999000000000000000000000000000099000000FF
      000000FF000000CC000000FF000000CC000000CC000000CC000000CC000000CC
      000000990000009900000000000000000000000000000000000099999900CCCC
      CC00CCCCCC00B2B2B200CCCCCC00B2B2B200B2B2B200B2B2B200B2B2B200B2B2
      B200999999009999990000000000000000000000000099330000CC660000CC66
      0000CC660000CC660000CC660000CC660000CC66000099330000CC660000CC66
      0000CC6600009933000000000000000000000000000099999900CCCCCC00CCCC
      CC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC0099999900CCCCCC00CCCC
      CC00CCCCCC0099999900000000000000000000000000000000000099000099FF
      990000FF000000FF000000CC000000FF000000CC000000CC000000CC000000CC
      000000CC0000009900000000000000000000000000000000000099999900E5E5
      E500CCCCCC00CCCCCC00B2B2B200CCCCCC00B2B2B200B2B2B200B2B2B200B2B2
      B200B2B2B2009999990000000000000000000000000099330000CC660000CC66
      0000CC660000CC660000CC660000CC66000099330000CC660000CC660000CC66
      0000993300000000000000000000000000000000000099999900CCCCCC00CCCC
      CC00CCCCCC00CCCCCC00CCCCCC00CCCCCC0099999900CCCCCC00CCCCCC00CCCC
      CC009999990000000000000000000000000000000000000000000099000099FF
      990099FF990000FF000000FF000000CC000000FF000000CC000000CC000000CC
      000000CC0000009900000000000000000000000000000000000099999900E5E5
      E500E5E5E500CCCCCC00CCCCCC00B2B2B200CCCCCC00B2B2B200B2B2B200B2B2
      B200B2B2B2009999990000000000000000000000000099330000993300009933
      0000CC660000CC660000CC66000099330000CC660000CC660000CC6600009933
      0000000000000000000000000000000000000000000099999900999999009999
      9900CCCCCC00CCCCCC00CCCCCC0099999900CCCCCC00CCCCCC00CCCCCC009999
      9900000000000000000000000000000000000000000000000000000000000099
      0000009900000099000000990000009900000099000000990000009900000099
      0000009900000000000000000000000000000000000000000000000000009999
      9900999999009999990099999900999999009999990099999900999999009999
      9900999999000000000000000000000000000000000000000000000000009933
      0000CC660000CC6600009933000099330000CC660000CC660000993300000000
      0000000000000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC009999990099999900CCCCCC00CCCCCC00999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009933
      0000CC660000993300000000000099330000CC66000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000009999
      9900CCCCCC00999999000000000099999900CCCCCC0099999900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009933
      0000993300000000000000000000993300009933000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009999
      9900999999000000000000000000999999009999990000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000E2EFF100000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000E2EFF100000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF0000000000FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF0000000000FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000E2EF
      F100E5E5E500CCCCCC00E5E5E500E2EFF1000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000E2EF
      F10000000000CCCCCC00E5E5E500E2EFF1000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      00000000000000000000000000000000000000000000E2EFF100E5E5E500B2B2
      B200CC9999009966660099666600B2B2B200CCCCCC00E5E5E500E2EFF1000000
      00000000000000000000000000000000000000000000E2EFF10000000000B2B2
      B200999999009999990099999900B2B2B200CCCCCC0000000000E2EFF1000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008080800000009900000099000000990000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008080800066666600666666006666660000000000000000000000
      000000000000000000000000000000000000E5E5E500CC99990099666600CC99
      9900CC999900FFFFFF00996666009999990099999900B2B2B200E5E5E5000000
      0000000000000000000000000000000000000000000099999900999999009999
      990099999900FFFFFF00999999009999990099999900B2B2B200000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00808080000000CC0000009900000099000000990000009900000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00808080009999990066666600666666006666660066666600000000000000
      00000000000000000000000000000000000099666600CC999900FFCC9900FFCC
      9900FFCCCC00FFFFFF0099666600336699003366990033669900E2EFF1000000
      0000000000000000000000000000000000009999990099999900C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900999999009999990099999900E2EFF1000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000CC000000CC000000CC00000099000000990000009900000099000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00999999009999990099999900666666006666660066666600666666000000
      00000000000000000000000000000000000099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF009966660066CCCC0066CCCC000099CC00FFFFFF00FFCC
      CC000000000000000000000000000000000099999900C0C0C000C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900C0C0C000C0C0C00099999900FFFFFF00CCCC
      CC0000000000000000000000000000000000FFFFFF0000000000FFFFFF000000
      00000000FF000000CC000000CC000000CC000000990000009900000099000099
      990000000000000000000000000000000000FFFFFF0000000000FFFFFF000000
      0000CCCCCC009999990099999900999999006666660066666600666666006666
      66000000000000000000000000000000000099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF009966660066CCCC0066CCFF003399CC00FFCCCC00CC66
      00000000000000000000000000000000000099999900C0C0C000C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900C0C0C000CCCCCC0099999900CCCCCC009999
      9900000000000000000000000000000000000000000000000000000000000000
      00000000FF000000FF000000CC000000CC000000CC00000099000099990000CC
      CC00009999000000000000000000000000000000000000000000000000000000
      0000CCCCCC00CCCCCC0099999900999999009999990066666600666666009999
      99006666660000000000000000000000000099666600FFCC9900CC999900CC99
      6600FFCCCC00FFFFFF009966660099CCCC0099CCFF00B2B2B200FF660000CC66
      00000000000000000000000000000000000099999900C0C0C000999999009999
      9900CCCCCC00FFFFFF0099999900CCCCCC00CCCCCC00B2B2B200999999009999
      9900000000000000000000000000000000000000000000000000000000000000
      0000000000000000FF000000FF000000CC000000CC000099990000CCCC0000CC
      CC0000CCCC000099990000000000000000000000000000000000000000000000
      000000000000CCCCCC00CCCCCC00999999009999990066666600999999009999
      99009999990066666600000000000000000099666600FFCC990099666600FFFF
      FF00FFCCCC00FFFFFF009966660099CCCC00C0C0C000CC660000CC660000CC66
      0000CC660000CC660000CC6600000000000099999900C0C0C00066666600FFFF
      FF00CCCCCC00FFFFFF0099999900CCCCCC00C0C0C00099999900999999009999
      9900999999009999990099999900000000000000000000000000000000000000
      000000000000000000000000FF000000800000CCCC0000FFFF0000FFFF0000CC
      CC0000CCCC0000CCCC0000999900000000000000000000000000000000000000
      00000000000000000000CCCCCC006666660099999900CCCCCC00CCCCCC009999
      99009999990099999900666666000000000099666600FFCC9900CC9999009966
      6600FFCCCC00FFFFFF009966660000000000CC660000CC660000CC660000CC66
      0000CC660000CC660000CC6600000000000099999900C0C0C000999999006666
      6600CCCCCC00FFFFFF0099999900E5E5E5009999990099999900999999009999
      9900999999009999990099999900000000000000000000000000000000000000
      000000000000000000000000000000CCCC0000FFFF00FFFFFF00C0C0C00000FF
      FF0000CCCC0000CCCC0000CCCC00009999000000000000000000000000000000
      000000000000000000000000000099999900CCCCCC00FFFFFF00C0C0C000CCCC
      CC009999990099999900999999006666660099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF009966660000000000CC999900CC660000CC660000CC66
      0000CC660000CC660000CC6600000000000099999900C0C0C000C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900E5E5E5009999990099999900999999009999
      9900999999009999990099999900000000000000000000000000000000000000
      00000000000000000000000000000000000000CCCC0000FFFF00FFFFFF00C0C0
      C00000FFFF0000CCCC0000999900993300000000000000000000000000000000
      00000000000000000000000000000000000099999900CCCCCC00FFFFFF00C0C0
      C000CCCCCC0099999900666666006666660099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF0099666600CCCCCC00E2EFF100CC999900FF660000CC66
      00000000000000000000000000000000000099999900C0C0C000C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900CCCCCC00E2EFF10099999900999999009999
      9900000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000CCCC0000FFFF00FFFF
      FF0000FFFF0000999900CC660000993300000000000000000000000000000000
      0000000000000000000000000000000000000000000099999900CCCCCC00FFFF
      FF00CCCCCC0066666600999999006666660099666600FFCC9900FFCC9900FFCC
      9900FFCCCC00FFFFFF009966660099CCCC000000000099CCCC00FFCC9900CC66
      00000000000000000000000000000000000099999900C0C0C000C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900CCCCCC00E5E5E500CCCCCC00C0C0C0009999
      9900000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000CCCC0000FF
      FF0000CCCC00CC660000CC660000CC6600000000000000000000000000000000
      000000000000000000000000000000000000000000000000000099999900CCCC
      CC009999990099999900999999009999990099666600CC999900FFCC9900FFCC
      9900FFCCCC00FFFFFF0099666600CCCCCC00000000003399CC0000000000FFCC
      9900000000000000000000000000000000009999990099999900C0C0C000C0C0
      C000CCCCCC00FFFFFF0099999900CCCCCC00E5E5E5009999990000000000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000000CC
      CC00FF990000FF990000CC660000CC6600000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00999999009999990000000000C0C0C000CC996600CC99
      9900CCCC9900FFFFFF00996666000099CC000099CC000099CC00000000000000
      00000000000000000000000000000000000000000000C0C0C000999999009999
      9900C0C0C000FFFFFF0099999900999999009999990099999900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000099330000FF990000FF990000CC6600000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000066666600CCCCCC00CCCCCC0099999900000000000000000000000000CCCC
      CC00CC9999009966660099666600000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000CCCC
      CC00999999009999990099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099330000FF990000FF9900000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000066666600CCCCCC00CCCCCC000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099330000993300009933000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099999900999999009999990099999900000000000000
      0000000000000000000000000000000000000000000000000000000000009933
      0000993300009933000099330000993300009933000099330000993300009933
      0000993300000000000000000000000000000000000000000000000000009999
      9900999999009999990099999900999999009999990099999900999999009999
      9900999999000000000000000000000000000000000000000000000000000000
      0000CC99660099330000CC660000CC660000CC660000CC66000099330000CC99
      6600000000000000000000000000000000000000000000000000000000000000
      0000CCCCCC0099999900CCCCCC00CCCCCC00CCCCCC00CCCCCC0099999900CCCC
      CC00000000000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00999999000000000000000000000000000000000000000000000000000000
      000099330000CC660000CC660000CC660000CC660000CC660000CC6600009933
      0000000000000000000000000000000000000000000000000000000000000000
      000099999900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC009999
      9900000000000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00999999000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00999999000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00999999000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00999999000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00999999000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00999999000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00999999000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00999999000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00999999000000000000000000000000000000000000000000000000000000
      000099330000CC660000CC660000CC660000CC660000CC660000CC6600009933
      0000000000000000000000000000000000000000000000000000000000000000
      000099999900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC009999
      9900000000000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00999999000000000000000000000000000000000000000000000000000000
      0000CC99660099330000CC660000CC660000CC660000CC66000099330000CC99
      6600000000000000000000000000000000000000000000000000000000000000
      0000CCCCCC0099999900CCCCCC00CCCCCC00CCCCCC00CCCCCC0099999900CCCC
      CC00000000000000000000000000000000000000000000000000000000009933
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000993300000000000000000000000000000000000000000000000000009999
      9900CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00999999000000000000000000000000000000000000000000000000000000
      0000000000000000000099330000993300009933000099330000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099999900999999009999990099999900000000000000
      0000000000000000000000000000000000000000000000000000000000009933
      0000993300009933000099330000993300009933000099330000993300009933
      0000993300000000000000000000000000000000000000000000000000009999
      9900999999009999990099999900999999009999990099999900999999009999
      9900999999000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000007B000000000000000000000000000000000000000000
      000000000000000000007B000000000000000000000000000000000000000000
      000000000000000000007B000000000000000000000000000000000000000000
      000000000000000000007B000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000007B0000000000000000000000000000000000
      0000000000007B00000000000000000000000000000000000000000000000000
      00000000000000000000000000007B0000000000000000000000000000000000
      0000000000007B00000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B00000000000000000000000000
      00007B0000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B00000000000000000000000000
      00007B0000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000007B000000000000007B00
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000007B000000000000007B00
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007B0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007B0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000007B000000000000007B00
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000007B000000000000007B00
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B00000000000000000000000000
      00007B0000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007B00000000000000000000000000
      00007B000000000000000000000000000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000000000007B000000000000000000
      00000000000000000000000000007B000000000000007B000000000000000000
      0000000000007B0000000000000000000000000000007B000000000000000000
      00000000000000000000000000007B000000000000007B000000000000000000
      0000000000007B00000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007B0000000000
      000000000000000000007B000000000000007B00000000000000000000000000
      000000000000000000007B0000000000000000000000000000007B0000000000
      000000000000000000007B000000000000007B00000000000000000000000000
      000000000000000000007B000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000007B00
      00000000000000000000000000007B0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000007B00
      00000000000000000000000000007B0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00007B000000000000007B000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00007B000000000000007B000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000007B00000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000007B00000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00007B000000000000007B000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00007B000000000000007B000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000007B00
      00000000000000000000000000007B0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000007B00
      00000000000000000000000000007B0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007B0000000000
      0000000000000000000000000000000000007B00000000000000000000000000
      00000000000000000000000000000000000000000000000000007B0000000000
      0000000000000000000000000000000000007B00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000007B000000000000000000
      000000000000000000000000000000000000000000007B000000000000000000
      000000000000000000000000000000000000000000007B000000000000000000
      000000000000000000000000000000000000000000007B000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC996600CC99
      6600CC996600CC99660000000000000000000000000000000000999999009999
      9900999999009999990099999900999999009999990099999900999999009999
      99009999990099999900000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F7000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099999900000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F70000000000BDE7F7000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F70000000000BDE7F700000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC000000000099999900000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F70000000000BDE7F700000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F70000000000BDE7F70000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099999900000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F70000000000BDE7F700000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F70000000000BDE7F70000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC000000000099999900000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F70000000000BDE7F700000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F70000000000BDE7F70000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000009999990000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC0000000000999999000000000000000000BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F7000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000999999000000000000000000BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F7000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00000000009999990000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00CC99660000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000099999900000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F7000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700000000000000000000000000CC996600FFFF
      FF00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500FFFFFF00CC996600CC99
      6600CC996600CC99660000000000000000000000000000000000999999000000
      0000CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC0000000000999999009999
      99009999990099999900000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F7000000000000000000000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700000000000000000000000000000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC996600E5E5
      E500CC9966000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000999999000000
      00009999990000000000000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F70000000000BDE7F7000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F70000000000BDE7F700000000000000000000000000CC996600FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00CC996600CC99
      6600000000000000000000000000000000000000000000000000999999000000
      0000000000000000000000000000000000000000000000000000999999009999
      99000000000000000000000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F70000000000BDE7F7000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700BDE7F70000000000BDE7F700000000000000000000000000CC996600CC99
      6600CC996600CC996600CC996600CC996600CC996600CC996600CC9966000000
      0000000000000000000000000000000000000000000000000000999999009999
      9900999999009999990099999900999999009999990099999900999999000000
      00000000000000000000000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F7000000000000000000000000000000000000000000BDE7F700BDE7F700BDE7
      F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7F700BDE7
      F700000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000993300009933
      0000993300009933000099330000993300009933000099330000993300009933
      0000993300009933000099330000000000000000000000000000999999009999
      9900999999009999990099999900999999009999990099999900999999009999
      990099999900999999009999990000000000000000003399CC00006699000066
      9900006699000066990000669900006699000066990000669900006699000066
      990066CCCC000000000000000000000000000000000099999900999999009999
      9900999999009999990099999900999999009999990099999900999999009999
      9900CCCCCC000000000000000000000000000000000099330000CC660000CC66
      000099330000E5E5E500CC66000099330000E5E5E500E5E5E500E5E5E5009933
      0000CC660000CC66000099330000000000000000000099999900CCCCCC00CCCC
      CC0099999900E5E5E500CCCCCC0099999900E5E5E500E5E5E500E5E5E5009999
      9900CCCCCC00CCCCCC0099999900000000003399CC003399CC0099FFFF0066CC
      FF0066CCFF0066CCFF0066CCFF0066CCFF0066CCFF0066CCFF0066CCFF003399
      CC00006699000000000000000000000000009999990099999900E5E5E500CCCC
      CC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC009999
      9900999999000000000000000000000000000000000099330000CC660000CC66
      000099330000E5E5E500CC66000099330000E5E5E500E5E5E500E5E5E5009933
      0000CC660000CC66000099330000000000000000000099999900CCCCCC00CCCC
      CC0099999900E5E5E500CCCCCC0099999900E5E5E500E5E5E500E5E5E5009999
      9900CCCCCC00CCCCCC0099999900000000003399CC003399CC0066CCFF0099FF
      FF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0066CC
      FF00006699003399CC0000000000000000009999990099999900CCCCCC00E5E5
      E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500CCCC
      CC00999999009999990000000000000000000000000099330000CC660000CC66
      000099330000E5E5E500CC66000099330000E5E5E500E5E5E500E5E5E5009933
      0000CC660000CC66000099330000000000000000000099999900CCCCCC00CCCC
      CC0099999900E5E5E500CCCCCC0099999900E5E5E500E5E5E500E5E5E5009999
      9900CCCCCC00CCCCCC0099999900000000003399CC003399CC0066CCFF0099FF
      FF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0066CC
      FF0066CCCC000066990000000000000000009999990099999900CCCCCC00E5E5
      E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500CCCC
      CC00CCCCCC009999990000000000000000000000000099330000CC660000CC66
      000099330000E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E5009933
      0000CC660000CC66000099330000000000000000000099999900CCCCCC00CCCC
      CC0099999900E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E5009999
      9900CCCCCC00CCCCCC0099999900000000003399CC0066CCFF003399CC0099FF
      FF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0066CC
      FF0099FFFF00006699003399CC000000000099999900CCCCCC0099999900E5E5
      E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500CCCC
      CC00E5E5E5009999990099999900000000000000000099330000CC660000CC66
      0000CC660000993300009933000099330000993300009933000099330000CC66
      0000CC660000CC66000099330000000000000000000099999900CCCCCC00CCCC
      CC00CCCCCC00999999009999990099999900999999009999990099999900CCCC
      CC00CCCCCC00CCCCCC0099999900000000003399CC0066CCFF0066CCCC0066CC
      CC0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0099FFFF0066CC
      FF0099FFFF0066CCCC00006699000000000099999900CCCCCC00CCCCCC00CCCC
      CC00E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500CCCC
      CC00E5E5E500CCCCCC0099999900000000000000000099330000CC660000CC66
      0000CC660000CC660000CC660000CC660000CC660000CC660000CC660000CC66
      0000CC660000CC66000099330000000000000000000099999900CCCCCC00CCCC
      CC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCCCC00CCCC
      CC00CCCCCC00CCCCCC0099999900000000003399CC0099FFFF0066CCFF003399
      CC00CCFFFF00CCFFFF00CCFFFF00CCFFFF00CCFFFF00CCFFFF00CCFFFF0099FF
      FF00CCFFFF00CCFFFF00006699000000000099999900E5E5E500CCCCCC009999
      9900E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500E5E5E500E5E5E50099999900000000000000000099330000CC660000CC66
      0000993300009933000099330000993300009933000099330000993300009933
      0000CC660000CC66000099330000000000000000000099999900CCCCCC00CCCC
      CC00999999009999990099999900999999009999990099999900999999009999
      9900CCCCCC00CCCCCC0099999900000000003399CC0099FFFF0099FFFF0066CC
      FF003399CC003399CC003399CC003399CC003399CC003399CC003399CC003399
      CC003399CC003399CC0066CCFF000000000099999900E5E5E500E5E5E500CCCC
      CC00999999009999990099999900999999009999990099999900999999009999
      99009999990099999900CCCCCC00000000000000000099330000CC6600009933
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0099330000CC66000099330000000000000000000099999900CCCCCC009999
      9900FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0099999900CCCCCC0099999900000000003399CC00CCFFFF0099FFFF0099FF
      FF0099FFFF0099FFFF00CCFFFF00CCFFFF00CCFFFF00CCFFFF00CCFFFF000066
      99000000000000000000000000000000000099999900E5E5E500E5E5E500E5E5
      E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E500E5E5E5009999
      9900000000000000000000000000000000000000000099330000CC6600009933
      0000FFFFFF00993300009933000099330000993300009933000099330000FFFF
      FF0099330000CC66000099330000000000000000000099999900CCCCCC009999
      9900FFFFFF00999999009999990099999900999999009999990099999900FFFF
      FF0099999900CCCCCC009999990000000000000000003399CC00CCFFFF00CCFF
      FF00CCFFFF00CCFFFF003399CC003399CC003399CC003399CC003399CC000000
      0000000000000000000000000000000000000000000099999900E5E5E500E5E5
      E500E5E5E500E5E5E50099999900999999009999990099999900999999000000
      0000000000000000000000000000000000000000000099330000CC6600009933
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0099330000CC66000099330000000000000000000099999900CCCCCC009999
      9900FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0099999900CCCCCC00999999000000000000000000000000003399CC003399
      CC003399CC003399CC0000000000000000000000000000000000000000000000
      0000000000009933000099330000993300000000000000000000999999009999
      9900999999009999990000000000000000000000000000000000000000000000
      0000000000009999990099999900999999000000000099330000E5E5E5009933
      0000FFFFFF00993300009933000099330000993300009933000099330000FFFF
      FF00993300009933000099330000000000000000000099999900E5E5E5009999
      9900FFFFFF00999999009999990099999900999999009999990099999900FFFF
      FF00999999009999990099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099330000993300000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000099999900999999000000000099330000CC6600009933
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0099330000CC66000099330000000000000000000099999900CCCCCC009999
      9900FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0099999900CCCCCC0099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000099330000000000000000
      0000000000009933000000000000993300000000000000000000000000000000
      0000000000000000000000000000000000000000000099999900000000000000
      0000000000009999990000000000999999000000000099330000993300009933
      0000993300009933000099330000993300009933000099330000993300009933
      0000993300009933000099330000000000000000000099999900999999009999
      9900999999009999990099999900999999009999990099999900999999009999
      9900999999009999990099999900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000993300009933
      0000993300000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000999999009999
      9900999999000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000900000000100010000000000800400000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FFFFFFFFFFFFFFFFFFDFFFDFFFFFFFFF
      FF9FFF9FF3FFF3FF83018301E1FFE1FF0F900F90C0FFC0FF3FDC3FDC807F807F
      3C9C3C9C803F803F7C1E7C1E8C1F8C1F7E3E7E3E9E0F9E0F3C1C3C1CFF07FF07
      3C9C3C9CFF83FF830BF00BF0FFC3FFC380018001FFE3FFE3FFFFFFFFFFF3FFF3
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFFFDF
      F9FFF9FFFF9FFF9FF8FFF8FF83018301F87FF87F0F900F90E03FE03F3FDC3FDC
      E01FE01F3FFC3FFCE00FE00F7FFE7FFEE007E0077FFE7FFEE00FE00F3FFC3FFC
      E01FE01F3FFC3FFCE03FE03F0FF00FF0F87FF87F80018001F8FFF8FFFFFFFFFF
      F9FFF9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFE67FE67FFFFFFFFFE23FE23FE007E007E01FE01FC003C003800F800F
      C003C00380078007C003C00380038003C003C00380018001C003C00380038003
      C003C00380078007C003C003800F800FE007E007E01FE01FFFFFFFFFE23FE23F
      FFFFFFFFE67FE67FFFFFFFFFFFFFFFFFFDFFFDFFA7FFA7FFE0FFE8FF01FF01FF
      801FA05F007F007F001F803F003F003F001F001F001F001F000F000F500F500F
      000F000FF007F007000F000FF803F80300010001FC01FC0101010001FE00FE00
      01010001FF00FF00000F000FFF80FF80008F000FFFC0FFC000AF002FFFE0FFE0
      803F803FFFF0FFF0E1FFE1FFFFF8FFF8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFC3FFC3FE007E007F00FF00FE007E007F00FF00FE007E007
      E007E007E007E007E007E007E007E007E007E007E007E007E007E007E007E007
      F00FF00FE007E007F00FF00FE007E007FC3FFC3FE007E007FFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDFDFFFFFFFFFEFBFEFB
      FFFFFFFFFF77FF77FFFFFFFFFFAFFFAFFFFFFFFFFFDFFFDFFFFFFFFFFFAFFFAF
      FFFFFFFFFF77FF7700000000BEBBBEBBFFFFFFFFDD7DDD7DFFFFFFFFEEFFEEFF
      FFFFFFFFF5FFF5FFFFFFFFFFFBFFFBFFFFFFFFFFF5FFF5FFFFFFFFFFEEFFEEFF
      FFFFFFFFDF7FDF7FFFFFFFFFBFBFBFBFFFFFFFFFFFFFFFFFC003C00380018001
      C003DFFB80018001C003D00B80018001C003DFFB80018001C003D00B80018001
      C003DFFBFFFFFFFFC003D00B00000000C003DFFB00000000C003D00BFFFFFFFF
      C003DFFB80018001C003D04380018001C007DFD780018001C00FDFCF80018001
      C01FC01F80018001FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC001C001
      8007800780018001000700078001800100030003800180010003000380018001
      0001000180018001000100018001800100010001800180010001000180018001
      000F000F80018001801F801F80018001C3F8C3F880018001FFFCFFFC80018001
      FFBAFFBA80018001FFC7FFC7FFFFFFFF00000000000000000000000000000000
      000000000000}
  end
  object RzVersionInfo1: TRzVersionInfo
    Left = 528
    Top = 328
  end
  object PopupMenu1: TPopupMenu
    Left = 464
    Top = 192
    object N16: TMenuItem
      Caption = #1055#1077#1088#1077#1080#1084#1077#1085#1086#1074#1072#1090#1100
    end
    object N17: TMenuItem
      Caption = '-'
    end
    object N18: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100
      Enabled = False
    end
  end
  object RzRegIniFile1: TRzRegIniFile
    Left = 576
    Top = 192
  end
  object RzFormState1: TRzFormState
    RegIniFile = RzRegIniFile1
    Left = 576
    Top = 280
  end
  object xJvThread1: TJvThread
    Exclusive = True
    MaxCount = 0
    RunOnCreate = True
    FreeOnTerminate = False
    Priority = tpHighest
    OnExecute = xJvThread1Execute
    Left = 576
    Top = 328
  end
  object RzPropertyStore1: TRzPropertyStore
    Properties = <
      item
        Component = RzNumericEdit1
        PropertyName = 'Value'
      end
      item
        Component = RzNumericEdit2
        PropertyName = 'Value'
      end
      item
        Component = RzNumericEdit3
        PropertyName = 'Value'
      end
      item
        Component = CheckBox1
        PropertyName = 'Checked'
      end
      item
        Component = RzNumericEdit4
        PropertyName = 'Value'
      end
      item
        Component = RzSpinEdit1
        PropertyName = 'Value'
      end
      item
        Component = RzNumericEdit5
        PropertyName = 'Value'
      end>
    RegIniFile = RzRegIniFile1
    Section = 'Settings'
    Left = 416
    Top = 192
  end
  object MSWheel1: TMSWheel
    Auto = True
    Version = '1.5.0.0'
    OnWheelEvent = MSWheel1WheelEvent
    Left = 192
    Top = 160
  end
end
