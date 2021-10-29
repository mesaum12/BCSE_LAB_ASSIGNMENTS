#include<iostream>
#include<cstring>
using namespace std;
class Time_AMPM;
class Time24;
class Time24
{
  int hh,min,sec;
  public:
  void display_time()
  {
    cout<<"The time is:"<<hh<<":"<<min<<":"<<sec<<"\n";
  }
  int show_hh();
  int show_min();
  int show_sec();
  Time24(Time_AMPM t)
  {
      hh=t.show_hh();
      min=t.show_min;
      sec=t.show_sec;
      if(t.show_ampm()==1)
      hh=(hh+12)%24;
  }
  Time24 operator+(int m)
  {
     min+=m;
     if(min>=60)
     {
       hh+=min/60;
       min%=60;

     }
     if(hh>=24)
     hh%=24;
     return *this;
  }
  Time24(int h=0,int m=0,int s=0)
  {
     hh=h;
     min=m;
     sec=s;
  }
  Time24 operator=(Time24 t)
  {
    hh=t.show_hh();
    min=t.show_min();
    sec=t.show_sec();
    return t;

  }
  
};

class Time_AMPM
{
  int hh,min,sec;
  int am_pm;
  public:
  void display_time()
  {
    cout<<"The time is:"<<hh<<":"<<min<<":"<<sec<<(am_pm==0?"AM":"PM")<<"\n";
  }
  
  
  int show_hh();
  int show_min();
  int show_sec();
  int show_ampm();
  Time_AMPM operator+(int m)
  {
     min+=m;
     if(min>=60)
     {
       hh+=min/60;
       min%=60;
     }
     if(hh>12)
     {
       am_pm=1-am_pm;
       hh=hh%12;
     }
     return *this;
  }
  Time_AMPM(Time24 t)
  {
    if(t.show_hh()<12)
    {
      am_pm=0;
      hh=t.show_hh();
      min=t.show_min();
      sec=t.show_sec();
    }
    else
    {
      am_pm=1;
      hh=t.show_hh()%12;
      min=t.show_min();
      sec=t.show_sec();
      
    }
   }
  Time_AMPM(int h=0,int m=0,int s=0,int flag=0)
  {
      hh=h;
      min=m;
      sec=s;
      am_pm=flag;
  }
};
int Time24::show_hh()
{
    return hh;
}
int Time24::show_min()
{
    return min;
}
int Time24::show_sec()
{
    return sec;
}
int Time_AMPM::show_hh()
{
    return hh;
}
int Time_AMPM::show_min()
{
    return min;
}
int Time_AMPM::show_sec()
{
    return sec;
}
int Time_AMPM::show_ampm()
{
    return am_pm;
}
int main()
{
  while(1)
  {
    cout<<"1.Enter time in 24 hour format\n";
    cout<<"2.Enter time in 12 hour format\n";
    cout<<"3.Exit the program\n";
    cout<<"Enter your choice\n";
    int choice;
    cin>>choice;
    if(choice==1)
  {
     
     int hh,min,sec;
     //t24.get_time();

     cout<<"Enter hour:";
     cin>>hh;
     cout<<"Enter min:";
     cin>>min;
     cout<<"Enter sec:";
     cin>>sec;

     Time24 t24(hh,min,sec);

     cout<<"1.Display in 24h format\n";
     cout<<"2.Display in 12h format\n";
     cout<<"3.Add minutes\n";
     cout<<"4.Exit\n";
     cout<<"Enter your choice\n";

     int c;
     cin>>c;

     switch(c)
     {
       case 1:
             t24.display_time();
             break;
       case 2:
             Time_AMPM t12;
             t12=t24;
             t12.display_time();
             break;

       case 3:
             cout<<"Enter the minutes to be added \n";
             int minutes;
             cin>>minutes;
             t24=(t24+minutes);
             break;

       case 4:
             exit(0);

       default:
       cout<<"Invalid choice\n";
     }

  }
  else if(choice==2)
  {
      
      int hh,min,sec,am_pm;
      Time24 t24;
      //t.get_time();
      cout<<"Enter hour:";
     cin>>hh;
     cout<<"Enter min:";
     cin>>min;
     cout<<"Enter sec:";
     cin>>sec;
     cout<<"Enter 0 for AM and 1 for PM:";
     cin>>am_pm;
     Time_AMPM t(hh,min,sec,am_pm);

     cout<<"1.Display in 12h format\n";
     cout<<"2.Display in 24h format\n";
     cout<<"3.Add minutes\n";
     cout<<"4.Exit\n";
     cout<<"Enter your choice\n";

     int c;
     cin>>c;

      switch(c)
     {
       case 1:
             t.display_time();
             break;
       case 2:
            
             t24=t;
             t24.display_time();
             break;
       case 3:
             cout<<"Enter the minutes to be added \n";
             int minutes;
             cin>>minutes;
             t=(t+minutes);
             break;
       case 4:
             exit(0);

       default:
             cout<<"Invalid choice\n";
     }
      
  }
  else if(choice==3)
  {
    exit(0);
    
  }
  else
  {
    cout<<"Invalid choice\n";
  }
  }
  
  return 0;
}