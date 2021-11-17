
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((socket.gethostname(), 12345))

# choices with the user 
print("1.Search for a file on the server ")
print("2.Rename a file  ")
print("3.Upload a file on the server database ")
while True:
    choice=int(input("Enter your choice: "))
    if choice<1 or choice>3:
        print("--Please enter a valid choice--")
    else:
        break



if choice==1:
    filename = input("Enter filename to be searched: ")
    s.send(bytes("1"+filename, "utf-8"))
    data = s.recv(1024).decode()
    if data[0]=="1":
        print(data[1:])
    else:
        print(" File found !")
        print("File contains the following : ", data)

elif choice==2:
    filename = input("Enter filename to be renamed: ")
    s.send(bytes("2"+filename, "utf-8"))
    data = s.recv(1024).decode()
    if data[0]=="1":
        print(data[1:])
    else:
        print("File renamed!")
        
elif choice==3:
    filename = input("Enter filename to be uploaded: ")
    try:
        file=open(filename,'r')
        data=file.read()
        file.close()       
        s.send(bytes("3"+filename, "utf-8"))
        s.send(bytes(data, "utf-8"))
        print('File uploaded Successfully')
    except:
        s.send(bytes("31Upload error!!", "utf-8"))
        print("No such file exists !")

else:
    exit()

s.close()
