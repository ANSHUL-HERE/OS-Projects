#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int status;
    pid_t pid = fork();
    if(pid < 0){
        printf("Error Creating Process");
    }
    else if(pid == 0){
        printf("Child process\n");
        printf("Before Parent Execution\n");
        printf("PID : %d PPID : %d \n",getpid(),getppid());
        sleep(5);
        printf("After Parent Execution\n");
        printf("PID : %d PPID : %d \n",getpid(),getppid());
    }
    else{
        sleep(2);
        printf("Parent Process\n");
        printf("PID : %d PPID %d \n",getpid(),getppid());
    }
    
}
