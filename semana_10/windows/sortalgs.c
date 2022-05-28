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
    int contador; 

    for(i = 1; i < size; i++){

        temp = vetor[i]; 
        j = i-1; 
        contador = 0;

        while(temp < vetor[j] && j >= 0){
            contador++; 
            j--;
        }

        if(contador > 0){
            memmove(&vetor[j+2], &vetor[j+1], (contador) * sizeof(int));
            vetor[j+1] = temp;
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

void merge_sort(int* vetor, int esq, int dir){

    /* Enquanto o índice da subarray da esquerda for menor que a da 
    direita, ele continuará dividindo em outras 2 subarrays. */

    if(esq < dir){
        int meio = (dir + esq) / 2;
        merge_sort(vetor, esq, meio);
        merge_sort(vetor, meio + 1, dir);
        merge(vetor, esq, meio, dir);
    }
}

void merge(int* vetor, int esq, int meio, int dir){

    /* O Tamanho das subarrays é dado pela diferença do índice mais 
    a direita pro índice mais a esquerda. */
    
    int* temp_esq = malloc((meio - esq + 1) * sizeof(int));
    int* temp_dir = malloc((dir - meio) * sizeof(int));

    int sz_esq = meio - esq + 1; 
    int sz_dir = dir - meio; 
    int i, j, k;

    for(i = 0; i < sz_esq; i++)
        temp_esq[i] = vetor[esq + i];

    for(j = 0; j < sz_dir; j++)
        temp_dir[j] = vetor[meio + j + 1];

    /* Merge das subarrays de volta na array principal */

    i = 0;
    j = 0;
    k = esq; 

    while(sz_esq > 0 || sz_dir > 0){                       /* Enquanto 1 dos dois lados tiverem conteúdo                    */
        if(sz_esq > 0 && sz_dir > 0){                      /* Se os dois tiverem então                                      */
            if(temp_esq[i] <= temp_dir[j]){                /* Se o primeiro da esquerda for menor que o primeiro da direita */
                vetor[k] = temp_esq[i];                    
                i++;                                       /*  É inserido ele no vetor principal e são incrementados    */
                k++;                                       /*  os índices do vetor principal, do subvetor à esquerda    */
                sz_esq--;                                  /*  e decrementado o "tamanho" do subvetor à esquerda        */
            }
            else{                                          /* Se não, o mesmo é feito com o subvetor da direita */                                  
                vetor[k] = temp_dir[j];
                j++;
                k++;
                sz_dir--; 
            }
        }
        else{                                              /* Casos onde um dos lados estão vazios */    
            if(sz_esq > 0){
                while(sz_esq > 0){
                    vetor[k] = temp_esq[i];
                    i++;
                    k++;
                    sz_esq--;
                }
            }
            else{
                while(sz_dir > 0){
                    vetor[k] = temp_dir[j];
                    j++;
                    k++;
                    sz_dir--; 
                }
            }
        }
    }
    free(temp_dir);
    free(temp_esq);
}