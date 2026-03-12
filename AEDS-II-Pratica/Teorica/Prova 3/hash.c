#include <stdlib.h>   
#include <stdio.h>    
#include <stdbool.h>  

void troca(int *x, int *y){
    int aux = *x;  
    *x = *y;       
    *y = aux;     
}

// Função para imprimir o vetor
int imprime_vetor(int vetor[], int n){
    for (int i = 0; i < n; i++){   
        printf("%d ", vetor[i]);   
    }
    printf("\n");                  
}

#define TAMANHO_TABELA 10  

// Estrutura de um nó da lista encadeada (cada nó guarda uma chave, um valor e o próximo nó)
typedef struct No {
    int chave;        // chave usada para calcular o índice da hash (identificador)
    int valor;        // valor associado à chave (pode ser o dado que você quer armazenar)
    struct No* prox;  // ponteiro para o próximo nó da lista (colisão: vários nós na mesma posição)
} No;

// Estrutura da tabela hash: vetor de ponteiros para listas (cada posição aponta para início da lista)
typedef struct {
    No* tabela[TAMANHO_TABELA]; // array de ponteiros para No, tamanho definido por TAMANHO_TABELA
} TabelaHash;


// Função hash simples (método da divisão): transforma a chave em índice entre 0 e TAMANHO_TABELA-1
int funcaoHash(int chave) {
    return chave % TAMANHO_TABELA; // resto da divisão garante índice válido
}

// Busca um elemento na tabela hash; retorna o valor associado ou -1 se não encontrar
int buscar(TabelaHash* th, int chave) {
    int indice = funcaoHash(chave); // calcula onde procurar usando a função hash
    No* atual = th->tabela[indice]; // pega o início da lista na posição calculada
    
    // Percorre a lista encadeada procurando pela chave
    while (atual != NULL) {         // enquanto houver nós na lista
        if (atual->chave == chave)  // se a chave do nó atual for a que procuramos
            return atual->valor;    // retorna o valor associado (encontrado)
        atual = atual->prox;        // avança para o próximo nó
    }
    
    return -1; // Não encontrou: retorna -1 como sinal de "não encontrado"
}

// Insere um par (chave, valor) na tabela hash (insere no início da lista da posição)
void inserir(TabelaHash* th, int chave, int valor) {
    int indice = funcaoHash(chave); // calcula a posição na tabela

    // Cria um novo nó na memória
    No* novo = (No*)malloc(sizeof(No)); // aloca espaço para o nó
    novo->chave = chave;                // coloca a chave no nó
    novo->valor = valor;                // coloca o valor no nó
    novo->prox = th->tabela[indice];    // faz o novo nó apontar para o que já estava na lista (inserção no início)
    
    // Atualiza o início da lista para o novo nó
    th->tabela[indice] = novo;
}

// Remove um elemento (pela chave) da tabela hash
void remover(TabelaHash* th, int chave) {
    int indice = funcaoHash(chave); // calcula a posição onde a chave deveria estar
    No* atual = th->tabela[indice]; // nó atual para percorrer a lista
    No* anterior = NULL;            // ponteiro para guardar o nó anterior (para conectar a lista ao remover)
    
    // Procura o elemento na lista encadeada
    while (atual != NULL && atual->chave != chave) {
        anterior = atual;           // guarda o nó anterior
        atual = atual->prox;        // avança para o próximo
    }
    
    // Se o laço terminou e atual == NULL, quer dizer que não encontrou a chave
    if (atual == NULL) {
        printf("Chave %d não encontrada.\n", chave); // mensagem informando ausência
        return; // termina a função
    }
    
    // Se anterior == NULL, o nó a remover é o primeiro da lista (cabeça)
    if (anterior == NULL) {
        th->tabela[indice] = atual->prox; // atualiza o início da lista para o próximo nó
    } else {
        // Caso contrário, pula o nó atual na lista (removendo-o)
        anterior->prox = atual->prox;
    }
    
    free(atual); // libera a memória do nó removido
}
