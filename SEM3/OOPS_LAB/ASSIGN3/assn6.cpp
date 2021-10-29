#include<iostream>
using namespace std;
void f(int);
void f(float);
int main()
{
   int i;
   char ch;
   float fl;
   double dl;
   f(i);
   f(ch);
   f(fl);
   //f(dl);//gives error that more than one function matches the argument list and hence an error in the 
   //function overloading


}
void f(int)
{
    cout<<"inside f(int) \n";
}
void f(float)
{
    cout<<"inside f(float) \n";
}
