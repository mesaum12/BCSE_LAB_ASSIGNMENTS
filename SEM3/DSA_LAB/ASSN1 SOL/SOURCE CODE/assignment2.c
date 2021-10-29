#include<stdio.h>
//iterative function to find the fibonacci number 
long long fib_iterative(int n)
{
  long long a=0,b=1,c,i;
  if(n==0 || n==1)
  return n;
  else
  { 
     for(i=2;i<=n;i++)
     {
      c=a+b;
      a=b;
      b=c;
    
     }
     return c;  
  }

}
//recursive function to find the fibonacci number
long fib_recursive(int n)
{ 
   if(n==0 || n==1)
   return n;
   return  fib_recursive(n-1)+fib_recursive(n-2);
}
int main()
{
  int n;
  scanf("%ld",&n);
  printf("%lld\n",fib_iterative(n));//int failing at 47 till 46 giving correct output long failing at 93 as well as long long
  printf("%d\n",fib_recursive(n));
  return 0;
}
