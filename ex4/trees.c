#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"
#include "trees.h"

/* Operações */

No * criaNo(int valor){
   No *novo_no = (No*)malloc(sizeof(No));
   novo_no->valor = valor;
   novo_no->esq = NULL;
   novo_no->dir = NULL;
   return novo_no;
}

No * criaArvoreComVetor(Vetor * vetor){
    if(vetor == NULL || vetor->tamanho == 0)
        return NULL;
    int meio = (vetor->tamanho/2);
    No * raiz = criaNo(vetor->dados[meio]);

    for(int i = 0; i < meio; i++){
        insereNo(raiz, vetor->dados[i]);
    }
    
    for(int i = meio + 1; i < vetor->tamanho; i++){
        insereNo(raiz, vetor->dados[i]);
    }
    return raiz;
}

No * insereNo(No * raiz, int valor){
    if(raiz == NULL){
        return criaNo(valor);
    }
    
    if (valor < raiz->valor){
        raiz->esq = insereNo(raiz->esq, valor);   
    }
    else if(valor > raiz->valor){
        raiz->dir = insereNo(raiz->dir, valor);
    }
    return raiz;
}

void imprimeCentral(No * raiz){
    if (raiz!=NULL){
        imprimeCentral(raiz->esq);
        printf("%d ", raiz->valor);
        imprimeCentral(raiz->dir);
    }

}

void imprimePreFixado(No * raiz){
    if(raiz !=NULL){
        printf("%d ", raiz->valor);
        imprimePreFixado(raiz->esq);
        imprimePreFixado(raiz->dir);
        
    }
}

void imprimePosFixado(No * raiz){
    if(raiz !=NULL){
        imprimePosFixado(raiz->esq);
        imprimePosFixado(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

void liberaArvore(No * raiz){
    if(raiz!=NULL){
        liberaArvore(raiz->esq);
        liberaArvore(raiz->dir);
        free(raiz);
    }
}


/* Funções para buscar */

No * buscaNaArvore(No * raiz, int valor){
    if(raiz){
        if(raiz->valor == valor) return raiz;
        else if(raiz->valor > valor) return buscaNaArvore(raiz->esq, valor);
        else return buscaNaArvore(raiz->dir, valor);
    }
    return NULL;
}
