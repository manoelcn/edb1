/**
 * @file contarDigitosParesImpares.cpp
 * @brief Contar quantos dígitos pares e ímpares existem em um número natural N usando recursão.
 * 
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include <utility> // Para usar std::pair

/**
 * @brief Função para contar a quantidade de dígitos pares e ímpares.
 *
 * @param N O número natural a ser processado.
 * @return Um par com a quantidade de dígitos pares e ímpares.
 */
std::pair<int, int> contarDigitosParesImpares(int N) {
    if (N >= 0 && N <= 9) {
        if (N % 2 == 0) {
            return std::make_pair(1, 0);
        } else {
            return std::make_pair(0, 1);
        }
    } else {
        if ((N % 10) % 2 == 0){
            auto resultado = contarDigitosParesImpares(N / 10);
            return std::make_pair(resultado.first + 1, resultado.second);
        } else {
            auto resultado = contarDigitosParesImpares(N / 10);
            return std::make_pair(resultado.first, resultado.second + 1);           
        }
    }
}

TEST_CASE("Contar Dígitos Pares e Ímpares - Testes") {
    auto resultado = contarDigitosParesImpares(0);
    CHECK(resultado.first == 1);  // Verifica a quantidade de dígitos pares
    CHECK(resultado.second == 0); // Verifica a quantidade de dígitos ímpares

    resultado = contarDigitosParesImpares(9);
    CHECK(resultado.first == 0);  // Verifica a quantidade de dígitos pares
    CHECK(resultado.second == 1); // Verifica a quantidade de dígitos ímpares

    resultado = contarDigitosParesImpares(111111);
    CHECK(resultado.first == 0);  // Verifica a quantidade de dígitos pares
    CHECK(resultado.second == 6); // Verifica a quantidade de dígitos ímpares

    resultado = contarDigitosParesImpares(24680);
    CHECK(resultado.first == 5);  // Verifica a quantidade de dígitos pares
    CHECK(resultado.second == 0); // Verifica a quantidade de dígitos ímpares

    resultado = contarDigitosParesImpares(1267774613);
    CHECK(resultado.first == 4);  // Verifica a quantidade de dígitos pares
    CHECK(resultado.second == 6); // Verifica a quantidade de dígitos ímpares

    resultado = contarDigitosParesImpares(1234567890);
    CHECK(resultado.first == 5);  // Verifica a quantidade de dígitos pares
    CHECK(resultado.second == 5); // Verifica a quantidade de dígitos ímpares

    resultado = contarDigitosParesImpares(987654321);
    CHECK(resultado.first == 4);  // Verifica a quantidade de dígitos pares
    CHECK(resultado.second == 5); // Verifica a quantidade de dígitos ímpares
}
