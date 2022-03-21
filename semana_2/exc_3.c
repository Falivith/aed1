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
void* rem_cadastro(void *pBuffer);


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
        printf("\nOpção: ");
        scanf("%d", &option);
        getc(stdin);

        switch(option)
        {
        case 1:
            pBuffer = add_cadastro(pBuffer);
        break;

        case 2:
            pBuffer = rem_cadastro(pBuffer);
        break;

        case 3:
            pBuffer = buscar_cadastro(pBuffer);
        break;

        case 4:
            pBuffer = listar_cadastro(pBuffer);
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

    *(int*)pBuffer = *(int*)pBuffer + 1; //o conteudo do endereço 0 é um int, logo, incrementar pBuffer aumenta o n de clientes
    void *p; 
    int temp_idade, tel_size = 0, n_cliente, size_dados;
    char temp_nome[TAM_NOME], telefone[TAM_TELEFONE];

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


    return p; //retorna o endereço de p, que é na verdade o endereço inicial de pBuffer que foi guardado antes dele começar a preencher os campos
    }

void* listar_cadastro(void *pBuffer){

    void *p;
    p = pBuffer;                     //guarda o endereço inicial de pBuffer
    int n_clientes, i;
    n_clientes = *(int*)pBuffer; 
    pBuffer = pBuffer + sizeof(int); //pula o numero de clientes

        for(i=0; i<n_clientes; i++){
            printf("\nCliente Nº %d:", i+1);
            printf("\nNome: %s", (char*)pBuffer);
            pBuffer = pBuffer + TAM_NOME; 
            printf("\nIdade: %d", *(int*)pBuffer); 
            pBuffer = pBuffer + sizeof(int);
            printf("\nTelefone: %s", (char*)pBuffer);
            pBuffer = pBuffer + TAM_TELEFONE;
            printf("\n\n");
        }

    return p;
}

void* buscar_cadastro(void *pBuffer){

    void *p = pBuffer;        
    int n_clientes, i, option, verificador = 0, temp_idade;
    n_clientes = *(int*)pBuffer;
    char temp_nome[TAM_NOME], temp_telefone[TAM_TELEFONE];
    pBuffer = pBuffer + sizeof(int); //pula o numero de clientes

    printf("\n||||||||||||||||||\n1) Nome\n2) Telefone\n3) Idade\n4) Voltar ao Menu\n||||||||||||||||||\n\nVocê deseja procurar o cliente via: ");
    scanf("%d", &option); getc(stdin);

        switch(option){
            case 1: 
                printf("Digite o nome do cliente: ");
                fgets(temp_nome, TAM_NOME, stdin);
                temp_nome[strcspn(temp_nome, "\n")] = 0;
                    for(i=0; i<n_clientes; i++){
                        if(strcmp(temp_nome, (char*)pBuffer) == 0){
                            printf("\nO cliente %s é o de número %d na lista.\n", temp_nome, i+1);
                            printf("\nNome: %s", (char*)pBuffer);
                            pBuffer = pBuffer + TAM_NOME;
                            printf("\nIdade: %d", *(int*)pBuffer);
                            pBuffer = pBuffer + sizeof(int);
                            printf("\nTelefone: %s\n", (char*)pBuffer);
                            verificador++;
                            break;
                        }
                        else{pBuffer = pBuffer + sizeof(int) + TAM_NOME + TAM_TELEFONE;} //avança até o próximo nome
                    }
                    if(verificador == 0) printf("\n--| Erro: Não foram encontrados cadastros com esse nome. |--");
            break;

            case 2:
                printf("\nDigite o Nº de telefone a ser procurado na base de dados: ");
                fgets(temp_telefone, TAM_TELEFONE, stdin);
                temp_telefone[strcspn(temp_telefone, "\n")] = 0;
                pBuffer = pBuffer + TAM_NOME + sizeof(int); //pula pro campo telefone
                    for(i=0; i<n_clientes; i++){
                        if(strcmp(temp_telefone, (char*)pBuffer) == 0){
                            printf("\nCliente Nº%d\n", i+1);
                            pBuffer = pBuffer - TAM_NOME - sizeof(int); //volta pro campo nome
                            printf("\nNome: %s", (char*)pBuffer);
                            pBuffer = pBuffer + TAM_NOME;
                            printf("\nIdade: %d", *(int*)pBuffer);
                            pBuffer = pBuffer + sizeof(int);
                            printf("\nTelefone: %s\n", (char*)pBuffer);
                            verificador++;
                            break;
                        }
                        else{pBuffer = pBuffer + sizeof(int) + TAM_NOME + TAM_TELEFONE;} //avança até o próximo telefone
                    }
                if(verificador == 0) printf("\n--| Erro: Não foram encontrados clientes com esse Nº de Telefone |--");
            break;

            case 3:
                printf("\nDigite a idade do cliente: ");
                    scanf("%d", &temp_idade); getc(stdin);
                    pBuffer = pBuffer + TAM_NOME; //pula pro campo idade.
                    for(i=0; i<n_clientes; i++){
                        if(temp_idade == *(int*)pBuffer){
                            pBuffer = pBuffer - TAM_NOME;
                            printf("\nCliente Nº%d: ", i+1);
                            printf("\nNome: %s", (char*)pBuffer);
                            pBuffer = pBuffer + TAM_NOME;
                            printf("\nIdade: %d", *(int*)pBuffer);
                            pBuffer = pBuffer + sizeof(int);
                            printf("\nTelefone: %s\n", (char*)pBuffer);
                            pBuffer = pBuffer + TAM_TELEFONE + TAM_NOME;
                            verificador++;
                        }
                        else{
                            pBuffer = pBuffer + sizeof(int) + TAM_NOME + TAM_TELEFONE; //avança até a proxima idade
                        }
                    }
                    if(verificador == 0)printf("\n--| Erro: Não foram encontrados cadastros com essa idade. |--");
            break;

            case 4:
            break;

            default: 
            break;
            }
    return p; 
}

void* rem_cadastro(void *pBuffer){
    int x_cli = 0, size_dados, n_clientes = *(int*)pBuffer;
    void *start, *end; 
    start = pBuffer;
    if(n_clientes<1)return pBuffer;
    size_dados = sizeof(int) + TAM_NOME + TAM_TELEFONE;

        do{
        printf("\nInsira o Nº do usuário a ser excluido: "); //laço pra evitar valores invalidos de cliente
        scanf("%d", &x_cli); getc(stdin);
        }while(x_cli<1 || x_cli>n_clientes);

    start = start + sizeof(int);
    start = start + (x_cli-1)*size_dados;
    end = start; 
    end = end + size_dados;
    memmove(start, end, (n_clientes*size_dados - x_cli*size_dados) ); //sobrescreve o conteudo.
    pBuffer = realloc(pBuffer, sizeof(int) + (n_clientes-1)*size_dados); 
    *(int*)pBuffer = *(int*)pBuffer - 1;  
    return pBuffer;
}