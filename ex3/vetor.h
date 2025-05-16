#ifndef VETOR_H
#define VETOR_H

/* Struct */

typedef struct{
    int * dados;
    int tamanho;
} Vetor;
  
/* Operações */

Vetor * criaVetor(int tamanho);
void liberaVetor(Vetor * vet);
void imprime_vet(Vetor *vet);

/* Funções para popular vetores */

void populaVetorAleatorio(Vetor * vet);

void populaVetorOrdenado(Vetor * vet);
  
/* Funções para buscar em vetores */

int buscaBinariaVetor(Vetor * vet, int valor_procurado );

void quickSort(Vetor * vet, int tam);
#endif
    