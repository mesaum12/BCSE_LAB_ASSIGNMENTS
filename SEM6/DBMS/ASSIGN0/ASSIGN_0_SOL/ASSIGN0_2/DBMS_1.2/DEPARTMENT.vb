Public Class DEPARTMENT
    Private DeptCode As String
    Private DeptName As String
    Public Sub setDeptCode(value As String)
        DeptCode = value
    End Sub
    Public Sub setDeptName(value As String)
        DeptName = value
    End Sub
    Public Function getDeptName() As String
        Return DeptName
    End Function
    Public Function getDeptCode() As String
        Return DeptCode
    End Function
End Class
