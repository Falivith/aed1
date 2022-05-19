#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "iohandler.h"
#include "sortalgs.h"

int main (){

    SetConsoleOutputCP(65001);

    int escolha, sair = 1;

    vetores *x = (vetores*)malloc(sizeof(vetores));
    x->desordenado = (int*)malloc(sizeof(int));
    x->ordenado = (int*)malloc(sizeof(int));

    x = escolher_tamanho(x);

    while(sair){
        printf("\n");
        printf(" _________________________________\n");
        printf("| -> Tamanho Atual <%05d>        |\n", x->tamanho);
        printf("|                                 |\n");
        printf("| 1) Gerar outro Vetor            |\n");
        printf("| 2) Escolher tamanho do vetor    |\n");
        printf("| 3) Selection Sort + Print       |\n");
        printf("| 4) Insertion Sort + Print       |\n");
        printf("| 5) Quick Sort + Print           |\n");
        printf("| 6) Merge Sort + Print           |\n");
        printf("| 7) Sair                         |\n");
        printf("|_________________________________|\n");
        printf("\n-> ");
        scanf("%d", &escolha);
        
        switch(escolha){

            case 1:
                randomizar(x);
                printf("\nVetor aleatório gerado com sucesso.\n");
                break;

            case 2:
                escolher_tamanho(x);
                break;

            case 3:
                selection_sort(x->ordenado, x->tamanho);
                system("cls");
                mostrar_vetores(x);
                break;

            case 4:
                insertion_sort(x->ordenado, x->tamanho);
                system("cls");
                mostrar_vetores(x);
                break;

            case 5:
                quick_sort(x->ordenado, 0, x->tamanho-1);
                system("cls");
                mostrar_vetores(x);
                break;

            case 6:
                system("cls");
                mostrar_vetores(x);
                break;

            case 7:
                sair = 0;
                break;
        }
    }

    return 0;
}
