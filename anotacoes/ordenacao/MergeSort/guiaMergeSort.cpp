#include <iostream>

void mesclar(int lista[], int indiceEsquerda, int indiceMeio, int indiceDireita)
{
    // 1. calcule o tamanho de cada metade


    // 2. aloque dois arrays temporários, um para cada metade


    // 3. copie os dados do lista[] para os arrays temporários
    //    (um loop para cada metade)


    // 4. declare os três ponteiros:
    //    - i: percorre o array da esquerda (começa em 0)
    //    - j: percorre o array da direita (começa em 0)
    //    - k: percorre o lista[] original (começa em indiceEsquerda)


    // 5. intercale os dois arrays temporários de volta em lista[]:
    //    enquanto i e j não chegarem ao fim dos seus arrays,
    //    compare subEsquerda[i] com subDireita[j] e copie o menor para lista[k]


    // 6. copie os elementos restantes do array da esquerda (se houver)


    // 7. copie os elementos restantes do array da direita (se houver)


    // 8. libere a memória dos dois arrays temporários
}

void mergeSort(int lista[], int indiceEsquerda, int indiceDireita)
{
    // 1. caso base: se indiceEsquerda >= indiceDireita, retorne


    // 2. calcule o indiceMeio sem risco de overflow
    //    dica: não use (esquerda + direita) / 2


    // 3. chame mergeSort recursivamente para a metade esquerda


    // 4. chame mergeSort recursivamente para a metade direita


    // 5. chame mesclar() para juntar as duas metades ordenadas
}