#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

struct Nodo{
    int altura;
    int valor;
    struct Nodo* direita;
    struct Nodo* esquerda;
};

int altura(struct Nodo* raiz){

    if(raiz == NULL)
        return 0;
    
    int altura_esquerda = altura(raiz->esquerda);
    int altura_direita = altura(raiz->direita);

    if(altura_esquerda > altura_direita)
    return altura_esquerda+1;

    else
    return altura_direita+1; 
}

int fb(struct Nodo* raiz){

    if (raiz == NULL)
        return 0; 

    return (altura(raiz->esquerda) - altura(raiz->direita));
}

struct Nodo* criar(int num){

    struct Nodo* novo = (struct Nodo*)malloc(sizeof(struct Nodo));

    novo->valor = num;
    novo->altura = 1;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

struct Nodo* rot_dir(struct Nodo* critico){

    struct Nodo* girado = critico->esquerda;
    struct Nodo* temp = girado->direita;
 
    girado->direita = critico;
    critico->esquerda = temp;

    critico->altura = altura(critico);
    girado->altura = altura(girado);
 
    return girado;
}

struct Nodo* rot_esq(struct Nodo* critico){

    struct Nodo* girado = critico->direita;
    struct Nodo* temp = girado->esquerda;
 
    girado->esquerda = critico;
    critico->direita = temp;

    critico->altura = altura(critico);
    girado->altura = altura(girado);
 
    return girado;
}

struct Nodo* inserir(struct Nodo* raiz, struct Nodo* novo){

    //Caso Base
    if(raiz == NULL){
        return novo; 
    }

    if(novo->valor >= raiz->valor){
        raiz->direita = inserir(raiz->direita, novo);
    }
    else{
        raiz->esquerda = inserir(raiz->esquerda, novo);
    }

    //Cálculo do fator de balanceamento/altura do nodo atual
    raiz->altura = altura(raiz);
    int f_balanc = fb(raiz); 

    // Rotação à Esquerda
    if (f_balanc < -1 && novo->valor > raiz->direita->valor)
        return rot_esq(raiz);

    // Rotação à Direita
    if (f_balanc > 1 && novo->valor < raiz->esquerda->valor)
        return rot_dir(raiz);

    // Rotação Dupla à Esquerda
    if (f_balanc > 1 && novo->valor > raiz->esquerda->valor){
        raiz->esquerda = rot_esq(raiz->esquerda);
        return rot_dir(raiz);
    }

    // Rotação Dupla à Direita
    if (f_balanc < -1 && novo->valor < raiz->direita->valor){
        raiz->direita = rot_dir(raiz->direita);
        return rot_esq(raiz);
    }

    return raiz; 
}

void print(struct Nodo *raiz, int spaces){

    if (raiz == NULL)
        return;
 
    spaces += 5;
 
    print(raiz->direita, spaces);
 
    printf("\n");
    for (int i = 5; i < spaces; i++)
        printf(" ");
    printf("%d\n", raiz->valor);
 
    print(raiz->esquerda, spaces);
}
 

int EhArvoreAvl(struct Nodo* pRaiz){

    int fbalanc;

        if (pRaiz == NULL)
            return 1;

        if (!EhArvoreAvl(pRaiz->esquerda))
            return 0;
        if (!EhArvoreAvl(pRaiz->direita))
            return 0;

        fbalanc = fb(pRaiz);
        if ( ( fbalanc > 1 ) || ( fbalanc <-1) )
            return 0;

            else

            return 1;
}

int main(){

    SetConsoleOutputCP(65001);
    srand(time(0));

    int num, choice, exit;
    struct Nodo* raiz = NULL;

    do{ 
        printf("\n");
        printf("|----------------------------|\n");
        printf("| 1) Inserir valor           |\n");
        printf("| 2) Inserir valor randômico |\n");
        printf("| 3) Printar Árvore          |\n");
        printf("| 4) É AVL?                  |\n");
        printf("| 5) Sair                    |\n");
        printf("|----------------------------|\n");
        printf("\n-> ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Digite o valor a ser inserido na Árvore: ");
                scanf("%d", &num);
                raiz = inserir(raiz, criar(num)); 
                break;

            case 2:
                raiz = inserir(raiz, criar(rand() % 100));
                printf("Inserido com Sucesso");
                break;

            case 3:
                print(raiz, 0);
                break;

            case 4:
                if (EhArvoreAvl(raiz))
                printf("\n é AVL.");
                else
                printf("\n Não é AVL.");
                break;

            default:
                exit = 0; 
                break;
        }
    }
    while(exit);

    return 0;
}