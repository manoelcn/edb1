// Escreva uma função recursiva potencia que calcule base elevado ao expoente.

#include <iostream>
using namespace std;

int potencia(int base, int expoente) {
    if (expoente <= 0) {
        return 1;
    } else {
        return base * potencia(base, expoente - 1);
    }
}

int main() {
    cout << potencia(2, 4) << endl;
    return 0;
}