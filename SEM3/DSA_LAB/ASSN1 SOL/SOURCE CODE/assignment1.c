#include<stdio.h>
//iterative function to find the factorial
long long factorial_iterative(int n)
{
  int i;long result=1;
  for(i=1;i<=n;i++)
  result*=i;
  return result;
}
//recursive function to calculate the function
long long factorial_recursive(int n)
{
   if(n<=1)
   return 1;
   return n*factorial_recursive(n-1);
}


int main()
{
  int n;
  scanf("%d",&n);
  printf("%lld\n",factorial_iterative(n));//Failing at 13 facorial for int data type and for 21 at long as well as for long long int
  printf("%lld\n",factorial_recursive(n));
  return 0;
}
  
