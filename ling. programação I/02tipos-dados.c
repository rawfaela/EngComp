#include<stdio.h>

int main() 
{
    char nome[50];
    int idade;
    float num1;
    double num2;

    printf("Digite seu nome: ");
    scanf("%s",&nome);
    printf("Digite sua idade: ");
    scanf("%i",&idade);

    printf("Digite um numero float: ");
    scanf("%f",&num1);
    printf("Digite um numero double: ");
    scanf("%lf",&num2);

    printf("Olá %s! Sua idade é %i.\n",nome,idade);
    printf("Número float: %.7f \nNúmero double: %.15lf \n",num1,num2); //maximo de numeros decimais de cada tipo
    return 0;
}
