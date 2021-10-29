import sys
filename=sys.argv[1] #take the filename from the user as argument in the command line
file=open(filename,"r")
file_data=file.read()
data=(''.join(format(ord(x),'b')  for x in file_data))
file2=open("in.txt","a")
file2.write(f"{data} \n {len(data)}")
file.close()
file2.close()