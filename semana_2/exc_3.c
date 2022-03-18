#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*struct dados{ 
    int idade;
    int telefone;
    char nome[10];
};*/

void add_cadastro(void *pBuffer){
    void *p = pBuffer;
    unsigned int temp_idade, i;
    char temp_nome[11], telefone[9];
    printf("\n\nDigite o nome do cliente: ");
    fgets(temp_nome, sizeof(temp_nome), stdin);
    printf("\nDigite a idade do cliente: ");
    scanf("%d", &temp_idade);   getc(stdin);

        printf("\nDigite o telefone do cliente: ");
        fgets(telefone, sizeof(telefone), stdin);
        

    }

int main(){
    int sair = 1; 
    int option = 1;
    void *pBuffer = calloc(1,sizeof(int)); //é reservado um int pra guardar o Npessoas


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