
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd;
    char buffer[100];
    ssize_t n;

    fd = open("myfifo", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }

    n = read(fd, buffer, sizeof(buffer) - 1);

    if (n == -1)
    {
        perror("read");
        close(fd);
        return EXIT_FAILURE;
    }

    buffer[n] = '\0';

    printf("Received: %s", buffer);

    close(fd);
    unlink("myfifo");

    return EXIT_SUCCESS;
}
