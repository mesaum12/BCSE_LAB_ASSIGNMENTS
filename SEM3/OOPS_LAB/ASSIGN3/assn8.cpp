#include<iostream>
using namespace std;
struct student 
{
  int roll;
  int score;
  void take_input(int a,int b);
  void show_data();
};
//making global functions to modify a and b
void modify(student *s)
{
    cout<<"Enter the modified roll number\n";
    cin>>s->roll;
    
    cout<<"Enter the modified score\n";
    cin>>s->score;
}
void student::take_input(int a,int b)
{
    roll=a;
    score=b;
}
void student::show_data()
{
    cout<<"Roll:"<<roll<<" ";
    cout<<"Score:"<<score<<"  \n";

}
int main()
{
   student s;
   int a,b;
   cout<<"Enter roll \n";
   cin>>a;
   cout<<"Enter score\n";
   cin>>b;
   s.take_input(a,b);
   s.show_data();
   modify(&s);
   s.show_data();
   return 0;

}