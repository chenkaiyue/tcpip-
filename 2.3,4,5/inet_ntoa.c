#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc,char *argv[])
{
	struct sockaddr_in addr1;
	char *str_ptr;
	char str_arr[20];
	addr1.sin_addr.s_addr=htonl(0x1020304);
	str_ptr = inet_ntoa(addr1.sin_addr);
	strcpy(str_arr,str_ptr);
	printf("%s",str_ptr);
	printf("%s",str_arr)
	return 0;
}