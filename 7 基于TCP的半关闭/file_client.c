
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