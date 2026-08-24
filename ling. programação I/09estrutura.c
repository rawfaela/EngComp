#include <stdio.h>
//#include <string.h>

int main()
{
    struct Pessoa //agrupa varias variáveis q podem ser de tipos diff
    {
        char nome[50];
        int idade;
        float altura, peso;
    };

    struct Pessoa pessoa1 = {"João", 25, 1.75, 70.5};

    //? outro jeito de declarar
    /* struct Pessoa rafa;
    strcpy(rafa.nome, "Rafa"); //strcpy(destino, origem)
    rafa.idade = 19;
    rafa.altura = 1.70;
    rafa.peso = 60;
    printf("Nome: %s\n", rafa.nome);
    printf("Idade: %i anos\n", rafa.idade);
    printf("Altura: %.2fm\n", rafa.altura);
    printf("Peso: %.2fkg\n", rafa.peso); */
    //? fim

    printf("Nome: %s\n", pessoa1.nome);
    printf("Idade: %i anos\n", pessoa1.idade);
    printf("Altura: %.2fm\n", pessoa1.altura);
    printf("Peso: %.2fkg\n", pessoa1.peso);


    //? testes
    struct Pessoa listaPessoas[50];
    int op, aux=0;

    while (op != 3)
    {
        printf("1-Adicionar pessoa\n2-Ver pessoas\n3-Sair e ver pessoas\nDigite sua opção: ");
        scanf("%i",&op);

        switch (op)
        {
        case 1:
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
            for (int i = 0; i<aux; i++)
            {
                printf("\nPessoa %i: \n",i);
                printf("nome: %s \n",listaPessoas[i].nome);
                printf("idade: %i \n",listaPessoas[i].idade);
                printf("altura: %.2f \n",listaPessoas[i].altura);
                printf("peso: %.2f \n",listaPessoas[i].peso);
            }
        break;
        case 3:
            printf("\nSaindo!\n");
        break;
        default:
            printf("Opção inválida.");
        break;
        }
    }
    printf("----Pessoas cadastradas----");
    for (int i = 0; i<aux; i++)
    {
        printf("\nPessoa %i: \n",i);
        printf("nome: %s \n",listaPessoas[i].nome);
        printf("idade: %i \n",listaPessoas[i].idade);
        printf("altura: %.2f \n",listaPessoas[i].altura);
        printf("peso: %.2f \n",listaPessoas[i].peso);
    }
}

//recursividade: função chama ela mesma;
