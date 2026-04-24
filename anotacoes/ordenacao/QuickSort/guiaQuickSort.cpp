#include <iostream>

void trocar(int lista[], int i, int j)
{
    // 1. guarde lista[i] em uma variável temporária

    // 2. copie lista[j] para lista[i]

    // 3. copie a variável temporária para lista[j]
}

int medianaDeTres(int lista[], int indiceEsquerda, int indiceDireita)
{
    // 1. calcule o indiceMeio sem risco de overflow


    // 2. se lista[esquerda] > lista[meio], troque os dois


    // 3. se lista[esquerda] > lista[direita], troque os dois


    // 4. se lista[meio] > lista[direita], troque os dois
    //    (após os três passos acima, lista[meio] é a mediana)


    // 5. mova a mediana para lista[direita] para que particionar()
    //    a encontre onde espera (troque meio com direita)


    // 6. retorne lista[direita] (o pivô)
}

int particionar(int lista[], int indiceEsquerda, int indiceDireita)
{
    // 1. pegue o valorPivo em lista[indiceDireita]
    //    (já colocado lá pelo medianaDeTres)


    // 2. declare indiceMenor começando em indiceEsquerda - 1
    //    (fronteira da partição esquerda, começa vazia)


    // 3. percorra j de indiceEsquerda até indiceDireita - 1 (não inclui o pivô):
    //    se lista[j] <= valorPivo:
    //      - avance indiceMenor
    //      - troque lista[indiceMenor] com lista[j]


    // 4. coloque o pivô na posição definitiva:
    //    - posicaoFinalPivo = indiceMenor + 1
    //    - troque lista[posicaoFinalPivo] com lista[indiceDireita]


    // 5. retorne posicaoFinalPivo
}

void quickSort(int lista[], int indiceEsquerda, int indiceDireita)
{
    // 1. caso base: se indiceEsquerda >= indiceDireita, retorne


    // 2. chame medianaDeTres() para escolher e posicionar o pivô


    // 3. chame particionar() e guarde o índice do pivô em indicePivo


    // 4. chame quickSort() recursivamente para o lado esquerdo
    //    (de indiceEsquerda até indicePivo - 1)


    // 5. chame quickSort() recursivamente para o lado direito
    //    (de indicePivo + 1 até indiceDireita)
}