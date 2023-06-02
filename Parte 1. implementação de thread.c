//Parte 1- implementação de thread
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void Pidfilho() {
    printf("pid do filho: %d\n", getpid());
}

void Pidpai() {
    printf("pid do pai: %d\n", getpid());
}

void erro() {
    perror("fork");
    exit(1);
}

int main(){
    int i;
    pid_t pid;
    
    if ((pid = fork()) < 0){
        erro();
}
    if (pid == 0) {
        Pidfilho();
    }
    else{
        Pidpai();
    }
    printf("este print sera executado por ambos processos\n\n");
    
    exit(0);
}
