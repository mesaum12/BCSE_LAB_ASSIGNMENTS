import socket
import pickle
from error_algo import *

s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind((socket.gethostname(),12345))
s.listen(5)
# count_lrc,count_vrc,count_checksum,count_crc=0,0,0,0

while True:
    clientsocket,address=s.accept()
    print(f"Connection from {address} has been established.")
    recv_msg=clientsocket.recv(10000)
    myobj=pickle.loads(recv_msg)
    codeword_checksum = myobj[1]
    codeword_vrc = myobj[2]
    codeword_lrc = myobj[3]
    codeword_crc = myobj[4]
    packet_size = myobj[5]
    data_length=myobj[6]

    d={}
    receiver_checksum = CHECKSUM(codeword_checksum, packet_size)
    if (int(receiver_checksum, 2) == 0):
        d[1]="Receiver Checksum:" + receiver_checksum + "\nStatus of Detection: ERROR NOT PRESENT"
    else:
        d[1]="Receiver Checksum:" + receiver_checksum + "\nStatus of Detection :ERROR IS PRESENT"
    # if(int(receiver_checksum,2)!=0):
    #     count_checksum+=1
    # d[1]=count_checksum
     

         

    receiver_vrc = VRC(codeword_vrc[0:data_length], packet_size)
    if (receiver_vrc == codeword_vrc[-1 * len(receiver_vrc):]):
         d[2]=f"Receiver VRC:{receiver_vrc} Sender's VRC:{codeword_vrc[-1 * len(receiver_vrc):]}\nStatus of Detection: ERROR NOT PRESENT"
    else:
         d[2]=f"Receiver VRC:{receiver_vrc} Sender's VRC:{codeword_vrc[-1 * len(receiver_vrc):]}\nStatus of Detection: ERROR  PRESENT"

        #  count_vrc+=1
        #  d[2]=count_vrc
        
    # if (receiver_vrc != codeword_vrc[-1 * len(receiver_vrc):]): 
    #     count_vrc+=1
    # d[2]=count_vrc
         

    receiver_lrc = LRC(codeword_lrc[0:data_length], packet_size)
    if (receiver_lrc == codeword_lrc[-1 * len(receiver_lrc):]):
          d[3]=f"Receiver LRC:{receiver_lrc} Sender's LRC:{codeword_lrc[-1 * len(receiver_lrc):]}\nStatus of Detection: ERROR NOT PRESENT"
    else:
          d[3]=f"Receiver LRC:{receiver_lrc} Sender's LRC:{codeword_lrc[-1 * len(receiver_lrc):]}\nStatus of Detection: ERROR  PRESENT"
        # d[3]=count_lrc
        #  count_lrc+=1
         
        
    # if (receiver_lrc != codeword_lrc[-1 * len(receiver_lrc):]):  
    #     count_lrc+=1
    # d[3]=count_lrc 


    receiver_crc = CRC(codeword_crc)
    if (int(receiver_crc, 2) == 0):
        d[4]="Receiver CRC:" + receiver_crc + "\nStatus of Detection: ERROR NOT PRESENT"
    else:
        d[4]="Receiver CRC:" + receiver_crc + "\nStatus of Detection :ERROR IS PRESENT"
        
         #  count_crc+=1
        #  d[4]=count_crc
    # if (int(receiver_crc,2)!=0):
    #     count_crc+=1
    # d[4]=count_crc
        
    msg=pickle.dumps(d)
    clientsocket.send(msg)