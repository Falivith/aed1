#include <stdio.h>
#include <windows.h>
#include <time.h>

#define SIZE 50

void mostrar_vetores(int* desordenado, int* ordenado, int size){

    int i; 

    printf("\nSeu vetor desordenado: "); 
        for(i = 0; i < size; i++)
            printf("%d ", desordenado[i]); 
    printf("\nAgora, vetor ordenado: "); 
        for(i = 0; i < size; i++)
            printf("%d ", ordenado[i]); 
}

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

        for(j = i; vetor[j] < vetor[j-1]; j--){

            temp = vetor[j];
            vetor[j] = vetor[j-1];
            vetor[j-1] = temp;
        }
    }
}

int main (){

    SetConsoleOutputCP(65001);
    srand(time(NULL));
    int i, random, desordenado[SIZE], ordenado[SIZE];
    int sair, escolha; 

    for(i = 0; i < SIZE; i++){
        random = rand() % 100;
        desordenado[i] = random;
        ordenado   [i] = random;
    }

    while(sair){
        printf("\n");
        printf(" _________________________________\n");
        printf("|                                 |\n");
        printf("| 1) Gerar outro Vetor            |\n");
        printf("| 2) Selection Sort + Print       |\n");
        printf("| 3) Insertion Sort + Print       |\n");
        printf("| 4) Sair                         |\n");
        printf("|_________________________________|\n");
        printf("\n-> ");
        scanf("%d", &escolha);
        
        switch(escolha){

            case 1:
                for(i = 0; i < SIZE; i++){
                    random = rand() % 100;
                    desordenado[i] = random;
                    ordenado   [i] = random;
                }

                printf("\nVetor aleatório gerado com sucesso.\n");
                break;

            case 2:
                selection_sort(ordenado, SIZE);
                mostrar_vetores(desordenado, ordenado, SIZE);
                break;

            case 3:
                insertion_sort(ordenado, SIZE);
                mostrar_vetores(desordenado, ordenado, SIZE);
                break;

            case 4:
                sair = 0;
                break;
        }
    }

    return 0;
}