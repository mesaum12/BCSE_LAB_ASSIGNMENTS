
import pickle,socket,datetime

def StopNWait(data,count_of_packets):
    msg={} #now instead of this msg we have to send the data packets one by one 

    counter,k=0,0
    round_trip_time={}
    while counter<count_of_packets:

        msg={"data":data[k:k+512]}
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((socket.gethostname(), 4000))
        currtime=datetime.datetime.now()
        s.sendall(pickle.dumps(msg))

        msg=s.recv(100)
        my_dict=pickle.loads(msg)
        if my_dict["ack"]==1:
            print("Acknowledgement for packet ",counter+1," is received..Sending next")
            round_trip_time[counter+1]=(datetime.datetime.now()-currtime).total_seconds()
            print("Round trip time in seconds:",(datetime.datetime.now()-currtime).total_seconds())
            counter+=1
            k+=512
        else:
            print("Negative Ack, Resending the packet :",counter+1)
        
        s.close()