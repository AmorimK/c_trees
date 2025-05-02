#ifndef PACKAGES_H
#define PACKAGES_H

typedef struct Pacote{
    int id;
    int valor;
} Pacote;

Pacote criaPacote(int id, int valor);

void preencheVetorDePacotes(Pacote * vetor, int tam);

#endif