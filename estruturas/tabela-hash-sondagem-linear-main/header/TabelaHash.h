//
//  TabelaHash.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#include <string>
#include <optional>
#include <unordered_set>
#include <iostream>

enum class Estado
{
    LIVRE = 0,
    OCUPADO,
    REMOVIDO
};

struct Elemento
{
    std::string chave;
    std::string valor;
    Estado estado = Estado::LIVRE;
};

enum class ConsistenciaStatus
{
    OK = 0,
    QUANTIDADE_INCORRETA,
    CHAVE_DUPLICADA,
};

class TabelaHash
{
    friend class TabelaHashTestHelper;

private:
    Elemento *array;
    int capacidade;
    int quantidade;

    static constexpr int CAPACIDADE_PADRAO = 17;
    static constexpr float CARGA_LIMITE_INFERIOR = 0.125f;
    static constexpr float CARGA_LIMITE_SUPERIOR = 0.5f;

    size_t valorHash(const std::string &chave) const
    {
        size_t valorHash = 0;
        for (char c : chave)
        {
            // Função simples para facilitar colisões em testes
            valorHash += static_cast<unsigned int>(c);
            // Forma melhor de calcular valor hash que gera valores mais distribuídos
            // valorHash = 31 * valorHash + static_cast<unsigned int>(c);
        }
        return valorHash;
    }

    int hash(const std::string &chave) const
    {
        return this->valorHash(chave) % this->capacidade;
    }

    float fatorDeCarga()
    {
        return (float)quantidade / (float)capacidade;
    }

    void aumentar()
    {
        auto novaCapacidade = this->capacidade * 2 + 1;
        redimensionar(novaCapacidade);
    }

    void diminuir()
    {
        auto metade = this->capacidade / 2;
        auto novaCapacidade = metade % 2 == 0 ? metade + 1 : metade;
        redimensionar(novaCapacidade);
    }

    void redimensionar(size_t tamanhoNovo)
    {
        auto arrayNovo = new Elemento[tamanhoNovo];
        auto arrayVelho = this->array;
        this->array = arrayNovo;

        auto capacidadeVelha = this->capacidade;
        this->capacidade = tamanhoNovo;

        for (int i = 0; i < capacidadeVelha; i++)
        {
            auto elemento = arrayVelho[i];

            if (elemento.estado == Estado::OCUPADO)
            {
                for (int delta = 0; delta < this->capacidade; delta++)
                {
                    auto indice = (this->hash(elemento.chave) + delta) % this->capacidade;

                    if (arrayNovo[indice].estado == Estado::LIVRE)
                    {
                        arrayNovo[indice].chave = elemento.chave;
                        arrayNovo[indice].valor = elemento.valor;
                        arrayNovo[indice].estado = Estado::OCUPADO;
                        break;
                    }
                }
            }
        }

        delete[] arrayVelho;
    }

public:
    TabelaHash(int capacidadeInicial = CAPACIDADE_PADRAO) : capacidade(capacidadeInicial), quantidade(0)
    {
        this->array = new Elemento[this->capacidade];
    }

    ~TabelaHash()
    {
        delete[] this->array;
    }

    bool inserir(const std::string &chave, const std::string &valor)
    {
        auto posicaoRemovida = -1;
        for (int delta = 0; delta < this->capacidade; delta++)
        {
            auto indice = (this->hash(chave) + delta) % this->capacidade;
            auto elemento = this->array[indice];

            if (elemento.estado == Estado::LIVRE)
            {
                if (posicaoRemovida == -1)
                {
                    this->array[indice].chave = chave;
                    this->array[indice].valor = valor;
                    this->array[indice].estado = Estado::OCUPADO;
                }
                else
                {
                    this->array[posicaoRemovida].chave = chave;
                    this->array[posicaoRemovida].valor = valor;
                    this->array[posicaoRemovida].estado = Estado::OCUPADO;
                }

                this->quantidade++;
                return true;
            }

            else if (elemento.estado == Estado::OCUPADO && elemento.chave == chave)
            {
                this->array[indice].valor = valor;
                return true;
            }

            else if (elemento.estado == Estado::REMOVIDO && posicaoRemovida == -1)
            {
                posicaoRemovida = indice;
            }
        }

        if (posicaoRemovida == -1)
        {
            throw std::overflow_error("Tabela cheia");
        }
        else
        {
            this->array[posicaoRemovida].chave = chave;
            this->array[posicaoRemovida].valor = valor;
            this->array[posicaoRemovida].estado = Estado::OCUPADO;
            this->quantidade++;
            return true;
        }
    }

    bool remover(const std::string &chave)
    {
        for (int delta = 0; delta < this->capacidade; delta++)
        {
            auto indice = (hash(chave) + delta) % this->capacidade;
            auto elemento = this->array[indice];

            if (elemento.chave == chave && elemento.estado == Estado::OCUPADO)
            {
                this->array[indice].estado = Estado::REMOVIDO;
                this->quantidade--;
                return true;
            }
            else if (elemento.estado == Estado::LIVRE)
            {
                return false;
            }
        }
        return false;
    }

    std::optional<std::string> buscar(const std::string &chave) const
    {
        for (int delta = 0; delta < this->capacidade; delta++)
        {
            auto indice = (hash(chave) + delta) % this->capacidade;
            auto elemento = this->array[indice];

            if (elemento.chave == chave && elemento.estado == Estado::OCUPADO)
            {
                return this->array[indice].valor;
            }

            else if (elemento.estado == Estado::LIVRE)
            {
                return std::nullopt;
            }
        }
        return std::nullopt;
    }

    ConsistenciaStatus checarConsistencia() const
    {
        int contador = 0;
        std::unordered_set<std::string> chaves;

        for (int i = 0; i < this->capacidade; ++i)
        {
            const Elemento &e = this->array[i];

            if (e.estado == Estado::OCUPADO)
            {
                contador++;

                // Verifica duplicatas
                if (chaves.count(e.chave) > 0)
                {
                    return ConsistenciaStatus::CHAVE_DUPLICADA;
                }
                chaves.insert(e.chave);
            }
        }

        if (contador != this->quantidade)
        {
            return ConsistenciaStatus::QUANTIDADE_INCORRETA;
        }

        return ConsistenciaStatus::OK;
    }

    int tamanho() const
    {
        return quantidade;
    }

    bool vazia() const
    {
        return this->quantidade == 0;
    }

    bool cheia() const
    {
        return this->capacidade == this->quantidade;
    }

    void imprimir() const
    {
        for (int i = 0; i < this->capacidade; ++i)
        {
            const Elemento &e = this->array[i];

            std::cout << "[" << i << "]: ";

            switch (e.estado)
            {
            case Estado::LIVRE:
                std::cout << "LIVRE";
                break;
            case Estado::REMOVIDO:
                std::cout << "REMOVIDO";
                break;
            case Estado::OCUPADO:
                std::cout << "OCUPADO (" << e.chave << ", " << e.valor << ")";
                break;
            }

            std::cout << std::endl;
        }
    }
};

#endif /* TABELA_HASH_H */
