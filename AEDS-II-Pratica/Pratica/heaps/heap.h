#ifndef HEAP_H
#define HEAP_H

struct Heap {
    int max;
    int pos;
    int *prioridade;
};

struct Heap* heap_inicializa(int max);
void heap_insere(struct Heap* heap, int prioridade);
int heap_remove(struct Heap* heap);

void corrige_acima(struct Heap* heap, int pos);
void corrige_abaixo(int *prios, int atual, int tam);

void troca(int a, int b, int* v);

int ehVazia(struct Heap *heap);
int ehCheia(struct Heap *heap);

#endif
