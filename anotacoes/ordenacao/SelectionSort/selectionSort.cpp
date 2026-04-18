#include <iostream>

void selectionSort(int lista[], int tamanho)
{
    for (int i = 0; i < tamanho; i++) // i representa a fronteira entre a parte ordenada e a parte não ordenada
    {
        int indiceMenor = i; // assume que o primeiro elemento da parte não ordenada é o mínimo

        for (int j = i + 1; i < tamanho; j++) // varre o restante do array para encontrar o verdadeiro mínimo
        {
            if (lista[j] < lista[indiceMenor])
            {
                indiceMenor = j; // atualiza o índice do menor valor encontrado
            }

            if (indiceMenor != i) // se o mínimo não está na posição i, troca os elementos
            {
                int temp = lista[i];
                lista[i] = lista[indiceMenor];
                lista[indiceMenor] = temp;
            }
        }
    }
}