#ifndef IOHANDLER_H_INCLUDED
#define IOHANDLER_H_INCLUDED

typedef struct{
    int* desordenado;
    int* ordenado;
    int tamanho; 
}vetores;

void mostrar_vetores(vetores* x);

void randomizar(vetores* x);

vetores* escolher_tamanho(vetores* x);

#endif
