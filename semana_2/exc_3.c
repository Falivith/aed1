#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados{ 
    int idade;
    int telefone;
    char nome[10];
};

void add_cadastro(void *pBuffer){
    char temp[50];
    printf("\nDigite o nome do cliente.");
    scanf("%s", temp);
    }

int main(){
    int sair = 1; 
    int option = 1;
    //int clientes = 0;
    void *pBuffer = calloc(1,1);


    while(sair){

        printf("\n1) Incluir novo cadastro");
        printf("\n2) Excluir cadastro");
        printf("\n3) Buscar cliente");
        printf("\n4) Listar clientes");
        printf("\n5) Sair"); 
        scanf("%d", &option);

            switch(option)
            {
            case 1: 
                printf("\n");
                add_cadastro(pBuffer);
            break;

            case 2:
            break;

            case 3: 
            break;

            case 4:
                sair = 0; 
            break; 

            default:
            break;
        }
    }

    return 0;
}