
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    msg.type = 1;

    printf("Enter message: ");
    fgets(msg.text, sizeof(msg.text), stdin);

    if (msgsnd(msgid, &msg, strlen(msg.text) + 1, 0) == -1)
    {
        perror("msgsnd");
        return EXIT_FAILURE;
    }

    printf("Message sent.\n");

    return EXIT_SUCCESS;
}
