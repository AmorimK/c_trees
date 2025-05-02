#include "packages.h"

typedef struct NoPacote{
    Pacote pacote;
    struct NoPacote * esq;
    struct NoPacote * dir;
} NoPacote;

NoPacote * criaNoPacote(Pacote pacote);

NoPacote * insereNoPacote(NoPacote * raiz, Pacote pacote);

NoPacote * criaArvoreComVetorDePacotes(Pacote * vetor, int tamanho);

void imprimeCentralPacotes(NoPacote * raiz);