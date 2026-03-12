#include <stdio.h>

void swap(int *xp, int *yp){
    int temp = *xp;  // guarda o valor de xp TEMPORARIO
    *xp = *yp; // xp recebe o valor de yp ANTERIOR RECEBE O VALOR MAIOR
    *yp = temp;    // yp recebe o valor guardado em temp
    // *xp = endereço de &j
    // *yp  = endereço de &j+1
}


// Função Bubble Sort
void bubbleSort(int vet[], int n) {
    
    int trocou =0;
    int i , j; // variaveis
    for(i=0; i < n-1; i++){ //controla o número de passadas no vetor (i < tamanho do vetor - 1)
       trocou = 0; //flag
        for(j=0; j < n - 1 - i; j++){  //percorre o vetor até a última posição não ordenada
            if (vet[j] > vet [j + 1]){ // Compara o elemento atual com o próximo
                swap(&vet[j], &vet[j+1]); //  // Se estiverem fora de ordem, troca usando a função swap
                 trocou = 1; //flag              
            } 
       }
    }
    if (!trocou); // se nao trocou nada, ja esta ordenado O(n)
}

int main() {

    // Vetor já preenchido
    int vet[] = {5, 2, 9, 1, 7, 3};
    int n = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    // Chama o Bubble Sort
    bubbleSort(vet, n);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}
