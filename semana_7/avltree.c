#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

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
    if (f_balanc < -1 && novo->valor >= raiz->direita->valor)
        return rot_esq(raiz);

    // Rotação à Direita
    if (f_balanc > 1 && novo->valor < raiz->esquerda->valor)
        return rot_dir(raiz);

    // Rotação Dupla à Esquerda
    if (f_balanc > 1 && novo->valor >= raiz->esquerda->valor){
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

struct Nodo* deletar(struct Nodo* raiz, int valor){

    // Caso base
    if (raiz == NULL)
        return raiz;
 
    // Procura recursiva do valor na árvore
    if (valor < raiz->valor)
        raiz->esquerda = deletar(raiz->esquerda, valor);
 
    else if( valor > raiz->valor )
        raiz->direita = deletar(raiz->direita, valor);
 

    // Se o valor é o mesmo, então é esse o nodo a ser deletado.
    else
    {
        if( (raiz->esquerda == NULL) || (raiz->direita == NULL) )
        {
            struct Nodo* temp;

            if(raiz->esquerda != NULL)
            temp = raiz->esquerda; 
            else
            temp = raiz->direita;
 
            if (temp == NULL)
            {
                temp = raiz;
                raiz = NULL;
            }
            else
            *raiz = *temp;

            free(temp);
        }
        else // Caso com uma subárvore
        {
             // Acha o menor valor da subárvore
            struct Nodo* temp = raiz->direita;
                while (temp->esquerda != NULL)
                    temp = temp->esquerda;

            raiz->valor = temp->valor;
            raiz->direita = deletar(raiz->direita, temp->valor);
        }
    }
    
    if (raiz == NULL)
      return raiz;
 
    // Atualiza a altura do nodo atual

    if(altura(raiz->esquerda) > altura(raiz->direita))
        raiz->altura = 1 + altura(raiz->esquerda);
    else
        raiz->altura = 1 + altura(raiz->direita);
 
    
    // Verifica o fator de balanceamento

    int f_balanc = fb(raiz);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Rotação à Direita
    if (f_balanc > 1 && fb(raiz->esquerda) >= 0)
        return rot_dir(raiz);
 
    // Rotação Dupla à Esquerda
    if (f_balanc > 1 && fb(raiz->esquerda) < 0)
    {
        raiz->esquerda =  rot_esq(raiz->esquerda);
        return rot_dir(raiz);
    }
 
     // Rotação à Esquerda
    if (f_balanc < -1 && fb(raiz->direita) <= 0)
        return rot_esq(raiz);
 
    // Rotação Dupla à Direita
    if (f_balanc < -1 && fb(raiz->direita) > 0)
    {
        raiz->direita = rot_dir(raiz->direita);
        return rot_esq(raiz);
    }
 
    return raiz;
}

void limpar(struct Nodo* raiz)
{
    if (raiz == NULL) return;
 
    // Primeiro, deleta as subárvores
    limpar(raiz->esquerda);
    limpar(raiz->direita);
   
    // Então deleta a atual raiz
    printf("\n Deletando Nodo <%d>", raiz->valor);
    free(raiz);
}
 
void print(struct Nodo *raiz, int spaces){

    if (raiz == NULL)
        return;
 
    spaces += 8;
 
    print(raiz->direita, spaces);
 
    printf("\n");
    for (int i = 8; i < spaces; i++)
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