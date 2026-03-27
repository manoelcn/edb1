/**
 * @file contarOcorrencias.cpp
 * @brief Conta o número de ocorrências de um elemento em um array ordenado usando busca binária.
 * 
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

/**
 * @brief Conta o número de ocorrências de um elemento em um array ordenado.
 *
 * @param arr O array ordenado de inteiros.
 * @param tamanho O tamanho do array.
 * @param alvo O elemento a ser contado.
 * @return O número de ocorrências do elemento no array.
 */

int buscaPrimeiro(const int arr[], int inicio, int fim, int alvo) {
    int resultado = -1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (arr[meio] == alvo) {
            resultado = meio;
            fim = meio - 1;
        } else if (arr[meio] > alvo) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return resultado;
}

int buscaUltimo(const int arr[], int inicio, int fim, int alvo) {
    int resultado = -1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (arr[meio] == alvo) {
            resultado = meio;
            inicio = meio + 1;
        } else if (arr[meio] > alvo) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return resultado;
}

int contarOcorrencias(const int arr[], int tamanho, int alvo) {
    int inicio = 0;
    int fim = tamanho - 1;
    int primeiro = buscaPrimeiro(arr, inicio, fim, alvo);
    int ultimo = buscaUltimo(arr, inicio, fim, alvo);
    if (primeiro == -1 && ultimo == -1) {
        return 0;
    }
    return ultimo - primeiro + 1;
}

TEST_CASE("Contar Ocorrências de um Elemento em um Array Ordenado - Testes") {
    int arr1[] = {1, 2, 2, 2, 3, 4, 5};
    CHECK(contarOcorrencias(arr1, 7, 2) == 3);
    CHECK(contarOcorrencias(arr1, 7, 4) == 1);
    CHECK(contarOcorrencias(arr1, 7, 5) == 1);
    CHECK(contarOcorrencias(arr1, 7, 6) == 0);
}
