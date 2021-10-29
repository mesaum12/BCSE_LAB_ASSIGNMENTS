#include<stdio.h>
#define ROW 2
#define COL 3
int main()
{
    int array[ROW][COL],i,j;
    //A pointer to an array 
    int (*ptr)[COL];
    // An array of pointers 
    int *p[ROW];
    for(i=0;i<ROW;i++)
     p[i]=&array[i][0];
    ptr=array;

    printf("Enter the values of the array");
    //reading the array using the pointer to the array
    for(i=0;i<ROW;i++)
      for(j=0;j<COL;j++)
       scanf("%d",*(ptr+i)+j);

    printf("Printing the values of the array using the pointer to array\n");
    for(i=0;i<ROW;i++)
        {
         for(j=0;j<COL;j++)
                printf("%d ",*(*(ptr+i)+j));
              printf("\n");
        }
      printf("\nPrinting the values of the array using the array of pointers\n");
    for(i=0;i<ROW;i++)
        {
         for(j=0;j<COL;j++)
                printf("%d ",*(*(p+i)+j));
              printf("\n");
        }
    return 0;
}