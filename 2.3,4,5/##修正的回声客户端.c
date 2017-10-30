##修正的回声客户端
if(connect(sock,(struct sockaddr*)serv_addr,sizeof(serv_addr)) == -1){
	error_handling();
}

while(1){
	fputs("message",stdout);
	fgets(message,BUF_SIZE,stdin);

	if (!strcmp(message,'q\n'))
		break;

	int str_len = write(sock,message,strlen(message));
	int recv_len=0
	while(recv_len<str_len){
		revc_cnt = read(sock,&message[recv_len],BUF_SIZE-1);
		if (revc_cnt == -1){
			error_handling();
		}
		recv_len += revc_cnt;
	}
	message[recv_len]=0;
}