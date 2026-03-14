/**
 * @file verificarSequencia.cpp
 * @brief Verifica se existe uma sequência de pelo menos dois dígitos iguais e consecutivos em um número natural N usando recursão.
 * 
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

/**
 * @brief Verifica se há dois dígitos iguais consecutivos em N usando recursão.
 *
 * @param N O número natural a ser verificado.
 * @return true se houver dois dígitos iguais consecutivos, false caso contrário.
 */

bool iguais(int A, int B) {
    if (A == B) {
        return true;
    } else {
        return false;
    }
}

bool verificarSequencia(int N) {
    if (N >= 0 && N <= 9){
        return false;
    } else {
        int ultimoDigito = N % 10;
        int penultimoDigito = (N / 10) % 10;
        if (iguais(ultimoDigito, penultimoDigito) == true) {
            return true;
        } else {
            return verificarSequencia(N / 10); 
        }
    }
}

TEST_CASE("Verificar Dígitos Iguais Consecutivos - Testes") {
    CHECK(verificarSequencia(0) == false);
    CHECK(verificarSequencia(9) == false);
    CHECK(verificarSequencia(2113) == true);
    CHECK(verificarSequencia(2131) == false);
    CHECK(verificarSequencia(112345) == true);
    CHECK(verificarSequencia(123456) == false);
    CHECK(verificarSequencia(122233) == true);
}
