import socket

while True:
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind((socket.gethostname(),5000))
    print("Listening for a connection on its own port....")
    s.listen(1)
    conn,addr=s.accept()
    print("Connected by", addr)
    message = conn.recv(1024).decode() #receives requesting port number of the host
    print(message, " received from ", addr ) #display message received
    conn.send(bytes(str(addr), "utf-8")) 
    conn.close()
    s.close()