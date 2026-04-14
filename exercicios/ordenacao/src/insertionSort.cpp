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
        string novo = array[i];
        int j = i - 1;
        while (j >= 0 && novo < array[j])
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = novo;
    }
}