#include <stdio.h>
#include <string.h>
#include <malloc.h>
//tem mais coisa no moodle, mas queria os comentarios
typedef struct lista //tem valores e comportamentos (funções)
{
    struct nodo 
    {
        struct nodo *pProximo;
        struct nodo *pAnterior;
        void *pPessoa;
    };

    struct nodo *pInicio;
    struct nodo *pFim;
    struct nodo *pAtual;
    
    struct lista (*CriaLista)(void); //encapsulamento -> esse comportamento é so desse objeto
    struct lista (*DestroiLista)(void);

} LISTA;

LISTA *CriaLista(void)
{
    LISTA *pLista = (LISTA *)malloc(sizeof(LISTA));
    if (pLista != NULL)
    {
        pLista->pInicio = NULL;
        pLista->pFim    = NULL;
        pLista->pAtual  = NULL;
    }
    return pLista;
}

int main(void)
{
    LISTA *minhaLista = CriaLista();
    if (minhaLista != NULL)
    {
        printf("\nLista criada com sucesso!\n");
    }
    else
    {
        printf("\nFalha ao criar lista.\n");
    }
    return 0;
}
