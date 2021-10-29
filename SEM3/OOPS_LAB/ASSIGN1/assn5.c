//solving without using structure of array
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ROW 100
//function for allocating memory to the age and name array
void memory_allocate(int **age,char ***name,int n)
{
   int i;
   (*age)=(int*)malloc(n*sizeof(int));
    //Dynamic Memory Allocation to the name array
   *name=(char**)malloc(n*sizeof(char*));
   for(i=0;i<n;i++)
   ((*name)[i])=(char*)malloc(50*sizeof(char));
   return;

}
void sorting_list(int *age,char **name,int n)
{
    int i,j;
    char str[50];
    //using bubble sort,more efficient sorting techniques can also be used to achieve more efficiency
    for(i=0;i<n-1;i++)
      for(j=0;j<n-i-1;j++)
      {
         if(age[j]>age[j+1])
         {
            //swapping the corresponding ages in nondecreasing order
            int temp=age[j];
            age[j]=age[j+1];
            age[j+1]=temp;

            //swapping the corresponding names as per their ages
            strcpy(str,name[j]);
            strcpy(name[j],name[j+1]);
            strcpy(name[j+1],str);


         }
      }

}
void print_list(int *age,char **name,int n)
{
   int i;
   for(i=0;i<n;i++)
   {
      printf("%d %s\n",age[i],name[i]);
   }
   printf("\n");
}
void memory_deallocate(int **age,char ***name,int n)
{
   int i;
   free(*age);
   for(i=0;i<n;i++)
   free((*name)[i]);

   free(*name);
   

}
int main()
{
   int *age,n,i;
   char **name;//let us take the length of name to be maximum of 50 characters 
   printf("Enter the number of persons\n");
   scanf("%d",&n);
   memory_allocate(&age,&name,n);
   if(age && name)
   {
   printf("Enter the age and name of the persons one by one separated by a space\n");
   for(i=0;i<n;i++)
   {
      
      scanf("%d",age+i);
      scanf("%[^\n]s",name[i]);
   }
   sorting_list(age,name,n);

   printf("\nDisplaying the sorted output in the list in ascending order of their age\n");
   print_list(age,name,n);

   memory_deallocate(&age,&name,n);

   }
   else
   {
      printf("Couldn't allocate memory to the blocks\n");
      
   }
   
  return 0;

}