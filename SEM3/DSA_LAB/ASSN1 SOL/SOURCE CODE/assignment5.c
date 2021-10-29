#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000
int main()
{
    int n=10;
    FILE *ptr;
    ptr=fopen("string.txt","w");//opening the file string.txt in write mode to write the strings 
    //generated randomly
    srand(time(0));
    //char array[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char array[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0;i<MAX;i++)
    {
        //char s[]="";
        for(int j=0;j<10;j++)
        {
           char c=array[rand()%26];
           //strcat(s,array[rand()%26]);
           fputc(c,ptr);//putting the character side by side till this inner loop ends
        }
        fputc('\n',ptr);//putting a newline character once a string writing is complete to the file
    }
    fclose(ptr);//closing the file 
    return 0;
}
    