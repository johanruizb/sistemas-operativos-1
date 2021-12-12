#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int contador = 1;
    pid_t pid = fork();
    
    if (pid < 0){
        printf("Error en la creación del hijo");
        return -1;
    } else if (pid == 0){
        contador += 5;
    } else {
        contador += 2;
    }

    printf("Contador %d\n", contador);
    return 0;
}
