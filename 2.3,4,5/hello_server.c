#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
void error_handling(char *message);

int main(int argc,char *argv[])
{
	int serv_sock;
	int clnt_sock;

	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;

	char message[] = "hello world";

	if (argc != 2){
		exit(1);
	}

	serv_sock = socket(PF_INET,SOCK_STREAM,0);
	if (serv_sock == -1){
		error_handling();
	}
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if (bind(serv_sock,(struct sockaddr*) &serv_addr,sizeof(serv_addr))==-1)
		error_handling();

	if (listen(serv_sock,5)==-1)
		error_handling();

	clnt_addr_size = sizeof(clnt_addr);
	clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_addr,clnt_addr_size);
	if (clnt_sock == -1)
		error_handling();
	write(clnt_sock,message,sizeof(message));
	close(clnt_sock);
	close(serv_sock);
	return 0;
}

void error_handling(char *message){
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}


#define BUF_SIZE 100
int main(int argc, char *argv[])
{
	int serv_sock,clnt_sock;
	struct sockaddr_in serv_addr,clnt_addr;
	struct timeval timeout;
	fd_set reads,cpy_reads;

	socklen_t adr_sz;
	int fd_max,str_len,fd_num,i;
	char buf[BUF_SIZE];


	serv_sock=socket(PF_INET,SOCK_STREAM,0);
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(atoi(argv[1]));
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1){
		error_handling();
	}
	if (listen(serv_sock,5)==-1){
		error_handling();
	}

	FD_ZERO(&reads);
	FD_SET(serv_sock,&reads);
	fd_max = serv_sock;

	while(1){
		cpy_reads = reads;
		timeout.tv_sec=5;
		timeout.tv_usec=5000;

		if ((fd_num=select(fd_max+1,&cpy_reads,0,0,&timeout))==-1)
			break;
		if (fd_num == 0)
			continue;

		for(i=0;i<fd_max+1;i++){
			if (FD_ISSET(i,&cpy_reads))
			{
				if (i == serv_sock){
					adr_sz=sizeof(clnt_addr);
					clnt_sock=accept(serv_sock,(struct sockaddr*)&clnt_addr,&adr_sz);
					FD_SET(clnt_sock,&reads);
					if (fd_max < clnt_sock)
						fd_max = clnt_sock;
					printf("connect from %d",clnt_sock);
				}
				else{
					str_len = read(clnt_sock,buf,BUF_SIZE);
					if (str_len == 0){
						FD_CLR(i,&reads);
						close(i);
						printf("closed client %d \n",i);
					}
					else{
						write(i,buf,str_len);
					}
				}
			}
		}
	}
	close(serv_sock);
	return 0;
}
