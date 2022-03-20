/*Ulian Gabriel Alff Ramires
* Matrícula Nº 20200274
* Cursando no terceiro semestre AED1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_NOME 11   
#define TAM_TELEFONE 9

#include <windows.h> //apenas pra acentuação em conjunto com a primeira linha do main

void* add_cadastro(void *pBuffer);
void* listar_cadastro(void *pBuffer);
void* buscar_cadastro(void *pBuffer);

int main(){
    SetConsoleOutputCP(65001);
    int sair = 1; 
    int option = 1;
    void *pBuffer = calloc(1,sizeof(int)); //é reservado um int pra guardar o Npessoas
    *(int*)pBuffer = 0;

    while(sair){

        printf("\n1) Incluir novo cadastro");
        printf("\n2) Excluir cadastro");
        printf("\n3) Buscar cliente");
        printf("\n4) Listar clientes");
        printf("\n5) Sair");
        printf("\n\nOpção: ");
        scanf("%d", &option);
        getc(stdin);

        switch(option)
        {
        case 1:
            pBuffer = add_cadastro(pBuffer);
        break;

        case 2:
        break;

        case 3:
        break;

        case 4:
            pBuffer = listar_cadastro(pBuffer);
            printf("\n");
        break;

        case 5:
            sair = 0;
        break;

        default:
        break;
        }
    }

    return 0;
}

void* add_cadastro(void *pBuffer){

    /*||||||||||||| variáveis |||||||||||||*/  

    *(int*)pBuffer = *(int*)pBuffer + 1; //o conteudo do endereço 0 é um int, logo, incrementar pBuffer aumenta o n de clientes
    void *p; 
    p = pBuffer;
    int temp_idade, tel_size = 0, n_cliente, size_dados;
    char temp_nome[TAM_NOME], telefone[TAM_TELEFONE];

    /*||||||||||||| preenchimento dos dados |||||||||||||*/  

    printf("\nDigite o nome do cliente: ");
    fgets(temp_nome, sizeof(temp_nome), stdin);
    temp_nome[strcspn(temp_nome, "\n")] = 0;   //copiado de https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input, preciso de explicação depois
    printf("Digite a idade do cliente: ");
    scanf("%d", &temp_idade);   getc(stdin);

        while(tel_size != 8){
        printf("(8 caracteres, mais serão ignorados) Digite o telefone do cliente: ");
        fgets(telefone, sizeof(telefone), stdin);
        tel_size = strlen(telefone);
        }

    /*||||||||||||| passagem dos dados pro pBuffer |||||||||||||*/

    n_cliente = *(int*)pBuffer; 
    size_dados = sizeof(int) + n_cliente * (sizeof(temp_nome) + sizeof(telefone) + sizeof(int));  //calcula a quantidade de memória necessária pro cadastro
    pBuffer = realloc(pBuffer, size_dados); 

        pBuffer = pBuffer + sizeof(int);                             //pula o numero de clientes e vai para o campo nome
            memmove((char*)pBuffer, temp_nome, sizeof(temp_nome));   //preenche o campo nome
        pBuffer = pBuffer + sizeof(temp_nome);                       //pula o tamanho do nome e vai para o campo idade
            *(int*)pBuffer = temp_idade;                             //preenche a idade
        pBuffer = pBuffer + sizeof(int);                             //pula o tamanho da idade e vai para o campo telefone
            memmove((char*)pBuffer, telefone, sizeof(telefone));     //prenche o telefone

    return p; //retorna o endereço de p, que é na verdade o endereço inicial de pBuffer que foi guardado antes dele começar a preencher os campos
    }

void* listar_cadastro(void *pBuffer){

    void *p = pBuffer;               //guarda o endereço inicial de pBuffer
    int n_clientes, i;
    n_clientes = *(int*)pBuffer; 

    pBuffer = pBuffer + sizeof(int); //pula o numero de clientes


    for(i=0; i<n_clientes; i++){
        printf("\n\nCliente Nº %d:", i+1);
        printf("\nNome: %s", (char*)pBuffer);
        pBuffer = pBuffer + TAM_NOME; 
        printf("\nIdade: %d", *(int*)pBuffer); 
        pBuffer = pBuffer + sizeof(int);
        printf("\nTelefone: %s", (char*)pBuffer);
    }

    return p;
}

void* buscar_cadastro(void *pBuffer){

    void *p = pBuffer;        
    int n_clientes, i, option, exit = 1;
    n_clientes = *(int*)pBuffer;

    printf("\nVocê deseja procurar o cliente via:\n1) Nome\n2) Telefone\n3) Idade\n 4) Voltar ao Menu");

    while(exit){
        switch(option){
            case 1: 
                
            break;
            case 2: break;
            case 3: break;
            case 4: exit = 0; break;
        }
    }
}