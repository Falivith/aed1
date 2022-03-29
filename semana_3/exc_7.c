/*Ulian Gabriel Alff Ramires
* Matrícula Nº 20200274
* Cursando no terceiro semestre AED1
*
* Exercício 7: Programa deve armazenar os dados de 10 pessoas, todas as variáveis devem ser ponteiros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>                                //apenas pra acentuação em conjunto com a primeira linha do main
#define QNT_PESSOAS 10

typedef struct data{
char nome[11];
char telefone[9];
int idade;
}Pessoa; 

Pessoa pessoas[QNT_PESSOAS];

void* menu_agenda(void *pBuffer);
void* add_cadastro(void *pBuffer);
void* listar_cadastro(void *pBuffer);
void* rem_cadastro(void *pBuffer);

int main(){
    SetConsoleOutputCP(65001); //acentuação         
    void* pBuffer = malloc(6*sizeof(int));
    *(int*)pBuffer = 1;                               //1º Campo INT de pBuffer = controle do while do menu
    void* ptr = pBuffer + sizeof(int);                
    *(int*)ptr = 0;                                   //2º Campo INT de pBuffer = controle do CASE do menu 
    ptr = pBuffer + 2*sizeof(int); 
    *(int*)ptr = 0;                                   //3º Campo INT de pBuffer = Contagem de Usuarios preenchidos  
    ptr = pBuffer + 3*sizeof(int);
    *(int*)ptr = 0;                                   //4º Campo INT de pBuffer = Inteiro usado pra teste na função add_cadastro
    ptr = pBuffer + 4*sizeof(int);              
    *(int*)ptr = 0;                                   //5º Campo INT de pBuffer = Variável auxiliar (for, contador, etc)
    ptr = pBuffer + 5*sizeof(int); 
    *(int*)ptr = 0;                                   //6º Campo INT de pBUffer = Variável auxiliar (for, contador, etc)

    while(*(int*)pBuffer){                   
        menu_agenda(pBuffer);
    }
    free(pBuffer);
    return 0;
}

void* menu_agenda(void *pBuffer){
    void* ptr = pBuffer + sizeof(int);                //Acessando o 2º campo (controle do CASE)
    printf("\n1) Incluir novo cadastro");
    printf("\n2) Excluir cadastro");
    printf("\n3) Listar clientes");
    printf("\n4) Sair");
    printf("\n\nOpção: ");
    scanf("%d", (int*)ptr);
    getc(stdin);

    switch(*(int*)ptr){
        case 1:
        pBuffer = add_cadastro(pBuffer);
        break;

        case 2:
        pBuffer = rem_cadastro(pBuffer);
        break;

        case 3:
        pBuffer = listar_cadastro(pBuffer);
        break;

        case 4:
        *(int*)pBuffer = 0;
        break;

        default:
        break;
    }
    return pBuffer;
}

void* add_cadastro(void *pBuffer){
    void *n_users = pBuffer + 2*sizeof(int);  //3º Campo de pBuffer
    void *teste = pBuffer + 3*sizeof(int);    //4º Campo de pBuffer

        if(*(int*)n_users+1 > QNT_PESSOAS){
            printf("\nNão há espaço para mais usuários! Remova algum ou saia do programa.\n");
            return pBuffer;
        }

    printf("\nDigite o nome (10 Caracteres) do cliente: ");
    fgets(pessoas[*(int*)n_users].nome, sizeof(pessoas->nome), stdin);
    pessoas[*(int*)n_users].nome[strcspn(pessoas[*(int*)n_users].nome, "\n")] = 0;

    printf("Digite a idade do cliente: ");
    scanf("%d", &pessoas[*(int*)n_users].idade);   getc(stdin);

        while(*(int*)teste != 8){
        printf("Digite o telefone do cliente: ");
        fgets(pessoas[*(int*)n_users].telefone, sizeof(pessoas->telefone), stdin);
        *(int*)teste = strlen(pessoas[*(int*)n_users].telefone);
        }
        
        *(int*)teste = 0; 
        *(int*)n_users = *(int*)n_users+1; 
    return pBuffer;
}

void* listar_cadastro(void *pBuffer){

    void* n_users = pBuffer + 2*sizeof(int);            //Campo 3: numero de usuarios
    void* contador = pBuffer + 4*sizeof(int);           //Campo 5: contador FOR

    for(*(int*)contador = 0; *(int*)contador < *(int*)n_users; *(int*)contador = *(int*)contador+1){
        printf("\nCliente Nº %d:", *(int*)contador+1);
        printf("\nNome: %s", pessoas[*(int*)contador].nome);
        printf("\nIdade: %d", pessoas[*(int*)contador].idade); 
        printf("\nTelefone: %s", pessoas[*(int*)contador].telefone);
        printf("\n\n");
    }
    return pBuffer; 
}

void* rem_cadastro(void *pBuffer){
    void* n_users = pBuffer + 2*sizeof(int);            //Campo 3: numero de usuarios
    void* rem_user = pBuffer + 4*sizeof(int);           //Campo 5: Variável utilitária 
    void* contador = pBuffer + 5*sizeof(int);           //Campo 6: Contador FOR
    
    do{
        printf("Digite o número (0 para voltar ao menu) do cliente que deseja remover da lista: ");
        scanf("%d", (int*)rem_user);     
        getc(stdin);

        if(*(int*)rem_user == 0){
            printf("\nVoltando ao menu..."); return pBuffer;
        }
        if(*(int*)rem_user >= *(int*)n_users+1){
            printf("\nEsse usuário não está na lista. Voltando ao menu..."); return pBuffer; 
        }
        }while(*(int*)rem_user<0 || *(int*)rem_user>*(int*)n_users);

    for(*(int*)contador = *(int*)rem_user-1; *(int*)contador < *(int*)n_users; *(int*)contador = *(int*)contador+1){    //i = num do usuario a ser removido; enquanto i < n_users; i++
        pessoas[*(int*)contador] = pessoas[*(int*)contador+1];
    }
    *(int*)contador = 0; 
    *(int*)rem_user = 0;
    *(int*)n_users = *(int*)n_users - 1;
    return pBuffer; 
}