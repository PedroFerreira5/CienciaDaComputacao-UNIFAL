// hash.h
#ifndef HASH_H
#define HASH_H

// Estrutura para um nó de Item/Lista Ligada (chain)
struct Item {
    int valor;
    struct Item* proximo; // Ponteiro para o próximo item em caso de colisão
};

// Estrutura para a Tabela Hash
struct Hash {
    // Array de ponteiros, onde cada ponteiro é o cabeçalho de uma lista ligada
    struct Item** items; 
};

// Declarações das funções (assinaturas)
struct Hash* criar_hash(int tamanho);
void hash_insere(struct Hash* hash, struct Item item);
void hash_remove(struct Hash* hash, struct Item item);
struct Item busca(struct Hash* hash, struct Item item);
int hashing(int chave);
void liberar_hash(struct Hash* hash); // Adicionada função para liberar memória

#endif