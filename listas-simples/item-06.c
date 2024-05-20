#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *prox;
} No;

No *alocaNo(int k);
void inserirFim(No **p, int k);
void imprimir(No *aux);
int tamanhoLista(No **p);

int main()
{
    No *lista=NULL;
    inserirFim(&lista, 55);
    inserirFim(&lista, 23);
    inserirFim(&lista, 65);
    inserirFim(&lista, 68);
    imprimir(lista);
    printf("\n---------------");
    printf("\nTamanho da lista: %d", tamanhoLista(&lista));

    return 0;
}

No *alocaNo(int k)
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
        novo = alocaNo(k);
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
        novo = alocaNo(k);
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

int tamanhoLista(No **p)
{
    int tam = 0;
    No *aux = *p;
    if(*p == NULL)
    {
        printf("\nLista Vazia, adicione elementos!");
    }
    else
    {
        while(aux)
        {
            tam++;
            aux = aux->prox;
        }
    }
    return tam++;
}