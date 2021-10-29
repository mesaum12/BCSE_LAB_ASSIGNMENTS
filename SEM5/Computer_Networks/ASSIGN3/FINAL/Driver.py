import sys

import socket,sys,pickle,datetime,threading,time,random

print("---User have the options for the following different protocols---")
print("1.1-persistent")
print("2.Non-persistent ")
print("3.p-persistent ")

choice=int(input("Enter your choice among the above three options:"))
if choice<1 or choice>3:
    print("Please enter a valid choice ")
    exit()


# Establishing the socket connection with the server 
ClientMultiSocket = socket.socket()
host = '127.0.0.1'
port = 2004

print('...Waiting for connection response from the Server Side...')
try:
    ClientMultiSocket.connect((host, port))
except socket.error as e:
    print(str(e))

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


round_trip_time={}
time_duration=3
probability_factor=4
time_slot=4

number_of_stations=int(input("Enter the number of stations:"))
back_off={}
Collisions={}
Attempts={}

for i in range(1,number_of_stations+1):
    back_off["Station"+str(i)]=0
    Collisions["Station"+str(i)]=0
    Attempts["Station"+str(i)]=0
    


def One_Persistent(thread_name,data,count_of_packets):
    msg={} #now instead of this msg we have to send the data packets one by one 

    counter,k=0,0
    while counter<count_of_packets:

        msg={"data":data[k:k+512]}
        currtime=datetime.datetime.now()
        ClientMultiSocket.send(pickle.dumps(msg))

        msg = ClientMultiSocket.recv(1024)
        my_dict=pickle.loads(msg)
        time.sleep(random.randint(1,5))#Assume this as the time for the processing which is random
        
        if number_of_stations==1: 
            my_dict["ack"]=1
        if my_dict["ack"]<=3:
            print(thread_name,"Frame:",counter+1," is received by the server ..Sending next")
            Attempts[thread_name]+=1
            round_trip_time[(thread_name,counter+1)]=(datetime.datetime.now()-currtime).total_seconds()
            counter+=1
            k+=512
        else:
            print(thread_name,",Collision occurred , Resending the packet :",counter+1)
            Collisions[thread_name]+=1
            Attempts[thread_name]+=1
            

        
        
def Non_Persistent(thread_name,data,count_of_packets):
    msg={} #now instead of this msg we have to send the data packets one by one 

    counter,k=0,0
    while counter<count_of_packets :

        msg={"data":data[k:k+512]}
        currtime=datetime.datetime.now()
        time.sleep(time_duration) #It waits for a fixed time slot for sensing the channel
        ClientMultiSocket.send(pickle.dumps(msg))

        msg = ClientMultiSocket.recv(1024)
        my_dict=pickle.loads(msg)
        

        if number_of_stations==1:
            my_dict["ack"]=1
        if my_dict["ack"]<=4:
            print(thread_name,"Frame:",counter+1," is received by the server ..Sending next")
            Attempts[thread_name]+=1
            round_trip_time[(thread_name,counter+1)]=(datetime.datetime.now()-currtime).total_seconds()
            counter+=1
            k+=512
        else:
            print(thread_name,",Collision occurred , Resending the packet :",counter+1)
            Collisions[thread_name]+=1
            Attempts[thread_name]+=1
            time.sleep(random.randint(1,5)) #we need to backoff a random amount of time before trying again
 

def P_Persistent(thread_name,data,count_of_packets):
    msg={} #now instead of this msg we have to send the data packets one by one 

    counter,k=0,0
    while counter<count_of_packets:

        msg={"data":data[k:k+512]}
        currtime=datetime.datetime.now()
        
        random_num=random.randint(1,4)
        if(random_num<probability_factor):
            ClientMultiSocket.send(pickle.dumps(msg))
        else:
            print("Waiting for the next slot",thread_name," is less , can't be sent")
            time.sleep(time_slot)
            continue

        msg = ClientMultiSocket.recv(1024)
        my_dict=pickle.loads(msg)
        # time.sleep(random.randint(1,5))
        if number_of_stations==1:
            my_dict["ack"]=1
        if my_dict["ack"]<=6:
            print(thread_name,"Frame:",counter+1," is received by the server ..Sending next")
            Attempts[thread_name]+=1
            round_trip_time[(thread_name,counter+1)]=(datetime.datetime.now()-currtime).total_seconds()
            counter+=1
            k+=512
        else:
            print(thread_name,",Collision occurred , Resending the packet :",counter+1)
            Collisions[thread_name]+=1
            Attempts[thread_name]+=1
            # Now we need to wait a random backoff time before trying again
            # back_off[thread_name]+=1
            # print("Current Backoff value for "+thread_name+"is :"+back_off[thread_name])
            # time.sleep(random.randint(0,2**back_off[thread_name]-1))

# This method is common to all types of methods followed  

sender_threads=[]
if choice==1:
    for i in range(1,number_of_stations+1):
       t=threading.Thread(target=One_Persistent,args=("Station"+str(i),data,count_of_packets,))
       sender_threads.append(t)
       t.start()
elif choice==2:
    for i in range(1,number_of_stations+1):
       t=threading.Thread(target=Non_Persistent,args=("Station"+str(i),data,count_of_packets,))
       sender_threads.append(t)
       t.start()
else:
    for i in range(1,number_of_stations+1):
       t=threading.Thread(target=P_Persistent,args=("Station"+str(i),data,count_of_packets,))
       sender_threads.append(t)
       t.start()

for mythread in sender_threads:
    mythread.join()

print("RTT VALUES:")
for key in round_trip_time:
    print(key,":",round_trip_time[key])

print("----------------Performance Metrics ----------------")
for key in Attempts:
    print("Attempts:",key,":",Attempts[key]," Collisions:",key,Collisions[key])





    
    



