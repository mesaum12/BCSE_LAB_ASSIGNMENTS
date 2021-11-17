#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main() {


   char pipe1writemessage11[3][100];
   char pipe2writemessage11[3][100];

   //take the text file for reading the data between the caller and the receiver 
   FILE *ptr=fopen("Conversation.txt","r");
   if(ptr==NULL)
   {
       printf("The file couldn't be opened !");
       exit(0);
   }
   
   char line[100];
   int flag=1;
   int count1=0,count2=0;

   while (fgets(line, sizeof(line), ptr)) {
     if(flag)
     {
         strcpy(pipe1writemessage11[count1],line);
         //printf("%s\n",pipe1writemessage11[count1]);
         count1++;
     }
     else{
          strcpy(pipe2writemessage11[count2],line);
          //printf("%s\n",pipe2writemessage11[count2]);
          count2++;
     }
     flag=1-flag;
     
   }

   int current_count=0;
   while(current_count<3)
   {
       //for each conversation take two pipes 
       int pipefds1[2], pipefds2[2];
       int returnstatus1, returnstatus2;
       int pid;

       char readmessage[100];

       returnstatus1 = pipe(pipefds1);
       if (returnstatus1 == -1) {
       printf("Unable to create pipe 1 \n");
       return 1;
       }

       returnstatus2 = pipe(pipefds2);
       if (returnstatus2 == -1) {
       printf("Unable to create pipe 2 \n");
       return 1;
       }

       pid = fork();//Fork the process to create child processes 
   
     // Parent process 
     if (pid != 0) {
      close(pipefds1[0]); // Close the unwanted pipe1 read side
      close(pipefds2[1]); // Close the unwanted pipe2 write side
      //printf("In Parent: Writing to pipe 1  %s\n", pipe1writemessage11[current_count]);
      write(pipefds1[1], pipe1writemessage11[current_count], sizeof(pipe1writemessage11[current_count]));
      read(pipefds2[0], readmessage, sizeof(readmessage));
    //   printf("In Parent: Reading from pipe 2 – Message is %s\n", readmessage);
      printf("%s\n", readmessage);
     } 
   else { //child process
      close(pipefds1[1]); // Close the unwanted pipe1 write side
      close(pipefds2[0]); // Close the unwanted pipe2 read side
      read(pipefds1[0], readmessage, sizeof(readmessage));
    //   printf("In Child: Reading from pipe 1 – Message is %s\n", readmessage);
      printf("%s\n", readmessage);
    //   printf("In Child: Writing to pipe 2 – Message is %s\n", pipe2writemessage11[current_count]);
      write(pipefds2[1], pipe2writemessage11[current_count], sizeof(pipe2writemessage11[current_count]));
   }
   current_count++;


   }
   return 0;
}