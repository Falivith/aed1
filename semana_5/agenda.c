/*  Ulian Gabriel Alff Ramires; 
 *  Matrícula Nº 20200274; 
 *  3º Semestre AED1;
 *  Exercício 3 Agenda (Extendido);
 *  Todas as variáveis devem ser ponteiros, tem que usar PILHA pra ordenar as pessoas. 
 *  A Base de dados deve ser implementada com lista encadeada duplamente ligada. 
 */

/* Estrutura Imaginária, de tamanho 32 (31+\n) + 4 + 4 = 40 Bytes. 
 *
 *  char nome[31];
 *  int idade;
 *  int telefone; 
 *
 */

//TODO LIST: Menu está funcionando 100%. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>  /*Acentos*/
#define AUX_VAR 3
#define STRUCT 40 

void menu (void* pBuffer);
void 

int main(){

    SetConsoleOutputCP(65001); /*Acentos*/

    /*| Os primeiros N inteiros do Buffer são variáveis auxiliares |*
      | usadas para menus, contadores de for, etc.                 |*/

    void* pBuffer = malloc(AUX_VAR*sizeof(int));
    void* pilha = malloc(1);
    menu(pBuffer);
    free(pBuffer);
    free(pilha);
    return 0;
}

void menu (void* pBuffer){

    /*| Nessa função, o primeiro inteiro de pBuffer é o "EXIT" do  |*
      | do/while. O segundo inteiro é a opção do Switch/case.      |*/

      *(int*)pBuffer = 1;

    do{
        
        printf("|--------------------------|\n");
        printf("| 1) Incluir novo cadastro |\n");
        printf("| 2) Excluir cadastro      |\n");
        printf("| 3) Buscar cliente        |\n");
        printf("| 4) Listar clientes       |\n");
        printf("| 5) Sair                  |\n");
        printf("|--------------------------|\n");
        scanf("%d", &((int*)pBuffer)[1]);
        getchar();

        switch(((int*)pBuffer)[1]){

            case 1:
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
                *(int*) pBuffer = 0; 
            break;

            default:
            break;
        }

    }while(*(int*)pBuffer);
}