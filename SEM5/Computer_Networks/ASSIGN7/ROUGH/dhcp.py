import socket


HOST = '127.0.0.1'  
OWNport = 4900       
BGPport = 5000

print("----Welcome to the DHCP server----")
while True:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((HOST, OWNport))
    print("Listening for a connection on its own port....")
    s.listen()
    conn, addr = s.accept()
    print("Connected by", addr)
    message = conn.recv(1024).decode() #receives requesting port number of the host
    name = conn.recv(1024).decode() #receives the name of the host
    print(message, " received from ", addr , " named " , name) #display message received
    conn.send(bytes(str(addr), "utf-8")) 
    conn.close()
    s.close()
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST, BGPport))
    s.send(bytes("Request to add host to the log!", "utf-8"))
    message = s.recv(1024).decode()
    print("Message received: ", message)
    s.send(bytes(name, "utf-8"))
    message = s.recv(1024).decode()
    print("Message received: ", message)
    s.send(bytes(str(addr), "utf-8"))
    print(name + " added to the log!")
    