#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int search(char* arr[],char key[])
{
	int i;
	for(i=0;i<5;i++)
	{
		if(strcmp(arr[i],key)==0)
			return 1;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	int i;
	char key[10];
	printf("in child");
	for(i=0;i<5;i++)
 		printf("%s\n",argv[i]);	
 	printf("Enter no. to be searched:: ");
 	scanf("%s",key);
 	if(search(argv,key)==1)
 		printf("Found!\n");
 	else
 		printf("Not found!\n");


}
