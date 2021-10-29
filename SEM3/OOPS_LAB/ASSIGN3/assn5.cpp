#include<iostream>
using namespace std;
//double interest_money(double amount,double=10);
double interest_money(double amount,double taxrate=10)
{
    return (taxrate*amount)/100;
}
int main()
{
  double amount,taxrate;
  cout<<"Enter the amount : ";
  cin>>amount;
  cout<<"Enter the tax rate: ";
  cin>>taxrate;
  cout<<"The tax amount is:"<<interest_money(amount,taxrate)<<"\n";
  cout<<"The tax amount with the default tax rate is: "<<interest_money(amount)<<"\n";
  return 0;
  
}
