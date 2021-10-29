list1=list(range(0,51))
print("Multiples of 5 ")
new_list=list(filter(lambda x:(x%5==0),list1))
print(new_list)