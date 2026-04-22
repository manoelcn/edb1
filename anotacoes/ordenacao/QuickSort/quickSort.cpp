#include <iostream>

void trocar(int lista[], int i, int j)
{
    int temp = lista[i];
    lista[i] = lista[j];
    lista[j] = temp;
}

int medianaDeTres(int lista[], int indiceEsquerda, int indiceDireita)
{
    // garante que lista[esquerda] <= lista[meio] <= lista[direita]
    int indiceMeio = indiceEsquerda + (indiceDireita - indiceEsquerda) / 2;

    if (lista[indiceEsquerda] > lista[indiceMeio])
    {
        trocar(lista, indiceEsquerda, indiceMeio);
    }

    if (lista[indiceEsquerda] > lista[indiceDireita])
    {
        trocar(lista, indiceEsquerda, indiceDireita);
    }

    if (lista[indiceMeio] > lista[indiceDireita])
    {
        trocar(lista, indiceMeio, indiceDireita);
    }

    // move a mediana para a última posição para que o particionamento de Lomuto a encontre onde espera
    trocar(lista, indiceMeio, indiceDireita);

    // retorna o valor do pivô
    return lista[indiceDireita];
}

int particionar(int lista[], int indiceEsquerda, int indiceDireita)
{
    int valorPivo = lista[indiceDireita]; // pivô já feito a mediana de 3
    int indiceMenor = indiceEsquerda - 1; // fronteira dos elementos <= pivô

    for (int j = indiceEsquerda; j < indiceDireita; j++)
    {
        // se o elemento atual é menor ou igual ao pivô, ele deve ficar na partição esquerda
        if (lista[j] <= valorPivo)
        {
            indiceMenor++;                 // aumenta a partição esquerda
            trocar(lista, indiceMenor, j); // faz a troca para trazer este elemento para a partição esqueda
        }
        // se lista[j] > valorPivo, não faz nada, pois o elemento já está na partição direita
    }

    // coloca o pivô na sua posição definitiva
    int posicaoFinalPivo = indiceMenor + 1;
    trocar(lista, posicaoFinalPivo, indiceDireita);

    return posicaoFinalPivo; // retorna o índice onde o pivô foi colocado
}

void quickSort(int lista[], int indiceEsquerda, int indiceDireita)
{
    // caso base, o subarray inválido ou de um único elemento
    if (indiceEsquerda >= indiceDireita)
    {
        return;
    }

    // faz a mediana de 3 para evitar o pior caso
    medianaDeTres(lista, indiceEsquerda, indiceDireita);

    // particiona o subarray e obtém a posição definitiva do pivô
    int indicePivo = particionar(lista, indiceEsquerda, indiceDireita);

    // ordena recursivamente a partição à esquerda do pivô (elementos menores ou iguais ao pivô)
    quickSort(lista, indiceEsquerda, indicePivo - 1);

    // ordena recursivamente a partição à direita do pivô (elementos maiores que o pivô)
    quickSort(lista, indicePivo + 1, indiceDireita);
}