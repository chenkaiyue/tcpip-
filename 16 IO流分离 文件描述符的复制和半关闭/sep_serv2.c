FILE * readfp = fdopen(clnt_sock,"r");
FILE * writefp = fdopne(dup(clnt_sock),"w");
fputs("hello",writefp);
fflush(writefp);

shutdown(fileno(writefp),SHUT_WR);//半关闭
fclose(writefp);

fgets(buf,sizeof(buf),readfp);
fclose(readfp);


int main(int argc, char const *argv[])
{
	int serv_sock,clnt_sock;
	FILE * readfp;
	FILE * writefp;

	struct sockaddr_in serv_addr,clnt_adr;
	socklen_t clnt_adr_sz;
	char buf[BUF_SIZE]={0,};

	serv_sock=socket(PF_INET,SOCK_STREAM,0);
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	listen(serv_sock,5);
	clnt_adr_sz = sizeof(clnt_adr);
	clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_adr,&clnt_adr_sz);

	readfp = fdopen(clnt_sock,"r");
	writefp = fdopen(dup(clnt_sock),"w");

	fputs("from server hi\n",writefp);
	fflush(writefp);

	shutdown(fileno(writefp),SHUT_WR); //半关闭
	fclose(writefp);

	fgets(buf,sizeof(buf),readfp);
	fclose(readfp);

	return 0;
}