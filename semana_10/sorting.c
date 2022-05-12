#include <stdio.h>
#include <windows.h>
#include <time.h>

#define SIZE 50

void selection_sort(int* vetor, int size){

    int j, i, menor_valor, indice, temp;
    int existe_menor; 

    for(i = 0; i < size-1 ; i++){

        menor_valor = vetor[i];
        existe_menor = 0; 

        for(j = i+1; j < size; j++){
            if(vetor[j] <= menor_valor){
                menor_valor = vetor[j];
                indice = j;
                existe_menor = 1; 
            }
        }

        if(existe_menor){
        temp = vetor[i];
        vetor[i] = vetor[indice];
        vetor[indice] = temp;
        }
    }
}

int main (){

    srand(time(NULL));
    int i, vetor[SIZE];

    for(i = 0; i < SIZE; i++){
        vetor[i] = rand() % 100;
        printf("%d ", vetor[i]); 
    }

    selection_sort(vetor, SIZE);

    printf("\n\n"); 

    for(i = 0; i < SIZE; i++){
        printf("%d ", vetor[i]); 
    }

    return 0;
}