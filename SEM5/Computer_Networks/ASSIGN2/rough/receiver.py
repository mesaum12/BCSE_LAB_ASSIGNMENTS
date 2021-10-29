import socket
while True:
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind((socket.gethostname(),5000))
    s.listen(5)
    clientsocket,address=s.accept()
    print(f"Connection from {address} has been established.")
