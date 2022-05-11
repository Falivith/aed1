#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "avltree.h"

int main(){

    SetConsoleOutputCP(65001);
    srand(time(0));

    int num, choice, exit, i;
    struct Nodo* raiz = NULL;

    do{ 
        printf("\n");
        printf("|---------------------------------|\n");
        printf("| 1) Inserir valor                |\n");
        printf("| 2) Inserir X Valores Randômicos |\n");
        printf("| 3) Deletar valor                |\n");
        printf("| 4) Printar Árvore               |\n");
        printf("| 5) É AVL?                       |\n");
        printf("| 6) Deletar Árvore               |\n");
        printf("| 7) Deletar e Sair               |\n");
        printf("|---------------------------------|\n");
        printf("\n-> ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Digite o valor a ser inserido na Árvore: ");
                scanf("%d", &num);
                raiz = inserir(raiz, criar(num)); 
                break;

            case 2:
                printf("Digite o número de nodos randômicos a serem adicionados: ");
                scanf("%d", &num);
                
                for(i = 0; i < num; i++){
                    raiz = inserir(raiz, criar(rand() % 100));
                    printf("\nInserido com Sucesso");
                }

                break;

            case 3:
                printf("Digite o valor a ser deletado da Árvore: ");
                scanf("%d", &num);
                raiz = deletar(raiz, num);
                break;

            case 4:
                print(raiz, SPACE);
                break;

            case 5:
                if (EhArvoreAvl(raiz))
                printf("\n é AVL.");
                else
                printf("\n Não é AVL.");
                break;

            case 6:
                limpar(raiz);
                raiz = NULL;
            break;

            default:
                limpar(raiz);
                raiz = NULL;
                exit = 0; 
                break;
        }
    }
    while(exit);

    return 0;
}