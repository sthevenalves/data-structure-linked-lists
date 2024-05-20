#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int chave;
    struct node *prox;
} Node;

Node *aloca(int k);
void insere(Node **p, int k);
void imprime(Node *p);
void remover(Node **p);
Node *busca(Node *aux, int n);

int main()
{
    Node *lista = NULL;
    insere(&lista, 1);
    insere(&lista, 2);
    insere(&lista, 3);
    imprime(lista);
    // remover(&lista);
    // printf("\n");
    // imprime(lista);
    // if (busca(lista, 2))
    //     printf("\ntrue");
    // else
    //     printf("\nfalse");

        return 0;
}

Node *aloca(int k)
{
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo)
    {
        novo->chave = k;
        novo->prox = NULL;
        return novo;
    }
    return NULL;
}

void insere(Node **p, int k)
{
    Node *novo = aloca(k);
    if (novo)
    {
        if (*p == NULL)
        {
            *p = novo;
            novo->prox = *p;
        }
        else
        {
            novo->prox = (*p)->prox;
            (*p)->prox = novo;
            *p = novo;
        }
    }
}

void remover(Node **p)
{
    Node *aux = (*p)->prox;
    if (aux == NULL)
    {
        printf("\nLista Vazia");
    }
    else
    {
        if (aux == (*p))
        {
            free(aux);
            *p = NULL;
        }
        else
        {
            (*p)->prox = aux->prox;
            free(aux);
        }
    }
}

void imprime(Node *p)
{
    Node *aux = NULL;
    if (p == NULL)
    {
        printf("\nLista Vazia");
    }
    else
    {
        aux = p->prox;

        do
        {
            printf("\n%d", aux->chave);
            aux = aux->prox;

        } while (aux != p->prox);
    }
}

Node *busca(Node *aux, int n)
{
    if (aux == NULL)
    {
        printf("\nLista Vazia");
    }
    else
    {
        while (aux)
        {
            if (aux->chave == n)
            {
                return aux;
            }
            aux = aux->prox;
        }
    }
    return NULL;
}