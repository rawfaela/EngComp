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
    FILE *pCadastro;                   //se for fazer do outro jeito, tem q usar "wb+" (write binary +read)
    pCadastro = fopen("cadastro.txt", "w"); //file open, abre ou cria arquivo no modo de escrita (w) (se ja tem algo escrito, é apagado, pra adicionar infos tem q usar "a" (append))

    //um jeito de salvar no arq
    fprintf(pCadastro,"Nome: %s\nIdade: %i",pPessoa->nome,pPessoa->idade); //printa no arquivo (file print), no disco
    
    //outro jeito de salvar no arq, grava os bytes da estrutrura (em binário)
    /* fwrite(pPessoa, sizeof(PESSOA), 1, pCadastro); //escreve direto, no arquivo já aberto com fopen
    rewind(pCadastro);
    fflush(pCadastro); //obriga o sist operacional a salvar no disco (pq salva na cache) (aparentemente desnecessário)
    fread(pPessoa, sizeof(PESSOA), 1, pCadastro);
    printf("Nome: %s\n", pPessoa->nome);
    printf("Idade: %d\n", pPessoa->idade); */

    //se usa no final dos dois jeitos
    fclose(pCadastro);
    free(pPessoa);
    //se colocar "cat cadastro.txt" no terminal, printa o conteudo do arquivo (concatenate -> read, combine, and display file contents directly in your terminal window)
}
