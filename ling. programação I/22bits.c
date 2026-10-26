/*
 * bits.c - Implementacao do modulo de manipulacao de bits.
 *
 * Operadores usados nesta aula:
 *   &   E  (AND)    : 1 somente se os dois bits forem 1
 *   |   OU (OR)     : 1 se pelo menos um dos bits for 1
 *   ^   OU exclusivo (XOR) : 1 se os bits forem diferentes
 *   ~   NAO (NOT)   : inverte todos os bits
 *   <<  shift esquerda : empurra os bits para a esquerda (entra 0 a direita)
 *   >>  shift direita  : empurra os bits para a direita  (entra 0 a esquerda)
 */

#include <stdio.h>
#include "bits.h"

/* ------------------------------------------------------------------ */
/* Operacoes em um unico bit                                           */
/* ------------------------------------------------------------------ */

/*
 * Para mexer em UM bit, criamos uma "mascara" com 1 somente nessa posicao:
 *
 *   mascara = 1 << posicao
 *
 *   posicao 3  ->  0000 1000
 */

uint32_t Bits_Liga(uint32_t valor, int posicao)
{
    uint32_t mascara = 1u << posicao;

    /* OU com a mascara forca aquele bit a ser 1 e nao mexe nos outros. */
    uint32_t resultado = valor | mascara;
    return resultado;
}

uint32_t Bits_Desliga(uint32_t valor, int posicao)
{
    uint32_t mascara = 1u << posicao;

    /* ~mascara tem 0 somente na posicao desejada.
     * E com ela forca aquele bit a ser 0 e nao mexe nos outros. */
    uint32_t mascaraInvertida = ~mascara;
    uint32_t resultado = valor & mascaraInvertida;
    return resultado;
}

uint32_t Bits_Inverte(uint32_t valor, int posicao)
{
    uint32_t mascara = 1u << posicao;

    /* XOR com 1 inverte o bit; XOR com 0 deixa como esta. */
    uint32_t resultado = valor ^ mascara;
    return resultado;
}

int Bits_Testa(uint32_t valor, int posicao)
{
    /* Primeiro trazemos o bit desejado para a posicao 0 ... */
    uint32_t deslocado = valor >> posicao;

    /* ... e depois isolamos so o bit 0 com a mascara 1. */
    uint32_t bit = deslocado & 1u;
    return (int)bit;
}

/* ------------------------------------------------------------------ */
/* Operacoes em varios bits (campos)                                   */
/* ------------------------------------------------------------------ */

/* Cria uma mascara com 'tamanho' bits 1 seguidos, comecando no bit 0.
 *
 *   tamanho 3  ->  0000 0111
 *
 * Como funciona:  (1 << 3) = 0000 1000   ;   0000 1000 - 1 = 0000 0111
 */
static uint32_t CriaMascaraDeTamanho(int tamanho)
{
    uint32_t umNaPosicao = 1u << tamanho;
    uint32_t mascara = umNaPosicao - 1u;
    return mascara;
}

/*
 * Extrai um campo de 'tamanho' bits que comeca em 'posicao'.
 *
 *   valor = 1011 0110 , posicao = 2 , tamanho = 3
 *
 *   passo 1: valor >> 2     = 0010 1101   (campo foi para o bit 0)
 *   passo 2: & 0000 0111    = 0000 0101   (so ficam os 3 bits do campo)
 */
uint32_t Bits_ExtraiCampo(uint32_t valor, int posicao, int tamanho)
{
    uint32_t deslocado = valor >> posicao;
    uint32_t mascara = CriaMascaraDeTamanho(tamanho);
    uint32_t campo = deslocado & mascara;
    return campo;
}

