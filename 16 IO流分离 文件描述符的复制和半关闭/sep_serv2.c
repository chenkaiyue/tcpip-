FILE * readfp = fdopen(clnt_sock,"r");
FILE * writefp = fdopne(dup(clnt_sock),"w");
fputs("hello",writefp);
fflush(writefp);

shutdown(fileno(writefp),SHUT_WR);//半关闭
fclose(writefp);

fgets(buf,sizeof(buf),readfp);
fclose(readfp);
