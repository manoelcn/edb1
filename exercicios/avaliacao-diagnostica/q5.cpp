// Descrição:
// Crie uma função que conte quantos números entre 0 e N são primos.

#include <iostream>
#include <cmath>
using namespace std;

bool ehPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }
    else if (numero == 2) {
        return true;
    }
    else {
        for (int i = 2; i <= sqrt(numero); i++){
            if (numero % i == 0) {
                return false;
            }
        }
        return true;
    }
}

int contarPrimosAteN(int N) {
    int resultado = 0;
    for (int i = 1; i <= N; i++){
        if (ehPrimo(i) == true) {
            resultado += 1;
        }
    }
    return resultado;
}

int main() {
    int testesPassados = 0;

    cout << "Teste 1: O resultado esperado é 4 e o valor retornado foi " << contarPrimosAteN(10) << endl;
    if (contarPrimosAteN(10) == 4) testesPassados++;

    cout << "Teste 2: O resultado esperado é 8 e o valor retornado foi " << contarPrimosAteN(20) << endl;
    if (contarPrimosAteN(20) == 8) testesPassados++;

    cout << "Teste 3: O resultado esperado é 3 e o valor retornado foi " << contarPrimosAteN(5) << endl;
    if (contarPrimosAteN(5) == 3) testesPassados++;

    cout << "Teste 4: O resultado esperado é 0 e o valor retornado foi " << contarPrimosAteN(1) << endl;
    if (contarPrimosAteN(1) == 0) testesPassados++;

    cout << "Teste 5: O resultado esperado é 25 e o valor retornado foi " << contarPrimosAteN(100) << endl;
    if (contarPrimosAteN(100) == 25) testesPassados++;

    cout << "Sua implementação passou em " << testesPassados << " de 5 testes." << endl;

    return 0;
}