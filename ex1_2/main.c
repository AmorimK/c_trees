#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "trees.h"
#include "packages.h"
#include "package_trees.h"

int main(){

 srand(time(NULL));

 /* Exercicio 1 */

 int tam_arvore = 20;

 No * raiz = criaNo(rand() % 1000);

 for(int i = 1; i < 20; i++){
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

int qtd_pacotes = 10;

Pacote * pacotes = (Pacote*) malloc(sizeof(Pacote) * qtd_pacotes);

preencheVetorDePacotes(pacotes, qtd_pacotes);

printf("\n\n");
for(int i = 0; i<qtd_pacotes; i++){
    printf("id: %d, valor: %d\n", pacotes[i].id, pacotes[i].valor);
}
printf("\n");

NoPacote * raiz_pacotes = criaArvoreComVetorDePacotes(pacotes, qtd_pacotes);
imprimeCentralPacotes(raiz_pacotes);

/* raiz_pacotes deve virar arquivo depois */

}
