#include <stdio.h> //standart io -> entrada e saída padrão

int main() {
    printf("Olá, mundo!\n");

    float altura = 1.75;
    int idade = 25;
    char letra = 'a'; //se for só uma letra (um char), usa aspas simples
    char nome[50] = "João"; //uma string (seq de chars), aspas duplas
    double r = 1.5674; //numeros reais, precisão dupla
    
                             //placeholder - formata a string
    printf("Altura definida: %.2fm\n", altura);
    printf("Idade definida: %i anos\n", idade); //pode ser %i ou %d
    printf("Nome definido: %s\n", nome);

    printf("Digite sua altura: ");
    scanf("%f",&altura);
    printf("Altura digitada: %.2fm\n", altura);

    return 0; //nao faz diferença com ou sem
}
