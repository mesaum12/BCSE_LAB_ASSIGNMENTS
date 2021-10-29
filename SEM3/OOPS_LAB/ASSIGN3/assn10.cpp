#include<iostream>
using namespace std;
#define MAX 100
class STACK
{
  int tos;
  int stack[MAX];
  public:
  STACK(){
  tos=0;
  }
  void push(int k);
  void pop();
  int size();
  ~STACK()
  {
      cout<<"stack released\n";
  }
};
void STACK::push(int k)
{
    if(tos==MAX)
    cout<<"Stack Overflow\n";
    else
    {
        stack[tos]=k;
        tos++;
    }
    
}
int STACK::size()
{ return tos;}
void STACK::pop()
{
    if(tos==0)
    cout<<"Underflow\n";
    else
    {
        tos--;
    }
}
int main()
{
  STACK s;
  while(1)
  {
      cout<<"1.Push\n";
      cout<<"2.Pop\n";
      cout<<"3.Size \n";
      cout<<"4.Exit\n";
      cout<<"Enter your choice\n";
      int choice;
      cin>>choice;
      switch(choice)
      {
          case 1:
                cout<<"Enter the element to be pushed:\n";
                int k;
                cin>>k;
                s.push(k);
                break;
          case 2:
                s.pop();
                break;
          case 3:
                cout<<s.size()<<"\n";
                break;
          case 4:
                exit(0);
          default:
                cout<<"Invalid choice \n";
                
      }
  }
  return 0;
}