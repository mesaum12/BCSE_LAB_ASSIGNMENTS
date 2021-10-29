import socket,random,pickle
def receiverGoBackN():
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind((socket.gethostname(),5000))
    s.listen(5)

    clientsocket,address=s.accept()
    print(f"Connection from {address} has been established.")

    # THE BELOW TWO LINES NEEDS TO BE UNCOMMENTED FOR WORKING OF STOP AND WAIT AND GO BACK N
    recv_msg=clientsocket.recv(100)
    print("Message Received, sending the acknowledgement\n")

    # Go back N STARTS HERE
    random_number=random.randint(-1,3)
    msg={"ack":random_number}
    clientsocket.send(pickle.dumps(msg))
    # GO BACK N ENDS HERE