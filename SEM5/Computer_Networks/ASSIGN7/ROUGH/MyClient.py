#!/usr/bin/env python3

import socket

HostIpAddress = '127.0.0.1'  # The server's hostname or IP address


# Assign the port numbers for the various ports 
DHCPport = 4900        # The port used by the server
FTPport = 4800        # The port used by the server
BGPport = 5000        # The port used by the server'


OWNaddr = ("","")
name = ""

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HostIpAddress, DHCPport))
s.send(bytes("Requesting port number of the host-:" , "utf-8"))
name = input("Enter name of the host: ") #write the name of the host 
s.send(bytes(name, "utf-8")) #send the name of the host to the dhcp server 
OWNaddr = s.recv(1024).decode() #receive the address from the server
print("The address of the host connected is: " , OWNaddr)
s.close()

while True:
    print("------------User has the following choices---------")
    print("1.Request file from the  server through protocol 1.FTP ")
    print("2.Send a file to the another host ")
    print("3.Receive a file from another host ")
    print("4.Exit")
    choice = int(input("Enter your choice :"))
    if choice == "4":
        print("You chose to exit ")
        break

    elif choice == 1:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((HostIpAddress, FTPport))
        s.send(bytes(name, "utf-8"))
        filename = input("Enter filename to be searched: ")
        s.send(bytes(filename, "utf-8"))
        data = s.recv(1024).decode()
        print("File data fetched successfully using FTP protocol")
        print("File contains the following : ", data)
        s.close()
        continue

    elif choice == 2:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((HostIpAddress, BGPport))
        s.send(bytes("Requesting file transfer to another host!", "utf-8"))
        message = s.recv(1024).decode()
        print("Message received "+message)
        receiver = input("Enter name of receiver: ")
        s.send(bytes(receiver, "utf-8"))
        data = input("Enter data to be transferred: ")
        s.send(bytes(data, "utf-8"))
        s.close()
        continue

    else:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.bind((HostIpAddress, int(OWNaddr[13:-2])))
        s.listen()
        print("Listening for a connection on its own port....")
        conn, addr = s.accept()
        print("---Connection established---")
        message = conn.recv(1024).decode()
        print("Message received "+message)
        conn.send(bytes("Request granted! Send data!", "utf-8"))
        data = conn.recv(1024).decode()
        print("Data received: "+data)
        print("Transmission successful!")
        conn.close()
        s.close()
        continue