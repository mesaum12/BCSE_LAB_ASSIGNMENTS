//creating functions to get dimensions,read,print the contents and dynamically allocating
//the memory inside functions

#include<stdio.h>
#include<stdlib.h>
//function to read dimensions
void read_dimension(int *r,int *c)
{
   printf("Enter the number of rows\n");
   scanf("%d",r);
   printf("Enter the number of columns\n");
   scanf("%d",c);
}
//function to print the contents of the array
void print_array(int **p,int r,int c)
{
   int i,j;
   printf("Printing the contents of the array:\n");
   for(i=0;i<r;i++)
   {
       for(j=0;j<c;j++)
        printf("%d ",p[i][j]);
      printf("\n");
   }


}
//function to read the array
void read_array(int ***p,int r,int c)
{
    int i,j;
    if(*p){
    printf("Enter the values of the array\n");
      for(i=0;i<r;i++)
        for(j=0;j<c;j++)
          scanf("%d",*((*p)+i)+j);
    }
    else
    {
       printf("Memory Failure\n");
       exit(0);
    }
    

}
//function for the dynamic memory allocation
void dynamic_allocation(int ***p,int r,int c)
{
    int i,j;
   *p=(int**)malloc(r*sizeof(int*));
   for(i=0;i<r;i++)
   (*p)[i]=(int*)malloc(c*sizeof(int));

}
//function for the memory deallocation using the free function
void deallocate(int ***p,int r)
{
     int i;
     //releasing the memory for columns in each row
     for(i=0;i<r;i++)
     free((*p)[i]);
     
     free(*p);
     printf("Memory released successfully\n");

}
//main function
int main()
{
    int **p;
    int r,c;
    //Reading the number of elements 
     read_dimension(&r,&c);
     //calling the function for the dynamic memory allocation
     dynamic_allocation(&p,r,c);
     //reading the array
     read_array(&p,r,c);
     //printing the contents of the array
     print_array(p,r,c);
     //deallocating the array
     deallocate(&p,r);

     return 0;
}

