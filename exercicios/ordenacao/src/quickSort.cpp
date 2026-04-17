#include "../include/ordenar.h"
#include <string>

void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

void mediana3(string arr[], int esquerda, int direita)
{
    int meio = (esquerda + direita) / 2;
    if (arr[esquerda] > arr[meio])
    {
        swap(arr[esquerda], arr[meio]);
    }
    if (arr[esquerda] > arr[direita])
    {
        swap(arr[esquerda], arr[direita]);
    }
    if (arr[meio] > arr[direita])
    {
        swap(arr[meio], arr[direita]);
    }
    swap(arr[meio], arr[direita]);
}

int particionar(string arr[], int esquerda, int direita)
{
    mediana3(arr, esquerda, direita);
    string pivo = arr[direita];
    int pos_final_pivo = esquerda - 1;
    for (int i = esquerda; i <= direita - 1; i++)
    {
        if (arr[i] <= pivo)
        {
            pos_final_pivo++;
            swap(arr[pos_final_pivo], arr[i]);
        }
    }
    swap(arr[pos_final_pivo + 1], arr[direita]);
    return pos_final_pivo + 1;
}

void quicksort(string v[], int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int i_pivo = particionar(v, esquerda, direita);
        quicksort(v, esquerda, i_pivo - 1);
        quicksort(v, i_pivo + 1, direita);
    }
}

void ordenar(string array[], int tamanho)
{
    quicksort(array, 0, tamanho - 1);
}