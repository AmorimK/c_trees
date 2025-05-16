#include "tree_avl.h"
#include "vetor.h"
#include "trees.h"
#include <stdio.h>
#include <time.h>

#define TAM 1000000
#define EXEC 10
#define EXEC_BUSCAS 30
int main(){
    int testes = 0;
    Vetor *vetor;  
    clock_t inicio_execucao;
    clock_t fim_execucao;
    double tempo_gasto;
    No *avl, *arvore;
    double soma_buscas_BST = 0, soma_buscas_AVL;
    double media_buscas_BST, media_buscas_AVL;

    int randNumber;
    
    FILE * arquivo = fopen("buscas_avl.txt", "a");

    srand(time(NULL));
    fprintf(arquivo, "\n=================================================\n");
    fprintf(arquivo, "Criação e busca em árvores BST e árvores AVL\n");
    fprintf(arquivo, "Tamanho do vetor: %d\n", TAM);
    fprintf(arquivo, "Quantidade de execuções: %d\n", EXEC);
    fprintf(arquivo, "=================================================\n");

    while(testes < EXEC){
        // gera o vetor e um numero aleatorio para buscar
        vetor = criaVetor(TAM);
        populaVetorAleatorio(vetor);

        // cria a AVL
        inicio_execucao = clock();
        avl = avl_criaArvoreComVetor(vetor);
        fim_execucao = clock();
        tempo_gasto = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;
        fprintf(arquivo, "criação AVL[h=%d]: %.6fs | ", altura(avl),tempo_gasto);
        
        // cria a BST
        inicio_execucao = clock();
        arvore = criaArvoreComVetor(vetor);
        fim_execucao = clock();
        tempo_gasto = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;
        fprintf(arquivo, "criação BST[h=%d]: %.6fs\n", altura(arvore), tempo_gasto);

        // buscas
        for(int i=0; i < EXEC_BUSCAS; i++){
            //sorteio de um numero ou posição
            if(i%2 == 0)
                randNumber = vetor->dados[rand() % vetor->tamanho];
            else
                randNumber = rand() % vetor->tamanho;

            // busca AVL
            inicio_execucao = clock();
            buscaNaArvore(avl, randNumber);
            fim_execucao = clock();
            tempo_gasto = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;
                    
            soma_buscas_AVL += tempo_gasto;

            // busca BST
            inicio_execucao = clock();
            buscaNaArvore(arvore, randNumber);
            fim_execucao = clock();
            tempo_gasto = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;

            soma_buscas_BST += tempo_gasto;
        }

        media_buscas_AVL = soma_buscas_AVL / EXEC_BUSCAS;
        media_buscas_BST = soma_buscas_BST / EXEC_BUSCAS;
        fprintf(arquivo, "tempo médio das %d buscas na AVL: %.6f\n", EXEC_BUSCAS, media_buscas_AVL);
        fprintf(arquivo, "tempo médio das %d buscas na BST: %.6f\n", EXEC_BUSCAS, media_buscas_BST);
        fprintf(arquivo, "-----------------------------------------------------\n");


        // limpando dados
        liberaArvore(avl);
        liberaArvore(arvore);
        liberaVetor(vetor);
        testes++;
    }   
}