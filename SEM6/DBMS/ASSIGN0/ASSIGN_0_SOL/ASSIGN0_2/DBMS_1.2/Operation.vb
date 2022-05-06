Public Class Operation
    Public Property Stud_list As [STUDENT]()
    Private Studentlist(10) As STUDENT
    Private DeptList(5) As DEPARTMENT
    Private currentcountStudents As Integer = 0
    Private currentcountDepartment As Integer = 0

    Public Sub setStudentList(value As STUDENT)

        Studentlist(currentcountStudents) = New STUDENT()
        Dim currstudent As STUDENT = Studentlist(currentcountStudents)
        currstudent.setName(value.getName())
        currstudent.setDeptCode(value.getDeptCode())
        currstudent.setPhone(value.getPhone())
        currstudent.setAddress(value.getAddress())
        currstudent.setRoll(value.getRoll())
        currentcountStudents += 1
    End Sub
    Public Sub setDeptList(value As DEPARTMENT)

        DeptList(currentcountDepartment).setDeptName(value.getDeptName())
        DeptList(currentcountStudents).setDeptCode(value.getDeptCode())
        currentcountDepartment = currentcountDepartment + 1

    End Sub

    Public Sub setStudentCount(count As Integer)
        currentcountStudents = count
    End Sub


    Public Function getStudentList() As STUDENT()
        Return Studentlist
    End Function

    Public Function getDeptList() As DEPARTMENT()
        Return DeptList
    End Function


    Public Function getcurrentStudentCount() As Integer
        Return currentcountStudents
    End Function

    Public Function getdeptCount() As Integer
        Return currentcountDepartment
    End Function



End Class
