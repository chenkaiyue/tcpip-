int main(int argc,char *argv[])
{
	int sock;
	struct sockaddr_in serv_addr;
	char message[30];
	int str_len;

	if (argc != 3){
		error_handling();
	}

	sock=socket(PF_INET,SOCK_STREAM,0);
	if (sock==-1){
		error_handling();
	}

	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));
	ser_addr.sin_family = AF_INET;

	if(connect(sock,(struct sockaddr*)serv_addr,sizeof(ser_addr))){
		error_handling();
	}

	str_len = read(sock,message,sizeof(message)-1);
	if (str_len == -1)
		error_handling();

	printf("message is %s \n",message);
	close(sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}