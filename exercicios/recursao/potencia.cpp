// Escreva uma função recursiva potencia que calcule base elevado ao expoente.

#include <iostream>

int potencia(int base, int expoente) {
    if (expoente <= 0) {
        return 1;
    } else {
        return base * potencia(base, expoente - 1);
    }
}

int main() {
    std::cout << potencia(2, 4) << std::endl;
    return 0;
}