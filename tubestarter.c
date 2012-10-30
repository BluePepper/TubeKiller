#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	char process[10];
	char time[4];
	int itime;
	int i;
	pid_t pid = fork();
	if (pid == 0){
		execlp("/Applications/TheTube.app/Contents/MacOS/TheTube", "TheTube",  NULL);
	}else{
		sscanf(argv[1], "%d", &itime);
		sprintf(process, "%d", pid);
		for (i = 0; i < itime; i++){
			sleep(60);
			printf("Sleeping in %d Minutes", itime-i);
		}
		printf("Test");
		execlp("kill", "kill", "-s", "kill", process, NULL);
	}

}