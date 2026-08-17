#include <stdio.h>

int main()
{
    int lista[5];

    //atribui valores ao vetor
    for (int i = 0; i < 5; i++)
    {
        lista[i] = i + 10;
    }

    //imprime o conteudo do vetor
    for(int i = 0; i<5; i++)
    {
        printf("lista[%i]: %i\n",i,lista[i]);
    }
    
    return 0;
}
