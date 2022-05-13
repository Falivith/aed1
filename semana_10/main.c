#include <stdio.h>
#include <windows.h>
#include <time.h>

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
        printf("|                       Size <%03d>|\n", x->tamanho);
        printf("| 1) Gerar outro Vetor            |\n");
        printf("| 2) Escolher tamanho do vetor    |\n");
        printf("| 3) Selection Sort + Print       |\n");
        printf("| 4) Insertion Sort + Print       |\n");
        printf("| 5) Sair                         |\n");
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
                sair = 0;
                break;
        }
    }

    return 0;
}
