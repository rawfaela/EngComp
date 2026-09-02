#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa
{
    char nome[50];
    int idade;
} PESSOA;

int main()
{
    PESSOA *pPessoa;
    pPessoa = (PESSOA *)malloc(sizeof(PESSOA));
    strcpy(pPessoa->nome, "rafa"); //quando a estrutura é esyática usa ".", quando é dinamica usa "->", pode ser com ou sem espaço
    pPessoa -> idade = 19;

    printf("Nome: %s\nIdade: %i\n",pPessoa->nome,pPessoa->idade);

    free(pPessoa);
    pPessoa = NULL;
}
