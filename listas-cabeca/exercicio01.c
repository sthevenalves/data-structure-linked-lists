#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario
{
    char cpf[12];
    char nomeCompleto[25];
    char telefone[15];
    char email[25];
    double salario;
} Funcionario;

typedef struct departamento
{
    char setor[50];
    int qtd_funcionarios;
    Funcionario *funcionarios;
} Departamento;

Departamento *criarDepartamento(char *setor, int nFuncionario);
void imprimirDepartamento(Departamento *aux);

int main()
{
    Departamento *rh = criarDepartamento("Recursos Humanos", 10);
    Departamento *ti = criarDepartamento("TI", 6);
    imprimirDepartamento(rh);
    imprimirDepartamento(ti);

    free(rh);
    free(ti);

    return 0;
}

Departamento *criarDepartamento(char *setor, int nFuncionario)
{
    Departamento *novo = (Departamento *)malloc(sizeof(Departamento));
    if(novo)
    {
        strcpy(novo->setor, setor);
        novo->qtd_funcionarios = nFuncionario;
        novo->funcionarios = NULL;
        return novo;
    }
    return NULL;
}

void imprimirDepartamento(Departamento *aux)
{
    if(aux == NULL)
    {
        printf("\nDepartamento vazio");
    }
    else
    {
            printf("\nSetor: %s\n", aux->setor);
            printf("Qauntidade Funcionarios: %d\n", aux->qtd_funcionarios);
    }
}