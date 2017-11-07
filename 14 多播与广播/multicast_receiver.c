

int main()
{
	int recv_sock;
	recv_sock = socket(PF_INET,SOCK_DGRAM,0);
	sockaddr_in adr;
	char buf[BUF_SIZE];
	
	struct ip_mreq join_adr;

	memset(&adr,0,sizeof(adr));
	adr.sin_family=AF_INET；
	adr.sin_port = htons(argv[2]);
	adr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(recv_sock,(struct sockaddr*)&adr,sizeof(&adr))==-1){
		error_handling();
	}
	
	join_adr.imr_multiaddr.s_addr = inet_addr(argv[1]);
	join_adr.imr_inerface.s_addr = htonl(INADDR_ANY);


	setsockopt(recv_sock,IPPROTO_IP,IP_ADD_MEMBERSHIP,(void*)&join_adr,sizeof(join_adr));

	while (1)
	{
		int str_len = recvfrom(recv_sock,buf,BUF_SIZE,0,NULL,0);
		if (str_len < 0)
			break;
		buf[str_len] = 0;
		fputs(buf,stdout);
	}

	close(recv_sock);
	return 0;
}