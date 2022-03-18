#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados{ 
    int idade;
    int telefone;
    char nome[10];
};

add_cadastro(void *pBuffer);
//rem_cadastro(void *pBuffer);
//list_dados(void *pBuffer);

int main(){
    unsigned int controle = 1, clientes = 0; 
    void *pBuffer = malloc(1);


    while(exit)
        switch(controle)
        {
        case 1: 
        add_cadastro(pBuffer);
        break;

        default:
        break;
        }
    

    return 0;
}