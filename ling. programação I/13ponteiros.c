#include <stdio.h>

int main()
{
    int a = 20, *pA; //ponteiro para A (tem q ser do mesmo tipo da var)
    pA = &a; //& extrai endereço (na memória) de uma variável

    printf("Valor de A: %i\n",a);
    printf("Endereço de A por A: %p\n",(void*)&a);
    printf("Endereço de A pelo ponteiro: %p\n",(void*)pA);
    printf("Valor apontado por pA: %i\n",*pA);

    *pA = 30; //o conteudo da memória apontada por pA recebe 30
    printf("Valor apontado por pA depois de mudar *pA: %i\n",*pA);
    printf("Valor de A depois de mudar *pA: %i\n",a);

    /*  -------------------------------------------------------------------------------------  */
    printf("\n\n");
    
    int vetor[5], *pV;
    for (int i = 0; i<5; i++)
    {
        vetor[i] = i * 10;
        printf("vetor[%i]: %i\n", i, vetor[i]);
    }

    pV = vetor; // aponta p primeiro elemento do vetor (nao precisa de & pq vetor ja é o endereço)
    //nome de um vetor é o endereço base (na memória) de uma lista de valores

    for (int i = 0; i<5; i++)
    {
        pV[i] = i * 100;
    }
    for (int i = 0; i<5; i++)
    {
        printf("vetor[%i]: %i\n", i, vetor[i]);
    }

    //aritmética de ponteiros
    for (int i = 0; i<5; i++)
    {
        *(pV + i) = i * 1000;
    }
    for (int i = 0; i<5; i++)
    {
        printf("vetor[%i]: %i\n", i, vetor[i]);
    }
}
