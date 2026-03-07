// Descrição
// Implemente uma função que calcule a média dos elementos de um array de inteiros.

#include <iostream>
using namespace std;

double mediaArray(int arr[], int tamanho) {
    double soma = 0;
    double media = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += arr[i];
    }
    media = soma / tamanho;
    return media;
}

int main() {
    int testesPassados = 0;

    int arr1[] = {1, 2, 3, 4};
    cout << "Teste 1: O resultado esperado é 2.5 e o valor retornado foi " << mediaArray(arr1, 4) << endl;
    if (mediaArray(arr1, 4) == 2.5) testesPassados++;

    int arr2[] = {5, 5, 5, 5};
    cout << "Teste 2: O resultado esperado é 5 e o valor retornado foi " << mediaArray(arr2, 4) << endl;
    if (mediaArray(arr2, 4) == 5) testesPassados++;

    int arr3[] = {0, 0, 0, 0};
    cout << "Teste 3: O resultado esperado é 0 e o valor retornado foi " << mediaArray(arr3, 4) << endl;
    if (mediaArray(arr3, 4) == 0) testesPassados++;

    int arr4[] = {-1, -2, -3, -4};
    cout << "Teste 4: O resultado esperado é -2.5 e o valor retornado foi " << mediaArray(arr4, 4) << endl;
    if (mediaArray(arr4, 4) == -2.5) testesPassados++;

    int arr5[] = {10, 20, 30, 40, 50};
    cout << "Teste 5: O resultado esperado é 30 e o valor retornado foi "  << mediaArray(arr5, 5) << endl;
    if (mediaArray(arr5, 5) == 30) testesPassados++;

    cout << "Sua implementação passou em " << testesPassados << " de 5 testes." << endl;

    return 0;
}