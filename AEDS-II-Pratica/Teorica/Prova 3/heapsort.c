#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Reajusta um nó para manter o max-heap
void heapify(int vet[], int n, int i) {
    int maior = i;       // assume que o nó i (pai) é o maior entre pai e filhos
    int esq = 2 * i + 1; // índice do filho esquerdo no array (heap representado por vetor)
    int dir = 2 * i + 2; // índice do filho direito no array

    // Se o filho da esquerda existe (esq < n) e é maior que o valor atual em 'maior', atualiza 'maior'
    if (esq < n && vet[esq] > vet[maior])
        maior = esq;

    // Se o filho da direita existe (dir < n) e é maior que o maior até agora, atualiza 'maior'
    if (dir < n && vet[dir] > vet[maior])
        maior = dir;

    // Se 'maior' mudou (ou seja, algum filho é maior que o pai), troca o pai com o maior filho
    if (maior != i) {
        swap(&vet[i], &vet[maior]);   // coloca o maior no topo dessa subárvore
        heapify(vet, n, maior);      // chama recursivamente para garantir que a subárvore onde o valor foi para também seja heap
    }
}

void heapSort(int vet[], int n) {
    // 1. Construir o max-heap (reorganizar vetor)
    for (int i = n/2 - 1; i >= 0; i--) // começa no último pai (n/2 - 1) e vai até a raiz (0)
        heapify(vet, n, i);           // para cada pai, ajusta a subárvore para ser max-heap

    // 2. Extrair os elementos um por um
    for (int i = n - 1; i > 0; i--) { // i é o índice do último elemento não-ordenado; decresce até 1
        // Move a raiz (maior elemento) para o fim do segmento não-ordenado
        swap(&vet[0], &vet[i]);       // coloca o maior elemento (vet[0]) na posição final correta (vet[i])

        // Reajusta o heap na porção vet[0..i-1] (ignora vet[i] que já está ordenado)
        heapify(vet, i, 0);           // chama heapify com novo tamanho i para restaurar a propriedade do max-heap a partir da raiz
    }
}
