/**
 * @file raizQuadradaInteira.cpp
 * @brief Encontra a parte inteira da raiz quadrada de um número usando busca binária.
 * 
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

/**
 * @brief Encontra a parte inteira da raiz quadrada de um número positivo usando busca binária.
 *
 * @param N O número positivo.
 * @return A parte inteira da raiz quadrada de N.
 */
int raizQuadradaInteira(int N) {
    int inicio = 0;
    int fim = N;
    int resultado = -1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (meio * meio == N) {
            return meio;
        } else if (meio * meio > N) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
            resultado = meio;
        }
    }
    return resultado;
}

TEST_CASE("Encontrar a Raiz Quadrada Inteira - Testes") {
    CHECK(raizQuadradaInteira(16) == 4);
    CHECK(raizQuadradaInteira(20) == 4);
    CHECK(raizQuadradaInteira(25) == 5);
    CHECK(raizQuadradaInteira(1) == 1);
    CHECK(raizQuadradaInteira(0) == 0);
}
