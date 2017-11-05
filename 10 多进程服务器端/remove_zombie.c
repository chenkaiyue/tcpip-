void read_childproc(int sig)
{
	int status;
	pid_t pid=waitpid(-1,&status,WNOHANG);
	if (WIFEXITED(status))
	{
		printf("remove pid:%d",pid);
		printf("child send:%d",WEXITSTATUS(status));
	}
}

int main()
{
	pid_t pid;
	struct sigaction act;
	act.sa_handler=read_childproc;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	sigaction(SIGCHLD,&act,0);

	pid=fork();
	if(pid==0)
	{
		sleep(10);
		return 12;
	}
	else{
		pid=fork();
		if (pid==0){
			sleep(10);
			exit(24);
		}
		else{
			int i;
			for(i=0;i<5;i++){
				puts("wait");
				sleep(5);
			}
		}
	}
	return 0;
}


