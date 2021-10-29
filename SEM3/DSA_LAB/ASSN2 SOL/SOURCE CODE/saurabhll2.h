#include<stdio.h>
#define MAX 101
typedef struct 
{
   int array[MAX];
   int length;
}list;
void init(list *l)
{
    (*l).length=0;
}
int is_empty(list *l)
{
   return ((*l).length==0);
}
void add_element(list *l,int element)
{
   int i;
   for(i=0;i<(*l).length;i++);
   if(i==(*l).length)
   ((*l).array)[i]=element;
   (*l).length++;
   
}
int get_last_node(list *l)
{
   int i=0;
   for(i=0;;i++)
   {
     if((i+1)==(l->length))return i;
   }
}
void insert_after(list *l,int add_after,int element_to_add)
{
   int i=0;
   for(i=0;(*l).array[i]!=add_after && (*l).length>i;i++);
   if((*l).length==i){
       printf("data not found\n");
       return ;
   }
   else
   {
      int t=get_last_node(l),j=t+1; 
      while(j>i+1)
      {
         (*l).array[j]=(*l).array[j-1];
         j--;
      }
      (*l).array[j]=element_to_add;
      (*l).length++;
     
   }
   
}
void insert_front(list *l,int element)
{
   int i,t=get_last_node(l),j=t+1;
   while(j>0)
   {
      (*l).array[j]=(*l).array[j-1];
      j--;
   }
   (*l).length++;
   ((*l).array)[0]=element;
}
void delete_node(list *l,int element)
{
   int i,j;
   if(is_empty(l)){printf("List is empty\n");
      return ;
   }
   for(i=0;((*l).array)[i]!=element && (*l).length!=i;i++);
   if((*l).length==i)printf("data not found\n");
   else
   {
       for(j=i;j<(*l).length-1;j++)
       ((*l).array)[j]=((*l).array)[j+1];
   }
   (*l).length--;
   
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
      for(i=0;(*l).length!=i && ((*l).array)[i]!=element;i++);
       if((*l).length==i)printf("data not found\n");
       else
       {
          if((*l).length-i==1)printf("It is the last node, no node after it exists which could be deleted\n");
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
      while((*l).length!=i)
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
   (*l).length=0;
}