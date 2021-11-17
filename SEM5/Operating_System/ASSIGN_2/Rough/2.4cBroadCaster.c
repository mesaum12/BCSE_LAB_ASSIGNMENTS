// C Program for Message Queue (Writer Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#include<unistd.h>
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

	// ftok to generate unique key
	key = ftok("mesfl", 75);
	key2 = ftok("msf2", 76);
	
	// msgget creates a message queue
	// and returns identifier
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgid2 = msgget(key2, 0666 | IPC_CREAT);

	msgctl(msgid, IPC_RMID, NULL);
	msgctl(msgid2, IPC_RMID,NULL);

	
	key = ftok("mesfl", 75);
	key2 = ftok("msf2", 76);
	
	// msgget creates a message queue
	// and returns identifier
	msgid = msgget(key, 0666 | IPC_CREAT);
	msgid2 = msgget(key2, 0666 | IPC_CREAT);
	
	message.mesg_type=1;
	while(1)
	{
         printf("Enter the message to be broadcasted:");
         fgets(message.mesg_text,MAX,stdin);
	 if(strcmp(message.mesg_text,"Over\n")==0)
	 break;
	 
        // msgsnd to send message
	for(int i=0;i<6;i++)
	msgsnd(msgid, &message, sizeof(message), 0);

	printf("Broadcasted message : %s", message.mesg_text);

	int count=0;
	while(count<6)
	{
	  count+=1;
          msgrcv(msgid2, &query, sizeof(query),count, 0);
	  printf("Farmer %ld is connected : %s", query.sender,query.mesg_text);
	  sleep(1);	
	}
	
	}
	return 0;
}

