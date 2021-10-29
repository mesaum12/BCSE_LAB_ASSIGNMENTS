#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct person
{
   int age;
   char name[50];
}person;
void memory_allocate(person **ptr,int n)
{
  //memory allocation to the structure
    *ptr=(person*)malloc(n*sizeof(person));

}
void sort_list(person ptr[],int n)
{
    int i,j;
    person temp;
    for(i=0;i<n-1;i++)
      for(j=0;j<n-i-1;j++)
      {
          if(ptr[j].age>ptr[j+1].age)
          {
               temp=(ptr[j]);
              (ptr[j])=(ptr[j+1]);
              (ptr[j+1])=temp;
          }
         
      }
}
void read_data(person **ptr,int n)
{
    int i;
    if(*ptr){
        printf("\nEnter the age and name of the persons in the list one by one separated by a space\n");
    for(i=0;i<n;i++)
      {
        
        scanf("%d",&((*ptr+i)->age));
        
        scanf("%[^\n]s",(*ptr+i)->name);
       }
    }
    else
    {
        printf("Memory Failure\n");
        exit(0);
    }
    
    return;
}
void print_list(person *ptr,int n)
{
    int i;
    printf("The list is as follows in the ascending order of their age\n");
    for(i=0;i<n;i++)
    {
        printf("%d %s\n",(ptr+i)->age,(ptr+i)->name);
    }
}
void memory_deallocate(person **ptr)
{
    free(*ptr);
    printf("Memory released successfully\n");

}
int main()
{
    int i,n;
    person *ptr;
    printf("Enter the number of persons in the list\n");
    scanf("%d",&n);
    //function for the memory allocation to the structure 
    memory_allocate(&ptr,n);
    //function for reading data
    read_data(&ptr,n);
    
    //funtion call for the sorting of the list 
    sort_list(ptr,n);
     //funtion call for printing the list
    print_list(ptr,n);
    //function call for memory deallocation
    memory_deallocate(&ptr);

    return 0;

}