// Descrição:
// Crie uma função que encontre o menor elemento de um array de inteiros.

#include <iostream>
using namespace std;

int encontrarMenorElemento(int arr[], int tamanho) {
    int menor_valor = arr[0];
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] < menor_valor) {
            menor_valor = arr[i];
        }
    }
    return menor_valor;
    
}

int main() {
    int testesPassados = 0;

    int arr1[] = {3, 1, 4, 1, 5};
    cout << "Teste 1: O resultado esperado é 1 e o valor retornado foi " << encontrarMenorElemento(arr1, 5) << endl;
    if (encontrarMenorElemento(arr1, 5) == 1) testesPassados++;

    int arr2[] = {10, 20, 5, 15};
    cout << "Teste 2: O resultado esperado é 5 e o valor retornado foi " << encontrarMenorElemento(arr2, 4) << endl;
    if (encontrarMenorElemento(arr2, 4) == 5) testesPassados++;

    int arr3[] = {-3, -1, -4, -2};
    cout << "Teste 3: O resultado esperado é -4 e o valor retornado foi " << encontrarMenorElemento(arr3, 4) << endl;
    if (encontrarMenorElemento(arr3, 4) == -4) testesPassados++;

    int arr4[] = {7};
    cout << "Teste 4: O resultado esperado é 7 e o valor retornado foi " << encontrarMenorElemento(arr4, 1) << endl;
    if (encontrarMenorElemento(arr4, 1) == 7) testesPassados++;

    int arr5[] = {0, 2, -1, 3};
    cout << "Teste 5: O resultado esperado é -1 e o valor retornado foi " << encontrarMenorElemento(arr5, 4) << endl;
    if (encontrarMenorElemento(arr5, 4) == -1) testesPassados++;

    cout << "Sua implementação passou em " << testesPassados << " de 5 testes." << endl;

    return 0;
}