#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
void error_handing(char* message);

int main(void)
{
	int fd;
	char buf[]="let's go";

	fd = open("data.txt",O_CREAT|O_WRONLY|O_TRUNC);
	if (fd == -1){
		error_handing("open() error");
	}
	printf("file descriptor : %d \n",fd);

	if (write(fd,buf,sizeof(buf)) == -1)
		error_handing("write() error!");
	close(fd);
	return 0;
}
void error_handing(char* message)
{
	fputs(message,stderr);
	fputc('\n',stderr);
	exit(1);
}




#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	char buf[]="hello,you";
	fd = open('data.txt',O_CREAT|O_TRUNC|O_WRONLY);
	if (fd==-1){
		error_handing("open error");
	}

	if(write(fd,buf,sizeof(buf))==-1)
		error_handing("write error");

	close(fd);
	return 0;
}



int main(){
	int fd;
	char buf[]="ehllo";
	fd=open('data.txt',O_TRUNC|O_WRONLY|O_CREAT);
	if (fd==-1){
		error_handing();
	}
	if (write(fd,buf,sizeof(buf))==-1){
		error_handing();
	}
	close(fd);
	return 0;
}