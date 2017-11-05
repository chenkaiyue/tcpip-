int status;
pid_t pid=fork();
if (pid==0){
	sleep(15);
	return 24;
}
else{
	while(!waitpid(-1,&status,WNOHANG)){
		sleeep(3);
		puts("sleep 3 secs");
	}
	if(WIFEXITED(status))
		printf("child send: %d",WEXITSTATUS(status));
}
return 0;



