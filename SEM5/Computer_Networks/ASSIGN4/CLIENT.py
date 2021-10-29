import math
import socket,sys,pickle,datetime,threading,time,random


# Establishing the socket connection with the server 
ClientMultiSocket = socket.socket()
host = '127.0.0.1'
port = 2004

print('...Waiting for connection response from the Server Side...')
try:
    ClientMultiSocket.connect((host, port))
except socket.error as e:
    print(str(e))


def createWalsh(r):
	global walsh
	walsh=[[int(bin(x&y),13)%2 or -1 for x in range(r)]for y in range(r)]


def Convert(x):
    if x=="1":return 1
    elif x=="0":return -1
    else: return 0

walsh=[]
stations=int(input("Enter the number of stations:"))
r_value=2**(math.ceil(math.log(stations,2)))

createWalsh(r_value)
for i in range(0,len(walsh)):
    for j in range(0,len(walsh[i])):
        print(walsh[i][j],end=" ")
    print()

max_length=int(input("Enter the maximum length of the data to be sent :"))
data=[input("Enter data for station:") for i in range(stations)]
for i in range(stations):
    diff=max_length-len(data[i])
    if diff>0:
        data[i]+=diff*('_')
    print("The new data for station ",i+1,":",data[i])

code=[walsh[i] for i in range(stations)]
print("Code for encoding the data by multiplying it with the data:")
for i in range(stations):
    code[i]=len(data[i])*code[i]
    print(code[i])



for i in range(stations):
    k=0
    for j in range(len(code[i])):
        if j%len(walsh[i])==0 and j!=0:k+=1
        if(data[i][k]=="0"):
            code[i][j]=-code[i][j]
        elif data[i][k]=="_":
            code[i][j]=0
    print("CODE :",code[i])
           


# Now we need to prepare the final string to be sent
to_send=[0 for i in range(len(code[0]))]
for i in range(len(code[0])):
    for k in range(stations):
        to_send[i]+=code[k][i]

to_send.insert(0,stations)
print(to_send) # That is the final combination we need to send to the server and then decode it on 
# server side 
# to_send is a list which is converted into object by the pickle module for sending purpose
ClientMultiSocket.send(pickle.dumps(to_send))

msg = ClientMultiSocket.recv(1024)
print(pickle.loads(msg))

ClientMultiSocket.close()



