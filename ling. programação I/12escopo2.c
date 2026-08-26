#include <stdio.h>

typedef struct Pessoa
{
    char nome[50];
    int idade;
    float altura, peso;
}PESSOA;
PESSOA listaPessoas[50];
int op, aux=0;

void Menu() //void quando n tem certeza doq retorna
{
    printf("\n==== MENU ====\n");
    printf("1-Adicionar pessoa\n2-Ver pessoas\n3-Sair e ver pessoas\nDigite sua opção: ");
    scanf("%i",&op);
}

void Lista()
{
    printf("\n==== LISTA ====\n");
    for (int i = 0; i<aux; i++)
    {
        printf("---- Pessoa %i ---- \n",i);
        printf("nome: %s \n",listaPessoas[i].nome);
        printf("idade: %i anos\n",listaPessoas[i].idade);
        printf("altura: %.2fm\n",listaPessoas[i].altura);
        printf("peso: %.2fkg \n",listaPessoas[i].peso);
    }
}


int main()
{
    while (op != 3)
    {
        Menu();

        switch (op)
        {
        case 1:
            if (aux >= 50)
            {
                printf("\nLimite de cadastros atingido.\n");
                break;
            }
            printf("\n==== CADASTRO ====\n");
            printf("Digite o nome da pessoa: ");
            scanf("%s",listaPessoas[aux].nome);
            printf("Digite a idade: ");
            scanf("%i",&listaPessoas[aux].idade);
            printf("Digite a altura: ");
            scanf("%f",&listaPessoas[aux].altura);
            printf("Digite o peso: ");
            scanf("%f",&listaPessoas[aux].peso);

            aux++;
        break;

        case 2:
            Lista();
        break;

        case 3:
            printf("\nSaindo!\n");
        break;

        default:
            printf("Opção inválida.");
        break;
        }
    }
    Lista();
}
