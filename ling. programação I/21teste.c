#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//! FALTA EXCLUIR !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1

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
void BuscaDisco(int op);
void EditaDisco(DISCO *pDisco);
void Minusculo(char *texto);

int codAux = 0;

NODO *CriaDisco(void) 
{
    DISCO *pDisco;
    pDisco = (DISCO *)malloc(sizeof(DISCO));
    
    NODO *pNodo;
    pNodo         = CriaNodo();
    pNodo->pDisco = pDisco;

    return(pNodo); 
}

NODO *CriaNodo(void)
{
    NODO *pNodo;

    pNodo        = (NODO *)malloc(sizeof(NODO));
    pNodo->pProx = NULL;
    pNodo->pPrev = NULL;

    return(pNodo);
}

void CadastroDisco(DISCO *pDisco)
{
    codAux++;
    pDisco->codigo = codAux;

    printf("Digite o título do disco: ");
    scanf(" %[^\n]", pDisco->titulo); 
    printf("Digite o artista do disco: ");
    scanf(" %[^\n]", pDisco->artista); 
    printf("Digite a gravadora do disco: ");
    scanf(" %[^\n]", pDisco->gravadora);
    printf("Digite o ano de publicação do disco: ");
    scanf("%i", &pDisco->anoPublicacao);
    printf("Digite a duração do disco (min): ");
    scanf("%f", &pDisco->duracao);
}


void BuscaDisco(int op)
{
    if (pInicio == NULL)
    {
        printf("Nenhum disco cadastrado.\n");
        return;
    }

    RESULTADO *bufferDiscos = (RESULTADO *)malloc(pFim->pDisco->codigo * sizeof(RESULTADO)); //!! so funciona se não excluir
    char pesquisa[100];
    int  opPesq;
    int  auxPos = 0;
    pAtual      = pInicio;

    do
    {
        printf("Deseja pesquisar por\n1- Título\n2- Artista\nDigite sua opção: ");
        scanf("%i",&opPesq);

        switch (opPesq)
        {
        case 1:
            printf("Digite o nome do disco para buscar: ");
            scanf(" %[^\n]", pesquisa);
            Minusculo(pesquisa);

            while(pAtual != NULL)
            {
                char titulo[100];
                strcpy(titulo, pAtual->pDisco->titulo);
                Minusculo(titulo);

                if (strstr(titulo, pesquisa) != NULL) //tolower aq nao funciona pq so recebe um char por vez (fazer loop p trocar)
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
            Minusculo(pesquisa);

            while(pAtual != NULL)
            {
                char artista[100];
                strcpy(artista, pAtual->pDisco->titulo);
                Minusculo(artista);

                if (strstr(artista, pesquisa) != NULL) //tolower aq nao funciona pq so recebe um char por vez (fazer loop p trocar)
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
    } while(opPesq != 1 && opPesq!=2);

    
    if (auxPos > 0)
    {
        printf("Discos encontrados com sucesso!\n");
        for (int i = 0; i < auxPos; i++)
        {
            printf("-------------\n");
            printf("Código: %i\n",bufferDiscos[i].disco.codigo);
            printf("Título: %s\n",bufferDiscos[i].disco.titulo);
            printf("Artista: %s\n",bufferDiscos[i].disco.artista);
            printf("Gravadora: %s\n",bufferDiscos[i].disco.gravadora);
            printf("Ano de publicação: %i\n",bufferDiscos[i].disco.anoPublicacao);
            printf("Duração (min): %.2f\n",bufferDiscos[i].disco.duracao);
        }
    }
    else
    {
        printf("Disco não encontrado.\n");
    }

    if (op == 2)
    {
        AlteraDisco(bufferDiscos, auxPos);
    }

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
            else
            {
                printf("Disco não encontrado.\n");
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
        printf("-------------\n");
        printf("Código: %i\n",pAtual->pDisco->codigo);
        printf("Título: %s\n",pAtual->pDisco->titulo);
        printf("Artista: %s\n",pAtual->pDisco->artista);
        printf("Gravadora: %s\n",pAtual->pDisco->gravadora);
        printf("Ano de publicação: %i\n",pAtual->pDisco->anoPublicacao);
        printf("Duração (min): %.2f\n",pAtual->pDisco->duracao);
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
        pAtual  = pInicio;
        pInicio = pInicio->pProx;

        free(pAtual->pDisco);
        free(pAtual);   
    }
    pFim   = NULL;
    pAtual = NULL;
}

void MainMenu(void)
{
    int op;
    NODO *pNodo = NULL;

    do
    {
        printf("\n==== MENU ====\n");
        printf("1- Cadastrar disco\n2- Alterar disco\n3- Imprimir discos\n4- Buscar discos\n5- Salvar na memória local\n6- Ler lista\n7- Sair\nEscolha uma opção: ");
        scanf("%i",&op);

        switch (op)
        {
            case 1:
                pNodo = CriaDisco();
                CadastroDisco(pNodo->pDisco);
                InsereNaLista(pNodo);
            break;
            
            case 2:
                BuscaDisco(op);
            break;

            case 3: 
                PrintDisco();
            break;
            
            case 4:
                BuscaDisco(op);
            break;

            case 5:
                SalvaLista();
                printf("Salvo na memória local com sucesso!\n");
            break;

            case 6:
                LeLista();
                printf("Lista lida com sucesso, ecolha a opção 3 para ver registros.\n");
            break;

            case 7:
                DestroiLista();
                printf("Saindo.\n");
            break;

            default:
                printf("Opção inválida.\n");
            break;
        }
    } while (op != 7);
}

void SalvaLista(void)
{
    FILE *pArquivo;
    pArquivo = fopen("lista.txt", "w+");

    if (pArquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

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
    FILE  *pArquivo;
    NODO  *pNodo  = NULL;
    DISCO *pDisco = NULL;
    NODO  *pAux   = NULL;

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
    pFim    = NULL;
    pAtual  = NULL;

    while(1)
    {
        pDisco = (DISCO *)malloc(sizeof(DISCO));

        if(fread(pDisco, sizeof(DISCO), 1, pArquivo) != 1)
        {
            free(pDisco);
            break;
        }

        if(pDisco->codigo > codAux)
        {
            codAux = pDisco->codigo;
        }

        pNodo         = CriaNodo();
        pNodo->pDisco = pDisco;

        InsereNaLista(pNodo);
    }

    fclose(pArquivo);
}

void Minusculo(char *texto)
{
    int i;

    for(i = 0; texto[i] != '\0'; i++)
    {
        texto[i] = tolower(texto[i]);
    }
}

int main()
{
    MainMenu();
    return 0;
}