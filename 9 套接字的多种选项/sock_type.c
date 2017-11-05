int main()
{
	int tcp_sock,udp_sock;
	int sock_type;
	socklen_t optlen;
	int state;

	optlen=sizeof(sock_type);
	tcp_sock=socket(PF_INET,SOCK_STREAM,0);
	udp_sock=socket(PF_INET,SOCK_DGRAM,0);

	state=getsockopt(tcp_sock,SOL_SOCKET,SO_TYPE,(void *)&sock_type,&optlen);
	printf("%d",sock_type);
}