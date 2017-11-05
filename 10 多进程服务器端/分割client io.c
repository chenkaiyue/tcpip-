
int main()
{
	if(connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)
		error_handling();
	pid=fork()
	if (pid==0)
		write_routine(sock,buf);
	else
		read_routine(sock,buf);
	close(sock);
	return 0;
}
if(connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)
	error_handling();
pid=fork()
if (pid==0)
	write_routine(sock,buf);
else
	read_routine(sock,buf);
close(sock);
return 0


void read_routine(int sock,char *buf)
{
	while(1)
	{
		int str_len=read(sock,buf,BUF_SIZE);
		if (str_len==0)
			return;

		buf[str_len]=0;
		printf("%s",buf);
	}
}


void write_routine(int sock,char *buf)
{
	while(1)
	{
		fgets(buf,BUF_SIZE,stdin);
		if (!strcmp(buf,'q\n')){
			shutdown(sock,SHUT_WR);
			return ;
		}
		write(sock,buf,strlen(buf));
	}
}
