#include<iostream>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))
int main()
{
   cout<<"Enter two integers separated by a space \n";
   int a,b;
   cin>>a>>b;
   cout<<"The maximum of a and b is :"<<MAX(a,b)<<"\n";
   //if we do not use the const keyword the compiler generates and error saying converting string 
   //to char* is forbidden
   cout<<" Two char pointers or string literals:"<<"\n";
   const char *s1="saurabh",*s2="manoj";
   //cin>>s1>>s2;
   cout<<"The maximum is :"<<MAX(s1,s2)<<"\n";
   return 0;
}