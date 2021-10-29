#include<stdio.h>
void merge(int array1[],int array2[],int m,int n,int array_final[])
{
    int i=0,j=0,k=0;
    while(i<m && j<n)
    {
        if(array1[i]<=array2[j])
        {
            array_final[k]=array1[i];
            i++;k++;
        }
        else
        {
            array_final[k]=array2[j];j++;k++;
        }
        
    }
    while(i<m)
    {
        array_final[k]=array1[i];i++;k++;
    }
    while(j<n){
        array_final[k]=array2[j];j++;k++;
    }
}
int main()
{
    int m,n,array1[100],array2[100],array3[200],i;
    printf("Enter the size of array1\n");
    scanf("%d",&m);
    printf("Enter the elements of array 1 in sorted order \n");
    for(i=0;i<m;i++)scanf("%d",&array1[i]);
     printf("Enter the size of array2\n");
    scanf("%d",&n);
    printf("Enter the elements of array 2 in sorted order\n");
    for(i=0;i<n;i++)scanf("%d",&array2[i]);

    //merging both the sorted arrays
    merge(array1,array2,m,n,array3);

    printf("The elements of the sorted array are \n");
    for(i=0;i<m+n;i++)
    printf("%d ",array3[i]);

    return 0;
    
    
}