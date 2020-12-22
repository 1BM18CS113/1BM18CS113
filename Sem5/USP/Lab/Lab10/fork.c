#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int pid;
	
	printf("Before");
	pid = fork();
	if(pid>0){
		sleep(3);
		printf("parent --PID %d PPID %d, child: %d\n", getpid(), getppid(), pid);
	}
	else if(pid == 0){
		printf("child pid: %d, ppid: %d \n", getpid(), getppid());
	}
	else{
		printf("Fork Error");
		exit(1);
	}
	printf("Both process continue");
	
	exit(0);
}
