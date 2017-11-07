
int main(){
	write(sock,"123",strlen("123"));
}


int main(){
	while (1){
		str_len = recv(clnt_sock,buf,sizeof(buf)-1,MSG_PEEK|MSG_DONTWAIT);
		if (str_len > 0)
			break;
	}

	buf[str_len] = 0;
	printf("first read :%s",buf)

	str_len = revc(clnt_sock,sizeof(buf)-1,0);
	buf[str_len] = 0;
	printf("seconf read :%s",buf)

	close(serv_sock);
	close(clnt_sock);
	return 0;

}