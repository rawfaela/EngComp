#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pessoa
{
    char nome[50];
    int idade;
} PESSOA;

typedef struct nodo //ponto de intersecção
{
    struct nodo *pProx; //ponteiro pro proximo nodo (é oq liga um no outro)
    struct nodo *pPrev; //          '' nodo anterior ''
    PESSOA *pPessoa; 
} NODO;

NODO *pInicio = NULL;
NODO *pFim    = NULL;
NODO *pAtual  = NULL;

NODO *CriaNodo(void)
{
    NODO *pNodo;
    pNodo = (NODO *)malloc(sizeof(NODO));

    pNodo->pProx   = NULL;
    pNodo->pPrev   = NULL;
    pNodo->pPessoa = NULL;

    return(pNodo);
}

PESSOA *CriaPessoa (void)
{
    PESSOA *pPessoa;
    pPessoa = (PESSOA *)malloc(sizeof(PESSOA));
    
    return(pPessoa); //endereço da memoria onde a pessoa foi criada
}

void CadastroPessoa(PESSOA *pPessoa)
{
    printf("Digite o nome: ");
    scanf(" %[^\n]", pPessoa->nome);
    printf("Digite a idade: ");
    scanf("%i",&pPessoa->idade);
}

void PrintPessoa(PESSOA *pPessoa)
{
    printf("Nome: %s\n",pPessoa->nome);
    printf("Idade: %i\n",pPessoa->idade);
}

void AdicionaPessoa(PESSOA *pPessoa)
{
    NODO *pNodo;
    pNodo          = CriaNodo();
    pNodo->pPessoa = pPessoa;

    if(pInicio == NULL)
    {
        pInicio = pNodo;
        pFim    = pNodo;
        pAtual  = pNodo;
    }
    else
    {
        pNodo->pPrev = pFim;
        pFim->pProx  = pNodo;
        pFim         = pNodo;
        pAtual       = pNodo;
    }
}

void MainMenu()
{
    int op;

    while (op != 3)
    {
        printf("\n==== MENU ====\n");
        printf("1- Cadastrar pessoa\n2- Imprimir pessoa\n3- Sair\nEscolha uma opção: ");
        scanf("%i",&op);

        switch (op)
        {
            case 1:
                PESSOA *pPessoa = CriaPessoa();
                CadastroPessoa(pPessoa);
                AdicionaPessoa(pPessoa);
            break;
            
            case 2: //so printa a atual
                if (pAtual == NULL)
                {
                    printf("Nenhuma pessoa cadastrada.");
                }
                else
                {
                    printf("\n--- Pessoas Cadastradas ---\n");
                    PrintPessoa(pAtual->pPessoa);
                }
            break;
            
            case 3:
                printf("Saindo.\n");
            break;

            default:
                printf("Opção inválida.\n");
            break;
        }
    }
}

int main()
{
    MainMenu();
    return 0;
}
