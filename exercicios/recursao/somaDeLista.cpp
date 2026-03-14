// Escreva uma função recursiva soma que receba um array e seu tamanho, e retorne a soma de todos os elementos.

#include <iostream>

int somaDeLista(int lista[], int tamanho) {
    if (tamanho == 0) {
        return 0;
    } else {
        return lista[tamanho - 1] + somaDeLista(lista, tamanho - 1);
    }
}

int main() {
    int lista[] = {1, 2, 3, 4};
    std::cout << somaDeLista(lista, 4) << std::endl;
    return 0;
}