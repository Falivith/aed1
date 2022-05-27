#ifndef SORTALGS_H_INCLUDED
#define SORTALGS_H_INCLUDED

void selection_sort(int* vetor, int size);

void insertion_sort(int* vetor, int size);

void quick_sort(int* vetor, int inicio, int fim);

void merge_sort(int* vetor, int esq, int dir);

void merge(int* vetor, int esq, int meio, int dir);

#endif
