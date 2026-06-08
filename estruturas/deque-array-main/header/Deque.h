//
//  Deque.h
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#ifndef __Deque__
#define __Deque__

#include <string>
#include <sstream>
#include <stdexcept>

template <typename T>
class Deque
{
private:
    T *elementos;
    int capacidade;
    int quantidade;
    int frente;
    int atras;

public:
    Deque(int cap)
    {
        this->capacidade = cap;
        this->elementos = new T[this->capacidade];
        this->quantidade = 0;
        this->frente = 0;
        this->atras = 0;
    }

    ~Deque()
    {
        delete[] this->elementos;
    }

    int tamanho() const
    {
        return this->quantidade;
    }

    bool cheia() const
    {
        return this->quantidade == this->capacidade;
    }

    bool vazia() const
    {
        return this->quantidade == 0;
    }

    void empurrarFrente(T elemento)
    {
        if (this->cheia() == true)
        {
            throw std::overflow_error("Deque cheio.");
        }
        this->frente = (this->frente - 1 + this->capacidade) % this->capacidade;
        this->elementos[this->frente] = elemento;
        this->quantidade++;
    }

    void empurrarAtras(T elemento)
    {
        if (this->cheia() == true)
        {
            throw std::overflow_error("Deque cheio.");
        }
        this->elementos[this->atras] = elemento;
        this->atras = (this->atras + 1) % this->capacidade;
        this->quantidade++;
    }

    T removerFrente()
    {
        if (this->vazia() == true)
        {
            throw std::underflow_error("Deque vazio.");
        }
        auto temp = this->elementos[this->frente];
        this->frente = (this->frente + 1) % this->capacidade;
        this->quantidade--;
        return temp;
    }

    T removerAtras()
    {
        if (this->vazia() == true)
        {
            throw std::underflow_error("Deque vazio.");
        }
        auto temp = this->elementos[this->atras - 1];
        this->atras = (this->atras - 1) % this->capacidade;
        this->quantidade--;
        return temp;
    }

    T daFrente() const
    {
        return this->elementos[this->frente];
    }

    T deTras() const
    {
        return this->elementos[(this->atras - 1 + this->capacidade) % this->capacidade];
    }

    std::string imprimir() const
    {
        std::stringstream resultado;
        resultado << "{ ";
        int i = this->frente;
        for (int cont = 0; cont < this->quantidade; ++cont)
        {
            resultado << this->elementos[i] << " ";
            i = (i + 1) % this->capacidade;
        }
        resultado << "}";
        return resultado.str();
    }
};

#endif