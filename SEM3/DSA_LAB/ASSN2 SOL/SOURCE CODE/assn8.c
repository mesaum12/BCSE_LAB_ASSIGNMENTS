#include<stdio.h>
int is_sorted(int array[],int n)
{
    int i;
    for(i=0;i<n-1;i++)
    {
         if(array[i]>array[i+1])
         return 0;
    }
    return 1;
}
int main()
{
    int n,array[100],i;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)scanf("%d",&array[i]);
    if(is_sorted(array,n))
    printf("The array is sorted \n");
    else
    {
        printf("The array is not sorted\n");
    }
    
    return 0;
}