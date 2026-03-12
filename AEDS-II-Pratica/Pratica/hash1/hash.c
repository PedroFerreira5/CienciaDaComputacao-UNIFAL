#include "hash.h"

// Variável M (tamanho da tabela) declarada como externa no .h
int M;

/**
 * Cria e inicializa a tabela hash.
 * Aloca a memória para o array de ponteiros e inicializa todos com NULL.
 */
struct Hash* criar_hash(int tamanho) {
    M = tamanho;
    struct Hash* hash = (struct Hash*) malloc(sizeof(struct Hash));
    if (hash == NULL) {
        perror("Erro ao alocar struct Hash");
        exit(EXIT_FAILURE);
    }
    
    // Aloca um array de ponteiros para Item e inicializa todos com NULL
    hash->items = (struct Item**) calloc(tamanho, sizeof(struct Item*)); 
    if (hash->items == NULL) {
        perror("Erro ao alocar hash->items");
        free(hash);
        exit(EXIT_FAILURE);
    }
    
    printf("\nHash criada com sucesso (Tamanho M=%d).\n", tamanho);
    return hash;
}

/**
 * Função de hash simples (k mod M).
 */
int hashing(int chave) {
    return (chave % M);
}

/**
 * Insere um novo item na tabela hash usando encadeamento separado.
 * O novo item é inserido no início da lista ligada no bucket.
 */
void hash_insere(struct Hash* hash, struct Item item) {
    int pos = hashing(item.valor);
    
    // 1. Criar um novo nó (Item)
    struct Item* novo_item = (struct Item*) malloc(sizeof(struct Item));
    if (novo_item == NULL) {
        perror("Erro ao alocar novo item");
        return;
    }
    novo_item->valor = item.valor;
    
    // 2. O novo nó aponta para o item que está atualmente no bucket (cabeçalho da lista)
    novo_item->proximo = hash->items[pos];
    
    // 3. Atualiza o array para apontar para o novo nó (inserção no início)
    hash->items[pos] = novo_item;
    
    printf("\nItem %d inserido na posição %d.", item.valor, pos);
}

/**
 * Busca um item na tabela hash.
 * Percorre a lista ligada no bucket correspondente.
 * Retorna um ponteiro para o Item se encontrado, ou NULL.
 */
struct Item* busca(struct Hash* hash, struct Item item) {
    int pos = hashing(item.valor);
    struct Item* atual = hash->items[pos];
    
    // Percorre a lista no bucket
    while (atual != NULL) {
        if (atual->valor == item.valor) {
            printf("\nItem %d encontrado na posição %d.", item.valor, pos);
            return atual; // Item encontrado
        }
        atual = atual->proximo;
    }
    
    printf("\nItem %d não encontrado.", item.valor);
    return NULL; // Item não encontrado
}

/**
 * Remove um item da tabela hash.
 * Percorre a lista ligada, localiza o nó e o remove, liberando a memória.
 */
void hash_remove(struct Hash* hash, struct Item item) {
    int pos = hashing(item.valor);
    struct Item* anterior = NULL;
    struct Item* atual = hash->items[pos];
    
    // Percorre a lista para encontrar o item
    while (atual != NULL && atual->valor != item.valor) {
        anterior = atual;
        atual = atual->proximo;
    }
    
    // Se 'atual' for NULL, o item não foi encontrado
    if (atual == NULL) {
        printf("\nItem %d não encontrado para remoção.", item.valor);
        return;
    }
    
    // Item encontrado. Remove-o da lista.
    if (anterior == NULL) {
        // O item a ser removido é o primeiro da lista
        hash->items[pos] = atual->proximo;
    } else {
        // O item está no meio/fim da lista
        anterior->proximo = atual->proximo;
    }
    
    free(atual); // Libera a memória do nó removido
    printf("\nItem %d removido da posição %d.", item.valor, pos);
}

/**
 * Libera toda a memória alocada para a tabela hash.
 */
void liberar_hash(struct Hash* hash) {
    if (hash == NULL) return;

    for (int i = 0; i < M; i++) {
        struct Item* atual = hash->items[i];
        struct Item* temp;
        // Libera cada nó da lista ligada
        while (atual != NULL) {
            temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
    // Libera o array de ponteiros
    free(hash->items);
    // Libera a estrutura Hash
    free(hash);
    printf("\nMemória da Hash liberada.\n");
}

int main() { 
    int n;
    /* Cria hash com 10 posições */
    struct Hash* hash = criar_hash(10);
    struct Item item;
    struct Item* resultado; // Para armazenar o ponteiro de retorno da busca
    
    do {
        printf("\n\n\n******************** Escolha a opção *******************");
        printf("\n1.Inserir item");
        printf("\n2.Remover item");
        printf("\n3.Obter item");
        printf("\n0.Sair");
        printf("\nEntre sua opção : ");
        if (scanf("%d",&n) != 1) {
            // Lidar com entrada inválida (não numérica)
            while (getchar() != '\n'); // Limpa o buffer de entrada
            n = -1; // Define uma opção inválida
        }

        switch(n) {
            case 1: printf("\nDigite o item (número inteiro): ");
                    scanf("%d",&item.valor);
                    hash_insere(hash, item);
                    break;
            case 2: printf("\nDigite o item a remover: ");
                    scanf("%d",&item.valor);
                    hash_remove(hash, item);
                    break;
            case 3: printf("\nDigite o item a buscar: ");
                    scanf("%d",&item.valor);
                    resultado = busca(hash, item);
                    if (resultado != NULL) {
                        printf("\nValor obtido: %d", resultado->valor);
                    }
                    break;
            case 0: liberar_hash(hash); // Libera a memória antes de sair
                    exit(0);
            default: printf("\n Opção errada!");
                    break;
            }
        } while(1);
}