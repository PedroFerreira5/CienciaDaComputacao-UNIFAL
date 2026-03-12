#ifndef AVL_H
#define AVL_H

// Definição da estrutura do nó da Árvore AVL
struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
    int altura;
};

// Protótipos das funções
int altura(struct Node *N);
struct Node* newNode(int valor);
struct Node* direitaRotate(struct Node *y);
struct Node* esquerdaRotate(struct Node *x);
int balanceamento(struct Node *N);
struct Node* inserir(struct Node* node, int valor);
void inOrder(struct Node *raiz);

#endif // AVL_H