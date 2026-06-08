#define __CHECK_INTEGRIDADE__ 1
#include "../header/Lista.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <sstream> // pra implementar o método imprimir ​

// Implemente aqui sua solução ​
int Lista::removerTodos(const std::string& valor)                                                                                                                                                                                                // versão: EAMB-1.0
{// Begin​​⁣
    auto quantidadeRemovidos = 0;
    auto atual = this->primeiro;
    Lista::No *anterior = nullptr;
    while (atual != nullptr)
    {
        if (atual->valor == valor)
        {
            if (anterior == nullptr)
            {
                auto auxiliar = this->primeiro;
                this->primeiro = this->primeiro->proximo;
                if (this->primeiro == nullptr)
                {
                    this->ultimo = nullptr;
                }
                delete auxiliar;
                this->quantidade--;
                atual = this->primeiro;
                quantidadeRemovidos++;
                continue;
            }

            if (atual->proximo == nullptr)
            {
                delete this->ultimo;
                this->ultimo = anterior;
                this->ultimo->proximo = nullptr;
                this->quantidade--;
                atual = nullptr;
                quantidadeRemovidos++;
                break;
            }
            anterior->proximo = atual->proximo;
            auto remover = atual;
            delete remover;
            atual = anterior->proximo;
            quantidadeRemovidos++;
            this->quantidade--;
            continue;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return quantidadeRemovidos;
}// End​




















































// Não alterar código daqui pra baixo ​
Lista::Lista(){this->quantidade=0;this->primeiro=nullptr;this->ultimo=nullptr;}Lista::~Lista(){auto a=this->primeiro;while(a!=nullptr){auto b=a;a=a->proximo;delete b;}this->primeiro=nullptr;this->ultimo=nullptr;this->quantidade=0;}bool Lista::inserirInicio(const std::string& x){No* n=new No(x);n->proximo=this->primeiro;this->primeiro=n;if(this->quantidade==0){this->ultimo=n;}this->quantidade++;return true;}const std::string& Lista::primeiroElemento()const{if(quantidade>0){return primeiro->valor;}else{throw std::out_of_range("A lista está vazia. Não é possível acessar o primeiro elemento.");}}const std::string& Lista::ultimoElemento()const{if(quantidade>0){return ultimo->valor;}else{throw std::out_of_range("A lista está vazia. Não é possível acessar o último elemento.");}}unsigned long Lista::tamanho()const{return quantidade;}std::string Lista::imprimir()const{std::ostringstream o;o<<"{";No* p=primeiro;while(p!=nullptr){o<<p->valor;if(p->proximo!=nullptr)o<<", ";p=p->proximo;}o<<"}";return o.str();}
