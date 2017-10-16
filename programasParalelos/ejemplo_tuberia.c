#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
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
	pid = fork();

	switch(pid){
		case -1:
		fprintf(stderr, "Error en for\n");
			exit(-1);

		case 0:
			write(tuberia[1],"Hola padre!", 11*sizeof(char));
			break;
		
		default:
		wait(NULL);
			char buffer[20];
			read(tuberia[0], buffer, 11*sizeof(char));
			fprintf(stdout, "%s\n", buffer);
			close(tuberia[0]);
			close(tuberia[1]);
	}
	return 0;
}