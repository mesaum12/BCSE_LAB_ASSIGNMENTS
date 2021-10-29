#include<stdio.h>
#include<stdlib.h>

int main()
{
    //using the concept of Dynamic Memory Allocation to read an array and print the values
    int *p,n,i;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));
    if(p)
    {
        printf("Enter the values of the array\n");
        for(i=0;i<n;i++)
        {
              scanf("%d",p+i);
        }
        printf("Printing the values of the array\n");
        for(i=0;i<n;i++)
        {
            printf("%d ",*(p+i));
        }
        printf("\n");
        free(p);
    }
    else
    {
        printf("Memory Failure\n");
    }
    return 0;
    
}