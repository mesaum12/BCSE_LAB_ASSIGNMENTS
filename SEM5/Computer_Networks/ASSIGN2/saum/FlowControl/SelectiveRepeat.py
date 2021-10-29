
import pickle,socket,datetime

def SelectiveRepeat(data,number_of_frames):
    # frame_size=4
    counter,k=0,0
    current_size=0
    frames_list=[]

    round_trip_time={}
    while True:
        while current_size<4 and k<len(data):
            frames_list.append({k//512:data[k:k+512]})
            k+=512
            current_size+=1
            
        if current_size==0:break  
        
        msg={"data":frames_list}
        # msg=frames_list
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((socket.gethostname(), 4000))
        currtime=datetime.datetime.now()
        s.sendall(pickle.dumps(msg))


        msg=s.recv(4096)
        my_set=pickle.loads(msg)#set containing corrupted packets or negative acknowledgement here
        my_list=[]
        # here in my list we collect the keys present in the frame at this moment
        for i in range(len(frames_list)):
            dict=frames_list[i]
            for x in dict.keys():
                my_list.append(x)
       
        for x in my_list:
            if x not in my_set:
                print("Acknowledgement for frame ",x," has been received ..")
                round_trip_time[x]=(datetime.datetime.now()-currtime).total_seconds()
                print("Round trip time is " ,round_trip_time[x])
                counter+=1
            else:
                print("Negative Acknowledgement for frame sequence ", x ,"  received..needs to retransmit")
                
        newFramesList=[]
        for i in range(len(my_list)):
            if my_list[i] in my_set:
                newFramesList.append(frames_list[i])
            

        frames_list=newFramesList
        current_size=len(frames_list)
        
        s.close()

    print(round_trip_time) 