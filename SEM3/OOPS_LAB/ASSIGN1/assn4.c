#include<stdio.h>
#include<stdlib.h>
#define ROW 10
#define COL 10
int main()
{
    int r,c,i,j;
    scanf("%d%d",&r,&c); 
    //int *ptr[ROW];
    int (*p)[COL];
    int **ptr;
    
    ptr=(int**)malloc(r*sizeof(int*));
    for(i=0;i<r;i++)
    ptr[i]=(int*)malloc(10*sizeof(int));
    p=ptr;
   
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        scanf("%d",*(p+i)+j);
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        printf("%d ",*(*(p+i)+j));
        printf("\n");
    }

    return 0;


}