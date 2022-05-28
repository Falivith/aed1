#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "iohandler.h"
#include "sortalgs.h"

int main (){

  int escolha, sair = 1;

  clock_t inicio;
  clock_t fim;
  double tempo; 

  vetores *x = (vetores*)malloc(sizeof(vetores));
  x->desordenado = (int*)malloc(sizeof(int));
  x->ordenado = (int*)malloc(sizeof(int));

  x = escolher_tamanho(x);
  system("clear");

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
        system("clear");
        printf("\n\nVetor aleatório gerado com sucesso.\n");
        break;

      case 2:
        escolher_tamanho(x);
        system("clear");
        break;

      case 3:
        system("clear");
        
        inicio = clock();
          selection_sort(x->ordenado, x->tamanho);
        fim = clock();
        
        mostrar_vetores(x);
        tempo = (double)(fim - inicio)/CLOCKS_PER_SEC;
        printf("\nTempo medido (Selection Sort): %.3f segundos.\n", tempo);
        break;

      case 4:
        system("clear");
        
        inicio = clock();
          insertion_sort(x->ordenado, x->tamanho);
        fim = clock();
        
        mostrar_vetores(x);
        tempo = (double)(fim - inicio)/CLOCKS_PER_SEC;
        printf("\n\nTempo medido (Insertion Sort): %.3f segundos.\n", tempo);
        break;

      case 5:
        system("clear");
      
        inicio = clock();
          quick_sort(x->ordenado, 0, x->tamanho-1);
        fim = clock();

        mostrar_vetores(x);
        tempo = (double)(fim - inicio)/CLOCKS_PER_SEC;
        printf("\n\nTempo medido (Quick Sort): %.3f segundos.\n", tempo);
        break;

      case 6:
        system("cls");
        
        inicio = clock();
        merge_sort(x->ordenado, 0, x->tamanho-1);
        fim = clock();
        
        mostrar_vetores(x);
        tempo = (double)(fim - inicio)/CLOCKS_PER_SEC;
        printf("\n\nTempo medido (Merge Sort): %.3f segundos.\n", tempo);
        break;

      case 7:
        sair = 0;
        break;
    }
  }

  free(x->desordenado);
  free(x->ordenado);
  free(x);

  return 0;
}
