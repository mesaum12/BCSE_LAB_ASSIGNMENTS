# This channel method is to be used for Selective Repeat Protocol
import socket,time,random
def Channel2():
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind((socket.gethostname(),4000))
    s.listen(5)

    clientsocket,address=s.accept()
    print(f"Connection from {address} has been established.")

    
    recv_msg=clientsocket.recv(4096)
    
    s2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s2.connect((socket.gethostname(), 5000))

    time.sleep(random.randint(0,5))
    s2.send(recv_msg)

    ackfromrec=s2.recv(4096)#This is also in the form of a dictionary from the receiver
    clientsocket.send(ackfromrec) #sends the acknowl rec from the receiver to the sender again