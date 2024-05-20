#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *prox;
} No;

No *alocaNo(int k);
void insereLista(No **p, int k);
void imprimeLista(No *p);
void removeLista(No **p);

int main()
{

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

void insereLista(No **p, int k)
{
    No *novo = NULL;
    novo = alocaNo(k);
    if (novo)
    {
        if (*p == NULL)
        {
            *p = novo; //Atribui o endereço do novo nó ao ponteiro que representa o início da lista 
            novo->prox = *p; //Como a lista é circular, o ponteiro prox do novo nó deve apontar de volta para o primeiro nó.
        }
        else
        {
            novo->prox = (*p)->prox; // O ponteiro prox do novo nó deve apontar para o nó que atualmente segue o ponteiro prox do primeiro nó (ou seja, o segundo nó da lista).
            (*p)->prox = novo; //O ponteiro prox do primeiro nó (que atualmente aponta para o segundo nó) deve apontar para o novo nó, inserindo-o na lista.
            (*p) = novo; //O ponteiro que representa o último nó da lista (*p) é atualizado para apontar para o novo nó, garantindo que a circularidade seja mantida.
        }
    }
}

void imprimeLista(No *p)
{
    No *aux = NULL;
    if (p == NULL)
    {
        printf("\nLista Vazia!");
        return;
    }
    else
    {
        aux = p->prox; // Inicializa o ponteiro aux com o endereço do nó seguinte ao nó
        /*Como a lista é circular, o próximo nó após o último nó (cujo endereço é p) é o primeiro nó da lista. Portanto, paux começa apontando para o primeiro nó da lista.*/
        do
        {
            printf("\n%d", aux->chave);
            aux = aux->prox;
        } while (aux != p->prox); //usada para garantir que a iteração pela lista seja interrompida após um ciclo completo.
    }
}

void removeLista(No **p)
{
    No *aux = (*p)->prox;
    if(aux == NULL)
    {
        printf("\nLista Vazia"); return;
    }
    if(aux == *(p)) //Verifica se há apenas um nó na lista. 
    /* Se paux for igual a *p, isso significa que há apenas um nó na lista (a lista tem apenas um elemento, formando um ciclo).*/
    {
        free(aux);
        (*p) = NULL;
    }
    else
    {
        /*Atualiza o ponteiro prox do primeiro nó da lista (*p) para apontar para o nó seguinte ao nó que está sendo removido (paux).*/
        (*p)->prox = aux->prox;
        free(aux);
    }
}