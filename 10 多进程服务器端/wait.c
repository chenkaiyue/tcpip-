#include <sys/wait.h>

int main(int argc,char *argv[])
{
	int status;
	pid_t pid=fork();

	if (pid == 0)
		return 3;
	else{
		printf('child pid: %d',pid);
		pid=fork();
		if (pid==0){
			exit(7);
		}
		else{
			printf("child pid: %d",pid);
			wait(&status);
			if (WIFEXITED(status))
				printf("child send :%d",WEXITSTATUS(status));

			wait(&status);
			if(WIFEXITED(status))
				printf("child send %d",WEXITSTATUS(status));

			sleep(30);
		}

	}
}









