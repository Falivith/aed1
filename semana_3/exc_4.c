#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <windows.h> //apenas pra acentuação em conjunto com a primeira linha do main

typedef struct data{
char nome[11];
char telefone[9];
int idade;
}Pessoa; 

Pessoa pessoas[10];

void* menu_agenda(void *pBuffer);
/*void* add_cadastro(void *pBuffer);
void* listar_cadastro(void *pBuffer);
void* buscar_cadastro(void *pBuffer);
void* rem_cadastro(void *pBuffer);*/



int main(){
SetConsoleOutputCP(65001);
void* pBuffer = malloc(4*sizeof(int));
*(int*)pBuffer = 1;                           //1º Campo de pBuffer = controle do while do menu

    while(*(int*)pBuffer){                    //1º Campo de pBuffer = controle do while do menu
    menu_agenda(pBuffer);
    }

return 0;
}

