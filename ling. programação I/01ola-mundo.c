#include <stdio.h> //standart io -> entrada e saída padrão

int main() {
    printf("Olá, mundo!\n");

    float altura;
    int idade;
    char nome[50] = "João";

    altura = 1.75;  
    idade = 25;       
                             //placeholder - formata a string
    printf("Altura definida: %.2fm\n", altura);
    printf("Idade definida: %i anos\n", idade); //pode ser %i ou %d
    printf("Nome definido: %s\n", nome);

    printf("Digite sua altura: ");
    scanf("%f",&altura);
    printf("Altura digitada: %.2fm\n", altura);

    return 0; //nao faz diferença com ou sem ?
}
