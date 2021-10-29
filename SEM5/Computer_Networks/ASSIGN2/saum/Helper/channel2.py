import socket
import time,random
while True:
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind((socket.gethostname(),4000))
    s.listen(5)

    clientsocket,address=s.accept()
    print(f"Connection from {address} has been established.")

    # recv_msg=clientsocket.recv(100)
    # recv_msg=b""
    # while True:
    #     packet=clientsocket.recv(100)
    #     if len(packet)==0:
    #         break
    #     else:
    #         recv_msg+=packet
    recv_msg=clientsocket.recv(4096)
    # mydict=pickle.loads(recv_msg)#msg is received from the sender side , now need to send to receiver

    # msg={"msg":"received"}
    # tosend=pickle.dumps(msg)
    # clientsocket.send(tosend)

    # ***we need to inject some random sleep or delay here at this point,note it

    s2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s2.connect((socket.gethostname(), 5000))

    # tosend=pickle.dumps(recv_msg)
    # here we will make our channel sleep for few seconds selected randomly
    # time.sleep(random.randint(0,5))
    s2.send(recv_msg)

    # ackfromrec=b""
    # while True:
    #     packet=s2.recv(100)
    #     if len(packet)==0:
    #         break
    #     else:
    #         ackfromrec+=packet

    ackfromrec=s2.recv(4096)#This is also in the form of a dictionary from the receiver
    clientsocket.send(ackfromrec) #sends the acknowl rec from the receiver to the sender again
