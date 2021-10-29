#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 10000
int main()
{
    int n[]={1103,1229,1231,1399,1667,1831,2003,1997}; //a four digit prime number
    FILE *ptr;
    srand(time(0));
    ptr=fopen("primesmod.txt","w");
    int k=0;
    for(int i=0;i<MAX;i++)
    {
       long t=rand()%MAX;
       char s1[10],s2[10];
       long r=(t%n[rand()%8]);//this will choose any index from 0 to 7 at random and any random prime from the array n[]
       sprintf(s1,"%lu",t);
       sprintf(s2,"%lu",r);
       fprintf(ptr,"%s1 %s2\n",s1,s2);
    }
    fclose(ptr);
    return 0;

}