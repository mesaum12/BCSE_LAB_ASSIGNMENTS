# we have to take the standard ethernet data size which is 512 bits or 64 bytes
import socket
import sys,pickle


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


msg={"msg":"hello"} #now instead of this msg we have to send the data packets one by one 

counter=0
while counter<10:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((socket.gethostname(), 4000))
    s.sendall(pickle.dumps(msg))

    msg=s.recv(100)
    print(pickle.loads(msg))
    s.close()
    counter+=1


   