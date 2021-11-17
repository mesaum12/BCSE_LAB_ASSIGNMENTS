
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((socket.gethostname(), 12345))

filename = input("Enter filename to be searched: ")
s.send(bytes(filename, "utf-8"))

data = s.recv(1024).decode()

if data[0]=="1":
    print(data[1:])
else:
    print(" File found !")
    print("File contains the following : ", data)

s.close()
