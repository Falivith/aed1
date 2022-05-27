#ifndef SORTALGS_H_INCLUDED
#define SORTALGS_H_INCLUDED

void selection_sort(int* vetor, int size);

void insertion_sort(int* vetor, int size);

void quick_sort(int* vetor, int inicio, int fim);

int* merge_sort(int* vetor, int size);

int* merge(int* left, int* right, int sz_left, int sz_right);

#endif
