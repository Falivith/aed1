#include "sortalgs.h"
#include <string.h>
#include <stdlib.h>

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

        temp = vetor[i]; 
        j = i-1; 

        while(temp < vetor[j] && j >= 0){
            vetor[j+1] = vetor[j];
            j--;
        }
    
        vetor[j+1] = temp; 
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

int* merge_sort(int* vetor, int size){ 
    
    //Implementei em inglês porque esquerda/direita fica muito confuso devido ao tamanho das palavras, right/left é mais conciso 

    //Base

    if(size <= 1)
    return vetor;

    int i, j, mid = size/2;
    int sz_left = mid;
    int sz_right = mid;

    if(size % 2 == 1)
        sz_right = mid+1; 

    int* left = malloc(sz_left*sizeof(int));
    int* right = malloc(sz_right*sizeof(int));

    for(i = 0; i < mid; i++)
        left[i] = vetor[i];

    for(j = 0; i < size; i++, j++)
        right[j] = vetor[i];

    left = merge_sort(left, sz_left);
    right = merge_sort(right, sz_right);

    vetor = merge(left, right, sz_left, sz_right);

    free(left);
    free(right);

    return vetor; 
}

int* merge(int* left, int* right, int sz_left, int sz_right){

    int* result = malloc((sz_left + sz_right) * sizeof(int));

    int i = 0, j = 0, k = 0; 

    while(sz_left > 0 || sz_right > 0){
        if(sz_left > 0 && sz_right > 0){
            if(left[i] <= right[j]){
                result[k] = left[i];
                i++;
                k++;
                sz_left--;
            }
            else{
                result[k] = right[j];
                j++;
                k++;
                sz_right--; 
            }
        }
        else 
            if(sz_left > 0){
                while(sz_left > 0){
                    result[k] = left[i];
                    i++;
                    k++;
                    sz_left--;
                }
            }
            else{
                while(sz_right > 0){
                    result[k] = right[j];
                    j++;
                    k++;
                    sz_right--; 
                }
            }
    }
    return result;
}