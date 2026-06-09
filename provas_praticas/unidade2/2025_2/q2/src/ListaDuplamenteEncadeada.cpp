#include "ListaDuplamenteEncadeada.h"
#include <sstream>
#include <stdexcept>
#define __CHECK_INTEGRIDADE__ 1

bool ListaDuplamenteEncadeada::buscar_e_mover(const std::string& s)                                                                                                                                                                                                 // versão: EAMB-1.0
{   // ​Leia o enunciado com atenção antes de implementar este método. 
    throw std::runtime_error("Ainda não foi implementado.");
}






























/**
 * 
 * !!!!! PERIGO !!!!! 
 * NÃO MODIFIQUE O CÓDIGO ABAIXO 
 * !!!!! PERIGO !!!!! 
 */

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada() {
    this->cabeca = new No<std::string>("CABECA_NAO_DEVE_SER_ACESSADA");
    this->cauda = new No<std::string>("CAUDA_NAO_DEVE_SER_ACESSADA");
    
    this->cabeca->proximo = this->cauda;
    this->cabeca->anterior = nullptr;

    this->cauda->proximo = nullptr;
    this->cauda->anterior = this->cabeca;

    this->quantidade = 0;
}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada() {
    auto aux = this->cabeca->proximo;
    while (aux != this->cauda) {
        auto tmp = aux;
        aux = aux->proximo;
        delete tmp;
    }

    delete this->cabeca;
    delete this->cauda;

	this->cabeca = nullptr;
	this->cauda = nullptr;
	this->quantidade = 0;
}

int ListaDuplamenteEncadeada::tamanho() const {
    return this->quantidade;
}

bool ListaDuplamenteEncadeada::vazia() const {
    return this->quantidade == 0;
}

bool ListaDuplamenteEncadeada::inserirInicio(std::string s) {
    auto novo = new No(s);
    
    novo->anterior = cabeca;
    novo->proximo = cabeca->proximo;

    novo->proximo->anterior = novo;
    novo->anterior->proximo = novo;

    ++quantidade;
    return true;
}

std::string ListaDuplamenteEncadeada::imprimir() const {
    std::stringstream resultado;
    No<std::string>* n = this->cabeca->proximo;

    if (n == this->cauda) {
        return "{}";
    } else {
        resultado << "{";
        resultado << n->valor;
        n = n->proximo;
    }

    for (; n != this->cauda; n = n->proximo) {
        resultado << ", " << n->valor;
    }

    resultado << "}";

    return resultado.str();
}

StatusDaLista ListaDuplamenteEncadeada::checarConsistencia() const {
    if (this->cabeca == nullptr) {
        return CABECA_NULA;
    } else if (this->cabeca->proximo == nullptr) {
        return CABECA_PROXIMO_NULO;
    } else if (this->cabeca->proximo->anterior != this->cabeca) {
        return ENCADEAMENTO_INCORRETO;
    } else if (this->cabeca->anterior != nullptr) {
        return CABECA_ANTERIOR;
    }

    if (this->cauda == nullptr) {
        return CAUDA_NULA;
    } else if (this->cauda->anterior == nullptr) {
        return CAUDA_ANTERIOR_NULO;
    } else if (this->cauda->anterior->proximo != this->cauda) {
        return ENCADEAMENTO_INCORRETO;
    } else if (this->cauda->proximo != nullptr) {
        return CAUDA_PROXIMO;
    }

    if (this->vazia()) {
        if (this->cabeca->proximo != this->cauda) {
            return CABECA_CAUDA;
        }
        if (this->cabeca != this->cauda->anterior) {
            return CABECA_CAUDA;
        }
    } else {
		int contagem = 0;
        for (No<std::string>* i = this->cabeca->proximo; i != this->cauda; i = i->proximo) {
			if (i->proximo == nullptr || i->anterior == nullptr) {
				return ENCADEAMENTO_INCORRETO;
			}
            if (i->proximo->anterior != i) {
                return ENCADEAMENTO_INCORRETO;
            }
            if (i->anterior->proximo != i) {
                return ENCADEAMENTO_INCORRETO;
            }
			contagem++;
        }

		if (contagem != this->quantidade) {
            return QUANTIDADE_DIFERENTE; 
        }
    }

    return OK;
}
