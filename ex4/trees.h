#ifndef TREES_H
#define TREES_H

#include "vetor.h"
#include "tree_avl.h"
#include "no.h"

/* Operações */

No * criaNo(int valor);

No * criaArvoreComVetor(Vetor * vetor);

No* insereNo(No * raiz, int valor);

void imprimeCentral(No * raiz);

void imprimePreFixado(No * raiz);

void imprimePosFixado(No * raiz);

void liberaArvore(No * raiz);

/* Funções para buscar */

No * buscaNaArvore(No * raiz, int valor);

#endif