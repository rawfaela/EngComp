/*
 * bits-demo.c - Demonstracao do modulo bits.
 *
 * Compilar:  gcc -Wall -Wextra bits.c bits-demo.c -o bits-demo
 */

#include <stdio.h>
#include "bits.h"

/* Mostra "rotulo: <binario> (decimal)" em uma linha. */
static void Mostra(const char *rotulo, uint32_t valor)
{
    printf("%-22s ", rotulo);
    Bits_Imprime(valor, 8);
    printf("  (%u)\n", valor);
}

/* Permissoes de arquivo: cada bit e uma opcao liga/desliga. */
#define PERMISSAO_LER      0   /* bit 0 */
#define PERMISSAO_ESCREVER 1   /* bit 1 */
#define PERMISSAO_EXECUTAR 2   /* bit 2 */

int main(void)
{
    uint32_t valor = 0x4B;   /* 0100 1011 */

    printf("\n=== 1. Operacoes em um bit ===\n");
    Mostra("valor original", valor);
    Mostra("liga bit 2", Bits_Liga(valor, 2));
    Mostra("desliga bit 0", Bits_Desliga(valor, 0));
    Mostra("inverte bit 7", Bits_Inverte(valor, 7));
    printf("bit 3 esta ligado? %d\n", Bits_Testa(valor, 3));
    printf("bit 2 esta ligado? %d\n", Bits_Testa(valor, 2));

    printf("\n=== 2. Campos (varios bits) ===\n");
    valor = 0xB6;            /* 1011 0110 */
    Mostra("valor original", valor);
    Mostra("campo bits 2..4", Bits_ExtraiCampo(valor, 2, 3));
    Mostra("troca campo por 010", Bits_InsereCampo(valor, 2, 3, 2));

    printf("\n=== 3. Shift como multiplicacao e divisao ===\n");
    printf("5 << 3 = %u\n", Bits_MultiplicaPor2ElevadoA(5, 3));
    printf("40 >> 3 = %u\n", Bits_DividePor2ElevadoA(40, 3));
    printf("64 e potencia de 2? %d\n", Bits_EhPotenciaDeDois(64));
    printf("65 e potencia de 2? %d\n", Bits_EhPotenciaDeDois(65));

    printf("\n=== 4. Contagem e rotacao ===\n");
    valor = 0x96;            /* 1001 0110 */
    Mostra("valor original", valor);
    printf("bits ligados: %d\n", Bits_ContaLigados(valor));
    Mostra("gira 3 a esquerda", Bits_GiraEsquerda8(valor, 3));

    printf("\n=== 5. Exemplo pratico: permissoes ===\n");
    uint32_t permissoes = 0;
    permissoes = Bits_Liga(permissoes, PERMISSAO_LER);
    permissoes = Bits_Liga(permissoes, PERMISSAO_ESCREVER);
    Mostra("ler + escrever", permissoes);

    if (Bits_Testa(permissoes, PERMISSAO_EXECUTAR) == 0)
    {
        printf("Sem permissao de executar.\n");
    }

    permissoes = Bits_Desliga(permissoes, PERMISSAO_ESCREVER);
    Mostra("removeu escrever", permissoes);

    printf("\n");
    return 0;
}
