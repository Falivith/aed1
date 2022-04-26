#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>  /*Acentos*/

#define NODE_SIZE    46 
#define PBUFFER_SIZE 42 
#define TEMPNOME     12

/* Acesso aos elementos do nodo, para facilitar a organização */

#define IDADE    30
#define TELEFONE 34
#define PROXIMO  42
#define ANTERIOR 38

void* create_node ();
void* insert    (void* start, void* pBuffer, void* nodo);
void* exclude   (void* start, void* pBuffer);
void* restart   (void* start, void* pBuffer);
void  search    (void* start, void* pBuffer);
void  printlist (void* start, void* pBuffer);

int main(){

    SetConsoleOutputCP(65001); /*Acentos*/

    /*| Os primeiros 2 inteiros do Buffer são variáveis auxiliares |*
     *| usadas para menus, contadores de for, switch, etc.         |*
     *| Nessa função, o primeiro inteiro de pBuffer é o "EXIT" do  |*
     *| do/while. O segundo inteiro é a opção do Switch/case.      |*
     *| O terceiro campo é a quantidade de nodos (sentinela)       |*/

    void* pBuffer = malloc(PBUFFER_SIZE);
                            
    ((int*)pBuffer)[0] = 1;                                     // |* Acessando void* como inteiros, pra poder usar esse índice
    ((int*)pBuffer)[2] = 0;                                     // |* Usando um índice pois os dados de pBuffer exceto o TEMPNOME tem 4 bytes

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
                start = insert(start, pBuffer, create_node());
            break;

            case 2:
                start = exclude(start, pBuffer);
            break;

            case 3:
                search(start, pBuffer);
            break;

            case 4:
                printlist(start, pBuffer);
            break;

            case 5:
                start = restart(start, pBuffer);
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

    void* nodo = malloc(NODE_SIZE);

    printf("\nInsira o nome do novo usuário: ");
    scanf("%s", (char*)nodo);
    getchar(); 

    printf("Insira a idade do novo usuário: ");
    scanf("%d", &*(int*)(nodo + IDADE));
    getchar(); 

    printf("Insira o telefone do novo usuário: ");
    scanf("%d", &*(int*)(nodo + TELEFONE));
    getchar();

        *(void**)(nodo + ANTERIOR) = NULL; 

        *(void**)(nodo + PROXIMO) = NULL; 

    return nodo; 
}

void* insert (void* start, void* pBuffer, void* novo_nodo){ 

    // Caso 1: Lista vazia

    if(start == NULL){
        start = novo_nodo;
        ((int*)pBuffer)[2]++;
        return start;
    }

    // Caso 2: Inserção na Cabeça

    if((strcmp((char*)start, (char*)novo_nodo)) >= 0){
        *(void**)(novo_nodo + PROXIMO) = start;
        *(void**)(start + ANTERIOR) = novo_nodo;
        start = novo_nodo;
        ((int*)pBuffer)[2]++;
        return start; 
    }

    // Caso 3: Inserção no meio/final da Lista

    void* atual = start;
    void* anterior = start; 
    
    while(atual != NULL && (strcmp((char*)atual, (char*)novo_nodo) <= 0)){
        anterior = atual;
        atual = *(void**)(atual + PROXIMO);
    }

    *(void**)(anterior + PROXIMO) = novo_nodo;
    *(void**)(novo_nodo + PROXIMO) = atual;
    *(void**)(novo_nodo + ANTERIOR) = anterior;

    ((int*)pBuffer)[2]++;
    return start;
}

void* exclude (void* start, void* pBuffer){

    //Caso 1: Caso a lista esteja vazia

    if(((int*)pBuffer)[2] == 0){
        printf("\nA agenda está vazia.\n");
        return start;
    }

    //Caso 2: Caso a lista tenha só um elemento

    void* segundo_nodo = *(void**)(start + PROXIMO); 
    free(start);

    if(segundo_nodo == NULL){
        ((int*)pBuffer)[2]--;
        printf("\nRemovido com sucesso: Agora a agenda está vazia. \n");
        return segundo_nodo;
    }

    //Caso 3: Caso padrão 

    start = segundo_nodo;
    *(void**)(start + ANTERIOR) = NULL;
    ((int*)pBuffer)[2]--;
    printf("\nRemovido com sucesso. Restam <%d> cadastros\n", ((int*)pBuffer)[2]);
    return start;
}

void* restart (void* start, void* pBuffer){

    void* cleaner;

    while(start != NULL){
        cleaner = start; 
        start = *(void**)(start + PROXIMO);
        free(cleaner);
    }

    ((int*)pBuffer)[2] = 0;
    printf("\nVocê reiniciou sua lista.\n");
    return start; 
}

void search (void* start, void* pBuffer){

    if(start == NULL){
        printf("\nSua agenda está vazia.\n");
        return;
    }
    else{
        printf("\nDigite o nome que você quer buscar na agenda: ");
        scanf("%s", (char*)(pBuffer + TEMPNOME));

        ((int*)pBuffer)[1] = 1; 
        void* atual = start; 

        while(atual != NULL && (strcmp((char*)atual, (char*)(pBuffer + TEMPNOME)) != 0)){
            atual = *(void**)(atual + PROXIMO);
            ((int*)pBuffer)[1]++;
        }

        if(atual == NULL){
            printf("\nEsse nome não se encontra na agenda.\n");
            return;
        }
        else{
            printf("\n  <Nodo %d>\nNome do usuário: <%s>", ((int*)pBuffer)[1], (char*)atual);
            printf("\nIdade: <%d>", *(int*)(atual + IDADE));
            printf("\nTelefone: <%d>\n", *(int*)(atual + TELEFONE));
        }
    }
}
<<<<<<< HEAD

void printlist (void* start, void* pBuffer){

    if(start == NULL){
    printf("\nSua agenda não contém usuários cadastrados.\n");
    return;
    }
    
    void* atual = start;
    ((int*)pBuffer)[1] = 0;                       // Campo 2 de pBuffer usado como contador de nodos

    while(atual != NULL){

        ((int*)pBuffer)[1]++; 

        printf("\n  <Nodo %d>\nNome do usuário: <%s>", ((int*)pBuffer)[1], (char*)atual);
        printf("\nIdade: <%d>", *(int*)(atual + IDADE));
        printf("\nTelefone: <%d>\n", *(int*)(atual + TELEFONE));

        atual = *(void**)(atual + PROXIMO); 
    }
}
=======
>>>>>>> 8a5b75fa1e5096235cb6253db90e251cc3be20a4
