int main(int argc, char const *argv[])
{
	FILE * f1;
	FILE * f2;
	f1 = fopen('news.txt','r');
	f2 = fopen('cpy.txt','w');

	while(fgets(buf,BUF_SIZE,f1)!=NULL)
		fputs(buf,f2);

	fclose(f1);
	fclose(f2);
	return 0;
}