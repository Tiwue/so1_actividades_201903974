#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Error al crear el proceso
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Proceso hijo: termina de inmediato, convirtiéndose en zombie
        printf("Proceso hijo (PID: %d) terminado, convirtiéndose en zombie...\n", getpid());
        exit(0);
    } else {
        // Proceso padre: duerme por 60 segundos para permitir que el proceso hijo sea zombie
        printf("Proceso padre (PID: %d) dormirá 60 segundos mientras el hijo es zombie...\n", getpid());
        sleep(60);
        wait(NULL);
    }

    return 0;
}
