#include<iostream>
using namespace std;
class APPLICANT
{
  static int last_id;
  int score,id;
  char name[31];
  public:
  void set_details();
  void show_details();
  static int show_student_count();
  
};
int APPLICANT::last_id=0;
void APPLICANT::set_details()
{
  cout<<"Enter the name\n";
  cin>>name;
  cout<<"Enter the score\n";
  cin>>score;
  id=last_id+1;
  last_id++;
}
void APPLICANT::show_details()
{
    cout<<"Name:"<<name<<"\n";
    cout<<"Score:"<<score<<"\n";

}
int APPLICANT::show_student_count()
{
  return last_id;
}
int main()
{
    
    APPLICANT s1,s2;
    s1.set_details();
    s1.show_details();
    s2.set_details();
    s2.show_details();
    cout<<APPLICANT::show_student_count()<<"\n";
    return 0;
}