/*Ulian Gabriel Alff Ramires
* Matrícula Nº 20200274
* Cursando no terceiro semestre AED1
*
* Exercício 5: Programa deve armazenar possíveis infinitos usuários, e listar todos eles no final.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> //acentuação

typedef struct{
    char nome[30];
    int idade;
    float altura;
}Pessoa;

Pessoa* add_cliente (Pessoa* pBuffer, int n_clientes); 
Pessoa* list_quit   (Pessoa* pBuffer, int n_clientes); 

int main(){
    SetConsoleOutputCP(65001); 
    int n_clientes = 0;
    int exit_flag = 1;
    int option; 
    Pessoa *pBuffer = (Pessoa*)malloc(sizeof(Pessoa)); 

    while(exit_flag){
        
        printf("\n1) Incluir novo cadastro");
        printf("\n2) Mostrar todos cadastros e sair");
        printf("\nOpção: ");
        scanf("%d", &option); 
        getc(stdin);

        switch(option){
            case 1:
            pBuffer = add_cliente(pBuffer, n_clientes);
            n_clientes++;
            break;

            case 2:
            pBuffer = list_quit(pBuffer, n_clientes);
            exit_flag = 0; 
            break; 

            default:
            break;
        }
    }

    free(pBuffer);
    return 0;
}

Pessoa* add_cliente (Pessoa* pBuffer, int n_clientes){
    Pessoa temporario; 
    pBuffer = (Pessoa*)realloc(pBuffer, (n_clientes+1)*sizeof(Pessoa));
        printf("\nDigite o nome do Cliente: ");
        scanf("%s", temporario.nome);         
        getc(stdin);

        printf("Digite a idade do Cliente: ");
        scanf("%d", &temporario.idade);       
        getc(stdin);

        printf("Digite a altura do Cliente: ");
        scanf("%f", &temporario.altura);      
        getc(stdin);
    pBuffer[n_clientes] = temporario; 
    return pBuffer; 
}

Pessoa* list_quit (Pessoa* pBuffer, int n_clientes){
    int i;
    for(i = 0; i<n_clientes; i++){
        printf("\nInformações do cliente %d: ", i+1);
        printf("\nNome: %s", pBuffer[i].nome);
        printf("\n Idade: %d ", pBuffer[i].idade);
        printf("\n  Altura: %.2f \n", pBuffer[i].altura);
    }
    printf("\n");
    return pBuffer; 
}