def my_func(n):
    return abs(n-100)

# list=[234,100,256,768,121,112,89,78,235,67]
list=[]
size=int(input("Enter the size of the list:"))
count=0
while count<size:
    list.append(int(input("Enter the number:")))
    count+=1

print("---Nearer to 100 larger is the priority----")
while len(list)>0:
    list.sort(key=my_func)
    print(list.pop(0),end=" ")


