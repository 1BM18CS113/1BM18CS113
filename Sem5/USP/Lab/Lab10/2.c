#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	pid_t pidChild;

	char *prgName="/bin/cat";
	char *arg1="demo";
	int status;

	pidChild=fork();
	if(pidChild == 0)
	{
		printf("\nChild Process Created!\n");
		printf("Executing in child process(execl): \n");
		execl(prgName,prgName,arg1,NULL);
		
	}

	else if(pidChild <0)	
	{
		fprintf(stderr,"%s","Child process creation failed");
		return 1;
	}
	
	waitpid(pidChild,&status,0);
	printf("waitpid return=%d\n",status);

	if (WIFEXITED(status) )
	{
		int exit_status = WIFEXITED(status);
		printf("WIFEXITED(status)=%d\n",exit_status );
	}

	return 0;
}