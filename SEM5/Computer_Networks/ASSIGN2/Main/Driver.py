import sys

from saum.FlowControl.SelectiveRepeat import SelectiveRepeat
from saum.FlowControl.GoBackN import GoBackN
from saum.FlowControl.StopNWait import *

print("-------User have the options for the following different protocols--------")
print("1.STOP AND WAIT PROTOCOL")
print("2.GO BACK N ")
print("3.SELECTIVE REPEAT PROTOCOL")

choice=int(input("Enter your choice among the above three options:"))
if choice<1 or choice>3:
    print("Please enter a valid choice ")
    exit()
 

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

if choice==1:
    StopNWait(data,count_of_packets)
elif choice==2:
    GoBackN(data,count_of_packets)
else:
    SelectiveRepeat(data,count_of_packets)

