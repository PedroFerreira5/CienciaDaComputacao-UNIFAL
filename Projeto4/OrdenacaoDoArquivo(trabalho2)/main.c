#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ordenacao.h"

/*
AEDS II (Prática)
Trabalho 2

Diego Vianna Leite Montemor
Francisco Toro Tonissi 
Pedro Ferreira Prado
*/

int main() {
    const char* arquivoEntrada = "entrada_desordenada.txt";
    const char* arquivoSaida = "saida_ordenada.txt";

    int tamBloco;
    printf("Digite quantos números cabem na memória (tamanho de cada bloco), 1.000.000 é aprox. 4MB: ");
    scanf("%d", &tamBloco);

    printf("\nCriando blocos...\n");
    int qtdBlocos = criarBlocos(arquivoEntrada, tamBloco);
    printf("...Concluido.\n");

    printf("\nJuntando os blocos...\n");
    mergeBlocos(qtdBlocos, arquivoSaida);
    printf("...Concluido.\n");
    return 0;
}
