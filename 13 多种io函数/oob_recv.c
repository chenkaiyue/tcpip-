
int main(){
	struct sigaction act;
	act.sa_handler = urg_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_addr,&clnt_addr_sz);

	fcntl(clnt_sock,F_SETOWN,getpid())
	state = sigaction(SIGURG,&act,0);
	while ((str_len = recv(clnt_sock,buf,BUF_SIZE,0))!=0)
	{
		if (str_len == -1)
			continue
		buf[str_len] = 0;
		puts(buf);
	}
	close(serv_sock);
	close(clnt_sock);
	return 0;

}


void urg_handler(int signal)
{
	int str_len;
	char buf[BUF_SIZE];
	str_len = recv(clnt_sock,buf,sizeof(buf)-1,MSG_OOB);
	buf[str_len] = 0;
	printf("%s",buf);
}