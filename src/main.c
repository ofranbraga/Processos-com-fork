#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <numero_de_processos>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "O número de processos deve ser positivo\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        
        if (pid < 0) {
            perror("fork falhou");
            exit(1);
        } else if (pid == 0) {
            // Processo filho
            execlp("./hello", "hello", NULL);
            perror("exec falhou");
            exit(1);
        }
    }

    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    return 0;
}