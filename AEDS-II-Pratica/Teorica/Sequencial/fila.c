#include <stdio.h>
#include <stdlib.h>
#include "variaveis.h"

int f = -1;
int r = -1;
No fi[MAX_FILA_SIZE];

int insereFila(No no) {
    int prov = (r + 1) % MAX_FILA_SIZE;
    
    if (prov == f && r != -1) {
        return -1;
    }
    
    r = prov;
    fi[r] = no;
    
    if (f == -1) {
        f = 0;
    }
    
    return r;
}

No* removeFila() {
    No* removido = NULL;
    
    if (f == -1) {
        return NULL;
    }
    
    removido = &fi[f];
    
    if (f == r) {
        f = -1;
        r = -1;
    } else {
        f = (f + 1) % MAX_FILA_SIZE;
    }
    
    return removido;
}

int main() {
    printf("--- Testando a Fila ---\n\n");
    
    printf("Inserindo elementos...\n");
    No no1 = {10, 100};
    No no2 = {20, 200};
    No no3 = {30, 300};

    int res1 = insereFila(no1);
    printf("Inserido: chave %d, valor %d. Retaguarda: %d, Frente: %d\n", fi[res1].chave, fi[res1].valor, r, f);
    
    int res2 = insereFila(no2);
    printf("Inserido: chave %d, valor %d. Retaguarda: %d, Frente: %d\n", fi[res2].chave, fi[res2].valor, r, f);
    
    int res3 = insereFila(no3);
    printf("Inserido: chave %d, valor %d. Retaguarda: %d, Frente: %d\n", fi[res3].chave, fi[res3].valor, r, f);

    printf("\nRemovendo elementos...\n");
    No *removido1 = removeFila();
    if (removido1 != NULL) {
        printf("Removido: chave %d, valor %d. Retaguarda: %d, Frente: %d\n", removido1->chave, removido1->valor, r, f);
    }
    
    No *removido2 = removeFila();
    if (removido2 != NULL) {
        printf("Removido: chave %d, valor %d. Retaguarda: %d, Frente: %d\n", removido2->chave, removido2->valor, r, f);
    }
    
    printf("\nTentando remover de uma fila vazia...\n");
    No *removido3 = removeFila();
    if (removido3 == NULL) {
        printf("A fila esta vazia. Nao foi possivel remover.\n");
    }

    system("pause");
    
    return 0;
}