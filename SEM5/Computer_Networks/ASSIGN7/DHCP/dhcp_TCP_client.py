import socket

# Initially take the address to be empty tuple and then after server assigns it , display it .
Address = ("","")
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((socket.gethostname(), 5000))
s.send(bytes("Requesting port number of the host" , "utf-8"))
Address = s.recv(1024).decode()
print("You are assigned an address: " ,Address)
s.close()
