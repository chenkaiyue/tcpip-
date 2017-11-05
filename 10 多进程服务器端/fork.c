#include <stdio.h>
#include <unistd.h>

int gval=10;
int main()
{
	pid_t pid;
	int lval=10;
	gval++,lval+=5;

	pid=fork();
	if(pid==0)
		gavl+=2,lval+=2;
	else
		gval-=2,lval-=2;
}