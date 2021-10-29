/*Take an arbitrary Matrix of positive integers, say, 128 X 128. Also take integer matrices of
size 3 X 3 and 5 X 5. Find out an output matrix of size 128 X 128 by multiplying the small
matrix with the corresponding submatrix of the large matrix with the centre of the small matrix
placed at the individual positions within the large matrix. Explain how you will handle the
boundary values.
*/
#define MAX 128
#define MAX2 5
#include<stdio.h>
#include<stdlib.h>
void multiply(int ***mat,int mat2[MAX][MAX2],int point,int point2)
{
    int array[MAX2][MAX2],result[MAX2][MAX2];//the submatrix is generated 
    int i,j,k,t,r;
     
    for(i=point-MAX2/2,t=0;i<=point+MAX2/2;i++,t++)
    {
        for(j=point2-MAX2/2,r=0;j<=point2+MAX2/2;j++,r++)
        {
            array[t][r]=(*mat)[i][j];
        }
    }
  
    
    for(i=0;i<MAX2;i++)
      for(j=0;j<MAX2;j++)
      {
          result[i][j]=0;
      }
    for(i=0;i<MAX2;i++)
      for(j=0;j<MAX2;j++)
         for(k=0;k<MAX2;k++)
           result[i][j]+=(array[i][k] * mat2[k][j]);
    
  

    for(i=point-MAX2/2,t=0;i<=point+MAX2/2;i++,t++)
    {
        for(j=point2-MAX2/2,r=0;j<=point2+MAX2/2;j++,r++)
        {
            (*mat)[i][j]=result[t][r];
            printf("%d ",(*mat)[i][j]);
        }
       printf("\n");
    }
    
}
int main()
{
   int **mat;
   int mat2[MAX2][MAX2];
   int i,j,k,n,row,col,value,value2;
   mat=(int**)malloc(MAX*sizeof(int*));
   for(i=0;i<MAX;i++)
   mat[i]=(int*)malloc(MAX*sizeof(int));
   
   printf("Enter the number of matrix entries which are non-zeroes\n");
   scanf("%d",&n);
   //clearing the matrix before taking input as the non-zero entries
   for(i=0;i<MAX;i++)
   {
       for(j=0;j<MAX;j++)
       {
          mat[i][j]=0;
       }
   }
   //clearing the matrix 2 
   for(i=0;i<MAX2;i++)
   {
       for(j=0;j<MAX2;j++)
       {
          mat2[i][j]=0;
       }
   }

   for(i=0;i<n;i++)
   {
       printf("Row: Col: Value:\n");
       scanf("%d%d%d",&row,&col,&value);
       mat[row][col]=value;
   }

   printf("Enter the number of matrix entries which are non-zeroes\n");
   scanf("%d",&n);

   for(i=0;i<n;i++)
   {
        printf("Row: Col: Value:\n");
        scanf("%d%d%d",&row,&col,&value);
        mat2[row][col]=value;
   }

    printf("Enter the value of the middle point in the submatrix of the larger matrix correctly \n");
    scanf("%d%d",&value,&value2);
    if(value-MAX2/2<0 || value+MAX2>=MAX || value2-MAX2/2<0 || value2+MAX2/2>=MAX)
    {
        printf("The boundary values are not correct and the submatrix gets out of bounds\n");
        exit(0);
    }
    multiply(&mat,mat2,value,value2);

    printf("The final values of the new matrix are\n");
    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            if(mat[i][j]!=0)
            {
                printf("Row:%d Col:%d Value:%d",i,j,mat[i][j]);
            }
        }
    }
    printf("\n");
     for(i=0;i<MAX;i++)
    free(mat[i]);
    free(mat);
    printf("Rest all are zeroes for the matrix after multiplication\n");
    return 0;

}