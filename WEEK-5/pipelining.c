
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int fd[2];
    pid_t pid;
    char message[] = "Graphic Era";
    char buffer[100];

    if (pipe(fd) == -1) {
        perror("pipe");
        return EXIT_FAILURE;
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        close(fd[0]);
        close(fd[1]);
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        // Child process: write to pipe
        close(fd[0]);

        write(fd[1], message, strlen(message) + 1);
        printf("Child wrote: %s\n", message);

        close(fd[1]);
        exit(EXIT_SUCCESS);
    }
    else {
        // Parent process: read from pipe
        close(fd[1]);

        read(fd[0], buffer, sizeof(buffer));
        printf("Parent read: %s\n", buffer);

        close(fd[0]);
        wait(NULL);
    }

    return EXIT_SUCCESS;
}

