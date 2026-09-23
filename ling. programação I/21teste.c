#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct disco
{
    int   codigo;
    char  titulo[100];
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

int codAux = 0;

//quando declara as funções antes (pra uma "saber" da existência da outra) é um protótipo de função
NODO *CriaDisco(void);
NODO *CriaNodo(void);
void CadastroDisco(DISCO *pDisco);
void AlteraDisco(void);
void PrintDisco(void);
void MainMenu(void);
void SalvaLista(void);
void LeLista(void);


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
    pDisco->codigo = codAux + 1;

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

void AlteraDisco(void)
{
    char nomeAlt[100];

    printf("Digite o nome do disco para alterar: ");
    scanf(" %[^\n]", &nomeAlt);
    pAtual = pInicio;

    DISCO *bufferDiscos = (DISCO *)malloc(pFim->pDisco->codigo * sizeof(DISCO));
    

    int auxPos = 0;
    int auxCod;
    while(pAtual != NULL)
    {
        if (strcmp(pAtual->pDisco->titulo, nomeAlt) == 0)
        {
            memcpy(&bufferDiscos[auxPos], pAtual->pDisco, sizeof(DISCO));
            auxPos++;
        }
        pAtual = pAtual->pProx;
    }

    if (bufferDiscos != NULL)
    {
        printf("Discos encontrados com sucesso!\n");
        for (int i = 0; i < auxPos - 1; i++)
        {
            printf("Código: %i\n",bufferDiscos[i].codigo);
            printf("Título: %s\n",bufferDiscos[i].titulo);
            printf("Artista: %s\n",bufferDiscos[i].artista);
            printf("Gravadora: %s\n",bufferDiscos[i].gravadora);
            printf("Ano de publicação: %i\n",bufferDiscos[i].anoPublicacao);
            printf("Duração (min): %.2f\n",bufferDiscos[i].duracao);
            printf("-------------\n");
        }
        
        if (auxPos > 0)
        {
            printf("Digite o código do disco para alterar: ");
            scanf("%i", &auxCod);
            for (int i = 0; i<auxPos -  1; i++)
            {
                if (auxCod == bufferDiscos[i].codigo)
                {
                    printf("Insira os novos dados:\n");
                    //CadastroDisco(pEncontrado->pDisco);
                    printf("Disco alterado com sucesso!\n");
                }
            }
        }
    }
    else
    {
        printf("Disco não encontrado.\n");
    }

    free(bufferDiscos);
}

void PrintDisco(void)
{ 
    printf("\n--- Discos Cadastrados ---\n");
    pAtual = pInicio; 
    if (pAtual == NULL)
    {
        printf("Nenhum disco cadastrado.\n");
        return;
    }
    while(pAtual != NULL)
    {
        printf("Código: %i\n",pAtual->pDisco->codigo);
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

void MainMenu(void)
{
    int op;
    NODO *pNodo = NULL;

    do
    {
        printf("\n==== MENU ====\n");
        printf("1- Cadastrar disco\n2- Alterar disco\n3- Imprimir discos\n4- Salvar na memória local\n5- Ler lista\n6- Sair\nEscolha uma opção: ");
        scanf("%i",&op);

        switch (op)
        {
            case 1:
                pNodo = CriaDisco();
                CadastroDisco(pNodo->pDisco);
                InsereNaLista(pNodo);
            break;
            
            case 2:
                
                AlteraDisco();
            break;

            case 3: 
                PrintDisco();
            break;
            
            case 4:
                SalvaLista();
                printf("Salvo na memória local com sucesso!\n");
            break;

            case 5:
                LeLista();
                printf("Lista lida com sucesso, ecolha a opção 2 para ver registros.\n");
            break;

            case 6:
                printf("Saindo.\n");
            break;

            default:
                printf("Opção inválida.\n");
            break;
        }
    } while (op != 6);
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
