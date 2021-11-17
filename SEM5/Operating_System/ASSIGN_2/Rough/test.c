// C Program for Message Queue (Reader Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <string.h>
#include<unistd.h>
#include <sys/msg.h>
#define MAX 100
// structure for message queue
struct mesg_buffer {
	long mesg_type;
	char mesg_text[100];
} message;
struct query_buffer {
	long sender;
	char mesg_text[100];
} query;
int main()
{
	key_t key,key2;
	int msgid,msgid2;
	int recid=1;
    pid_t pid2=fork();
	if(pid2==0)
	recid=2;
	int pr=recid;
	pid_t pid3=fork();
	if(pid3==0)
	{
	   if(pr==1)
	    recid=3;
	   else
	     recid=4;
	}
	
	int ps=0;
	key = ftok("mesfl", 75);
	key2 = ftok("msf2", 76);
	
	// msgget creates a message queue
	// and returns identifier
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgid2 = msgget(key2, 0666 | IPC_CREAT);
	while(1)
	{
	
       msgrcv(msgid, &message, sizeof(message), 1, 0);
	   if(recid==1)
	   {
            FILE *fptr ; 
            fptr = fopen("temp.txt", "w");
            fprintf(fptr, "%d",0);
            fclose(fptr);
	   }
	  if(strcmp(message.mesg_text,"Over\n")==0)
	  break;

	 // display the message
	  printf("For farmer %d ,the broadcasted msg is : %s",recid,
					message.mesg_text);
	  ps+=1;
	  sleep(1);
	
	  while(1)
	  {
		FILE *fptr ; 
		fptr = fopen("temp.txt", "r");
		int c=-2;
		fscanf(fptr, "%d",&c);
		fclose(fptr);
		if(c==recid-1)
		break;
	  }
	
	sleep(1);
	printf("Id number of the farmer %d -> What is your query regarding ?? : ",recid);
	fgets(query.mesg_text,MAX,stdin);
	query.sender=recid;
	msgsnd(msgid2, &query, sizeof(query), 0);
	
	FILE *fptr ; 

    fptr = fopen("temp.txt","w");
	fprintf(fptr, "%d",recid);
	fclose(fptr);
	
    }

	// to destroy the message queue
	msgctl(msgid, IPC_RMID, NULL);
	msgctl(msgid2, IPC_RMID,NULL);

	return 0;
}

