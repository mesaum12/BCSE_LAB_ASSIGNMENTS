/*
Operations:
init_l(cur) – initialise a list
empty_l(head) – boolean function to return true if list pointed to by
head is empty
atend_l(cur) – boolean function to return true if cur points to the last
node in the list
insert_front(target, head) – insert the node pointed to by target as the
first node of the list pointed to by head
insert_after(target, prev) – insert the node pointed to by target after
the node pointed to by prev
delete_front(head) – delete the first element of the list pointed to by
head
delete_after(prev) – delete the node after the one pointed to by prev
*/
#include<stdio.h>
#include "saurabh_ll.h"
#include<stdlib.h>
int main()
{
    int choice,element,add_after ;
    list l;
    init(&l);
    while(1)
    {
       printf("1.Add node\n");
       printf("2.Insert After\n");
       printf("3.Print the list\n");
       printf("4.Delete the list\n");
       printf("5.Insert at front\n");
       printf("6.Delete the front node\n");
       printf("7.delete after a particular node\n");
       printf("8.check if list is empty\n");
       printf("9.Exit the program\n");
       printf("Enter your choice\n");
       scanf("%d",&choice);

   

      switch(choice)
       {
      case 1:
             printf("Enter the element to be added\n");
             scanf("%d",&element);
             add_element(&l,element);
             break;
      case 2:
             printf("Enter the element after which insertion is to be done  \n");
             scanf("%d",&add_after);
             printf("Enter the element to be inserted\n");
             scanf("%d",&element);
             insert_after(&l,add_after,element);
             break;

      case 3:
            printlist(&l);
            break;

      case 4:
            delete_list(&l);
            break;
           
      case 5:
             printf("Enter the element to be added\n");
             scanf("%d",&element);
             insert_front(&l,element);
             break;
            
      case 6:
            delete_front(&l);
            break;
      case 7:
             printf("Enter the element after which deletion is to be performed \n");
             scanf("%d",&element);
             delete_after(&l,element);
             break;

      case 8:
            if(is_empty(&l))
            printf("Yes the list is empty\n");
            break;

      case 9:
           exit(0);

      default:
            printf("Invalid choice\n");
       }

   }
   return 0;
  
}