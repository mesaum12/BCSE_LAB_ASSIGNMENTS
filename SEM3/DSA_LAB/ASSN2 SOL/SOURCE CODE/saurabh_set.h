#define MAX 1000
#include<stdio.h>
typedef struct 
{
   int array[MAX];
}set;
int add_element(set s,int element);
int remove_element(set s,int element);
void print_set(set s);
int search_element(set s,int element);//return the index or -1 if not found
//int add_at_particular_position(set s,int position,int element);
int size_of_set(set s);
int size_of_set(set s)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        if(s.array[i]==-1000)return i;
    }
    return MAX;
}
int add_element(set s,int element)
{
   int temp=size_of_set(s);
   if(temp<MAX)
   {
      s.array[temp]=element;
      s.array[temp+1]=-1000;
      return 1;
   }
   return 0;
}
int search_element(set s,int element)
{
    int temp=size_of_set(s),i;
    int flag=0;
    for(i=0;i<temp;i++)
    {
      if(s.array[i]==element)
      {
          return i;
      }
    }
    return -1;

}
int remove_element(set s,int element)
{
   int temp=search_element(s,element),t;
   if(temp!=-1)
   {
        for(t=temp;t<size_of_set(s);t++)
        s.array[t]=s.array[t+1];
        return 1;
   }
   return 0;
}
/*int add_at_particular_position(set s,int position,int element)
{
     int temp=size_of_set(array);int i=temp;
     if(temp!=MAX)
     {
         array[temp+1]=-1000;//shifting the sentinel to the next block in the array
         while(i>position)
         {
            array[i]=array[i-1];
            i--;
         }
         array[position]=element;
         return 1;
     }
     return 0;
}*/
void print_set(set s)
{
    int t=0;
    while(s.array[t]!=-1000)
    {
        printf("%d ",s.array[t]);
        t++;
    }
    
}