def fibonacciGenerator(n):
    a,b,loopcounter=0,1,0
    while loopcounter<=n:
        print("Before yield\n")
        yield a
        print("After yield\n")
        a,b=b,a+b
        loopcounter+=1

f=fibonacciGenerator(7)
print("Printing the first fibonacci numbers:")
for value in f:
    print("Val:"+str(value),end=' ')

