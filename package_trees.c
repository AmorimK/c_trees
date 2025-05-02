#include <stdlib.h>
#include <stdio.h>
#include "packages.h"
#include "package_trees.h"

NoPacote * criaNoPacote(Pacote pacote){
   NoPacote *novo_no = (NoPacote*)malloc(sizeof(NoPacote));
   novo_no->pacote = pacote;
   novo_no->esq = NULL;
   novo_no->dir = NULL;
   return novo_no;
}

NoPacote* insereNoPacote(NoPacote * raiz, Pacote pacote){
    if(raiz == NULL){
        return criaNoPacote(pacote);
    }
    
    if (pacote.id < raiz->pacote.id){
        raiz->esq = insereNoPacote(raiz->esq, pacote);   
    }
    else if(pacote.id > raiz->pacote.id){
        raiz->dir = insereNoPacote(raiz->dir, pacote);
    }
    return raiz;
}

voi preencheArvoreComVetorDePacotes(NoPacote * raiz, Pacote * vetor, int tamanho){
    for(int i = 0; i<tamanho;i++){
        raiz = insereNoPacote(raiz, vetor[i]);
    }
}

void imprimeCentralPacotes(NoPacote * raiz){
    if (raiz!=NULL){
        imprimeCentralPacotes(raiz->esq);
        printf("idarv: %d, valorarv: %d\n", raiz->pacote.id, raiz->pacote.valor);
        imprimeCentralPacotes(raiz->dir);
    }

}