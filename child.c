#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}

int main(int argc, char* argv[])
{
	printf("in child");
	printf("%d",*(*argv+8));
//	printf("%s",ptr);
 	//printf("%d",getpid());
  	//qsort((int*)argv[1], 5, sizeof(int), cmpfunc);
  //for(i=0;i<5;i++)
//  printf("%d\n",argv[1][i]);			
  	//printf("%d",getppid());
}