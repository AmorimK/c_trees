/* Struct */

typedef struct No No;

/* Operacoes */

No * criaNo(int valor);

No* insereNo(No * raiz, int valor);

No * preencheArvoreComVetor(No *raiz, int *vetor, int tamanho);

void imprimeCentral(No * raiz);

void imprimePreFixado(No * raiz);

void imprimePosFixado(No * raiz);

void liberaArvore(No * raiz);