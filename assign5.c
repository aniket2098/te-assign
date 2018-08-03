#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#define buffer_size 10

sem_t wrt,mutex;
static int buffer[buffer_size],data=0,front=0,rc=0,i;
void init()
{
	sem_init(&wrt,0,1);
	sem_init(&mutex,0,1);
}

void* writer(void* p)
{
	int i;
	int p1=*((int*)p);
	while(1)
	{
		printf("Writer %d wants to write\n",p1);
		sem_wait(&wrt);
		buffer[data]=rand()%10;
		data++;
		data=data%10;
		printf("Queue: ");
		for(i=0;i<10;i++)
			printf("%d ",buffer[i]);
		printf("\n");
		sleep(rand()%5);
		sem_post(&wrt);
		printf("Writer %d has writen\n",p1);
	}	
}

void* reader(void* p)
{
	int i;
	int p1=*((int*)p);
	while(1)
	{
		printf("Reader %d wants to read\n",p1);
		sem_wait(&mutex);
		rc++;
		if(rc==1)
		{
			sem_wait(&wrt);
		}
		sem_post(&mutex);
		printf("Reader %d is reading\n",p1);
		printf("Queue: ");
		for(i=0;i<10;i++)
			printf("%d ",buffer[i]);
		printf("\n");
		sleep(rand()%5);
		sem_wait(&mutex);
		rc--;
		if(rc==0)
			sem_post(&wrt);
		sem_post(&mutex);
		printf("Reader %d has read\n",p1);
	}	
}

int main()
{
	init();
	pthread_t pth[10],cth[10];
	int i;
	for(i=0;i<4;i++)
	pthread_create(&pth[i],NULL,writer,(void*)&i);

	int k;
	for(k=0;k<5;k++)
	pthread_create(&cth[k],NULL,reader,(void*)&k);

	for(i=0;i<4;i++)
	pthread_join(pth[i],NULL);

	for(k=0;k<5;k++)
	pthread_join(cth[k],NULL);
}