#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



int main()
{
  int i,values[5] = { 98, 56, 100, 2, 25 };
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
  	char* ptr;
  	ptr=(char*)values;
  	char** ptr1=&ptr;
  	printf("%d",*(*ptr1+4));
  	//char** ptr1=&ptr;
  	sleep(1);
  	execv("./c",ptr1);
  }
   else 
   {  
    
   }
}
