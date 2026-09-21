#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//! VER ARQ NO MOODLE, COPIAR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef struct pessoa
{
    char nome[50];
    int  idade;
} PESSOA;

typedef struct nodo //ponto de intersecção
{
    struct nodo *pProx; //ponteiro pro proximo nodo (é oq liga um no outro)
    struct nodo *pPrev; //          '' nodo anterior ''
    PESSOA      *pPessoa; 
} NODO;

NODO *pInicio = NULL;
NODO *pFim    = NULL;
NODO *pAtual  = NULL;

//quando declara as funções antes (pra uma "saber" da existência da outra) é um protótipo de função
NODO *CriaPessoa(void);
NODO *CriaNodo(void);
void CadastroPessoa(PESSOA *pPessoa);
void PrintPessoa(void);
void MainMenu(void);
void SalvaLista(void);
void LeLista(void);


NODO *CriaPessoa(void) //(void) explicita que ela não recebe parametros, se fosse () os parametros não estão especificados
{
    PESSOA *pPessoa;
    pPessoa = (PESSOA *)malloc(sizeof(PESSOA));
    
    NODO *pNodo;
    pNodo = CriaNodo();
    pNodo->pPessoa = pPessoa;

    return(pNodo); //endereço da memoria onde a pessoa foi criada
}

NODO *CriaNodo(void)
{
    NODO *pNodo;
    pNodo = (NODO *)malloc(sizeof(NODO));

    return(pNodo);
}

void CadastroPessoa(PESSOA *pPessoa)
{
    printf("Digite o nome: ");
    scanf(" %[^\n]", pPessoa->nome);
    printf("Digite a idade: ");
    scanf("%i",&pPessoa->idade);
}

void PrintPessoa(void)
{ 
    //ta printando so o ultimo
    printf("\n--- Pessoas Cadastradas ---\n");
    pAtual = pInicio; 
    if (pAtual == NULL)
    {
        printf("Nenhuma pessoa cadastrada.");
        return;
    }
    while(pAtual != NULL)
    {
        printf("Nome: %s\n",pAtual->pPessoa->nome);
        printf("Idade: %i\n",pAtual->pPessoa->idade);
        printf("-------------\n");
        pAtual = pAtual->pProx;
    }
}

void InsereNaLista(NODO *pNodo)
{
    if(pInicio == NULL)
    {
        pInicio        = pNodo;
        pFim           = pNodo;
        pAtual         = pNodo;
        pInicio->pPrev = NULL;
    }
    else
    {
        pFim->pProx  = pNodo;
        pNodo->pPrev = pFim;
        pFim         = pNodo;
        pFim->pProx  = NULL;
    }
}

void MainMenu(void)
{
    int op;
    NODO *pNodo = NULL;

    while (op != 5)
    {
        printf("\n==== MENU ====\n");
        printf("1- Cadastrar pessoa\n2- Imprimir pessoa\n3- Salvar no disco\n4- Ler lista\n5- Sair\nEscolha uma opção: ");
        scanf("%i",&op);

        switch (op)
        {
            case 1:
                pNodo = CriaPessoa();
                CadastroPessoa(pNodo->pPessoa);
                InsereNaLista(pNodo);
            break;
            
            case 2: 
                PrintPessoa();
            break;
            
            case 3:
                SalvaLista();
            break;

            case 4:
                LeLista();
            break;

            case 5:
                printf("Saindo.\n");
            break;

            default:
                printf("Opção inválida.\n");
            break;
        }
    }
}

void SalvaLista(void)
{
    FILE *pArquivo;
    pArquivo = fopen("lista.txt", "w+");
    pAtual = pInicio;
    while(pAtual != NULL)
    {
        fwrite(pAtual->pPessoa, sizeof(PESSOA), 1, pArquivo);
        pAtual = pAtual->pProx;
    }
    fclose(pArquivo);
}

void LeLista(void)
{
    FILE *pArquivo;
    NODO *pNodo = NULL;
    PESSOA *pPessoa = NULL;

    pArquivo = fopen("lista.txt", "r+");
    while(1)
    {
        pPessoa = (PESSOA *)malloc(sizeof(PESSOA));

        if(fread(pPessoa, sizeof(PESSOA), 1, pArquivo) != 1)
        {
            free(pPessoa);
            break;
        }
        pNodo = CriaNodo();
        pNodo->pPessoa = pPessoa;
        InsereNaLista(pNodo);
    }
    fclose(pArquivo);
}

int main()
{
    MainMenu();
    return 0;
}
