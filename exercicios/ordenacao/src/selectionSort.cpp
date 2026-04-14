#include "../include/ordenar.h"
#include <string>

void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

void ordenar(string array[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        int indiceMinimo = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            if (array[j] < array[indiceMinimo])
            {
                indiceMinimo = j;
            }
        }
        if (i != indiceMinimo)
        {
            swap(array[i], array[indiceMinimo]);
        }
    }
}