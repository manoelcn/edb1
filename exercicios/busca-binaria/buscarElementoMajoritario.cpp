/**
 * @file buscarElementoMajoritario.cpp
 * @brief Determina se existe um elemento majoritário em um array ordenado.
 *
 * @copyright (c) 2024 Eiji Adachi Medeiros Barbosa
 *
 * Este código é licenciado sob a Licença MIT.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"

/**
 * @brief Verifica se existe um elemento majoritário em um array ordenado.
 *
 * @param arr O array ordenado de inteiros.
 * @param tamanho O tamanho do array.
 * @return O elemento majoritário se existir, caso contrário -1.
 */

int buscaPrimeiro(const int arr[], int inicio, int fim, int alvo)
{
    int resultado = -1;
    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (arr[meio] == alvo)
        {
            resultado = meio;
            fim = meio - 1;
        }
        else if (arr[meio] > alvo)
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }
    }
    return resultado;
}

int buscaUltimo(const int arr[], int inicio, int fim, int alvo)
{
    int resultado = -1;
    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (arr[meio] == alvo)
        {
            resultado = meio;
            inicio = meio + 1;
        }
        else if (arr[meio] > alvo)
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }
    }
    return resultado;
}

int buscarElementoMajoritario(const int arr[], int tamanho)
{
    int tamanhoMajoritario = tamanho / 2;
    int inicio = 0;
    int fim = tamanho - 1;
    int meio = (inicio + fim) / 2;
    int primeiro = buscaPrimeiro(arr, inicio, fim, arr[meio]);
    int ultimo = buscaUltimo(arr, inicio, fim, arr[meio]);
    int resultado = ultimo - primeiro + 1;
    if (resultado > tamanhoMajoritario)
    {
        return arr[meio];
    }
    return -1;
}

TEST_CASE("Buscar o Elemento Majoritário - Testes")
{
    int arr1[] = {1, 1, 1, 2, 2, 2, 2};
    CHECK(buscarElementoMajoritario(arr1, 7) == 2);

    int arr2[] = {1, 2, 3, 4, 5};
    CHECK(buscarElementoMajoritario(arr2, 5) == -1);

    int arr3[] = {3, 3, 3, 3, 4};
    CHECK(buscarElementoMajoritario(arr3, 5) == 3);

    int arr4[] = {10, 10, 10, 10, 10, 11, 12};
    CHECK(buscarElementoMajoritario(arr4, 7) == 10);
}
