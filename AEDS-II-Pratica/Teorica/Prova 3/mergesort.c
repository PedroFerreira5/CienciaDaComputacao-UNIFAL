#include <stdio.h>

// Função que intercala (merge) duas metades ordenadas do vetor
void merge(int vet[], int inicio, int meio, int fim) {
    int i, j, k;

    // Tamanhos das duas metades
    int n1 = meio - inicio + 1;   // tamanho da metade esquerda
    int n2 = fim - meio;          // tamanho da metade direita

    // Vetores temporários para armazenar as metades
    int L[n1], R[n2];

    // Copiando os elementos da metade esquerda para L[]
    for (i = 0; i < n1; i++) 
        L[i] = vet[inicio + i]; //(0+1, 0+2.... salvar posição)

    // Copiando os elementos da metade direita para R[]
    for (j = 0; j < n2; j++)
        R[j] = vet[meio + 1 + j];

    // Índices iniciais de cada vetor
    i = 0;        // índice do vetor L
    j = 0;        // índice do vetor R
    k = inicio;   // índice do vetor original

    // Intercalação: compara os menores elementos de L e R
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {       // se o elemento da esquerda é menor
            vet[k] = L[i];        // ele vai para o vetor original
            i++;                  // avança na esquerda
        } else {                  
            vet[k] = R[j];        // senão pega o da direita
            j++;                  // avança na direita
        }
        k++;                      // avança no vetor original
    }

    // Copia o restante dos elementos de L, se ainda houver (ELE COMPARA SE UM VETOR AUXILIAR TIVER MAIS QUE O OUTRO, "SOBRA")
    while (i < n1) {
        vet[k] = L[i];
        i++;
        k++;
    }

    // Copia o restante dos elementos de R, se ainda houver
    while (j < n2) {
        vet[k] = R[j];
        j++;
        k++;
    }
}

// Função principal do Merge Sort (recursiva)
void mergeSort(int vet[], int inicio, int fim) {
    if (inicio < fim) { // condição de parada: 1 elemento → já está ordenado
        int meio = inicio + (fim - inicio) / 2; // calcula o meio do vetor

        // Chamadas recursivas: divide em duas metades
        mergeSort(vet, inicio, meio);     // ordena a metade esquerda
        mergeSort(vet, meio + 1, fim);    // ordena a metade direita

        // Junta as duas metades ordenadas
        merge(vet, inicio, meio, fim);
    }
}

int main() {
    int vet[] = {10, 5, 8, 3, 9, 4, 1, 7};
    int n = sizeof(vet) / sizeof(vet[0]); // tamanho do vetor

    mergeSort(vet, 0, n - 1); // chama o merge sort completo

    // Imprime o vetor já ordenado
    for (int i = 0; i < n; i++)
        printf("%d ", vet[i]);

    return 0;
}
