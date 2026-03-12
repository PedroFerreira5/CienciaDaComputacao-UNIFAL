// Função para trocar dois valores
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição (Lomuto)
int partition(int vet[], int inicio, int fim) {
    int pivo = vet[fim];   // escolhe o pivô
    int i = inicio - 1;    // marca posição dos menores

    for (int j = inicio; j < fim; j++) {
        // se elemento atual é <= ao pivô
        if (vet[j] <= pivo) {
            i++;
            swap(&vet[i], &vet[j]); // traz o menor pra esquerda
        }
    }

    // coloca o pivô na posição correta
    swap(&vet[i + 1], &vet[fim]);
    return i + 1;  // retorna posição final do pivô
}

// Algoritmo Quick Sort
void quickSort(int vet[], int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = partition(vet, inicio, fim);
        
        // ordena a metade esquerda
        quickSort(vet, inicio, indicePivo - 1);

        // ordena a metade direita
        quickSort(vet, indicePivo + 1, fim);
    }
}


int main(void) {
    int v[] = {5, 3, 9, 1, 7, 2};
    int n = sizeof(v) / sizeof(v[0]);

    quickSort(v, 0, n - 1);

    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");
    return 0;
}