#include "../include/ordenar.h"
#include <string>
#include <vector>

void merge(string array[], int inicio1, int inicio2, int fim2)
{
    int fim1 = inicio2 - 1;
    vector<string> temp(fim2 - inicio1 + 1);
    int i = inicio1;
    int j = inicio2;
    int k = 0;
    while (i <= fim1 && j <= fim2)
    {
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            i = i + 1;
        }
        else
        {
            temp[k] = array[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i <= fim1)
    {
        temp[k] = array[i];
        i = i + 1;
        k = k + 1;
    }
    while (j <= fim2)
    {
        temp[k] = array[j];
        j = j + 1;
        k = k + 1;
    }
    for (int i = inicio1, j = 0; i <= fim2; i++, j++)
    {
        array[i] = temp[j];
    }
}

void mergesort(string array[], int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int meio = (esquerda + direita) / 2;
        mergesort(array, esquerda, meio);
        mergesort(array, meio + 1, direita);
        merge(array, esquerda, meio + 1, direita);
    }
}

void ordenar(string array[], int tamanho)
{
    mergesort(array, 0, tamanho - 1);
}