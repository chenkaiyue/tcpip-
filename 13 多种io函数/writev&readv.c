int main(){
	struct iovec vec[2];
	char buf1[]="abcd";
	char buf2[]="1234";
	int str_len;

	vec[0].iov_base=buf1;
	vec[0].iov_len = strlen(buf1);
	vec[1].iov_base=buf2;
	vec[1].iov_len = strlen(buf2);

	str_len = writev(1,vec,2);
	puts("");
	printf("d",str_len);
	return 0;
}


int main()
{
	struct iovec vec[2];
	char buf1[BUF_SIZE] = {0,};
	char buf2[BUF_SIZE] = {0,};
	int str_len;

	vec[0].iov_base=buf1;
	vec[0].iov_len=5;
	vec[1].iov_base=buf2;
	vec[1].iov_len=BUF_SIZE;

	str_len = readv(0,vec,2);
	printf("%d",str_len);
	printf("%s",buf1);
	printf("%s",buf2);

	return 0;
}