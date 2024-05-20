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
void removerElemento(No **p, int n);
No *copiarElemento(No **p);
void reverterOrdem(No **p);

int main()
{
    No *lista = NULL;
    inserirFim(&lista, 1);
    inserirFim(&lista, 2);
    inserirFim(&lista, 3);
    inserirFim(&lista, 4);
    imprimir(lista);
    printf("\n-------------");
    removerElemento(&lista, 3);
    reverterOrdem(&lista);
    imprimir(lista);

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

void removerElemento(No **p, int n)
{
    No *aux = *p;

    if (aux == NULL)
    {
        printf("\nLista vazia");
        return;
    }

    // Verificando se o primeiro elemento é o que queremos remover
    if (aux->chave == n)
    {
        *p = aux->prox;
        free(aux);
        printf("\nElemento Removido!");
        return;
    }

    while (aux->prox != NULL && aux->prox->chave != n)
    {
        aux = aux->prox;
    }

    // Se o elemento não estiver na lista
    if (aux->prox == NULL)
    {
        printf("\nElemento nao encontrado na lista.");
        return;
    }

    No *temp = aux->prox;
    aux->prox = aux->prox->prox;
    free(temp);
    printf("\nElemento Removido!");
}

No *copiarElemento(No **p)
{
    No *novaLista = NULL, *ultimoNo = NULL, *aux = *p;
    if (aux == NULL)
    {
        printf("\nLista Vazia");
        return novaLista;
    }
    else
    {
        while (aux)
        {
            No *novo = alocaNo(aux->chave);
            if (novo)
            {
                if (novaLista == NULL)
                {
                    novaLista = novo;
                }
                else
                {
                    ultimoNo->prox = novo;
                }
                ultimoNo = novo;
                aux = aux->prox;
            }
            else
            {
                printf("\nErro ao alocar memoria!");
            }
        }
    }
    return novaLista;
}

void reverterOrdem(No **p)
{
    No *aux = *p, *anterior = NULL, *proximo = NULL;
    if (aux == NULL)
    {
        printf("\nLista Vazia");
    }
    else
    {
        while (aux)
        {
            proximo = aux->prox; // Salva o próximo nó
            aux->prox = anterior; // Inverte o ponteiro para o nó anterior
            anterior = aux; // Atualiza o nó anterior para o nó atual
            aux = proximo; // Move para o próximo nó na lista
        }
        *p = anterior; // Atualiza o ponteiro para o início da lista invertida
    }
}