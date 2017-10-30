#define BUF_SIZE 1024
#define RLT_SIZE 4
#define OPSZ 4
void error_handling(char *message);

int main(int argc,char *argv[])
{
	int sock;
	int i,opnd_cnt,result;
	struct sockaddr_in serv_addr;
	char opmsg[BUF_SIZE];
	if (argc!=3)
		error_handling();
	sock = socket(PF_INET,SOCK_STREAM,0);
	if (sock == -1)
		error_handling();

	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_famliy=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port=htons(atoi(argv[2]));

	if(connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)
		error_handling();
	else
		puts("connected");

	fputs("operand count:",stdout);
	scanf("%d",&opnd_cnt);
	opmsg[0] = (char)opnd_cnt;

	for (i=0;i<opnd_cnt;i++){
		scanf("%d",(int*)&opmsg[1+i*OPSZ]);
	}
	fgetc(stdin);
	fputs("operator:",stdout);
	scanf("%c",&opmsg[1+opnd_cnt*OPSZ]);
	write(sock,opmsg,2+opnd_cnt*OPSZ);
	read(sock,&result,RLT_SIZE);

	printf("%d",result);
	close(sock);
	return 0;
}
