// Descrição:
// Crie uma função que verifique se um número é primo.
// A função deve retornar true se o número for primo e false caso contrário

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

int main() {
    int testesPassados = 0;

    cout << "Teste 1: O resultado esperado é 1 e o valor retornado foi " << ehPrimo(5) << endl;
    if (ehPrimo(5) == true) testesPassados++;

    cout << "Teste 2: O resultado esperado é 0 e o valor retornado foi " << ehPrimo(10) << endl;
    if (ehPrimo(10) == false) testesPassados++;

    cout << "Teste 3: O resultado esperado é 1 e o valor retornado foi " << ehPrimo(13) << endl;
    if (ehPrimo(13) == true) testesPassados++;

    cout << "Teste 4: O resultado esperado é 0 e o valor retornado foi " << ehPrimo(1) << endl;
    if (ehPrimo(1) == false) testesPassados++;

    cout << "Teste 5: O resultado esperado é 1 e o valor retornado foi " << ehPrimo(17) << endl;
    if (ehPrimo(17) == true) testesPassados++;

    cout << "Sua implementação passou em " << testesPassados << " de 5 testes." << endl;

    return 0;
}
