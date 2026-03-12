#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de memória!\n");
        exit(1);
    }
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserir_nao_balanceado(No* raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }
    
    // Sempre insere na direita para criar árvore desbalanceada
    No* atual = raiz;
    while (atual->direita != NULL) {
        atual = atual->direita;
    }
    atual->direita = criar_no(valor);
    
    return raiz;
}

// Conta quantos nós tem na árvore
int contar_nos(No* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contar_nos(raiz->esquerda) + contar_nos(raiz->direita);
}

// Guarda os nós em ordem em um vetor
void guardar_nos_em_ordem(No* raiz, No** vetor, int* indice) {
    if (raiz == NULL) return;
    
    guardar_nos_em_ordem(raiz->esquerda, vetor, indice);
    vetor[*indice] = raiz;
    (*indice)++;
    guardar_nos_em_ordem(raiz->direita, vetor, indice);
}

No* construir_arvore_balanceada(No** vetor, int inicio, int fim) {
    if (inicio > fim) return NULL;
    
    int meio = (inicio + fim) / 2;
    No* raiz = vetor[meio];
    
    raiz->esquerda = construir_arvore_balanceada(vetor, inicio, meio - 1);
    raiz->direita = construir_arvore_balanceada(vetor, meio + 1, fim);
    
    return raiz;
}

// Balanceia a árvore
No* balancear_arvore(No* raiz) {
    if (raiz == NULL) return NULL;
    
    int total_nos = contar_nos(raiz);
    No** vetor_nos = (No**)malloc(total_nos * sizeof(No*));
    if (vetor_nos == NULL) {
        printf("Erro de memória!\n");
        exit(1);
    }
    
    int indice = 0;
    guardar_nos_em_ordem(raiz, vetor_nos, &indice);
    
    No* raiz_balanceada = construir_arvore_balanceada(vetor_nos, 0, total_nos - 1);
    free(vetor_nos);
    
    return raiz_balanceada;
}

// Imprime a árvore em ordem
void imprimir_em_ordem(No* raiz) {
    if (raiz == NULL) return;
    imprimir_em_ordem(raiz->esquerda);
    printf("%d ", raiz->valor);
    imprimir_em_ordem(raiz->direita);
}

// Imprime a estrutura da árvore de forma visual
void imprimir_estrutura(No* raiz, int nivel) {
    if (raiz == NULL) return;
    
    imprimir_estrutura(raiz->direita, nivel + 1);
    
    for (int i = 0; i < nivel; i++) {
        printf("    ");
    }
    printf("%d\n", raiz->valor);
    
    imprimir_estrutura(raiz->esquerda, nivel + 1);
}

// Libera a memória da árvore
void liberar_arvore(No* raiz) {
    if (raiz == NULL) return;
    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);
    free(raiz);
}

// Função principal
int main() {
    No* arvore_desbalanceada = NULL;
    No* arvore_balanceada = NULL;
    
    printf("=== ARVORE BINARIA - BALANCEAMENTO ===\n\n");
    
    // Criando árvore desbalanceada artificialmente
    printf("Criando arvore desbalanceada...\n");
    int valores[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int quantidade_valores = 10;
    
    for (int i = 0; i < quantidade_valores; i++) {
        arvore_desbalanceada = inserir_nao_balanceado(arvore_desbalanceada, valores[i]);
    }
    
    printf("\nARVORE DESBALANCEADA:\n");
    printf("Estrutura visual:\n");
    imprimir_estrutura(arvore_desbalanceada, 0);
    
    printf("\nValores em ordem: ");
    imprimir_em_ordem(arvore_desbalanceada);
    printf("\n");
    
    printf("Total de nos: %d\n", contar_nos(arvore_desbalanceada));
    
    // Balanceando a árvore
    printf("\n--- BALANCEANDO A ARVORE ---\n");
    arvore_balanceada = balancear_arvore(arvore_desbalanceada);
    
    printf("\nARVORE BALANCEADA:\n");
    printf("Estrutura visual:\n");
    imprimir_estrutura(arvore_balanceada, 0);
    
    printf("\nValores em ordem: ");
    imprimir_em_ordem(arvore_balanceada);
    printf("\n");
    
    printf("Total de nos: %d\n", contar_nos(arvore_balanceada));
    
    // Liberando memória
    liberar_arvore(arvore_balanceada);
    
    printf("\nMemoria liberada. Fim do programa.\n");
    
    return 0;
}