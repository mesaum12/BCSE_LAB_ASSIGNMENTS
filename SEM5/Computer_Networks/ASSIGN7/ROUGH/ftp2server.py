import socket

while True:
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind((socket.gethostname(),12345))
    s.listen(1)
    conn,address=s.accept()
    print(f"Connection from {address} has been established.")
    filename = conn.recv(1024).decode()
    file = open(filename, 'r')
    data = file.read()
    file.close()
    conn.send(bytes(data, "utf-8"))
    s.close()