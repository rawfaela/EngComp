#include <stdio.h>

int main()
{
    int i = 0;
    int lista[5];

    //diff dos dois: while testa antes de entrar no corpo, do while testa depois de entrar no corpo
    do
    {
        lista[i] = i + 10;
        i++;
    } while (i<5);

    i = 0;
    do
    {
        printf("lista[%i] = %i\n",i,lista[i]);
        i++;
    } while (i<5);
}
