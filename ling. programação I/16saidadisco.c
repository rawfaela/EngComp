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
    
    strcpy(pPessoa->nome, "rafa");
    pPessoa->idade = 19;

    //abre arquivo pra escrita
    FILE *pCadastro;
    pCadastro = fopen("cadastro.txt", "w"); //file open, abre ou cria arquivo no modo de escrita (w) (se ja tem algo escrito, é apagado, pra adicionar infos tem q usar "a" (append))

    fprintf(pCadastro,"Nome: %s\nIdade: %i",pPessoa->nome,pPessoa->idade); //printa no arquivo (file print), no disco

    fclose(pCadastro);
    free(pPessoa);
    //se colocar "cat cadastro.txt" no terminal, printa o conteudo do arquivo (concatenate -> read, combine, and display file contents directly in your terminal window)
}
