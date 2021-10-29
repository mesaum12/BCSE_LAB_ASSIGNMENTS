import socket,math
import pickle


# Connecting with the client 
ServerSideSocket = socket.socket()
host = '127.0.0.1'
port = 2004

try:
    ServerSideSocket.bind((host, port))
except socket.error as e:
    print(str(e))

print('Socket is listening..')
ServerSideSocket.listen(5)

def createWalsh(r):
	global walsh
	walsh=[[int(bin(x&y),13)%2 or -1 for x in range(r)]for y in range(r)]

walsh=[]

def Decode(number_of_stations,data_recvd):
    
    r_value=2**(math.ceil(math.log(number_of_stations,2)))
    createWalsh(r_value)
    
    while True:
        Data=""
        while True:
            Station_Num=int(input("Enter the station number for which data needs to be decoded:"))
            if(Station_Num>number_of_stations):
                print("--Please enter a valid station number--")
            else:
                break
        code=walsh[Station_Num-1]
        i=0
        while i<len(data_recvd):
            sum=0
            flag=False
            for k in range(len(code)):
                sum+=code[k]*data_recvd[i]
                i+=1
            if sum<0:flag=True
            sum=abs(sum)
            sum=sum//number_of_stations
            if sum==0:
                Data+="_"
            elif flag==True:
                Data+="0"
            else:Data+="1"
        
        print("The decoded data is :",Data)
        exit_code=int(input("Press 0 to exit"))
        if exit_code==0:
            exit()
       



def Server_Function(connection):
    
        data = connection.recv(1024)
        if not data:
            connection.close()
        recvd_msg=pickle.loads(data)
        number_of_stations=recvd_msg[0]
        my_list_data=recvd_msg[1:]
        print(my_list_data)
        msg="Transmission is successfull"
        tosend=pickle.dumps(msg)
        connection.sendall(tosend)
        Decode(number_of_stations,my_list_data)
        
    

while True:
    Client, address = ServerSideSocket.accept()
    print('Connected to: ' + address[0] + ':' + str(address[1]))
    Server_Function(Client)


