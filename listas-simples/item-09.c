#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *prox;
} No;

No *alocaNo(int k);
void inserirInicio(No **p, int k);
void imprimirLista(No *aux);
void removerElemento(No **p, int n);
No *copiarLista(No **p);

int main()
{
    No *lista=NULL;
    inserirInicio(&lista, 98);
    inserirInicio(&lista, 34);
    inserirInicio(&lista, 23);
    inserirInicio(&lista, 64);
    imprimirLista(lista);
    printf("\n-------------");
    No *listaCopiada = copiarLista(&lista);
    removerElemento(&listaCopiada, 23);
    imprimirLista(listaCopiada);
    
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

void inserirInicio(No **p, int k)
{
    No *novo = alocaNo(k);
    if (novo)
    {
        novo->prox = *p;
        *p = novo;
    }
    else
    {
        printf("\nFalha ao inserir elemento!");
    }
}

void imprimirLista(No *aux)
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
    No *aux = *p, *ant = NULL;
    if (*p == NULL)
    {
        printf("\nLista vazia!");
    }
    else
    {
        while (aux)
        {
            if (aux->chave == n)
            {
                if (ant == NULL)
                {
                    *p = aux->prox;
                }
                else
                {
                    ant->prox = aux->prox;
                }
                free(aux);
                printf("\nElemento Removido!");
                return;
            }
            ant = aux;
            aux = aux->prox;
        }
    }
    printf("\nElemento nao encontrado");
}

No *copiarLista(No **p)
{
    No *novaLista = NULL, *ultimoNo = NULL, *aux = *p;

    if (*p == NULL)
    {
        printf("\nLista Vazia");
        return novaLista; // Retorna a lista vazia
    }

    while (aux)
    {
        // Aloca um novo nó para a nova lista
        No *novo = alocaNo(aux->chave);

        if (novo)
        {
            if (novaLista == NULL)
            {
                // Se a nova lista estiver vazia, o novo nó será o primeiro
                novaLista = novo;
            }
            else
            {
                // Caso contrário, adiciona o novo nó ao final da nova lista
                ultimoNo->prox = novo;
            }

            // Atualiza o ponteiro para o último nó da nova lista
            ultimoNo = novo;

            // Avança para o próximo nó da lista original
            aux = aux->prox;
        }
        else
        {
            printf("\nFalha ao alocar memória para copiar lista!");
            return novaLista; // Retorna a nova lista até o ponto de falha
        }
    }

    // Retorna a nova lista criada
    return novaLista;
}
