/*Ulian Gabriel Alff Ramires
* Matrícula Nº 20200274
* Cursando no terceiro semestre AED1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <windows.h>

/*struct dados{ 
    int idade;
    int telefone;
    char nome[10];
};*/

void* add_cadastro(void *pBuffer);

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
    p = pBuffer;
    int temp_idade, tel_size = 0, n_cliente, size_dados;
    char temp_nome[11], telefone[9];

    printf("\nDigite o nome do cliente: ");
    fgets(temp_nome, sizeof(temp_nome), stdin);
    printf("Digite a idade do cliente: ");
    scanf("%d", &temp_idade);   getc(stdin);

        while(tel_size != 8){
        printf("(8 caracteres) Digite o telefone do cliente: ");
        fgets(telefone, sizeof(telefone), stdin);
        tel_size = strlen(telefone);
        }

    n_cliente = *(int*)pBuffer;
    size_dados = sizeof(int) + n_cliente * (sizeof(temp_nome) + sizeof(telefone) + sizeof(int));  //calcula a quantidade de memória necessária pro cadastro
    pBuffer = realloc(pBuffer, size_dados); 

        pBuffer = pBuffer + sizeof(int);                             //pula o numero de clientes e vai para o campo nome
            memmove((char*)pBuffer, temp_nome, sizeof(temp_nome)); //preenche o campo nome
        pBuffer = pBuffer + sizeof(temp_nome);                       //pula o tamanho do nome e vai para o campo idade
            *(int*)pBuffer = temp_idade;                              //preenche a idade
        pBuffer = pBuffer + sizeof(int);                             //pula o tamanho da idade e vai para o campo telefone
            memmove((char*)pBuffer, telefone, sizeof(telefone));   //prenche o telefone

    return p; //retorna o endereço de p, que é na verdade o endereço inicial de pBuffer que foi guardado antes dele começar a preencher os campos
    }