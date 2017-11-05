int main(int argc,char *argv[])
{
	int i;
	struct hostent *host;
	host=gethostbyname(argv[1]);
	printf("%s",host->h_name);
	for (i=0;host->h_aliases[i];i++){
		printf("%s\n",host->h_aliases[i]);
	}
	printf("address type %s\n",(host->addrtype==AF_INET)?"AF_INET":"AF_INET6");
	for (i=0;host->h_addr_list[i];i++)
	{
		printf("ip address %s\n",inet_ntoa(*(struct in_addr*)host->h_addr_list[i]));
	}
	return 0;
}


struct hostent * host;
struct sockaddr_in addr;
memset(&addr,0,sizeof(addr));
addr.sin_addr.s_addr=inet_addr(argv[1]);
host=gethostbyaddr((char*)&addr.sin_addr,4,AF_INET);
