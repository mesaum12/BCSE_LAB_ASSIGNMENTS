import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((socket.gethostname(), 12345))

filename=input("Enter the filename where incoming file needs to be saved :")
file=open(filename,'wb')
fileData=s.recv(1024)
file.write(fileData)
file.close()

print("The file has been received successfully!!")


   
   






