//Print the return value of fork() in both processes.
//
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    pid_t pid = fork();

    if(pid < 0){
        printf("Error Creating Process");
    }
    else if(pid == 0){
        printf("Child Process\n");
        printf("The Return value of this process : %d",pid);
    }
    else{
        printf("Parent Process\n");
        printf("The Return value of this process : %d",pid);
    }
    return 0;
}
