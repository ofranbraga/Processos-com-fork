#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <numero_de_processos>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "O número de processos deve ser positivo\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        
        if (pid < 0) {
            perror("fork falhou");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Processo filho
            execlp("echo", "echo", "Hello World!", NULL);
            // Se execlp retornar, houve erro
            perror("execlp falhou");
            exit(EXIT_FAILURE);
        }
    }

    // Processo pai espera todos os filhos terminarem
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    printf("Todos os %d processos terminaram\n", n);
    return 0;
}