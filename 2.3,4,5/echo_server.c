socklen_t clnt_sock_size;
int i,str_len;
if (listen(serv_sock,5)==-1){
	error_handling();
}
clnt_addr_size = sizeof(clnt_addr);

for(i=0;i<5;i++){
	clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_addr,&clnt_addr_size);
	if clnt_sock == -1
		error_handling;
	while((str_len=read(clnt_sock,message,BUF_SIZE))!=0){
		write(clnt_sock,message,str_len);
	}
	close(clnt_sock);
}
close(serv_sock);
return 0;