Public Class STUDENT
    Private Roll As String
    Private DeptCode As String
    Private Name As String
    Private Address As String
    Private Phone As String
    Public Sub setRoll(value As String)
        Roll = value
    End Sub

    Public Sub setDeptCode(value As String)
        DeptCode = value
    End Sub

    Public Sub setName(value As String)
        Name = value
    End Sub

    Public Sub setAddress(value As String)
        Address = value
    End Sub

    Public Sub setPhone(value As String)
        Phone = value
    End Sub

    Public Function getRoll() As String
        Return Roll
    End Function

    Public Function getName() As String
        Return Name
    End Function

    Public Function getDeptCode() As String
        Return DeptCode
    End Function

    Public Function getAddress() As String
        Return Address
    End Function

    Public Function getPhone() As String
        Return Phone
    End Function
End Class
