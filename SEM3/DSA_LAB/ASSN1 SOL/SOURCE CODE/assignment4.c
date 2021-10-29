#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 100000
int main()
{
    srand(time(0));//for generating random numbers each time
    FILE *ptr;
    ptr=fopen("myname.txt","w");
    long long t;
    int i;
    for(i=0;i<MAX;i++)
    {
        char s[10];
        t=rand()%MAX+1;
        sprintf(s,"%llu",t);
        fprintf(ptr,"%s\n",s);
    }
    fclose(ptr);
    return 0;
}