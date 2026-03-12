#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura do item/nó da lista ligada
struct Item {
    int valor; // O valor/chave armazenado
    struct Item* proximo; // Ponteiro para o próximo nó na lista
};

// Estrutura da tabela hash
struct Hash {
    // Array de ponteiros para Item. Cada elemento é o cabeçalho de uma lista ligada.
    struct Item** items; 
};

// Variável global para o tamanho da tabela (M)
extern int M;

// Protótipos das funções
struct Hash* criar_hash(int tamanho);
void hash_insere(struct Hash* hash, struct Item item);
void hash_remove(struct Hash* hash, struct Item item);
struct Item* busca(struct Hash* hash, struct Item item);
int hashing(int chave);
void liberar_hash(struct Hash* hash); // Função para liberar memória

#endif // HASH_H