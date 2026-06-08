//
//  ListaEncadeada.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "../header/ListaEncadeada.h"
#include "../header/No.h"
#include <iostream>
#include <string>
#include <sstream>

ListaEncadeada::ListaEncadeada()
{
    this->inicio = nullptr;
}

ListaEncadeada::~ListaEncadeada()
{
    // To-Do
}

void ListaEncadeada::inserirNoInicio(int e){auto n = new No<int>(e);if( inicio == nullptr ) inicio = n;else { n->setProximo( inicio );inicio = n;}}

int ListaEncadeada::removerTodos(int val) 
{
    int quantidadeRemovidos = 0;
    auto atual = this->getInicio();
    No<int> *anterior = nullptr;
    while (atual != nullptr)
    {
        if (atual->getValor() == val)
        {
            if (anterior == nullptr)
            {
                auto remover = atual;
                this->inicio = atual->proximo;
                delete remover;
                atual = this->inicio;
                quantidadeRemovidos++;
                continue;
            }

            if (atual->proximo == nullptr)
            {
                auto remover = atual;
                delete remover;
                atual = anterior;
                atual->proximo = nullptr;
                atual = nullptr;
                quantidadeRemovidos++;
                break;
            }
            anterior->proximo = atual->proximo;
            auto remover = atual;
            delete remover;
            atual = anterior->proximo;
            quantidadeRemovidos++;
            continue;
        }
        
        anterior = atual;
        atual = atual->getProximo();
    }
    return quantidadeRemovidos;
}

No<int>* ListaEncadeada::getInicio()
{
    return this->inicio;
}

std::string ListaEncadeada::imprimir()
{
    std::stringstream resultado;
    
    auto no = this->getInicio();

    while(no != nullptr)
    {
        resultado << no->getValor() << "->" ;
        no = no->getProximo();
    }
    resultado << "null";

    return resultado.str();
}

