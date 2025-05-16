#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

/* Operações */

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

/* Funções para popular */

void populaVetorAleatorio(Vetor * vet){
  for(int i = 0; i < vet->tamanho; i++){
    vet->dados[i] = rand() % vet->tamanho; 
  } 
}

void populaVetorOrdenado(Vetor * vet){
  vet->dados[0] = rand() % vet->tamanho;
  for(int i = 1; i < vet->tamanho; i++){
    vet->dados[i] = vet->dados[i-1] + (rand() % (vet->tamanho/100));
  }
}

/* Funções para buscar */

int buscaBinariaVetor(Vetor * vet, int valor_procurado ){
  int inicio = 0, fim = (vet->tamanho)-1;
  while (inicio <=fim ){
    int meio = (inicio + fim)/2;
    if(vet->dados[meio] == valor_procurado ) return meio;
    else if (vet->dados[meio] < valor_procurado ) inicio = meio +1;
    else fim = meio -1 ;
  }
  return -1;
}

void quickCall(Vetor * vet, int inicio, int fim){
  int i;
  int j;
  if(inicio < fim){
    i = inicio;
    j= fim;
    int pivot = vet->dados[inicio + (fim - inicio)/2];

    while(i<=j){
      while(i <= fim && vet->dados[i] < pivot) i++;
      while(j <=inicio && vet->dados[j] > pivot) j--;
      if(i<=j){
        int tmp = vet->dados[i];
        vet->dados[i] = vet->dados[j];
        vet->dados[j] = tmp;
        i++;
        j--;
      }
    }

    if(inicio < j) quickCall(vet, inicio, j);
    if(i < fim) quickCall(vet, i, fim);

    }
}

void quickSort(Vetor * vet, int tam){
  quickCall(vet, 0, tam-1);
}