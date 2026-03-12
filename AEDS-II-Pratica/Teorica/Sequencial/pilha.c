#include <stdlib.h>
#include <stdio.h>
#include "variaveis.h"
int topo = -1;
No p[MAX_PILHA_SIZE];

int inserePilha(No no) {
    if (topo == MAX_PILHA_SIZE - 1) { 
        return -1; // Retorna -1 para indicar que a pilha está cheia
    }
    topo++;
    p[topo] = no;
    return topo;
}


No* removePilha() {
    if (topo == -1) { //se pilha vazia
        return NULL; // NULL == a pilha está vazia
    }
    No *removido = &p[topo];
    topo--;   
    return removido; // Retorna o ponteiro para o elemento removido
}

int main() {
    No no1 = {1, 10};
    No no2 = {2, 20};
    No no3 = {3, 30};

    printf("--- Testando a insercao ---\n");
    inserePilha(no1);
    printf("Inserido: chave %d, valor %d. Topo: %d\n", p[topo].chave, p[topo].valor, topo);
    
    inserePilha(no2);
    printf("Inserido: chave %d, valor %d. Topo: %d\n", p[topo].chave, p[topo].valor, topo);
    
    inserePilha(no3);
    printf("Inserido: chave %d, valor %d. Topo: %d\n", p[topo].chave, p[topo].valor, topo);
    
    printf("\n--- Testando a remocao ---\n");
    No *removido1 = removePilha();
    if (removido1 != NULL) {
        printf("Elemento removido: chave %d, valor %d. Novo topo: %d\n", removido1->chave, removido1->valor, topo);
    }
    
    No *removido2 = removePilha();
    if (removido2 != NULL) {
        printf("Elemento removido: chave %d, valor %d. Novo topo: %d\n", removido2->chave, removido2->valor, topo);
    }
    printf("\n--- Tentando remover de uma pilha vazia ---\n");
    No *removido3 = removePilha();
    if (removido3 == NULL) {
        printf("Pilha vazia! Nao foi possivel remover.\n");
    }

    printf("\nFim do programa.");
    system("pause"); // Pausa o terminal para você ver a saída.
    
    return 0;
}