// Descrição:
// Escreva uma função que determine se um número é par.
// A função deve retornar true se o número for par e false caso contrário.

#include <iostream>
using namespace std;

bool ehPar(int numero) {
    if (numero % 2 == 0) {
        return true;
    }
    return false;

}

int main() {
    int testesPassados = 0;

    cout << "Teste 1: O resultado esperado é 1 e o valor retornado foi " << ehPar(4) << endl;
    if (ehPar(4) == true) testesPassados++;

    cout << "Teste 2: O resultado esperado é 0 e o valor retornado foi " << ehPar(7) << endl;
    if (ehPar(7) == false) testesPassados++;

    cout << "Teste 3: O resultado esperado é 1 e o valor retornado foi " << ehPar(0) << endl;
    if (ehPar(0) == true) testesPassados++;

    cout << "Teste 4: O resultado esperado é 0 e o valor retornado foi " << ehPar(-5) << endl;
    if (ehPar(-5) == false) testesPassados++;

    cout << "Teste 5: O resultado esperado é 1 e o valor retornado foi " << ehPar(-8) << endl;
    if (ehPar(-8) == true) testesPassados++;

    cout << "Sua implementação passou em " << testesPassados << " de 5 testes." << endl;

    return 0;
}