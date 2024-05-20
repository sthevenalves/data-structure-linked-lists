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
No *valorMax(No **p);
No *valorMin(No **p);

int main()
{
    No *lista = NULL;
    inserirFim(&lista, 58);
    inserirFim(&lista, 23);
    inserirFim(&lista, 34);
    inserirFim(&lista, 12);
    inserirFim(&lista, 105);
    imprimirLista(lista);
    printf("\n---------------");
    No *maxLista = valorMax(&lista);
    No *minLista = valorMin(&lista);

    printf("\nMaior: %d", maxLista->chave);
    printf("\nMenor: %d", minLista->chave);

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

No *valorMax(No **p)
{
    No *aux = *p, *max = NULL;
    while (aux)
    {
        if (max == NULL || aux->chave > max->chave)
        {
            max = aux;
        }
        aux = aux->prox;
    }
    return max;
}

No *valorMin(No **p)
{
    No* aux=*p, *min = NULL;
    while(aux)
    {
        if(min == NULL || aux->chave < min->chave)
        {
            min = aux;
        }
        aux = aux->prox;
    }
    return min;
}