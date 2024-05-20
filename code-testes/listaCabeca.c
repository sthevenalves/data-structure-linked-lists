#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *prox;
} TNo;

TNo *alocaNO(int k);
TNo *criarLista();
void insereInicio(TNo *p, int k);
void imprimirLista(TNo *paux);
void removerInicio(TNo *p);
void removerTodos(TNo **p);

int main()
{
    TNo *lista = criarLista();
    insereInicio(lista, 55);
    insereInicio(lista, 71);
    insereInicio(lista, 62);
    insereInicio(lista, 37);
    imprimirLista(lista->prox);
    removerInicio(lista);
    printf("\n--------------------");
    imprimirLista(lista->prox);

    return 0;
}

TNo *criarLista()
{
    TNo *novo = NULL;
    novo = (TNo *)malloc(sizeof(TNo));
    if (novo)
    {
        novo->chave = -1;
        novo->prox = NULL;
        return novo;
    }
    return NULL;
}

TNo *alocaNO(int k)
{
    TNo *novo = NULL;
    novo = (TNo *)malloc(sizeof(TNo));
    if (novo)
    {
        novo->chave = k;
        novo->prox = NULL;
        return novo;
    }
    return NULL;
}

void insereInicio(TNo *p, int k)
{
    TNo *novo = NULL;
    novo = alocaNO(k);
    if (novo)
    {
        novo->prox = p->prox;
        p->prox = novo;
    }
}

void imprimirLista(TNo *paux)
{
    if (paux == NULL)
        printf("\nLista vazia!");
    else
    {
        while (paux)
        {
            printf("\n%d", paux->chave);
            paux = paux->prox;
        }
    }
}

void removerInicio(TNo *p)
{
    TNo *aux = p->prox;
    if (p->prox)
    {
        p->prox = p->prox->prox;
        free(aux);
        aux = NULL;
    }
}

void removerTodos(TNo **p)
{
    if (*p == NULL)
        printf("\nLista vazia");
    else
    {
        while (*p)
        {
            removerInicio(p);
        }
    }
}