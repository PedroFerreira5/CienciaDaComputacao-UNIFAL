#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} no;

no *f = NULL, *r = NULL;

void inserir(int valor)
{ // em uma fila voce insere no final (r)
    no *novo = malloc(sizeof(no));
    novo->data = valor;
    novo->next = NULL;
    if (f == NULL)
    { // fila vazia
        f = novo;
        r = novo;
    }
    else
    { // fila com algo
        r->next = novo;
        r = novo;
    }
}
void imprimirFila()
{
    no *aux = f;
    printf("Fila:  ");
    while (aux != NULL)
    {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

no *remover() //em uma fila voce remove do começo (f)
{
    if (f == NULL)
        return NULL; // Fila vazia
    no *removido = f;
    f = f->next;
    if (f == NULL)
        r = NULL;
    return removido;
}

int main()
{
    int opcao = -1;
    while (opcao != 0)
    {
        printf("\n************************* MENU ************************");
        printf("\n(1).Inserir na fila");
        printf("\n(2)Remover da fila");
        printf("\n(3)Imprimir fila");
        printf("\n(0).Sair");
        printf("\nEscolha a opção : \n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
        {
            int valor;
            printf("\nDigite o valor: ");
            scanf("%d", &valor);
            inserir(valor);
            break;
        }
        case 2:
        {
            no *n = remover();
            if (n != NULL)
            {
                printf("Removido: %d\n", n->data);
                free(n);
            }
            else
            {
                printf("Fila vazia!\n");
            }
            break;
        }
        case 3:
        {
            imprimirFila();
            break;
        }
        case 0:
        {
            printf("Fila finalizada!");
            break;
        }
        default:
            printf("Opção inválida! Tente outro número. \n");
            break;
        }
    }
    return 1;
}