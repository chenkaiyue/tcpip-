int main()
{
	int sock;
	int send_buf=1024*3;
	int state;
	socklen_t len;

	sock=socket(PF_INET,SOCK_STREAM,0);
	state=setsockopt(sock,SOL_SOCKET,SO_SNDBUF,(void *)&send_buf,sizeof(send_buf));
	


	len=sizeof(send_buf);
	state=getsockope(sock,SOL_SOCKET,SO_SDNBUF,(void *)&send_buf,&len);

	printf("output buffer size: %d",send_buf);
	return 0;

}


