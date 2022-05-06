Public Class Form1

    Public Property op As Operation
    Dim operation As New Operation()
    Dim StudentList As [STUDENT]() = operation.getStudentList()
    Public Function checkUniqueRoll(value As String)

        For index As Integer = 0 To operation.getcurrentStudentCount() - 1
            Dim currentRoll As String = StudentList(index).getRoll()
            If currentRoll = value Then
                Return 0
            End If
        Next
        Return 1
    End Function

    Public Function deptNameToCodeMap(DEPT_NAME As String) As String

        Dim DEPT_CODE As String
        Select Case DEPT_NAME
            Case "CSE"
                DEPT_CODE = "CS001"
            Case "ETC"
                DEPT_CODE = "ETC002"
            Case "CIVIL"
                DEPT_CODE = "CIV003"
            Case "MECHANICAL"
                DEPT_CODE = "MECH004"
            Case "IT"
                DEPT_CODE = "IT005"
        End Select

        Return DEPT_CODE

    End Function


    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles ADD.Click

        Dim student As STUDENT
        student = New STUDENT()
        Dim DEPT_NAME As String = ComboBox1.Text

        Dim DEPT_CODE As String = deptNameToCodeMap(DEPT_NAME)


        'DECIDING THE DEPT CODE FROM THE DEPT NAME CHOSEN
        Dim roll As String = SROLL.Text 'Get the roll number of the student to be added and check its uniqueness 
        If checkUniqueRoll(roll) = 0 Then
            MessageBox.Show("  Student already exists !! ")
        ElseIf SROLL.Text = "" Then
            MessageBox.Show("PLEASE ENTER A VALID ROLL NUMBER")
        ElseIf SNAME.Text = "" Then
            MessageBox.Show("Please enter a valid name , can't be empty !")
        ElseIf ADDRESS.Text = "" Then
            MessageBox.Show("Please enter a valid address !!")
        ElseIf PHONE.Text.Length < 9 Then
            MessageBox.Show("Phone numbers must be at least 9 digits long")
        ElseIf PHONE.Text.Length > 11 Then
            MsgBox("Phone numbers must be of a maximum of 11 digits long")
            PHONE.Focus()
        Else
            'set the student property and add it to the current student list
            student.setRoll(SROLL.Text)
            student.setName(SNAME.Text)
            student.setDeptCode(DEPT_CODE)
            student.setAddress(ADDRESS.Text)
            student.setPhone(PHONE.Text)
            operation.setStudentList(student)
            MessageBox.Show("Student Successfully added !!")
        End If



    End Sub

    Public Function searchHelper(Roll As String) As Integer

        For index As Integer = 0 To operation.getcurrentStudentCount - 1
            Dim student As STUDENT
            student = StudentList(index)
            If student.getRoll() = Roll Then
                Return index
            End If

        Next
        Return -1

    End Function





    Private Sub SEARCH_Click(sender As Object, e As EventArgs) Handles SEARCH.Click

        Dim Roll As String
        Roll = SROLL.Text
        Dim flag As Integer = searchHelper(Roll)
        If flag = -1 Then
            MessageBox.Show("No such student Exists !!")
        Else
            MessageBox.Show("Student Found !!")
        End If
    End Sub







    Private Sub EDIT_Click(sender As Object, e As EventArgs) Handles EDIT.Click
        Dim Roll As String
        Roll = SROLL.Text 'extract out the roll number of the student first 
        Dim flag As Integer = searchHelper(Roll) ' check if the roll number exists 
        If flag = -1 Then
            MessageBox.Show(" No such student Exists !!")
        Else
            MessageBox.Show("  Student Found,Please enter the new details !!")

            'edit portion start 
            Dim student As New STUDENT()
            Dim DEPT_NAME As String = ComboBox1.Text
            'set everything except the roll number 
            student.setRoll(StudentList(flag).getRoll())
            student.setName(SNAME.Text)
            student.setDeptCode(deptNameToCodeMap(DEPT_NAME))
            student.setAddress(ADDRESS.Text)
            student.setPhone(PHONE.Text)
            StudentList(flag) = student
            MessageBox.Show("Student details successfully edited !!")

            'edit portion ended 

        End If

    End Sub

    Private Sub DELETE_Click(sender As Object, e As EventArgs) Handles DELETE.Click

        Dim Roll As String
        Roll = SROLL.Text 'extract out the roll number of the student first 
        Dim flag As Integer = searchHelper(Roll) ' check if the roll number exists 
        If flag = -1 Then
            MessageBox.Show("No such student Exists !!")
        Else

            'we have the index of the roll at flag variable , now we must copy the 
            If operation.getcurrentStudentCount() = 1 Then
                operation.setStudentCount(operation.getcurrentStudentCount() - 1)
            Else
                Dim current As Integer = flag
                For index As Integer = flag To operation.getcurrentStudentCount() - 2
                    StudentList(current) = StudentList(current + 1)
                Next
                operation.setStudentCount(operation.getcurrentStudentCount() - 1)
                MessageBox.Show("Details successfully deleted !!")


            End If

        End If

    End Sub
    Private Sub DISPLAY_Click(sender As Object, e As EventArgs) Handles DISPLAY.Click

        op = operation
        Dim newform As New Form2
        newform.operation = operation
        newform.Show()

    End Sub

    'INITIALLY TWO STUDENTS 'SAURABH' AND 'SUDIPTO' ARE PRELOADED INTO THE ARRAY 
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load

        Me.Text = "STUDENT REGISTRATION FORM"

        Dim ST As STUDENT = New STUDENT()
        ST.setRoll("1")
        ST.setName("Saurabh")
        ST.setDeptCode("CS001")
        ST.setAddress("KOLKATA")
        ST.setPhone("9798313192")
        operation.setStudentList(ST)

        ST.setRoll("2")
        ST.setName("Sudipto")
        ST.setDeptCode("ETC002")
        ST.setAddress("KOLKATA")
        ST.setPhone("9798315492")
        operation.setStudentList(ST)

    End Sub

    Private Sub Button1_Click_1(sender As Object, e As EventArgs) Handles Button1.Click
        SNAME.Text = ""
        SROLL.Text = ""
        ADDRESS.Text = ""
        PHONE.Text = ""

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Button1_Click(sender, e)
        Button1_Click_1(sender, e)
    End Sub

End Class




























