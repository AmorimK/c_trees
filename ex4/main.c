#include "tree_avl.h"
#include "vetor.h"
#include "trees.h"
#include <stdio.h>
#include <time.h>

#define TAM 10000
#define EXEC 10
#define EXEC_BUSCAS 30
int main(){
    int testes = 0;
    Vetor *vetor;  
    clock_t inicio_execucao;
    clock_t fim_execucao;
    double tempo_gasto;
    No *avl, *arvore;

    char *find;
    No *noBusca;
    int randNumber;
    
    FILE * arquivo = fopen("log.txt", "a");

    srand(time(NULL));
    fprintf(arquivo, "=================================================\n");
    fprintf(arquivo, "Criação e busca em árvores BST e árvores AVL\n");
    fprintf(arquivo, "Tamanho do vetor: %d\n", TAM);
    fprintf(arquivo, "Quantidade de execuções: %d\n", EXEC);
    fprintf(arquivo, "=================================================\n");

    while(testes < EXEC){
        // gera o vetor e um numero aleatorio para buscar
        vetor = criaVetor(TAM);
        populaVetorAleatorio(vetor);
        if(testes % 2 == 0)
            randNumber = vetor->dados[rand() % vetor->tamanho];
        else
            randNumber = rand() % vetor->tamanho;

        // cria a AVL
        inicio_execucao = clock();
        avl = avl_criaArvoreComVetor(vetor);
        fim_execucao = clock();
        tempo_gasto = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;
        fprintf(arquivo, "criação AVL[h=%d]: %.5fs | ", altura(avl),tempo_gasto);
        
        // cria a BST
        inicio_execucao = clock();
        arvore = criaArvoreComVetor(vetor);
        fim_execucao = clock();
        tempo_gasto = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;
        fprintf(arquivo, "criação BST[h=%d]: %.5fs\n", altura(arvore), tempo_gasto);

        // busca AVL
        inicio_execucao = clock();
        noBusca = buscaNaArvore(avl, randNumber);
        fim_execucao = clock();
        find = (noBusca != NULL ? "sim" : "nao");
        tempo_gasto = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;
        fprintf(arquivo, "busca na AVL[%s]: %.5fs", find, tempo_gasto); 
        
        // busca BST
        inicio_execucao = clock();
        noBusca = buscaNaArvore(arvore, randNumber);
        fim_execucao = clock();
        find = (noBusca != NULL ? "sim" : "nao");
        tempo_gasto = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;
        fprintf(arquivo, "busca na BST[%s]: %.5fs\n", find, tempo_gasto); 
        fprintf(arquivo, "=================================================\n");

        // limpando dados
        liberaArvore(avl);
        liberaArvore(arvore);
        liberaVetor(vetor);
        testes++;
    }   
}