#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "DadosEntrada.h"
#include <vector>

using namespace std;

void mesclar(int arr[], int esquerda, int meio, int direita)
{
    int tamanhoEsquerda = meio - esquerda + 1;
    int tamanhoDireita = direita - meio;

    int *subArrEsquerda = new int[tamanhoEsquerda];
    int *subArrDireita = new int[tamanhoDireita];

    for (int i = 0; i < tamanhoEsquerda; i++)
    {
        subArrEsquerda[i] = arr[esquerda + i];
    }

    for (int j = 0; j < tamanhoDireita; j++)
    {
        subArrDireita[j] = arr[meio + 1 + j];
    }

    int i = 0, j = 0;
    int k = esquerda;

    while (i < tamanhoEsquerda && j < tamanhoDireita)
    {
        if (subArrEsquerda[i] >= subArrDireita[j])
        {
            arr[k] = subArrEsquerda[i];
            i++;
        }
        else
        {
            arr[k] = subArrDireita[j];
            j++;
        }
        k++;
    }

    while (i < tamanhoEsquerda)
    {
        arr[k] = subArrEsquerda[i];
        i++;
        k++;
    }

    while (j < tamanhoDireita)
    {
        arr[k] = subArrDireita[j];
        j++;
        k++;
    }

    delete[] subArrEsquerda;
    delete[] subArrDireita;
}

void mergeSort(int arr[], int esquerda, int direita)
{
    if (esquerda >= direita)
    {
        return;
    }

    int meio = esquerda + (direita - esquerda) / 2;

    mergeSort(arr, esquerda, meio);
    mergeSort(arr, meio + 1, direita);

    mesclar(arr, esquerda, meio, direita);
}

/**
 * Não altere o código abaixo.
 * Sua solução deve ser implementada na função mergeSort.
 */
// Função auxiliar para verificar ordem decrescente
bool estaDecrescente(int array[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        if (array[i] < array[i + 1])
        {
            return false;
        }
    }

    return true;
}

// Função auxiliar ao teste
void CHECK_EQUALS(const vector<int> &entrada, const vector<int> &esperado)
{
    vector<int> copia = entrada;
    int *arr = copia.data();
    mergeSort(arr, 0, copia.size() - 1);
    CHECK(copia == esperado);
}

//  Testes
TEST_CASE("Casos básicos")
{
    CHECK_EQUALS({}, {});
    CHECK_EQUALS({1}, {1});
    CHECK_EQUALS({2, 1}, {2, 1});
    CHECK_EQUALS({1, 2}, {2, 1});
}

TEST_CASE("Casos médios")
{
    CHECK_EQUALS({3, 1, 4, 2}, {4, 3, 2, 1});
    CHECK_EQUALS({5, 3, 8, 4, 2}, {8, 5, 4, 3, 2});
    CHECK_EQUALS({10, 9, 8, 7, 6, 5}, {10, 9, 8, 7, 6, 5});
}

TEST_CASE("Casos com repetidos e negativos")
{
    CHECK_EQUALS({1, 3, 3, 2, 2, 1}, {3, 3, 2, 2, 1, 1});
    CHECK_EQUALS({-3, -1, -2, 0}, {0, -1, -2, -3});
    CHECK_EQUALS({1000, -100, 500, 0, -1, 999}, {1000, 999, 500, 0, -1, -100});
}

TEST_CASE("Caso array pequeno e aleatório")
{
    int t1 = sizeof(arrayPequeno) / sizeof(int);
    mergeSort(arrayPequeno, 0, t1 - 1);

    CHECK(estaDecrescente(arrayPequeno, t1));
}

TEST_CASE("Caso array grande e aleatório")
{
    int t1 = sizeof(arrayGrande) / sizeof(int);
    mergeSort(arrayGrande, 0, t1 - 1);

    CHECK(estaDecrescente(arrayGrande, t1));
}
