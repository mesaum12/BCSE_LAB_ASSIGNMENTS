#include<iostream>
using namespace std;
void f(int,int);
void f(char,int);
void f(float,float);
int main()
{
    int a;
    char ch;
    float fl;
    f(a,ch);
    f(ch,ch);
    f(fl,fl);
    return 0;
}
void f(int,int)
{
  cout<<"inside f(int,int) ";
}
void f(char,int)
{
  cout<<"inside f(char,int) ";
}
void f(float,float)
{
   cout<<"inside f(float,float) ";
}
