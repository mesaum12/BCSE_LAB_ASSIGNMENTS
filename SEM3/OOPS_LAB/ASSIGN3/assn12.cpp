#include<iostream>
using namespace std;
class STUDENT
{
    int roll;
    char name[31];
    char course[31];
    char admission_date[10];
    int marks[5];
    static int number_of_students;
    public:
    void take_admission();
    void display_marksheet();
    static int show_number_of_students();
};
int STUDENT::number_of_students=0;
void STUDENT::take_admission()
{
    
    number_of_students++;
    roll=number_of_students;

    cout<<"Enter the name:";
    cin>>name;
    cout<<"Enter the course name:";
    cin>>course;
    cout<<"Enter the marks in five subjects:";
    for(int i=0;i<5;i++)
    {
        cout<<"Subject["<<i+1<<"]:";
        cin>>marks[i];
    }
    cout<<"Enter the date of admission:";
    cin>>admission_date;
}
void STUDENT::display_marksheet()
{
  cout<<"DOA(Date of Admission):"<<admission_date<<"\n";
  cout<<"Name:"<<name<<" ";
  cout<<"Roll:"<<roll<<" ";
  cout<<"Course:"<<course<<" ";
  cout<<"Scores:\n";
  for(int i=0;i<5;i++)
  cout<<"Score["<<i+1<<"]:"<<marks[i]<<"\n";
  
}
int STUDENT::show_number_of_students()
{
    return number_of_students;
}
int main()
{
    /*STUDENT s1,s2;
    s1.take_admission();
    s1.display_marksheet();
    cout<<STUDENT::show_number_of_students()<<"\n";*/
    //The loop for taking and displaying the student marks and details
    
    while(1)
    {
        STUDENT s;
        s.take_admission();
        s.display_marksheet();
        int choice;
        cout<<"Press 0 to exit\n";
        cin>>choice;
        if(!choice)
        break;
    }
    cout<<STUDENT::show_number_of_students()<<"\n";
    return 0;
}