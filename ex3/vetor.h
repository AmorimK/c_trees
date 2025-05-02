typedef struct {
    int * dados;
    int tamanho;
  } Vetor;
  
  Vetor * criaVetor(int tamanho);
  void liberaVetor(Vetor * vet);
  
  /* Funções para popular vetores */
  
  void populaVetorAleatorio(Vetor * vet);
  
  void imprime_vet(Vetor *vet);
    