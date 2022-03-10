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

int exit = 1, controle, case_1 = 1;
char buffer[50];
char *string = malloc(sizeof(char));
memset(string, 0, 1); //limpar lixo

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
            case_1 = 1;
            while (case_1)
            {
            addnome(string);
            printf("\nDigite 1 pra adicionar outro nome, e 0 para voltar ao MENU: ");
            scanf("%d", &case_1);
            getchar();
            }
        break;

        case 2:
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

return 0;
}

char* addnome(char* str){
    int tamanho;
    char div[] = "|";
    char buffer[50];
    printf("\nInsira o nome: ");
    scanf("%s", &buffer);
    getc(stdin);
    tamanho = strlen(buffer);
    realloc(str, (sizeof(str)+sizeof(div))+(tamanho*sizeof(char))); //soma a memória já alocada com o tamanho do nome +1 da divisão
    
    strcat(str, buffer); //adiciona o nome
    strcat(str, div); //adiciona o marcador
    return *str;
}

char* remnome(char* str){
    int tamanho, i;
    char buffer[50];
    char* ptr, ptr_1; 
    printf("\nInsira o nome a ser removido da lista: ");
    scanf("%s", buffer);
    tamanho = strlen(buffer);
    ptr = strstr(str, buffer); //achado o ponteiro pro começo da palavra a ser retirada, ou Null caso ela n exista
    //memset(ptr, 0, tamanho+1); //substitui o nome e o seguinte caractere de divisão por 0

    for(i=0; i<=tamanho; i++){ //pula a palavra a ser tirada + o caractere divisor
    ptr++; 
    } 


}