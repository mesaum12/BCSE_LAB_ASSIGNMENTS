#define MAX 101
#include<stdio.h>
typedef struct 
{
   int array[MAX];
}list;
void init(list *l)
{
    ((*l).array)[0]=-1;
}
int is_empty(list *l)
{
   return (((*l).array)[0]==-1);
}
void add_element(list *l,int element)
{
   int i;
   for(i=0;((*l).array)[i]!=-1;i++);
   if(((*l).array)[i]==-1)
   ((*l).array)[i]=element;
   ((*l).array)[i+1]=-1;
   
}
int get_last_node(list *l)
{
   int i=0;
   for(i=0;;i++)
   {
     if(((*l).array)[i]==-1)return i;
   }
}
void insert_after(list *l,int add_after,int element_to_add)
{
   int i=0;
   for(i=0;((*l).array)[i]!=add_after && ((*l).array)[i]!=-1;i++);
   if(((*l).array)[i]==-1)printf("data not found\n");
   else
   {
      int t=get_last_node(l); ((*l).array)[t+1]=-1;
      int j=t;
      while(j>i+1)
      {
         ((*l).array)[j]=((*l).array)[j-1];
         j--;
      }
      ((*l).array)[j]=element_to_add;
     
   }
   
}
void insert_front(list *l,int element)
{
   int i,t=get_last_node(l),j=t;
   ((*l).array)[t+1]=-1;
   while(j>0)
   {
      ((*l).array)[j]=((*l).array)[j-1];
      j--;
   }
   ((*l).array)[0]=element;
}
void delete_node(list *l,int element)
{
   int i,j;
   if(is_empty(l)){printf("List is empty\n");
      return ;
   }
   for(i=0;((*l).array)[i]!=element && ((*l).array)[i]!=-1;i++);
   if(((*l).array)[i]==-1)printf("data not found\n");
   else
   {
       for(j=i;((*l).array)[j]!=-1;j++)
       ((*l).array)[j]=((*l).array)[j+1];
   }
   
}
void delete_front(list *l)
{
   int i=0;
   if(is_empty(l))printf("List is empty\n");
   else
   {
     delete_node(l,((*l).array)[0]);
   }
   
}
void delete_after(list *l,int element)
{
   int i;
   if(is_empty(l))printf("List is empty\n");
   else
   {
      for(i=0;((*l).array)[i]!=-1 && ((*l).array)[i]!=element;i++);
       if(((*l).array)[i]==-1)printf("data not found\n");
       else
       {
          if(((*l).array)[i+1]==-1)printf("It is the last node, no node after it exists which could be deleted\n");
          else delete_node(l,((*l).array)[i+1]);
       }
   }
}
void printlist(list *l)
{
   int i=0;
   if(is_empty(l))printf("List is empty\n");
   else
   {
      while(((*l).array)[i]!=-1)
      {
         printf("%d ",((*l).array)[i]);
         i++;
      }
      printf("\n");
   }
   
}
void delete_list(list *l)
{
   int i=0;
   while(((*l).array)[i]!=-1)
   {
      ((*l).array)[i]=-1;
      i++;
   }
}