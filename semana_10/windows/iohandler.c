#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "iohandler.h"

vetores* escolher_tamanho(vetores* x){
    
    do 
    {   printf(" _________________________________\n");
        printf("|                                 |\n");
        printf("| -> Insira o tamanho desejado    |\n");
        printf("|    do vetor a ser ordenado.     |\n");
        printf("|_________________________________|\n");
        printf("\n-> ");
        scanf("%d", &x->tamanho);
    }
    while(x->tamanho < 1 || x->tamanho > TAMANHO_MAXIMO);

    x->desordenado = (int*)realloc(x->desordenado, x->tamanho*sizeof(int));
    x->ordenado = (int*)realloc(x->ordenado, x->tamanho*sizeof(int));
    randomizar(x);

    return x; 
}

void randomizar(vetores* x){

    srand(time(NULL));
    int i, random;

    for(i = 0; i < x->tamanho; i++){
        random = rand() % 100;
        x->desordenado[i] = random;
        x->ordenado[i] = random;
    }
}

void mostrar_vetores(vetores* x){

    int i; 

    printf("\nSeu vetor anteriormente desordenado: "); 
        for(i = 0; i < x->tamanho; i++)
            printf("%02d ", x->desordenado[i]); 
    printf("\n\nAgora, vetor ordenado: "); 
        for(i = 0; i < x->tamanho; i++)
            printf("%02d ", x->ordenado[i]);
    printf("\n\n-> Warning: Ordenar novamente sem gerar outro vetor irá forçar o caso de ordenação em uma lista já ordenada.\n"); 
}
