import socket

localIP     = "127.0.0.1"
localPort   = 20001
 # Create a datagram socket
UDPServerSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
UDPServerSocket.bind((localIP, localPort))
print("DHCP server up and listening")

while(True):

    bytesAddressPair = UDPServerSocket.recvfrom(1024)
    message = bytesAddressPair[0]
    address = bytesAddressPair[1]

    clientMsg = "Message from Client:{}".format(message)
    clientIP  = "Client IP Address:{}".format(address)
    
    print(clientMsg)
    print(clientIP)
    # Sending a reply with ip address 
    bytesToSend         = str.encode(clientIP)
    UDPServerSocket.sendto(bytesToSend, address)