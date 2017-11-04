#define BUF_SIZE 30
int main(int argc,char *argv[])
{
	int serv_sd,clnt_sd;
	FILE *fp;
	char buf[BUF_SIZE];
	int read_cnt;

	struct sockaddr_in ser_addr,clnt_addr;
	socklen_t clnt_addr_sz;

	fp = fopen("file_server.c","rb");
	serv_sd=socket(PF_INET,SOCK_STREAM,0);

	memset(&ser_addr,0,sizeof(ser_addr));
	ser_addr.sin_family=AF_INET;
	ser_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	ser_addr.sin_port=htons(atoi(argv[1]));

	bind(serv_sd,(struct sockaddr*)ser_addr,sizeof(ser_addr));
	listen(serv_sd,5);

	clnt_addr_sz = sizeof(clnt_addr);
	clnt_sd=accept(serv_sd,(struct sockaddr*)&clnt_addr,&clnt_addr_sz);

	while(1)
	{
		read_cnt=fread((void*)buf,1,BUF_SIZE,fp);
		if (read_cnt < BUF_SIZE){
			write(clnt_sd,buf,read_cnt);
			break;
		}
		write(clnt_sd,buf,BUF_SIZE);
	}

	shutdown(clnt_sd,SHUT_WR);
	read(clnt_sd,buf,BUF_SIZE);
	printf("message from client %s",buf);

	fclose(fp);
	close(clnt_sd);
	close(serv_sd);
	return 0;
}




int main(int argc,char * argv[])
{
	int sd;
	FILE *fp;

	char buf[BUF_SIZE];
	int read_cnt;
	struct sockaddr_in ser_addr;
	fp=fopen("receive.dat","wb");
	sd=socket(PF_INET,SOCK_STREAM,0);

	memset(&ser_addr,0,sizeof(ser_addr));
	ser_addr.sin_family=AF_INET;
	ser_addr.sin_addr.s_addr=inet_addr(argv[1]);
	ser_addr.sin_port=htons(atoi(argv[2]));

	connect(sd,(struct sockaddr*)&ser_addr,sizeof(ser_addr));

	while(read_cnt=read(sd,buf,BUF_SIZE)!=0)
	{
		fwrite((void*)buf,1,read_cnt,fp);
	}

	puts("received data");
	write(sd,"thank you",10);
	
	fclose(fp);
	close(sd);
	return 0;
}