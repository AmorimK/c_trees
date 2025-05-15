#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "trees.h"
#include "packages.h"
#include "package_trees.h"
#define TAM_ARVORE 20
#define QTD_PACOTES 50

/*
Integrantes da Equipe:
Carlos Henrick Cavalcante Gomes
Kauã Amorim
Adrian Batista
Andre Kaled
*/

int main(){

 srand(time(NULL));

 /* Exercicio 1 */

 No * raiz = criaNo(rand() % 1000);

 for(int i = 1; i < TAM_ARVORE; i++){
    insereNo(raiz, rand() % 1000);
 }

 /* Mostrando caminhamentos */

 printf("Caminhamento Pre Fixado:\n");
 imprimePreFixado(raiz);

 printf("\nCaminhamento Pos Fixado:\n");
 imprimePosFixado(raiz);

 printf("\nCaminhamento Central:\n");
 imprimeCentral(raiz);

 /* Exercicio 2 */

 /* Recebendo pacotes */

Pacote * pacotes = (Pacote*) malloc(sizeof(Pacote) * QTD_PACOTES);
preencheVetorDePacotes(pacotes, QTD_PACOTES);

FILE * pacotes_recebidos = fopen("pacotes_recebidos.txt", "w");

for(int i = 0; i<QTD_PACOTES; i++){
    fprintf(pacotes_recebidos,"id: %d, valor: %d\n", pacotes[i].id, pacotes[i].valor);
}

FILE * pacotes_validados = fopen("pacotes_validados.txt", "w");
NoPacote * raiz_pacotes = criaArvoreComVetorDePacotes(pacotes, QTD_PACOTES);
imprimeCentralPacotes(raiz_pacotes, pacotes_validados);

}
