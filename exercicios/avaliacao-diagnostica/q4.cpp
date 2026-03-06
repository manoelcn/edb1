// Descrição:
// Escreva uma função que conte quantos números entre 0 e N são divisíveis por 3 e 5 ao mesmo tempo.

#include <iostream>
using namespace std;

int contarDivisiveisPor3e5(int N) {
    int resultado = 0;
    for (int i = 1; i <= N; i++){
        if (i % 3 == 0 && i % 5 == 0){
            resultado += 1;
        }
    }
    return resultado;
}

int main() {
    int testesPassados = 0;

    cout << "Teste 1: O resultado esperado é 1 e o valor retornado foi " << contarDivisiveisPor3e5(15) << endl;
    if (contarDivisiveisPor3e5(15) == 1) testesPassados++;

    cout << "Teste 2: O resultado esperado é 2 e o valor retornado foi " << contarDivisiveisPor3e5(30) << endl;
    if (contarDivisiveisPor3e5(30) == 2) testesPassados++;

    cout << "Teste 3: O resultado esperado é 0 e o valor retornado foi " << contarDivisiveisPor3e5(10) << endl;
    if (contarDivisiveisPor3e5(10) == 0) testesPassados++;

    cout << "Teste 4: O resultado esperado é 3 e o valor retornado foi " << contarDivisiveisPor3e5(45) << endl;
    if (contarDivisiveisPor3e5(45) == 3) testesPassados++;

    cout << "Teste 5: O resultado esperado é 6 e o valor retornado foi " << contarDivisiveisPor3e5(90) << endl;
    if (contarDivisiveisPor3e5(90) == 6) testesPassados++;

    cout << "Sua implementação passou em " << testesPassados << " de 5 testes." << endl;

    return 0;
}