#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "algorithms.h"

// Algoritmo de Dijkstra usando matriz de adjacência
#define INF 999999999.0
 
double dijkstra(int **matriz, int num_nos, int origem) {
    double custo = 0;
 
    double *distancia = (double*) malloc(num_nos * sizeof(double));
    bool *visitado = (bool*) malloc(num_nos * sizeof(bool));
 
    // Inicialização
    for (int i = 0; i < num_nos; i++) {
        distancia[i] = INF;
        visitado[i] = false;
        custo++;
    }
    distancia[origem] = 0;
 
    // Loop principal
    for (int i = 0; i < num_nos; i++) {
 
        double min_dist = INF;
        int u = -1;
 
        // Escolhe o nó não visitado com menor distância
        for (int j = 0; j < num_nos; j++) {
            custo++;
            if (!visitado[j] && distancia[j] < min_dist) {
                min_dist = distancia[j];
                u = j;
            }
        }
 
        if (u == -1) break;
 
        visitado[u] = true;
        custo++;
 
        // Relaxamento das arestas
        for (int v = 0; v < num_nos; v++) {
            custo++;
            if (matriz[u][v] != 0 && !visitado[v]) {
                if (distancia[u] != INF && distancia[u] + matriz[u][v] < distancia[v]) {
                    distancia[v] = distancia[u] + matriz[u][v];
                    custo++;
                }
            }
        }
    }
 
    free(distancia);
    free(visitado);
 
    return custo;
}

// Algoritmo de Duan usando matriz de adjacência, serve para achar o menor caminho pelos menores pesos
double duan(int **matriz, int num_nos, int origem) { 
    double custo = 0;

    
    
    return custo;
}

// Implementação do terceiro usando matriz de adjacência
double outro(int **matriz, int num_nos, int origem) {
    double custo = 0;

    /***********************
    ***********************
     Implementar código aqui
    ************************
    ***********************/

    /* Esta retorno também é obrigatório e não deve ser retirado*/  
    return custo;
}