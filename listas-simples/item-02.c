#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *prox;
} No;

No *alocarNo(int k);
void inserirFim(No **p, int k);
void inserirInicio(No **p, int k);
void imprimirLista(No *aux);

int main()
{
    No *listaInicio=NULL, *listaFim=NULL;
    inserirFim(&listaFim, 52);
    inserirFim(&listaFim, 41);
    inserirFim(&listaFim, 96);
    inserirFim(&listaFim, 72);
    imprimirLista(listaFim);
    printf("\n-----------");
    inserirInicio(&listaInicio, 52);
    inserirInicio(&listaInicio, 41);
    inserirInicio(&listaInicio, 96);
    inserirInicio(&listaInicio, 72);
    imprimirLista(listaInicio);
    

    return 0;
}

No *alocarNo(int k)
{
    No *novo = NULL;
    novo = (No *)malloc(sizeof(No));
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
    No *novo=NULL;
    novo = alocarNo(k);
    if(novo)
    {
        novo->prox = *p;
        *p = novo;
    }

}

void inserirFim(No **p, int k)
{
    No *novo = NULL, *aux = *p; //aux será usado para percorrer a lista, inicializado com o endereço do primeiro nó da lista encadeada
    if (*p == NULL) //Verifica se a lista encadeada está vazia
    {
        /*Se estiver vazia, significa que não há nenhum nó na lista, então precisamos adicionar o novo nó como o primeiro nó.*/
        novo = alocarNo(k);
        if (novo)
        {
            /*Se o novo nó for alocado com sucesso, atribui o endereço do novo nó ao ponteiro para a lista encadeada *p tornando-o o primeiro nó da lista.*/
            *p = novo;
        }
    }
    else //Se a lista não estiver vazia, precisamos percorrer a lista até o último nó.
    {
        while(aux->prox) // Este laço percorre a lista até o último nó.
        {
            aux = aux->prox; //atualizando o ponteiro aux para o próximo nó em cada iteração.
        }
        novo = alocarNo(k); // Aloca memória para um novo nó com a chave k.
        if(novo)//Se o novo nó for alocado com sucesso
        {
            /* Atribui o endereço do novo nó ao ponteiro prox do último nó da lista, fazendo com que o novo nó seja o último nó da lista.*/
            aux->prox = novo;
        }
    }
}
void imprimirLista(No *aux)
{
    if(aux == NULL)
    {
        printf("\nLista Vazia!");
    }
    else
    {
        while(aux)
        {
            printf("\n%d", aux->chave);
            aux = aux->prox;
        }
    }
}