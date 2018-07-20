#include<stdio.h>

#include<unistd.h>

#include<stdlib.h>

#include<pthread.h>

#include<string.h>

struct mat
{
	void* a;
	void* b;
	int r;
};

void *thread_function(void*);

int main()
{
	int res;
	pthread_t a_thread[100];
	void *thread_result;
	int a[10][10],b[10][10],c[10][10],i,j,r1,c1,r2,c2,no;
	printf("Enter no. of rows: ");
	scanf("%d",&r1);
	printf("Enter no. of columns: ");
	scanf("%d",&c1);
	printf("Enter no. of rows: ");
	scanf("%d",&r2);
	printf("Enter no. of columns: ");
	scanf("%d",&c2);
	no=c2 * r2;
	printf("Enter matrix 1: ");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Matrix 1::\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("Enter matrix 2:");

	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			scanf("%d",&b[j][i]);
		}
	}

	printf("Matrix 2::\n");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%d\t",b[j][i]);
		}
		printf("\n");
	}
	struct mat* a1=malloc(sizeof(struct mat));
	for(i = 0; i < r1; i++) {

		a1->a=(void*)a[i];
		a1->r=c1;
		for(j=0;j<c2;j++)
		{
			a1->b=(void*)b[j];
			res = pthread_create(&(a_thread[i*r1+j]), NULL, thread_function,(void*)a1);
			if (res != 0) {
			perror("Thread creation failed");
			exit(EXIT_FAILURE);
		}
			sleep(1);
	}
	}
		printf("Waiting for thread to finish...\n");
	for(i = 0; i < r1; i++)
	{
		for(j=0 ;j<c2;j++)
		{
		res = pthread_join(a_thread[i*r1+j], &thread_result);
		if (res == 0) {
			// printf("Picked up a thread\n");
			c[i][j]=*(int*)thread_result;
			// printf("%d",*(int*)thread_result);
		}
		else {
			perror("pthread_join failed");
		}
	}
	}
	printf("Resultant::\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
}


void *thread_function(void* a1) 
{
	struct mat* a2=(struct mat*)a1; 
	int* c=(int*)a2->a;
	int* d=(int*)a2->b;
	int* sum=malloc(sizeof(int));
	*sum=0;
	int i;
	for(i=0;i<a2->r;i++)
	{
		*sum+=(c[i]*d[i]);
	}
	pthread_exit((void*)(sum));
}
