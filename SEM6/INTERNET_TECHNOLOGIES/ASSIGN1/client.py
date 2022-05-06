import socket
import pickle
import sys
from urllib import request

# Function to return a dictionary based on the request
def readInput(InputDataString):
	req=[]
	i=0
	while i<(len(InputDataString)):
		if(InputDataString[i].lower()=='get'):
			if(i==len(InputDataString)-1 or InputDataString[i+1].lower()=='put'): # Error case
				return 0,req
			else:
				req.append({'userOption':'get','key':InputDataString[i+1]})
				i=i+1
		elif(InputDataString[i].lower()=='exit'):
			 req.append({'userOption':'exit','key':''})
			 i=i+1
			 
		elif(InputDataString[i].lower()=='put'):
			if(i==len(InputDataString)-2): # Error case
				return 0,req
			else:
				req.append({'userOption':'put','key':InputDataString[i+1],'value':InputDataString[i+2]})
				i=i+2

		elif(InputDataString[i].lower()=='managerfetch'):
			if(i==len(InputDataString)-2): # Error case
				return 0,req
			else:
				req.append({'userOption':'ManagerFetch','key':InputDataString[i+2],'username':InputDataString[i+1]})
				i=i+2
					
		elif(InputDataString[i].lower()=='updatepermission'):
				if(i==len(InputDataString)-1): # Error case
					return 0,req
				else:
					req.append({'userOption':'UpdatePermission','password':InputDataString[i+1]})
					i=i+1
		else:
			return 0,req
		i=i+1
	return 1,req

print(f"Connected to host: {sys.argv[1]} and PORT: {sys.argv[2]}")
clientSocket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
try:
    clientSocket.connect((socket.gethostname(), 5555))
except socket.error as e:
    print(str(e))

# connecting with the server send the username from the client to the server side and then check 
# enter it in the dictionary in the server side so that it can be fetched later on need
# uname=input('Enter a username: ')
uname=str(sys.argv[1])
clientSocket.sendall(uname.encode())

print('--------------------Client Operations-----------------')
print('Get key\nDescription: fetch value for a particular key entered or Invalid if not present\n')
print('Put key value\nDesription:To insert a value corresponding to a key\n')
print('UpdatePermission password\nDescription:To upgrade permission of a user to manager\n')
print('ManagerFetch username key\nDesciption:To get value of another user (only allowed if manager)\n')

while(True):
	# Take input
	request=input('Operation: ')
	
	# request=sys.argv[3:]
	return_val,req=readInput(request.split(' '))
	

	if(return_val==0 ):
		print('Invalid arguments')
		continue

	req=pickle.dumps(req)
	# Send the dictionary through socket
	clientSocket.sendall(req)
    
	# Wait for response
	if(request.lower()=='exit'):break
	response=clientSocket.recv(1024)
	response=pickle.loads(response)
	print(response)

clientSocket.close()