import socket

# from client import host

host = '127.0.0.1'  # the local host address
port = 4800         # the port number on which the connection would be establised

while True:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((host, port))
    s.listen()
    conn, addr = s.accept()
    print('Connected to: ' + addr[0] + ':' + str(addr[1]))
    name = conn.recv(1024).decode()
    filename = conn.recv(1024).decode()
    print(name, " with address " , addr , " is requesting file: ", filename)
    file = open(filename, 'r')
    data = file.read()
    conn.send(bytes(data, "utf-8"))
    s.close()
    

