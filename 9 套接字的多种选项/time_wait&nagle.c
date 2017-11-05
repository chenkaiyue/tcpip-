int optlen;
int option;
optlen=sizeof(option);
option=1;
setsockopt(serv_sock,SOL_SOCKET,SO_REUSEADDR,(void *)&option,optlen);


int opt_val=1;
setsockopt(sock,IPPROTO_TCP,TCP_NODELAY,(void *)&opt_val,sizeof(opt_val));
int opt_len=sizeof(opt_val);
getsockopt(sock,IPPROTO_TCP,TCP_NODELAY,(void *)&opt_val,&opt_len);