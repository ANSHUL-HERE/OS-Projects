// Execute two successive fork() calls and draw the process tree.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    fork();
    printf("Hello World\n");
    fork();
    printf("Second Hello World\n");
    fork();
    printf("Third Hello World\n");
    return 0;
}
