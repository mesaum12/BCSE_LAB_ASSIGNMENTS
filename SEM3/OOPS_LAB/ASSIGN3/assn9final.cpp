#include<iostream>
using namespace std;
class Time24
{
  int hh,min,sec;
  public:
  void set_time(int hr,int mn,int sc)
  {
     hh=hr%24;
     min=mn;
     sec=sc;
  }
  Time24(int hr=12,int mn=0,int sc=0)
  {
     hh=hr;
     min=mn;
     sec=sc;
  }
  int get_hr(){
      return hh;
  }
  int get_min()
  {
      return min;
  }
  int get_sec()
  {
      return sec;
  }
  void display_time()
  {
      cout<<"Time: "<<hh<<":"<<min<<":"<<sec<<"\n";
  }
  Time24 operator+(int minutes)
  {
     int temp=(minutes/60);
     hh=(hh+temp)%24;
     min+=minutes;
     if(min>60)
     min%=60;
     
     return *this;
  }
};
class TimeAMPM
{
   int hh,min,sec,flag;
   public:
   void set_time(int hr,int mn,int sc,int flag)
  {
     hh=hr;
     min=mn;
     sec=sc;
     flag=flag;
  }
  TimeAMPM(int hour=12,int min=0,int sec=0,int flag=0)
  {
    
    hh=hour;
    min=min;
    sec=sec;
    flag=flag;
  }
  int get_hr(){
      return hh;
  }
  int get_min()
  {
      return min;
  }
  int get_sec()
  {
      return sec;
  }
  TimeAMPM(Time24 t)
  {
     hh=t.get_hr();
     min=t.get_min();
     sec=t.get_sec();
     flag=0;
     if(hh>12)
     {
         flag=1-flag;
         hh=hh%12;
     }
  }
   //typecasting object of type TimeAMPM to object of type Time24
   operator Time24()
   {
       int h,m,s;
       h=hh;
       m=min;
       s=sec;
       if(flag)
       h=(h+12)%24;
       return Time24(h,m,s);
   }
   TimeAMPM operator+(int minutes)
  {
     min+=minutes;
     if(min>60)
     min%=60;
     hh=(hh+minutes/60);
     if(hh>12)
     {
         flag=1-flag;
         hh%=12;
     }
    return *this;
  }
   void display_time()
  {
      cout<<"Time: "<<hh<<":"<<min<<":"<<sec<<(flag==1?"PM":"AM")<<"\n";
  }

};
int main()
{
    
    int hh,min,sec,flag,minutes;
    Time24 t24,tt24;
    TimeAMPM t12,tt12;
     
    
    cout<<"Enter hour ,min and sec(Please ensure that hour<24,min<60,sec<60) :\n";
    cin>>hh>>min>>sec;
    t24.set_time(hh,min,sec);//take input in 24 hour format
    t24.display_time();//display in 24 hour format
    t12=t24;
    t12.display_time();//display in 12hour format
    cout<<"Enter minutes to add:";
    cin>>minutes;
    t24=(t24+minutes);//overloading the + operator to do the required addition in minutes to the time
    t24.display_time();


    
    cout<<"Enter hour ,min , sec and flag(0 for am and 1 for pm),and ensure hour<=12,min<60,sec<60\n";
    cin>>hh>>min>>sec>>flag;
    tt12.set_time(hh,min,sec,flag);//take input in 12 hour format
    tt12.display_time();//display in 12 hour format
    tt24=tt12;
    tt24.display_time();//display in 24 hour format
    cout<<"Enter minutes to add:";
    cin>>minutes;
    tt12=(tt12+minutes);//overloading the + operator to do the required addition in minutes to the time
    tt12.display_time();//display in 12 hour format
       
    return 0;
}