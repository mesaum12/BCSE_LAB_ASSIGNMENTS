#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//to  calculate the length of the provided string
int length_name(char *str)
{ 
   return strlen(str);
}
//creating and writing the names alphabetically sorted in ascending order 
void write_to_file(char *fn,long long int roll[100],char name[50][100],int n)
{
   FILE *ptr=fopen(fn,"w");
   int i,j;
   for(i=0;i<n-1;i++)
    {
      for(j=0;j<n-i-1;j++)
       {
         char str[50];
         if(strcmp(name[j],name[j+1])>1)
         {
           strcpy(str,name[j]);
           strcpy(name[j],name[j+1]);
           strcpy(name[j+1],str);
         
            
           long long int temp;
           temp=roll[j];
           roll[j]=roll[j+1];
           roll[j+1]=temp;
         }
        
        }
     }
   for(i=0;i<n;i++)
   {
    fprintf(ptr,"%lu  %s\n",roll[i],name[i]);
   }
   fclose(ptr);//closing the file
   
}
int main()
{
  //int roll_of_longest_name=-1;
  FILE *ptr=fopen("roll_name.txt","r");
  if(ptr==NULL)
  {
      printf("file not found\n");
      exit(0);
  }
  long long int roll[100];
  char name[50][100];
  int i=0,counter=0;
  while(1)
  {
   fscanf(ptr,"%lu %[^\n]s",&roll[i],name[i]);
   counter++;
   i++;
   if(feof(ptr))break;
   }
  char longest_name[50],shortest_name[50],str[50];
  strcpy(longest_name,"");
  strcpy(shortest_name,"saurabhfashfjdkfhkjsahfjkds");
  for(i=0;i<counter;i++)
   {
    strcpy(str,name[i]);
   //finding the longest name from the file  
    if(length_name(str)>length_name(longest_name))
     {
         strcpy(longest_name,name[i]);
         //roll_of_longest_name=roll[i];
     }
     //finding the shortest name from the file
     if(length_name(str)<length_name(shortest_name))
     {
         strcpy(shortest_name,name[i]);
         //roll_of_longest_name=roll[i];
     }
   }
  //printing the longest and shortest name 
  printf("The length of the longest name is %s .It is of length %d\n",longest_name,strlen(longest_name));
  printf("The length of the shortest name is %s.It is of length %d\n",shortest_name,strlen(shortest_name));
  char fn[31];
  strcpy(fn,"filename.txt");
  write_to_file(fn,roll,name,counter);
  fclose(ptr);//closing the file 
  return 0;
}