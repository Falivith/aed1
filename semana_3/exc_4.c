#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <windows.h> //apenas pra acentuação em conjunto com a primeira linha do main

typedef struct data{
char nome[11];
char telefone[9];
int idade;
}Pessoa; 

Pessoa pessoas[10];

void* menu_agenda(void *pBuffer);
void* add_cadastro(void *pBuffer);
/*void* listar_cadastro(void *pBuffer);
void* buscar_cadastro(void *pBuffer);
void* rem_cadastro(void *pBuffer);*/



int main(){
void* pBuffer = malloc(4*sizeof(int));            SetConsoleOutputCP(65001); //acentuação          
*(int*)pBuffer = 1;                               //1º Campo INT de pBuffer = controle do while do menu
void* ptr = pBuffer + 2*sizeof(int); 
*(int*)ptr = 0;                                   //3º Campo de pBuffer = Contagem de Usuarios preenchidos  

    while(*(int*)pBuffer){                   
    menu_agenda(pBuffer);
    }

return 0;
}

void* menu_agenda(void *pBuffer){

    void *ptr = pBuffer; 
    ptr = ptr + sizeof(int);                      //2º Campo INT de pBuffer = controle do CASE do menu 

    printf("\n1) Incluir novo cadastro");
    printf("\n2) Excluir cadastro");
    printf("\n3) Buscar cliente");
    printf("\n4) Listar clientes");
    printf("\n5) Sair");
    printf("\nOpção: ");

    scanf("%d", (int*)ptr);
    getc(stdin);

    switch(*(int*)ptr)
        {
        case 1:
            pBuffer = add_cadastro(pBuffer);
        break;

        case 2:
            //pBuffer = rem_cadastro(pBuffer);
        break;

        case 3:
            //pBuffer = buscar_cadastro(pBuffer);
        break;

        case 4:
            //pBuffer = listar_cadastro(pBuffer);
        break;

        case 5:
            *(int*)pBuffer = 0;
        break;

        default:
        break;
        }

return pBuffer;
}

void* add_cadastro(void *pBuffer){

    void *ptr_1 = pBuffer, *ptr = pBuffer;
    ptr = ptr + 2*sizeof(int);             //3º Campo de pBuffer = Contagem de Usuarios preenchidos  
    ptr_1 = ptr_1 + 3*sizeof(int);         //4º Campo de pBuffer = Inteiro usado pra teste no preenchimento de telefone
    *(int*)ptr_1 = 0; 

    printf("\nDigite o nome (10 Caracteres) do cliente: ");
    fgets(pessoas[*(int*)ptr].nome, sizeof(pessoas->nome), stdin);
    pessoas[*(int*)ptr].nome[strcspn(pessoas[*(int*)ptr].nome, "\n")] = 0;

    printf("Digite a idade do cliente: ");
    scanf("%d", pessoas[*(int*)ptr].idade);   getc(stdin);

        while(*(int*)ptr_1 != 8){
        printf("(8 caracteres, mais serão ignorados) Digite o telefone do cliente: ");
        fgets(pessoas[*(int*)ptr].telefone, sizeof(pessoas->telefone), stdin);
        *(int*)ptr_1 = strlen(pessoas[*(int*)ptr].telefone);
        }

    /*||||||||||||| passagem dos dados pro pBuffer |||||||||||||*/

    n_cliente = *(int*)pBuffer; 
    size_dados = (sizeof(temp_nome) + sizeof(telefone) + sizeof(int));  //calcula a quantidade de memória necessária pro cadastro
    pBuffer = realloc(pBuffer, sizeof(int) + n_cliente*size_dados); 
    p = pBuffer; 

        pBuffer = pBuffer + sizeof(int);                             //pula o campo n_clientes e vai para o campo nome
        pBuffer = pBuffer + (n_cliente-1) * size_dados;              //pula a quantidade de dados já usada por outros cadastros
            memmove((char*)pBuffer, temp_nome, sizeof(temp_nome));   //preenche o campo nome
        pBuffer = pBuffer + sizeof(temp_nome);                       //pula o tamanho do nome e vai para o campo idade
            *(int*)pBuffer = temp_idade;                             //preenche a idade
        pBuffer = pBuffer + sizeof(int);                             //pula o tamanho da idade e vai para o campo telefone
            memmove((char*)pBuffer, telefone, sizeof(telefone));     //prenche o telefone

    *(int*)ptr++; 
    return pBuffer;
    }