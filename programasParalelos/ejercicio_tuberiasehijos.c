#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	int tuberia[2];
	pipe(tuberia);

	if(pipe(tuberia)==-1){
		fprintf(stderr, "Error en tubría\n");
		exit(-1);
	}

	pid_t pid;

	for (int i=0; i<3; i++){
		if(fork()==0){
			pid_t pid = getpid();
			write(tuberia[1],&pid, 11*sizeof(pid_t));
			return 0;
		}
	}
	/*if (pid ==-1){//Código del hijo
		fprintf(stderr, "Error en for\n");
			exit(-1);
	}else if(pid == 0){
		write(tuberia[1],&pid, 11*sizeof(pid_t));
	}else{
		pid =fork();
		if (pid ==-1){//Código del hijo
			fprintf(stderr, "Error en for\n");
			exit(-1);
		}else if(pid == 0){
			write(tuberia[1],&pid, 11*sizeof(pid_t));
		}else{
			pid=fork();
			if (pid ==-1){//Código del hijo
				fprintf(stderr, "Error en for\n");
				exit(-1);
			}else if(pid == 0){
				write(tuberia[1],&pid, 11*sizeof(pid_t));
			}
		}
	}*/
	for (int i=0;i<3;i++){
		wait(NULL);
		read(tuberia[0],&pid, sizeof(pid_t));
		fprintf(stdout,"EL PID de un hijo es: %d\n", pid );

	}

	return 0;
}