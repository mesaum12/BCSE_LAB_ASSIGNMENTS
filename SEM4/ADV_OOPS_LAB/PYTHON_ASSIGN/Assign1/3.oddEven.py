import itertools
def is_odd(n):
    if n%2!=0:
        return True
    else:
        return False

even_nums=[x for x in range(1,21) if is_odd(x)==False]

odd_nums=[x for x in range(1,21) if is_odd(x)==True]

compress_value=[True for x in range(0,10)]

compressed1=itertools.compress(odd_nums,compress_value)

compressed2=itertools.compress(even_nums,compress_value)

print("Odd numbers using the compress method :")
for eachval in compressed1:
    print(eachval,end=" ")

print("\nEven numbers using the compress method :")
for eachval in compressed2:
    print(eachval,end=" ")