#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
sem_t x,y;
pthread_t tid;
pthread_t writerthreads[100],readerthreads[100];
int readercount = 0;

void *reader(void* param)
{
    sem_wait(&x);
    readercount++;
    if(readercount==1)
        sem_wait(&y);
    sem_post(&x);
    printf("%d Reader  is inside the critical section \n",readercount);
    usleep(3);
    sem_wait(&x);
    readercount--;
    if(readercount==0)
    {
        sem_post(&y);
    }
    sem_post(&x);
    printf("%d Reader is leaving the critical section \n",readercount+1);
    return NULL;
}

void *writer(void* param)
{
    printf("Writer %d is trying to enter the critical section \n",(*((int *)param)));
    sem_wait(&y);
    printf("Writer %d has entered critical section \n",(*((int *)param)));
    sem_post(&y);
    printf("Writer %d is leaving the critical section\n",(*((int *)param)));
    return NULL;
}

int main()
{
    int num_readers,num_writers,i;
    printf("Enter the number of readers:");
    scanf("%d",&num_readers);
    
    printf("Enter the number of writers:");
    scanf("%d",&num_writers);

    int read_arr[num_readers],write_arr[num_writers];
    for(int i=0;i<num_readers;i++)read_arr[i]=i+1;
	for(int i=0;i<num_writers;i++)write_arr[i]=i+1;
    sem_init(&x,0,1);
    sem_init(&y,0,1);

    //Creating the required number of reader and writer threads 
    for(i=0;i<num_readers;i++)
    pthread_create(&readerthreads[i],NULL,writer,(void *)&read_arr[i]);
    
    for(i=0;i<num_writers;i++)
    pthread_create(&writerthreads[i],NULL,reader,(void *)&write_arr[i]);
        
    
    for(i=0;i<num_readers;i++)
    pthread_join(readerthreads[i],NULL);
    
    for(i=0;i<num_writers;i++)
    pthread_join(writerthreads[i],NULL);

    return 0;
        
}