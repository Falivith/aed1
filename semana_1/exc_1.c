/*Ulian Gabriel Alff Ramires
* Matrícula Nº 20200274
* Cursando no terceiro semestre AED1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> //apenas acentuação, pode ser retirado em conjunto com a primeira linha do main

char* addnome(char* str);
char* remnome(char* str);

int main(){
SetConsoleOutputCP(65001);

int exit = 1, controle, case_loop = 1;
char *string = calloc(2 ,sizeof(char));
strcat(string, "|\0");

while(exit){
    printf("\n1) Adicionar nomes \n");
    printf("2) Remover nomes \n");
    printf("3) Listar nomes \n"); 
    printf("4) Sair \n");
    printf("\nDigite o número da opção: ");

    scanf("%d", &controle);
    getc(stdin);

    switch (controle){
        case 1:
            case_loop = 1;
            while (case_loop)
            {
            string = addnome(string);
            printf("\nDigite 1 pra adicionar outro nome, e 0 para voltar ao MENU: ");
            scanf("%d", &case_loop);
            getchar();
            }
        break;

        case 2:
            case_loop = 1;
            while (case_loop)
            {
            remnome(string);
            printf("\nDigite 1 pra remover outro nome, e 0 para voltar ao MENU: ");
            scanf("%d", &case_loop);
            getchar();
            }
        break;

        case 3:
        printf("\n   %s\n\n", string);
        break;

        case 4:
        exit = 0; 
        break; 

        default: 
        break; 
    }
}

free(string);
return 0;
}

char* addnome(char* str){
    int str_length, buffer_length;
    char div[] = "|";
    char temp_str[25];
    printf("\nInsira o nome: ");
    scanf("%s", temp_str);
    getc(stdin);
    strcat(temp_str, div); //adiciona o marcador
    buffer_length = strlen(temp_str);
    str_length = strlen(str);
    realloc(str, sizeof(str)+sizeof(char)*buffer_length); //soma a memória já alocada com o tamanho do nome
    strcat(str, temp_str); //adiciona o nome
    return str;
}

char* remnome(char* str){
    int tamanho, i;
    char buffer[50];
    char div[] = "|";
    char *start, *end; 
    printf("\nInsira o nome a ser removido da lista: ");
    scanf("%s", buffer);
    getc(stdin);



    strcat(buffer, div);
    tamanho = strlen(buffer);
    start = strstr(str, buffer); //achado o ponteiro pro começo da palavra a ser retirada, ou Null caso ela n exista
    end = start;  //guarda o local do começo da palavra a ser retirada
        for(i=0; i<tamanho; i++)
        end++; //end agora aponta pra primeira letra da proxima palavra 
    memmove(start, end, strlen(end)+1); //sobrescreve a palavra com o restante da string. o +1 é importantissimo no memmove, para trazer o caractere nulo também. 
    return str; 
}