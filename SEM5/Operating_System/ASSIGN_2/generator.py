import random
file=open("t3.txt","a")
arrival_time=0
random_number=0
seen=[0 for i in range(0,31)]
for i in range(1,31):
    file.write(str(i))
    file.write(" ")
    while True:
        random_num=random.randint(1,30)
        if seen[random_num]:continue
        seen[random_num]=1
        file.write(str(random_num))
        file.write(" ")
        break
    file.write(str(arrival_time))
    file.write(" ")
    arrival_time+=random.randint(1,20)
    for j in range(random.randint(3,12)):
        file.write(str(random.randint(10,40)))
        file.write(" ")
    file.write("-1 ")


    

      
