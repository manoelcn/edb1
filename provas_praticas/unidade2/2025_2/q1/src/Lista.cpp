#include "Lista.h"
#include <sstream>
#include <stdexcept>
#define __CHECK_INTEGRIDADE__ 1

bool Lista::removerUltimaOcorrencia(const std::string& s)                                                                                                                                                                                                 // versão: EAMB-1.0
{   // ​Leia o enunciado com atenção antes de implementar este método. ​
    if (this->quantidade == 0) 
    {
        return false;
    }
    auto atual = this->primeiro;
    No *anterior = nullptr;
    No *alvo = nullptr;
    No *anteriorAlvo = nullptr;
    while (atual != nullptr) 
    {
        if (atual->valor == s) 
        {
            alvo = atual;
            anteriorAlvo = anterior;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    if (alvo == nullptr) 
    {
        return false;    
    }
    else
    {
        if (anteriorAlvo == nullptr) 
        {
            this->primeiro = alvo->proximo;
            delete alvo;
            this->quantidade--;
            return true;
        }
        anteriorAlvo->proximo = alvo->proximo;
        delete alvo;
        this->quantidade--;
        return true;
    }
}































/**
 * 
 * !!!!! PERIGO !!!!! 
 * NÃO MODIFIQUE O CÓDIGO ABAIXO 
 * !!!!! PERIGO !!!!! 
 */

Lista::Lista()
{
    this->quantidade = 0;
    this->primeiro = nullptr;
}

Lista::~Lista()
{
    auto aux = this->primeiro;

    while(aux != nullptr)
    {
        auto tmp = aux;
        aux = aux->proximo;
        delete tmp;
    }

    this->primeiro = nullptr;
    this->quantidade = 0;
}

bool Lista::inserirInicio(const std::string& elemento)
{
    No* novo = new No(elemento);
    novo->proximo = primeiro;
    primeiro = novo;
    ++quantidade;
    return true;
}

std::string Lista::imprimir() const
{
    std::ostringstream oss;
    oss << "{";
    No* atual = primeiro;
    while (atual != nullptr)
    {
        oss << atual->valor;
        if (atual->proximo != nullptr)
            oss << ", ";
        atual = atual->proximo;
    }
    oss << "}";
    return oss.str();
}

unsigned long Lista::tamanho() const
{
    return this->quantidade;
}

Lista::No::No(std::string valor)
{
    this->valor = valor;
    this->proximo = nullptr;
}

Lista::No::~No()
{
}