import socket
import random,pickle
from _thread import *

ThreadCount = 0
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

try:
    s.bind((socket.gethostname(),12345))
except socket.error as e:
    print(str(e))

print('Socket is listening..')
s.listen(1)

def multi_threaded_client(conn):
        filename = conn.recv(1024).decode()
        file = open(filename, 'r')
        data = file.read()
        file.close()
        conn.send(bytes(data, "utf-8"))
        conn.close()
   
while True:
    conn,address=s.accept()
    print('Connected to: ' + address[0] + ':' + str(address[1]))
    start_new_thread(multi_threaded_client, (conn, ))
    ThreadCount += 1
    print('Thread Number: ' + str(ThreadCount))

