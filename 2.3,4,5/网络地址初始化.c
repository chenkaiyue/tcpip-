struct sockaddr_in addr;
addr.sin_family=AF_INET;
char *ip="1.1.1.1";
char *port="21";
memset(&addr,0,sizeof(addr));
addr.sin_addr.s_addr=inet_addr(ip);
addr.sin_port=htons(atoi(port));


struct sockaddr_in addr;
char * server_port="22";
memset(&addr,0,sizeof(addr));
addr.sin_addr.s_addr=htonl(INADDR_ANY);
addr.sin_port=htons(atoi(server_port));
addr.sin_family=AF_INET;


int serv_sock;
serv_sock=socket(PF_INET,SOCK_STREAM,0);
bind(sock,(struct sockaddr *)&addr,sizeof(addr));

