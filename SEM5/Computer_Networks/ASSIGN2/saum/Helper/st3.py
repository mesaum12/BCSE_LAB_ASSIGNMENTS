# we have to take the standard ethernet data size which is 512 bits or 64 bytes
import socket
import sys,pickle,datetime


filename=sys.argv[1] #take the filename from the user as argument in the command line
file=open(filename,"r")
file_data=file.read()
data=(''.join(format(ord(x),'b')  for x in file_data))

# divide the data into packets of size 512 bits each,the standard ethernet 
packet_size=512
temp = 0
if (len(data) % packet_size != 0):
    temp = packet_size - (len(data) % packet_size)
data += ('0' * temp)
count_of_packets = len(data) // packet_size

# connect with the channel first from the client side 


msg={} #now instead of this msg we have to send the data packets one by one 

counter,k=0,0
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
        print("Round trip time in seconds:",(datetime.datetime.now()-currtime).total_seconds())
        counter+=1
        k+=512
    else:
        print("Negative Ack, Resending the packet :",counter+1)
    
    s.close()
    

# go back n protocol 
# number_of_frames=count_of_packets

# frame_size=4
# frames_list=[]

# counter=0
# current_size,k=0,0
# while counter<=number_of_frames:
    
#     while current_size<4:
#         frames_list.append(data[k:k+512])
#         k+=512
#         current_size+=1
        
    
#     msg={"data":frames_list}
#     s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#     s.connect((socket.gethostname(), 4000))
#     currtime=datetime.datetime.now()
#     s.sendall(pickle.dumps(msg))

#     msg=s.recv(100)
#     my_dict=pickle.loads(msg)
#     ack_num=my_dict["ack"]
   
#     pop_front_count=0
#     if ack_num!=-1:
#          while pop_front_count<=ack_num:
#           frames_list.pop(0)
#           current_size-=1
#           pop_front_count+=1
   

#     if ack_num!=-1:
#         print("Acknowledgement for frames till ",ack_num," is received..Sending next")
#         print("Round trip time in seconds:",(datetime.datetime.now()-currtime).total_seconds())
#         counter+=(ack_num+1)
#     else:
#         print("Negative Ack, Resending the frames for this window :")
    
#     s.close()


# # selective repeat protocol

# frame_size=4
# counter,k=0,0
# current_size=0
# frames_list=[]

# round_trip_time=[0 for x in range(number_of_frames)]
# while counter<number_of_frames:
#     while current_size<4:
#         frames_list.append({k//512:data[k:k+512]})
#         k+=512
#         current_size+=1
        
    
#     msg={"data":frames_list}
#     s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#     s.connect((socket.gethostname(), 4000))
#     currtime=datetime.datetime.now()
#     s.sendall(pickle.dumps(msg))

#     msg=s.recv(100)
#     my_set=pickle.loads(msg)

#     for i in range(len(frames_list)):
#         for key in frames_list[i].keys():
#             if key not in my_set:
#                 print("Acknowledgement for frame ",i," has been received ..")
#                 round_trip_time[key]=datetime.datetime.now().total_seconds()-currtime.total_seconds()
#                 frames_list.pop(i)
#                 current_size-=1
#                 counter+=1
#             else:
#                 print("Acknowledgement for frame  ",i," not received..")
            
#     s.close()
    