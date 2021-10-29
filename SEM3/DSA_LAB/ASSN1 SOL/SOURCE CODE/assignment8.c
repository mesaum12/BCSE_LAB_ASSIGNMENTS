#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//counting the number of digits in the program
int n_of_dig(long long n)
{
    int dig=0;
    do
    {
        dig++;
        n/=10;
    } while (n);
    return dig;
}
//calculating a to the power b
long power(int a,int b)
{
   long result=1;
   while(b--)
   {
       result*=a;
   }
   return result;
}
void solve(char *name)
{
    int temp,i;
    int primes[]={1103,1229,1231,1399,1667,1831,2003,1997};
    long long unsigned t=name[0];
    for( i=1;name[i]!='\0';i++)
    {
        temp=name[i];//storing the ASCII value of name[i] in temp in each iteration 
        int dig_c=n_of_dig(temp);//calculating the number of digits in temp 
        t=t*power(10,dig_c)+temp;//converting the number again to integer after ASCII from this iteration
                                 //gets juxtaposed
    }
    printf("%llu\n",t);
    int number_of_dig=n_of_dig(t);
    long num_right=t%power(10,number_of_dig/2),num_left=t/power(10,n_of_dig(num_right));
    //uncomment to get the sum of the left_num and the right_num printed to the console
    //printf("%llu\n%llu\n",num_left,num_right);
    long new_number=num_left+num_right;//generating the sum of the left and right half number
    int x=8;
    for(i=0;i<8;i++)
    printf("%lu\n",new_number%primes[i]);
}
int main()
{
    char name[]="Saurabh";
    char surname[]="Mukherjee";
    solve(name);//calling the function for name 
    printf("\n");
    solve(surname);//calling the function for the surname
    return 0;
}