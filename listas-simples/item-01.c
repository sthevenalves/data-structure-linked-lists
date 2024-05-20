#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *prox;
} TNo;

TNo *alocaNo(int k);
void inserirInicio(TNo **p, int k);
void imprimirLista(TNo *aux);

int main()
{
    TNo *lista = NULL;
    inserirInicio(&lista, 55);
inserirInicio(&lista, 92);
    inserirInicio(&lista, 31);
    imprimirLista(lista);

    return 0;
}

TNo *alocaNo(int k)
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

void inserirInicio(TNo **p, int k)
{
    TNo *novo = NULL;
    novo = alocaNo(k);
    if (novo)
    {
        /*Isso significa que o próximo nó após o novo nó será o nó que atualmente é o primeiro na lista.*/
        novo->prox = *p;
        /*Agora, o novo nó se tornou o primeiro nó da lista, e os nós anteriores foram "empurrados" para frente na lista.*/
        *p = novo;
    }
}

void imprimirLista(TNo *aux)
{
    if (aux == NULL)
    {
        printf("\nLista vazia!");
    }
    else
    {
        while(aux)
        {
            /*imprime o valor da chave do nó atual*/
            printf("\n%d", aux->chave);
            /* atualiza o ponteiro aux para apontar para o próximo nó na lista*/
            aux = aux->prox;
        }
    }
}