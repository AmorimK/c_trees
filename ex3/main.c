#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "trees.h"
#include "vetor.h"
#define TAM 1000
#define EXEC 30

int main(){

    srand(time(NULL));

    FILE * arquivo = fopen("log.txt", "a");

    double tempo_gasto;
    double soma_tempos_arvore = 0;
    double soma_tempos_vetor = 0;

    clock_t inicio_execucao;
    clock_t fim_execucao;

    int valores_busca[EXEC];

    /* Criando Vetor e Arvore */

    Vetor * vetor = criaVetor(TAM);
    populaVetorOrdenado(vetor);

    No * raiz = criaArvoreComVetor(vetor);

    /* Gerando valores a serem buscados */

    for(int i = 0; i < EXEC; i++){
        valores_busca[i] = vetor->dados[rand() % TAM];
    }

    /* Efetuando Buscas */

    for(int i = 0; i < EXEC; i++){
        
        /* Busca Vetor */
    
        inicio_execucao = clock();
        buscaBinariaVetor(vetor, valores_busca[i]);
        fim_execucao = clock();
        
        /* Guarda buscas do Vetor */

        tempo_gasto = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;
        fprintf(arquivo, "BuscaVet[%d] = %f\n", i, tempo_gasto);
        soma_tempos_vetor += (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;

        /* Busca Arvore */

        inicio_execucao = clock();
        buscaNaArvore(raiz, valores_busca[i]);
        fim_execucao = clock();

        /* Guarda buscas da Arvore */

        tempo_gasto = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;
        fprintf(arquivo, "BuscaArv[%d] = %f\n\n", i, tempo_gasto);
        soma_tempos_arvore += (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;

    }

    /* Calculando e guardando media de tempo */

    fprintf(arquivo, "\nMedia Vetor = %f\n", soma_tempos_vetor/EXEC);
    fprintf(arquivo, "Media Arvore = %f", soma_tempos_arvore/EXEC);


}