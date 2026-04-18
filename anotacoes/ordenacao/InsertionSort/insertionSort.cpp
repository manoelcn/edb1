#include <iostream>

void insertionSort(int lista[], int tamanho)
{
    for (int i = 1; i < tamanho; i++) // começa no índice 1, pois o elemento 0 já está "ordenado" sozinho
    {
        int elementoChave = lista[i]; // guarda o elemento atual que vamos inserir na posição certa
        int j = i - 1;                // j começa uma posição antes do elemento atual

        while (j >= 0 && lista[j] > elementoChave) // desloca para a direita todos os elementos da parte ordenada que são maiores do que a chave
        {
            lista[j + 1] = lista[j]; // abre espaço deslocando para a direita
            j--;                     // move o ponteiro para a esquerda.
        }

        lista[j + 1] = elementoChave; // insere a chave na lacuna aberta pelo deslocamento
        // j+1 é a posição correta porque j parou onde array[j] <= chave
    }
}