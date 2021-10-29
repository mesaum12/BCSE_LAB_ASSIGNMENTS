//how to check the size of the oject code is the doubt in this assignment
#include<iostream>
#include<chrono>
#include<algorithm>
using namespace std::chrono;
using namespace std;
int prod_two_nums(int a,int b)
{
    return a*b;
}
inline int prod_two_nums1(int a,int b)
{
    return a*b;
}
int main()
{
    int a,b,numberoftimes=1;
   
  cout<<"Enter the two numbers:\n";
  cin>>a>>b;
  cout<<"Enter the number of times the product function should be called "<<"\n";
  cin>>numberoftimes;
  int t=0;
  while (t!=numberoftimes)
  {
    auto start=high_resolution_clock::now();
    cout<<t<<" "<<prod_two_nums1(a,b)<<" ";
    auto stop=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(stop-start);
    cout<<"Execution time"<<t<<" "<<duration.count()<<"\n";
    t++;
  }
  t=0;
  cout<<"Enter the number of times the inline prod function should be called "<<"\n";
  cin>>numberoftimes;
   while (t!=numberoftimes)
  {
    auto start=high_resolution_clock::now();
    cout<<t<<" "<<prod_two_nums1(a,b)<<" ";
    auto stop=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(stop-start);
    cout<<"Execution time"<<t<<" "<<duration.count()<<"\n";
    t++;
  }
  return 0;
  
}