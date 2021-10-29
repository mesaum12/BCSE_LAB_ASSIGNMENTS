#include<stdio.h>
#include<stdlib.h>
#include "sparse_mat.h"
int main()
{
    sparse_mat s;//creating a sparse matrix s 
    int a,b,choice,i,j,rows1,rows2,col1,col2;
    //user have the follwing choices to do with the matrix
  
      printf("--------You have the following choices----------\n");
    printf("1.Add two matrices \n");
    printf("2.multiply the matrices\n");
    printf("3.transpose the matrix\n");
    printf("4.exit the program\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);

    //taking the matrix entries 

    if(choice!=3)
    {
       printf("Enter the number of non-zero elements for the first matrix:");
    scanf("%d",&a);
    printf("Enter the number of rows for the first matrix:");
    scanf("%d",&rows1);
    printf("Enter the number of columns:");
    scanf("%d",&col1);

    printf("\n");

    printf("Enter the number of non-zero elements in the second matrix:");
    scanf("%d",&b);
    printf("Enter the number of rows for the second matrix:");
    scanf("%d",&rows2);
    printf("Enter the number of columns:");
    scanf("%d",&col2);
    printf("Enter the elements of the first matrix(ensure the order is rowwise then columnwise)\n");
    for(i=0;i<a;i++)
    {
       printf("Row:");
       scanf("%d",&s.array[i].row);
       printf("Col:");
       scanf("%d",&s.array[i].col);
       printf("Value:");
        scanf("%d",&s.array[i].value);
    }
    printf("\nYou entered the following as the first matrix\n");
    for(i=0;i<a;i++)
    {
       printf("Row:");
       printf("%d ",s.array[i].row);
       printf("Col:");
       printf("%d ",s.array[i].col);
       printf("Value:");
       printf("%d ",s.array[i].value);
       printf("\n");
    }
    printf("\n");
    printf("Enter the elements of the second  matrix(ensure the order is rowwise then columnwise)\n");
    for(i=a;i<a+b;i++)
    {
       printf("Row:");
       scanf("%d",&s.array[i].row);
       printf("Col:");
       scanf("%d",&s.array[i].col);
       printf("Value:");
       scanf("%d",&s.array[i].value);
      
    }
    printf("\nYou entered  the following as the second matrix\n");
    for(i=a;i<a+b;i++)
    {
       printf("Row:");
       printf("%d",s.array[i].row);
       printf("Col:");
       printf("%d",s.array[i].col);
       printf("Value:");
       printf("%d",s.array[i].value);
       printf("\n");
    }
     printf("\n");
     printf("\n");
    }
    
    switch(choice)
    {
        case 1:
              if(rows1==rows2 && col1==col2)
              {
                  add_sparse_mat(&s,a,b);
                  printf("The final matrix is :");
                  for(i=a+b;s.array[i].row!=-1;i++)
                  {
                  printf("Row:%d Col:%d Value:%d\n",s.array[i].row,s.array[i].col,s.array[i].value);
                  }
              }
              
              else 
              {
                  printf("Cannot be added since the rows or columns must be same for both the matrices\n");
                  exit(0);
              }

              break;
        case 2:
              if(col1==rows2)
              {
                    multiply(&s,a,b,rows1,col1,col2);
                    printf("The final matrix is :");
                    for(i=a+b;s.array[i].row!=-1;i++)
                    {
                    printf("Row:%d Col:%d Value:%d\n",s.array[i].row,s.array[i].col,s.array[i].value);
                    }
              }
              else
              printf("The matrices are of incompatible types and hence cannot be multiplied\n");

              break;
              
        case 3:
              printf("Enter the number of non-zero elements:");
              scanf("%d",&a);
              printf("Enter the number of rows for the matrix:");
              scanf("%d",&rows1);
              printf("Enter the number of columns:");
              scanf("%d",&col1);
              printf("Reading the elements of the matrix to be transposed\n");
              for(i=0;i<a;i++)
              {
               printf("Row:");
               scanf("%d",&s.array[i].row);
               printf("Col:");
               scanf("%d",&s.array[i].col);
               printf("Value:");
               scanf("%d",&s.array[i].value);
              }
              printf("\n");
              transpose(&s,a);//calling the transpose function
              printf("The final matrix is :");
              for(i=0;i<a;i++)
              {
                  printf("Row:%d Col:%d Value:%d\n",s.array[i].row,s.array[i].col,s.array[i].value);
              }
              printf("\n");
              break;

        case 4:
              exit(0);

        default:
              printf("Invalid choice\n");
    }
    return 0;
}
