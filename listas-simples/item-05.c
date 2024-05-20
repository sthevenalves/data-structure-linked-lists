#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *prox;
} No;

No *alocarNo(int k);
void inserirIncio(No **p, int k);
void imprimirLista(No *aux);
int somarElementos(No **p);

int main()
{
    No *lista = NULL;
    inserirIncio(&lista, 12);
    inserirIncio(&lista, 87);
    inserirIncio(&lista, 35);
    inserirIncio(&lista, 27);
    imprimirLista(lista);
    printf("\n---------");
    int somaLista = somarElementos(&lista);
    printf("\nSoma Lista: %d", somaLista);

    return 0;
}

No *alocarNo(int k)
{
    No *novo = NULL;
    novo = (No *)malloc(sizeof(No));
    if (novo)
    {
        novo->chave = k;
        novo->prox = NULL;
        return novo;
    }
    return NULL;
}

void inserirIncio(No **p, int k)
{
    No *novo = NULL;
    novo = alocarNo(k);
    if (novo)
    {
        novo->prox = *p;
        *p = novo;
    }
}

void imprimirLista(No *aux)
{
    if (aux == NULL)
    {
        printf("\nLista Vazia!");
    }
    else
    {
        while (aux)
        {
            printf("\n%d", aux->chave);
            aux = aux->prox;
        }
    }
}

int somarElementos(No **p)
{
    No *aux = *p;
    int soma = 0;
    while (aux)
    {
        soma += aux->chave;
        aux = aux->prox;
    }
    return soma;
}