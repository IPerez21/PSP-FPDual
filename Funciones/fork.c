#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	pid_t pid, pid2;
	printf("Hola\n");
	pid = fork();
	if (pid ==0){//Código del hijo
		printf("Hola soy el hijo. Mi padre es: %d\n", getppid());
	}else{//Código del padre
		pid2=fork();
		if (pid2 ==0){//Código del segundo hijo
			printf("Hola soy el 2º hijo. Mi padre es: %d\n", getppid());

		}else{
			printf("Hola soy el padre. Mi padre es: %d\n", getpid());
			printf("he creado un proceso hijo cuyo pid es: %d\n", pid);	
			printf("he creado un proceso hijo cuyo pid es: %d\n", pid);	
			printf("El proceso %d terminó \n", wait(NULL));
			printf("Eĺ proceso %d terminó \n", wait(NULL));
		}
		
	}
	return 0;
}
