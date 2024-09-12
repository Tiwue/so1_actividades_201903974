#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>

void *thread_function(void *arg) {
    printf("Hilo creado (PID: %d)\n", getpid());
    return NULL;
}

int main() {
    pid_t pid;
    pthread_t thread;

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Proceso hijo
        printf("Proceso hijo (PID: %d)\n", getpid());
        
        if (fork() == 0) {  // Segundo fork dentro del proceso hijo
            printf("Proceso nieto (PID: %d)\n", getpid());
        }

        // Crear un hilo dentro del proceso hijo
        if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
            perror("Error al crear el hilo");
            exit(1);
        }

        pthread_join(thread, NULL);
    }

    // Tercer fork
    fork();

    // Finalización del proceso
    printf("Proceso finalizando (PID: %d)\n", getpid());

    return 0;
}
