import socket,sys,pickle,datetime,threading,time,random

ClientMultiSocket = socket.socket()
host = '127.0.0.1'
port = 2004

print('...Waiting for connection response from the Server Side...')
try:
    ClientMultiSocket.connect((host, port))
except socket.error as e:
    print(str(e))

# res = ClientMultiSocket.recv(1024)

# Read the file name from the command line as an argument 
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

probability_factor=4

round_trip_time={}
def P_Persistent(thread_name,data,count_of_packets):
    msg={} #now instead of this msg we have to send the data packets one by one 

    counter,k=0,0
    while counter<count_of_packets:

        msg={"data":data[k:k+512]}
        currtime=datetime.datetime.now()
        # print(thread_name)
        # time.sleep(3) #It waits for a fixed time slot for sensing the channel
        # selecting the probability outcome here
        random_num=random.randint(1,4)
        if(random_num<probability_factor):
            ClientMultiSocket.send(pickle.dumps(msg))
        else:
            print("Sorry , the probability factor for",thread_name," is less , can't be sent")
            continue

        msg = ClientMultiSocket.recv(1024)
        my_dict=pickle.loads(msg)
        if my_dict["ack"]==1:
            # print("Acknowledgement for packet ",counter+1," is received..Sending next")
            print(thread_name,"Frame:",counter+1," is received by the server ..Sending next")
            round_trip_time[(thread_name,counter+1)]=(datetime.datetime.now()-currtime).total_seconds()
            # print("Round trip time in seconds:",(datetime.datetime.now()-currtime).total_seconds())
            counter+=1
            k+=512
        else:
            # print("Negative Ack, Resending the packet :",counter+1)
            print(thread_name,",Collision occurred , Resending the packet :",counter+1)
            time.sleep(random.randint(1,5)) #we need to backoff a random amount of time before trying again
        
 
# This is just a trial to raise multiple threads in single sender 
sender_threads=[]
for i in range(1,5):
    t=threading.Thread(target=P_Persistent,args=("Station"+str(i),data,count_of_packets,))
    sender_threads.append(t)
    t.start()
for mythread in sender_threads:
    mythread.join()

# One_Persistent(data,count_of_packet
print(round_trip_time)