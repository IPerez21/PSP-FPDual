#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]){
	pid_t pid;
	printf("Hola\n");
	pid = fork();
	if (pid==0){//Código del hijo
		pid = fork();
		if (pid==0){
			fprintf(stdout, "Hola soy el nieto. \n");
			fprintf(stdout, "PID: %d PPID %d \n",getpid(), getppid() );
		}else{
			fprintf(stdout, "Hola soy el hijo.\n");
			fprintf(stdout, "PID: %d PPID %d \n",getpid(), getppid() );
			fprintf(stdout, "Mi hijo es: %d\n", pid);
			fprintf(stdout, "Mi hijo %d termino \n", wait(NULL)  );
		}
	}else{//Código del padre
		fprintf(stdout,"Hola soy el padre.\n");
		fprintf(stdout, "PID: %d PPID:%d \n", getpid(), getppid());
		fprintf(stdout, "Mi hijo es :%d \n", pid);	
		fprintf(stdout, "Mi hijo %d termino \n", wait(NULL));
	}
}
