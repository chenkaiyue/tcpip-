

int main(int argc ,char *argv[])
{
	int serv_sock,clnt_sock;
	struct sockaddr_in serv_addr,clnt_addr;
	int fds[2];

	pid_t pid;
	struct sigaction act;
	socklen_t adr_sz;
	int strlen,state;
	char buf[BUF_SIZE];

	act.sa_handler=read_childproc;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	state = sigaction(SIGCHID,&act,0);

	serv_sock=socket(PF_INET,SOCK_STREAM,0);
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port=htons(argv[1]);

	if (bind(serv_sock,&serv_addr,sizeof(serv_addr))==-1)
		error_handling();

	if (listen(serv_sock,5)==-1)
		error_handling();

	pipe(fds);
	pid=fork();
	if (pid==0){
		FILE *fp = fopen("data.dt","wt");
		char msgbuf[BUF_SIZE];
		int i,len;
		for (i=0;i<10;i++){
			len=read(fds[0],msgbuf,BUF_SIZE);
			fwrite((void*)msgbuf,1,len,fp);
		}
		fclose(fp);
		return 0;
	}


	while(1)
	{
		adr_sz = sizeof(clnt_addr);
		clnt_sock=accept(serv_sock,&clnt_addr,&adr_sz);
		if(clnt_sock==-1)
			continue;
		else
			printf("new client connected\n", );

		pid=fork();
		if (pid==0)
		{
			close(serv_sock);
			while(str_len=read(clnt_sock,buf,BUF_SIZE)){
				write(clnt_sock,buf,str_len);
				write(fds[1],buf,str_len);
			}
			close(clnt_sock);
			return 0;
		}
		else
			close(clnt_sock);
	}
	close(serv_sock);
	return 0;
}


void read_childproc(int sig)
{
	int status;
	pid_t pid=waitpid(-1,&status,WNOHANG);
	if (WIFEXITED(status)){
		printf("remove pid:%d",pid);
		printf("child return :%d",WEXITSTATUS(status));
	}
}
