int main(int argc, char const *argv[])
{
	FILE * fp;
	int fd;
	fd = open('test',O_WRONLY|O_CREAT|O_TRUNC)
	if (fd == -1){
		fputs("error",stdout);
		return -1;
	}
	fp = fdopen(fd,"w");
	fputs("hello",fp);
	printf("file descriptor %d",fileno(fp));
	fclose(fp);
	return 0;
}