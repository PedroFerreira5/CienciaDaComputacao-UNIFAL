#include <stdio.h>
#include "avl.h"

/* Driver program para testar a Árvore AVL */
int main() {
    struct Node *raiz = NULL;

    printf("--- Teste de Inserção na Árvore AVL ---\n");
    printf("Inserindo: 10, 20, 30, 40, 50, 25\n");
    
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 30);
    // Inserção 40, 50 causará Rotação Simples à Esquerda (DD) em 30
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 50);
    // Inserção 25 causará Rotação Dupla Direita Esquerda (DE) em 40
    // A árvore final será rebalanceada com a raiz 30.
    raiz = inserir(raiz, 25);
    
    /* A árvore final será:
                30
               /  \
              20  40
             / \    \
            10 25    50
    */

    printf("\nOs elementos da árvore, em ordem (In-Order Traversal), são:\n");
    // A saída esperada é: 10 20 25 30 40 50
    inOrder(raiz);
    printf("\n");

    return 0;
}