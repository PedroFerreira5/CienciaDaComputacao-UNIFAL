#ifndef ORDENACAO_H
#define ORDENACAO_H


void ordenacao(int *vetor, int tamanho);// ordenacao atraves do quick sort

//criação de blocos e merge
int criarBlocos(const char* arquivoEntrada, int tamBloco);
void mergeBlocos(int qtdBlocos, const char* arquivoSaida);

#endif
