#include<stdio.h>
int main()
{
    int n;
    //pointer variable p pointing to n
    int *p=&n;
    printf("Enter the value of the integer variable n\n");
    scanf("%d",p);
    //pointer  pp pointing to the pointer variable p
    int **pp=&p;
    //printing the value using the pointer and the pointer to the pointer
    printf("The value of n using the pointer p is: %d\n",*p);

    printf("The value of n using the pointer to the pointer variable pp is: %d\n",**pp);
    return 0;
}