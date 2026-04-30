#include <iostream>
#include <cassert>
#include "DadosEntrada.h"

using namespace std;

void mergeSort(int[], int, int);
bool estaDecrescente(int[], int);

int main(void)
{
    cout << "\t---\tQuestão 02: Início\t---" << endl;

    int tamanho = 1000000;

    mergeSort(arrayAleatorio, 0, tamanho - 1); // arrayAleatorio é definido dentro de DadosEntrada.h

    assert(estaDecrescente(arrayAleatorio, tamanho));

    mergeSort(arrayCrescente, 0, tamanho - 1); // arrayCrescente é definido dentro de DadosEntrada.h

    assert(estaDecrescente(arrayCrescente, tamanho));

    cout << "\t---\tQuestão 02: Passou em todos os testes\t---" << endl;

    return 0;
}

void merge(int array[], int esquerda, int meio, int direita)
{
    int tamanhoEsquerda = meio - esquerda + 1;
    int tamanhoDireita = direita - meio;

    int *subArrayEsquerda = new int[tamanhoEsquerda];
    int *subArrayDireita = new int[tamanhoDireita];

    for (int i = 0; i < tamanhoEsquerda; i++)
    {
        subArrayEsquerda[i] = array[esquerda + i];
    }

    for (int j = 0; j < tamanhoDireita; j++)
    {
        subArrayDireita[j] = array[meio + 1 + j];
    }

    int i = 0, j = 0;
    int k = esquerda;

    while (i < tamanhoEsquerda && j < tamanhoDireita)
    {
        if (subArrayEsquerda[i] >= subArrayDireita[j])
        {
            array[k] = subArrayEsquerda[i];
            i++;
        }
        else
        {
            array[k] = subArrayDireita[j];
            j++;
        }
        k++;
    }

    while (i < tamanhoEsquerda)
    {
        array[k] = subArrayEsquerda[i];
        i++;
        k++;
    }

    while (j < tamanhoDireita)
    {
        array[k] = subArrayDireita[j];
        j++;
        k++;
    }

    delete[] subArrayEsquerda;
    delete[] subArrayDireita;
}

void mergeSort(int array[], int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int meio = (esquerda + direita) / 2;
        mergeSort(array, esquerda, meio);
        mergeSort(array, meio + 1, direita);
        merge(array, esquerda, meio, direita);
    }
}

/**
 * Esta é uma função auxiliar que eu criei para poder testar se sua ordenação está correta. Não altere-a.
 */
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