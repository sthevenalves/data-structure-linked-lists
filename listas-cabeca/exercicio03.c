#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
    int dia;
    int mes;
} Data;

typedef struct Contato
{
    char nome[45];
    char telefone[12];
    struct Data dataAniversario;
    struct Contato *prox;
} Contato;

typedef struct Agenda
{
    int qnt_contatos;
    struct Contato *contatos;
} Agenda;

Agenda *criarAgenda();
Contato *alocarContato(char *nome, char *telefone, int dia, int mes);
void addContato(Agenda **p, char *nome, char *telefone, int dia, int mes);
void exibirContatos(Contato *aux);
void buscarContato(Agenda *p, char *telefone);
void removerContato(Agenda **p, char *telofone);
void removerTodos(Agenda **p);

int main()
{
    Agenda *agenda = criarAgenda();
    char nome[45], telefone[12]; // Alocando espaço para armazenar o nome e telefone
    int dia, mes;

    int opc;
    do
    {
        printf("\n------Menu------");
        printf("\n1-Adicionar novo contato");
        printf("\n2-Exibir contatos");
        printf("\n3-Pesquisar contato");
        printf("\n4-Remover contato");
        printf("\n5-Remover Todos os registros");
        printf("\n6-Sair");
        printf("\nEscolha: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
        {
            printf("telefone: ");
            scanf("%s", telefone);
            printf("Nome: ");
            scanf("%s", nome);
            printf("dia(aniversario): ");
            scanf("%d", &dia);
            printf("mes(aniversario): ");
            scanf("%d", &mes);
            addContato(&agenda, nome, telefone, dia, mes);
        }
        break;

        case 2:
        {
            exibirContatos(agenda->contatos);
        }
        break;
        case 3:
        {
            printf("Telefone: ");
            scanf("%s", telefone);
            buscarContato(agenda, telefone);
        }
        break;
        case 4:
        {
            printf("\n----Lista de contatos----");
            exibirContatos(agenda->contatos);
            printf("\ntelefone: ");
            scanf("%s", telefone);
            removerContato(&agenda, telefone);
        }
        break;
        case 5:
        {
            removerTodos(&agenda);
        }
        break;
        case 6:
        {
            printf("\nsaindo...");
            removerTodos(&agenda);
        }
        break;

        default:
            printf("\nComando invalido, selecione novamente");
            break;
        }

    } while (opc != 6);

    return 0;
}

Agenda *criarAgenda()
{
    Agenda *novo = (Agenda *)malloc(sizeof(Agenda));
    if (novo)
    {
        novo->qnt_contatos = 0;
        novo->contatos = NULL;
        return novo;
    }
    return NULL;
}

Contato *alocarContato(char *nome, char *telefone, int dia, int mes)
{
    Contato *novo = (Contato *)malloc(sizeof(Contato));
    if (novo)
    {
        strcpy(novo->nome, nome);
        strcpy(novo->telefone, telefone);
        novo->dataAniversario.dia = dia;
        novo->dataAniversario.mes = mes;
        return novo;
    }
    return NULL;
}

void addContato(Agenda **p, char *nome, char *telefone, int dia, int mes)
{
    Contato *novo = NULL;
    novo = alocarContato(nome, telefone, dia, mes);
    if (novo)
    {
        novo->prox = (*p)->contatos;
        (*p)->contatos = novo;
        (*p)->qnt_contatos++;
    }
}

void exibirContatos(Contato *aux)
{
    if (aux == NULL)
    {
        printf("\nAgenda Vazia");
    }
    else
    {
        while (aux)
        {
            printf("\n%s | %s | %d/%d", aux->nome, aux->telefone, aux->dataAniversario.dia, aux->dataAniversario.mes);
            aux = aux->prox;
        }
    }
}

void buscarContato(Agenda *p, char *telefone)
{
    Contato *aux = p->contatos;
    int encontrado = 0;
    if (aux == NULL)
    {
        printf("\nAgenda Vazia");
    }
    else
    {
        while (aux)
        {
            if (strcmp(aux->telefone, telefone) == 0)
            {
                printf("\n%s | %s | %d/%d", aux->nome, aux->telefone, aux->dataAniversario.dia, aux->dataAniversario.mes);
                encontrado = 1;
                break;
            }
            aux = aux->prox;
        }
    }
    if (!encontrado)
    {
        printf("\nContato nao existe!");
    }
}

void removerContato(Agenda **p, char *telofone)
{
    Contato *aux = (*p)->contatos, *cAnterio = NULL;
    if (aux == NULL)
    {
        printf("\nAgenda Vazia!");
    }
    else
    {
        while (aux)
        {
            if (strcmp(aux->telefone, telofone) == 0)
            {
                if (cAnterio == NULL)
                {
                    (*p)->contatos = aux->prox;
                }
                else
                {
                    cAnterio->prox = aux->prox;
                }
                free(aux);
                printf("\nContato removido com sucesso!\n");
                (*p)->qnt_contatos--;
                return;
            }
            cAnterio = aux;
            aux = aux->prox;
        }
        printf("\nContato nao encontrado!\n");
    }
}

void removerTodos(Agenda **p)
{
    Contato *aux = (*p)->contatos, *prox = NULL;
    if (aux == NULL)
    {
        printf("\nAgenda vazia");
        return;
    }
    else
    {
        while (aux)
        {
            prox = aux->prox;
            free(aux);
            aux = prox;
        }
        (*p)->contatos = NULL;
        (*p)->qnt_contatos = 0;
        printf("\nTodos os contatos foram removidos com sucesso!\n");
    }
}