#include <stdio.h>
#include <string.h>

typedef struct Pessoa //estrutura definida fora do main é var global (conhecida em todo o programa)
{
    char nome[50];
    int idade;
    float altura, peso;
}PESSOA; //maiúsculo pq é um tipo de dado que o usuário fez (tipo definido pelo usuario)

int main()
{
    PESSOA jose;
    strcpy(jose.nome,"José");
    jose.idade = 25;
    jose.altura = 1.75;
    jose.peso = 70;

    printf("Nome: %s\n", jose.nome);
    printf("Idade: %i anos\n", jose.idade);
    printf("Altura: %.2fm\n", jose.altura);
    printf("Peso: %.2fkg\n", jose.peso);
}
