#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
} *p, *tmp, *tmp1;

void inserirPosicao(int valor, int posicao)
{
    int i = 1;
    tmp1 = (struct node *)malloc(sizeof(struct node)); // novo nó
    tmp1->data = valor;                                // data = valor

    if (posicao == 1)
    {
        tmp1->next = p;
        p = tmp1;
        return;
    }

    tmp = p; // ponteiro começa do início

    // Percorre até o nó anterior à posição desejada
    while (i < posicao - 1 && tmp != NULL)
    {
        i++;
        tmp = tmp->next;
    }

    if (tmp == NULL)
    {
        printf("\nPosição inválida! Lista tem menos elementos.");
        free(tmp1);
        return;
    }

    tmp1->next = tmp->next;
    tmp->next = tmp1;
}
void removerPosicao(int posicao){
    if (posicao == 1 && p != NULL)
    {
        tmp1 = p;    // -> nó a ser removido
        p = p->next; // proximo no, virando P o primeiro nó
        free(tmp1);  // remove
        return;
    }

    tmp = p;
    int i = 1;
    while (i < posicao - 1 && tmp != NULL)
    {
        i++;
        tmp = tmp->next;
    }
    if (tmp == NULL || tmp->next == NULL)
    {
        printf("\nPosição Inválida!");
        return;
    }
    tmp1 = tmp->next;       // -> nó a ser removido
    tmp->next = tmp1->next; // nó anterior aponta para o próximo do removido
    free(tmp1);
}
void imprimir()
{
    tmp = p;
    while (tmp != NULL)
    {
        printf("\n %d", tmp->data);
        tmp = tmp->next;
    }
}
int obterPosicao(int posicao)
{
    int i;
    tmp = p;
    while (tmp != NULL && i < posicao)
    {
        tmp = tmp->next;
        i++;
    }
    if (tmp == NULL)
    {
        printf("\nPosição Inválida!\n");
        return -1;
    }
    return tmp->data; //retorna o valor da posição desejada
}

int main()
{
    int opcao = -1;
    while (opcao != 0)
    {
        printf("\n************************* MENU ************************");
        printf("\n(1).Inserir na posição");
        printf("\n(2).Remover da posição");
        printf("\n(3).Ver lista");
        printf("\n(4).Obter valor da posição");
        printf("\n(0).Sair");
        printf("\nEscolha a opção : \n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
        {
            int valor, posicao;
            printf("\nDigite o valor: ");
            scanf("%d", &valor);
            printf("\nDigite a posição: ");
            scanf("%d", &posicao);
            inserirPosicao(valor, posicao);
            break;
        }
        case 2:
        {
            int posicao;
            printf("\nigite a posição que deseja remover: ");
            scanf("%d", &posicao);
            removerPosicao(posicao);
            break;
        }
        case 3:
        {
            printf("\nLista abaixo: ");
            imprimir();
            break;
        }
        case 4:
        {
            int posicao;
            printf("\nDigite a posição que deseja obter: ");
            scanf("%d", &posicao);
            int valor = obterPosicao(posicao);
            if (valor != -1)
            {
                printf("Valor na posição %d: %d\n", posicao, valor);
            }
            break;
        }
        case 0:
        {
            printf("Lista finalizada!");
            break;
        }
        default:
            printf("Opção inválida! Tente outro número. \n");
            break;
        }
    }
    return 1;
}