//
//  ListaEncadeada.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "ListaEncadeada.h"
#include "No.h"
#include <iostream>
#include <string>

ListaEncadeada::ListaEncadeada()
{
    this->inicio = nullptr;
    this->quantidade = 0;
}

ListaEncadeada::~ListaEncadeada()
{
    // To-Do
}

void ListaEncadeada::inserirNoInicio(std::string elemento)
{
    ++this->quantidade;
    auto novo = new No<std::string>(elemento);
    if( this->inicio == nullptr )
    {
        this->inicio = novo;
    }
    else
    {
        novo->setProximo( this->inicio );
        this->inicio = novo;
    }
}

bool ListaEncadeada::remover(std::string val)
{
	auto atual = this->inicio;
	No<std::string> *anterior = nullptr;
	while (atual != nullptr)
	{
		if (atual->getValor() == val)
		{
			if (anterior == nullptr)
			{
				auto remover = atual;
				this->inicio = atual->getProximo();
				delete remover;
				this->quantidade--;
				return true;
			}
			if (atual->getProximo() == nullptr)
			{
				auto remover = atual;
                delete remover;
                anterior->setProximo(nullptr);
                atual = anterior;
                this->quantidade--;
                return true;
			}
			auto remover = atual;
            anterior->setProximo(atual->getProximo());
            atual = atual->getProximo();
            delete remover;
            this->quantidade--;
            return true;
		}
		anterior = atual;
		atual = atual->getProximo();
	}
	return false;
}

bool ListaEncadeada::vazia()
{
    return this->inicio == nullptr;
}

int ListaEncadeada::tamanho()
{
    return this->quantidade;
}

No<std::string>* ListaEncadeada::getInicio()
{
    return this->inicio;
}

void ListaEncadeada::imprimir()
{
    if(this->tamanho() > 0 )
    {
        auto no = this->getInicio();

        std::cout << "\t{";
        while(no != nullptr)
        {
            std::cout << no->getValor() << ", " ;
            no = no->getProximo();
        }
        std::cout << "}" << std::endl;
    }
}

