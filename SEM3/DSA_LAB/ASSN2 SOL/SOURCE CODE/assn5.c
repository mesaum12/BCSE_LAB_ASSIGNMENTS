#include<stdio.h>
#include "saurabh_str.h"
int main()
{
    
    char array[10]="saurabh";
    char array2[100]="hi i am a very good boyi";
    char subs[25];
    printf("%d\n",length(array));//defined under self-made header file
    printf("%d\n",is_empty(array));//defined under self-made header file
    printf("%s\n",string_cat(array,array2));//defined under self-made header file
    sub_str(array2,1,4,subs);//defined under self-made header file
    printf("%s\n",subs);//defined under self-made header file
    printf("%d\n",compare_str("saura","saurab"));
    
    return 0;
}