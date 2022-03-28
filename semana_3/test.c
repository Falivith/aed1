#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <windows.h>

typedef struct{
char nome[30];
int idade;
float altura;
}Pessoa;

int main(){

SetConsoleOutputCP(65001);

int exit_flag = 1, n_clientes = 0;
Pessoa *todas_contas = malloc(2*sizeof(Pessoa)); //Inicializa o Buffer, contendo espaço pra uma pessoa.
printf("%d", sizeof(Pessoa));
printf("\nDigite 0 no NOME caso deseje sair do programa e imprimir os usuários.\nNo caso da altura, o digito separador de casa decimal é o ponto (.)");

   printf("nome: ");
   fgets(todas_contas->nome, 30, stdin);
   
   printf("%s", todas_contas->nome);
   
   todas_contas = todas_contas + sizeof(Pessoa);

   printf("nome: ");
   fgets(todas_contas->nome, 30, stdin);

   printf("%s", todas_contas->nome);

return 0;  
}
