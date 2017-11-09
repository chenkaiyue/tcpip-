FILE * readfp = fdopen(clnt_sock,"r");
FILE * writefp = fdopen(clnt_sock,"w");
while(!feof(readfp)){
	fgets(message,BUF_SIZE,readfp);
	fputs(message,writefp);
	fflush(writefp);
}
flcose(readfp);
flcose(writefp);
