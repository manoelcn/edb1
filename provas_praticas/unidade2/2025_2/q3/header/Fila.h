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

    // ​Leia o enunciado com atenção antes de implementar este método. 
    T frente()                                                                                                                                                                                                // versão: EAMB-1.0
    {// Begin ​
        if (this->vazia() == true) 
        {
            throw std::underflow_error("Lista vazia");
        }
        return this->elementos[this->inicio];
    }// End

    void enfileirar(T elemento)
    {// Begin
        if (this->cheia() == true) 
        {
            throw std::overflow_error("Lista cheia");
        }
        this->elementos[this->fim] = elemento;
        this->fim = (this->fim + 1) % this->capacidade;
        this->quantidade++;
    }// End​

    T desenfileirar()
    {// Begin ​
        if (this->vazia() == true) 
        {
            throw std::underflow_error("Lista vazia");
        }
        auto valorElemento = this->elementos[this->inicio];
        this->inicio = (this->inicio + 1) % this->capacidade;
        this->quantidade--;
        return valorElemento;
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