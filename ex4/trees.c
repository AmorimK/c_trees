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
    No * raiz = criaNo(vetor->dados[0]);

    for(int i = 1; i < vetor->tamanho; i++){
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

/* Calculo da altura */
int altura(No *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = altura(raiz->esq);
        int dir = altura(raiz->dir);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
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
