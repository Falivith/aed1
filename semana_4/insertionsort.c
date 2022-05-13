#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 50

static int num_compar1 = 0;

int* Insertionsort(int *data, int n){
    int tmp, i, j;
    for (j = 1; j < n; j++){
        i = j-1;
        tmp = data [j];
        while( (i>=0) && (tmp < data[i]) ){
            data [i+1] = data [i];
            i--;

            num_compar1++;
            num_compar1++;
        }
        data[i+1] = tmp;
    }
    return data;
}

int main(){
    srand(time(0));
    int *conjunto = malloc(SIZE*sizeof(int));

    printf("\nVetor Randomico  >");
    for(int i = 0; i<SIZE; i++){
        conjunto[i] = rand() % 50;
        printf(" %2d ", conjunto[i]);
    }

    conjunto = Insertionsort(conjunto, SIZE);

    printf("\nVetor Ordenado   >");
    for(int i = 0; i<SIZE; i++){
        printf(" %2d ", conjunto[i]);
    }

    conjunto = Insertionsort(conjunto, SIZE);

    printf("\nVetor Reordenado >");
    for(int i = 0; i<SIZE; i++){
        printf(" %2d ", conjunto[i]);
    }
    printf("\n");

    return 0;
}
