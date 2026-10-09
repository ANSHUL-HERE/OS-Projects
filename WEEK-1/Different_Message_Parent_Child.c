//Modify the program so that the parent and child print different messages.
//
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    pid_t pid = fork();

    if(pid < 0){
        printf("Error Process");
    }
    else if(pid == 0){
        printf("This is the child process\n");
    }
    else{
        printf("This is the parent process\n");
    }
    return 0;
}
