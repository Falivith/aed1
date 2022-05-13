#include "sortalgs.h"

void selection_sort(int* vetor, int size){

    int i, j, menor_valor, indice, temp;
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

void insertion_sort(int* vetor, int size){

    int i, j, temp; 

    for(i = 1; i < size; i++){
        for(j = i; vetor[j] < vetor[j-1] && (j-1) >= 0; j--){

            temp = vetor[j];
            vetor[j] = vetor[j-1];
            vetor[j-1] = temp;
        }
    }
}
