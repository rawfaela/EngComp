#include <stdio.h>
#include <string.h>

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
    char nomeaux[50];

    while (op != 3)
    {
        printf("1-Adicionar pessoa\n2-Ver pessoas\n3-Sair e ver pessoas\nDigite sua opção: ");
        scanf("%i",&op);

        switch (op)
        {
        case 1:
            printf("Digite o nome da pessoa: ");
            scanf("%s",nomeaux);
            strcpy(listaPessoas[aux].nome,nomeaux);
            
            printf("nome dg: %s \n",listaPessoas[aux].nome); //aq pra teste só
            aux++;

            break;
        
        default:
            break;
        }
    }
}
