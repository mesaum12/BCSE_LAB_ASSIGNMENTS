# This channel method is to be used for Stop N Wait and Go Back N protocol
import socket,random,time
def Channel1():
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind((socket.gethostname(),4000))
    s.listen(5)

    clientsocket,address=s.accept()
    print(f"Connection from {address} has been established.")

    recv_msg=clientsocket.recv(100)
    
    
    s2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s2.connect((socket.gethostname(), 5000))

    # here we will make our channel sleep for few seconds selected randomly
    time.sleep(random.randint(0,5))
    s2.send(recv_msg)

    ackfromrec=s2.recv(100)#This is also in the form of a dictionary from the receiver
    clientsocket.send(ackfromrec) #sends the acknowl rec from the receiver to the sender again
