#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main() {

    struct Heap* h = heap_inicializa(10);

    printf("Inserindo valores no heap MAX:\n");
    heap_insere(h, 5);
    heap_insere(h, 12);
    heap_insere(h, 8);
    heap_insere(h, 30);
    heap_insere(h, 2);

    printf("\nHeap esta vazio? %s\n", ehVazia(h) ? "sim" : "nao");
    printf("Heap esta cheio? %s\n\n", ehCheia(h) ? "sim" : "nao");

    printf("Removendo valores (maiores primeiro):\n");
    while (!ehVazia(h)) {
        printf("removido: %d\n", heap_remove(h));
    }

    free(h->prioridade);
    free(h);

    return 0;
}
