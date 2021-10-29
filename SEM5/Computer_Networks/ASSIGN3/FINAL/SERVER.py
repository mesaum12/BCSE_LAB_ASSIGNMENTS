import socket
import random,pickle
from _thread import *

ServerSideSocket = socket.socket()
host = '127.0.0.1'
port = 2004
ThreadCount = 0
try:
    ServerSideSocket.bind((host, port))
except socket.error as e:
    print(str(e))

print('Socket is listening..')
ServerSideSocket.listen(10)

def multi_threaded_client(connection):
    while True:
        data = connection.recv(2048)
        random_number=random.randint(0,10)
        msg={"ack":random_number}
        tosend=pickle.dumps(msg)
        if not data:
            break
        connection.sendall(tosend)
    connection.close()
    

while True:
    Client, address = ServerSideSocket.accept()
    print('Connected to: ' + address[0] + ':' + str(address[1]))
    start_new_thread(multi_threaded_client, (Client, ))
    ThreadCount += 1
    print('Thread Number: ' + str(ThreadCount))