/*
 * Troca o campo de 'tamanho' bits que comeca em 'posicao' por um novo valor.
 *
 *   valor = 1011 0110 , posicao = 2 , tamanho = 3 , campo = 010
 *
 *   passo 1: mascara do campo na posicao   = 0001 1100
 *   passo 2: apaga o campo antigo          = 1010 0010
 *   passo 3: campo novo na posicao         = 0000 1000
 *   passo 4: junta com OU                  = 1010 1010
 */
uint32_t Bits_InsereCampo(uint32_t valor, int posicao, int tamanho, uint32_t campo)
{
    uint32_t mascaraBase = CriaMascaraDeTamanho(tamanho);
    uint32_t mascaraNaPosicao = mascaraBase << posicao;

    uint32_t valorSemCampo = valor & ~mascaraNaPosicao;

    /* 'campo & mascaraBase' garante que o campo novo nao passa do tamanho. */
    uint32_t campoLimitado = campo & mascaraBase;
    uint32_t campoNaPosicao = campoLimitado << posicao;

    uint32_t resultado = valorSemCampo | campoNaPosicao;
    return resultado;
}

/* ------------------------------------------------------------------ */
/* Contas feitas com shift                                             */
/* ------------------------------------------------------------------ */

/* Cada shift a esquerda multiplica por 2:  5 << 3 = 5 * 8 = 40 */
uint32_t Bits_MultiplicaPor2ElevadoA(uint32_t valor, int n)
{
    uint32_t resultado = valor << n;
    return resultado;
}

/* Cada shift a direita divide por 2 (divisao inteira):  40 >> 3 = 5 */
uint32_t Bits_DividePor2ElevadoA(uint32_t valor, int n)
{
    uint32_t resultado = valor >> n;
    return resultado;
}

/*
 * Uma potencia de 2 tem exatamente um bit ligado:
 *
 *   8     = 1000
 *   8 - 1 = 0111
 *   8 & 7 = 0000   -> zero somente para potencias de 2
 */
int Bits_EhPotenciaDeDois(uint32_t valor)
{
    if (valor == 0)
    {
        return 0;
    }

    uint32_t anterior = valor - 1u;
    uint32_t resultado = valor & anterior;

    if (resultado == 0)
    {
        return 1;
    }
    return 0;
}

/* ------------------------------------------------------------------ */
/* Informacoes e utilitarios                                           */
/* ------------------------------------------------------------------ */

/* Conta quantos bits 1 existem, testando um por um. */
int Bits_ContaLigados(uint32_t valor)
{
    int total = 0;
    int posicao = 0;

    while (posicao < 32)
    {
        if (Bits_Testa(valor, posicao) == 1)
        {
            total++;
        }
        posicao++;
    }
    return total;
}

/*
 * Rotacao de 8 bits: os bits que "saem" pela esquerda
 * voltam a entrar pela direita.
 *
 *   1001 0110 girado 3 casas para a esquerda:
 *
 *   parte que continua: 1001 0110 << 3 = 1011 0000  (corta em 8 bits)
 *   parte que voltou  : 1001 0110 >> 5 = 0000 0100
 *   junta com OU      :                  1011 0100
 */
uint32_t Bits_GiraEsquerda8(uint32_t valor, int n)
{
    uint32_t valor8 = valor & 0xFFu;
    int giro = n % 8;

    uint32_t parteQueFicou = (valor8 << giro) & 0xFFu;
    uint32_t parteQueVoltou = valor8 >> (8 - giro);

    uint32_t resultado = parteQueFicou | parteQueVoltou;
    return resultado;
}

/* Imprime os 'quantidadeDeBits' bits menos significativos, do mais alto ao 0. */
void Bits_Imprime(uint32_t valor, int quantidadeDeBits)
{
    int posicao = quantidadeDeBits - 1;

    while (posicao >= 0)
    {
        printf("%d", Bits_Testa(valor, posicao));

        /* Espaco a cada 4 bits para facilitar a leitura. */
        if (posicao % 4 == 0 && posicao != 0)
        {
            printf(" ");
        }
        posicao--;
    }
}
