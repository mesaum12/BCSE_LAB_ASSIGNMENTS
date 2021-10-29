import socket,random,pickle

def receiverSelectiveRepeat():
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind((socket.gethostname(),5000))
    s.listen(5)

    clientsocket,address=s.accept()
    print(f"Connection from {address} has been established.")

    recv_msg=clientsocket.recv(4096)
    print("Message Received, sending the acknowledgement\n")

    my_dict=pickle.loads(recv_msg)
    my_list=my_dict["data"]
    temp=set()
    
    
    
    for i in range(len(my_list)):
        random_number=random.randint(1,100)
        if random_number>50:
            dict=my_list[i]
            for x in dict.keys():
                temp.add(x)

    clientsocket.send(pickle.dumps(temp))