//the program is  using linked-list data structure to store and display the data
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct String
{
  char name[30];
}String;
//structure defining the Student data type 
typedef struct 
{
   int roll;
   char name[30];
   int score[5];
}Student;
//structure defining the Linked list node with data field of student type
typedef struct Node
{
   Student s;
   struct Node *next;
}Node;
//the head/root node
Node *root=NULL;

//function for creating a node
Node* createNode()
{
   Node *temp;
   char sub[][10]={"Maths","Phy","Chem","Comp","Bio"};
   int i;
   temp=(Node*)malloc(sizeof(Node));
   if(temp)
   {
       
       temp->next=NULL;
       printf("Enter the name:");
       getchar();
       scanf("%[^\n]s",(temp->s).name);
       printf("Enter the roll number: ");
       scanf("%d",&(temp->s).roll);
       
       
       printf("Enter the scores: ");
       for(i=0;i<5;i++)
       {
           printf("%s:",sub[i]);
           scanf("%d",&(temp->s).score[i]);
           
       }
       
   }
   else
   {
       printf("Memory Failure\n");
       
   }
   
   return temp;
}
//function for inserting a node
void insert_student(Node **root)
{
    Node *temp=createNode();
    
    if(temp)
    {
        if(*root==NULL)
        *root=temp;
        else 
        {
            //inserting at the beginning is the most efficient insertion 
            //for a singly linked list 
            temp->next=*root;
           *root=temp;
        }
    }
    else
    {
        printf("Memory Failure\n");
        exit(0);
    }
    
}
//function for deleting a node
void delete_student(Node **root,Student s1)
{
     if(*root==NULL)
     printf("The list is empty\n");
     //if the list is non-empty
     else
     {
         
         Node *temp=*root,*ptr;
         //if the data to be deleted is root itself
         if((temp->s).roll==s1.roll)
         {
             *root=(*root)->next;
             free(temp);
         }
         //otherwise if the root is not to be deleted
         else
         {
             while( (temp->next!=NULL) && (temp->next->s).roll!=s1.roll)
             temp=temp->next;
             
             if(temp->next==NULL)
             {
                 printf("Data not found\n");
                 return;
             }

             else
              {
                ptr=temp->next;
                temp->next=temp->next->next;
                free(ptr);
              }
             }
         }
    }
     

//function for displaying the list
void display_list(Node *root)
{
   int i;
   printf("Printing the list\n");
   if(!root)
   printf("List is empty\n");
   else
   {
       char sub[][10]={"Maths","Phy","Chem","Comp","Bio"};
       Node *temp=root;
       while(temp)
       {
           //print the roll,name and the corresponding marks in the subjects
           printf("%d %s ",temp->s.roll,temp->s.name);
           for(i=0;i<5;i++)
           printf("%s:%d ",sub[i],temp->s.score[i]);
           printf("\n");
           //moving to the next node of the list this is veru very imp else infinite loop
           temp=temp->next;
       }
   }
   
}
//main function of the program
int main()
{
    //we need to add ,delete and display the student's data 
    //for that we need to create a linked list(SLL here) and modify it each time a data 
    //is inserted or deleted;
    int choice;Student s1;
    while(1)
    {
        printf("You have the following choices:\n");
    printf("1.Insert data\n");
    printf("2.Delete data\n");
    printf("3.Display the list\n");
    printf("4.Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
     //using the user choice to call the desired function 
       switch(choice)
       {
           case 1:
                insert_student(&root);
                break;
           case 2:
                 
                 printf("Enter the roll number of the student to deleted\n");
                 scanf("%d",&s1.roll);
                 delete_student(&root,s1);
                 break;
           case 3:
                 display_list(root);
                 break;
           case 4:
                 exit(0);
           case 5:
                printf("Invalid Choice\n");
       }
    }
     return 0;
}