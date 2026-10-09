#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t pid = fork();

    if(pid < 0){
        printf("Creating failed");
    }
    else if(pid == 0){
        printf("Child Process Terminating");
    }
    else{
        sleep(20);
        printf("Parent Process Terminating");
    }
    return 0;
}
