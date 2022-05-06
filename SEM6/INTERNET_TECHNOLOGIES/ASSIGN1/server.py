import socket
import threading
import pickle

# Class to store key value for each client
class User:
	def __init__(self,username):
		self.username=username
		self.user_detail_dict={}
		self.mode='guest'
		self.password='password'

	def modeChangeRequest(self):
		self.mode='manager'

	def getRequest(self,key):
		if(key not in self.user_detail_dict):
			return 'Invalid key'
		return self.user_detail_dict[key]

	def putRequest(self,key,value):
		self.user_detail_dict[key]=value
		return 'True'

	# Function to take action on the requests
	def ResponseHandler(self,req):
		res=[]
		for reqs in req:
			if(reqs['userOption'].lower()=='exit'):
				res.append('exit')
			elif(reqs['userOption'].lower()=='get'):
				res.append(self.getRequest(reqs['key']))

			elif(reqs['userOption'].lower()=='put'):
				res.append(self.putRequest(reqs['key'],reqs['value']))

			elif(reqs['userOption'].lower()=='updatepermission'):
					if(self.password==reqs['password']):
						res.append('Success(ModeChange)!')
						self.modeChangeRequest()                    
					else:
						res.append('Invalid Password')

			elif(reqs['userOption'].lower()=='managerfetch'):
				if(self.mode=='guest' and self.username!=reqs['username']):
					res.append('Access Denied!!!!')
				elif(self.username==reqs['username'] or self.mode=='manager'):
					if(reqs['username'] in my_data_dict):
						res.append(my_data_dict[reqs['username']].getRequest(reqs['key']))
					else:
						res.append('Invalid username')
		return res

# Function to service a client
def serviceClient(client, clientAddr,addr):
	while True:
		req=clientAddr.recv(1024) # Receive the request dictionary
		req=pickle.loads(req)
		res=client.ResponseHandler(req)
		if(res[0]=='exit'):
			print(f"User {addr} decided to log out !! ")
			break
		res=pickle.dumps(res)
		clientAddr.sendall(res)
		

def connection_establishment():
	while(True):
		# Wait for a connection from the client side 
		serverSocket.listen(10)
		conn, addr=serverSocket.accept()
		print('Server is up and running !! , at address:',addr)
		# Fetch username
		username=conn.recv(1024).decode()
		print(f"User currently active : {username}")
		if username not in my_data_dict.keys():
			client=User(username) # Create client by that username
			my_data_dict[username]=client
		else:
			client=my_data_dict[username]
        # Start a new thread for the sender
		sendThread=threading.Thread(target=serviceClient, args=[client,conn,addr])
		sendThread.start()
	

# creating the server using socket programming and running it in port number 5555
serverSocket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
try:
    serverSocket.bind((socket.gethostname(), 5555))
except socket.error as e:
    print(str(e))


# creating a dictionary on the server side to put the value received from the client side and serve the requests
my_data_dict={}
connection_establishment()