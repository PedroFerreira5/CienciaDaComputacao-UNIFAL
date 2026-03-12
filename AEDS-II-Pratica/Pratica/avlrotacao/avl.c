#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

// Obtem a altura da AVL
int altura(struct Node *N) {
    if (N == NULL) {
        return 0;
    }
    return N->altura;
}

// Obtem o máximo entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

/* Cria um novo nó com apontadores esquerda e direita nulos */
struct Node* newNode(int valor) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    if (node == NULL) {
        perror("Falha ao alocar memória para novo nó.");
        exit(EXIT_FAILURE);
    }
    node->valor     = valor;
    node->esquerda  = NULL;
    node->direita   = NULL;
    node->altura    = 1; // Novo nó é adicionado como folha
    return(node);
}

// Faz a rotação a direita na raiz y
struct Node *direitaRotate(struct Node *y) {
    struct Node *x = y->esquerda;
    struct Node *T2 = x->direita;

    // Realiza a rotação
    x->direita = y;
    y->esquerda = T2;

    // Atualiza as alturas
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    // Retorna a nova raiz
    return x;
}

// Faz a rotação a esquerda na raiz x
struct Node *esquerdaRotate(struct Node *x) {
    struct Node *y = x->direita;
    struct Node *T2 = y->esquerda;

    // Realiza a rotação
    y->esquerda = x;
    x->direita = T2;

    // Atualiza as alturas (x é o nó mais baixo, atualize primeiro)
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    // Retorna a nova raiz
    return y;
}

// Obtem o fator de balanceamento para o nó N
int balanceamento(struct Node *N) {
    if (N == NULL) {
        return 0;
    }
    return (altura(N->esquerda) - altura(N->direita));
}

// Função recursiva para inserir um novo item na árvore
struct Node* inserir(struct Node* node, int valor) {
    /* 1. Realiza a inserção normal de árvore binária */
    if (node == NULL) {
        return(newNode(valor));
    }

    if (valor < node->valor) {
        node->esquerda  = inserir(node->esquerda, valor);
    } else if (valor > node->valor){
        node->direita = inserir(node->direita, valor);
    } else {
        // Valores duplicados não são permitidos
        return node;
    }

    /* 2. Atualiza a altura de seu antecessor */
    node->altura = 1 + max(altura(node->esquerda), altura(node->direita));

    /* 3. Obtem o fator de balanceamento */
    int balance = balanceamento(node);

    // Se desbalanceada, trata os 4 casos:

    // Caso Esquerda Esquerda (Rotação Simples à Direita)
    if (balance > 1 && valor < node->esquerda->valor) {
        return direitaRotate(node);
    }

    // Caso Direita Direita (Rotação Simples à Esquerda)
    if (balance < -1 && valor > node->direita->valor) {
        return esquerdaRotate(node);
    }

    // Caso Esquerda Direita (Rotação Dupla: Esquerda + Direita)
    if (balance > 1 && valor > node->esquerda->valor) {
        node->esquerda = esquerdaRotate(node->esquerda);
        return direitaRotate(node);
    }

    // Caso Direita Esquerda (Rotação Dupla: Direita + Esquerda)
    if (balance < -1 && valor < node->direita->valor) {
        node->direita = direitaRotate(node->direita);
        return esquerdaRotate(node);
    }

    /* Retorna o ponteiro (pode ter sido atualizado) para a raiz */
    return node;
}

// Imprime os nós em ordem (In-Order Traversal)
void inOrder(struct Node *raiz) {
    if(raiz != NULL) {
        inOrder(raiz->esquerda);
        printf("%d ", raiz->valor);
        inOrder(raiz->direita);
    }
}