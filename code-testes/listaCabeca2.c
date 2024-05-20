#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *prox;
} TNo;

typedef struct cabeca
{
    int qtde;
    TNo *prox, *ult;
} TCabeca;

TNo *alocaNO(int k);
TCabeca *criarLista();
void insereInicio(TCabeca *p, int k);
void imprimirLista(TNo *paux);
void removerInicio(TCabeca *p);

int main()
{
    TCabeca *lista = criarLista();
    insereInicio(lista, 55);
    insereInicio(lista, 71);
    insereInicio(lista, 62);
    insereInicio(lista, 37);
    imprimirLista(lista->prox);

    return 0;
}

TCabeca *criarLista()
{
    TCabeca *novo = NULL;
    novo = (TCabeca *)malloc(sizeof(TCabeca));
    if (novo)
    {
        novo->qtde = 0;
        novo->prox = NULL;
        novo->ult = NULL;
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

void insereInicio(TCabeca *p, int k)
{
    TNo *novo = NULL;
    novo = alocaNO(k);
    if (novo)
    {
        novo->prox = p->prox;
        if (p->prox == NULL)
            p->ult = novo;
        p->prox = novo;
        p->qtde++;
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

void removerInicio(TCabeca *p)
{
    TNo *aux = p->prox;
    if (p->prox)
    {
        p->prox = p->prox->prox;
        free(aux);
        aux = NULL;
        p->qtde--;
        if(p->prox == NULL)
        {
            p->ult = NULL;
        }
    }
}