import pickle
import sys
import socket
from error_algo import *
from InjectErrorALL import *
# from injectError2 import *
# from injectErrorVRCfailure import *
# from injectErrorForCheckSumFailure import *
# from injectErrorLRCfailure import *
# helo
filename=sys.argv[1] #take the filename from the user as argument in the command line
file=open(filename,"r")
file_data=file.read()
data=(''.join(format(ord(x),'b')  for x in file_data))


print("\n\n")
print("--------------THE ERROR DETECTION SYSTEM------------")
print("SCHEMES USED\n1.CHECKSUM\n2.VRC\n3.LRC\n4.CRC")
packet_size=int(input("Enter the packet size of the data :"))
# case=int(input("1.DETECT_ALL\n2.CRC FAILURE\n3.CHECKSUM FAILURE\n4.VRC FAILURE\n5.LRC FAILURE\nEnter your choice:"))

redundant_string_checksum=CHECKSUM(data,packet_size)
redundant_string_vrc=VRC(data,packet_size)
redundant_string_lrc=LRC(data,packet_size)
redundant_string_crc=CRC(data)

#inject error into the datastream
file1=open("fa.txt","a")
file2=open("fb.txt","a")
file3=open("fc.txt","a")
file4=open("fd.txt","a")
counter=0

while counter<1000:
    # case = int(input("1.DETECT_ALL\n2.CRC FAILURE\n3.CHECKSUM FAILURE\n4.VRC FAILURE\n5.LRC FAILURE\n6.EXIT\nEnter your choice:"))
    case=1
    to_send = ''
    if (case == 1):
        erroneous_data = injectBurstError(data,7)
        to_send_crc = erroneous_data + redundant_string_crc
    elif (case == 2):  # for crc failure
        erroneous_data = injectError2(data)
        to_send_crc = erroneous_data
    elif (case == 3):  # for checksum failure
        erroneous_data = injectError3(data, packet_size)
        to_send_crc = erroneous_data
    elif (case == 4):  # for vrc failure
        erroneous_data = injectError4(data)
        to_send_crc = erroneous_data
    elif (case == 5):  # for lrc failure
        erroneous_data = injectError5(data, packet_size)
        to_send_crc = erroneous_data
    elif (case == 6):
        exit(0)
    else:
        print("OOPS ,Please enter valid input ;-; ")
        exit()

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((socket.gethostname(), 12345))

    d = {1: erroneous_data + redundant_string_checksum, 2:
        erroneous_data + redundant_string_vrc, 3: erroneous_data + redundant_string_lrc,
         4: to_send_crc, 5: packet_size, 6: len(data)}

    msg = pickle.dumps(d)
    s.send(msg)

    recvd_msg = s.recv(10000)
    my_dict = pickle.loads(recvd_msg)

    # print("\n--------CHECKSUM STATUS -----")
    # print(my_dict[1])

    # print("\n---VRC STATUS-----")
    # print(my_dict[2])

    # print("\n---LRC STATUS-----")
    # print(my_dict[3])

    # print("\n---CRC STATUS-----")
    # print(my_dict[4])
    file1.write(str(my_dict[1])+"\n")
    file2.write(str(my_dict[2])+"\n")
    file3.write(str(my_dict[3])+"\n")
    file4.write(str(my_dict[4])+"\n")
   
    counter+=1

print("Thanks\n")





