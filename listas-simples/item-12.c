#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *prox;
} No;

No *alocaNo(int k);
void inserirInicio(No **p, int k);
void imprimir(No *aux);
void removerElemento(No **p, int n);
No *juntarLista(No **p1, No **p2);
void dividirLista(No *lista, No **lista1, No **lista2);

int main()
{
    No *lista1 = NULL, *lista2 = NULL, *p1 = NULL, *p2 = NULL;
    printf("\nLista 1");
    inserirInicio(&lista1, 1);
    inserirInicio(&lista1, 2);
    inserirInicio(&lista1, 3);
    inserirInicio(&lista1, 4);
    inserirInicio(&lista1, 5);
    imprimir(lista1);
    printf("\n--------------");
    printf("\nLista 2");
    inserirInicio(&lista2, 5);
    inserirInicio(&lista2, 6);
    inserirInicio(&lista2, 7);
    inserirInicio(&lista2, 8);
    imprimir(lista2);
    printf("\n--------------");
    printf("\nLista Unificada");
    No *listaUnica = juntarLista(&lista1, &lista2);
    imprimir(listaUnica);
    dividirLista(listaUnica, &p1, &p2);
    printf("\n--------------");
    printf("\nDivisao 1");
    imprimir(p1);
    printf("\n--------------");
    printf("\nDivisao 2");
    imprimir(p2);

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
    No *aux = *p, *anterior = NULL;
    if (aux == NULL)
    {
        printf("\nLista Vazia!");
    }
    else
    {
        while (aux)
        {
            if (aux->chave == n)
            {
                if (anterior == NULL)
                {
                    *p = aux->prox;
                }
                else
                {
                    anterior->prox = aux->prox;
                }
                free(aux);
                printf("\nElemento Removido!");
            }
            anterior = aux;
            aux = aux->prox;
        }
    }
    printf("\nElemento nao encontrado");
}

No *juntarLista(No **p1, No **p2)
{
    No *listaUnificada = NULL, *ultimoNo = NULL;
    No *aux1 = *p1, *aux2 = *p2;
    while (aux1)
    {
        No *novo = alocaNo(aux1->chave);
        if (novo == NULL)
        {
            return NULL;
        }
        if (listaUnificada == NULL)
        {
            listaUnificada = novo;
            ultimoNo = novo;
        }
        else
        {
            ultimoNo->prox = novo;
            ultimoNo = novo;
        }
        aux1 = aux1->prox;
    }
    while (aux2)
    {
        No *novo = alocaNo(aux2->chave);
        if (novo == NULL)
            return NULL;

        if (listaUnificada == NULL) 
        {
            listaUnificada = novo;
            ultimoNo = novo;
        }
        else
        {
            ultimoNo->prox = novo;
            ultimoNo = novo;
        }
        aux2 = aux2->prox;
    }
    return listaUnificada;
}

void dividirLista(No *lista, No **lista1, No **lista2)
{
    int tam = 0;
    No *aux = lista;

    if (lista == NULL && lista->prox == NULL) // Se a lista estiver vazia ou tiver apenas um nó, não há necessidade de dividir
    {
        *lista1 = lista;
        *lista2 = NULL;
        return;
    }

    while(aux)
    {
        tam++;
        aux = aux->prox;
    }

    int metade = tam/2, i;
    aux = lista;

    for(i=0; i<metade-1; i++) // Percorre até a metade da lista
    {
        aux = aux->prox; //aux estará apontando para o último nó da primeira metade.
    }
    /*
    Depois de encontrar o último nó da primeira metade, a função ajusta os ponteiros para separar as duas metades. O ponteiro lista2 aponta para o nó seguinte ao aux(aux->prox), que é o primeiro nó da segunda metade. Em seguida, o ponteiro prox do atual é definido como NULL, indicando o fim da primeira metade.*/

    //responsável por atribuir o endereço do primeiro nó da lista original à variável lista1
    //Essa operação é importante porque estamos dividindo a lista em duas partes, e lista1 precisa apontar para o início da primeira metade da lista.
    *lista1 = lista;
    *lista2 = aux->prox;
    aux->prox = NULL;

    /* *lista1 = lista; não faz primeiraMetade apontar para toda a lista original, mas sim para o início dela, que, no contexto da função dividirLista, representa a primeira metade da lista.*/
}