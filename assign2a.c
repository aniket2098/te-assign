#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main()
{
	int i,values[] = { 88, 56, 100, 2, 25 };
  pid_t cpid;
  char buf;
  cpid = fork();
  if (cpid == -1)
  {
  	perror("fork");
    exit(EXIT_FAILURE);
  }

  if (cpid == 0) 
  {   
  	printf("%d",getpid());	
    qsort(values, 5, sizeof(int), cmpfunc);
    for(i=0;i<5;i++)
    	printf("%d\n",values[i]);			
		printf("%d",getppid());
   } 
   else 
   {  
 			qsort(values, 5, sizeof(int), cmpfunc);
      for(i=0;i<5;i++)
      	printf("%d\n",values[i]);
				wait(NULL);
				sleep(10);
   }
}
