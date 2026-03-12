// Escreva uma função recursiva contagem que imprima todos os números de n até 1.

#include <iostream>
using namespace std;

void contagem_regressiva(int n) {
    cout << n << endl;
    if (n <= 1) {
        return;
    } else {
        contagem_regressiva(n - 1);
    }
}

int main() {
    contagem_regressiva(3);
    return 0;
}
