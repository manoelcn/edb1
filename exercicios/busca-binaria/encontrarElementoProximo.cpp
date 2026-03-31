/**
 * @file encontrarElementoProximo.cpp
 * @brief Encontra o elemento mais próximo de um valor alvo em um array ordenado.
 * 
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 * 
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

/**
 * @brief Encontra o elemento mais próximo de um valor alvo em um array ordenado.
 *
 * @param arr O array ordenado de inteiros.
 * @param tamanho O tamanho do array.
 * @param alvo O valor alvo.
 * @return O valor do elemento mais próximo ao alvo.
 */
int encontrarElementoProximo(const int arr[], int tamanho, int alvo) {
    int inicio = 0;
    int fim = tamanho - 1;
    int maisProximo = arr[inicio];
    while (inicio <= fim){
        int meio = (inicio + fim) / 2;
        if (arr[meio] == alvo) {
            return arr[meio];
        } else if (arr[meio] > alvo) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
            maisProximo = arr[meio];
        }
    }
    return maisProximo;
}

TEST_CASE("Encontrar o Elemento Mais Próximo - Testes") {
    int arr1[] = {1, 3, 5, 7, 9};
    CHECK(encontrarElementoProximo(arr1, 5, 4) == 3);
    CHECK(encontrarElementoProximo(arr1, 5, 8) == 7);
    CHECK(encontrarElementoProximo(arr1, 5, 5) == 5);
    CHECK(encontrarElementoProximo(arr1, 5, 10) == 9);
}
