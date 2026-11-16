
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message
{
    long type;
    char text[100];
};

int main(void)
{
    key_t key;
    int msgid;
    struct message msg;

    key = ftok(".", 'A');

    if (key == -1)
    {
        perror("ftok");
        return EXIT_FAILURE;
    }

    msgid = msgget(key, 0666 | IPC_CREAT);

    if (msgid == -1)
    {
        perror("msgget");
        return EXIT_FAILURE;
    }

    if (msgrcv(msgid, &msg, sizeof(msg.text), 1, 0) == -1)
    {
        perror("msgrcv");
        return EXIT_FAILURE;
    }

    printf("Received: %s", msg.text);

    if (msgctl(msgid, IPC_RMID, NULL) == -1)
    {
        perror("msgctl");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
