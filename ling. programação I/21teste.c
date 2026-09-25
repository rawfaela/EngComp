#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct disco
{
    int   codigo;
    char  titulo[100];
    char  artista[100];
    char  gravadora[50];
    int   anoPublicacao;
    float duracao;
} DISCO;

typedef struct nodo
{
    struct nodo *pProx; 
    struct nodo *pPrev; 
    DISCO       *pDisco; 
} NODO;

typedef struct resultado
{
    DISCO disco;
    NODO  *pNodo;
} RESULTADO;

NODO *pInicio = NULL;
NODO *pFim    = NULL;
NODO *pAtual  = NULL;
NODO *CriaDisco(void);
NODO *CriaNodo(void);

void CadastroDisco(DISCO *pDisco);
void AlteraDisco(RESULTADO *bufferDiscos, int auxPos);
void PrintDisco(void);
void MainMenu(void);
void SalvaLista(void);
void LeLista(void);
void DestroiLista(void);
void BuscaDisco(void);
void EditaDisco(DISCO *pDisco);

int codAux = 0;

NODO *CriaDisco(void) 
{
    DISCO *pDisco;
    pDisco = (DISCO *)malloc(sizeof(DISCO));
    
    NODO *pNodo;
    pNodo = CriaNodo();
    pNodo->pDisco = pDisco;

    return(pNodo); 
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
    scanf(" %[^\n]", pDisco->titulo); 
    printf("Digite o artista do disco: ");
    scanf(" %[^\n]", pDisco->artista); 
    printf("Digite a gravadora do disco: ");
    scanf(" %[^\n]", pDisco->gravadora);
    printf("Digite o ano de publicação do disco: ");
    scanf("%i",&pDisco->anoPublicacao);
    printf("Digite a duração do disco (min): ");
    scanf("%f",&pDisco->duracao);
}


void BuscaDisco(void)
{
    if (pInicio == NULL)
    {
        printf("Nenhum disco cadastrado.\n");
        return;
    }

    int op;
    int auxPos = 0;
    char pesquisa[100];
    pAtual = pInicio;
    RESULTADO *bufferDiscos = (RESULTADO *)malloc(pFim->pDisco->codigo * sizeof(RESULTADO));

    do
    {
        printf("Deseja pesquisar por\n1- Título\n2- Artista\nDigite sua opção: ");
        scanf("%i",&op);
        switch (op)
        {
        case 1:
            
            printf("Digite o nome do disco para buscar: ");
            scanf(" %[^\n]", pesquisa);

            while(pAtual != NULL)
            {
                if (strcmp(pAtual->pDisco->titulo, pesquisa) == 0) //tolower aq nao funciona pq so recebe um char por vez (fazer loop p trocar)
                {
                    bufferDiscos[auxPos].disco = *pAtual->pDisco;
                    bufferDiscos[auxPos].pNodo = pAtual;
                    auxPos++;
                }
                pAtual = pAtual->pProx;
            }
        break;
        
        case 2:
            printf("Digite o nome do artista para buscar: ");
            scanf(" %[^\n]", pesquisa);

            while(pAtual != NULL)
            {
                if (strcmp(pAtual->pDisco->artista, pesquisa) == 0) //tolower aq nao funciona pq so recebe um char por vez (fazer loop p trocar)
                {
                    bufferDiscos[auxPos].disco = *pAtual->pDisco;
                    bufferDiscos[auxPos].pNodo = pAtual;
                    auxPos++;
                }
                pAtual = pAtual->pProx;
            }
        break;

        default:
            printf("Opção inválida.\n\n");
        break;
        }
    } while(op != 1 && op!=2);

    
    if (auxPos > 0)
    {
        printf("Discos encontrados com sucesso!\n");
        for (int i = 0; i < auxPos; i++)
        {
            printf("Código: %i\n",bufferDiscos[i].disco.codigo);
            printf("Título: %s\n",bufferDiscos[i].disco.titulo);
            printf("Artista: %s\n",bufferDiscos[i].disco.artista);
            printf("Gravadora: %s\n",bufferDiscos[i].disco.gravadora);
            printf("Ano de publicação: %i\n",bufferDiscos[i].disco.anoPublicacao);
            printf("Duração (min): %.2f\n",bufferDiscos[i].disco.duracao);
            printf("-------------\n");
        }
    }
    else
    {
        printf("Disco não encontrado.\n");
    }

    AlteraDisco(bufferDiscos, auxPos);
    free(bufferDiscos);
}

void AlteraDisco(RESULTADO *bufferDiscos, int auxPos)
{
    int auxCod;
    if (auxPos > 0)
    {
        printf("Digite o código do disco para alterar: ");
        scanf("%i", &auxCod);
        for (int i = 0; i<auxPos; i++)
        {
            if (auxCod == bufferDiscos[i].disco.codigo)
            {
                printf("Insira os novos dados:\n");
                EditaDisco(bufferDiscos[i].pNodo->pDisco);
                printf("Disco alterado com sucesso!\n");
            }
        }
    }
}

void EditaDisco(DISCO *pDisco)
{   
    char titulo, artista, gravadora, ano, duracao;

    printf("Deseja alterar o título? (S/N)\n");
    scanf(" %c", &titulo);
    if(toupper(titulo) == 'S')
    {
        printf("Digite o novo título do disco: ");
        scanf(" %[^\n]", pDisco->titulo);
    }
    
    printf("Deseja alterar o artista? (S/N)\n");
    scanf(" %c", &artista);
    if(toupper(artista) == 'S')
    {
        printf("Digite o novo artista do disco: ");
        scanf(" %[^\n]", pDisco->artista);       
    }

    printf("Deseja alterar a gravadora? (S/N)\n");
    scanf(" %c", &gravadora);
    if(toupper(gravadora) == 'S')
    {
        printf("Digite a nova gravadora do disco: ");
        scanf(" %[^\n]", pDisco->gravadora);
    }

    printf("Deseja alterar o ano de publicação? (S/N)\n");
    scanf(" %c", &ano);
    if(toupper(ano) == 'S')
    {
        printf("Digite o novo ano de publicação do disco: ");
        scanf("%i", &pDisco->anoPublicacao);
    }

    printf("Deseja alterar a duração? (S/N)\n");
    scanf(" %c", &duracao);
    if(toupper(duracao) == 'S')
    {
        printf("Digite a nova duração do disco (min): ");
        scanf("%f", &pDisco->duracao);
    }
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
                BuscaDisco();
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
                printf("Lista lida com sucesso, ecolha a opção 3 para ver registros.\n");
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

void LeLista(void)
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
