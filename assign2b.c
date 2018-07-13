#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
static int myCompare (const void * a, const void * b)
{
    return strcmp (*(const char **) a, *(const char **) b);
}
int main()
{
  int i;
  char* values[5];

  for( i=0;i<5;i++)
  {
  	values[i]=(char*)malloc(sizeof(char)*10);
  	scanf("%s",values[i]);
  }

  pid_t cpid;
  char buf;

  cpid = fork();
  if (cpid == -1)
  {
  	perror("fork");
    exit(EXIT_FAILURE);
  }
  if (cpid > 0) 
  {
  	wait(NULL);
  	qsort (values,5,sizeof (const char *), myCompare);            
  	
  }
  else 
  { 
  	sleep(1);
  	execv("./c",values);  		
  }
}
