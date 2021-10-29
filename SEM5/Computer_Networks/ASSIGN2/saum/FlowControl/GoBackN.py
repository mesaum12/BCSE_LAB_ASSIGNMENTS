
import pickle,socket,datetime
def GoBackN(data,count_of_packets):
    # GO BACK N PROTOCOL
    number_of_frames=count_of_packets

    # frame_size=4
    frames_list=[]

    counter=0
    current_size,k=0,0
    while counter<number_of_frames :
        
        while current_size<4:
            frames_list.append(data[k:k+512])
            k+=512
            current_size+=1
            
        
        msg={"data":frames_list}
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((socket.gethostname(), 4000))
        currtime=datetime.datetime.now()
        s.sendall(pickle.dumps(msg))

        msg=s.recv(100)
        my_dict=pickle.loads(msg)
        ack_num=my_dict["ack"]
    
        pop_front_count=0
        if ack_num!=-1:
            while pop_front_count<ack_num:
                frames_list.pop(0)
                current_size-=1
                pop_front_count+=1
    

        if ack_num!=-1:
            print("Acknowledgement for frames till ",ack_num," is received..Sending next")
            print("Round trip time in seconds:",(datetime.datetime.now()-currtime).total_seconds())
            counter+=(ack_num+1)
        else:
            print("Ack Received:", ack_num ,"Frame Corrupted , Negative ack , resending the frames for this window :")
            k=(k-512*4)
        
        s.close()