#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "maxrand.c"
#include <limits.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    if (pid < 0) {
        printf("Error en la creacion del hijo");
        return -1;
    } else if (pid == 0) {
      //printf("Max. %d\n",INT_MAX);
        printf("[%d] Termina hijo\n", getpid());
//        printf("%d",(1/0));
//        return maxrand(2147483647);
        return 2147483647;
    } else{
        int retorno;
        wait(&retorno);
        printf("[%d] WIFEXITED %d\n", getpid(), WIFEXITED(retorno));
        printf("[%d] WEXITSTATUS %d\n", getpid(), WEXITSTATUS(retorno));
    }

    printf("[%d] Termina padre\n", getpid());

    return 0;
}
