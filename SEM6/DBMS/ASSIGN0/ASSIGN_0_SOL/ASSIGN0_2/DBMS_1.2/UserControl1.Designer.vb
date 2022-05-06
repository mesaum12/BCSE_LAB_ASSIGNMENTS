<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class UserControl1
    Inherits System.Windows.Forms.UserControl

    'UserControl overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.DISPLAY = New System.Windows.Forms.ListView()
        Me.PREV = New System.Windows.Forms.Button()
        Me.NXT = New System.Windows.Forms.Button()
        Me.SNAME = CType(New System.Windows.Forms.ColumnHeader(), System.Windows.Forms.ColumnHeader)
        Me.ROLL = CType(New System.Windows.Forms.ColumnHeader(), System.Windows.Forms.ColumnHeader)
        Me.DEPT = CType(New System.Windows.Forms.ColumnHeader(), System.Windows.Forms.ColumnHeader)
        Me.DCODE = CType(New System.Windows.Forms.ColumnHeader(), System.Windows.Forms.ColumnHeader)
        Me.ADDRESS = CType(New System.Windows.Forms.ColumnHeader(), System.Windows.Forms.ColumnHeader)
        Me.PHONE = CType(New System.Windows.Forms.ColumnHeader(), System.Windows.Forms.ColumnHeader)
        Me.SuspendLayout()
        '
        'DISPLAY
        '
        Me.DISPLAY.Columns.AddRange(New System.Windows.Forms.ColumnHeader() {Me.SNAME, Me.ROLL, Me.DEPT, Me.DCODE, Me.ADDRESS, Me.PHONE})
        Me.DISPLAY.HideSelection = False
        Me.DISPLAY.Location = New System.Drawing.Point(38, 24)
        Me.DISPLAY.Name = "DISPLAY"
        Me.DISPLAY.Size = New System.Drawing.Size(1059, 505)
        Me.DISPLAY.TabIndex = 0
        Me.DISPLAY.UseCompatibleStateImageBehavior = False
        '
        'PREV
        '
        Me.PREV.Location = New System.Drawing.Point(188, 549)
        Me.PREV.Name = "PREV"
        Me.PREV.Size = New System.Drawing.Size(174, 58)
        Me.PREV.TabIndex = 1
        Me.PREV.Text = "PREV"
        Me.PREV.UseVisualStyleBackColor = True
        '
        'NXT
        '
        Me.NXT.Location = New System.Drawing.Point(420, 549)
        Me.NXT.Name = "NXT"
        Me.NXT.Size = New System.Drawing.Size(195, 58)
        Me.NXT.TabIndex = 2
        Me.NXT.Text = "NEXT"
        Me.NXT.UseVisualStyleBackColor = True
        '
        'SNAME
        '
        Me.SNAME.Text = "SNAME"
        '
        'UserControl1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(9.0!, 20.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.Controls.Add(Me.NXT)
        Me.Controls.Add(Me.PREV)
        Me.Controls.Add(Me.DISPLAY)
        Me.Name = "UserControl1"
        Me.Size = New System.Drawing.Size(1121, 670)
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents DISPLAY As ListView
    Friend WithEvents PREV As Button
    Friend WithEvents NXT As Button
    Friend WithEvents SNAME As ColumnHeader
    Friend WithEvents ROLL As ColumnHeader
    Friend WithEvents DEPT As ColumnHeader
    Friend WithEvents DCODE As ColumnHeader
    Friend WithEvents ADDRESS As ColumnHeader
    Friend WithEvents PHONE As ColumnHeader
End Class
