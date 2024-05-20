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
void removerFinal(No **p);
int compararLista(No *p1, No *p2);
void verificarBool(int igual);

int main()
{
    No *lista1 = NULL, *lista2 = NULL;
    inserirFim(&lista1, 1);
    inserirFim(&lista1, 2);
    inserirFim(&lista1, 3);
    inserirFim(&lista1, 4);
    imprimir(lista1);
    printf("\n-------------");
    inserirFim(&lista2, 1);
    inserirFim(&lista2, 2);
    inserirFim(&lista2, 3);
    inserirFim(&lista2, 4);
    imprimir(lista2);
    printf("\n-------------");
    int iguais = compararLista(lista1, lista2);
    verificarBool(iguais);
    removerFinal(&lista1);
    int iguais2 = compararLista(lista1, lista2);
    verificarBool(iguais2);

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
    No *aux = *p, *novo = NULL;
    if (aux == NULL)
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
        printf("\nLista vazia!");
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

void removerFinal(No **p)
{
    No *aux = *p, *anterior = NULL;
    if (aux == NULL)
    {
        printf("\nLista Vazia!");
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
                anterior = aux;
                aux = aux->prox;
            }
            free(aux);
            anterior->prox = NULL;
        }
    }
}

int compararLista(No *p1, No *p2)
{
    No *aux1 = p1, *aux2 = p2;

    while (aux1 && aux2)
    {
        if (aux1->chave != aux2->chave)
        {
            return 0;
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    // Se ambas as listas chegaram ao final ao mesmo tempo, elas são iguais
    // último nó geralmente tem o ponteiro prox apontando para NULL.
    if (aux1 == NULL && aux2 == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void verificarBool(int igual)
{
    if (igual == 1)
    {
        printf("\nTrue");
    }
    else
    {
        printf("\nFalse");
    }
}