#ifndef TREE_AVL
#define TREE_AVL

#include <stdlib.h>
#include "vetor.h"
#include "no.h"

No* avl_criaNo(int valor);

No* avl_insereNo(No* raiz, int valor);

No* avl_criaArvoreComVetor(Vetor *vetor);

#endif