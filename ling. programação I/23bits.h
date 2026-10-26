/*
 * bits.h - Interface publica do modulo de manipulacao de bits.
 *
 * Convencao usada em todo o modulo:
 *   - Os bits sao numerados da direita para a esquerda, comecando em 0.
 *   - O bit 0 e o menos significativo (o mais a direita).
 *
 *        bit:  7 6 5 4 3 2 1 0
 *        valor 0 1 0 0 1 0 1 1   = 0x4B = 75
 */

#ifndef BITS_H
#define BITS_H

#include <stdint.h>

/* ---- Operacoes em um unico bit ---- */
uint32_t Bits_Liga(uint32_t valor, int posicao);     /* poe 1 no bit        */
uint32_t Bits_Desliga(uint32_t valor, int posicao);  /* poe 0 no bit        */
uint32_t Bits_Inverte(uint32_t valor, int posicao);  /* troca 0 <-> 1       */
int      Bits_Testa(uint32_t valor, int posicao);    /* retorna 0 ou 1      */

/* ---- Operacoes em varios bits (campos) ---- */
uint32_t Bits_ExtraiCampo(uint32_t valor, int posicao, int tamanho);
uint32_t Bits_InsereCampo(uint32_t valor, int posicao, int tamanho, uint32_t campo);

/* ---- Contas feitas com shift ---- */
uint32_t Bits_MultiplicaPor2ElevadoA(uint32_t valor, int n);
uint32_t Bits_DividePor2ElevadoA(uint32_t valor, int n);
int      Bits_EhPotenciaDeDois(uint32_t valor);

/* ---- Informacoes e utilitarios ---- */
int      Bits_ContaLigados(uint32_t valor);
uint32_t Bits_GiraEsquerda8(uint32_t valor, int n);  /* rotacao em 8 bits   */
void     Bits_Imprime(uint32_t valor, int quantidadeDeBits);

#endif
