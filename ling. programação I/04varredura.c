#include <stdio.h>

int main()
{
    char nome[] = "João da Silva";
    char primNome[50];

    for (int i = 0; i < sizeof(nome); i++)
    {
        printf("%c",nome[i]);
    }
    printf("\n");

    printf("Nome ao contrário: ");
    for (int i = (sizeof(nome) - 1); i >= 0; i--)
    {
        printf("%c",nome[i]);
    }
    printf("\n");

    for (int i = 0; i< sizeof(nome); i++)
    {
        primNome[i] += nome[i];

        if (nome[i] == ' ') //char é com aspas simples
        {
            break;
        }
    }
    printf("Primeiro nome: %s\n",primNome);
    

    char nome2[50];
    printf("Digite o nome: ");
    fgets(nome2, 50, stdin);
    printf("nome digitado: %s\n",nome2);

    return 0;
}
