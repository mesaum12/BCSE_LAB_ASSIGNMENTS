<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
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
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.ADD = New System.Windows.Forms.Button()
        Me.DISPLAY = New System.Windows.Forms.Button()
        Me.DELETE = New System.Windows.Forms.Button()
        Me.EDIT = New System.Windows.Forms.Button()
        Me.SEARCH = New System.Windows.Forms.Button()
        Me.SNAME = New System.Windows.Forms.TextBox()
        Me.PHONE = New System.Windows.Forms.TextBox()
        Me.ADDRESS = New System.Windows.Forms.TextBox()
        Me.SROLL = New System.Windows.Forms.TextBox()
        Me.Label7 = New System.Windows.Forms.Label()
        Me.DataSet1 = New System.Data.DataSet()
        Me.ComboBox1 = New System.Windows.Forms.ComboBox()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.Button2 = New System.Windows.Forms.Button()
        CType(Me.DataSet1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.ForeColor = System.Drawing.Color.White
        Me.Label1.Location = New System.Drawing.Point(50, 61)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(55, 20)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "NAME"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.ForeColor = System.Drawing.Color.White
        Me.Label2.Location = New System.Drawing.Point(482, 135)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(65, 20)
        Me.Label2.TabIndex = 1
        Me.Label2.Text = "PHONE"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.ForeColor = System.Drawing.Color.White
        Me.Label3.Location = New System.Drawing.Point(471, 64)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(89, 20)
        Me.Label3.TabIndex = 2
        Me.Label3.Text = "ADDRESS"
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.ForeColor = System.Drawing.Color.White
        Me.Label5.Location = New System.Drawing.Point(50, 115)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(51, 20)
        Me.Label5.TabIndex = 4
        Me.Label5.Text = "ROLL"
        '
        'ADD
        '
        Me.ADD.BackColor = System.Drawing.Color.FromArgb(CType(CType(128, Byte), Integer), CType(CType(255, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.ADD.Location = New System.Drawing.Point(77, 255)
        Me.ADD.Name = "ADD"
        Me.ADD.Size = New System.Drawing.Size(99, 46)
        Me.ADD.TabIndex = 5
        Me.ADD.Text = "ADD"
        Me.ADD.UseVisualStyleBackColor = False
        '
        'DISPLAY
        '
        Me.DISPLAY.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(128, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.DISPLAY.Location = New System.Drawing.Point(635, 255)
        Me.DISPLAY.Name = "DISPLAY"
        Me.DISPLAY.Size = New System.Drawing.Size(120, 46)
        Me.DISPLAY.TabIndex = 7
        Me.DISPLAY.Text = "DISPLAY"
        Me.DISPLAY.UseVisualStyleBackColor = False
        '
        'DELETE
        '
        Me.DELETE.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer))
        Me.DELETE.Location = New System.Drawing.Point(486, 255)
        Me.DELETE.Name = "DELETE"
        Me.DELETE.Size = New System.Drawing.Size(106, 46)
        Me.DELETE.TabIndex = 8
        Me.DELETE.Text = "DELETE"
        Me.DELETE.UseVisualStyleBackColor = False
        '
        'EDIT
        '
        Me.EDIT.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.EDIT.Location = New System.Drawing.Point(347, 255)
        Me.EDIT.Name = "EDIT"
        Me.EDIT.Size = New System.Drawing.Size(90, 46)
        Me.EDIT.TabIndex = 9
        Me.EDIT.Text = "EDIT"
        Me.EDIT.UseVisualStyleBackColor = False
        '
        'SEARCH
        '
        Me.SEARCH.BackColor = System.Drawing.Color.FromArgb(CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer))
        Me.SEARCH.Location = New System.Drawing.Point(214, 255)
        Me.SEARCH.Name = "SEARCH"
        Me.SEARCH.Size = New System.Drawing.Size(102, 46)
        Me.SEARCH.TabIndex = 10
        Me.SEARCH.Text = "SEARCH"
        Me.SEARCH.UseVisualStyleBackColor = False
        '
        'SNAME
        '
        Me.SNAME.Location = New System.Drawing.Point(179, 58)
        Me.SNAME.Name = "SNAME"
        Me.SNAME.Size = New System.Drawing.Size(175, 26)
        Me.SNAME.TabIndex = 11
        '
        'PHONE
        '
        Me.PHONE.Location = New System.Drawing.Point(616, 135)
        Me.PHONE.Name = "PHONE"
        Me.PHONE.Size = New System.Drawing.Size(175, 26)
        Me.PHONE.TabIndex = 13
        '
        'ADDRESS
        '
        Me.ADDRESS.Location = New System.Drawing.Point(616, 61)
        Me.ADDRESS.Name = "ADDRESS"
        Me.ADDRESS.Size = New System.Drawing.Size(175, 26)
        Me.ADDRESS.TabIndex = 14
        '
        'SROLL
        '
        Me.SROLL.Location = New System.Drawing.Point(179, 112)
        Me.SROLL.Name = "SROLL"
        Me.SROLL.Size = New System.Drawing.Size(175, 26)
        Me.SROLL.TabIndex = 16
        '
        'Label7
        '
        Me.Label7.AutoSize = True
        Me.Label7.ForeColor = System.Drawing.Color.White
        Me.Label7.Location = New System.Drawing.Point(50, 178)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(51, 20)
        Me.Label7.TabIndex = 18
        Me.Label7.Text = "DEPT"
        '
        'DataSet1
        '
        Me.DataSet1.DataSetName = "NewDataSet"
        '
        'ComboBox1
        '
        Me.ComboBox1.FormattingEnabled = True
        Me.ComboBox1.Items.AddRange(New Object() {"CSE", "ETC", "CIVIL", "MECHANICAL", "IT"})
        Me.ComboBox1.Location = New System.Drawing.Point(179, 170)
        Me.ComboBox1.Name = "ComboBox1"
        Me.ComboBox1.Size = New System.Drawing.Size(175, 28)
        Me.ComboBox1.TabIndex = 20
        '
        'Button1
        '
        Me.Button1.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(128, Byte), Integer), CType(CType(0, Byte), Integer))
        Me.Button1.Location = New System.Drawing.Point(293, 338)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(97, 51)
        Me.Button1.TabIndex = 21
        Me.Button1.Text = "CANCEL"
        Me.Button1.UseVisualStyleBackColor = False
        '
        'Button2
        '
        Me.Button2.BackColor = System.Drawing.Color.Lime
        Me.Button2.Location = New System.Drawing.Point(444, 338)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(116, 51)
        Me.Button2.TabIndex = 22
        Me.Button2.Text = "SAVE"
        Me.Button2.UseVisualStyleBackColor = False
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(9.0!, 20.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.Color.Black
        Me.ClientSize = New System.Drawing.Size(867, 438)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.ComboBox1)
        Me.Controls.Add(Me.Label7)
        Me.Controls.Add(Me.SROLL)
        Me.Controls.Add(Me.ADDRESS)
        Me.Controls.Add(Me.PHONE)
        Me.Controls.Add(Me.SNAME)
        Me.Controls.Add(Me.SEARCH)
        Me.Controls.Add(Me.EDIT)
        Me.Controls.Add(Me.DELETE)
        Me.Controls.Add(Me.DISPLAY)
        Me.Controls.Add(Me.ADD)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Name = "Form1"
        Me.Text = "Form1"
        CType(Me.DataSet1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label5 As Label
    Friend WithEvents ADD As Button
    Friend WithEvents DISPLAY As Button
    Friend WithEvents DELETE As Button
    Friend WithEvents EDIT As Button
    Friend WithEvents SEARCH As Button
    Friend WithEvents SNAME As TextBox
    Friend WithEvents PHONE As TextBox
    Friend WithEvents ADDRESS As TextBox
    Friend WithEvents SROLL As TextBox
    Friend WithEvents Label7 As Label
    Friend WithEvents DataSet1 As DataSet
    Friend WithEvents ComboBox1 As ComboBox
    Friend WithEvents Button1 As Button
    Friend WithEvents Button2 As Button
End Class
