#include<iostream>
#include<cstring>
using namespace std;
class TRANSACTION;
class BALANCE
{
    int account_number;
    float balance;
    char date_of_last_update[10];
    public:
    //friend class TRANSACTION;
    BALANCE(int account_number=1234,float balance=0,const char *date_of_last_update="1/12/2020")
    {
        cout<<"Initial balance using the constructor\n";
    }
    void show_balance();
    //void set_details();
    void update_balance(TRANSACTION &t);

};
class TRANSACTION
{
   int account_num;
   float amount;//the balance to be withdrawn or deposited 
   char type;//either W OR D for withdrawal and deposit respectively
   char date[10];
   public:
   void get_details();
   void friend BALANCE::update_balance(TRANSACTION &t);
   
};
void TRANSACTION::get_details()
{
    cout<<"Enter the account_num:";
    cin>>account_num;
    cout<<"Enter the amount to be withdrawn or deposited\n";
    cin>>amount;
    cout<<"Enter the type W OR D";
    cin>>type;
    cout<<"Enter the date:";
    cin>>date;
    
}
void BALANCE::show_balance()
{
    cout<<"Account Number:"<<account_number<<"\n";
    cout<<"Balance:"<<balance<<"\n";
    cout<<"Last date of Update:"<<date_of_last_update<<"\n";
}
void BALANCE::update_balance(TRANSACTION &t)
{
    if(t.type=='W')
    {
        if(balance>=t.amount)
        {
           balance=balance-t.amount;
           strcpy(date_of_last_update,t.date);
        }
        else
        {
            cout<<"low balance\n";
            return;
        }
        
    }
    else
    {
        balance=balance+t.amount;
        strcpy(date_of_last_update,t.date);

    }
    
}
int main()
{
     TRANSACTION t;BALANCE b;
     t.get_details();
     b.update_balance(t);
     b.show_balance();
     
}