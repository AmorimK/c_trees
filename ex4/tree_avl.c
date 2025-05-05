#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"
#include "tree_avl.h"

int avl_max(int a, int b){
    return a > b ? a : b;
}

int avl_altura(No *no){
    if(no == NULL)
        return -1;
    return no->h;
}

void avl_atualizaAltura(No *no){
    if(no)
        no->h = 1 + avl_max(avl_altura(no->esq), avl_altura(no->dir));
}

No* avl_rotacionaSimplesDireita(No *no){
    No *aux_A = no, *aux_B = aux_A->esq;

    //rotacionando
    aux_A->esq = aux_B->dir;
    aux_B->dir = aux_A;

    avl_atualizaAltura(aux_A);
    avl_atualizaAltura(aux_B);

    return aux_B; //nova raiz
}

No* avl_rotacionaSimplesEsquerda(No *no){
    No *aux_A = no, *aux_B = aux_A->dir;

    aux_A->dir = aux_B->esq;
    aux_B->esq = aux_A;

    avl_atualizaAltura(aux_A);
    avl_atualizaAltura(aux_B);

    return aux_B; // nova raiz
}

No* avl_rotacionaDuplaDireita(No *no){
    no->esq = avl_rotacionaSimplesEsquerda(no->esq);
    return avl_rotacionaSimplesDireita(no);
}
No* avl_rotacionaDuplaEsquerda(No *no){
    no->dir = avl_rotacionaSimplesDireita(no->dir);
    return avl_rotacionaSimplesEsquerda(no);
}

No* avl_criaNo(int valor){
    No *novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    novo_no->h = 0;
    return novo_no;
 }

No* avl_insereNo(No* raiz, int valor){
    int fb;
    if(!raiz)
        return avl_criaNo(valor);
    
    if(valor < raiz->valor)
        raiz->esq = avl_insereNo(raiz->esq, valor);
    else if(valor > raiz->valor)
        raiz->dir = avl_insereNo(raiz->dir, valor);
    else
        return raiz;
    
    avl_atualizaAltura(raiz);

    //se tiver desbalanceada, balanceia
    fb = avl_altura(raiz->esq) - avl_altura(raiz->dir);

    //balanceia a esquerda
    if(fb > 1){
        if(valor < raiz->esq->valor)
            return avl_rotacionaSimplesDireita(raiz);
        else
            return avl_rotacionaDuplaDireita(raiz);
    }
    //balanceia a direita
    if(fb < -1){
        if(valor > raiz->dir->valor)
            return avl_rotacionaSimplesEsquerda(raiz);
        else
            return avl_rotacionaDuplaEsquerda(raiz);
    }
    //sem balanceamento
    return raiz;
}

No* avl_noMinimo(No *no){
    while(no && no->esq)
        no = no->esq;
    return no;
}

No* avl_removeNo(No *no, int valor){
    //busca
    if(no == NULL)
        return no;
    if(valor < no->esq){
        no->esq = avl_removeNo(no->esq, valor);
    }else if(valor > no->dir){
        no->dir =avl_removeNo(no->dir, valor);
    }else{
        // achou
        // é folha ou tem 1 filho
        if(no->esq == NULL || no->dir == NULL){
            No *tmp = no->esq ? no->esq :no->dir;
            free(no);
            return tmp;
        }else{
            // 2 filhos, troca o valor minimo a esquerda com o no achado e remove a folha
            No *tmp = avl_noMinimo(no->dir);
            no->valor = tmp->valor;
            no->dir = avl_removeNo(no->dir, tmp->valor);
        }
    }
    /** Tem que balancear aqui */

}

No* avl_criaArvoreComVetor(Vetor *vetor){
    if(vetor == NULL || vetor->dados == NULL) return NULL;
    No *raiz = avl_criaNo(vetor->dados[0]);
    for(int i=1; i<vetor->tamanho; i++)
        raiz = avl_insereNo(raiz, vetor->dados[i]);
    return raiz;
}