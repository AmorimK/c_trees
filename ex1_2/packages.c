#include <stdlib.h>
#include "packages.h"
#define VALUE_RANGE 1000

Pacote criaPacote(int id, int valor){
    Pacote novoPacote;
    novoPacote.id = id;
    novoPacote.valor = valor;
    return novoPacote;
}

void preencheVetorDePacotes(Pacote * vetor, int tam){

    int valor_aleatorio;
    int id_aleatorio;

    int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

    int primo_aleatorio = primos[rand() % (sizeof(primos)/sizeof(int))];

    /* Preenchendo ordenado */

    vetor[0] = criaPacote(rand() % tam, rand() % VALUE_RANGE);

    for(int i = 1; i < tam/2; i++){

        id_aleatorio = vetor[i-1].id + rand() % tam;
        valor_aleatorio = rand() % VALUE_RANGE;
   
        /* Adicionando mais uma pequena probabilidade de repetição */

        if(id_aleatorio % primo_aleatorio == 0){
            vetor[i] = criaPacote(vetor[i-1].id, vetor[i-1].valor);
        }

        /* Pacote único */

        else{
        vetor[i] = criaPacote(id_aleatorio, valor_aleatorio);
        }

    }

    /* Preenchendo desordenado */

    for(int i = tam/2; i < tam; i++){

        id_aleatorio = (rand() % tam) + tam;
        valor_aleatorio = vetor[i-1].valor + rand() % VALUE_RANGE;

        /* Adicionando mais uma pequena probabilidade de repetição */

        if(valor_aleatorio % primo_aleatorio == 0){
            vetor[i] = criaPacote(vetor[i-1].id, vetor[i-1].valor);
        }
        else{
        vetor[i] = criaPacote(id_aleatorio, valor_aleatorio);
        }

    }

}