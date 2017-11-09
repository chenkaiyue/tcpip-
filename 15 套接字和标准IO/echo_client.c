readfp=fdopen(sock,"r");
writefp = fdopen(sock,"w");
while(1){
	fputs(message,writefp);
	fflush(writefp);
	fgets(message,BUF_SIZE,readfp);
}
fclose(readfp);
fclose(writefp);