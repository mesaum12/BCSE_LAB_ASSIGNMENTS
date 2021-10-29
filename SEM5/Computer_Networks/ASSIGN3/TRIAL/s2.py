import socket
import os,random,pickle
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
ServerSideSocket.listen(5)

# def multi_threaded_client(connection):
#     # connection.send(str.encode('Server is working:'))
    
#     data = connection.recv(2048)#data is received in dictionary format from the sender 
#     # response = 'Server message: ' + data.decode('utf-8')
    
#     random_number=random.randint(1,100)
#     # if random_number>75:
#     #     msg={"ack":0}
#     # else:
#     #     msg={"ack":1}#proper receival of the data packet
#     msg={"ack":random_number%2}
#     tosend=pickle.dumps(msg)
#     connection.sendall(tosend)
#     connection.close()

def multi_threaded_client(connection):
    while True:
        data = connection.recv(2048)
        random_number=random.randint(1,100)
        msg={"ack":random_number%2}
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

