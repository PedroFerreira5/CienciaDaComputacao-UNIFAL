#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

// Variável global para o tamanho da tabela hash (M)
int M;

struct Hash* criar_hash(int tamanho) {
    M = tamanho;
    struct Hash* hash = (struct Hash*) malloc(sizeof(struct Hash));
    if (hash == NULL) {
        perror("Falha na alocacao da estrutura Hash");
        exit(EXIT_FAILURE);
    }
    // Usa calloc para alocar e inicializar todos os ponteiros do array com NULL
    hash->items = (struct Item**) calloc(tamanho, sizeof(struct Item*));
    if (hash->items == NULL) {
        perror("Falha na alocacao do array de itens");
        free(hash);
        exit(EXIT_FAILURE);
    }
    return hash;
}

int hashing(int chave) {
    // Funcao hash f(k) = k % M, conforme especificado
    return (chave % M);
}

void hash_insere(struct Hash* hash, struct Item item) {
    int indice = hashing(item.valor);
    
    struct Item* novoItem = (struct Item*) malloc(sizeof(struct Item));
    if (novoItem == NULL) {
        perror("Falha na alocacao de memoria para o Item");
        return;
    }
    novoItem->valor = item.valor;
    
    novoItem->proximo = hash->items[indice];
    hash->items[indice] = novoItem;
    
    printf("\n✅ Item %d inserido na posicao %d.", item.valor, indice);
}

void hash_remove(struct Hash* hash, struct Item item) {
    int indice = hashing(item.valor);
    struct Item* atual = hash->items[indice];
    struct Item* anterior = NULL;

 
    while (atual != NULL) {
        if (atual->valor == item.valor) {
           
            if (anterior == NULL) {
              
                hash->items[indice] = atual->proximo;
            } else {
              
                anterior->proximo = atual->proximo;
            }
            free(atual); 
            printf("\n🗑️ Item %d removido da posicao %d.", item.valor, indice);
            return; 
        }
        
        anterior = atual;
        atual = atual->proximo;
    }
    
    printf("\n❌ Item %d nao encontrado para remocao.", item.valor);
}

struct Item busca(struct Hash* hash, struct Item item) {
    int indice = hashing(item.valor);
    struct Item* atual = hash->items[indice];

   
    while (atual != NULL) {
        if (atual->valor == item.valor) {
            printf("\n🔍 Item %d encontrado na posicao %d.", atual->valor, indice);
            return *atual;
        }
        atual = atual->proximo;
    }
    
    
    struct Item notFound = {-1, NULL}; 
    printf("\n Item %d nao encontrado.", item.valor);
    return notFound;
}

void liberar_hash(struct Hash* hash) {
    if (hash == NULL) return;
    
    for (int i = 0; i < M; i++) {
        struct Item* atual = hash->items[i];
        struct Item* proximo;
        
       
        while (atual != NULL) {
            proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }
    

    free(hash->items);
    
    
    free(hash);
    printf("\nMemoria da Tabela Hash liberada com sucesso.");
}


int main() {
    int n;
    /* Cria hash com 10 posições */
    struct Hash* hash = criar_hash(10);
    struct Item item;
    
    do {
        printf("\n\n\n******************** Escolha a opcao *******************");
        printf("\n1. Inserir item");
        printf("\n2. Remover item");
        printf("\n3. Obter item");
        printf("\n0. Sair");
        printf("\nEntre sua opcao : ");
        
        // Verifica se a leitura foi bem-sucedida e limpa o buffer
        if (scanf("%d", &n) != 1) {
            while (getchar() != '\n');
            n = -1; // Opção inválida
        }
        
        switch(n) {
            case 1: 
                printf("\nDigite o item (valor inteiro): ");
                if (scanf("%d", &item.valor) == 1) {
                    hash_insere(hash, item);
                } else {
                    printf("\nEntrada invalida.");
                    while (getchar() != '\n');
                }
                break;
            case 2: 
                printf("\nDigite o item para remocao: ");
                if (scanf("%d", &item.valor) == 1) {
                    hash_remove(hash, item);
                } else {
                    printf("\nEntrada invalida.");
                    while (getchar() != '\n');
                }
                break;
            case 3: 
                printf("\nDigite o item para busca: ");
                if (scanf("%d", &item.valor) == 1) {
                    item = busca(hash, item);
                } else {
                    printf("\nEntrada invalida.");
                    while (getchar() != '\n');
                }
                break;
            case 0: 
                liberar_hash(hash); // Chama a função para evitar vazamento de memória
                exit(0);
                break;
            default: 
                printf("\n Opcao errada!");
                break;
        }
    } while(1);
    
    return 0; 
}