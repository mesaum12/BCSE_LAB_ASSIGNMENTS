Public Class Form2

    Public Property operation As Operation
    Dim list As [STUDENT]()
    Dim count As Integer = 0

    Private Sub setButtonactiveOrInactive()
        Dim total As Integer = operation.getcurrentStudentCount()
        ' Initially check the condition and disable both the buttons if the number of students are less than or equal to 5
        If total <= 5 Then
            Button1.Enabled = False
            Button2.Enabled = False
        ElseIf count = 0 Then
            Button1.Enabled = False
        ElseIf count + 5 = total Then
            Button2.Enabled = False
        Else
            Button1.Enabled = True
            Button2.Enabled = True
        End If


    End Sub
    Private Sub Form2_Load(sender As Object, e As EventArgs) Handles MyBase.Load

        Me.Text = " STUDENT LIST  "
        list = operation.getStudentList()
        Dim DisplayText As String = ""
        For index As Integer = 0 To Math.Min(5, operation.getcurrentStudentCount()) - 1
            DisplayText += "STUDENT NAME:" + list(index).getName() + " ROLL NUM:" + list(index).getRoll() + " DEPT CODE:" + list(index).getDeptCode() + " ADDRESS:" + list(index).getAddress() + " CONTACT:" + list(index).getPhone + vbCrLf
        Next
        TextBox1.Text = DisplayText
        setButtonactiveOrInactive()
    End Sub


    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        count -= 1
        setButtonactiveOrInactive()
        Dim displaytext As String = ""
        For index As Integer = count To Math.Min(count + 4, operation.getcurrentStudentCount() - 1)
            displaytext += "STUDENT NAME:" + list(index).getName() + " ROLL NUM:" + list(index).getRoll() + " DEPT CODE:" + list(index).getDeptCode() + " ADDRESS:" + list(index).getAddress() + " CONTACT:" + list(index).getPhone + vbCrLf
        Next
        TextBox1.Text = displaytext

    End Sub




    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        count += 1
        setButtonactiveOrInactive()

        Dim displaytext As String = ""
        For index As Integer = count To Math.Min(count + 4, operation.getcurrentStudentCount() - 1)
            displaytext += "STUDENT NAME:" + list(index).getName() + " ROLL NUM:" + list(index).getRoll() + " DEPT CODE:" + list(index).getDeptCode() + " ADDRESS:" + list(index).getAddress() + " CONTACT:" + list(index).getPhone + vbCrLf
        Next
        TextBox1.Text = displaytext

    End Sub



End Class