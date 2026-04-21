#include <iostream>

void mesclar(int lista[], int indiceEsquerda, int indiceMeio, int indiceDireita)
{
    // calcula o tamanho de cada metade
    int tamanhoEsquerda = indiceMeio - indiceEsquerda + 1;
    int tamanhoDireita = indiceDireita - indiceMeio;

    // aloca arrays temporários para guardar as duas metades
    int *subEsquerda = new int[tamanhoEsquerda];
    int *subDireita = new int[tamanhoDireita];

    // copia os dados para os arrays temporários
    for (int i = 0; i < tamanhoEsquerda; i++)
    {
        subEsquerda[i] = lista[indiceEsquerda + i];
    }
    for (int j = 0; j < tamanhoDireita; j++)
    {
        subDireita[j] = lista[indiceMeio + 1 + j];
    }

    int i = 0;              // ponteiro para percorrer subEsquerda
    int j = 0;              // ponteiro para percorrer subDireita
    int k = indiceEsquerda; // ponteiro para a posição atual no array original

    // intercala os dois subarrays em ordem crescente
    while (i < tamanhoEsquerda && j < tamanhoDireita)
    {
        if (subEsquerda[i] <= subDireita[j])
        {
            lista[k] = subEsquerda[i]; // elemento da esquerda é menor, usa ele
            i++;
        }
        else
        {
            lista[k] = subDireita[j]; // elemento da direita é menor, usa ele
            j++;
        }
        k++;
    }

    // copia os elementos restantes da esquerda (se houver)
    while (i < tamanhoEsquerda)
    {
        lista[k] = subEsquerda[i];
        i++;
        k++;
    }

    // copia os elementos restantes da direita (se houver)
    while (j < tamanhoDireita)
    {
        lista[k] = subDireita[j];
        j++;
        k++;
    }

    // libera a memória dos arrays temporários
    delete[] subEsquerda;
    delete[] subDireita;
}

void mergeSort(int lista[], int indiceEsquerda, int indiceDireita)
{
    // caso base: o subarray tem 0 ou 1 elemento
    if (indiceEsquerda >= indiceDireita)
    {
        return;
    }

    // encontra o índice do meio sem risco de overflow de inteiro
    int indiceMeio = indiceEsquerda + (indiceDireita - indiceEsquerda) / 2;

    // ordena recursivamente a metade esquerda
    mergeSort(lista, indiceEsquerda, indiceMeio);

    // ordena recursivamente a metade direita
    mergeSort(lista, indiceMeio + 1, indiceDireita);

    // mescla as duas metades já ordenadas em um subarray ordenado
    mesclar(lista, indiceEsquerda, indiceMeio, indiceDireita);
}