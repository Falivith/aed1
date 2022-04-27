#include <stdio.h>

int main(){

    int variavel1, variavel2,  retorno; 

    retorno = scanf("%d, %d", &variavel1, &variavel2);

    printf("Retorno: %d\n", retorno);
    printf("Variavel 1: %d\n", variavel1);
    printf("Variavel 2: %d\n", variavel2);

    return 0;

}