
// QUICK SORT AUXILIAR
int divide(int *vetor, int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1, j, aux;

    for (j = inicio; j < fim; j++) {
        if (vetor[j] < pivo) {
            i++;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }
    aux = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = aux;
    return i + 1;
}

// QUICK SORT
void quickSort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int p = divide(vetor, inicio, fim);
        quickSort(vetor, inicio, p - 1);
        quickSort(vetor, p + 1, fim);
    }
}

void ordenacao(int *vetor, int tamanho) {
    quickSort(vetor, 0, tamanho - 1);
}
