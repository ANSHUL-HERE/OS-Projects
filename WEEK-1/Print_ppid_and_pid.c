//Write a program that prints the PID and PPID of parent and child.
//
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    pid_t pid = fork();
    if(pid < 0){
        printf("Process Creation Failed !");

    }
    else if(pid == 0){
        printf("Child Process \n");
        printf("Process ID : %d\n",(int)getpid());
        printf("Parent ID : %d\n",(int)getpid());
    }
    else{
        printf("Parent Process \n");
        printf("Process ID : %d\n",(int)getpid());
        printf("Parent ID : %d\n",(int)getppid());

    }
    return 0;
}
