#include<iostream>
using namespace std;
void swap(int&,int&);
int main()
{
    int a,b;
    cout<<"Enter the values of a and b separated by a space\n";
    cin>>a>>b;
    swap(a,b);
    cout<<"The values of a and b is "<<a<<" "<<b;
    return 0;
}
void swap(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
