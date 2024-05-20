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
void removerInicio(No **p);
void removerFim(No **p);
void removerElemento(No **p, int n);
void removerTodos(No **p);

int main()
{

    No *lista = NULL;
    inserirFim(&lista, 55);
    inserirFim(&lista, 23);
    inserirFim(&lista, 65);
    inserirFim(&lista, 68);
    inserirFim(&lista, 65);
    inserirFim(&lista, 65);
    imprimir(lista);
    printf("\n---------------");
    removerElemento(&lista, 68);
    imprimir(lista);

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

void removerInicio(No **p)
{
    No *aux = *p;
    if (*p)
    {
        *p = (*p)->prox; // aponta para o proximo nó da lista
        free(aux);       // remove o primeiro nó da lista
        aux = NULL;
    }
    else
    {
        printf("\nLista Vazia");
    }
}

void removerTodos(No **p)
{
    if (*p == NULL)
    {
        printf("\nLista Vazia");
    }
    else
    {
        while (*p)
        {
            removerInicio(p);
        }
    }
}

void removerFim(No **p)
{
    No *aux = *p, *ant = NULL;
    if (*p == NULL)
    {
        printf("\nLista Vazia");
    }
    else
    {
        if ((*p)->prox == NULL) // verifica se a lista tem apenas um nó
        {
            free(*p);
            *p = NULL;
        }
        else
        {
            while (aux->prox) // percorre ate o ultimo nó
            {
                ant = aux; // anterior recebe o penultimo nó
                aux = aux->prox;
            }
            free(aux);        // libera o ultimo nó
            ant->prox = NULL; /*anterior ao prioximo, que seria o ultimo no, recebe null, indicando que anterior agora é o último nó*/
        }
    }
}

void removerElemento(No **p, int n)
{
    No *aux = *p, *ant = NULL;
    if (*p == NULL)
    {
        printf("\nLista vazia");
    }
    else

        while (aux)
        {
            if (aux->chave == n)
            {
                if (ant == NULL) // Se o nó a ser removido é o primeiro da lista
                {
                    *p = aux->prox;
                }
                else
                {
                    ant->prox = aux->prox; //pega nó anterior e conecta ao proximo, pulando o nó a ser romovido, garantindo que a lista continue conectada
                }
                free(aux);
                printf("\nElemento removido com sucesso");
                return; // Termina a função após remover o elemento
            }
            ant = aux; //ant recebe o nó lido atual
            aux = aux->prox;
        }
    printf("\nElemento nao encontrado na lista");
}