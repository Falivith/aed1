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

void quick_sort(int* vetor, int inicio, int fim){

    int temp, pivot, i, j;

    i = inicio; 
    j = fim;
    pivot = vetor[(inicio + fim)/2];

    do{
        while(vetor[i] < pivot)
        i++;
        while(pivot < vetor[j])
        j--;

        //SWAP
        if(i <= j){
            temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
            i++;
            j--;
        }
    }while(i <= j);

    if(inicio < j)
    quick_sort(vetor, inicio, j);

    if(i < fim)
    quick_sort(vetor, i, fim);
}
