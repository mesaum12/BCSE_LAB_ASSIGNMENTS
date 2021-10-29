import random

def injectError(data):
    random_limit_error=random.randint(1,5)
    # random_limit_error=7
    for i in range(random_limit_error):
        random_pos=random.randint(1,len(data)-2)
        if (data[random_pos]=='1'):
            data=data[0:random_pos]+'0'+data[random_pos+1:]
        else:
            data=data[0:random_pos]+'1'+data[random_pos+1:]

    return data


# def injectBurstError(data,max_burst_len):
#     random_pos=random.randint(1,len(data)-max_burst_len-1)
#     for i in range(max_burst_len):
#         if (data[random_pos]=='1'):
#             data=data[0:random_pos]+'0'+data[random_pos+1:]
#         else:
#             data=data[0:random_pos]+'1'+data[random_pos+1:]
#         random_pos+=1
#     return data

def injectBurstError(data,max_burst_len):
    random_pos=random.randint(1,len(data)-max_burst_len-1)
    data=data[0:random_pos]+str(int(data[random_pos:random_pos+1])^1)+data[random_pos+1:random_pos+max_burst_len-1]+str(int(data[random_pos+max_burst_len-1:random_pos+max_burst_len])^1)+data[random_pos+max_burst_len:]
    if(max_burst_len<=2): return data
    random_limit=random.randint(0,max_burst_len-2)
    
    for i in range(random_limit):
        random_change_pos=random.randint(random_pos+1,random_pos+max_burst_len-2)
        if (data[random_change_pos]=='1'):
            data=data[0:random_change_pos]+'0'+data[random_change_pos+1:]
        else:
            data=data[0:random_change_pos]+'1'+data[random_change_pos+1:]
    return data


# Special Cases where some code fail to detect the error whereas others are able to detect it
def injectError2(data):
    # since the crc10 is taken we find the length of the codeword and store it in length
    length=len(data)+9
    f=open("testfile2.txt","r")
    temp_str=f.read()
    diff=length-len(temp_str)
    temp_str=('0'*(diff))+temp_str
    return temp_str


def injectError3(data,packet_size):
    # we will add some number to the first packet and subtract same amount of data from second packet
    err_data=data[0:5]+str(int(data[5:6])^1)+data[6:5+packet_size]+str(int(data[5+packet_size:6+packet_size])^1)+data[6+packet_size:]
    return err_data


def injectError4(data):
    # we will add some number to the first packet and subtract same amount of data from second packet
    err_data=data[0:3]+str(int(data[3:4])^1)+data[4:5]+str(int(data[5:6])^1)+data[6:]
    return err_data


def injectError5(data,packet_size):
    # we will add some number to the first packet and subtract same amount of data from second packet
    err_data=data[0:3]+str(int(data[3:4])^1)+data[4:3+packet_size]+str(int(data[3+packet_size:4+packet_size])^1)+data[4+packet_size:]
    return err_data