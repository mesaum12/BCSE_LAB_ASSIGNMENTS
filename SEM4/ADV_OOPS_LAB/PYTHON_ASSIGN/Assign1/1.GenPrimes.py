primes_list={x:True for x in range(2,100)}
for key in primes_list.keys():
    if primes_list[key]==True:
        for x in range(key**2,100,key):
               primes_list[x]=False
print(primes_list)
# prime generator using only primes
