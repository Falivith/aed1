#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

struct Nodo{
    int altura;
    int valor;
    struct Nodo* direita;
    struct Nodo* esquerda;
};

int altura(struct Nodo* raiz);

int fb(struct Nodo* raiz);

struct Nodo* criar(int num);

struct Nodo* rot_dir(struct Nodo* critico);

struct Nodo* rot_esq(struct Nodo* critico);

struct Nodo* inserir(struct Nodo* raiz, struct Nodo* novo);

struct Nodo* deletar(struct Nodo* raiz, int valor);

void limpar(struct Nodo* raiz);
 
void print(struct Nodo *raiz, int spaces);
 
int EhArvoreAvl(struct Nodo* pRaiz);

#endif