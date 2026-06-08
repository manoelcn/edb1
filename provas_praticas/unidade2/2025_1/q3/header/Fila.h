//
//  Fila.h ​
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#ifndef __Fila__
#define __Fila__
#define __CHECK_INTEGRIDADE__ 1
#include <string>
#include <sstream>
#include <vector>
template <typename T>
class Fila
{
private:
    T* elementos;
    int capacidade;
    int quantidade;
    int inicio;
    int fim;
    
public:
    // Não altere ​
    Fila(int cap)
    {
        this->quantidade = 0;
        this->inicio = 0;
        this->fim = 0;
        this->capacidade = cap;
        this->elementos = new T[this->capacidade];
    }
    // Não altere ​
    ~Fila()
    {
        delete [] this->elementos;
    }
    
    int tamanho()
    {
        return this->quantidade;
    }

    T frente()                                                                                                                                                                                                // versão: EAMB-1.0
    {// Begin ​
        throw "Método 'frente' não implementado.";// Lembre-se de comentar esta linha ​
    }// End

    void enfileirar(T elemento)
    {// Begin
        throw "Método 'enfileirar' não implementado.", elemento;// Lembre-se de comentar esta linha 
    }// End​

    T desenfileirar()
    {// Begin ​
        throw "Método 'desenfileirar'não implementado.";// Lembre-se de comentar esta linha 
    }//⁣ End

    bool cheia()
    {
        return this->quantidade == this->capacidade;
    }

    bool vazia()
    {
        return this->quantidade == 0;
    }

    std::string imprimir()
    {
        std::stringstream r; r << "{ "; for (int a = this->inicio, b = 0; b < this->quantidade; ++b, a = (a + 1) % this->capacidade) r << this->elementos[a] << " ";r << "}";return r.str();       
    }
};

#endif