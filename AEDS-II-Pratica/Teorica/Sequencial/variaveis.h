#ifndef VARIAVEIS_H
#define VARIAVEIS_H
typedef struct {
    int chave;
    int valor;
} No;

extern No L[5];
extern No L1[6];
extern No p[6];  // Pilha
extern No fi[6]; // Fila

// Variáveis de controle de tamanho e índices
extern int m;    // Tamanho atual da lista L
extern int n;    // Tamanho atual da lista L1
extern int topo; // Índice do topo da pilha p
extern int f;    // Índice da frente (front) da fila fi
extern int r;    // Índice da retaguarda (rear) da fila fi

// Definições de tamanho máximo (boas práticas)
#define MAX_L_SIZE 5
#define MAX_L1_SIZE 6
#define MAX_PILHA_SIZE 6
#define MAX_FILA_SIZE 6

// Protótipos das funções
// Os protótipos devem ter os tipos de dados corretos.
// Funções de busca em lista
int busca1(int x);      // Busca linear em lista
int busca2(int x);      // Busca linear em outra lista (ou nome duplicado?)
int buscaOrd(int x);    // Busca em lista ordenada
int buscaBin(int x);    // Busca binária

// Funções de manipulação de lista
int insere(No no);
No* removeLista(int x);

// Funções de manipulação de pilha
int inserePilha(No no); // Corrigido para usar o tipo 'No'
No* removePilha();      // Corrigido para retornar um ponteiro para 'No'

// Funções de manipulação de fila
int insereFila(No no);
No* removeFila();

#endif