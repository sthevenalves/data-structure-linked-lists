#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *prox;
} No;

No *alocarNo(int k);
void inserirFim(No **p, int k);
void imprimirLista(No *aux);
No *buscarElemento(No **p, int valor);

int main()
{
    No *lista = NULL;
    inserirFim(&lista, 78);
    inserirFim(&lista, 56);
    inserirFim(&lista, 43);
    inserirFim(&lista, 24);
    imprimirLista(lista);
    printf("\n-----------");
    No *elementoBuscado = buscarElemento(&lista, 24);
    if (elementoBuscado)
    {
        printf("\nEndereco: %d, valor: %d", &elementoBuscado, elementoBuscado->chave);
    }
    else
    {
        printf("\nValor nao encontrado");
    }

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

void inserirFim(No **p, int k)
{
    No *novo = NULL, *aux = *p;
    if (*p == NULL)
    {
        novo = alocarNo(k);
        if (novo)
        {
            *p = novo;
        }
    }
    else
    {
        while (aux->prox)
        {
            aux = aux->prox;
        }
        novo = alocarNo(k);
        if (novo)
        {
            aux->prox = novo;
        }
    }
}

void imprimirLista(No *aux)
{
    if (aux == NULL)
    {
        printf("\nLista vazia");
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

No *buscarElemento(No **p, int valor)
{
    No *aux = *p;

    while (aux)
    {
        if (aux->chave == valor)
        {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}