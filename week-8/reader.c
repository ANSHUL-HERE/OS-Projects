
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
    key_t key;
    int shmid;
    char *shared;

    key = ftok(".", 'S');

    if (key == -1)
    {
        perror("ftok");
        return EXIT_FAILURE;
    }

    shmid = shmget(key, 1024, 0666);

    if (shmid == -1)
    {
        perror("shmget");
        return EXIT_FAILURE;
    }

    shared = (char *)shmat(shmid, NULL, 0);

    if (shared == (char *)-1)
    {
        perror("shmat");
        return EXIT_FAILURE;
    }

    printf("Data received: %s", shared);

    if (shmdt(shared) == -1)
    {
        perror("shmdt");
        return EXIT_FAILURE;
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("shmctl");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
