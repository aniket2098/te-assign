#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
       
 int main(int argc, char *argv[])
       {
          int pipefd[2],pipefd1[2];
          pid_t cpid;
          char buf[10];
          char buff[1000];
					FILE *fp;
					char ch;
					int i=0;
          if (argc != 2) {
            fprintf(stderr, "Usage: %s <string>\n", argv[1]);
            exit(EXIT_FAILURE);
           }

           if (pipe(pipefd) == -1 || pipe(pipefd1) == -1) {
               perror("pipe");
               exit(EXIT_FAILURE);
           }

           cpid = fork();
           if (cpid == -1) {
               perror("fork");
               exit(EXIT_FAILURE);
           }

           if (cpid == 0) 
           {  
		       		close(pipefd[1]);        
		        	while (read(pipefd[0], &buf[i], 1) > 0) 
		        	i++;		     
							buf[i]='\0';	
		        	fp=fopen(buf,"r");
		       	  i=0;
		 					while((ch = fgetc(fp)) != EOF)
		    				buff[i++]=ch;
		        	write(pipefd1[1], buff, strlen(buff));
		        	close(pipefd1[0]);
		        	close(pipefd[1]);
		       		_exit(EXIT_SUCCESS);
           } 
           else 
           {           
               close(pipefd[0]);          
               write(pipefd[1], argv[1], strlen(argv[1]));
               close(pipefd[1]);          
               wait(NULL);                  
           		 close(pipefd1[1]);
               while (read(pipefd1[0], &buf[0], 1) > 0) 
               		write(STDOUT_FILENO, &buf[0], 1);           
               close(pipefd1[0]);
               exit(EXIT_SUCCESS);
           }           
       }
