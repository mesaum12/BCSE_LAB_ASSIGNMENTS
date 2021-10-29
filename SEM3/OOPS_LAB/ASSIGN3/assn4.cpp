//write a function that will return a reference of the larger variable ,In both the cases store the 
//modified values in variable x and x1 where x is a variable of the type of a and x1 is a reference variable
//referring to the type of a then modify both x and x1 and see the changes in both the cases
#include<iostream>
using namespace std;
int& max(int& a,int& b)
{
    return a>b?a:b;

}
int main()
{
    int a,b,x;
    cout<<"Enter the values of a and b\n";
    cin>>a>>b;
    
    int ans1=max(a,b);
    cout<<"Before modification, max:"<<ans1<<" a:"<<a<<" b:"<<b<<"\n";
    ans1++;
    cout<<"After modification, max:"<<ans1<<" a:"<<a<<" b:"<<b<<"\n";
    int& ans2=max(a,b);
    cout<<"Before modification, max:"<<ans2<<" a:"<<a<<" b:"<<b<<"\n";
    ans2++;
    cout<<"After modification, max:"<<ans2<<" a:"<<a<<" b:"<<b<<"\n";
    return 0;
}