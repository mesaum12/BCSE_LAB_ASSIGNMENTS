#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include <pthread.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
char msgToPrint[50]="";
int visited[100];
void *myThreadFun(void *vargp)
{
	sleep(1);
    int id;
    while(1)
    {
       id=rand()%100;
       if(visited[id]==0)
       {
           visited[id]=1;
           break;
       }
    }
    printf("Id: %d Message: %s\n",id,msgToPrint);
}
void recv_msg(char *readmessage)
{
    strcpy(msgToPrint,readmessage);
    int number_of_listeners=10;
    pthread_t thread_id[number_of_listeners];
    for(int i=0;i<number_of_listeners;i++)
	pthread_create(&thread_id[i], NULL, myThreadFun, NULL);
    for(int i=0;i<number_of_listeners;i++)
	pthread_join(thread_id[i], NULL);
	
}
int main() {


   char pipeWriteMsg[1][100];
   //take the text file for reading the data between the caller and the receiver 
   FILE *ptr=fopen("Weather.txt","r");
   if(ptr==NULL)
   {
       printf("The file couldn't be opened !");
       exit(0);
   }
   
   char line[100];
   int line_num=0;
   

   while (fgets(line, sizeof(line), ptr)) 
   strcpy(pipeWriteMsg[line_num++],line);
        
    int pipefds1[2];
    int returnstatus1;
    int pid;

    char readmessage[100];

    returnstatus1 = pipe(pipefds1);

    if (returnstatus1 == -1) {
    printf("Unable to create pipe 1 \n");
    return 1;
    }

    pid = fork();//Fork the process to create child processes 
   
     // Parent process 
    if (pid != 0) {
      close(pipefds1[0]); // Close the unwanted pipe1 read side
      write(pipefds1[1], pipeWriteMsg[0], sizeof(pipeWriteMsg[0]));
    } 
    else { //child process
      
      close(pipefds1[1]); // Close the unwanted pipe1 write side
      read(pipefds1[0], readmessage, sizeof(readmessage));
      recv_msg(readmessage);
      
    }
    return 0;
}