#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int * dados;
  int tamanho;
} Vetor;

Vetor * criaVetor(int tamanho){
  Vetor * vet = (Vetor*) malloc(sizeof(Vetor));
  if (!vet) {
  printf("Erro ao alocar memória para Vetor.\n");
  exit(1);
  }
  vet->dados = (int*) malloc(sizeof(int) * tamanho);
  if (!vet->dados) {
  printf("Erro ao alocar memória para array de ints.\n");
  exit(1);
  }
  vet->tamanho = tamanho;
  return vet;
}

void liberaVetor(Vetor * vet){
  free(vet->dados);
  free(vet);
}

void imprime_vet(Vetor *vet){
    for(int i = 0;i < vet->tamanho;i++){
        printf("%d", vet->dados[i]);
    }

}
/* Funções para popular vetores */

void populaVetorAleatorio(Vetor * vet){
  for(int i = 0; i < vet->tamanho; i++){
    vet->dados[i] = rand() % vet->tamanho; 
  } 
}
  