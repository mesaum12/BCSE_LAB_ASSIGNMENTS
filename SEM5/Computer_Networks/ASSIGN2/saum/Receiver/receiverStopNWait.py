import socket,random,pickle

def receiveStopNWait():
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind((socket.gethostname(),5000))
    s.listen(5)

    clientsocket,address=s.accept()
    print(f"Connection from {address} has been established.")
    recv_msg=clientsocket.recv(100)
    print("Message Received, sending the acknowledgement\n")

    
    random_number=random.randint(1,100)
    if random_number>75:
        msg={"ack":0}
    else:
        msg={"ack":1}#proper receival of the data packet
    tosend=pickle.dumps(msg)
    clientsocket.send(tosend)
    