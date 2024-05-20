#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *prox;
} No;

No *alocarNo(int k);
void inserirFim(No **p, int k);
void imprimir(No *aux);
int frequenciaElemento(No **p, int n);

int main()
{
    No *lista=NULL;
    inserirFim(&lista, 55);
    inserirFim(&lista, 23);
    inserirFim(&lista, 65);
    inserirFim(&lista, 68);
    inserirFim(&lista, 65);
    inserirFim(&lista, 65);
    imprimir(lista);
    printf("\n---------------");
    printf("\nfrequencia: %d", frequenciaElemento(&lista, 65));

    return 0;
}

No *alocarNo(int k)
{
    No *novo = (No *)malloc(sizeof(No));
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

void imprimir(No *aux)
{
    if (aux == NULL)
    {
        printf("\nLista Vazia, adicione elementos!");
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

int frequenciaElemento(No **p, int n)
{
    No *aux = *p;
    int freq = 0;
    if (aux == NULL)
    {
        printf("\nLista Vazia, adicione elementos");
    }
    else
    {
        while (aux)
        {
            if (aux->chave == n)
            {
                freq++;
            }
            aux = aux->prox;
        }
    }
    return freq;
}