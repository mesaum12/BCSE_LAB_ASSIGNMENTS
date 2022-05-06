Public Class Form1
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim A, B As Integer
        A = TextBox1.Text
        B = TextBox2.Text
        TextBox3.Text = A + B

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Dim A, B As Integer
        A = TextBox1.Text
        B = TextBox2.Text
        TextBox3.Text = A - B
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click

        TextBox1.Text = " "
        TextBox2.Text = " "
        TextBox3.Text = " "
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Dim dt As Date = Date.Today
        Me.Text = dt.ToString("dd'/'MM'/'yyyy")
    End Sub
End Class
