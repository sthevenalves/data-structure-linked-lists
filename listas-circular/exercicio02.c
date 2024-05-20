#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int chave;
    struct node *prox;
} Node;

Node *aloca(int v);
void insere(Node **p, int v);
void remover(Node **p);
void imprime(Node *p);
void rotacionarEsq(Node **p);
void rotacionarDir(Node **p);

int main()
{
    Node *lista = NULL;
    insere(&lista, 1);
    insere(&lista, 2);
    insere(&lista, 3);
    imprime(lista);
    printf("\n");
    rotacionarEsq(&lista);
    imprime(lista);
    printf("\n");
    rotacionarDir(&lista);
    imprime(lista);
    return 0;
}

Node *aloca(int v)
{
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo)
    {
        novo->chave = v;
        novo->prox = NULL;
        return novo;
    }
    return NULL;
}

void insere(Node **p, int v)
{
    Node *novo = aloca(v);
    if (novo)
    {
        if (*p == NULL)
        {
            *p = novo;
            novo->prox = novo;
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
    if (*p == NULL)
    {
        printf("\nLista Vazia");
        return;
    }
    else
    {
        if (aux == *p)
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
        return;
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

void rotacionarEsq(Node **p)
{
    if (*p == NULL || (*p)->prox == *p)
    {
        return;
    }
    else
    {
        *p = (*p)->prox;
    }
}

void rotacionarDir(Node **p)
{
    if (*p == NULL || (*p)->prox == *p)
    {
        printf("\nLista Vazia");
        return;
    }
    else
    {
        Node *aux = (*p);

        while (aux->prox != *p)
        {
            aux = aux->prox;
        }
        (*p)->prox = aux;
        
        }
}