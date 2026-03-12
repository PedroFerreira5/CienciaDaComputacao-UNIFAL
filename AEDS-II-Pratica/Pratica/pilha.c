#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //INT_MIN é um valor que normalmente não seria um elemento válido da pilha.
#include <stdbool.h>


struct no {
    int item;
    struct no* prox;
};

struct pilha {
    struct no* topo;
    int tamanho; 
};

// pilha vazia
struct pilha* criar_pilha() {
    struct pilha* p = (struct pilha*) malloc(sizeof(struct pilha));
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

// Verifica se a pilha está vazia
bool ehVazia(struct pilha* pilha) {
    return (pilha->topo == NULL);
}

// Insere um elemento no topo da pilha
void push(struct pilha* pilha, int item) {
    struct no* novo_no = (struct no*) malloc(sizeof(struct no));
    if (novo_no == NULL) {
        printf("\nErro de alocação de memória");
        return;
    }
    novo_no->item = item;
    novo_no->prox = pilha->topo;
    pilha->topo = novo_no;
    pilha->tamanho++;
}

// Remove e retorna o elemento do topo da pilha
int pop(struct pilha* pilha) {
    if (ehVazia(pilha)) {
        printf("\nPilha vazia. Impossível remover elementos");
        return -1;
    }
    struct no* temp = pilha->topo;
    int item = temp->item;
    pilha->topo = temp->prox;
    free(temp);
    pilha->tamanho--;
    return item;
}

// Retorna o elemento do topo sem remover
int obtem_elemento(struct pilha* pilha) {
    if (ehVazia(pilha)) {
        printf("\nPilha vazia. Impossível obter elementos");
        return INT_MIN;
    }
    return pilha->topo->item;
}

// Função para liberar toda a memória da pilha
void liberar_pilha(struct pilha* pilha) {
    while (!ehVazia(pilha)) {
        pop(pilha);
    }
    free(pilha);
}

int main() {
    int val, n;
    bool aux;
    struct pilha* pilha = criar_pilha();

    do {
        printf("\n************************* MENU ************************");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Obtém elemento");
        printf("\n4. Pilha vazia?");
        printf("\n5. Sair");
        printf("\nDigite sua escolha : ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("\nDigite o valor: ");
                scanf("%d", &val);
                push(pilha, val);
                break;
            case 2:
                val = pop(pilha);
                if (val != -1)
                    printf("\nElemento retirado: %d", val);
                break;
            case 3:
                val = obtem_elemento(pilha);
                if (val != INT_MIN)
                    printf("\nElemento do topo: %d", val);
                break;
            case 4:
                aux = ehVazia(pilha);
                if (aux) {
                    printf("\nPilha vazia");
                } else {
                    printf("\nPilha não está vazia");
                }
                break;
            case 5:
                liberar_pilha(pilha);
                return 0;
            default:
                printf("\nOpção errada!");
                break;
        }
    } while (1);

    return 0;
}
