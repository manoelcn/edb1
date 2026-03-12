// Escreva uma função recursiva soma que receba um array e seu tamanho, e retorne a soma de todos os elementos.

#include <iostream>
using namespace std;

int soma_de_lista(int lista[], int tamanho) {
    if (tamanho == 0) {
        return 0;
    } else {
        return lista[tamanho - 1] + soma_de_lista(lista, tamanho - 1);
    }
}

int main() {
    int lista[] = {1, 2, 3, 4};
    cout << soma_de_lista(lista, 4) << endl;
    return 0;
}