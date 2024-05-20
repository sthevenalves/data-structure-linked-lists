#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char ip[16];
    char domain[100];
    struct node *prox;
} Node;

Node *criarNode();
Node *alocaNo(char *ip, char *domain);
void inserirNode(Node **p, char *ip, char *domain);
char *encontrarDomain(Node *p, char *ip);
void imprime(Node *aux);
void separarDados();

int main()
{
    Node *lista = criarNode();
    inserirNode(&lista, "192.168.0.1", "www.facebook.com");
    inserirNode(&lista, "172.217.28.206", "www.google.com");
    imprime(lista->prox);
    separarDados();
    char *dominio = encontrarDomain(lista, "171.217.28.206");
    printf("\n%s", dominio);

    return 0;
}

void separarDados()
{
    printf("\n---------------");
}

Node *criarNode()
{
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo)
    {
        novo->ip[0] = '\0';
        novo->domain[0] = '\0';
        novo->prox = NULL;
        return novo;
    }
    return NULL;
}

Node *alocaNo(char *ip, char *domain)
{
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo)
    {
        strcpy(novo->ip, ip);
        strcpy(novo->domain, domain);
        novo->prox = NULL;
        return novo;
    }
    return NULL;
}

void inserirNode(Node **p, char *ip, char *domain)
{
    Node *aux = *p, *novo = NULL;
    {
        if (*p == NULL)
        {
            novo = alocaNo(ip, domain);
            if (novo)
                *p = novo;
        }
        else
        {
            novo = alocaNo(ip, domain);
            if (novo)
            {
                while(aux->prox)
                {
                    aux = aux->prox;
                }
                aux->prox = novo;
            }
        }
    }
}

char *encontrarDomain(Node *p, char *ip)
{
    Node *aux = p;
    if(aux == NULL)
    {
        printf("\nLista Vazia!");
    }
    else
    {
        while(aux)
        {
            if(strcmp(aux->ip, ip) == 0)
            {
                return aux->domain;
            }
            aux = aux->prox;
        }
    }
    printf("\nEndereco IP nao encontrado");
    return NULL;
}

void imprime(Node *aux)
{
    if(aux == NULL)
    {
        printf("\nLista Vazia");
    }
    else
    {
        while (aux)
        {
            printf("\n%s - %s", aux->ip, aux->domain);
            aux = aux->prox;
        }
        
    }
}