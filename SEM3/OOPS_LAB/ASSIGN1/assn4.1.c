//creating functions to get dimensions,read,print the contents and dynamically allocating
//the memory inside functions

#include<stdio.h>
#include<stdlib.h>
//function to read dimension
void read_dimension(int *n)
{
   printf("Enter the number of elements for which the memory is to be allocated\n");
   scanf("%d",n);
}
//function to print the contents of the array
void print_array(int *p,int r)
{
   int i;
   printf("Printing the contents of the array:\n");
   for(i=0;i<r;i++)
   printf("%d ",p[i]);
   printf("\n");


}
//function to read the array
void read_array(int **p,int n)
{
    int i;
    printf("Enter the values of the array\n");
    for(int i=0;i<n;i++)
    scanf("%d",*p+i);

}
//function for the dynamic memory allocation
void dynamic_allocation(int **p,int n)
{
   *p=(int*)malloc(n*sizeof(int));

}
//function for the memory deallocation using the free function
void deallocate(int **p)
{
    free(*p);
}
//main function
int main()
{
    int *p;
    int n;
    //Reading the number of elements 
    read_dimension(&n);
     //calling the function for the dynamic memory allocation
     dynamic_allocation(&p,n);
     //reading the array
     read_array(&p,n);
     //printing the contents of the array
     print_array(p,n);
     //deallocating the array
     deallocate(&p);

     return 0;
}

