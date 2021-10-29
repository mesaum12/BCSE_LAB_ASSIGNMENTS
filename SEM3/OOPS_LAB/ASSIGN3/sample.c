#include<stdio.h>
#include<stdlib.h>
int main()
{
    int **p;
    printf("Enter the numbe of rows and columns\n");
    int row,col;
    scanf("%d%d",&row,&col);
    p=(int**)malloc(row*sizeof(int*)+row*col*sizeof(int));
    int i,j;
    for(i=0;i<row;i++)
    {
        p[i]=*(p+row)+i*col;
    }
    //reading the date in the array locations now
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        scanf("%d",&p[i][j]);
    }
    printf("Printing the array values:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        printf("%d ",p[i][j]);
        printf("\n");
    }
    //this is the program which uses one malloc statement and a 2d pointer 
    //to initialise the pointer
    return 0;
}