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
    int temp_idade, tel_size = 0, n_cliente, i, size_dados;
    char temp_nome[11], telefone[9];

    printf("\n\nDigite o nome do cliente: ");
    fgets(temp_nome, sizeof(temp_nome), stdin);
    printf("\nDigite a idade do cliente: ");
    scanf("%d", &temp_idade);   getc(stdin);

        while(tel_size =! 8){
        printf("\n(8 caracteres) Digite o telefone do cliente: ");
        fgets(telefone, sizeof(telefone), stdin);
        tel_size = strlen(telefone);
        }

    n_cliente = (int*) pBuffer;
    size_dados = sizeof(int) + n_cliente * (sizeof(temp_nome) + sizeof(telefone) + sizeof(temp_idade) );

    pBuffer = realloc(pBuffer, sizeof(int)+size_dados); 

        p = p + size_dados;               //pula o numero de clientes e vai para o campo nome
            memset(p, '\0', sizeof(temp_nome));  
            strcat(p, temp_nome);               //preenche o campo nome
        p = p + sizeof(temp_nome);      //pula o tamanho do nome e vai para o campo idade
            p = temp_idade;                     //preenche a idade
        p = p + sizeof(int);            //pula o tamanho da idade e vai para o campo telefone
            memset(p, '\0', sizeof(telefone)); 
            strcat(p, telefone);                //preenche o telefone

    *pBuffer++; //o conteudo do endereço 0 é um int, logo, incrementar pBuffer aumenta o n de clientes
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