
#define BUF_SIZE 30
int main(int argc,char *argv[])
{
	int sock,str_len;
	char message[BUF_SIZE];
	socklen_t adr_sz;

	struct sockaddr_in serv_addr,from_addr;

	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	while(1){
		fputs("input",stdout);
		fgets(message,sizeof(message),stdin);
		if (!strcmp(message,'q\n'))
			break;
		sendto(sock,message,strlen(message),0,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
		adr_sz = sizeof(from_addr);
		str_len = recvfrom(sock,message,BUF_SIZE,0,(struct sockaddr*)&from_addr,&adr_sz);
		message[str_len]=0;
		printf("%s",message);
	}
	close(sock);
	return 0;
}