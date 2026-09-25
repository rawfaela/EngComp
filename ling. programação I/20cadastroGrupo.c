#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct disco
{
    char  titulo[50];
    char  artista[100];
    char  gravadora[50];
    int   anoPublicacao;
    float duracao;
} DISCO;

typedef struct nodo //ponto de intersecção
{
    struct nodo *pProx; //ponteiro pro proximo nodo (é oq liga um no outro)
    struct nodo *pPrev; //          '' nodo anterior ''
    DISCO       *pDisco; 
} NODO;

NODO *pInicio = NULL;
NODO *pFim    = NULL;
NODO *pAtual  = NULL;

//quando declara as funções antes (pra uma "saber" da existência da outra) é um protótipo de função
NODO *CriaDisco(void);
NODO *CriaNodo(void);
void CadastroDisco(DISCO *pDisco);
void PrintDisco(void);
void MainMenu(void);
void SalvaLista(void);
void LeLista(void);
void DestroiLista(void);

NODO *CriaDisco(void) //(void) explicita que ela não recebe parametros, se fosse () os parametros não estão especificados
{
    DISCO *pDisco;
    pDisco = (DISCO *)malloc(sizeof(DISCO));
    
    NODO *pNodo;
    pNodo = CriaNodo();
    pNodo->pDisco = pDisco;

    return(pNodo); //endereço da memoria onde a pessoa foi criada
}

NODO *CriaNodo(void)
{
    NODO *pNodo;
    pNodo = (NODO *)malloc(sizeof(NODO));

    return(pNodo);
}

void CadastroDisco(DISCO *pDisco)
{
    printf("Digite o título do disco: ");
    scanf(" %[^\n]", pDisco->titulo); //espaço em branco antes do % ignora todo espaço em branco antes de começar a string
    printf("Digite o artista do disco: ");
    scanf(" %[^\n]", pDisco->artista); //%[^\n]: leia e aceite qualquer caractere, exceto (^) a quebra de linha (\n)
    printf("Digite a gravadora do disco: ");
    scanf(" %[^\n]", pDisco->gravadora);
    printf("Digite o ano de publicação do disco: ");
    scanf("%i",&pDisco->anoPublicacao);
    printf("Digite a duração do disco (min): ");
    scanf("%f",&pDisco->duracao);
}

void PrintDisco(void)
{ 
    printf("\n--- Discos Cadastrados ---\n");
    pAtual = pInicio; 
    if (pAtual == NULL)
    {
        printf("Nenhum disco cadastrado.");
        return;
    }
    while(pAtual != NULL)
    {
        printf("Título: %s\n",pAtual->pDisco->titulo);
        printf("Artista: %s\n",pAtual->pDisco->artista);
        printf("Gravadora: %s\n",pAtual->pDisco->gravadora);
        printf("Ano de publicação: %i\n",pAtual->pDisco->anoPublicacao);
        printf("Duração (min): %.2f\n",pAtual->pDisco->duracao);
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

void DestroiLista(void)
{
    while (pInicio != NULL)
    {
        pAtual = pInicio;
        pInicio = pInicio->pProx;
        free(pAtual->pDisco);
        free(pAtual);   
    }
    pFim = NULL;
    pAtual = NULL;
}

void MainMenu(void)
{
    int op;
    NODO *pNodo = NULL;

    do
    {
        printf("\n==== MENU ====\n");
        printf("1- Cadastrar disco\n2- Imprimir discos\n3- Salvar na memória local\n4- Ler lista\n5- Sair\nEscolha uma opção: ");
        scanf("%i",&op);

        switch (op)
        {
            case 1:
                pNodo = CriaDisco();
                CadastroDisco(pNodo->pDisco);
                InsereNaLista(pNodo);
            break;
            
            case 2: 
                PrintDisco();
            break;
            
            case 3:
                SalvaLista();
                printf("Salvo na memória local com sucesso!\n");
            break;

            case 4:
                LeLista();
                printf("Lista lida com sucesso, ecolha a opção 2 para ver registros.\n");
            break;

            case 5:
                DestroiLista();
                printf("Saindo.\n");
            break;

            default:
                printf("Opção inválida.\n");
            break;
        }
    } while (op != 5);
}

void SalvaLista(void)
{
    FILE *pArquivo;
    pArquivo = fopen("lista.txt", "w+");
    pAtual = pInicio;
    while(pAtual != NULL)
    {
        fwrite(pAtual->pDisco, sizeof(DISCO), 1, pArquivo);
        pAtual = pAtual->pProx;
    }
    fclose(pArquivo);
}

void LeLista(void) //reconstroi lista do printPessoa se fecha o arq
{
    FILE *pArquivo;
    NODO *pNodo = NULL;
    DISCO *pDisco = NULL;
    NODO *pAux = NULL;

    pArquivo = fopen("lista.txt", "r+");

    if (pArquivo == NULL)
    {
        printf("Arquivo nao encontrado.\n");
        return;
    }

    //limpa a lista atual
    pAtual = pInicio;

    while (pAtual != NULL)
    {
        pAux = pAtual->pProx;

        free(pAtual->pDisco);
        free(pAtual);

        pAtual = pAux;
    }

    pInicio = NULL;
    pFim = NULL;
    pAtual = NULL;

    while(1)
    {
        pDisco = (DISCO *)malloc(sizeof(DISCO));

        if(fread(pDisco, sizeof(DISCO), 1, pArquivo) != 1)
        {
            free(pDisco);
            break;
        }

        pNodo = CriaNodo();
        pNodo->pDisco = pDisco;

        InsereNaLista(pNodo);
    }

    fclose(pArquivo);
}

int main()
{
    MainMenu();
    return 0;
}
