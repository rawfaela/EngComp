#include <stdio.h>

int main()
{
    printf("Quantidade de bytes de cada tipo de variável\n");
    printf("int: %d\n",sizeof(int));
    printf("char: %d\n",sizeof(char));
    printf("float: %d\n",sizeof(float));
    printf("double: %d\n",sizeof(double));

    printf("Quantidade de bits de cada tipo de variável\n");
    printf("int: %d\n",sizeof(int)*8);
    printf("char: %d\n",sizeof(char)*8);
    printf("float: %d\n",sizeof(float)*8);
    printf("double: %d\n",sizeof(double)*8);
}
