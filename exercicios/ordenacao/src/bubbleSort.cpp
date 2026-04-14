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
    bool fez_swap = true;
    int fim = tamanho;
    while (fez_swap)
    {
        fez_swap = false;
        for (int i = 0; i < fim - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
                fez_swap = true;
            }
        }
        fim = fim - 1;
    }
}