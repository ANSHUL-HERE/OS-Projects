#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i < n;i++){
        printf("Enter the %d element : ",i+1);
        scanf("%d",&(arr[i]));
    }

    pid_t pid = fork();

    if(pid < 0){
        printf("Error creating child process !");
    }
    else if(pid == 0){
        int max = arr[0];
        for(int i = 1;i < n;i++){
            if(max < arr[i])max = arr[i];
        }
        printf("The largest element of the array is : %d\n",max);
    }
    else{
        int min = arr[0];
        for(int i = 1;i < n;i++){
            if (min > arr[i])min = arr[i];
        }
        printf("The smallest element of the array is : %d\n",min);
    }
    return 0;
}
