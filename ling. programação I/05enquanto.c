#include<stdio.h>

int main()
{
    int i = 0;
    int lista[5];
    
    //atribui valores ao vetor
    while (i<5)
    {
        lista[i] = i+ 10;
        i++;
    }

    i=0;
    while (i<5)
    {
        printf("lista[%i] = %i\n",i,lista[i]);
        i++;
    }
}
