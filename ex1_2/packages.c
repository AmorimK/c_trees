#include <stdlib.h>
#include "packages.h"

Pacote criaPacote(int id, int valor){
    Pacote novoPacote;
    novoPacote.id = id;
    novoPacote.valor = valor;
    return novoPacote;
}

void preencheVetorDePacotes(Pacote * vetor, int tam){

    int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

    int primo_aleatorio = primos[rand() % 20];

    /* Preenchendo ordenado */

    vetor[0] = criaPacote(0, rand() % 1000);
    for(int i = 1; i < tam/2; i++){
        int numero_aleatorio = vetor[i-1].valor + rand() % 1000;

        if(numero_aleatorio % primo_aleatorio == 0){
            vetor[i] = criaPacote(i, vetor[i-1].valor);
        }
        else{
        vetor[i] = criaPacote(i, numero_aleatorio);
        }

    }

    /* Preenchendo desordenado */

    for(int i = tam/2; i < tam; i++){
        int numero_aleatorio = vetor[i-1].valor + rand() % 1000;

        if(numero_aleatorio % primo_aleatorio == 0){
            vetor[i] = criaPacote(i, vetor[i-1].valor);
        }
        else{
        vetor[i] = criaPacote(i, numero_aleatorio);
        }

    }

}