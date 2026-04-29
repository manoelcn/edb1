#include <iostream>
#include <cassert>
#include "DadosEntrada.h"

using namespace std;

bool estaDecrescente(int[], int);

void trocar(int array[], int a, int b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

int mediana3(int array[], int esquerda, int direita)
{
    int meio = esquerda + (direita - esquerda) / 2;

    if (array[esquerda] > array[meio])
    {
        trocar(array, esquerda, meio);
    }

    if (array[esquerda] > array[direita])
    {
        trocar(array, esquerda, direita);
    }

    if (array[meio] > array[direita])
    {
        trocar(array, meio, direita);
    }

    trocar(array, meio, direita);

    return array[direita];
}

int particionar(int array[], int esquerda, int direita)
{
    int valorPivo = array[direita];
    int indiceMenor = esquerda - 1;

    for (int i = esquerda; i < direita; i++)
    {
        if (array[i] >= valorPivo)
        {
            indiceMenor++;
            trocar(array, indiceMenor, i);
        }
    }

    int posicaoFinalPivo = indiceMenor + 1;
    trocar(array, posicaoFinalPivo, direita);

    return posicaoFinalPivo;
}

void quickSort(int array[], int esquerda, int direita)
{
    if (esquerda >= direita)
    {
        return;
    }

    mediana3(array, esquerda, direita);

    int pivo = particionar(array, esquerda, direita);

    quickSort(array, esquerda, pivo - 1);
    quickSort(array, pivo + 1, direita);
}

/**
 * Não altere a função main.
 * Sua solução deve ser implementada na função quickSort.
 */
int main(void)
{
    cout << "\t---\tQuestão 02: Início\t---" << endl;

    int t1 = sizeof(arrayPequeno) / sizeof(int);

    cout << t1 << endl;

    quickSort(arrayPequeno, 0, t1 - 1); // arrayPequeno é definido dentro de DadosEntrada.h

    assert(estaDecrescente(arrayPequeno, t1));

    int t2 = sizeof(arrayGrande) / sizeof(int);

    quickSort(arrayGrande, 0, t2 - 1); // arrayGrande é definido dentro de DadosEntrada.h

    assert(estaDecrescente(arrayGrande, t2));

    cout << "\t---\tQuestão 02: Passou em todos os testes\t---" << endl;

    return 0;
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