char message[1024];
while(1){
	fputs("input message",stdout);
	fgets(message,1024,stdin);

	if(!strcmp(message,'q\n') || !strcmp(message,'Q\n'))
		break;

	write(sock,message,strlen(message));
	str_len=read(sock,message,BUF_SIZE-1);
	message[str_len]=0;
	printf("%s",message);
}
close(sock);
