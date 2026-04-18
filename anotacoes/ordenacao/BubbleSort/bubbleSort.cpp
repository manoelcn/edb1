#include <iostream>

void bubbleSort(int lista[], int tamanho)
{
    for (int passagem = 0; passagem < tamanho - 1; passagem++) // cada passagem garante que o maior elemento não ordenado vai para sua posição final
                                                               // por isso reduzimos o limite em 1 a cada iteração
    {
        bool houveTroca = false; // flag de otimização, se não houver nenhuma troca nesta passagem, o array já está ordenado e podemos parar

        for (int j = 0; j < tamanho - 1 - passagem; j++) // compara pares adjacentes até o último elemento não ordenado
                                                         // (tamanho - 1 - passagem), pois os últimos 'passagem' jã estão no lugar
        {
            if (lista[j] > lista[j + 1])
            {
                // troca os vizinhos fora de ordem
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
                houveTroca = true;
            }
        }

        if (!houveTroca) // encerra antecipadamente se já está ordernado
        {
            break;
        }
    }
}