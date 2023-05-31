#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(){
    pid_t iPid;
    printf("\nDuplicando o processo\n");
    
    iPid = fork();
    if(iPid < 0){
        perror("Error");
        exit(errno);
    }
    if(iPid != 0){ /*este trecho de codigo sera executado apenas no pai */
    printf("\nCodigo executado no processo pai\n");
    printf("\nPAI -Processo pai. PID |%d| \n", getpid());
    printf("\nPAI -Processo filho. PID |%d| \n", iPid);
    }else{
    printf("\nCodigo exectado pelo filho");
    }
//este trecho de codigo sera executado apenas no filho, embora o comando if esteja disponivel para o pai*/
    if(iPid == 0){
        printf("\nCodigo executado no processo filho\n");
        printf("\nFILHO-Processo pai. PID:|%d|\n", getppid());
        printf("\nFILHO-Processo filho. PID |%d|\n", getpid()); 
    }
    else{
        printf("\nCodigo executado pelo pai");
    }    
    //este cÃ³digo esta disponivel no pai e no filho
    printf("\nEsta mensagem sera impressa 2 vezes");
    return 0;
}
