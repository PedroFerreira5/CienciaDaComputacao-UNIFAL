#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ordenacao.h"

// QUICK SORT AUXILIAR
int divide(int *vetor, int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1, j, aux;

    for (j = inicio; j < fim; j++) {
        if (vetor[j] < pivo) {
            i++;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }
    aux = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = aux;
    return i + 1;
}

// QUICK SORT
void quickSort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int p = divide(vetor, inicio, fim);
        quickSort(vetor, inicio, p - 1);
        quickSort(vetor, p + 1, fim);
    }
}

void ordenacao(int *vetor, int tamanho) {
    quickSort(vetor, 0, tamanho - 1);
}

// Dividir o arquivo grande em blocos menores
int criarBlocos(const char* arquivoEntrada, int tamBloco) {
    FILE* entrada = fopen(arquivoEntrada, "r");
    if (entrada == NULL) {
        printf("Erro ao abrir arquivo de entrada.\n");
        return 0;
    }

    int* buffer = (int*)malloc(tamBloco * sizeof(int));
    if (buffer == NULL) {
        printf("Erro de alocação de memória.\n");
        fclose(entrada);
        return 0;
    }

    int numero, count = 0, indiceBloco = 0;

    while (fscanf(entrada, "%d", &numero) == 1) {
        buffer[count++] = numero;

        // Quando atingir o tamanho do bloco, ordena e grava
        if (count == tamBloco) {
            indiceBloco++;
            ordenacao(buffer, count); // QuickSort no bloco

            char nomeBloco[50];
            sprintf(nomeBloco, "bloco_%d.txt", indiceBloco);

            FILE* bloco = fopen(nomeBloco, "w");
            if (bloco == NULL) {
                printf("Erro ao criar arquivo %s\n", nomeBloco);
                free(buffer);
                fclose(entrada);
                return 0;
            }

            for (int i = 0; i < count; i++)
                fprintf(bloco, "%d\n", buffer[i]);

            fclose(bloco);
            count = 0; // reinicia o count
        }
    }

    // Cria um último bloco caso sobre dados
    if (count > 0) {
        indiceBloco++;
        ordenacao(buffer, count);

        char nomeBloco[50];
        sprintf(nomeBloco, "bloco_%d.txt", indiceBloco);

        FILE* bloco = fopen(nomeBloco, "w");
        if (bloco == NULL) {
            printf("Erro ao criar arquivo %s\n", nomeBloco);
            free(buffer);
            fclose(entrada);
            return 0;
        }

        for (int i = 0; i < count; i++)
            fprintf(bloco, "%d\n", buffer[i]);

        fclose(bloco);
    }

    free(buffer);
    fclose(entrada);

    printf("Total de blocos criados: %d\n", indiceBloco);
    return indiceBloco;
}

// junta os blocos ja ordenados
void mergeBlocos(int qtdBlocos, const char* arquivoSaida) {
    FILE** blocos = (FILE**)malloc(qtdBlocos * sizeof(FILE*));
    int* valores = (int*)malloc(qtdBlocos * sizeof(int));
    int* ativo = (int*)malloc(qtdBlocos * sizeof(int));

    if (!blocos || !valores || !ativo) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    // Inicializa blocos e lê o primeiro valor
    for (int i = 0; i < qtdBlocos; i++) {
        char nome[50];
        sprintf(nome, "bloco_%d.txt", i + 1);
        blocos[i] = fopen(nome, "r");

        if (blocos[i] && fscanf(blocos[i], "%d", &valores[i]) == 1) {
            ativo[i] = 1;
        } else {
            ativo[i] = 0;
        }
    }

    FILE* saida = fopen(arquivoSaida, "w");
    if (!saida) {
        printf("Erro ao criar arquivo de saída.\n");
        return;
    }

    while (1) {
        int menor = INT_MAX, indiceMenor = -1;

        // encontra o menor valor entre os blocos
        for (int i = 0; i < qtdBlocos; i++) {
            if (ativo[i] && valores[i] < menor) {
                menor = valores[i];
                indiceMenor = i;
            }
        }

        if (indiceMenor == -1) break;

        fprintf(saida, "%d\n", menor);

        if (fscanf(blocos[indiceMenor], "%d", &valores[indiceMenor]) != 1) {
            ativo[indiceMenor] = 0;
            fclose(blocos[indiceMenor]);
        }
    }

    fclose(saida);

    for (int i = 0; i < qtdBlocos; i++) {
        char nome[50];
        sprintf(nome, "bloco_%d.txt", i + 1);
        remove(nome);
    }

    free(blocos);
    free(valores);
    free(ativo);

    printf("Arquivo final ordenado salvo em: %s\n", arquivoSaida);
}
