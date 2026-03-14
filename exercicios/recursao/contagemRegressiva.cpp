// Escreva uma função recursiva contagem que imprima todos os números de n até 1.

#include <iostream>

void contagemRegressiva(int n) {
    std::cout << n << std::endl;
    if (n <= 1) {
        return;
    } else {
        contagemRegressiva(n - 1);
    }
}

int main() {
    contagemRegressiva(3);
    return 0;
}
