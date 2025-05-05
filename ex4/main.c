/**
 * Crie uma árvore AVL e uma árvore binária de pesquisa com os mesmos 
 * 1.000.000 (ummilhão) de elementos do tipo inteiro. 
 * Implemente as operações de inserção e de busca por um valor. 
 * Crie 10 árvores de cada tipo (com os mesmos valores em cada execução)
 * e compare o tempo da criação da árvore AVL com o tempo da criação da
 * árvore binária de pesquisa. Mostre a altura das árvores em cada uma 
 * das 10 execuções. Compare também o tempo da busca na árvore AVL 
 * com o tempo da busca na árvore binária depesquisa, calculando o 
 * tempo de execução para 30 consultas e a média entre as 30 consultas 
 * para cada árvore
 */
#include "tree_avl.h"
#include "vetor.h"
#include "trees.h"
#include <stdio.h>
int main(){
    int dados[] = {3,2,1,4,5,6,7};
    Vetor vetor = {dados, 7};  

    No* raiz = avl_criaArvoreComVetor(&vetor);

    imprimePreFixado(raiz);
    printf("\n");
    
}