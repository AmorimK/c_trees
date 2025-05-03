#include "vetor.h"

/* Struct */

typedef struct No{
    int valor;
    struct No *esq;
    struct No *dir;
} No;

/* Operações */

No * criaNo(int valor);

No * criaArvoreComVetor(Vetor * vetor, int tamanho);

No* insereNo(No * raiz, int valor);

void imprimeCentral(No * raiz);

void imprimePreFixado(No * raiz);

void imprimePosFixado(No * raiz);

void liberaArvore(No * raiz);

/* Funções para buscar */

No * buscaNaArvore(No * raiz, int valor);