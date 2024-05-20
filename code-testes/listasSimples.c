/*
    inserir no inicio, inserir no final, imprimir, remover no inicio, remover no final, remove todos
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    // outros campos
    struct no *prox;
} TNo;

TNo *alocaNo(int k);
void insereLista(TNo **p, int k);
void imprimir(TNo *paux);
void removeLista(TNo **p);
void removeTodos(TNo **p);
void insereFim(TNo **p, int k);
void removeFim(TNo **p);

int main()
{
    TNo *prim = NULL, *prim2 = NULL;
    imprimir(prim);
    insereLista(&prim, 77);
    insereLista(&prim, 36);
    insereLista(&prim, 19);
    insereLista(&prim, 2);
    insereLista(&prim, 89);
    imprimir(prim);
    removeLista(&prim);
    printf("\n-----------------------");
    imprimir(prim);
    removeTodos(&prim);
    imprimir(prim);
    printf("\n-----------------------");
    insereFim(&prim2, 11);
    insereFim(&prim2, 23);
    insereFim(&prim2, 45);
    insereFim(&prim2, 25);
    insereFim(&prim2, 21);
    imprimir(prim2);
    removeFim(&prim2);
    printf("\n-----------------------");
    imprimir(prim2);
    while (prim2)
        removeFim(&prim2);
    printf("\n-----------------------");
    imprimir(prim2);

    // insereLista(&prim,200);
    // imprimir(prim);
}

void removeTodos(TNo **p)
{
    if (*p == NULL)
    {
        printf("\nLista vazia!");
    }
    else
    {
        while (*p)
        {
            removeLista(p);
        }
    }
}

// remove no inicio
void removeLista(TNo **p)
{
    TNo *paux = *p;
    if (*p)
    {
        *p = (*p)->prox;
        free(paux);
        paux = NULL;
    }
    else
        printf("\nLista Vazia!");
}

void imprimir(TNo *paux)
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
// insere no início
void insereLista(TNo **p, int k)
{
    TNo *novo = NULL;
    novo = alocaNo(k);
    if (novo)
    {
        // ligações dos ponteiros da lista
        novo->prox = *p;
        *p = novo;
    }
}

TNo *alocaNo(int k)
{
    TNo *novo = NULL;
    novo = (TNo *)malloc(sizeof(TNo));
    if (novo) // novo!=NULL
    {
        novo->chave = k;
        novo->prox = NULL;
    }
    return novo;
}

// inserir no final da lista
void insereFim(TNo **p, int k)
{
    TNo *aux = *p, *novo = NULL;
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

//remover no final da lista
void removeFim(TNo **p)
{
    TNo *aux = *p, *ant = NULL;
    if (*p == NULL)
    {
        printf("\nLista vazia");
    }
    else
    {
        if ((*p)->prox == NULL)
        {
            free(*p);
            *p = NULL;
        }
        else
        {
            while (aux->prox)
            {
                ant = aux;
                aux = aux->prox;
            }
            free(aux);
            ant->prox = NULL;
        }
    }
}