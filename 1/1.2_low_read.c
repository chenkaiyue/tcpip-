#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 100
void error_handing(char *message);

int main(void)
{
	int fd;
	char buf[BUF_SIZE];

	fd = open("data.txt",O_RDONLY);
	if (fd == -1){
		error_handing("open wrong");
	}
	printf("file descri is %d \n",fd);

	if(read(fd,buf,sizeof(buf))==-1){
		error_handing("read error");
	}
	printf("data is %s",buf);
	close(fd);
	return 0;
}

void error_handing(char* message){
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}


int main(){
	int fd;
	char buf[BUF_SIZE];

	fd = open('data.txt',O_RDONLY);
	if (fd == -1){
		error_handing();
	}

	if (readb(fd,buf,sizeof(buf))==-1){
		error_handing();
	}
	printf("%d",fd);
	close(fd);
	return 0;
}

void error_handing(char* message){
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}