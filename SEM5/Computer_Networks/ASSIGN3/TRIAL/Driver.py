import sys

print("-------User have the options for the following different protocols--------")
print("1.1-persistent")
print("2.Non-persistent ")
print("3.p-persistent ")

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
    



