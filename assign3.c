#include<stdio.h>

#include<unistd.h>

#include<stdlib.h>

#include<pthread.h>

#include<string.h>

void *thread_function(void *arg);
int main(){
int res,i;
pthread_t a_thread;
void *thread_result;
int a[10][10],i,j,r1,c1,r2,c2;
printf("Enter no. of rows: ",&r1);
printf("Enter no. of rows: ",&c1);
for(i=0;i<r1;i++)
{
	for(j=0;j<c1;j++)
	{
		scanf("%d",&a[i][j]);
	}
}

res = pthread_create(&a_thread, NULL, thread_function,(void*)a);
if (res != 0) {
perror("Thread creation failed");
exit(EXIT_FAILURE);
}
printf("Waiting for thread to finish...\n");
res = pthread_join(a_thread, &thread_result);
if (res != 0) {
perror("Thread join failed");
exit(EXIT_FAILURE);
}
printf("Thread joined, it returned %d\n", *(int*)thread_result);
exit(EXIT_SUCCESS);
}
void *thread_function(void *a) {
int* c=(int*)a;
printf("thread_function is running. Argument was %d\n", c[1]);
sleep(3);
c[0]=c[0]+c[1];
pthread_exit((void*)(c));
}