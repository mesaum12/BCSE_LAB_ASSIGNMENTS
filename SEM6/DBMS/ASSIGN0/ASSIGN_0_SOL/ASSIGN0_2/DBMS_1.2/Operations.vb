Public Class Operations
    Public Sub Main()

        Dim StudentList(10) As STUDENT

        StudentList(0) = New STUDENT()
        StudentList(0).setRoll("1")
        StudentList(0).setName("Saurabh")
        StudentList(0).setAddress("Jadavpur")
        StudentList(0).setPhone("12345")
        StudentList(0).setDeptCode("BCSE")

        Dim DeptList(5) As DEPARTMENT

        DeptList(0) = New DEPARTMENT()
        DeptList(0).setDeptCode("BCSE")
        DeptList(0).setDeptName("COMPUTER SCIENCE ENGG.")



    End Sub
End Class
