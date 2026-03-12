#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ordenacao.h"


/*
========== Trabalho 2 - AEDS II Prática ==============

Diego Vianna Leite Montemor
Francisco Toro Tonissi 
Pedro Ferreira Prado

*/

// Dividir o arquivo grande em blocos menores
int dividirEmBlocos(const char* arquivoEntrada, int tamanhoBloco) {
    FILE* entrada = fopen(arquivoEntrada, "r");
    if (entrada == NULL) {
        printf("Erro ao abrir arquivo de entrada.\n");
        return 0;
    }

    int* buffer = (int*)malloc(tamanhoBloco * sizeof(int));
    if (buffer == NULL) {
        printf("Erro de alocação de memória.\n");
        fclose(entrada);
        return 0;
    }

    int numero, contador = 0, indiceBloco = 0;

    while (fscanf(entrada, "%d", &numero) == 1) {
        buffer[contador++] = numero;

        // Quando atingir o tamanho do bloco, ordena e grava
        if (contador == tamanhoBloco) {
            indiceBloco++;
            ordenacao(buffer, contador); // usa a função Quick Sort

            char nomeBloco[50];
            sprintf(nomeBloco, "bloco_%d.txt", indiceBloco);

            FILE* bloco = fopen(nomeBloco, "w");
            if (bloco == NULL) {
                printf("Erro ao criar arquivo %s\n", nomeBloco);
                free(buffer);
                fclose(entrada);
                return 0;
            }

            for (int i = 0; i < contador; i++)
                fprintf(bloco, "%d\n", buffer[i]);

            fclose(bloco);
            contador = 0; // reinicia o contador
        }
    }

    // Grava o último bloco se sobrar algo
    if (contador > 0) {
        indiceBloco++;
        ordenacao(buffer, contador);

        char nomeBloco[50];
        sprintf(nomeBloco, "bloco_%d.txt", indiceBloco);

        FILE* bloco = fopen(nomeBloco, "w");
        if (bloco == NULL) {
            printf("Erro ao criar arquivo %s\n", nomeBloco);
            free(buffer);
            fclose(entrada);
            return 0;
        }

        for (int i = 0; i < contador; i++)
            fprintf(bloco, "%d\n", buffer[i]);

        fclose(bloco);
    }

    free(buffer);
    fclose(entrada);

    printf("Total de blocos criados: %d\n", indiceBloco);
    return indiceBloco;
}

//  Intercalar blocos ordenados (merge externo)
void intercalarBlocos(int qtdBlocos, const char* arquivoSaida) {
    FILE** blocos = (FILE**)malloc(qtdBlocos * sizeof(FILE*));
    int* valores = (int*)malloc(qtdBlocos * sizeof(int));
    int* ativo = (int*)malloc(qtdBlocos * sizeof(int)); // 1 = ativo, 0 = inativo

    if (blocos == NULL || valores == NULL || ativo == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    // Inicializa os blocos e lê o primeiro valor de cada um
    for (int i = 0; i < qtdBlocos; i++) {
        char nome[50];
        sprintf(nome, "bloco_%d.txt", i + 1);
        blocos[i] = fopen(nome, "r");

        if (blocos[i] != NULL && fscanf(blocos[i], "%d", &valores[i]) == 1) {
            ativo[i] = 1;
        } else {
            ativo[i] = 0;
        }
    }

    FILE* saida = fopen(arquivoSaida, "w");
    if (saida == NULL) {
        printf("Erro ao criar arquivo de saída.\n");
        for (int i = 0; i < qtdBlocos; i++) {
            if (blocos[i] != NULL) fclose(blocos[i]);
        }
        free(blocos);
        free(valores);
        free(ativo);
        return;
    }

    while (1) {
        int menor = INT_MAX;
        int indiceMenor = -1;

        // Encontra o menor valor entre os blocos 
        for (int i = 0; i < qtdBlocos; i++) {
            if (ativo[i] && valores[i] < menor) {
                menor = valores[i];
                indiceMenor = i;
            }
        }

        if (indiceMenor == -1) break; // nenhum bloco ativo -> fim

        // Escreve o menor valor no arquivo de saída
        fprintf(saida, "%d\n", menor);

        // Lê o próximo número do bloco de onde o menor saiu
        if (fscanf(blocos[indiceMenor], "%d", &valores[indiceMenor]) != 1) {
            ativo[indiceMenor] = 0; // fim do bloco
            fclose(blocos[indiceMenor]);
        }
    }

    fclose(saida);
    printf("Arquivo final ordenado salvo em: %s\n", arquivoSaida);

    // Remove blocos temporários
    for (int i = 0; i < qtdBlocos; i++) {
        char nome[50];
        sprintf(nome, "bloco_%d.txt", i + 1);
        remove(nome);
    }

    // Libera memória
    free(blocos);
    free(valores);
    free(ativo);
}

// Funçao principal
int main() {
    const char* arquivoEntrada = "output.txt";
    const char* arquivoSaida = "saida_ordenada.txt";
    int tamanhoBloco = 100000; // quantidade de números que cabem na RAM

    printf("=== Ordenacao Externa com Merge Sort ===\n");
    printf("Lendo arquivo: %s\n", arquivoEntrada);

    // Criar blocos menores
    int qtdBlocos = dividirEmBlocos(arquivoEntrada, tamanhoBloco);

    // Fazer o merge externo
    intercalarBlocos(qtdBlocos, arquivoSaida);

    printf("Processo concluído com sucesso!\n");
    return 0;
}
