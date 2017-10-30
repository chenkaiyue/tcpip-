#define BUF_SIZE 30
int main(int argc,cahr *argv[])
{
	int serv_sock;
	char message[BUF_SIZE];
	int str_len;
	socklen_t clnt_addr_sz;
	struct sockaddr_in serv_addr,clnt_addr;

	serv_sock=socket(PF_INET,SOCK_DGRAM,0);
	if(serv_sock==-1)
		error_handling();

	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(atoi(argv[1]));

	if(bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)
		error_handling();

	while(1){
		clnt_addr_sz=sizeof(clnt_addr);
		str_len = recvfrom(serv_sock,message,BUF_SIZE,0,(struct sockaddr*)&clnt_addr,&clnt_addr_sz);
		sendto(serv_sock,message,str_len,(struct sockaddr*)&clnt_addr,clnt_addr_sz);
	}
	close(serv_sock);
	return 0;
}



