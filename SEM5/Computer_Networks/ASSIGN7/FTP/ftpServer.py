import socket
import os
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
        choice=int(filename[0])
        filename=filename[1:]
        if choice==1:
            try:
                file = open(r"./serverDatabase/"+filename, 'r')
                data = file.read()
                file.close()
                conn.send(bytes(data, "utf-8"))
            except:
                data="1No such file found !"
                conn.send(bytes(data,"utf-8"))
            finally:
                conn.close()
        elif choice==2:
             try:
                os.rename(r"./serverDatabase/"+filename,"./serverDatabase/Renamed.txt")
                conn.send(bytes("File renamed successfully !", "utf-8"))
             except:
                data="1No such file exists !"
                conn.send(bytes(data,"utf-8"))
             finally:
                conn.close()
        else:
            if filename[0]=="1":
                print(filename[1:])
            else:
                fdata = conn.recv(1024).decode()
                file = open(r"./serverDatabase/"+filename, 'w')
                file.write(fdata)
                file.close()
            conn.close()
            

while True:
    conn,address=s.accept()
    print('Connected to: ' + address[0] + ':' + str(address[1]))
    start_new_thread(multi_threaded_client, (conn, ))
    ThreadCount += 1
    print('Thread Number: ' + str(ThreadCount))

