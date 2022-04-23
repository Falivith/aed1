/*  Ulian Gabriel Alff Ramires; 
 *  Matrícula Nº 20200274; 
 *  3º Semestre AED1;
 *  Exercício 3 Agenda (Extendido);
 *  Todas as variáveis devem ser ponteiros, tem que usar PILHA pra ordenar as pessoas. 
 *  A Base de dados deve ser implementada com lista encadeada duplamente ligada. 
 *
 *  Struct{             Imaginárias

 *  char nome[30];
 *  int idade;
 *  int telefone; 
 *  void* anterior; 
 *  void* proximo;
 *  }Nodo;             (46 Bytes)
 * 
 *  pBUffer {[0]int aux1, [1]int aux2, [2]int n_nodos} (12 Bytes)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>  /*Acentos*/

#define STRUCT_SIZE 46 
#define PBUFFER_SIZE 12 

void* create_node ();
void printlist (void* start, void* pBuffer);
void* insert (void* start, void* nodo, void* pBuffer); 
bool reset (void* pBuffer, void* start);
bool empty (void* pBuffer, void* start); 

int main(){

    SetConsoleOutputCP(65001); /*Acentos*/

    /*| Os primeiros 2 inteiros do Buffer são variáveis auxiliares |*
     *| usadas para menus, contadores de for, switch, etc.         |*
     *| Nessa função, o primeiro inteiro de pBuffer é o "EXIT" do  |*
     *| do/while. O segundo inteiro é a opção do Switch/case.      |*
     *| O terceiro campo é a quantidade de nodos (sentinela)       |*/

    void* pBuffer = malloc(PBUFFER_SIZE);
                            
    ((int*)pBuffer)[0] = 1;                                     // |* Acessando void* como inteiros, pra poder usar esse índice
    ((int*)pBuffer)[2] = 0;                                     // |* Usando um índice pois todos os dados de pBuffer tem 4 bytes

    void* start = NULL; 

    do{
        
        printf("\n");
        printf("|--------------------------|\n");
        printf("| 1) Incluir novo cadastro |\n");
        printf("| 2) Excluir cadastro      |\n");
        printf("| 3) Buscar cliente        |\n");
        printf("| 4) Listar clientes       |\n");
        printf("| 5) Reiniciar cadastros   |\n");
        printf("| 6) Sair                  |\n");
        printf("|--------------------------|\n");
        scanf("%d", &( (int*)pBuffer)[1] );
        getchar();

        switch(((int*)pBuffer)[1]){

            case 1:
                start = insert(start, create_node(), pBuffer);
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
                printlist(start, pBuffer);
            break;

            case 5:
            break;

            case 6:
            *(int*) pBuffer = 0; 
            break;

            default:
            break;
        }

    }while(*(int*)pBuffer);

    free(pBuffer);
    return 0;
}

void* create_node (){

    void* nodo = malloc( 30*sizeof(char) + 2*sizeof(int) + 2*sizeof(void**) );

    printf("\nInsira o nome do novo usuário: ");
    scanf("%s", (char*)nodo);
    getchar(); 
        nodo = nodo + 30;  

    printf("Insira a idade do novo usuário: ");
    scanf("%d", (int*)nodo);
    getchar(); 
        nodo = nodo + 4; 

    printf("Insira o telefone do novo usuário: ");
    scanf("%d", (int*)nodo);
    getchar();
        nodo = nodo + 4; 

        *(void**)nodo = NULL; 
        nodo = nodo + 4; 
        *(void**)nodo = NULL; 

        nodo = nodo - 42; 

    return nodo; 
}

void* insert (void* start, void* novo_nodo, void* pBuffer){    //por enquanto, ela adiciona um elemento numa lista vazia.

    void* atual = start; 

    if(atual == NULL){  //cuida do caso em que a lista está vazia
        atual = novo_nodo;
    }

    while(atual != NULL && (strcmp( (char*)atual, (char*)novo_nodo) < 1) ){ //se a lista nao estiver vazia, mas não for o momento de inserir (proximo nodo)
    atual = *(void**)(atual + 42); 
    }

    
    ((int*)pBuffer)[2]++; 
    return start; 
}

bool reset (void* pBuffer, void* start){
return true;
}

bool empty (void* pBuffer, void* start){
return true;
}

void printlist (void* start, void* pBuffer){
    
    void* atual = start;

    while(atual != NULL){
        printf("\n<Nodo %d>\nNome do usuário: <%s>", ((int*)pBuffer)[2], (char*)atual);
        atual = atual + 30;
        printf("\nIdade: <%d>", *(int*)atual);
        atual = atual + 4; 
        printf("\nTelefone: <%d>", *(int*)atual);
        atual = atual + 4; 
        atual = *(void**)atual; 
    }
}