#include<stdio.h>
#include<stdlib.h>
#include "saurabh_set.h"
int main()
{
     set s;int choice,element,index,i;
     for(i=0;i<MAX;i++) s.array[i]=0;
     s.array[0]=-1000;//we are using -1000 as the sentinel 
     while(1)
     {
     printf("1.add element \n");
     printf("2.remove element\n");
     printf("3.search element\n");
     printf("4.size of the set\n");
     printf("5.Print the set\n");
     printf("6.Exit \n");
     printf("Enter your choice\n");
     scanf("%d",&choice);
     switch (choice)
     {
     case 1:
            printf("Enter the element to be added\n");
            scanf("%d",&element);
            add_element(s,element);
            break;
     case 2:
            printf("Enter the element to be removed\n");
            scanf("%d",&element);
            remove_element(s,element);
            break;
     case 3:
            printf("Enter the element to be searched\n");
            scanf("%d",&element);
            int t=search_element(s,element);
            if(t!=-1)printf("Element is present ");
            else printf("Element not found\n");
            break;
     case 4:
            printf("%d\n",size_of_set(s));
            break;
     case 5:
          print_set(s);
          printf("\n");
          break;
    case 6: exit(0);
     
    default:
           printf("Invalid choice\n");
         
         }
     }
    
   return 0;
}
