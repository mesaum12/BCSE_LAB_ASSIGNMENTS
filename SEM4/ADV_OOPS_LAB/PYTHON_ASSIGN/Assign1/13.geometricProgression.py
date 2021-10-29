import time
begin=time.time()
a_value=int(input("Enter the value of a:"))
q_value=int(input("Enter the value of q:"))

value=a_value
loop_time=time.time()
while value<100000:
    print(value,end=" ")
    value=value*q_value

end=time.time()
print()
print(f"The total time taken is {end-begin} and the loop time is {end-loop_time}\n")