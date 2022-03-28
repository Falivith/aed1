#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <windows.h>

typedef struct{
char nome[30];
int idade;
float altura;
}Pessoa;

int n_clientes = 0;                                                                                      //var global só pra facilitar, já que o programa só faz isso.

Pessoa* add_cliente (Pessoa* pBuffer); 
Pessoa* list_quit (Pessoa* pBuffer); 

int main(){
SetConsoleOutputCP(65001); 

int exit_flag = 1;

int option; 

Pessoa *pBuffer = (Pessoa*)malloc(sizeof(Pessoa)); printf("O tamanho da struct é %d", sizeof(Pessoa));    //Inicializa o Buffer, contendo espaço pra uma pessoa.

while(exit_flag){

    printf("\n1) Incluir novo cadastro");
    printf("\n2) Mostrar todos cadastros e sair");
    printf("\nOpção: ");
    scanf("%d", &option); getc(stdin);

    switch(option){
        case 1:
            pBuffer = add_cliente(pBuffer);
                break;
        
        case 2:
            pBuffer = list_quit(pBuffer);
            exit_flag = 0; 
                break; 

        default:
            break;
        }
    }

    return 0;
}

Pessoa* add_cliente (Pessoa* pBuffer){
 
    pBuffer = (Pessoa*)realloc(pBuffer, (n_clientes+1)*sizeof(Pessoa));

    Pessoa* ptr = pBuffer;
    ptr = ptr + n_clientes*sizeof(Pessoa); 

    printf("\nDigite o nome do Cliente: ");
    fgets(ptr[n_clientes].nome, 30, stdin);
    ptr[n_clientes].nome[strcspn(ptr[n_clientes].nome, "\n")] = 0; 
    printf("Digite a idade do Cliente: ");
    scanf("%d", &ptr[n_clientes].idade); getc(stdin);
    printf("Digite a altura do Cliente: ");
    scanf("%f", &ptr[n_clientes].altura); getc(stdin);

    n_clientes++;

return pBuffer; 
}

Pessoa* list_quit (Pessoa* pBuffer){

    for(int i = 0; i<n_clientes; i++){
        printf("\nInformações do cliente %d: ", i+1);
        printf("\n Nome: %s", pBuffer[i].nome);
        printf("\n  Idade: %d ", pBuffer[i].idade);
        printf("\n   Altura: %.2f \n", pBuffer[i].altura);
        pBuffer = pBuffer + sizeof(Pessoa);
    }

printf("\n");
return pBuffer; 
}