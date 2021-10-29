//This is the file for the record maintaining of the students 
//The file uses the various functions like display,search,modify,delete(physical and logical),
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student 
{
    int roll;
    char name[31];
    int score[5];
    int flag;
}student;
int search(char *fn,int k)
{
    FILE *ptr=fopen(fn,"rb");
    int counter=0;
    student s;
    while(fread(&s,sizeof(student),1,ptr)>0 && s.flag==1)
    {
        counter++;
        if(s.roll==k)
        return counter;
    }
    fclose(ptr);
    return 0;
    
}
int checkpresence(int roll_presence,char *fn)
{
   FILE *ptr=fopen(fn,"rb");
   student s;
   while(fread(&s,sizeof(student),1,ptr)>0 && s.flag==1)
   {
      if(roll_presence==s.roll)
      return 1;
   }
   return 0;
}
void physical_deletion(char *fn,int k)
{
  FILE *ptr1;
  FILE *ptr2;
  ptr1=fopen(fn,"rb");
  ptr2=fopen("newfile.txt","wb+");
  student s;
  while(fread(&s,sizeof(student),1,ptr1)>0 && s.flag==1)
  {
      if(s.roll!=k)
      {
          fwrite(&s,sizeof(student),1,ptr2);
      }
  }
  remove(fn);
  rename("newfile.txt",fn);
  fclose(ptr1);
  fclose(ptr2);


}
void logical_deletion(char *fn,int k)
{
    student s;
    FILE *ptr1=fopen(fn,"rb+");
    FILE *ptr2;

    while(fread(&s,sizeof(student),1,ptr1)>0 )
    {
        if(s.roll==k && s.flag==1)
        {
           s.flag=0;
           fseek(ptr1,-1*sizeof(student),SEEK_CUR);
           fwrite(&s,sizeof(student),1,ptr1);
        }
    }
    fclose(ptr1);
}
void deleterecord(char *fn,int k)
{
    FILE *ptr=fopen(fn,"rb");
    if(ptr==NULL)
    {
        printf("File not found\n");
        return;
    }
    printf("Enter 1 for physical deletion and 2 for logical deletion\n");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
              physical_deletion(fn,k);
              break;
        case 2:
              logical_deletion(fn,k);
              break;
        default:
             printf("invalid choice");
    }

    fclose(ptr);

}
void modifyrecord(char *fn,int k)
{
    FILE *ptr,*ptrtemp=fopen(fn,"rb");int i;
    
    ptr=fopen(fn,"rb+");
    student s;
    int temp;
    temp=checkpresence(k,fn);
    if(temp==0)
    {
        printf("Data is not found\n");
        return;
    }
    else
    {
       /* offset=(temp-1)*sizeof(student);
        fseek(ptr,offset,0);
        fread(&s,sizeof(student),1,ptr);
        printf("Enter the new name:\n");
        scanf("%s",s.name);
        printf("Enter the new scores\n");
        for(i=0;i<5;i++)
        scanf("%d",&s.score[i]);
        fwrite(&s,sizeof(student),1,ptr);*/
        while(fread(&s,sizeof(student),1,ptr)>0 && s.flag)
        {
            if(s.roll==k)
            {
                break;
            }
        }
        fseek(ptr,-1*sizeof(student),SEEK_CUR);
        printf("Enter the new name:\n");
        scanf("%s",s.name);
        printf("Enter the new scores\n");
        for(i=0;i<5;i++)
        scanf("%d",&s.score[i]);
        fwrite(&s,sizeof(student),1,ptr);

    }
    fclose(ptr);
    

}
void addrecord(char *fn)
{
    FILE *ptr;
    int i;
    student s;

    ptr=fopen(fn,"ab+");
    printf("Enter the roll\n");
    scanf("%d",&s.roll);
    printf("Enter the name of the student\n");
    scanf("%s",s.name);
    printf("Enter the score in the five subjects\n");
    for(i=0;i<5;i++)
     scanf("%d",&s.score[i]);
    if(checkpresence(s.roll,fn))
    {
        printf("Please enter unique roll number as it is already there in the list\n");
        return;
    }
    else
    {
        s.flag=1;
        fwrite(&s,sizeof(student),1,ptr);
    }
    fclose(ptr);
    

}
void displayrecord(char *fn)
{
    FILE *ptr=fopen(fn,"rb");
    int i;
    student s;
    if(ptr==NULL)
    {
        printf("file not found\n");
        return;
    }
    while(fread(&s,sizeof(student),1,ptr)>0 && s.flag==1)
    {
       printf("Roll:%d ",s.roll);
       printf("Name:%s ",s.name);
       for(i=0;i<5;i++)
       {
           printf("Score[%d]:%d ",i+1,s.score[i]);
       }
       printf("\n");
    }
    fclose(ptr);


}
void display_against(char *fn,int temp)
{
    student s;int i;
    FILE *ptr=fopen(fn,"rb");
    if(ptr==NULL)
    {
        printf("file not found\n");
        return;
    }
    while(fread(&s,sizeof(student),1,ptr)>0 && s.roll==temp)
    {
       
            printf("Roll:%d Name:%s",s.roll,s.name);
            for(i=0;i<5;i++)
            {
                printf("Score[%d]:%d ",i+1,s.score[i]);
            }
            printf("\n");
            break;
        
    }
    fclose(ptr);
}
int main() 
{
    char fn[31];
    int i,k;
    
    strcpy(fn,"student.txt");
    while(1)
    {
      printf("1.addrecord\n");
      printf("2.search\n");
      printf("3.modifyrecord\n");
      printf("4.deleterecord\n");
      printf("5.display record\n");
      printf("6.exit\n");
      int choice;
      printf("Enter your choice\n");
      scanf("%d",&choice);
      switch(choice)
      {
          case 1:
                 addrecord(fn);
                 break;
          case 2:
                
                  printf("Enter the roll number to be searched\n");
                 int temp;
                 scanf("%d",&temp);
                 if(checkpresence(temp,fn))
                 {
                     printf("Yes the value is present \n");
                     display_against(fn,temp);
                 }
                 else
                 {
                     printf("No the data is not present in the record\n");
                 }
                 
                 break;
          case 3:
                //int k;
               
                printf("Enter the roll number to be modified\n");
                scanf("%d",&k);
                modifyrecord(fn,k);
                break;
          case 4:
                //int k;
                printf("Enter the roll number to be deleted\n");
                scanf("%d",&k);
                deleterecord(fn,k);
                break;
          case 5:
               
                displayrecord(fn);
                break;
          case 6:
                exit(0);

      }
    }
    return 0;
}