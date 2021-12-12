#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int fibo(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}

int main(int argc, char *argv[]) {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Error en la creacion del hijo");
        return -1;
    } else if (pid == 0) {
        int resultado = -1;
        resultado = fibo(25);

        printf("[%d] Resultado %d\n", getpid(), resultado);
    } else{
   //wait(NULL);
    }


    if (pid != 0)
        printf("[%d] Termina padre\n", getpid());
    else if (pid == 0)
        printf("[%d] Termina hijo\n", getpid());

    return 0;
}
